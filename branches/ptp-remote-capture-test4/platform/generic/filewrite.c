#include "stdlib.h" // for NULL

#include "remotecap_core.h"
static int ignore_current_write=0; //used by the platform routine to check whether to write the current file
#ifdef CAM_DRYOS
volatile int current_write_ignored=0; //needed to prevent nasty surprises with the current override code
#endif //CAM_DRYOS

/*
handle camera specific MAX_CHUNKS_FOR_JPEG, camp_ptp_data_chunk
get address and size of chunk N
returns NULL addr and zero size when max chunks reached
*/
static cam_ptp_data_chunk *jpeg_chunks;
#ifdef CAM_FILEWRITETASK_SEEKS
static int jpeg_bytes_left;
static int jpeg_curr_session_chunk;
static int jpeg_file_offset;
static int jpeg_full_size;
#endif //CAM_FILEWRITETASK_SEEKS

int filewrite_get_jpeg_chunk(char **addr,int *size,unsigned n,int *pos) {
#ifndef CAM_FILEWRITETASK_SEEKS
    *pos=-1;
    if (n >= MAX_CHUNKS_FOR_JPEG || jpeg_chunks == NULL) {
        *addr=(char *)0xFFFFFFFF; // signals last chunk
        *size=0;
        return 0; // last chunk
    }
    *addr=(char *)jpeg_chunks[n].address;
    *size=jpeg_chunks[n].length;
    if (n < MAX_CHUNKS_FOR_JPEG-1) {
        if (jpeg_chunks[n+1].length==0) {
            return 0; // last chunk
        }
        return 1; // not last chunk
    }
    return 0; // last chunk
#else
    if ( jpeg_chunks == NULL ) { //do we have a valid queue?
        int m=50;
        while (m>0) { //wait for at most 500ms
            _SleepTask(10);
            m--;
            if ( jpeg_chunks != NULL ) break;
        }
        if ( jpeg_chunks == NULL ) { //timeout, error
            *addr=(char *)0;
            *size=0;
            *pos=-1;
            return 0;
        }
    }
    if ( n == 0 ) { // first chunk for this shot
        jpeg_bytes_left = jpeg_full_size;
    }
    /*
     * handle multiple filewritetask invocations
     * return 0 for the last chunk
     * return 1 when there's an additional chunk in the current queue
     * return 2 when the current queue is done, but the file isn't
     */
    *addr=(char *)jpeg_chunks[jpeg_curr_session_chunk].address;
    *size=jpeg_chunks[jpeg_curr_session_chunk].length;
    jpeg_bytes_left -= *size;
    if (jpeg_curr_session_chunk == 0) {
        *pos=jpeg_file_offset; //only post file offset for the first chunk in the current queue
    }
    else {
        *pos=-1;
    }
    jpeg_curr_session_chunk++;
    if (jpeg_bytes_left>0) {
        if ( jpeg_curr_session_chunk < MAX_CHUNKS_FOR_JPEG ) {
            if (jpeg_chunks[jpeg_curr_session_chunk].length==0) { //last chunk of the current queue
                return 2;
            }
        }
        else {
            return 2;
        }
    }
    else {
        return 0; //last
    }

    return 1; //not last

#endif //CAM_FILEWRITETASK_SEEKS
}

void filewrite_set_discard_jpeg(int state) {
    ignore_current_write = state;
}

void filewrite_main_hook(fwt_data_struct *fwt_data)
{
#ifdef CAM_FILEWRITETASK_SEEKS
    // don't forget to #define FWT_SEEKMASK, FWT_MUSTSEEK

    jpeg_curr_session_chunk = 0;
    /*
     * below information is only valid when this routine is called
     *
     * seek flag is at offset 0x50 for DryOS r50
     * 2: seek is needed
     * if not 2, seek is only performed when file_offset is not 0
     *
     * seek flag is at offset 0x4c for DryOS r51
     * if (seek_flag & 0x40) == 0x40 then seek is needed
     * otherwise, seek is only performed when file_offset is not 0
     */
    if ( ((fwt_data->seek_flag & FWT_SEEKMASK) == FWT_MUSTSEEK) || (fwt_data->file_offset != 0) ) {
        jpeg_file_offset = fwt_data->file_offset;
    }
    else {
        jpeg_file_offset = -1; // no seek needed
    }
    jpeg_full_size = fwt_data->full_size;
#endif //CAM_FILEWRITETASK_SEEKS
    jpeg_chunks = &(fwt_data->pdc[0]);
    remotecap_jpeg_available(&(fwt_data->name[0]));
    while (remotecap_hook_wait(RC_WAIT_FWTASK)) {
        _SleepTask(10);
    }
    jpeg_chunks=NULL;
}

#ifdef CAM_FILEWRITETASK_SEEKS
void remotecap_jpeg_chunks_done() {
    jpeg_chunks=NULL;
}
#endif //CAM_FILEWRITETASK_SEEKS

// wrapper functions for use in filewritetask
#ifdef CAM_DRYOS
static long fwt_bytes_written = 0; // need to track this independently of ptp
int fwt_open(const char *name, int flags, int mode) {
    if (!ignore_current_write) {
        return _Open(name, flags, mode);
    }
    current_write_ignored=1;
    return 255; // fake, invalid file descriptor
}

int fwt_write(int fd, const void *buffer, long nbytes) {
    if (!current_write_ignored) {
        return _Write(fd, buffer, nbytes);
    }
    fwt_bytes_written += nbytes;
    return (int)nbytes; // "everything's written"
}

#ifdef CAM_FILEWRITETASK_SEEKS
int fwt_lseek(int fd, long offset, int whence) {
    if (!current_write_ignored) {
        return _lseek(fd, offset, whence);
    }
    return (int)offset; // "file position set to the requested value"
}
#endif // CAM_FILEWRITETASK_SEEKS

int fwt_close (int fd) {
    if (!current_write_ignored) {
        int ret = _Close(fd);
        //imagesavecomplete=1;
        fwt_bytes_written = 0;
        return ret;
    }
#ifdef CAM_FILEWRITETASK_SEEKS
    if (fwt_bytes_written >= jpeg_full_size) {
        ignore_current_write=0;
        current_write_ignored=0;
        fwt_bytes_written = 0;
    }
#else
    ignore_current_write=0;
    current_write_ignored=0;
    fwt_bytes_written = 0;
#endif // CAM_FILEWRITETASK_SEEKS
//  imagesavecomplete=1;
    return 0;
}
#else // ifdef CAM_DRYOS
/*
 * helper function for VxWorks camera
 * to be used when imagesavecomplete handling is needed
 */
int fwt_after_close (int param) {
//    imagesavecomplete=1;
    return param;
}
#endif //CAM_DRYOS
