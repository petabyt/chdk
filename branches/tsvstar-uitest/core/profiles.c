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

// A/CHDK/CFG/PROFILES.LST
//	code|name
//		code - use only last digit of code

//========================================================

// Buffers which are core store for profmenu
struct ProfileMenu pmenu = { MAKE_API_VERSION(1,0) };

//========================================================

const char CONF_BASEFILE[] = "A/CHDK/CFG/CHDK_%02d.CFG";			// template of chdk config file
const char CONF_0BASEFILE[] = "A/CHDK/CCHDK2.CFG";					// back-compatible name of chdk cfg for profile#0
const char PROF_NUM_FILE[] = "A/CHDK/DATA/PROFILE.NOW";		// contain current select profile num

extern void adjust_root_menu();

#ifdef OPT_PROFILES
static char root_menu_title[50];
static int profile_need_postprocess_flag = 0;

//-----------------------------------------------------------
static void get_profilename_to_buf( char* buf, int size )
{
	unsigned int argv[] ={ 1, (unsigned int)buf, (unsigned int) size, conf.current_profile };

	// Try to choose already loaded module or load minimal module
	char* module_name =  (module_find("profiles.flt")>=0)?"profiles.flt":"prof_min.flt";

	module_run("profiles.flt", 0, sizeof(argv)/sizeof(argv[0]), argv, UNLOAD_IF_ERR);
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

#ifdef OPT_SCRIPTING
		const char* dir;
		dir = make_param_filename( MAKE_PARAM_FILENAME, 0, 0 );
		mkdir(dir);
		dir =  make_param_filename( MAKE_PARAMSET_NAMES_FILENAME, 0, 0 );
		mkdir(dir);
#endif

		profile_need_postprocess_flag = 1;
		if ( do_postprocess )
			profile_set_postprocessing();
		
		profile_remember();
	}

}

//-----------------------------------------------------------
// Store id of currently selected profile
void profile_remember()
{
	save_int_value_file(PROF_NUM_FILE, conf.current_profile);
}
#endif

//-----------------------------------------------------------
// PURPOSE: Load stored profile num
// PARAMETERS: do_postprocess - <>0 make whole processing at once, 0 postpone finalization

void profile_restore( int do_postprocess )
{
#ifdef OPT_PROFILES
	int profile=0;

	load_int_value_file( PROF_NUM_FILE, &profile );
	profile_need_postprocess_flag = 1;				// say if need to finalize immediatly after
	profile_set( profile, do_postprocess );
#else
	strcpy( conf_filename, CONF_0BASEFILE );
#endif
}

//-----------------------------------------------------------
void profile_set_postprocessing()
{
#ifdef OPT_PROFILES
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
#endif
}


//-----------------------------------------------------------
// Callbacks for profile manager 
void gui_safe_set_profile(int arg)
{
#ifdef OPT_PROFILES
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
#ifdef OPT_USER_MENU
		user_menu_save();
#endif
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
#endif
}

//=======================================================================
//							PROFILE MENU
//=======================================================================


#ifdef OPT_PROFILES
char* get_profilemenu_file()
{
	static char PROFILE_MENU_FILE[40];
	sprintf ( PROFILE_MENU_FILE, "A/CHDK/CFG/PROFILES/%02d.CFG", conf.current_profile );
	return PROFILE_MENU_FILE;
}

// RETURN: 1 if "menu" is profile menu menu
//----------------------------------------
int is_pmenu_menu( const CMenu* menu)
{
	if ( pmenu.count_menu<=0 || !pmenu.menu_buf || menu<pmenu.menu_buf )
	  return 0;
	return ( (menu - pmenu.menu_buf) < pmenu.count_menu );
}

// RETURN: stored_idx of profile menu item
//		-1 if this is not profile menu item
//----------------------------------------
int pmenu_get_itemidx( const CMenuItem* item )
{
	if ( pmenu.count_items<=0 || !pmenu.items_buf || 
		 !pmenu.itemidx_buf || item<pmenu.items_buf)
	  return -1;

	int idx = (item - pmenu.items_buf);
	if ( idx >= pmenu.count_items )
		return -1;

	return pmenu.itemidx_buf[idx];
}

