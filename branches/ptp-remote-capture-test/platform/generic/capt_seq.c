// generic capt_seq fuctions
#include "asmsafe.h"
#include "conf.h"
#include "stdlib.h"

#define RAWDATA_AVAILABLE (1)
#define RAWDATA_SAVED (2)

// some cams use different values
// note: many cams ROM also accepts a value of 3, meaning unknown
#ifndef NR_ON
#define NR_ON (2)
#endif
#ifndef NR_OFF
#define NR_OFF (1)
#endif

static long raw_save_stage;
volatile long shutter_open_time=0;      // for DNG EXIF creation
volatile long shutter_open_tick_count;  // for DNG EXIF creation

#ifdef CAM_CHDK_PTP_REMOTESHOOT

static int remote_file_target=0;
static int ignore_current_write=0; //used by the platform routine to check whether to write the current file
static int currently_active_overrides=0; //bitmask of formats currently available

typedef struct {
    unsigned int address;
    unsigned int length;
} ptp_data_chunk;

#define MAX_CHUNKS_FOR_RAW 1 //raw data, could include the DNG exif

static ptp_data_chunk rawchunk[MAX_CHUNKS_FOR_RAW];
static int rawcurrchnk;
static char nameforptp[12];
static int startline=0;
static int linecount=0;

#ifdef CAM_HAS_FILEWRITETASK_HOOK

#define MAX_CHUNKS_FOR_YUV 1 //yuv data
static ptp_data_chunk jpegchunk[MAX_CHUNKS_FOR_JPEG];
static ptp_data_chunk yuvchunk[MAX_CHUNKS_FOR_YUV];
static int jpegcurrchnk;
static int yuvcurrchnk;

#endif //CAM_HAS_FILEWRITETASK_HOOK

extern void ptp_file_data_available(int);

//called by ptp code to activate needed overrides
void set_remote_file_target ( int type, int lstart, int lcount )
{
    remote_file_target=type;
    startline=lstart;
    linecount=lcount;
}

#endif //CAM_CHDK_PTP_REMOTESHOOT

void __attribute__((naked,noinline)) capt_seq_hook_raw_here()
{
 asm volatile("STMFD   SP!, {R0-R12,LR}\n");

#ifdef PAUSE_FOR_FILE_COUNTER
    // Some cameras need a slight delay for the file counter to be updated correctly
    // before raw_savefile tries to get the file name & directory.
    // Add '#define PAUSE_FOR_FILE_COUNTER 100' in the camera firmware capt_seq.c file.
    // The value can be adjusted as needed for different cameras.
    if ( (conf.save_raw && is_raw_enabled()) // Only delay if RAW enabled (prevents slowdown in HQ burst mode)
#ifdef CAM_CHDK_PTP_REMOTESHOOT
        || (remote_file_target & 7) //... or if remote shooting is active
#endif //CAM_CHDK_PTP_REMOTESHOOT
    )
    {
        _SleepTask(PAUSE_FOR_FILE_COUNTER);
    }
#endif

    raw_save_stage = RAWDATA_AVAILABLE;
#ifdef CAM_CHDK_PTP_REMOTESHOOT
    if ( remote_file_target == 0 ) //no remote redirection
    {
        core_rawdata_available(); //notifies spytask in core/main.c
    }
    else if ( (remote_file_target & 2) > 0 ) //chdk raw requested
    {
        if (startline<0) startline=0;
        if (startline>CAM_RAW_ROWS-1) startline=0;
        if (linecount<=0) linecount=CAM_RAW_ROWS;
        if ( (linecount+startline)>CAM_RAW_ROWS ) linecount=CAM_RAW_ROWS-startline;
        
        rawchunk[0].address=(unsigned int)(hook_raw_image_addr()+startline*CAM_RAW_ROWPIX*CAM_SENSOR_BITS_PER_PIXEL/8 );
        if ( (startline==0) && (linecount==CAM_RAW_ROWS) )
        {
            //hook_raw_size() is sometimes different than CAM_RAW_ROWS*CAM_RAW_ROWPIX*CAM_SENSOR_BITS_PER_PIXEL/8
            //if whole size is requested, send hook_raw_size()
            rawchunk[0].length=(unsigned int)hook_raw_size();
        }
        else
        {
            rawchunk[0].length=linecount*CAM_RAW_ROWPIX*CAM_SENSOR_BITS_PER_PIXEL/8;
        }
        rawcurrchnk=0;
        ignore_current_write=1; //don't save the jpeg locally
        ptp_file_data_available(2); //notifies ptp code in core/ptp.c, first thing to happen
        currently_active_overrides=2; //to track this locally
    }
    else
    {
        raw_save_stage = RAWDATA_SAVED;
    }
#else
    core_rawdata_available(); //notifies spytask in core/main.c
#endif //CAM_CHDK_PTP_REMOTESHOOT
    while (raw_save_stage != RAWDATA_SAVED){
	_SleepTask(10);
    }

 asm volatile("LDMFD   SP!, {R0-R12,PC}\n");
}

#ifdef CAM_CHDK_PTP_REMOTESHOOT

