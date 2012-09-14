#ifndef REMOTECAP_H
#define REMOTECAP_H
// get supported remote capture data types
#ifdef CAM_CHDK_PTP_REMOTESHOOT
int remotecap_get_target_support(void);
// set request remote capture data
int remotecap_set_target(int type, int lstart, int lcount);
// get selected types
int remotecap_get_target(void);
// get currently available type(s)
int remotecap_get_available_data_type(void);
// call from task hooks to notify remotecap of data
void remotecap_raw_available(void);
void remotecap_jpeg_available(const char *name);
// called from filewrite to check if it needs to continue waiting
int remotecap_filewrite_wait(void);
// called by ptp code to get next chunk address/size for the format (fmt) that is being currently worked on
int remotecap_get_data_chunk( int fmt, char **addr, unsigned int *size );
// frees both hooks, clears available_image_data, signals end of shoot()
void remotecap_free_hooks(void);
#else
#define remotecap_get_target_support() (0)
#endif
#endif
