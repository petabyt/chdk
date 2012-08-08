#include "stdlib.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "conf.h"
#include "font.h"
#include "lang.h"
#include "gui.h"
#include "gui_draw.h"
#include "modules.h"
#include "module_load.h"
#include "gui_menu.h"
#include "gui_user_menu.h"
#include "gui_lang.h"

extern gui_handler menueditGuiHandler;
typedef const char* (*enum_callback_t)(int change, int arg);
//-------------------------------------------------------------------
#define MENUSTACK_MAXDEPTH  4

//-------------------------------------------------------------------
typedef struct {
    CMenu       *menu;
    int         curpos;
    int         toppos;
    int         module_idx;
} CMenuStacked;

//-------------------------------------------------------------------

static CMenu        *curr_menu;
static CMenuStacked gui_menu_stack[MENUSTACK_MAXDEPTH];
static unsigned int gui_menu_stack_ptr;
static int          gui_menu_curr_item;
static int          gui_menu_top_item;
static int          gui_menu_redraw;

static int          count_visible;
static int          x, y;
static int          w, wplus, num_lines;
static int          len_bool, len_int, len_enum, len_space, len_br1, len_br2, cl_rect;
static int          int_incr, incr_modified;
static unsigned char *item_color;

//-------------------------------------------------------------------

/*
common code for "enum" menu items that just take a list of string values and don't require any special setters
would be better to have another menu item type that does this by default
save memory by eliminating dupe code
*/
void gui_enum_value_change(int *value, int change, unsigned num_items) {
    *value+=change;
    if (*value<0)
        *value = num_items-1;
    else if (*value>=num_items)
        *value = 0;
}

const char* gui_change_simple_enum(int* value, int change, const char** items, unsigned num_items) {
    gui_enum_value_change(value, change, num_items);
    return items[*value];
}

const char* gui_change_enum2(const CMenuItem *menu_item, int change)
{
    const char** items = (const char**)menu_item->arg;
    gui_enum_value_change(menu_item->value, change, menu_item->opt_len);
    return items[*menu_item->value];
}

// specific processing of migrated to quickdisabled enum fields
void gui_qenum_value_change(int* value, int change, unsigned num_items ) {
    *value+=change;

	if (!change && !*value ) {*value=-2; }
    if (*value<1 && change ) *value = num_items-1;
    else if (*value>=num_items) *value=1;
}

const char* gui_change_simple_qenum(int* value, int change, const char** items, unsigned num_items) {
    gui_qenum_value_change(value, change, num_items);
	if (*value<=0)
		return "Off";
    return items[*value];
}

//-------------------------------------------------------------------
int* menuitem_get_valueptr( CMenu *menu, int imenu ) 
{
  if (imenu < 0) return 0;
  if ( (menu->menu[imenu].type & MENUITEM_MASK) == MENUITEM_ENUM )
    return (int*) menu->menu[imenu].arg;
  return (int*) menu->menu[imenu].value;
}

//-------------------------------------------------------------------
static void gui_menu_set_curr_menu(CMenu *menu_ptr, int top_item, int curr_item) {
    curr_menu = menu_ptr;
    gui_menu_top_item = top_item;
    gui_menu_curr_item = curr_item;
}

//-------------------------------------------------------------------
// Unload any module based sub-menus
void gui_menu_unload_module_menus()
{
    // Unload any module menus
    while (gui_menu_stack_ptr > 0)
    {
        gui_menu_stack_ptr--;
        if (gui_menu_stack[gui_menu_stack_ptr].module_idx >= 0)
            module_unload_idx(gui_menu_stack[gui_menu_stack_ptr].module_idx);
    }
}

//-------------------------------------------------------------------
static void gui_menu_reset_incr() 
{
	int_incr = 1;
	if ( curr_menu && gui_menu_curr_item>=0 ) {
		int itemid = lang_strhash31( curr_menu->menu[gui_menu_curr_item].text );
		if ( itemid == LANG_MENU_SUBJ_DIST_BRACKET_VALUE ||
			 itemid == LANG_MENU_OVERRIDE_SUBJ_DIST_VALUE )
		{
			int_incr = 100;
		}
		else if ( itemid == LANG_MENU_ISO_BRACKET_VALUE ||
			 itemid == LANG_MENU_OVERRIDE_ISO_VALUE )
		{
			int_incr = 10;
		}
	}
}

//-------------------------------------------------------------------
void gui_menu_init(CMenu *menu_ptr) {

    if (menu_ptr) {
        if (conf.menu_select_first_entry)
            gui_menu_set_curr_menu(menu_ptr, 0, 0);
        else 
            gui_menu_set_curr_menu(menu_ptr, 0, -1);
        gui_menu_stack_ptr = 0;
    }

    num_lines = camera_screen.height/rbf_font_height()-1;
    x = CAM_MENU_BORDERWIDTH;
    w = camera_screen.width-x-x;
    len_bool = rbf_str_width("\x95");
    len_int = rbf_str_width("99999");
    len_enum = rbf_str_width("WUBfS3a");
    len_space = rbf_char_width(' ');
    len_br1 = rbf_char_width('[');
    len_br2 = rbf_char_width(']');
    cl_rect = rbf_font_height() - 4;
	gui_menu_reset_incr();

    gui_menu_redraw=2;
}

//-------------------------------------------------------------------

// Return num of all rows + recalculate global count_visible
int gui_menu_rows()
{
    int n;

    count_visible = 0;
    // Count the numer of rows in current menu
    for(n = 0; curr_menu->menu[n].text; n++) {
      if ((curr_menu->menu[n].type & MENUITEM_HIDDEN)==0 )
         count_visible++;
    }
    return n;
}

//-------------------------------------------------------------------
// Full screen erase and redraw of menu
static void gui_menu_erase_and_redraw()
{
    gui_menu_redraw = 2;
    gui_set_need_restore();
}

//-------------------------------------------------------------------
// Function passed to gui_palette_init
// This is called when a new color is selected to update the menu / config value
static void gui_menu_color_selected(color clr)
{
    *item_color = FG_COLOR(clr);
    gui_menu_erase_and_redraw();
}

