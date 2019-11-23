#include "stdlib.h"
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "keyboard.h"
#include "touchscreen.h"
#include "gui.h"
#include "gui_draw.h"
#include "gui_osd.h"
#include "gui_menu.h"
#include "gui_user_menu.h"
#include "font.h"
#include "kbd_common.h"

long kbd_new_state[4]          = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[4]  = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[4]   = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long touch_panel_state  =   0xFFFFFFFF;
static long touch_panel_button =   0xFFFFFFFF;

extern void _GetKbdState(long*);
extern int kbd_is_blocked(void);

int get_usb_bit()
{
    long usb_physw[3];
    usb_physw[USB_IDX] = 0;
    _kbd_read_keys_r2(usb_physw);
    return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ;
}

#define TS_KEY_SCRIPT_RUN   200
#define TS_KEY_TOGGLE_RAW   201
#define TS_KEY_TOGGLE_OSD   202
#define TS_KEY_TOGGLE_OVRD  203
#define TS_KEY_PLAYBACK     204 
#define TS_KEY_POWER        205
#define TS_KEY_EXIT         206
#define TS_KEY_USER_MENU    207
#define TS_KEY_ZOMBIE       0xFFFE

#define MODE_VID    0x400

extern const char* gui_on_off_enum(int change, int arg);
extern const char* gui_histo_show_enum(int change, int arg);
extern const char* gui_override_disable_enum(int change, int arg);
extern gui_handler scriptGuiHandler;

static const char* ts_user_menu_enable(int change, int arg) 
{ 
    extern void gui_menu_init();
    extern gui_handler* gui_set_mode(gui_handler *) ;
    extern int gui_user_menu_flag ;    
    if ( change ) 
    {
            gui_set_mode(&menuGuiHandler);
            gui_user_menu_flag = 0;
            gui_menu_init(&user_submenu);
    }
    return 0;
}

static const char* simulate_playback_press(int change, int arg) 
{ 
    void levent_set_play(void);
    void levent_set_record(void) ;
    if ( change ) 
    {
        int camMode = (get_movie_status()==VIDEO_RECORD_IN_PROGRESS) ? MODE_VID : (mode_get() & MODE_MASK);
        if (camMode) levent_set_play(); else levent_set_record() ;
    }
    return 0; 
} 
 
static const char* simulate_power_press(int change, int arg) 
{ 
    void camera_shutdown_in_a_second(void); 
    if (change) camera_shutdown_in_a_second(); 
    return 0; 
} 

static const char* ts_exit_alt(int change, int arg)
{
    if (change) exit_alt() ;
    return 0;
}

static const char* ts_run_script(int change, int arg)
{
    if (change) 
    {
        kbd_new_state[2]=kbd_new_state[2]&0xFFFFFFC0 ;      
    }
    return 0;
}

