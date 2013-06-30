#include "ptp.h"
#include "stdlib.h"
#include "platform.h"
#include "conf.h"
#include "remotecap_core.h"
#include "module_load.h"
#include "modules.h"
#include "raw.h"
#include "cachebit.h"
static int hook_wait[2]; // counter for raw(0)/filewrite(1) wait, decrements for every 10ms sleep

static int available_image_data=0; // type of data available

static int remote_file_target=0;

static ptp_data_chunk rawchunk;
static ptp_data_chunk dng_hdr_chunk;
static int startline=0;
static int linecount=0;

#ifdef CAM_HAS_FILEWRITETASK_HOOK
static int jpegcurrchnk;
#endif //CAM_HAS_FILEWRITETASK_HOOK


int remotecap_get_target_support(void) {
    int ret = (PTP_CHDK_CAPTURE_RAW | PTP_CHDK_CAPTURE_DNGHDR);
#ifdef CAM_HAS_FILEWRITETASK_HOOK
    ret |= PTP_CHDK_CAPTURE_JPG;
#endif
    return ret;
}

int remotecap_get_target(void) {
    return remote_file_target;
}

//called to activate or deactive hooks
int remotecap_set_target( int type, int lstart, int lcount )
{
    // fail if invalid / unsupported type requested,
    // or current mode cannot support requested types
    if ((type & ~remotecap_get_target_support()) 
        || !(mode_get() & MODE_REC)
        || ((type & PTP_CHDK_CAPTURE_RAW) && !is_raw_possible())) {
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
    // invalid range, return error
    if(lstart<0 || lstart>CAM_RAW_ROWS-1 || lcount<0 || lcount+lstart>CAM_RAW_ROWS) {
        remote_file_target=0;
        remotecap_free_hooks(0); //frees up current hook (if any)
        return 0;
    }
    // default lcount = to end of buffer
    if(lcount == 0) {
        lcount = CAM_RAW_ROWS - lstart;
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

/*
don't allow unloading DNG module if target is DNG
not optimal since it could lead to loading/unloading every shot
could make logic more sophisticated later
*/
int remotecap_using_dng_module(void) {
    return (remote_file_target & PTP_CHDK_CAPTURE_DNGHDR) != 0;
}

void filewrite_set_discard_jpeg(int state);
int filewrite_get_jpeg_chunk(char **addr,unsigned *size, unsigned n, int *pos);

extern long hook_raw_size(void); // TODO should use camera_sensor, but see note on size mismatch!

void remotecap_raw_available(char *rawadr) {
// TODO this should probably just be noop if hook doesn't exist
#ifdef CAM_HAS_FILEWRITETASK_HOOK
    filewrite_set_discard_jpeg(1);
    jpegcurrchnk=0; //needs to be done here
#endif //CAM_HAS_FILEWRITETASK_HOOK
    if (remote_file_target & PTP_CHDK_CAPTURE_DNGHDR) {
        hook_wait[RC_WAIT_SPYTASK] = 3000; // x10ms sleeps = 30 sec timeout, TODO make setable

        libdng->create_dng_header_for_ptp(&dng_hdr_chunk);
        remotecap_set_available_data_type(PTP_CHDK_CAPTURE_DNGHDR);
        while (remotecap_hook_wait(RC_WAIT_SPYTASK)) {
            msleep(10);
        }
        libdng->free_dng_header_for_ptp();
    }

    if(!(remote_file_target & PTP_CHDK_CAPTURE_RAW)) {
        hook_wait[RC_WAIT_SPYTASK] = 0; // don't block
        return;
    }
    hook_wait[RC_WAIT_SPYTASK] = 3000; // x10ms sleeps = 30 sec timeout, TODO make setable

    started();
    
    rawchunk.address=(unsigned int)ADR_TO_UNCACHED(rawadr+startline*CAM_RAW_ROWPIX*CAM_SENSOR_BITS_PER_PIXEL/8);
    if ( (startline==0) && (linecount==CAM_RAW_ROWS) )
    {
        //hook_raw_size() is sometimes different than CAM_RAW_ROWS*CAM_RAW_ROWPIX*CAM_SENSOR_BITS_PER_PIXEL/8
        // TODO above shoudln't be true!!!
        //if whole size is requested, send hook_raw_size()
        rawchunk.length=(unsigned int)hook_raw_size();
    }
    else
    {
        rawchunk.length=linecount*CAM_RAW_ROWPIX*CAM_SENSOR_BITS_PER_PIXEL/8;
    }
  
    remotecap_set_available_data_type(PTP_CHDK_CAPTURE_RAW);
    
    while (remotecap_hook_wait(RC_WAIT_SPYTASK)) {
        msleep(10);
    }
    
    finished();
}

#ifdef CAM_HAS_FILEWRITETASK_HOOK
/*
called from filewrite hook to notify code that jpeg data is available
TODO name is not currently saved here
*/
void remotecap_jpeg_available(const char *name) {
    if(!(remote_file_target & (PTP_CHDK_CAPTURE_JPG | PTP_CHDK_CAPTURE_RAW))) {
        hook_wait[RC_WAIT_FWTASK] = 0; // don't block filewrite task
        return;
    }
    hook_wait[RC_WAIT_FWTASK] = 3000; // x10ms sleeps = 30 sec timeout, TODO make setable

    remotecap_set_available_data_type(remote_file_target & PTP_CHDK_CAPTURE_JPG);
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
    int morechunks = 0; // default = no more chunks
    *pos = -1; // default = sequential
    switch ( fmt )
    {
        case PTP_CHDK_CAPTURE_RAW: //raw
            *addr=(char*)rawchunk.address;
            *size=rawchunk.length;
            break;
#ifdef CAM_HAS_FILEWRITETASK_HOOK
        case PTP_CHDK_CAPTURE_JPG: //jpeg
            morechunks = filewrite_get_jpeg_chunk(addr,size,jpegcurrchnk,pos);
            jpegcurrchnk+=1;
            break;
#endif
        case PTP_CHDK_CAPTURE_DNGHDR: // dng header
            *addr=(char*)dng_hdr_chunk.address;
            *size=dng_hdr_chunk.length;
            break;
        default:
            /*
             * attempting to get an unsupported image format will result in
             * freeing up the raw hook
             */
            *addr=NULL;
            *size=0;
            remotecap_set_available_data_type(0);
    }
    return morechunks;
}

void remotecap_data_type_done(int type) {
    remotecap_set_available_data_type(available_image_data & ~type);
}

void remotecap_free_hooks(int mode) {
#ifdef CAM_FILEWRITETASK_SEEKS
    if (mode==1) // for DryOS >= r50
    {
        remotecap_jpeg_chunks_done(); // make jpeg_chunks NULL, immediately
        hook_wait[RC_WAIT_FWTASK] = 0; // free the current filewrite hook
    }
    else
#endif
    {
        // TODO these will be called at the end raw and again at the end of jpeg
        remotecap_set_available_data_type(0); // for fmt -1 case
        // free the filewrite hook
        hook_wait[RC_WAIT_FWTASK] = 0;
        // allow raw hook to continue
        hook_wait[RC_WAIT_SPYTASK] = 0;
    }
}
