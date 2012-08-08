#include "stdlib.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "conf.h"
#include "camera.h"
#include "font.h"
#include "lang.h"
#include "gui.h"
#include "gui_lang.h"
#include "gui_draw.h"
#include "gui_menu.h"
#include "gui_mbox.h"
#include "modules.h"
#include "module_load.h"

//-------------------------------------------------------------------
extern  CMenu   root_menu;

//-------------------------------------------------------------------
static void rinit()
{
	// Erase screen if switching from user menu to main menu
	// in case the user menu is larger than the main menu
	// otherwise it leaves remnants of the user menu above and below
	// the main menu.
    gui_set_need_restore();
	gui_menu_init(&root_menu);
}

//-------------------------------------------------------------------
/*
 * 1 extra entry for the "Main menu" and 1 for null when the menu is full with user selections
 * Compiler will zero init remaining portion of array so no there is no hidden relationship between
 * this structure and the value of USER_MENU_ITEMS. The value of USER_MENU_ITEMS can be anything you
 * wish and everything automagically works.
*/

static CMenuItem user_submenu_items[USER_MENU_ITEMS + 2] = {
	MENU_ITEM(0x20,LANG_MENU_MAIN_TITLE,     MENUITEM_PROC,  rinit, 0 )
};

CMenu user_submenu = {0x2e,LANG_MENU_USER_MENU, NULL, user_submenu_items };

//-------------------------------------------------------------------
void add_user_menu_item(CMenuItem curr_menu_item, int* cur_memnu_item_indx)
{
    int i;

    /*
     * Insert new Item at end of existing entries
     */
    for(i = 1; i < USER_MENU_ITEMS + 1; i++)
    {
        if(!user_submenu_items[i].text)
        {
            user_submenu_items[i] = curr_menu_item;
            char buf[200];
            sprintf(buf,lang_str(LANG_USER_MENU_ITEM_ADDED), lang_str(curr_menu_item.text));
            gui_mbox_init(LANG_MENU_USER_MENU, (int)buf, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
            return;
        }
    }
    gui_mbox_init(LANG_MENU_USER_MENU, LANG_USER_MENU_FULL, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
}

void del_user_menu_item(int* cur_memnu_item_indx)
{
    int i;

    // don't allow deleting link to main menu
    if (*cur_memnu_item_indx == 0)
        return;

    /*
     * Delete user menu entry by sliding all the lower valid/existing entries up.
     */
    for(i = *cur_memnu_item_indx; user_submenu_items[i].text; i++)
    {
        user_submenu_items[i] = user_submenu_items[i+1];
    }

    /*
     * there were no valid entries below this one, so
     * the index pointer must be decremented.
     */
    if(!user_submenu_items[*cur_memnu_item_indx].text)
        *cur_memnu_item_indx -= 1;
}

static void move_user_menu_item(int* cur_memnu_item_indx, int dir)
{
    // Move current user menu item up (dir = -1) or down (dir = 1)
    CMenuItem tmp_menu_item = user_submenu_items[*cur_memnu_item_indx + dir];
    user_submenu_items[*cur_memnu_item_indx + dir] = user_submenu_items[*cur_memnu_item_indx];
    user_submenu_items[*cur_memnu_item_indx] = tmp_menu_item;
    *cur_memnu_item_indx += dir;
}

void move_user_menu_item_up(int* cur_memnu_item_indx)
{
    /*
     * Move entry up
     */
    if (*cur_memnu_item_indx > 1)
        move_user_menu_item(cur_memnu_item_indx, -1);
}

void move_user_menu_item_down(int* cur_memnu_item_indx)
{
    // don't allow moving link to main menu
    if (*cur_memnu_item_indx == 0)
        return;

    /*
     * Move entry down below next entry if next entry is not empty
     */
    if((*cur_memnu_item_indx < (USER_MENU_ITEMS)) && (user_submenu_items[*cur_memnu_item_indx +1].text))
        move_user_menu_item(cur_memnu_item_indx, 1);
}

//-------------------------------------------------------------------
CMenuItem* find_mnu(CMenu *curr_menu, int itemid )
{
	int gui_menu_curr_item;
	CMenuItem* rv=0;

	if ( itemid==0 )
		return 0;		

	gui_menu_curr_item = 0;
	while(curr_menu->menu[gui_menu_curr_item].text) {
		if ( lang_strhash31(curr_menu->menu[gui_menu_curr_item].text) == itemid){
			return (CMenuItem*) &(curr_menu->menu[gui_menu_curr_item]);
		}
		if ((curr_menu->menu[gui_menu_curr_item].type & MENUITEM_MASK) == MENUITEM_SUBMENU)
			if (curr_menu->menu[gui_menu_curr_item].text != LANG_MENU_USER_MENU) {
				rv = find_mnu((CMenu*)(curr_menu->menu[gui_menu_curr_item].value), itemid);
				if ( rv )
					return rv;
			}
		gui_menu_curr_item++;
	}
	return 0;
}

void user_menu_save() {
    int x;
	for (x=0; x<USER_MENU_ITEMS; x++) {
		/*
		 * First entry in user_submenu_items is reserved for the "Main Menu"
 		 * conf.user_menu_vars only traks/saves the real user entries.
 		 */
 		conf.user_menu_vars[x] = lang_strhash31(user_submenu_items[x+1].text);
	}
}

void user_menu_restore() {
    int x;
	CMenuItem* item=0;

 	for (x=0; x<USER_MENU_ITEMS; x++) {
 		/*
 		 * First entry in user_submenu_items is reserved for the "Main Menu"
 		 * conf.user_menu_vars only traks/saves the real user entries.
 		 */
 		 item = find_mnu(&root_menu, conf.user_menu_vars[x]);
		 if ( item )
			user_submenu_items[x+1] = *item;
 	}
}
