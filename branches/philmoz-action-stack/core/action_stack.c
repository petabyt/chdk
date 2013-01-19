#include "camera_info.h"
#include "stdlib.h"
#include "modes.h"
#include "clock.h"
#include "shooting.h"
#include "console.h"
#include "conf.h"
#include "keyboard.h"
#include "histogram.h"
#include "action_stack.h"
#include "script_api.h"

//----------------------------------------------------------------------------------

#define AS_FUNC_ENTRY   0xa32f1c9e      // Magic number to flag a function ptr on the stack

//----------------------------------------------------------------------------------
// action stack memory structure

#define ACTION_STACK_SIZE 48
#define MAX_ACTION_STACKS 5

typedef struct _action_stack
{
    long                    stack[ACTION_STACK_SIZE];   // Actions and parameters
    int                     stack_ptr;                  // Current position in stack
    AS_ID                   comp_id;                    // Unique ID
    unsigned long           delay_target_ticks;         // Used for sleep function
    struct _action_stack*   next;                       // next action stack
} action_stack_t;

//----------------------------------------------------------------------------------
// Global variables for implementation

static action_stack_t* action_stacks = NULL;            // List of active stacks
static action_stack_t* active_stack = NULL;             // Currently executing stack
static action_stack_t* free_stacks = NULL;              // Free list (for reuse of memory)
static int num_stacks = 0;                              // Number of active stacks
static AS_ID task_comp_id = 1;                          // Next stack ID (0 = unused / finished stack)

//----------------------------------------------------------------------------------
// Stack management functions

// Returns true if the task denoted by comp_id has finished execution.
// comp_id is returned by action_stack_create().
int action_stack_is_finished(AS_ID comp_id)
{
    action_stack_t *p = action_stacks;
    while (p)
    {
        if (p->comp_id == comp_id)
            return 0;
        p = p->next;
    }

    return 1;
}

// Starts a new action stack with initial stack entry p.
// The action stack is alive as long as its stack has entries.
// The proc_func parameter is a pointer to the initial processing function
// for the stack
AS_ID action_stack_create(action_func proc_func)
{
    // Cap the maximum number of action_stacks
    if (num_stacks == MAX_ACTION_STACKS)
        return -1;

    // Initialize new action stack
    action_stack_t* stack = 0;
    if (free_stacks)
    {
        // Reuse previous memory block
        stack = free_stacks;
        free_stacks = free_stacks->next;
    }
    else
    {
        // Get a new block
        stack = (action_stack_t*)malloc(sizeof(action_stack_t));
    }
    memset(stack,0,sizeof(action_stack_t));

    // Insert at start of list - stacks execute in order of most recent creation
    stack->next = action_stacks;
    action_stacks = stack;

    // Initialize id & processing function
    stack->comp_id = task_comp_id;
    stack->stack[0] = (long)proc_func;
    stack->stack[1] = AS_FUNC_ENTRY;    // Can't use action_push_func as active_stack not set
    stack->stack_ptr = 1;

    ++num_stacks;

    // Increment task_comp_id
    // For this to clash with a running stack you would need to leave one running
    // while 4 billion more were created - highly unlikely.
    ++task_comp_id;
    // Reset just in case it wraps around to 'finished' value
    if (task_comp_id == 0) task_comp_id = 1;

    return stack->comp_id;
}

// Clean up and release an action stack
static void action_stack_finish(action_stack_t *p)
{
    // Check in case already finalised
    if (p->comp_id == 0) return;

    // Remove 'active_stack' from the list since it is done execuing
    if (p == action_stacks)
    {
        action_stacks = action_stacks->next;
    }
    else
    {
        action_stack_t* prev = action_stacks;
        while (prev && (prev->next != p))
        {
            prev = prev->next;
        }
        if (prev)
        {
            prev->next = prev->next->next;
        }
    }

    --num_stacks;

    // Mark as free in case this function gets called again
    p->comp_id = 0;
    p->stack_ptr = -1;

    // Instead of freeing memory, save it to the free list
    // Next time this block will be reused
    p->next = free_stacks;
    free_stacks = p;
}

// Find and terminate an action stack
// comp_id is returned by action_stack_create().
void action_stack_kill(AS_ID comp_id)
{
    action_stack_t *p = action_stacks;
    while (p)
    {
        if (p->comp_id == comp_id)
        {
            action_stack_finish(p);
            return;
        }
        p = p->next;
    }
}

//----------------------------------------------------------------------------------
// Add / remove a generic entry from the stack
// Note - these assume 'active_stack' is set correctly.

// Get top Nth entry off the stack (without removing it)
// Can only be called from an action stack
long action_top(int n)
{
    if (active_stack)
        return active_stack->stack[active_stack->stack_ptr-n];
    return 0;
}

// Pop top entry off the stack
// Can only be called from an action stack
long action_pop()
{
    if (active_stack)
        return active_stack->stack[active_stack->stack_ptr--];
    return 0;
}

// Pop top func entry off the stack
// Can only be called from an action stack
long action_pop_func()
{
    action_pop();
    return action_pop();
}

// Push a new entry onto the stack
// Can only be called from an action stack
void action_push(long p)
{
    if (active_stack)
        active_stack->stack[++active_stack->stack_ptr] = p;
}

// Push a function onto the stack
void action_push_func(action_func f)
{
    action_push((long)f);
    action_push(AS_FUNC_ENTRY);
}

//----------------------------------------------------------------------------------
// Custom functions to push specific actions onto the stack

// Process a sleep function from the stack
static void action_stack_AS_SLEEP()
{
    long delay = action_top(2);

    if (action_process_delay(delay))
    {
        action_clear_delay();
        action_pop_func();
        action_pop();
    }
}

