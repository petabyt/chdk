/*
	MODULE "PROFILE MENU SYSTEM"
	
	PURPOSE:
		- Load and parse profile menu config file
			So it produce from config menu ready to use menu hierarchy

	HOW TO RUN:
		- empty arg list   - build profile menu from file
		- argn=1, arg[0]=1 - load autoexec list only

NOTES:
	"Profile menu" is kind of userMenu. It could be toggled on/off.
	It is loaded on_demand on first menu open (!NO WE HAVE TO PROCESS AUTOEXEC LIST!)
*/



#include "stdlib.h"
#include "lang.h"
#include "gui.h"
#include "gui_lang.h"
#include "gui_menu.h"
#include "gui_user_menu.h"
#include "profiles.h"
#include "conf.h"

#include "module_load.h"

//-------------------------------------------------------------------
//			Imported functions
//-------------------------------------------------------------------

//-------------------------------------------------------------------
//			Global variables sections
//-------------------------------------------------------------------

// local temporary buffers
static CMenuItem* pmenu_items_tmpbuf;	// temporary buffer to rearrange items lists from hiearchical form to plain lists form
static char* pmenu_level_buf;			// temporary buffer. levels of each item.

// count of items each kind
static int count_string;
static int count_menu;
static int count_items;
static int count_level;

// iterators to fillup buffers
static char* 	  ptr_string;
static CMenu* 	  ptr_menu;
static CMenuItem* ptr_item;
static char*	  ptr_level;
static char**     ptr_autoexec;

// other important global variables
static int cur_level=0;			// current submenu level
static char* ptr;				// main pointer thru .cfg content
static int is_prepare_mode;   	// 0=make_processing, 1=do_count
static int autoexec_only_mode;	// 0=regular_processing, 1=light processing (load autoexec symbols only)

//=======================================================
// AUXILARY FUNCTIONS
//=======================================================

char* skip_to_pipe(char *ptr)
{
	while (*ptr && *ptr!='\r' && *ptr!='\n' && *ptr!='|') ++ptr;
	return ptr;
}

//=======================================================
//			Value Parsing functions
//=======================================================


// if *ptr starting from "(hex)" -> mean "symbol" read and return it
// return -1 otherwise
//-----------------------------------------------
int read_symbol_value()
{
	char* p,*e;
	int rv = -1;

	if (*ptr=='('){
		p=ptr+1;
        rv = strtol(p, &e, 16/*hex_number*/);    // convert "*p" to long "i" and return pointer beyond to e
		if (p!=e && *e==')' )
			ptr=e+1;
		else
			rv=-1;
	}

	return rv;
}

// read trimmed text value
//-----------------------------------------------
int read_filename_value()
{
	char* b;	// begin
	char* e;	// next

	while(*ptr==' ' || *ptr=='\t') ptr++;			// ltrim
	b=ptr;
	ptr=e=skip_to_pipe(ptr);
	if (*ptr=='|') ptr++;
	while ( e>b && (*e==' ' || *e=='\t') ) e--;		// rtrim

	// empty string
	if ( e<=b ) {

		// empty script name have to be added to string because it is required component
		//	of scriptname/scriptparam pair
		if ( is_prepare_mode )
			count_string++;
		else
			*ptr_string++ = 0;
		return 0;
	}

	if ( is_prepare_mode ) {
		count_string += (e-b)+1;
		return -1;
	} else {
		char* cur_str = ptr_string;

		memcpy( ptr_string, b, e-b );
		ptr_string += (e-b);
		*ptr_string++ = 0;

		return (int)cur_str;
	}
}

