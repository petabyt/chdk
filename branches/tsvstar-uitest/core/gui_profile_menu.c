/*
	MODULE "PROFILE MENU SYSTEM"
	
	PURPOSE:
		- Load and parse profile menu config file
			So it produce from config menu ready to use menu hierarchy

	HOW TO RUN:
		argv[0]=mode, argv[1]=pmenu_file_name, argv[]=different for different modes
		See _module_run() for details

NOTES:
	"Profile menu" is kind of userMenu. It could be toggled on/off.
	It is loaded on_demand on first menu open (!NO WE HAVE TO PROCESS AUTOEXEC LIST!)
*/

#include "stdlib.h"
#include "lang.h"
#include "gui.h"
#include "gui_lang.h"
#include "gui_menu.h"
#include "profiles.h"

#include "gui_mbox.h"
#include "gui_user_menu.h"
#include "conf.h"
#include "modules.h"
#include "module_load.h"

//-------------------------------------------------------------------
//			Imported functions
//-------------------------------------------------------------------

//-------------------------------------------------------------------
//			Global variables sections
//-------------------------------------------------------------------

int module_idx=-1;

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

enum PMenuParseModeEnum {
	MODE_PREPARE,				// pass1: calculate size requirements
	MODE_LOAD_MENU,				// regular menu processing

	MODE_COPY_MENUITEM,			// edit: copy part [start_idx; stop_idx)
	MODE_COPY_SELECTED_ITEM,	// edit: copy part start_idx..end_chain(while depth drop lower then level)
	MODE_COPY_AUTOEXEC,			// edit: copy autoexec part [start_idx, stop_idx) 

	MODE_STOP					// stop this pass
};

static char* pmenu_content;		// content of (source) profile menu cfg file

static int parse_mode;			// mode of process_parse_cfgfile
static int cur_level=0;			// current submenu level
static char* ptr;				// main pointer thru .cfg content
static int autoexec_only_mode;	// 0=regular_processing, 1=light processing (load autoexec symbols only)
static int cur_item_level;		// level of current item

/////////////// FOR EDIT FEATURE ////////////////

static int   edit_op, ed_val1, ed_val2;	// parameter of PMENU_EDIT_OP

static char* pmenufile_name;	// to write changed file

static char* ptr_bol;			// pointer to begin of current line
static char* tgt_file_buf;		// here new file is assembled
static char* ptr_tgt_file;		// pointer going in tgt_file_buf
static int   tgt_file_size;		// result size of tgt_file

static int start_idx;           // process starting from this menuidx   [-1=no limit]
static int stop_idx;			// stop processing before this menuidx (not including) [-1=no limit]
static int flag_do_fill;		// if <>0 mean only virtual processing (to skip removed part). nothing copied

#ifdef EDIT_FEATURE

static int stop_level;			// >=0 - end level condition (to stop MODE_COPY_SELECTED_ITEM process)
static int depth_offset;		// offset of depth for menu items (to move branch to different level)
static int depth_target;		// >=0 - requested target depth of first item of branch
static int edit_rename_item_idx; // >=0 - idx of menu item which should be renamed
static char* edit_rename_name;	// new name of this item

static int last_item_level;
static int cur_item_level;		// level of current menu item
static int cur_item_idx;		// idx of current menu item
static int cur_autoexec_idx;	// idx of current autoexec item

// Used in process_parse_cfgfile().
// Global are to simplify "rename"
static char type;
static int val1, val2, val3;
static int sym, sym2;
#endif

//=======================================================
// AUXILARY FUNCTIONS
//=======================================================

char* skip_to_pipe(char *ptr)
{
	while (*ptr && *ptr!='\r' && *ptr!='\n' && *ptr!='|') ++ptr;
	return ptr;
}

// PURPOSE:
//		free unneded resources
//		reset pmenu.menu/pmenu.items if no items
void free_tmp_buf()
{
	if (pmenu_level_buf) 	free( pmenu_level_buf );
	pmenu_level_buf=0;
	if (pmenu_items_tmpbuf) free( pmenu_items_tmpbuf );
	pmenu_items_tmpbuf=0;	

	if (tgt_file_buf) ufree( tgt_file_buf );
	tgt_file_buf=0;
	tgt_file_size=0;

	// If no active items - say no profile menu
	// but keep autoexec/strings
	if ( !pmenu.count_items ) { 
		if (pmenu.menu_buf) free(pmenu.menu_buf); 
		pmenu.menu_buf=0; 
		if (pmenu.items_buf) free(pmenu.menu_buf);
		pmenu.items_buf=0; 
	}		
}

// PURPOSE:
//	 finalize everything on error
int pmenu_error()
{
	reset_profile_menu( &pmenu );
	free_tmp_buf();
	return 1;
}

// PURPOSE:
//	 change last char of string to "new_char"
// RETURN:
//		replaced char
char filename_set_lastchar( char new_char )
{
	char *last_char = pmenufile_name+ strlen(pmenufile_name)-1;
	char bak_char = *last_char;

	if ( last_char>=pmenufile_name )
		*last_char = new_char;

	return bak_char;
}

// PURPOSE:
//	 store file and its backup copy
// PARAMETERS:
//	new_content, new_size - new content
//  old_content, old_size - previous content
//	last_sym			  - backup extension (change last symbol to this)
void store_with_backup( char* new_content, int new_size, char* old_content, int old_size, char last_sym )
{
	int fd;
	char bak_char = filename_set_lastchar( last_sym );

	fd = safe_open( pmenufile_name, O_WRONLY|STD_O_CREAT|STD_O_TRUNC, 0777 );
	if ( fd>0 )
	{
		write( fd, old_content, old_size );
		close(fd);

		// Store new file	
		filename_set_lastchar( bak_char );
		fd = safe_open( pmenufile_name, O_WRONLY|STD_O_CREAT|STD_O_TRUNC, 0777 );
		if ( fd>0 )
		{
			write( fd, new_content, new_size );
			close(fd);
		}		
	}
}

