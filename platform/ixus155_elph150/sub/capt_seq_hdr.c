#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define NR_AUTO (0)                 // have to explictly reset value back to 0 to enable auto
static long *nrflag = (long*)(0xa324); // found near 0xffa2316c (0a320 + 4)
//#define PAUSE_FOR_FILE_COUNTER 200  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"