// read text value. no trim. @value - mean id
// return: 0 if empty. langid otherwise
//-----------------------------------------------
int read_text_value()
{
	char* b;	// begin
	char* e;	// cur

	if ( *ptr == '@' ) {
	    int value = strtol( ptr+1, &e, 0/*autodetect base oct-dec-hex*/);    // convert "*p" to long "i" and return pointer beyond to e
		if ( e != ptr+1 ) {
			ptr = skip_to_pipe(e);
			if (*ptr=='|') ptr++;
			return value;
		}
	}
	
	if (*ptr=='\\') ptr++;	// shield first symbol to allow use '@' at start
	
	b = ptr;
	ptr = e = skip_to_pipe(ptr);	
	if (*ptr=='|') ptr++;
	
	// empty string
	if ( e==b )
	  return 0;

	if ( is_prepare_mode ) {
		count_string += (e-b)+1;
		return -1;
	} else {
		char* cur_str = ptr_string;

		memcpy( ptr_string, b, e-b );
		ptr_string += (e-b);
		*ptr_string++ = 0;

		return (int)cur_str;
	}
}

// prepare and squeeze scriptparam kind of value
// return: 0 if empty, ptr to string otherwise
//-----------------------------------------------
int read_scriptparam_value()
{
	char scriptparam[150];	// target buffer
	int cur_param=0;		// num of processed parameters
	int wait_comma=0;       // flag that we should wait for comma before continue
								// 0-parse_enable, 1-wait_for_comma, 2-wait_comma_and_process_it

	char* e;				// temp variable

	char *tgt = scriptparam;
	char *stop_at = scriptparam + sizeof(scriptparam) - 15;
	while ( *ptr && *ptr!='|' && *ptr!='\r' && *ptr!='\n' && tgt<stop_at )
	{
		if ( wait_comma ) {

			if (*ptr!=',') {
				ptr++;
				continue; 
			}

			if ( wait_comma==2 )
				*tgt++ = *ptr;

			ptr++;
			wait_comma=0;
		}

		// #scriptset
		if ( *ptr=='#' && tgt==scriptparam ) {
			if ( ptr[1]>='0' && ptr[1]<='9')
			{
				cur_param++;
				*tgt++ = *ptr++;	// copy '#'
				*tgt++ = *ptr++;	// copy digit
			}

			wait_comma=2;
			continue;
		}

		// varname=value
		if (*ptr>='a' && *ptr<='z') {
			e = strpbrk( ptr, "=|\r\n" );
			if ( !e ) break;

			if ( *e!= '=' ) {
				ptr=e;
				wait_comma=1;
				continue;
			}

			// we are on '=' now
			e++;
			while( *e==' ' || *e=='\t' ) e++;	// ltrim

			if ( *e<'0' || *e>'9' ) {
				ptr=e;
				wait_comma=1;
				continue;
			}

			cur_param++;

			*tgt++ = *ptr;	// copy varname
			*tgt++ = '=';	// copy '='
			ptr=e;
			while ( *ptr>='0' && *ptr<='9' )	// copy value
				*tgt++ = *ptr++;

			wait_comma=2;
			continue;
		}
		ptr++;
	}

	if (*ptr=='|') ptr++;

	if ( !cur_param ) 
	{
		// if empty - say 0, but store ' ' to strings
		// this is required for correct autoexec_list fillup

		if ( is_prepare_mode ) {
			count_string += 2;
		} else {
		 *ptr_string++ = ' ';
		 *ptr_string++ = 0;
		}

		return 0;
	}

	if ( is_prepare_mode ) {
		count_string += (tgt-scriptparam)+1;
		return -1;
	} else {
		char* cur_str = ptr_string;

		memcpy( ptr_string, scriptparam, (tgt-scriptparam) );
		ptr_string += (tgt-scriptparam);
		*ptr_string++ = 0;

		return (int)cur_str;
	}
}

//====================================
// menu-related processing functions 
//====================================

void add_menuitem(int symbol, int titleid, int type, void* value, int arg )
{
	if ( is_prepare_mode ) {
		count_items++;
	} else {
		memset(ptr_item,0,sizeof(CMenuItem));
		ptr_item->symbol = (symbol<0) ? 0x5c : symbol;
		ptr_item->type = type;
		ptr_item->text = titleid;
		ptr_item->value = value;
		ptr_item->arg = arg;
		ptr_item++;

		*ptr_level = cur_level;
		ptr_level++;
	}
}

