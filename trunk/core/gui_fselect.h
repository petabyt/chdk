#ifndef GUI_FSELECT_H
#define GUI_FSELECT_H

//-------------------------------------------------------------------
extern void gui_fselect_init(int title, const char* prev_dir, const char* default_dir, void (*on_select)(const char *fn));
extern char* gui_fselect_result();
extern void gui_fselect_force_redraw();
extern void finalize_fselect();
//-------------------------------------------------------------------
#endif
