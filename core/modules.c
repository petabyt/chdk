/*
 *   CHDK-FLAT Module System.  
 *
 *   (c)2011 Sergey Taranenko aka tsvstar
 *
 *   Specific "shortcuts", dynamic libraries binding
 */

#include "modules.h"
#include "module_load.h"
#include "camera.h"
#include "stdlib.h"
#include "conf.h"
#include "gui_draw.h"
#include "dng.h"

/************* DYNAMIC LIBRARY RAWOPERATION ******/

#if CAM_SENSOR_BITS_PER_PIXEL==10
#define MODULE_NAME_RAWOP "_rawop10.flt"
#elif CAM_SENSOR_BITS_PER_PIXEL==12
#define MODULE_NAME_RAWOP "_rawop12.flt"
#else 
 #error define set_raw_pixel for sensor bit depth
#endif

// This is to minimize sharing sym to use this lib in other modules
struct librawop_sym* librawop;

static int bind_module_rawop( void** export_list )
{
	  // Unbind
	if ( !export_list ) {
		librawop=0;
    	return 0;
  	}

	// Bind
	if ( (unsigned int)export_list[0] != EXPORTLIST_MAGIC_NUMBER )
	     return 1;
  	if ( (unsigned int)export_list[1] <3 )
    	 return 1;

	librawop = export_list[2];

	if ( !librawop )
    	 return 1;

    /* NO API VERSION CHECK HERE - EACH MODULE CHECK THIS AGAINST ITS REQUIREMENT
	if ( !API_VERSION_MATCH_REQUIREMENT( librawop->version, 1, 0 ) ) {
		librawop=0;
		return 1;
	}
    */

	return 0;
}

void module_rawop_unload()
{
	if (librawop==0)
    	return;

	module_unload(MODULE_NAME_RAWOP);  
}


// Return: 0-fail, otherwise - bind list
struct librawop_sym* module_rawop_load()
{
  static int module_idx=-1;

  if (librawop)
     return librawop;

  module_idx=module_load(MODULE_NAME_RAWOP, bind_module_rawop );
  if ( module_idx<0 )
	 module_unload(MODULE_NAME_RAWOP);  

  return librawop;
}



/************* DYNAMIC LIBRARY EDGE OVERLAY ******/

#define MODULE_NAME_EDGEOVR "edgeovr.flt"

struct libedgeovr_sym* libedgeovr;

static int bind_module_edgeovr( void** export_list )
{
	  // Unbind
	if ( !export_list ) {
		libedgeovr =0;
    	return 0;
  	}

	// Bind
	if ( (unsigned int)export_list[0] != EXPORTLIST_MAGIC_NUMBER )
	     return 1;
  	if ( (unsigned int)export_list[1] <3 )
    	 return 1;

	libedgeovr = export_list[2];
	if ( !libedgeovr )
    	 return 1;
	if ( !API_VERSION_MATCH_REQUIREMENT( libedgeovr->version, 1, 0 ) ) {
		libedgeovr=0;
		return 1;
	}

	return 0;
}

// Return: 0-fail, 1-ok
struct libedgeovr_sym* module_edgeovr_load()
{
  if (libedgeovr)
     return libedgeovr;

  // This flag is because edgeovr called each tick
  //   If module loading failed, then do not try to load it until reboot
  //    (otherwise we will try to load module each tick)
  static int flag_load_fail = 0;
  static int module_idx=-1;

  if ( flag_load_fail==0 )
  {
    module_idx=module_load(MODULE_NAME_EDGEOVR, bind_module_edgeovr );
	if ( module_idx<0 ) {
		flag_load_fail = 1;
		module_unload(MODULE_NAME_EDGEOVR);  
	}
	else {
		// This library never unloaded once it is loaded
		// Reason - it should keep its data during whole session
	 	module_set_flags(module_idx, MODULE_FLAG_DISABLE_AUTOUNLOAD);
	}
  }

  return libedgeovr;
}


// edgeovr module will never unload to keep its picture
// void module_edgeovr_unload() {}


/************* DYNAMIC LIBRARY CURVES ******/

#define MODULE_NAME_CURVES "curves.flt"

struct libcurves_sym* libcurves;

static int bind_module_curves( void** export_list )
{
	  // Unbind
	if ( !export_list ) {
		libcurves=0;
    	return 0;
  	}

	// Bind
	if ( (unsigned int)export_list[0] != EXPORTLIST_MAGIC_NUMBER )
	     return 1;
  	if ( (unsigned int)export_list[1] <3 )
    	 return 1;

	libcurves = export_list[2];

	if ( !libcurves )
    	 return 1;
	if ( !API_VERSION_MATCH_REQUIREMENT( libcurves->version, 1, 0 ) ) {
		librawop=0;
		return 1;
	}

	return 0;
}

// Return: 0-fail, addr-ok
struct libcurves_sym* module_curves_load()
{
  if (libcurves)
     return libcurves;

  static int module_idx=-1;

  module_idx=module_load(MODULE_NAME_CURVES, bind_module_curves );
  if ( module_idx<0 )
		module_unload(MODULE_NAME_CURVES);  
  else {
	// This library never unloaded once it is loaded
	// Reason - changing mode mode from LUA stored inside module only
	module_set_flags(module_idx, MODULE_FLAG_DISABLE_AUTOUNLOAD);

	// Initialize - in module
	// curve_init_mode();
  }

  return libcurves;
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

#if DNG_SUPPORT
static int bind_module_dng( void** export_list )
{
	  // Unbind
	if ( !export_list ) {
		libdng=0;
    	return 0;
  	}

	// Bind
	if ( (unsigned int)export_list[0] != EXPORTLIST_MAGIC_NUMBER )
	     return 1;
  	if ( (unsigned int)export_list[1] < 3 )
    	 return 1;

	libdng = export_list[2];
  	if ( libdng==0 )
    	 return 1;

	if ( !API_VERSION_MATCH_REQUIREMENT( libdng->version, 1, 0 ) ) {
		libdng=0;		
		return 1;
	}

	return 0;
}
#endif

void module_dng_unload(int owner)
{
#if DNG_SUPPORT
	if (libdng==0)
    	return;

  	module_dng_semaphore&=~owner;
	if (module_dng_semaphore)
		return;

	module_unload(MODULE_NAME_DNG);  
#endif
}


// Return: 0-fail, otherwise - bind list
struct libdng_sym* module_dng_load(int owner)
{
#if DNG_SUPPORT
  static int module_idx=-1;

  module_dng_semaphore|=owner;
  if (libdng)
     return libdng;

  module_idx=module_load(MODULE_NAME_DNG, bind_module_dng );
  if ( module_idx<0 ) {
	 module_unload(MODULE_NAME_DNG);  
  	 module_dng_semaphore=0;
  }
  else {
	 // This module could be unloaded only manualy (because store badpixel)
	 module_set_flags(module_idx, MODULE_FLAG_DISABLE_AUTOUNLOAD);
  }

  return libdng;
#else
  return 0;
#endif
}

// Make convertion or check operation exsitsing
// Parameter: fn = filename or 0 to just check is operation possible
// Return: 0-fail, 1-ok
//--------------------------------------------------------
int module_convert_dng_to_chdk_raw(char* fn)
{
#if DNG_SUPPORT
	if ( fn==0 )
		return module_check_is_exist(MODULE_NAME_DNG);
	if ( !module_dng_load(LIBDNG_OWNED_BY_CONVERT) )
		return 0;
	libdng->convert_dng_to_chdk_raw(fn);
	module_dng_unload(LIBDNG_OWNED_BY_CONVERT);
	return 1;
#else
	return 0;
#endif
}
