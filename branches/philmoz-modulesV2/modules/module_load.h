#ifndef __MODULE_LOAD_H__
#define __MODULE_LOAD_H__

// Module definitions for inclusion into core CHDK files.

#include "module_def.h"

#define MODULES_PATH "A/CHDK/MODULES"

// Struct for symbol hash table entries
typedef struct
{
    uint32_t    hash;
    const void  *address;
} sym_hash;

// Base typedefs
//-------------------

typedef int (*_module_bind_t)( void** chdk_export_list );

enum ModuleUnloadMode
{
	DO_NOT_UNLOAD,	// load, run and then leave
    UNLOAD_IF_ERR,	// load, run. if module was not loaded yet and have no run handler, unload it after
    UNLOAD_ALWAYS	// load, run and then unload
};

// Common module functions
//-------------------------

int module_check_is_exist(char* name);
int module_find(char * name );
int module_load(char* name, _module_bind_t callback);
int module_run(char* name, _module_bind_t callback, int argn, void* args, enum ModuleUnloadMode unload_after);
void module_unload(char* name);
void module_unload_idx(int module_idx);
const void* module_find_symbol_address(uint32_t importid);

// Flag for modules which couldn't be safely autounloaded (lua, basic,..)
#define MODULE_FLAG_DISABLE_AUTOUNLOAD 1
void module_set_flags(unsigned int idx, char value);

void* module_get_adr(unsigned int idx);

// Asynchronous unloading
//-------------------------
void module_async_unload_allrunned(int enforce);
void module_tick_unloader();

#endif /* __MODULE_LOAD_H__ */
