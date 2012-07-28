#include "stdlib.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "conf.h"
#include "action_stack.h"
#include "camera.h"
#include "lang.h"
#include "gui_lang.h"
#include "console.h"
#include "usb_remote.h"

int state_kbd_script_run;

static int kbd_blocked;

void enter_alt()
{
    get_usb_power(CLEAR_USB_REGISTERS);         // Prevent previous USB remote pulse from starting script.
    kbd_blocked = 1;
    gui_set_alt_mode_state(ALT_MODE_ENTER);
}

void exit_alt()
{
    kbd_blocked = 0;
    gui_set_alt_mode_state(ALT_MODE_LEAVE);
}

/* 
    main kb processing
 */

int kbd_is_blocked()
{
	return kbd_blocked;
}

void kbd_set_block(int bEnableBlock)
{
    kbd_blocked = bEnableBlock ? 1 : 0;
}

//-------------------------------------------------------------------
// Core keyboard handler
long kbd_process()
{
    static int key_pressed;

    // Set Shutter Half Press state for GUI task.
    camera_info.state.is_shutter_half_press = kbd_is_key_pressed(KEY_SHOOT_HALF);

	// Alternative keyboard mode stated/exited by pressing print key.
	// While running Alt. mode shoot key will start a script execution.

	// alt-mode switch and delay emulation
 
	if ( key_pressed  && !usb_remote_active ) 
	{
        if (kbd_is_key_pressed(conf.alt_mode_button)
                || ((key_pressed >= CAM_EMUL_KEYPRESS_DELAY)
                && (key_pressed < CAM_EMUL_KEYPRESS_DELAY+CAM_EMUL_KEYPRESS_DURATION)))
        {
            if (key_pressed <= CAM_EMUL_KEYPRESS_DELAY+CAM_EMUL_KEYPRESS_DURATION) 
                key_pressed++;
            if (key_pressed == CAM_EMUL_KEYPRESS_DELAY) 
                kbd_key_press(conf.alt_mode_button);
            else if (key_pressed == CAM_EMUL_KEYPRESS_DELAY+CAM_EMUL_KEYPRESS_DURATION) 
                kbd_key_release(conf.alt_mode_button);
            return 1;
        } 
        else if (kbd_get_pressed_key() == 0)
        {
            if (key_pressed < CAM_EMUL_KEYPRESS_DELAY)
            {
                if (!kbd_blocked) 
                    enter_alt();
                else
                    exit_alt();
            }
            key_pressed = 0;
            return 1;
        }
        return 1;
    }
       
    // auto iso shift
    if (camera_info.state.is_shutter_half_press && kbd_is_key_pressed(conf.alt_mode_button)) 
        return 0;

    if (kbd_is_key_pressed(conf.alt_mode_button)) 
	{
        key_pressed = 1;
        kbd_key_release_all();          
        return 1;
    }

#ifdef CAM_TOUCHSCREEN_UI
    extern int ts_process_touch();
    if (ts_process_touch())
    {
        gui_set_need_restore();
    }
#endif

    // deals with the rest

    if ( !kbd_blocked || usb_remote_active ) 
	{
		kbd_blocked = handle_usb_remote();
	}

    if (gui_kbd_process())
        return 1;

    action_stack_process_all();

    return kbd_blocked;
}
