/*
 *   THIS FILE IS FOR DECLARATION/LISTING OF EXPORTED TO MODULES SYMBOLS
 *
 *    CHDK-FLAT Module System.  Sergey Taranenko aka tsvstar
 */

#include "module_exportlist.h"
#include "lang.h"
#include "platform.h"
#include "stdlib.h"
#include "stdlib_unified.h"
#include "keyboard.h"

#include "gui.h"
#include "gui_draw.h"
#include "gui_batt.h"
#include "gui_menu.h"
#include "gui_osd.h"
#include "gui_mbox.h"
#include "gui_mpopup.h"
#include "conf.h"
#include "raw.h"
#include "bitvector.h"
#include "font.h"

#include "modules.h"
#include "module_load.h"
#include "raw.h"
#include "action_stack.h"
#include "console.h"


extern int fselect_sort_nothumb(const void* v1, const void* v2);
extern short shooting_get_ev_correction1();

extern long shutter_open_time; // defined in platform/generic/capt_seq.c


// ATTENTION: DO NOT USE BRACES OR OWN /**/-STYLE COMMENTS ANYWHERE IN THIS FILE TO AVOID AUTO PARSING MISTAKES



// ** SECTION 1: DEFINE UNDECLARED EXPORTED ITEMS

#ifndef CAM_FIRMWARE_MEMINFO
#define GetMemInfo 0
#endif


// ** SECTION 2: IMPLEMENTATION OF EXPORTED #define VALUES
// 	  1. PLEASE DO NOT CHANGE START AND FINAL COMMENTS TO CORRECT AUTOPARSING

/* EXPORTED_DEFINES_BEGIN */

char SCREEN__EXPORTEDSYM_COLOR        = SCREEN_COLOR		;
char COLOR__EXPORTEDSYM_WHITE         = COLOR_WHITE         ;
char COLOR__EXPORTEDSYM_RED           = COLOR_RED           ;
char COLOR__EXPORTEDSYM_GREY          = COLOR_GREY          ;
char COLOR__EXPORTEDSYM_GREEN         = COLOR_GREEN         ;
char COLOR__EXPORTEDSYM_BLUE_LT       = COLOR_BLUE_LT       ;
char COLOR__EXPORTEDSYM_BLUE          = COLOR_BLUE          ;
char COLOR__EXPORTEDSYM_YELLOW        = COLOR_YELLOW        ;
char COLOR__EXPORTEDSYM_BG            = COLOR_BG            ;
char COLOR__EXPORTEDSYM_FG            = COLOR_FG            ;
char COLOR__EXPORTEDSYM_SELECTED_BG   = COLOR_SELECTED_BG   ;
char COLOR__EXPORTEDSYM_SELECTED_FG   = COLOR_SELECTED_FG   ;
char COLOR__EXPORTEDSYM_ALT_BG        = COLOR_ALT_BG        ;
char COLOR__EXPORTEDSYM_SPLASH_RED    = COLOR_SPLASH_RED    ;
char COLOR__EXPORTEDSYM_SPLASH_PINK   = COLOR_SPLASH_PINK   ;
char COLOR__EXPORTEDSYM_SPLASH_GREY   = COLOR_SPLASH_GREY   ;
char COLOR__EXPORTEDSYM_HISTO_R       = COLOR_HISTO_R       ;
char COLOR__EXPORTEDSYM_HISTO_R_PLAY  = COLOR_HISTO_R_PLAY  ;
char COLOR__EXPORTEDSYM_HISTO_B       = COLOR_HISTO_B       ;
char COLOR__EXPORTEDSYM_HISTO_G       = COLOR_HISTO_G       ;
char COLOR__EXPORTEDSYM_HISTO_G_PLAY  = COLOR_HISTO_G_PLAY  ;
char COLOR__EXPORTEDSYM_HISTO_BG      = COLOR_HISTO_BG      ;
char COLOR__EXPORTEDSYM_HISTO_RG      = COLOR_HISTO_RG      ;
char COLOR__EXPORTEDSYM_HISTO_RB      = COLOR_HISTO_RB      ;
char COLOR__EXPORTEDSYM_HISTO_RB_PLAY = COLOR_HISTO_RB_PLAY ;
char COLOR__EXPORTEDSYM_HISTO_B_PLAY  = COLOR_HISTO_B_PLAY  ;
char COLOR__EXPORTEDSYM_HISTO_BG_PLAY = COLOR_HISTO_BG_PLAY ;
char COLOR__EXPORTEDSYM_HISTO_RG_PLAY = COLOR_HISTO_RG_PLAY ;


/* EXPORTED_DEFINES_END */

// ** SECTION 3: LIST OF EXPORTED SYMBOLS (pointer to function/variable)
//    1. DO NOT CHANGE ORDER AND DO NOT DELETE EXISTED ENTRIES
//    2. VARIABLE conf SHOULDN'T EXIST IN THE LIST TO KEEP ISOLATION. USE set|get_chdk_conf|get_chdk_conf_ptr INSTEAD
//	STOPLIST: conf, open, opendir, closedir, rewinddir, readdir, stat

