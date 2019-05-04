#ifndef CLOCK_H
#define CLOCK_H

// CHDK interface to firmware timer / clock functions

// Note: used in modules and platform independent code. 
// Do not add platform dependent stuff in here (#ifdef/#endif compile options or camera dependent values)

extern long get_tick_count();

extern int SetHPTimerAfterNow(int delay, int(*good_cb)(int, int), int(*bad_cb)(int, int), int param);
extern int CancelHPTimer(int handle);


#endif