#ifdef CAM_HAS_FILEWRITETASK_HOOK
void filewrite_main_hook(char *name, cam_ptp_data_chunk *pdc)
{
    if ( ((remote_file_target & 1) > 0) || ((remote_file_target & 4) > 0) ) {//jpeg or yuv requested
        int n;
        for (n=0; n<MAX_CHUNKS_FOR_JPEG; n++) {
            jpegchunk[n].address=pdc[n].address;
            jpegchunk[n].length=pdc[n].length;
        }
        //todo:
        //- find an address for this
        //- check the current picture size (L,M1,M2,S,whatever...)
        //- implement it
        yuvchunk[0].address=0;
        yuvchunk[0].length=0;

        jpegcurrchnk=0;
        yuvcurrchnk=0;
        ignore_current_write=1;
        raw_save_stage = RAWDATA_AVAILABLE;
        ptp_file_data_available(5); //notifies ptp code in core/ptp.c (jpeg+yuv), happens after RAW
        currently_active_overrides=(remote_file_target & 5); //to track these locally
        while (raw_save_stage != RAWDATA_SAVED) {
        _SleepTask(10);
        }
    }
}
#endif //CAM_HAS_FILEWRITETASK_HOOK

// called by ptp code to get next chunk address/size for the format (fmt) that is being currently worked on
void get_next_chunk_data_for_ptp( int fmt, char **addr, unsigned int *size )
{
    switch ( fmt )
    {
        case 0: //name
            //two ways to get this
            //1) get_file_next_counter(), may increment between the raw and filewrite hooks
            //2) from filewritetask data (only available for jpeg and yuv)
            sprintf(nameforptp,"IMG_%04d",get_target_file_num());
            *addr=&nameforptp[0];
            *size=9;
            break;
        case 2: //raw
            if ( rawcurrchnk >= MAX_CHUNKS_FOR_RAW ) {
                *addr=(char*)0xffffffff;
                *size=0;
            }
            else {
                *addr=(char*)rawchunk[rawcurrchnk].address;
                *size=rawchunk[rawcurrchnk].length;
                rawcurrchnk+=1;
            }
            if ( (*addr==0) || (*size==0) ) {
                currently_active_overrides&=0xfffffffd;
            }
            break;
#ifdef CAM_HAS_FILEWRITETASK_HOOK
        case 1: //jpeg
            if ( jpegcurrchnk >= MAX_CHUNKS_FOR_JPEG ) {
                *addr=(char*)0xffffffff;
                *size=0;
            }
            else {
                *addr=(char*)jpegchunk[jpegcurrchnk].address;
                *size=jpegchunk[jpegcurrchnk].length;
                jpegcurrchnk+=1;
            }
            if ( (*addr==0) || (*size==0) ) {
                currently_active_overrides&=0xfffffffe;
            }
            break;
        case 4: //yuv
            if ( yuvcurrchnk >= MAX_CHUNKS_FOR_YUV ) {
                *addr=(char*)0xffffffff;
                *size=0;
            }
            else {
                *addr=(char*)yuvchunk[yuvcurrchnk].address;
                *size=yuvchunk[yuvcurrchnk].length;
                yuvcurrchnk+=1;
            }
            if ( (*addr==0) || (*size==0) ) {
                currently_active_overrides&=0xfffffffb;
            }
            break;
#else
        default:
            /*
             * attempting to get an unsupported image format will result in
             * freeing up the raw hook
             */
            *addr=(char*)0xffffffff;
            *size=0;
            currently_active_overrides=0;
#endif
    }
    if ( (currently_active_overrides == 0) || (fmt == -1) ) {
        ptp_file_data_available(0); //current formats exhausted
        raw_save_stage = RAWDATA_SAVED; //free up hook
        state_shooting_progress=SHOOTING_PROGRESS_DONE; //shoot() needs this...
    }
}

#endif //CAM_CHDK_PTP_REMOTESHOOT

// wrapper function to store status on stack as this routine is called from assembly code in capt_seq_task()

void __attribute__((naked,noinline)) wait_until_remote_button_is_released(  ) 
{ 
asm volatile (
ASM_SAFE("BL _wait_until_remote_button_is_released\n")
 "	BX      LR \n"
	) ;
}


void hook_raw_save_complete()
{
    raw_save_stage = RAWDATA_SAVED; //spytask notifies about the finished raw save procedure
}

void __attribute__((naked,noinline)) capt_seq_hook_set_nr()
{
 asm volatile("STMFD   SP!, {R0-R12,LR}\n");
    switch (core_get_noise_reduction_value()){
    case NOISE_REDUCTION_AUTO_CANON:
        // leave it alone
#if defined(NR_AUTO)			// If value defined store it (e.g. for G12 & SX30 need to reset back to 0 to enable auto)
        *nrflag = NR_AUTO;
#endif
        break;
    case NOISE_REDUCTION_OFF:
        *nrflag = NR_OFF;
        break;
    case NOISE_REDUCTION_ON:
        *nrflag = NR_ON;
        break;
    };

 shutter_open_time=_time((void*)0);
 shutter_open_tick_count = get_tick_count();

 asm volatile("LDMFD   SP!, {R0-R12,PC}\n");
}