KeyMap keymap[] = {
    // Order IS important. kbd_get_pressed_key will walk down this table
    // and take the first matching mask. Notice that KEY_SHOOT_HALF is
    // always pressed if KEY_SHOOT_FULL is.

    { 0, KEY_POWER           ,0x00100000 }, // Found @0xff5bdba8, levent 0x100
    { 2, KEY_SHOOT_FULL      ,0x00000030 }, // Found @0xff5bdbb8, levent 0x01
    { 2, KEY_SHOOT_FULL_ONLY ,0x00000020 }, // Found @0xff5bdbb8, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00000010 }, // Found @0xff5bdbb0, levent 0x00
    { 2, KEY_ZOOM_OUT        ,0x00000100 }, // Found @0xff5bdbc0, levent 0x04
    { 2, KEY_ZOOM_IN         ,0x00000200 }, // Found @0xff5bdbc8, levent 0x03
    { 2, KEY_PLAYBACK        ,0x00010000 }, // Found @0xff5bdbd8, levent 0x101
    { 2, KEY_PRINT           ,0x00020000 }, // wifi button - use as default <ALT> key
//  { 0. KEY_TOUCH_NONE      ,0x10000000 }. // touch screen not touched
//  { 0, KEY_TOUCH_DOWN      ,0x20000000 }, // touch screen touched
//  { 2, KEY_CUSTOM_SWITCH   ,0x00002000 }, // Custom Mode Switch
//  { 2, KEY_SDCARD_DOOR     ,0x00080000 }. // SD card door switch     

    { 3, KEY_MENU           , 0x00000001,   0,    0, 39,  47,  0, "CHDK", "MENU", GUI_MODE_ALT, 100,          MODE_REC|MODE_PLAY },
    { 3, TS_KEY_EXIT        , 0x00000002,   0,  192, 39, 239,  0, "Exit",  "ALT", GUI_MODE_ALT, 100,          MODE_REC|MODE_PLAY, 0, ts_exit_alt, 0 },
    
    { 3, TS_KEY_USER_MENU   , 0x00000004,   0,   48, 39,  95,  0, "USER",  "MENU",GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY, 0, ts_user_menu_enable, 0 },
    { 3, KEY_SET            , 0x00000008,   0,   96, 39, 143,  0, "PRGM",  0,     GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY },
// was DISPLAY but assume blank name means not used, switched to ZOMBIE
//    { 3, KEY_DISPLAY        , 0x00000010,   0,  144, 39, 191,  0, " ",     0,     GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY },
    { 3, TS_KEY_ZOMBIE      , 0x00000020,   0,  144, 39, 191,  0, " ",     0,     GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY },

    { 3, TS_KEY_ZOMBIE      , 0x00000020,   0,   48, 39,  95,  0, " ",     0,     GUI_MODE_MENU, GUI_MODE_MENU,  MODE_REC|MODE_PLAY },
    { 3, TS_KEY_ZOMBIE      , 0x00000020,   0,   96, 39, 143,  0, " ",     0,     GUI_MODE_MENU, GUI_MODE_MENU,  MODE_REC|MODE_PLAY },
    { 3, KEY_DISPLAY        , 0x00000010,   0,  144, 39, 191,  0, "BACK",  0,     GUI_MODE_MENU, GUI_MODE_MENU,  MODE_REC|MODE_PLAY },
    
    { 3, KEY_DISPLAY        , 0x00000010,   0,  144, 39, 191,  0, "DISP",  0,     GUI_MODE_SCRIPT, GUI_MODE_OSD,  MODE_REC|MODE_PLAY },
    
    { 3, KEY_UP             , 0x00000200, 320,   0, 359,  47,  0, "Up",    0,     GUI_MODE_MENU,100, MODE_REC|MODE_PLAY },
    { 3, KEY_LEFT           , 0x00000400, 320,  48, 359,  95,  0, "Left",  0,     GUI_MODE_MENU,100, MODE_REC|MODE_PLAY },
    { 3, KEY_SET            , 0x00000800, 320,  96, 359, 143,  0, " Set",  0,     GUI_MODE_MENU,100, MODE_REC|MODE_PLAY },
    { 3, KEY_RIGHT          , 0x00001000, 320, 144, 359, 191,  0, "Right", 0,     GUI_MODE_MENU,100, MODE_REC|MODE_PLAY },
    { 3, KEY_DOWN           , 0x00002000, 320, 192, 359, 239,  0, "Down",  0,     GUI_MODE_MENU,100, MODE_REC|MODE_PLAY },
    
    { 3, TS_KEY_SCRIPT_RUN  , 0x00004000, 320,   0, 359,  47,  0, "RUN",   0,     GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY, 0, ts_run_script, 0 },
    { 3, TS_KEY_TOGGLE_RAW  , 0x00008000, 320,  48, 359,  95,  1, "RAW",   0,     GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY, &conf.save_raw, gui_on_off_enum, &conf.touchscreen_disable_shortcut_controls },
//  { 3, TS_KEY_TOGGLE_OSD  , 0x00010000, 320,  96, 359, 143,  1, "OSD",   0,     GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY, &conf.show_osd, gui_on_off_enum, &conf.touchscreen_disable_shortcut_controls },
    { 3, TS_KEY_TOGGLE_OVRD , 0x00020000, 320,  96, 359, 143,  1, "OVR",   0,     GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY, &conf.override_disable, gui_override_disable_enum, &conf.touchscreen_disable_shortcut_controls },  
    { 3, TS_KEY_PLAYBACK    , 0x00040000, 320, 144, 359, 191,  0, "REC/", "PLAY",  GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY, 0, simulate_playback_press, 0 }, 
    { 3, TS_KEY_POWER       , 0x00080000, 320, 192, 359, 239,  0, "OFF",   0,     GUI_MODE_ALT, GUI_MODE_ALT, MODE_REC|MODE_PLAY, 0, simulate_power_press, 0 }, 
  
    { 0, 0, 0 }
};


