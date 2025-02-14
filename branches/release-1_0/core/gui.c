#include "stdlib.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "conf.h"
#include "camera.h"
#include "font.h"
#include "lang.h"
#include "gui.h"
#include "gui_lang.h"
#include "gui_draw.h"
#include "gui_menu.h"
#include "gui_palette.h"
#include "gui_mbox.h"
#include "gui_mpopup.h"
#ifdef OPT_GAME_REVERSI
    #include "gui_reversi.h"
#endif
#ifdef OPT_GAME_SOKOBAN
    #include "gui_sokoban.h"
#endif
#ifdef OPT_GAME_CONNECT4
    #include "gui_4wins.h"
#endif
#ifdef OPT_GAME_MASTERMIND
    #include "gui_mastermind.h"
#endif
#ifdef OPT_GAME_TETRIS
    #include "gui_tetris.h"
#endif
#include "console.h"
#ifdef OPT_DEBUGGING
    #include "gui_debug.h"
    #include "gui_bench.h"
#endif
#include "gui_fselect.h"
#include "gui_batt.h"
#include "gui_usb.h"
#include "gui_space.h"
#include "gui_osd.h"
#ifdef OPT_TEXTREADER
    #include "gui_read.h"
#endif
#ifdef OPT_CALENDAR
    #include "gui_calendar.h"
#endif
#include "gui_grid.h"
#include "histogram.h"
#include "motion_detector.h"
#include "raw.h"
#include "dng.h"
#ifdef OPT_CURVES
	#include "curves.h"
#endif
#ifdef OPT_EDGEOVERLAY
    #include "edgeoverlay.h"
#endif
#ifdef OPT_SCRIPTING
    #include "script.h"
    int script_params_has_changed=0;
#endif
//-------------------------------------------------------------------

#define OPTIONS_AUTOSAVE
#define SPLASH_TIME               20

//shortcuts
//------------------------------------------------------------------
// #define KEY_NONE (KEY_DUMMY+1)

#if defined(CAMERA_a580) // Cam has not erase button AND Half press shoot button + Left sets AFL, + Up sets AEL!
    //Alt mode
    #define SHORTCUT_TOGGLE_RAW          KEY_DISPLAY
    #define SHORTCUT_MF_TOGGLE           KEY_UP
    //Half press shoot button
    #define SHORTCUT_TOGGLE_HISTO        KEY_DOWN
    #define SHORTCUT_TOGGLE_ZEBRA        KEY_MENU
    #define SHORTCUT_TOGGLE_OSD          KEY_RIGHT
    #define SHORTCUT_DISABLE_OVERRIDES   KEY_DISPLAY
    //Alt mode & Manual mode    
    #define SHORTCUT_SET_INFINITY        KEY_DISPLAY
    #define SHORTCUT_SET_HYPERFOCAL      KEY_DOWN
    // For models without ZOOM_LEVER  (#if !CAM_HAS_ZOOM_LEVER)
    // SHORTCUT_SET_INFINITY is not used
    // KEY_DISPLAY is used for gui_subj_dist_override_koef_enum;
    // KEY_LEFT/KEY_RIGHT is used for gui_subj_dist_override_value_enum (because of no separate ZOOM_IN/OUT)

#elif defined(CAMERA_a3300) || defined(CAMERA_a3200)// a3300 has no erase button, so make DISP button the toggle_raw and Alt +/- shortcuts.
    //Alt mode
    // NOTE both of these conflict with adjustable alt
    #define SHORTCUT_TOGGLE_RAW          KEY_DISPLAY
    #define SHORTCUT_MF_TOGGLE           KEY_FACE
    //Half press shoot button    
    #define SHORTCUT_TOGGLE_HISTO        KEY_UP
    #define SHORTCUT_TOGGLE_ZEBRA        KEY_DOWN
    #define SHORTCUT_TOGGLE_OSD          KEY_RIGHT
    #define SHORTCUT_DISABLE_OVERRIDES   KEY_LEFT
    //Alt mode & Manual mode  
    #define SHORTCUT_SET_INFINITY        KEY_UP
    #define SHORTCUT_SET_HYPERFOCAL      KEY_DOWN

#elif !CAM_HAS_ERASE_BUTTON
    //Alt mode
    #define SHORTCUT_TOGGLE_RAW          KEY_DISPLAY
    #define SHORTCUT_MF_TOGGLE           KEY_UP
    //Half press shoot button   
    #define SHORTCUT_TOGGLE_HISTO        KEY_DOWN
    #define SHORTCUT_TOGGLE_ZEBRA        KEY_MENU
    #define SHORTCUT_TOGGLE_OSD          KEY_RIGHT
    #define SHORTCUT_DISABLE_OVERRIDES   KEY_LEFT
    //Alt mode & Manual mode    
    #define SHORTCUT_SET_INFINITY        KEY_DISPLAY
    #define SHORTCUT_SET_HYPERFOCAL      KEY_DOWN
    // For models without ZOOM_LEVER  (#if !CAM_HAS_ZOOM_LEVER)
    // SHORTCUT_SET_INFINITY is not used
    // KEY_DISPLAY is used for gui_subj_dist_override_koef_enum;
    // KEY_LEFT/KEY_RIGHT is used for gui_subj_dist_override_value_enum (because of no separate ZOOM_IN/OUT)

#elif defined(CAMERA_g7) || defined(CAMERA_sx10) || defined(CAMERA_sx1) ||defined(CAMERA_sx120is) || defined(CAMERA_sx20) || defined(CAMERA_sx30) || defined(CAMERA_sx40hs)
    //Alt mode
    #define SHORTCUT_TOGGLE_RAW          KEY_ERASE
    //Half press shoot button    
    #define SHORTCUT_TOGGLE_HISTO        KEY_DOWN
    #define SHORTCUT_TOGGLE_ZEBRA        KEY_LEFT
    #define SHORTCUT_TOGGLE_OSD          KEY_RIGHT
    #define SHORTCUT_DISABLE_OVERRIDES   KEY_UP
    //Alt mode & Manual mode  
    #define SHORTCUT_SET_INFINITY        KEY_UP
    #define SHORTCUT_SET_HYPERFOCAL      KEY_DOWN

#elif defined(CAMERA_sx100is) || defined(CAMERA_sx110is)
    //Alt mode
    #define SHORTCUT_TOGGLE_RAW          KEY_ERASE
    //Half press shoot button    
    #define SHORTCUT_TOGGLE_HISTO        KEY_UP
    #define SHORTCUT_TOGGLE_ZEBRA        KEY_DOWN
    #define SHORTCUT_TOGGLE_OSD          KEY_RIGHT
    #define SHORTCUT_DISABLE_OVERRIDES   KEY_LEFT
    //Alt mode & Manual mode  
    #define SHORTCUT_SET_INFINITY        KEY_UP
    #define SHORTCUT_SET_HYPERFOCAL      KEY_DOWN

#else
    //Alt mode
    #define SHORTCUT_TOGGLE_RAW          KEY_ERASE
    //Half press shoot button    
    #define SHORTCUT_TOGGLE_HISTO        KEY_UP
    #define SHORTCUT_TOGGLE_ZEBRA        KEY_LEFT
    #define SHORTCUT_TOGGLE_OSD          KEY_RIGHT
    #define SHORTCUT_DISABLE_OVERRIDES   KEY_DOWN
    //Alt mode & Manual mode  
    #define SHORTCUT_SET_INFINITY        KEY_UP
    #define SHORTCUT_SET_HYPERFOCAL      KEY_DOWN
    #ifndef CAM_HAS_MANUAL_FOCUS
        #define SHORTCUT_MF_TOGGLE       KEY_DISPLAY
    #endif
#endif

#if CAM_HAS_ZOOM_LEVER
    #define SHORTCUT_SD_SUB KEY_ZOOM_OUT
    #define SHORTCUT_SD_ADD KEY_ZOOM_IN
#endif

// forward declarations
//-------------------------------------------------------------------
extern void dump_memory();
// both from platform/generic/shooting.c
extern const char* tv_override[];
extern const int tv_override_amount;
extern const int tv_override_zero_shift;

static void gui_draw_osd();

#ifdef CAM_HAS_GPS
int exit_gpx_record=1;
int exit_gps_kompass=1;
int exit_gps_navi=1;
int exit_gps_data=1;

extern void init_gpx_record_task();
extern void init_gps_kompass_task();
extern void init_gps_trackback_task();
extern void gps_record(int arg);
extern void gps_get_data();
extern void write_timezone();
extern void write_home();
extern void gps_navigate_home();


static void gpx_start_stop(int arg);
static void show_kompass(int arg);
static void show_navi(int arg);

static void mark_timezone(int arg);
static void mark_home(int arg);
static void navigate_home(int arg);

extern int _CreateTask (const char *name, int prio, int stack_size /*?*/,void *entry, long parm /*?*/);

#endif
static void gui_draw_splash(char* logo, int logo_size);

void user_menu_save();
void user_menu_restore();
// Menu procs
//-------------------------------------------------------------------
static void gui_show_build_info(int arg);
static void gui_show_memory_info(int arg);
static void gui_draw_palette(int arg);
#ifdef OPT_GAME_REVERSI
    static void gui_draw_reversi(int arg);
#endif
#ifdef OPT_GAME_SOKOBAN
    static void gui_draw_sokoban(int arg);
#endif
#ifdef OPT_GAME_CONNECT4
    static void gui_draw_4wins(int arg);
#endif
#ifdef OPT_GAME_MASTERMIND
    static void gui_draw_mastermind(int arg);
#endif
#ifdef OPT_GAME_TETRIS
    static void gui_draw_tetris(int arg);
#endif
#ifdef OPT_DEBUGGING
    static void gui_draw_debug(int arg);
    static void gui_draw_bench(int arg);
    void gui_compare_props(int arg);
    static void gui_menuproc_break_card(int arg);
    static void gui_debug_shortcut(void);
    static void save_romlog(int arg);
#endif
static void gui_draw_fselect(int arg);
static void gui_draw_osd_le(int arg);
#ifdef OPT_TEXTREADER
    static void gui_draw_read(int arg);
    static void gui_draw_read_last(int arg);
#endif
static void gui_draw_load_menu_rbf(int arg);
static void gui_draw_load_symbol_rbf(int arg);      //AKA
#ifdef OPT_TEXTREADER
    static void gui_draw_load_rbf(int arg);
#endif
#ifdef OPT_CALENDAR
    static void gui_draw_calendar(int arg);
#endif
static void gui_draw_load_lang(int arg);
static void gui_menuproc_mkbootdisk(int arg);
#ifndef OPTIONS_AUTOSAVE
    static void gui_menuproc_save(int arg);
#endif
static void gui_menuproc_reset(int arg);
static void gui_grid_lines_load(int arg);
static void gui_raw_develop(int arg);
#if CAM_MULTIPART
    static const char* gui_menuproc_swap_partitions_enum(int change, int arg);
#endif
static void gui_menuproc_reset_files(int arg);
#ifdef OPT_CURVES
    static void gui_load_curve_selected(const char *fn);
    static void gui_load_curve(int arg);
#endif
static const char* gui_histo_mode_enum(int change, int arg);
static const char* gui_histo_layout_enum(int change, int arg);
static const char* gui_font_enum(int change, int arg);

#if CAM_ADJUSTABLE_ALT_BUTTON
    static const char* gui_alt_mode_button_enum(int change, int arg);
#endif
static const char* gui_alt_power_enum(int change, int arg);
static const char* gui_video_bitrate_enum(int change, int arg);
static const char* gui_av_override_enum(int change, int arg);
#if ZOOM_OVERRIDE
    static const char* gui_zoom_override_enum(int change, int arg);
#endif
static const char* gui_tv_override_koef_enum(int change, int arg);
static const char* gui_tv_override_value_enum(int change, int arg);
static const char* gui_tv_enum_type_enum(int change, int arg);
const char* gui_subj_dist_override_value_enum(int change, int arg);
const char* gui_subj_dist_override_koef_enum(int change, int arg);
const char* gui_user_menu_show_enum(int change, int arg);
static const char* gui_bad_pixel_enum(int change, int arg);
static const char* gui_video_af_key_enum(int change, int arg);
#ifdef OPT_CURVES
    static const char* gui_conf_curve_enum(int change, int arg);
#endif
#ifdef OPT_EDGEOVERLAY
    static void gui_menuproc_edge_save(int arg);
    static void gui_menuproc_edge_load(int arg);
#endif

#ifdef OPT_SCRIPTING
static void gui_load_script(int arg);
static void gui_load_script_default(int arg);
static const char* gui_script_param_set_enum(int change, int arg);
#endif

#if CAM_REMOTE
    static const char* gui_show_usb_info_enum(int change, int arg);
#endif
void rinit();

// Menu callbacks
//-------------------------------------------------------------------
void cb_autoiso_menu_change(unsigned int item); // Used from conf loader
static void cb_step_25();
static void cb_perc();
static void cb_volts();
static void cb_space_perc();
static void cb_space_mb();
static void cb_battery_menu_change(unsigned int item);
static void cb_zebra_restore_screen();
static void cb_zebra_restore_osd();
#if DNG_SUPPORT
    static void cb_change_dng(); 
    void gui_menuproc_badpixel_create(int arg);
#endif
#if defined (DNG_EXT_FROM)
    static void cb_change_dng_usb_ext();
#endif

// for memory info, duplicated from lowlevel
extern const char _start,_end;

#if CAM_MULTIPART
  char* partitions_enum=NULL;
#endif

#ifdef OPT_DEBUGGING
    static int debug_tasklist_start;
    static int debug_display_direction=1;
#endif

// Menu definition
//-------------------------------------------------------------------
static CMenuItem remote_submenu_items[] = {
    MENU_ITEM   (0x71,LANG_MENU_REMOTE_ENABLE,              MENUITEM_BOOL,                      &conf.remote_enable,            0 ),
    MENU_ITEM   (0x0 ,LANG_MENU_SYNCHABLE_REMOTE,           MENUITEM_SEPARATOR,                 0,                              0 ),
    MENU_ITEM   (0x71,LANG_MENU_SYNCHABLE_REMOTE_ENABLE,    MENUITEM_BOOL,                      &conf.ricoh_ca1_mode,           0 ),
    MENU_ITEM   (0x5c,LANG_MENU_SYNCH_ENABLE,               MENUITEM_BOOL,                      &conf.synch_enable,             0 ),
    MENU_ITEM   (0x5c,LANG_MENU_SYNCH_DELAY_ENABLE,         MENUITEM_BOOL,                      &conf.synch_delay_enable,       0 ),
    MENU_ITEM   (0x5c,LANG_MENU_SYNCH_DELAY_VALUE,          MENUITEM_INT|MENUITEM_F_UNSIGNED,   &conf.synch_delay_value,        0 ),
    MENU_ITEM   (0x5c,LANG_MENU_SYNCH_DELAY_COARSE_VALUE,   MENUITEM_INT|MENUITEM_F_UNSIGNED,   &conf.synch_delay_coarse_value, 0 ),
    MENU_ITEM   (0x5c,LANG_MENU_REMOTE_ZOOM_ENABLE,         MENUITEM_BOOL,                      &conf.remote_zoom_enable,       0 ),
    MENU_ITEM   (0x5f,LANG_MENU_REMOTE_ZOOM_TIMEOUT,        MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &conf.zoom_timeout, MENU_MINMAX(2,10)),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,                        0,                              0 ),
    {0}
};
static CMenu remote_submenu = {0x86,LANG_MENU_REMOTE_PARAM_TITLE, NULL, remote_submenu_items };


#ifdef OPT_SCRIPTING
static const char* gui_script_autostart_modes[]=            { "Off", "On", "Once"};
static CMenuItem script_submenu_items_top[] = {
    MENU_ITEM   (0x35,LANG_MENU_SCRIPT_LOAD,                MENUITEM_PROC,                      gui_load_script,            0 ),
    MENU_ITEM   (0x5f,LANG_MENU_SCRIPT_DELAY,               MENUITEM_INT|MENUITEM_F_UNSIGNED,   &conf.script_shoot_delay,   0 ),
    // remote autostart
    MENU_ENUM2  (0x5f,LANG_MENU_SCRIPT_AUTOSTART,           &conf.script_startup,               gui_script_autostart_modes ),

#if CAM_REMOTE
    MENU_ITEM   (0x86,LANG_MENU_REMOTE_PARAM,               MENUITEM_SUBMENU,                   &remote_submenu,            0 ),
#endif
    MENU_ITEM   (0x5d,LANG_MENU_SCRIPT_DEFAULT_VAL,         MENUITEM_PROC,                      gui_load_script_default,    0 ),
    MENU_ITEM   (0x5e,LANG_MENU_SCRIPT_PARAM_SET,           MENUITEM_ENUM,                      gui_script_param_set_enum,  0 ),
    MENU_ITEM   (0x5c,LANG_MENU_SCRIPT_PARAM_SAVE,          MENUITEM_BOOL,                      &conf.script_param_save,    0 ),
    MENU_ITEM   (0x0 ,(int)script_title,                    MENUITEM_SEPARATOR,                 0,                          0 ),
};

static CMenuItem script_submenu_items_bottom[] = {
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,                        0,                          0 ),
    {0}
};

static CMenuItem script_submenu_items[sizeof(script_submenu_items_top)/sizeof(script_submenu_items_top[0])+SCRIPT_NUM_PARAMS+
                               sizeof(script_submenu_items_bottom)/sizeof(script_submenu_items_bottom[0])];
static CMenu script_submenu = {0x27,LANG_MENU_SCRIPT_TITLE, NULL, script_submenu_items };
#endif

static CMenuItem games_submenu_items[] = {
#ifdef OPT_GAME_REVERSI
    MENU_ITEM   (0x38,LANG_MENU_GAMES_REVERSI,              MENUITEM_PROC,      gui_draw_reversi,   0 ),
#endif
#ifdef OPT_GAME_SOKOBAN
    MENU_ITEM   (0x38,LANG_MENU_GAMES_SOKOBAN,              MENUITEM_PROC,      gui_draw_sokoban,   0 ),
#endif
#ifdef OPT_GAME_CONNECT4
    MENU_ITEM   (0x38,LANG_MENU_GAMES_CONNECT4,             MENUITEM_PROC,      gui_draw_4wins,     0 ),
#endif
#ifdef OPT_GAME_MASTERMIND
    MENU_ITEM   (0x38,LANG_MENU_GAMES_MASTERMIND,           MENUITEM_PROC,      gui_draw_mastermind, 0 ),
#endif
#ifdef OPT_GAME_TETRIS
    MENU_ITEM   (0x38,LANG_MENU_GAMES_TETRIS,               MENUITEM_PROC,      gui_draw_tetris,    0 ),
#endif
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,        0,                  0 ),
    {0}
};
static CMenu games_submenu = {0x38,LANG_MENU_GAMES_TITLE, NULL, games_submenu_items };

static const char* gui_autoiso_shutter_modes[] =            { "Auto", "1/8s", "1/15s", "1/30s", "1/60s", "1/125s", "1/250s", "1/500s", "1/1000s" };
static const int shutter1_values[]={0, 8, 15, 30, 60, 125, 250, 500, 1000 };

static const char* gui_autoiso2_shutter_modes[]={ "Off", "1/4s", "1/6s", "1/8s", "1/12s", "1/15s", "1/20s", "1/25s", "1/30s", 
				 "1/40s", "1/50s", "1/60s", "1/80s", "1/100s", "1/125s", "1/160s", "1/250s", "1/500s", "1/1000s"};
static const int shutter2_values[]={0, 4, 6, 8, 12, 15, 20, 25, 30, 40, 50, 60, 80, 100, 125, 160, 200, 250, 500, 1000 };

static const char* gui_overexp_ev_modes[]={ "Off", "-1/3 Ev", "-2/3 Ev", "-1 Ev", "-1 1/3Ev", "-1 2/3Ev", "-2 Ev" };


static CMenuItem autoiso_submenu_items[] = {
    MENU_ITEM   (0x5c,LANG_MENU_AUTOISO_ENABLED,            MENUITEM_BOOL,                                      &conf.autoiso_enable,       0 ),
    MENU_ENUM2	(0x5f,LANG_MENU_AUTOISO_MIN_SHUTTER,  		&conf.autoiso_shutter_enum, gui_autoiso_shutter_modes ),
    MENU_ITEM   (0x5f,LANG_MENU_AUTOISO_USER_FACTOR,        MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &conf.autoiso_user_factor,  	MENU_MINMAX(1, 8) ),

#if CAM_HAS_IS
    MENU_ITEM   (0x5f,LANG_MENU_AUTOISO_IS_FACTOR,          MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &conf.autoiso_is_factor,    	MENU_MINMAX(1, 8) ),
#endif

    MENU_ITEM   (0x5f,LANG_MENU_AUTOISO_MIN_ISO,            MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &conf.autoiso_min_iso,      	MENU_MINMAX(1, 20) ),
    MENU_ITEM	(0x5f,LANG_MENU_AUTOISO_MAX_ISO_AUTO, 		MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &conf.autoiso_max_iso_auto, 	MENU_MINMAX(10, 320) ),

	//@tsv
    MENU_ENUM2	(0x5f,LANG_MENU_AUTOISO_MIN_SHUTTER2,  		&conf.autoiso2_shutter_enum, gui_autoiso2_shutter_modes ),
    MENU_ITEM	(0x5f,LANG_MENU_AUTOISO_MAX_ISO2, 			MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &conf.autoiso2_max_iso_auto,	MENU_MINMAX(10, 320) ),

#if !defined(CAMERA_sx230hs)
    MENU_ITEM   (0x5f,LANG_MENU_AUTOISO_MAX_ISO_HI,         MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &conf.autoiso_max_iso_hi,		MENU_MINMAX(20, 320) ),
#endif

    MENU_ENUM2	(0x5f,LANG_MENU_AUTOISO_OVEREXP_EV,  		&conf.overexp_ev_enum, gui_overexp_ev_modes ),
    MENU_ITEM	(0x57,LANG_MENU_ZEBRA_OVER,            		MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &conf.zebra_over,    			MENU_MINMAX(0, 32) ),
    MENU_ITEM	(0x5f,LANG_MENU_AUTOISO_OVEREXP_THRES, 		MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &conf.overexp_threshold, 		MENU_MINMAX(1, 20) ),

    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,    0,                                                              0 ),
    {0}
};
//static CMenu autoiso_submenu = {0x2d,LANG_MENU_AUTOISO_TITLE, NULL, autoiso_submenu_items };
static CMenu autoiso_submenu = {0x2d,LANG_MENU_AUTOISO_TITLE, cb_autoiso_menu_change, autoiso_submenu_items };


