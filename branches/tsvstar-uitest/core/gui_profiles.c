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
#include "modules.h"

#include "module_load.h"

//-------------------------------------------------------------------

enum { MAX_PROF_NUM = 100 };

// Module variables

char* profile_list[ MAX_PROF_NUM ];		// array of profile names
int  appearance_list[ MAX_PROF_NUM+1 ];
char* profile_file_content = 0;
int	  profile_file_size = 0;

static const char PROFILE_CONF_FILE[] = "A/CHDK/CFG/PROFILES.LST";
static const char PMENU_PATH[] = "A/CHDK/CFG/PROFILES/%02d.%s";
//-------------------------------------------------------------------

void parse_profilelist()
{
	int* appearance_ptr = appearance_list;

	// Prepare
	memset( profile_list, 0, sizeof(profile_list) );
	profile_list[0] = (char*)lang_str(LANG_PROFILE_BASE);
	
	*appearance_ptr++=0;


	if ( profile_file_size <= 0 || !profile_file_content ) {
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

// PURPOSE: Load profiles.cfg file and convert to profile_list
void load_and_parse_profilelist( int force )
{
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

	// Load profiles file
    profile_file_content = load_file( PROFILE_CONF_FILE, &profile_file_size );

	// Do parse
	parse_profilelist();
}

//-------------------------------------------------------------------
#ifdef EDIT_FEATURE

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
	profiles_submenu.menu = profiles_default_submenu_items;
	if ( profiles_submenu_items )
		free ( profiles_submenu_items );

	// allocate new
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

//==================================================================
//					EDIT PROFILE
//==================================================================

//-------------------------------------------------------------------
enum {
	MPOPUP_CUT 					= 0x0001,
	MPOPUP_PASTE 				= 0x0002,
	MPOPUP_DELETE				= 0x0004,
	MPOPUP_CLONE			 	= 0x0008,
	MPOPUP_RENAME				= 0x0010,
	MPOPUP_ADD					= 0x0020,
	MPOPUP_INFO					= 0x0040,
};

static struct mpopup_item popup_main[]= {
        { MPOPUP_ADD,			LANG_POPUP_ADD_PROFILE },
        { MPOPUP_CLONE,			LANG_POPUP_CLONE_PROFILE },
        { MPOPUP_DELETE,        LANG_POPUP_DELETE },
        { MPOPUP_RENAME,        LANG_POPUP_RENAME  },
        { MPOPUP_CUT,           LANG_POPUP_CUT    },
        { MPOPUP_PASTE,         LANG_POPUP_PASTE  },
        { MPOPUP_INFO,	        LANG_INFORMATION  },
        { MPOPUP_CANCEL,        LANG_CANCEL  },
        { 0,					0 },
};

static int editop_cut_idx=-1;
static int op_add_shared;
static int op_add_clone_idx;
static int reset_idx_on_update=0;

//-------------------------------------------------------------------

enum {
	PROFILE_OP_ADD,				// val1=before_idx(-1=to end), val2=string
	PROFILE_OP_DEL,				// val1=item_idx
	PROFILE_OP_RENAME,			// val1=item_idx, val2=string_item_name
	PROFILE_OP_MOVE,			// val1=before_idx_tgt, val2=from_idx
};

//-------------------------------------------------------------------
//					AUXILARY FUNCTIONS
//-------------------------------------------------------------------

int get_cur_appidx()
{
	if ( !profiles_submenu_items )
		return -1;

	int idx;
	CMenuItem* item = get_menu_currentitem();
	for ( idx=0; profiles_submenu_items[idx].text; idx++ )
	{
		if ( &(profiles_submenu_items[idx])==item )
			return idx;
	}
	return -1;
}

int appidx_to_profidx( int appidx )
{
	if ( appidx<0 )
		return -1;
	return appearance_list[appidx];
}

int profile_find_slot( int base_profile )
{
	int idx;

	// try to find empty slot shared to base_profile
	if ( op_add_shared )
	{
		for( idx = base_profile%10; idx<100; idx+=10) {
			if ( !profile_list[idx] )
				return idx;
		}
		return -1;
	}

	// try to find non-shared to any profile empty slot
	for( base_profile = 0; base_profile<10; base_profile++) {

		for( idx = base_profile; idx<100; idx+=10) {
			if ( profile_list[idx] )
				break;
		}

		if ( idx>=100 )
			return base_profile;
	}

	return -1;
}

int copy_file( const char* dst_name, const char* src_name )
{
	int size;
	char* buf = load_file( src_name, &size );

	int fd = safe_open(dst_name, O_WRONLY|STD_O_CREAT|STD_O_TRUNC, 0777 );
	if ( fd<0 )
		return 0;

	if ( buf )
		write( fd, buf, size );
	close(fd);

	if ( buf )
		ufree(buf);
	return 1;
	
}

//-------------------------------------------------------------------
//				MAIN EDIT PROCESSING FUNCTIONS
//-------------------------------------------------------------------

// PURPOSE:
//		Store new profile.lst file and update menu
//-------------------------------------------------
int update_profile_file()
{
	char* tgt_file_buf = umalloc( profile_file_size + 200 );

	if ( !tgt_file_buf )
		return 0;

	// Make new file content
	char* tgtptr = tgt_file_buf;
	int* appearance_ptr;
	for ( appearance_ptr=appearance_list; *appearance_ptr>=0; appearance_ptr++ )
	{
		int i = *appearance_ptr;
		if ( profile_list[i] )
		{
			sprintf( tgtptr, "%d|%s\n",i, profile_list[i]);
			tgtptr+=strlen(tgtptr);
		}
	}

	// Store file
	int fd = safe_open(PROFILE_CONF_FILE, O_WRONLY|STD_O_CREAT|STD_O_TRUNC, 0777 );
	if ( fd<0 ) {
		ufree( tgt_file_buf);
		return 0;
	}

	profile_file_size = (tgtptr-tgt_file_buf);
	write( fd, tgt_file_buf, profile_file_size );
	close(fd);

	// Replace buffer with new
	char* profile_file_content_old = profile_file_content;
	profile_file_content = tgt_file_buf;
	profile_file_size++;

	// Update values
	parse_profilelist();
	make_profiles_submenu();
	if (reset_idx_on_update)
		gui_menu_select_first_entry();
	gui_menu_erase_and_redraw();

	reset_idx_on_update = 0;
	editop_cut_idx = -1;

	ufree( profile_file_content_old );
	return 1;
}

//-------------------------------------------------------------------

// PURPOSE:
//		Apply operation
//-------------------------------------------------
int do_edit_operation( int op, int val1, int val2 )
{
	char buf1[50], buf2[50];
	int new_pidx;
	int appidx;

	int new_app_list[MAX_PROF_NUM+1];
	int* tgtptr = 0;

	switch ( op )
	{
		case PROFILE_OP_ADD:
			op_add_clone_idx = appidx_to_profidx(op_add_clone_idx);
			if ( op_add_clone_idx<0 )
				new_pidx = profile_find_slot(conf.current_profile);
			else
				new_pidx = profile_find_slot(op_add_clone_idx);

			if ( new_pidx < 0 ) {
				gui_mbox_init(LANG_ERROR, (op_add_shared ? LANG_ERROR_NO_SHARED_SLOT : LANG_ERROR_NO_REGULAR_SLOT),
										 MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
				return 0;
			}

			for(appidx=0; appearance_list[appidx]>=0; appidx++);
			if (appidx>=99) {
				//gui_mbox(ERR);
				return 0;
			}

			if ( op_add_clone_idx>=0 ) {
				sprintf(buf1,PMENU_PATH,op_add_clone_idx, ".CFG" );
				sprintf(buf2,PMENU_PATH,new_pidx, ".CFG" );
				copy_file( buf2, buf1 );
			}

			profile_list[new_pidx]=(char*)val2;
			appearance_list[appidx++]=new_pidx;
			appearance_list[appidx]=-1;
			
			break;

		case PROFILE_OP_DEL:
			val2=0;
			reset_idx_on_update=1;

/*			// Move menu to bak
            remove(tgtbak);
			rename(selected_file,tgtbak);
*/
			// delete = rename to \0

		case PROFILE_OP_RENAME:
			val1=appidx_to_profidx(val1);
			if ( val1<0 || !profile_list[val1] )
				return 0;
			profile_list[val1]=(char*)val2;
			break;

		case PROFILE_OP_MOVE:
			if ( val2<=0 || val1==0 || val1==val2)
				return 0;

			tgtptr = new_app_list;
			new_pidx = appearance_list[val2];
			for( appidx=0; appearance_list[appidx]>=0; appidx++ ) {
				if ( appidx==val1 ) { *tgtptr++ = new_pidx; new_pidx=-1;}
				if ( appidx==val2 ) continue;
				*tgtptr++ = appearance_list[appidx];
			}
			if (new_pidx>=0)
				*tgtptr++ = new_pidx;	
			*tgtptr = -1;
			memcpy( appearance_list, new_app_list, sizeof(appearance_list));
			break;

		default:
			return 0;

	}

	return update_profile_file();
}

//-------------------------------------------------------------------
//					GUI CALLBACKS
//-------------------------------------------------------------------

static const char* str_trim_and_check( const char* name )
{
	const char *b = 0;
	const char *e = 0;
	
	// check emptiness + cut '|'
	if (!name)
		return 0;

	// Do trimming
 	{
		for( b=name; *b==' ' || *b=='\t' || *b=='|'; b++ );

		for ( e=b; *e && *e!='|'; e++);
		*((char*)e)=0;

		if ( *b=='@' )
		{
			strtol(b+1, (char**)&e, 10);    // convert "*p" to long "i" and return pointer beyond to e
			if ( e<=(b+1) )
				name=0;
		}
		else
		{
			for ( ; b>e && (*e==' ' || *e=='\t');e--);
		}
	}

	// Check emptyness
	if ( name && e>b ) 
		return b;
	return 0;
}

static void tbox_add_cb(const char* name)
{
	name = str_trim_and_check(name);
	if ( name )
		do_edit_operation( PROFILE_OP_ADD, -1, (int)name);
}

static void tbox_rename_cb(const char* name)
{
	name = str_trim_and_check(name);
	if ( name )
		do_edit_operation( PROFILE_OP_RENAME, get_cur_appidx(), (int)name );
}

static void mbox_add_op_cb(unsigned int btn)
{
    if ( btn==MBOX_BTN_CANCEL )
		return;

	op_add_shared = (btn==MBOX_BTN_NO);
	if (module_tbox_load())
		module_tbox_load()->textbox_init( (op_add_clone_idx<0)?LANG_POPUP_ADD_PROFILE:LANG_POPUP_CLONE_PROFILE, LANG_PROMPT_ENTER_TITLE, "", 25, tbox_add_cb, 0);
}

static void profile_delete_op(unsigned int btn)
{
	if ( btn==MBOX_BTN_YES )
		do_edit_operation( PROFILE_OP_DEL, get_cur_appidx(), 0);
}

static void	profiles_show_info()
{
	static char buf[200];

	int profile = appidx_to_profidx( get_cur_appidx() );
	if ( profile<0 )
		profile=conf.current_profile;

	if ( profile<0 || profile>99 )
		profile=0;

	char* prof_name = profile_list[profile];

	sprintf(buf, lang_str(LANG_PROFILE_INFO), prof_name?prof_name:"??", profile );

	int idx;
	for ( idx=profile%10; idx<100; idx+=10 ) {

		if ( idx!=profile && profile_list[idx] ) {
			sprintf( buf+strlen(buf), "\n- %s", profile_list[idx] );
		}
	}

	gui_mbox_init( LANG_INFORMATION, (int)buf, MBOX_BTN_OK, NULL);
}


static void profiles_mpopup_main_cb(unsigned int actn)
{
	CMenuItem* item = get_menu_currentitem();

    switch (actn) {
	    case MPOPUP_ADD:
			op_add_clone_idx = -1;
			gui_mbox_init_adv( LANG_MENU_PROFILE_MANAGER, LANG_PROMPT_ADD_PROFILE,  MBOX_BTN_YES_NO_CANCEL|MBOX_TEXT_CENTER, 
					mbox_add_op_cb,
               		0, LANG_MBOX_BTN_NEW, LANG_MBOX_BTN_SHARED, LANG_MBOX_BTN_CANCEL);
			break;
	    case MPOPUP_CLONE:
			op_add_clone_idx = get_cur_appidx();
			gui_mbox_init_adv( LANG_MENU_PROFILE_MANAGER, LANG_PROMPT_CLONE_PROFILE,  MBOX_BTN_YES_NO_CANCEL|MBOX_TEXT_CENTER, 
					mbox_add_op_cb,
               		0, LANG_MBOX_BTN_NEW, LANG_MBOX_BTN_SHARED, LANG_MBOX_BTN_CANCEL);
			break;
        case MPOPUP_RENAME:
            if (item && module_tbox_load())
                module_tbox_load()->textbox_init(LANG_POPUP_RENAME, LANG_PROMPT_RENAME, lang_str(item->text), 25, tbox_rename_cb, 0);
            break;
        case MPOPUP_DELETE:
            gui_mbox_init( LANG_POPUP_DELETE, LANG_PROFILE_DELETE_TEXT,
                          MBOX_TEXT_CENTER|MBOX_BTN_YES_NO|MBOX_DEF_BTN2, profile_delete_op);
            break;
        case MPOPUP_PASTE:
			do_edit_operation( PROFILE_OP_MOVE, get_cur_appidx(), editop_cut_idx );
            break;
        case MPOPUP_CUT:
			editop_cut_idx = get_cur_appidx();
            break;
        case MPOPUP_INFO:
			profiles_show_info();
			break;
	}
}

int profiles_kbd_process( int keycode )
{
    if ( keycode==KEY_ERASE || keycode==KEY_SHOOT_HALF ) {

		CMenuItem* curr = get_menu_currentitem();
		if ( !curr )
			return 0;

		int flags = MPOPUP_ADD;
		if ( curr->text != LANG_MENU_BACK ) {
			flags|=MPOPUP_CLONE|MPOPUP_DELETE|MPOPUP_RENAME|MPOPUP_INFO;
			if ( curr!=profiles_submenu_items )
				flags|=MPOPUP_CUT;
		}
		if ( editop_cut_idx>= 0 )
			flags|=MPOPUP_PASTE;
		module_mpopup_init( popup_main, flags, profiles_mpopup_main_cb, 0);

		// internal processing, skip regular processing
		return 1;
	}

	// continue processing by regular menu
	return 0;
}
#endif

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

#ifdef EDIT_FEATURE
	if ( profiles_submenu_items )
		free( profiles_submenu_items );
	profiles_submenu_items = 0;
#endif

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

#ifdef EDIT_FEATURE
  if ( !mode ) {

	  // Mode==0: Raise profile manager menu
	  load_and_parse_profilelist( 1 );
	  make_profiles_submenu();
	  gui_activate_sub_menu( &profiles_submenu, module_idx );
	  gui_menu_set_kdb_callback( profiles_kbd_process );

  } else 
#endif
	if ( mode==1 && argn==4 ) {

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
