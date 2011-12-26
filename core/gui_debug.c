#include "stdlib.h"
#include "keyboard.h"
#include "platform.h"
#include "core.h"
#include "gui.h"
#include "gui_draw.h"
#include "gui_debug.h"
#include "conf.h"

#include "module_load.h"

extern void gui_module_menu_kbd_process();
int *conf_mem_view_addr_init;

gui_handler GUI_MODE_DEBUG = 
    /*GUI_MODE_DEBUG*/          { gui_debug_draw,       gui_debug_kbd_process,      gui_module_menu_kbd_process, 0, GUI_MODE_MAGICNUM };

//-------------------------------------------------------------------
static void *addr;
static char debug_to_draw;
static char debug_cont_update;
static char buf[32];
static long dummy=0;
static unsigned int step;

//-------------------------------------------------------------------
void gui_debug_init(void *st_addr) {
    addr = st_addr;
    debug_to_draw = 1;
    debug_cont_update = 1;
    step = 4;
    gui_set_mode((unsigned int)&GUI_MODE_DEBUG);
}

//-------------------------------------------------------------------
static void gui_debug_draw_values(const coord y, void* addr) {
    int i;

	// non-significant check. remove to platform independency
    // if (!(addr<=(void*)MAXRAMADDR || addr>=(void*)ROMBASEADDR)) { addr = &dummy; };

    sprintf(buf, "0x%08X (%10u)", *((unsigned int*)addr), *((unsigned int*)addr));
    draw_txt_string(10, y, buf, MAKE_COLOR(COLOR_BLACK, COLOR_WHITE));

    sprintf(buf, "0x%04X (%5hu)", *((unsigned short*)addr), *((unsigned short*)addr));
    draw_txt_string(10, y+1, buf, MAKE_COLOR(COLOR_BLACK, COLOR_WHITE));

    sprintf(buf, "0x%02X (%3hu)", *((unsigned char*)addr), *((unsigned char*)addr));
    draw_txt_string(10, y+2, buf, MAKE_COLOR(COLOR_BLACK, COLOR_WHITE));

    //sprintf(buf, "0x%lf", *((double*)addr));
    //draw_txt_string(10, y+3, buf, MAKE_COLOR(COLOR_BLACK, COLOR_WHITE));

    for (i=0; i<30; ++i) {
        if (*((char*)(addr+i))) buf[i]=*((char*)(addr+i));
        else break;
    }
    while (i<30) {
        buf[i++]=' ';
    }
    buf[i]=0;
    draw_txt_string(10, y+4, buf, MAKE_COLOR(COLOR_BLACK, COLOR_WHITE));
}

