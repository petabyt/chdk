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

extern struct libcurves_sym* libcurves;
extern struct libcurves_sym* module_curves_load();		// 0fail, addr-ok

//-------------------------------------------------------------------

#endif
