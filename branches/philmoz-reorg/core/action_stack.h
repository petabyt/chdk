#ifndef _ACTION_STACK_H
#define _ACTION_STACK_H

// CHDK Script action handler

// Note: used in modules and platform independent code. 
// Do not add platform dependent stuff in here (#ifdef/#endif compile options or camera dependent values)

// Return values from 'script_run'
#define SCRIPT_RUN_ENDED        0
#define SCRIPT_RUN_RUNNING      1
#define SCRIPT_RUN_ERROR        -1

typedef void (*action_func)(void);

void action_stack_AS_SHOOT(void);

long action_stack_create(action_func proc_func);

long action_top(int n);
long action_pop();
void action_push(long p);
void action_push_delay(long msec);
void action_push_press(long key);
void action_push_release(long key);
void action_push_click(long key);
long action_pop_func();
void action_push_func(action_func f);

void action_wait_for_click(int timeout);
int action_process_delay(long delay);
void action_clear_delay(void);

void action_stack_process_all();
int  action_stack_is_finished(long comp_id);
void action_stack_kill(long comp_id);

#endif // _ACTION_STACK_H

