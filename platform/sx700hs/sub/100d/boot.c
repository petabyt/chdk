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
//extern void task_LiveImageTask();
extern void task_ExpDrv();

extern void handle_jogdial();


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
//    *(int*)0xd20b0994 = 0x4d0002;

    _CreateTask("SpyTask", 0x19, 0x2000, spytask, 0);
}

//unsigned rbval=0;
void task_blinker()
{
#if 0
    unsigned v=*(volatile unsigned *)(0x9808);
    unsigned pat=0;
    if(v & 0x80000){
        pat |=1;
    }
    if(v & 0x100000){
        pat |=2;
    }
    if(v & 0x200000){
        pat |=4;
    }
    if(v & 0x400000){
        pat |=8;
    }
    if(v & 0x800000){
        pat |=0x10;
    }
    while(1) {
        int i;
        for(i=0;i<5;i++) {
            *(volatile int*)0xd20b0994 = 0x4d0002;
            if((pat >> i) & 1) {
                msleep(1000);
            } else {
                msleep(250);
            }
            *(volatile int*)0xd20b0994 = 0x4c0003;
            msleep(500);
        }
        msleep(5000);
    }
#endif
#if 0
    int delay=1000;
    if(rbval == 0x12345678) {
        delay=100;
    }
    while(1) {
        *(volatile int*)0xd20b0994 = 0x4d0002;
        msleep(delay);
        *(volatile int*)0xd20b0994 = 0x4c0003;
        msleep(delay);
    }
#endif
    while(1) {
        *(volatile int*)0xd20b0994 = 0x4d0002;
        msleep(250);
        *(volatile int*)0xd20b0994 = 0x4c0003;
        msleep(250);
    }
}