//-------------------------------------------------------------------
// Return to previous menu on stack
static void gui_menu_back() {
    if (gui_menu_stack_ptr > 0)
    {
        gui_menu_stack_ptr--;
        if (gui_menu_stack[gui_menu_stack_ptr].module_idx >= 0)
            module_unload_idx(gui_menu_stack[gui_menu_stack_ptr].module_idx);
        gui_menu_set_curr_menu(gui_menu_stack[gui_menu_stack_ptr].menu, gui_menu_stack[gui_menu_stack_ptr].toppos, gui_menu_stack[gui_menu_stack_ptr].curpos);
        gui_menu_erase_and_redraw();
    }
    else
    {
        // 'Back' selected; but no menu to go back to
        // Occurs when script menu opened using 'Func/Set' button
        // Return to normal <ALT> mode.
        gui_set_mode(&altGuiHandler);
        kbd_reset_autoclicked_key();    // Need this to stop 'Func/Set' registering twice???
    }
}

//-------------------------------------------------------------------
// Turn value on/off (quickdisable items)
// Argument: 1 turn on, -1 turn off, 0 - toggle
// Return: 1 if changed, 0 otherwise
int value_turn_state( int* valueptr, int dir )
{
  // return if item already have same quickdisable status
  if ( !dir ) 
	dir = ( *valueptr<0 )?1:-1;

  if ( dir >0 ) {
   if ( *valueptr >= 0 )
     return 0;
  }
  else {
   if ( *valueptr < 0 )
     return 0;
  }

  // toggle value
  *valueptr = - *valueptr - 1;
  return 1;
}

//-------------------------------------------------------------------
// Turn current item on/off (quickdisable items)
// Argument: 1 turn on, -1 turn off, 0 - toggle
// Return: 1 if ok, 0 otherwise
static int turn_current_item( int dir )
{
  int* valueptr;
  valueptr = menuitem_get_valueptr( curr_menu, gui_menu_curr_item );

  if ( !valueptr  )
    return 0;

  if (( curr_menu->menu[gui_menu_curr_item].type & MENUITEM_QUICKDISABLE ) == 0)
    return 0;

  if ( value_turn_state( valueptr, dir ) ) {
	  gui_menu_redraw=1;
	// TODO - do callback (and add negative value processing in them)
	return 1;
  }

  return 0;
}

//-------------------------------------------------------------------
static int turn_current_item_on()
{
 return turn_current_item(1);
}

static int turn_current_item_off()
{
 return turn_current_item(-1);
}


//-------------------------------------------------------------------
// Helper functions for gui_menu_kbd_process
//  common code blocks extracted to try and make it easier to understand

// Display the increment value for int items
static void gui_menu_disp_incr()
{
    static char sbuf[7];
    extern int rbf_str_clipped_width(const char *str, int l, int maxlen);

    int max = rbf_str_clipped_width("±10K",0,100);

    if (int_incr >= 1000)
    {
        sprintf(sbuf, "±%dK",int_incr/1000);
    }
    else
    {
        sprintf(sbuf, "±%d",int_incr);
    }
    rbf_draw_string_len(x+w+wplus-2-max,y-rbf_font_height(),max,sbuf,conf.menu_title_color);
}

// If updating an 'int' value check if other buttons are also pressed, and set increment accordingly
// E.G. if ZOOM_OUT is held then RIGHT pressed the 'int' value will be incremented by 10, ZOOM_IN + RIGHT increment by 100
static void get_int_incr_from_button()
{
    if (kbd_is_key_pressed(KEY_ZOOM_OUT))
    {
        incr_modified=int_incr;
        int_incr=10;
    }
    if (kbd_is_key_pressed(KEY_ZOOM_IN))
    {
        incr_modified=int_incr;
        int_incr=100;
    }
    if (camera_info.state.is_shutter_half_press)
    {
        incr_modified=int_incr;
        int_incr=1000;
    }
}

//-------------------------------------------------------------------
// After updating a value check for callback and on_change functions and call if necessary
static void do_callback()
{
    if ((curr_menu->menu[gui_menu_curr_item].type & MENUITEM_ARG_MASK) == MENUITEM_ARG_CALLBACK && curr_menu->menu[gui_menu_curr_item].arg)
    {
        ((void (*)())(curr_menu->menu[gui_menu_curr_item].arg))();
    }

    if (curr_menu->on_change)
    {
        curr_menu->on_change(gui_menu_curr_item);
    }
}

// Update an 'int' value, direction = 1 for increment, -1 for decrement
static void update_int_value(int direction)
{
    // set amount to increment by (int_incr) if other buttons pressed
    get_int_incr_from_button();

    // If current item was turned off, then turn it on and do callback below
    if ( turn_current_item_on() ) 
      direction=0;

    // do update
    *(curr_menu->menu[gui_menu_curr_item].value) += int_incr * direction;

    // Limit new value to defined bounds
    if ( curr_menu->menu[gui_menu_curr_item].type & MENUITEM_F_UNSIGNED)
    {
        if (*(curr_menu->menu[gui_menu_curr_item].value) < 0) 
            *(curr_menu->menu[gui_menu_curr_item].value) = 0;

        if ( curr_menu->menu[gui_menu_curr_item].type & MENUITEM_F_MIN)
        {
            if (*(curr_menu->menu[gui_menu_curr_item].value) < (unsigned short)(curr_menu->menu[gui_menu_curr_item].arg & 0xFFFF)) 
                *(curr_menu->menu[gui_menu_curr_item].value) = (unsigned short)(curr_menu->menu[gui_menu_curr_item].arg & 0xFFFF);
        }
    }
    else
    {
        if (*(curr_menu->menu[gui_menu_curr_item].value) < -9999) 
            *(curr_menu->menu[gui_menu_curr_item].value) = -9999;

        if ( curr_menu->menu[gui_menu_curr_item].type & MENUITEM_F_MIN)
        {
            if (*(curr_menu->menu[gui_menu_curr_item].value) < (short)(curr_menu->menu[gui_menu_curr_item].arg & 0xFFFF)) 
                *(curr_menu->menu[gui_menu_curr_item].value) = (short)(curr_menu->menu[gui_menu_curr_item].arg & 0xFFFF);
        }
    }

    if (*(curr_menu->menu[gui_menu_curr_item].value) > 99999) 
        *(curr_menu->menu[gui_menu_curr_item].value) = 99999;

    if ( curr_menu->menu[gui_menu_curr_item].type & MENUITEM_F_UNSIGNED)
    {
        if ( curr_menu->menu[gui_menu_curr_item].type & MENUITEM_F_MAX)
        {
            if (*(curr_menu->menu[gui_menu_curr_item].value) > (unsigned short)((curr_menu->menu[gui_menu_curr_item].arg>>16) & 0xFFFF)) 
                *(curr_menu->menu[gui_menu_curr_item].value) = (unsigned short)((curr_menu->menu[gui_menu_curr_item].arg>>16) & 0xFFFF);
        }
    }
    else
    {
        if ( curr_menu->menu[gui_menu_curr_item].type & MENUITEM_F_MAX)
        {
            if (*(curr_menu->menu[gui_menu_curr_item].value) > (short)((curr_menu->menu[gui_menu_curr_item].arg>>16) & 0xFFFF)) 
                *(curr_menu->menu[gui_menu_curr_item].value) = (short)((curr_menu->menu[gui_menu_curr_item].arg>>16) & 0xFFFF);
        }
    }

    // execute custom callback and on_change functions
    do_callback();

    // reset int_incr if necessary
    if (incr_modified)
    {
        int_incr = incr_modified;
        incr_modified = 0;
        gui_menu_disp_incr();
    }

    // force menu redraw
    gui_menu_redraw=1;
}

