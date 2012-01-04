#ifndef CURVES_H
#define CURVES_H

#define CURVE_DIR "A/CHDK/CURVES"

struct libcurves_sym {
	int version;

	void (*curve_init_mode)();
	void (*curve_apply)();
};


// Defines of exported to chdk symbols
#ifdef THIS_IS_CHDK_CORE
	// This section is for CHDK core
	extern struct libcurves_sym* libcurves;
#else
	// This section is for module
	extern void curve_init_mode();
	extern void curve_apply();
#endif

//-------------------------------------------------------------------
//-------------------------------------------------------------------

#endif
