#ifndef __MODULE_LOAD_H__
#define __MODULE_LOAD_H__

#include "gui.h"
#include "gui_draw.h"
#include "flt.h"
#ifndef THIS_IS_CHDK_CORE
#include "module_exportlist.h"
#endif

// This is main CHDK trunk
#define CURRENT_CHDK_BRANCH 1

#define MODULES_PATH "A/CHDK/MODULES"


// Struct for symbol hash table entries
typedef struct
{
    uint32_t    hash;
    void        *address;
} sym_hash;

// Hashed Symbol table for exported symbols
extern sym_hash symbol_hash_table[];


// Base typedefs
//-------------------

#define EXPORTLIST_MAGIC_NUMBER  0x43215678

typedef int (*_module_bind_t)( void** chdk_export_list );
typedef int (*_module_loader_t)( unsigned int* chdk_export_list );
typedef int (*_module_unloader_t)();
typedef int (*_module_run_t)(int moduleidx, int argn, int* arguments);

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
int module_load( char* name, _module_bind_t callback);
int module_run(char* name, _module_bind_t callback, int argn, void* args, enum ModuleUnloadMode unload_after);
void module_unload(char* name);
void module_unload_idx(int module_idx);
void* module_find_symbol_address(uint32_t importid);

// Flag for modules which couldn't be safely autounloaded (lua, basic,..)
#define MODULE_FLAG_DISABLE_AUTOUNLOAD 1
void module_set_flags(unsigned int idx, char value);

void* module_get_adr(unsigned int idx);


// Asynchronous unloading
//-------------------------
void module_async_unload(unsigned int idx);
void module_async_unload_allrunned(int enforce);
void module_tick_unloader();

// API versions check
//---------------------------
#define MAKE_CHDKVER(major,minor,last) (major*10000+minor*100+last)
#define MAKE_API_VERSION(major,minor) ((major<<16)+minor)
#define API_VERSION_MATCH_REQUIREMENT( api_ver, req_major, req_minor ) ((api_ver>>16)==req_major && (api_ver&0xffff)>=req_minor)


#endif /* __MODULE_LOAD_H__ */
