#ifndef GUI_H
#define GUI_H

typedef unsigned int      coord;
typedef unsigned short    color;

#define MAKE_COLOR(bg, fg)    ((color)((((char)(bg))<<8)|((char)(fg))))

// Module ID's for specific modules that we need to be able to detect
// use GUI_MODE_MODULE for generic module modes (e.g.games)
enum Gui_Mode_ {
    GUI_MODE_NONE = 0,
    GUI_MODE_ALT,
    GUI_MODE_MENU,
    GUI_MODE_MBOX,
    GUI_MODE_OSD,
    GUI_MODE_PALETTE,
    GUI_MODE_FSELECT,
    GUI_MODE_MPOPUP,
    GUI_MODE_MODULE,    // generic module
};


typedef unsigned int gui_mode_t;

#define GUI_MODE_MAGICNUM	0xd36c1559

// Specific behaviour of gui mode
#define GUI_MODE_FLAG_NODRAWRESTORE       1
#define GUI_MODE_FLAG_NORESTORE_ON_SWITCH 2
// Binded to module gui mode
#define GUI_MODE_FLAG_ALIAS				  4


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
    void (*kbd_process)(void);

	// Menu button handler for mode
    void (*kbd_process_menu_btn)(void);

	int flags;

	// Safety check for modules
	unsigned int magicnum;
} gui_handler;

extern gui_handler defaultGuiHandler;
extern gui_handler altGuiHandler;
extern gui_handler menuGuiHandler;

void gui_default_kbd_process_menu_btn();

extern void gui_redraw();
extern void gui_force_restore();

extern gui_mode_t gui_get_mode();
extern gui_handler* gui_set_mode(gui_handler *mode);


#ifdef OPT_SCRIPTING
extern void gui_update_script_submenu();
#endif

extern void gui_menu_run_fltmodule(int arg);

//----------------------------
struct gui_common_api_ver {
		unsigned int common_api;		// common gui version: gui_mode handling, mbox, this structure
		unsigned int menu_api;		// cmenu structure version
	};

// Defined in gui.c
extern struct gui_common_api_ver gui_version;

#endif