//=======================================================
//			Add to string buffer
//=======================================================

// PURPOSE:
// add to ptr_string_buf "size" chars from string "str" and close with \0
int add_string( char* str, int size )
{
	char* cur_str = ptr_string;

	switch( parse_mode )
	{
	  case MODE_PREPARE: 
		count_string+=size+1;	
		return -1;
	  case MODE_COPY_MENUITEM: 	 
	  case MODE_COPY_SELECTED_ITEM: 	 
		if (!ptr_string)
			return -1;
	  case MODE_LOAD_MENU: 	 
		if ( size ) {
			memcpy( ptr_string, str, size );
			ptr_string += size;
		}
		*ptr_string++ = 0;
		return (int)cur_str;
	  default:
		return -1;
	}
}

//=======================================================
//			Add to target file buffer ( edit operations)
//=======================================================

#ifdef EDIT_FEATURE

// 
void add_line_to_tgt( int level, char* str, int size )
{
	if ( !flag_do_fill )
		return;
	if ( !str || !size )
		return;

	if ( depth_target>=0 ) {
		depth_offset = depth_target-level;
		level=depth_target;
		depth_target=-1;
	}

	for( ;level>0; level-- )
	   *ptr_tgt_file++ = '>';

	memcpy( ptr_tgt_file, str, size );
	ptr_tgt_file += size;
	*ptr_tgt_file++ = '\n';
}



void _add_sym_to_tgt( int symbol )
{
	if ( symbol>=0) {
		sprintf( ptr_tgt_file,"(%x)", symbol );
		ptr_tgt_file+=strlen(ptr_tgt_file);
	}
}
void _add_value_to_tgt( int value )
{
	if ( value>0 ) {

		if ( (int)lang_str(value)!=value ) 
		  sprintf( ptr_tgt_file,"@%d", value );
		else
		  strcpy( ptr_tgt_file, (char*) value );

		ptr_tgt_file+=strlen(ptr_tgt_file);
	}

	*ptr_tgt_file++ = '|';
}

static void add_and_rename_item_to_tgt()
{
	int size;
	int level = cur_item_level;

	for( ;level>0; level-- )
	   *ptr_tgt_file++ = '>';

	*ptr_tgt_file++ = type;
	*ptr_tgt_file++ = '|';

	_add_sym_to_tgt(sym);
	_add_value_to_tgt( (int)edit_rename_name );
	_add_sym_to_tgt(sym2);
	_add_value_to_tgt(val2);
	_add_value_to_tgt(val3);
	*ptr_tgt_file++ = '\n';
}

#endif

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
		add_string( "", 0 );
		return 0;
	}

	return add_string( b, (e-b) );
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

	return add_string( b, e-b );
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

			if ( (*e<'0' || *e>'9') && *e!='-' ) {
				ptr=e;
				wait_comma=1;
				continue;
			}

			cur_param++;

			*tgt++ = *ptr;	// copy varname
			*tgt++ = '=';	// copy '='
			ptr=e;
			if ( *ptr=='-')
				*tgt++ = *ptr++;
		
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

		add_string(" ", 1);
		return 0;
	}

	return add_string( scriptparam, (tgt-scriptparam) );
}

//====================================
// menu-related processing functions 
//====================================

void add_menuitem( int symbol, int titleid, int type, void* value, int arg )
{
	switch( parse_mode )
	{
	  case MODE_PREPARE:
		count_items++;
		break;
	  case MODE_LOAD_MENU:
		memset(ptr_item,0,sizeof(CMenuItem));
		ptr_item->symbol = (symbol<0) ? 0x5c : symbol;
		ptr_item->type = type;
		ptr_item->text = titleid;
		ptr_item->value = value;
		ptr_item->arg = arg;
		ptr_item++;

		*ptr_level = cur_level;
		ptr_level++;
		break;
#ifdef EDIT_FEATURE
	  case MODE_COPY_MENUITEM:
		cur_item_idx++;
		last_item_level=cur_level;
		if ( stop_idx>=0 && cur_item_idx >= stop_idx) {
		    parse_mode = MODE_STOP;
			break;
		}

		if ( start_idx<0 || cur_item_idx >= start_idx) {

			if (!titleid || (type & MENUITEM_MASK)==MENUITEM_UP)
				break;

			if ( cur_item_idx==edit_rename_item_idx ) {

				// special case: assemble new line from val/sym
				add_and_rename_item_to_tgt();
				break;
			}

			add_line_to_tgt( cur_item_level+depth_offset, ptr_bol, (int)(ptr-ptr_bol) );
		}
		break;
	  case MODE_COPY_SELECTED_ITEM:
		cur_item_idx++;
		last_item_level=cur_level;
		if ( stop_level>=0 && cur_level<=stop_level ) {
		    parse_mode = MODE_STOP;
			break;
		}

		if ( start_idx<0 || cur_item_idx >= start_idx) {
			if ( stop_level<0 )
				stop_level=cur_level;
			if (!titleid || (type & MENUITEM_MASK)==MENUITEM_UP)
				break;
			add_line_to_tgt( cur_item_level+depth_offset, ptr_bol, (int)(ptr-ptr_bol) );
		}
		break;
#endif
	  default:		// no action needed for COPY_AUTOEXEC mode
		break;
	}
}