void create_submenu( int symbol, int titleid, CMenuItem *menuitem_ptr ) 
{
	if ( is_prepare_mode ) {
		count_menu++;
		cur_level++;
	} else {
		ptr_menu->symbol = (symbol<0) ? 0x20 : symbol;
		ptr_menu->title = titleid;
		ptr_menu->on_change = 0;
		ptr_menu->menu = menuitem_ptr;
		ptr_menu++;
		cur_level++;
	}
}

void close_submenu( ) 
{
	if ( cur_level<0 )
	  return;
	add_menuitem( 0,0,0,0,0 );
	cur_level--;
}


// check if requested menulevel is allowed. finalize if needed
// return: 0- if error, 1 if ok
int preprocess_menu( int requested_level )
{
	// skip unauthorized increasing of submenu depth
	if ( requested_level > cur_level )
		return 0;

	while ( requested_level < cur_level ) {
		add_menuitem( 0x51, LANG_MENU_BACK, MENUITEM_UP, 0, 0 );
		close_submenu();
	}
	return 1;
}

void add_autoexec_item( char* ptr )
{
	if ( is_prepare_mode )
		count_autoexec++;
	else
		*ptr_autoexec++ = ptr;
}

void add_int_to_stringbuf( int value )
{
	if ( is_prepare_mode )
		count_string+=sizeof(int);
	else {

		// simple "*(int*)ptr_string = value" doesn't work because
		//	complier make silent alignement to word boundary
		memcpy( ptr_string, &value, sizeof(int) );	

		ptr_string += sizeof(int);
	}
}

//=======================================================
//				MAIN PROCESSING FUNCTIONS
//=======================================================

// Postprocessing: Rebuild menuitems buf to make lists plain
//----------------------------------------------------------
void postprocess_parse()
{
	CMenuItem* src_p;
	CMenuItem* tgt_p = pmenu_items_buf;
	
	int level;
    int i,idx_item;

	//cycle thru all menus
	for( i=0; i<count_menu; i++) {

		// find out idx of its first item in menuitem_buf
		src_p=(CMenuItem*)pmenu_menu_buf[i].menu;
		idx_item = (src_p-pmenu_items_tmpbuf);
		if ( idx_item<0 ) continue;	// sanity check

		level=pmenu_level_buf[idx_item];
		if ( level<0 ) continue;
		
		pmenu_menu_buf[i].menu = (const CMenuItem*)tgt_p;

		// collect to target buf items of this menu
		for ( ; idx_item<count_items; idx_item++ ) {

			if ( pmenu_level_buf[idx_item]!=level )
				continue;
			memcpy( tgt_p, &pmenu_items_tmpbuf[idx_item], sizeof(CMenuItem) );
			tgt_p++;
			pmenu_level_buf[idx_item]=-1;
			if ( pmenu_items_tmpbuf[idx_item].text==0 ) 
				break;
		}
	}
}

