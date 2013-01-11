#ifndef CLOCK_H
#define CLOCK_H

// CHDK interface to firmware timer / clock functions

// Note: used in modules and platform independent code. 
// Do not add platform dependent stuff in here (#ifdef/#endif compile options or camera dependent values)

extern long get_tick_count();

extern int shooting_get_day_seconds();
extern int shooting_get_tick_count();

#endif
