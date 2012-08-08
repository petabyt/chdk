#include "stdlib.h"
#include "gui_lang.h"
#include "lang.h"
#include "conf.h"
#include "script.h"
#include "module_load.h"
#include "gui_menu.h"
#include "gui_user_menu.h"
#include "profiles.h"
#include "platform.h"

#include "gui_mbox.h"
#include "console.h"

// A/CHDK/CFG/PROFILES.LST
//	code|name
//		code - use only last digit of code

//========================================================

// Buffers which are core store for profmenu
char** pmenu_autoexec_list;		// array of pointers to pairs "scriptname\0scripparam\0" - profile menu autoexecution list
char* pmenu_autoexec_scene;		// pointer to pair "scriptname\0scriptparam\0" of scene to autoexecute (0 - if no one selected)
char* pmenu_string_buf;			// just plain array of strings (contain everything)
CMenu* pmenu_menu_buf;   		// array of menu headers
CMenuItem* pmenu_items_buf;		// result arrays of menuitems (one by one)

int count_autoexec;				// num of pairs in pmenu_autoexec_list


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

	// load_profile_menu
	//load_profile_menu( 0 );
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

	// load_profile_menu
	load_profile_menu( 0 );

    kbd_reset_autoclicked_key();    // Need this to stop 'Func/Set' registering twice???

	// make autoexec sequence
	do_autoexec_sequence( 0, 0, gui_menu_popup_mainmenu );	// synchronous autoexec. call mainmenu at the end

	// open menu back again
	//gui_menu_popup_mainmenu();
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

//=======================================================================
//							PROFILE MENU
//=======================================================================


void load_profile_menu( int autoexeconly )
{
	char PROFILE_MENU_FILE[40];
	unsigned int argv[] ={ (autoexeconly)?1:0, (unsigned int)PROFILE_MENU_FILE };

	sprintf ( PROFILE_MENU_FILE, "A/CHDK/CFG/PROFILES/%02d.CFG", conf.current_profile );
	reset_profile_menu();
	if ( is_file_exists(PROFILE_MENU_FILE) )
		module_run("profmenu.flt", 0, sizeof(argv)/sizeof(argv[0]), argv, UNLOAD_IF_ERR);

	extern void adjust_root_menu();
	adjust_root_menu();
}

//-----------------------------------------------------------

// -> free_buffers(); root_menu_ptr = root_menu;
void reset_profile_menu()
{
	pmenu_autoexec_scene  = 0;
	if ( pmenu_autoexec_list ) free(pmenu_autoexec_list);
	pmenu_autoexec_list=0;
	if ( pmenu_string_buf ) free(pmenu_string_buf);
	pmenu_string_buf=0;
	if ( pmenu_menu_buf ) free(pmenu_menu_buf);
	pmenu_menu_buf=0;
	if ( pmenu_items_buf ) free(pmenu_items_buf);
	pmenu_items_buf=0;
	
	root_menu_ptr = &root_menu;
}

//-----------------------------------------------------------
//				PROFILE MENU: AUTOEXEC
//-----------------------------------------------------------

static char** ptr_autoexec;      		// ptr of current autoexec entry
static char*  ptr_autoexec_scene;  		// ptr of current autoexec_scene entry
static int	  autoexec_base_script;		// 1-need to start base script in the end of autoexec sequence, 0-otherwise
static int	  autoexec_async_mode;		// 1-async mode of script starts(for on chdk start sequence), 0-sync mode(profile switch)

static void (*autoexec_callback)();		// ptr to callback which should be called once before script running
static void (*autoexec_fin_cb)();		// ptr to callback which should be called after script chain



//-----------------------------------------------------------

static void run_autoexec_callback() { if ( autoexec_callback ) { autoexec_callback(); autoexec_callback=0;} }

static int autoexec_callback_next();

