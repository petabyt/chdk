#include "camera_info.h"
#include "stdlib.h"
#include "module_load.h"
#include "module_exportlist.h"
#include "ubasic.h"

// =========  MODULE INIT =================

int module_idx=-1;

/***************** BEGIN OF AUXILARY PART *********************
  ATTENTION: DO NOT REMOVE OR CHANGE SIGNATURES IN THIS SECTION
 **************************************************************/

extern int ubasic_error;
extern const char *ubasic_errstrings[UBASIC_E_ENDMARK];
int ubasic_init(const char *program, int is_ptp);
void ubasic_run(void);
void ubasic_end(void);
int ubasic_finished(void);
int ubasic_linenumber(void);
int ubasic_get_variable(int varnum);
void ubasic_set_variable(int varum, int value);
void ubasic_set_md_ret(int md_ret);
int jump_label(char * label);

static int ubasic_error_msg(char *buf)
{
    if (ubasic_error)
    {
        const char *msg;
        if (ubasic_error >= UBASIC_E_ENDMARK)
        {
            msg = ubasic_errstrings[UBASIC_E_UNKNOWN_ERROR];
        }
        else
        {
            msg = ubasic_errstrings[ubasic_error];
        }
        sprintf(buf, "uBASIC:%d %s ", ubasic_linenumber(), msg);
        return 1;
    }
    return 0;
}

static void ubasic_reset_error(int err)         { ubasic_error = UBASIC_E_NONE; }
static int ubasic_run_restore(void)             { return jump_label("restore"); }

// Dummy routines for API (PTP not supported in ubasic)
static void ubasic_read_usb_msg(char *data, unsigned int size)  {}
static void ubasic_write_usb_msg(int result)                    {}

struct libscriptapi_sym _libubasic =
{
	MAKE_API_VERSION(1,0),		// apiver: increase major if incompatible changes made in module, 
								// increase minor if compatible changes made(including extending this struct)

    ubasic_init,
    ubasic_run,
    ubasic_finished,
    ubasic_end,
    ubasic_set_variable,
    ubasic_set_md_ret,
    ubasic_run_restore,

    ubasic_error_msg,
    ubasic_reset_error,

    ubasic_read_usb_msg,
    ubasic_write_usb_msg,
};

void* MODULE_EXPORT_LIST[] = {
	/* 0 */	(void*)EXPORTLIST_MAGIC_NUMBER,
	/* 1 */	(void*)1,
    &_libubasic
};


//---------------------------------------------------------
// PURPOSE:   Bind module symbols with chdk. 
//		Required function
// PARAMETERS: pointer to chdk list of export
// RETURN VALUE: 1 error, 0 ok
//---------------------------------------------------------
int _module_loader( unsigned int* chdk_export_list )
{
  if ( chdk_export_list[0] != EXPORTLIST_MAGIC_NUMBER )
     return 1;

  if ( !API_VERSION_MATCH_REQUIREMENT( gui_version.common_api, 1, 0 ) )
	  return 1;

  return 0;
}



//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{
  return 0;
}


//---------------------------------------------------------
// PURPOSE: Default action for simple modules (direct run)
// NOTE: Please comment this function if no default action and this library module
//---------------------------------------------------------
int _module_run(int moduleidx, int argn, int* arguments)
{
  module_idx=moduleidx;

  return 0;
}

/******************** Module Information structure ******************/

struct ModuleInfo _module_info = {	MODULEINFO_V1_MAGICNUM,
									sizeof(struct ModuleInfo),

									ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
									ANY_PLATFORM_ALLOWED,		// Specify platform dependency
									0,							// flag
									(int32_t)"uBasic",// Module name
									1, 0,						// Module version
									(int32_t)"Run uBasic Scripts"
								 };


/*************** END OF AUXILARY PART *******************/
