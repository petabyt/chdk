#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "kbd_common.h"
#include "touchscreen.h"
#include "levent.h"
#include "gui.h"
#include "gui_draw.h"
#include "gui_osd.h"
#include "font.h"

// Uncomment this line to enable 'PLAY' and 'OFF' buttons in the CHDK OSD 
// Can be used to switch in/out of playback mode and power off the camera 
// (For 'nekut' whose camera has a broken playback button - http://chdk.setepontos.com/index.php?topic=6634.msg75039#msg75039) 
//#define   TS_PLAY_POWER_HACK  1 

long kbd_new_state[4] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[4] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[4] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long touch_panel_state;

extern void _GetKbdState(long*);

//void my_blinkk(void) {
//	int i;
////	while(1) {
//		*((volatile int *) 0xC0220134) = 0x46; // Turn on LED
//		for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }
//
//		*((volatile int *) 0xC0220134) = 0x44; // Turn off LED
//		for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }
//
//		*((volatile int *) 0xC0220134) = 0x46; // Turn on LED
//		for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }
//
//		*((volatile int *) 0xC0220134) = 0x44; // Turn off LED
//		for (i=0; i<0x900000; i++) { asm volatile ( "nop\n" ); }
////	}
//}

#define TS_KEY_TOGGLE_RAW   200
#define TS_KEY_TOGGLE_ZEBRA 201
#define TS_KEY_TOGGLE_HISTO 202
#define TS_KEY_TOGGLE_OSD   203
#define TS_KEY_TOGGLE_OVRD  204
#define TS_KEY_TOGGLE_EDGE  205
#define TS_KEY_PLAYBACK     214 
#define TS_KEY_POWER        215 

#define TS_XL       0
#define TS_XR       422
#define TS_W        58
#define TS_YT       0
#define TS_H        48
#define LB(x,n,s)   TS_XL+x*TS_W, TS_YT+n*TS_H, TS_XL+(x+1)*TS_W-1, TS_YT+n*TS_H+TS_H-1, s
#define RB(x,n,s)   TS_XR-x*TS_W, TS_YT+n*TS_H, TS_XR-(x-1)*TS_W-1, TS_YT+n*TS_H+TS_H-1, s

extern const char* gui_on_off_enum(int change, int arg);
extern const char* gui_histo_show_enum(int change, int arg);
extern const char* gui_override_disable_enum(int change, int arg);

#define MODE_VID    0x400

#if defined(TS_PLAY_POWER_HACK) 
static int playbutton_hack; 
static const char* simulate_playback_press(int change, int arg) 
{ 
    void levent_set_play(void); 
    if (change) levent_set_play(); 
    return 0; 
} 
 
static const char* simulate_power_press(int change, int arg) 
{ 
    void camera_shutdown_in_a_second(void); 
    if (change) camera_shutdown_in_a_second(); 
    return 0; 
} 
#endif

