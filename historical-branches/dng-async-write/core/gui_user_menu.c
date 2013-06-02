#include "camera_info.h"
#include "stdlib.h"
#include "conf.h"
#include "keyboard.h"
#include "font.h"
#include "lang.h"
#include "gui.h"
#include "gui_lang.h"
#include "gui_draw.h"
#include "gui_menu.h"
#include "gui_mbox.h"
#include "modules.h"
#include "module_load.h"

#define USER_MENU_IS_SCRIPT     -1
#define USER_MENU_IS_MODULE     -2

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
void gui_load_user_menu_script(const char *fn) 
{
    if (fn)
    {
		script_load(fn);

        // exit menu system on the assumption the user will want to run the script just loaded
        gui_set_mode(&altGuiHandler);
    }
}

//-------------------------------------------------------------------
static CMenuItem* find_mnu_adv(CMenu *curr_menu, int flags, int itemid )
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
		if ((flags & FLAG_FIND_RECURSIVE) &&
		  (curr_menu->menu[gui_menu_curr_item].type & MENUITEM_MASK) == MENUITEM_SUBMENU) {

				if (curr_menu->menu[gui_menu_curr_item].text != LANG_MENU_USER_MENU) {
					rv = find_mnu((CMenu*)(curr_menu->menu[gui_menu_curr_item].value), itemid);
					if ( rv )
						return rv;
				}
		}
		gui_menu_curr_item++;
	}
	return 0;
}

CMenuItem* find_mnu(CMenu *curr_menu, int itemid )
{
	return find_mnu_adv(curr_menu, FLAG_FIND_RECURSIVE, itemid );
}

void user_menu_save() {
    int x;
    for (x=0; x<USER_MENU_ITEMS; x++) {
		/*
		 * First entry in user_submenu_items is reserved for the "Main Menu"
 		 * conf.user_menu_vars only tracks/saves the real user entries.
 		 */
	
        if ( user_submenu_items[x+1].text )
        {
            if ( user_submenu_items[x+1].value == (int *)gui_load_user_menu_script )
            {
                conf.user_menu_vars.items[x].var = USER_MENU_IS_SCRIPT;                             // flag script entries specially 
            }
            else if ((user_submenu_items[x+1].value == (int *)module_run) && ((user_submenu_items[x+1].type & MENUITEM_USER_MODULE) == MENUITEM_USER_MODULE))
            {
                conf.user_menu_vars.items[x].var = USER_MENU_IS_MODULE;                             // flag module entries specially 
            }
            else
            {
                conf.user_menu_vars.items[x].var = lang_strhash31(user_submenu_items[x+1].text);    // otherwise save a hash
            }
        }
        else
        {
            conf.user_menu_vars.items[x].var = 0;
            if (conf.user_menu_vars.items[x].script_file != 0)
            {
                free(conf.user_menu_vars.items[x].script_file);
                conf.user_menu_vars.items[x].script_file = 0;
            }
            if (conf.user_menu_vars.items[x].script_title != 0)
            {
                free(conf.user_menu_vars.items[x].script_title);
                conf.user_menu_vars.items[x].script_title = 0;
            }
        }
    } 
}

static void set_user_menu_extern(int menu, int var, char sym, short type, int* func)
{
    // restore the script/module entry
    user_submenu_items[menu].symbol = sym;
    user_submenu_items[menu].opt_len = 0;
    user_submenu_items[menu].type = type;
    user_submenu_items[menu].text = (int)conf.user_menu_vars.items[var].script_title;
    user_submenu_items[menu].value = func;
    user_submenu_items[menu].arg = (int)conf.user_menu_vars.items[var].script_file;  
}

void user_menu_restore()
{
    int x, y;
    CMenuItem* item=0;
    /*
     * First entry in user_submenu_items is reserved for the "Main Menu"
     * conf.user_menu_vars only tracks/saves the real user entries.
     */
       
    for (x=0, y=1; x<USER_MENU_ITEMS; x++, y++)
    {
        if (conf.user_menu_vars.items[x].var == USER_MENU_IS_SCRIPT)    // special flag- there is no hash for script entries
        {
            set_user_menu_extern(y, x, 0x35, MENUITEM_PROC, (int*)gui_load_user_menu_script);
        }
        else if (conf.user_menu_vars.items[x].var == USER_MENU_IS_MODULE)    // special flag- there is no hash for module entries
        {   
            set_user_menu_extern(y, x, 0x28, MENUITEM_PROC|MENUITEM_USER_MODULE, (int*)module_run);
        }
        else
        { 
            if (conf.user_menu_vars.items[x].var > 0 )  // look up the menu text
                 item = find_mnu(&root_menu, conf.user_menu_vars.items[x].var);
            else item = NULL ;
            
            if ( item )                                 // add back in if found
            {
                user_submenu_items[y] = *item;
            }
            else                                        // otherwise clear the menu entry
            {
                user_submenu_items[y].text = 0;            
                break ;                                 // and exit - all done !
            }
        }
    }  
}

