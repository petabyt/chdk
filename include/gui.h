#ifndef GUI_H
#define GUI_H

typedef unsigned int      coord;
typedef unsigned short    color;

#define MAKE_COLOR(bg, fg)    ((color)((((char)(bg))<<8)|((char)(fg))))

// Don't delete or re-order entries unless guiHandlers (gui.c) table is updated to match 
enum Gui_Mode_ {
    GUI_MODE_NONE = 0,
    GUI_MODE_ALT,
    GUI_MODE_MENU,
    GUI_MODE_PALETTE,
    GUI_MODE_MBOX,
    GUI_MODE_FSELECT,
    GUI_MODE_OSD,
    GUI_MODE_MPOPUP,
	GUI_MODE_COUNT
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
	// Called to redraw screen. Argument is GUI_REDRAWFLAG_* set
    void (*redraw)(int);

	// Main button handler for mode
	// Note: this pointer reused as gui_handler* for 
	//    GUI_MODE_FLAG_ALIAS entries
	// Do not use union because warning on initializer
    void (*kbd_process)(void);

	// Menu button handler for mode
    void (*kbd_process_menu_btn)(void);

	int flags;

	// Safety check for modules
	unsigned int magicnum;
} gui_handler;



void gui_default_kbd_process_menu_btn();

extern void gui_redraw();
extern void gui_force_restore();

extern void draw_pixel(coord x, coord y, color cl);

extern gui_mode_t gui_get_mode();
extern void gui_set_mode(gui_mode_t mode);

extern int gui_bind_mode(int core_mode, gui_handler* handler);



#ifdef OPT_SCRIPTING
extern void gui_update_script_submenu();
#endif

extern void gui_menu_run_fltmodule(int arg);

#endif
