#ifndef ZEBRA_H
#define ZEBRA_H

#define ZEBRA_DRAW_NONE             0
#define ZEBRA_DRAW_HISTO            1
#define ZEBRA_DRAW_OSD              2

#define ZEBRA_MODE_BLINKED_1        0
#define ZEBRA_MODE_BLINKED_2        1
#define ZEBRA_MODE_BLINKED_3        2
#define ZEBRA_MODE_SOLID            3
#define ZEBRA_MODE_ZEBRA_1          4
#define ZEBRA_MODE_ZEBRA_2          5

struct libzebra_sym {
	int version;
    int (*gui_osd_draw_zebra)(int show);
};

extern struct libzebra_sym* libzebra;
extern struct libzebra_sym* module_zebra_load();	// 0fail, addr-ok

#endif
