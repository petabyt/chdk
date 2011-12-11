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
    GUI_MODE_MBOX,
    GUI_MODE_OSD,
	GUI_MODE_COUNT
};

typedef unsigned int gui_mode_t;

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
    void (*redraw)(int);                    // Called to redraw screen
    void (*kbd_process)(void);              // Main button handler for mode
    void (*kbd_process_menu_btn)(void);     // Menu button handler for mode
	int flags;
	unsigned int magicnum;					// Safety check for modules
} gui_handler;

void gui_default_kbd_process_menu_btn();


extern void gui_redraw();
extern void gui_force_restore();

extern void draw_pixel(coord x, coord y, color cl);

extern gui_mode_t gui_get_mode();
extern void gui_set_mode(gui_mode_t mode);



#ifdef OPT_SCRIPTING
extern void gui_update_script_submenu();
#endif

#endif
