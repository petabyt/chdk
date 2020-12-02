#include "lolevel.h"
#include "platform.h"
#include "core.h"
//#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

// Forward declarations
extern volatile int jogdial_stopped;
void JogDial_task_my(void);

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_RotaryEncoder();
extern void task_MovieRecord();
extern void task_LiveImageTask();
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
//    *(int*)0xd20b0884 = 0x4d0002;

    _CreateTask("SpyTask", 0x19, 0x2000, spytask, 0);
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
//   extern void _init_nd_semaphore();
    //extern void _init_zoom_semaphore(); // for MoveZoomLensWithPoint

    _init_focus_eventflag();
    _init_nd_eventflag();
    // for MoveIrisWithAv, based on fc3d1a74 (but without registers eventprocs)
    extern int av_override_semaphore;
    extern int _CreateBinarySemaphoreStrictly(int x, int y);
    av_override_semaphore = _CreateBinarySemaphoreStrictly(0,0);
//    _init_nd_semaphore();
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
//    *(int*)0xd20b0884 = 0x4d0002;
    asm volatile ( // 0xfc02000c
"    ldr.w   sp, =0x80010000\n"
"    bl      sub_fc020064\n" 
"    ldr     r2, =0xc0242010\n"
"    ldr     r1, [r2]\n"
"    orr     r1, r1, #1\n"
"    str     r1, [r2]\n"
"    ldr     r0, =0xfcd16b8c\n"
"    ldr     r1, =0x010e1000\n"
"    ldr     r3, =0x0110daa4\n"
"loc_fc020024:\n"
"    cmp     r1, r3\n"
"    itt     lo\n"
"    ldrlo   r2, [r0], #4\n"
"    strlo   r2, [r1], #4\n"
"    blo     loc_fc020024\n"
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
"    ldr     r1, =0x0002caa4\n"
"    bl      sub_fc1361ce\n" 
"    ldr     r0, =0xfccec580\n"
"    ldr     r1, =0x00008000\n"
"    ldr     r3, =0x0003260c\n"
"loc_fc020040:\n"
"    cmp     r1, r3\n"
"    itt     lo\n"
"    ldrlo   r2, [r0], #4\n"
"    strlo   r2, [r1], #4\n"
"    blo     loc_fc020040\n"
"    ldr     r3, =0x0003260c\n"
"    ldr     r1, =0x003a8bb0\n"
"    mov.w   r2, #0\n"
"loc_fc020056:\n"
"    cmp     r3, r1\n"
"    it      lo\n"
"    strlo   r2, [r3], #4\n"
"    blo     loc_fc020056\n"
//"    b.w     loc_fc05eec0\n"
"    b.w     sub_fc05eec0_my\n" // continue 

        "patch_CreateTask:\n"
        "ldr.w   pc, [pc,#0]\n"             // Do jump to absolute address CreateTask_my
        ".long   CreateTask_my + 1\n"           // has to be a thumb address

 
);
}

/*************************************************************/
void __attribute__((naked,noinline)) CreateTask_my() {
//    *(int*)0xd20b0884 = 0x4d0002;
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
/*
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
"    itt     eq\n"
"    LDREQ   R3, =movie_record_task\n"
"    BEQ     exitHook\n"

"    LDR     R0, =task_LiveImageTask\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =liveimage_task\n"
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
/*                        // turn led on
                        "push    {r4-r5}\n"
                        "ldr r4, =0x4d0002\n"
                        "ldr r5, =0xd20b0884\n"
                        "str r4, [r5]\n"
                        "pop     {r4-r5}\n"
 */                   
// Execute overwritten instructions from original code, then jump to firmware
"    stmdb   sp!, {r1, r2, r3, r4, r5, r6, r7, r8, r9, lr}\n"
//"    push.w  {r1, r2, r3, r4, r5, r6, r7, r8, sb, lr}\n"
"    mov     r4, r0\n"
"    ldr     r0, =0x8160\n" //at fc05f1b0
//"    mov     r6, r1\n"
//"    mov     r5, r2\n"
"    ldr.w   pc, =(hook_CreateTask + 8 + 1) \n"  // Continue in firmware
".ltorg\n"
);
 
}

