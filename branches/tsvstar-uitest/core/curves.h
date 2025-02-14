#ifndef CURVES_H
#define CURVES_H

#define CURVE_DIR "A/CHDK/CURVES"

struct libcurves_sym {
	int version;

	void (*curve_init_mode)();
	void (*curve_apply)();
    void (*curve_set_mode)();
    void (*curve_set_file)();
};


// Defines of exported to chdk symbols
#ifdef THIS_IS_CHDK_CORE
	// This section is for CHDK core
	extern struct libcurves_sym* libcurves;
    extern struct libcurves_sym* module_curves_load();		// 0fail, addr-ok
#else
	// This section is for module
    extern void curve_set_mode();
    extern void curve_set_file();
	extern void curve_init_mode();
	extern void curve_apply();
#endif

//-------------------------------------------------------------------

#endif
