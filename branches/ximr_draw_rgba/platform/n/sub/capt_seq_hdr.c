// Powershot N
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 100           // sometimes the file counter isn't updated when hook starts

static long *nrflag = (long*)(0xdec0+0x00);  // Found @ ff2ff5f4 (0xdec0) & ff2ff630 (+0x00)

#include "../../../generic/capt_seq.c"