//fc04f194 fc05eec0
void __attribute__((naked,noinline)) sub_fc05eec0_my() {
//*(int*)0xd20b0884 = 0x4d0002;

/* no gpio checks needed    if (*(int*)(0xd20b0000 + 0x10 * 4) & 0x10000) {
        // see sub_fc060338, sub_fc06082a
        // GPIO 0x10 (aka ON/OFF button) is not pressed -> play
        *(int*)(0x970c+0x4) = 0x200000;
    }
    else {
        // GPIO 0x10 is pressed -> rec
        *(int*)(0x970c+0x4) = 0x100000;
    }
*/
    asm volatile (
    "push    {r4, lr}\n"

#if defined(CHDK_NOT_IN_CANON_HEAP)
    "ldr     r4, =0x003a8bb0\n"         // heap start, modify here
#else
    "ldr     r4, =new_sa\n"             // +
    "ldr     r4, [r4]\n"                // +
#endif
"    sub     sp, #0x78\n"
"    ldr     r0, =0x006ce000\n"
"    ldr     r1, =0x0008fd8c\n"
"    subs    r0, r0, r4\n"
"    cmp     r0, r1\n"
"    bhs     loc_fc05eed2\n"
"loc_fc05eed0:\n"
"    b       loc_fc05eed0\n"
"loc_fc05eed2:\n"
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
"    blx     sub_fc2cf438\n" 
"    ldr     r0, =0x0062e000\n"
"    mov.w   r1, #0xa0000\n"
"    stm.w   sp, {r0, r1, r4}\n"
"    ldr     r1, =0x00622274\n" //  *"t"b"
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
//"    ldr     r1, =0xfc05f051\n"
    "ldr     r1, =sub_fc05f050_my\n"    // -> continue here (init_task)
"    asrs    r0, r0, #4\n"
"    str     r0, [sp, #0x64]\n"
"    lsls    r0, r0, #5\n"
"    str     r0, [sp, #0x68]\n"
"    mov     r0, sp\n"
"    blx     sub_fc2ce9a4\n" 
"    add     sp, #0x78\n"
"    pop     {r4, pc}\n"
    ".ltorg\n"

    );


}


