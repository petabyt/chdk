#ifndef REMOTECAP_CORE_H
#define REMOTECAP_CORE_H
#include "remotecap.h"
/*
 * remotecap functions not exported to modules
 */
// get currently selected data types
int remotecap_get_target(void);
// called by ptp to get currently available type and image number
void remotecap_is_ready(int *available_type,int *image_num);
// call from task hooks to notify remotecap of data
void remotecap_raw_available(char *rawadr);
void remotecap_jpeg_available(void);
// called by ptp code to get next chunk address/size for the format (fmt) that is being currently worked on
int remotecap_get_data_chunk( int fmt, char **addr, unsigned int *size, int *pos );
// called by ptp code to notify remotecap that chunk send is complete
void remotecap_send_complete(int rcgd_status,int type);
// sets jpeg_chunks to NULL for DryOS r50+
void remotecap_jpeg_chunks_done(void);

#endif
