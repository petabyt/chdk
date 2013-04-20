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

// Forward reference
extern librawop_sym default_librawop;

module_handler_t h_rawop =
{
    (base_interface_t**)&librawop,
    &default_librawop.base,
    RAW_MERGE_VERSION,
    0
};

static int module_load_rawop()
{
    h_rawop.name = rawop_module_name();
    return module_load(&h_rawop);
}

// Default (unloaded) function(s)
static int default_raw_merge_start(int action)
{
    // If load succeeded call module version of function
    if (module_load_rawop())
        return librawop->raw_merge_start(action);

    // Failure
    return 0;
}
static int default_raw_merge_add_file(const char* filename)
{
    // Do nothing unless 'raw_merge_start' already called to load module
    return 0;
}
static void default_raw_merge_end()
{
    // Do nothing unless 'raw_merge_start' already called to load module
    return;
}
static int default_raw_subtract(const char *from, const char *sub, const char *dest)
{
    // If load succeeded call module version of function
    if (module_load_rawop())
        return librawop->raw_subtract(from, sub, dest);

    // Failure
    return 0;
}

// Default library - module unloaded
librawop_sym default_librawop =
{
    { 0,0,0,0,0 },
    default_raw_merge_start,
    default_raw_merge_add_file,
    default_raw_merge_end,
    default_raw_subtract
};

// Library pointer
librawop_sym* librawop = &default_librawop;


/************* DYNAMIC LIBRARY EDGE OVERLAY ******/

// Storage and interface for edge overlay 'image' buffer.
// This is so the previous overlay can survive if the module gets unloaded
// (Need these for the module export list, even if OPT_EDGEOVERLAY is not defined).
static void* saved_edgebuf = 0;
static int saved_edgestate = 0;

void module_restore_edge(void **buf, int *state) { *buf = saved_edgebuf; *state = saved_edgestate; }
void module_save_edge(void* buf, int state)      { saved_edgebuf = buf; saved_edgestate = state; }

#define MODULE_NAME_EDGEOVR "edgeovr.flt"

// Forward reference
extern libedgeovr_sym default_libedgeovr;

module_handler_t h_edgeovr =
{
    (base_interface_t**)&libedgeovr,
    &default_libedgeovr.base,
    EDGEOVERLAY_VERSION,
    MODULE_NAME_EDGEOVR
};

// Return: 0-fail, 1-ok
static int module_edgeovr_load()
{
    // This flag is because edgeovr called each tick
    //   If module loading failed, then do not try to load it until reboot
    //    (otherwise we will try to load module each tick)
    static int flag_load_fail = 0;

    if ( flag_load_fail==0 )
        if (!module_load(&h_edgeovr))
    		flag_load_fail = 1;

    return flag_load_fail == 0;
}

// Default (unloaded) function(s)
static void default_edge_overlay()
{
    // If load succeeded call module version of function
    if (module_edgeovr_load())
        libedgeovr->edge_overlay();
}
static void default_load_edge_overlay(const char* fn)
{
    // If load succeeded call module version of function
    if (module_edgeovr_load())
        libedgeovr->load_edge_overlay(fn);
}
static void default_save_edge_overlay()
{
    // Don't need to do anything unless module already loaded
    return;
}

// Default library - module unloaded
libedgeovr_sym default_libedgeovr =
{
    { 0,0,0,0,0 },
    default_edge_overlay,
    default_load_edge_overlay,
    default_save_edge_overlay
};

// Library pointer
libedgeovr_sym* libedgeovr = &default_libedgeovr;

/************* DYNAMIC LIBRARY MOTION DETECT ******/

#define MODULE_NAME_MDETECT "mdetect.flt"

// Forward reference
extern libmotiondetect_sym default_libmotiondetect;

module_handler_t h_motiondetect =
{
    (base_interface_t**)&libmotiondetect,
    &default_libmotiondetect.base,
    MOTION_DETECTOR_VERSION,
    MODULE_NAME_MDETECT
};

// Default (unloaded) function(s)
static int default_md_init_motion_detector(
 int columns, int rows, int pixel_measure_mode, int detection_timeout, int measure_interval, int threshold, int draw_grid, 
 int clipping_region_mode, int clipping_region_column1, int clipping_region_row1, int clipping_region_column2, int clipping_region_row2,
 int parameters, int pixels_step, int msecs_before_trigger)
{
    // If load succeeded call module version of function
    if (module_load(&h_motiondetect))
        return libmotiondetect->md_init_motion_detector(
                    columns, rows, pixel_measure_mode, detection_timeout, measure_interval, threshold, draw_grid, 
                    clipping_region_mode, clipping_region_column1, clipping_region_row1, clipping_region_column2, clipping_region_row2,
                    parameters, pixels_step, msecs_before_trigger);

    // Failure
    return 0;
}
static void default_md_close_motion_detector()
{
    // Do nothing unless module loaded using 'md_init_motion_detector'
    return;
}
static void default_md_draw_grid()
{
    // Do nothing unless module loaded using 'md_init_motion_detector'
    return;
}
static int default_md_get_cell_diff(int column, int row)
{
    // Do nothing unless module loaded using 'md_init_motion_detector'
    return 0;
}
static int default_md_get_cell_val(int column, int row)
{
    // Do nothing unless module loaded using 'md_init_motion_detector'
    return 0;
}

