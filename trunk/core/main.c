#include "platform.h"
#include "core.h"
#include "conf.h"
#include "keyboard.h"
#include "stdlib.h"
#include "gui.h"
#include "histogram.h"
#include "raw.h"
#ifdef OPT_EDGEOVERLAY
    #include "modules.h"
#endif

#include "module_load.h"
#include "gui_draw.h"

//==========================================================
// Data Structure to store camera specific information
// Used by modules to ensure module code is platform independent

_cam_sensor camera_sensor = { 
    MAKE_API_VERSION(1,0),

    CAM_SENSOR_BITS_PER_PIXEL, 
    CAM_BLACK_LEVEL, CAM_WHITE_LEVEL,
    CAM_RAW_ROWS, CAM_RAW_ROWPIX, (CAM_RAW_ROWPIX*CAM_SENSOR_BITS_PER_PIXEL)/8, CAM_RAW_ROWS * ((CAM_RAW_ROWPIX*CAM_SENSOR_BITS_PER_PIXEL)/8),
#if defined(CAM_ACTIVE_AREA_X1) && defined(CAM_JPEG_WIDTH)
    {{
        (CAM_ACTIVE_AREA_X2-CAM_ACTIVE_AREA_X1-CAM_JPEG_WIDTH)/2, (CAM_ACTIVE_AREA_Y2-CAM_ACTIVE_AREA_Y1-CAM_JPEG_HEIGHT)/2,
        CAM_JPEG_WIDTH, CAM_JPEG_HEIGHT
    }},
    { { CAM_ACTIVE_AREA_Y1, CAM_ACTIVE_AREA_X1, CAM_ACTIVE_AREA_Y2, CAM_ACTIVE_AREA_X2 } }, 
#else
    {{
        0, 0,
        0, 0
    }},
    { { 0, 0, 0, 0 } }, 
#endif
#if defined(CAM_DNG_LENS_INFO)
    CAM_DNG_LENS_INFO,
#else
    { 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
#if defined(CAM_DNG_EXPOSURE_BIAS)
    { CAM_DNG_EXPOSURE_BIAS },
#else
    { -1 , 2 },
#endif
#if defined(cam_CFAPattern)
    cam_CFAPattern, 
#else
    0,
#endif
#if defined(CAM_COLORMATRIX1)
    cam_CalibrationIlluminant1,
    { CAM_COLORMATRIX1 },
#else
    0,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
#if defined(CAM_COLORMATRIX2)
    cam_CalibrationIlluminant2,
    { CAM_COLORMATRIX2 },
#else
    0,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
#if defined(CAM_CAMERACALIBRATION1)
    1,
    { CAM_CAMERACALIBRATION1 },
#else
    0,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
#if defined(CAM_CAMERACALIBRATION2)
    1,
    { CAM_CAMERACALIBRATION2 },
#else
    0,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
#if defined(CAM_FORWARDMATRIX1)
    1,
    { CAM_FORWARDMATRIX1 },
#else
    0,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
#if defined(CAM_FORWARDMATRIX2)
    1,
    { CAM_FORWARDMATRIX2 },
#else
    0,
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
#endif
};

_cam_screen camera_screen =
{
    CAM_SCREEN_WIDTH, CAM_SCREEN_HEIGHT, CAM_SCREEN_WIDTH * CAM_SCREEN_HEIGHT,
    CAM_BITMAP_WIDTH, CAM_BITMAP_HEIGHT, CAM_BITMAP_WIDTH * CAM_BITMAP_HEIGHT,
    EDGE_HMARGIN, CAM_TS_BUTTON_BORDER,
#if defined(CAM_ZEBRA_NOBUF)
    1,
#else
    0,
#endif
#if defined(CAM_ZEBRA_ASPECT_ADJUST)
    1,
#else
    0,
#endif
#if defined(CAM_HAS_VARIABLE_ASPECT)
    1,
#else
    0,
#endif
};

_cam_info camera_info =
{
    MAKE_API_VERSION(1,0),

    {
#if defined(PARAM_CAMERA_NAME)
    PARAM_CAMERA_NAME,
#else
    0,
#endif
#if defined(PARAM_OWNER_NAME)
    PARAM_OWNER_NAME,
#else
    0,
#endif
#if defined(PARAM_ARTIST_NAME)
    PARAM_ARTIST_NAME,
#else
    0,
#endif
#if defined(PARAM_COPYRIGHT)
    PARAM_COPYRIGHT,
#else
    0,
#endif
    },
    {
#if defined(CAM_HAS_GPS)
    PROPCASE_GPS,
#else
    0,
#endif
    PROPCASE_ORIENTATION_SENSOR,
    PROPCASE_TV, PROPCASE_AV, PROPCASE_MIN_AV,
    PROPCASE_EV_CORRECTION_2, 
    PROPCASE_FLASH_MODE, PROPCASE_FLASH_FIRE, 
    PROPCASE_METERING_MODE, PROPCASE_WB_ADJ,
#if defined(PROPCASE_ASPECT_RATIO)
    PROPCASE_ASPECT_RATIO,
#else
    0,
#endif
    PROPCASE_SHOOTING,
    },
    ROMBASEADDR, MAXRAMADDR,
};

//==========================================================

volatile int chdk_started_flag=0;

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

int core_get_free_memory()
{
    cam_meminfo camera_meminfo;

#if defined(OPT_EXMEM_MALLOC) && !defined(OPT_EXMEM_TESTING)
    // If using the exmem / suba memory allocation system then don't need
    // to try allocating memory to find out how much is available
    // Call function to scan free list for the largest free block available.
    GetExMemInfo(&camera_meminfo);
#else
    // Call function to fill memory info structure and return size of largest free block
    // If implemented this will use firmware function, otherwise it will calculate largest
    // free block
    GetMemInfo(&camera_meminfo);
#endif

    return camera_meminfo.free_block_max_size;
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
    mkdir("A/CHDK/MODULES");
    mkdir("A/CHDK/MODULES/CFG");
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
    if (conf.script_startup==1) script_autostart();             // remote autostart
    if (conf.script_startup==2) {
        conf.script_startup=0;
        conf_save();
        script_autostart();
    }
#endif

    // Calculate the value of get_tick_count() when the clock ticks over to the next second
    // Used to calculate the SubSecondTime value when saving DNG files.
    long t1, t2;
    t2 = time(0);
    do
    {
        t1 = t2;
        camera_info.tick_count_offset = get_tick_count();
        t2 = time(0);
        msleep(10);
    } while (t1 != t2);
    camera_info.tick_count_offset = camera_info.tick_count_offset % 1000;

    while (1)
    {

#ifdef  CAM_LOAD_CUSTOM_COLORS
        load_chdk_palette();
#endif

        if (raw_data_available)
        {
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

        // Unload any GUI menu modules
        extern void gui_kbd_unload_modules();
        gui_kbd_unload_modules();

        if (state_shooting_progress != SHOOTING_PROGRESS_PROCESSING)
        {
            if (conf.show_histo)
                histogram_process();

#ifdef OPT_EDGEOVERLAY
            if(((gui_get_mode()==GUI_MODE_NONE) || (gui_get_mode()==GUI_MODE_ALT)) && conf.edge_overlay_thresh && conf.edge_overlay_enable)
            {
                // We need to skip first tick because stability
                static int skip_counter=1;

                if (skip_counter>0)
                {
                    skip_counter--;
                }
                else if (module_edgeovr_load())
                {
                    libedgeovr->edge_overlay();
                }
            }
#endif
        }

        if ((state_shooting_progress == SHOOTING_PROGRESS_PROCESSING) && (!shooting_in_progress()))
        {
            state_shooting_progress = SHOOTING_PROGRESS_DONE;
            if (raw_need_postprocess) raw_postprocess();
        }

#ifdef DEBUG_PRINT_TO_LCD
        char osd_buf[30];
        sprintf(osd_buf, "%d", cnt );	// modify cnt to what you want to display
        draw_txt_string(2, 2, osd_buf, conf.osd_color);
#endif

        // Process async module unload requests
        module_tick_unloader();

        msleep(20);
        chdk_started_flag=1;
    }
}

long ftell(FILE *file) {
    if(!file) return -1;
    return file->pos;
}
