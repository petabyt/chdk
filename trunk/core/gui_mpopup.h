#ifndef GUI_MPOPUP_H
#define GUI_MPOPUP_H

//-------------------------------------------------------------------
#define MPOPUP_MASK             0x7FFF
#define MPOPUP_CANCEL           0x8000

struct mpopup_item {
        unsigned int            flag;
        int                     text;
};

//-------------------------------------------------------------------
extern void gui_mpopup_init(struct mpopup_item* popup_actions, const unsigned int flags, void (*on_select)(unsigned int actn), int mode);

//-------------------------------------------------------------------
#endif
