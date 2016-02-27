#include "platform.h"
#include "stdlib.h"
#include "core.h"
#include "conf.h"
#include "gui.h"
#include "gui_draw.h"
#include "histogram.h"
#include "raw.h"
#include "console.h"
#include "shooting.h"

#include "edgeoverlay.h"
#include "module_load.h"

#ifdef CAM_HAS_GPS
  #include "gps.h"
#endif

//==========================================================

static char osd_buf[50];

//==========================================================

volatile int chdk_started_flag=0;

int no_modules_flag;

static volatile int spytask_can_start;

static unsigned int memdmptick = 0;
volatile int memdmp_delay = 0; // delay in seconds

void schedule_memdump()
{
    memdmptick = get_tick_count() + memdmp_delay * 1000;
}

void dump_memory()
{
    int fd;
    static int cnt=1;
    static char fn[32];

    // zero size means all RAM
    if (conf.memdmp_size == 0) conf.memdmp_size = (unsigned int)camera_info.maxramaddr + 1;
    // enforce RAM area
    if ((unsigned int)conf.memdmp_start > (unsigned int)camera_info.maxramaddr)
        conf.memdmp_start = 0;
    if ( (unsigned int)conf.memdmp_start + (unsigned int)conf.memdmp_size > ((unsigned int)camera_info.maxramaddr+1) )
        conf.memdmp_size = (unsigned int)camera_info.maxramaddr + 1 - (unsigned int)conf.memdmp_start;

    started();
    // try to avoid hanging the camera
    if ( !is_video_recording() ) {
        mkdir("A/DCIM");
        mkdir("A/DCIM/100CANON");
        fd = -1;
        do {
            sprintf(fn, "A/DCIM/100CANON/CRW_%04d.JPG", cnt++);
            if (stat(fn,0) != 0) {
                fd = open(fn, O_WRONLY|O_CREAT, 0777);
                break;
            }
        } while(cnt<9999);
        if (fd>=0) {
            if ( conf.memdmp_start == 0 ) {
                long val0 = *((long*)(0|CAM_UNCACHED_BIT));
                write(fd, &val0, 4);
                if  (conf.memdmp_size > 4) {
                    write(fd, (void*)4, conf.memdmp_size - 4);
                }
            }
            else {
                write(fd, (void*)conf.memdmp_start, conf.memdmp_size);
            }
            close(fd);
        }
        vid_bitmap_refresh();
    }
    finished();
}

