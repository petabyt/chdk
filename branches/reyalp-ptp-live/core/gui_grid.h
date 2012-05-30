#ifndef GUI_GRID_H
#define GUI_GRID_H

struct libgrids_sym {
	int version;

    void (*gui_grid_draw_osd)(int force);
    void (*grid_lines_load)(const char *fn);
};

//-------------------------------------------------------------------
// Defines of exported to chdk symbols
#ifdef THIS_IS_CHDK_CORE
	// This section is for CHDK core
	extern struct libgrids_sym* libgrids;
    extern struct libgrids_sym* module_grids_load();		// 0fail, addr-ok
#else
	// This section is for module
    extern void gui_grid_draw_osd(int force);
    extern void grid_lines_load(const char *fn);
#endif

extern struct libgrids_sym* module_grids_load();		// 0fail, addr-ok
extern void module_grids_unload();

//-------------------------------------------------------------------
#endif
