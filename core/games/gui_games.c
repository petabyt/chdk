#include "stdlib.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "gui.h"
#include "gui_menu.h"
#include "gui_lang.h"

#include "modules.h"

//-------------------------------------------------------------------

static CMenuItem games_submenu_items[] = {
    MENU_ITEM(0x38,LANG_MENU_GAMES_REVERSI,           MENUITEM_PROC,  gui_menu_run_fltmodule, "reversi.flt" ),
    MENU_ITEM(0x38,LANG_MENU_GAMES_SOKOBAN,           MENUITEM_PROC,  gui_menu_run_fltmodule, "sokoban.flt" ),
    MENU_ITEM(0x38,LANG_MENU_GAMES_CONNECT4,          MENUITEM_PROC,  gui_menu_run_fltmodule, "4wins.flt" ),
    MENU_ITEM(0x38,LANG_MENU_GAMES_MASTERMIND,        MENUITEM_PROC,  gui_menu_run_fltmodule, "mastmind.flt" ),
    MENU_ITEM(0x38,"Snake" ,                          MENUITEM_PROC,  gui_menu_run_fltmodule, "snake.flt" ),
    MENU_ITEM(0x38,"Tetris",                          MENUITEM_PROC,  gui_menu_run_fltmodule, "tetris.flt" ),
	MENU_ITEM(0x38,"Sudoku",						  MENUITEM_PROC,  gui_menu_run_fltmodule, "sudoku.flt" ),
    MENU_ITEM(0x51,LANG_MENU_BACK,                    MENUITEM_UP, 0, 0 ),
    {0}
};
static CMenu games_submenu = {0x38,LANG_MENU_GAMES_TITLE, NULL, games_submenu_items };

// =========  MODULE INIT =================

#include "module_load.h"

struct libgrids_sym libgrids = {
			MAKE_API_VERSION(1,0),		// apiver: increase major if incompatible changes made in module, 
										// increase minor if compatible changes made(including extending this struct)
};

int module_idx=-1;

/***************** BEGIN OF AUXILARY PART *********************
  ATTENTION: DO NOT REMOVE OR CHANGE SIGNATURES IN THIS SECTION
 **************************************************************/

void* MODULE_EXPORT_LIST[] = {
	/* 0 */	(void*)EXPORTLIST_MAGIC_NUMBER,
	/* 1 */	(void*)0,
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

  if ( !API_VERSION_MATCH_REQUIREMENT( conf.api_version, 2, 0 ) )
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

  gui_activate_sub_menu(&games_submenu, module_idx);

  return 0;
}


/******************** Module Information structure ******************/

struct ModuleInfo _module_info = {	MODULEINFO_V1_MAGICNUM,
									sizeof(struct ModuleInfo),

									ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
									ANY_PLATFORM_ALLOWED,		// Specify platform dependency
									MODULEINFO_FLAG_SYSTEM,		// flag
									(int32_t)"Games Menu",	    // Module name
									1, 0,						// Module version
									(int32_t)"Games Menu"
								 };


/*************** END OF AUXILARY PART *******************/
