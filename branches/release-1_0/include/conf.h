#ifndef CONF_H
#define CONF_H

#include "gui.h"
#include "script.h"

#define USER_MENU_ITEMS     14
#define CONF_STR_LEN        100

#define CONF_EMPTY          0
// regular char-int-short value
#define CONF_VALUE          1
#define CONF_DEF_VALUE      1
// pointer to value
#define CONF_VALUE_PTR      2
// pointer to array of int
#define CONF_INT_PTR        3
// pointer to the string
#define CONF_CHAR_PTR       4
// pointer to the OSD_pos
#define CONF_OSD_POS_PTR    5

typedef struct {
    unsigned short  x, y;
} OSD_pos;

typedef struct {
    int isNumb, isStr, isPInt, isPos;
    int numb;
    char* str;
    int* pInt;
    OSD_pos pos;
} tConfigVal;

typedef struct {
    int save_raw;
    int save_raw_in_video;
    int save_raw_in_sports;
    int save_raw_in_burst;
    int save_raw_in_edgeoverlay;
    int save_raw_in_auto;
    int save_raw_in_ev_bracketing;
    int save_raw_in_timer;
    int raw_exceptions_warn;
    int raw_in_dir;
    int raw_prefix;
    int raw_ext;
    int raw_save_first_only; //for series shooting
    int raw_nr;
    int sub_batch_prefix; // output of batch subtracts
    int sub_batch_ext;
    int raw_cache;
    int dng_raw;
    int raw_timer;
    int raw_dng_ext;
    int dng_usb_ext;

    int show_osd;
    int hide_osd;
    int show_osd_in_review;
    int script_shoot_delay;
    int show_histo;
    int script_vars[SCRIPT_NUM_PARAMS];
    char script_file[CONF_STR_LEN];

    int show_dof;
    int batt_volts_max;
    int batt_volts_min;
    int batt_step_25;
    int batt_perc_show;
    int batt_volts_show;
    int batt_icon_show;
    int space_bar_show;
    int space_bar_size;
    int space_bar_width;
    int space_icon_show;
    int show_clock;
    int show_temp;
    int temperature_unit;
    int clock_format;
    int clock_indicator;
    int clock_halfpress;
    int space_perc_show;
    int space_mb_show;
    int show_partition_nr;
    int space_perc_warn;
    int space_mb_warn;
    int space_warn_type;
    int show_movie_time;
    int show_movie_refresh;

    int zoom_value;

    int show_state;
    int show_remaining_raw;
    int remaining_raw_treshold;
    int show_raw_state;
    int show_values;
    int show_values_in_video;
    int show_overexp;

    int histo_mode;
    int histo_auto_ajust;
    int histo_ignore_boundary;
    int histo_layout;
    int histo_show_ev_grid;

    int zebra_draw;
    int zebra_mode;
    int zebra_restore_screen;
    int zebra_restore_osd;
    int zebra_over;
    int zebra_under;
    int zebra_draw_osd;
    int zebra_multichannel;

    OSD_pos histo_pos;
    OSD_pos dof_pos;
    OSD_pos batt_icon_pos;
    OSD_pos space_icon_pos;
    OSD_pos space_hor_pos;
    OSD_pos space_ver_pos;
    OSD_pos batt_txt_pos;
    OSD_pos space_txt_pos;
    OSD_pos mode_state_pos;
    OSD_pos mode_raw_pos;
    OSD_pos values_pos;
    OSD_pos clock_pos;
    OSD_pos mode_video_pos;
    OSD_pos mode_ev_pos;
    OSD_pos temp_pos;
    OSD_pos ev_video_pos;
    OSD_pos usb_info_pos;

    color histo_color;
    color histo_color2; // markers/border
    color osd_color;
    color osd_color_warn;
//    color batt_icon_color;
    color space_color;
    color menu_color;
    color menu_title_color;
    color menu_cursor_color;
    color menu_symbol_color;
    int menu_center;
    int menu_select_first_entry;
    int menu_symbol_enable;
    color reader_color;
    color zebra_color; // under/over
    color grid_color;
    color osd_color_override;

    int font_cp;
    char menu_rbf_file[CONF_STR_LEN];
    char menu_symbol_rbf_file[CONF_STR_LEN];

    char lang_file[CONF_STR_LEN];

    char reader_file[CONF_STR_LEN];
    int  reader_pos;
    int  reader_autoscroll;
    int  reader_autoscroll_delay;
    char reader_rbf_file[CONF_STR_LEN];
    int  reader_codepage;
    int  reader_wrap_by_words;

    int sokoban_level;

    int flashlight;
    int fast_ev;
    int fast_ev_step;
    int fast_image_quality;
    int fast_movie_control;
    int fast_movie_quality_control;
    int splash_show;
    int start_sound;
    int platformid;

    int use_zoom_mf;
    long alt_mode_button; //for S-series
    int alt_prevent_shutdown;

    int show_grid_lines;
    char grid_lines_file[CONF_STR_LEN];
    int grid_force_color;

    int video_mode;
    int video_quality;
    int video_bitrate;

    int tv_bracket_value;
    int av_bracket_value;
    int iso_bracket_value;
    int iso_bracket_koef;
    int subj_dist_bracket_value;
    int subj_dist_bracket_koef;
    int bracket_type;
    int bracketing_add_raw_suffix;
    int clear_bracket;
    int clear_video;
    int override_disable;
    int override_disable_all;

    int tv_override_value;
    int tv_override_koef;
    int tv_enum_type;
    int av_override_value;

    int nd_filter_state;

    int iso_override_value;
    int iso_override_koef;
//    int zoom_override_value;
//    int zoom_override;
    int subj_dist_override_value;
    int subj_dist_override_koef;
    int clear_override;
//    int clear_zoom_override;

    int autoiso_enable;
//  int autoiso_shutter;
    int autoiso_shutter_enum;
    int autoiso_user_factor;
    int autoiso_is_factor;
    int autoiso_max_iso_hi;
    int autoiso_max_iso_auto;
    int autoiso_min_iso;
    int autoiso2_shutter_enum;
    int autoiso2_max_iso_auto;
    //AutoISO2 precalced values
    float autoiso2_coef;        // C2=( iso2_max_auto_real - iso_max_auto_real) / ( tv_num[autoiso_shutter] - tv_numerator[autoiso2_shutter])
    int autoiso_max_iso_hi_real;    // converted from GUI (possible marketing) to real iso value
    int autoiso_max_iso_auto_real;
    int autoiso_min_iso_real;
    int autoiso2_max_iso_auto_real;
    int autoiso_min_shutter_numerator;  // converted from enum to numerator
    int autoiso2_min_shutter_numerator;

    int overexp_threshold;
    int overexp_ev_enum;    // 0-off, 1=-1/3, ..

    int dof_subj_dist_as_near_limit;
    int dof_use_exif_subj_dist;
    int dof_subj_dist_in_misc;
    int dof_near_limit_in_misc;
    int dof_far_limit_in_misc;
    int dof_hyperfocal_in_misc;
    int dof_depth_in_misc;
//    int dof_dist_from_lens;

    int values_show_in_review;
    int values_show_zoom;
    int values_show_real_aperture;
    int values_show_real_iso;
    int values_show_market_iso;
    int values_show_iso_only_in_autoiso_mode;
    int values_show_ev_seted;
    int values_show_ev_measured;
    int values_show_bv_measured;
    int values_show_bv_seted;
    int values_show_overexposure;
    int values_show_canon_overexposure;
    int values_show_luminance;

    int debug_shortcut_action;   // 0=none, 1=dump, 2=page display
    int debug_display;           // 0=none, 1=props, 2=flash param, 3=tasks
    int debug_propcase_page;     // save propcase page
    int debug_lua_restart_on_error; // 0=no, 1=yes
    int debug_misc_vals_show;    // 0=no, 1=yes

    int script_startup;          // remote autostart
    int remote_enable;           // remote enable
    int user_menu_enable;
    int user_menu_vars[USER_MENU_ITEMS];
    int user_menu_as_root;
    int zoom_scale;
    int unlock_optical_zoom_for_video;
    int mute_on_zoom;
    int bad_pixel_removal;
    int video_af_key;

    char curve_file[CONF_STR_LEN];
    int curve_enable;

    int edge_overlay_enable;
    int edge_overlay_filter;
    int edge_overlay_thresh;
    int edge_overlay_zoom;  // shall zoom be set when *edg file is loaded?
    int edge_overlay_pano;  // whether a full press changes back to live mode
    int edge_overlay_pano_overlap; // overlap in % in pano mode
    int edge_overlay_show;  // whether to show overlay even when no button is pressed
    int edge_overlay_play;  // whether edge overlay is switched on also for play mode
    color edge_overlay_color;

    int synch_enable;
    int ricoh_ca1_mode;
    int synch_delay_enable;
    int synch_delay_value;
    int synch_delay_coarse_value;
    int remote_zoom_enable;
    int zoom_timeout;

    int script_param_set;
    int script_param_save;

    long mem_view_addr_init;
    int flash_sync_curtain;
    int flash_video_override;
    int flash_manual_override;
    int flash_video_override_power;

    // Overrides to disable touchscreen U/I components (IXUS 310)
    int touchscreen_disable_video_controls;
    int touchscreen_disable_shortcut_controls;

    // Enable USB icon
    int usb_info_enable;
    int ext_video_time;     // save gps_track_time

#if defined(CAM_ZOOM_ASSIST_BUTTON_CONTROL)
    int zoom_assist_button_disable;    // used to disable the zoom assist button on SX30 & SX40 for people who keep accidentaly pressing it
#endif

#ifdef CAM_HAS_GPS
    int gps_record;
    int gps_navi_show;
    int gps_navi_hide;
    int gps_kompass_show;
    int gps_kompass_hide;
    int gps_coordinates_show;
    int gps_height_show;
    int gps_waypoint_save;
    int gps_track_time;
    int gps_wait_for_signal;
    int gps_kompass_time;
    int gps_navi_time;
    int gps_wait_for_signal_time;
    int gps_kompass_smooth;
    int gps_batt;
    int gps_countdown;
    int gps_2D_3D_fix;
    int gps_countdown_blink;
    int gps_rec_play_set;
    int gps_play_dark_set;
    int gps_rec_play_time;
    int gps_play_dark_time;
    int gps_rec_play_set_1;
    int gps_play_dark_set_1;
    int gps_rec_play_time_1;
    int gps_play_dark_time_1;
    int gps_show_symbol;

    int gps_batt_warn;
    int gps_track_symbol;
    int gps_test_timezone;
    int gps_beep_warn;
    int gps_on_off;
#endif
} Conf;

