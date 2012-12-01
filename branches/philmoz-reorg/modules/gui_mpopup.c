#include "stdlib.h"
#include "keyboard.h"
#include "platform.h"
#include "core.h"
#include "lang.h"
#include "gui.h"
#include "gui_draw.h"
#include "gui_lang.h"
#include "gui_mpopup.h"

#include "module_load.h"

extern int module_idx;

/*
	History:	1.1 - make possible call next mpopup in callback [multilevel mpopups]
				1.2 - allow to use MPOPUP_CANCEL item in the list
*/

int gui_mpopup_kbd_process();
void gui_mpopup_kbd_process_menu_btn();
void gui_mpopup_draw(int enforce_redraw);

gui_handler GUI_MODE_MPOPUP_MODULE = 
    /*GUI_MODE_MPOPUP*/ { GUI_MODE_MPOPUP, gui_mpopup_draw, gui_mpopup_kbd_process, gui_mpopup_kbd_process_menu_btn, GUI_MODE_FLAG_NORESTORE_ON_SWITCH, GUI_MODE_MAGICNUM };

// Simple popup menu. No title, no separators, only processing items

//-------------------------------------------------------------------
static gui_handler              *gui_mpopup_mode_old;
static char                     mpopup_to_draw;

#define MAX_ACTIONS             10

struct mpopup_item* actions;

static int                      mpopup_actions[MAX_ACTIONS];    // Content of raised popupmenu
static int                      mpopup_actions_num;             // Num of items in raised popupmenu
static int                      mpopup_actions_active;          // Idx of current item (cursor)
static coord                    mpopup_actions_x, mpopup_actions_y;    // top-left coord of window
static unsigned int             mpopup_actions_w;               // width of window

typedef void (*mpopup_on_select_t)(unsigned int btn);
static mpopup_on_select_t mpopup_on_select;

//-------------------------------------------------------------------
void gui_mpopup_init(struct mpopup_item* popup_actions, const unsigned int flags, void (*on_select)(unsigned int actn), int mode) 
{
    int i;

    mpopup_actions_num = 0;
    actions = popup_actions;
    for (i=0; actions[i].flag && mpopup_actions_num<MAX_ACTIONS; ++i) {
        if (flags & MPOPUP_MASK & actions[i].flag)
            mpopup_actions[mpopup_actions_num++] = i;
		else if ( actions[i].flag==MPOPUP_CANCEL )
			mpopup_actions[mpopup_actions_num++] = i;
    }
    if (mpopup_actions_num == 0) {
        on_select(MPOPUP_CANCEL);
		return;
	}

    mpopup_actions_active = 0;

    mpopup_to_draw = 1;
    mpopup_on_select = on_select;
    gui_mpopup_mode_old = gui_set_mode(&GUI_MODE_MPOPUP_MODULE);
}

//-------------------------------------------------------------------
unsigned int gui_mpopup_result() {
    return actions[mpopup_actions[mpopup_actions_active]].flag;
}

//-------------------------------------------------------------------
static void gui_mpopup_draw_actions() {
    int i;
    coord y = mpopup_actions_y;
    color cl;

    for (i=0; i<mpopup_actions_num; ++i) {
        cl = MAKE_COLOR((mpopup_actions_active==i)?COLOR_RED:COLOR_GREY, (mpopup_actions_active==i)?COLOR_RED:COLOR_GREY);
        draw_filled_rect(mpopup_actions_x, y, mpopup_actions_x+mpopup_actions_w*FONT_WIDTH, y+FONT_HEIGHT-1, cl);
        cl = MAKE_COLOR((mpopup_actions_active==i)?COLOR_RED:COLOR_GREY, COLOR_WHITE);
        draw_string(mpopup_actions_x+FONT_WIDTH, y, lang_str(actions[mpopup_actions[i]].text), cl);
        y+=FONT_HEIGHT;
    }
}