int core_get_free_memory()
{
    cam_meminfo camera_meminfo;
    GetCombinedMemInfo(&camera_meminfo);
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

// remote autostart
void script_autostart()
{
    // Tell keyboard task we are in <ALT> mode
    enter_alt();
    // We were called from the GUI task so switch to <ALT> mode before switching to Script mode
    gui_activate_alt_mode();
    // Switch to script mode and start the script running
    script_start_gui( 1 );
}

void core_spytask()
{
    int cnt = 1;
    int i=0;
#ifdef CAM_HAS_GPS
    int gps_delay_timer = 200 ;
    int gps_state = -1 ;
#endif
#if (OPT_DISABLE_CAM_ERROR)
    extern void DisableCamError();
    int dce_cnt=0;
    int dce_prevmode=0;
    int dce_nowmode;
#endif
    
    parse_version(&chdk_version, BUILD_NUMBER, BUILD_SVNREV);

    // Init camera_info bits that can't be done statically
    camera_info_init();

    spytask_can_start=0;

    extern void aram_malloc_init(void);
    aram_malloc_init();

    extern void exmem_malloc_init(void);
    exmem_malloc_init();

#ifdef CAM_CHDK_PTP
    extern void init_chdk_ptp_task();
    init_chdk_ptp_task();
#endif

    while((i++<400) && !spytask_can_start) msleep(10);

    started();
    msleep(50);
    finished();

#if !CAM_DRYOS
    drv_self_unhide();
#endif

    conf_restore();

    extern void gui_init();
    gui_init();

#if CAM_CONSOLE_LOG_ENABLED
    extern void cam_console_init();
    cam_console_init();
#endif

    static char *chdk_dirs[] =
    {
        "A/CHDK",
        "A/CHDK/FONTS",
        "A/CHDK/SYMBOLS",
        "A/CHDK/SCRIPTS",
        "A/CHDK/LANG",
        "A/CHDK/BOOKS",
        "A/CHDK/MODULES",
        "A/CHDK/MODULES/CFG",
        "A/CHDK/GRIDS",
        "A/CHDK/CURVES",
        "A/CHDK/DATA",
        "A/CHDK/LOGS",
        "A/CHDK/EDGE",
    };
    for (i = 0; i < sizeof(chdk_dirs) / sizeof(char*); i++)
        mkdir_if_not_exist(chdk_dirs[i]);

    no_modules_flag = stat("A/CHDK/MODULES/FSELECT.FLT",0) ? 1 : 0 ;

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

    // remote autostart
    if (conf.script_startup==SCRIPT_AUTOSTART_ALWAYS)
    {
        script_autostart();
    }
    else if (conf.script_startup==SCRIPT_AUTOSTART_ONCE)
    {
        conf.script_startup=SCRIPT_AUTOSTART_NONE;
        conf_save();
        script_autostart();
    }

    shooting_init();

    while (1)
    {
        // Set up camera mode & state variables
        mode_get();

        extern void set_palette();
        set_palette();

#if (OPT_DISABLE_CAM_ERROR)
        dce_nowmode = camera_info.state.mode_play;
        if (dce_prevmode==dce_nowmode)
        {                       //no mode change
            dce_cnt++;          // overflow is not a concern here
        }
        else
        {                       //mode has changed
            dce_cnt=0;
        }
        if (dce_cnt==100)
        {                       // 1..2s past play <-> rec mode change
            DisableCamError();
        }
        dce_prevmode=dce_nowmode;
#endif

        if ( memdmptick && (get_tick_count() >= memdmptick) )
        {
            memdmptick = 0;
            dump_memory();
        }

#ifdef CAM_HAS_GPS
        if ( --gps_delay_timer == 0 )
        {
            gps_delay_timer = 50 ;
            if ( gps_state != (int)conf.gps_on_off )
            {
                gps_state = (int)conf.gps_on_off ;
                init_gps_startup(!gps_state) ; 
            }
        }
#endif        
        
        // Change ALT mode if the KBD task has flagged a state change
        gui_activate_alt_mode();

#ifdef  CAM_LOAD_CUSTOM_COLORS
        // Color palette function
        extern void load_chdk_palette();
        load_chdk_palette();
#endif

        if (raw_data_available)
        {
            raw_process();
            extern void hook_raw_save_complete();
            hook_raw_save_complete();
            raw_data_available = 0;
#ifdef CAM_HAS_GPS
            if (((int)conf.gps_on_off == 1) && ((int)conf.gps_waypoint_save == 1)) gps_waypoint();
#endif
#if defined(CAM_CALC_BLACK_LEVEL)
            // Reset to default in case used by non-RAW process code (e.g. raw merge)
            camera_sensor.black_level = CAM_BLACK_LEVEL;
#endif
            continue;
        }

        if ((camera_info.state.state_shooting_progress != SHOOTING_PROGRESS_PROCESSING) || recreview_hold)
        {
            if (((cnt++) & 3) == 0)
                gui_redraw();
        }

        if (camera_info.state.state_shooting_progress != SHOOTING_PROGRESS_PROCESSING)
        {
            if (conf.show_histo)
                libhisto->histogram_process();

            if ((camera_info.state.gui_mode_none || camera_info.state.gui_mode_alt) && conf.edge_overlay_thresh && conf.edge_overlay_enable)
            {
                // We need to skip first tick because stability
                if (chdk_started_flag)
                {
                    libedgeovr->edge_overlay();
                }
            }
        }

        if ((camera_info.state.state_shooting_progress == SHOOTING_PROGRESS_PROCESSING) && (!shooting_in_progress()))
        {
            camera_info.state.state_shooting_progress = SHOOTING_PROGRESS_DONE;
        }

        i = 0;

#ifdef DEBUG_PRINT_TO_LCD
        sprintf(osd_buf, "%d", cnt );	// modify cnt to what you want to display
        draw_txt_string(1, i++, osd_buf, user_color(conf.osd_color));
#endif
#if defined(OPT_FILEIO_STATS)
        sprintf(osd_buf, "%3d %3d %3d %3d %3d %3d %3d %4d",
                camera_info.fileio_stats.fileio_semaphore_errors, camera_info.fileio_stats.close_badfile_count,
                camera_info.fileio_stats.write_badfile_count, camera_info.fileio_stats.open_count,
                camera_info.fileio_stats.close_count, camera_info.fileio_stats.open_fail_count,
                camera_info.fileio_stats.close_fail_count, camera_info.fileio_stats.max_semaphore_timeout);
        draw_txt_string(1, i++, osd_buf,user_color( conf.osd_color));
#endif

        if (camera_info.perf.md_af_tuning)
        {
            sprintf(osd_buf, "MD last %-4d min %-4d max %-4d avg %-4d", 
                camera_info.perf.af_led.last, camera_info.perf.af_led.min, camera_info.perf.af_led.max, 
                (camera_info.perf.af_led.count>0)?camera_info.perf.af_led.sum/camera_info.perf.af_led.count:0);
            draw_txt_string(1, i++, osd_buf, user_color(conf.osd_color));
        }

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
