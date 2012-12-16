#ifndef SCRIPT_H
#define SCRIPT_H

// CHDK Script interface

// Note: used in modules and platform independent code. 
// Do not add platform dependent stuff in here (#ifdef/#endif compile options or camera dependent values)

//-------------------------------------------------------------------
#define SCRIPT_NUM_PARAMS           26

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

extern void script_load(const char *fn);
extern int load_params_values(const char *fn, int paramset );
extern void save_params_values(int enforce);
extern void script_reset_to_default_params_values();

extern void script_console_add_line(const char *str);
extern void script_print_screen_init();
extern void script_print_screen_end();
extern void script_print_screen_statement(int val);
//-------------------------------------------------------------------

extern int script_is_running();
extern void script_end();
extern long script_start_gui( int autostart );

extern int script_key_is_pressed( int keyid );
extern int script_key_is_clicked( int keyid );
extern int script_keyid_by_name( const char *name );
extern long script_start_ptp( char *script );
extern void script_wait_and_end();
//-------------------------------------------------------------------

#endif
