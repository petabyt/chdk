#ifndef GUI_OSD_H
#define GUI_OSD_H

// CHDK OSD interface

// Note: used in modules and platform independent code. 
// Do not add platform dependent stuff in here (#ifdef/#endif compile options or camera dependent values)

//-------------------------------------------------------------------
#define ZOOM_SHOW_X                     0
#define ZOOM_SHOW_FL                    1
#define ZOOM_SHOW_EFL                   2

#define DOF_DONT_SHOW                   0
#define DOF_SHOW_IN_DOF                 1
#define DOF_SHOW_IN_DOF_EX              2
#define DOF_SHOW_IN_MISC                3
#define DOF_SHOW_IN_MISC_EX             4

//-------------------------------------------------------------------
extern void gui_osd_draw_dof();
extern void gui_osd_draw_state();
extern void gui_osd_draw_raw_info();
extern void gui_osd_draw_values(int showtype);
extern void gui_osd_draw_clock(int x, int y, color cl);
extern void gui_osd_draw_temp();
extern void gui_draw_debug_vals_osd();
extern void gui_update_debug_page();

extern void gui_draw_osd();
extern void gui_kbd_shortcuts();

extern void gui_osd_calc_dof();

extern void gui_osd_draw_ev_video(int visible);

extern gui_handler defaultGuiHandler;

//------------------------------------------------------------------- 

#define DEBUG_DISPLAY_NONE 0
#define DEBUG_DISPLAY_PROPS 1
#define DEBUG_DISPLAY_PARAMS 2
#define DEBUG_DISPLAY_TASKS 3

//-------------------------------------------------------------------

#endif