//-------------------------------------------------------------------
void gui_mpopup_draw(int enforce_redraw) {
    if (mpopup_to_draw) {
        int i;
        coord x=0, y=0;
        unsigned int w, h;

        w = 0;
        for (i=0; i<mpopup_actions_num; ++i) {
            h=strlen(lang_str(actions[mpopup_actions[i]].text));
            if (h > w) w=h;
        }
        w+=2;
        h = mpopup_actions_num;
    
        x = 10*FONT_WIDTH;
        y = 5*FONT_HEIGHT;
        draw_rect_shadow(x-3, y-3, x+w*FONT_WIDTH+5, y+h*FONT_HEIGHT+4, COLOR_BLACK, 3); //shadow
        draw_filled_rect_thick(x-4, y-4, x+w*FONT_WIDTH+4, y+h*FONT_HEIGHT+3, MAKE_COLOR(COLOR_GREY, COLOR_WHITE), 3); // main box
    
        mpopup_actions_x = x;
        mpopup_actions_y = y;
        mpopup_actions_w = w;

        gui_mpopup_draw_actions();
        mpopup_to_draw = 0;
    }
}

//-------------------------------------------------------------------
void exit_mpopup(int action)
{
    gui_set_mode(gui_mpopup_mode_old);

	mpopup_on_select_t on_select = mpopup_on_select;	// this could be reinited in callback

	mpopup_on_select=0;
    if (on_select) 
        on_select(action);
}

//-------------------------------------------------------------------
void gui_mpopup_kbd_process_menu_btn()
{
    kbd_reset_autoclicked_key();
	exit_mpopup(MPOPUP_CANCEL);		
	if ( mpopup_on_select==0 )		// exit if not re-inited
		module_async_unload(module_idx);
}

int gui_mpopup_kbd_process()
{
    switch (kbd_get_clicked_key() | get_jogdial_direction()) {
    case JOGDIAL_LEFT:
    case KEY_UP:
        if (mpopup_actions_active > 0) --mpopup_actions_active;
        else mpopup_actions_active = mpopup_actions_num-1;
        gui_mpopup_draw_actions();
        break;
    case JOGDIAL_RIGHT:
    case KEY_DOWN:
        if (mpopup_actions_active < mpopup_actions_num-1) ++mpopup_actions_active;
        else mpopup_actions_active = 0;
        gui_mpopup_draw_actions();
        break;
    case KEY_LEFT:
        gui_mpopup_kbd_process_menu_btn();
        break;
    case KEY_SET:
        kbd_reset_autoclicked_key();
		exit_mpopup(actions[mpopup_actions[mpopup_actions_active]].flag);		
		if ( mpopup_on_select==0 )		// exit if not re-inited
		module_async_unload(module_idx);
        break;
    }
    return 0;
}

//-------------------------------------------------------------------

// =========  MODULE INIT =================

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
    if (mpopup_on_select) 
        mpopup_on_select(MPOPUP_CANCEL);

	//sanity clean to prevent accidentaly assign/restore guimode to unloaded module 
	GUI_MODE_MPOPUP_MODULE.magicnum = 0;

    return 0;
}


//---------------------------------------------------------
// PURPOSE: Default action for simple modules (direct run)
// NOTE: Please comment this function if no default action and this library module
//---------------------------------------------------------
int _module_run(int moduleidx, int argn, int* arguments)
{
  module_idx=moduleidx;

  if ( argn!=4) {
	module_async_unload(moduleidx);
    return 1;
  }

  // Currently only old (0) mode is supported
  // This is for load error if newer version is required
  if (arguments[3]!=0)
		return 1;

  gui_mpopup_init( (struct mpopup_item*)arguments[0], (const unsigned int)arguments[1], (void*) arguments[2], arguments[3]);
  

  return 0;
}


/******************** Module Information structure ******************/

struct ModuleInfo _module_info = {	MODULEINFO_V1_MAGICNUM,
									sizeof(struct ModuleInfo),

									ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
									ANY_PLATFORM_ALLOWED,		// Specify platform dependency
									MODULEINFO_FLAG_SYSTEM,		// flag
									(int32_t)"Popup menu module",		// Module name
									1, 2,						// Module version
									0
								 };

/*************** END OF AUXILARY PART *******************/
