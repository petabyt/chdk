/*
 *   CHDK-FLAT Module System.  
 *
 *   (c)2011 Sergey Taranenko aka tsvstar
 *
 *   Specific "shortcuts", dynamic libraries binding
 */

#include "camera_info.h"
#include "console.h"
#include "modules.h"
#include "module_load.h"

/************* GENERIC ******/

static int bind_module_generic( void** export_list, void** lib, int count, int major, int minor )
{
    *lib = 0;

	// Unbind
	if ( !export_list ) {
    	return 0;
  	}

	// Bind
	if ( (unsigned int)export_list[0] != EXPORTLIST_MAGIC_NUMBER )
	     return 1;
  	if ( (unsigned int)export_list[1] < count )
    	 return 1;

	*lib = (void*)export_list[2];

	if ( !*lib )
    	 return 1;
	if ( (major > 0) && !API_VERSION_MATCH_REQUIREMENT( *((int*)(*lib)), major, minor ) ) {
		*lib=0;
		return 1;
	}

	return 0;
}

// Return: 0-fail, addr-ok
static void* module_load_generic(void **lib, char *name, _module_bind_t callback, int flags)
{
    if (*lib == 0)
    {
        int module_idx = module_load(name, callback);
        if ( module_idx < 0 )
            module_unload(name);  
        else
        {
            if (flags)
    	 	    module_set_flags(module_idx, flags);
        }
    }

    return *lib;
}

/************* DYNAMIC LIBRARY RAWOPERATION ******/

static char* rawop_module_name()
{
    switch (camera_sensor.bits_per_pixel)
    {
    case 10:
        return "_rawop10.flt";
    case 12:
        return "_rawop12.flt";
    case 14:
        return "_rawop14.flt";
    default:
        return 0;
    }
}

// This is to minimize sharing sym to use this lib in other modules
struct librawop_sym* librawop;

void module_rawop_unload()
{
	if (librawop)
    {
    	module_unload(rawop_module_name());  
        librawop = 0;
    }
}

static int bind_module_rawop( void** export_list )
{
    return bind_module_generic(export_list, (void**)&librawop, 1, 0, 0);
}

// Return: 0-fail, otherwise - bind list
struct librawop_sym* module_rawop_load()
{
    return module_load_generic((void**)&librawop, rawop_module_name(), bind_module_rawop, 0);
}


/************* DYNAMIC LIBRARY EDGE OVERLAY ******/

// Storage and interface for edge overlay 'image' buffer.
// This is so the previous overlay can survive if the module gets unloaded
// (Need these for the module export list, even if OPT_EDGEOVERLAY is not defined).
static void* saved_edgebuf = 0;
static int saved_edgestate = 0;

void module_restore_edge(void **buf, int *state) { *buf = saved_edgebuf; *state = saved_edgestate; }
void module_save_edge(void* buf, int state)      { saved_edgebuf = buf; saved_edgestate = state; }

#define MODULE_NAME_EDGEOVR "edgeovr.flt"

struct libedgeovr_sym* libedgeovr;

static int bind_module_edgeovr( void** export_list )
{
    return bind_module_generic(export_list, (void**)&libedgeovr, 1, 1, 0);
}

// Return: 0-fail, 1-ok
struct libedgeovr_sym* module_edgeovr_load()
{
    // This flag is because edgeovr called each tick
    //   If module loading failed, then do not try to load it until reboot
    //    (otherwise we will try to load module each tick)
    static int flag_load_fail = 0;

    if ( flag_load_fail==0 )
    {
        module_load_generic((void**)&libedgeovr, MODULE_NAME_EDGEOVR, bind_module_edgeovr, MODULE_FLAG_DISABLE_AUTOUNLOAD);

        if (libedgeovr == 0)
    		flag_load_fail = 1;
    }

    return libedgeovr;
}

// edgeovr module will never unload to keep its picture
// void module_edgeovr_unload() {}


/************* DYNAMIC LIBRARY MOTION DETECT ******/

#define MODULE_NAME_MDETECT "mdetect.flt"

struct libmotiondetect_sym* libmotiondetect;

static int bind_module_motiondetect( void** export_list )
{
    return bind_module_generic(export_list, (void**)&libmotiondetect, 1, 1, 0);
}

