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
#if defined(CAM_COLORMATRIX1)
    { CAM_COLORMATRIX1 },
    cam_CFAPattern, cam_CalibrationIlluminant1,
#else
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    0, 0,
#endif
};

_cam_screen camera_screen =
{
    CAM_SCREEN_WIDTH, CAM_SCREEN_HEIGHT, CAM_SCREEN_WIDTH * CAM_SCREEN_HEIGHT,
    CAM_BITMAP_WIDTH, CAM_BITMAP_HEIGHT, CAM_BITMAP_WIDTH * CAM_BITMAP_HEIGHT,
    EDGE_HMARGIN, CAM_TS_BUTTON_BORDER,
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
    },
    {
#if defined(OPT_GPS)
    PROPCASE_GPS,
#else
    0,
#endif
    PROPCASE_ORIENTATION_SENSOR,
    PROPCASE_TV, PROPCASE_AV, PROPCASE_MIN_AV,
    PROPCASE_EV_CORRECTION_2, 
    PROPCASE_FLASH_MODE, PROPCASE_FLASH_FIRE, 
    PROPCASE_METERING_MODE, PROPCASE_WB_ADJ,
    },
    ROMBASEADDR, MAXRAMADDR,
};

//==========================================================

volatile int chdk_started_flag=0;

static int raw_need_postprocess;
static volatile int spytask_can_start;

void core_hook_task_create(void *tcb) {
}

void core_hook_task_delete(void *tcb) {
    char *name = (char*)(*(long*)((char*)tcb+0x34));
    if (strcmp(name,"tInitFileM")==0) core_spytask_can_start();
}

long core_get_noise_reduction_value() {
    return conf.raw_nr;
}

void dump_memory() {
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

// called from another process
void core_rawdata_available() {
    raw_data_available = 1;
}

void core_spytask_can_start() {
    spytask_can_start = 1;
}

void core_spytask() {
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
    cam_console_init();
#endif

    mkdir("A/CHDK");
    mkdir("A/CHDK/FONTS");
    mkdir("A/CHDK/SYMBOLS");
    mkdir("A/CHDK/SCRIPTS");
    mkdir("A/CHDK/LANG");
    mkdir("A/CHDK/BOOKS");
    mkdir("A/CHDK/MODULES");
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
    if (conf.script_startup==1) script_autostart();    // remote autostart
    if (conf.script_startup==2) {
        conf.script_startup=0;
        conf_save();
        script_autostart();
    }
#endif

    while (1) {

#ifdef  CAM_LOAD_CUSTOM_COLORS
        load_chdk_palette();
#endif

        if (raw_data_available) {
            raw_need_postprocess = raw_savefile();
            hook_raw_save_complete();
            raw_data_available = 0;
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
            if(conf.edge_overlay_thresh && conf.edge_overlay_enable) {

				// We need to skip first tick because stability
				static int skip_counter=1;
				
				if (skip_counter>0) {
					skip_counter--;
				}
				else if (module_edgeovr_load()) {
					libedgeovr->edge_overlay();
				}
			}
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
