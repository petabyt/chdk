#ifndef SCRIPT_API_H
#define SCRIPT_API_H

// Module interface for script languages (Lua and uBasic)
struct libscriptapi_sym 
{
	int version;

    int     (*script_start)( char const* script, int is_ptp ); // initialize and load script
    void    (*script_run)( void );          // run script timeslice
    int     (*script_finished)(void);
    void    (*script_reset)(void);
    void    (*set_variable)(int varnum, int value);
    void    (*set_md_ret)(int md_ret);
    int     (*run_restore)( void );         // run the "restore" function at the end of a script

    // Error handling
    int     (*error_msg)(char *buf);
    void    (*reset_error)();

    // PTP
    void    (*read_usb_msg)(char *data, unsigned int size);
    void    (*write_usb_msg)(int result);
};

extern struct libscriptapi_sym* libscriptapi;
extern struct libscriptapi_sym* module_script_lang_load(int lang_id);

// Which script language is being used
#define SCRIPT_LANG_UBASIC  0
#define SCRIPT_LANG_LUA     1

#endif
