#ifndef GUI_H
#define GUI_H

typedef int             coord;
typedef unsigned short  color;

#define MAKE_COLOR(bg, fg)  ((color)((((char)(bg))<<8)|((char)(fg))))
#define FG_COLOR(color)     ((unsigned char)(color & 0xFF))
#define BG_COLOR(color)     ((unsigned char)(color >> 8))

// Module ID's for specific modules that we need to be able to detect
// use GUI_MODE_MODULE for generic module modes (e.g.games)
enum Gui_Mode_ {
    GUI_MODE_NONE = 0,
    GUI_MODE_ALT,
    GUI_MODE_MENU,
    GUI_MODE_SCRIPT,
    GUI_MODE_MBOX,
    GUI_MODE_OSD,
    GUI_MODE_PALETTE,
    GUI_MODE_FSELECT,
    GUI_MODE_MPOPUP,
    GUI_MODE_MODULE,    // generic module
};

typedef unsigned int gui_mode_t;

// States for flag to control entering / leaving ALT mode
// Set in KBD task code and activated in GUI task - reduces conflicts
// arising from tasks performin actions that should be done by the
// other task (e.g. screen erase)
enum ALT_Mode_State {
    ALT_MODE_NORMAL = 0,    // don't change ALT mode
    ALT_MODE_ENTER,         // enter ALT mode
    ALT_MODE_LEAVE,         // leave ALT mode
};

extern void gui_set_alt_mode_state(int);    // Called from KBD task to tell GUI task what state to set
extern void gui_activate_alt_mode();        // Called from GUI task to set ALT mode

#define GUI_MODE_MAGICNUM	0xd36c1559

// Specific behaviour of gui mode
#define GUI_MODE_FLAG_NODRAWRESTORE       1
#define GUI_MODE_FLAG_NORESTORE_ON_SWITCH 2

// Values (bit-flag) for gui_draw argument
#define GUI_REDRAWFLAG_ERASEGUARD       1
#define GUI_REDRAWFLAG_MODE_WAS_CHANGED 2
#define GUI_REDRAWFLAG_DRAW_RESTORED    4

// Structure to store gui redraw and kbd process handlers for each mode
typedef struct
{
    // Gui_Mode enum value
    int mode;

	// Called to redraw screen. Argument is GUI_REDRAWFLAG_* set
    void (*redraw)(int);

	// Main button handler for mode
    // Return:
    //          0 = normal button handling
    //          1 = force buttons pressed to be blocked from Camera firmware
    int (*kbd_process)(void);

	// Menu button handler for mode
    void (*kbd_process_menu_btn)(void);

	int flags;

	// Safety check for modules
	unsigned int magicnum;
} gui_handler;

extern gui_handler altGuiHandler;

extern int gui_kbd_process();
extern void gui_default_kbd_process_menu_btn();

extern void gui_redraw();
extern void gui_set_need_restore();

extern gui_mode_t gui_get_mode();
extern gui_handler* gui_set_mode(gui_handler *mode);
extern void gui_reset_alt_helper();

extern const char* gui_subj_dist_override_value_enum(int change, int arg);
extern const char* gui_subj_dist_override_koef_enum(int change, int arg);

#if !CAM_VIDEO_QUALITY_ONLY
extern const char* gui_video_bitrate_enum(int change, int arg);
#endif

#ifdef OPT_SCRIPTING
extern void gui_update_script_submenu();
#endif

extern void gui_menu_run_fltmodule(int arg);

//------------------------------------------------------------------- 
#ifdef OPT_DEBUGGING

#define TASKLIST_MAX_LINES 12 // probably as much as will fit on screen
#define TASKLIST_NUM_TASKS 64 // should be enough ?

#define DEBUG_DISPLAY_NONE 0
#define DEBUG_DISPLAY_PROPS 1
#define DEBUG_DISPLAY_PARAMS 2
#ifndef CAM_DRYOS
#define DEBUG_DISPLAY_TASKS 3
#endif

#ifndef CAM_DRYOS
extern int debug_tasklist_start;
#endif
extern int debug_display_direction;

#endif
//------------------------------------------------------------------- 

struct gui_common_api_ver {
		unsigned int common_api;		// common gui version: gui_mode handling, mbox, this structure
		unsigned int menu_api;		// cmenu structure version
	};

// Defined in gui.c
extern struct gui_common_api_ver gui_version;

//------------------------------------------------------------------- 
//shortcuts
//------------------------------------------------------------------

