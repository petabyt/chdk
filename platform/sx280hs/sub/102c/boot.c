
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
    (void)ua; (void)ub; (void)uc; (void)ud; (void)ue; (void)uf;
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
// short *jog_position;

/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/

/*************************************************************/
void __attribute__((naked,noinline)) boot() {
    asm volatile ( // 0xfc02000c
"    ldr.w   sp, =0x80010000\n" // top of data tcm?
"    BL      sub_fc020064\n" // ITCM setup (vectors?)
"    ldr     r2, =0xc0242010\n"
"    ldr     r1, [r2, #0]\n"
"    orr.w   r1, r1, #1\n"
"    str     r1, [r2, #0]\n" // interrupt related?
"    ldr     r0, =0xfc953974\n"
"    ldr     r1, =0x010c1000\n"
"    ldr     r3, =0x010e03c4\n"
"    loc_fc020024:\n"
"    cmp     r1, r3\n"
"    itt     cc\n"
"    ldrcc.w r2, [r0], #4\n"
"    strcc.w r2, [r1], #4\n"
"    bcc.n   loc_fc020024\n" // copy dryos kernel to RAM

// Install CreateTask patch
// use half words in case source or destination not word aligned
        "adr     r0, patch_CreateTask\n"    // src: Patch data
        "ldr     r1, =hook_CreateTask\n"    // dest: Address to patch (hook_ has thumb bit off)
        "add     r2, r0, #8\n" // two words
"task_hook_loop:\n"
        "ldrh   r3, [r0],#2\n"
        "strh   r3, [r1],#2\n"
        "cmp    r0,r2\n"
        "blo    task_hook_loop\n"

"    ldr     r0, =0x010c1000\n"
"    ldr     r1, =0x0001f3c4\n"
"    BL      sub_fc12dd3a\n" // clean data cache (on the kernel area)
"    ldr     r0, =0xfc932514\n"
"    ldr     r1, =0x00008000\n" // end of ITCM
"    ldr     r3, =0x00029460\n"
"    loc_fc020040:\n"
"    cmp     r1, r3\n"
"    itt     cc\n"
"    ldrcc.w r2, [r0], #4\n"
"    strcc.w r2, [r1], #4\n"
"    bcc.n   loc_fc020040\n" // copy pre-initialized data
"    ldr     r3, =0x00029460\n"
"    ldr     r1, =0x002bd558\n"
"    mov.w   r2, #0\n"
"    loc_fc020056:\n"
"    cmp     r3, r1\n"
"    it      cc\n"
"    strcc.w r2, [r3], #4\n"
"    bcc.n   loc_fc020056\n" // zero-fill the above area
"    b.w     sub_fc04f194_my\n" // continue 

        "patch_CreateTask:\n"
        "ldr.w   pc, [pc,#0]\n"             // Do jump to absolute address CreateTask_my
        ".long   CreateTask_my + 1\n"           // has to be a thumb address
);
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
"    orreq   r3, #1\n"                  // make sure it's a thumb address (may not be needed?)
"    beq     exitHook\n"                // below compares not necessary if this check has found something.

"    LDR     R0, =task_ExpDrv\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =exp_drv_task\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"

"    LDR     R0, =task_DvlpSeqTask\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =developseq_task\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"

"    LDR     R0, =task_TricInitTask\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =tricinittask\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"

"    LDR     R0, =task_FileWrite\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =filewritetask\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"



"    LDR     R0, =task_MovieRecord\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =movie_record_task\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"


"    ldr     r0, =task_InitFileModules\n"
"    cmp     r0, r3\n"
"    itt     eq\n"
"    ldreq   r3, =init_file_modules_task\n"
"    orreq   r3, #1\n"
"exitHook:\n" 
// restore overwritten register(s)
"    pop    {r0}\n"
// Execute overwritten instructions from original code, then jump to firmware
"    stmdb   sp!, {r1, r2, r3, r4, r5, r6, r7, r8, r9, lr}\n"
"    mov     r4, r0\n"
"    ldr     r0, =0x8154\n"
"    ldr.w   pc, =(hook_CreateTask + 8 + 1) \n"  // Continue in firmware, thumb bit set
".ltorg\n"
);
}