// Default library - module unloaded
libmotiondetect_sym default_libmotiondetect =
{
    { 0,0,0,0,0 },
    default_md_close_motion_detector,
    default_md_init_motion_detector,
    default_md_get_cell_diff,
    default_md_draw_grid,
    default_md_get_cell_val
};

// Library pointer
libmotiondetect_sym* libmotiondetect = &default_libmotiondetect;

/************* DYNAMIC LIBRARY Script language ******/

#define MODULE_NAME_UNK     "unknown"
#define MODULE_NAME_LUA     "lua.flt"
#define MODULE_NAME_UBASIC  "ubasic.flt"

// Forward reference
extern libscriptapi_sym default_libscriptapi;

module_handler_t h_script =
{
    (base_interface_t**)&libscriptapi,
    &default_libscriptapi.base,
    SCRIPT_API_VERSION,
    MODULE_NAME_UNK
};

// Which script language is being used
#define SCRIPT_LANG_NONE    0
#define SCRIPT_LANG_UBASIC  1
#define SCRIPT_LANG_LUA     2

static int current_lang_id = SCRIPT_LANG_NONE;

static int script_lang_id(const char* script_file)
{
    if ((script_file == 0) || (script_file[0] == 0))
        return SCRIPT_LANG_LUA;  // Default script is Lua

    char *ext = strrchr(script_file,'.');

    if (ext && (strlen(ext) == 4) && (toupper(ext[1]) == 'L') && (toupper(ext[2]) == 'U') && (toupper(ext[3]) == 'A'))
        return SCRIPT_LANG_LUA;

    return SCRIPT_LANG_UBASIC;
}

void module_set_script_lang(const char* script_file)
{
    char* lang_names[] = { MODULE_NAME_UNK, MODULE_NAME_UBASIC, MODULE_NAME_LUA };

    int lang_id = script_lang_id(script_file);

    if (lang_id != current_lang_id)
    {
        module_unload(h_script.name);
        current_lang_id = lang_id;
        h_script.name = lang_names[lang_id];
    }
}

// Default (unloaded) function(s)
static int default_script_start(char const* script, int is_ptp)
{
    // If load succeeded call module version of function
    if (module_load(&h_script))
        return libscriptapi->script_start(script, is_ptp);

    // Failure
    return 0;
}
static int default_script_run()
{
    // Nothing to do if script not started
    return 0;
}
static void default_script_reset()
{
    // Nothing to do if script not started
    return;
}
static void default_set_variable(int varnum, int value)
{
    // Nothing to do if script not started
    return;
}
static void default_set_as_ret(int as_ret)
{
    // Nothing to do if script not started
    return;
}
static int default_run_restore()
{
    // Nothing to do if script not started
    return 0;
}

// Default library - module unloaded
libscriptapi_sym default_libscriptapi =
{
    { 0,0,0,0,0 },
    default_script_start,
    default_script_run,
    default_script_reset,
    default_set_variable,
    default_set_as_ret,
    default_run_restore
};

// Library pointer
libscriptapi_sym* libscriptapi = &default_libscriptapi;

/************* DYNAMIC LIBRARY ZEBRA ******/

#define MODULE_NAME_ZEBRA "zebra.flt"

// Forward reference
extern libzebra_sym default_libzebra;

module_handler_t h_zebra =
{
    (base_interface_t**)&libzebra,
    &default_libzebra.base,
    ZEBRA_VERSION,
    MODULE_NAME_ZEBRA
};

// Default (unloaded) function(s)
static int default_gui_osd_draw_zebra(int show)
{
    // If load succeeded call module version of function
    if (module_load(&h_zebra))
        return libzebra->gui_osd_draw_zebra(show);

    // Failure
    return 0;
}

// Default library - module unloaded
libzebra_sym default_libzebra =
{
    { 0,0,0,0,0 },
    default_gui_osd_draw_zebra
};

// Library pointer
libzebra_sym* libzebra = &default_libzebra;


/************* DYNAMIC LIBRARY CURVES ******/

#define MODULE_NAME_CURVES "curves.flt"