//fc04f324
void __attribute__((naked,noinline)) sub_fc05f050_my() {

//*(int*)0xd20b0884 = 0x4d0002;
    asm volatile (
"    push    {r4, lr}\n"
"    ldr     r4, =0xfc05f0fc\n" //  *"/_term"
"    bl      sub_fc0602ec\n"
"    ldr     r0, =0x000080ec\n"
"    ldr     r1, [r0]\n"
"    ldr     r0, =0x00008074\n"
"    ldr     r0, [r0]\n"
"    adds    r0, #0x10\n"
"    cmp     r1, r0\n"
"    bhs     loc_fc05f06c\n"
"    ldr     r0, =0xfc05f10c\n" //  *"USER_MEM size checking"
"    bl      sub_fc05f0e4\n"
"loc_fc05f06c:\n"
"    bl      sub_fc1362a8\n"
"    ldr     r3, =0x80000800\n"
// bad capdis output
//  
    "mov.w   r1, #0x80000000\n" //2147483648
    "mov.w   r2, #0xeeeeeeee\n"
"loc_fc05f07a:\n"
"    stm     r1!, {r2}\n"
"    cmp     r1, r3\n"
"    blo     loc_fc05f07a\n"
"    bl      sub_fc1362ba\n" 
"    bl      sub_fc136890\n" 
"    cmp     r0, #0\n"
"    bge     loc_fc05f092\n"
"    ldr     r0, =0xfc05f128\n" //  *"dmSetup"
"    bl      sub_fc05f0e4\n"
"loc_fc05f092:\n"
"    bl      sub_fc05f8c4\n"  
"    cmp     r0, #0\n"
"    bge     loc_fc05f0a0\n"
"    ldr     r0, =0xfc05f130\n" //  *"termDriverInit"
"    bl      sub_fc05f0e4\n"
"loc_fc05f0a0:\n"
"    mov     r0, r4\n"
"    bl      sub_fc05f952\n" 
// led works here
"    cmp     r0, #0\n"
"    bge     loc_fc05f0b0\n" 
"    ldr     r0, =0xfc05f140\n" //  *"termDeviceCreate"
"    bl      sub_fc05f0e4\n"
"loc_fc05f0b0:\n"
"    mov     r0, r4\n"
"    bl      sub_fc05f288\n" 
// led works here
"    cmp     r0, #0\n"
"    bge     loc_fc05f0c0\n" 
"    ldr     r0, =0xfc05f154\n" //  *"stdioSetup"
"    bl      sub_fc05f0e4\n"
"loc_fc05f0c0:\n"
"    bl      sub_fc05f3cc\n" 
"    cmp     r0, #0\n"
"    bge     loc_fc05f0ce\n"
"    ldr     r0, =0xfc05f160\n" //  *"stdlibSetup"
"    bl      sub_fc05f0e4\n"
"loc_fc05f0ce:\n"
"    bl      sub_fc0623e8\n"
"    cmp     r0, #0\n"
"    bge     loc_fc05f0dc\n"
"    ldr     r0, =0xfc05f16c\n" //  *"extlib_setup"
"    bl      sub_fc05f0e4\n"
"loc_fc05f0dc:\n"
"    pop.w   {r4, lr}\n"
//"    b.w     sub_fc05f456\n"
    "b.w     sub_fc05f456_my\n" // -> continue (taskcreate_startup)
    ".ltorg\n"

    );

}

void __attribute__((naked,noinline)) sub_fc05f0e4_my() {

//*(int*)0xd20b0884 = 0x4d0002;
}
void __attribute__((naked,noinline)) sub_fc05f456_my() {
// turn on LED
 //   *(int*)0xd20b0884 = 0x4d0002;
       
    asm volatile (
"    push    {r3, lr}\n"
"    bl      sub_fc05f570\n" 
"    bl      sub_fc0b9738\n" 
"    cbnz    r0, loc_fc05f46c\n"
"    bl      sub_fc07f062\n" // is normal camera Mode_FW
"    cbz     r0, loc_fc05f46c\n"
"    movs    r0, #1\n"
"    b       loc_fc05f46e\n"
"loc_fc05f46c:\n"
    "movs    r0, #0\n"
"loc_fc05f46e:\n"
"    bl      sub_fc07319c\n" 
"    cbnz    r0, loc_fc05f47a\n"
"    bl      sub_fc05f55e\n" 
"loc_fc05f478:\n"
"    b       loc_fc05f478\n"
"loc_fc05f47a:\n"
"    blx     sub_fc2ce9fc\n"
"    ldr     r1, =0x006ce000\n"
"    movs    r0, #0\n"
"    bl      sub_fc3364fc\n" 
"    blx     sub_fc2cefd0\n"
"    movs    r3, #0\n"
"    str     r3, [sp]\n"
//"    ldr     r3, =0xfc05f3f1\n" //  task_Startup
    "ldr     r3, =task_Startup_my\n"
"    movs    r2, #0\n"
"    movs    r1, #0x19\n"
"    ldr     r0, =0xfc05f4a8\n" //  *"Startup"
 /*                       // ###### turn led on
                        "push    {r4-r5}\n"
                        "ldr r4, =0x4d0002\n"
                        "ldr r5, =0xd20b0884\n"
                        "str r4, [r5]\n"
                        "pop     {r4-r5}\n"
*/
//"    blx     sub_fc2cf018\n" // j_CreateTask
    "bl       _CreateTask\n"    // CreateTask
"    movs    r0, #0\n"
"    pop     {r3, pc}\n"
    ".ltorg\n"
    );
}