// Update a 'bool' value
static void update_bool_value()
{
    // update value
    *(curr_menu->menu[gui_menu_curr_item].value) = !(*(curr_menu->menu[gui_menu_curr_item].value));

    // execute custom callback and on_change functions
    do_callback();

    // force menu redraw
    gui_menu_redraw=1;
}

//-------------------------------------------------------------------
// Update an 'enum' value, direction = 1 for increment, -1 for decrement
static void update_enum_value(int direction)
{
    // update value
    if (curr_menu->menu[gui_menu_curr_item].value)
    {
        // If current item was turned off, then turn it on and do callback below
        if ( turn_current_item_on() ) 
           direction=0;

        int c;
        if (camera_info.state.is_shutter_half_press)    c = 3;
        else if (kbd_is_key_pressed(KEY_ZOOM_IN))  c = 6;
        else if (kbd_is_key_pressed(KEY_ZOOM_OUT)) c = 3;
        else c = int_incr;
        if ((curr_menu->menu[gui_menu_curr_item].type & MENUITEM_MASK) == MENUITEM_ENUM)
        {
            ((const char* (*)(int change, int arg))(curr_menu->menu[gui_menu_curr_item].value))(c*direction, curr_menu->menu[gui_menu_curr_item].arg);
        }
        else
        {
            gui_change_enum2(&curr_menu->menu[gui_menu_curr_item], c*direction);
        }
    }

    // execute on_change functions
    do_callback();

    // force menu redraw
    gui_menu_redraw=1;
}

//-------------------------------------------------------------------
// Open a sub-menu
void gui_activate_sub_menu(CMenu *sub_menu, int module_idx)
{
    // push current menu on stack
    gui_menu_stack[gui_menu_stack_ptr].menu = curr_menu;
    gui_menu_stack[gui_menu_stack_ptr].curpos = gui_menu_curr_item;
    gui_menu_stack[gui_menu_stack_ptr].toppos = gui_menu_top_item;
    gui_menu_stack[gui_menu_stack_ptr].module_idx = module_idx;

    // Select first item in menu, (or none)
    gui_menu_set_curr_menu(sub_menu, 0, -1);
    if (conf.menu_select_first_entry)
    {
	do
        {
            ++gui_menu_curr_item;
        }
        while ((curr_menu->menu[gui_menu_curr_item].type & MENUITEM_MASK)==MENUITEM_TEXT ||
		(curr_menu->menu[gui_menu_curr_item].type & MENUITEM_MASK)==MENUITEM_SEPARATOR ||
		(curr_menu->menu[gui_menu_curr_item].type & MENUITEM_HIDDEN) );
    }

    gui_menu_stack_ptr++;

    // FIXME check on stack overrun;
    if (gui_menu_stack_ptr > MENUSTACK_MAXDEPTH)
    {
        draw_txt_string(0, 0, "E1", MAKE_COLOR(COLOR_RED, COLOR_YELLOW));
        gui_menu_stack_ptr = 0;
    }

    // Force full redraw
    gui_menu_erase_and_redraw();
}

//-------------------------------------------------------------------
// Calculate num of visible items between last and start
int distance_items( int start, int last)
{
  int count=0;
  for(last=last-1; last>=0 && last>=start; last-- ) {
      if ((curr_menu->menu[last].type & MENUITEM_HIDDEN)==0 )
         count++;
  }
  return count;
}

// Set top of menu to "offset" distance before "last" item
void adjust_top ( int last, int offset ) 
{
  for ( ; last>0 ; last--)
  {
      if ((curr_menu->menu[last].type & MENUITEM_HIDDEN)==0 )
      {
	 if ( offset<=0) 
	    break;
         offset--; 
      }
  }
  gui_menu_top_item = last;
}


// Open a sub-menu
static void select_sub_menu()
{
    gui_activate_sub_menu((CMenu*)(curr_menu->menu[gui_menu_curr_item].value), -1);
}

// Call a function to process a menu item (may be a sub-menu loaded via a module)
static void select_proc()
{
    if (curr_menu->menu[gui_menu_curr_item].value)
    {
        ((void (*)(int arg))(curr_menu->menu[gui_menu_curr_item].value))(curr_menu->menu[gui_menu_curr_item].arg);
        if (curr_menu->on_change)
        {
            curr_menu->on_change(gui_menu_curr_item);
        }
        //gui_menu_set_curr_menu(curr_menu, 0, 0); // restore this if it causes problems
        gui_menu_redraw=2;
    }
}

