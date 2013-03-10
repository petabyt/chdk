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
    void (*load_edge_overlay)(const char* fn);
    void (*save_edge_overlay)(void);
};

extern struct libedgeovr_sym* libedgeovr;
extern struct libedgeovr_sym* module_edgeovr_load();	// 0fail, addr-ok
extern void module_restore_edge(void **buf, int *state);
extern void module_save_edge(void* buf, int state);

#endif
