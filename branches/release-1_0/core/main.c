#include "platform.h"
#include "core.h"
#include "conf.h"
#include "keyboard.h"
#include "stdlib.h"
#include "gui.h"
#include "histogram.h"
#include "raw.h"
#ifdef OPT_EDGEOVERLAY
    #include "edgeoverlay.h"
#endif
static int raw_need_postprocess;
static volatile int spytask_can_start;
#ifdef CAM_HAS_GPS
    extern void wegpunkt();
#endif

void core_hook_task_create(void *tcb)
{
}

void core_hook_task_delete(void *tcb)
{
char *name = (char*)(*(long*)((char*)tcb+0x34));
 if (strcmp(name,"tInitFileM")==0) core_spytask_can_start();
}


long core_get_noise_reduction_value()
{
    return conf.raw_nr;
}


void dump_memory()
{
    int fd;
    static int cnt=1;
    static char fn[32];

    started();
        mkdir("A/DCIM");
        mkdir("A/DCIM/100CANON");
    sprintf(fn, "A/DCIM/100CANON/CRW_%04d.JPG", cnt++);
    fd = open(fn, O_WRONLY|O_CREAT, 0777);
    if (fd) {
        long val0 = *((long*)(0|CAM_UNCACHED_BIT));
        write(fd, &val0, 4);
        write(fd, (void*)4, MAXRAMADDR-3);   // MAXRAMADDR is last valid RAM location
        close(fd);
    }
    vid_bitmap_refresh();
    finished();
}

int core_get_free_memory() {
#if defined(OPT_EXMEM_MALLOC) && !defined(OPT_EXMEM_TESTING)
    // If using the exmem / suba memory allocation system then don't need
    // to try allocating memory to find out how much is available
    // Call function to scan free list for the largest free block available.
    cam_meminfo camera_meminfo;
    GetExMemInfo(&camera_meminfo);
    return camera_meminfo.free_block_max_size;
#elif defined(CAM_FIRMWARE_MEMINFO)
    // Call firmware function to fill memory info structure and return size of largest free block
    cam_meminfo camera_meminfo;
    GetMemInfo(&camera_meminfo);
    return camera_meminfo.free_block_max_size;
#else
    int size, l_size, d;
    char* ptr;

    size = 16;
    while (1) {
        ptr= malloc(size);
        if (ptr) {
            free(ptr);
            size <<= 1;
        } else
            break;
    }

    l_size = size;
    size >>= 1;
    d=1024;
    while (d) {
        ptr = malloc(size);
        if (ptr) {
            free(ptr);
            d = l_size-size;
            if (d<0) d=-d;
            l_size = size;
            size += d>>1;
        } else {
            d = size-l_size;
            if (d<0) d=-d;
            l_size = size;
            size -= d>>1;
        }
        
    }
    return size-1;
#endif
}

static volatile long raw_data_available;

/* called from another process */
void core_rawdata_available()
{
    raw_data_available = 1;
}

void core_spytask_can_start() {
    spytask_can_start = 1;
}

void core_spytask()
{
    int cnt = 1;
    int i=0;

    raw_need_postprocess = 0;

    spytask_can_start=0;

#ifdef OPT_EXMEM_MALLOC
    exmem_malloc_init();
#endif

#ifdef CAM_CHDK_PTP
    init_chdk_ptp_task();
#endif

    while((i++<400) && !spytask_can_start) msleep(10);

    started();
    msleep(50);
    finished();
    drv_self_unhide();

    conf_restore();
    gui_init();

#if CAM_CONSOLE_LOG_ENABLED
    extern void cam_console_init();
    cam_console_init();
#endif

    mkdir("A/CHDK");
    mkdir("A/CHDK/FONTS");
    mkdir("A/CHDK/SYMBOLS");
    mkdir("A/CHDK/SCRIPTS");
    mkdir("A/CHDK/LANG");
    mkdir("A/CHDK/BOOKS");
    mkdir("A/CHDK/GRIDS");
#ifdef OPT_CURVES
    mkdir("A/CHDK/CURVES");
#endif
    mkdir("A/CHDK/DATA");
    mkdir("A/CHDK/LOGS");
#ifdef OPT_EDGEOVERLAY
    mkdir("A/CHDK/EDGE");
#endif
    auto_started = 0;

#ifdef OPT_SCRIPTING
    if (conf.script_startup==1) script_autostart();				// remote autostart
    if (conf.script_startup==2) {
        conf.script_startup=0;
        conf_save();
        script_autostart();
    }
#endif

    while (1){

#ifdef  CAM_LOAD_CUSTOM_COLORS
        load_chdk_palette();
#endif

        if (raw_data_available) {
            raw_need_postprocess = raw_savefile();
            hook_raw_save_complete();
            raw_data_available = 0;
#ifdef CAM_HAS_GPS
            if( (int)conf.gps_waypoint_save == 1 ) wegpunkt();
#endif
            continue;
        }

        if ((state_shooting_progress != SHOOTING_PROGRESS_PROCESSING) || recreview_hold)
        {
            if (((cnt++) & 3) == 0)
                gui_redraw();
        }

        if (state_shooting_progress != SHOOTING_PROGRESS_PROCESSING)
        {
            histogram_process();
#ifdef OPT_EDGEOVERLAY
            if(conf.edge_overlay_thresh && conf.edge_overlay_enable) edge_overlay();
#endif
        }

        if ((state_shooting_progress == SHOOTING_PROGRESS_PROCESSING) && (!shooting_in_progress())) {
            state_shooting_progress = SHOOTING_PROGRESS_DONE;
            if (raw_need_postprocess) raw_postprocess();
        }

#ifdef DEBUG_PRINT_TO_LCD
        char osd_buf[30];
        sprintf(osd_buf, "%d", cnt );	// modify cnt to what you want to display
        draw_txt_string(2, 2, osd_buf, conf.osd_color);
#endif
        msleep(20);
    }
}

long ftell(FILE *file) {
    if(!file) return -1;
    return file->pos;
}
