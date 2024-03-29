#ifndef _ACTION_STACK_H
#define _ACTION_STACK_H

#define ACTION_STACK_SIZE 24
#define MAX_ACTION_STACKS 5

enum STANDARD_ACTIONS
{
    AS_NOOP = 1024,
    AS_SHOOT,
    AS_SLEEP,
    AS_PRESS,
    AS_RELEASE,
    AS_WAIT_SAVE,
    AS_WAIT_FLASH,
    AS_WAIT_CLICK,
    AS_WAIT_SHOOTING_IN_PROGRESS,
    AS_SCRIPT_RUN,
    AS_MOTION_DETECTOR,
    AS_SCRIPT_READ_USB_MSG, // params: timeout
    AS_SCRIPT_WRITE_USB_MSG, // params: timeout, msg
    AS_FILE_BROWSER,
    AS_TEXTBOX,
};

typedef int (*action_process)(long p);

long action_stack_create(action_process proc_func, long p);
void action_push(long p);
void action_push_delay(long msec);
void action_push_press(long key);
void action_push_release(long key);
void action_push_click(long key);
void action_wait_for_click(int timeout);
void action_pop();
int action_process_delay(int p);
void action_clear_delay(void);
long action_get_prev(int p);
int action_stack_standard(long p);
void action_stack_process_all();
int action_stack_is_finished(long comp_id);

#endif // _ACTION_STACK_H