// Forward reference
extern libcurves_sym default_libcurves;

module_handler_t h_curves =
{
    (base_interface_t**)&libcurves,
    &default_libcurves.base,
    CURVES_VERSION,
    MODULE_NAME_CURVES
};

// Return: 0-fail, addr-ok
static int module_curves_load()
{
    if (camera_sensor.bits_per_pixel == 10)
        return module_load(&h_curves);
    return 0;
}

// Default (unloaded) function(s)
static void default_curve_init_mode()
{
    // If load succeeded call module version of function
    if (module_curves_load())
        libcurves->curve_init_mode();
}
static void default_curve_apply()
{
    // Do nothing if module not loaded
    return;
}
static void default_curve_set_mode()
{
    // If load succeeded call module version of function
    if (module_curves_load())
        libcurves->curve_set_mode();
}
static void default_curve_set_file()
{
    // If load succeeded call module version of function
    if (module_curves_load())
        libcurves->curve_set_file();
}

// Default library - module unloaded
libcurves_sym default_libcurves =
{
    { 0,0,0,0,0 },
    default_curve_init_mode,
    default_curve_apply,
    default_curve_set_mode,
    default_curve_set_file
};

// Library pointer
libcurves_sym* libcurves = &default_libcurves;

/************* DYNAMIC LIBRARY GRIDS ******/

#define MODULE_NAME_GRIDS "grids.flt"

// Forward reference
extern libgrids_sym default_libgrids;

module_handler_t h_grids =
{
    (base_interface_t**)&libgrids,
    &default_libgrids.base,
    GUI_GRID_VERSION,
    MODULE_NAME_GRIDS
};

// Default (unloaded) function(s)
static void default_gui_grid_draw_osd(int force)
{
    // If load succeeded call module version of function
    if (module_load(&h_grids))
        libgrids->gui_grid_draw_osd(force);
}
static void default_grid_lines_load(const char *fn)
{
    // If load succeeded call module version of function
    if (module_load(&h_grids))
        libgrids->grid_lines_load(fn);
}

// Default library - module unloaded
libgrids_sym default_libgrids =
{
    { 0,0,0,0,0 },
    default_gui_grid_draw_osd,
    default_grid_lines_load
};

// Library pointer
libgrids_sym* libgrids = &default_libgrids;


/************* MODULE PALETTE ******/

#define MODULE_NAME_PALETTE "palette.flt"

// Forward reference
extern libpalette_sym default_libpalette;

module_handler_t h_palette =
{
    (base_interface_t**)&libpalette,
    &default_libpalette.base,
    GUI_PALETTE_VERSION,
    MODULE_NAME_PALETTE
};

// Default (unloaded) function
static void default_show_palette(int mode, color st_color, void (*on_select)(color clr))
{
    // If load succeeded call module version of function
    if (module_load(&h_palette))
        libpalette->show_palette(mode, st_color, on_select);
}

// Default library - module unloaded
libpalette_sym default_libpalette =
{
    { 0,0,0,0,0 },
    default_show_palette
};

// Library pointer
libpalette_sym* libpalette = &default_libpalette;

/************* MODULE MPOPUP ******/

#define MODULE_NAME_MPOPUP "mpopup.flt"

// Forward reference
extern libmpopup_sym default_libmpopup;

module_handler_t h_mpopup =
{
    (base_interface_t**)&libmpopup,
    &default_libmpopup.base,
    GUI_MPOPUP_VERSION,
    MODULE_NAME_MPOPUP
};

// Default (unloaded) function
static void default_show_popup(struct mpopup_item* popup_actions, const unsigned int flags, void (*on_select)(unsigned int actn), int mode)
{
    // If load succeeded call module version of function
    if (module_load(&h_mpopup))
        libmpopup->show_popup(popup_actions, flags, on_select, mode);
}

// Default library - module unloaded
libmpopup_sym default_libmpopup =
{
    { 0,0,0,0,0 },
    default_show_popup
};

// Library pointer
libmpopup_sym* libmpopup = &default_libmpopup;

/************* MODULE FSELECT ******/

#define MODULE_NAME_FSELECT "fselect.flt"

// Forward reference
extern libfselect_sym default_libfselect;

module_handler_t h_fselect =
{
    (base_interface_t**)&libfselect,
    &default_libfselect.base,
    GUI_FSELECT_VERSION,
    MODULE_NAME_FSELECT
};

// Default (unloaded) function
static void default_file_select(int title, const char* prev_dir, const char* default_dir, void (*on_select)(const char *fn))
{
    // If load succeeded call module version of function
    if (module_load(&h_fselect))
        libfselect->file_select(title, prev_dir, default_dir, on_select);
}

// Default library - module unloaded
libfselect_sym default_libfselect =
{
    { 0,0,0,0,0 },
    default_file_select
};