// Return: 0-fail, 1-ok
struct libmotiondetect_sym* module_mdetect_load()
{
    return module_load_generic((void**)&libmotiondetect, MODULE_NAME_MDETECT, bind_module_motiondetect, MODULE_FLAG_DISABLE_AUTOUNLOAD);
}

void module_mdetect_unload()
{
	if (libmotiondetect)
    {
    	module_unload(MODULE_NAME_MDETECT);  
        libmotiondetect = 0;
    }
}


/************* DYNAMIC LIBRARY uBasic ******/

#define MODULE_NAME_UBASIC "ubasic.flt"

static struct libscriptapi_sym* libubasic;

static int bind_module_ubasic( void** export_list )
{
    return bind_module_generic(export_list, (void**)&libubasic, 1, 1, 0);
}

static void module_ubasic_unload()
{
	if (libubasic)
    {
    	module_unload(MODULE_NAME_UBASIC);  
        libubasic = 0;
    }
}


/************* DYNAMIC LIBRARY Lua ******/

#define MODULE_NAME_LUA "lua.flt"

static struct libscriptapi_sym* liblua;

static int bind_module_lua( void** export_list )
{
    return bind_module_generic(export_list, (void**)&liblua, 1, 1, 0);
}

static void module_lua_unload()
{
	if (liblua)
    {
    	module_unload(MODULE_NAME_LUA);  
        liblua = 0;
    }
}


/************* DYNAMIC LIBRARY Script language ******/

struct libscriptapi_sym* libscriptapi;

// Which script language is being used
#define SCRIPT_LANG_UBASIC  0
#define SCRIPT_LANG_LUA     1

static int script_lang_id(const char* script_file)
{
    if ((script_file == 0) || (script_file[0] == 0))
        return SCRIPT_LANG_LUA;  // Default script is Lua

    char *ext = strrchr(script_file,'.');

    if (ext && (strlen(ext) == 4) && (toupper(ext[1]) == 'L') && (toupper(ext[2]) == 'U') && (toupper(ext[3]) == 'A'))
        return SCRIPT_LANG_LUA;

    return SCRIPT_LANG_UBASIC;
}

struct libscriptapi_sym* module_script_lang_load(const char *script_fn)
{
    int lang_id = script_lang_id(script_fn);

    char *lang_name = "Unknown";

    switch (lang_id)
    {
    case SCRIPT_LANG_UBASIC:
        module_lua_unload();
        libscriptapi = module_load_generic((void**)&libubasic, MODULE_NAME_UBASIC, bind_module_ubasic, MODULE_FLAG_DISABLE_AUTOUNLOAD);
        lang_name = "uBasic";
        break;
    case SCRIPT_LANG_LUA:
        module_ubasic_unload();
        libscriptapi = module_load_generic((void**)&liblua, MODULE_NAME_LUA, bind_module_lua, MODULE_FLAG_DISABLE_AUTOUNLOAD);
        lang_name = "Lua";
        break;
    default:
        module_lua_unload();
        module_ubasic_unload();
        libscriptapi = 0;
        break;
    }

    if (libscriptapi == 0)
    {
        char msg[64];
        sprintf(msg,"%s script module failed to load",lang_name);
        console_add_line(msg);
    }

    return libscriptapi;
}


/************* DYNAMIC LIBRARY ZEBRA ******/

#define MODULE_NAME_ZEBRA "zebra.flt"

struct libzebra_sym* libzebra;

static int bind_module_zebra( void** export_list )
{
    return bind_module_generic(export_list, (void**)&libzebra, 1, 1, 0);
}

// Return: 0-fail, 1-ok
struct libzebra_sym* module_zebra_load()
{
    return module_load_generic((void**)&libzebra, MODULE_NAME_ZEBRA, bind_module_zebra, MODULE_FLAG_DISABLE_AUTOUNLOAD);
}


/************* DYNAMIC LIBRARY CURVES ******/

#define MODULE_NAME_CURVES "curves.flt"

struct libcurves_sym* libcurves;

static int bind_module_curves( void** export_list )
{
    return bind_module_generic(export_list, (void**)&libcurves, 1, 1, 0);
}

// Return: 0-fail, addr-ok
struct libcurves_sym* module_curves_load()
{
    if (camera_sensor.bits_per_pixel == 10)
        return module_load_generic((void**)&libcurves, MODULE_NAME_CURVES, bind_module_curves, 0);
    libcurves = 0;
    return 0;
}