// Override shortcuts with camera specific values here
// Default values are set below if not overridden

// For models without ZOOM_LEVER  (#if !CAM_HAS_ZOOM_LEVER)
// SHORTCUT_SET_INFINITY is not used
// KEY_DISPLAY is used for gui_subj_dist_override_koef_enum;
// KEY_LEFT/KEY_RIGHT is used for gui_subj_dist_override_value_enum (because of no separate ZOOM_IN/OUT)

#if defined(CAMERA_a580) // Cam has not erase button AND Half press shoot button + Left sets AFL, + Up sets AEL!
    //Alt mode
    #define SHORTCUT_TOGGLE_RAW          KEY_DISPLAY
    #define SHORTCUT_MF_TOGGLE           KEY_UP
    //Half press shoot button
    #define SHORTCUT_TOGGLE_HISTO        KEY_MENU
    #define SHORTCUT_TOGGLE_ZEBRA        KEY_DISPLAY
    //Alt mode & Manual mode    
    #define SHORTCUT_SET_INFINITY        KEY_DISPLAY

#elif defined(CAMERA_a590)  // Shutter Half Press + Down = AFL
    //Half press shoot button    
    #define SHORTCUT_DISABLE_OVERRIDES   KEY_DISPLAY

#elif defined(CAMERA_a3300) || defined(CAMERA_a3200)// a3300 has no erase button, so make DISP button the toggle_raw and Alt +/- shortcuts.
    //Alt mode
    // NOTE both of these conflict with adjustable alt
    #define SHORTCUT_TOGGLE_RAW          KEY_DISPLAY
    #define SHORTCUT_MF_TOGGLE           KEY_FACE

#elif defined(CAMERA_g1x) || defined(CAMERA_sx30) || defined(CAMERA_sx40hs)
    //Half press shoot button    
    #define SHORTCUT_TOGGLE_ZEBRA        KEY_ERASE      // On camera Shutter Half Press + Left = switch MF on/off

#elif defined(CAMERA_g12)
    //Half press shoot button    
    #define SHORTCUT_TOGGLE_HISTO        KEY_ERASE      // On camera Shutter Half Press + Up = switch MF on/off

#elif !CAM_HAS_ERASE_BUTTON
    //Alt mode
    #define SHORTCUT_TOGGLE_RAW          KEY_DISPLAY
#if !defined(CAM_HAS_MANUAL_FOCUS)
    #define SHORTCUT_MF_TOGGLE           KEY_UP
#endif
    //Half press shoot button   
    #define SHORTCUT_TOGGLE_HISTO        KEY_MENU
    //Alt mode & Manual mode    
    #define SHORTCUT_SET_INFINITY        KEY_DISPLAY
#endif

// Define shortcut values not already set above

//Alt mode
#if !defined(SHORTCUT_TOGGLE_RAW)
    #define SHORTCUT_TOGGLE_RAW         KEY_ERASE
#endif
#if !defined(CAM_HAS_MANUAL_FOCUS) && !defined(SHORTCUT_MF_TOGGLE)
    #define SHORTCUT_MF_TOGGLE          KEY_DISPLAY
#endif

//Half press shoot button    
#if !defined(SHORTCUT_TOGGLE_HISTO)
    #define SHORTCUT_TOGGLE_HISTO       KEY_UP
#endif
#if !defined(SHORTCUT_TOGGLE_ZEBRA)
    #define SHORTCUT_TOGGLE_ZEBRA       KEY_LEFT
#endif
#if !defined(SHORTCUT_TOGGLE_OSD)
    #define SHORTCUT_TOGGLE_OSD         KEY_RIGHT
#endif
#if !defined(SHORTCUT_DISABLE_OVERRIDES)
    #define SHORTCUT_DISABLE_OVERRIDES  KEY_DOWN
#endif

//Alt mode & Manual mode  
#if !defined(SHORTCUT_SET_INFINITY)
    #define SHORTCUT_SET_INFINITY       KEY_UP
#endif
#if !defined(SHORTCUT_SET_HYPERFOCAL)
    #define SHORTCUT_SET_HYPERFOCAL     KEY_DOWN
#endif

#if CAM_HAS_ZOOM_LEVER
    #define SHORTCUT_SD_SUB KEY_ZOOM_OUT
    #define SHORTCUT_SD_ADD KEY_ZOOM_IN
#endif
//------------------------------------------------------------------- 

#endif
