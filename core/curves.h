#ifndef CURVES_H
#define CURVES_H

#define CURVE_DIR "A/CHDK/CURVES"


// Defines of exported to chdk symbols
#ifdef THIS_IS_CHDK_CORE
	// This section is for CHDK core
	extern void (*curve_set_mode)();
	extern void (*curve_init_mode)();
	extern void (*curve_apply)();
#else
	// This section is for module
	extern void curve_set_mode();
	extern void curve_init_mode();
	extern void curve_apply();
#endif

//-------------------------------------------------------------------
//-------------------------------------------------------------------

#endif