// Push a sleep onto the stack
// Can only be called from an action stack
void action_push_delay(long msec)
{
    action_push(msec);
    action_push_func(action_stack_AS_SLEEP);
}

// Process a button press action from the stack
static void action_stack_AS_PRESS()
{
    extern int usb_sync_wait;

    action_pop_func();
    long skey = action_pop();   // Key parameter

    if ((skey == KEY_SHOOT_FULL) && conf.remote_enable && conf.synch_enable) usb_sync_wait = 1;

    kbd_key_press(skey);
}

// Push a button press action onto the stack
// Can only be called from an action stack
void action_push_press(long key)
{
    // WARNING stack program flow is reversed
    action_push_delay(camera_info.cam_key_press_delay);
    action_push(key);
    action_push_func(action_stack_AS_PRESS);
}

// Process a button release action from the stack
static void action_stack_AS_RELEASE()
{
    action_pop_func();
    long skey = action_pop();   // Key parameter
    kbd_key_release(skey);
}

// Push a button release action onto the stack
// Can only be called from an action stack
void action_push_release(long key)
{
    // WARNING stack program flow is reversed
    action_push_delay(camera_info.cam_key_release_delay);
    action_push(key);
    action_push_func(action_stack_AS_RELEASE);
}

// Push a button click action onto the stack (press, optional delay, release)
// Can only be called from an action stack
void action_push_click(long key)
{
    // WARNING stack program flow is reversed
    action_push_release(key);
    // camera need delay for click?
    if (camera_info.cam_key_click_delay > 0)
        action_push_delay(camera_info.cam_key_click_delay);
    action_push_press(key);
}

// Wait for a button to be pressed and released (or the timeout to expire)
static void action_stack_AS_WAIT_CLICK()
{
    long delay = action_top(2);

    if (action_process_delay(delay) || (camera_info.state.kbd_last_clicked = kbd_get_clicked_key()))
    {
        if (!camera_info.state.kbd_last_clicked)
            camera_info.state.kbd_last_clicked=0xFFFF;
        action_clear_delay();
        action_pop_func();
        action_pop();
    }
}

// Push a wait for button click action onto the stack
// Can only be called from an action stack
void action_wait_for_click(int timeout)
{
    // accept wait_click 0 for infinite, but use -1 internally to avoid confusion with generated waits
    action_push(timeout?timeout:-1);
    action_push_func(action_stack_AS_WAIT_CLICK);
}

//----------------------------------------------------------------------------------
// Delay processing

// handle initializing and checking a timeout value set by 'delay'
// returns zero if the timeout has not expired, 1 if it has
// does not pop the delay value off the stack or clear the delay value
int action_process_delay(long delay)
{
    unsigned t = get_tick_count();
    // FIXME take care if overflow occurs
    if (active_stack->delay_target_ticks == 0)
    {
        /* delay of -1 signals indefinite (actually 1 day) delay*/
        if(delay == -1)
            delay = 86400000;

        active_stack->delay_target_ticks = t+delay;
        return 0;
    }
    if (active_stack->delay_target_ticks <= t)
    {
        return 1;
    }
    return 0;
}

// Disable current delay
void action_clear_delay(void)
{
    active_stack->delay_target_ticks = 0;
}

//----------------------------------------------------------------------------------
// 'Shoot' actions

static void action_stack_AS_WAIT_SAVE()
{
    if (!shooting_in_progress())
    {
        action_pop_func();
        if (libscriptapi)
            libscriptapi->set_as_ret((camera_info.state.state_shooting_progress == SHOOTING_PROGRESS_NONE) ? 0 : 1);
    }
}

static void action_stack_AS_WAIT_FLASH()
{
    if (shooting_is_flash_ready())
        action_pop_func();
}

static void action_stack_AS_WAIT_SHOOTING_IN_PROGRESS()
{
    if (shooting_in_progress() || MODE_IS_VIDEO(mode_get()))
        action_pop_func();
}

void action_stack_AS_SHOOT()
{
    action_pop_func();

    camera_info.state.state_shooting_progress = SHOOTING_PROGRESS_NONE;

    // XXX FIXME find out how to wait to jpeg save finished
    action_push_delay(conf.script_shoot_delay*100);

    action_push_func(action_stack_AS_WAIT_SAVE);

    action_push_release(KEY_SHOOT_HALF);
    action_push_release(KEY_SHOOT_FULL);

    action_push_press(KEY_SHOOT_FULL);

    action_push_func(action_stack_AS_WAIT_FLASH);
    action_push_func(action_stack_AS_WAIT_SHOOTING_IN_PROGRESS);

    action_push_press(KEY_SHOOT_HALF);
}

//----------------------------------------------------------------------------------
// Stack execution

// Run the topmost function on the active stack.
static void action_stack_process()
{
    if (active_stack->stack_ptr >= 0)
    {
        // Get function address and id from stack
        long id = action_top(0);
        action_func f = (action_func)action_top(1);
        if (id == AS_FUNC_ENTRY)    // Safety check
        {
            f();
        }
        else
        {
            char buf[100];
            sprintf(buf,"AS Error - Not a Function. Aborting. %d %08x %08x.",active_stack->stack_ptr,id,f);
            script_console_add_line((long)buf);
            action_stack_finish(active_stack);
        }
    }
    else
    {
        action_stack_finish(active_stack);
    }
}

// Run the topmost function on each stack
void action_stack_process_all()
{
    active_stack = action_stacks;

    while (active_stack)
    {
        // Save the next stack in case the current one ends and 
        // releases it's stack during execution
        action_stack_t *next = active_stack->next;

        // Process stack functions
        action_stack_process();

        active_stack = next;
    }
}

//----------------------------------------------------------------------------------
