#ifndef SCRIPT_H
#define SCRIPT_H

//-------------------------------------------------------------------
#define SCRIPT_DEFAULT_FILENAME     "A/SCRIPT.LUA"
#define SCRIPT_NUM_PARAMS           26
#define SCRIPT_DEFAULT_DIR			"A/CHDK/SCRIPTS/"

#ifdef OPT_UBASIC
#include "ubasic.h"
#endif

#ifdef OPT_LUA
#include "../core/luascript.h"
#endif

//-------------------------------------------------------------------

extern long kbd_last_clicked;

extern char script_title[36];
extern char script_params[SCRIPT_NUM_PARAMS][28];
extern int script_range_values[SCRIPT_NUM_PARAMS];
extern short script_range_types[SCRIPT_NUM_PARAMS];
extern short script_param_order[SCRIPT_NUM_PARAMS];
extern const char **script_named_values[SCRIPT_NUM_PARAMS];
extern int script_named_counts[SCRIPT_NUM_PARAMS];

//-------------------------------------------------------------------
enum ScriptLoad_Mode_ { SCRIPT_LOAD_DEFAULT_VALUES = 0,
						SCRIPT_LOAD_LAST_PARAMSET,
						SCRIPT_UPDATE_PARAMS };

extern void script_load(const char *fn, enum ScriptLoad_Mode_ saved_params);
extern void script_apply_paramstr( char* param_str, int allow_load_paramset );
extern int load_params_values(const char *fn, int paramset );
extern void save_params_values(int enforce);
extern void script_reset_to_default_params_values();


typedef int (*tmpscr_callb_t)();
extern void temporary_script_load( char* fn, char* paramstr, tmpscr_callb_t callback, int autoexec_flag );
extern void temporary_script_unload();

extern void script_console_add_line(const char *str);
extern void script_print_screen_init();
extern void script_print_screen_end();
extern void script_print_screen_statement(int val);
//-------------------------------------------------------------------

extern const char* paramset_names[10];			// pointer of names of paramsets
extern void load_params_names_cfg();

//-------------------------------------------------------------------

// Requested filename
enum FilenameMakeModeEnum 
	{ 	MAKE_PARAMSETNUM_FILENAME,		// "DATA/scriptname.set" -> cfg_name
		MAKE_PARAMSET_NAMES_FILENAME,	// "CFG/scriptname.cfg"  -> cfg_name
		MAKE_PARAM_TMPRUN_FILENAME,		// "DATA/_params_.old"   -> cfg_param_name
		MAKE_PARAM_FILENAME };			// "DATA/scriptname._%d" -> cfg_param_name

extern const char* make_param_filename( enum FilenameMakeModeEnum mode, const char* fn, int paramset );
extern void make_paramstr( char* tgtbuf );

//-------------------------------------------------------------------

long script_stack_start();
int script_is_running();
void script_end();
long script_start_gui( int autostart );

int script_key_is_pressed( int keyid );
int script_key_is_clicked( int keyid );
int script_keyid_by_name( const char *name );
#ifdef OPT_LUA
long script_start_ptp( char *script );
#endif
void script_wait_and_end();

#endif
