#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"


extern long link_bss_start;
extern long link_bss_end;
extern void boot();

void startup() {
    long *bss = &link_bss_start;
    // sanity check
    if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)) {
        started();
        shutdown();
    }
    // initialize .bss senment
    while (bss<&link_bss_end)
        *bss++ = 0;
    boot();
}

const int zoom_points = 1;
extern int _GetLensCurrentFocalLength(void);
extern int _GetLensWideFocalLength(void);

int get_effective_focal_length(__attribute__ ((unused))int zp) {
    return _GetLensCurrentFocalLength() * 1600;
}

int get_focal_length(__attribute__ ((unused))int zp) {
    return _GetLensCurrentFocalLength() * 1000;
}

int get_zoom_x(__attribute__ ((unused))int zp) {
    return _GetLensCurrentFocalLength()*100 / (_GetLensWideFocalLength()*100);
}

long get_vbatt_min()
{
    return 2*3300;
}


long get_vbatt_max()
{
    return 2*4168;  // 4168 original battery just charged ASM1989
}
