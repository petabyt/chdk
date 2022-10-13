#include "lolevel.h"
#include "platform.h"
#include "core.h"

static long *nrflag = (long*)(0xcf74+0x00);  // Found @ ff2f3000 & ff2f303c
#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable autostatic long *nrflag = (long*)(0xE4F0+4); // FF3634B8, 4th arg to  sub_FF2A49C4

#define PAUSE_FOR_FILE_COUNTER 100 // sometimes the file counter isn't updated when hook starts

#include "../../../generic/capt_seq.c"
