#include "ptp.h"
#include "stdlib.h"
#include "platform.h"
#include "conf.h"
#include "remotecap.h"
#include "module_load.h"
#include "modules.h"
#include "raw.h"
#ifdef CAM_CHDK_PTP_REMOTESHOOT
static int hook_wait[2]; // counter for raw(0)/filewrite(1) wait, decrements for every 10ms sleep

static int available_image_data=0; // type of data available

int remotecap_get_target_support(void) {
    int ret = 0;
    ret |= PTP_CHDK_CAPTURE_RAW;
#ifdef CAM_HAS_FILEWRITETASK_HOOK
    ret |= PTP_CHDK_CAPTURE_JPG | PTP_CHDK_CAPTURE_YUV;
#endif
    return ret;
}

static int remote_file_target=0;

static ptp_data_chunk rawchunk[MAX_CHUNKS_FOR_RAW];
static int rawcurrchnk;
static char nameforptp[12];
static long filenumforptp;
static int startline=0;
static int linecount=0;

#ifdef CAM_HAS_FILEWRITETASK_HOOK
static ptp_data_chunk yuvchunk[MAX_CHUNKS_FOR_YUV];
static int yuvcurrchnk;
static int jpegcurrchnk;
#endif //CAM_HAS_FILEWRITETASK_HOOK

int remotecap_get_target(void) {
    return remote_file_target;
}

//called to activate or deactive hooks
int remotecap_set_target ( int type, int lstart, int lcount )
{
    // unknown type or not in rec, clear and return error
    // TODO not clear REC should be required, could be valid to set / clear before switching
    if ((type & ~remotecap_get_target_support()) || !(mode_get() & MODE_REC)) {
        remote_file_target=0;
        remotecap_free_hooks(0); //frees up current hook (if any)
        return 0;
    }
    remote_file_target=type;
    // clear requested
    if(type==0) {
        remotecap_free_hooks(0); //frees up current hook (if any)
        return 1;
    }
    startline=lstart;
    linecount=lcount;
    return 1;
}

int remotecap_get_available_data_type(void) {
    return available_image_data;
}

void remotecap_set_available_data_type(int type)
{
    available_image_data = type;
}

void filewrite_set_discard_jpeg(int state);
int filewrite_get_jpeg_chunk(char **addr,unsigned *size, unsigned n, int *pos);
int remotecap_raw_savefile(ptp_data_chunk *rawchunk, int startline, int linecount);

void remotecap_raw_available(void) {
    filenumforptp = get_target_file_num(); // need to get this here for consistency
// TODO this should probably just be noop if hook doesn't exist
#ifdef CAM_HAS_FILEWRITETASK_HOOK
    filewrite_set_discard_jpeg(1);
    jpegcurrchnk=0; //needs to be done here
    yuvcurrchnk=0;
#endif //CAM_HAS_FILEWRITETASK_HOOK
    if(!(remote_file_target & PTP_CHDK_CAPTURE_RAW)) {
        hook_wait[RC_WAIT_CAPTSEQTASK] = 0; // don't block capt_seq task
        return;
    }
    hook_wait[RC_WAIT_CAPTSEQTASK] = 3000; // x10ms sleeps = 30 sec timeout, TODO make setable

    if (startline<0) startline=0;
    if (startline>CAM_RAW_ROWS-1) startline=0;
    if (linecount<=0) linecount=CAM_RAW_ROWS;
    if ( (linecount+startline)>CAM_RAW_ROWS ) linecount=CAM_RAW_ROWS-startline;

    rawcurrchnk=0;
    
    remotecap_raw_savefile(&rawchunk[0],startline,linecount);
}