// Library pointer
libfselect_sym* libfselect = &default_libfselect;

/************* MODULE DNG ******/

#define MODULE_NAME_DNG "_dng.flt"

// Forward reference
extern libdng_sym default_libdng;

module_handler_t h_dng =
{
    (base_interface_t**)&libdng,
    &default_libdng.base,
    DNG_VERSION,
    MODULE_NAME_DNG
};

// Default (unloaded) function
static void default_create_badpixel_bin()
{
    // If load succeeded call module version of function
    if (module_load(&h_dng))
        libdng->create_badpixel_bin();
}
static int default_raw_init_badpixel_bin()
{
    // Do nothing unless module is loaded
    return 0;
}
static void default_capture_data_for_exif()
{
    // If load succeeded call module version of function
    if (module_load(&h_dng))
        libdng->capture_data_for_exif();
}
static void default_load_bad_pixels_list_b(char* filename)
{
    // If load succeeded call module version of function
    if (module_load(&h_dng))
        libdng->load_bad_pixels_list_b(filename);
}
static int default_badpixel_list_loaded_b()
{
    // Do nothing unless module is loaded
    return 0;
}
static int default_convert_dng_to_chdk_raw(char* fn)
{
    // If load succeeded call module version of function
    if (module_load(&h_dng))
        return libdng->convert_dng_to_chdk_raw(fn);

    // Failure
    return 0;
}
static void default_write_dng(int fd, char* rawadr, char* altrawadr, unsigned long uncachedbit)
{
    // Do nothing unless module is loaded
    return;
}

// Default library - module unloaded
libdng_sym default_libdng =
{
    { 0,0,0,0,0 },
    default_create_badpixel_bin,
    default_raw_init_badpixel_bin,
    default_capture_data_for_exif,
    default_load_bad_pixels_list_b,
    default_badpixel_list_loaded_b,
    default_convert_dng_to_chdk_raw,
    default_write_dng
};

// Library pointer
libdng_sym* libdng = &default_libdng;

/************* MODULE TBOX ******/

#define MODULE_NAME_TBOX "_tbox.flt"

// Forward reference
extern libtextbox_sym default_libtextbox;

module_handler_t h_textbox =
{
    (base_interface_t**)&libtextbox,
    &default_libtextbox.base,
    GUI_TBOX_VERSION,
    MODULE_NAME_TBOX
};

// Default (unloaded) function
static int default_textbox_init(int title, int msg, const char* defaultstr, unsigned int maxsize, void (*on_select)(const char* newstr), char *input_buffer)
{
    // If load succeeded call module version of function
    if (module_load(&h_textbox))
        return libtextbox->textbox_init(title,msg,defaultstr,maxsize,on_select,input_buffer);

    // Failure
    return 0;
}

// Default library - module unloaded
libtextbox_sym default_libtextbox =
{
    { 0,0,0,0,0 },
    default_textbox_init,
};

// Library pointer
libtextbox_sym* libtextbox = &default_libtextbox;

/************* MODULE HEXBOX ******/

#define MODULE_NAME_HEXBOX "_hexbox.flt"

// Forward reference
extern libhexbox_sym default_libhexbox;

module_handler_t h_hexbox =
{
    (base_interface_t**)&libhexbox,
    &default_libhexbox.base,
    GUI_HEXBOX_VERSION,
    MODULE_NAME_HEXBOX
};

// Default (unloaded) function
static int default_hexbox_init(int *num, char *title, int flags)
{
    // If load succeeded call module version of function
    if (module_load(&h_hexbox))
        return libhexbox->hexbox_init(num, title, flags);

    // Failure
    return 0;
}

// Default library - module unloaded
libhexbox_sym default_libhexbox =
{
    { 0,0,0,0,0 },
    default_hexbox_init,
};

// Library pointer
libhexbox_sym* libhexbox = &default_libhexbox;

/************* MODULE TXTREAD ******/

#define MODULE_NAME_TXTREAD "txtread.flt"

// Forward reference
extern libtxtread_sym default_libtxtread;

module_handler_t h_txtread =
{
    (base_interface_t**)&libtxtread,
    &default_libtxtread.base,
    GUI_READ_VERSION,
    MODULE_NAME_TXTREAD
};

// Default (unloaded) function
static int default_read_file(const char *fn)
{
    // If load succeeded call module version of function
    if (module_load(&h_txtread))
        return libtxtread->read_file(fn);

    // Failure
    return 0;
}

// Default library - module unloaded
libtxtread_sym default_libtxtread =
{
    { 0,0,0,0,0 },
    default_read_file,
};

// Library pointer
libtxtread_sym* libtxtread = &default_libtxtread;
