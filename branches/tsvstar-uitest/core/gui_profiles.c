/*
	MODULE "PROFILE MANAGER"
	profiles.flt 
		argv[0]=mode
	    mode=0/empty_arg_list => show list of profiles
		mode=1 - arv[1]=buf, argv[2]=size_or_buf => fill up buffer with current profile

	POSSIBLE IMPROVEMENT:
		CREATE/DELETE/REARRANGE	profiles using SHOOT button
*/
#include "stdlib.h"
#include "lang.h"
#include "gui.h"
#include "gui_lang.h"
#include "gui_menu.h"
#include "conf.h"
#include "profiles.h"
#include "keyboard.h"
#include "gui_mbox.h"

#include "module_load.h"

//-------------------------------------------------------------------


// Module variables

char* profile_list[100];	// array of profile names
int  appearance_list[101];
char* profile_file_content = 0;

static const char PROFILE_CONF_FILE[] = "A/CHDK/CFG/PROFILES.LST";

//-------------------------------------------------------------------


// PURPOSE: Load profiles.cfg file and convert to profile_list
void load_and_parse_profilelist( int force )
{
	int* appearance_ptr = appearance_list;

	// Prepare buffer
	if ( profile_file_content )
	{
		if ( force )
			ufree( profile_file_content );
		else {
			// Do not reparse profiles.cfg to avoid unallocation of menu items name
			//		while menu could be active
			return;
		}
	}


	// Prepare
	memset( profile_list, 0, sizeof(profile_list) );
	profile_list[0] = (char*)lang_str(LANG_PROFILE_BASE);
	
	*appearance_ptr++=0;

	// Load profiles file
	int size;
    profile_file_content = load_file( PROFILE_CONF_FILE, &size );

	if ( size <= 0 || !profile_file_content ) {
		*appearance_ptr++=-1;
		return;
	}

	// Do parse

    char *p, *e;
    int num;

    e = profile_file_content-1;
    while(e) {
        p = e+1;
        while (*p && (*p=='\r' || *p=='\n')) ++p; //skip empty lines
        num = strtol(p, &e, 0/*autodetect base oct-dec-hex*/);    // convert "*p" to long "i" and return pointer beyond to e
        if (e!=p && *e=='|' && (num>=0 && num<=99) ) {
            p = e+1;
            e = strpbrk(p, "\r\n");        //break string with zero on \r or \n
            if (e) *e=0;

			if (!profile_list[num])
				*appearance_ptr++=num;				

			profile_list[num] = p;
        } else { //skip invalid line
            e = strpbrk(p, "\r\n");
            if (e) *e=0;
        }
    }
	*appearance_ptr++=-1;
}

//-------------------------------------------------------------------

static CMenuItem *profiles_submenu_items = 0;

static CMenuItem profiles_default_submenu_items[] = {
    MENU_ITEM   (0x51,LANG_MENU_BACK,                       MENUITEM_UP,                    0,                                  0 ),
    {0},
};

static CMenu profiles_submenu = {0x29,LANG_MENU_PROFILE_MANAGER_TITLE, NULL, profiles_default_submenu_items };

void make_profiles_submenu()
{
	if ( conf.current_profile<0 || conf.current_profile>99 )
	  conf.current_profile=0;

	gui_menu_clean_marks( MENU_MARK_CATEGORY_PROFILES );
	gui_menu_add_mark( MENU_MARK_CATEGORY_PROFILES, lang_strhash31((int)profile_list[conf.current_profile]) );

	// calculate num of items
	int i;
	int count = 2;		// start from 2 because "back" and \\0
	for ( i=0; i<=99; i++ )
	{
		if ( profile_list[i] )
			count++;
	}

	// Safe reallocate space for submenu items

	if ( profiles_submenu_items )
		free ( profiles_submenu_items );

	profiles_submenu.menu = profiles_default_submenu_items;

	profiles_submenu_items = malloc( count * sizeof(profiles_default_submenu_items[0]) );
	if ( !profiles_submenu_items )
		return;

	// Fill up menu

	CMenuItem *item_ptr = profiles_submenu_items;
	int* appearance_ptr;
	for ( appearance_ptr=appearance_list; *appearance_ptr>=0; appearance_ptr++ )
	{
		i = *appearance_ptr;
		if ( profile_list[i] )
		{
			item_ptr->symbol = 0x2a;
			item_ptr->type = MENUITEM_PROC;
			item_ptr->text = (int) profile_list[i];
			item_ptr->value = (int*) gui_safe_set_profile;
			item_ptr->arg = i;
			item_ptr++;
		}
	}

	// finalize with profiles_default_submenu_items
	memcpy( item_ptr, profiles_default_submenu_items, sizeof(profiles_default_submenu_items) ); 

	profiles_submenu.menu = profiles_submenu_items;
}