#ifdef CAM_HAS_FILEWRITETASK_HOOK
/*
called from filewrite hook to notify code that jpeg data is available
TODO name is not currently saved here
*/
void remotecap_jpeg_available(const char *name) {
    if(!(remote_file_target & (PTP_CHDK_CAPTURE_JPG | PTP_CHDK_CAPTURE_YUV | PTP_CHDK_CAPTURE_RAW))) {
        hook_wait[RC_WAIT_FWTASK] = 0; // don't block filewrite task
        return;
    }
    hook_wait[RC_WAIT_FWTASK] = 3000; // x10ms sleeps = 30 sec timeout, TODO make setable
#if 0
    //for use in debug & porting, for example to dump the filewritetask data block or some memory
    yuvchunk[0].address=0x1000;
    yuvchunk[0].length=MAXRAMADDR+1-0x1000;
#else
    yuvchunk[0].address=(int)hook_yuv_shooting_buf_addr();
    //UYVY format is assumed, 16bits/pixel total
    yuvchunk[0].length=hook_yuv_shooting_buf_width()*hook_yuv_shooting_buf_height()*2;
#endif

    remotecap_set_available_data_type(remote_file_target & (PTP_CHDK_CAPTURE_JPG | PTP_CHDK_CAPTURE_YUV));
}
#endif

/*
return true until data is read, or timeout / cancel
*/
int remotecap_hook_wait(int which) {
    if(hook_wait[which]) {
        hook_wait[which]--;
    }
    return hook_wait[which] && remotecap_get_available_data_type();
}

// called by ptp code to get next chunk address/size for the format (fmt) that is being currently worked on
int remotecap_get_data_chunk( int fmt, char **addr, unsigned int *size, int *pos )
{
    int notlastchunk = 0; // default = no more chunks
    *pos = -1; // default = sequential
    switch ( fmt )
    {
        case 0: //name
            //two ways to get this
            //1) get_file_next_counter(), may increment between the raw and filewrite hooks
            //2) from filewritetask data (only available for jpeg and yuv)
            sprintf(nameforptp,"IMG_%04d",filenumforptp);
            *addr=&nameforptp[0];
            *size=9;
            break;
        case PTP_CHDK_CAPTURE_RAW: //raw
            //TODO turn this into a function?
            if ( rawcurrchnk >= MAX_CHUNKS_FOR_RAW ) {
                *addr=(char*)0xffffffff;
                *size=0;
            }
            else {
                *addr=(char*)rawchunk[rawcurrchnk].address;
                *size=rawchunk[rawcurrchnk].length;
                rawcurrchnk+=1;
                if ( rawcurrchnk < MAX_CHUNKS_FOR_RAW ) {
                    if ( rawchunk[rawcurrchnk].length != 0 ) notlastchunk = 1; // not the last chunk
                }
            }
//             if ( (*addr==0) || (*size==0) || (!notlastchunk) ) {
//                 remotecap_set_available_data_type(available_image_data & ~PTP_CHDK_CAPTURE_RAW);
//             }
            break;
#ifdef CAM_HAS_FILEWRITETASK_HOOK
        case PTP_CHDK_CAPTURE_JPG: //jpeg
            notlastchunk = filewrite_get_jpeg_chunk(addr,size,jpegcurrchnk,pos);
            jpegcurrchnk+=1;
//             if ( (*addr==0) || (*size==0) || (!notlastchunk) ) {
//                 remotecap_set_available_data_type(available_image_data & ~PTP_CHDK_CAPTURE_JPG);
//             }
            break;
        case PTP_CHDK_CAPTURE_YUV: //yuv
            // TODO use the same function as for RAW?
            if ( yuvcurrchnk >= MAX_CHUNKS_FOR_YUV ) {
                *addr=(char*)0xffffffff;
                *size=0;
            }
            else {
                *addr=(char*)yuvchunk[yuvcurrchnk].address;
                *size=yuvchunk[yuvcurrchnk].length;
                yuvcurrchnk+=1;
                if ( yuvcurrchnk < MAX_CHUNKS_FOR_YUV ) {
                    if ( yuvchunk[yuvcurrchnk].length != 0 ) notlastchunk = 1; // not the last chunk
                }
            }
//             if ( (*addr==0) || (*size==0) || (!notlastchunk) ) {
//                 remotecap_set_available_data_type(available_image_data & ~PTP_CHDK_CAPTURE_YUV);
//             }
            break;
#endif
        default:
            /*
             * attempting to get an unsupported image format will result in
             * freeing up the raw hook
             */
            *addr=NULL;
            *size=0;
            remotecap_set_available_data_type(0);
    }
    return notlastchunk;
}