// RETURN: <>0 if "item" is profile menu item
//----------------------------------------
int is_pmenu_item( const CMenuItem* item )
{
	return (pmenu_get_itemidx(item)+1);
}

int is_pmenu_regular_item( const CMenuItem* item )
{
	return ( is_pmenu_item(item) &&
		     item->text &&
			 (item->type & MENUITEM_MASK) != MENUITEM_UP );
}


// PURPOSE: Load profile menu
// PARAMETERS: autoexeconly - 1 if load only autoexec entry
//----------------------------------------
void load_profile_menu( int autoexeconly )
{
	unsigned int argv[] ={ (autoexeconly)?PMENU_LOAD_AUTOEXEC:PMENU_LOAD, 0 };

	reset_profile_menu( &pmenu );
	argv[1] = (unsigned int)get_profilemenu_file();
	if ( is_file_exists( (char*)argv[1] ) > 0 )
		module_run("pmenu.flt", 0, sizeof(argv)/sizeof(argv[0]), argv, UNLOAD_IF_ERR);

	adjust_root_menu();
}

// PURPOSE: Load profile menu
// PARAMETERS: autoexeconly - 1 if load only autoexec entry
//----------------------------------------
void run_edit_profile_menu( unsigned int* argv, int argn )
{
	if ( argn < 3 )
		return;

	argv[1] = (unsigned int)get_profilemenu_file();
	module_run("pmenuedi.flt", 0, argn, argv, UNLOAD_IF_ERR);

	adjust_root_menu();
}
#endif

//-----------------------------------------------------------

