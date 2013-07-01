#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

// Forward declarations
extern volatile int jogdial_stopped;
void JogDial_task_my(void);

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_RotaryEncoder();
extern void task_MovieRecord();
extern void task_ExpDrv();

/*----------------------------------------------------------------------
    spytask
-----------------------------------------------------------------------*/
void spytask(long ua, long ub, long uc, long ud, long ue, long uf)
{
    core_spytask();
}

/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask()
{
    _CreateTask("SpyTask", 0x19, 0x2000, spytask, 0);
}

///*----------------------------------------------------------------------
// Pointer to stack location where jogdial task records previous and current
// jogdial positions
short *jog_position;

///*----------------------------------------------------------------------
/* ERR99: PATCH the TASK CREATE functions in RAM to install our hooks.
   To catch all TaskCreate calls (needed to install our own task functions),
   it is necessary to patch two different TaskCreate functions in RAM. 
 */

void __attribute__((naked,noinline)) HookIntoTaskCreateFunction()
{
    asm volatile (
        "STMFD   SP!, {R0-R2,LR}\n"         // Save all register which are used below
        
        /* Install CreateTask patch */
        "LDR     R0, =patch_CreateTask\n"   // Patch data
        "LDM     R0, {R1,R2}\n"             // Get two patch instructions
        "LDR     R0, =hook_CreateTask\n"    // Address to patch
        "STM     R0, {R1,R2}\n"             // Store patch instructions

        /* Install CreateTask2 patch */
        "LDR     R0, =patch_CreateTask2\n"  // Patch data
        "LDM     R0, {R1,R2}\n"             // Get two patch instructions
        "LDR     R0, =hook_CreateTask2\n"   // Address to patch
        "STM     R0, {R1,R2}\n"             // Store patch instructions

        "LDMFD   SP!, {R0-R2,PC}\n"         // Restore all used registers

        // Our hook code payload for CreateTask
"patch_CreateTask:\n"
        "LDR     PC, [PC,#-0x4]\n"          // Do jump to absolute address CreateTask_my
        ".long   CreateTask_my\n"

        // Our hook code payload for CreateTask2
"patch_CreateTask2:\n"
        "LDR     PC, [PC,#-0x4]\n"          // Do jump to absolute address CreateTask2_my
        ".long   CreateTask2_my\n"
    );
}

/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/
