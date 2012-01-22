#ifndef GUI_OSD_H
#define GUI_OSD_H

//-------------------------------------------------------------------
#define ZOOM_SHOW_X                     0
#define ZOOM_SHOW_FL                    1
#define ZOOM_SHOW_EFL                   2

#define ZOOM_SCALE_042                  0
#define ZOOM_SCALE_100                  1
#define ZOOM_SCALE_175                  2
#define ZOOM_SCALE_200                  3
#define ZOOM_SCALE_300                  4

//ARM begin
#define DOF_DONT_SHOW                   0
#define DOF_SHOW_IN_DOF                 1
#define DOF_SHOW_IN_MISC                2
//ARM End

//-------------------------------------------------------------------
extern void gui_draw_osd_le(int arg);

extern void gui_osd_draw_dof();
extern void gui_osd_draw_state();
extern void gui_osd_draw_raw_info();
extern void gui_osd_draw_values();
extern void gui_osd_draw_clock(int x, int y, color cl);
extern void gui_osd_draw_temp();
extern void gui_osd_draw_seconds();
extern void gui_osd_draw_ev();

//ARM Begin
extern void gui_osd_calc_dof();
extern void gui_osd_calc_expo_param();
//ARM End

extern void gui_osd_draw_movie_time_left();

extern void gui_osd_draw_ev_video(int visible);

//-------------------------------------------------------------------
#endif
