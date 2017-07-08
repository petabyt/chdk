#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1          // see stubs_entry.S
#define NR_AUTO (0)                 // have to explictly reset value back to 0 to enable auto

#include "../../../generic/capt_seq.c"

void __attribute__((naked,noinline)) block_sv_cooking()
{
    // On G1X (possibly others), when Tv >= 1s and ISO >= 400, then the camera shoots at 1/2 ISO and cooks the JPG/CR2 image data to compensate
    // Setting this property blocks the firmware from doing this.
    static short v = 1;
    set_property_case(77, &v, sizeof(v));
}
