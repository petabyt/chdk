#ifndef GUI_FSELECT_H
#define GUI_FSELECT_H

//-------------------------------------------------------------------
extern void module_fselect_init(int title, const char* prev_dir, const char* default_dir, void (*on_select)(const char *fn));
extern void module_fselect_init_w_mode(int title, const char* prev_dir, const char* default_dir, void (*on_select)(const char *fn), unsigned int key_redraw_mode);
//-------------------------------------------------------------------
#endif
