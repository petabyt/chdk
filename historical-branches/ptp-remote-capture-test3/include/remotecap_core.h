#ifndef REMOTECAP_CORE_H
#define REMOTECAP_CORE_H
#include "remotecap.h"
/*
 * remotecap functions not exported to modules
 */
int remotecap_get_target(void);
// get currently available type(s)
int remotecap_get_available_data_type(void);
// call from task hooks to notify remotecap of data
void remotecap_raw_available(void);
void remotecap_jpeg_available(const char *name);
// called from filewrite/capt_seq to check if it needs to continue waiting
int remotecap_hook_wait(int);
// called by ptp code to get next chunk address/size for the format (fmt) that is being currently worked on
int remotecap_get_data_chunk( int fmt, char **addr, unsigned int *size, int *pos );
// called by ptp code when a specific data type has been completely transferred
void remotecap_data_type_done(int type);
// frees both hooks, clears available_image_data, signals end of shoot()
void remotecap_free_hooks(int);
// sets jpeg_chunks to NULL for DryOS r50+
void remotecap_jpeg_chunks_done(void);

#define MAX_CHUNKS_FOR_RAW 3 //raw data, including the DNG exif and thumbnail when asked
#define MAX_CHUNKS_FOR_YUV 1 //yuv data

//possible values for remotecap_hook_wait()
#define RC_WAIT_FWTASK 1
#define RC_WAIT_CAPTSEQTASK 0
#endif