// Move up / down in menu, adjusting scroll position if needed
//   increment = -1 to move up, 1 to move down
static void gui_menu_updown(int increment)
{
    int c, j;

    // Determine number of rows to move (1 or 4)
    if (camera_info.state.is_shutter_half_press || kbd_is_key_pressed(KEY_ZOOM_IN) || kbd_is_key_pressed(KEY_ZOOM_OUT)) c=4; else c=1;

    for (j = 0; j < c; ++j)
    {
        do
        {
            // Move to next or previous row
            gui_menu_curr_item += increment;

            if (gui_menu_curr_item < 0)                                     // Off top, move to bottom
            {
                gui_menu_curr_item = gui_menu_rows() - 1;
                adjust_top( gui_menu_curr_item, num_lines - 1);
            }
            else if (gui_menu_curr_item >= gui_menu_rows())                 // Off bottom, move to top
            {
                gui_menu_curr_item = gui_menu_top_item = 0;
            }
            else if (increment == 1)                                        // Still in menu, if moving down adjust scroll if needed
            {
                if ( distance_items(gui_menu_top_item, gui_menu_curr_item) >= num_lines - 1 )
                {
                    adjust_top( gui_menu_curr_item, num_lines-1 );
                    if ( distance_items( gui_menu_top_item, gui_menu_rows() ) < num_lines ) adjust_top( gui_menu_rows(), num_lines-1 );
                }
            }
            else                                                            // Still in menu, and moving up, adjust scroll
            {
                if (gui_menu_curr_item == gui_menu_top_item) 
                    --gui_menu_top_item;
            }

            // Check in case scroll moved off top of menu
            if (gui_menu_top_item < 0) gui_menu_top_item = 0;

        } while ((curr_menu->menu[gui_menu_curr_item].type & MENUITEM_MASK)==MENUITEM_TEXT || 
                 (curr_menu->menu[gui_menu_curr_item].type & MENUITEM_MASK)==MENUITEM_SEPARATOR ||
                 curr_menu->menu[gui_menu_curr_item].type & MENUITEM_HIDDEN );

        // Reset amount to increment integer values by
		gui_menu_reset_incr();
        gui_menu_disp_incr();

        // Redraw menu if needed
        if (gui_menu_redraw == 0) gui_menu_redraw=1;
    }
}

static int flag_editmode=0;	// 1 if current menu item is "edit"
static int item_prev_value = 0;

void gui_menu_set_editmode(int flag)
{
   if (flag_editmode!=flag ) {
	   if ( flag ) 
		   item_prev_value = *menuitem_get_valueptr(curr_menu,gui_menu_curr_item);

		if (!conf.menuedit_popup) {
			gui_menu_redraw = 1;
		} else {
			if ( flag )
				gui_set_mode(&menueditGuiHandler);
			else
				gui_set_mode(&menuGuiHandler);

			gui_menu_redraw = 2;
		}
   }   
   flag_editmode = flag;
}
int gui_menu_get_editmode()
{ 
	return flag_editmode;
}

void gui_menu_left( int value )
{
            if (gui_menu_curr_item >= 0) {
                switch (curr_menu->menu[gui_menu_curr_item].type & MENUITEM_MASK) {
                    case MENUITEM_INT:
                        update_int_value(value);
                        break;
                    case MENUITEM_BOOL:
                        update_bool_value();
                        break;
                    case MENUITEM_ENUM:
                    case MENUITEM_ENUM2:
                        update_enum_value(value);
                        break;
                    case MENUITEM_UP:
                        gui_menu_back();
                        break;
                }
            } else {
                gui_menu_back();
            }
}

void gui_menu_right( int value )
{
            if (gui_menu_curr_item >= 0) {
                switch (curr_menu->menu[gui_menu_curr_item].type & MENUITEM_MASK){
                    case MENUITEM_INT:
                        update_int_value(value);
                        break;
                    case MENUITEM_BOOL:
                        update_bool_value();
                        break;
                    case MENUITEM_ENUM:
                    case MENUITEM_ENUM2:
                        update_enum_value(value);
                        break;
                    case MENUITEM_SUBMENU_PROC:
                        select_proc();
                    case MENUITEM_SUBMENU:
                        select_sub_menu();
                        break;
                }
            }
}


// Purpose: cancel edit mode without apply changes
void gui_menu_cancel_editmode()
{
	// cancel change
    int *valueptr = menuitem_get_valueptr(curr_menu,gui_menu_curr_item);

    if ( valueptr )
        *valueptr = item_prev_value;

    gui_menu_set_editmode(0);
    gui_menu_left(0);	// process bounds and callbacks

	// keep quickdisable state on cancel
	if ( item_prev_value < 0 )
		turn_current_item_off();
}

