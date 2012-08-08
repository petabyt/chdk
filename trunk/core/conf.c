#include "platform.h"
#include "keyboard.h"
#include "conf.h"
#include "histogram.h"
#include "font.h"
#include "camera.h"
#include "raw.h"
#include "modules.h"
#include "module_load.h"
#include "gui_draw.h"
#include "gui_osd.h"
#include "gui_grid.h"
#include "gui_lang.h"
#include "gui_menu.h"
#include "gui_user_menu.h"
#include "core.h"
#include "stdlib.h"
#include "script.h"


//-------------------------------------------------------------------
#define CONF_FILE  "A/CHDK/CCHDK2.CFG"
#define CONF_MAGICK_VALUE   (0x33204741)

//-------------------------------------------------------------------
Conf conf = { MAKE_API_VERSION(2,1) };

int state_shooting_progress = SHOOTING_PROGRESS_NONE;
int state_save_raw_nth_only;
int auto_started;

// reyalp: putting these in conf, since the conf values are lookups for them
// prefixes and extentions available for raw images (index with conf.raw_prefix etc)
const char* img_prefixes[NUM_IMG_PREFIXES]={ "IMG_", "CRW_", "SND_" /*, "AUT_", "ETC_","SDR_", "MVI_", "MRK_"*/};
const char* img_exts[NUM_IMG_EXTS]={ ".JPG", ".CRW", ".CR2", ".THM", ".WAV"/*, ".AVI", ".MRK"*/};

//-------------------------------------------------------------------
static int def_batt_volts_max, def_batt_volts_min;

static void conf_change_script_file();
static void conf_change_font_cp();
static void conf_change_menu_rbf_file();
static void conf_change_menu_symbol_rbf_file();
static void conf_change_alt_mode_button();
static void conf_change_video_bitrate();
static void conf_change_dng_ext();
static void conf_change_autoiso();
extern void cb_autoiso_menu_change(unsigned int item);

void camera_set_raw(int mode)
{
    conf.save_raw = mode;
}

void camera_set_nr(int mode)
{
    // "Auto", "Off", "On"
    conf.raw_nr = mode;
}
int camera_get_script_autostart()
{   
    // 1 = Autostarted
    return auto_started;
}


void camera_set_script_autostart(int state)
{   
    // 1 = Autostarted
    auto_started = state;
}


int camera_get_nr()
{
    // "Auto", "Off", "On"
    return conf.raw_nr;
}


void clear_values()
{	
    if (conf.platformid != PLATFORMID) // the following config entries will be resetted if you switch the camera using the same cfg
    {
    conf.raw_cache = 0;
#if ZOOM_OVERRIDE
    conf.zoom_override_value = 0;
#endif
    conf.fast_ev = 0;
    conf.fast_movie_control = 0;
    conf.fast_movie_quality_control = 0;
    conf.zoom_scale = 100;
    conf.platformid = PLATFORMID;
    conf.flash_video_override = 0;
    }

    if (conf.clear_override)
    {
		value_turn_state( &conf.tv_override_value, -1 );
		value_turn_state( &conf.av_override_value, -1 );
		value_turn_state( &conf.subj_dist_override_value, -1 );
		value_turn_state( &conf.iso_override_value, -1 );
        conf.nd_filter_state=0;
    }
#if ZOOM_OVERRIDE
    if (conf.clear_zoom_override)
    {
		value_turn_state( &conf.conf.zoom_override, -1 );
    }
#endif
    if (conf.clear_bracket)
    {
        value_turn_state( &conf.av_bracket_value, -1);
        value_turn_state( &conf.tv_bracket_value, -1);
        value_turn_state( &conf.iso_bracket_value, -1);
        value_turn_state( &conf.subj_dist_bracket_value, -1);
    }
    if (conf.clear_video)
    {
        conf.video_mode = 0;
#if CAM_CHDK_HAS_EXT_VIDEO_TIME
        conf.ext_video_time=0;
#endif
        conf.video_quality = VIDEO_DEFAULT_QUALITY;
        conf.video_bitrate = VIDEO_DEFAULT_BITRATE;
        shooting_video_bitrate_change(conf.video_bitrate);
    }
    //conf.edge_overlay_pano = 0; // reset it because otherwise this feature cant be used at startup (when buffer is empty) - needs workaround other than this!
}

