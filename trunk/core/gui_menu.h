#ifndef GUI_MENU_H
#define GUI_MENU_H

//-------------------------------------------------------------------
// Type of menuitem. 
//   ENUM2 - simple choicelist, ENUM - for choicelist with callback
#define MENUITEM_MASK           0x000f
#define MENUITEM_BOOL           1
#define MENUITEM_INT            2
#define MENUITEM_SUBMENU        3
#define MENUITEM_PROC           4
#define MENUITEM_UP             5
#define MENUITEM_TEXT           6
#define MENUITEM_SEPARATOR      7
#define MENUITEM_ENUM           8
#define MENUITEM_COLOR_BG       9
#define MENUITEM_COLOR_FG       10
#define MENUITEM_ENUM2          11
#define MENUITEM_SUBMENU_PROC   12

// Flags, which describe limits of F_INT value
#define MENUITEM_F_MASK         0x00f0
#define MENUITEM_F_UNSIGNED     0x0010
#define MENUITEM_F_MIN          0x0020
#define MENUITEM_F_MAX          0x0040
#define MENUITEM_F_MINMAX       0x0060

// Value, which specify specific kind of argument
#define MENUITEM_ARG_MASK       0x0f00
    // menuitem.arg contain ptr to callback function
#define MENUITEM_ARG_CALLBACK   0x0300

// Hide this item in menu
#define MENUITEM_HIDDEN		0x1000
// This item is able to be "turned off" (negate sign) in edit mode
#define MENUITEM_QUICKDISABLE   0x2000


#define MENU_MINMAX(min, max)   (((max)<<16)|(min&0xFFFF))

//-------------------------------------------------------------------
typedef struct {
    char                symbol;     // menuitem icon symbol
    char                opt_len;    // ENUM2 num of elements 
    short               type;       // MENUITEM_MASKS
    int                 text;       // Text
    int                 *value;     // pointer to binded variable
                                    //   exceptions: _PROC = pointer to processing func
                                    //               _ENUM = pointer to processing func
    int                 arg;        // additional argument
                                    //     by default type is controled by _ARG_MASK and by _F_MINMAX
                                    //     for ENUM - pointer to related variable
                                    //     for ENUM2 - pointer to string list
} CMenuItem;

typedef struct {
    char                symbol;
    int                 title;
    void                (*on_change)(unsigned int item);
    const CMenuItem     *menu;
} CMenu;

// Menu item constructor macros
#define MENU_ITEM(sym, txt, typ, val, arg)  { (char)sym, 0, (short)typ, (int)txt, (int*)val, (int)arg }
#define MENU_ENUM2(sym, txt, val, arg)      { (char)sym, sizeof(arg)/sizeof(arg[0]), MENUITEM_ENUM2, (int)txt, (int*)val, (int)arg }
#define MENU_ENUM2typ(sym, txt, typ, val, arg)    { (char)sym, sizeof(arg)/sizeof(arg[0]), typ, (int)txt, (int*)val, (int)arg }
#define MENU_ENUM2a(sym, txt, val, arg, num){ (char)sym, (char)num, MENUITEM_ENUM2, (int)txt, (int*)val, (int)arg }


typedef const char* (enum_callback_func_t)(int change, int arg);
typedef void (menuproc_t)(int);

//-------------------------------------------------------------------
extern void gui_menu_init(CMenu *menu_ptr);
extern int gui_menu_kbd_process();
extern void gui_menu_draw(int enforce_redraw);
extern void gui_menu_force_redraw();
extern void gui_menu_unload_module_menus();
//-------------------------------------------------------------------
extern void gui_enum_value_change(int *value, int change, unsigned num_items);
extern const char* gui_change_simple_enum(int* value, int change, const char** items, unsigned num_items);
extern const char* gui_change_enum2(const CMenuItem *menu_item, int change);
extern void gui_qenum_value_change(int* value, int change, unsigned num_items );
extern const char* gui_change_simple_qenum(int* value, int change, const char** items, unsigned num_items);

//-------------------------------------------------------------------
extern int menuitem_set_visible( CMenu* menu, int itemid, int flags, int visibility);
extern int value_turn_state( int* valueptr, int dir );

//-------------------------------------------------------------------
extern gui_handler menuGuiHandler;

//-------------------------------------------------------------------
extern  CMenu   root_menu;									// defined in gui.c

enum { FLAG_FIND_RECURSIVE = 0x01
};
extern CMenuItem* find_mnu(CMenu *curr_menu, int itemid );  // defined in gui_user_menu.c
extern CMenuItem* find_mnu_adv(CMenu *curr_menu, int flags, int itemid );   // defined in gui_user_menu.c


//-------------------------------------------------------------------
#endif
