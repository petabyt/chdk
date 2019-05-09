#include "stubs_asm.h"

DEF(enabled_refresh_physical_screen,    0x392C + 0x10)  // sub_FF8944D4 (0xFF8944D8 + 0xFF8944F4)
//DEF(some_flag_for_af_scan,              0x6778 + 0x08) // Found @FF9619F0

// the original some_flag_for_af_scan should not be used, as the fw's MakeAFScan function is not called
.globl some_flag_for_af_scan
some_flag_for_af_scan: .long 0