static const ConfInfo conf_info[] = {
/* !!! Do NOT change ID for items defined already! Append a new one at the end! !!! */
    CONF_INFO(  1, conf.show_osd,               CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO(  2, conf.save_raw,               CONF_DEF_VALUE, i:0, conf_change_dng),
    CONF_INFO(  3, conf.script_shoot_delay,     CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(  4, conf.show_histo,             CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(  5, conf.script_vars,            CONF_INT_PTR,   i:0, NULL),
    CONF_INFO(  6, conf.script_param_set,       CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(  7, conf.show_dof,               CONF_DEF_VALUE, i:DOF_DONT_SHOW, NULL),
    CONF_INFO(  8, conf.batt_volts_max,         CONF_VALUE_PTR, ptr:&def_batt_volts_max, NULL),
    CONF_INFO(  9, conf.batt_volts_min,         CONF_VALUE_PTR, ptr:&def_batt_volts_min, NULL),
    CONF_INFO( 10, conf.batt_step_25,           CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO( 11, conf.batt_perc_show,         CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO( 12, conf.batt_volts_show,        CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 13, conf.batt_icon_show,         CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO( 14, conf.show_state,             CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO( 15, conf.show_values,            CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 16, conf.show_overexp,           CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO( 17, conf.histo_mode,             CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 18, conf.histo_auto_ajust,       CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO( 19, conf.histo_ignore_boundary,  CONF_DEF_VALUE, i:4, NULL),
    CONF_INFO( 20, conf.histo_layout,           CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO2( 21, conf.histo_pos,             CONF_OSD_POS,   45,CAM_SCREEN_HEIGHT-HISTO_HEIGHT-40),
    CONF_INFO2( 22, conf.dof_pos,               CONF_OSD_POS,   90,45),
    CONF_INFO2( 23, conf.batt_icon_pos,         CONF_OSD_POS,   178,0),
    CONF_INFO2( 24, conf.batt_txt_pos,          CONF_OSD_POS,   178,FONT_HEIGHT),
    CONF_INFO2( 25, conf.mode_state_pos,        CONF_OSD_POS,   35,0),
    CONF_INFO2( 26, conf.values_pos,            CONF_OSD_POS,   CAM_SCREEN_WIDTH-9*FONT_WIDTH,30),
    CONF_INFO( 27, conf.histo_color,            CONF_DEF_VALUE, cl:MAKE_COLOR(COLOR_BG, COLOR_WHITE), NULL),
    CONF_INFO( 28, conf.osd_color,              CONF_DEF_VALUE, cl:MAKE_COLOR(COLOR_BG, COLOR_FG), NULL),
//    CONF_INFO( 29, conf.batt_icon_color,        CONF_DEF_VALUE, cl:COLOR_WHITE, NULL),
    CONF_INFO( 30, conf.menu_color,             CONF_DEF_VALUE, cl:MAKE_COLOR(COLOR_BG, COLOR_FG), NULL),
    CONF_INFO( 31, conf.reader_color,           CONF_DEF_VALUE, cl:MAKE_COLOR(COLOR_GREY, COLOR_WHITE), NULL),
    CONF_INFO( 32, conf.ricoh_ca1_mode,         CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 33, conf.flashlight,             CONF_DEF_VALUE, i:0, NULL),
    //CONF_INFO( 34, conf.ns_enable_memdump,      CONF_DEF_VALUE, i:0, NULL),                                       // ?????
    CONF_INFO( 34, conf.debug_shortcut_action,  CONF_DEF_VALUE, i:0, NULL), // backwards compatible
    CONF_INFO( 35, conf.raw_in_dir,             CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 36, conf.raw_prefix,             CONF_DEF_VALUE, i:RAW_PREFIX_CRW, NULL),
    CONF_INFO( 37, conf.raw_ext,                CONF_DEF_VALUE, i:DEFAULT_RAW_EXT, NULL),
    CONF_INFO( 38, conf.reader_file,            CONF_CHAR_PTR,   ptr:"A/CHDK/BOOKS/README.TXT", NULL),
    CONF_INFO( 39, conf.reader_pos,             CONF_DEF_VALUE, i:0, NULL),
    //CONF_INFO( 40, conf.sokoban_level,          CONF_DEF_VALUE, i:0, NULL),                                       // moved to sokoban module
    CONF_INFO( 41, conf.show_clock,             CONF_DEF_VALUE, i:2, NULL),
    CONF_INFO2( 42, conf.clock_pos,             CONF_OSD_POS,   CAM_SCREEN_WIDTH-5*FONT_WIDTH-2,0),
    CONF_INFO( 43, conf.reader_autoscroll,      CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 44, conf.reader_autoscroll_delay,CONF_DEF_VALUE, i:5, NULL),
    CONF_INFO( 45, conf.reader_rbf_file,        CONF_CHAR_PTR,   ptr:"", NULL),
    CONF_INFO( 46, conf.reader_codepage,        CONF_DEF_VALUE, i:FONT_CP_WIN, NULL),
    CONF_INFO( 47, conf.splash_show,            CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO( 48, conf.histo_color2,           CONF_DEF_VALUE, cl:MAKE_COLOR(COLOR_RED, COLOR_WHITE), NULL),
    CONF_INFO( 49, conf.zebra_draw,             CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 50, conf.zebra_mode,             CONF_DEF_VALUE, i:ZEBRA_MODE_BLINKED_2, NULL),
    CONF_INFO( 51, conf.zebra_restore_screen,   CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO( 52, conf.zebra_restore_osd,      CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO( 53, conf.zebra_over,             CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO( 54, conf.zebra_under,            CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 55, conf.zebra_color,            CONF_DEF_VALUE, cl:MAKE_COLOR(COLOR_RED, COLOR_RED), NULL),
    CONF_INFO( 56, conf.zebra_draw_osd,         CONF_DEF_VALUE, i:ZEBRA_DRAW_HISTO, NULL),
    CONF_INFO( 57, conf.user_menu_as_root,      CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 58, conf.zoom_value,             CONF_DEF_VALUE, i:ZOOM_SHOW_X, NULL),
    CONF_INFO( 59, conf.use_zoom_mf,            CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 60, conf.raw_save_first_only,    CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 61, conf.reader_wrap_by_words,   CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO( 62, conf.menu_symbol_enable,     CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO( 63, conf.alt_mode_button,        CONF_DEF_VALUE, i:KEY_PRINT, conf_change_alt_mode_button),
    CONF_INFO( 64, conf.lang_file,              CONF_CHAR_PTR,   ptr:"", NULL),
    CONF_INFO( 65, conf.font_cp,                    CONF_DEF_VALUE,     i:FONT_CP_WIN_1252, conf_change_font_cp),
    CONF_INFO( 66, conf.menu_rbf_file,          CONF_CHAR_PTR,   ptr:"", conf_change_menu_rbf_file),
    CONF_INFO( 67, conf.alt_prevent_shutdown,   CONF_DEF_VALUE, i:ALT_PREVENT_SHUTDOWN_ALT, conf_update_prevent_shutdown),
    CONF_INFO( 68, conf.show_grid_lines,        CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 69, conf.grid_lines_file,        CONF_CHAR_PTR,   ptr:"", NULL),
    CONF_INFO( 70, conf.raw_nr,                 CONF_DEF_VALUE, i:NOISE_REDUCTION_AUTO_CANON, NULL),
    CONF_INFO( 71, conf.grid_force_color,       CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 72, conf.grid_color,             CONF_DEF_VALUE, cl:MAKE_COLOR(COLOR_BG, COLOR_FG), NULL),

    CONF_INFO( 80, conf.dof_subj_dist_as_near_limit,CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO( 81, conf.dof_use_exif_subj_dist,     CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO( 82, conf.dof_subj_dist_in_misc,      CONF_DEF_VALUE,     i:1, NULL),
    CONF_INFO( 83, conf.dof_near_limit_in_misc,     CONF_DEF_VALUE,     i:1, NULL),
    CONF_INFO( 84, conf.dof_far_limit_in_misc,      CONF_DEF_VALUE,     i:1, NULL),
    CONF_INFO( 85, conf.dof_hyperfocal_in_misc,     CONF_DEF_VALUE,     i:1, NULL),
    CONF_INFO( 86, conf.dof_depth_in_misc,          CONF_DEF_VALUE,     i:0, NULL),

    CONF_INFO( 87, conf.values_show_in_review,      CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO( 88, conf.values_show_zoom,           CONF_DEF_VALUE,     i:1, NULL),
    CONF_INFO( 89, conf.values_show_real_aperture,  CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO( 90, conf.values_show_real_iso,       CONF_DEF_VALUE,     i:1, NULL),
    CONF_INFO( 91, conf.values_show_market_iso,     CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO( 92, conf.values_show_iso_only_in_autoiso_mode, CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 93, conf.values_show_ev_seted,       CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO( 94, conf.values_show_ev_measured,    CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO( 95, conf.values_show_bv_measured,    CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO( 96, conf.values_show_bv_seted,       CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO( 97, conf.values_show_overexposure,   CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO( 98, conf.values_show_luminance,      CONF_DEF_VALUE,     i:0, NULL),

    CONF_INFO( 99, conf.video_mode,                 CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(100, conf.video_quality,              CONF_DEF_VALUE,     i:VIDEO_DEFAULT_QUALITY,NULL),
    CONF_INFO(101, conf.video_bitrate,              CONF_DEF_VALUE,     i:VIDEO_DEFAULT_BITRATE, conf_change_video_bitrate),
    
    CONF_INFO(102, conf.tv_override_value,          CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(103, conf.tv_override_koef,           CONF_DEF_VALUE,     i:0, NULL), // to remove if tv_factor mode will be canceled

    CONF_INFO(104, conf.av_override_value,          CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(105, conf.iso_override_value,         CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(106, conf.iso_override_koef,          CONF_DEF_VALUE,     i:0, NULL),	// deprecated - to remove (only to import once and contain 1 then)
    
    CONF_INFO(107, conf.subj_dist_override_value,   CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(108, conf.subj_dist_override_koef,    CONF_DEF_VALUE,     i:0, NULL),	// deprecated - to remove (only to import once and contain 1 then; possible exlusion: superzooms) 
    
    CONF_INFO(109, conf.tv_bracket_value,           CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(110, conf.av_bracket_value,           CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(111, conf.iso_bracket_value,          CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(112, conf.iso_bracket_koef,           CONF_DEF_VALUE,     i:0, NULL),	// deprecated - to remove (only to import once and contain 1 then)
    CONF_INFO(113, conf.subj_dist_bracket_value,    CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(114, conf.subj_dist_bracket_koef,     CONF_DEF_VALUE,     i:0, NULL),	// deprecated - to remove (only to import once and contain 1 then; possible exlusion: superzooms)
    CONF_INFO(115, conf.bracket_type,               CONF_DEF_VALUE,     i:0, NULL),

//    CONF_INFO(116, conf.recalc_exposure,            CONF_DEF_VALUE,     i:0, NULL),
//    CONF_INFO(117, conf.tv_exposure_order,          CONF_DEF_VALUE,     i:2, NULL),
//    CONF_INFO(118, conf.av_exposure_order,          CONF_DEF_VALUE,     i:1, NULL),
//    CONF_INFO(119, conf.iso_exposure_order,         CONF_DEF_VALUE,     i:3, NULL),

    CONF_INFO(120, conf.script_startup,             CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(121, conf.remote_enable,              CONF_DEF_VALUE,     i:0, NULL),
    
    CONF_INFO(122, conf.values_show_canon_overexposure, CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(123, conf.clear_override,             CONF_DEF_VALUE,     i:1, NULL),
    
    CONF_INFO(124, conf.show_osd_in_review,         CONF_DEF_VALUE,     i:0, NULL),
    
//    CONF_INFO(125, conf.dof_dist_from_lens,         CONF_DEF_VALUE,     i:0, NULL),
    
    CONF_INFO(126, conf.clear_bracket,              CONF_DEF_VALUE,     i:1, NULL),
    CONF_INFO(127, conf.zebra_multichannel,         CONF_DEF_VALUE,     i:0, NULL),
    
    CONF_INFO(128, conf.nd_filter_state,            CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(129, conf.histo_show_ev_grid,         CONF_DEF_VALUE,     i:0, NULL),
    
    CONF_INFO(130, conf.osd_color_warn,             CONF_DEF_VALUE,     cl:MAKE_COLOR(COLOR_BG, COLOR_RED), NULL),
    CONF_INFO(131, conf.space_color,                CONF_DEF_VALUE,     cl:MAKE_COLOR(COLOR_BG, COLOR_FG), NULL),
    CONF_INFO(132, conf.space_icon_show,            CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO2(133, conf.space_icon_pos,            CONF_OSD_POS,       CAM_SCREEN_WIDTH-100,0),
    CONF_INFO(134, conf.space_perc_show,            CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(135, conf.space_mb_show,              CONF_DEF_VALUE,     i:1, NULL),
    CONF_INFO2(136, conf.space_txt_pos,             CONF_OSD_POS,       128,0),
    CONF_INFO(137, conf.show_remaining_raw,         CONF_DEF_VALUE,     i:1, NULL),
    CONF_INFO2(138, conf.mode_raw_pos,              CONF_OSD_POS,       CAM_SCREEN_WIDTH-7*FONT_WIDTH-2,CAM_SCREEN_HEIGHT-3*FONT_HEIGHT-2),
    CONF_INFO(139, conf.show_raw_state,             CONF_DEF_VALUE,     i:1, NULL),
    
    CONF_INFO(140, conf.show_values_in_video,       CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(141, conf.tv_enum_type,               CONF_DEF_VALUE,     i:1, NULL),		// to remove if tv_factor mode will be canceled

    CONF_INFO(142, conf.user_menu_enable,       CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(143, conf.user_menu_vars,         CONF_INT_PTR,   i:0, NULL),
    CONF_INFO(144, conf.zoom_scale,             CONF_DEF_VALUE, i:100, NULL), 
    CONF_INFO(145, conf.space_bar_show,         CONF_DEF_VALUE, i:1, NULL), 
    CONF_INFO(146, conf.space_bar_size,         CONF_DEF_VALUE, i:1, NULL), 
    CONF_INFO2(147, conf.space_ver_pos,         CONF_OSD_POS,   CAM_SCREEN_WIDTH-7,0),
    CONF_INFO2(148, conf.space_hor_pos,         CONF_OSD_POS,   0,CAM_SCREEN_HEIGHT-7),   
    CONF_INFO(149, conf.space_bar_width,        CONF_DEF_VALUE, i:2, NULL), 
    CONF_INFO(150, conf.space_perc_warn,        CONF_DEF_VALUE, i:10, NULL),
    CONF_INFO(151, conf.space_mb_warn,          CONF_DEF_VALUE, i:20, NULL),
    CONF_INFO(152, conf.space_warn_type,        CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(153, conf.remaining_raw_treshold, CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(154, conf.unlock_optical_zoom_for_video, CONF_DEF_VALUE, i:1, NULL), 
    CONF_INFO(155, conf.clock_format,           CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(156, conf.clock_indicator,        CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(157, conf.clock_halfpress,        CONF_DEF_VALUE, i:1, NULL),
    
    CONF_INFO(158, conf.autoiso_enable,             CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(159, conf.autoiso_shutter_enum,       CONF_DEF_VALUE,     i:5, NULL), // 5='1/125'
    CONF_INFO(160, conf.autoiso_user_factor,        CONF_DEF_VALUE,     i:5, NULL),
    CONF_INFO(161, conf.autoiso_is_factor,          CONF_DEF_VALUE,     i:2, NULL),
    CONF_INFO(162, conf.autoiso_max_iso_hi,         CONF_DEF_VALUE,     i:55, NULL),
    CONF_INFO(163, conf.autoiso_max_iso_auto,       CONF_DEF_VALUE,     i:32, NULL),
    CONF_INFO(164, conf.autoiso_min_iso,            CONF_DEF_VALUE,     i:8, NULL),

    CONF_INFO(165, conf.menu_title_color,           CONF_DEF_VALUE, cl:MAKE_COLOR(COLOR_WHITE, COLOR_BLACK), NULL),
    CONF_INFO(166, conf.menu_cursor_color,          CONF_DEF_VALUE, cl:MAKE_COLOR(COLOR_SELECTED_BG, COLOR_SELECTED_FG), NULL),
    CONF_INFO(167, conf.menu_center,                CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO(168, conf.mute_on_zoom,               CONF_DEF_VALUE, i:0, NULL), 
    CONF_INFO(169, conf.bad_pixel_removal,          CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(170, conf.video_af_key,               CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(171, conf.osd_color_override,         CONF_DEF_VALUE, cl:MAKE_COLOR(COLOR_BG, COLOR_RED), NULL),
    CONF_INFO(172, conf.override_disable,           CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(173, conf.override_disable_all,       CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO(174, conf.hide_osd,                   CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO(175, conf.save_raw_in_video,          CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO(176, conf.show_movie_time,            CONF_DEF_VALUE, i:3, NULL),
    CONF_INFO(177, conf.show_movie_refresh,         CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO2(178, conf.mode_video_pos,            CONF_OSD_POS,   CAM_SCREEN_WIDTH-25*FONT_WIDTH-2,CAM_SCREEN_HEIGHT-6*FONT_HEIGHT-2),
    CONF_INFO(179, conf.clear_video,                CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(180, conf.fast_ev,                    CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(181, conf.fast_ev_step,               CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO2(182, conf.mode_ev_pos,               CONF_OSD_POS,   CAM_SCREEN_WIDTH-40*FONT_WIDTH-2,CAM_SCREEN_HEIGHT-8*FONT_HEIGHT-2),
    CONF_INFO(183, conf.menu_symbol_rbf_file,       CONF_CHAR_PTR,   ptr:DEFAULT_SYMBOL_FILE, conf_change_menu_symbol_rbf_file),
    CONF_INFO(184, conf.menu_symbol_color,          CONF_DEF_VALUE, cl:MAKE_COLOR(COLOR_BG, COLOR_FG), NULL),
#ifdef OPT_CURVES
    CONF_INFO(185, conf.curve_file,                 CONF_CHAR_PTR,      ptr:"", NULL),
    CONF_INFO(186, conf.curve_enable,               CONF_DEF_VALUE,     i:0, NULL),
#endif
    CONF_INFO(187, conf.edge_overlay_enable,        CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(188, conf.edge_overlay_thresh,        CONF_DEF_VALUE, i:60, NULL),
    CONF_INFO(189, conf.edge_overlay_color,         CONF_DEF_VALUE, cl:0x66, NULL),
    CONF_INFO(190, conf.synch_enable,               CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(191, conf.synch_delay_enable,         CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(192, conf.synch_delay_value,          CONF_DEF_VALUE, i:100, NULL),
    //CONF_INFO(193, conf.synch_delay_coarse_value,   CONF_DEF_VALUE, i:0, NULL),                                     // obsolete - no longer used
    CONF_INFO(194, conf.script_file,                CONF_CHAR_PTR,   ptr:"", conf_change_script_file),
    CONF_INFO(195, conf.mem_view_addr_init,         CONF_DEF_VALUE, i:0x1000, NULL),
    CONF_INFO(196, conf.save_raw_in_sports,         CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(197, conf.save_raw_in_burst,          CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(198, conf.save_raw_in_ev_bracketing,  CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(199, conf.save_raw_in_timer,          CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(200, conf.raw_exceptions_warn,        CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO(201, conf.menu_select_first_entry,    CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO(202, conf.fast_movie_control,         CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(203, conf.show_temp,                  CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO2(204, conf.temp_pos,                  CONF_OSD_POS,   CAM_SCREEN_WIDTH-9*FONT_WIDTH-2,FONT_HEIGHT),
    CONF_INFO(205, conf.fast_movie_quality_control, CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO(206, conf.remote_zoom_enable,         CONF_DEF_VALUE, i:0, NULL),
//    CONF_INFO(207, conf.zoom_timeout,               CONF_DEF_VALUE, i:5, NULL),   // Not used
   	CONF_INFO(208, conf.start_sound,                CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(209, conf.sub_batch_prefix,           CONF_DEF_VALUE, i:RAW_PREFIX_SND, NULL), // SND_
    CONF_INFO(210, conf.sub_batch_ext,              CONF_DEF_VALUE, i:DEFAULT_RAW_EXT, NULL), // .CRW
//    CONF_INFO(211, conf.sub_in_dark_value,          CONF_DEF_VALUE, i:30, NULL), 
//    CONF_INFO(212, conf.sub_out_dark_value,         CONF_DEF_VALUE, i:0, NULL), 
   	CONF_INFO(213, conf.debug_display,              CONF_DEF_VALUE, i:0, NULL),
   	CONF_INFO(214, conf.script_param_save,          CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO2(215, conf.ev_video_pos,              CONF_OSD_POS,   18,80),
#if ZOOM_OVERRIDE
    CONF_INFO(216, conf.zoom_override_value,        CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(217, conf.zoom_override,              CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(218, conf.clear_zoom_override,        CONF_DEF_VALUE,     i:1, NULL),
#endif 
    CONF_INFO(219, conf.bracketing_add_raw_suffix,  CONF_DEF_VALUE, i:0, NULL),			
    CONF_INFO(220, conf.temperature_unit,           CONF_DEF_VALUE, i:0, NULL),
//    CONF_INFO(221, conf.clear_zoom_override,        CONF_DEF_VALUE, i:1, NULL),			
    CONF_INFO(222, conf.edge_overlay_play,          CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(223, conf.edge_overlay_pano,          CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(224, conf.edge_overlay_zoom,          CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO(225, conf.raw_cache,                  CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(226, conf.dng_raw,                    CONF_DEF_VALUE, i:1, conf_change_dng),
    CONF_INFO(227, conf.flash_sync_curtain,         CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(228, conf.raw_timer,                  CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(229, conf.platformid,                 CONF_DEF_VALUE, i:PLATFORMID, NULL),
    CONF_INFO(230, conf.save_raw_in_edgeoverlay,    CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(231, conf.save_raw_in_auto,           CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(232, conf.flash_video_override,       CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(233, conf.flash_video_override_power, CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(234, conf.raw_dng_ext,                CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO(235, conf.dng_usb_ext,                CONF_DEF_VALUE, i:0, conf_change_dng_ext),
    CONF_INFO(236, conf.flash_manual_override,      CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(237, conf.fast_image_quality,         CONF_DEF_VALUE, i:3, NULL),
	CONF_INFO(238, conf.debug_lua_restart_on_error, CONF_DEF_VALUE, i:0, NULL),
	CONF_INFO(239, conf.debug_propcase_page,        CONF_DEF_VALUE, i:0, NULL),
	CONF_INFO(240, conf.debug_misc_vals_show,       CONF_DEF_VALUE, i:0, NULL),
	CONF_INFO(241, conf.edge_overlay_filter,        CONF_DEF_VALUE, i:0, NULL),
	CONF_INFO(242, conf.edge_overlay_show,          CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(243, conf.edge_overlay_pano_overlap,  CONF_DEF_VALUE, i:30, NULL),

    // Touch screen U/I overrides
    CONF_INFO(244, conf.touchscreen_disable_video_controls,     CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO(245, conf.touchscreen_disable_shortcut_controls,  CONF_DEF_VALUE, i:0, NULL),

    // USB Icon enable & position
    CONF_INFO(246, conf.usb_info_enable,            CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO2(247, conf.usb_info_pos,              CONF_OSD_POS,   95,0),

	// new USB remote stuff
	CONF_INFO(248, conf.remote_switch_type,         CONF_DEF_VALUE, i:0, NULL),
	CONF_INFO(249, conf.remote_control_mode,        CONF_DEF_VALUE, i:0, NULL),

	CONF_INFO(250, conf.remote_enable_scripts,      CONF_DEF_VALUE, i:0, NULL),

    CONF_INFO(251, conf.show_partition_nr,          CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(252, conf.ext_video_time,             CONF_DEF_VALUE,     i:0, NULL),
#ifdef CAM_HAS_GPS
    // GPS
    CONF_INFO(253, conf.gps_record,                 CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(254, conf.gps_navi_show,              CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(255, conf.gps_kompass_show,           CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(256, conf.gps_coordinates_show,       CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(257, conf.gps_height_show,            CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(258, conf.gps_waypoint_save,          CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(259, conf.gps_track_time,             CONF_DEF_VALUE,     i:1, NULL),
    CONF_INFO(260, conf.gps_kompass_hide,           CONF_DEF_VALUE,     i:0, NULL),

    CONF_INFO(261, conf.gps_wait_for_signal,        CONF_DEF_VALUE,     i:300, NULL),
    CONF_INFO(262, conf.gps_kompass_time,           CONF_DEF_VALUE,     i:1, NULL),
    CONF_INFO(263, conf.gps_navi_time,              CONF_DEF_VALUE,     i:1, NULL),
    CONF_INFO(264, conf.gps_wait_for_signal_time,   CONF_DEF_VALUE,     i:5, NULL),
    CONF_INFO(265, conf.gps_kompass_smooth,         CONF_DEF_VALUE,     i:7, NULL),
    CONF_INFO(266, conf.gps_batt,                   CONF_DEF_VALUE,     i:25, NULL),
    CONF_INFO(267, conf.gps_countdown,              CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(268, conf.gps_2D_3D_fix,              CONF_DEF_VALUE,     i:2, NULL),
    CONF_INFO(269, conf.gps_countdown_blink,        CONF_DEF_VALUE,     i:1, NULL),
    
    CONF_INFO(270, conf.gps_rec_play_set,           CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(271, conf.gps_play_dark_set,          CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(272, conf.gps_rec_play_time,          CONF_DEF_VALUE,     i:30, NULL),
    CONF_INFO(273, conf.gps_play_dark_time,         CONF_DEF_VALUE,     i:45, NULL),

    CONF_INFO(274, conf.gps_rec_play_set_1,         CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(275, conf.gps_play_dark_set_1,        CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(276, conf.gps_rec_play_time_1,        CONF_DEF_VALUE,     i:10, NULL),
    CONF_INFO(277, conf.gps_play_dark_time_1,       CONF_DEF_VALUE,     i:15, NULL),
    CONF_INFO(278, conf.gps_show_symbol,            CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(279, conf.gps_batt_warn,              CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(270, conf.gps_track_symbol,           CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(280, conf.gps_test_timezone,          CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(281, conf.gps_beep_warn,              CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(282, conf.gps_on_off,                 CONF_DEF_VALUE,     i:0, NULL),
#endif

    // AutoISO2
    CONF_INFO(283, conf.autoiso2_shutter_enum,      CONF_DEF_VALUE,     i:6, NULL), // 6='1/20'
    CONF_INFO(284, conf.autoiso2_max_iso_auto,      CONF_DEF_VALUE,     i:60, NULL),
    CONF_INFO(285, conf.autoiso2_over,              CONF_DEF_VALUE,     i:1, NULL),
    CONF_INFO(286, conf.overexp_threshold,          CONF_DEF_VALUE,     i:5, NULL),
    CONF_INFO(287, conf.overexp_ev_enum,            CONF_DEF_VALUE,     i:3, conf_change_autoiso),

#if defined(CAM_ZOOM_ASSIST_BUTTON_CONTROL)
    CONF_INFO(288, conf.zoom_assist_button_disable, CONF_DEF_VALUE,     i:0, NULL),
#endif

    CONF_INFO(289, conf.dng_version,                CONF_DEF_VALUE,     i:0, conf_change_dng),
    CONF_INFO(290, conf.tbox_char_map,              CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(291, conf.show_alt_helper,            CONF_DEF_VALUE,     i:1, NULL),
    CONF_INFO(292, conf.show_alt_helper_delay,      CONF_DEF_VALUE,     i:3, NULL),
    CONF_INFO(293, conf.help_was_shown, 	        CONF_DEF_VALUE,     i:0, NULL),
    CONF_INFO(294, conf.menuedit_popup,		        CONF_DEF_VALUE,     i:1, NULL),
    };
#define CONF_NUM (sizeof(conf_info)/sizeof(conf_info[0]))

// Since only a few of the ConfInfo entries have a 'func' it saves space to not store the function addresses in the ConfInfo struct
void conf_info_func(unsigned short id)
{
    switch (id)
    {
    case  63: conf_change_alt_mode_button(); break;
    case  64: gui_lang_init(); break;
    case  65: conf_change_font_cp(); break;
    case  66: conf_change_menu_rbf_file(); break;
    case  67: conf_update_prevent_shutdown(); break;
    case 101: conf_change_video_bitrate(); break;
    case 143: user_menu_restore(); break;
    case 183: conf_change_menu_symbol_rbf_file(); break;
    case 194: conf_change_script_file(); break;
    case 2:
    case 226: 
    case 289: conf_change_dng(); break;
    case 235: conf_change_dng_ext(); break;
    case 284: conf_change_autoiso(); break;
    }
}

//-------------------------------------------------------------------

static void conf_change_font_cp() {
    font_init();
    font_set(conf.font_cp);
}

static void conf_change_script_file() {
#ifdef OPT_SCRIPTING
    script_load(conf.script_file, SCRIPT_UPDATE_PARAMS );
	load_params_names_cfg();
#endif
}


static void conf_change_menu_rbf_file() {
    rbf_load_from_file(conf.menu_rbf_file, FONT_CP_WIN);
}

static void conf_change_menu_symbol_rbf_file() {
    if(!rbf_load_symbol(conf.menu_symbol_rbf_file)) conf.menu_symbol_enable=0;      //AKA
}

static void conf_change_alt_mode_button() {
#if CAM_ADJUSTABLE_ALT_BUTTON
    kbd_set_alt_mode_key_mask(conf.alt_mode_button);
#else
    conf.alt_mode_button = KEY_PRINT;
#endif
}

static void conf_change_video_bitrate() {
    shooting_video_bitrate_change(conf.video_bitrate);
 }

void conf_change_dng(void){
#if DNG_SUPPORT
 if (conf.save_raw && conf.dng_raw && conf.dng_version) {
	if ( !module_dng_load(LIBDNG_OWNED_BY_RAW) )
        return;
    if (!libdng->badpixel_list_loaded_b()) libdng->load_bad_pixels_list_b("A/CHDK/badpixel.bin");
    if (!libdng->badpixel_list_loaded_b()) conf.dng_version=0;
 }
 else if ( libdng && libdng->load_bad_pixels_list_b ) {
    libdng->load_bad_pixels_list_b(0);        //unload badpixel.bin
 	module_dng_unload(LIBDNG_OWNED_BY_RAW);
 }
#endif
}

void conf_change_dng_ext(void){
#if defined (DNG_EXT_FROM)
 save_ext_for_dng();
 if (conf.dng_usb_ext) change_ext_to_dng(); else change_ext_to_default();
#endif 
}

void conf_change_autoiso()
{
  // Use menu callback ( some required enum declaration are isolated there)
  cb_autoiso_menu_change(-1);
}

/*
update the prevent display off/prevent shutdown based on current state
doesn't really belong in conf but not clear where else it should go
*/
void conf_update_prevent_shutdown(void) {
    if(conf.alt_prevent_shutdown == ALT_PREVENT_SHUTDOWN_ALWAYS 
        || (conf.alt_prevent_shutdown == ALT_PREVENT_SHUTDOWN_ALT && gui_get_mode() != GUI_MODE_NONE)
        || (conf.alt_prevent_shutdown == ALT_PREVENT_SHUTDOWN_ALT_SCRIPT && state_kbd_script_run)) {
        disable_shutdown();
    } else {
        enable_shutdown();
    }
}

//-------------------------------------------------------------------
static void conf_init_defaults() {
    // init some defaults values
    def_batt_volts_max = get_vbatt_max();
    def_batt_volts_min = get_vbatt_min();
}

//-------------------------------------------------------------------
void config_load_defaults(const ConfInfo *confinfo, int conf_num, void (*info_func)(unsigned short id))
{
    register int i;

    for (i=0; i<conf_num; ++i) {
        switch (confinfo[i].type) {
            case CONF_OSD_POS:
            case CONF_DEF_VALUE:
                memcpy(confinfo[i].var, &(confinfo[i].i), confinfo[i].size);
                break;
            case CONF_INT_PTR:
                memset(confinfo[i].var, 0, confinfo[i].size);
                break;
            case CONF_VALUE_PTR:
            case CONF_CHAR_PTR:
                memcpy(confinfo[i].var, confinfo[i].ptr, confinfo[i].size);
                break;
        }
        if (info_func) info_func(confinfo[i].id);
    }
}

void conf_load_defaults()
{
    config_load_defaults(&conf_info[0], CONF_NUM, conf_info_func);
}

//-------------------------------------------------------------------

// Structure for saved conf info (allows for changes to ConfInfo without affecting saved configurations
typedef struct
{
    unsigned short id;
    unsigned short size;
} ConfInfoSave;

void config_save(const ConfInfo *conf_info, char *filename, int conf_num)
{
    static const long t=CONF_MAGICK_VALUE;
    register int i;
    
    int size = sizeof(t) + conf_num * sizeof(ConfInfoSave);
    for (i=0; i<conf_num; i++) size += conf_info[i].size;

    char *buf = umalloc(size);
    char *p = buf;

    int fd = open(filename, O_WRONLY|O_CREAT|O_TRUNC, 0777); 
    if (fd >= 0)
    {
        memcpy(p, &t, sizeof(t));
        p += sizeof(t);
        for (i=0; i<conf_num; ++i)
        {
            ((ConfInfoSave*)p)->id   = conf_info[i].id;
            ((ConfInfoSave*)p)->size = conf_info[i].size;
            p += sizeof(ConfInfoSave);
            memcpy(p, conf_info[i].var, conf_info[i].size);
            // Clear out unused space after string config item value
            if ((conf_info[i].size == CONF_STR_LEN) && (strlen(conf_info[i].var) < CONF_STR_LEN))
                memset(p+strlen(conf_info[i].var), 0, CONF_STR_LEN-strlen(conf_info[i].var));
            p += conf_info[i].size;
        }

        write(fd, buf, p-buf);
        close(fd);
    }
    ufree(buf);
}

void conf_save()
{
    config_save(&conf_info[0], CONF_FILE, CONF_NUM);
}

//-------------------------------------------------------------------
void config_restore(const ConfInfo *confinfo, char *filename, int conf_num, void (*info_func)(unsigned short id))
{
    int fd, rcnt, i;
    unsigned short id, size;
    char *buf;
    int offs, old_ver;
    struct stat st;

    config_load_defaults(confinfo, conf_num, info_func);

    if( stat(filename,&st) != 0 || st.st_size < sizeof(int))
        return;

    if(!(buf=umalloc(st.st_size)))
        return;

    fd = open(filename, O_RDONLY, 0777); 
    if( fd < 0 ) {
        ufree(buf);
        return;
    }
    
    rcnt = read(fd,buf,st.st_size);
    close(fd);
    // read magick value
    if (*(int *)buf!=CONF_MAGICK_VALUE || rcnt != st.st_size) {
        ufree(buf);
        return;
    }

    offs=sizeof(int);
    while (1) {
        if (offs + sizeof(short) > rcnt)
            break;
        id=*((short *)(buf + offs));
        offs += sizeof(short);

        if (offs + sizeof(short) > rcnt)
            break;
        size=*((short *)(buf + offs));
        offs += sizeof(short);

        for (i=0; i<conf_num; ++i) {
            if (confinfo[i].id==id && confinfo[i].size==size) {
                if (offs + size <= rcnt) {
                   memcpy(confinfo[i].var, buf+offs, size);
                   if (info_func) info_func(confinfo[i].id);
                }
                break;
            }
        }

        offs += size;
    }
    ufree(buf);
    // clear any "clear on restart" values
    clear_values();
#if CAM_CHDK_HAS_EXT_VIDEO_TIME
    conf.ext_video_time=0;
#endif
}

void conf_restore()
{
    conf_init_defaults();
    config_restore(&conf_info[0], CONF_FILE, CONF_NUM, conf_info_func);
    // Fixup old conf.override_disable value
    if (conf.override_disable == 2) conf.override_disable = 0;
}

//-------------------------------------------------------------------
int conf_getValue(unsigned short id, tConfigVal* configVal) {
    unsigned short i;
    int ret = CONF_EMPTY;
    OSD_pos* pos;
    
    if( id==0 ) {
        configVal->numb = 0;
        for( i=0; i<CONF_NUM; ++i ) if( configVal->numb<conf_info[i].id ) configVal->numb = conf_info[i].id;
        ret = CONF_VALUE;
    } else {
        for( i=0; i<CONF_NUM; ++i ) {
            if( conf_info[i].id==id ) {
                switch( conf_info[i].type ) {
                    case CONF_VALUE:
                    case CONF_VALUE_PTR:
                        switch( conf_info[i].size ) {
                            case sizeof(int):
                                configVal->numb = *(int*)conf_info[i].var;
                                ret = CONF_VALUE;
                            break;
                            case sizeof(short):
                                configVal->numb = *(short*)conf_info[i].var;
                                ret = CONF_VALUE;
                            break;
                            case sizeof(char):
                                configVal->numb = *(char*)conf_info[i].var;
                                ret = CONF_VALUE;
                            break;
                        }
                        configVal->pInt = (int*)conf_info[i].var;
                    break;
                    case CONF_INT_PTR:
                        configVal->numb = conf_info[i].size/sizeof(int);
                        configVal->pInt = (int*)conf_info[i].var;
                        ret = CONF_INT_PTR;
                    break;
                    case CONF_CHAR_PTR:
                        configVal->str = conf_info[i].var;
                        ret = CONF_CHAR_PTR;
                    break;
                    case CONF_OSD_POS:
                        pos = (OSD_pos*)conf_info[i].var;
                        configVal->pos.x = pos->x;
                        configVal->pos.y = pos->y;
                        ret = CONF_OSD_POS;
                        configVal->pInt = (int*)conf_info[i].var;
                    break;
                }
                break;
            }
        }
    }
    return ret;
}

//-------------------------------------------------------------------
int conf_setValue(unsigned short id, tConfigVal configVal) {
    unsigned short i;
    int ret = CONF_EMPTY, len, len2;
    OSD_pos* pos;
    
    for( i=0; i<CONF_NUM; ++i ) {
        if( conf_info[i].id==id ) {
            switch( conf_info[i].type ) {
                case CONF_VALUE:
                case CONF_VALUE_PTR:
                    if( configVal.isNumb ) {
                        switch( conf_info[i].size ) {
                            case sizeof(int):
                                *(int*)conf_info[i].var = (int)configVal.numb;
                                ret = CONF_VALUE;
                            break;
                            case sizeof(short):
                                *(short*)conf_info[i].var = (short)configVal.numb;
                                ret = CONF_VALUE;
                            break;
                            case sizeof(char):
                                *(char*)conf_info[i].var = (char)configVal.numb;
                                ret = CONF_VALUE;
                            break;
                        }
                    }
                break;
                case CONF_INT_PTR:
                    if( configVal.isPInt ) {
                        len = conf_info[i].size;
                        len2 = configVal.numb*sizeof(int);
                        if( len2<len ) len = len2;
                        memcpy(conf_info[i].var, configVal.pInt, len);
                        ret = CONF_INT_PTR;
                    }
                break;
                case CONF_CHAR_PTR:
                    if( configVal.isStr ) {
                        len = strlen(configVal.str);
                        if( len>0 && len<CONF_STR_LEN) {
                            strncpy(conf_info[i].var, configVal.str ,len+1);
                        }
                        ret = CONF_CHAR_PTR;
                    }
                break;
                case CONF_OSD_POS:
                    if( configVal.isPos ) {
                        pos = (OSD_pos*)conf_info[i].var;
                        pos->x = configVal.pos.x;
                        pos->y = configVal.pos.y;
                        ret = CONF_OSD_POS;
                    }
                break;
            }
            break;
        }
    }
    if( ret!=CONF_EMPTY ) {
        conf_save();
    }
    return ret;
}

//-------------------------------------------------------------------
// Common code extracted from raw.c (raw_savefile) and gui_osd.c (gui_osd_draw_raw_info)
// returns 0 if RAW save is disabled due to mode settings, etc, return 1 if RAW save OK
int is_raw_enabled()
{
    int m = mode_get() & MODE_SHOOTING_MASK;

    // NOTE: the conf.save_raw_in variables are negative logic
    //       1 = disable saving raw in this mode, 0 = allow saving raw
    //       variables should be named conf.disable_save_raw_in_XXX

    return !(   // Return false if any of these tests are true
        (is_video_recording() && conf.save_raw_in_video) ||                                 // True is movie mode and save_raw_in_video is disabled
#ifdef CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE
        (shooting_get_resolution()==7) ||                                                   // True if shooting resolution is 'low light'
#endif
#if defined(CAM_DISABLE_RAW_IN_HQ_BURST)
        (m == MODE_SCN_HIGHSPEED_BURST) ||                                                  // True if HQ Burst mode (SX40HS corrupts JPEG images if RAW enabled in this mode)
#endif
#if defined(CAM_DISABLE_RAW_IN_HANDHELD_NIGHT_SCN)
        (m == MODE_NIGHT_SCENE) ||                                                          // True if HandHeld Night Scene (SX40HS corrupts JPEG images if RAW enabled in this mode)
#endif
        (shooting_get_resolution()==5) ||                                                   // True if shooting resolution is ??? (what is mode 5)
        ((m==MODE_SPORTS) && conf.save_raw_in_sports) ||                                    // True if sports mode and save_raw_in_sports is disabled
        ((m==MODE_AUTO) && conf.save_raw_in_auto) ||                                        // True if auto mode and save_raw_in_auto is disabled
        (conf.edge_overlay_enable && conf.save_raw_in_edgeoverlay) ||                       // True if edge overlay on and save_raw_in_edgeoverlay is disabled
        ((shooting_get_drive_mode()==1) && conf.save_raw_in_burst && !(m==MODE_SPORTS)) ||  // True if drive mode is continuous and save_raw_in_burst is disabled and not sports mode
        ((shooting_get_drive_mode()>=2) && conf.save_raw_in_timer) ||                       // True if drive mode is timer and save_raw_in_timer is disabled
        ((shooting_get_prop(PROPCASE_BRACKET_MODE)==1) && conf.save_raw_in_ev_bracketing)   // True if bracketing enabled and save_raw_in_ev_bracketing is disabled
    );
}

//-------------------------------------------------------------------
static Conf old_conf;

void conf_store_old_settings()
{
    old_conf = conf;
}

int conf_save_new_settings_if_changed()
{
    if (memcmp(&old_conf, &conf, sizeof(Conf)) != 0)
    {
		user_menu_save();
        conf_save();
        conf_store_old_settings();
        return 1;
    }
    return 0;
}

//-------------------------------------------------------------------
