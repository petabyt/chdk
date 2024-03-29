/* remotecap functions and structures exported to modules*/
#ifndef REMOTECAP_H
#define REMOTECAP_H
typedef struct {
    unsigned int address;
    unsigned int length;
} ptp_data_chunk;

// get supported remote capture data types
int remotecap_get_target_support(void);
// set request remote capture data
int remotecap_set_target(int type, int lstart, int lcount);
#endif
