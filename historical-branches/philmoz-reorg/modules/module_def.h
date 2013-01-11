#ifndef __MODULE_DEF_H__
#define __MODULE_DEF_H__

// Module definitions for inclusion into module files.

#include "flt.h"

// This is main CHDK trunk
#define CURRENT_CHDK_BRANCH 1

// Base typedefs
//-------------------

#define EXPORTLIST_MAGIC_NUMBER  0x43215678

// Asynchronous unloading
//-------------------------
void module_async_unload(unsigned int idx);

// API versions check
//---------------------------
#define MAKE_CHDKVER(major,minor,last) (major*10000+minor*100+last)
#define MAKE_API_VERSION(major,minor) ((major<<16)+minor)
#define API_VERSION_MATCH_REQUIREMENT( api_ver, req_major, req_minor ) ((api_ver>>16)==req_major && (api_ver&0xffff)>=req_minor)


#endif /* __MODULE_LOAD_H__ */
