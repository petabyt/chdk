/*
 *   THIS FILE IS FOR DECLARATION/LISTING OF EXPORTED TO MODULES SYMBOLS
 *
 *    CHDK-FLAT Module System.  Sergey Taranenko aka tsvstar
 */

#include "module_exportlist.h"
#include "lang.h"
#include "platform.h"
#include "stdlib.h"
#include "keyboard.h"

#include "gui.h"
#include "gui_draw.h"
#include "gui_batt.h"
#include "gui_osd.h"
#include "conf.h"
#include "gui_mbox.h"
#include "raw.h"
#include "gui_mpopup.h"
#include "bitvector.h"
#include "font.h"

#include "modules.h"
#include "raw.h"
#include "dng.h"


extern int fselect_sort_nothumb(const void* v1, const void* v2);
extern short shooting_get_ev_correction1();


// ATTENTION: DO NOT USE BRACES OR OWN /**/-STYLE COMMENTS ANYWHERE IN THIS FILE TO AVOID AUTO PARSING MISTAKES



// ** SECTION 1: DEFINE UNDECLARED EXPORTED ITEMS

#ifndef CAM_FIRMWARE_MEMINFO
#define GetMemInfo 0
#endif


// ** SECTION 2: IMPLEMENTATION OF EXPORTED #define VALUES
// 	  1. PLEASE DO NOT CHANGE START AND FINAL COMMENTS TO CORRECT AUTOPARSING

/* EXPORTED_DEFINES_BEGIN */

int CAM_CHDK_BLACK_LEVEL = CAM_BLACK_LEVEL;
int CAM_CHDK_WHITE_LEVEL = CAM_WHITE_LEVEL;
int CAM_CHDK_RAW_ROWS    = CAM_RAW_ROWS   ;
int CAM_CHDK_RAW_ROWPIX  = CAM_RAW_ROWPIX ;
int RAW_CHDK_ROWLEN      = RAW_ROWLEN     ;

/* EXPORTED_DEFINES_END */

// ** SECTION 3: LIST OF EXPORTED SYMBOLS (pointer to function/variable)
//    1. DO NOT CHANGE ORDER AND DO NOT DELETE EXISTED ENTRIES
//    2. VARIABLE conf SHOULDN'T EXIST IN THE LIST TO KEEP ISOLATION. USE set|get_chdk_conf|get_chdk_conf_ptr INSTEAD

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
            open,
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
            stat,
            opendir,
            readdir,
            closedir,

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

            &screen_width,
            &screen_height,
            &screen_buffer_size,
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
            &CAM_CHDK_BLACK_LEVEL,
            &CAM_CHDK_WHITE_LEVEL,
            &CAM_CHDK_RAW_ROWS,
            &CAM_CHDK_RAW_ROWPIX,
            &RAW_CHDK_ROWLEN,
            GetFreeCardSpaceKb,
            debug_led,
            gui_browser_progress_show,
        
        	// for edgeovr.flt
			vid_get_viewport_width,
			vid_get_viewport_buffer_width,
            vid_get_viewport_xoffset,
            vid_get_viewport_yoffset,
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
			convert_dng_to_chdk_raw,
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

			gui_bind_mode,

			0
};

/*			debug_open,
			debug_print_int,
			debug_print,
			debug_flush,
 			debug_close,
*/