// TODO generic touch stuff should be in kbd_common.c or it's own file
static int is_button_displayed(int b, int guiMode, int camMode)
{
    return(
            (keymap[b].grp == 3) &&
            (guiMode >= keymap[b].min_gui_mode) &&
            (guiMode <= keymap[b].max_gui_mode) &&
            (camMode & keymap[b].cam_mode_mask) &&
            ((keymap[b].conf_disable == 0) || (*keymap[b].conf_disable == 0))
           );
}

static int is_button_active(int b, int guiMode, int camMode)
{
    return is_button_displayed(b, guiMode, camMode);
}

int show_virtual_buttons()
{
    extern int active_palette_buffer;
    return((active_palette_buffer == 0x00) || (active_palette_buffer == 0x10)) ;
}

int chdk_process_touch()
{
    int guiMode = camera_info.state.gui_mode;
    int camMode = (get_movie_status()==VIDEO_RECORD_IN_PROGRESS) ? MODE_VID : (mode_get() & MODE_MASK);
    
    unsigned short tx, ty;                                              // Touch co-ordinate
    tx = touch_screen_x * 360 / 0x2FF ;
    ty = touch_screen_y *  240 / 0x1FF ;
    if (conf.rotate_osd)
    {
        tx = 360 - tx;
        ty = 240 - ty;
    }

    if ( touch_screen_active )                                          // Search for CHDK on screen buttons matching co-ordinate
    {
        int i;
        for (i=0; keymap[i].hackkey; i++)
        {
            if ((tx >= keymap[i].x1) && (tx < keymap[i].x2) && (ty >= keymap[i].y1) && (ty < keymap[i].y2) && is_button_active(i,guiMode,camMode))
            {
                touch_panel_button &= ~keymap[i].canonkey;              //
            }
       }
       
        // Check if menu touched
        int mk = gui_touch_process(tx, ty);
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
    }
    else
    {
        touch_panel_state = touch_panel_button ;                        // on touch release update touch_panel_state
        touch_panel_button = 0xFFFFFFFF ;                               // this means there is not key repeat function though
    }
    return 0;
}