//fc04f194
void __attribute__((naked,noinline)) sub_fc04f194_my() {

    if (*(int*)(0xd20b0000 + 0x10 * 4) & 0x10000) {
        // see sub_fc060338, sub_fc06082a
        // GPIO 0x10 (aka ON/OFF button) is not pressed -> play
        *(int*)(0x92a0+0x4) = 0x200000;
    }
    else {
        // GPIO 0x10 is pressed -> rec
        *(int*)(0x92a0+0x4) = 0x100000;
    }
    asm volatile (
    "push    {r4, lr}\n"
#if defined(CHDK_NOT_IN_CANON_HEAP)
    "ldr     r4, =0x002bd558\n"         // heap start, modify here
#else
    "ldr     r4, =new_sa\n"             // +
    "ldr     r4, [r4]\n"                // +
#endif
    "sub     sp, #0x78\n"
    "ldr     r0, =0x005ce000\n"
    "ldr     r1, =0x00071b34\n"
    "subs    r0, r0, r4\n"
    "cmp     r0, r1\n"
    "bcs.n   loc_fc04f1a6\n"
    "loc_fc04f1a4:\n"
    "b.n     loc_fc04f1a4\n"            // too small heap, go into infinite loop
    "loc_fc04f1a6:\n"
    "ldr     r1, =0x00008070\n"
    "mov.w   r0, #0x80000\n"
    "str     r0, [r1, #0]\n"
    "ldr     r1, =0x00008074\n"
    "ldr     r0, =0x42b21000\n"         // SD boot sector is copied here later
    "str     r0, [r1, #0]\n"
    "ldr     r1, =0x00008078 \n"
    "ldr     r0, =0x42b23000\n"         // copy of FAT?
    "str     r0, [r1, #0]\n"
    "movs    r1, #0x74\n"
    "add     r0, sp, #4\n"
    "blx     sub_fc251dcc\n"            // zerofill, ARM veneer for an ARM function
    "add     r2, sp, #4\n"
    "ldr     r0, =0x0054b000\n"
    "mov.w   r1, #0x83000\n"
    "stmia   r2!, {r0, r1, r4}\n"
    "ldr     r1, =0x005404cc\n"
    "str     r0, [sp, #24]\n"
    "movs    r0, #0x22\n"
    "subs    r2, r1, r4\n"
    "str     r0, [sp, #28]\n"
    "movs    r0, #0x98\n"
    "str     r0, [sp, #32]\n"
    "strd    r2, r1, [sp, #16]\n"
    "movw    r0, #0x1e8\n"
    "str     r0, [sp, #36]\n"
    "movs    r0, #0xf6\n"
    "str     r0, [sp, #40]\n"
    "movs    r0, #0xb6\n"
    "str     r0, [sp, #44]\n"
    "movs    r0, #0x85\n"
    "str     r0, [sp, #48]\n"
    "movs    r0, #0x40\n"
    "str     r0, [sp, #52]\n"
    "movs    r0, #4\n"
    "str     r0, [sp, #56]\n"
    "movs    r0, #0\n"
    "str     r0, [sp, #60]\n"
    "movs    r0, #16\n"
    "str     r0, [sp, #96]\n"
    "ldr     r1, =sub_fc04f324_my\n"    // -> continue here (init_task)
    "movs    r2, #0\n"
    "lsls    r0, r0, #7\n"
    "str     r0, [sp, #100]\n"
    "asrs    r0, r0, #3\n"
    "str     r0, [sp, #104]\n"
    "lsls    r0, r0, #5\n"
    "str     r0, [sp, #108]\n"
    "add     r0, sp, #4\n"
    "blx     sub_fc251414\n"
    "add     sp, #0x78\n"
    "pop     {r4, pc}\n"
    ".ltorg\n"
    );
}