static int next_autoexec_entry()
{
	char* scriptname;

	// First execute each entry from autoexec_list
	if ( ptr_autoexec && *ptr_autoexec )
	{
		scriptname=*ptr_autoexec++;
		run_autoexec_callback();
		temporary_script_load( scriptname, scriptname+1+strlen(scriptname), autoexec_callback_next, 1 );
		return 0;
	}

	// Then autoexec_scene_script
	if ( ptr_autoexec_scene )
	{
		scriptname=ptr_autoexec_scene;
		ptr_autoexec_scene=0;
		run_autoexec_callback();
		temporary_script_load( scriptname, scriptname+1+strlen(scriptname), autoexec_callback_next, 1 );
		return 0;
	}

	// Then autoexec_base_script
	if ( autoexec_base_script )
	{
		autoexec_base_script=0;
		temporary_script_unload();	// restore previous state
		run_autoexec_callback();
		script_start_gui( 1 );
		return 0;
	}

	if ( autoexec_fin_cb ) {
		autoexec_fin_cb();
		autoexec_fin_cb=0;
	}

	return 1;
}

static int autoexec_callback_next()
{
	if ( autoexec_async_mode )
		return 0;				// do not terminate "temporary" chain

	return next_autoexec_entry();
}


// PURPOSE: This function is called on each tick
// It execute scripts one-by-one and turn off at the end
void autostart_sequence_entry()
{
	if ( autoexec_async_mode && !state_kbd_script_run ) {
	  if ( next_autoexec_entry() ) {
			autoexec_async_mode=0;
			temporary_script_unload();	// restore previous state
		}
	}
}


// PURPOSE: Run preloaded autoexec sequence:
// PARAMETERS:
//		async_mode - 
//		callback - this function should be called before first script run if any
//		callback_fin - this function should be called after end of last script in chain
void do_autoexec_sequence( int async_mode, void (*callback)(), void(*callback_fin)() ) 
{
	int script_startup_was = conf.script_startup;

	// reset mode if startup mode = once
	if (conf.script_startup==2)
    {
        conf.script_startup=0;
        conf_save();
	}

	autoexec_callback = callback;
	autoexec_fin_cb = callback_fin;

	autoexec_base_script = 0;
	ptr_autoexec = 0;
	ptr_autoexec_scene = pmenu_autoexec_scene;

	// If autoexec list exists - use it, otherwise base script
	if ( script_startup_was ) {

		if ( count_autoexec && pmenu_autoexec_list )
			ptr_autoexec = pmenu_autoexec_list;
		else
			autoexec_base_script = 1;
	}

	autoexec_async_mode = async_mode;

	if ( !async_mode )
		next_autoexec_entry();		
}


//-----------------------------------------------------------
//				PROFILE MENU: GUI CALLBACKS
//-----------------------------------------------------------

void gui_pmenu_load_script(int arg) 
{
	char* scriptpath = (char*)arg;

	gui_menu_close_menu(1);

	script_load( scriptpath, SCRIPT_LOAD_DEFAULT_VALUES );
	script_apply_paramstr( scriptpath+1+strlen(scriptpath),1 );

    kbd_reset_autoclicked_key();    // Need this to stop 'Func/Set' registering twice???
}

void gui_pmenu_run_script(int arg)
{
	char* scriptpath = (char*)arg;

	if ( scriptpath && scriptpath[0] )
		temporary_script_load( scriptpath, scriptpath+1+strlen(scriptpath), 0, 0 );
	else
		gui_mbox_init((int)"Run script", (int)"No script defined for this item", MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
}


void gui_pmenu_run_as_mode(int arg)
{
	char* scriptpath = (char*)arg;
	char* scriptparam = scriptpath;
	int   namehash = 0;

	if ( scriptpath ) {

		scriptparam += strlen(scriptpath)+1;

		memcpy( &namehash, scriptparam+1+strlen(scriptparam), sizeof(int) );

		if ( !scriptpath[0] )
			namehash=0;
	}

	extern void conf_change_scene_script();

	conf.scene_script_mode = namehash;
	conf_change_scene_script();
	conf_save_new_settings_if_changed();

	if ( namehash )
		temporary_script_load( scriptpath, scriptparam, 0, 0 );
	/*
	else
		gui_mbox_init((int)"Mode", (int)"Reset mode", MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
	*/
}

void gui_menu_goto_mainmenu(int arg)
{
	gui_menu_close_menu(1);
	root_menu_ptr = &root_menu;
	conf.profile_menu_mode = 0;
	gui_menu_popup_mainmenu();
}
