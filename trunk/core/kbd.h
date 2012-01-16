#ifndef KBD_H
#define KBD_H

int keyid_by_name (const char *n);
int script_is_running();
void kbd_set_block(int bEnableBlock);
int handle_usb_remote() ;

extern long kbd_last_clicked;
extern int kbd_blocked;

#endif
