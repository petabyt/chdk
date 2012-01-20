#include "kbd.h"
#include "stdlib.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "conf.h"
#include "action_stack.h"
#include "camera.h"
#include "histogram.h"
#include "gui_lang.h"
#include "console.h"
#include "lang.h"
#include "gui_lang.h"

#include "module_load.h"
#include "gui.h"

long kbd_last_clicked;
int state_kbd_script_run;

int kbd_blocked;
static long delay_target_ticks;
static int soft_half_press = 0;
static int key_pressed;

int shutter_int=0;
extern int usb_remote_active ;

#ifdef OPT_SCRIPTING
// remote autostart
void script_autostart()
{
    kbd_blocked = 1;
    gui_kbd_enter();
    console_clear();
    script_console_add_line("***Autostart***"); //lang_str(LANG_CONSOLE_TEXT_STARTED));
    script_start_gui( 1 );
}
#endif

void exit_alt()
{
    kbd_blocked = 0;
    gui_kbd_leave();
}

/*
    main kb processing
 */
long kbd_process()
{
	// Alternative keyboard mode stated/exited by pressing print key.
	// While running Alt. mode shoot key will start a script execution.

	// alt-mode switch and delay emulation
 
	if ( key_pressed  && !usb_remote_active ) 
	{
        if (kbd_is_key_pressed(conf.alt_mode_button)
                || ((key_pressed >= CAM_EMUL_KEYPRESS_DELAY)
                && (key_pressed < CAM_EMUL_KEYPRESS_DELAY+CAM_EMUL_KEYPRESS_DURATION))) {
            if (key_pressed <= CAM_EMUL_KEYPRESS_DELAY+CAM_EMUL_KEYPRESS_DURATION)
                key_pressed++;
            if (key_pressed == CAM_EMUL_KEYPRESS_DELAY)
                kbd_key_press(conf.alt_mode_button);
            else if (key_pressed == +CAM_EMUL_KEYPRESS_DELAY+CAM_EMUL_KEYPRESS_DURATION)
                kbd_key_release(conf.alt_mode_button);
            return 1;
        } else if (kbd_get_pressed_key() == 0) {
            if (key_pressed != 100 && (key_pressed < CAM_EMUL_KEYPRESS_DELAY)) {
                kbd_blocked = 1-kbd_blocked;
                if (kbd_blocked)
                    gui_kbd_enter();
                else
                    gui_kbd_leave();
            }
            key_pressed = 0;
            return 1;
        }
        return 1;
    }

    // auto iso shift

    if (kbd_is_key_pressed(KEY_SHOOT_HALF) && kbd_is_key_pressed(conf.alt_mode_button))
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
        extern void draw_restore();
        draw_restore();
    }
#endif

    // deals with the rest

    if ( kbd_blocked && !usb_remote_active ) 
	{
#ifdef OPT_SCRIPTING
		// Start or stop a script if the shutter button pressed in <ALT> mode (kdb_blocked) or USB remote sequence running
		// Note: this is blocked if CHDK is in the file selector. prevents problems
		//       when the file selector is called from a script.
		
        if (kbd_is_key_pressed(KEY_SHOOT_FULL) && (gui_get_mode() != GUI_MODE_FSELECT) && (gui_get_mode() != GUI_MODE_MPOPUP)) 
		{
            key_pressed = 100;
            if (!state_kbd_script_run) {
                script_start_gui(0);
            } else if (state_kbd_script_run == 2 || state_kbd_script_run == 3) {
                script_console_add_line(lang_str(LANG_CONSOLE_TEXT_INTERRUPTED));
                script_end();
            }
#ifdef OPT_LUA
            else if (L) {
                state_kbd_script_run = 2;
				lua_run_restore();
                script_console_add_line(lang_str(LANG_CONSOLE_TEXT_INTERRUPTED));
                script_end();
            }
#endif
#ifdef OPT_UBASIC
            else {
                state_kbd_script_run = 2;
                if (jump_label("restore") == 0) {
                    script_console_add_line(lang_str(LANG_CONSOLE_TEXT_INTERRUPTED));
                    script_end();
                }
            }
#endif
        }
#endif
        action_stack_process_all();
		if (!state_kbd_script_run) gui_kbd_process();
    }
	else
	{
		kbd_blocked = handle_usb_remote() ;
	    action_stack_process_all();
		
#ifdef CAM_USE_ZOOM_FOR_MF
		if (conf.use_zoom_mf && kbd_use_zoom_as_mf()) return 1;
#endif 

		if (	(conf.fast_ev || conf.fast_movie_control || conf.fast_movie_quality_control)
			&&	kbd_use_up_down_left_right_as_fast_switch()) return 1;
		
		other_kbd_process();   // processed other keys in not <alt> mode
	}

    return kbd_blocked;
}

int kbd_is_blocked() {
	return kbd_blocked;
}

void kbd_set_block(int bEnableBlock) {
    kbd_blocked = bEnableBlock ? 1 : 0;
}

