#include "lolevel.h"
#include "platform.h"
#include "core.h"

const char * const new_sa = &_end;

// Forward declarations

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_RotaryEncoder();
extern void task_MovieRecord();
extern void task_ExpDrv();

extern void handle_jogdial();

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


/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/

/*************************************************************/
//  -s=0xfc02000d -c=35
void __attribute__((naked,noinline)) boot() {
    asm volatile (
"    movw    r0, #0x4000\n"
"    movt    r0, #0\n"
"    mov     sp, r0\n"
"    bl      sub_fc02006a\n"
"    ldr     r2, =0xc0242010\n"
"    ldr     r1, [r2]\n"
"    orr     r1, r1, #1\n"
"    str     r1, [r2]\n"
"    ldr     r0, =0xfcd67020\n"
"    ldr     r1, =0x010e1000\n"
"    ldr     r3, =0x0110dc1c\n"
"loc_fc02002a:\n"
"    cmp     r1, r3\n"
"    itt     lo\n"
"    ldrlo   r2, [r0], #4\n"
"    strlo   r2, [r1], #4\n"
"    blo     loc_fc02002a\n"
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
"    ldr     r0, =0x010e1000\n"
"    ldr     r1, =0x0002cc1c\n"
"    bl      sub_fc133dae\n"
"    ldr     r0, =0xfcd39d68\n"
"    ldr     r1, =0x00008000\n"
"    ldr     r3, =0x000352b8\n"
"loc_fc020046:\n"
"    cmp     r1, r3\n"
"    itt     lo\n"
"    ldrlo   r2, [r0], #4\n"
"    strlo   r2, [r1], #4\n"
"    blo     loc_fc020046\n"
"    ldr     r3, =0x000352b8\n"
"    ldr     r1, =0x0036a354\n"
"    mov.w   r2, #0\n"
"loc_fc02005c:\n"
"    cmp     r3, r1\n"
"    it      lo\n"
"    strlo   r2, [r3], #4\n"
"    blo     loc_fc02005c\n"

"    blx     patch_mzrm_sendmsg\n"

"    b.w     sub_fc064300_my\n"

        "patch_CreateTask:\n"
        "ldr.w   pc, [pc,#0]\n"             // Do jump to absolute address CreateTask_my
        ".long   CreateTask_my + 1\n"           // has to be a thumb address
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
            "    beq     chk_msg_type\n"
            "exit_debug_logging_my:\n"
            "    bx      lr\n"

            "chk_msg_type:\n"
            // mzrm_sendmsg 'msg' value (2nd parameter, saved in r11)
            "    ldr     r1, [r11]\n"                   // message type
            "    cmp     r1, 0x23\n"                    // message type XimrExe
            "    beq     do_ui_update\n"
            "    cmp     r1, 0x24\n"                    // message type XimrExeGain
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

/*
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
*/

"    ldr     r0, =task_FileWrite\n"
"    cmp     r0, r3\n"
"    itt     eq\n"
"    ldreq   r3, =filewritetask\n"
"    orreq   r3, #1\n"
"    beq     exitHook\n"

/*
"    LDR     R0, =task_MovieRecord\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =movie_record_task\n"
"    BEQ     exitHook\n"
*/

"    ldr     r0, =task_InitFileModules\n"
"    cmp     r0, r3\n"
"    itt     eq\n"
"    ldreq   r3, =init_file_modules_task\n"
"    orreq   r3, #1\n"
"exitHook:\n"
// restore overwritten register(s)
"    pop    {r0}\n"
// Execute overwritten instructions from original code, then jump to firmware
// NOTE number of instructions duplicated here depends on size of original ROM code
// instructions. Must replace 8 bytes!
"    stmdb   sp!, {r1, r2, r3, r4, r5, r6, r7, r8, r9, lr}\n"
"    mov     r4, r0\n"
"    ldr     r0, =0x8160\n"
"    ldr.w   pc, =(hook_CreateTask + 8 + 1) \n"  // Continue in firmware (thumb bit set)
".ltorg\n"
);
}