/************* DYNAMIC LIBRARY GRIDS ******/

#define MODULE_NAME_GRIDS "grids.flt"

struct libgrids_sym* libgrids;

static int bind_module_grids( void** export_list )
{
    return bind_module_generic(export_list, (void**)&libgrids, 1, 1, 0);
}

// Return: 0-fail, addr-ok
struct libgrids_sym* module_grids_load()
{
    return module_load_generic((void**)&libgrids, MODULE_NAME_GRIDS, bind_module_grids, 0);
}


/************* MODULE PALETTE ******/

void module_palette_run(int mode, color st_color, void (*on_select)(color clr))
{
	unsigned int argv[] = {	mode,
							(unsigned int)st_color,
							(unsigned int)on_select };
    module_run("palette.flt", 0, sizeof(argv)/sizeof(argv[0]), argv,  UNLOAD_IF_ERR);
}


/************* MODULE MPOPUP ******/

void module_mpopup_init(struct mpopup_item* popup_actions, const unsigned int flags, void (*on_select)(unsigned int actn), int mode)
{
	unsigned int argv[] = {	(unsigned int)popup_actions,
							(unsigned int)flags,
							(unsigned int)on_select,
							(unsigned int)mode,
							 };
    module_run("mpopup.flt", 0, sizeof(argv)/sizeof(argv[0]), argv,  UNLOAD_IF_ERR);
}


/************* MODULE FSELECT ******/

void module_fselect_init_w_mode(int title, const char* prev_dir, const char* default_dir, void (*on_select)(const char *fn), unsigned int key_redraw_mode)
{
	unsigned int argv[] = {	title,
							(unsigned int)prev_dir,
							(unsigned int)default_dir,
							(unsigned int)on_select,
							(unsigned int)key_redraw_mode,
							 };
    module_run("fselect.flt", 0,  sizeof(argv)/sizeof(argv[0]), argv, UNLOAD_IF_ERR);
}

void module_fselect_init(int title, const char* prev_dir, const char* default_dir, void (*on_select)(const char *fn))
{
	module_fselect_init_w_mode(title, prev_dir, default_dir, on_select, 0/*key_redraw_mode*/);
}

/************* MODULE DNG ******/

#define MODULE_NAME_DNG "_dng.flt"

// This is to keep module in memory while it required by anyone
static int module_dng_semaphore;

struct libdng_sym* libdng;

void module_dng_unload(int owner)
{
	if (libdng==0)
    	return;

  	module_dng_semaphore &= ~owner;
	if (module_dng_semaphore)
		return;

	module_unload(MODULE_NAME_DNG);  
}

static int bind_module_dng( void** export_list )
{
    return bind_module_generic(export_list, (void**)&libdng, 1, 1, 0);
}

// Return: 0-fail, otherwise - bind list
struct libdng_sym* module_dng_load(int owner)
{
    module_dng_semaphore |= owner;

    module_load_generic((void**)&libdng, MODULE_NAME_DNG, bind_module_dng, MODULE_FLAG_DISABLE_AUTOUNLOAD);

    if (libdng == 0)
        module_dng_semaphore=0;

    return libdng;
}

// Make convertion or check operation exsitsing
// Parameter: fn = filename or 0 to just check is operation possible
// Return: 0-fail, 1-ok
//--------------------------------------------------------
int module_convert_dng_to_chdk_raw(char* fn)
{
	if ( fn==0 )
		return module_check_is_exist(MODULE_NAME_DNG);
	if ( !module_dng_load(LIBDNG_OWNED_BY_CONVERT) )
		return 0;
	libdng->convert_dng_to_chdk_raw(fn);
	module_dng_unload(LIBDNG_OWNED_BY_CONVERT);
	return 1;
}


/************* MODULE TBOX ******/

#define MODULE_NAME_TBOX "_tbox.flt"

struct libtextbox_sym* libtextbox;

static int bind_module_tbox( void** export_list )
{
    return bind_module_generic(export_list, (void**)&libtextbox, 1, 1, 0);
}

// Return: 0-fail, addr-ok
struct libtextbox_sym* module_tbox_load()
{
    return module_load_generic((void**)&libtextbox, MODULE_NAME_TBOX, bind_module_tbox, 0);
}
