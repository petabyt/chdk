#ifndef PROFILES_H
#define PROFILES_H

extern void profile_remember();
extern void profile_restore( int do_postprocess );
extern void profile_set_postprocessing();
extern void gui_safe_set_profile(int arg);

//---------------------------------------------

#include "gui_menu.h"

// Common buffers
extern char** pmenu_autoexec_list;		// array of pointers to pairs "scriptname\0scripparam\0" - profile menu autoexecution list
extern char* pmenu_autoexec_scene;		// pointer to pair "scriptname\0scriptparam\0" of scene to autoexecute (0 - if no one selected)
extern char* pmenu_string_buf;			// plain array of zero-terminated strings (contain everything)
extern CMenu* pmenu_menu_buf;   		// array of menu headers
extern CMenuItem* pmenu_items_buf;		// result arrays of menuitems (one by one)

extern int count_autoexec;				// num of pairs in pmenu_autoexec_list

// gui callbacks
extern void gui_pmenu_load_script(int arg);
extern void gui_pmenu_run_script(int arg);
extern void gui_pmenu_run_as_mode(int arg);
extern void gui_menu_goto_mainmenu(int arg);

//
extern void load_profile_menu( int autoexeconly );
extern void reset_profile_menu();
extern void autostart_sequence_entry();
extern void do_autoexec_sequence( int async_mode, void (*callback)(), void (*callback_fin)() );


#endif
