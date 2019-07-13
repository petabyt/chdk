#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1 // see stubs_min.S
#define NR_AUTO (0)        // have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 350  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"
