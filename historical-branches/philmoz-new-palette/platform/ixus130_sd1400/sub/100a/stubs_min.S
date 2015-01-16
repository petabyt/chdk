#include "stubs_asm.h"

// RAM addresses

DEF(led_table, 0x2474)    // R0 -> 0x246c + 0x8
DEF(enabled_refresh_physical_screen, 0x8e30)    // ff9f8cb8, 0x8e10 + 0x20 = 0x8e30

//DEF(viewport_buffers, 0xffb3da8c) // Found @0xff84f52c
