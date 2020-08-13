#include "lolevel.h"
#include "platform.h"

// debug
//#define FILEWRITE_DEBUG_LOG 1
extern void _LogCameraEvent(int id,const char *fmt,...);

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_JPEG 4 //filewritetask is prepared for this many chunks
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1[5];                                //
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_JPEG];
    char name[32];
} fwt_data_struct;

#include "../../../generic/filewrite.c"

#ifdef FILEWRITE_DEBUG_LOG
void log_fwt_msg(fwt_data_struct *fwd)
{
    int m=fwd->unkn1[0];
    _LogCameraEvent(0x20,"fw m:%d",m);
    _LogCameraEvent(0x20,"fw %s",fwd->name);
    if(m >= 4 && m < (4+MAX_CHUNKS_FOR_JPEG)) {
        _LogCameraEvent(0x20,"fw chunk adr:0x%08x l:0x%08x",fwd->pdc[m-4].address,fwd->pdc[m-4].length);
    }
    _LogCameraEvent(0x20,"fw u %08x %08x %08x %08x",fwd->unkn1[1],fwd->unkn1[2],fwd->unkn1[3],fwd->unkn1[4]);
}
#endif