#ifdef OPT_TEXTREADER
static const char* gui_reader_codepage_cps[] =              { "Win1251", "DOS"};
static CMenuItem reader_submenu_items[] = {
    MENU_ITEM   (0x35,LANG_MENU_READ_OPEN_NEW,              MENUITEM_PROC,                  gui_draw_read,              0 ),
    MENU_ITEM   (0x35,LANG_MENU_READ_OPEN_LAST,             MENUITEM_PROC,                  gui_draw_read_last,         0 ),
    MENU_ITEM   (0x35,LANG_MENU_READ_SELECT_FONT,           MENUITEM_PROC,                  gui_draw_load_rbf,          0 ),
    MENU_ENUM2  (0x5f,LANG_MENU_READ_CODEPAGE,              &conf.reader_codepage,          gui_reader_codepage_cps ),
    MENU_ITEM   (0x5c,LANG_MENU_READ_WORD_WRAP,             MENUITEM_BOOL,                  &conf.reader_wrap_by_words, 0 ),
    MENU_ITEM   (0x5c,LANG_MENU_READ_AUTOSCROLL,            MENUITEM_BOOL,                  &conf.reader_autoscroll,    0 ),
    MENU_ITEM   (0x5f,LANG_MENU_READ_AUTOSCROLL_DELAY,      MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &conf.reader_autoscroll_delay, MENU_MINMAX(0, 60) ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,                    0,                          0 ),
    {0}
};
static CMenu reader_submenu = {0x37,LANG_MENU_READ_TITLE, NULL, reader_submenu_items };
#endif

#ifdef OPT_DEBUGGING
static const char* gui_debug_shortcut_modes[] =             { "None", "DmpRAM", "Page", "CmpProps"};
static const char* gui_debug_display_modes[] =              { "None", "Props", "Params", "Tasks"};
static CMenuItem debug_submenu_items[] = {
    MENU_ENUM2  (0x5c,LANG_MENU_DEBUG_DISPLAY,              &conf.debug_display,            gui_debug_display_modes ),
    MENU_ITEM   (0x2a,LANG_MENU_DEBUG_PROPCASE_PAGE,        MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,   &conf.debug_propcase_page, MENU_MINMAX(0, 128) ),
    MENU_ITEM   (0x2a,LANG_MENU_DEBUG_TASKLIST_START,       MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,   &debug_tasklist_start, MENU_MINMAX(0, 63) ),
    MENU_ITEM   (0x5c,LANG_MENU_DEBUG_SHOW_MISC_VALS,       MENUITEM_BOOL,                  &conf.debug_misc_vals_show,         0 ),
    MENU_ITEM   (0x2a,LANG_MENU_DEBUG_MEMORY_BROWSER,       MENUITEM_PROC,                  gui_draw_debug,                     0 ),
    MENU_ITEM   (0x2a,LANG_MENU_DEBUG_BENCHMARK,            MENUITEM_PROC,                  gui_draw_bench,                     0 ),
    MENU_ENUM2  (0x5c,LANG_MENU_DEBUG_SHORTCUT_ACTION,      &conf.debug_shortcut_action,    gui_debug_shortcut_modes ),
    MENU_ITEM   (0x5c,LANG_MENU_RAW_TIMER,                  MENUITEM_BOOL,                  &conf.raw_timer,                    0 ),
#ifdef OPT_LUA
    MENU_ITEM   (0x5c,LANG_MENU_LUA_RESTART,                MENUITEM_BOOL,                  &conf.debug_lua_restart_on_error,   0 ),
#endif
#if CAM_MULTIPART
    MENU_ITEM   (0x33,LANG_MENU_DEBUG_CREATE_MULTIPART ,    MENUITEM_PROC,                  gui_menuproc_break_card,            0 ),
#endif
    MENU_ITEM   (0x2a,LANG_SAVE_ROMLOG,                     MENUITEM_PROC,                  save_romlog,                        0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,                    0,                                  0 ),
    {0}
};
static CMenu debug_submenu = {0x2a,LANG_MENU_DEBUG_TITLE, NULL, debug_submenu_items };
#endif
#ifdef CAM_HAS_GPS

static CMenuItem gps_logging_items[] = {
    MENU_ITEM	(0x2a,LANG_MENU_GPS_TRACK_TIME,				MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,	&conf.gps_track_time, 		MENU_MINMAX(1, 60) ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,									0,							0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_TRACK_SYMBOL,			MENUITEM_BOOL,  									&conf.gps_track_symbol,		0 ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,									0,							0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_REC_PLAY_SET_1,			MENUITEM_BOOL,          							&conf.gps_rec_play_set_1,	0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_REC_PLAY_TIME_1,		MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,	&conf.gps_rec_play_time_1,	MENU_MINMAX(1, 60) ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_PLAY_DARK_SET_1,		MENUITEM_BOOL,          							&conf.gps_play_dark_set_1,	0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_PLAY_DARK_TIME_1,		MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,	&conf.gps_play_dark_time_1,	MENU_MINMAX(1, 60) ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,									0,							0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,                        				0,							0 ),
    {0}
};
static CMenu gps_logging_submenu = {0x86,LANG_MENU_GPS_LOGGING, NULL, gps_logging_items };

static CMenuItem gps_tagging_items[] = {
    MENU_ITEM	(0x5c,LANG_MENU_GPS_WAYPOINT_SAVE,          MENUITEM_BOOL,          		&conf.gps_waypoint_save,			0 ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,									0,							0 ),
    MENU_ITEM   (0x2a,LANG_MENU_GPS_WAIT_FOR_SIGNAL,		MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,	&conf.gps_wait_for_signal,	MENU_MINMAX(1, 599) ),
    MENU_ITEM   (0x2a,LANG_MENU_GPS_WAIT_FOR_SIGNAL_TIME,	MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,	&conf.gps_wait_for_signal_time,	MENU_MINMAX(1, 60) ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,									0,							0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_REC_PLAY_SET,			MENUITEM_BOOL,          							&conf.gps_rec_play_set,		0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_REC_PLAY_TIME,			MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,	&conf.gps_rec_play_time,	MENU_MINMAX(1, 60) ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_PLAY_DARK_SET,			MENUITEM_BOOL,          							&conf.gps_play_dark_set,	0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_PLAY_DARK_TIME,			MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,	&conf.gps_play_dark_time,	MENU_MINMAX(1, 60) ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,									0,							0 ),
    MENU_ITEM	(0x5c,LANG_MENU_GPS_COUNTDOWN,          	MENUITEM_BOOL,          							&conf.gps_countdown	,		0 ),
//    MENU_ITEM	(0x5c,LANG_MENU_GPS_COUNTDOWN_BLINK,      	MENUITEM_BOOL,          							&conf.gps_countdown_blink,	0 ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,									0,							0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,                        				0,							0 ),
    {0}
};
static CMenu gps_tagging_submenu = {0x86,LANG_MENU_GPS_TAGGING, NULL, gps_tagging_items };


static CMenuItem gps_navigation_items[] = {
    MENU_ITEM	(0x2a,LANG_MENU_GPS_KOMPASS_SMOOTH,			MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,	&conf.gps_kompass_smooth,	MENU_MINMAX(1, 40) ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_KOMPASS_TIME,			MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,	&conf.gps_kompass_time, 	MENU_MINMAX(1, 60) ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_NAVI_TIME,				MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,	&conf.gps_navi_time,		MENU_MINMAX(1, 60) ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,									0,							0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_MARK_HOME,              MENUITEM_PROC,          		(int*)mark_home,					0 ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,									0,							0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,                        				0,							0 ),
    {0}
};
static CMenu gps_navigation_submenu = {0x86,LANG_MENU_GPS_NAVIGATION, NULL, gps_navigation_items };


static const char* gui_gps_sat_fix[] =                  { "immer", "2D", "3D", "2D/3D" };
static CMenuItem gps_values_items[] = {
    MENU_ITEM	(0x2a,LANG_MENU_GPS_BATT,					MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,	&conf.gps_batt,				MENU_MINMAX(0, 99) ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_BATT_WARNING,			MENUITEM_BOOL,  									&conf.gps_batt_warn,		0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_BEEP_WARNING,			MENUITEM_BOOL,  									&conf.gps_beep_warn,		0 ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,									0,							0 ),
    MENU_ENUM2  (0x69,LANG_MENU_GPS_2D_3D_FIX,				&conf.gps_2D_3D_fix,   								gui_gps_sat_fix ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,									0,							0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_SYMBOL_SHOW,			MENUITEM_BOOL,  									&conf.gps_show_symbol,		0 ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,									0,							0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_TEST_TIMEZONE,			MENUITEM_BOOL,  									&conf.gps_test_timezone,	0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_MARK_TIMEZONE,          MENUITEM_PROC,          		(int*)mark_timezone,				0 ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,				0,									0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,                        				0,							0 ),
    {0}
};
static CMenu gps_values_submenu = {0x86,LANG_MENU_GPS_VALUES, NULL, gps_values_items };


static CMenuItem gps_submenu_items[] = {
    MENU_ITEM	(0x2a,LANG_MENU_GPS_ON_OFF,					MENUITEM_BOOL,  				&conf.gps_on_off,					0 ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,				0,									0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_KOMPASS_SHOW,           MENUITEM_PROC,  				(int*)show_kompass,					0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_NAVI_SHOW,              MENUITEM_PROC,          		(int*)show_navi,					0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_NAVI_HOME,              MENUITEM_PROC,          		(int*)navigate_home,				0 ),
    MENU_ITEM	(0x2a,LANG_MENU_GPS_TRACK_START,            MENUITEM_PROC,          		(int*)gpx_start_stop,				0 ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,				0,									0 ),
    MENU_ITEM   (0x2a,LANG_MENU_GPS_VALUES,               	MENUITEM_SUBMENU,               &gps_values_submenu,            	0 ),
    MENU_ITEM   (0x2a,LANG_MENU_GPS_LOGGING,               	MENUITEM_SUBMENU,               &gps_logging_submenu,            	0 ),
    MENU_ITEM   (0x2a,LANG_MENU_GPS_TAGGING,               	MENUITEM_SUBMENU,               &gps_tagging_submenu,            	0 ),
    MENU_ITEM   (0x2a,LANG_MENU_GPS_NAVIGATION,            	MENUITEM_SUBMENU,               &gps_navigation_submenu,            0 ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,				0,									0 ),
    MENU_ITEM	(0x51,LANG_MENU_BACK,                       MENUITEM_UP, 					0,                                  0 ),
    {0}
};
static CMenu gps_submenu = {0x2a,LANG_MENU_GPS, NULL, gps_submenu_items };

#endif


static CMenuItem misc_submenu_items[] = {
    MENU_ITEM   (0x35,LANG_MENU_MISC_FILE_BROWSER,          MENUITEM_PROC,                  gui_draw_fselect,                   0 ),
#ifdef OPT_CALENDAR
    MENU_ITEM   (0x36,LANG_MENU_MISC_CALENDAR,              MENUITEM_PROC,                  gui_draw_calendar,                  0 ),
#endif
#ifdef OPT_TEXTREADER
    MENU_ITEM   (0x37,LANG_MENU_MISC_TEXT_READER,           MENUITEM_SUBMENU,               &reader_submenu,                    0 ),
#endif
#if defined (OPT_GAME_REVERSI) || (OPT_GAME_SOKOBAN || (OPT_GAME_CONNECT4) || OPT_GAME_MASTERMIND || OPT_GAME_TETRIS)
    MENU_ITEM   (0x38,LANG_MENU_MISC_GAMES,                 MENUITEM_SUBMENU,               &games_submenu,                     0 ),
#endif
#if CAM_SWIVEL_SCREEN
    MENU_ITEM   (0x28,LANG_MENU_MISC_FLASHLIGHT,            MENUITEM_BOOL,                  &conf.flashlight,                   0 ),
#endif
    MENU_ITEM   (0x5c,LANG_MENU_MISC_SHOW_SPLASH,           MENUITEM_BOOL,                  &conf.splash_show,                  0 ),
    MENU_ITEM   (0x5c,LANG_MENU_MISC_START_SOUND,           MENUITEM_BOOL,                  &conf.start_sound,                  0 ),
#if CAM_USE_ZOOM_FOR_MF
    MENU_ITEM   (0x59,LANG_MENU_MISC_ZOOM_FOR_MF,           MENUITEM_BOOL,                  &conf.use_zoom_mf,                  0 ),
#endif
#if CAM_ADJUSTABLE_ALT_BUTTON
    MENU_ITEM(0x22,LANG_MENU_MISC_ALT_BUTTON,               MENUITEM_ENUM,                  gui_alt_mode_button_enum,           0 ),
#endif
#if defined(CAM_ZOOM_ASSIST_BUTTON_CONTROL)
    MENU_ITEM   (0x5c,LANG_MENU_MISC_ZOOM_ASSIST,           MENUITEM_BOOL,                  &conf.zoom_assist_button_disable,   0 ),
#endif
    MENU_ITEM   (0x5d,LANG_MENU_MISC_DISABLE_LCD_OFF,       MENUITEM_ENUM,                  gui_alt_power_enum,                 0 ),
    MENU_ITEM   (0x65,LANG_MENU_MISC_PALETTE,               MENUITEM_PROC,                  gui_draw_palette,                   0 ),
    MENU_ITEM   (0x80,LANG_MENU_MISC_BUILD_INFO,            MENUITEM_PROC,                  gui_show_build_info,                0 ),
    MENU_ITEM   (0x80,LANG_MENU_MISC_MEMORY_INFO,           MENUITEM_PROC,                  gui_show_memory_info,               0 ),
    MENU_ITEM   (0x33,LANG_MENU_DEBUG_MAKE_BOOTABLE,        MENUITEM_PROC,                  gui_menuproc_mkbootdisk,            0 ),
#if CAM_MULTIPART
    MENU_ITEM   (0x33,LANG_MENU_DEBUG_SWAP_PART,            MENUITEM_ENUM,                  gui_menuproc_swap_partitions_enum,  0 ),
#endif
    MENU_ITEM   (0x2b,LANG_MENU_MAIN_RESET_OPTIONS,         MENUITEM_PROC,                  gui_menuproc_reset,                 0 ),
#ifdef OPT_DEBUGGING
    MENU_ITEM   (0x2a,LANG_MENU_MAIN_DEBUG,                 MENUITEM_SUBMENU,               &debug_submenu,                     0 ),
#endif
    MENU_ITEM   (0x86,LANG_MENU_REMOTE_PARAM,               MENUITEM_SUBMENU,               &remote_submenu,                    0 ),
#if defined (DNG_EXT_FROM)
    MENU_ITEM   (0x71,LANG_MENU_DNG_VIA_USB,                MENUITEM_BOOL | MENUITEM_ARG_CALLBACK, &conf.dng_usb_ext , (int)cb_change_dng_usb_ext ),
#endif
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,                    0,                                  0 ),
    {0},
};
static CMenu misc_submenu = {0x29,LANG_MENU_MISC_TITLE, NULL, misc_submenu_items };

static int voltage_step;
static CMenuItem battery_submenu_items[] = {
    MENU_ITEM   (0x66,LANG_MENU_BATT_VOLT_MAX,              MENUITEM_INT|MENUITEM_ARG_ADDR_INC,     &conf.batt_volts_max,   (int)&voltage_step ),
    MENU_ITEM   (0x67,LANG_MENU_BATT_VOLT_MIN,              MENUITEM_INT|MENUITEM_ARG_ADDR_INC,     &conf.batt_volts_min,   (int)&voltage_step ),
    MENU_ITEM   (0x68,LANG_MENU_BATT_STEP_25,               MENUITEM_BOOL|MENUITEM_ARG_CALLBACK,    &conf.batt_step_25,     (int)cb_step_25 ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR,                     0,                      0 ),
    MENU_ITEM   (0x73,LANG_MENU_BATT_SHOW_PERCENT,          MENUITEM_BOOL|MENUITEM_ARG_CALLBACK,    &conf.batt_perc_show,   (int)cb_perc ),
    MENU_ITEM   (0x73,LANG_MENU_BATT_SHOW_VOLTS,            MENUITEM_BOOL|MENUITEM_ARG_CALLBACK,    &conf.batt_volts_show,  (int)cb_volts ),
    MENU_ITEM   (0x32,LANG_MENU_BATT_SHOW_ICON,             MENUITEM_BOOL,                          &conf.batt_icon_show,   0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,                            0,                      0 ),
    {0}
};
static CMenu battery_submenu = {0x32,LANG_MENU_BATT_TITLE, cb_battery_menu_change, battery_submenu_items };

static const char* gui_space_bar_modes[] =                  { "Don't", "Horizontal", "Vertical"};
static const char* gui_space_bar_size_modes[] =             { "1/4", "1/2", "1"};
static const char* gui_space_bar_width_modes[] =            { "1", "2", "3","4","5","6","7","8","9","10"};
static const char* gui_space_warn_type_modes[] =            { "Percent", "MB", "Don't"};
static CMenuItem space_submenu_items[] = {
    MENU_ITEM   (0x5c,LANG_MENU_SPACE_SHOW_ICON,            MENUITEM_BOOL,          &conf.space_icon_show,  0 ),
    MENU_ENUM2  (0x69,LANG_MENU_SPACE_SHOW_BAR,             &conf.space_bar_show,   gui_space_bar_modes ),
    MENU_ENUM2  (0x6a,LANG_MENU_SPACE_BAR_SIZE,             &conf.space_bar_size,   gui_space_bar_size_modes ),
    MENU_ENUM2  (0x6b,LANG_MENU_SPACE_BAR_WIDTH,            &conf.space_bar_width,  gui_space_bar_width_modes ),
    MENU_ITEM   (0x5c,LANG_MENU_SPACE_SHOW_PERCENT,         MENUITEM_BOOL|MENUITEM_ARG_CALLBACK, &conf.space_perc_show, (int)cb_space_perc ),
    MENU_ITEM   (0x5c,LANG_MENU_SPACE_SHOW_MB,              MENUITEM_BOOL|MENUITEM_ARG_CALLBACK, &conf.space_mb_show,   (int)cb_space_mb ),
#if CAM_MULTIPART
    MENU_ITEM   (0x5c,LANG_MENU_SHOW_PARTITION_NR,          MENUITEM_BOOL,          &conf.show_partition_nr, 0 ),
#endif
    MENU_ENUM2  (0x5f,LANG_MENU_SPACE_WARN_TYPE,            &conf.space_warn_type,  gui_space_warn_type_modes ),
    MENU_ITEM   (0x58,LANG_MENU_SPACE_WARN_PERCENT,         MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,   &conf.space_perc_warn,    MENU_MINMAX(1, 99) ),
    MENU_ITEM   (0x58,LANG_MENU_SPACE_WARN_MB,              MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,   &conf.space_mb_warn,      MENU_MINMAX(1, 4000) ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,            0,                      0 ),
    {0}
};
static CMenu space_submenu = {0x33,LANG_MENU_OSD_SPACE_PARAMS_TITLE, NULL, space_submenu_items};

static const char* gui_dof_show_value_modes[] =             { "Don't", "Separate", "+Separate", "In Misc", "+In Misc" };
static CMenuItem dof_submenu_items[] = {
    MENU_ENUM2  (0x5f,LANG_MENU_OSD_SHOW_DOF_CALC,          &conf.show_dof,     gui_dof_show_value_modes ),
    MENU_ITEM   (0x5c,LANG_MENU_DOF_SUBJ_DIST_AS_NEAR_LIMIT,MENUITEM_BOOL,      &conf.dof_subj_dist_as_near_limit,  0 ),
    MENU_ITEM   (0x5c,LANG_MENU_DOF_USE_EXIF_SUBJ_DIST,     MENUITEM_BOOL,      &conf.dof_use_exif_subj_dist,       0 ),
    MENU_ITEM   (0x5c,LANG_MENU_DOF_SUBJ_DIST_IN_MISC,      MENUITEM_BOOL,      &conf.dof_subj_dist_in_misc,        0 ),
    MENU_ITEM   (0x5c,LANG_MENU_DOF_NEAR_LIMIT_IN_MISC,     MENUITEM_BOOL,      &conf.dof_near_limit_in_misc,       0 ),
    MENU_ITEM   (0x5c,LANG_MENU_DOF_FAR_LIMIT_IN_MISC,      MENUITEM_BOOL,      &conf.dof_far_limit_in_misc,        0 ),
    MENU_ITEM   (0x5c,LANG_MENU_DOF_HYPERFOCAL_IN_MISC,     MENUITEM_BOOL,      &conf.dof_hyperfocal_in_misc,       0 ),
    MENU_ITEM   (0x5c,LANG_MENU_DOF_DEPTH_LIMIT_IN_MISC,    MENUITEM_BOOL,      &conf.dof_depth_in_misc,            0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,        0,                                  0 ),
    {0}
};
static CMenu dof_submenu = {0x31,LANG_MENU_DOF_TITLE, /*cb_dof_menu_change*/ NULL, dof_submenu_items };

