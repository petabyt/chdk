#include "lolevel.h"
#include "platform.h"
#include "core.h"

//From a2600 100c, by comparison to a2500 100a
static long *nrflag = (long*)(0xC144+0x4); // @ 0xffa96d88, 4th arg to  sub_ff9f5f60 (100c)
#define PAUSE_FOR_FILE_COUNTER 200  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"
