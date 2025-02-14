#ifndef PLATFORM_H
#define PLATFORM_H

#include "vxworks.h"

#define SSID_INVALID (-32767)
#define ASID_INVALID (-32767)

#define MODE_MASK               0x0300
#define MODE_REC                0x0100
#define MODE_PLAY               0x0200

#define MODE_SHOOTING_MASK      0x00FF
#define MODE_AUTO               1
#define MODE_P                  2
#define MODE_TV                 3
#define MODE_AV                 4
#define MODE_M                  5
#define MODE_PORTRAIT           6
#define MODE_NIGHT              7
#define MODE_LANDSCAPE          8
#define MODE_VIDEO_STD          9
#define MODE_VIDEO_SPEED        10
#define MODE_VIDEO_COMPACT      11
#define MODE_VIDEO_MY_COLORS    12
#define MODE_VIDEO_COLOR_ACCENT 13
#define MODE_STITCH             14
#define MODE_MY_COLORS          15
#define MODE_SCN_WATER          16
#define MODE_SCN_NIGHT          17
#define MODE_SCN_CHILD          18
#define MODE_SCN_PARTY          19
#define MODE_SCN_GRASS          20
#define MODE_SCN_SNOW           21
#define MODE_SCN_BEACH          22
#define MODE_SCN_FIREWORK       23
#define MODE_SCN_COLOR_ACCENT   24

#define MODE_SCREEN_MASK        0x0C00
#define MODE_SCREEN_OPENED      0x0400
#define MODE_SCREEN_ROTATED     0x0800

#define LED_AF   0xc0220080
#define LED_PR   0xc0220084
#define LED_RED  0xc0220088

/* Keyboard repeat and initial delays */
#define KBD_REPEAT_DELAY  140
#define KBD_INITIAL_DELAY 300

#if 0
  
  #define DEBUG_TRACE(...)

#else

  #define DEBUG_TRACE(a,b) debug_trace(a,b)

#endif


typedef struct {
    short int id; // hacks id
    short int prop_id; // Canons id
    char name[8];
    short int shutter_dfs_value; // shutter speed to use dark frame substraction
} ISOTable;

typedef struct {
    short int id; // hacks id
    short int prop_id; // Canons id
    char name[8];
    long usec;
} ShutterSpeed;

typedef struct {
    short int id; // hacks id
    short int prop_id; // Canons id
    char name[8];
} ApertureSize;

/******************************************************************/

int get_focal_length(int zp);
int get_effective_focal_length(int zp);
int get_zoom_x(int zp);

/******************************************************************/

long get_tick_count();

void remount_filesystem();
void mark_filesystem_bootable();

/******************************************************************/

long get_parameter_data(long id, void *buf, long bufsize);
long set_parameter_data(long id, void *buf, long bufsize);

long get_property_case(long id, void *buf, long bufsize);
long set_property_case(long id, void *buf, long bufsize);

long get_file_counter();
long get_file_next_counter();
long get_target_dir_num();
long get_target_file_num();

/******************************************************************/

void kbd_key_press(long key);
void kbd_key_release(long key);
void kbd_key_release_all();
long kbd_is_key_pressed(long key);
long kbd_is_key_clicked(long key);
long kbd_get_pressed_key();
long kbd_get_clicked_key();
long kbd_get_autoclicked_key();
void kbd_reset_autoclicked_key();
long kbd_use_zoom_as_mf();
void kbd_set_alt_mode_key_mask(long key);

/******************************************************************/

long vid_is_bitmap_shown();
void *vid_get_bitmap_fb();
long vid_get_bitmap_width();
long vid_get_bitmap_height();
void *vid_get_viewport_fb();
void *vid_get_viewport_fb_d();
void *vid_get_viewport_live_fb();
void vid_bitmap_refresh();
long vid_get_viewport_height();

/******************************************************************/

void *hook_raw_fptr();
void *hook_raw_ret_addr();
char *hook_raw_image_addr();
long hook_raw_size();
void hook_raw_install();
void hook_raw_save_complete();

/******************************************************************/

long lens_get_zoom_pos();
void lens_set_zoom_pos(long newpos);
long lens_get_zoom_point();
void lens_set_zoom_point(long newpt);
void lens_set_zoom_speed(long newspd); //for S-series
long lens_get_focus_pos();
void lens_set_focus_pos(long newpos);
long lens_get_target_distance();

/******************************************************************/

int shooting_in_progress();
int shooting_is_flash_ready();

int shooting_get_tv();
void shooting_set_tv(int v);
void shooting_set_tv_rel(int v);
const ShutterSpeed *shooting_get_tv_line();

int shooting_get_av();
void shooting_set_av(int v);
void shooting_set_av_rel(int v);

int shooting_get_real_av();

extern int circle_of_confusion;

extern const int zoom_points;
int shooting_get_zoom();
void shooting_set_zoom(int v);
void shooting_set_zoom_rel(int v);
void shooting_set_zoom_speed(int v);

int shooting_get_focus();
void shooting_set_focus(int v);

int shooting_get_iso();
void shooting_set_iso(int v);
void shooting_set_iso_direct(int v);

void shooting_set_movie_hi_compression(int c);

/******************************************************************/

int mode_get();

/******************************************************************/

long stat_get_vbatt();
long get_vbatt_min();
long get_vbatt_max();

void disable_shutdown();
void enable_shutdown();


/******************************************************************/
void __attribute__((noreturn)) shutdown();


void debug_led(int state);

#define started() led_on(LED_AF)
#define finished() led_off(LED_AF)

void debug_blink(int led);

void led_on(int led);
void led_off(int led);

void debug_trace(char *a, int b);

void logger_task();


#endif