static const char* gui_zoom_value_modes[] =                 { "X", "FL", "EFL" };
static const char* gui_show_values_modes[] =                { "Don't", "Always", "Shoot" };
static CMenuItem values_submenu_items[] = {
    MENU_ENUM2  (0x5f,LANG_MENU_OSD_SHOW_MISC_VALUES,       &conf.show_values,  gui_show_values_modes ),
    MENU_ITEM   (0x5c,LANG_MENU_SHOW_VALUES_IN_VIDEO,       MENUITEM_BOOL,      &conf.show_values_in_video,                 0 ),
    MENU_ITEM   (0x5c,LANG_MENU_VALUES_SHOW_ZOOM,           MENUITEM_BOOL,      &conf.values_show_zoom,                     0 ),
    MENU_ENUM2  (0x5f,LANG_MENU_OSD_ZOOM_VALUE,             &conf.zoom_value,   gui_zoom_value_modes ),
    MENU_ITEM   (0x60,LANG_MENU_OSD_ZOOM_SCALE,             MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,  &conf.zoom_scale,   MENU_MINMAX(0, 1000) ),
    MENU_ITEM   (0x62,LANG_MENU_VALUES_SHOW_REAL_APERTURE,  MENUITEM_BOOL,      &conf.values_show_real_aperture,            0 ),
    MENU_ITEM   (0x74,LANG_MENU_VALUES_SHOW_REAL_ISO,       MENUITEM_BOOL,      &conf.values_show_real_iso,                 0 ),
    MENU_ITEM   (0x74,LANG_MENU_VALUES_SHOW_MARKET_ISO,     MENUITEM_BOOL,      &conf.values_show_market_iso,               0 ),
    MENU_ITEM   (0x2d,LANG_MENU_SHOW_ISO_ONLY_IN_AUTOISO_MODE, MENUITEM_BOOL,   &conf.values_show_iso_only_in_autoiso_mode, 0 ),
    MENU_ITEM   (0x5c,LANG_MENU_VALUES_SHOW_EV_SETED,       MENUITEM_BOOL,      &conf.values_show_ev_seted,                 0 ),
    MENU_ITEM   (0x5c,LANG_MENU_VALUES_SHOW_EV_MEASURED,    MENUITEM_BOOL,      &conf.values_show_ev_measured,              0 ),
    MENU_ITEM   (0x5c,LANG_MENU_VALUES_SHOW_BV_SETED,       MENUITEM_BOOL,      &conf.values_show_bv_seted,                 0 ),
    MENU_ITEM   (0x5c,LANG_MENU_VALUES_SHOW_BV_MEASURED,    MENUITEM_BOOL,      &conf.values_show_bv_measured,              0 ),
    MENU_ITEM   (0x5c,LANG_MENU_VALUES_SHOW_OVEREXPOSURE,   MENUITEM_BOOL,      &conf.values_show_overexposure,             0 ),
    MENU_ITEM   (0x5c,LANG_MENU_SHOW_CANON_OVEREXPOSURE,    MENUITEM_BOOL,      &conf.values_show_canon_overexposure,       0 ),
    MENU_ITEM   (0x5c,LANG_MENU_VALUES_SHOW_LUMINANCE,      MENUITEM_BOOL,      &conf.values_show_luminance,                0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,        0,                                          0 ),
    {0}
};
static CMenu values_submenu = {0x28,LANG_MENU_OSD_VALUES_TITLE, /*cb_values_menu_change*/ NULL, values_submenu_items };

static const char* gui_show_clock_modes[]=                  { "Don't", "Normal", "Seconds"};
static const char* gui_clock_format_modes[] =               { "24h", "12h"};
static const char* gui_clock_indicator_modes[] =            { "PM", "P", "."};
static const char* gui_clock_halfpress_modes[] =            { "Full", "Seconds", "Don't"};
static CMenuItem clock_submenu_items[] = {
    MENU_ENUM2  (0x5f,LANG_MENU_OSD_SHOW_CLOCK,             &conf.show_clock,       gui_show_clock_modes ),
    MENU_ENUM2  (0x6d,LANG_MENU_OSD_CLOCK_FORMAT,           &conf.clock_format,     gui_clock_format_modes ),
    MENU_ENUM2  (0x6c,LANG_MENU_OSD_CLOCK_INDICATOR,        &conf.clock_indicator,  gui_clock_indicator_modes ),
    MENU_ENUM2  (0x6e,LANG_MENU_OSD_CLOCK_HALFPRESS,        &conf.clock_halfpress,  gui_clock_halfpress_modes ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,            0,                              0 ),
    {0}
};
static CMenu clock_submenu = {0x34,LANG_MENU_OSD_CLOCK_PARAMS_TITLE, NULL, clock_submenu_items };


static const char* gui_show_movie_time_modes[] =            { "Don't", "hh:mm:ss", "KB/s","both"};
#if !CAM_VIDEO_QUALITY_ONLY
    static const char* gui_video_mode_modes[] =             { "Bitrate", "Quality"};
#else
    static const char* gui_video_mode_modes[] =             { "Default", "Quality"};
#endif
static CMenuItem video_submenu_items[] = {
#if CAM_CHDK_HAS_EXT_VIDEO_MENU
    MENU_ENUM2  (0x23,LANG_MENU_VIDEO_MODE,                 &conf.video_mode,       gui_video_mode_modes ),
#if !CAM_VIDEO_QUALITY_ONLY
    MENU_ITEM   (0x5e,LANG_MENU_VIDEO_BITRATE,              MENUITEM_ENUM,          gui_video_bitrate_enum,             0 ),
#endif
    MENU_ITEM   (0x60,LANG_MENU_VIDEO_QUALITY,              MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,  &conf.video_quality, MENU_MINMAX(1, 99) ),
#if CAM_CHDK_HAS_EXT_VIDEO_TIME
    MENU_ITEM   (0x5c,LANG_MENU_VIDEO_EXT_TIME,             MENUITEM_BOOL,          &conf.ext_video_time,               0 ),
#endif
    MENU_ITEM   (0x5c,LANG_MENU_CLEAR_VIDEO_VALUES,         MENUITEM_BOOL,          &conf.clear_video,                  0 ),
#endif
#if CAM_VIDEO_CONTROL
    MENU_ITEM   (0x5c,LANG_MENU_FAST_SWITCH_VIDEO,          MENUITEM_BOOL,          &conf.fast_movie_control,           0 ),
#endif
#if CAM_CHDK_HAS_EXT_VIDEO_MENU
    MENU_ITEM   (0x5c,LANG_MENU_FAST_SWITCH_QUALITY_VIDEO,  MENUITEM_BOOL,          &conf.fast_movie_quality_control,   0 ),
#endif
#if CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    MENU_ITEM   (0x5c,LANG_MENU_OPTICAL_ZOOM_IN_VIDEO,      MENUITEM_BOOL,          &conf.unlock_optical_zoom_for_video, 0 ),
#endif
#if CAM_CAN_MUTE_MICROPHONE
    MENU_ITEM   (0x83,LANG_MENU_MUTE_ON_ZOOM,               MENUITEM_BOOL,          &conf.mute_on_zoom,                 0 ),
#endif
#if CAM_AF_SCAN_DURING_VIDEO_RECORD
    MENU_ITEM   (0x82,LANG_MENU_VIDEO_AF_KEY,               MENUITEM_ENUM,          gui_video_af_key_enum,              0 ),
#endif
    MENU_ENUM2  (0x5c,LANG_MENU_OSD_SHOW_VIDEO_TIME,        &conf.show_movie_time,  gui_show_movie_time_modes ),
    MENU_ITEM   (0x60,LANG_MENU_OSD_SHOW_VIDEO_REFRESH,     MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &conf.show_movie_refresh,   MENU_MINMAX(1, 20) ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,            0,                                  0 ),
    {0}
};
static CMenu video_submenu = {0x23,LANG_MENU_VIDEO_PARAM_TITLE, NULL, video_submenu_items };

static const char* gui_bracket_values_modes[] =             { "Off", "1/3 Ev","2/3 Ev", "1 Ev", "1 1/3Ev", "1 2/3Ev", "2 Ev", "2 1/3Ev", "2 2/3Ev", "3 Ev", "3 1/3Ev", "3 2/3Ev", "4 Ev"};
static const char* gui_override_koef_modes[] =              { "Off", "1", "10", "100", "1000" };
static const char* gui_bracket_type_modes[] =               { "+/-", "-","+"};
static CMenuItem bracketing_in_continuous_submenu_items[] = {
    MENU_ENUM2  (0x63,LANG_MENU_TV_BRACKET_VALUE,           &conf.tv_bracket_value,         gui_bracket_values_modes ),
#if CAM_HAS_IRIS_DIAPHRAGM
    MENU_ENUM2  (0x62,LANG_MENU_AV_BRACKET_VALUE,           &conf.av_bracket_value,         gui_bracket_values_modes ),
#endif
#if CAM_CAN_SD_OVERRIDE
    MENU_ITEM   (0x5e,LANG_MENU_SUBJ_DIST_BRACKET_VALUE,    MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,                 &conf.subj_dist_bracket_value, MENU_MINMAX(0, 100) ),
    MENU_ENUM2  (0x5f,LANG_MENU_SUBJ_DIST_BRACKET_KOEF,     &conf.subj_dist_bracket_koef,   gui_override_koef_modes ),
#endif
    MENU_ITEM   (0x74,LANG_MENU_ISO_BRACKET_VALUE,          MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,                 &conf.iso_bracket_value, MENU_MINMAX(0, 100) ),
    MENU_ENUM2a (0x5f,LANG_MENU_ISO_BRACKET_KOEF,           &conf.iso_bracket_koef,         gui_override_koef_modes,            4 ),
    MENU_ENUM2  (0x60,LANG_MENU_BRACKET_TYPE,               &conf.bracket_type,             gui_bracket_type_modes ),
    MENU_ITEM   (0x5b,LANG_MENU_CLEAR_BRACKET_VALUES,       MENUITEM_BOOL,                  &conf.clear_bracket,                0 ),
    MENU_ITEM   (0x5c,LANG_MENU_BRACKETING_ADD_RAW_SUFFIX,  MENUITEM_BOOL,                  &conf.bracketing_add_raw_suffix,    0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,                    0,                                  0 ),
    {0}
};
static CMenu bracketing_in_continuous_submenu = {0x2c,LANG_MENU_BRACKET_IN_CONTINUOUS_TITLE, NULL, bracketing_in_continuous_submenu_items };

// "Extra Photo Operations" Menu
static const char* gui_override_disable_modes[] =           { "Off", "On", "Disabled" };
static const char* gui_nd_filter_state_modes[] =            { "Off", "In", "Out" };
static const char* gui_fast_ev_step_modes[] =               { "1/6 Ev","1/3 Ev","1/2 Ev", "2/3 Ev","5/6 Ev","1 Ev","1 1/6 Ev","1 1/3 Ev","1 1/2 Ev", "1 2/3 Ev","1 5/6 Ev","2 Ev","2 1/6 Ev","2 1/3 Ev","2 1/2 Ev", "2 2/3 Ev","2 5/6 Ev","3 Ev","3 1/6 Ev","3 1/3 Ev","3 1/2 Ev", "3 2/3 Ev","3 5/6 Ev","4 Ev"};
static const char* gui_fast_image_quality_modes[] =         { "sup.fine", "fine", "normal", "off" };
static CMenuItem operation_submenu_items[] = {
    MENU_ENUM2  (0x5f,LANG_MENU_OVERRIDE_DISABLE,           &conf.override_disable, gui_override_disable_modes ),
    MENU_ITEM   (0x5c,LANG_MENU_OVERRIDE_DISABLE_ALL,       MENUITEM_BOOL,      &conf.override_disable_all,         0 ),
    MENU_ITEM   (0x61,LANG_MENU_OVERRIDE_TV_VALUE,          MENUITEM_ENUM,      gui_tv_override_value_enum,         0 ),
    MENU_ITEM   (0x5f,LANG_MENU_OVERRIDE_TV_KOEF,           MENUITEM_ENUM,      gui_tv_override_koef_enum,          0 ),
    MENU_ITEM   (0x59,LANG_MENU_TV_ENUM_TYPE,               MENUITEM_ENUM,      gui_tv_enum_type_enum,              0 ),
#if CAM_HAS_IRIS_DIAPHRAGM
    MENU_ITEM   (0x62,LANG_MENU_OVERRIDE_AV_VALUE,          MENUITEM_ENUM,      gui_av_override_enum,               0 ),
#endif
#if CAM_HAS_ND_FILTER
    MENU_ENUM2  (0x5f,LANG_MENU_OVERRIDE_ND_FILTER,         &conf.nd_filter_state, gui_nd_filter_state_modes ),
#endif
#if CAM_CAN_SD_OVERRIDE
    MENU_ITEM   (0x5e,LANG_MENU_OVERRIDE_SUBJ_DIST_VALUE,   MENUITEM_ENUM,      gui_subj_dist_override_value_enum,  0 ),
    MENU_ITEM   (0x5f,LANG_MENU_OVERRIDE_SUBJ_DIST_KOEF,    MENUITEM_ENUM,      gui_subj_dist_override_koef_enum,   0 ),
#endif
    MENU_ITEM   (0x74,LANG_MENU_OVERRIDE_ISO_VALUE,         MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,     &conf.iso_override_value, MENU_MINMAX(0, 800) ),
    MENU_ENUM2a (0x5f,LANG_MENU_OVERRIDE_ISO_KOEF,          &conf.iso_override_koef, gui_override_koef_modes,       4 ),
#if ZOOM_OVERRIDE
    MENU_ITEM   (0x5c,LANG_MENU_OVERRIDE_ZOOM,              MENUITEM_BOOL,      &conf.zoom_override,                0 ),
    MENU_ITEM   (0x5f,LANG_MENU_OVERRIDE_ZOOM_VALUE,        MENUITEM_ENUM,      gui_zoom_override_enum,             0 ),

    MENU_ITEM   (0x5c,LANG_MENU_CLEAR_ZOOM_OVERRIDE_VALUES, MENUITEM_BOOL,      &conf.clear_zoom_override,          0 ),
#endif
    MENU_ITEM   (0x2c,LANG_MENU_BRACKET_IN_CONTINUOUS,      MENUITEM_SUBMENU,   &bracketing_in_continuous_submenu,  0 ),
    MENU_ITEM   (0x2d,LANG_MENU_AUTOISO,                    MENUITEM_SUBMENU,   &autoiso_submenu,                   0 ),
    MENU_ITEM   (0x5b,LANG_MENU_CLEAR_OVERRIDE_VALUES,      MENUITEM_BOOL,      &conf.clear_override,               0 ),
    MENU_ITEM   (0x5c,LANG_MENU_MISC_FAST_EV,               MENUITEM_BOOL,      &conf.fast_ev,                      0 ),
    MENU_ENUM2  (0x5f,LANG_MENU_MISC_FAST_EV_STEP,          &conf.fast_ev_step, gui_fast_ev_step_modes ),
#if CAM_REAR_CURTAIN
    MENU_ITEM   (0x5c, LANG_MENU_REAR_CURTAIN,              MENUITEM_BOOL,      &conf.flash_sync_curtain,           0 ),
#endif
    MENU_ITEM   (0x5c, LANG_MENU_FLASH_MANUAL_OVERRIDE,     MENUITEM_BOOL,      &conf.flash_manual_override,        0 ),
    MENU_ITEM   (0x5f, LANG_MENU_FLASH_VIDEO_OVERRIDE_POWER,MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &conf.flash_video_override_power, MENU_MINMAX(0, 2) ),
#if CAM_HAS_VIDEO_BUTTON
    MENU_ITEM   (0x5c, LANG_MENU_FLASH_VIDEO_OVERRIDE,      MENUITEM_BOOL,      &conf.flash_video_override,         0 ),
#endif
#if CAM_QUALITY_OVERRIDE
    MENU_ENUM2  (0x5c,LANG_MENU_MISC_IMAGE_QUALITY,         &conf.fast_image_quality, gui_fast_image_quality_modes ),
#endif
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,        0,                                  0 ),
    {0}
};
static CMenu operation_submenu = {0x21,LANG_MENU_OPERATION_PARAM_TITLE, NULL, operation_submenu_items };

#ifdef OPT_EDGEOVERLAY
static const char* gui_edge_pano_modes[] =                  { "Off", "Right", "Down", "Left", "Up", "Free" };
static CMenuItem edge_overlay_submenu_items[] = {
    MENU_ITEM   (0x5c,LANG_MENU_EDGE_OVERLAY_ENABLE,        MENUITEM_BOOL,          &conf.edge_overlay_enable,  0 ),
    MENU_ITEM   (0x5c,LANG_MENU_EDGE_FILTER,                MENUITEM_BOOL,          &conf.edge_overlay_filter,  0 ),
    MENU_ENUM2  (0x5f,LANG_MENU_EDGE_PANO,                  &conf.edge_overlay_pano, gui_edge_pano_modes ),
    MENU_ITEM   (0x5e,LANG_MENU_EDGE_PANO_OVERLAP,          MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &conf.edge_overlay_pano_overlap, MENU_MINMAX(0, 100) ),
    MENU_ITEM   (0x5c,LANG_MENU_EDGE_SHOW,                  MENUITEM_BOOL,          &conf.edge_overlay_show,    0 ),
    MENU_ITEM   (0x5e,LANG_MENU_EDGE_OVERLAY_TRESH,         MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &conf.edge_overlay_thresh, MENU_MINMAX(0, 255) ),
    MENU_ITEM   (0x65,LANG_MENU_EDGE_OVERLAY_COLOR,         MENUITEM_COLOR_FG,      &conf.edge_overlay_color,   0 ),
    MENU_ITEM   (0x5c,LANG_MENU_EDGE_PLAY,                  MENUITEM_BOOL,          &conf.edge_overlay_play,    0 ), //does not work on cams like s-series, which dont have a real "hardware" play/rec switch, need a workaround, probably another button
    MENU_ITEM   (0x33,LANG_MENU_EDGE_SAVE,                  MENUITEM_PROC,          gui_menuproc_edge_save,     0 ),
    MENU_ITEM   (0x5c,LANG_MENU_EDGE_ZOOM,                  MENUITEM_BOOL,          &conf.edge_overlay_zoom,    0 ),
    MENU_ITEM   (0x33,LANG_MENU_EDGE_LOAD,                  MENUITEM_PROC,          gui_menuproc_edge_load,     0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,            0,                          0 ),
    {0}
};
static CMenu edge_overlay_submenu = {0x7f,LANG_MENU_EDGE_OVERLAY_TITLE, NULL, edge_overlay_submenu_items };
#endif

static CMenuItem grid_submenu_items[] = {
    MENU_ITEM   (0x2f,LANG_MENU_SHOW_GRID,                  MENUITEM_BOOL,      &conf.show_grid_lines,  0 ),
    MENU_ITEM   (0x35,LANG_MENU_GRID_LOAD,                  MENUITEM_PROC,      gui_grid_lines_load,    0 ),
    MENU_ITEM   (0x0 ,LANG_MENU_GRID_CURRENT,               MENUITEM_SEPARATOR, 0,                      0 ),
    MENU_ITEM   (0x0 ,(int)grid_title,                      MENUITEM_TEXT,      0,                      0 ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR, 0,                      0 ),
    MENU_ITEM   (0x5c,LANG_MENU_GRID_FORCE_COLOR,           MENUITEM_BOOL,      &conf.grid_force_color, 0 ),
    MENU_ITEM   (0x65,LANG_MENU_GRID_COLOR_LINE,            MENUITEM_COLOR_FG,  &conf.grid_color,       0 ),
    MENU_ITEM   (0x65,LANG_MENU_GRID_COLOR_FILL,            MENUITEM_COLOR_BG,  &conf.grid_color,       0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,        0,                      0 ),
    {0}
};
static CMenu grid_submenu = {0x2f,LANG_MENU_GRID_TITLE, NULL, grid_submenu_items };

