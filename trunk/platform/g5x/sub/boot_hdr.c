
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#include "camera_info.h"

const char * const new_sa = &_end;

// Forward declarations
extern void task_CaptSeq ();
extern void task_InitFileModules ();
//extern void task_MovieRecord();
extern void task_ExpDrv ();

/*----------------------------------------------------------------------
 CreateTask_spytask
 -----------------------------------------------------------------------*/
void
CreateTask_spytask ()
{
    _CreateTask ("SpyTask", 0x19, 0x2000, core_spytask, 0);
}

/*************************************************************/
/*
    Custom function called in mzrm_sendmsg via logging function pointer (normally disabled)
    Checks if called from function that is updating the Canon UI.
    Updates CHDK bitmap settings and sets flag to update CHDK UI.
*/
void __attribute__((naked,noinline))
debug_logging_my(char* fmt, ...)
{
    (void)fmt;  // unused parameter
    asm volatile (
            //LR = Return address
            "    ldr     r0, =mzrm_sendmsg_ret_adr\n"   // Is return address in mzrm_sendmsg function?
            "    cmp     r0, lr\n"
            "    beq     chk_msg_type\n"
            "exit_debug_logging_my:\n"
            "    bx      lr\n"

            "chk_msg_type:\n"
            // mzrm_sendmsg 'msg' value (2nd parameter, saved in r11)
            "    ldr     r1, [r11]\n"                   // message type
            "    cmp     r1, 0x25\n"                    // message type XimrExe
            "    beq     do_ui_update\n"
            "    cmp     r1, 0x26\n"                    // message type XimrExeGain
            "    bne     exit_debug_logging_my\n"
            "do_ui_update:\n"
            "    ldr     r0, [r11,0x0c]\n"              // address of Ximr context in 'msg'
            "    b       update_ui\n"
    );
}

/*
    Install and enable custom logging function for mzrm_sendmsg.
*/
void
patch_mzrm_sendmsg ()
{
    extern int debug_logging_flag;
    extern void (*debug_logging_ptr)(char* fmt, ...);

    // Each bit in debug_logging_flag enables logging in different areas of the firmware code - only set the bit required for mzrm logging.
    debug_logging_flag = 0x200;
    debug_logging_ptr = debug_logging_my;
}

/*************************************************************/
void __attribute__((naked,noinline))
CreateTask_my ()
{
    asm volatile (
            "    push   {r0}\n"
            //R3 = Pointer to task function to create

            "    ldr     r0, =task_CaptSeq\n" // DryOS original code function ptr.
            "    cmp     r0, r3\n" // is the given taskptr equal to our searched function?
            "    itt     eq\n" // EQ block
            "    ldreq   r3, =capt_seq_task\n" // if so replace with our task function base ptr.
            "    beq     exitHook\n" // below compares not necessary if this check has found something.

            "    ldr     r0, =task_ExpDrv\n"
            "    cmp     r0, R3\n"
            "    itt     eq\n"
            "    ldreq   r3, =exp_drv_task\n"
            "    beq     exitHook\n"

            //"    ldr     r0, =task_DvlpSeq\n"
            //"    cmp     r0, R3\n"
            //"    itt     eq\n"
            //"    LDREQ   r3, =developseq_task\n"
            //"    BEQ     exitHook\n"

            "    ldr     r0, =task_FileWrite\n"
            "    cmp     r0, R3\n"
            "    itt     eq\n"
            "    ldreq   r3, =filewritetask\n"
            "    beq     exitHook\n"

            //"    ldr     r0, =task_MovieRecord\n"
            //"    cmp     r0, R3\n"
            //"    itt     eq\n"
            //"    ldreq   r3, =movie_record_task\n"
            //"    beq     exitHook\n"

            "    ldr     r0, =task_TricInitTask\n"
            "    cmp     r0, r3\n"
            "    itt     eq\n"
            "    ldreq   r3, =task_TricInitTask_my\n"
            "    beq     exitHook\n"

            "    ldr     r0, =task_InitFileModules\n"
            "    cmp     r0, r3\n"
            "    it      eq\n"
            "    ldreq   r3, =init_file_modules_task\n"

            "exitHook:\n"
            // restore overwritten register(s)
            "    pop    {r0}\n"
            // Execute overwritten instructions from original code, then jump to firmware
            "    push.w  {r1, r2, r3, r4, r5, r6, r7, r8, sb, lr}\n"
            "    mov     r4, r0\n"
            "    ldr     r0, =0x00008164\n"
            "    ldr.w   pc, =(hook_CreateTask + 9) \n" // Continue in firmware, thumb bit set
            ".ltorg\n"
    );
}

/*************************************************************/

// *** TEMPORARY? workaround ***
// Init stuff to avoid asserts on cameras running DryOS r54+
// https://chdk.setepontos.com/index.php?topic=12516.0
// Execute this only once
void init_required_fw_features(void)
{
//    extern void _init_focus_eventflag();
//    _init_focus_eventflag();
//    extern void _init_nd_eventflag();
//    _init_nd_eventflag();
    extern int av_override_semaphore;
    extern int _CreateBinarySemaphoreStrictly(int x, int y);
    av_override_semaphore = _CreateBinarySemaphoreStrictly(0,0);
}

/*************************************************************/

extern int physw0_override;

/*----------------------------------------------------------------------
 boot()

 Main entry point for the CHDK code
 -----------------------------------------------------------------------*/