// override not needed
#if 0
void __attribute__((naked,noinline)) sub_fc07319c_my() {
    asm volatile (
    "stmdb   sp!, {r2, r3, r4, r5, r6, r7, r8, lr}\n"
    "mov.w   r8, #0\n"
    "mov     r7, r0\n"
    "mov     r6, r8\n"
    "bl      sub_fc0705ee\n" // nullsub
    "movs    r0, #16\n"
    "bl      sub_fc06fbde\n"
    "movs    r4, #1\n"
    "bic.w   r5, r4, r0\n"
    "movs    r0, #15\n"  
    "bl      sub_fc06fbde\n"    // reads GPIO (15)
    "bics    r4, r0\n"
    "cbz     r7, loc_fc0731f6\n"
    "orrs.w  r0, r5, r4\n"
    //"beq.n   loc_fc06037e\n"  // - this check fails and results in shutdown
    "loc_fc0731f6:\n"
    "bl      sub_fc0b9738\n"
    "movs    r3, #0\n"
    "mov     r2, r0\n"
    "strd    r8, r6, [sp]\n"
    "mov     r1, r4\n"
    "mov     r0, r5\n"
    //"bl      sub_fc06082a\n"  // - startupchecks
    //"bl      sub_fc060828\n"  // - nullsub
    "movs    r0, #1\n"
    "loc_fc073210:\n"
    "ldmia.w sp!, {r2, r3, r4, r5, r6, r7, r8, pc}\n"
    ".ltorg\n"
    );
}
#endif


// task_Startup
//"    ldr     r3, =0xfc05f3f1\n" //  task_Startup
void __attribute__((naked,noinline)) task_Startup_my() {
//    *(int*)0xd20b0884 = 0x4d0002;
    asm volatile (
"    push    {r4, lr}\n"
"    bl      sub_fc137ad4\n" // CreateTask ClockSave
"    bl      sub_fc05f53c\n" // posixSetup etc
//"    bl      sub_fc05f6bc\n"
"    bl      sub_fc0daedc\n" // StartWDT ...
"bl sub_010e6355\n" //see 0x010e63cc task_SD1stInit in RAMCODE.dis
//"    bl      sub_fc05f712\n"
"    bl      sub_fc08da46\n"
"    bl      sub_fc0db028\n"
"    bl      sub_fc05f804\n"
"    bl      sub_fc05f650\n"
"    bl      sub_fc0daf1a\n"
"    bl      sub_fc0b947c\n"
"    bl      sub_fc0db02e\n"
"    bl      sub_fc07308e_my\n"
"    bl      CreateTask_spytask\n"
"    bl      init_required_fw_features\n"
"    bl      sub_fc275708\n"
"    bl      sub_fc0db044\n"
"    bl      sub_fc0b9230\n"
"    bl      sub_fc13788e\n"
"    bl      sub_fc0b95e4\n"
"    bl      sub_fc0b942e\n"
"    bl      sub_fc13784a\n"
"    bl      sub_fc05f808\n"
"    bl      sub_fc32f656\n" 
"    bl      sub_fc13781e\n"
"    pop.w   {r4, lr}\n"
"    b.w     sub_fc137aaa\n"  
    ".ltorg\n"
    );
}
//taskcreate_physw
void __attribute__((naked,noinline)) sub_fc07308e_my() {
//    *(int*)0xd20b0884 = 0x4d0002;
    asm volatile (
"    push    {r3, r4, r5, lr}\n"
"    bl      sub_fc07202c\n"
"    bl      sub_fc07efe0\n" // IsFactoryMode_FW
"    cbnz    r0, loc_fc07309e\n"
"    bl      sub_fc071fd0\n" // OpLog.Start_FW
"loc_fc07309e:\n"
"    ldr     r4, =0x000082c8\n"
"    ldr     r0, [r4, #4]\n"
"    cmp     r0, #0\n"
"    bne     loc_fc0730ba\n"
"    movs    r3, #0\n"
"    str     r3, [sp]\n"
//"    ldr     r3, =0xfc073069\n" //  task_PhySw
	"ldr     r3, =mykbd_task\n"   // fix this!!
"    movs    r1, #0x17\n"
"    ldr     r0, =0xfc0730e8\n" //  *"PhySw"
"    movw    r2, #0x2000\n" // adjust upward?was 800
"    blx     sub_fc2cf340\n" // j_CreateTaskStrictly
/*                        // ###### turn led on
                        "push    {r4-r5}\n"
                        "ldr r4, =0x4d0002\n"
                        "ldr r5, =0xd20b0884\n"
                        "str r4, [r5]\n"
                        "pop     {r4-r5}\n"
*/
"    str     r0, [r4, #4]\n"
"loc_fc0730ba:\n"
"    pop     {r3, r4, r5, pc}\n"
			".ltorg\n"
    );
}