// -> free_buffers(); root_menu_ptr = root_menu;
void reset_profile_menu( struct ProfileMenu *pmenu_p )
{
	pmenu_p->autoexec_scene  = 0;
	pmenu_p->editop_cut_idx  = -1;

	pmenu_p->count_autoexec = pmenu_p->count_menu = pmenu_p->count_items = 0;

	if ( pmenu_p->autoexec_list ) free(pmenu_p->autoexec_list);
	pmenu_p->autoexec_list=0;
	if ( pmenu_p->string_buf ) free(pmenu_p->string_buf);
	pmenu.string_buf=0;
	if ( pmenu_p->menu_buf ) free(pmenu_p->menu_buf);
	pmenu_p->menu_buf=0;
	if ( pmenu_p->items_buf ) free(pmenu_p->items_buf);
	pmenu_p->items_buf=0;
	if ( pmenu_p->itemidx_buf ) free(pmenu_p->itemidx_buf);
	pmenu_p->itemidx_buf=0;
	
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
#ifdef OPT_SCRIPTING
#ifdef OPT_PROFILES
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
#endif

	// Then autoexec_base_script
	if ( autoexec_base_script )
	{
		autoexec_base_script=0;
		temporary_script_unload();	// restore previous state
		run_autoexec_callback();
		script_start_gui( 1 );
		return 0;
	}
#endif

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
#ifdef OPT_SCRIPTING
			temporary_script_unload();	// restore previous state
#endif
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
	ptr_autoexec_scene = pmenu.autoexec_scene;

	// If autoexec list exists - use it, otherwise base script
	if ( script_startup_was ) {

		if ( pmenu.count_autoexec && pmenu.autoexec_list )
			ptr_autoexec = pmenu.autoexec_list;
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
#ifdef OPT_PROFILES
#ifdef OPT_SCRIPTING
	char* scriptpath = (char*)arg;

	gui_menu_close_menu(1);

	script_load( scriptpath, SCRIPT_LOAD_DEFAULT_VALUES );
	script_apply_paramstr( scriptpath+1+strlen(scriptpath),1 );

    kbd_reset_autoclicked_key();    // Need this to stop 'Func/Set' registering twice???
#else
		gui_mbox_init(LANG_ERROR, (int)"No script support in this CHDK build", MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
#endif
#endif
}

void gui_pmenu_run_script(int arg)
{
#ifdef OPT_PROFILES
#ifdef OPT_SCRIPTING
	char* scriptpath = (char*)arg;

	if ( scriptpath && scriptpath[0] )
		temporary_script_load( scriptpath, scriptpath+1+strlen(scriptpath), 0, 0 );
	else
		gui_mbox_init(LANG_ERROR, LANG_ERR_NO_SCRIPT_FOR_ITEM, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
#else
		gui_mbox_init(LANG_ERROR, (int)"No script support in this CHDK build", MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
#endif
#endif
}


void gui_pmenu_run_as_mode(int arg)
{
#ifdef OPT_PROFILES
#ifdef OPT_SCRIPTING
	char* scriptpath = (char*)arg;
	char* scriptparam = scriptpath;
	int   namehash = 0;

	if ( scriptpath ) {

		scriptparam += strlen(scriptpath)+1;

		memcpy( &namehash, scriptparam+1+strlen(scriptparam), sizeof(int) );

		if ( !scriptpath[0] )
			namehash=0;
	}

	conf.scene_script_mode = namehash;
	conf_change_scene_script();
	conf_save_new_settings_if_changed();

	if ( namehash )
		temporary_script_load( scriptpath, scriptparam, 0, 0 );
	/*
	else
		gui_mbox_init((int)"Mode", (int)"Reset mode", MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
	*/
#else
		gui_mbox_init(LANG_ERROR, (int)"No script support in this CHDK build", MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
#endif
#endif
}

void gui_pmenu_goto_mainmenu(int arg)
{
#ifdef OPT_PROFILES
	gui_menu_close_menu(1);
	conf.profile_menu_mode = 0;
	conf_update_pmenu_mode();
	gui_menu_popup_mainmenu();
#endif
}

void gui_pmenu_unknown_map(int arg)
{
#ifdef OPT_PROFILES
	gui_mbox_init(LANG_TITLE_PROFMENU, LANG_ERR_UNKNOWN_ITEM, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
#endif
}

//-----------------------------------------------------------
//				PROFILE MENU: EDIT OPERATIONS
//-----------------------------------------------------------

#ifdef OPT_PROFILES

// Callback for edit operations
void edit_profile_menu_op( const CMenuItem* curr_menu_item )
{
	unsigned int argv[] ={ (root_menu_ptr == &root_menu)? PMENU_MMENU_CALLBACK:PMENU_EDIT_CALLBACK, 
							0, (int)curr_menu_item, (conf.profile_menu_editmode == 3)?0:1 };
	run_edit_profile_menu( argv, sizeof(argv)/sizeof(argv[0]) );
}

// Move curr_item into move_offs direction: -1 up, +1 down
void move_pmenu_item( const CMenuItem* curr_item, int move_offs )
{
	// check moving ability of item
	if ( !is_pmenu_regular_item( curr_item ) )
		return; 
	
	const CMenuItem* tgt = curr_item;
	int steps = (move_offs<0)?1:2;	// for move down offset is +2 because we look for "before" item
	move_offs = (move_offs<0)?-1:1;

	// Check for boundaries
	//step 1
		tgt += move_offs;
		if ( !is_pmenu_regular_item(tgt) )
			return;

	//step 2
		if ( steps==2 ) {
			tgt += move_offs;
			if ( !is_pmenu_item(tgt) )
				return;
		}

	// Do move
	unsigned int argv[] ={ PMENU_EDIT_OP, 0, PMENU_OP_MOVE, -1, -1 };
	argv[3] = pmenu_get_itemidx(tgt);     		// move before this
	argv[4] = pmenu_get_itemidx(curr_item);		// move this
	run_edit_profile_menu( argv, sizeof(argv)/sizeof(argv[0]) );
}
#endif