//-------------------------------------------------------------------

static void profile_op_cb(unsigned int btn) {
    if (btn==MBOX_BTN_YES) {
		// MOVE
		gui_mbox_init((int)"Move profile", (int)"Not implemented yet", MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
	}
	else if (btn==MBOX_BTN_NO) {
		// DELETE
		gui_mbox_init((int)"Delete profile", (int)"Not implemented yet", MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
	}
}

int profiles_kbd_process( int keycode )
{
    if ( keycode==KEY_ERASE || keycode==KEY_SHOOT_HALF ) {

		CMenuItem* curr = get_menu_currentitem();
		if ( !curr )
			return 0;

		if ( curr->text == LANG_MENU_BACK ) {
            gui_mbox_init((int)"Add new profile", (int)"Not implemented yet", MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
		} else {

			gui_mbox_init_adv((int)"Profile Operation", (int)"Choose operation",  MBOX_BTN_YES_NO_CANCEL|MBOX_DEF_BTN3|MBOX_TEXT_CENTER, 
					profile_op_cb,
               		0, (int)"Move", (int)"Delete", LANG_MBOX_BTN_CANCEL);
		}

		// internal processing, skip regular processing
		return 1;
	}

	// continue processing by regular menu
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

  // min version for conf.current_profile
  if ( !API_VERSION_MATCH_REQUIREMENT( conf.api_version, 2, 2 ) )
	  return 1;

  return 0;
}



//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{

	// Could control flow reach this with active submenu (?)

	if ( profile_file_content )
		ufree( profile_file_content );
	profile_file_content = 0;

	if ( profiles_submenu_items )
		free( profiles_submenu_items );
	profiles_submenu_items = 0;

    return 0;
}


//---------------------------------------------------------
// PURPOSE: Default action for simple modules (direct run)
// NOTE: Please comment this function if no default action and this library module
//---------------------------------------------------------
int _module_run(int moduleidx, int argn, int* arguments)
{
  module_idx=moduleidx;

  int mode = 0;
  if ( argn>0 )
	mode = arguments[0];

  if ( !mode ) {

	  // Mode==0: Raise profile manager menu
	  load_and_parse_profilelist( 1 );
	  make_profiles_submenu();
	  gui_activate_sub_menu( &profiles_submenu, module_idx );
	  gui_menu_set_kdb_callback( profiles_kbd_process );

  } else if ( mode==1 && argn==4 ) {

	  // Mode==1: convert profile# to its name to buffer

	  char *tgtbuf = (char*)arguments[1];
	  int  bufsize = arguments[2];
	  int  profilenum = arguments[3];

	  if ( !tgtbuf || bufsize<=0 )
		return 1;

	  load_and_parse_profilelist( 0 );
	  if ( profilenum<0 || profilenum>99 || !profile_list[profilenum] )
		 { strncpy(tgtbuf, "???", bufsize ); }
	  else
		 { strncpy( tgtbuf, profile_list[profilenum], bufsize ); }
	  tgtbuf[bufsize-1]=0;

  } else {
	  module_async_unload(moduleidx);
  }

  return 0;
}


/******************** Module Information structure ******************/

struct ModuleInfo _module_info = {	MODULEINFO_V1_MAGICNUM,
									sizeof(struct ModuleInfo),

									ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
									ANY_PLATFORM_ALLOWED,		// Specify platform dependency
									0,							// flag
									(int32_t)"Profile Manager",					// Module name
									1, 0,						// Module version
									0
								 };

/*************** END OF AUXILARY PART *******************/
