#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#define HISTO_WIDTH                 128 // Note code is optimised for this value, it should not be changed!
#define HISTO_HEIGHT                50

extern void histogram_process();
extern void gui_osd_draw_histo();

void live_histogram_process_quick();
void live_histogram_end_process();
int live_histogram_get_range(int from, int to);
int live_histogram_read_y(int *buf);

#endif
