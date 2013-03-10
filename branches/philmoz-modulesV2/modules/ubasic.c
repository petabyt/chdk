#include "camera_info.h"
#include "stdlib.h"
#include "gui.h"

#include "script_api.h"
#include "module_def.h"

/***************** BEGIN OF AUXILARY PART *********************
  ATTENTION: DO NOT REMOVE OR CHANGE SIGNATURES IN THIS SECTION
 **************************************************************/

int ubasic_init(const char *program, int is_ptp);
int ubasic_run(void);
void ubasic_end(void);
void ubasic_set_variable(int varum, int value);
void ubasic_set_as_ret(int md_ret);
int jump_label(char * label);

static int ubasic_run_restore(void)             { return jump_label("restore"); }

/******************** Module Information structure ******************/

libscriptapi_sym _libubasic =
{
    {
         0, 0, 0, 0, 0
    },

    ubasic_init,
    ubasic_run,
    ubasic_end,
    ubasic_set_variable,
    ubasic_set_as_ret,
    ubasic_run_restore,
};

struct ModuleInfo _module_info =
{
    MODULEINFO_V1_MAGICNUM,
    sizeof(struct ModuleInfo),
    {2,0},						// Module version

    ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
    ANY_PLATFORM_ALLOWED,		// Specify platform dependency

    (int32_t)"uBasic",          // Module name
    (int32_t)"Run uBasic Scripts",

    &_libubasic.base,

    {1,0},                      // GUI version
    {0,0},                      // CONF version
    {0,0},                      // CAM SENSOR version
    {0,0},                      // CAM INFO version
};

/*************** END OF AUXILARY PART *******************/