static CMenuItem visual_submenu_items[] = {
    MENU_ITEM   (0x35,LANG_MENU_VIS_LANG,                   MENUITEM_PROC,      gui_draw_load_lang,         0 ),
    MENU_ITEM   (0x5f,LANG_MENU_VIS_OSD_FONT,               MENUITEM_ENUM,      gui_font_enum,              0 ),
    MENU_ITEM   (0x35,LANG_MENU_VIS_MENU_FONT,              MENUITEM_PROC,      gui_draw_load_menu_rbf,     0 ),
    MENU_ITEM   (0x35,LANG_MENU_VIS_MENU_SYMBOL_FONT,       MENUITEM_PROC,      gui_draw_load_symbol_rbf,   0 ),
    MENU_ITEM   (0x80,LANG_MENU_RESET_FILES,                MENUITEM_PROC,      gui_menuproc_reset_files,   0 ),
    MENU_ITEM   (0x0 ,LANG_MENU_VIS_COLORS,                 MENUITEM_SEPARATOR, 0,                          0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_OSD_TEXT,               MENUITEM_COLOR_FG,  &conf.osd_color,            0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_OSD_BKG,                MENUITEM_COLOR_BG,  &conf.osd_color,            0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_OSD_WARNING,            MENUITEM_COLOR_FG,  &conf.osd_color_warn,       0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_OSD_WARNING_BKG,        MENUITEM_COLOR_BG,  &conf.osd_color_warn,       0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_HISTO,                  MENUITEM_COLOR_FG,  &conf.histo_color,          0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_HISTO_BKG,              MENUITEM_COLOR_BG,  &conf.histo_color,          0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_HISTO_BORDER,           MENUITEM_COLOR_FG,  &conf.histo_color2,         0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_HISTO_MARKERS,          MENUITEM_COLOR_BG,  &conf.histo_color2,         0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_ZEBRA_UNDER,            MENUITEM_COLOR_BG,  &conf.zebra_color,          0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_ZEBRA_OVER,             MENUITEM_COLOR_FG,  &conf.zebra_color,          0 ),
    //MENU_ITEM   (0x65,LANG_MENU_VIS_BATT_ICON,              MENUITEM_COLOR_FG,  &conf.batt_icon_color,      0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_SPACE_ICON,             MENUITEM_COLOR_FG,  &conf.space_color,          0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_SPACE_ICON_BKG,         MENUITEM_COLOR_BG,  &conf.space_color,          0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_MENU_TEXT,              MENUITEM_COLOR_FG,  &conf.menu_color,           0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_MENU_BKG,               MENUITEM_COLOR_BG,  &conf.menu_color,           0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_MENU_TITLE_TEXT,        MENUITEM_COLOR_FG,  &conf.menu_title_color,     0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_MENU_TITLE_BKG,         MENUITEM_COLOR_BG,  &conf.menu_title_color,     0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_MENU_CURSOR_TEXT,       MENUITEM_COLOR_FG,  &conf.menu_cursor_color,    0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_MENU_CURSOR_BKG,        MENUITEM_COLOR_BG,  &conf.menu_cursor_color,    0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_MENU_SYMBOL_TEXT,       MENUITEM_COLOR_FG,  &conf.menu_symbol_color,    0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_MENU_SYMBOL_BKG,        MENUITEM_COLOR_BG,  &conf.menu_symbol_color,    0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_READER_TEXT,            MENUITEM_COLOR_FG,  &conf.reader_color,         0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_READER_BKG,             MENUITEM_COLOR_BG,  &conf.reader_color,         0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_OSD_OVERRIDE,           MENUITEM_COLOR_FG,  &conf.osd_color_override,   0 ),
    MENU_ITEM   (0x65,LANG_MENU_VIS_OSD_OVERRIDE_BKG,       MENUITEM_COLOR_BG,  &conf.osd_color_override,   0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,        0,                          0 ),
    {0}
};
static CMenu visual_submenu = {0x28,LANG_MENU_VIS_TITLE, NULL, visual_submenu_items };

/*
 * 1 extra entry for the "Main menu" and 1 for null when the menu is full with user selections
 * Compiler will zero init remaining portion of array so no there is no hidden relationship between
 * this structure and the value of USER_MENU_ITEMS. The value of USER_MENU_ITEMS can be anything you
 * wish and everything automagically works.
*/

static CMenuItem user_submenu_items[USER_MENU_ITEMS + 2] = {
    MENU_ITEM   (0x20,LANG_MENU_MAIN_TITLE,                 MENUITEM_PROC,      rinit,                      0 )
};

static CMenu user_submenu = {0x2e,LANG_MENU_USER_MENU, NULL, user_submenu_items };

static CMenuItem raw_state_submenu_items[] = {
    MENU_ITEM   (0x5c,LANG_MENU_OSD_SHOW_RAW_STATE,         MENUITEM_BOOL,      &conf.show_raw_state,       0 ),
    MENU_ITEM   (0x5c,LANG_MENU_OSD_SHOW_REMAINING_RAW,     MENUITEM_BOOL,      &conf.show_remaining_raw,   0 ),
    MENU_ITEM   (0x60,LANG_MENU_OSD_RAW_TRESHOLD,           MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,  &conf.remaining_raw_treshold,   MENU_MINMAX(0, 200) ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,        0,                          0 ),
    {0}
};

static CMenu raw_state_submenu = {0x24,LANG_MENU_OSD_RAW_STATE_PARAMS_TITLE, NULL, raw_state_submenu_items };

#ifdef  CAM_TOUCHSCREEN_UI
static const char* gui_touchscreen_disable_modes[]=         { "Enable", "Disable" };
static CMenuItem touchscreen_submenu_items[] = {
    MENU_ENUM2  (0x5f,LANG_MENU_TS_VIDEO_AE_DISABLE,        &conf.touchscreen_disable_video_controls,    gui_touchscreen_disable_modes ),
    MENU_ENUM2  (0x5f,LANG_MENU_TS_ALT_SHORTCUTS_DISABLE,   &conf.touchscreen_disable_shortcut_controls, gui_touchscreen_disable_modes ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,        0, 0 ),
    {0}
};
static CMenu touchscreen_submenu = {0x28,LANG_MENU_TOUCHSCREEN_VALUES, /*cb_values_menu_change*/ NULL, touchscreen_submenu_items };
#endif

#ifdef CAM_HAS_CMOS
    static const char* gui_temp_mode_modes[] =              { "Off", "Optical", "CMOS", "Battery", "all" };
#else
    static const char* gui_temp_mode_modes[] =              { "Off", "Optical", "CCD", "Battery", "all" };
#endif
static const char* gui_hide_osd_modes[] =                   { "Don't", "In Playback", "On Disp Press", "Both" };
static const char* gui_show_usb_info_modes[] =              { "Off", "Icon", "Text" };
static CMenuItem osd_submenu_items[] = {
    MENU_ITEM   (0x5c,LANG_MENU_OSD_SHOW,                   MENUITEM_BOOL,      &conf.show_osd,             0 ),
    MENU_ENUM2  (0x5c,LANG_MENU_OSD_HIDE_PLAYBACK,          &conf.hide_osd,     gui_hide_osd_modes ),
    MENU_ITEM   (0x81,LANG_MENU_VIS_MENU_CENTER,            MENUITEM_BOOL,      &conf.menu_center,          0 ),
    MENU_ITEM   (0x81,LANG_MENU_SELECT_FIRST_ENTRY,         MENUITEM_BOOL,      &conf.menu_select_first_entry, 0 ),
    MENU_ITEM   (0x64,LANG_MENU_VIS_SYMBOL,                 MENUITEM_BOOL,      &conf.menu_symbol_enable,   0 ),
    MENU_ITEM   (0x2e,LANG_MENU_USER_MENU,                  MENUITEM_SUBMENU,   &user_submenu,              0 ),
    MENU_ITEM   (0x5f,LANG_MENU_USER_MENU_ENABLE,           MENUITEM_ENUM,      gui_user_menu_show_enum,    0 ),
    MENU_ITEM   (0x5c,LANG_MENU_USER_MENU_AS_ROOT,          MENUITEM_BOOL,      &conf.user_menu_as_root,    0 ),
    MENU_ITEM   (0x5f,LANG_MENU_OSD_SHOW_STATES,            MENUITEM_BOOL,      &conf.show_state,           0 ),
    MENU_ENUM2  (0x5f,LANG_MENU_OSD_SHOW_TEMP,              &conf.show_temp,    gui_temp_mode_modes ),
    MENU_ITEM   (0x59,LANG_MENU_OSD_TEMP_FAHRENHEIT,        MENUITEM_BOOL,      &conf.temperature_unit,     0 ),
    MENU_ENUM2  (0x71,LANG_MENU_USB_SHOW_INFO,              &conf.usb_info_enable, gui_show_usb_info_modes ),
    MENU_ITEM   (0x72,LANG_MENU_OSD_LAYOUT_EDITOR,          MENUITEM_PROC,      gui_draw_osd_le,            0 ),
    MENU_ITEM   (0x2f,LANG_MENU_OSD_GRID_PARAMS,            MENUITEM_SUBMENU,   &grid_submenu,              0 ),
    MENU_ITEM   (0x22,LANG_MENU_OSD_VALUES,                 MENUITEM_SUBMENU,   &values_submenu,            0 ),
    MENU_ITEM   (0x31,LANG_MENU_OSD_DOF_CALC,               MENUITEM_SUBMENU,   &dof_submenu,               0 ),
    MENU_ITEM   (0x24,LANG_MENU_OSD_RAW_STATE_PARAMS,       MENUITEM_SUBMENU,   &raw_state_submenu,         0 ),
    MENU_ITEM   (0x32,LANG_MENU_OSD_BATT_PARAMS,            MENUITEM_SUBMENU,   &battery_submenu,           0 ),
    MENU_ITEM   (0x33,LANG_MENU_OSD_SPACE_PARAMS,           MENUITEM_SUBMENU,   &space_submenu,             0 ),
    MENU_ITEM   (0x34,LANG_MENU_OSD_CLOCK_PARAMS,           MENUITEM_SUBMENU,   &clock_submenu,             0 ),
    MENU_ITEM   (0x59,LANG_MENU_OSD_SHOW_IN_REVIEW,         MENUITEM_BOOL,      &conf.show_osd_in_review,   0 ),
#ifndef OPTIONS_AUTOSAVE
    MENU_ITEM   (0x5c,LANG_MENU_MAIN_SAVE_OPTIONS,          MENUITEM_PROC,      gui_menuproc_save,          0 ),
#endif
#ifdef  CAM_TOUCHSCREEN_UI
    MENU_ITEM   (0x22,LANG_MENU_TOUCHSCREEN_VALUES,         MENUITEM_SUBMENU,   &touchscreen_submenu,       0 ),
#endif
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP, 0,                                 0 ),
    {0}
};

static CMenu osd_submenu = {0x22,LANG_MENU_OSD_TITLE, NULL, osd_submenu_items };

static const char* gui_histo_show_modes[] =                 { "Don't", "Always", "Shoot" };
static CMenuItem histo_submenu_items[] = {
    MENU_ENUM2  (0x5f,LANG_MENU_HISTO_SHOW,                 &conf.show_histo,   gui_histo_show_modes ),
    MENU_ITEM   (0x6f,LANG_MENU_HISTO_LAYOUT,               MENUITEM_ENUM,      gui_histo_layout_enum,      0 ),
    MENU_ITEM   (0x5f,LANG_MENU_HISTO_MODE,                 MENUITEM_ENUM,      gui_histo_mode_enum,        0 ),
    MENU_ITEM   (0x5c,LANG_MENU_HISTO_EXP,                  MENUITEM_BOOL,      &conf.show_overexp,         0 ),
    MENU_ITEM   (0x70,LANG_MENU_HISTO_IGNORE_PEAKS,         MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,  &conf.histo_ignore_boundary,   MENU_MINMAX(0, 32) ),
    MENU_ITEM   (0x5c,LANG_MENU_HISTO_MAGNIFY,              MENUITEM_BOOL,      &conf.histo_auto_ajust,     0 ),
    MENU_ITEM   (0x5c,LANG_MENU_HISTO_SHOW_EV_GRID,         MENUITEM_BOOL,      &conf.histo_show_ev_grid,   0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,        0,                          0 ),
    {0}
};
static CMenu histo_submenu = {0x25,LANG_MENU_HISTO_TITLE, NULL, histo_submenu_items };

static CMenuItem raw_exceptions_submenu_items[] = {
#if defined CAM_HAS_VIDEO_BUTTON
    MENU_ITEM   (0x5c,LANG_MENU_RAW_SAVE_IN_VIDEO,          MENUITEM_BOOL,      &conf.save_raw_in_video,        0 ),
#endif
#if defined(CAMERA_s3is)
    MENU_ITEM   (0x5c,LANG_MENU_RAW_SAVE_IN_SPORTS,         MENUITEM_BOOL,      &conf.save_raw_in_sports,       0 ),
#endif
    MENU_ITEM   (0x5c,LANG_MENU_RAW_SAVE_IN_BURST,          MENUITEM_BOOL,      &conf.save_raw_in_burst,        0 ),
    MENU_ITEM   (0x5c,LANG_MENU_RAW_SAVE_IN_TIMER,          MENUITEM_BOOL,      &conf.save_raw_in_timer,        0 ),
    MENU_ITEM   (0x5c,LANG_MENU_RAW_SAVE_IN_EDGEOVERLAY,    MENUITEM_BOOL,      &conf.save_raw_in_edgeoverlay,  0 ),
    MENU_ITEM   (0x5c,LANG_MENU_RAW_SAVE_IN_AUTO,           MENUITEM_BOOL,      &conf.save_raw_in_auto,         0 ),
#if CAM_BRACKETING
    MENU_ITEM   (0x5c,LANG_MENU_RAW_SAVE_IN_EV_BRACKETING,  MENUITEM_BOOL,      &conf.save_raw_in_ev_bracketing, 0 ),
#endif
    MENU_ITEM   (0x5c,LANG_MENU_RAW_WARN,                   MENUITEM_BOOL,      &conf.raw_exceptions_warn,      0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,        0,                              0 ),
    {0}
};
static CMenu raw_exceptions_submenu = {0x59,LANG_MENU_OSD_RAW_EXCEPTIONS_PARAMS_TITLE, NULL, raw_exceptions_submenu_items };


static const char* gui_raw_nr_modes[] =                     { "Auto", "Off", "On"};
static CMenuItem raw_submenu_items[] = {
    MENU_ITEM   (0x5c,LANG_MENU_RAW_SAVE,                   MENUITEM_BOOL,      &conf.save_raw,             0 ),
    MENU_ITEM   (0x59,LANG_MENU_OSD_RAW_EXCEPTIONS_PARAMS,  MENUITEM_SUBMENU,   &raw_exceptions_submenu,    0 ),
    MENU_ENUM2  (0x5f,LANG_MENU_RAW_NOISE_REDUCTION,        &conf.raw_nr,       gui_raw_nr_modes ),
    MENU_ITEM   (0x5c,LANG_MENU_RAW_FIRST_ONLY,             MENUITEM_BOOL,      &conf.raw_save_first_only,  0 ),
    MENU_ITEM   (0x5c,LANG_MENU_RAW_SAVE_IN_DIR,            MENUITEM_BOOL,      &conf.raw_in_dir,           0 ),
    MENU_ENUM2a (0x5f,LANG_MENU_RAW_PREFIX,                 &conf.raw_prefix, img_prefixes, NUM_IMG_PREFIXES ),
    MENU_ENUM2a (0x5f,LANG_MENU_RAW_EXTENSION,              &conf.raw_ext,      img_exts, NUM_IMG_EXTS ),
    MENU_ENUM2a (0x5f,LANG_MENU_SUB_PREFIX,                 &conf.sub_batch_prefix, img_prefixes, NUM_IMG_PREFIXES ),
    MENU_ENUM2a (0x5f,LANG_MENU_SUB_EXTENSION,              &conf.sub_batch_ext, img_exts, NUM_IMG_EXTS ),
    MENU_ITEM   (0x2a,LANG_MENU_RAW_DEVELOP,                MENUITEM_PROC,      gui_raw_develop,            0 ),
    MENU_ITEM   (0x5c,LANG_MENU_BAD_PIXEL_REMOVAL,          MENUITEM_ENUM,      gui_bad_pixel_enum,         0 ),
#if DNG_SUPPORT
    MENU_ITEM   (0x5c,LANG_MENU_DNG_FORMAT,                 MENUITEM_BOOL | MENUITEM_ARG_CALLBACK, &conf.dng_raw , (int)cb_change_dng ),
    MENU_ITEM   (0x5c,LANG_MENU_RAW_DNG_EXT,                MENUITEM_BOOL,      &conf.raw_dng_ext,          0 ),
    MENU_ITEM   (0x2a,LANG_MENU_BADPIXEL_CREATE,            MENUITEM_PROC,      gui_menuproc_badpixel_create, 0 ),
#endif
    MENU_ITEM   (0x5c,LANG_MENU_RAW_CACHED,                 MENUITEM_BOOL,      &conf.raw_cache,            0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,        0,                          0 ),
    {0}
};
static CMenu raw_submenu = {0x24,LANG_MENU_RAW_TITLE, NULL, raw_submenu_items };


static const char* gui_zebra_mode_modes[] =                 { "Blink 1", "Blink 2", "Blink 3", "Solid", "Zebra 1", "Zebra 2" };
static const char* gui_zebra_draw_osd_modes[] =             { "Nothing", "Histo", "OSD" };
static CMenuItem zebra_submenu_items[] = {
    MENU_ITEM   (0x5c,LANG_MENU_ZEBRA_DRAW,                 MENUITEM_BOOL,                              &conf.zebra_draw,           0 ),
    MENU_ENUM2  (0x5f,LANG_MENU_ZEBRA_MODE,                 &conf.zebra_mode,                           gui_zebra_mode_modes ),
    MENU_ITEM   (0x58,LANG_MENU_ZEBRA_UNDER,                MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,  &conf.zebra_under, MENU_MINMAX(0, 32) ),
    MENU_ITEM   (0x57,LANG_MENU_ZEBRA_OVER,                 MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,  &conf.zebra_over,  MENU_MINMAX(0, 32) ),
    MENU_ITEM   (0x28,LANG_MENU_ZEBRA_RESTORE_SCREEN,       MENUITEM_BOOL|MENUITEM_ARG_CALLBACK,        &conf.zebra_restore_screen, (int)cb_zebra_restore_screen ),
    MENU_ITEM   (0x5c,LANG_MENU_ZEBRA_RESTORE_OSD,          MENUITEM_BOOL|MENUITEM_ARG_CALLBACK,        &conf.zebra_restore_osd,    (int)cb_zebra_restore_osd ),
    MENU_ENUM2  (0x5f,LANG_MENU_ZEBRA_DRAW_OVER,            &conf.zebra_draw_osd,                       gui_zebra_draw_osd_modes ),
    MENU_ITEM   (0x5c,LANG_MENU_ZEBRA_MULTICHANNEL,         MENUITEM_BOOL,                              &conf.zebra_multichannel,   0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,                                0,                          0 ),
    {0}
};
static CMenu zebra_submenu = {0x26,LANG_MENU_ZEBRA_TITLE, NULL, zebra_submenu_items };

#ifdef OPT_CURVES
static CMenuItem curve_submenu_items[] = {
    MENU_ITEM   (0x5f,LANG_MENU_CURVE_ENABLE,               MENUITEM_ENUM,      gui_conf_curve_enum,0 ),
    MENU_ITEM   (0x35,LANG_MENU_CURVE_LOAD,                 MENUITEM_PROC,      gui_load_curve,     0 ),
    MENU_ITEM   (0x0 ,LANG_MENU_CURVE_CURRENT,              MENUITEM_SEPARATOR, 0,                  0 ),
    MENU_ITEM   (0x0 ,(int)conf.curve_file,                 MENUITEM_TEXT,      0,                  0 ),
    MENU_ITEM   (0x0 ,(int)"",                              MENUITEM_SEPARATOR, 0,                  0 ),
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,        0,                  0 ),
    {0}
};
static CMenu curve_submenu = {0x85,LANG_MENU_CURVE_PARAM_TITLE, NULL, curve_submenu_items };
#endif

static CMenuItem root_menu_items[] = {
    MENU_ITEM   (0x21,LANG_MENU_OPERATION_PARAM,            MENUITEM_SUBMENU,   &operation_submenu, 0 ),
    MENU_ITEM   (0x23,LANG_MENU_VIDEO_PARAM,                MENUITEM_SUBMENU,   &video_submenu,     0 ),
    MENU_ITEM   (0x24,LANG_MENU_MAIN_RAW_PARAM,             MENUITEM_SUBMENU,   &raw_submenu,       0 ),
#ifdef OPT_EDGEOVERLAY
    MENU_ITEM   (0x7f,LANG_MENU_EDGE_OVERLAY,               MENUITEM_SUBMENU,   &edge_overlay_submenu, 0 ),
#endif
#ifdef OPT_CURVES
    MENU_ITEM   (0x85,LANG_MENU_CURVE_PARAM,                MENUITEM_SUBMENU,   &curve_submenu,     0 ),
#endif
    MENU_ITEM   (0x25,LANG_MENU_MAIN_HISTO_PARAM,           MENUITEM_SUBMENU,   &histo_submenu,     0 ),
    MENU_ITEM   (0x26,LANG_MENU_MAIN_ZEBRA_PARAM,           MENUITEM_SUBMENU,   &zebra_submenu,     0 ),
    MENU_ITEM   (0x22,LANG_MENU_MAIN_OSD_PARAM,             MENUITEM_SUBMENU,   &osd_submenu,       0 ),
    MENU_ITEM   (0x28,LANG_MENU_MAIN_VISUAL_PARAM,          MENUITEM_SUBMENU,   &visual_submenu,    0 ),
#ifdef OPT_SCRIPTING
    MENU_ITEM   (0x27,LANG_MENU_MAIN_SCRIPT_PARAM,          MENUITEM_SUBMENU,   &script_submenu,    0 ),
#endif
    MENU_ITEM   (0x29,LANG_MENU_MAIN_MISC,                  MENUITEM_SUBMENU,   &misc_submenu,      0 ),
#ifndef OPTIONS_AUTOSAVE
    MENU_ITEM   (0x33,LANG_MENU_MAIN_SAVE_OPTIONS,          MENUITEM_PROC,      gui_menuproc_save,  0 ),
#endif
#ifdef CAM_HAS_GPS
    MENU_ITEM	(0x2a,LANG_MENU_GPS,                        MENUITEM_SUBMENU,	&gps_submenu,		0 ),
#endif
    {0}
};

static CMenu root_menu = {0x20,LANG_MENU_MAIN_TITLE, NULL, root_menu_items };

static int gui_user_menu_flag;

static char buf[256];

void rinit(){
    // Erase screen if switching from user menu to main menu 
    // in case the user menu is larger than the main menu 
    // otherwise it leaves remnants of the user menu above and below 
    // the main menu. 
    draw_restore(); 
    gui_menu_init(&root_menu);
}

//-------------------------------------------------------------------
#ifdef CAM_HAS_GPS

void gpx_start_stop(int arg) {
    int i = 0;
    while( gps_submenu_items[i].value != (int*)gpx_start_stop ) i++;    //find entry
    if( gps_submenu_items[i].text == LANG_MENU_GPS_TRACK_START ) {  //toggle text
        gps_submenu_items[i].text = LANG_MENU_GPS_TRACK_STOP;
		exit_gpx_record = 0;
		init_gpx_record_task();

    } else {
        gps_submenu_items[i].text = LANG_MENU_GPS_TRACK_START;
		exit_gpx_record = 1;
    }
}

