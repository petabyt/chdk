#include "stubs_asm.h"

#define NULLSUB 0xFF810B24

DEF(enabled_refresh_physical_screen,	0x3A68 + 0x14) // FF8A2E2C + FF8A2E54

DEF(active_palette_buffer,				0x9018)		// FFA00618
DEF(palette_buffer,						0xB41E4)	// FFA009DC
DEF(palette_control,					0x9010)		// FFA006D0
