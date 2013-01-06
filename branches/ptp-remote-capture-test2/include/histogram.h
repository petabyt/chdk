#ifndef HISTOGRAM_H
#define HISTOGRAM_H

// CHDK Histogram OSD interface

// Note: used in modules and platform independent code. 
// Do not add platform dependent stuff in here (#ifdef/#endif compile options or camera dependent values)

#define HISTO_WIDTH                 128 // Note code is optimised for this value, it should not be changed!
#define HISTO_HEIGHT                50

extern void histogram_process();
extern void gui_osd_draw_histo();

extern void live_histogram_process_quick();
extern void live_histogram_end_process();
extern int live_histogram_get_range(int from, int to);
extern int live_histogram_read_y(int *buf);

#endif
