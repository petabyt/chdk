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


// Base typedefs
//-------------------

#define EXPORTLIST_MAGIC_NUMBER  0x43215678

typedef int (*_module_loader_t)( void** chdk_export_list );
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
int module_load( char* name, _module_loader_t callback);
int module_run(char* name, _module_loader_t callback, int argn, void* args, enum ModuleUnloadMode unload_after);
void module_unload(char* name);

// Flag for modules which couldn't be safely autounloaded (lua, basic,..)
#define MODULE_FLAG_DISABLE_AUTOUNLOAD 1
void module_set_flags(unsigned int idx, char value);

void* module_get_adr(unsigned int idx);


// Asynchronous unloading
//-------------------------
void module_async_unload(unsigned int idx);
void module_async_unload_allrunned(int enforce);
void module_tick_unloader();

// In-module binding to conf.
//---------------------------
#define CONF_BIND_INT(idConf,var)  if ( conf_getValue(idConf, &configVal) == CONF_VALUE ) {	var = configVal.pInt; } else { return 1;}
#define CONF_BIND_COLOR(idConf,var)  if ( conf_getValue(idConf, &configVal) == CONF_VALUE ) {	var = (color*)configVal.pInt; } else { return 1;}
#define CONF_BIND_STR(idConf,var)  if ( conf_getValue(idConf, &configVal) == CONF_CHAR_PTR ) {	var = (char*)configVal.str; } else { return 1;}


#endif /* __MODULE_LOAD_H__ */