void __attribute__((naked,noinline)) init_file_modules_task() { //sub_fc088220_my()
//fc0bda11
// task_InitFileModules 0xfc0bda11
    asm volatile (
"    push    {r4, r5, r6, lr}\n"
"    bl      sub_fc0e5238\n"
"    movs    r4, r0\n"
"    movw    r5, #0x5006\n"
"    beq     loc_fc0bda26\n"
"    movs    r1, #0\n"
"    mov     r0, r5\n"
"    bl      _PostLogicalEventToUI\n"
"loc_fc0bda26:\n"
"    bl      sub_fc0e5262\n"
"    BL      core_spytask_can_start\n" // + CHDK: Set "it's-safe-to-start" flag for spytask
"    cmp     r4, #0\n"
"    bne     loc_fc0bda3a\n"
"    mov     r0, r5\n"
"    pop.w   {r4, r5, r6, lr}\n"
"    movs    r1, #0\n"
"    b.w     _PostLogicalEventToUI\n"
"loc_fc0bda3a:\n"
"    pop     {r4, r5, r6, pc}\n"
"    .ltorg\n"
    );

}


void __attribute__((naked,noinline)) kbd_p2_f_my() { 

// kbd_p2_f 0xfc072e35

   asm volatile(
"    stmdb   sp!, {r4, r5, r6, r7, r8, lr}\n"
//"    push.w  {r4, r5, r6, r7, r8, lr}\n"
"    ldr     r6, =0x00033f88\n"
"    sub     sp, #0x18\n"
"    add     r7, sp, #8\n"
"    subs    r6, #0xc\n"
"    b       loc_fc072e76\n"

"loc_fc072e42:\n"
"    ldr     r1, =0x00033f88\n"
"    add     r3, sp, #8\n"
"    ldrb.w  r0, [sp, #4]\n"
"    add     r2, sp, #0x14\n"
"    subs    r1, #0x18\n"
"    bl      sub_fc070b4e\n"
"    cbnz    r0, loc_fc072e5c\n"
"    ldr     r1, [sp, #0x14]\n"
"    movs    r0, #0\n"
"    bl      sub_fc072da6\n"

"loc_fc072e5c:\n"
"    movs    r0, #2\n"
"loc_fc072e5e:\n"
"    ldr.w   r1, [r7, r0, lsl #2]\n"
"    cbz     r1, loc_fc072e6e\n"
"    ldr.w   r2, [r6, r0, lsl #2]\n"
"    bics    r2, r1\n"
"    str.w   r2, [r6, r0, lsl #2]\n"
"loc_fc072e6e:\n"
"    subs    r0, r0, #1\n"
"    sxtb    r0, r0\n"
"    cmp     r0, #0\n"
"    bge     loc_fc072e5e\n"

"loc_fc072e76:\n"
"    ldr     r0, =0x00033f88\n"
"    add     r1, sp, #4\n"
"    subs    r0, #0xc\n"
"    bl      sub_fc07084c\n"
"    cmp     r0, #0\n"
"    bne     loc_fc072e42\n"
"    ldr.w   r8, =0x00033f88\n"
"    movs    r4, #0\n"
"loc_fc072e8a:\n"
"    movs    r5, #0\n"
"    ldr.w   r0, [r6, r4, lsl #2]\n"
"    ldr.w   r1, [r8, r4, lsl #2]\n"
"    ands    r0, r1\n"
"    str.w   r0, [r6, r4, lsl #2]\n"
"    b       loc_fc072ee2\n"
"loc_fc072e9c:\n"
"    lsrs    r0, r5\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc072eda\n"
"    ldr     r1, =0x00033f88\n"
"    add.w   r0, r5, r4, lsl #5\n"
"    add     r3, sp, #8\n"
"    subs    r1, #0x18\n"
"    add     r2, sp, #0x14\n"
"    uxtb    r0, r0\n"
"    bl      sub_fc070b4e\n"
"    cbnz    r0, loc_fc072ebe\n"
"    ldr     r1, [sp, #0x14]\n"
"    movs    r0, #1\n"
"    bl      sub_fc072da6\n"
"loc_fc072ebe:\n"
"    mov     r0, r4\n"
"    b       loc_fc072ed6\n"

"loc_fc072ec2:\n"
"    ldr.w   r1, [r7, r0, lsl #2]\n"
"    cbz     r1, loc_fc072ed2\n"
"    ldr.w   r2, [r6, r0, lsl #2]\n"
"    bics    r2, r1\n"
"    str.w   r2, [r6, r0, lsl #2]\n"
"loc_fc072ed2:\n"
"    adds    r0, r0, #1\n"
"    sxtb    r0, r0\n"
"loc_fc072ed6:\n"
"    cmp     r0, #3\n"
"    blt     loc_fc072ec2\n"
"loc_fc072eda:\n"
"    ldr.w   r0, [r6, r4, lsl #2]\n"
"    adds    r5, r5, #1\n"
"    uxtb    r5, r5\n"
"loc_fc072ee2:\n"
"    cmp     r0, #0\n"
"    bne     loc_fc072e9c\n"
"    adds    r4, r4, #1\n"
"    sxtb    r4, r4\n"
"    cmp     r4, #3\n"
"    blt     loc_fc072e8a\n"
//"    bl      sub_fc0706e8\n"
"    bl      sub_fc0706e8_my\n"     // ->
"    add     sp, #0x18\n"
"    pop.w   {r4, r5, r6, r7, r8, pc}\n"
".ltorg\n"
    );

}
//extern void handle_jogdial();
void __attribute__((naked,noinline)) sub_fc0706e8_my() {
    asm volatile(
"    push    {r4, lr}\n"
"    ldr     r4, =0x0000970c\n"
"    ldr     r0, [r4, #0xc]\n"
"    bl      sub_fc072250\n"
"    bl      sub_fc0f9118\n"
"    ldr     r0, [r4, #0x10]\n"
"    bl      sub_fc07216c\n"
//"    ldmia.w sp!, {r4, lr}\n" // - (reordered below)
//"    b.w     loc_fc05cbf6\n"  // - (reordered below)
"    bl      handle_jogdial\n"  // +
"    cmp     r0, #0\n"          // +
"    beq     no_scroll\n"       // +
"    bl      sub_fc072490\n"    // handles scrollwheel(s), void function, no args
"no_scroll:\n"                  // +
"    pop     {r4, pc}\n"        // +
    );
}

