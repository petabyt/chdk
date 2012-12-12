#ifndef KBD_H
#define KBD_H

extern void kbd_set_block(int bEnableBlock);
extern void force_wait_for_key_release();

void enter_alt();
void exit_alt();

#endif