//-------------------------------------------------------------------
void gui_debug_draw(int enforce_redraw) {
    switch (debug_to_draw) {
        case 1:
            draw_filled_rect(0, 0, screen_width-1, screen_height-1, MAKE_COLOR(SCREEN_COLOR, SCREEN_COLOR));
            draw_txt_string(1, 0, "Address:", MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
            draw_txt_string(22, 0, "Incr:", MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
            draw_txt_string(39,0,  "Auto:", MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
            draw_txt_string(1, 1, "Values:",  MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
            draw_txt_string(2, 2, "DWORD  :", MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
            draw_txt_string(2, 3, "WORD   :", MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
            draw_txt_string(2, 4, "BYTE   :", MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
            draw_txt_string(2, 5, "DOUBLE :", MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
            draw_txt_string(2, 6, "STRING :", MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
            draw_txt_string(1, 7, "Dereferencing:",  MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
            draw_txt_string(2, 8, "DWORD  :", MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
            draw_txt_string(2, 9, "WORD   :", MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
            draw_txt_string(2, 10, "BYTE   :", MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
            draw_txt_string(2, 11, "DOUBLE :", MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
            draw_txt_string(2, 12, "STRING :", MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));

            debug_to_draw = 2;
            break;
        case 2:
            sprintf(buf, "0x%08X", addr);
            draw_txt_string(10, 0, buf, MAKE_COLOR(COLOR_BLACK, COLOR_WHITE));
            sprintf(buf, "0x%08X", step);
            draw_txt_string(28, 0, buf, MAKE_COLOR(COLOR_BLACK, COLOR_WHITE));
            sprintf(buf,"%0d",debug_cont_update);
            draw_txt_string(44, 0, buf, MAKE_COLOR(COLOR_BLACK, COLOR_WHITE));
            gui_debug_draw_values(2, addr);
            gui_debug_draw_values(8, *((void**)addr));
            *conf_mem_view_addr_init = (long)addr;

            if (debug_cont_update==0) debug_to_draw = 0;
            break;
        default:
            debug_to_draw = 0;
            break;
    }
}

//-------------------------------------------------------------------
void gui_debug_kbd_process() {
    switch (kbd_get_autoclicked_key()) {
    case KEY_DOWN:
        break;
    case KEY_UP:
        debug_cont_update = !debug_cont_update;
        debug_to_draw = 2;
        break;
    case KEY_LEFT:
        addr-=step;
        debug_to_draw = 2;
        break;
    case KEY_RIGHT:
        addr+=step;
        debug_to_draw = 2;
        break;
    case KEY_DISPLAY:
        switch (step) {
            case 0x00000004: step = 0x00000010; break;
            case 0x10000000: step = 0x00000004; break;
            default: step<<=4; break;
        }
        debug_to_draw = 2;
        break;
    case KEY_ZOOM_IN:    // reduce step
        switch (step) {
            case 0x00000010: step = 0x0000004; break;
            case 0x00000004: break;
            default: step>>=4; break;
        }
        debug_to_draw = 2;
        break;
    case KEY_ZOOM_OUT:    // increase step
        switch (step) {
            case 0x00000004: step = 0x00000010; break;
            case 0x10000000: break;
            default: step<<=4; break;
        }
        debug_to_draw = 2;
        break;
    }
}

//-------------------------------------------------------------------

extern int module_idx;
void gui_module_menu_kbd_process() {
	gui_default_kbd_process_menu_btn();
  	module_async_unload(module_idx);
}


// =========  MODULE INIT =================
#include "module_load.h"
int module_idx=-1;

/***************** BEGIN OF AUXILARY PART *********************
  ATTENTION: DO NOT REMOVE OR CHANGE SIGNATURES IN THIS SECTION
 **************************************************************/

void* MODULE_EXPORT_LIST[] = {
	/* 0 */	(void*)EXPORTLIST_MAGIC_NUMBER,
	/* 1 */	(void*)0
		};


//---------------------------------------------------------
// PURPOSE:   Bind module symbols with chdk. 
//		Required function
// PARAMETERS: pointer to chdk list of export
// RETURN VALUE: 1 error, 0 ok
//---------------------------------------------------------
int _module_loader( void** chdk_export_list )
{
  if ( (unsigned int)chdk_export_list[0] != EXPORTLIST_MAGIC_NUMBER )
     return 1;

  tConfigVal configVal;
  CONF_BIND_INT(195, conf_mem_view_addr_init);

  return 0;
}



//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{
  return 0;
}


//---------------------------------------------------------
// PURPOSE: Default action for simple modules (direct run)
// NOTE: Please comment this function if no default action and this library module
//---------------------------------------------------------
int _module_run(int moduleidx, int argn, int* arguments)
{
  module_idx=moduleidx;

  void* adr;

  if ( argn== 0 )
    adr =(char*)(*conf_mem_view_addr_init);
  else if ( argn ==1)
    adr = (char*)arguments[0]; 
  else {
	module_async_unload(moduleidx);
    return 1;
  }

  gui_debug_init(adr);

  return 0;
}


/******************** Module Information structure ******************/
#include "gui_lang.h"

struct ModuleInfo _module_info = {	MODULEINFO_V1_MAGICNUM,
									sizeof(struct ModuleInfo),

									ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
									ANY_PLATFORM_ALLOWED,		// Specify platform dependency
									0,							// flag
									-LANG_MENU_DEBUG_MEMORY_BROWSER,	// Module name
									1, 0,						// Module version
									(int32_t)"Simple memory content browser"
								 };

/*************** END OF AUXILARY PART *******************/
