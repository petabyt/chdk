#include "lolevel.h"
#include "platform.h"
#include "core.h"

// NOTE auto in P mode doesn't seem to ever enable dark frame, even if you override > 1.3 sec
// TO DO: This value was copied from ixus140
static long *nrflag = (long*)(0xE4F0+4);

#include "../../../generic/capt_seq.c"
