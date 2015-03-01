#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define NR_AUTO (0)                 // have to explictly reset value back to 0 to enable auto
static long *nrflag = (long*)(0xCF68+0xC); // sx510 101a Found @ 0xff2adfe4 (0xcf68) & 0xff2adfe8 (+0xC)
#define PAUSE_FOR_FILE_COUNTER 350  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"