//-------------------------------------------------------------------
// Process button presses when in GUI_MODE_MENU mode
int gui_menu_kbd_process() {

    switch (kbd_get_autoclicked_key() | get_jogdial_direction()) {
#if CAM_HAS_ERASE_BUTTON
        case KEY_ERASE:
#else    
        case KEY_SHOOT_HALF:
#endif
			if ( flag_editmode ) {
				gui_menu_cancel_editmode();
				break;
			}

            if (conf.user_menu_enable == 3) {
                if (curr_menu->title != LANG_MENU_USER_MENU) {
                    /*
                    * Add new entry
                    * user menu is currently not visible so no redraw necessary
                    */
                    add_user_menu_item(curr_menu->menu[gui_menu_curr_item],&gui_menu_curr_item);
                }
                else {
                    /*
                    * Remove entry from menu
                    */
                    del_user_menu_item(&gui_menu_curr_item);

                    /*
                    * Check to see if the last visible entry was deleted and we need need
                    * to move up our top menu item.
                    */
                    if(gui_menu_top_item)
                        if(!curr_menu->menu[gui_menu_top_item + num_lines-1].text)
                            gui_menu_top_item--;

                    /*
                    * menu list is smaller so have to redraw everything to get
                    * things like scroll bar correct.
                    */
                    gui_menu_redraw=2;

                    /*
                    * if the new menu is smaller than visible menu lines on screen
                    * you have to restore full screen before menu redraw.
                    * If you don't do this, then a new smaller menu will be drawn
                    * on top of the older larger menu
                    *
                    */
                    gui_menu_rows();
                    if( count_visible < num_lines)
                        gui_set_need_restore();
                }
            }
            break;
        case JOGDIAL_LEFT:
            if ( flag_editmode ) {
                gui_menu_left(-1);
            } else
                gui_menu_updown(-1);
            break;
        case KEY_UP:
            if ( flag_editmode ) {
                gui_menu_right(10);
            } else
            gui_menu_updown(-1);
            break;
        case JOGDIAL_RIGHT:
            if ( flag_editmode ) {
                gui_menu_right(1);
            } else
                gui_menu_updown(1);
            break;
        case KEY_DOWN: 
            if ( flag_editmode ) {
                gui_menu_left(-10);
            } else
            gui_menu_updown(1);
            break;
        case FRONTDIAL_LEFT:
        case KEY_LEFT:
            gui_menu_left(-1);
            break;
        case FRONTDIAL_RIGHT:
        case KEY_RIGHT:
            gui_menu_right(1);
            break;
        case KEY_MENU:
            // The only way to get this point - "edit" submode
			turn_current_item(0);	// toggle state
			do_callback();
            break;
        case KEY_SET:
            if ( flag_editmode) {
                gui_menu_set_editmode(0);
            } else if (gui_menu_curr_item >= 0) {
                switch (curr_menu->menu[gui_menu_curr_item].type & MENUITEM_MASK){
                    case MENUITEM_INT:
                        if (camera_info.state.is_shutter_half_press )
                        {
                            *(curr_menu->menu[gui_menu_curr_item].value) = 0;
                        }
                        else {
                            gui_menu_set_editmode(1);
                        }							
                        gui_menu_redraw=1;
                        break;
                    case MENUITEM_BOOL:
                        update_bool_value();
                        break;
                    case MENUITEM_SUBMENU_PROC:
                    case MENUITEM_PROC:
                        select_proc();
                        break;
                    case MENUITEM_SUBMENU:
                        select_sub_menu();
                        break;
                    case MENUITEM_UP:
                        gui_menu_back();
                        break;
                    case MENUITEM_COLOR_FG:
                    case MENUITEM_COLOR_BG:
                        item_color=((unsigned char*)(curr_menu->menu[gui_menu_curr_item].value)) + (((curr_menu->menu[gui_menu_curr_item].type & MENUITEM_MASK)==MENUITEM_COLOR_BG)?1:0);
                        module_palette_run(PALETTE_MODE_SELECT, FG_COLOR(*item_color), gui_menu_color_selected);
                        gui_menu_redraw=2;
                        break;
                    case MENUITEM_ENUM:
                    case MENUITEM_ENUM2:
                        // @tsv: TODO - Check enum size<=3 and do not lock if 
						gui_menu_set_editmode(1);
                        gui_menu_redraw=1;
                        break;
                }
            }
            break;

#if CAM_HAS_ZOOM_LEVER
        case KEY_ZOOM_IN:
            /*
            * Move current entry up in menu
            * if in user menu edit mode and viewing user menu
            */
            if( (conf.user_menu_enable == 3)  && (curr_menu->title == LANG_MENU_USER_MENU)) {
                move_user_menu_item_up(&gui_menu_curr_item);
                if(gui_menu_curr_item < gui_menu_top_item+1) {
                    if(gui_menu_curr_item)
                        gui_menu_top_item = gui_menu_curr_item-1;
                }

                gui_menu_redraw=1;
            }
            else {
                if (int_incr >= 10){
                    int_incr /= 10;
                }
                gui_menu_disp_incr();
            }
            break;

        case KEY_ZOOM_OUT:
            /*
            * Move current entry down in menu
            * if in user menu edit mode and viewing user menu
            */
            if( (conf.user_menu_enable == 3)  && (curr_menu->title == LANG_MENU_USER_MENU)) {
                move_user_menu_item_down(&gui_menu_curr_item);
                if(gui_menu_curr_item > gui_menu_top_item + num_lines -2) {
                    if((gui_menu_curr_item < USER_MENU_ITEMS) && curr_menu->menu[gui_menu_curr_item +1].text)
                        gui_menu_top_item++;
                }

                gui_menu_redraw=1;
            }
            else {
                if (int_incr <= 1000){
                    int_incr *= 10;
                }
                gui_menu_disp_incr();
            }
            break;

        case KEY_DISPLAY:
                if ( flag_editmode ) {
					gui_menu_cancel_editmode();					  
                } else {
            		gui_menu_back();
                }            
            break;
#else
        case KEY_DISPLAY:
            if ( flag_editmode ) {
				gui_menu_cancel_editmode();					  
            } else if (conf.user_menu_enable == 3 && curr_menu->title == LANG_MENU_USER_MENU) {
                gui_menu_back();
            }
            else {
                if (int_incr <= 1000){
                    int_incr *= 10;
                }
                else {
                    int_incr = 1;
                }
                gui_menu_disp_incr();
                break;
            }
#endif
    }

    return 0;
}

static int count_visible_initial;

//-------------------------------------------------------------------
// Draw menu scroll bar if needed, and title bar
void gui_menu_draw_initial() { 
    color cl = BG_COLOR(conf.menu_title_color);

    // call to calc visible rows
    gui_menu_rows();

	// remember num of rows for which values are adjusted
	count_visible_initial = count_visible;

    if (count_visible > num_lines)
    {
        y = ((camera_screen.height-(num_lines-1)*rbf_font_height())>>1);
        wplus = 8; 
        // scrollbar background 
        draw_filled_rect((x+w), y, (x+w)+wplus, y+num_lines*rbf_font_height()-1, MAKE_COLOR(BG_COLOR(conf.menu_color), BG_COLOR(conf.menu_color))); 
    }
    else
    {
        wplus = 0;
        if (conf.menu_center)
        {
            y = (camera_screen.height-(count_visible-1)*rbf_font_height())>>1; 
        }
        else
        {
            y = ((camera_screen.height-(num_lines-1)*rbf_font_height())>>1);  
        }
    }

    rbf_draw_menu_header(x, y-rbf_font_height(), w+wplus, (conf.menu_symbol_enable)?curr_menu->symbol:0, lang_str(curr_menu->title), conf.menu_title_color);
    gui_menu_disp_incr();
}

//-------------------------------------------------------------------

// Local variables used by menu draw functions
static int imenu, yy, xx, symbol_width;
static color cl, cl_symbol;
static int is_cur_edited;

