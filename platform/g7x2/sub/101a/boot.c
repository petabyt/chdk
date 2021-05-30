
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#include "camera_info.h"

const char * const new_sa = &_end;

// Forward declarations
extern void task_CaptSeq();
extern void task_InitFileModules();
//extern void task_MovieRecord();
extern void task_ExpDrv();
extern void task_FsIoNotifyTask();

// void blinker()
// {
//     // green LED
//     volatile int* p = (int*)0xD20801E4;
// 
//     // blinker
//     int i;
//     while (1)
//     {
//         *p = 0x24D0002;
//         for(i=0;i<10000000;i++) {
//             asm volatile(
//             "nop\n"
//             );
//         }
//         *p = 0x24C0003;
//         for(i=0;i<10000000;i++) {
//             asm volatile(
//             "nop\n"
//             );
//         }
//     }
// }
// void blinkeraf()
// {
//     // green LED
//     volatile int* p = (int*)0xD20801E8;
// 
//     // blinker
//     int i;
//     while (1)
//     {
//         *p = 0x24D0002;
//         for(i=0;i<10000000;i++) {
//             asm volatile(
//             "nop\n"
//             );
//         }
//         *p = 0x24C0003;
//         for(i=0;i<10000000;i++) {
//             asm volatile(
//             "nop\n"
//             );
//         }
//     }
// }
// void blinktask(long ua, long ub, long uc, long ud, long ue, long uf)
// {
//     // green LED
//     volatile int* p = (int*)0xD20801E4;
// 
//     // blinker
//     while (1)
//     {
//         *p = 0x24D0002;
//         _SleepTask(1000);
//         *p = 0x24C0003;
//         _SleepTask(1000);
//     }
// }

/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask()
{
//    _CreateTask("BlinkTask", 0x19, 0x800, blinktask, 0);
    _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}

/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/

