#include "lolevel.h"
#include "platform.h"



typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_FWT 7 // filewritetask is prepared for this many chunks


/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for cameras with CAM_FILEWRITETASK_SEEK/CAM_FILEWRITETASK_MULTIPASS
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1; // message number
    int file_offset;
    int maybe_full_size; // maybe, on g7x wasn't always full size
    int unkn2, unkn3;
    int unkn4;
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_FWT];
    int maybe_seek_flag;      // 0x2083 jpeg, 0x100 create dir, 0x200 CacheFlush
    int unkn5, unkn6;
    char name[32];      // offset from start 0x5c, from Open case
} fwt_data_struct;
/*
observed message sequences
JPEG
12 maybe_full_size = 0x004437ac (=actual size), seek_flag = 0x2083
 0 chunk 0-0x004437ac
 1 chunk 0-0
 7 close

new directory
11 seek_flag = 0x100
before m 12 for shot, after raw hook in capt_seq

after shot
10 A/ seek_flag 0x200
*/

#include "../../../generic/filewrite.c"