// Common code extracted from gui_menu_draw for displaying the symbol on the left
static void gui_menu_draw_symbol(int num_symbols)
{
    if (conf.menu_symbol_enable)
    {
        xx += rbf_draw_char(xx, yy, ' ', cl_symbol);
        xx += symbol_width = rbf_draw_symbol(xx, yy, curr_menu->menu[imenu].symbol, cl_symbol);
        symbol_width = (symbol_width * num_symbols) + len_space;
    }
    else
    {
        symbol_width = 0;
    }

    xx += rbf_draw_char(xx, yy, ' ', cl);
}

// Common code extracted from gui_menu_draw for displaying an int, enum or bool value on the right
static void gui_menu_draw_value(const char *str, int len_str)
{
    gui_menu_draw_symbol(1);
    xx += rbf_draw_string_len(xx, yy, w-len_space-len_space-len_br1-len_str-len_br2-len_space-symbol_width, lang_str(curr_menu->menu[imenu].text), cl);
    xx += rbf_draw_string(xx, yy, (is_cur_edited?" >":" ["), cl);
    xx += rbf_draw_string_right_len(xx, yy, len_str, str, cl);
    rbf_draw_string(xx, yy, (is_cur_edited?"< ":"] "), cl);
}

// Common code extracted from gui_menu_draw for displaying a text menu string
static void gui_menu_draw_text(char *str, int num_symbols)
{
    gui_menu_draw_symbol(num_symbols);
    xx += rbf_draw_string_len(xx, yy, w-len_space-len_space-symbol_width, str, cl);
    if ((num_symbols == 2) && conf.menu_symbol_enable)
        xx += rbf_draw_symbol(xx, yy, 0x52, cl_symbol);
    rbf_draw_char(xx, yy, ' ', cl);
}

//-------------------------------------------------------------------
void gui_menu_draw(int enforce_redraw) {
    static char tbuf[64];
    int i, j;
    const char *ch = "";

	if ( enforce_redraw )
		gui_menu_redraw = 2;

    if (gui_menu_redraw)
    {
		// if partial update
        if (gui_menu_redraw!=2)
		{
			// check if size of menu was changed
			gui_menu_rows();
			if ( count_visible != count_visible_initial)
				gui_menu_redraw = 2;

			// if it was shrinked, ask for restore and wait for next draw cycle
            if ( count_visible < count_visible_initial &&
				 !(enforce_redraw & GUI_REDRAWFLAG_DRAW_RESTORED) ) {
				draw_restore();
			}
		}

        if (gui_menu_redraw==2)
            gui_menu_draw_initial();

        gui_menu_redraw=0;

        for (imenu=gui_menu_top_item, i=0, yy=y; curr_menu->menu[imenu].text && i<num_lines; ++imenu)
        {
            if (curr_menu->menu[imenu].type & MENUITEM_HIDDEN)
				continue;

            cl = (gui_menu_curr_item==imenu)?conf.menu_cursor_color:conf.menu_color;
            /*
            * When cursor is over a symbol, force symbol background color to be the menu cursor color but
            * keep the symbol color user defined.
            * old method was to set the symbol color to the symbol background color when the cursor highlighted it.
            * This method allows the user to have any symbol color and background color they want with the restriction
            * that the symbol background color will match the rest of the line when the cursor highlights it.
            * It creates a nice consistent look expecially when the symbol color matches the menu text color.
            * without this mod, there is no way to ever make the symbol color match the color of the rest of text menu line
            * when the cursor highlights a line.
            */
            cl_symbol = (gui_menu_curr_item==imenu)?MAKE_COLOR(BG_COLOR(cl),FG_COLOR(conf.menu_symbol_color)):conf.menu_symbol_color; //color 8Bit=Hintergrund 8Bit=Vordergrund
            is_cur_edited = (gui_menu_curr_item==imenu && flag_editmode);

            xx = x;

            switch (curr_menu->menu[imenu].type & MENUITEM_MASK)
            {
            case MENUITEM_BOOL:
                gui_menu_draw_value((*(curr_menu->menu[imenu].value))?"\x95":"", len_bool);
                break;
            case MENUITEM_INT:
                if ( *(curr_menu->menu[imenu].value) < 0 ) 
                    strcpy(tbuf,"Off");
                else
                sprintf(tbuf, "%d", *(curr_menu->menu[imenu].value));
                gui_menu_draw_value(tbuf, len_int);
                break;
            case MENUITEM_SUBMENU_PROC:
            case MENUITEM_SUBMENU:
                sprintf(tbuf, "%s%s", lang_str(curr_menu->menu[imenu].text),(conf.menu_symbol_enable)?"":" ->");
                gui_menu_draw_text(tbuf,2);
                break;
            case MENUITEM_UP:
                sprintf(tbuf, "%s%s", (conf.menu_symbol_enable)?"":"<- ", lang_str(curr_menu->menu[imenu].text));
                gui_menu_draw_text(tbuf,1);
                break;
            case MENUITEM_PROC:
            case MENUITEM_TEXT:
                gui_menu_draw_text(lang_str(curr_menu->menu[imenu].text),1);
                break;
            case MENUITEM_SEPARATOR:
                rbf_draw_char(x, yy, ' ', cl);

                if (lang_str(curr_menu->menu[imenu].text)[0])
                    sprintf(tbuf," %s ",lang_str(curr_menu->menu[imenu].text));
                else
                    tbuf[0] = 0;

                j = rbf_str_width(tbuf);
                xx += ((w - j) >> 1);

                if (xx > (x + len_space))
                {
                    draw_filled_rect(x+len_space, yy, xx-1, yy+rbf_font_height()/2-1, MAKE_COLOR(BG_COLOR(cl), BG_COLOR(cl)));
                    draw_line(x+len_space, yy+rbf_font_height()/2, xx-1, yy+rbf_font_height()/2, cl);
                    draw_filled_rect(x+len_space, yy+rbf_font_height()/2+1, xx-1, yy+rbf_font_height()-1, MAKE_COLOR(BG_COLOR(cl), BG_COLOR(cl)));
                }
                else
                {
                    xx = x;
                }

                if (j) xx += rbf_draw_clipped_string(xx, yy, tbuf, cl, 0, w);

                if (xx < (x+w-len_space))
                {
                    draw_filled_rect(xx, yy, x+w-len_space-1, yy+rbf_font_height()/2-1, MAKE_COLOR(BG_COLOR(cl), BG_COLOR(cl)));
                    draw_line(xx, yy+rbf_font_height()/2, x+w-1-len_space, yy+rbf_font_height()/2, cl);
                    draw_filled_rect(xx, yy+rbf_font_height()/2+1, x+w-len_space-1, yy+rbf_font_height()-1, MAKE_COLOR(BG_COLOR(cl), BG_COLOR(cl)));
                }

                rbf_draw_char(x+w-len_space, yy, ' ', cl);
                break;
            case MENUITEM_COLOR_FG:
            case MENUITEM_COLOR_BG:
                gui_menu_draw_symbol(1);
                xx+=rbf_draw_string_len(xx, yy, w-len_space-symbol_width, lang_str(curr_menu->menu[imenu].text), cl);
                draw_filled_round_rect(x+w-1-cl_rect-2-len_space, yy+2, x+w-1-2-len_space, yy+rbf_font_height()-1-2, 
                    MAKE_COLOR(((*(curr_menu->menu[imenu].value))>>(((curr_menu->menu[imenu].type & MENUITEM_MASK)==MENUITEM_COLOR_BG)?8:0))&0xFF, 
                               ((*(curr_menu->menu[imenu].value))>>(((curr_menu->menu[imenu].type & MENUITEM_MASK)==MENUITEM_COLOR_BG)?8:0))&0xFF));
                break;
            case MENUITEM_ENUM:
                if (curr_menu->menu[imenu].value) {
                    if ( curr_menu->menu[imenu].arg && *((int*)curr_menu->menu[imenu].arg)<0 )
                       ch = "Off";
                    else
                       ch = ((const char* (*)(int change, int arg))(curr_menu->menu[imenu].value))(0, curr_menu->menu[imenu].arg);
                }
                gui_menu_draw_value(ch, len_enum);
                break;
            case MENUITEM_ENUM2:
                if (curr_menu->menu[imenu].value)
                {
                    if ( *(curr_menu->menu[imenu].value)<0 )
                       ch = "Off";
                    else
                       ch = gui_change_enum2(&curr_menu->menu[imenu], 0);
                }
                gui_menu_draw_value(ch, len_enum);
                break;
            }
            ++i;
            yy+=rbf_font_height();
        }

        // scrollbar
        if (count_visible > num_lines)
        {
            i = num_lines*rbf_font_height()-1 -1;           // full height
            j = i*num_lines/count_visible;                  // bar height
            if (j<20) j=20;
            i = (i-j)*((gui_menu_curr_item<0)?0:distance_items(0,gui_menu_curr_item))/(count_visible-1);   // top pos
            draw_filled_round_rect((x+w)+2, y+1,   (x+w)+6, y+1+i,                             MAKE_COLOR(COLOR_BLACK, COLOR_BLACK));
            draw_filled_round_rect((x+w)+2, y+i+j, (x+w)+6, y+num_lines*rbf_font_height()-1-1, MAKE_COLOR(COLOR_BLACK, COLOR_BLACK));
            draw_filled_round_rect((x+w)+2, y+1+i, (x+w)+6, y+i+j,                             MAKE_COLOR(COLOR_WHITE, COLOR_WHITE));
        }

    }
}

