#include "../module_load.h"
#include "../gui_draw.h"
#include "../module_exportlist.h"


// =========  MODULE INIT =================

int module_idx=-1;

extern int basic_module_init();

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
int _module_loader( unsigned int* chdk_export_list )
{
  if ( chdk_export_list[0] != EXPORTLIST_MAGIC_NUMBER )
     return 1;

  if ( !API_VERSION_MATCH_REQUIREMENT( gui_version.common_api, 1, 0 ) )
	  return 1;

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

  basic_module_init();
  return 0;
}

/******************** Module Information structure ******************/

struct ModuleInfo _module_info = {	MODULEINFO_V1_MAGICNUM,
									sizeof(struct ModuleInfo),

									ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
									ANY_PLATFORM_ALLOWED,		// Specify platform dependency
									0,							// flag
									(int32_t)"Module Inspector",// Module name
									1, 0,						// Module version
									(int32_t)"Show list of loaded modules"
								 };


/*************** END OF AUXILARY PART *******************/




/*************** GUI MODULE *******************/

#include "../flt.h"
#include "../gui_mbox.h"
#include "keyboard.h"
#include "stdlib.h"
#include "platform.h"


void gui_module_menu_kbd_process();
void gui_module_kbd_process();
void gui_module_draw();

gui_handler GUI_MODE_MODULE_INSPECTOR = 
    /*GUI_MODE_MODULE_INSPECTOR*/   { GUI_MODE_MODULE,   gui_module_draw,       gui_module_kbd_process,      gui_module_menu_kbd_process, 0, GUI_MODE_MAGICNUM };


int modinspect_redraw;
gui_handler *modinspect_old_guimode;

static void modinspect_unload_cb(unsigned int btn) {
    if (btn==MBOX_BTN_YES) {
		module_async_unload_allrunned(0);
        gui_set_mode(modinspect_old_guimode);	// if core gui - return to it
    }
    modinspect_redraw=2;
}


void gui_module_kbd_process() {
    switch (kbd_get_autoclicked_key()) {
    	case KEY_SET:
        	modinspect_redraw=2;
        	break;
    	case KEY_DISPLAY:
                gui_mbox_init( (int)"Module Inspector", (int)"Unload all modules?",
                              MBOX_TEXT_CENTER|MBOX_BTN_YES_NO|MBOX_DEF_BTN2, modinspect_unload_cb);
			break;
    }
}

//-------------------------------------------------------------------

int basic_module_init() {
	modinspect_redraw=2;
    modinspect_old_guimode = gui_set_mode(&GUI_MODE_MODULE_INSPECTOR);
	return 1;
}

extern int module_idx;

void gui_module_menu_kbd_process() {
	gui_set_mode(modinspect_old_guimode);
  	module_async_unload(module_idx);
}

static void gui_mem_info(char *typ, cam_meminfo *meminfo, int showidx)
{
    char txt[50];
    sprintf(txt,"%-5s: %08x-%08x: %d",typ,meminfo->start_address, meminfo->end_address, meminfo->total_size);
    draw_txt_string(0, 5+showidx,  txt,       MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
	sprintf(txt,"alloc: now=%d(%d) max=%d", meminfo->allocated_size, meminfo->allocated_count, meminfo->allocated_peak);
    draw_txt_string(0, 6+showidx,  txt,       MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
	sprintf(txt,"free:  now=%d(%d) max=%d", meminfo->free_size, meminfo->free_block_count, meminfo->free_block_max_size);
    draw_txt_string(0, 7+showidx,  txt,       MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
}

void gui_module_draw()
{
    int idx, showidx;

    if (modinspect_redraw) {

    	draw_filled_rect(0, 0, camera_screen.width-1, camera_screen.height-1, MAKE_COLOR(SCREEN_COLOR, SCREEN_COLOR));
        draw_txt_string(5, 0,  "*** Module Inspector ***", MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
        draw_txt_string(0, 2,  "Idx Name         Addr       Size", MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));

		showidx=0;
		for ( idx=0; idx<20; idx++)
		{
			struct flat_hdr* flat = module_get_adr(idx);
			if (flat==0) continue;

			char namebuf[12];
			memcpy(namebuf,flat->modulename,11);
			namebuf[11]=0;

			char txt[50];
		    sprintf(txt,"%02d: %-12s %08x - %d bytes", idx, namebuf, (unsigned)flat, flat->reloc_start);
        	draw_txt_string(0, 3+showidx,  txt,       MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));
			showidx++;
		}

//    sprintf(buf, lang_str(LANG_MSG_MEMORY_INFO_TEXT), core_get_free_memory(), MEMISOSIZE, &_start, &_end);
//		sprintf(buf,"MEM     %08x-%08x - %d free",&_start, &_end,core_get_free_memory());
//		sprintf(buf,"--- %-12s %08x - %d","CHDK",&_start, MEMISOSIZE );

        draw_txt_string(1, 4+showidx,  "SET-redraw, DISP-unload_all, MENU-exit",       MAKE_COLOR(SCREEN_COLOR, COLOR_WHITE));

    	cam_meminfo meminfo;

        // Display Canon heap memory info
        // amount of data displayed may vary depending on GetMemInfo implementation
        memset(&meminfo,0,sizeof(meminfo));
        GetMemInfo(&meminfo);
        gui_mem_info("MEM", &meminfo, showidx);
        showidx += 3;

        // Display EXMEM memory info (only if enabled)
        memset(&meminfo,0,sizeof(meminfo));
        if (GetExMemInfo(&meminfo))
        {
            gui_mem_info("EXMEM", &meminfo, showidx);
		}
	}

	modinspect_redraw = 0;
}