void create_submenu( int symbol, int titleid, CMenuItem *menuitem_ptr ) 
{
	cur_level++;
	switch( parse_mode )
	{
	  case MODE_PREPARE:
		count_menu++;
		break;
	  case MODE_LOAD_MENU:
		ptr_menu->symbol = (symbol<0) ? 0x20 : symbol;
		ptr_menu->title = titleid;
		ptr_menu->on_change = 0;
		ptr_menu->menu = menuitem_ptr;
		ptr_menu++;
		break;
	  default:		// no action needed for COPY modes
		break;
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

void add_autoexec_item( char* ptr_str )
{
	switch( parse_mode )
	{
	  case MODE_PREPARE:
		pmenu.count_autoexec++;
		break;
	  case MODE_LOAD_MENU:
		*ptr_autoexec++ = ptr_str;
		break;
#ifdef EDIT_FEATURE
	  case MODE_COPY_AUTOEXEC:
		cur_autoexec_idx++;
		if ( stop_idx>=0 && cur_autoexec_idx >= stop_idx) {
		    parse_mode = MODE_STOP;
			break;
		}

		if ( start_idx<0 || cur_autoexec_idx >= start_idx) {
			if ( ptr_str )
				add_line_to_tgt( 0, ptr_bol, ptr-ptr_bol );
		}
		break;
#endif
	  default:	// no action for COPY_ITEM modes
		break;
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
	CMenuItem* tgt_p = pmenu.items_buf;
	short*     index_p = pmenu.itemidx_buf;
	
	int level;
    int i,idx_item;

	//cycle thru all menus
	for( i=0; i<count_menu; i++) {

		// find out idx of its first item in menuitem_buf
		src_p=(CMenuItem*)pmenu.menu_buf[i].menu;
		idx_item = (src_p-pmenu_items_tmpbuf);
		if ( idx_item<0 ) continue;	// sanity check

		level=pmenu_level_buf[idx_item];
		if ( level<0 ) continue;
		
		pmenu.menu_buf[i].menu = (const CMenuItem*)tgt_p;

		// collect to target buf items of this menu
		for ( ; idx_item<count_items; idx_item++ ) {

			if ( pmenu_level_buf[idx_item]!=level )
				continue;
			*index_p++ = idx_item;
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
void process_parse_cfgfile( int mode, int start, int stop, int fill )
{
	char *e;
	
	int hash;
	menuproc_t* func;

#ifndef EDIT_FEATURE
	int cur_item_level;

	char type;
	int val1, val2, val3;
	int sym, sym2;
#endif
	int sym1;

	int flag_mainmenu_reference=0;

	ptr = pmenu_content;                // start parsing from begining
	ptr_string = pmenu.string_buf;		// reinitialize tgt string ptr to beginning (could be multiple 'real' passes)

	// store pass parameters
	parse_mode   = mode;
    start_idx	 = start;
	stop_idx 	 = stop;
	flag_do_fill = fill;

	// init processing variables
	cur_level=-1;
#ifdef EDIT_FEATURE
    cur_item_idx=-1;
	cur_autoexec_idx=-1;
	depth_offset=0;
	stop_level=-1;

	// optimizations
	switch ( parse_mode )
	{
		case MODE_COPY_MENUITEM:
		case MODE_COPY_SELECTED_ITEM:
			autoexec_only_mode=0;
			break;
		case MODE_COPY_AUTOEXEC:
			autoexec_only_mode=1;
			break;
	}
#endif

	if ( parse_mode==MODE_PREPARE ) {
		count_menu = count_items = count_string = pmenu.count_autoexec = 0;
	}


	// initialize root menu
	if ( !autoexec_only_mode )
		create_submenu( 0x20, root_menu.title, ptr_item );

    e = pmenu_content-1;
    while(e) {

		if ( parse_mode == MODE_STOP ) return;

        ptr = e+1;
        while (*ptr=='\r' || *ptr=='\n' || *ptr==' ' || *ptr=='\t' ) ++ptr; //skip empty lines and empty lead space

		cur_item_level=0;
		while ( *ptr=='>' ) { cur_item_level++; ptr++; }

		ptr_bol = ptr;						// store begin of line

		type = *ptr;
		
		ptr = skip_to_pipe(ptr);
		if (*ptr=='|') ptr++;
		
		sym2=-1;

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
				if ( preprocess_menu( cur_item_level ) )
				{
					sym = read_symbol_value();
					val1 = read_text_value();
					sym2 = read_symbol_value();
					val2 = read_text_value();
					sym1 = ( sym<0 )?0x28:sym;
				    if ( !val2 ) 
					  { val2=val1; sym2=sym; }
					val3 = 0;

					// create submenu item with pointed to futher menu slot
				    add_menuitem( sym1, val1, MENUITEM_SUBMENU, (int*)ptr_menu,  0 );

					// THEN create this menu object with pointed to its futher items
					create_submenu( (sym2<0?sym1:sym2), val2, ptr_item );
				}
				break;

			case '-':	//separator
				if ( autoexec_only_mode )
					break;
				if ( preprocess_menu( cur_item_level ) ) {
					val1 = read_text_value();
					val2 = val3 = 0;
					add_menuitem (0x0 , (val1?val1:LANG_EMPTY_STRING), MENUITEM_SEPARATOR, 0, 0 );
				}
				break;

			case 'l':	//load (load but do not run)
			case 'r':	//run
				if ( autoexec_only_mode )
					break;
			case 'm':	//mode
				
				if ( !preprocess_menu( cur_item_level ) ) 
					break;

				sym = read_symbol_value();
				val1 = read_text_value();
				if ( !val1 ) break;
				val2 = read_filename_value();
				//if ( !val2 ) break; -> empty mean "reset to default script" (for mode mean "reset mode")
				val3 = read_scriptparam_value(); // {read 0-9,=,comma,bukva; trimed. if empty - say 0 but store ' ')

				if ( type=='l') { func = gui_pmenu_load_script; sym1=0x27;}
				else if ( type=='r') { func = gui_pmenu_run_script; sym1=0x2a;}
				else {
					hash = lang_strhash31(val1);
					func = gui_pmenu_run_as_mode; sym1=0x72;

					// "mode" item have to know hash of its name to store
					// store title hash "as is" (integer) to string buf
					add_string( (char*)&hash, sizeof(int) );

					// check is this autostarted mode script
					if ( hash && hash==conf.scene_script_mode )
						pmenu.autoexec_scene = (char*) val2;

				}

				// Important hint: we can only provide one arg for _PROC, but we need to two arg (scriptname, scriptparams)
				// We transfer only first one and handler know that second one is begin right after first one
				add_menuitem( (sym<0?sym1:sym), val1, MENUITEM_PROC, func, val2 );

				break;

			case 'f':	//flt
				if ( autoexec_only_mode )
					break;
				if ( !preprocess_menu( cur_item_level ) ) 
					break;
				sym = read_symbol_value();
				val1 = read_text_value();
				if ( !val1 ) break;
				val2 = read_filename_value();
				if ( !val2 ) break;
				val3 = read_scriptparam_value(); // {read 0-9,=,comma,bukva; trimed. if empty - say 0 but store ' ')

				add_menuitem( (sym<0?0x2a:sym), val1, MENUITEM_PROC, gui_menu_run_fltmodule, val2 );
				break;

			case 'i':	//item
				if ( autoexec_only_mode )
					break;
				if ( !preprocess_menu( cur_item_level ) ) 
					break;

				sym = read_symbol_value();
				val1 = read_text_value();
				if ( !val1 ) break;
				val2 = read_text_value();
				if ( !val2 ) { val2=val1;}
				val3=0;

				if ( val2 == LANG_MENU_MAIN_TITLE ) {

					// Special case: item "Main menu"
					if (val1==LANG_MENU_MAIN_TITLE)
						val1=LANG_MENU_GOTO_MAINMENU;
					add_menuitem ( (sym<0?0x20:sym), val1, MENUITEM_PROC, gui_pmenu_goto_mainmenu, 0 );
					flag_mainmenu_reference++;
					break;
				}

				// try to find target item
				hash = lang_strhash31(val2);
				CMenuItem* item = (val2<0)?0:find_mnu( &root_menu, hash );

				if ( hash==val2 && val2>0 ) {

					// @langid - regular processing
					if ( !item )
						break;

				} else {
					// string - specific processing.
					// on pass1 we can't determine is such item exists in menu because string is not ready
					//  so reserve space for it always

					if ( parse_mode==MODE_PREPARE ) {

						// always reserve space for item.
						count_items++;
						break;
					} else if ( !item ) {

						// if no such item exist on real pass
						// or we can't check (assemble passes)
						// add it as "no-action" item to consistence
						add_menuitem( (sym<0?0x2a:sym), val1, MENUITEM_PROC, gui_pmenu_unknown_map, 0 );
						break;
					}

				}
				
				add_menuitem( (sym<0?item->symbol:sym), val1, item->type, item->value, item->arg );
				if ( parse_mode == MODE_LOAD_MENU )
					(ptr_item-1)->opt_len = item->opt_len;

				break;

			default:
				;
				// invalid line - skip it
		}

		e = strpbrk(ptr, "\r\n");	//skip rest of string
		//if (e) *e=0;	//?? why this
	}

#ifdef EDIT_FEATURE
	// remember last stored item level
	int last_level = (last_item_level<0)?0:last_item_level;
#endif

	if ( pmenu.count_autoexec )
		add_autoexec_item( 0 );

	if ( autoexec_only_mode )
		return;
	
	// finalize every submenus
	preprocess_menu( 0 );

	// finalize menu with "main menu" if no such one
	if ( !flag_mainmenu_reference )
		add_menuitem ( 0x20, LANG_MENU_GOTO_MAINMENU, MENUITEM_PROC, gui_pmenu_goto_mainmenu, 0 );

	close_submenu();

#ifdef EDIT_FEATURE
	// Write last real item level
	if ( parse_mode!= MODE_PREPARE &&
		 parse_mode!= MODE_LOAD_MENU ) 
	{
		last_item_level = last_level;
	}
#endif

	// Store to core CHDK values
	pmenu.count_items = count_items;
	pmenu.count_menu  = count_menu;
}

//----------------------------------------------------------
int do_load_process_cb( char* content, int size )
{
	if ( size <= 0 )
	  return 1;

	pmenu_content = content;

	// PASS #1: Just count everything we need
	process_parse_cfgfile( MODE_PREPARE, -1, -1,  1);

	// PREPARE TO PASS #2: Allocate buffers

	ptr_string = pmenu.string_buf = malloc( count_string +1 );
	ptr_menu   = pmenu.menu_buf	  = malloc( count_menu * sizeof(CMenu) +1 );
	pmenu.items_buf = malloc( count_items * sizeof(CMenuItem) +1 );
	pmenu.itemidx_buf = malloc( (count_items) * sizeof(short) +1 );
	ptr_autoexec = pmenu.autoexec_list = malloc( (pmenu.count_autoexec) * sizeof(char*) +1 );

	// this items will gone after parsing so allocate them last 
	pmenu_items_tmpbuf		 = malloc( count_items * sizeof(CMenuItem) +1 );
	ptr_level  = pmenu_level_buf = malloc( count_items +1 );

	// for items tmpbuf is filled from file. and postprocess move to main buf
	ptr_item  = pmenu_items_tmpbuf;

	// if fail to allocate anything - no profile menu provided at all
	if ( !pmenu.string_buf ||
		 !pmenu.autoexec_list ||
		 !pmenu.menu_buf ||
		 !pmenu_level_buf ||
		 !pmenu.items_buf || 
		 !pmenu_items_tmpbuf ||
		 !pmenu.itemidx_buf ) 
	{
		return pmenu_error();
	}

	// PASS #2: Actually fillup arrays

	process_parse_cfgfile( MODE_LOAD_MENU, -1, -1,  1);			// pass1: do load

	postprocess_parse();

	free_tmp_buf();
	return 0;
}

void prepare_load_profile_menu( int autoexec )
{
	autoexec_only_mode=autoexec;
	// Store current values of profile menu
	struct STD_stat st;
	if ( safe_stat(pmenufile_name, &st)!=0 ) 
	{
		st.st_size=0;
		st.st_mtime=0;
	}
	pmenu.file_size = st.st_size;
	pmenu.file_mtime = st.st_mtime; 

	reset_profile_menu( &pmenu );
}

// =========  EDIT PROCESSING =================

#ifdef EDIT_FEATURE

static char empty_tmp_buf[2] = {0, 0};		// empty buf to correct process empty/absent file case

// PURPOSE
//		"load_file" processing callback for edit operations
//		Global edit_op, ed_val1, ed_val2 are used to determine operation and parameters
int do_edit_process_cb( char* content, int size )
{
	// Empty file is allowed for add_to end operation only
	if ( size <= 0 ) {
		if ( ed_val1>=0 || 
			 (edit_op!=PMENU_OP_AUTOEXEC_ADD && edit_op!=PMENU_OP_ADD) )
			return 1;

		if ( !content )
			content = empty_tmp_buf;
		size=0;
	}

	pmenu_content = content;

	char* edit_new_str = 0;                    
	if ( edit_op== PMENU_OP_ADD || 
		 edit_op== PMENU_OP_RENAME || 
		 edit_op== PMENU_OP_AUTOEXEC_ADD )
	{
	  edit_new_str = (char*)ed_val2;
	}

	// PASS #1: count sizes
	process_parse_cfgfile( MODE_PREPARE, -1, -1,  1);

	// PREPARE TO ASSEMBLE PASSES

	// Allocate string buf to correct processing "real" pass ( required only for RENAME )
	if ( edit_op == PMENU_OP_RENAME ) {
		ptr_string = pmenu.string_buf = malloc( count_string+1 );
		if ( !pmenu.string_buf ) 
			return pmenu_error();
	}


	// Allocate big enough buffer to contain target file
	tgt_file_buf = umalloc(size +									/* base size */
						   10 +										/* reserve for eol */
						   (edit_new_str?strlen(edit_new_str):0) +	/* size of added/rename str */
						   10*count_items							/* reserve for item depth change if move (per item) */
						 );
	ptr_tgt_file = tgt_file_buf;

	// if fail to allocate anything - no profile menu provided at all
	if ( !tgt_file_buf ) 
		return pmenu_error();

	// ASSEMBLE PASSES: assemble tgt file depending on requested operation

	depth_target=-1;			// no specific depth processing by default
	edit_rename_item_idx=-1;    // no specific renaming processing by default

	int stoped_at;
	switch ( edit_op )
	{
		case PMENU_OP_ADD:					// add item:	val1=before_idx(-1=to end), val2=string
			if ( ed_val1>= count_items )
				ed_val1=-1;

			process_parse_cfgfile( MODE_COPY_AUTOEXEC, -1, -1,  1);				// copy autoexecs
			process_parse_cfgfile( MODE_COPY_MENUITEM, -1, ed_val1, 1);			// copy items before

			flag_do_fill = 1;
			add_line_to_tgt( last_item_level, edit_new_str, strlen(edit_new_str) ); // add item with same depth as "before item"

			if ( ed_val1>=0 )
				process_parse_cfgfile( MODE_COPY_MENUITEM, ed_val1, -1, 1);	// copy rest of menu items

			break;
				
		case PMENU_OP_DEL:					// delete item: val1=item_idx
			if ( ed_val1<0 || ed_val1>= count_items )
				return pmenu_error();

			process_parse_cfgfile( MODE_COPY_AUTOEXEC, -1, -1,  1);				// copy autoexecs
			process_parse_cfgfile( MODE_COPY_MENUITEM, -1, ed_val1, 1);			// copy items before
			process_parse_cfgfile( MODE_COPY_SELECTED_ITEM, ed_val1, -1, 0);	// skip removed item and its childs (to determine end)
			process_parse_cfgfile( MODE_COPY_MENUITEM, cur_item_idx, -1, 1);	// copy items after branch (start_idx come from prev op)

			break;

		// Rename item: val1=item_idx, val2=string
		case PMENU_OP_RENAME:

			process_parse_cfgfile( MODE_COPY_AUTOEXEC, -1, -1,  1);				// copy autoexecs
			edit_rename_item_idx=ed_val1;
			edit_rename_name=edit_new_str;
			process_parse_cfgfile( MODE_COPY_MENUITEM, -1, -1, 1);				// copy all menu items (but with flag "rename")
			break;

		// Move item:	val1=before_idx_tgt, val2=from_idx
		case PMENU_OP_MOVE:
			if ( ed_val1<0 || ed_val1>= count_items )
				ed_val1=count_items;
			if ( ed_val1==ed_val2 )
				return pmenu_error();			
			if ( ed_val2<0 || ed_val2>= count_items )
				return pmenu_error();			


			process_parse_cfgfile( MODE_COPY_AUTOEXEC, -1, -1,  1);					// copy autoexecs

			if ( ed_val1 < ed_val2 ) {
				//  xxx1 ..[ins_point] .. xxx2 .. [selection] .. xxx3
				process_parse_cfgfile( MODE_COPY_MENUITEM, -1, ed_val1, 1);			// copy items xxx1
				depth_target = last_item_level; 
				process_parse_cfgfile( MODE_COPY_SELECTED_ITEM, ed_val2, -1, 1);	// copy selection (first item have same depth as "before item")
				stoped_at=cur_item_idx;
				process_parse_cfgfile( MODE_COPY_MENUITEM, ed_val1, ed_val2, 1);	// copy items xxx2
				process_parse_cfgfile( MODE_COPY_MENUITEM, stoped_at, -1, 1);		// copy items xxx3
			} else {
				//  xxx1 .. [selection] .. xxx2 .. [ins_point] .. xxx3
				process_parse_cfgfile( MODE_COPY_MENUITEM, -1, ed_val2, 1);			// copy items xxx1 
				process_parse_cfgfile( MODE_COPY_SELECTED_ITEM, ed_val2, -1, 0);	// skip selection
				stoped_at = cur_item_idx;
				if ( ed_val1 < cur_item_idx )										// error - target is inside selection (cycled move)
					return pmenu_error();
				process_parse_cfgfile( MODE_COPY_MENUITEM, stoped_at, ed_val1, 1); 	// copy xxx2
				depth_target = last_item_level; 
				process_parse_cfgfile( MODE_COPY_SELECTED_ITEM, ed_val2, -1, 1);	// copy selection
				process_parse_cfgfile( MODE_COPY_MENUITEM, ed_val1, -1,	1); 		// copy xxx3
			}
			break;

		// Add autoexec item: val1=-1, val2=string
		case PMENU_OP_AUTOEXEC_ADD:
			process_parse_cfgfile( MODE_COPY_AUTOEXEC,  -1, -1, 1);
			add_line_to_tgt( 0, edit_new_str, edit_new_str?strlen(edit_new_str):0 );
			process_parse_cfgfile( MODE_COPY_MENUITEM, -1, -1, 1);
			break;

		// Del autoexec item: val1=autoexec_idx
		case PMENU_OP_AUTOEXEC_DEL:
			if ( ed_val1<0 || ed_val1>= pmenu.count_autoexec )
				return pmenu_error();			
			process_parse_cfgfile( MODE_COPY_AUTOEXEC,  -1, 	ed_val1,  1);	// copy before item
			process_parse_cfgfile( MODE_COPY_AUTOEXEC,  ed_val1+1, -1,	  1);	// copy after item
			process_parse_cfgfile( MODE_COPY_MENUITEM,  -1, 		  -1, 1);
			break;

		default:
			return pmenu_error();
	}

	*ptr_tgt_file = 0;
	tgt_file_size = (ptr_tgt_file - tgt_file_buf);
	store_with_backup(tgt_file_buf, tgt_file_size, pmenu_content, size, '1' );

	reset_profile_menu( &pmenu );

	return 0;
}

// ---------------------------------
// PURPOSE:  Do edit operation 
// ---------------------------------
void do_edit_operation( int op, int val1, int val2 )
{
	// Check if cfg file doesn't changed
	struct STD_stat st;
	if ( safe_stat(pmenufile_name, &st)!=0 ) 
	{
	  st.st_size=0;
	  st.st_mtime=0;
	}

	if ( st.st_size != pmenu.file_size ||
		 st.st_mtime != pmenu.file_mtime ) 
	  return;

	int is_root_pmenu = (root_menu_ptr!=&root_menu);
 
	// Do edit processing

	edit_op   = op;
	ed_val1 = val1;
	ed_val2 = val2;	

	int size;
    char* content = 0;

	if (edit_op!=PMENU_OP_ROLLBACK) {
		// Regular case. Load and process file
		content = load_file( pmenufile_name, &size );

		// close menu
		if ( is_root_pmenu )
			gui_menu_close_menu(1);

		do_edit_process_cb( content, size );

		// reuse new content
		if ( tgt_file_buf )	{
			if ( content ) ufree(content);
			content = tgt_file_buf;
			size = tgt_file_size;
			tgt_file_buf=0;
		}

	}
	else {

		// Special case: rollback from backup file
		int fd;
		char bak_char = filename_set_lastchar( '1' );
		content = load_file( pmenufile_name, &size );

		filename_set_lastchar( bak_char );
		fd = safe_open( pmenufile_name, O_WRONLY|STD_O_CREAT|STD_O_TRUNC, 0777 );
		if ( fd>0 ) {
			if ( content )
				write( fd, content, size );
			close(fd);
		}

		// close menu
		if ( is_root_pmenu )
			gui_menu_close_menu(1);
	}

	// Parse in-memory content
	prepare_load_profile_menu(0);
	do_load_process_cb( content, size );

	if ( content )
		ufree( content );

	extern void adjust_root_menu();

	// reopen menu
	if ( is_root_pmenu )
		gui_menu_reopen_menu(1);
	else
		adjust_root_menu();
}

#endif

// =========  PROCESSING 'HALFSHOOT' ON PMENU ITEM =================

#ifdef EDIT_FEATURE

static void finish_edit() { gui_menu_erase_and_redraw(); module_async_unload(module_idx); }

static int op_item_idx;
static int op_item_action;
static int op_item_name;

// Popup
enum {
	MPOPUP_CUT 					= 0x0001,
	MPOPUP_PASTE 				= 0x0004,
	MPOPUP_DELETE				= 0x0008,
	MPOPUP_DELETE_SEPARATOR 	= 0x0010,
	MPOPUP_INSERT		     	= 0x0020,
	MPOPUP_INSERT_SUBMENU   	= 0x0040,
	MPOPUP_INSERT_SEPARATOR 	= 0x0080,
	MPOPUP_RENAME				= 0x0100,
	MPOPUP_ROLLBACK				= 0x0200
};

static struct mpopup_item popup_main[]= {
        { MPOPUP_INSERT,        LANG_POPUP_SUBM_INSERT },
        { MPOPUP_DELETE,        LANG_POPUP_DELETE },
        { MPOPUP_DELETE_SEPARATOR, LANG_POPUP_DELETE_SEPARATOR },
        { MPOPUP_ROLLBACK,      LANG_POPUP_ROLLBACK },
        { MPOPUP_RENAME,        LANG_POPUP_RENAME  },
        { MPOPUP_CUT,           LANG_POPUP_CUT    },
        { MPOPUP_PASTE,         LANG_POPUP_PASTE  },
        { MPOPUP_CANCEL,        LANG_CANCEL  },
        { 0,					0 },
};

static struct mpopup_item popup_insert[]= {
        { MPOPUP_INSERT_SUBMENU,   LANG_POPUP_SUBMENU },
        { MPOPUP_INSERT_SEPARATOR, LANG_POPUP_SEPARATOR },
		/* INSERT_SCRIPT_AS_RUN
		 * INSERT_SCRIPT_AS_LOAD
		 * INSERT_SCRIPT_AS_MODE
		 */
        { 0,					0 },
};

static void tbox_cb(const char* name)
{
	const char *b = 0;
	const char *e = 0;
	
	// check emptiness + cut '|'
	if (name) {
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

		
	char buf[50];
	switch ( op_item_action )
	{
		case MPOPUP_INSERT_SUBMENU:
			if ( name && e>b ) {
				sprintf(buf,"submenu|%s||",b);
				do_edit_operation( PMENU_OP_ADD, op_item_idx, (int)buf);
			}
			break;
		case MPOPUP_INSERT_SEPARATOR:
			sprintf(buf,"---|%s|", (name && e>b)?b:"" );
			do_edit_operation( PMENU_OP_ADD, op_item_idx, (int)buf);
			break;
		case MPOPUP_RENAME:
			if ( name && e>b ) {
				do_edit_operation( PMENU_OP_RENAME, op_item_idx, (int)b);
			}
			break;
	}		

	finish_edit();
}

static void pmenu_mpopup_insert_cb(unsigned int actn) {
    switch (actn) {
	    case MPOPUP_INSERT_SUBMENU:
			op_item_action = actn;
            if (module_tbox_load()) {
                module_tbox_load()->textbox_init(LANG_POPUP_SUBMENU, LANG_PROMPT_ENTER_TITLE, "", 25, tbox_cb, 0);
				return;
			}
			break;
	    case MPOPUP_INSERT_SEPARATOR:
			op_item_action = actn;
            if (module_tbox_load()) {
                module_tbox_load()->textbox_init(LANG_POPUP_SEPARATOR, LANG_PROMPT_ENTER_TITLE, "", 25, tbox_cb, 0);
				return;
			}
			break;
	}

	finish_edit();
}

static void pmenu_mpopup_main_cb(unsigned int actn) {

    switch (actn) {
	    case MPOPUP_INSERT:
			module_mpopup_init( popup_insert, MPOPUP_INSERT_SEPARATOR|MPOPUP_INSERT_SUBMENU, pmenu_mpopup_insert_cb, 0);
			// do not exit
			return;
        case MPOPUP_RENAME:
			op_item_action = actn;
            if (module_tbox_load()) {
                module_tbox_load()->textbox_init(LANG_POPUP_RENAME, LANG_PROMPT_RENAME, lang_str(op_item_name), 25, tbox_cb, 0);
				// do not exit
				return;
			}			
            break;
        case MPOPUP_DELETE:
			do_edit_operation( PMENU_OP_DEL, op_item_idx, 0);
            break;
        case MPOPUP_DELETE_SEPARATOR:
			if ( op_item_idx>0 )
				do_edit_operation( PMENU_OP_DEL, op_item_idx-1, 0);
            break;
        case MPOPUP_PASTE:
			if ( pmenu.editop_cut_idx>=0 && 
				 pmenu.editop_cut_idx!= op_item_idx )
			do_edit_operation( PMENU_OP_MOVE, op_item_idx, pmenu.editop_cut_idx);
            break;
        case MPOPUP_CUT:
			pmenu.editop_cut_idx = op_item_idx;
            break;
        case MPOPUP_ROLLBACK:
			do_edit_operation( PMENU_OP_ROLLBACK, 0, 0 );
			break;
	}

	finish_edit();
}

static void simple_op_cb(unsigned int btn)
{

    if (btn==MBOX_BTN_YES) {
		// DELETE
		do_edit_operation( PMENU_OP_DEL, op_item_idx, 0);
		// do not exit
		return;
	}
	else if (btn==MBOX_BTN_NO) {
		// RENAME
		op_item_action = MPOPUP_RENAME;
		if (module_tbox_load()) {
			module_tbox_load()->textbox_init(LANG_POPUP_RENAME, LANG_PROMPT_RENAME, lang_str(op_item_name), 25, tbox_cb, 0);
			// do not exit
			return;
		}
	}

	finish_edit();
}


static int gui_pmenu_edit_cb( CMenuItem* item, int advanced_mode )
{
	int item_idx = item - pmenu.items_buf;

	if ( item_idx<0 || item_idx>=pmenu.count_items )
		return 1;
		
	if ( item->text==0 )
		return 1;

	op_item_idx = pmenu.itemidx_buf[item_idx];
	op_item_name = item->text;

	if ( !advanced_mode )
	{		
		if ( (item->type & MENUITEM_MASK) == MENUITEM_UP )
			return 1;
		
		gui_mbox_init_adv(LANG_TITLE_PROFMENU, LANG_PROMPT_CHOOSE_OPERATION,  MBOX_BTN_YES_NO_CANCEL|MBOX_DEF_BTN3|MBOX_TEXT_CENTER, 
					simple_op_cb,
               		0, LANG_POPUP_DELETE, LANG_POPUP_RENAME, LANG_MBOX_BTN_CANCEL);

    } else {

		int flags = MPOPUP_INSERT|MPOPUP_ROLLBACK;
		if ( (item->type & MENUITEM_MASK) != MENUITEM_UP )
			flags|=MPOPUP_DELETE|MPOPUP_RENAME|MPOPUP_CUT;
		if ( (item[-1].type & MENUITEM_MASK) == MENUITEM_SEPARATOR )
			flags|=MPOPUP_DELETE_SEPARATOR;
		if ( pmenu.editop_cut_idx>= 0 )
			flags|=MPOPUP_PASTE;
		module_mpopup_init( popup_main, flags, pmenu_mpopup_main_cb, 0);
	}

	return 0;
}

//------- ADD SCRIPT UI ------

enum {
	MPOPUP_INSERT_SCRIPT_AS_LOAD	= 0x0001,
	MPOPUP_INSERT_SCRIPT_AS_RUN		= 0x0002,
	MPOPUP_INSERT_SCRIPT_AS_MODE	= 0x0004,
};

static struct mpopup_item popup_add_script[]= {
        { MPOPUP_INSERT_SCRIPT_AS_LOAD,        LANG_POPUP_AS_LOADSCRIPT },
        { MPOPUP_INSERT_SCRIPT_AS_RUN,         LANG_POPUP_AS_RUNSCRIPT  },
        { MPOPUP_INSERT_SCRIPT_AS_MODE,        LANG_POPUP_AS_MODESCRIPT },
        { 0,					0 },
};

static char* insert_as_type = "";
static char* ed_script_title = "";
static char* ed_script_file = "";
static char* ed_script_paramstr = "";

static void gui_add_script_tbox_cb( const char* title )
{
	char buf[500];
	if ( title ) {
		sprintf(buf,"%s|%s|%s|%s|\n", insert_as_type, title, ed_script_file, ed_script_paramstr );
		do_edit_operation( PMENU_OP_ADD, -1, (int)buf );
		gui_mbox_init( LANG_TITLE_PROFMENU, LANG_MSG_ADDED_SCRIPT_TO_PMENU, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
	}

	finish_edit();
}

static void gui_add_script_mpopup_cb( unsigned int actn )
{
    switch (actn) {
	    case MPOPUP_INSERT_SCRIPT_AS_LOAD:	insert_as_type="load";	break;
		case MPOPUP_INSERT_SCRIPT_AS_RUN:	insert_as_type="run";	break;
		case MPOPUP_INSERT_SCRIPT_AS_MODE:	insert_as_type="mode";	break;
		default:                            finish_edit();			return;
	}

	if (module_tbox_load()) {
		module_tbox_load()->textbox_init(LANG_MENU_ADD_SCRIPT_TO_PMENU, LANG_PROMPT_ENTER_TITLE, ed_script_title, 25, gui_add_script_tbox_cb, 0);
		// do not exit
		return;
	}
	finish_edit();
}

static void gui_pmenu_add_script()
{

	int flags = MPOPUP_INSERT_SCRIPT_AS_LOAD|MPOPUP_INSERT_SCRIPT_AS_RUN|MPOPUP_INSERT_SCRIPT_AS_MODE;
    module_mpopup_init( popup_add_script, flags, gui_add_script_mpopup_cb, 0);
}

//------- ADD ITEM UI ------

static void gui_pmenu_add_item( CMenuItem* item )
{
	char buf[500];
	if ( (int)lang_str(item->text) == item->text )
		sprintf(buf, "\nitem|%s\n", lang_str(item->text));
	else
		sprintf(buf, "\nitem|@%d\n", item->text);

	do_edit_operation( PMENU_OP_ADD, -1, (int)buf );
	sprintf(buf,lang_str(LANG_MSG_ADDED_ITEM_TO_PMENU), lang_str(item->text));
    gui_mbox_init(LANG_MENU_USER_MENU, (int)buf, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
	finish_edit();
}

#endif


// =========  MODULE INIT =================

/***************** BEGIN OF AUXILARY PART *********************
  ATTENTION: DO NOT REMOVE OR CHANGE SIGNATURES IN THIS SECTION
 **************************************************************/

void* MODULE_EXPORT_LIST[] = {
			(void*)EXPORTLIST_MAGIC_NUMBER,		// 0
			(void*)0							// 1
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

  // module shared struct API ver
  if ( !API_VERSION_MATCH_REQUIREMENT( pmenu.api_version, 1, 0 ) )	
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

  // Autounloading is unsafe because it should exists to catch finalization of mpopup
  module_set_flags(module_idx, MODULE_FLAG_DISABLE_AUTOUNLOAD);

  // profmenu.flt?[0]=mode&[1]=path_to_file

  pmenufile_name = (char*)arguments[1];
  if ( argn<2 || !pmenufile_name ) {
	  module_async_unload(module_idx);
	  return 1;
  }

#ifdef EDIT_FEATURE
  // EDIT
  // profmenu.flt?[0]=2&[1]=path_to_file&[2]=editop&[3]=val1&[4]=val2
  if ( argn >=5 && arguments[0]==PMENU_EDIT_OP )
  {
	do_edit_operation( arguments[2], arguments[3], arguments[4] );
	module_async_unload(module_idx);
  }
  // profmenu.flt?[0]=3&[1]=path_to_file&[2]=menuitem_ptr&[3]=advanced_mode
  else if ( argn >= 4 && arguments[0]==PMENU_EDIT_CALLBACK )
  {
	gui_pmenu_edit_cb( (CMenuItem*) arguments[2], arguments[3] );
  } 
  else if ( argn>=5 && arguments[0]==PMENU_ADD_SCRIPT )
  {
	ed_script_title		= (char*)arguments[2];
	ed_script_file		= (char*)arguments[3];
	ed_script_paramstr	= (char*)arguments[4];
	gui_pmenu_add_script();
  }
  else if ( argn>=3 && arguments[0]==PMENU_MMENU_CALLBACK )
  {
	gui_pmenu_add_item( (CMenuItem*) arguments[2] );
  }
  else

#endif
  if ( arguments[0]==PMENU_LOAD || arguments[0]==PMENU_LOAD_AUTOEXEC )
  {
	// REGULAR PROCESSING
	// mode= 0-regular_load, 1=autoexec_only_load

	prepare_load_profile_menu( ( arguments[0]==PMENU_LOAD_AUTOEXEC )?1:0 );
	load_from_file( pmenufile_name, do_load_process_cb );	// make main processing cycle

	module_async_unload(module_idx);
  }

  return 0;
}


// ******************** Module Information structure ****************** //

struct ModuleInfo _module_info = {	MODULEINFO_V1_MAGICNUM,
									sizeof(struct ModuleInfo),

									ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
									ANY_PLATFORM_ALLOWED,		// Specify platform dependency
									MODULEINFO_FLAG_SYSTEM,		// flag
									(int32_t)"Profile Menu System",	// Module name
									1, 0,						// Module version
									0
								 };

// *************** END OF AUXILARY PART ******************* //