KeyMap keymap[] = {

//  { 1, TOUCH_SCREEN       , 0x00000008, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // Touch screen panel
    { 1, KEY_ZOOM_IN        , 0x00001000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // Found @0xff3d144c, levent 0x02
    { 1, KEY_ZOOM_OUT       , 0x00008000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // Found @0xff3d1454, levent 0x03
    { 2, KEY_SHOOT_FULL     , 0x00000a00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // Found @0xff3d146c, levent 0x01
    { 2, KEY_SHOOT_FULL_ONLY, 0x00000800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },	// http://chdk.setepontos.com/index.php?topic=1444.msg70223#msg70223
    { 2, KEY_SHOOT_HALF     , 0x00000200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // Found @0xff3d1464, levent 0x00
    { 2, KEY_POWER           ,0x00001000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // Found @0xff3d1474, levent 0x600
    { 2, KEY_PLAYBACK        ,0x00004000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // Found @0xff3d147c, levent 0x601

    { 3, KEY_PRINT          , 0x00000001, LB(0,1,1), 0, "CHDK",  0,    GUI_MODE_NONE,      100, MODE_REC|MODE_PLAY|MODE_VID, 0, 0, 0 }, // virtual touch screen key

    { 3, KEY_MENU		    , 0x00000002, LB(0,2,1), 0, "Menu",  0, GUI_MODE_ALT, 100, MODE_REC|MODE_PLAY|MODE_VID, 0, 0, 0 },
	{ 3, KEY_SET		    , 0x00000004, LB(0,3,1), 0, "Set",   0, GUI_MODE_ALT, 100, MODE_REC|MODE_PLAY|MODE_VID, 0, 0, 0 },

    { 3, TS_KEY_TOGGLE_RAW  , 0x00000100, RB(1,1,1), 1, "RAW",   0, GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY, &conf.save_raw, gui_on_off_enum, &conf.touchscreen_disable_shortcut_controls },
    { 3, TS_KEY_TOGGLE_OSD  , 0x00000200, RB(1,2,1), 1, "OSD",   0, GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY, &conf.show_osd, gui_on_off_enum, &conf.touchscreen_disable_shortcut_controls },
    { 3, TS_KEY_TOGGLE_OVRD , 0x00000400, RB(1,3,1), 1, "OvrDis",0, GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY, &conf.override_disable, gui_override_disable_enum, &conf.touchscreen_disable_shortcut_controls },
    { 3, TS_KEY_TOGGLE_ZEBRA, 0x00000800, RB(2,1,1), 1, "Zebra", 0, GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY, &conf.zebra_draw, gui_on_off_enum, &conf.touchscreen_disable_shortcut_controls },
    { 3, TS_KEY_TOGGLE_HISTO, 0x00001000, RB(2,2,1), 1, "Hist",  0, GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY, &conf.show_histo, gui_histo_show_enum, &conf.touchscreen_disable_shortcut_controls },
    { 3, TS_KEY_TOGGLE_EDGE , 0x00002000, RB(2,3,1), 1, "Edge",  0, GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY, &conf.edge_overlay_enable, gui_on_off_enum, &conf.touchscreen_disable_shortcut_controls },

#if defined(TS_PLAY_POWER_HACK) 
    { 3, TS_KEY_PLAYBACK    , 0x00400000, LB(1,0,1), 0, "PLAY",  0,    GUI_MODE_ALT,       GUI_MODE_ALT,  MODE_REC|MODE_PLAY, &playbutton_hack, simulate_playback_press, 0 },
    { 3, TS_KEY_POWER       , 0x00800000, LB(3,0,1), 0, "OFF",   0,    GUI_MODE_ALT,       GUI_MODE_ALT,  MODE_REC|MODE_PLAY, &playbutton_hack, simulate_power_press, 0 },
#endif
#ifdef OPT_DEBUGGING
    { 3, KEY_DISPLAY        , 0x00000008, LB(0,4,1), 0, "Debug", 0,    GUI_MODE_ALT,       GUI_MODE_ALT,  MODE_REC|MODE_PLAY, 0, 0, 0 },
#endif
    { 3, KEY_DISPLAY	    , 0x00000008, LB(0,4,1), 0, "Back",  0,    GUI_MODE_MENU,      GUI_MODE_MENU, MODE_REC|MODE_PLAY, 0, 0, 0 },
    { 3, KEY_DISPLAY        , 0x00000008, LB(0,4,1), 0, "Disp",  0,    GUI_MODE_MENU+1,    100,           MODE_REC|MODE_PLAY|MODE_VID, 0, 0, 0 },
    { 3, KEY_UP             , 0x00000010, RB(0,1,2), 0, "\x18",  0,    GUI_MODE_MENU,      100,           MODE_REC|MODE_PLAY|MODE_VID, 0, 0, 0 },
    { 3, KEY_LEFT           , 0x00000020, RB(0,2,2), 0, "\x1B",  0,    GUI_MODE_MENU,      100,           MODE_REC|MODE_PLAY|MODE_VID, 0, 0, 0 },
    { 3, KEY_RIGHT          , 0x00000040, RB(0,3,2), 0, "\x1A",  0,    GUI_MODE_MENU,      100,           MODE_REC|MODE_PLAY|MODE_VID, 0, 0, 0 },
    { 3, KEY_DOWN           , 0x00000080, RB(0,4,2), 0, "\x19",  0,    GUI_MODE_MENU,      100,           MODE_REC|MODE_PLAY|MODE_VID, 0, 0, 0 },

    { 3, KEY_UP 		    , 0x00000010, RB(0,0,1), 0, "Man",   "Focus",  GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC, &conf.subj_dist_override_koef, 0, &conf.touchscreen_disable_shortcut_controls },
    { 3, KEY_DISPLAY        , 0x00000008, RB(0,1,1), 0, "Max",   "Dist",   GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC, 0, 0, &conf.touchscreen_disable_shortcut_controls },
    { 3, KEY_DOWN           , 0x00000080, RB(0,2,1), 0, "Hyper", "Dist",   GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC, 0, 0, &conf.touchscreen_disable_shortcut_controls },
	{ 3, KEY_LEFT		    , 0x00000020, RB(0,3,1), 0, "- Foc.","Factor", GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC, 0, 0, &conf.touchscreen_disable_shortcut_controls },
    { 3, KEY_RIGHT		    , 0x00000040, RB(0,4,1), 0, "+ Foc.","Factor", GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC, 0, 0, &conf.touchscreen_disable_shortcut_controls },

	{ 0 } 
};

static int is_button_displayed(int b, int guiMode, int camMode)
{
    return (
            (keymap[b].grp == 3) && 
            (guiMode >= keymap[b].min_gui_mode) && 
            (guiMode <= keymap[b].max_gui_mode) && 
            (camMode & keymap[b].cam_mode_mask) &&
            ((keymap[b].conf_disable == 0) || (*keymap[b].conf_disable == 0))
           );
}

static int is_button_active(int b, int guiMode, int camMode)
{
    return (is_button_displayed(b, guiMode, camMode) && keymap[b].canonkey);
}

int show_virtual_buttons()
{
    extern char canon_play_menu_active;
    return (canon_menu_active==(int)&canon_menu_active-4) && (canon_shoot_menu_active==0) && (canon_play_menu_active == 0);
}

// Called from hooked touch panel task (boot.c)
// Return 0 to allow touch event to pass onto firmware, 1 to block event from firmware.
int chdk_process_touch()
{
    //ts_check_cnt++;

    // If in canon menu, let the firmware have all the touch events.
    if (!show_virtual_buttons()) return 0;

    int camMode = (get_movie_status()==VIDEO_RECORD_IN_PROGRESS) ? MODE_VID : (camera_info.state.mode & MODE_MASK);

    // Touch co-ordinate
    unsigned int tx = ((touch_screen_x & 0x7FFF) >> 5) ^ 0x3FF;
    unsigned int ty = ((touch_screen_y & 0x7FFF) >> 5) ^ 0x3FF;
    // Screen co-ordinate
    int sx = ((tx - 40) * 480) / 954;
    int sy = ((ty - 60) * 240) / 900;
    if (conf.rotate_osd)
    {
        sx = 480 - sx;
        sy = 240 - sy;
    }

    // Search for CHDK on screen buttons matching co-ordinate
    int i;
    for (i=0; keymap[i].hackkey; i++)
    {
        if ((sx >= keymap[i].x1) && (sx < keymap[i].x2) && (sy >= keymap[i].y1) && (sy < keymap[i].y2) && is_button_active(i,camera_info.state.gui_mode,camMode))
        {
            touch_panel_state &= ~keymap[i].canonkey;
        }
    }

    // Check if menu touched
    int mk = gui_touch_process(sx, sy);
    if (mk != 0)
    {
        for (i=0; keymap[i].hackkey; i++)
        {
            if ((keymap[i].hackkey == mk) && is_button_active(i,camera_info.state.gui_mode,camMode))
            {
                touch_panel_state &= ~keymap[i].canonkey;
            }
        }
    }

    // If in alt mode (or about to enter alt mode) block event from firmware
    return !camera_info.state.gui_mode_none || (((touch_panel_state & 1) == 0) && ((kbd_mod_state[3] & 1) != 0));
}

int redraw_buttons = 1;

// Test a pixel value of the CHDK on-screen button to see if it may have been erased
static int draw_test_pixel(coord x, coord y, color c)
{
    extern char* bitmap_buffer[];
    extern int active_bitmap_buffer;
    if (conf.rotate_osd)
        return (bitmap_buffer[active_bitmap_buffer][(240-y) * camera_screen.buffer_width + ASPECT_XCORRECTION(480-x) - 1] == c);
    else
        return (bitmap_buffer[active_bitmap_buffer][y * camera_screen.buffer_width + ASPECT_XCORRECTION(x)] == c);
}

void virtual_buttons()
{
    char buf[30];

    // If shooting or in any Canon menus then don't display any CHDK buttons
    if ((camera_info.state.gui_mode_none && camera_info.state.is_shutter_half_press) || !show_virtual_buttons()) return;

    // Check if border of CHDK button is corrupted, force redraw if so
    if (!draw_test_pixel(0, 80, (camera_info.state.gui_mode)?COLOR_GREEN:COLOR_WHITE)) redraw_buttons = 1;

    if (redraw_buttons)
    {
        //ts_redraw_cnt++;

        int i, x1, y1, x2, y2, sc, xo, yo;
        int camMode = (get_movie_status()==VIDEO_RECORD_IN_PROGRESS) ? MODE_VID : (camera_info.state.mode & MODE_MASK);

        color c1 = MAKE_COLOR(COLOR_GREY_DK_TRANS, COLOR_WHITE);
        color c2 = MAKE_COLOR(COLOR_GREY_DK_TRANS, COLOR_GREEN);

        for (i=0; keymap[i].hackkey; i++)
        {
            if (is_button_displayed(i, camera_info.state.gui_mode, camMode) && keymap[i].nm)
            {
                x1 = keymap[i].x1;
                x2 = keymap[i].x2;
                y1 = keymap[i].y1;
                y2 = keymap[i].y2;
                sc = keymap[i].sc;
                yo = (sc == 1) ? 16 : 8;

                twoColors cl = c1;
                if (camera_info.state.gui_mode && (keymap[i].hackkey == KEY_PRINT)) cl = c2;
                if (keymap[i].conf_val && *keymap[i].conf_val) cl = c2;

                draw_rectangle(x1, y1, x2, y2, cl, RECT_BORDER3|DRAW_FILLED|RECT_ROUND_CORNERS);

                if (keymap[i].conf_val && keymap[i].chg_val)
                {
                    yo -= 9;
                    strcpy(buf,(char*)keymap[i].chg_val(0,(int)keymap[i].conf_val));
                    buf[6] = 0;
                    xo = (58 - strlen(buf)*FONT_WIDTH*sc) / 2;
                    draw_string(x1+xo, y1+yo+18, buf, cl);
                }
                else if (keymap[i].nm2)
                {
                    yo -= 9;
                    xo = (58 - strlen(keymap[i].nm2)*FONT_WIDTH*sc) / 2;
                    draw_string(x1+xo, y1+yo+18, keymap[i].nm2, cl);
                }
                xo = (58 - strlen(keymap[i].nm)*FONT_WIDTH*sc) / 2;
                draw_string_scaled(x1+xo, y1+yo, keymap[i].nm, cl, sc, sc);
            }
        }
    }

    redraw_buttons = 0;
}

int ts_process_touch()
{
    int rv = 0, i;

    if (touch_panel_state != (long)0xFFFFFFFF)
    {
        int camMode = (get_movie_status()==VIDEO_RECORD_IN_PROGRESS) ? MODE_VID : (camera_info.state.mode & MODE_MASK);

        //ts_proc_cnt++;

        for (i=0; keymap[i].hackkey; i++)
        {
            if (is_button_active(i, camera_info.state.gui_mode, camMode))
            {
                if (kbd_is_key_clicked(keymap[i].hackkey))
                {
                    if (keymap[i].conf_val && keymap[i].chg_val)
                    {
                        keymap[i].chg_val(1,(int)keymap[i].conf_val);
                        rv = keymap[i].redraw & 1;
                    }
                    if (keymap[i].redraw & 2) redraw_buttons = 1;
                }
            }
        }
    }

    return rv;
}

//-----------------------------------------------------------------------------

int get_usb_bit()
{
    long usb_physw[3];
    usb_physw[USB_IDX] = 0;
    _kbd_read_keys_r2(usb_physw);
    return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ;
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);

    static int was_active = 0;

    if (touch_screen_active == 2)               // Touch screen activated?
    {
        was_active = 1;                                     // Record activated, wait until released
    }
    else if (was_active)
    {
        kbd_new_state[3] = touch_panel_state;               // Use virtual button state
        was_active = 0;
    }
    else
    {
        kbd_new_state[3] = touch_panel_state = 0xFFFFFFFF;  // Clear out virtual button state
    }
}

void my_kbd_read_keys()
{
    kbd_update_key_state();
    kbd_update_physw_bits();
}

long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
    asm volatile(
        "STMFD   SP!, {R1-R7,LR}\n"
        "MOV     R5, #0\n"
        //"BL      _kbd_read_keys \n"
        "BL     my_kbd_read_keys\n"
        "B       _kbd_p1_f_cont\n"
    );
    return 0; // shut up the compiler
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((naked,noinline))
mykbd_task()
{
    while (physw_run){
        _SleepTask(physw_sleep_delay);

        if (wrap_kbd_p1_f() == 1){ // autorepeat ?
            _kbd_p2_f();
        }
    }

    _ExitTask();
}