// Main parse cycle
//---------------------------------------------
void process_parse_cfgfile( char* content )
{
	char *e;
	
	char type;
	int val1, val2, val3;
	int sym, sym2;
	int hash;
	menuproc_t* func;

	int flag_mainmenu_reference=0;

	ptr = content;

	cur_level=-1;

	// initialize root menu
	if ( !autoexec_only_mode )
		create_submenu( 0x20, root_menu.title, ptr_item );

    e = content-1;
    while(e) {
        ptr = e+1;
        while (*ptr=='\r' || *ptr=='\n') ++ptr; //skip empty lines

		int level=0;
		while ( *ptr=='>' ) { level++; ptr++; }

		type = *ptr;
		
		ptr = skip_to_pipe(ptr);
		if (*ptr=='|') ptr++;
		
		switch ( type )
		{
			case 'a':	//autoexec
				val1 = read_filename_value();
				if ( !val1 )
					break;
				val2 = read_scriptparam_value();
				add_autoexec_item( (char*) val1 );
				break;

			case 's':	//submenu
				if ( autoexec_only_mode )
					break;
				if ( preprocess_menu( level ) )
				{
					sym = read_symbol_value();
					val1 = read_text_value();
					sym2 = read_symbol_value();
					val2 = read_text_value();
					if ( sym<0 )
					  { sym=0x28;}
				    if ( !val2 ) 
					  { val2=val1; sym2=sym; }
					if ( sym2<0 )
						sym2 = sym;

					// create submenu item with pointed to futher menu slot
				    add_menuitem( sym, val1, MENUITEM_SUBMENU, (int*)ptr_menu,  0 );

					// THEN create this menu object with pointed to its futher items
					create_submenu( sym2, val2, ptr_item );
				}
				break;

			case '-':	//separator
				if ( autoexec_only_mode )
					break;
				if ( preprocess_menu( level ) ) {
					val1 = read_text_value();
					add_menuitem (0x0 , (val1?val1:LANG_EMPTY_STRING), MENUITEM_SEPARATOR, 0, 0 );
				}
				break;

			case 'm':	//mode
			case 'l':	//load (load but do not run)
			case 'r':	//run
				if ( autoexec_only_mode )
					break;
				
				if ( !preprocess_menu( level ) ) 
					break;

				sym = read_symbol_value();
				val1 = read_text_value();
				if ( !val1 ) break;
				val2 = read_filename_value();
				//if ( !val2 ) break; -> empty mean "reset to default script" (for mode mean "reset mode")
				val3 = read_scriptparam_value(); // {read 0-9,=,comma,bukva; trimed. if empty - say 0 but store ' ')

				if ( type=='l') { func = gui_pmenu_load_script; sym2=0x27;}
				else if ( type=='r') { func = gui_pmenu_run_script; sym2=0x2a;}
				else {
					hash = lang_strhash31(val1);
					func = gui_pmenu_run_as_mode; sym2=0x72;

					// "mode" item have to know hash of its name to store
					add_int_to_stringbuf( hash );

					// check is this autostarted mode script
					if ( hash==conf.scene_script_mode )
						pmenu_autoexec_scene = (char*) val2;
				}

				if (sym<0) {sym=sym2;}

				// Important hint: we can only provide one arg for _PROC, but we need to two arg (scriptname, scriptparams)
				// We transfer only first one and handler know that second one is begin right after first one
				add_menuitem( sym, val1, MENUITEM_PROC, func, val2 );

				break;

			case 'f':	//flt
				if ( autoexec_only_mode )
					break;
				if ( !preprocess_menu( level ) ) 
					break;
				sym = read_symbol_value();
				val1 = read_text_value();
				if ( !val1 ) break;
				val2 = read_filename_value();
				if ( !val2 ) break;
				val3 = read_scriptparam_value(); // {read 0-9,=,comma,bukva; trimed. if empty - say 0 but store ' ')

				if (sym<0) sym=0x2a;
				add_menuitem( sym, val1, MENUITEM_PROC, gui_menu_run_fltmodule, val2 );
				break;

			case 'i':	//item
				if ( autoexec_only_mode )
					break;
				if ( !preprocess_menu( level ) ) 
					break;

				sym = read_symbol_value();
				val1 = read_text_value();
				if ( !val1 ) break;
				val2 = read_text_value();
				if ( !val2 ) { val2=val1;}

				if ( val2 == LANG_MENU_MAIN_TITLE ) {
					if (sym<0)
						sym=0x20;
					if (val1==LANG_MENU_MAIN_TITLE)
						val1=(int)"CHDK Menu";          		// DANGER!!! this ptr will go away after unload
					add_menuitem ( 0x20, val1, MENUITEM_PROC, gui_menu_goto_mainmenu, 0 );
					flag_mainmenu_reference++;
				} else {

					hash = lang_strhash31(val2);
					CMenuItem* item = find_mnu( &root_menu, hash );

					if ( hash==val2 && val2>0 ) {

						// @langid - regular processing
						if ( !item )
							break;

					} else {
						// string - specific processing.
						// on pass1 we can't determine is such item exists in menu because string is not ready
						//  so reserve space for it always
						if ( is_prepare_mode ) {
							count_items++;
							break;
						} else if ( !item ) {
							count_items--;
							break;
						}

					}
					
					add_menuitem( (sym<0?item->symbol:sym), val1, item->type, item->value, item->arg );
					if ( !is_prepare_mode )
						(ptr_item-1)->opt_len = item->opt_len;

				}
				break;

			default:
				;
				// invalid line - skip it
		}

		e = strpbrk(ptr, "\r\n");	//skip rest of string
		//if (e) *e=0;	//?? why this
	}

	if ( count_autoexec )
		add_autoexec_item( 0 );

	if ( autoexec_only_mode )
		return;
	
	// finalize every submenus
	preprocess_menu( 0 );

	// finalize menu with "main menu" if no such one
	if ( !flag_mainmenu_reference )
		add_menuitem ( 0x20, (int)"CHDK Menu", MENUITEM_PROC, gui_menu_goto_mainmenu, 0 );

	close_submenu();
}