extern Conf conf;

#define ALT_PREVENT_SHUTDOWN_NO         0
#define ALT_PREVENT_SHUTDOWN_ALT        1
#define ALT_PREVENT_SHUTDOWN_ALT_SCRIPT 2
#define ALT_PREVENT_SHUTDOWN_ALWAYS     3

#define SHOOTING_PROGRESS_NONE          0
#define SHOOTING_PROGRESS_STARTED       1
#define SHOOTING_PROGRESS_PROCESSING    2
#define SHOOTING_PROGRESS_DONE          3


// video quality defaults. Ideally, these should match the camera default settings
#define VIDEO_DEFAULT_QUALITY   84  // ? where does 84 come from
#define VIDEO_MAX_QUALITY       99
#define VIDEO_DEFAULT_BITRATE   3   // should be 1 for all cams

extern void user_menu_restore();

extern int state_kbd_script_run;
extern int state_shooting_progress;
extern int state_save_raw_nth_only;
extern int state_expos_recalculated;
extern int state_expos_under;
extern int state_expos_over;

extern void script_autostart();     // remote autostart
extern void conf_save();
extern void conf_restore();
extern void conf_load_defaults();
extern int shutter_int;
extern void conf_change_dng(void);
extern void conf_update_prevent_shutdown(void);
extern int conf_getValue(unsigned short id, tConfigVal* configVal);
extern int conf_setValue(unsigned short id, tConfigVal configVal);

// reyalp: putting these in conf, since the conf values are lookups for them
// prefixes and extentions available for raw images (index with conf.raw_prefix etc)
#define NUM_IMG_PREFIXES 3  // IMG_ CRW_ SND_ (could add ETC_ SDR_ AUT_ MVI_ MRK_)
#define NUM_IMG_EXTS 5      // .JPG .CRW .CR2 .THM .WAV (could add .AVI .MRK)
extern const char* img_prefixes[NUM_IMG_PREFIXES];
extern const char* img_exts[NUM_IMG_EXTS];
// ugh, but various things need it
#define VIDEO_BITRATE_STEPS 10
extern const char *video_bitrate_strings[VIDEO_BITRATE_STEPS];

extern int is_raw_enabled();

#endif
