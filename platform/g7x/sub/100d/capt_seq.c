#include "lolevel.h"
#include "platform.h"
#include "core.h"

// TODO dummy
static long fake_nrflag=0;
static long *nrflag=&fake_nrflag;
// NOTE sx280hs had
//#define NR_AUTO (0) // not needed (in fact, it makes the camera crash)

#include "../../../generic/capt_seq.c"