/*************************************************************/
void __attribute__((naked,noinline)) boot() {
    asm volatile (
            "    mrc     p15, #0, r0, c0, c0, #5\n"
            "    ands    r0, #0xf\n"
            "    beq     loc_boot\n" // let core0 boot
            "    adr     r0, loc_boot\n"
            "    orr     r0, #1\n"
            "    bl      sub_e0539e68\n" // park core1 then continue at r0
            "loc_boot:\n"

            //capdis -f=chdk -s=0xe0020011 -c=65 -stubs PRIMARY.BIN 0xe0000000
            "    ldr     r0, =0xe0020200\n"
            "    mcr     p15, #0, r0, c12, c0, #0\n"
            "    isb     sy\n"
            "    movw    r0, #0x2000\n"
            "    movt    r0, #0\n"
            "    mov     sp, r0\n"
            "    mrc     p15, #0, r5, c0, c0, #5\n"
            "    ands    r0, r5, #0xf\n"
            "    bne     loc_e0020032\n"
            "    b.w     loc_e002003c\n"
            "loc_e0020032:\n"
            "    b.w     sub_e00200f8_my\n"     // Patched
//            "    movs    r0, r0\n"            // Data
//            "    lsls    r0, r0, #8\n"        // Data
//            "    b       loc_e0020042\n"      // Data
            "loc_e002003c:\n"
            "    ldr     r0, =0xe0fd3770\n"
            "    ldr     r1, =0x00008000\n"
            "    ldr     r3, =0x0004c618\n"
            "loc_e0020042:\n"
            "    cmp     r1, r3\n"
            "    itt     lo\n"
            "    ldrlo   r2, [r0], #4\n"
            "    strlo   r2, [r1], #4\n"
            "    blo     loc_e0020042\n"
            "    ldr     r1, =0x002c460c\n"
            "    mov.w   r2, #0\n"
            "loc_e0020056:\n"
            "    cmp     r3, r1\n"
            "    it      lo\n"
            "    strlo   r2, [r3], #4\n"
            "    blo     loc_e0020056\n"
            "    ldr     r0, =0xe1017d88\n" //  **"zH"
            "    ldr     r1, =0x01900000\n" //  **"zH"
            "    ldr     r3, =0x0190139c\n"
            "loc_e0020066:\n"
            "    cmp     r1, r3\n"
            "    itt     lo\n"
            "    ldrlo   r2, [r0], #4\n"
            "    strlo   r2, [r1], #4\n"
            "    blo     loc_e0020066\n"
            "    ldr     r0, =0x01900000\n" //  **"zH"
            "    ldr     r1, =0x0000139c\n"
            "    bl      sub_e042eb74\n"
            "    ldr     r0, =0x01900000\n" //  **"zH"
            "    ldr     r1, =0x0000139c\n"
            "    bl      sub_e042ec4c\n"
            "    ldr     r0, =0xe1019124\n"
            "    ldr     r1, =0xdffc4900\n"
            "    ldr     r3, =0xdffd0908\n"
            "loc_e002008a:\n"
            "    cmp     r1, r3\n"
            "    itt     lo\n"
            "    ldrlo   r2, [r0], #4\n"
            "    strlo   r2, [r1], #4\n"
            "    blo     loc_e002008a\n"
            "    ldr     r1, =0xdffd0908\n"
            "    mov.w   r2, #0\n"
            "loc_e002009e:\n"
            "    cmp     r3, r1\n"
            "    it      lo\n"
            "    strlo   r2, [r3], #4\n"
            "    blo     loc_e002009e\n"

            "    blx     patch_mzrm_sendmsg\n"

            // Install CreateTask patch
            // use half words in case source or destination not word aligned
            "    adr     r0, patch_CreateTask\n"    // src: Patch data
            "    ldr     r1, =hook_CreateTask\n"    // dest: Address to patch
            "    add     r2, r0, #8\n"              // two words
            "patch_hook_loop:\n"
            "    ldrh    r3, [r0],#2\n"
            "    strh    r3, [r1],#2\n"
            "    cmp     r0,r2\n"
            "    blo     patch_hook_loop\n"

            "    ldr     r0, =0xdffc4900\n"
            "    ldr     r1, =0x0000c008\n"
            "    bl      sub_e042eb74\n"
            "    ldr     r0, =0xdffc4900\n"
            "    ldr     r1, =0x0000c008\n"
            "    bl      sub_e042ec4c\n"
//            "    ldr     r0, =loc_e0020032\n"     // -
//            "    orr     r0, r0, #1\n"            // -
//            "    bx      r0\n"                    // -
            "    b       loc_e0020032\n" // +

            // CreateTask patch, must be aligned as the original
            "    .align  2\n"
            "    .short  0\n" // added for alignment
            "patch_CreateTask:\n"
            "    ldr.w   pc, _createtask_my\n"      // Do jump to absolute address CreateTask_my
            "_createtask_my:\n"
            "    .long   CreateTask_my + 1\n"       // has to be a thumb address
            "    .align  1\n"
    );
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
            "    beq     do_ui_update\n"
            "exit_debug_logging_my:\n"
            "    bx      lr\n"

            "do_ui_update:\n"
            "    ldr     r0, [sp,#0x18]\n"              // mzrm_sendmsg 'msg' value (2nd parameter, saved on stack)
            "    ldr     r1, [r0]\n"                    // message type
            "    mov     r2, #0x25\n"                   // Ximr update? (3rd parameter to mzrm_createmsg)
            "    cmp     r1, r2\n"
            "    bne     exit_debug_logging_my\n"
            "    add     r0, r0, #16\n"                 // Offset to Ximr context in 'msg'
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
void __attribute__((naked,noinline)) CreateTask_my() {
    asm volatile (
            "    push   {r0}\n"
            //R3 = Pointer to task function to create

            "    ldr     r0, =task_CaptSeq\n"       // DryOS original code function ptr.
            "    cmp     r0, r3\n"                  // is the given taskptr equal to our searched function?
            "    itt     eq\n"                      // EQ block
            "    ldreq   r3, =capt_seq_task\n"      // if so replace with our task function base ptr.
            "    beq     exitHook\n"                // below compares not necessary if this check has found something.

            "    ldr     r0, =task_ExpDrv\n"
            "    cmp     r0, R3\n"
            "    itt     eq\n"
            "    ldreq   r3, =exp_drv_task\n"
            "    beq     exitHook\n"

            //"    ldr     r0, =task_DvlpSeq\n"
            //"    cmp     r0, R3\n"
            //"    itt     eq\n"
            //"    ldreq   r3, =developseq_task\n"
            //"    beq     exitHook\n"

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

            "    ldr     r0, =task_FsIoNotifyTask\n"
            "    cmp     r0, r3\n"
            "    itt     eq\n"
            "    ldreq   r3, =task_FsIoNotifyTask_my\n"
            "    beq     exitHook\n"

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
            "    push    {r1, r2, r3, r4, r5, r6, r7, lr}\n"
            "    mov     r4, r3\n"
            "    mov.w   r3, #0x1000\n"
            "    ldr.w   pc, =0xDFFC93C3\n" // Continue in firmware
    );
}

//e00200f8
void __attribute__((naked,noinline)) sub_e00200f8_my() {

    if (*(int*)(0xd2082000 + 0x168) & 0x10000) {
        // see FUN_e004e4d6, FUN_e004e4d6
        // GPIO 0x10 (aka ON/OFF button) is not pressed -> play
        *(int*)(0x9914+0x8) = 0x100000;
    }
    else {
        // GPIO 0x10 is pressed -> rec
        *(int*)(0x9914+0x8) = 0x80000;
    }

    asm volatile (
            //capdis -f=chdk -s=0xe00200f9 -c=81 -stubs PRIMARY.BIN 0xe0000000
            "    push    {r4, r5, r6, lr}\n"
#if defined(CHDK_NOT_IN_CANON_HEAP)
            "    ldr     r0, =0x002c4613\n"         // heap start, modify here
#else
            "    ldr     r0, =new_sa\n"             // +
            "    ldr     r0, [r0]\n"                // +
            "    add     r0, #7\n"                  // +
#endif
            "    sub     sp, #0x80\n"
            "    ldr     r1, =0x000f264c\n"
            "    bic     r5, r0, #7\n"
            "    ldr     r0, =0x006cd400\n"
            "    subs    r0, r0, r5\n"
            "    cmp     r0, r1\n"
            "    bhs     loc_e002010e\n"
            "loc_e002010c:\n"
            "    b       loc_e002010c\n"
            "loc_e002010e:\n"
            "    mrc     p15, #0, r0, c0, c0, #5\n"
            "    and     r6, r0, #0xf\n"
            "    mov.w   r0, #0x400\n"
            "    add.w   r1, r5, #0x400\n"
            "    str     r0, [sp]\n"
            "    lsls    r2, r0, #1\n"
            "    mov     r3, r5\n"
            "    mov     r4, r1\n"
            "    mov     r0, r6\n"
            "    bl      sub_e002052c\n"
            "    cbz     r6, loc_e0020136\n"
            "    bl      sub_dffc570c\n"
            "loc_e0020132:\n"
            "    add     sp, #0x80\n"
            "    pop     {r4, r5, r6, pc}\n"
            "loc_e0020136:\n"
            "    ldr     r0, =0x00008088\n"
            "    mov.w   r1, #0x80000\n"
            "    str     r1, [r0]\n"
            "    ldr     r1, =0x0000808c\n"
            "    ldr     r0, =0x42aaa000\n"
            "    str     r0, [r1]\n"
            "    ldr     r1, =0x00008090\n"
            "    ldr     r0, =0x42aac000\n"
            "    str     r0, [r1]\n"
            "    movs    r1, #0x78\n"
            "    add     r0, sp, #4\n"
            "    bl      sub_dffcc544\n"
            "    ldr     r1, =0x005ce000\n"
            "    mov.w   r0, #0x100000\n"
            "    ldr     r2, =0x005bedb4\n"
            "    strd    r1, r0, [sp, #4]\n"
            "    subs    r2, r2, r5\n"
            "    add.w   r0, r5, #0xc00\n"
            "    strd    r0, r2, [sp, #0xc]\n"
            "    ldr     r2, =0x005bf9b4\n"
            "    strd    r2, r1, [sp, #0x14]\n"
            "    movs    r1, #0x22\n"
            "    str     r1, [sp, #0x1c]\n"
            "    movs    r1, #0xca\n"
            "    str     r1, [sp, #0x20]\n"
            "    mov.w   r1, #0x2b0\n"
            "    str     r1, [sp, #0x24]\n"
            "    movs    r1, #0xfa\n"
            "    str     r1, [sp, #0x28]\n"
            "    mov.w   r1, #0x11a\n"
            "    str     r1, [sp, #0x2c]\n"
            "    movs    r1, #0x85\n"
            "    str     r1, [sp, #0x30]\n"
            "    movs    r1, #0x40\n"
            "    str     r1, [sp, #0x34]\n"
            "    movs    r1, #4\n"
            "    str     r1, [sp, #0x38]\n"
            "    movs    r1, #0\n"
            "    str     r1, [sp, #0x3c]\n"
            "    movs    r1, #0x10\n"
            "    str     r1, [sp, #0x60]\n"
            "    lsls    r1, r1, #8\n"
            "    str     r1, [sp, #0x64]\n"
            "    asrs    r1, r1, #4\n"
            "    str     r1, [sp, #0x68]\n"
            "    lsls    r1, r1, #5\n"
            "    str     r1, [sp, #0x6c]\n"
            "    mov.w   r1, #-0x11111112\n"
            "    b       loc_e00201ae\n"
            "loc_e00201ac:\n"
            "    stm     r4!, {r1}\n"
            "loc_e00201ae:\n"
            "    cmp     r0, r4\n"
            "    bhi     loc_e00201ac\n"
            "    movs    r2, #0\n"
            "    ldr     r1, =sub_e0020398_my\n" // ->
            "    add     r0, sp, #4\n"
            "    bl      sub_dffc49e0\n"
            "    b       loc_e0020132\n"
    );
}

//e0020398
void __attribute__((naked,noinline)) sub_e0020398_my() {
    asm volatile (
            //capdis -f=chdk -s=0xe0020399 -c=47 -stubs PRIMARY.BIN 0xe0000000
            "    push    {r4, lr}\n"
            "    ldr     r4, =0xe0020474\n" //  *"/_term"
            "    bl      sub_e00213fa\n"
            "    ldr     r0, =0x00008154\n"
            "    ldr     r1, [r0]\n"
            "    ldr     r0, =0x00008088\n"
            "    ldr     r0, [r0]\n"
            "    adds    r0, #0x10\n"
            "    cmp     r1, r0\n"
            "    bhs     loc_e00203b4\n"
            "    ldr     r0, =0xe0020484\n" //  *"USER_MEM size checking"
            "    bl      sub_e0020418\n"
            "loc_e00203b4:\n"
            "    bl      sub_e0450d70\n"
            "    cmp     r0, #0\n"
            "    bge     loc_e00203c2\n"
            "    ldr     r0, =0xe002049c\n" //  *"dmSetup"
            "    bl      sub_e0020418\n"
            "loc_e00203c2:\n"
            "    bl      sub_e002210c\n"
            "    cmp     r0, #0\n"
            "    bge     loc_e00203d0\n"
            "    ldr     r0, =0xe00204a4\n" //  *"termDriverInit"
            "    bl      sub_e0020418\n"
            "loc_e00203d0:\n"
            "    mov     r0, r4\n"
            "    bl      sub_e00221b0\n"
            "    cmp     r0, #0\n"
            "    bge     loc_e00203e0\n"
            "    ldr     r0, =0xe00204b4\n" //  *"termDeviceCreate"
            "    bl      sub_e0020418\n"
            "loc_e00203e0:\n"
            "    mov     r0, r4\n"
            "    bl      sub_e002056c\n"
            "    cmp     r0, #0\n"
            "    bge     loc_e00203f0\n"
            "    ldr     r0, =0xe00204c8\n" //  *"stdioSetup"
            "    bl      sub_e0020418\n"
            "loc_e00203f0:\n"
            "    bl      sub_e00206b0\n"
            "    cmp     r0, #0\n"
            "    bge     loc_e00203fe\n"
            "    ldr     r0, =0xe00204d4\n" //  *"stdlibSetup"
            "    bl      sub_e0020418\n"
            "loc_e00203fe:\n"
            "    bl      sub_e0029ae4\n"
            "    cmp     r0, #0\n"
            "    bge     loc_e002040c\n"
            "    ldr     r0, =0xe00204e0\n" //  *"extlib_setup"
            "    bl      sub_e0020418\n"
            "loc_e002040c:\n"
            "    bl      sub_e002042e\n"
            "    pop.w   {r4, lr}\n"
            "    b.w     sub_e0020750_my\n" // -> continue (taskcreate_startup)
    );
}

//e0020750
void __attribute__((naked,noinline)) sub_e0020750_my() {
    asm volatile (
            //capdis -f=chdk -s=0xe0020751 -c=23 -stubs PRIMARY.BIN 0xe0000000
            "    push    {r3, lr}\n"
            "    bl      sub_e002088c\n"
            "    bl      sub_e0020848\n"

            "    mrc     p15, #0, r0, c0, c0, #5\n" // +
            "    ands    r0, r0, #0xf\n"            // +
            "    bne     skip\n"                    // + to be on the safe side, skip this with core1
            "    movs    r0, #1\n"                  // +
            "    bl      sub_e051e07c\n"            // unblock core1 (needs to be done twice)

            "    movs    r0, #1\n"
            "    bl      sub_e051e07c\n"            // unblock core1
            "skip:\n"                               // +

            "    bl      sub_e003e3bc\n"        // IsNormalCameraMode_FW
            "    bl      sub_e005b418_my\n"     // -> power-on mode handling & startupchecks here
            "    cbz     r0, loc_e002078a\n"
            "    bl      sub_dffc9094\n"
            "    ldr     r1, =0x006ce000\n"
            "    movs    r0, #0\n"
            "    bl      sub_e037e5d0\n"
            "    ldr     r3, =task_Startup_my\n"    // ->
            "    movs    r0, #0\n"
            "    mov     r2, r0\n"
            "    str     r0, [sp]\n"
            "    movs    r1, #0x19\n"
            "    ldr     r0, =0xe00207a8\n" //  *"Startup"
            "    bl      sub_dffc93ba\n"
            "    movs    r0, #0\n"
            "    pop     {r3, pc}\n"
            "loc_e002078a:\n"
            "    bl      sub_e002087c\n"
            "loc_e002078e:\n"
            "    b       loc_e002078e\n"
    );
}

//e005b418
void __attribute__((naked,noinline)) sub_e005b418_my() {
    asm volatile (
            //capdis -f=chdk -s=0xe005b419 -c=44 -stubs PRIMARY.BIN 0xe0000000
            "    push.w  {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}\n"
            "    movs    r5, #0\n"
            "    mov     sl, r0\n"
            "    mov     r4, r5\n"
            "    bl      sub_e004e4d2\n"
            "    mov.w   r0, #0x168\n"
            "    bl      sub_e004ed2a\n"
            "    movs    r6, #1\n"
            "    bic.w   r7, r6, r0\n"
            "    mov.w   r0, #0x150\n"
            "    bl      sub_e004ed2a\n"
            "    bic.w   r8, r6, r0\n"
            "    movs    r0, #0\n"
            "    bl      sub_e004e4ce\n"
            "    cbz     r0, loc_e005b454\n"
            "    mov.w   r0, #0x16c\n"
            "    bl      sub_e004ed2a\n"
            "    bic.w   r5, r6, r0\n"
            "loc_e005b454:\n"
            "    movs    r0, #0x38\n"
            "    bl      sub_e004ed2a\n"
            "    mov     sb, r6\n"
            "    bics    r6, r0\n"
            "    movs    r0, #1\n"
            "    bl      sub_e004e4ce\n"
            "    cbz     r0, loc_e005b472\n"
            "    mov.w   r0, #0x194\n"
            "    bl      sub_e004ed2a\n"
            "    bic.w   r4, sb, r0\n"
            "loc_e005b472:\n"
            "    cmp.w   sl, #0\n"
            "    beq     loc_e005b486\n"
            "    orr.w   r0, r7, r8\n"
            "    orr.w   r1, r5, r6\n"
            "    orrs    r0, r1\n"
            "    orrs    r0, r4\n"
//            "    beq     loc_e005b49a\n"
            "loc_e005b486:\n"
            "    mov     r3, r6\n"
            "    mov     r2, r5\n"
            "    mov     r1, r8\n"
            "    mov     r0, r7\n"
            "    str     r4, [sp]\n"
//            "    bl      sub_e004e4d6\n"
//            "    bl      sub_e004e4d4\n"
            "    movs    r0, #1\n"
            "loc_e005b49a:\n"
            "    pop.w   {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}\n"
    );
}

// *** TEMPORARY? workaround ***
// Init stuff to avoid asserts on cameras running DryOS r54+
// https://chdk.setepontos.com/index.php?topic=12516.0
// Execute this only once
void init_required_fw_features(void)
{
    extern void _init_focus_eventflag();
    _init_focus_eventflag();
    extern void _init_nd_eventflag();
    _init_nd_eventflag();
    extern int av_override_semaphore;
    extern int _CreateBinarySemaphoreStrictly(int x, int y);
    av_override_semaphore = _CreateBinarySemaphoreStrictly(0,0);
}

// task_Startup e00206d4
void __attribute__((naked,noinline)) task_Startup_my() {
    asm volatile (
            //capdis -f=chdk -s=0xe00206d5 -c=34 -stubs PRIMARY.BIN 0xe0000000
            "    push    {r4, lr}\n"
            "    bl      sub_e013a49a\n"
            "    ldr     r0, =0x4194a000\n"
            "    mov.w   r1, #0x20000\n"
            "    bl      sub_e03ea27c\n"
            "    cbz     r0, loc_e00206f0\n"
            "    movs    r2, #0x7d\n"
            "    movs    r0, #0\n"
            "    ldr     r1, =0xe0020794\n" //  *"Startup.c"
            "    bl      sub_dffc96f4\n"
            "loc_e00206f0:\n"
            "    bl      sub_e0020860\n"
            "    bl      sub_e046e380\n"
            "    bl      sub_e052fdac\n"
            // added for SD card UHS detection https://chdk.setepontos.com/index.php?topic=13089.msg132583#msg132583
            "    bl      sub_e04d998a\n" // ref in sub_e04d9c14 before "SDPower.c" string
//            "    bl      sub_e046e3dc\n"    // - diskboot
            "    bl      sub_e005a122\n"
            "    bl      sub_e0425880\n"
            "    bl      sub_e0020924\n"
            "    bl      sub_e00208be\n"
            "    bl      sub_e052fde2\n"
            "    bl      sub_e0056650\n"
            "    bl      sub_e0425886\n"
            "    bl      sub_e005b33e_my\n"     // -> taskcreate_physw
            "    BL      CreateTask_spytask\n"  // +
            "    bl      init_required_fw_features\n"   // +
            "    bl      sub_e0297df6\n"
            "    bl      sub_e042589c\n"
            "    bl      sub_e052fd44\n"
            "    bl      sub_e04914a0\n"
            "    bl      sub_e005b870\n"
            "    bl      sub_e005a0d2\n"
            "    bl      sub_e049145c\n"
            "    bl      sub_e0020928\n"
            "    bl      sub_e037bccc\n"
            "    bl      sub_e049142e\n"
            "    pop.w   {r4, lr}\n"
            "    b.w     sub_e013a496\n"    // + jump to FW
    );
}

//taskcreate_physw e005b33e
void __attribute__((naked,noinline)) sub_e005b33e_my() {
    asm volatile (
            //capdis -f=chdk -s=0xe005b33f -c=18 -stubs PRIMARY.BIN 0xe0000000
            "    push    {r2, r3, r4, lr}\n"
            "    bl      sub_e005744c\n"
            "    bl      sub_e003e33c\n"
            "    cbnz    r0, loc_e005b34e\n"
            "    bl      sub_e00573f0\n"
            "loc_e005b34e:\n"
            "    ldr     r4, =0x00008370\n"
            "    ldr     r0, [r4, #4]\n"
            "    cmp     r0, #0\n"
            "    bne     loc_e005b36a\n"
            "    movs    r1, #1\n"
//            "    ldr     r3, =0xe005b319\n" // -
//            "    lsls    r2, r1, #0xb\n"  // -
            "    ldr     r3, =mykbd_task\n" // + task_PhySw replacement
            "    mov     r2, #0x2000\n"     // +
            "    strd    r0, r1, [sp]\n"
            "    movs    r1, #0x17\n"
            "    ldr     r0, =0xe005b6a4\n" //  *"PhySw"
            "    bl      sub_dffc95d8\n"
            "    str     r0, [r4, #4]\n"
            "loc_e005b36a:\n"
            "    pop     {r2, r3, r4, pc}\n"
    );
}

//e04200b0
void __attribute__((naked,noinline)) init_file_modules_task() {
    asm volatile (
            //capdis -f=chdk -s=0xe04200b1 -c=18 -stubs PRIMARY.BIN 0xe0000000
            "    push    {r4, r5, r6, lr}\n"
            "    movs    r0, #6\n"
            "    bl      sub_e037b34c\n"
            "    bl      sub_e049681c\n"
            "    movs    r4, r0\n"
            "    movw    r5, #0x5006\n"
            "    beq     loc_e04200cc\n"
            "    movs    r1, #0\n"
            "    mov     r0, r5\n"
            "    bl      _PostLogicalEventToUI\n"
            "loc_e04200cc:\n"
            "    bl      sub_e0496844\n"
            "    BL      core_spytask_can_start\n" // + CHDK: Set "it's-safe-to-start" flag for spytask
            "    cmp     r4, #0\n"
            "    bne     loc_e04200e0\n"
            "    mov     r0, r5\n"
            "    pop.w   {r4, r5, r6, lr}\n"
            "    movs    r1, #1\n"
            "    b.w     _PostLogicalEventToUI\n"
            "loc_e04200e0:\n"
            "    pop     {r4, r5, r6, pc}\n"
".ltorg\n"
    );
}

//e005b078
void __attribute__((naked,noinline)) kbd_p2_f_my() {
    asm volatile(
            //capdis -f=chdk -s=0xe005b079 -c=77 -stubs PRIMARY.BIN 0xe0000000
            "    push.w  {r4, r5, r6, r7, r8, lr}\n"
            "    ldr     r6, =0x0004e46c\n"
            "    sub     sp, #0x18\n"
            "    mov     r7, sp\n"
            "    subs    r6, #0xc\n"
            "    b       loc_e005b0ba\n"
            "loc_e005b086:\n"
            "    ldrb.w  r0, [sp, #0x10]\n"
            "    mov     r3, sp\n"
            "    ldr     r1, =0x0004e46c\n"
            "    add     r2, sp, #0xc\n"
            "    subs    r1, #0x18\n"
            "    bl      sub_e004eb64\n"
            "    cbnz    r0, loc_e005b0a0\n"
            "    ldr     r1, [sp, #0xc]\n"
            "    movs    r0, #0\n"
            "    bl      sub_e005afe6\n"
            "loc_e005b0a0:\n"
            "    movs    r0, #2\n"
            "loc_e005b0a2:\n"
            "    ldr.w   r1, [r7, r0, lsl #2]\n"
            "    cbz     r1, loc_e005b0b2\n"
            "    ldr.w   r2, [r6, r0, lsl #2]\n"
            "    bics    r2, r1\n"
            "    str.w   r2, [r6, r0, lsl #2]\n"
            "loc_e005b0b2:\n"
            "    subs    r0, r0, #1\n"
            "    sxtb    r0, r0\n"
            "    cmp     r0, #0\n"
            "    bge     loc_e005b0a2\n"
            "loc_e005b0ba:\n"
            "    add     r1, sp, #0x10\n"
            "    ldr     r0, =0x0004e46c\n"
            "    subs    r0, #0xc\n"
            "    bl      sub_e004e820\n"
            "    cmp     r0, #0\n"
            "    bne     loc_e005b086\n"
            "    movs    r4, #0\n"
            "    ldr.w   r8, =0x0004e46c\n"
            "loc_e005b0ce:\n"
            "    movs    r5, #0\n"
            "    ldr.w   r0, [r6, r4, lsl #2]\n"
            "    ldr.w   r1, [r8, r4, lsl #2]\n"
            "    ands    r0, r1\n"
            "    str.w   r0, [r6, r4, lsl #2]\n"
            "    b       loc_e005b126\n"
            "loc_e005b0e0:\n"
            "    lsrs    r0, r5\n"
            "    lsls    r0, r0, #0x1f\n"
            "    beq     loc_e005b11e\n"
            "    add.w   r0, r5, r4, lsl #5\n"
            "    ldr     r1, =0x0004e46c\n"
            "    mov     r3, sp\n"
            "    uxtb    r0, r0\n"
            "    subs    r1, #0x18\n"
            "    add     r2, sp, #0xc\n"
            "    bl      sub_e004eb64\n"
            "    cbnz    r0, loc_e005b102\n"
            "    ldr     r1, [sp, #0xc]\n"
            "    movs    r0, #1\n"
            "    bl      sub_e005afe6\n"
            "loc_e005b102:\n"
            "    mov     r0, r4\n"
            "    b       loc_e005b11a\n"
            "loc_e005b106:\n"
            "    ldr.w   r1, [r7, r0, lsl #2]\n"
            "    cbz     r1, loc_e005b116\n"
            "    ldr.w   r2, [r6, r0, lsl #2]\n"
            "    bics    r2, r1\n"
            "    str.w   r2, [r6, r0, lsl #2]\n"
            "loc_e005b116:\n"
            "    adds    r0, r0, #1\n"
            "    sxtb    r0, r0\n"
            "loc_e005b11a:\n"
            "    cmp     r0, #3\n"
            "    blt     loc_e005b106\n"
            "loc_e005b11e:\n"
            "    adds    r5, r5, #1\n"
            "    ldr.w   r0, [r6, r4, lsl #2]\n"
            "    uxtb    r5, r5\n"
            "loc_e005b126:\n"
            "    cmp     r0, #0\n"
            "    bne     loc_e005b0e0\n"
            "    adds    r4, r4, #1\n"
            "    sxtb    r4, r4\n"
            "    cmp     r4, #3\n"
            "    blt     loc_e005b0ce\n"
            "    bl      sub_e004e5ee_my\n" // Patched
            "    add     sp, #0x18\n"
            "    pop.w   {r4, r5, r6, r7, r8, pc}\n"
    );
}

//e004e5ee
void __attribute__((naked,noinline)) sub_e004e5ee_my() {
    asm volatile(
            //capdis -f=chdk -s=0xe004e5ef -c=13 -stubs PRIMARY.BIN 0xe0000000
            "    push    {r4, lr}\n"
            "    ldr     r4, =0x00009914\n"
            "    ldr     r0, [r4, #0xc]\n"
            "    bl      sub_e0052e76\n"
            "    ldr     r0, [r4, #0x18]\n"
            "    bl      sub_e0052f00\n"
            "    bl      sub_e0402302\n"
            "    ldr     r0, [r4, #0x14]\n"
            "    bl      sub_e0052da8\n"
            "    ldr     r0, [r4, #0x10]\n"
            "    bl      sub_e0052da8\n"

            "    bl      handle_jogdial\n" // +
            "    cmp     r0, #0\n" // +
            "    beq     no_scroll\n" // +

            "    pop.w   {r4, lr}\n"
            "    b.w     sub_e0517004\n"    // + jump to FW

            "no_scroll:\n" // +
            "    pop     {r4, pc}\n" // +
    );
}

//e005b632
void __attribute__((naked,noinline)) kbd_p1_f_cont_my ()
{
    asm volatile(
            //capdis -f=chdk -s=0xe005b633 -c=18 -jfw -stubs PRIMARY.BIN 0xe0000000
            "    ldr     r6, =0x0004e448\n"
            "    movs    r1, #2\n"
            "    mov     r5, sp\n"
            "    add.w   r3, r6, #0x24\n"
            "loc_e005b63c:\n"
            "    add.w   r0, r3, r1, lsl #2\n"
            "    ldr.w   r2, [r6, r1, lsl #2]\n"
            "    ldr     r7, [r0, #0xc]\n"
            "    ldr     r0, [r0, #0x18]\n"
            "    ands    r2, r7\n"
            "    eors    r2, r0\n"
            "    str.w   r2, [r5, r1, lsl #2]\n"
            "    subs    r1, r1, #1\n"
            "    bpl     loc_e005b63c\n"
            "    mov     r0, r5\n"
            "    ldr     r2, =0x0004e448\n"
            "    adds    r2, #0x18\n"
            "    sub.w   r1, r2, #0xc\n"
            "    bl      sub_e005b13c_my\n" // -> some physical status is re-read here (not into physw_status)
            "    ldr     pc, =0xe005b663\n" // Continue in firmware
    );
}

extern int physw0_override;

//e005b13c
void __attribute__((naked,noinline)) sub_e005b13c_my ()
{
    asm volatile(
            //capdis -f=chdk -s=0xe005b13d -c=4 -jfw -stubs PRIMARY.BIN 0xe0000000
            "    push.w  {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, ip, lr}\n"
            "    mov     r5, r0\n"
            "    ldr     r4, =0x0004e46c\n"
            "    ldr     r0, =physw0_override\n" // +
            "    ldr.w   r0, [r0]\n" // + use CHDK override value
            //"    mov.w   r0, #-1\n"           // -
            "    ldr     pc, =0xe005b149\n" // Continue in firmware
    );
}

//e025d526
void __attribute__((naked,noinline)) task_TricInitTask_my() {
    asm volatile(
            //capdis -f=chdk -s=0xe025d527 -c=12 -stubs PRIMARY.BIN 0xe0000000
            "    push.w  {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, ip, lr}\n"
            "    movs    r0, #8\n"
            "    ldr     r1, =0xe025d7b4\n" //  *"InitTskStart"
            "    bl      sub_e033c7b2\n"
            "    ldr.w   fp, =0x000256f0\n"
            "    mov.w   sl, #0x1000\n"
            "    ldr     r4, =0x000256ec\n"
            "    movs    r2, #0\n"
            "    ldr     r1, =0x0703870f\n"
            "    ldr     r0, [r4]\n"
            "    bl      sub_dffc9830\n"
            "    lsls    r0, r0, #0x1f\n"
            "    bne     sub_e025d54a\n"    // + jump to FW

            //capdis -f=chdk -s=0xe025d55d -c=15 -stubs PRIMARY.BIN 0xe0000000
            "    ldr     r4, =0x000256ec\n"
            "    mov     r1, sp\n"
            "    ldr     r0, [r4]\n"
            "    bl      sub_dffc9996\n"
            "    ldr     r1, [sp]\n"
            "    ldr     r0, [r4]\n"
            "    bl      sub_dffc9966\n"
            "    ldr     r0, =0x02000003\n"
            "    ldr     r7, [sp]\n"
            "    tst     r7, r0\n"
            "    beq     sub_e025d652\n"    // + jump to FW
            "    lsls    r0, r7, #0x1f\n"
            "    beq     sub_e025d580\n"    // + jump to FW

            "    ldr     r0, =0xd2050074\n" // +
            "    ldr     r0, [r0]\n"        // + nonzero when core already running
            "    subs    r0, #0\n"          // +
            "    beq     tric1\n"           // +
            "    ldr     r0, [r4]\n"        // +
            "    mov     r1, #0x80\n"       // +
            "    bl      _SetEventFlag\n"   // + core already initialized, set the SmacIdleCmp eventflag here
            "tric1:\n"                      // +

            "    bl      sub_e025da1a\n"
            "    b       sub_e025d5c2\n"    // + jump to FW
    );
}

int check_fsio_skip(char* msg)
{
    // Short file name (< 32 chars)
    char* name = msg + 4;
    // Long file name (will be 0 if not allocated)
    char* long_name = *((char**)(msg+0x5c));
    if (long_name != 0) name = long_name;
    int l = strlen(name);

    // G7X2 crashes when deleting or creating non-Canon files in DCIM image folder if camera is connected to PC via USB
    // This causes the FsIoNotify task to ignore files that are not Canon image files.
    // Only applies to files in A/DCIM folders with filename xxx_nnnn.ext, and ext is not JPG or CR2.
    int skip = ((strncmp(name,"A/DCIM",6) == 0) && (name[l-9] == '_') && (strncmp(name+l-4, ".JPG", 4) != 0) && (strncmp(name+l-4, ".CR2", 4) != 0));

    // If we tell FsIoNotify to skip processing message, then we need to free the long name memory buffer
    if (skip && (long_name != 0))
        free(long_name);

    return skip;
}

//e00f2b5c
void __attribute__((naked,noinline)) task_FsIoNotifyTask_my() {
    asm volatile(
            //capdis -f=chdk -s=0xe00f2b5d -c=20 -stubs PRIMARY.BIN 0xe0000000
            "    ldr     r4, =0x000111a8\n"
            "    push    {r3, lr}\n"
            "    ldr     r0, [r4, #8]\n"
            "    cbnz    r0, loc_e00f2b6e\n"
            "    movs    r2, #0xbf\n"
            "    movs    r0, #0\n"
            "    ldr     r1, =0xe00f2ed0\n" //  *"FsIoNotify.c"
            "    bl      sub_dffc96f4\n"
            "loc_e00f2b6e:\n"
            "    ldr     r0, [r4, #8]\n"
            "    movs    r2, #0\n"
            "    mov     r1, sp\n"
            "    bl      sub_dffc9de0\n"
            "    cbz     r0, loc_e00f2b84\n"
            "    movs    r2, #0xc3\n"
            "    movs    r0, #0\n"
            "    ldr     r1, =0xe00f2ed0\n" //  *"FsIoNotify.c"
            "    bl      sub_dffc96f4\n"
            "loc_e00f2b84:\n"
            "    ldr     r0, [sp]\n"
            "    bl      check_fsio_skip\n" // +
            "    cbnz    r0, loc_skip\n"    // +
            "    ldr     r0, [sp]\n"
            "    bl      sub_e00f2ac4\n"
            "loc_skip:\n"                   // +
            "    b       loc_e00f2b6e\n"
    );
}
