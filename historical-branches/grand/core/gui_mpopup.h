#ifndef GUI_MPOPUP_H
#define GUI_MPOPUP_H

//-------------------------------------------------------------------
#define MPOPUP_MASK             0x00FF
#define MPOPUP_CUT              0x0001
#define MPOPUP_COPY             0x0002
#define MPOPUP_PASTE            0x0004
#define MPOPUP_DELETE           0x0008
#define MPOPUP_SELINV           0x0010
#define MPOPUP_CANCEL           0x0100

//-------------------------------------------------------------------
extern void gui_mpopup_init(const unsigned int flags, void (*on_select)(unsigned int actn));
extern void gui_mpopup_kbd_process();
extern void gui_mpopup_draw();

extern void gui_browser_progress_show(const unsigned int perc);

//-------------------------------------------------------------------
#endif
