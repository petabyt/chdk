#ifndef PROFILES_H
#define PROFILES_H

extern void profile_remember();
extern void profile_restore( int do_postprocess );
extern void profile_set_postprocessing();
extern void gui_safe_set_profile(int arg);

//---------------------------------------------

#include "gui_menu.h"


// Common buffers
struct ProfileMenu
{
	int		api_version;
	char**	autoexec_list;		// array of pointers to pairs "scriptname\0scripparam\0" - profile menu autoexecution list
	char*	autoexec_scene;		// pointer to pair "scriptname\0scriptparam\0" of scene to autoexecute (0 - if no one selected)

	char*	string_buf;			// plain array of zero-terminated strings (contain everything)
	CMenu*	menu_buf;   		// array of menu headers
	CMenuItem* items_buf;		// result arrays of menuitems (one by one)
	short* 	itemidx_buf;		// contain correspondance to item idx before reorder

	int count_autoexec;			// num of pairs in pmenu_autoexec_list
	int count_menu;				// num of menu in pmenu_menu_buf
	int count_items;			// num of items in pmenu_item_buf

	int editop_cut_idx;			// if "cut" operation, here stored idx in item_buf of this source item

	int file_size;				// to ensure that files was not changed
	int file_mtime;				// to ensure that files was not changed
};

extern struct ProfileMenu pmenu;


// gui callbacks
extern void gui_pmenu_load_script(int arg);
extern void gui_pmenu_run_script(int arg);
extern void gui_pmenu_run_as_mode(int arg);
extern void gui_pmenu_goto_mainmenu(int arg);
extern void gui_pmenu_unknown_map(int arg);

//
extern char* get_profilemenu_file();
extern int is_pmenu_menu( const CMenu* menu);
extern int pmenu_get_itemidx( const CMenuItem* item );
extern int is_pmenu_item( const CMenuItem* item );

extern void load_profile_menu( int autoexeconly );
extern void reset_profile_menu( struct ProfileMenu *pmenu_p );
extern void autostart_sequence_entry();
extern void do_autoexec_sequence( int async_mode, void (*callback)(), void (*callback_fin)() );

extern void edit_profile_menu_op( const CMenuItem* item );
extern void add_to_profile_menu( char* buf );
extern void move_pmenu_item( const CMenuItem* curr_item, int move_offs );


// pmenu/pmenuedi.flt ? argv[0]=MODE & argv[1]=PMENU_CFG_FILE

// Requested MODE(argv[0])
enum {
	PMENU_LOAD,					// complete load menu
	PMENU_LOAD_AUTOEXEC,		// load autoexec only (obsolete)
	PMENU_EDIT_OP,				// edit operation,  argv[2]=op_code, argv[3]=edval1, argv[4]=edval2
	PMENU_EDIT_CALLBACK			// callback on profile menu item:	argv[2]=CMenuItem_ptr
};


// Operation code( argv[2] for PMENU_EDIT_OP)
enum {
	PMENU_OP_ADD,				// val1=before_idx(-1=to end), val2=string
	PMENU_OP_DEL,				// val1=item_idx
	PMENU_OP_RENAME,			// val1=item_idx, val2=string_item_name
	PMENU_OP_MOVE,				// val1=before_idx_tgt, val2=from_idx
	PMENU_OP_AUTOEXEC_ADD,		// val1=-1, val2=string
	PMENU_OP_AUTOEXEC_DEL,		// val1=autoexec_idx
	PMENU_OP_ROLLBACK
};


#endif