void __attribute__((naked,noinline)) sub_fc064300_my() {
// no GPIO checks needed with 0x12345678 set, native fw handles long press
// -s=0xfc064301 -c=60
    asm volatile (
"    push    {r4, lr}\n"
#if defined(CHDK_NOT_IN_CANON_HEAP)
"    ldr     r4, =0x0036a354\n"         // heap start, modify here
#else
    "ldr     r4, =new_sa\n"             // +
    "ldr     r4, [r4]\n"                // +
#endif
"    sub     sp, #0x78\n"
"    ldr     r0, =0x006ce000\n"
"    ldr     r1, =0x0008fd8c\n"
"    subs    r0, r0, r4\n"
"    cmp     r0, r1\n"
"    bhs     loc_fc064312\n"
"loc_fc064310:\n"
"    b       loc_fc064310\n"
"loc_fc064312:\n"
"    ldr     r1, =0x00008074\n"
"    mov.w   r0, #0x80000\n"
"    str     r0, [r1]\n"
"    ldr     r1, =0x00008078\n"
"    ldr     r0, =0x42a41000\n"
"    str     r0, [r1]\n"
"    ldr     r1, =0x0000807c\n"
"    ldr     r0, =0x42a43000\n"
"    str     r0, [r1]\n"
"    movs    r1, #0x78\n"
"    mov     r0, sp\n"
"    blx     sub_fc2efa30\n" // j_bzero
"    ldr     r0, =0x0062e000\n"
"    mov.w   r1, #0xa0000\n"
"    stm.w   sp, {r0, r1, r4}\n"
"    ldr     r1, =0x00622274\n"
"    subs    r2, r1, r4\n"
"    strd    r2, r1, [sp, #0xc]\n"
"    str     r0, [sp, #0x14]\n"
"    movs    r0, #0x22\n"
"    str     r0, [sp, #0x18]\n"
"    movs    r0, #0x98\n"
"    str     r0, [sp, #0x1c]\n"
"    movw    r0, #0x24c\n"
"    str     r0, [sp, #0x20]\n"
"    movs    r0, #0xfa\n"
"    str     r0, [sp, #0x24]\n"
"    movs    r0, #0xe8\n"
"    str     r0, [sp, #0x28]\n"
"    movs    r0, #0x85\n"
"    str     r0, [sp, #0x2c]\n"
"    movs    r0, #0x40\n"
"    str     r0, [sp, #0x30]\n"
"    movs    r0, #4\n"
"    str     r0, [sp, #0x34]\n"
"    movs    r0, #0\n"
"    str     r0, [sp, #0x38]\n"
"    movs    r0, #0x10\n"
"    str     r0, [sp, #0x5c]\n"
"    movs    r2, #0\n"
"    lsls    r0, r0, #8\n"
"    str     r0, [sp, #0x60]\n"
//"    ldr     r1, =0xfc064491\n"
"    ldr     r1, =sub_fc064490_my\n"// -> continue here (init_task)
"    asrs    r0, r0, #4\n"
"    str     r0, [sp, #0x64]\n"
"    lsls    r0, r0, #5\n"
"    str     r0, [sp, #0x68]\n"
"    mov     r0, sp\n"
"    blx     sub_fc2eef88\n"
"    add     sp, #0x78\n"
"    pop     {r4, pc}\n"
".ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc064490_my() {
// -s=0xfc064491 -c=54
    asm volatile (
"    push    {r4, lr}\n"
"    ldr     r4, =0xfc06453c\n" //  *"/_term"
"    bl      sub_fc065764\n"
"    ldr     r0, =0x000080ec\n"
"    ldr     r1, [r0]\n"
"    ldr     r0, =0x00008074\n"
"    ldr     r0, [r0]\n"
"    adds    r0, #0x10\n"
"    cmp     r1, r0\n"
"    bhs     loc_fc0644ac\n"
"    ldr     r0, =0xfc06454c\n" //  *"USER_MEM size checking"
"    bl      sub_fc064524\n"
"loc_fc0644ac:\n"
"    bl      sub_fc133e88\n"
"    ldr     r3, =0x80000800\n"
// note capdis bad output
//"    mov.w   r1, #-0x80000000\n"
//"    mov.w   r2, #-0x11111112\n"
"    mov.w   r1, #0x80000000\n"
"    mov.w   r2, #0xeeeeeeee\n"
"loc_fc0644ba:\n"
"    stm     r1!, {r2}\n"
"    cmp     r1, r3\n"
"    blo     loc_fc0644ba\n"
"    bl      sub_fc133e9a\n"
"    bl      sub_fc133f18\n"
"    cmp     r0, #0\n"
"    bge     loc_fc0644d2\n"
"    ldr     r0, =0xfc064568\n" //  *"dmSetup"
"    bl      sub_fc064524\n"
"loc_fc0644d2:\n"
"    bl      sub_fc064d18\n"
"    cmp     r0, #0\n"
"    bge     loc_fc0644e0\n"
"    ldr     r0, =0xfc064570\n" //  *"termDriverInit"
"    bl      sub_fc064524\n"
"loc_fc0644e0:\n"
"    mov     r0, r4\n"
"    bl      sub_fc064da6\n"
"    cmp     r0, #0\n"
"    bge     loc_fc0644f0\n"
"    ldr     r0, =0xfc064580\n" //  *"termDeviceCreate"
"    bl      sub_fc064524\n"
"loc_fc0644f0:\n"
"    mov     r0, r4\n"
"    bl      sub_fc0646c8\n"
"    cmp     r0, #0\n"
"    bge     loc_fc064500\n"
"    ldr     r0, =0xfc064594\n" //  *"stdioSetup"
"    bl      sub_fc064524\n"
"loc_fc064500:\n"
"    bl      sub_fc06480c\n"
"    cmp     r0, #0\n"
"    bge     loc_fc06450e\n"
"    ldr     r0, =0xfc0645a0\n" //  *"stdlibSetup"
"    bl      sub_fc064524\n"
"loc_fc06450e:\n"
"    bl      sub_fc0678ec\n"
"    cmp     r0, #0\n"
"    bge     loc_fc06451c\n"
"    ldr     r0, =0xfc0645ac\n" //  *"extlib_setup"
"    bl      sub_fc064524\n"
"loc_fc06451c:\n"
"    pop.w   {r4, lr}\n"
"    b.w     sub_fc064896_my\n" // ->
    ".ltorg\n"
    );
}
void __attribute__((naked,noinline)) sub_fc064896_my() {
    asm volatile (
// -s=0xfc064897 -c=27
"    push    {r3, lr}\n"
"    bl      sub_fc0649b0\n"
"    bl      sub_fc0bda32\n"
"    cbnz    r0, loc_fc0648ac\n"
"    bl      sub_fc079012\n" // IsNormalCameraMode_FW
"    cbz     r0, loc_fc0648ac\n"
"    movs    r0, #1\n"
"    b       loc_fc0648ae\n"
"loc_fc0648ac:\n"
"    movs    r0, #0\n"
"loc_fc0648ae:\n"
"    bl      sub_fc0781f4\n" // power-on mode handling & startupchecks here, no override needed with 0x12345678 set
"    cbnz    r0, loc_fc0648ba\n"
"    bl      sub_fc06499e\n"
"loc_fc0648b8:\n"
"    b       loc_fc0648b8\n"
"loc_fc0648ba:\n"
"    blx     sub_fc2eefe0\n"
"    ldr     r1, =0x006ce000\n"
"    movs    r0, #0\n"
"    bl      sub_fc36025c\n"
"    blx     sub_fc2ef548\n"
"    movs    r3, #0\n"
"    str     r3, [sp]\n"
//"    ldr     r3, =0xfc064831\n" //  task_Startup
"    ldr     r3, =task_Startup_my\n" //  ->
"    movs    r2, #0\n"
"    movs    r1, #0x19\n"
"    ldr     r0, =0xfc0648e8\n" //  *"Startup"
"    bl      _CreateTask\n"
//"    blx     sub_fc2ef5b8\n" // j_CreateTask
"    movs    r0, #0\n"
"    pop     {r3, pc}\n"
    ".ltorg\n"
    );
}

void __attribute__((naked,noinline)) task_Startup_my() {
    asm volatile (
// -s=task_Startup -c=26
// task_Startup 0xfc064831
"    push    {r4, lr}\n"
"    bl      sub_fc13515c\n"
"    bl      sub_fc06497c\n"
//"    bl      sub_fc064b10\n" // ->nullsub
"    bl      sub_fc0db5c4\n"
// added for SD card UHS detection https://chdk.setepontos.com/index.php?topic=13089.msg132583#msg132583
"bl sub_010e638b\n" // ref in sub_010e647c following SD1stInit create
//"    bl      sub_fc064b66\n" // StartDiskboot
"    bl      sub_fc091b6e\n"
"    bl      sub_fc0db718\n"
"    bl      sub_fc064c58\n"
"    bl      sub_fc064a90\n"
"    bl      sub_fc0db602\n"
"    bl      sub_fc0bd780\n"
"    bl      sub_fc0db71e\n"
"    bl      sub_fc0780e6_my\n" // CreateTask PhySw
"    bl      CreateTask_spytask\n"
"    bl      init_required_fw_features\n" // added
"    bl      sub_fc282ac8\n"
"    bl      sub_fc0db734\n"
"    bl      sub_fc0bd718\n"
"    bl      sub_fc134f16\n"
"    bl      sub_fc0bd8de\n"
"    bl      sub_fc0db576\n"
"    bl      sub_fc134ed2\n"
"    bl      sub_fc064c5c\n"
"    bl      sub_fc356c6e\n"
"    bl      sub_fc134ea6\n"
"    pop.w   {r4, lr}\n"
"    b.w     sub_fc135132\n"
    ".ltorg\n"
    );
}

// -f=chdk -s=0xfc0780e7 -c=18
//taskcreate_physw
void __attribute__((naked,noinline)) sub_fc0780e6_my() {
    asm volatile (
"    push    {r3, r4, r5, lr}\n"
"    bl      sub_fc076fb8\n"
"    bl      sub_fc078f90\n" // IsFactoryMode_FW
"    cbnz    r0, loc_fc0780f6\n"
"    bl      sub_fc076f5c\n" // OpLog.Start_FW
"loc_fc0780f6:\n"
"    ldr     r4, =0x000082c8\n" //  physw_run
"    ldr     r0, [r4, #4]\n"
"    cmp     r0, #0\n"
"    bne     loc_fc078112\n"
"    movs    r3, #0\n"
"    str     r3, [sp]\n"
//"    ldr     r3, =0xfc0780c1\n" //  task_PhySw
"    ldr     r3, =mykbd_task\n" //+
"    movs    r1, #0x17\n"
"    ldr     r0, =0xfc078140\n" //  *"PhySw"
"    movw    r2, #0x2000\n" // adjusted 0x800 -> 0x2000
"    blx     sub_fc2ef908\n" // j_CreateTaskStrictly
"    str     r0, [r4, #4]\n"
"loc_fc078112:\n"
"    pop     {r3, r4, r5, pc}\n"
    ".ltorg\n"
    );
}

// -f=chdk -s=task_InitFileModules -c=16
void __attribute__((naked,noinline)) init_file_modules_task() {
    asm volatile (
// task_InitFileModules 0xfc0c22d1
"    push    {r4, r5, r6, lr}\n"
"    bl      sub_fc0c361c\n"
"    movs    r4, r0\n"
"    movw    r5, #0x5006\n"
"    beq     loc_fc0c22e6\n"
"    movs    r1, #0\n"
"    mov     r0, r5\n"
"    bl      _PostLogicalEventToUI\n"
"loc_fc0c22e6:\n"
"    bl      sub_fc0c3646_my\n" // for multipart
"    BL      core_spytask_can_start\n" // + CHDK: Set "it's-safe-to-start" flag for spytask
"    cmp     r4, #0\n"
"    bne     loc_fc0c22fa\n"
"    mov     r0, r5\n"
"    pop.w   {r4, r5, r6, lr}\n"
"    movs    r1, #0\n"
"    b.w     _PostLogicalEventToUI\n"
"loc_fc0c22fa:\n"
"    pop     {r4, r5, r6, pc}\n"
    ".ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc0c3646_my() {
    asm volatile (
// -s=0xfc0c3647 -c=3 -jfw
"    movs    r0, #3\n"
"    push    {r4, lr}\n"
"    bl      sub_fc3579aa_my\n" // ->
"    ldr     pc, =0xfc0c364f\n" // Continue in firmware
    );
}

void __attribute__((naked,noinline)) sub_fc3579aa_my() {
    asm volatile (
// -s=0xfc3579ab -c=25 -jfw
"    push.w  {r4, r5, r6, r7, r8, lr}\n"
"    mov     r6, r0\n"
"    bl      sub_fc35797c\n"
"    ldr     r1, =0x0003d908\n"
"    mov     r5, r0\n"
"    add.w   r4, r1, r0, lsl #7\n"
"    ldr     r0, [r4, #0x6c]\n"
"    lsls    r0, r0, #0x1d\n"
"    bpl     loc_fc3579d0\n"
"    movw    r2, #0xa6a\n"
"    ldr     r1, =0xfc357464\n" //  *"Mounter.c"
"    movs    r0, #0\n"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc3579d0:\n"
"    mov     r1, r6\n"
"    mov     r0, r5\n"
"    bl      sub_fc3572da\n"
"    ldr     r0, [r4, #0x38]\n"
"    bl      sub_fc357ef2\n"
"    cbnz    r0, loc_fc3579e4\n"
"    movs    r0, #0\n"
"    str     r0, [r4, #0x6c]\n"
"loc_fc3579e4:\n"
"    mov     r0, r5\n"
"    bl      sub_fc357332\n"
"    mov     r0, r5\n"
"    bl      sub_fc35757a_my\n"
"    ldr     pc, =0xfc3579f1\n" // Continue in firmware
    );
}

void __attribute__((naked,noinline)) sub_fc35757a_my() {
    asm volatile (
// -s=0xfc35757b -c=10 -jfw
"    push    {r4, r5, r6, lr}\n"
"    mov     r5, r0\n"
"    ldr     r0, =0x0003d908\n"
"    add.w   r4, r0, r5, lsl #7\n"
"    ldr     r0, [r4, #0x6c]\n"
"    lsls    r0, r0, #0x1e\n"
"    bmi     sub_fc3575ac\n" // jump to return in fw
"    ldr     r0, [r4, #0x38]\n"
"    mov     r1, r5\n"
"    bl      sub_fc357390_my\n" // ->
"    ldr     pc, =0xfc357593\n" // Continue in firmware
    );
}

void __attribute__((naked,noinline)) sub_fc357390_my() {
    asm volatile (
// -s=0xfc357391 -c=112
"    push.w  {r4, r5, r6, r7, r8, sb, sl, lr}\n"
"    mov     sl, r0\n"
"    ldr     r0, =0x0003d908\n"
"    mov.w   r8, #0\n"
"    add.w   r5, r0, r1, lsl #7\n"
"    mov     r6, r8\n"
"    mov     sb, r8\n"
"    ldr     r0, [r5, #0x3c]\n"
"    cmp     r0, #7\n"
"    bhs     loc_fc357492\n"
"    tbb     [pc, r0]\n" // (jumptable r0 7 elements)
"branchtable_fc3573ae:\n"
"    .byte((loc_fc3573c6 - branchtable_fc3573ae) / 2)\n" // (case 0)
"    .byte((loc_fc3573b6 - branchtable_fc3573ae) / 2)\n" // (case 1)
"    .byte((loc_fc3573b6 - branchtable_fc3573ae) / 2)\n" // (case 2)
"    .byte((loc_fc3573b6 - branchtable_fc3573ae) / 2)\n" // (case 3)
"    .byte((loc_fc3573b6 - branchtable_fc3573ae) / 2)\n" // (case 4)
"    .byte((loc_fc35748e - branchtable_fc3573ae) / 2)\n" // (case 5)
"    .byte((loc_fc3573b6 - branchtable_fc3573ae) / 2)\n" // (case 6)
".align 1\n"
"loc_fc3573b6:\n"
"    movs    r2, #0\n"
"    movw    r1, #0x200\n"
"    movs    r0, #2\n"
"    bl      _exmem_ualloc\n"
"    movs    r4, r0\n"
"    bne     loc_fc3573cc\n"
"loc_fc3573c6:\n"
"    movs    r0, #0\n"
"loc_fc3573c8:\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, sl, pc}\n"
"loc_fc3573cc:\n"
"    ldr     r7, [r5, #0x50]\n"
"    movs    r2, #1\n"
"    movs    r1, #0\n"
"    mov     r3, r4\n"
"    mov     r0, sl\n"
"    blx     r7\n"
"    cmp     r0, #1\n"
"    bne     loc_fc3573e4\n"
"    movs    r0, #2\n"
"    bl      _exmem_ufree\n"
"    b       loc_fc3573c6\n" //  return 0
"loc_fc3573e4:\n"
"    ldr     r1, [r5, #0x64]\n"
"    mov     r0, sl\n"
"    blx     r1\n"

"    mov     r1, r4\n"              //  pointer to MBR in r1
"    bl      mbr_read_dryos\n"      //  total sectors count in r0 before and after call

// Start of DataGhost's FAT32 autodetection code (Digic6+ version by philmoz)
// Policy: If there is a partition which has type FAT32 or exFat, use the first one of those for image storage
// According to the code below, we can use r1, r2, r3 and r12.
// LR wasn't really used anywhere but for storing a part of the partition signature. This is the only thing
// that won't work with an offset, but since we can load from LR+offset into LR, we can use this to do that :)
"    mov     r7, r4\n"              // Copy the MBR start address so we have something to work with
"    mov     lr, r4\n"              // Save old offset for MBR signature
"    mov     r1, #1\n"              // Note the current partition number
"    b       dg_sd_fat32_enter\n"   // We actually need to check the first partition as well, no increments yet!
"dg_sd_fat32:\n"
"    cmp     r1, #4\n"              // Did we already see the 4th partition?
"    beq     dg_sd_fat32_end\n"     // Yes, break. We didn't find anything, so don't change anything.
"    add     r7, r7, #0x10\n"       // Second partition
"    add     r1, r1, #1\n"          // Second partition for the loop
"dg_sd_fat32_enter:\n"
"    ldrb.w  r2, [r7, #0x1BE]\n"    // Partition status
"    ldrb.w  r3, [r7, #0x1C2]\n"    // Partition type (FAT32 = 0xB)
"    cmp     r3, #0xB\n"            // Is this a FAT32 partition?
"    beq     dg_sd_valid\n"
"    cmp     r3, #0xC\n"            // Not 0xB, is it 0xC (FAT32 LBA) then?
"    beq     dg_sd_valid\n"
"    cmp     r3, #0x7\n"            // exFat?
"    bne     dg_sd_fat32\n"         // No, it isn't. Loop again.
"dg_sd_valid:\n"
"    cmp     r2, #0x00\n"           // It is, check the validity of the partition type
"    beq     dg_sd_ok\n"
"    cmp     r2, #0x80\n"
"    bne     dg_sd_fat32\n"         // Invalid, go to next partition
"dg_sd_ok:\n"
                                    // This partition is valid, it's the first one, bingo!
"    mov     r4, r7\n"              // Move the new MBR offset for the partition detection.

"dg_sd_fat32_end:\n"
// End of DataGhost's FAT32 autodetection code

"    ldr.w   r2, [r4, #0x1c7]\n"
"    mov     r1, r0\n"
"    ldrb.w  r0, [r4, #0x1c6]\n"
"    ldr.w   r7, [r4, #0x1cb]\n"
"    orr.w   r0, r0, r2, lsl #8\n"
"    ldrb.w  r2, [r4, #0x1ca]\n"
"    ldrb.w  r3, [r4, #0x1be]\n"
"    orr.w   r2, r2, r7, lsl #8\n"
//"    ldrb.w  r7, [r4, #0x1fe]\n" // replaced below
//"    ldrb.w  r4, [r4, #0x1ff]\n" // replaced below
"    ldrb.w  r7, [lr, #0x1fe]\n"    // replace instructions above
"    ldrb.w  r4, [lr, #0x1ff]\n"    // replace instructions above
"    cbz     r3, loc_fc357416\n"
"    cmp     r3, #0x80\n"
"    bne     loc_fc357428\n"
"loc_fc357416:\n"
"    cmp     r1, r0\n"
"    blo     loc_fc357428\n"
"    adds    r3, r0, r2\n"
"    cmp     r3, r1\n"
"    bhi     loc_fc357428\n"
"    cmp     r7, #0x55\n"
"    bne     loc_fc357428\n"
"    cmp     r4, #0xaa\n"
"    beq     loc_fc357470\n"
"loc_fc357428:\n"
"    mov     r4, sb\n"
"    b       loc_fc357476\n"
".ltorg\n" // canon firmware had a literal pool here
"loc_fc357448:\n"
"    muls    r3, r2, r3\n"
"    ldr     r1, =0x6ba0d009\n"
"    strb    r0, [r2, r1]\n"
"    movs    r0, r0\n"
"    ldrb    r1, [r7, #0xd]\n"
"    lsls    r6, r1, #4\n"
"    ldrb    r3, [r4, #0x11]\n"
"    lsls    r6, r1, #4\n"
"    ldrb    r5, [r6, #9]\n"
"    lsls    r6, r1, #4\n"
"    ldrb    r3, [r2, #0x16]\n"
"    lsls    r6, r1, #4\n"
"    ldrb    r3, [r5, #0xd]\n"
"    lsls    r6, r1, #4\n"
"    ldr     r5, [r1, #0x74]\n"
"    ldr     r5, [r6, #0x64]\n"
"    str     r4, [r6, #0x54]\n"
"    cmp     r6, #0x72\n"
"    lsls    r3, r4, #1\n"
"    movs    r0, r0\n"
"loc_fc357470:\n"
"    movs    r4, #1\n"
"    mov     r8, r0\n"
"    mov     r6, r2\n"
"loc_fc357476:\n"
"    movs    r0, #2\n"
"    bl      _exmem_ufree\n"
"    cbnz    r4, loc_fc3574a0\n"
"    ldr     r1, [r5, #0x64]\n"
"    mov.w   r8, #0\n"
"    mov     r0, sl\n"
"    blx     r1\n"
"    mov     r6, r0\n"
"    b       loc_fc3574a0\n"
"    b       loc_fc357492\n"
"loc_fc35748e:\n"
"    movs    r6, #0x40\n"
"    b       loc_fc3574a0\n"
"loc_fc357492:\n"
"    movw    r2, #0x683\n"
"    ldr     r1, =0xfc357464\n" //  *"Mounter.c"
"    movs    r0, #0\n"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc3574a0:\n"
"    strd    r6, sb, [r5, #0x48]\n"
"    movs    r0, #1\n"
"    str.w   r8, [r5, #0x44]\n"
"    b       loc_fc3573c8\n" //  return
    );
}

/*
    *** TEMPORARY? workaround ***
    Init stuff to avoid asserts on cameras running DryOS r54+
    https://chdk.setepontos.com/index.php?topic=12516.0
    Execute this only once
 */
void init_required_fw_features(void) {
    extern void _init_focus_eventflag();
    extern void _init_nd_eventflag();
//    extern void _init_nd_semaphore();
    //extern void _init_zoom_semaphore(); // for MoveZoomLensWithPoint

    _init_focus_eventflag();
    _init_nd_eventflag();
    // for MoveIrisWithAv, based on fc3d1a74 (but without registers eventprocs)
    extern int av_override_semaphore;
    extern int _CreateBinarySemaphoreStrictly(int x, int y);
    av_override_semaphore = _CreateBinarySemaphoreStrictly(0,0);
//    _init_nd_semaphore();
}

// jogdial override code called from kbd task
// -f=chdk -s=kbd_p2_f -c=77
// kbd_p2_f 0xfc077e8d
void __attribute__((naked,noinline)) kbd_p2_f_my() {
    asm volatile(
"    push.w  {r4, r5, r6, r7, r8, lr}\n"
"    ldr     r6, =0x00036c34\n"
"    sub     sp, #0x18\n"
"    add     r7, sp, #8\n"
"    subs    r6, #0xc\n"
"    b       loc_fc077ece\n"
"loc_fc077e9a:\n"
"    ldr     r1, =0x00036c34\n"
"    add     r3, sp, #8\n"
"    ldrb.w  r0, [sp, #4]\n"
"    add     r2, sp, #0x14\n"
"    subs    r1, #0x18\n"
"    bl      sub_fc0760c4\n"
"    cbnz    r0, loc_fc077eb4\n"
"    ldr     r1, [sp, #0x14]\n"
"    movs    r0, #0\n"
"    bl      sub_fc077dfe\n"
"loc_fc077eb4:\n"
"    movs    r0, #2\n"
"loc_fc077eb6:\n"
"    ldr.w   r1, [r7, r0, lsl #2]\n"
"    cbz     r1, loc_fc077ec6\n"
"    ldr.w   r2, [r6, r0, lsl #2]\n"
"    bics    r2, r1\n"
"    str.w   r2, [r6, r0, lsl #2]\n"
"loc_fc077ec6:\n"
"    subs    r0, r0, #1\n"
"    sxtb    r0, r0\n"
"    cmp     r0, #0\n"
"    bge     loc_fc077eb6\n"
"loc_fc077ece:\n"
"    ldr     r0, =0x00036c34\n"
"    add     r1, sp, #4\n"
"    subs    r0, #0xc\n"
"    bl      sub_fc075dc4\n"
"    cmp     r0, #0\n"
"    bne     loc_fc077e9a\n"
"    ldr.w   r8, =0x00036c34\n"
"    movs    r4, #0\n"
"loc_fc077ee2:\n"
"    movs    r5, #0\n"
"    ldr.w   r0, [r6, r4, lsl #2]\n"
"    ldr.w   r1, [r8, r4, lsl #2]\n"
"    ands    r0, r1\n"
"    str.w   r0, [r6, r4, lsl #2]\n"
"    b       loc_fc077f3a\n"
"loc_fc077ef4:\n"
"    lsrs    r0, r5\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc077f32\n"
"    ldr     r1, =0x00036c34\n"
"    add.w   r0, r5, r4, lsl #5\n"
"    add     r3, sp, #8\n"
"    subs    r1, #0x18\n"
"    add     r2, sp, #0x14\n"
"    uxtb    r0, r0\n"
"    bl      sub_fc0760c4\n"
"    cbnz    r0, loc_fc077f16\n"
"    ldr     r1, [sp, #0x14]\n"
"    movs    r0, #1\n"
"    bl      sub_fc077dfe\n"
"loc_fc077f16:\n"
"    mov     r0, r4\n"
"    b       loc_fc077f2e\n"
"loc_fc077f1a:\n"
"    ldr.w   r1, [r7, r0, lsl #2]\n"
"    cbz     r1, loc_fc077f2a\n"
"    ldr.w   r2, [r6, r0, lsl #2]\n"
"    bics    r2, r1\n"
"    str.w   r2, [r6, r0, lsl #2]\n"
"loc_fc077f2a:\n"
"    adds    r0, r0, #1\n"
"    sxtb    r0, r0\n"
"loc_fc077f2e:\n"
"    cmp     r0, #3\n"
"    blt     loc_fc077f1a\n"
"loc_fc077f32:\n"
"    ldr.w   r0, [r6, r4, lsl #2]\n"
"    adds    r5, r5, #1\n"
"    uxtb    r5, r5\n"
"loc_fc077f3a:\n"
"    cmp     r0, #0\n"
"    bne     loc_fc077ef4\n"
"    adds    r4, r4, #1\n"
"    sxtb    r4, r4\n"
"    cmp     r4, #3\n"
"    blt     loc_fc077ee2\n"
"    bl      sub_fc075c6e_my\n" // ->
"    add     sp, #0x18\n"
"    pop.w   {r4, r5, r6, r7, r8, pc}\n"
".ltorg\n"
    );
}

//  -f=chdk -s=0xfc075c6f -c=13
void __attribute__((naked,noinline)) sub_fc075c6e_my() {
    asm volatile(
"    push    {r4, lr}\n"
"    ldr     r4, =0x00009800\n"
"    ldr     r0, [r4, #0xc]\n"
"    bl      sub_fc0771f0\n"
"    ldr     r0, [r4, #0x10]\n"
"    bl      sub_fc07727a\n"
"    bl      sub_fc0f8224\n"
"    ldr     r0, [r4, #0x14]\n"
"    bl      sub_fc07710c\n"
"    ldr     r0, [r4, #0x18]\n"
"    bl      sub_fc07710c\n"
// re-ordered
//"    pop.w   {r4, lr}\n"
//"    b.w     loc_fc0774e4\n"
"    bl      handle_jogdial\n"  // +
"    cmp     r0, #0\n"          // +
"    beq     no_scroll\n"       // +
"    bl      sub_fc0774e4\n"    // handles scrollwheel(s), void function, no args
"no_scroll:\n"                  // +
"    pop     {r4, pc}\n"        // +
".ltorg\n"
    );
}
