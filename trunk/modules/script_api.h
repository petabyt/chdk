#ifndef SCRIPT_API_H
#define SCRIPT_API_H

// Module interface for script languages (Lua and uBasic)
struct libscriptapi_sym 
{
	int version;

    int     (*script_start)( char const* script, int is_ptp ); // initialize and load script
    int     (*script_run)( void );          // run script timeslice
    void    (*script_reset)(void);
    void    (*set_variable)(int varnum, int value);
    void    (*set_as_ret)(int as_ret);      // save 'return' value from action stack code (e.g. motion detect, shoot)
    int     (*run_restore)( void );         // run the "restore" function at the end of a script
};

extern struct libscriptapi_sym* libscriptapi;
extern struct libscriptapi_sym* module_script_lang_load(const char*);

#endif
