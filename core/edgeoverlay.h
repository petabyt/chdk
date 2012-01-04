#ifndef EDGE_OVERLAY_H
#define EDGE_OVERLAY_H

// steps for up/down/left/right moving the overlay in ALT mode
#define XINC 6
#define YINC 2

// if you change this, remember to change the mkdir in main too
#define EDGE_SAVE_DIR "A/CHDK/EDGE"

struct libedgeovr_sym {
	int  version;
	void (*edge_overlay)();
	void (*save_edge_overlay)(void);
	void (*load_edge_overlay)( const char* );
};


// Defines of exported to chdk symbols
#ifdef THIS_IS_CHDK_CORE
	// This section is for CHDK core
	extern struct libedgeovr_sym* libedgeovr;
#else
	// This section is for module
void edge_overlay();
void save_edge_overlay(void);
void load_edge_overlay( const char* );
#endif

#endif