void CreateTask_blinker()
{
    _CreateTask("blinker", 0x19, 0x200, task_blinker, 0);
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
// -f=chdk -s=0xfc02000d -c=33
void __attribute__((naked,noinline)) boot() {
    asm volatile (
"    ldr.w   sp, =0x80010000\n"
"    bl      sub_fc020064\n"
"    ldr     r2, =0xc0242010\n"
"    ldr     r1, [r2]\n"
"    orr     r1, r1, #1\n"
"    str     r1, [r2]\n"
"    ldr     r0, =0xfcc64f9c\n"
"    ldr     r1, =0x010c1000\n"
"    ldr     r3, =0x010df808\n"
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
"    ldr     r0, =0x010c1000\n"
"    ldr     r1, =0x0001e808\n"
"    bl      sub_fc1194ee\n"
"    ldr     r0, =0xfcc3dfc0\n"
"    ldr     r1, =0x00008000\n"
"    ldr     r3, =0x0002efdc\n"
"loc_fc020040:\n"
"    cmp     r1, r3\n"
"    itt     lo\n"
"    ldrlo   r2, [r0], #4\n"
"    strlo   r2, [r1], #4\n"
"    blo     loc_fc020040\n"
"    ldr     r3, =0x0002efdc\n"
"    ldr     r1, =0x0035bb28\n"
"    mov.w   r2, #0\n"
"loc_fc020056:\n"
"    cmp     r3, r1\n"
"    it      lo\n"
"    strlo   r2, [r3], #4\n"
"    blo     loc_fc020056\n"
//"    b.w     loc_fc05d050\n"
"    b.w     sub_fc05d050_my\n"
        "patch_CreateTask:\n"
        "ldr.w   pc, [pc,#0]\n"             // Do jump to absolute address CreateTask_my
        ".long   CreateTask_my + 1\n"           // has to be a thumb address
    );
}

/*************************************************************/
void __attribute__((naked,noinline)) CreateTask_my() {
//    *(int*)0xd20b0994 = 0x4d0002;
asm volatile (
"    push   {r0}\n"
//R3 = Pointer to task function to create

"    ldr     r0, =task_CaptSeq\n"       // DryOS original code function ptr.
"    cmp     r0, r3\n"                  // is the given taskptr equal to our searched function?
"    itt     eq\n"                      // EQ block
"    ldreq   r3, =capt_seq_task\n"      // if so replace with our task function base ptr.
"    orreq   r3, #1\n"                  // make sure it's a thumb address (may not be needed?)
"    beq     exitHook\n"                // below compares not necessary if this check has found something.


// Appears to not be needed for sx700hs

#if 0
"    LDR     R0, =task_ExpDrv\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =exp_drv_task\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"
#endif

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
// Execute overwritten instructions from original code, then jump to firmware
// NOTE number of instructions duplicated here depends on size of original ROM code
// instructions. Must replace 8 bytes!
"    stmdb   sp!, {r1, r2, r3, r4, r5, r6, r7, r8, r9, lr}\n"
"    mov     r4, r0\n"
"    ldr     r0, =0x0000815c\n"
"    ldr.w   pc, =(hook_CreateTask + 8 + 1) \n"  // Continue in firmware
".ltorg\n"
);
 
}

// -f=chdk -s=0xfc05d051 -c=60
void __attribute__((naked,noinline)) sub_fc05d050_my() {
    asm volatile (
"    push    {r4, lr}\n"
#if defined(CHDK_NOT_IN_CANON_HEAP)
    "ldr     r4, =0x0035bb28\n"         // heap start, modify here
#else
    "ldr     r4, =new_sa\n"             // +
    "ldr     r4, [r4]\n"                // +
#endif
"    sub     sp, #0x78\n"
"    ldr     r0, =0x006ce000\n"
"    ldr     r1, =0x0008fd8c\n"
"    subs    r0, r0, r4\n"
"    cmp     r0, r1\n"
"    bhs     loc_fc05d062\n"
"loc_fc05d060:\n"
"    b       loc_fc05d060\n"
"loc_fc05d062:\n"
"    ldr     r1, =0x00008074\n"
"    mov.w   r0, #0x80000\n"
"    str     r0, [r1]\n"
"    ldr     r1, =0x00008078\n"
"    ldr     r0, =0x42a21000\n"
"    str     r0, [r1]\n"
"    ldr     r1, =0x0000807c\n"
"    ldr     r0, =0x42a23000\n"
"    str     r0, [r1]\n"
"    movs    r1, #0x78\n"
"    mov     r0, sp\n"
"    blx     sub_fc29b568\n" // j_bzero
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
//"    ldr     r1, =0xfc05d1e1\n"
    "ldr     r1, =sub_fc05d1e0_my\n"    // HHH -> continue here (init_task)
"    asrs    r0, r0, #4\n"
"    str     r0, [sp, #0x64]\n"
"    lsls    r0, r0, #5\n"
"    str     r0, [sp, #0x68]\n"
"    mov     r0, sp\n"
"    blx     sub_fc29abb0\n"
"    add     sp, #0x78\n"
"    pop     {r4, pc}\n"
    ".ltorg\n"

    );


}


//fc04f324?  -f=chdk -s=0xfc05d1e1 -c=54
void __attribute__((naked,noinline)) sub_fc05d1e0_my() {
    asm volatile (
"    push    {r4, lr}\n"
"    ldr     r4, =0xfc05d28c\n" //  *"/_term"
"    bl      sub_fc05e4a8\n"
"    ldr     r0, =0x000080ec\n"
"    ldr     r1, [r0]\n"
"    ldr     r0, =0x00008074\n"
"    ldr     r0, [r0]\n"
"    adds    r0, #0x10\n"
"    cmp     r1, r0\n"
"    bhs     loc_fc05d1fc\n"
"    ldr     r0, =0xfc05d29c\n" //  *"USER_MEM size checking"
"    bl      sub_fc05d274\n"
"loc_fc05d1fc:\n"
"    bl      sub_fc1195c8\n"
"    ldr     r3, =0x80000800\n"
// bad capdis output
//"    mov.w   r1, #-0x80000000\n"
//"    mov.w   r2, #-0x11111112\n"
    "mov.w   r1, #0x80000000\n" //2147483648
    "mov.w   r2, #0xeeeeeeee\n"
"loc_fc05d20a:\n"
"    stm     r1!, {r2}\n"
"    cmp     r1, r3\n"
"    blo     loc_fc05d20a\n"
"    bl      sub_fc1195da\n"
"    bl      sub_fc11961c\n"
"    cmp     r0, #0\n"
"    bge     loc_fc05d222\n"
"    ldr     r0, =0xfc05d2b8\n" //  *"dmSetup"
"    bl      sub_fc05d274\n"
"loc_fc05d222:\n"
"    bl      sub_fc05da54\n"
"    cmp     r0, #0\n"
"    bge     loc_fc05d230\n"
"    ldr     r0, =0xfc05d2c0\n" //  *"termDriverInit"
"    bl      sub_fc05d274\n"
"loc_fc05d230:\n"
"    mov     r0, r4\n"
"    bl      sub_fc05dae8\n"
"    cmp     r0, #0\n"
"    bge     loc_fc05d240\n"
"    ldr     r0, =0xfc05d2d0\n" //  *"termDeviceCreate"
"    bl      sub_fc05d274\n"
"loc_fc05d240:\n"
"    mov     r0, r4\n"
"    bl      sub_fc05d418\n"
"    cmp     r0, #0\n"
"    bge     loc_fc05d250\n"
"    ldr     r0, =0xfc05d2e4\n" //  *"stdioSetup"
"    bl      sub_fc05d274\n"
"loc_fc05d250:\n"
"    bl      sub_fc05d55c\n"
"    cmp     r0, #0\n"
"    bge     loc_fc05d25e\n"
"    ldr     r0, =0xfc05d2f0\n" //  *"stdlibSetup"
"    bl      sub_fc05d274\n"
"loc_fc05d25e:\n"
"    bl      sub_fc060920\n"
"    cmp     r0, #0\n"
"    bge     loc_fc05d26c\n"
"    ldr     r0, =0xfc05d2fc\n" //  *"extlib_setup"
"    bl      sub_fc05d274\n"
"loc_fc05d26c:\n"
"    pop.w   {r4, lr}\n"
"    b.w     sub_fc05d5e6_my\n"
    ".ltorg\n"
    );
}

// -f=chdk -s=0xfc05d5e7 -c=27
void __attribute__((naked,noinline)) sub_fc05d5e6_my() {
    asm volatile (
"    push    {r3, lr}\n"
"    bl      sub_fc05d700\n"
"    bl      sub_fc0a6f3c\n"
"    cbnz    r0, loc_fc05d5fc\n"
"    bl      sub_fc07bf42\n" // IsNormalCameraMode_FW
"    cbz     r0, loc_fc05d5fc\n"
"    movs    r0, #1\n"
"    b       loc_fc05d5fe\n"
"loc_fc05d5fc:\n"
"    movs    r0, #0\n"
"loc_fc05d5fe:\n"
"    bl      sub_fc07a1f0\n"
"    cbnz    r0, loc_fc05d60a\n"
"    bl      sub_fc05d6ee\n"
"loc_fc05d608:\n"
"    b       loc_fc05d608\n"
"loc_fc05d60a:\n"
"    blx     sub_fc29ac08\n"
"    ldr     r1, =0x006ce000\n"
"    movs    r0, #0\n"
"    bl      sub_fc30f8b8\n"
"    blx     sub_fc29b160\n"
"    movs    r3, #0\n"
"    str     r3, [sp]\n"
//"    ldr     r3, =0xfc05d581\n" //  task_Startup
    "ldr     r3, =task_Startup_my\n"
"    movs    r2, #0\n"
"    movs    r1, #0x19\n"
"    ldr     r0, =0xfc05d638\n" //  *"Startup"
//"    blx     sub_fc29b190\n" // j_CreateTask
"    bl      _CreateTask\n"
"    movs    r0, #0\n"
"    pop     {r3, pc}\n"
    ".ltorg\n"
    );

}



// task_Startup
//  -f=chdk -s=task_Startup -c=26
//"    ldr     r3, =0xfc05f3f1\n" //  task_Startup
void __attribute__((naked,noinline)) task_Startup_my() {
    asm volatile (
"    push    {r4, lr}\n"
"    bl      sub_fc11a940\n"
"    bl      sub_fc05d6cc\n"
//"    bl      sub_fc05d84c\n" //  nullsub
"    bl      sub_fc0c8f3c\n"
"bl sub_fc0945b5\n" // sd reset, see fc09461e task_SD1stInit
//"    bl      sub_fc05d8a2\n"  // StartDiskboot
"    bl      sub_fc0871d2\n"
"    bl      sub_fc11a9d8\n"
"    bl      sub_fc05d994\n"
"    bl      sub_fc05d7e0\n"
"    bl      sub_fc0c8f7a\n"
"    bl      sub_fc0a6c8c\n"
"    bl      sub_fc11a9de\n"
//"    bl      sub_fc07a0e2\n"
"    bl      sub_fc07a0e2_my\n" // create physw
"    bl      CreateTask_spytask\n"
"    bl      init_required_fw_features\n"
//"    bl      CreateTask_blinker\n"
"    bl      sub_fc25b37c\n"
"    bl      sub_fc11a9f4\n"
"    bl      sub_fc0a6c28\n"
"    bl      sub_fc11a6f8\n"
"    bl      sub_fc0a6dec\n"
"    bl      sub_fc0c8eee\n"
"    bl      sub_fc11a6b4\n"
"    bl      sub_fc05d998\n"
"    bl      sub_fc300f40\n"
"    bl      sub_fc11a688\n"
"    pop.w   {r4, lr}\n"
//"    b.w     loc_fc11a916\n"
"    ldr     pc,=0xfc11a917\n"
    ".ltorg\n"
    );
}

//taskcreate_physw  -f=chdk -s=0xfc07a0e3 -c=18
void __attribute__((naked,noinline)) sub_fc07a0e2_my() {
//    *(int*)0xd20b0994 = 0x4d0002;
    asm volatile (
"    push    {r3, r4, r5, lr}\n"
"    bl      sub_fc06f9d4\n"
"    bl      sub_fc07bec0\n" // IsFactoryMode_FW
"    cbnz    r0, loc_fc07a0f2\n"
"    bl      sub_fc06f978\n" // OpLog.Start_FW
"loc_fc07a0f2:\n"
"    ldr     r4, =0x000082c8\n" //  physw_run
"    ldr     r0, [r4, #4]\n"
"    cmp     r0, #0\n"
"    bne     loc_fc07a10e\n"
"    movs    r3, #0\n"
"    str     r3, [sp]\n"
//"    ldr     r3, =0xfc07a0bd\n" //  task_PhySw
       "    ldr     r3, =mykbd_task\n"
"    movs    r1, #0x17\n"
"    ldr     r0, =0xfc07a13c\n" //  *"PhySw"
//"    movw    r2, #0x800\n"
"    movw    r2, #0x2000\n" // increased stack size
"    blx     sub_fc29b450\n" // j_CreateTaskStrictly
"    str     r0, [r4, #4]\n"
"loc_fc07a10e:\n"
"    pop     {r3, r4, r5, pc}\n"
	".ltorg\n"
    );
}

 //-f=chdk -s=task_InitFileModules -c=16
// task_InitFileModules 0xfc0aa0f9
void __attribute__((naked,noinline)) init_file_modules_task() { 
    asm volatile (
"    push    {r4, r5, r6, lr}\n"
"    bl      sub_fc0ac1bc\n"
"    movs    r4, r0\n"
"    movw    r5, #0x5006\n"
"    beq     loc_fc0aa10e\n"
"    movs    r1, #0\n"
"    mov     r0, r5\n"
"    bl      _PostLogicalEventToUI\n"
"loc_fc0aa10e:\n"
"    bl      sub_fc0ac1e6\n"
"    BL      core_spytask_can_start\n" // + CHDK: Set "it's-safe-to-start" flag for spytask
"    cmp     r4, #0\n"
"    bne     loc_fc0aa122\n"
"    mov     r0, r5\n"
"    pop.w   {r4, r5, r6, lr}\n"
"    movs    r1, #0\n"
"    b.w     _PostLogicalEventToUI\n"
"loc_fc0aa122:\n"
"    pop     {r4, r5, r6, pc}\n"
"    .ltorg\n"
    );

}


#ifdef CAM_HAS_JOGDIAL
// jogdial override code called from kbd task
// sx700v100d -f=chdk -s=kbd_p2_f -c=77
// kbd_p2_f 0xfc079e89
void __attribute__((naked,noinline)) kbd_p2_f_my() { 
   asm volatile(
"    push.w  {r4, r5, r6, r7, r8, lr}\n"
"    ldr     r6, =0x000308d4\n"
"    sub     sp, #0x18\n"
"    add     r7, sp, #8\n"
"    subs    r6, #0xc\n"
"    b       loc_fc079eca\n"
"loc_fc079e96:\n"
"    ldr     r1, =0x000308d4\n"
"    add     r3, sp, #8\n"
"    ldrb.w  r0, [sp, #4]\n"
"    add     r2, sp, #0x14\n"
"    subs    r1, #0x18\n"
"    bl      sub_fc06e51c\n"
"    cbnz    r0, loc_fc079eb0\n"
"    ldr     r1, [sp, #0x14]\n"
"    movs    r0, #0\n"
"    bl      sub_fc079dfa\n"
"loc_fc079eb0:\n"
"    movs    r0, #2\n"
"loc_fc079eb2:\n"
"    ldr.w   r1, [r7, r0, lsl #2]\n"
"    cbz     r1, loc_fc079ec2\n"
"    ldr.w   r2, [r6, r0, lsl #2]\n"
"    bics    r2, r1\n"
"    str.w   r2, [r6, r0, lsl #2]\n"
"loc_fc079ec2:\n"
"    subs    r0, r0, #1\n"
"    sxtb    r0, r0\n"
"    cmp     r0, #0\n"
"    bge     loc_fc079eb2\n"
"loc_fc079eca:\n"
"    ldr     r0, =0x000308d4\n"
"    add     r1, sp, #4\n"
"    subs    r0, #0xc\n"
"    bl      sub_fc06e268\n"
"    cmp     r0, #0\n"
"    bne     loc_fc079e96\n"
"    ldr.w   r8, =0x000308d4\n"
"    movs    r4, #0\n"
"loc_fc079ede:\n"
"    movs    r5, #0\n"
"    ldr.w   r0, [r6, r4, lsl #2]\n"
"    ldr.w   r1, [r8, r4, lsl #2]\n"
"    ands    r0, r1\n"
"    str.w   r0, [r6, r4, lsl #2]\n"
"    b       loc_fc079f36\n"
"loc_fc079ef0:\n"
"    lsrs    r0, r5\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc079f2e\n"
"    ldr     r1, =0x000308d4\n"
"    add.w   r0, r5, r4, lsl #5\n"
"    add     r3, sp, #8\n"
"    subs    r1, #0x18\n"
"    add     r2, sp, #0x14\n"
"    uxtb    r0, r0\n"
"    bl      sub_fc06e51c\n"
"    cbnz    r0, loc_fc079f12\n"
"    ldr     r1, [sp, #0x14]\n"
"    movs    r0, #1\n"
"    bl      sub_fc079dfa\n"
"loc_fc079f12:\n"
"    mov     r0, r4\n"
"    b       loc_fc079f2a\n"
"loc_fc079f16:\n"
"    ldr.w   r1, [r7, r0, lsl #2]\n"
"    cbz     r1, loc_fc079f26\n"
"    ldr.w   r2, [r6, r0, lsl #2]\n"
"    bics    r2, r1\n"
"    str.w   r2, [r6, r0, lsl #2]\n"
"loc_fc079f26:\n"
"    adds    r0, r0, #1\n"
"    sxtb    r0, r0\n"
"loc_fc079f2a:\n"
"    cmp     r0, #3\n"
"    blt     loc_fc079f16\n"
"loc_fc079f2e:\n"
"    ldr.w   r0, [r6, r4, lsl #2]\n"
"    adds    r5, r5, #1\n"
"    uxtb    r5, r5\n"
"loc_fc079f36:\n"
"    cmp     r0, #0\n"
"    bne     loc_fc079ef0\n"
"    adds    r4, r4, #1\n"
"    sxtb    r4, r4\n"
"    cmp     r4, #3\n"
"    blt     loc_fc079ede\n"
//"    bl      sub_fc06e104\n"
"    bl      sub_fc06e104_my\n" // --->>
"    add     sp, #0x18\n"
"    pop.w   {r4, r5, r6, r7, r8, pc}\n"
".ltorg\n"
    );
}

//extern void handle_jogdial();
//sx700100d -f=chdk -s=0xfc06e105 -c=9
void __attribute__((naked,noinline)) sub_fc06e104_my() {
    asm volatile(
"    push    {r4, lr}\n"
"    ldr     r4, =0x00009334\n"
"    ldr     r0, [r4, #8]\n"
"    bl      sub_fc070a80\n"
"    bl      sub_fc0e4168\n"
"    ldr     r0, [r4, #0xc]\n"
"    bl      sub_fc07099c\n"
//"    pop.w   {r4, lr}\n"      // - (reordered below)
//"    b.w     loc_fc06bf5e\n"  // - (reordered below)
"    bl      handle_jogdial\n"  // +
"    cmp     r0, #0\n"          // +
"    beq     no_scroll\n"       // +
"    bl      sub_fc06bf5e\n"    // handles scrollwheel(s), void function, no args
"no_scroll:\n"                  // +
"    pop     {r4, pc}\n"        // +
".ltorg\n"
    );
}
#endif