long kbd_use_up_down_left_right_as_fast_switch() {
    static long key_pressed = 0; // ??? static masking a global
    int m=mode_get();
    int mode_video = MODE_IS_VIDEO(m) || (movie_status > 1);
    int ev_video=0;
    int jogdial;

#if CAM_EV_IN_VIDEO
    ev_video=get_ev_video_avail();
#endif

    if (!(kbd_is_key_pressed(KEY_UP)) && !(kbd_is_key_pressed(KEY_DOWN))) key_pressed = 0;

    if (canon_shoot_menu_active!=0 || (m&MODE_MASK) != MODE_REC)
        return 0;

#if !CAM_HAS_JOGDIAL
    if (kbd_is_key_pressed(KEY_UP) && ((m&MODE_SHOOTING_MASK) != MODE_M) && !mode_video) {
        if (conf.fast_ev && key_pressed == 0) {
            shooting_set_prop(PROPCASE_EV_CORRECTION_1,shooting_get_prop(PROPCASE_EV_CORRECTION_1)+(conf.fast_ev_step+1)*16);
            shooting_set_prop(PROPCASE_EV_CORRECTION_2,shooting_get_prop(PROPCASE_EV_CORRECTION_2)+(conf.fast_ev_step+1)*16);
            EnterToCompensationEVF();
            key_pressed = KEY_UP;

            return 1;
        }

    }

    if (kbd_is_key_pressed(KEY_DOWN) && ((m&MODE_SHOOTING_MASK) != MODE_M) && !mode_video) {
        if (conf.fast_ev && key_pressed == 0) {
            kbd_key_release_all();
            shooting_set_prop(PROPCASE_EV_CORRECTION_1,shooting_get_prop(PROPCASE_EV_CORRECTION_1)-(conf.fast_ev_step+1)*16);
            shooting_set_prop(PROPCASE_EV_CORRECTION_2,shooting_get_prop(PROPCASE_EV_CORRECTION_2)-(conf.fast_ev_step+1)*16);
            key_pressed = KEY_DOWN;
            EnterToCompensationEVF();
            return 1;
        }
    }

#else
    jogdial=get_jogdial_direction();

    if (conf.fast_ev &&kbd_is_key_pressed(KEY_SHOOT_HALF) && (jogdial==JOGDIAL_RIGHT) && ((m&MODE_SHOOTING_MASK) != MODE_M) && !mode_video) {
            shooting_set_prop(PROPCASE_EV_CORRECTION_1,shooting_get_prop(PROPCASE_EV_CORRECTION_1)+(conf.fast_ev_step+1)*16);
            shooting_set_prop(PROPCASE_EV_CORRECTION_2,shooting_get_prop(PROPCASE_EV_CORRECTION_2)+(conf.fast_ev_step+1)*16);
            EnterToCompensationEVF();
        }

    if (conf.fast_ev &&kbd_is_key_pressed(KEY_SHOOT_HALF) && (jogdial==JOGDIAL_LEFT) && ((m&MODE_SHOOTING_MASK) != MODE_M) && !mode_video) {
            shooting_set_prop(PROPCASE_EV_CORRECTION_1,shooting_get_prop(PROPCASE_EV_CORRECTION_1)-(conf.fast_ev_step+1)*16);
            shooting_set_prop(PROPCASE_EV_CORRECTION_2,shooting_get_prop(PROPCASE_EV_CORRECTION_2)-(conf.fast_ev_step+1)*16);
            EnterToCompensationEVF();
        }


#endif

    if (kbd_is_key_pressed(KEY_UP) && mode_video && movie_status == 4 ) {
        if (conf.fast_movie_quality_control && key_pressed == 0) {
            if (conf.video_mode==0) {
#if !CAM_VIDEO_QUALITY_ONLY
                conf.video_bitrate+=1;
                if (conf.video_bitrate>=VIDEO_BITRATE_STEPS)
                    conf.video_bitrate=VIDEO_BITRATE_STEPS-1;
                shooting_video_bitrate_change(conf.video_bitrate);
                movie_reset = 1;
#endif
            }
            else if (conf.video_mode==1) {
                conf.video_quality+=1;
                if (conf.video_quality>VIDEO_MAX_QUALITY)
                    conf.video_quality=VIDEO_MAX_QUALITY;
                movie_reset = 1;
            }
            key_pressed = KEY_UP;
            return 1;
        }
    }

    if (kbd_is_key_pressed(KEY_DOWN) && mode_video && movie_status == 4) {
        if (conf.fast_movie_quality_control && key_pressed == 0) {
            if (conf.video_mode==0) {
#if !CAM_VIDEO_QUALITY_ONLY
                conf.video_bitrate-=1;
                if (conf.video_bitrate<0)
                    conf.video_bitrate=0;

                shooting_video_bitrate_change(conf.video_bitrate);
                movie_reset = 1;
#endif
            }
            else if (conf.video_mode==1) {
                conf.video_quality-=1;
                if (conf.video_quality<1)
                    conf.video_quality=1;
                movie_reset = 1;
            }
            key_pressed = KEY_DOWN;
            return 1;
        }
    }

    if (kbd_is_key_pressed(KEY_LEFT) && mode_video && (movie_status == 4) && !ev_video) {
        if (conf.fast_movie_control && key_pressed == 0) {
            movie_status = VIDEO_RECORD_STOPPED;
            key_pressed = KEY_LEFT;
            return 1;
        }
    }
	// reyalp - HACK for cams that can do video in any mode
	// note that this means this will probably run whenever you press right
    if (kbd_is_key_pressed(KEY_RIGHT) &&
#ifndef CAM_HAS_VIDEO_BUTTON
            mode_video &&
#endif
	        (movie_status == 1) && !ev_video) {
        // BUG this doesn't know whether recording was stopped or paused.
        if (conf.fast_movie_control && key_pressed == 0) {
            movie_status = VIDEO_RECORD_IN_PROGRESS;
            movie_reset = 1;
            key_pressed = KEY_RIGHT;
            return 1;
        }
    }

    return 0;
}