void show_kompass(int arg){
    int i = 0;
    while( gps_submenu_items[i].value != (int*)show_kompass ) i++;    //find entry
    if( gps_submenu_items[i].text == LANG_MENU_GPS_KOMPASS_SHOW ) {  //toggle text
        gps_submenu_items[i].text = LANG_MENU_GPS_KOMPASS_HIDE;
		exit_gps_kompass = 0;
		init_gps_kompass_task();

    } else {
        gps_submenu_items[i].text = LANG_MENU_GPS_KOMPASS_SHOW;
		exit_gps_kompass = 1;
    }
}

void show_navi(int arg){
    int i = 0;
    while( gps_submenu_items[i].value != (int*)show_navi ) i++;    //find entry
    if( gps_submenu_items[i].text == LANG_MENU_GPS_NAVI_SHOW ) {  //toggle text
        gps_submenu_items[i].text = LANG_MENU_GPS_NAVI_HIDE;
		exit_gpx_record = 0;
		exit_gps_navi = 0;
		exit_gps_kompass = 0;
		init_gps_trackback_task();

    } else {
        gps_submenu_items[i].text = LANG_MENU_GPS_NAVI_SHOW;
		exit_gps_navi = 1;
		exit_gps_kompass = 1;
		exit_gpx_record = 1;
    }
}

void navigate_home(int arg){
	int i = 0;
    while( gps_submenu_items[i].value != (int*)navigate_home ) i++;    //find entry
    if( gps_submenu_items[i].text == LANG_MENU_GPS_NAVI_HOME ) {  //toggle text
        gps_submenu_items[i].text = LANG_MENU_GPS_NAVI_HOME_END;
		exit_gpx_record = 0;
		exit_gps_navi = 0;
		exit_gps_kompass = 0;
		gps_navigate_home();

    } else {
        gps_submenu_items[i].text = LANG_MENU_GPS_NAVI_HOME;
		exit_gps_navi = 1;
		exit_gps_kompass = 1;
		exit_gpx_record = 1;
    }
}

void mark_timezone(int arg){
write_timezone();
}

void mark_home(int arg){
write_home();
}

#endif
void
mod_user_menu(CMenuItem curr_menu_item, int* cur_memnu_item_indx, int mod) {
int i;
CMenuItem tmp_menu_item;
    switch(mod) {

        case 0:
            /*
            * Delete user menu entry by sliding all the lower valid/existing entries up.
            */

            if (*cur_memnu_item_indx == 0) /* don't allow deleting "user menu" */
                break;
            for(i = *cur_memnu_item_indx; user_submenu_items[i].text; i++) {
                user_submenu_items[i] = user_submenu_items[i+1];
            }
 
            /*
            * there were no valid entries below this one, so
            * the index pointer must be decremented.
            */
            if(!user_submenu_items[*cur_memnu_item_indx].text)
                *cur_memnu_item_indx -= 1;
            break;
 
        case 1:
            /*
            * Insert new Item at end of existing entries
            */
            for(i = 1; i < USER_MENU_ITEMS + 1; i++) {
                if(!user_submenu_items[i].text) {
                    user_submenu_items[i] = curr_menu_item;
                    break;
                }
            }
            break;
 
        case 2:
            /*
            * Move entry up
            */
            if((*cur_memnu_item_indx > 1)) {
                tmp_menu_item = user_submenu_items[*cur_memnu_item_indx -1];
                user_submenu_items[*cur_memnu_item_indx -1] = user_submenu_items[*cur_memnu_item_indx];
                user_submenu_items[*cur_memnu_item_indx] = tmp_menu_item;
                *cur_memnu_item_indx -=1;
            }
        break;

        case 3:
            /*
            * Move entry down below next entry if next entry is not empty
            */
            if (*cur_memnu_item_indx == 0) /* don't allow moving "user menu" */
                break;
            if((*cur_memnu_item_indx < (USER_MENU_ITEMS)) && (user_submenu_items[*cur_memnu_item_indx +1].text)) {
                tmp_menu_item = user_submenu_items[*cur_memnu_item_indx +1];
                user_submenu_items[*cur_memnu_item_indx + 1] = user_submenu_items[*cur_memnu_item_indx];
                user_submenu_items[*cur_memnu_item_indx] = tmp_menu_item;
                *cur_memnu_item_indx +=1;
            }
            break;
    }
}

//-------------------------------------------------------------------
void cb_step_25() {
    voltage_step = (conf.batt_step_25)?25:1;
}

void cb_perc() {
    conf.batt_volts_show=0;
}

void cb_volts() {
    conf.batt_perc_show=0;
}

void cb_space_perc() {
    conf.space_mb_show=0;
}

void cb_space_mb() {
    conf.space_perc_show=0;
}

void cb_battery_menu_change(unsigned int item) {
    switch (item) {
        case 0: //Voltage MAX
            if (conf.batt_volts_max<conf.batt_volts_min+25) {
                conf.batt_volts_min = conf.batt_volts_max-25;
            }
            break;
        case 1: //Voltage MIN
            if (conf.batt_volts_min>conf.batt_volts_max-25) {
                conf.batt_volts_max = conf.batt_volts_min+25;
            }
            break;
        default:
            break;
    }
}

void cb_zebra_restore_screen() {
    if (!conf.zebra_restore_screen)
        conf.zebra_restore_osd = 0;
}

void cb_zebra_restore_osd() {
    if (conf.zebra_restore_osd)
        conf.zebra_restore_screen = 1;
}