//----------------------------------------------------------
int do_parse_cb( char* content, int size )
{
	if ( size <= 0 )
	  return 1;

	// Pass #1: Just count everything we need

	count_menu = count_items = count_string = count_autoexec = 0;

	is_prepare_mode = 1;
	process_parse_cfgfile( content );

	// Prepare to Pass #2: Allocate buffers

	ptr_string = pmenu_string_buf = malloc( count_string );
	ptr_menu   = pmenu_menu_buf	  = malloc( count_menu * sizeof(CMenu) );
	pmenu_items_buf = malloc( count_items * sizeof(CMenuItem) );
	ptr_autoexec = pmenu_autoexec_list = malloc( (count_autoexec) * sizeof(char*) );

	// this items will gone after parsing so allocate them last 
	pmenu_items_tmpbuf		 = malloc( count_items * sizeof(CMenuItem) );
	ptr_level  = pmenu_level_buf = malloc( count_items );

	// for items tmpbuf is filled from file. and postprocess move to main buf
	ptr_item  = pmenu_items_tmpbuf;

	// if fail to allocate anything - no profile menu provided at all
	if ( !pmenu_string_buf ||
		 !pmenu_menu_buf ||
		 !pmenu_level_buf ||
		 !pmenu_items_buf || 
		 !pmenu_items_tmpbuf ) 
	{
		reset_profile_menu();
		return 1;
	}

	// Pass #2: Actually fillup arrays

	is_prepare_mode = 0;
	process_parse_cfgfile( content );
	
	postprocess_parse();

	// free unneded resources
	free( pmenu_level_buf ); 	pmenu_level_buf=0;
	free( pmenu_items_tmpbuf ); pmenu_items_tmpbuf=0;	
	return 0;
}

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

  // we maniplate with menu structures so check its API ver to make sure that it is has same size and struct
  if ( !API_VERSION_MATCH_REQUIREMENT( gui_version.menu_api, 1, 0 ) )	
	  return 1;

  // conf.script_scene_mode appear in conf v2.3
  if ( !API_VERSION_MATCH_REQUIREMENT( conf.api_version, 2, 3 ) )	
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


  // profmenu.flt?[0]=mode&[1]=path_to_file

  if ( argn > 1 ) {
	// mode= 0-regular_load, 1=autoexec_only_load
	autoexec_only_mode = 0;
	if ( arguments[0]==1 )
		autoexec_only_mode = 1;

	reset_profile_menu();
    load_from_file( (char*)arguments[1], do_parse_cb );	// make main processing cycle
  }

  return 0;
}


/******************** Module Information structure ******************/

struct ModuleInfo _module_info = {	MODULEINFO_V1_MAGICNUM,
									sizeof(struct ModuleInfo),

									ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
									ANY_PLATFORM_ALLOWED,		// Specify platform dependency
									MODULEINFO_FLAG_SYSTEM,		// flag
									(int32_t)"Profile Menu System",	// Module name
									1, 0,						// Module version
									0
								 };

/*************** END OF AUXILARY PART *******************/