void remotecap_data_type_done(int type) {
    remotecap_set_available_data_type(available_image_data & ~type);
}

void remotecap_free_hooks(int mode) {
#ifdef CAM_EXTENDED_FILEWRITETASK
    if (mode==1) // for DryOS >= r50
    {
        remotecap_jpeg_chunks_done(); // make jpeg_chunks NULL, immediately
        hook_wait[RC_WAIT_FWTASK] = 0; // free the current filewrite hook
    }
    else
#endif
    {
        // TODO these will be called at the end raw and again at the end of jpeg/yuv
        remotecap_set_available_data_type(0); // for fmt -1 case
        // free the filewrite hook
        hook_wait[RC_WAIT_FWTASK] = 0;
        // allow raw hook to continue
        hook_wait[RC_WAIT_CAPTSEQTASK] = 0;
        state_shooting_progress=SHOOTING_PROGRESS_PROCESSING; //is this still needed without shoot()?
    }
}

extern void patch_bad_pixels(void);
extern char* get_raw_image_addr(void);
extern char* get_alt_raw_image_addr(void);
// version of raw_savefile() for ptp
int remotecap_raw_savefile(ptp_data_chunk *rawchunk, int startline, int linecount) {
    int ret = 0;
#if DNG_SUPPORT
    if (conf.dng_raw) {  //REMINDER: set this from script before shooting
        if ( module_dng_load(LIBDNG_OWNED_BY_RAW) ) {
            if ( API_VERSION_MATCH_REQUIREMENT(libdng->version, 1, 1) ) {
                libdng->capture_data_for_exif();
            }
            else {
                module_dng_unload(LIBDNG_OWNED_BY_RAW);
                conf.dng_raw=0; //TODO: this is rude, but it does prevent further tries with an incompatible module
            }
        }
    }
#endif    
    // Get pointers to RAW buffers (will be the same on cameras that don't have two or more buffers)
    char* rawadr = get_raw_image_addr();
    char* altrawadr = get_alt_raw_image_addr();

    if (conf.bad_pixel_removal) patch_bad_pixels();

    state_shooting_progress = SHOOTING_PROGRESS_PROCESSING;

    started();
    
//TODO: partial raw implemented, partial dng not
    
#if DNG_SUPPORT
    if (conf.dng_raw)
    {
        if ( module_dng_load(LIBDNG_OWNED_BY_RAW) )
            libdng->create_dng_for_ptp(rawchunk, rawadr, altrawadr, CAM_UNCACHED_BIT, startline, linecount );
    }
    else 
#endif
    {
        rawchunk[0].address=(unsigned int)(rawadr+startline*CAM_RAW_ROWPIX*CAM_SENSOR_BITS_PER_PIXEL/8 )|CAM_UNCACHED_BIT;
        if ( (startline==0) && (linecount==CAM_RAW_ROWS) )
        {
            //hook_raw_size() is sometimes different than CAM_RAW_ROWS*CAM_RAW_ROWPIX*CAM_SENSOR_BITS_PER_PIXEL/8
            // TODO above shoudln't be true!!!
            //if whole size is requested, send hook_raw_size()
            rawchunk[0].length=(unsigned int)hook_raw_size();
        }
        else
        {
            rawchunk[0].length=linecount*CAM_RAW_ROWPIX*CAM_SENSOR_BITS_PER_PIXEL/8;
        }
      
        rawchunk[1].address=0xffffffff;
        rawchunk[1].length=0;
    }
    remotecap_set_available_data_type(PTP_CHDK_CAPTURE_RAW);
    
    while (remotecap_hook_wait(RC_WAIT_CAPTSEQTASK)) {
        msleep(10);
    }
    
#if DNG_SUPPORT
    if (conf.dng_raw)
    {
        libdng->free_dng_for_ptp(rawadr, altrawadr);
    }
#endif
    
    finished();

    ret = 1;

#ifdef OPT_CURVES
    if (conf.curve_enable) {
        if (module_curves_load())
            libcurves->curve_apply();
    }
#endif
    return ret;
}
#endif //CAM_CHDK_PTP_REMOTESHOOT