int ts_process_touch()
{
    int rv = 0, i;

    if (touch_panel_state != 0xFFFFFFFF)
    {
        int guiMode = camera_info.state.gui_mode;
        int camMode = (get_movie_status()==VIDEO_RECORD_IN_PROGRESS) ? MODE_VID : (mode_get() & MODE_MASK);

        for (i=0; keymap[i].hackkey; i++)
        {
            if (is_button_active(i, guiMode, camMode))
            {
                if (kbd_is_key_clicked(keymap[i].hackkey))
                {
                    if (keymap[i].chg_val)
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

int redraw_buttons = 1;
// int menu_key_index = -1;

void virtual_buttons()
{
    int guiMode = camera_info.state.gui_mode;
    char buf[30];

    //if(menu_key_index == -1) 
    //{
    //    int i;
    //    for (i=0; keymap[i].hackkey != KEY_MENU; i++);
    //    menu_key_index = i;
    //}

    if (redraw_buttons)
    {
        int i, x1, y1, x2, y2, ofst;
        int camMode = (get_movie_status()==VIDEO_RECORD_IN_PROGRESS) ? MODE_VID : (mode_get() & MODE_MASK);

        twoColors c1 = MAKE_COLOR(COLOR_RED_DK,COLOR_WHITE);        // ALT exit button
        twoColors c2 = MAKE_COLOR(COLOR_WHITE, COLOR_BLUE_DK);      // Right side keys
        twoColors c3 = MAKE_COLOR(COLOR_WHITE, COLOR_RED_DK);       // Left side keys
        twoColors c4 = MAKE_COLOR(COLOR_GREY_DK_TRANS, COLOR_WHITE); // Semi-transparent keys
        
        for (i=0; keymap[i].hackkey; i++)
        {
            if (is_button_displayed(i, guiMode, camMode) && keymap[i].nm)
            {
                x1 = keymap[i].x1;
                x2 = keymap[i].x2;
                y1 = keymap[i].y1;
                y2 = keymap[i].y2;

                twoColors clr = c3;
                if ( guiMode == GUI_MODE_SCRIPT ) clr = c4 ;
                else
                {
                    if (keymap[i].hackkey == TS_KEY_EXIT) clr = c1;
                    else
                    {
                        if ((x1 >180) || (*keymap[i].conf_val)) clr=c2;
                    }
                }
                ofst = 16;

                draw_rectangle(x1, y1, x2, y2, clr, RECT_BORDER1|DRAW_FILLED|RECT_ROUND_CORNERS);

                if      (keymap[i].hackkey == KEY_UP)
                {
                    rbf_draw_symbol(x1+12, y1+15, 0x53, clr);
                }
                else if (keymap[i].hackkey == KEY_RIGHT)
                {
                    rbf_draw_symbol(x1+12, y1+15, 0x52, clr);
                }
                else if (keymap[i].hackkey == KEY_LEFT)
                {
                    rbf_draw_symbol(x1+12, y1+15, 0x51, clr);
                }
                else if (keymap[i].hackkey == KEY_DOWN)
                {
                    rbf_draw_symbol(x1+12, y1+15, 0x54, clr);
                }
                else
                {
                    if (keymap[i].conf_val && keymap[i].chg_val)
                    {
                        ofst = 7;
                        strcpy(buf,(char*)keymap[i].chg_val(0,(int)keymap[i].conf_val));
                        buf[3] = 0;
                        draw_string(x1+4, y1+25, buf, c3);
                    }
                    else if (keymap[i].nm2)
                    {
                        ofst = 7;
                        draw_string(x1+4, y1+25, keymap[i].nm2, clr);
                    }
                    draw_string(x1+4, y1+ofst, keymap[i].nm, clr);
                }
            }
        }
    }

    redraw_buttons = 0;
}


long __attribute__((naked)) wrap_kbd_p1_f() ;


static void __attribute__((noinline)) mykbd_task_proceed()
{
    while (physw_run) {
        _SleepTask(physw_sleep_delay);

        if (wrap_kbd_p1_f() == 1) {                                     // autorepeat ?
            _kbd_p2_f();
        }
    }
}

void __attribute__((naked,noinline)) mykbd_task()                       // no stack manipulation needed here, since we create the task directly
{
    mykbd_task_proceed();
    _ExitTask();
}

long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
    asm volatile(
        "STMFD   SP!, {R1-R7,LR}\n"
        "MOV     R5, #0\n"
        "BL        my_kbd_read_keys\n"
        "B       _kbd_p1_f_cont\n"
    );
    return 0;                                                           // bring peace and understanding to the compiler
}

//static int sdelay = 0 ;
void kbd_fetch_data(long *state) {
    _GetKbdState(state);
    _kbd_read_keys_r2(state);
    // update virtual buttons
    if( kbd_is_blocked() )
    {
       // if (sdelay > 5 )
       // {
            chdk_process_touch();
            virtual_buttons();
            kbd_new_state[3] = touch_panel_state;                       // Yes, use virtual button state
       // } else sdelay++ ;
    }
    else
    {
        kbd_new_state[3] = touch_panel_state = 0xFFFFFFFF;              // No, clear out virtual button state
    }
}

void my_kbd_read_keys()
{
    kbd_update_key_state();
    kbd_update_physw_bits();
}