void* CHDK_EXPORT_LIST[] = {
            (void*)EXPORTLIST_MAGIC_NUMBER,
            (void*)EXPORTLIST_LAST_IDX,
			module_async_unload,
			module_set_flags,
			conf_getValue,
			module_run,

            malloc,
            free,
            umalloc,
            ufree,
            safe_open,
            write,
            lseek,
            close,
            read,
            remove,
            rename,
            fopen,
            fclose,
            fseek,
            fread,
            fwrite,
            safe_stat,
            safe_opendir,
            safe_readdir,
            safe_closedir,

            get_tick_count,
			time,
            utime,
			localtime,
            rand,
			srand,

            lang_str,
            sprintf,
			strlen,
			strcpy,
            strncmp,
            strpbrk,
            strchr,
			strcmp,
            memcpy,

            draw_txt_string,
			draw_string,
			draw_rect,
            draw_filled_rect,
 			draw_filled_ellipse,
			draw_filled_round_rect,
			draw_line,
			draw_char,

            gui_get_mode,
            gui_set_mode,
			gui_default_kbd_process_menu_btn,

            vid_get_viewport_fb,
            vid_get_viewport_height,
            vid_get_bitmap_fb,
            hook_raw_image_addr,
            hook_raw_size,
            kbd_get_autoclicked_key,

			get_batt_perc,
			gui_osd_draw_clock,
			gui_mbox_init,

			// for rawop.flt
            GetFreeCardSpaceKb,
            debug_led,
            gui_browser_progress_show,
        
        	// for edgeovr.flt
			vid_get_viewport_width,
            vid_get_viewport_byte_width,
            vid_get_viewport_xoffset,
            vid_get_viewport_yoffset,
            vid_get_viewport_yscale,
            vid_get_viewport_fb_d,
            kbd_is_key_pressed,
            bv_create,
            bv_get,
            bv_set,
            bv_free,
            draw_get_pixel,
            draw_pixel,
            draw_restore,
            memset,
			mode_get,
            shooting_get_zoom,
            shooting_set_zoom,

			// for txtread.flt
            draw_txt_char,
            rbf_char_width,
            rbf_font_height,
            rbf_draw_char,
            rbf_load,
            current_font,
            rbf_load_from_8x16,
            rbf_set_codepage,
            get_jogdial_direction,

			// for palette.flt
			draw_rect_thick,
			draw_filled_rect_thick,

			// for modinsp.flt
			module_get_adr,
			module_async_unload_allrunned,
			GetMemInfo,

			// for fselect.flt
			module_rawop_load,
            module_rawop_unload,
            module_mpopup_init,
            qsort,
            img_prefixes,
            img_exts,
            strrchr,
            strncpy,
			msleep,
            GetTotalCardSpaceKb,
			module_convert_dng_to_chdk_raw,
			raw_prepare_develop,

			// curves.flt			
			get_raw_image_addr,
			shooting_get_ev_correction1,

			// mpopup.flt			
            draw_rect_shadow,
			kbd_get_clicked_key,
			kbd_reset_autoclicked_key,

			// tetris.flt
			TurnOnBackLight,
			TurnOffBackLight,
			mkdir,

			// modlist.flt
			load_from_file,
			rbf_draw_string_len,
			rbf_draw_menu_header,
			gui_force_restore,

			// modmenu.flt
			gui_menu_run_fltmodule,

			// export palette
			&SCREEN__EXPORTEDSYM_COLOR		 ,
			&COLOR__EXPORTEDSYM_WHITE        ,
			&COLOR__EXPORTEDSYM_RED          ,
			&COLOR__EXPORTEDSYM_GREY         ,
			&COLOR__EXPORTEDSYM_GREEN        ,
			&COLOR__EXPORTEDSYM_BLUE_LT      ,
			&COLOR__EXPORTEDSYM_BLUE         ,
			&COLOR__EXPORTEDSYM_YELLOW       ,
			&COLOR__EXPORTEDSYM_BG           ,
			&COLOR__EXPORTEDSYM_FG           ,
			&COLOR__EXPORTEDSYM_SELECTED_BG  ,
			&COLOR__EXPORTEDSYM_SELECTED_FG  ,
			&COLOR__EXPORTEDSYM_ALT_BG       ,
			&COLOR__EXPORTEDSYM_SPLASH_RED   ,
			&COLOR__EXPORTEDSYM_SPLASH_PINK  ,
			&COLOR__EXPORTEDSYM_SPLASH_GREY  ,
			&COLOR__EXPORTEDSYM_HISTO_R      ,
			&COLOR__EXPORTEDSYM_HISTO_R_PLAY ,
			&COLOR__EXPORTEDSYM_HISTO_B      ,
			&COLOR__EXPORTEDSYM_HISTO_G      ,
			&COLOR__EXPORTEDSYM_HISTO_G_PLAY ,
			&COLOR__EXPORTEDSYM_HISTO_BG     ,
			&COLOR__EXPORTEDSYM_HISTO_RG     ,
			&COLOR__EXPORTEDSYM_HISTO_RB     ,
			&COLOR__EXPORTEDSYM_HISTO_RB_PLAY,
			&COLOR__EXPORTEDSYM_HISTO_B_PLAY ,
			&COLOR__EXPORTEDSYM_HISTO_BG_PLAY,
			&COLOR__EXPORTEDSYM_HISTO_RG_PLAY,

			// profile.flt
			find_mnu,
			lang_strhash31,

			action_stack_create,
			action_pop,
			action_push,
			action_push_delay,
			action_stack_standard,
			console_clear,
			console_add_line,
			shooting_set_tv96_direct,
			shooting_get_iso_market,
			get_focal_length,
			get_effective_focal_length,
			get_parameter_data,
			get_property_case,
			&shutter_open_time,
			get_raw_pixel,
			&state_shooting_progress,
			patch_bad_pixel,
			
			pow_calc,
			pow_calc_2,

            &camera_info,
            &camera_screen,
            &camera_sensor,
            &altGuiHandler,
            &gui_version,
			0
};
