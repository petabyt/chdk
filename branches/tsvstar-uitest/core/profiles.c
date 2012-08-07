#include "stdlib.h"
#include "gui_lang.h"
#include "lang.h"
#include "conf.h"
#include "script.h"
#include "module_load.h"
#include "gui_menu.h"
#include "gui_user_menu.h"
#include "profiles.h"

#include "gui_mbox.h"
#include "console.h"

// A/CHDK/CFG/PROFILES.LST
//	code|name
//		code - use only last digit of code


//========================================================

const char CONF_BASEFILE[] = "A/CHDK/CFG/CHDK_%02d.CFG";			// template of chdk config file
const char CONF_0BASEFILE[] = "A/CHDK/CCHDK2.CFG";					// back-compatible name of chdk cfg for profile#0
const char PROF_NUM_FILE[] = "A/CHDK/DATA/PROFILE.NOW";		// contain current select profile num

static char root_menu_title[50];
static int profile_need_postprocess_flag = 0;

//-----------------------------------------------------------
static void get_profilename_to_buf( char* buf, int size )
{
	unsigned int argv[] ={ 1, (unsigned int)buf, (unsigned int) size, conf.current_profile };
	module_run("profiles.flt", 0, sizeof(argv)/sizeof(argv[0]), argv, UNLOAD_IF_ERR);
}


//-----------------------------------------------------------
void profile_set_postprocessing()
{
	if ( !profile_need_postprocess_flag )
		return;
	profile_need_postprocess_flag=0;

	// set main menu title
	extern CMenu root_menu;
	memset( root_menu_title, 0, sizeof(root_menu_title));
	strcpy( root_menu_title, lang_str( LANG_MENU_MAIN_TITLE ) );

	int size=strlen(root_menu_title);
	if ( size>=46 ) {
		root_menu.title = LANG_MENU_MAIN_TITLE;
	} else {
		strcpy( root_menu_title+size,": " );
		get_profilename_to_buf( root_menu_title+size+2, 46-size );

		root_menu.title = (int) root_menu_title;
	}
}


//-----------------------------------------------------------
// Set current profile to "profile". do_postprocess=true - complete process, =false - postpone mainmenu title update
static void profile_set( int profile, int do_postprocess )
{
	if ( profile<0 )
	  profile=0;

	if ( profile%10==0)
		strcpy( conf_filename, CONF_0BASEFILE );
	else
		sprintf( conf_filename, CONF_BASEFILE, profile%10 );

	if ( profile!=conf.current_profile )
	{
		// update base script cfg dir
		conf.current_profile = profile;

		const char* dir;
		dir = make_param_filename( MAKE_PARAM_FILENAME, 0, 0 );
		mkdir(dir);
		dir =  make_param_filename( MAKE_PARAMSET_NAMES_FILENAME, 0, 0 );
		mkdir(dir);

		profile_need_postprocess_flag = 1;
		if ( do_postprocess )
			profile_set_postprocessing();
		
		profile_remember();
	}

}

//-----------------------------------------------------------
// Callbacks for profile manager 
void gui_safe_set_profile(int arg)
{
	extern void gui_menu_close_menu(int changemode);
	extern void gui_menu_popup_mainmenu();

	if ( arg == conf.current_profile )
		return;

	// Turn off menu (close menu, profile manager, etc) for safety
	gui_menu_close_menu(1);

	// change profile
	profile_set( arg, 1 );

	// load conf it is exists, create one otherwise
	if ( is_file_exists( conf_filename ) )
		conf_restore();
	else {
		user_menu_save();
        conf_save();
        conf_store_old_settings();
	}

	// open menu back again
	gui_menu_popup_mainmenu();
}

//-----------------------------------------------------------
// Store id of currently selected profile
void profile_remember()
{
	save_int_value_file(PROF_NUM_FILE, conf.current_profile);
}

//-----------------------------------------------------------
// PURPOSE: Load stored profile num
// PARAMETERS: do_postprocess - <>0 make whole processing at once, 0 postpone finalization

void profile_restore( int do_postprocess )
{
	int profile=0;

	load_int_value_file( PROF_NUM_FILE, &profile );
	profile_need_postprocess_flag = 1;				// say if need to finalize immediatly after
	profile_set( profile, do_postprocess );
}

