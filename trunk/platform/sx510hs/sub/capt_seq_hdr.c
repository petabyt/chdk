#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define NR_AUTO (0)                 // have to explictly reset value back to 0 to enable auto
static long *nrflag = (long*)(0xCF68+0xC); // sx510 101a Found @ 0xff2adfe4 (0xcf68) & 0xff2adfe8 (+0xC)

#include "../../../generic/capt_seq.c"
