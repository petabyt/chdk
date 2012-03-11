#include "stubs_asm.h"

//beta5
DEF(enabled_refresh_physical_screen,0x53C4+0x14) //changed to fix error when displaying menu, was 0x20 FF0A99C0 

//added beta2
DEF(focus_len_table, 0xfffea288)		  // search for 21500 (longest focus length in micrometers) & 4300 (shortest length)

//not touched
DEF(led_table, 0x258C + 0x04)             // FF0557C4