#if DNG_SUPPORT
void cb_change_dng(){
     int old=conf.dng_raw;
     conf_change_dng();
     if ((old==1) && (conf.dng_raw==0)) gui_mbox_init(LANG_ERROR, LANG_CANNOT_OPEN_BADPIXEL_FILE, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
}
    
void gui_menuproc_badpixel_create(int arg) {
    create_badpixel_bin();
}
#endif

#if defined (DNG_EXT_FROM)
    void cb_change_dng_usb_ext(){
     if (conf.dng_usb_ext) change_ext_to_dng(); else change_ext_to_default();
}
#endif

void cb_autoiso_menu_change(unsigned int item)
{
    conf.autoiso_min_shutter_numerator = shutter1_values[conf.autoiso_shutter_enum];
    conf.autoiso2_min_shutter_numerator =  shutter2_values[conf.autoiso2_shutter_enum];

    conf.autoiso_max_iso_auto_real=0;	// set invalid value of real autoiso as flag 'need recalc'
}

/*
common code for "enum" menu items that just take a list of string values and don't require any special setters
would be better to have another menu item type that does this by default
save memory by eliminating dupe code
*/
static void gui_enum_value_change(int *value, int change, unsigned num_items) {
    *value+=change;
    if (*value<0)
        *value = num_items-1;
    else if (*value>=num_items)
        *value = 0;
}

static const char* gui_change_simple_enum(int* value, int change, const char** items, unsigned num_items) {
    gui_enum_value_change(value, change, num_items);
    return items[*value];
}

const char* gui_change_enum2(const CMenuItem *menu_item, int change)
{
    const char** items = (const char**)menu_item->arg;
    gui_enum_value_change(menu_item->value, change, menu_item->opt_len);
    return items[*menu_item->value];
}

//-------------------------------------------------------------------
#if CAM_REMOTE
    const char* gui_show_usb_info_enum(int change, int arg) {
        static const char* modes[]={ "Off", "Icon", "Text"};

        gui_enum_value_change(&conf.usb_info_enable,change,sizeof(modes)/sizeof(modes[0]));

        return modes[conf.usb_info_enable];
    }
#endif
//-------------------------------------------------------------------
#ifdef OPT_CURVES
    const char* gui_conf_curve_enum(int change, int arg) {
        static const char* modes[]={ "None", "Custom", "+1EV", "+2EV", "Auto DR" };

        gui_enum_value_change(&conf.curve_enable,change,sizeof(modes)/sizeof(modes[0]));

        if(change)
            curve_init_mode();
        return modes[conf.curve_enable];
    }
#endif

#ifdef OPT_SCRIPTING
//-------------------------------------------------------------------
const char* gui_script_param_set_enum(int change, int arg) {
    static const char* modes[]={ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

    if (change != 0) {
        if (conf.script_param_save) {
            save_params_values(0);
        }
        gui_enum_value_change(&conf.script_param_set,change,sizeof(modes)/sizeof(modes[0]));

        if (!load_params_values(conf.script_file, 1, 0))
            script_load(conf.script_file, 0);
        gui_update_script_submenu();
    }

    return modes[conf.script_param_set];
}

//-------------------------------------------------------------------
void gui_update_script_submenu() {
    register int p=0, i;

    for (i=0; i<sizeof(script_submenu_items_top)/sizeof(script_submenu_items_top[0]); ++p, ++i)
    {
        script_submenu_items[p]=script_submenu_items_top[i];
    }
    for (i=0; i<SCRIPT_NUM_PARAMS; ++i)
    {
        if (script_param_order[i])
        {
            int n = script_param_order[i]-1;

            script_submenu_items[p].symbol = 0x0;
            script_submenu_items[p].text = (int)script_params[n];
            script_submenu_items[p].type = MENUITEM_INT;
            script_submenu_items[p].value = &conf.script_vars[n];

            if (script_range_values[n] != 0)
            {
                script_submenu_items[p].type = script_range_types[n];
                script_submenu_items[p].arg = script_range_values[n];
            }
            else if (script_named_counts[n] != 0)
            {
                script_submenu_items[p].type = MENUITEM_ENUM2;
                script_submenu_items[p].opt_len = script_named_counts[n];
                script_submenu_items[p].arg = (int)script_named_values[n];
            }

            ++p;
        }
    }
    for (i=0; i<sizeof(script_submenu_items_bottom)/sizeof(script_submenu_items_bottom[0]); ++p, ++i)
    {
        script_submenu_items[p]=script_submenu_items_bottom[i];
    }
}

//-------------------------------------------------------------------
static void gui_load_script_selected(const char *fn) {
    if (fn)
        script_load(fn, 1);
}

void gui_load_script(int arg) {
    gui_fselect_init(LANG_STR_SELECT_SCRIPT_FILE, conf.script_file, "A/CHDK/SCRIPTS", gui_load_script_selected);
}

void gui_load_script_default(int arg) {
    script_load(conf.script_file, 0);
    if (conf.script_param_save) {
        save_params_values(1);
    }
}
#endif

//-------------------------------------------------------------------
const char* gui_override_disable_enum(int change, int arg) {
    return gui_change_simple_enum(&conf.override_disable,change,gui_override_disable_modes,sizeof(gui_override_disable_modes)/sizeof(gui_override_disable_modes[0]));
}

//-------------------------------------------------------------------
const char* gui_histo_mode_enum(int change, int arg) {
    static const char* modes[]={ "Linear", "Log" };

    gui_enum_value_change(&conf.histo_mode,change,sizeof(modes)/sizeof(modes[0]));

    histogram_set_mode(conf.histo_mode);

    return modes[conf.histo_mode];
}

//-------------------------------------------------------------------
const char* gui_histo_layout_enum(int change, int arg) {
    static const char* modes[]={ "RGB", "Y", "RGB Y",  "R G B", "RGB all", "Y all", "Blend", "Blend Y"};

    gui_enum_value_change(&conf.histo_layout,change,sizeof(modes)/sizeof(modes[0]));

    if (conf.histo_layout==OSD_HISTO_LAYOUT_Y || conf.histo_layout==OSD_HISTO_LAYOUT_Y_argb) {
        histogram_set_main(HISTO_Y);
    } else {
        histogram_set_main(HISTO_RGB);
    }

    return modes[conf.histo_layout];
}

//-------------------------------------------------------------------
const char* gui_font_enum(int change, int arg) {
    static const char* fonts[]={ "Win1250", "Win1251", "Win1252", "Win1253", "Win1254", "Win1257"};

    gui_enum_value_change(&conf.font_cp,change,sizeof(fonts)/sizeof(fonts[0]));

    if (change != 0) {
        font_set(conf.font_cp);
        if (!rbf_load(conf.menu_rbf_file))
            rbf_load_from_8x16(current_font);
        rbf_set_codepage(FONT_CP_WIN);
        gui_menu_init(NULL);
    }

    return fonts[conf.font_cp];
}

//-------------------------------------------------------------------
#ifdef  CAM_TOUCHSCREEN_UI

const char* gui_on_off_enum(int change, int *conf_val)
{
    static const char* modes[]={ "Off", "On"};
    return gui_change_simple_enum(conf_val,change,modes,sizeof(modes)/sizeof(modes[0]));
}

#endif

//-------------------------------------------------------------------
const char* gui_nd_filter_state_enum(int change, int arg) {
    return gui_change_simple_enum(&conf.nd_filter_state,change,gui_nd_filter_state_modes,sizeof(gui_nd_filter_state_modes)/sizeof(gui_nd_filter_state_modes[0]));
}

const char* gui_histo_show_enum(int change, int arg) {
    return gui_change_simple_enum(&conf.show_histo,change,gui_histo_show_modes,sizeof(gui_histo_show_modes)/sizeof(gui_histo_show_modes[0]));
}

//-------------------------------------------------------------------
#if CAM_ADJUSTABLE_ALT_BUTTON
    const char* gui_alt_mode_button_enum(int change, int arg) {
    #if defined(CAMERA_s2is) || defined(CAMERA_s3is) || defined(CAMERA_s5is)
        static const char* names[]={ "Shrtcut", "Flash", "Timer", "ISO", "Video" };
        static const int keys[]={ KEY_PRINT, KEY_FLASH, KEY_TIMER, KEY_ISO, KEY_VIDEO };
    #elif defined(CAMERA_g7) || defined(CAMERA_g9)
        static const char* names[]={ "Print", "FE"};
        static const int keys[]={ KEY_PRINT, KEY_MICROPHONE };
    #elif defined(CAMERA_g10) || defined(CAMERA_g12)  
        static const char* names[]={ "Print", "Disp",  "AE Lock", "Jump" };
        static const int keys[]={ KEY_PRINT, KEY_DISPLAY, KEY_AE_LOCK, KEY_METERING};
    #elif defined(CAMERA_g11)
        static const char* names[]={ "Print", "Disp",  "AE Lock", "Jump" };
        static const int keys[]={ KEY_PRINT, KEY_DISPLAY, KEY_MICROPHONE, KEY_METERING};	
    #elif defined(CAMERA_a650)
        static const char* names[]={ "Print", "ISO"};
        static const int keys[]={ KEY_PRINT, KEY_ISO };
    #elif defined(CAMERA_a3300) || defined(CAMERA_a3200)
        static const char* names[]={ "Print", "Face", "Disp"};
        static const int keys[]={ KEY_PRINT, KEY_FACE, KEY_DISPLAY };
    #elif defined(CAMERA_sx100is) || defined(CAMERA_sx110is)
        static const char* names[]={ "Print", "Face"};
        static const int keys[]={ KEY_PRINT, KEY_FACE };
    #elif defined(CAMERA_sx10) || defined(CAMERA_sx1) || defined(CAMERA_sx20) || defined(CAMERA_sx30) || defined(CAMERA_sx40hs)
        static const char* names[]={ "Shrtcut", "Flash", "Video"};
        static const int keys[]={ KEY_PRINT, KEY_FLASH, KEY_VIDEO };
    #elif defined(CAMERA_a570) || defined(CAMERA_a580) || defined(CAMERA_a590) || defined(CAMERA_a720) || defined(CAMERA_ixus65_sd630)
        static const char* names[]={ "Print", "Display"};
        static const int keys[] = {KEY_PRINT, KEY_DISPLAY};
    #elif defined(CAMERA_sx150is) || (CAMERA_sx220hs) || defined(CAMERA_sx230hs)
        static const char* names[]={ "Playback", "Video", "Display" };
        static const int keys[] = {KEY_PRINT, KEY_VIDEO, KEY_DISPLAY};
    #elif defined(CAMERA_ixus220_elph300hs) || defined(CAMERA_ixus230_elph310hs)
        static const char* names[]={ "Video", "Display", "Playback", "Video"};
        static const int keys[] = {KEY_PRINT, KEY_DISPLAY, KEY_PLAYBACK, KEY_VIDEO};
    #else
        #error camera alt-buttons not defined
    #endif
        int i;

        for (i=0; i<sizeof(names)/sizeof(names[0]); ++i) {
            if (conf.alt_mode_button==keys[i]) {
                break;
            }
        }

        i+=change;
        if (i<0)
            i=(sizeof(names)/sizeof(names[0]))-1;
        else if (i>=(sizeof(names)/sizeof(names[0])))
            i=0;

        conf.alt_mode_button = keys[i];
        kbd_set_alt_mode_key_mask(conf.alt_mode_button);
        return names[i];
    }
#endif

//-------------------------------------------------------------------
const char* gui_alt_power_enum(int change, int arg) {
// Script option is retained even if scripting is disabled, otherwise conf values will change
// Equivalent to ALT
    static const char* modes[]={ "Never", "Alt", "Script", "Always" };

    gui_enum_value_change(&conf.alt_prevent_shutdown,change,sizeof(modes)/sizeof(modes[0]));
        
    return modes[conf.alt_prevent_shutdown];
}

//-------------------------------------------------------------------
const char* gui_video_bitrate_enum(int change, int arg) {
    gui_enum_value_change(&conf.video_bitrate,change,VIDEO_BITRATE_STEPS);

    shooting_video_bitrate_change(conf.video_bitrate);

    return video_bitrate_strings[conf.video_bitrate];
}

//-------------------------------------------------------------------
const char* gui_tv_bracket_values_enum(int change, int arg) {
    static const char* modes[]={ "Off", "1/3 Ev","2/3 Ev", "1 Ev", "1 1/3Ev", "1 2/3Ev", "2 Ev", "2 1/3Ev", "2 2/3Ev", "3 Ev", "3 1/3Ev", "3 2/3Ev", "4 Ev"};

    return gui_change_simple_enum(&conf.tv_bracket_value,change,modes,sizeof(modes)/sizeof(modes[0]));
}

const char* gui_tv_override_koef_enum(int change, int arg) {
    static const char* modes[]={"Off", "1/100K", "1/10000", "1/1000","1/100","1/10", "1","10","100"};

    conf.tv_override_koef+=change;
    if (conf.tv_enum_type) {
        if (conf.tv_override_koef<0)  conf.tv_override_koef=6;
        else if (conf.tv_override_koef>6) conf.tv_override_koef=0;
        else if (conf.tv_override_koef==1)	 conf.tv_override_koef=6;
        else if (conf.tv_override_koef==5)	 conf.tv_override_koef=0;
        else if (conf.tv_override_koef!=0 && conf.tv_override_koef!=6) conf.tv_override_koef=6;
    }
    else {
    if (conf.tv_override_koef<0)
        conf.tv_override_koef=sizeof(modes)/sizeof(modes[0])-1;
    else if (conf.tv_override_koef>=(sizeof(modes)/sizeof(modes[0])))
        conf.tv_override_koef=0;
    }

    return modes[conf.tv_override_koef]; 
}

const char* gui_tv_override_value_enum(int change, int arg) {
    /*
    static const char* modes[]={
    // add very long time exposures as approximately powers of 2, adding 15 exposures
    "2048","1625","1290","1024","812","645","512","406","322","256","203","161","128","101","80",
    "64","50.8", "40.3", "32", "25.4","20","16", "12.7", "10","8", "6.3","5","4","3.2", "2.5","2", "1.6", "1.3", "1", "0.8", "0.6", "0.5", "0.4", "0.3", "1/4", "1/5", "1/6", "1/8", "1/10", "1/13", "1/15", "1/20", "1/25", "1/30", "1/40", "1/50", "1/60", "1/80", "1/100", "1/125", "1/160", "1/200", "1/250", "1/320", "1/400", "1/500", "1/640","1/800", "1/1000", "1/1250", "1/1600","1/2000","1/2500","1/3200","1/4000", "1/5000", "1/6400", "1/8000", "1/10000", "1/12500", "1/16000", "1/20000", "1/25000", "1/32000", "1/40000", "1/50000", "1/64000","1/80000", "1/100k"};
    */

    // XXX This array above is redundant with platform/generic/shooting.c, this should be avoided!
    conf.tv_override_value+=change;
    if (conf.tv_enum_type) {
       if (conf.tv_override_value<0) {
          conf.tv_override_value=tv_override_amount-1;
        }
       else if ((unsigned)conf.tv_override_value>=(tv_override_amount))
         conf.tv_override_value=0;
       return tv_override[conf.tv_override_value]; 
    }
    else {
        if (conf.tv_override_value<0) {
            conf.tv_override_value=100;
        }
        else if (conf.tv_override_value>100)  conf.tv_override_value=0;
            sprintf(buf, "%d",  conf.tv_override_value);
        return buf; 
    }
}

const char* gui_tv_enum_type_enum(int change, int arg) {
    static const char* modes[]={"Factor", "Ev Step"};

    gui_enum_value_change(&conf.tv_enum_type,change,sizeof(modes)/sizeof(modes[0]));
    if (change) {
        conf.tv_override_koef=6;
        if (conf.tv_enum_type)  
            conf.tv_override_value=tv_override_zero_shift;
        else conf.tv_override_value=1; 
    }
    return modes[conf.tv_enum_type]; 
}

const char* gui_subj_dist_override_value_enum(int change, int arg) {
	int koef = shooting_get_subject_distance_override_koef();
    static char buf[9];
    if (koef == -1)
    {
        // If 'Infinity' selected in the 'koef' setting then set SD to the infinity value
        // technically the same as MAX_DIST when it's sent to the firmware function 
        // in the camera; but used here to alter the CHDK OSD display.
        conf.subj_dist_override_value = INFINITY_DIST;
    }
    else
    {
        // Increment / decrement the SD value, wrapping around from MIN_DIST to MAX_DIST
        conf.subj_dist_override_value += (change*koef);
        if (conf.subj_dist_override_value < MIN_DIST)
            conf.subj_dist_override_value = MAX_DIST;
        else if (conf.subj_dist_override_value > MAX_DIST)
            conf.subj_dist_override_value = MIN_DIST;
    }
    if (conf.subj_dist_override_value == INFINITY_DIST)
        strcpy(buf,"Inf.");
    else
        sprintf(buf, "%d", shooting_get_subject_distance_override_value());
    return buf; 
}

const char* gui_subj_dist_override_koef_enum(int change, int arg) {
    // Define the adjustment factor values for the subject distance override
#if MAX_DIST > 1000000      // Superzoom - e.g. SX30, SX40
    static const char* modes[] = { "Off", "1", "10", "100", "1000", "10K", "100K", "1M", "Inf." };
#elif MAX_DIST > 100000     // G12, IXUS310
    static const char* modes[] = { "Off", "1", "10", "100", "1000", "10K", "100K", "Inf." };
#else                       // Original values (MAX_DIST = 65535)
    static const char* modes[] = { "Off", "1", "10", "100", "1000" };
#endif
	const char *rv = gui_change_simple_enum(&conf.subj_dist_override_koef,change,modes,sizeof(modes)/sizeof(modes[0]));
    // If we've selected 'Infinity' focus then set the SD override value
    // Otherwise if we had previously selected 'Infinity' then reset back to MAX_DIST
    if (shooting_get_subject_distance_override_koef() == -1)
        conf.subj_dist_override_value = INFINITY_DIST;
    else if (conf.subj_dist_override_value == INFINITY_DIST)
        conf.subj_dist_override_value = MAX_DIST;
    return rv;
}

const char* gui_av_override_enum(int change, int arg) {
    conf.av_override_value+=change;
    if (conf.av_override_value<0) conf.av_override_value=shooting_get_aperture_sizes_table_size()+6;
    else if (conf.av_override_value>shooting_get_aperture_sizes_table_size()+6) conf.av_override_value=0;
    if (conf.av_override_value == 0)  return "Off";
    else {
         short prop_id=shooting_get_aperture_from_av96(shooting_get_av96_override_value());
         sprintf(buf, "%d.%02d", (int)prop_id/100, (int)prop_id%100 );
         return buf; 
    }
}

#if ZOOM_OVERRIDE
    const char* gui_zoom_override_enum(int change, int arg) {
        conf.zoom_override_value+=change;
        if (conf.zoom_override_value<0) conf.zoom_override_value=zoom_points-1;
        else if (conf.zoom_override_value>zoom_points-1) conf.zoom_override_value=0;
            sprintf(buf,"%i",conf.zoom_override_value);
            return buf; 
    }
#endif

const char* gui_user_menu_show_enum(int change, int arg) {
    static const char* modes[]={ "Off", "On","On Direct", "Edit" };

    if (conf.user_menu_enable == 3) user_menu_save();

    return gui_change_simple_enum(&conf.user_menu_enable,change,modes,sizeof(modes)/sizeof(modes[0]));
}
 
const char* gui_video_af_key_enum(int change, int arg) {
#if CAMERA_g12
    static const char* names[]={ "", "Shutter", "Set", "AE Lock"}; 
    static const int keys[]={0, KEY_SHOOT_HALF, KEY_SET, KEY_AE_LOCK }; 
#else
    static const char* names[]={ "", "Shutter", "Set"}; 
    static const int keys[]={0, KEY_SHOOT_HALF, KEY_SET }; 
#endif
    int i; 
 
    for (i=0; i<sizeof(names)/sizeof(names[0]); ++i) { 
        if (conf.video_af_key==keys[i]) { 
            break; 
        } 
    } 
 
    i+=change; 
    if (i<0) 
        i=(sizeof(names)/sizeof(names[0]))-1; 
    else if (i>=(sizeof(names)/sizeof(names[0]))) 
        i=0; 
 
    conf.video_af_key = keys[i]; 
    return names[i]; 
}
    
const char* gui_bad_pixel_enum(int change, int arg) { 
    int modes[]={LANG_MENU_BAD_PIXEL_OFF, LANG_MENU_BAD_PIXEL_INTERPOLATION, LANG_MENU_BAD_PIXEL_RAW_CONVERTER};
    
    return lang_str((int)gui_change_simple_enum(&conf.bad_pixel_removal,change,(const char**)modes,sizeof(modes)/sizeof(modes[0])));
}

//-------------------------------------------------------------------
void raw_fselect_cb(const char * filename){
    struct stat st;
    if (!filename) return;
    stat((char*)filename,&st);
    if (st.st_size!=hook_raw_size()) return;
    gui_mbox_init((int)"", LANG_RAW_DEVELOP_MESSAGE, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
    raw_prepare_develop((char*)filename);
}

//-------------------------------------------------------------------
void gui_raw_develop(int arg){
    gui_fselect_init(LANG_RAW_DEVELOP_SELECT_FILE, "A/DCIM", "A", raw_fselect_cb);
}

//-------------------------------------------------------------------
static void gui_menuproc_reset_files(int arg){
    conf.lang_file[0] = 0;
    conf.menu_symbol_rbf_file[0] = 0;
    conf.menu_rbf_file[0] = 0;
    conf_save();
    gui_mbox_init(LANG_INFORMATION, LANG_MENU_RESTART_CAMERA, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
}

//-------------------------------------------------------------------
#ifdef OPT_DEBUGGING
    #define TASKLIST_MAX_LINES 12 // probably as much as will fit on screen
    #define TASKLIST_NUM_TASKS 64 // should be enough ?
    static void gui_debug_draw_tasklist(void) {
    #ifndef CAM_DRYOS
        int tasklist[TASKLIST_NUM_TASKS]; // max number of tasks we will look at
        int n_tasks,n_show_tasks,show_start;
        const char *name;
        int i;
        n_tasks = task_id_list_get(tasklist,sizeof(tasklist)/sizeof(tasklist[0]));
        show_start = debug_tasklist_start;
        n_show_tasks = n_tasks - show_start;
        // auto adjust to show the last N tasks
        if(n_show_tasks < TASKLIST_MAX_LINES) {
            show_start = n_tasks - TASKLIST_MAX_LINES;
            if(show_start<0)
                show_start = 0;
             n_show_tasks = n_tasks - show_start;
        }
        else if( n_show_tasks > TASKLIST_MAX_LINES ) {
            n_show_tasks = TASKLIST_MAX_LINES;
        }
        sprintf(buf,"%d-%d of %d tasks %c",show_start,show_start+n_show_tasks,n_tasks,debug_display_direction > 0?'+':'-');
        draw_string(64,0,buf, conf.osd_color);
        for( i = 0;  i < n_show_tasks; i++ ) {
            // TODO get full task info
            name = task_name(tasklist[show_start+i]);
            if ( !name || !*name ) {
                name = "(unknown)";
            }
            sprintf(buf,"%10s %8X",name,tasklist[show_start+i]);
            draw_string(64,16+16*i,buf, conf.osd_color);
        }
    #endif //CAM_DRYOS
    }

    #define DEBUG_DISPLAY_NONE   0
    #define DEBUG_DISPLAY_PROPS  1
    #define DEBUG_DISPLAY_PARAMS 2
    #define DEBUG_DISPLAY_TASKS  3

    static void gui_debug_shortcut(void) {
        static int lastcall = -1;
        int t=get_tick_count();
        if ( lastcall != -1) {
            if (t-lastcall <= 400)
                debug_display_direction = -debug_display_direction;
        }
        lastcall=t;
        switch(conf.debug_shortcut_action) {
            case 1:
                dump_memory();
            break;
            case 2:
                if(conf.debug_display == DEBUG_DISPLAY_TASKS) {
                    debug_tasklist_start += debug_display_direction*(TASKLIST_MAX_LINES-2); // a little intentional overlap
                    if(debug_tasklist_start >= TASKLIST_NUM_TASKS || debug_tasklist_start < 0)
                        debug_tasklist_start = 0;
                }
                else if (conf.debug_display == DEBUG_DISPLAY_PROPS || conf.debug_display == DEBUG_DISPLAY_PARAMS) {
                    conf.debug_propcase_page += debug_display_direction*1;
                    if(conf.debug_propcase_page > 128 || conf.debug_propcase_page < 0) 
                        conf.debug_propcase_page = 0;
                }
            break;
            case 3:
                gui_compare_props(1);
            break;
        }
    }

#endif

#if CAM_MULTIPART
  void card_break_proc(unsigned int btn)
  {
    if (btn==MBOX_BTN_YES) create_partitions();
  }

#ifdef OPT_DEBUGGING
  static void gui_menuproc_break_card(int arg)
  {
    gui_mbox_init(LANG_WARNING, LANG_PARTITIONS_CREATE_WARNING, MBOX_BTN_YES_NO|MBOX_DEF_BTN2|MBOX_TEXT_CENTER, card_break_proc);
  }
#endif

  const char* gui_menuproc_swap_partitions_enum(int change, int arg)
  {
    int new_partition;
    int partition_count = get_part_count();
    char vBuf[16];
    if(partitions_enum)
    {
      free(partitions_enum);
      partitions_enum=NULL;
    }
    new_partition= get_active_partition()+change;
    if( new_partition <=0)
    {
      new_partition = partition_count;
    }
    else if( new_partition > partition_count)
    {
      new_partition = 1;
    }  
    sprintf(vBuf,"%d/%d",new_partition, partition_count);
    partitions_enum=malloc((strlen(vBuf)+1)*sizeof(char));
    strcpy(partitions_enum,vBuf);

    if(change != 0)
    {
      swap_partitions(new_partition);
    }
    return partitions_enum;
  }
#endif

//-------------------------------------------------------------------
static volatile enum Gui_Mode gui_mode;
static volatile int gui_restore;
static volatile int gui_in_redraw;
static int gui_splash, gui_splash_mode;
#ifdef OPTIONS_AUTOSAVE
    static Conf old_conf;
#endif

//-------------------------------------------------------------------
void gui_init()
{
    gui_set_mode(GUI_MODE_NONE);
    gui_restore = 0;
    gui_in_redraw = 0;
    if (conf.start_sound>0)
    {
        play_sound(4);
    }
    gui_splash = (conf.splash_show)?SPLASH_TIME:0;
    draw_init();

    exposition_thresh = screen_size/500;
    voltage_step = (conf.batt_step_25)?25:1;
    load_bad_pixels_list("A/CHDK/badpixel");
    load_bad_pixels_list("A/CHDK/badpixel.txt");
#ifdef OPT_CURVES
    // initialize curves, loading files if required by current mode
    curve_init_mode();
#endif

#if ZOOM_OVERRIDE
    // reyalp - need to do this in capt_seq
    // if (conf.zoom_override) shooting_set_zoom(conf.zoom_override_value);
#endif
}

//-------------------------------------------------------------------
#ifdef OPT_CURVES
    static void gui_load_curve_selected(const char *fn) {
        if (fn) {
            // TODO we could sanity check here, but curve_set_type should fail gracefullish
            strcpy(conf.curve_file,fn);
            if(conf.curve_enable == 1)
                curve_init_mode();
        }
    }

    //-------------------------------------------------------------------
    void gui_load_curve(int arg) {
        gui_fselect_init(LANG_STR_SELECT_CURVE_FILE, conf.curve_file, CURVE_DIR, gui_load_curve_selected);
    }

#endif
//-------------------------------------------------------------------
enum Gui_Mode gui_get_mode() {
    return gui_mode;
}

//-------------------------------------------------------------------
void gui_set_mode(enum Gui_Mode mode) {
#ifdef CAM_TOUCHSCREEN_UI
    if (((gui_mode == 0) != (mode == 0)) ||                         // Change from GUI_MODE_NONE to any other or vice-versa
        ((gui_mode > GUI_MODE_MENU) != (mode > GUI_MODE_MENU)))     // Switch in & out of menu mode
        redraw_buttons = 1;
#endif
    gui_mode = mode;
}

//-------------------------------------------------------------------
void gui_force_restore() {
    gui_restore = gui_in_redraw;
}

static void gui_handle_splash(void) {
    static char *logo = NULL;
    static int logo_size;
    if (gui_splash) {
        static int need_logo=1; // don't use logo ptr, since we don't want to keep re-trying
        if(need_logo) {
#if defined(VER_CHDK)
            const char *logo_name="A/CHDK/DATA/logo.dat";
#else   // CHDK-DE
            const char *logo_name="A/CHDK/DATA/logo_de.dat";
#endif
            FILE *fd;
            struct stat st;
            need_logo=0;
            if (stat(logo_name,&st) == 0) {
                logo_size=st.st_size;
                logo=malloc(logo_size);
                if(logo) {
                    fd = fopen(logo_name, "rb");
                    if(fd){
                        fread(logo,1,logo_size,fd);
                        fclose(fd);
                    }
                    else {
                        free(logo);
                        logo=NULL;
                        need_logo=1;
                    }
                }
            }
        }
        if (gui_splash>(SPLASH_TIME-4)) {
            gui_draw_splash(logo,logo_size);
           //   conf.show_osd = 0;
        } else if (gui_splash==1 && (mode_get()&MODE_MASK) == gui_splash_mode && (gui_mode==GUI_MODE_NONE || gui_mode==GUI_MODE_ALT)) {
            draw_restore();
           // conf.show_osd = 1; //had to uncomment in order to fix a bug with disappearing osd...
        }
        --gui_splash;
        if(!gui_splash) {
            free(logo);
            logo=NULL;
            need_logo=1;
        }
    }
}

//-------------------------------------------------------------------
#ifdef OPTIONS_AUTOSAVE

static void conf_store_old_settings() {
    old_conf=conf;
}

static int conf_save_new_settings_if_changed() {
    if (memcmp(&old_conf, &conf, sizeof(Conf)) != 0) {
		user_menu_save();
        conf_save();
        conf_store_old_settings();
        return 1;
    }
    return 0;
}

#endif

//-------------------------------------------------------------------
void gui_chdk_draw()
{
    static int show_md_grid=0;

    gui_draw_osd();

#ifdef CAM_DISP_ALT_TEXT
    draw_string(((vid_get_bitmap_screen_width()/2)-(FONT_WIDTH*5/2)), (vid_get_bitmap_screen_height()-FONT_HEIGHT), "<ALT>", MAKE_COLOR(COLOR_ALT_BG, COLOR_FG));
#endif

#ifdef OPT_SCRIPTING
    if ((mode_get()&MODE_MASK) == MODE_REC || (mode_get()&MODE_MASK) == MODE_PLAY)
    {
        draw_txt_string(0, 14, script_title, MAKE_COLOR(COLOR_ALT_BG, COLOR_FG));
        if (state_kbd_script_run) show_md_grid=5;
        if (show_md_grid)
        {
            --show_md_grid;
            md_draw_grid();
        }
    }
#endif

    console_draw();
}

//-------------------------------------------------------------------
// Handler for Menu button press default - enter Menu mode
void gui_default_kbd_process_menu_btn()
{
    gui_set_mode(GUI_MODE_MENU);
    draw_restore();
}

// Change SD override factor, direction = 1 to increase, -1 to decrease
// Only applies if camera has a Zoom lever
#if CAM_HAS_ZOOM_LEVER
static void sd_override_koef(int direction)
{
    gui_subj_dist_override_koef_enum(direction,0);
#if !CAM_HAS_MANUAL_FOCUS
    if (conf.subj_dist_override_koef==0) gui_subj_dist_override_koef_enum(direction,0);
#endif
    shooting_set_focus(shooting_get_subject_distance_override_value(), SET_NOW);
}
#endif

// Change SD override by factor amount, direction = 1 to increase (zoom in), -1 to decrease (zoom out)
static void sd_override(int direction)
{
    gui_subj_dist_override_value_enum(direction,0);
    shooting_set_focus(shooting_get_subject_distance_override_value(),SET_NOW);
}

// Main button processing for CHDK Alt mode (not in MENU mode)
// This needs to be cleaned up, re-organised and commented !!!!
void gui_chdk_kbd_process()
{
#if !CAM_HAS_ERASE_BUTTON && CAM_CAN_SD_OVERRIDE        // ALT RAW toggle kbd processing if camera has SD override but no erase button
    if (kbd_is_key_clicked(SHORTCUT_TOGGLE_RAW))
    {
        if (conf.debug_shortcut_action > 0)
        {
#ifdef OPT_DEBUGGING
            gui_debug_shortcut();
#endif
        }
        // Check in manual focus mode
        else if (!shooting_get_common_focus_mode())
        {
            // Not manual focus mode so just update RAW save setting
            conf.save_raw = !conf.save_raw;
            draw_restore();
        }
        else
        {
            // In manual focus mode so update shooting distance
#if CAM_HAS_ZOOM_LEVER
            conf.subj_dist_override_value=MAX_DIST;
            shooting_set_focus(shooting_get_subject_distance_override_value(), SET_NOW);
#else
            gui_subj_dist_override_koef_enum(1,0);
#endif
        }
    }
#else                                                   // ALT RAW toggle kbd processing if can't SD override or has erase button
    if (kbd_is_key_clicked(SHORTCUT_TOGGLE_RAW))
    {
        if (conf.debug_shortcut_action > 0)
        {
#ifdef OPT_DEBUGGING
            gui_debug_shortcut();
#endif
        }
        else
        {
            // Change RAW save state
            conf.save_raw = !conf.save_raw;
            draw_restore();
        }
    }
#endif
#ifdef OPT_SCRIPTING                                    // ALT Set button processing if scripting enabled - open script menu
    else if (kbd_is_key_clicked(KEY_SET))
    {
        gui_menu_init(&script_submenu);
        gui_default_kbd_process_menu_btn();
    }
#endif
#if CAM_CAN_SD_OVERRIDE                                 // ALT button processing if camera has SD override
    else
    {
#if !CAM_HAS_MANUAL_FOCUS
        if (kbd_is_key_clicked(SHORTCUT_MF_TOGGLE))     // Camera does not have manual focus
        {
            if (conf.subj_dist_override_koef>0)
                conf.subj_dist_override_koef=0;
            else conf.subj_dist_override_koef=1;
            draw_restore();
        }
        else
#endif
        if (shooting_get_common_focus_mode())           // Check in manual focus mode
        {
#if CAM_HAS_ZOOM_LEVER                                  // Camera has zoom lever, use left & right to change factor,up to set infinity
            if (kbd_is_key_clicked(KEY_RIGHT))
            {
                sd_override_koef(1);
            }
            else if (kbd_is_key_clicked(KEY_LEFT))
            {
                sd_override_koef(-1);
            }
            else if (kbd_is_key_clicked(SHORTCUT_SET_INFINITY))
            {
                conf.subj_dist_override_value=MAX_DIST;
                shooting_set_focus(shooting_get_subject_distance_override_value(), SET_NOW);
            }
            else
#endif
            if (kbd_is_key_clicked(SHORTCUT_SET_HYPERFOCAL))    // Set hyperfocal distance if down pressed
            {
                int m=mode_get()&MODE_SHOOTING_MASK;
                if ((m==MODE_M) || (m==MODE_AV))
                    conf.subj_dist_override_value=(int)shooting_get_hyperfocal_distance_1e3_f(shooting_get_aperture_from_av96(shooting_get_user_av96()),get_focal_length(lens_get_zoom_point()))/1000;
                else conf.subj_dist_override_value=(int)shooting_get_hyperfocal_distance();
                shooting_set_focus(shooting_get_subject_distance_override_value(), SET_NOW);
            }
            else
            {
                switch (kbd_get_autoclicked_key())
                {
#if CAM_HAS_ZOOM_LEVER
                case KEY_ZOOM_IN:
#else
                case KEY_RIGHT:
#endif
                    sd_override(1);
                    break;
#if CAM_HAS_ZOOM_LEVER
                case KEY_ZOOM_OUT:
#else
                case KEY_LEFT:
#endif
                    sd_override(-1);
                    break;
                }
            }
        }
    }
#endif
}

//-------------------------------------------------------------------
// Handler for Menu button press in CHDK Alt mode (not in Menu mode)
// Enter main menu or user menu based on configuration
void gui_chdk_kbd_process_menu_btn()
{
    if (conf.user_menu_as_root && (conf.user_menu_enable != 0)) {
        if (kbd_is_key_pressed(KEY_SHOOT_HALF))
            gui_menu_init(&root_menu);
        else
            gui_menu_init(&user_submenu);
    }
    else {
        if ((conf.user_menu_enable != 0) && kbd_is_key_pressed(KEY_SHOOT_HALF))
            gui_menu_init(&user_submenu);
        else
            gui_menu_init(&root_menu);
    }
    gui_default_kbd_process_menu_btn();
}

// Menu button handled for text reader
#ifdef OPT_TEXTREADER
void gui_read_kbd_process_menu_btn()
{
    gui_read_kbd_process();
    gui_default_kbd_process_menu_btn();
}
#endif

// Menu button handled for Menu mode
void gui_menu_kbd_process_menu_btn()
{
#ifdef OPTIONS_AUTOSAVE
    conf_save_new_settings_if_changed();
#endif
    if (gui_user_menu_flag)
    {
        gui_set_mode(GUI_MODE_MENU);
        gui_user_menu_flag = 0;
        gui_menu_init(&root_menu);
    }
    else
        gui_set_mode(GUI_MODE_ALT);
    draw_restore();
}

//-------------------------------------------------------------------
// Structure to store gui redraw and kbd process handlers for each mode
typedef struct
{
    void (*redraw)(void);                   // Called to redraw screen
    void (*kbd_process)(void);              // Main button handler for mode
    void (*kbd_process_menu_btn)(void);     // Menu button handler for mode
} gui_handler;

// GUI handler table (entries must be in the same order and have the same number of entries as Gui_Mode enum)
gui_handler guiHandlers[] =
{
    /*GUI_MODE_NONE*/           { gui_draw_osd,         0,                          0 },
    /*GUI_MODE_ALT*/            { gui_chdk_draw,        gui_chdk_kbd_process,       gui_chdk_kbd_process_menu_btn },
    /*GUI_MODE_MENU*/           { gui_menu_draw,        gui_menu_kbd_process,       gui_menu_kbd_process_menu_btn },
    /*GUI_MODE_PALETTE*/        { gui_palette_draw,     gui_palette_kbd_process,    gui_default_kbd_process_menu_btn },
    /*GUI_MODE_MBOX*/           { gui_mbox_draw,        gui_mbox_kbd_process,       0 },
#ifdef OPT_GAME_REVERSI
    /*GUI_MODE_REVERSI*/        { gui_reversi_draw,     gui_reversi_kbd_process,    gui_default_kbd_process_menu_btn },
#else
                                { 0, 0, 0 },
#endif
#ifdef OPT_GAME_SOKOBAN
    /*GUI_MODE_SOKOBAN*/        { gui_sokoban_draw,     gui_sokoban_kbd_process,    gui_default_kbd_process_menu_btn },
#else
                                { 0, 0, 0 },
#endif
#ifdef OPT_DEBUGGING
    /*GUI_MODE_DEBUG*/          { gui_debug_draw,       gui_debug_kbd_process,      gui_default_kbd_process_menu_btn },
#else
                                { 0, 0, 0 },
#endif
    /*GUI_MODE_FSELECT*/        { gui_fselect_draw,     gui_fselect_kbd_process,    gui_fselect_kbd_process },
#ifdef OPT_TEXTREADER
    /*GUI_MODE_READ*/           { gui_read_draw,        gui_read_kbd_process,       gui_read_kbd_process_menu_btn },
#else
                                { 0, 0, 0 },
#endif
    /*GUI_MODE_OSD*/            { gui_osd_draw,         gui_osd_kbd_process,        gui_default_kbd_process_menu_btn },
#ifdef OPT_CALENDAR
    /*GUI_MODE_CALENDAR*/       { gui_calendar_draw,    gui_calendar_kbd_process,   gui_default_kbd_process_menu_btn },
#else
                                { 0, 0, 0 },
#endif
#ifdef OPT_DEBUGGING
    /*GUI_MODE_BENCH*/          { gui_bench_draw,       gui_bench_kbd_process,      gui_default_kbd_process_menu_btn },
#else
                                { 0, 0, 0 },
#endif
    /*GUI_MODE_MPOPUP*/         { gui_mpopup_draw,      gui_mpopup_kbd_process,     gui_mpopup_kbd_process },
#ifdef OPT_GAME_CONNECT4
    /*GUI_MODE_4WINS*/          { gui_4wins_draw,       gui_4wins_kbd_process,      gui_default_kbd_process_menu_btn },
#else
                                { 0, 0, 0 },
#endif
#ifdef OPT_GAME_MASTERMIND
    /*GUI_MODE_MASTERMIND*/     { gui_mastermind_draw,  gui_mastermind_kbd_process, gui_default_kbd_process_menu_btn },
#else
                                { 0, 0, 0 },
#endif
#ifdef OPT_GAME_TETRIS
    /*GUI_MODE_TETRIS*/         { gui_tetris_draw,      gui_tetris_kbd_process,     gui_default_kbd_process_menu_btn },
#else
                                { 0, 0, 0 },
#endif
};

//-------------------------------------------------------------------
// Main GUI redraw function, perform common initialisation then calls the redraw handler for the mode
void gui_redraw()
{
    enum Gui_Mode gui_mode_old;

#ifdef CAM_DETECT_SCREEN_ERASE
    if (!draw_test_guard() && gui_mode)     // Attempt to detect screen erase in <Alt> mode, redraw if needed
    {
        draw_set_guard();
        gui_menu_force_redraw();
        gui_fselect_force_redraw();
#ifdef CAM_TOUCHSCREEN_UI
        extern int redraw_buttons;
        redraw_buttons = 1;
#endif
    }
#endif

    gui_handle_splash();

    gui_in_redraw = 1;
    gui_mode_old = gui_mode;

#ifdef CAM_TOUCHSCREEN_UI
    extern void virtual_buttons();
    virtual_buttons();
#endif

    // Call redraw handler
    if (guiHandlers[gui_mode].redraw) guiHandlers[gui_mode].redraw();

    // Forced redraw if needed
    gui_in_redraw = 0;
    if ((gui_mode_old != gui_mode && (gui_mode_old != GUI_MODE_NONE && gui_mode_old != GUI_MODE_ALT) && (gui_mode != GUI_MODE_MBOX && gui_mode != GUI_MODE_MPOPUP)) || gui_restore) {
        if (gui_restore) gui_menu_force_redraw();
        gui_restore = 0;
        if (gui_mode != GUI_MODE_REVERSI && gui_mode != GUI_MODE_SOKOBAN && gui_mode != GUI_MODE_4WINS && gui_mode != GUI_MODE_MASTERMIND && gui_mode != GUI_MODE_TETRIS)
        draw_restore();
    }
}

//-------------------------------------------------------------------
// Main kbd processing for GUI modes
void gui_kbd_process()
{
    // Call menu button handler if menu button pressed
    if (kbd_is_key_clicked(KEY_MENU))
    {
        if (guiHandlers[gui_mode].kbd_process_menu_btn) guiHandlers[gui_mode].kbd_process_menu_btn();
        return;
    }

    // Call mode handler for other buttons
    if (guiHandlers[gui_mode].kbd_process) guiHandlers[gui_mode].kbd_process();
}

//-------------------------------------------------------------------
void gui_kbd_enter()
{
    // XXX set custom palette
#ifdef OPTIONS_AUTOSAVE
    conf_store_old_settings();
#endif
    gui_set_mode(GUI_MODE_ALT);
    
    conf_update_prevent_shutdown();
    
    vid_turn_off_updates();

    // If user menu set to start automatically when <ALT> mode entered 
    // then enter user menu mode, unless a script was paused by exiting 
    // <ALT> mode when the script was running.
    gui_user_menu_flag = 0;
    if ((conf.user_menu_enable == 2) && !state_kbd_script_run) {
        gui_menu_init(&user_submenu);
        gui_set_mode(GUI_MODE_MENU);
        draw_restore();
        gui_user_menu_flag = 1;
    }

}

//-------------------------------------------------------------------
void gui_kbd_leave()
{
    // XXX restore palette
#ifdef OPTIONS_AUTOSAVE
    conf_save_new_settings_if_changed();
#endif
#ifdef OPT_UBASIC
    ubasic_error = UBASIC_E_NONE;
#endif
    draw_restore();
    if (gui_mode == GUI_MODE_READ && !rbf_load(conf.menu_rbf_file))
        rbf_load_from_8x16(current_font);
    rbf_set_codepage(FONT_CP_WIN);
    vid_turn_on_updates();
    gui_set_mode(GUI_MODE_NONE);
    
    conf_update_prevent_shutdown();
}

//------------------------------------------------------------------- 
void other_kbd_process(){ 
    int key;
#if CAM_AF_SCAN_DURING_VIDEO_RECORD 
   
    if (movie_status==VIDEO_RECORD_IN_PROGRESS) { 
        if (kbd_is_key_clicked(conf.video_af_key)) MakeAFScan(); 
    } 
 
#endif 

#if CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    // return from digital to optical zoom in video
    #if CAM_HAS_ZOOM_LEVER
        key=KEY_ZOOM_OUT;
    #else
        key=KEY_DOWN;
    #endif
        if (conf.unlock_optical_zoom_for_video && (movie_status==VIDEO_RECORD_IN_PROGRESS) &&  kbd_is_key_clicked(key)){
            short x;
            get_property_case(PROPCASE_DIGITAL_ZOOM_STATE, &x, sizeof(x));
            if (x) {
                get_property_case(PROPCASE_DIGITAL_ZOOM_POSITION, &x, sizeof(x));
    #if defined (CAMERA_s90) || defined (CAMERA_s95) || defined (CAMERA_g12) || defined (CAMERA_a3000)
        if (x==0) zoom_status=ZOOM_OPTICAL_MAX; //ERR99: No zoom back from digital to optical zoom possible if set to medium
    #else
        if (x==0) zoom_status=ZOOM_OPTICAL_MEDIUM;
    #endif

            }
        }
#endif

#if CAM_EV_IN_VIDEO
    if ((movie_status==VIDEO_RECORD_IN_PROGRESS) && !kbd_is_key_pressed(KEY_SHOOT_HALF)){
#if CAM_HAS_ERASE_BUTTON
        if (kbd_is_key_clicked(KEY_ERASE)){
#else
#if !defined (CAMERA_a480) && !defined (CAMERA_a495)
        if (kbd_is_key_clicked(KEY_DISPLAY)){
#else
        if (kbd_is_key_clicked(KEY_MENU)){
#endif  
#endif
            set_ev_video_avail(!get_ev_video_avail());
#ifdef CAM_TOUCHSCREEN_UI
            redraw_buttons = 1;
#endif
        }
        if (get_ev_video_avail()) {
            if (kbd_is_key_clicked(KEY_LEFT)) {
                set_ev_video(get_ev_video()-1);
            }
            if (kbd_is_key_clicked(KEY_RIGHT)){
                set_ev_video(get_ev_video()+1);
            }
        }
    }
#endif
}

void gui_draw_debug_vals_osd() {
#ifdef OPT_DEBUGGING

#if defined(OPT_EXMEM_TESTING)
    // Only do memory corruption testing if not recording video
    if (!MODE_IS_VIDEO(mode_get()))
    {
        // If defined the exmem memory is allocated; but not used for CHDK.
        // It is filled with a guard value (see wrappers.c) which is checked here
        // Any corruption is reported, otherwise 'OK' is displayed on screen (along with the exmem memory start address).
        extern void *exmem_start, *exmem_end;
        // check exmem allocated memory for corruption
        unsigned long* p = (unsigned long*)exmem_start;
        unsigned long *f = 0, *l = 0;
        long cnt = 0;
        while (p < (unsigned long*)exmem_end)
        {
            if (p[0] != 0xDEADBEEF)
            {
                l = p;
                if (f == 0) f = p;
                cnt++;
            }
            p++;
        }
        if (cnt != 0)
        {
            sprintf(buf, "s:%8x e:%8x", exmem_start, exmem_end);
            draw_txt_string(2, 12, buf, conf.osd_color);
            sprintf(buf, "f:%8x l:%8x c:%d", f, l, cnt);
        }
        else
        {
            sprintf(buf, "OK 0x%x", exmem_start);
        }
        draw_txt_string(2, 13, buf, conf.osd_color);
        // end of check	
    }
#endif

    // DEBUG: "Show misc. values"
    // change ROW to fit values on screen in draw_txt_string(COLUMN, ROW, ...)
    // uncomment gui_draw_debug_vals_osd() below if you want debug values always on top
    if (conf.debug_misc_vals_show) {
        // show value of Memory Address selected with Memory Browser
        sprintf(buf, "MEM: %#8x", (void*) (*(int*)conf.mem_view_addr_init));    // show value in Hexadecimal integer
        //sprintf(buf, "MEM: %8u", (void*) (*(int*)conf.mem_view_addr_init));    // show value in Decimal integer
        draw_txt_string(28,  9, buf, conf.osd_color);

        // show Autofocus status (if AF is working)
        extern volatile long focus_busy;
        sprintf(buf, "FB:  %8u", focus_busy);
        draw_txt_string(28, 10, buf, conf.osd_color);

        // show Zoom status (if Lens is moving)
        extern volatile long zoom_busy;
        sprintf(buf, "ZB:  %8u", zoom_busy);
        draw_txt_string(28, 11, buf, conf.osd_color);

        // show USB-Power status to debug remote / sync
        sprintf(buf, "USB: %8u", get_usb_power(1));
        draw_txt_string(28, 12, buf, conf.osd_color);

        /*
        // some cameras missing zoom_status
        sprintf(buf, "ZS:  %#8x", zoom_status);
        draw_txt_string(28, 13, buf, conf.osd_color);
        */

        /*
        sprintf(buf, "VP:  %#8x", vid_get_viewport_fb_d());
        draw_txt_string(28, 14, buf, conf.osd_color);
        */

        /*
        // debug keymap, KEYS_MASKx, SD_READONLY_FLAG, USB_MASK
        extern long physw_status[3];
        sprintf(buf, "PS1: %#8x", physw_status[0]);
        draw_txt_string(28, 10, buf, conf.osd_color);

        sprintf(buf, "PS2: %#8x", physw_status[1]);
        draw_txt_string(28, 11, buf, conf.osd_color);

        sprintf(buf, "PS3: %#8x", physw_status[2]);
        draw_txt_string(28, 12, buf, conf.osd_color);
        */

        /*
        long v=get_file_counter();
        sprintf(buf, "1:%03d-%04d", (v>>18)&0x3FF, (v>>4)&0x3FFF);
        sprintf(buf, "1:%d, %08X", xxxx, eeee);
        */
    }
    {
        int r,i, p, len;
        if (conf.debug_display == DEBUG_DISPLAY_PROPS){

            for (i=0;i<10;i++){
                r = 0;
                p = conf.debug_propcase_page*10+i;
                get_property_case(p, &r, 4);
                sprintf(buf, "%3d: %d              ", p, r);
                buf[20]=0;
                draw_string(64,16+16*i,buf, conf.osd_color);
            }
        }

        if (conf.debug_display == DEBUG_DISPLAY_PARAMS){
            extern long* FlashParamsTable[]; 
            char s[30];
            int count;

            for (i=0;i<10;i++){
                r = 0;
                p = conf.debug_propcase_page*10+i;
                if (p>=get_flash_params_count()) {
                    sprintf(buf, "%3d: This parameter does not exists", p);
                } else  {
                    len=FlashParamsTable[p][1]>>16;
                    if ((len==1)||(len==2)||(len==4)){
                        get_parameter_data(p, &r, len); 
                        sprintf(buf, "%3d: %30d :%2d ", p, r,len);
                    }
                    else {
                        if (len>=sizeof(s)) count=sizeof(s)-1; else count=len;
                        get_parameter_data(p, &s, count);
                        s[count]=0;
                        sprintf(buf, "%3d: %30s :%2d ", p, s,len);
                    }
                }
                draw_string(16,16+16*i,buf, conf.osd_color);
            }
        }
    }

    if(conf.debug_display == DEBUG_DISPLAY_TASKS) {
            gui_debug_draw_tasklist();
    }
#endif
}

//-------------------------------------------------------------------
// int osd_visible( uint playmode )         // playmode = m&MODE_MASK from gui_draw_osd()
//                                          // hide_osd =  0=Don't, 1=In Playback, 2=On Disp Press, 3=Both
//-------------------------------------------------------------------
int osd_visible(unsigned int playmode)
{
    if ( conf.hide_osd == 0 ) return(1) ;

    if( !kbd_is_key_pressed(KEY_SHOOT_HALF))
    {
        if (playmode == MODE_REC)
        {
            if ( conf.hide_osd < 2 ) return( 1 ) ;

#if defined(PARAM_DISPLAY_MODE1) && defined(PARAM_DISPLAY_MODE2)

            short disp_key_mode ;
            if (recreview_hold==0)
            {
                if ( shooting_get_prop(PROPCASE_DISPLAY_MODE) == 0) return( 1 );			
            }
            else
            {
            if (conf.show_osd_in_review )
                {
                    get_parameter_data(PARAM_DISPLAY_MODE2, &disp_key_mode, 2);		
                    if (disp_key_mode == 0 ) return( 1 ) ;
                }
            }
        }
        else
        {
            if (conf.hide_osd == 2 ) 
            {
                short disp_key_mode ;

                get_parameter_data(PARAM_DISPLAY_MODE1, &disp_key_mode, 2);
                if (disp_key_mode == 1 ) return( 1 ) ;
            }
        }
    }
#else
            if ( shooting_get_prop(PROPCASE_DISPLAY_MODE) == 0) return( 1 );
        }
    }
#endif

    return( 0 ) ;

}

//-------------------------------------------------------------------
// void gui_draw_osd()
//-------------------------------------------------------------------
void gui_draw_osd() {
    unsigned int m, mode_photo, mode_video;
#if CAM_SWIVEL_SCREEN
    static int flashlight = 0;
#endif
    static int pressed = 0;
    static int half_disp_press_old=0;
    int half_disp_press;
    int need_restore = 0;
    m = mode_get();

// DEBUG: uncomment if you want debug values always on top
//gui_draw_debug_vals_osd();

#if CAM_SWIVEL_SCREEN
    if (conf.flashlight && (m&MODE_SCREEN_OPENED) && (m&MODE_SCREEN_ROTATED) && (gui_mode==GUI_MODE_NONE /* || gui_mode==GUI_MODE_ALT */)) {
        draw_filled_rect(0, 0, screen_width-1, screen_height-1, MAKE_COLOR(COLOR_WHITE, COLOR_WHITE));
        flashlight = 1;
    }
    if (flashlight) {
        if ((!((m&MODE_SCREEN_OPENED) && (m&MODE_SCREEN_ROTATED))) || (gui_mode!=GUI_MODE_NONE /* && gui_mode!=GUI_MODE_ALT */)) {
            flashlight = 0;
            need_restore = 1;
        } else {
            return;
        }
    }
#endif
    
    if (kbd_is_key_pressed(KEY_SHOOT_HALF)) {
        if (kbd_is_key_pressed(SHORTCUT_TOGGLE_ZEBRA)) {
            if (!pressed) {
                conf.zebra_draw = !conf.zebra_draw;
                if (!conf.zebra_draw) {
                    need_restore = 1;
                }
                pressed = 1;
            }
        } else if (kbd_is_key_pressed(SHORTCUT_TOGGLE_HISTO)) {
            if (!pressed) {
                if (++conf.show_histo>SHOW_HALF) conf.show_histo=0;
                if (!conf.show_histo) {
                    need_restore = 1;
                }
                pressed = 1;
            }
        } else if (kbd_is_key_pressed(SHORTCUT_TOGGLE_OSD)) {
            if (!pressed) {
                conf.show_osd = !conf.show_osd;
                if (!conf.show_osd) {
                    need_restore = 1;
                }
                pressed = 1;
            }
        } else if (kbd_is_key_pressed(SHORTCUT_DISABLE_OVERRIDES)) {
             if (!pressed) {
                 if (conf.override_disable < 2) conf.override_disable = !conf.override_disable;
                 if (!conf.show_osd) {
                    need_restore = 1;
                 }
                 pressed = 1;
             }
        }
#if !CAM_HAS_MANUAL_FOCUS && CAM_HAS_ZOOM_LEVER && CAM_CAN_SD_OVERRIDE
        // Todo, check for AF and if its running, don't override
                else if (kbd_is_key_pressed(SHORTCUT_SD_SUB)) {
            if (!pressed) {
                            if (!(conf.override_disable==1) && shooting_can_focus() && shooting_get_common_focus_mode()) {
                                gui_subj_dist_override_value_enum(-1,0);
                                shooting_set_focus(shooting_get_subject_distance_override_value(),SET_NOW);
                //pressed = 1;
                            }
            }
        } else if (kbd_is_key_pressed(SHORTCUT_SD_ADD)) {
            if (!pressed) {
                            if (!(conf.override_disable==1) && shooting_can_focus() && shooting_get_common_focus_mode()) {
                                gui_subj_dist_override_value_enum(1,0);
                                shooting_set_focus(shooting_get_subject_distance_override_value(),SET_NOW);
                //pressed = 1;
                            }
            }
        }
#endif
                else {
            pressed = 0;
        }
    } else {
        pressed = 0;
    }
    
    // TODO some of the ifs below should probably use this
    mode_video = MODE_IS_VIDEO(m);

    mode_photo = (m&MODE_MASK) == MODE_PLAY || 
                !( mode_video ||
                (m&MODE_SHOOTING_MASK)==MODE_STITCH);

    half_disp_press=mode_photo && kbd_is_key_pressed(KEY_SHOOT_HALF) && kbd_is_key_pressed(KEY_DISPLAY);
    if (half_disp_press && ! half_disp_press_old) 
        need_restore = 1;
    half_disp_press_old=half_disp_press;

    if (need_restore)
        draw_restore();

    if (half_disp_press) 
        return;

    if (gui_osd_draw_zebra(conf.zebra_draw && gui_mode==GUI_MODE_NONE &&
                            kbd_is_key_pressed(KEY_SHOOT_HALF) && mode_photo &&
                            !state_kbd_script_run)) {// no zebra when script running, to save mem
        return; // if zebra drawn, we're done
    }
#if !CAM_SHOW_OSD_IN_SHOOT_MENU
      if (!(conf.show_osd && (canon_menu_active==(int)&canon_menu_active-4) && (canon_shoot_menu_active==0)))  return;    
#else
      if (!(conf.show_osd && (canon_menu_active==(int)&canon_menu_active-4) /*&& (canon_shoot_menu_active==0)*/ ))  return;
#endif  

    
    if ((gui_mode==GUI_MODE_NONE || gui_mode==GUI_MODE_ALT) && (
     (kbd_is_key_pressed(KEY_SHOOT_HALF) && ((conf.show_histo==SHOW_HALF)/* || (m&MODE_MASK) == MODE_PLAY*/)) || 
     ((conf.show_histo==SHOW_ALWAYS)  &&  /* !((m&MODE_MASK) == MODE_PLAY) && */ (recreview_hold==0))
    ) && 
    (mode_photo || (m&MODE_SHOOTING_MASK)==MODE_STITCH)) {
        gui_osd_draw_histo();
    }

    if ((m&MODE_MASK) == MODE_REC && (recreview_hold==0 || conf.show_osd_in_review) ) {
        if (conf.show_grid_lines) {
            gui_grid_draw_osd(1);
        }
        if ((gui_mode==GUI_MODE_NONE || gui_mode==GUI_MODE_ALT) && (((kbd_is_key_pressed(KEY_SHOOT_HALF) || (state_kbd_script_run) || (shooting_get_common_focus_mode())) && (mode_photo || (m&MODE_SHOOTING_MASK)==MODE_STITCH )) || ((mode_video || movie_status > 1) && conf.show_values_in_video) )) {
 
           if (conf.show_dof!=DOF_DONT_SHOW) gui_osd_calc_dof();
           
           if ((conf.show_dof==DOF_SHOW_IN_DOF) || (conf.show_dof==DOF_SHOW_IN_DOF_EX)) gui_osd_draw_dof();  
           
           if (conf.values_show_real_iso || conf.values_show_market_iso || conf.values_show_ev_seted || conf.values_show_ev_measured || conf.values_show_bv_measured || conf.values_show_bv_seted || conf.values_show_overexposure || conf.values_show_canon_overexposure || conf.values_show_luminance) gui_osd_calc_expo_param();           	           
        }
        if (conf.show_state) gui_osd_draw_state();
        if (conf.save_raw && conf.show_raw_state && !mode_video && (!kbd_is_key_pressed(KEY_SHOOT_HALF))) gui_osd_draw_raw_info();
        
        if ((conf.show_values==SHOW_ALWAYS && mode_photo) || ((mode_video || movie_status > 1)&& conf.show_values_in_video) || ((kbd_is_key_pressed(KEY_SHOOT_HALF) || (recreview_hold==1)) && (conf.show_values==SHOW_HALF)))
            gui_osd_draw_values(1);
        else if  (shooting_get_common_focus_mode() && mode_photo && conf.show_values && !((conf.show_dof==DOF_SHOW_IN_DOF) || (conf.show_dof==DOF_SHOW_IN_DOF_EX)))   
           gui_osd_draw_values(2);
        else if  (conf.show_values==SHOW_HALF)
            gui_osd_draw_values(0);   
    }

    if ( osd_visible(m&MODE_MASK) )  
    {
        gui_batt_draw_osd();
        gui_space_draw_osd();
        gui_usb_draw_osd();
        if(conf.show_temp>0) gui_osd_draw_temp();
#ifdef CAM_HAS_GPS
	if (((int)conf.gps_on_off ==1) && (exit_gps_data==1))
		{
			_CreateTask("GPSDATA", 0x19, 0x400, gps_get_data, 0);
			exit_gps_data=0;
		}
#endif
        if (conf.fast_ev && !mode_video && (m&MODE_MASK) == MODE_REC ) gui_osd_draw_ev();
    }

    if ( conf.show_clock )
    {
        if ( osd_visible(m&MODE_MASK) || ( kbd_is_key_pressed(KEY_SHOOT_HALF) && conf.clock_halfpress==0) ) gui_osd_draw_clock(0,0,0);
        else if ( kbd_is_key_pressed(KEY_SHOOT_HALF) && conf.clock_halfpress==1 ) gui_osd_draw_seconds();
    }

    if ( conf.show_movie_time > 0 && (mode_video || movie_status > 1)) gui_osd_draw_movie_time_left();
 
#if CAM_DRAW_EXPOSITION
    if (gui_mode==GUI_MODE_NONE && kbd_is_key_pressed(KEY_SHOOT_HALF) && ((m&MODE_MASK)==MODE_REC) && ((m&MODE_SHOOTING_MASK))!=MODE_VIDEO_STD && (m&MODE_SHOOTING_MASK)!=MODE_VIDEO_COMPACT) {
     strcpy(buf,shooting_get_tv_str());
     strcat(buf,"\"  F");
     strcat(buf,shooting_get_av_str());
     draw_txt_string(22-strlen(buf)/2, 14, buf, conf.osd_color);
    }
#endif

#if CAM_EV_IN_VIDEO
    if (movie_status==VIDEO_RECORD_IN_PROGRESS) gui_osd_draw_ev_video(get_ev_video_avail());
#endif

    gui_draw_debug_vals_osd();

#ifdef OPT_UBASIC
    if (ubasic_error){
    const char *msg;
        if (ubasic_error >= UBASIC_E_ENDMARK) {
            msg = ubasic_errstrings[UBASIC_E_UNKNOWN_ERROR];
        } else {
        msg = ubasic_errstrings[ubasic_error];
    }
    sprintf(buf, "uBASIC:%d %s ", ubasic_linenumber(), msg);
    draw_txt_string(0, 0, buf, MAKE_COLOR(COLOR_RED, COLOR_YELLOW));
    }
#endif
}

#ifndef OPTIONS_AUTOSAVE
//-------------------------------------------------------------------
void gui_menuproc_save(int arg)
{
    conf_save();
}
#endif

//-------------------------------------------------------------------
static void gui_menuproc_reset_selected(unsigned int btn) {
    if (btn==MBOX_BTN_YES)
        conf_load_defaults();
}

void gui_menuproc_reset(int arg)
{
    gui_mbox_init(LANG_MSG_RESET_OPTIONS_TITLE, 
                  LANG_MSG_RESET_OPTIONS_TEXT,
                  MBOX_FUNC_RESTORE|MBOX_TEXT_CENTER|MBOX_BTN_YES_NO|MBOX_DEF_BTN2, gui_menuproc_reset_selected);
}

//-------------------------------------------------------------------
void gui_draw_palette(int arg) {
    draw_restore();
    gui_palette_init(PALETTE_MODE_DEFAULT, 0x00, NULL);
    gui_set_mode(GUI_MODE_PALETTE);
}

//-------------------------------------------------------------------
void gui_show_build_info(int arg) {
    static char comp[64];

#ifdef __GNUC__
# ifndef __GNUC_PATCHLEVEL__
# define __GNUC_PATCHLEVEL 0
# endif
    sprintf(comp, "GCC %d.%d.%d", __GNUC__ ,__GNUC_MINOR__,__GNUC_PATCHLEVEL__ );
#else
    sprintf(comp, "UNKNOWN" );
#endif
    sprintf(buf, lang_str(LANG_MSG_BUILD_INFO_TEXT), HDK_VERSION, BUILD_NUMBER, BUILD_SVNREV, __DATE__, __TIME__, PLATFORM, PLATFORMSUB, comp);
    gui_mbox_init(LANG_MSG_BUILD_INFO_TITLE, (int)buf, MBOX_FUNC_RESTORE|MBOX_TEXT_LEFT, NULL);
}

//-------------------------------------------------------------------
void gui_show_memory_info(int arg) {
    sprintf(buf, lang_str(LANG_MSG_MEMORY_INFO_TEXT), core_get_free_memory(), MEMISOSIZE, &_start, &_end);
    gui_mbox_init(LANG_MSG_MEMORY_INFO_TITLE, (int)buf, MBOX_FUNC_RESTORE|MBOX_TEXT_CENTER, NULL);
}

//-------------------------------------------------------------------
#ifdef OPT_GAME_REVERSI
void gui_draw_reversi(int arg) {
    if ((mode_get()&MODE_MASK) != MODE_PLAY) {
        gui_mbox_init(LANG_MSG_INFO_TITLE, LANG_MSG_SWITCH_TO_PLAY_MODE,
                      MBOX_FUNC_RESTORE|MBOX_TEXT_CENTER, NULL);
        return;
    }

    gui_set_mode(GUI_MODE_REVERSI);
    gui_reversi_init();
}
#endif

//-------------------------------------------------------------------
#ifdef OPT_GAME_SOKOBAN
void gui_draw_sokoban(int arg) {
    if ((mode_get()&MODE_MASK) != MODE_PLAY) {
        gui_mbox_init(LANG_MSG_INFO_TITLE, LANG_MSG_SWITCH_TO_PLAY_MODE,
                      MBOX_FUNC_RESTORE|MBOX_TEXT_CENTER, NULL);
        return;
    }
    if ( gui_sokoban_init() )
        gui_set_mode(GUI_MODE_SOKOBAN);
}
#endif
//-------------------------------------------------------------------
#ifdef OPT_GAME_CONNECT4
void gui_draw_4wins(int arg) {
    if ((mode_get()&MODE_MASK) != MODE_PLAY) {
        gui_mbox_init(LANG_MSG_INFO_TITLE, LANG_MSG_SWITCH_TO_PLAY_MODE,
                      MBOX_FUNC_RESTORE|MBOX_TEXT_CENTER, NULL);
        return;
    }
    if ( gui_4wins_init() )
        gui_set_mode(GUI_MODE_4WINS);
}
#endif
//-------------------------------------------------------------------
#ifdef OPT_GAME_MASTERMIND
void gui_draw_mastermind(int arg) {
    if ((mode_get()&MODE_MASK) != MODE_PLAY) {
        gui_mbox_init(LANG_MSG_INFO_TITLE, LANG_MSG_SWITCH_TO_PLAY_MODE,
                      MBOX_FUNC_RESTORE|MBOX_TEXT_CENTER, NULL);
        return;
    }
    if ( gui_mastermind_init() )
        gui_set_mode(GUI_MODE_MASTERMIND);
}
#endif
//------------------------------------------------------------------- 
#ifdef OPT_GAME_TETRIS
void gui_draw_tetris(int arg) {
    if ((mode_get()&MODE_MASK) != MODE_PLAY) {
        gui_mbox_init(LANG_MSG_INFO_TITLE, LANG_MSG_SWITCH_TO_PLAY_MODE,
                      MBOX_FUNC_RESTORE|MBOX_TEXT_CENTER, NULL);
        return;
    }
    gui_set_mode (GUI_MODE_TETRIS);
    gui_tetris_init();
}
#endif
//-------------------------------------------------------------------
#ifdef OPT_DEBUGGING
void gui_draw_debug(int arg) {
//    gui_debug_init(0x2510);
//    gui_debug_init(0x127E0);
//    gui_debug_init(0x7F5B8);
//    gui_debug_init(malloc(16));
    gui_debug_init((void*)conf.mem_view_addr_init);
}

//-------------------------------------------------------------------
void gui_draw_bench(int arg) {
    gui_set_mode(GUI_MODE_BENCH);
    gui_bench_init();
}
#endif
//-------------------------------------------------------------------

#if defined(VER_CHDK)
#define LOGO_WIDTH  149
#define LOGO_HEIGHT 84
#else
#define LOGO_WIDTH  169
#define LOGO_HEIGHT 74
#endif

void gui_draw_splash(char* logo, int logo_size) {
    coord w, h, x, y;
    static const char *text[] = {
        "CHDK Version '" HDK_VERSION " " BUILD_NUMBER "-" BUILD_SVNREV "'" , 
        "Build: " __DATE__ " " __TIME__ ,
        "Camera: " PLATFORM " - " PLATFORMSUB };
    int i, l;
    color cl = MAKE_COLOR(COLOR_RED, COLOR_WHITE);

    gui_splash_mode = (mode_get()&MODE_MASK);
    
    h=sizeof(text)/sizeof(text[0])*FONT_HEIGHT+8;
    w=0;
    for (i=0; i<sizeof(text)/sizeof(text[0]); ++i) {
        l=strlen(text[i]);
        if (l>w) w=l;
    }
    w=w*FONT_WIDTH+10;

    x = (screen_width-w)>>1; y = ((screen_height-h)>>1) + 20;
    draw_filled_round_rect(x, y, x+w, y+h, MAKE_COLOR(COLOR_RED, COLOR_RED));
    for (i=0; i<sizeof(text)/sizeof(text[0]); ++i) {
        draw_string(x+((w-strlen(text[i])*FONT_WIDTH)>>1), y+i*FONT_HEIGHT+4, text[i], cl);
    }
    if(logo){
      int pos;
      int mx=0;
      int my=0;
      int offset_x = (screen_width-LOGO_WIDTH)>>1;
      int offset_y = ((screen_height-LOGO_HEIGHT)>>1) - 42;
      const color color_lookup[8] = {COLOR_BLACK,
                                    COLOR_SPLASH_RED/*0x2E redish*/,
                                    COLOR_RED,
                                    COLOR_GREY /*0x3D*/,
                                    COLOR_SPLASH_GREY /*0x1F*/,
                                    COLOR_SPLASH_PINK /*0x21 pinkish*/,
                                    COLOR_TRANSPARENT /*0x00*/,
                                    COLOR_WHITE /*0x11*/};
      for(pos=0; pos<logo_size; pos++){
          char data = logo[pos];
          color c = color_lookup[(data>>5) & 0x07];
          for(i=0; i<(data&0x1F)+1; i++){
              if (c!=0x00){
                  draw_pixel(offset_x+mx,offset_y+my,c);
              }
              if (mx==LOGO_WIDTH){
                  mx=0;
                  my++;
              }else{
                  mx++;
              }     
          }
      }
    }
}

//-------------------------------------------------------------------
void gui_draw_fselect(int arg) {
    gui_fselect_init(LANG_STR_FILE_BROWSER, "A", "A", NULL);
}

//-------------------------------------------------------------------
static void gui_grid_lines_load_selected(const char *fn) {
    if (fn)
        grid_lines_load(fn);
}
void gui_grid_lines_load(int arg) {
    gui_fselect_init(LANG_STR_SELECT_GRID_FILE, conf.grid_lines_file, "A/CHDK/GRIDS", gui_grid_lines_load_selected);
}

//-------------------------------------------------------------------
void gui_draw_osd_le(int arg) {
    gui_set_mode(GUI_MODE_OSD);
    gui_osd_init();
}

//-------------------------------------------------------------------
#ifdef OPT_TEXTREADER
static void gui_draw_read_selected(const char *fn) {
    if (fn) {
        if (!rbf_load(conf.reader_rbf_file))
            rbf_load_from_8x16(current_font);
        rbf_set_codepage(conf.reader_codepage);
        gui_set_mode(GUI_MODE_READ);
        gui_read_init(fn);
    }
}

void gui_draw_read(int arg) {
    gui_fselect_init(LANG_STR_SELECT_TEXT_FILE, conf.reader_file, "A/CHDK/BOOKS", gui_draw_read_selected);
    void gui_fselect_set_key_redraw(int n);
    gui_fselect_set_key_redraw(1);
}

void gui_draw_read_last(int arg) {
    struct stat st;
    if (stat(conf.reader_file,&st) == 0) {
        gui_draw_read_selected(conf.reader_file);
    } else {
        gui_draw_read(arg);
    }
}
#endif

//-------------------------------------------------------------------
void gui_menuproc_mkbootdisk(int arg) {
    mark_filesystem_bootable();
    gui_mbox_init(LANG_INFORMATION, LANG_CONSOLE_TEXT_FINISHED, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
}

#ifdef OPT_EDGEOVERLAY
    static void gui_load_edge_selected( const char* fn ) {
        if( fn )
        load_edge_overlay(fn);
    }

    void gui_menuproc_edge_save(int arg) {
        save_edge_overlay();
    }

    void gui_menuproc_edge_load(int arg) {
        gui_fselect_init(LANG_MENU_EDGE_LOAD, EDGE_SAVE_DIR, EDGE_SAVE_DIR, gui_load_edge_selected);
    }
#endif

//-------------------------------------------------------------------
#ifdef OPT_CALENDAR
    void gui_draw_calendar(int arg) {
        gui_set_mode(GUI_MODE_CALENDAR);
        gui_calendar_init();
    }
#endif
//-------------------------------------------------------------------
#ifdef OPT_TEXTREADER
static void gui_draw_rbf_selected(const char *fn) {
    if (fn) {
        strcpy(conf.reader_rbf_file, fn);
    }
}
    void gui_draw_load_rbf(int arg) {
        gui_fselect_init(LANG_STR_SELECT_FONT_FILE, conf.reader_rbf_file, "A/CHDK/FONTS", gui_draw_rbf_selected);
    }
#endif
//-------------------------------------------------------------------
static void gui_draw_menu_rbf_selected(const char *fn) {
    if (fn) {
        strcpy(conf.menu_rbf_file, fn);
        if (!rbf_load(conf.menu_rbf_file))
            rbf_load_from_8x16(current_font);
        rbf_set_codepage(FONT_CP_WIN);
        gui_menu_init(NULL);
    }
}
void gui_draw_load_menu_rbf(int arg) {
    gui_fselect_init(LANG_STR_SELECT_FONT_FILE, conf.menu_rbf_file, "A/CHDK/FONTS", gui_draw_menu_rbf_selected);
}

//-------------------------------------------------------------------
static void gui_draw_symbol_rbf_selected(const char *fn) {
    if (fn) {
        strcpy(conf.menu_symbol_rbf_file, fn);
        if(!rbf_load_symbol(conf.menu_symbol_rbf_file)) conf.menu_symbol_enable=0;		//AKA
        gui_menu_init(NULL);
    }
}
void gui_draw_load_symbol_rbf(int arg) {
    gui_fselect_init(LANG_STR_SELECT_SYMBOL_FILE, conf.menu_symbol_rbf_file, "A/CHDK/SYMBOLS", gui_draw_symbol_rbf_selected);
}

//-------------------------------------------------------------------
static void gui_draw_lang_selected(const char *fn) {
    if (fn) {
        strcpy(conf.lang_file, fn);
        lang_load_from_file(conf.lang_file);
        gui_menu_init(NULL);
    }
}
void gui_draw_load_lang(int arg) {
    gui_fselect_init(LANG_STR_SELECT_LANG_FILE, conf.lang_file, "A/CHDK/LANG", gui_draw_lang_selected);
}

int find_mnu(CMenu *curr_menu, int mnu, int count) 
{
    int gui_menu_curr_item;

    gui_menu_curr_item = 0;
    while(curr_menu->menu[gui_menu_curr_item].text) {
        if (curr_menu->menu[gui_menu_curr_item].text == mnu){
            user_submenu_items[count] = curr_menu->menu[gui_menu_curr_item];
            return 1;
        }
        if ((curr_menu->menu[gui_menu_curr_item].type & MENUITEM_MASK) == MENUITEM_SUBMENU) 
            if (curr_menu->menu[gui_menu_curr_item].text != LANG_MENU_USER_MENU)
                if (find_mnu((CMenu*)(curr_menu->menu[gui_menu_curr_item].value), mnu, count)) return 1;
        gui_menu_curr_item++;
    }
    return 0;
}

void user_menu_save() {
    int x;
    for (x=0; x<USER_MENU_ITEMS; x++) {
        /*
        * First entry in user_submenu_items is reserved for the "Main Menu"
        * conf.user_menu_vars only traks/saves the real user entries.
        */
        conf.user_menu_vars[x] = user_submenu_items[x+1].text;
    }
}
 
void user_menu_restore() {
     int x;
    for (x=0; x<USER_MENU_ITEMS; x++) {
        /*
        * First entry in user_submenu_items is reserved for the "Main Menu"
        * conf.user_menu_vars only traks/saves the real user entries.
        */
        find_mnu(&root_menu, conf.user_menu_vars[x], x+1);
    }
}

#ifdef OPT_DEBUGGING

    void gui_compare_props(int arg)
    {
        #define NUM_PROPS 512
        // never freed, but not allocated unless prop compare is used once
        static int *props = NULL;
        int i;
        int p;
        int c;

        if( props )
        { // we have previous data set! do a comparison
            c = 0;
            for( i = 0; i < NUM_PROPS; ++i )
            {
                p = shooting_get_prop(i);
                if( props[i] != p )
                {
                    ++c;
                    sprintf(buf,"%4d is %8d was %8d",i,p,props[i]);
                    draw_string(16,16*c,buf,MAKE_COLOR(COLOR_BLACK,COLOR_YELLOW));
                }
                props[i] = p;
                if( c == 12 )
                {
                    ++c;
                    sprintf(buf,"%s","Waiting 15 Seconds");
                    draw_string(16,16*c,buf,MAKE_COLOR(COLOR_BLACK,COLOR_YELLOW));
                    msleep(15000);
                    c = 0;
                }
            }
            ++c;
            sprintf(buf,"%s","Press <ALT> to leave");
            draw_string(16,16*c,buf,MAKE_COLOR(COLOR_BLACK,COLOR_YELLOW));
        }
        else
        {
        // no previous data was set so we save the data initially
            props = (int *)malloc(NUM_PROPS*sizeof(int));
            if(props) {
                for( i = 0; i < NUM_PROPS; ++i )
                {
                    props[i] = shooting_get_prop(i);
                }
            }
        }
    }

    // Save camera romlog to A/ROMLOG.LOG file
    void save_romlog(int arg)
    {
        extern unsigned _ExecuteEventProcedure(const char *name,...);

        struct stat st;
        if (stat("A/ROMLOG.LOG",&st)    == 0) remove("A/ROMLOG.LOG");
        if (stat("A/RomLogErr.txt",&st) == 0) remove("A/RomLogErr.txt");

        unsigned args[3];
        args[0] = (unsigned)"SystemEventInit";
        if (call_func_ptr(_ExecuteEventProcedure,args,1) == -1)
        {
            args[0] = (unsigned)"System.Create";
            if (call_func_ptr(_ExecuteEventProcedure,args,1) == -1)
            {
                gui_mbox_init(LANG_ERROR, LANG_SAVE_ROMLOG_INIT_ERROR, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
                return;
            }
        }

        args[0] = (unsigned)"GetLogToFile";
        args[1] = (unsigned)"A/ROMLOG.LOG";
        args[2] = 1;
        if (call_func_ptr(_ExecuteEventProcedure,args,3) == -1)
        {
            gui_mbox_init(LANG_ERROR, LANG_SAVE_ROMLOG_FAIL, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
        }
        else
        {
            gui_mbox_init(LANG_INFORMATION, LANG_SAVE_ROMLOG_OK, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
        }
    }

#endif
