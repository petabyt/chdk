#ifndef GUI_USER_MENU_H
#define GUI_USER_MENU_H

//-------------------------------------------------------------------
extern void add_user_menu_item(CMenuItem curr_menu_item, int* cur_memnu_item_indx);
extern void del_user_menu_item(int* cur_memnu_item_indx);
extern void move_user_menu_item_up(int* cur_memnu_item_indx);
extern void move_user_menu_item_down(int* cur_memnu_item_indx);
extern void user_menu_save();
extern void user_menu_restore();

//-------------------------------------------------------------------

#endif
