#include "stubs_asm.h"

DEF(enabled_refresh_physical_screen,    0x392C + 0x10)  // sub_FF8943C8 (0xFF8943CCC + 0xFF8943E8)
//DEF(some_flag_for_af_scan,              0x6778 + 0x08)  // Found @FF96194c

// the original some_flag_for_af_scan should not be used, as the fw's MakeAFScan function is not called
.globl some_flag_for_af_scan
some_flag_for_af_scan: .long 0