extern CMenuItem* find_mnu(CMenu *curr_menu, int itemid );

// Hide/Unhide item found in menu starting from "cmenu" by its lang_id
int menuitem_foreach2( CMenu* cmenu, int itemid, int tmp, int visibility )
{
	CMenuItem* item = find_mnu( cmenu, itemid );
	if ( !item )
		return 0;

	if ( visibility )
     *((short*)&(item->type)) &= ~MENUITEM_HIDDEN;   
	else	
     *((short*)&(item->type)) |= MENUITEM_HIDDEN;   
	return 1;
}

int gui_menu_get_editmode();

//-------------------------------------------------------------------
// Menu button handler for Menu mode
void gui_menu_kbd_process_menu_btn()
{
    extern int gui_user_menu_flag;
    extern CMenu root_menu;

    // In edit submode - MenuButton mean "Toggle feature" and processed by gui_menu_kbd_process
    if ( gui_menu_get_editmode() ) {
		gui_menu_kbd_process();
		return;
    }

    gui_menu_unload_module_menus();

    conf_save_new_settings_if_changed();

    if (gui_user_menu_flag)
    {
        gui_set_mode(&menuGuiHandler);
        gui_user_menu_flag = 0;
        gui_menu_init(&root_menu);
    }
    else
        gui_set_mode(&altGuiHandler);
}

//-------------------------------------------------------------------
// GUI handler for menus
gui_handler menuGuiHandler = { GUI_MODE_MENU, gui_menu_draw, gui_menu_kbd_process, gui_menu_kbd_process_menu_btn, 0, GUI_MODE_MAGICNUM };
//-------------------------------------------------------------------

static void gui_menuedit_draw_text(char *str, int is_center)
{
	int xx1;
	color bg = MAKE_COLOR( BG_COLOR(conf.menu_color), BG_COLOR(conf.menu_color) );
	int len = rbf_str_width(str);

	if ( len > w ) 
		len = w;
	if ( is_center)
		xx = (w-len)>>1;
	else
		xx = 0;

    draw_filled_rect(x, yy, x+xx, yy+rbf_font_height()-1, bg );
	xx1 = x+xx;
    xx1+= rbf_draw_string_len( xx1, yy, len, str, cl);
	if (xx1 < (x+w) )
	    draw_filled_rect(xx1, yy, x+w-1, yy+rbf_font_height()-1, bg );
}