//fc04f324
void __attribute__((naked,noinline)) sub_fc04f324_my() {
    asm volatile (
    "push    {r4, lr}\n"
    "ldr     r4, =0xfc04f3d0\n" // "/_term"
    "bl      sub_fc050c14\n"
    "ldr     r0, =0x000080e8\n"
    "ldr     r1, [r0, #0]\n"
    "ldr     r0, =0x00008070\n"
    "ldr     r0, [r0, #0]\n"
    "adds    r0, #16\n"
    "cmp     r1, r0\n"
    "bcs.n   loc_fc04f340\n"
    "ldr     r0, =0xfc04f3e0\n" // "USER_MEM size checking"
    "bl      sub_fc04f3b8\n"
    "loc_fc04f340:\n"
    "bl      sub_fc12de14\n"
    "ldr     r3, =0x80000800\n"
    "mov.w   r1, #0x80000000\n"
    "mov.w   r2, #0xeeeeeeee\n"
    "loc_fc04f34e:\n"
    "stmia   r1!, {r2}\n"
    "cmp     r1, r3\n"
    "bcc.n   loc_fc04f34e\n"
    "bl      sub_fc12de26\n"
    "bl      sub_fc0b9f4c\n"
    "cmp     r0, #0\n"
    "bge.n   loc_fc04f366\n"
    "ldr     r0, =0xfc04f3fc\n" // "dmSetup"
    "bl      sub_fc04f3b8\n"
    "loc_fc04f366:\n"
    "bl      sub_fc04fb90\n"
    "cmp     r0, #0\n"
    "bge.n   loc_fc04f374\n"
    "ldr     r0, =0xfc04f404\n" // "termDriverInit"
    "bl      sub_fc04f3b8\n"
    "loc_fc04f374:\n"
    "mov     r0, r4\n"
    "bl      sub_fc04fc24\n"
    "cmp     r0, #0\n"
    "bge.n   loc_fc04f384\n"
    "ldr     r0, =0xfc04f414\n" // "termDeviceCreate"
    "bl      sub_fc04f3b8\n"
    "loc_fc04f384:\n"
    "mov     r0, r4\n"
    "bl      sub_fc04f55c\n"
    "cmp     r0, #0\n"
    "bge.n   loc_fc04f394\n"
    "ldr     r0, =0xfc04f428\n" // "stdioSetup"
    "bl      sub_fc04f3b8\n"
    "loc_fc04f394:\n"
    "bl      sub_fc04f6a0\n"
    "cmp     r0, #0\n"
    "bge.n   loc_fc04f3a2\n"
    "ldr     r0, =0xfc04f434\n" // "stdlibSetup"
    "bl      sub_fc04f3b8\n"
    "loc_fc04f3a2:\n"
    "bl      sub_fc053604\n"
    "cmp     r0, #0\n"
    "bge.n   loc_fc04f3b0\n"
    "ldr     r0, =0xfc04f440\n" // "extlib_setup"
    "bl      sub_fc04f3b8\n"
    "loc_fc04f3b0:\n"
    "ldmia.w sp!, {r4, lr}\n"
    "b.w     sub_fc04f72a_my\n" // -> continue (taskcreate_startup)
    ".ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc04f72a_my() {
    asm volatile (
    "push    {r3, lr}\n"
    "bl      sub_fc04f82c\n"
    "bl      sub_fc095cbe\n"
    "cbnz    r0, loc_fc04f740\n"
    "bl      sub_fc07205c\n"    // IsNormalCameraMode
    "cbz     r0, loc_fc04f740\n"
    "movs    r0, #1\n"
    "b.n     loc_fc04f742\n"
    "loc_fc04f740:\n"
    "movs    r0, #0\n"
    "loc_fc04f742:\n"
    "bl      sub_fc060338_my\n" // -> power-on mode handling & startupchecks here
    "cbnz    r0, loc_fc04f74e\n"
    "bl      sub_fc04f81a\n"
    "loc_fc04f74c:\n"
    "b.n     loc_fc04f74c\n"    // infinite loop
    "loc_fc04f74e:\n"
    "blx     sub_fc251474\n"
    "ldr     r1, =0x005ce000\n" // could be removed, but doesn't matter
    "movs    r0, #0\n"
    "bl      sub_fc2b7bf4\n"    // could be removed, but doesn't matter
    "blx     sub_fc251b9c\n"    // kersys.c
    "movs    r3, #0\n"
    "str     r3, [sp, #0]\n"
    "ldr     r3, =sub_fc04f6c4_my\n"
    "movs    r2, #0\n"
    "movs    r1, #25\n"
    "ldr     r0, =0xfc04f77c\n" // "Startup"
    "blx     sub_fc25198c\n"    // CreateTask
    "movs    r0, #0\n"
    "pop     {r3, pc}\n"
    ".ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc060338_my() {
    asm volatile (
    "stmdb   sp!, {r2, r3, r4, r5, r6, r7, r8, lr}\n"
    "mov.w   r8, #0\n"
    "mov     r7, r0\n"
    "mov     r6, r8\n"
    "bl      sub_fc060826\n" // nullsub
    "movs    r0, #16\n"
    "bl      sub_fc05f5c2\n"
    "movs    r4, #1\n"
    "bic.w   r5, r4, r0\n"
    "movs    r0, #15\n"
    "bl      sub_fc05f5c2\n"    // reads GPIO (15)
    "bics    r4, r0\n"
    "cbz     r7, loc_fc060364\n"
    "orrs.w  r0, r5, r4\n"
    //"beq.n   loc_fc06037e\n"  // - this check fails and results in shutdown
    "loc_fc060364:\n"
    "bl      sub_fc095cbe\n"
    "movs    r3, #0\n"
    "mov     r2, r0\n"
    "strd    r8, r6, [sp]\n"
    "mov     r1, r4\n"
    "mov     r0, r5\n"
    //"bl      sub_fc06082a\n"  // - startupchecks
    //"bl      sub_fc060828\n"  // - nullsub
    "movs    r0, #1\n"
    "loc_fc06037e:\n"
    "ldmia.w sp!, {r2, r3, r4, r5, r6, r7, r8, pc}\n"
    ".ltorg\n"
    );
}


// task_Startup
void __attribute__((naked,noinline)) sub_fc04f6c4_my() {
    asm volatile (
    "push    {r4, lr}\n"
    "bl      sub_fc0ba768\n"
    "bl      sub_fc04f7f8\n"
    "bl      sub_fc04f96c\n"
    "bl      sub_fc095d10\n"
    //"bl      sub_fc04f9c2\n"      // - startdiskboot
    "bl      sub_fc07aff2\n"
    "bl      sub_fc0ba800\n"
    "bl      sub_fc04fad0\n"
    "bl      sub_fc04f908\n"
    "bl      sub_fc095d4e\n"
    "bl      sub_fc095998\n"
    "bl      sub_fc0ba806\n"
    "BL      CreateTask_spytask\n"  // +
    "bl      sub_fc06021a_my\n"     // -> taskcreate_physw
    "bl      sub_fc20d318\n"
    "bl      sub_fc0ba81c\n"
    "bl      sub_fc095750\n"

#if defined(OPT_RUN_WITH_BATT_COVER_OPEN)
"   mov     r0, #0x100000 \n"       // +
"batt_loop1: \n"                    // +
"   nop\n"                          // +
"   SUBS    R0,R0,#1 \n"            // +
"   BNE     batt_loop1 \n"          // +
#endif

    "bl      sub_fc12ed44\n"
    "bl      sub_fc095b24\n"
    "bl      sub_fc09594a\n"
    "bl      sub_fc12ed04\n"
    "bl      sub_fc04fad4\n"
    "bl      sub_fc2a3c36\n"
    "bl      sub_fc12ecde\n"
    "ldmia.w sp!, {r4, lr}\n"
    //"b.w     sub_fc0ba73e\n"      // - (not recognized automatically yet, transformed into ldr pc)
    "ldr     pc, =0xfc0ba73f\n"     // + thumb address must be used
    ".ltorg\n"
    );
}

//taskcreate_physw
void __attribute__((naked,noinline)) sub_fc06021a_my() {
    asm volatile (
    "push    {r3, r4, r5, lr}\n"
    "ldr     r4, =0x8328\n"
    "ldr     r0, [r4, #4]\n"
    "cbnz    r0, loc_fc060236\n"
    "movs    r3, #0\n"
    "str     r3, [sp, #0]\n"
    "ldr     r3, =mykbd_task\n"
    "movs    r1, #23\n"
    "ldr     r0, =0xfc06027c\n" // "PhySw"
    "movw    r2, #0x2000\n"     // original value 0x800
    "blx     sub_fc251c94\n"
    "str     r0, [r4, #4]\n"
    "loc_fc060236:\n"
    "bl      sub_fc061aac\n"
    "bl      sub_fc071fe6\n"
    "cmp     r0, #0\n"
    "bne.n   loc_fc06024e\n"
    "ldr     r1, =0x2ae94\n"
    "ldmia.w sp!, {r3, r4, r5, lr}\n"
    "subs    r1, #24\n"
    //"b.w     sub_fc061a54\n"  // - the stub generator needs fixing to support this
    "ldr     pc, =0xfc061a55\n" // + thumb address must be used
    "loc_fc06024e:\n"
    "pop     {r3, r4, r5, pc}\n"
    ".ltorg\n"
    );
}

void __attribute__((naked,noinline)) init_file_modules_task() { //sub_fc088220_my()
    asm volatile (
"    push    {r4, r5, r6, lr}\n"
"    bl      sub_fc09ad60\n"
"    movs    r4, r0\n"
"    movw    r5, #0x5006\n"
"    beq.n   loc_fc088236\n"
"    movs    r1, #0\n"
"    mov     r0, r5\n"
"    bl      sub_fc2a6188\n"
"loc_fc088236:\n"
"    bl      sub_fc09ad96\n"
"    BL      core_spytask_can_start\n" // + CHDK: Set "it's-safe-to-start" flag for spytask
"    cmp     r4, #0\n"
"    bne.n   loc_fc08824a\n"
"    mov     r0, r5\n"
"    ldmia.w sp!, {r4, r5, r6, lr}\n"
"    movs    r1, #0\n"
"    b.w     sub_fc2a6188\n"
"loc_fc08824a:\n"
"    pop     {r4, r5, r6, pc}\n"
    );
}

void __attribute__((naked,noinline)) kbd_p2_f_my() { // 0xfc05ffc0
    asm volatile(
"    stmdb   sp!, {r4, r5, r6, r7, r8, lr}\n"
"    ldr     r6, =0x2ae94\n"
"    sub     sp, #0x18\n"
"    add     r7, sp, #8\n"
"    subs    r6, #0xc\n"
"    b.n     loc_fc060002\n"
"loc_fc05ffce:\n"
"    ldr     r1, =0x2ae94\n"
"    add     r3, sp, #8\n"
"    ldrb.w  r0, [sp, #4]\n"
"    add     r2, sp, #0x14\n"
"    subs    r1, #0x18\n"
"    bl      sub_fc060ca4\n"
"    cbnz    r0, loc_fc05ffe8\n"
"    ldr     r1, [sp, #0x14]\n"
"    movs    r0, #0\n"
"    bl      sub_fc05ff32\n"
"loc_fc05ffe8:\n"
"    movs    r0, #2\n"
"loc_fc05ffea:\n"
"    ldr.w   r1, [r7, r0, lsl #2]\n"
"    cbz     r1, loc_fc05fffa\n"
"    ldr.w   r2, [r6, r0, lsl #2]\n"
"    bics    r2, r1\n"
"    str.w   r2, [r6, r0, lsl #2]\n"
"loc_fc05fffa:\n"
"    subs    r0, r0, #1\n"
"    sxtb    r0, r0\n"
"    cmp     r0, #0\n"
"    bge.n   loc_fc05ffea\n"
"loc_fc060002:\n"
"    ldr     r0, =0x2ae94\n"
"    add     r1, sp, #4\n"
"    subs    r0, #0xc\n"
"    bl      sub_fc0609d6\n"
"    cmp     r0, #0\n"
"    bne.n   loc_fc05ffce\n"
"    ldr     r8, =0x2ae94\n"
"    movs    r4, #0\n"
"loc_fc060016:\n"
"    movs    r5, #0\n"
"    ldr.w   r0, [r6, r4, lsl #2]\n"
"    ldr.w   r1, [r8, r4, lsl #2]\n"
"    ands    r0, r1\n"
"    str.w   r0, [r6, r4, lsl #2]\n"
"    b.n     loc_fc06006e\n"
"loc_fc060028:\n"
"    lsrs    r0, r5\n"
"    lsls    r0, r0, #0x1f\n"
"    beq.n   loc_fc060066\n"
"    ldr     r1, =0x2ae94\n"
"    add.w   r0, r5, r4, lsl #5\n"
"    add     r3, sp, #8\n"
"    subs    r1, #0x18\n"
"    add     r2, sp, #0x14\n"
"    uxtb    r0, r0\n"
"    bl      sub_fc060ca4\n"
"    cbnz    r0, loc_fc06004a\n"
"    ldr     r1, [sp, #0x14]\n"
"    movs    r0, #1\n"
"    bl      sub_fc05ff32\n"
"loc_fc06004a:\n"
"    mov     r0, r4\n"
"    b.n     loc_fc060062\n"
"loc_fc06004e:\n"
"    ldr.w   r1, [r7, r0, lsl #2]\n"
"    cbz     r1, loc_fc06005e\n"
"    ldr.w   r2, [r6, r0, lsl #2]\n"
"    bics    r2, r1\n"
"    str.w   r2, [r6, r0, lsl #2]\n"
"loc_fc06005e:\n"
"    adds    r0, r0, #1\n"
"    sxtb    r0, r0\n"
"loc_fc060062:\n"
"    cmp     r0, #3\n"
"    blt.n   loc_fc06004e\n"
"loc_fc060066:\n"
"    ldr.w   r0, [r6, r4, lsl #2]\n"
"    adds    r5, r5, #1\n"
"    uxtb    r5, r5\n"
"loc_fc06006e:\n"
"    cmp     r0, #0\n"
"    bne.n   loc_fc060028\n"
"    adds    r4, r4, #1\n"
"    sxtb    r4, r4\n"
"    cmp     r4, #3\n"
"    blt.n   loc_fc060016\n"
"    bl      sub_fc060900_my\n"     // ->
"    add     sp, #0x18\n"
"    ldmia.w sp!, {r4, r5, r6, r7, r8, pc}\n"
".ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc060900_my() {
    asm volatile(
"    push    {r4, lr}\n"
"    ldr     r4, =0x92a0\n"
"    ldr     r0, [r4, #8]\n"
"    bl      sub_fc0629f4\n"
"    bl      sub_fc0a0fa0\n"
"    ldr     r0, [r4, #12]\n"
"    bl      sub_fc062910\n"
//"    ldmia.w sp!, {r4, lr}\n" // - (reordered below)
//"    b.w     loc_fc05cbf6\n"  // - (reordered below)
"    bl      handle_jogdial\n"  // +
"    cmp     r0, #0\n"          // +
"    beq     no_scroll\n"       // +
"    bl      sub_fc05cbf6\n"    // handles scrollwheel(s), void function, no args
"no_scroll:\n"                  // +
"    pop     {r4, pc}\n"        // +
    );
}


// following is for supporting "firmware update" boot
void __attribute__((naked,noinline)) tricinittask() {
    asm volatile(
// capdis -f=chdk -s=task_TricInitTask -c=35 -stubs PRIMARY.BIN 0xfc000000
// task_TricInitTask 0xfc373dc1
"    push.w  {r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}\n"
"    blx     sub_fc251ad4\n"
"    movs    r0, #8\n"
"    ldr     r1, =0xfc374010\n" //  *"InitTskStart"
"    bl      sub_fc28b7ee\n"
"    ldr.w   fp, =0x0001bf74\n"
"    movw    sl, #0x1000\n"
"    ldr     r4, =0x0001bf70\n"
"    movs    r2, #0\n"
"    ldr     r1, =0x0003830f\n"
"    ldr     r0, [r4]\n"
"    blx     sub_fc251d4c\n" // j_WaitForAnyEventFlag
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc373dfa\n"
"    movs    r0, #8\n"
"    ldr     r1, =0xfc374028\n" //  *"ER IniTskWait"
"    bl      sub_fc28b84a\n"
"    ldr     r1, =0x0001bf5c\n"
"    movs    r0, #0\n"
"    str     r0, [r1]\n"
"    pop.w   {r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}\n"
"loc_fc373dfa:\n"
"    ldr     r4, =0x0001bf70\n"
"    add     r1, sp, #8\n"
"    ldr     r0, [r4]\n"
"    blx     sub_fc251bec\n" // j_GetEventFlagValue
"    ldr     r1, [sp, #8]\n"
"    ldr     r0, [r4]\n"
"    blx     sub_fc251c1c\n" // j_ClearEventFlag
"    ldr     r6, [sp, #8]\n"
"    lsls    r0, r6, #0x1e\n"
"    beq     sub_fc373ed2\n" // loc -> sub
"    lsls    r0, r6, #0x1f\n"
"    beq     sub_fc373e1c\n" // loc -> sub

"    ldr     r0, =0xd2020074\n" // +
"    ldr     r0, [r0]\n"        // + nonzero when core already running
"    subs    r0, #0\n"          // +
"    beq     tric1\n"           // +
"    ldr     r0, [r4]\n"        // +
"    mov     r1, #0x80\n"       // +
"    bl      _SetEventFlag\n"   // + core already initialized, set the SmacIdleCmp eventflag here
"tric1:\n"                      // +

"    bl      sub_fc374160\n"
//"    b       loc_fc373e5e\n" // -
"    ldr     pc, =0xfc373e5f\n" // -> continue in rom
    );
}



