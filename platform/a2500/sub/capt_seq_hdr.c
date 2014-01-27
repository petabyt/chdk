#include "lolevel.h"
#include "platform.h"
#include "core.h"

//From a2500 100a, by comparison to ixus140
static long *nrflag = (long*)(0xC144+0x4); // @ 0xffa96f28, 4th arg to  sub_ff9f5f68
#define PAUSE_FOR_FILE_COUNTER 200  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"