void gui_menuedit_draw_initial() 
{ 
	int i;

    count_visible = 8;
    y = (camera_screen.height-(count_visible-1)*rbf_font_height())>>1; 

	// Header
    rbf_draw_menu_header(x, y-rbf_font_height(), w, 0, "Edit value", conf.menu_title_color);
    gui_menu_disp_incr();

	// Create body
	static char* mbox_map[] =
		{
			"",
			"",  // valuename
			"",
			0,
			"",
			"",
#if CAM_HAS_ZOOM_LEVER
			"arrow/jogdial=change value, ZOOM=incrementor",
#else
			"arrow/jogdial=change value",
#endif
			""   // bottom line
		};

	mbox_map[1] = lang_str(curr_menu->menu[gui_menu_curr_item].text);
	if ( curr_menu->menu[gui_menu_curr_item].type & MENUITEM_QUICKDISABLE)
		mbox_map[7]="DISP=Cancel, MENU=turn on/off, SET=Confirm";
	else
		mbox_map[7]="DISP=Cancel, SET=Confirm";

	// Display body
    cl = conf.menu_color;
	for ( yy=y, i=0; i<count_visible; i++, yy += rbf_font_height() ) {
		if ( !mbox_map[i] )
			continue;
		gui_menuedit_draw_text( lang_str((int)mbox_map[i]), (i<4) );
	}
}

void gui_menuedit_draw(int enforce_redraw) {
    char tbuf[64];

	if ( enforce_redraw )
		gui_menu_redraw = 2;

    if (gui_menu_redraw)
    {
        if (gui_menu_redraw==2)
            gui_menuedit_draw_initial();

        gui_menu_redraw=0;

        cl = conf.menu_cursor_color;
		yy = y + 3*rbf_font_height();

		int* valueptr = menuitem_get_valueptr( curr_menu, gui_menu_curr_item );
		if (!valueptr)
			strcpy(tbuf,"---");
		else if (*valueptr<0)
			strcpy(tbuf,"[Off]");
		else {
	        switch (curr_menu->menu[gui_menu_curr_item].type & MENUITEM_MASK)
			{
        	    case MENUITEM_INT:
                	sprintf(tbuf, "[%d]", *valueptr);
                	break;
            	case MENUITEM_ENUM:
                    sprintf(tbuf,"[%s]",((enum_callback_t)curr_menu->menu[gui_menu_curr_item].value)(0, curr_menu->menu[gui_menu_curr_item].arg) );
	                break;
	            case MENUITEM_ENUM2:
                    sprintf(tbuf,"[%s]", gui_change_enum2(&curr_menu->menu[gui_menu_curr_item], 0) );
					break;
				default:
					strcpy(tbuf,"---");
            }
		}
		gui_menuedit_draw_text( tbuf, 1 );
	}
}

//-------------------------------------------------------------------
// GUI handler for menus
gui_handler menueditGuiHandler = { GUI_MODE_MENU, gui_menuedit_draw, gui_menu_kbd_process, gui_menu_kbd_process_menu_btn, 0, GUI_MODE_MAGICNUM };
//-------------------------------------------------------------------


/*
// Infrastructure below cause strange side-effects so it is replaced by simplified show/hide
// List of catched side-effects: shutdown on start, damage "Menu setting" menu or its first item
//-------------------------------------------------------------------

//-------------------------------------------------------------------
typedef void menuitem_action_func_t( CMenuItem* item );

// from .h
enum { FLAG_RECURSIVE=1, FLAG_FIND_ALL=2, FLAG_SKIP_USERMENU=4 };
extern int menuitem_foreach( CMenu* menu, int itemid, int mode, menuitem_action_func_t* actionfunc );
extern int menuitem_foreach2( CMenu* menu, int itemid, int tmp, int visibility);

extern void menuitem_hide( CMenuItem* item );
extern void menuitem_unhide( CMenuItem* item );
//CMenuItem* find_mnu(CMenu *curr_menu, int itemid );
extern int value_turn_state( int* valueptr, int dir );

//---------------------------
void menuitem_hide( CMenuItem* item )
{
     *((short*)&(item->type)) |= MENUITEM_HIDDEN;   
}

void menuitem_unhide( CMenuItem* item )
{
     *((short*)&(item->type)) &= ~MENUITEM_HIDDEN;   
}


int menuitem_turn_on( CMenuItem* item )
{
	menuitem_turn_state(item,1);
}

int menuitem_turn_off( CMenuItem* item )
{
	menuitem_turn_state(item,-1);
}

//-------------------------------------------------------------------

//
// PURPOSE:		Apply actionfunc for menuitem with correct id
// ARGUMENTS:	curr_menu - start menu
//				id	 - LANG_ID of looked up item
//				mode - flags FLAG_RECURSIVE(lookup into deep of tree, or this menu only if absent)
//							 FLAG_FIND_ALL(change status of all matched items, or first found only if absent)
//							 FLAG_SKIP_USERMENU(skip usermenu in recursion, or go everywhere)
//				actionfunc - this func will be called for found item
// RETURN VALUE: number of found items
//
int menuitem_foreach( CMenu* cmenu, int itemid, int mode, menuitem_action_func_t* actionfunc )
{
   int rv = 0;

   // processing by idx
   for (imenu=0; cmenu->menu[imenu].text; ++imenu) {
	 if ( lang_strhash31(cmenu->menu[imenu].text) == itemid ) {
         actionfunc( (CMenuItem*) &(cmenu->menu[imenu]) );
		 rv++;
	 }

	 if ( (mode & FLAG_RECURSIVE ) &&
	 	 (cmenu->menu[imenu].type & MENUITEM_MASK) == MENUITEM_SUBMENU ) {

		if ( !(mode & FLAG_SKIP_USERMENU) ||
			cmenu->menu[gui_menu_curr_item].text != LANG_MENU_USER_MENU) {
	      rv += menuitem_foreach((CMenu*)(cmenu->menu[imenu].value), itemid, mode, actionfunc);
		}
     }

	 if	( rv && !(mode & FLAG_FIND_ALL) )
	 	break;
   }
   return rv;
}

//-------------------------------------------------------------------

static CMenuItem* found_item = 0;
static void menuitem_find ( CMenuItem* item )
{
	found_item = item;
}

// Find menuitem by its id in non-usermenu
CMenuItem* find_mnu(CMenu *curr_menu, int itemid )
{                                                                                                 
	if ( !menuitem_foreach( curr_menu, itemid, FLAG_RECURSIVE|FLAG_SKIP_USERMENU, menuitem_find ) )
		found_item = 0;
	return found_item;
}
*/
