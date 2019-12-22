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
extern void task_TricInitTask();

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
    _CreateTask("SpyTask", 0x19, 0x2000, spytask, 0);
}

//unsigned rbval=0;
/*
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
*/

/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/

/*************************************************************/
//  -f=chdk -s=0xfc02000d -c=43
void __attribute__((naked,noinline)) boot() {
    asm volatile ( // 0xfc02000c
"    movw    r0, #0x4000\n"
"    movt    r0, #0\n"
"    mov     sp, r0\n"
"    bl      sub_fc02007e\n"
"    ldr     r2, =0xc0242010\n"
"    ldr     r1, [r2]\n"
"    orr     r1, r1, #1\n"
"    str     r1, [r2]\n"
"    ldr     r0, =0xfcd4740c\n" // code copied from ROM
"    ldr     r1, =0x010e1000\n" // to RAM
"    ldr     r3, =0x01107bd0\n"
"loc_fc02002a:\n"
"    cmp     r1, r3\n"
"    itt     lo\n"
"    ldrlo   r2, [r0], #4\n"
"    strlo   r2, [r1], #4\n"
"    blo     loc_fc02002a\n"
"    ldr     r0, =0x010e1000\n"
"    ldr     r1, =0x00026bd0\n"
"    bl      sub_fc11f606\n"    // cache stuff for RAM code
"    ldr     r0, =0xfcd6dfdc\n" // code copied from ROM
"    ldr     r1, =0xbfe10800\n" // to TCM
"    ldr     r3, =0xbfe17419\n"
"loc_fc020046:\n"
"    cmp     r1, r3\n"
"    itt     lo\n"
"    ldrlo   r2, [r0], #4\n"
"    strlo   r2, [r1], #4\n"
"    blo     loc_fc020046\n"
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
"    ldr     r0, =0xfcd1e5b4\n"
"    ldr     r1, =0x00008000\n" // DATA copied
"    ldr     r3, =0x00030e58\n" // to RAM
"loc_fc02005a:\n"
"    cmp     r1, r3\n"
"    itt     lo\n"
"    ldrlo   r2, [r0], #4\n"
"    strlo   r2, [r1], #4\n"
"    blo     loc_fc02005a\n"
"    ldr     r3, =0x00030e58\n" // BSS
"    ldr     r1, =0x003c3998\n"
"    mov.w   r2, #0\n"
"loc_fc020070:\n"
"    cmp     r3, r1\n"
"    it      lo\n"
"    strlo   r2, [r3], #4\n"
"    blo     loc_fc020070\n"
"    b.w     sub_fc055894_my\n"

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

// exp_drv not needed for extended exposure, probably works up to 1024s, but required for < 1/3200
"    LDR     R0, =task_ExpDrv\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =exp_drv_task\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"

// not needed in sx710
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

// not implemented
/*
"    LDR     R0, =task_MovieRecord\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =movie_record_task\n"
"    BEQ     exitHook\n"
*/

"    ldr     r0, =task_TricInitTask\n"
"    cmp     r0, r3\n"
"    itt     eq\n"
"    ldreq   r3, =TricInitTask_my\n"
"    orreq   r3, #1\n"
"    beq     exitHook\n"

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

// -f=chdk -s=0xfc055895 -c=60
void __attribute__((naked,noinline)) sub_fc055894_my() {
// startup key checks handled in sub_fc0cf0ee_my
    asm volatile (
"    push    {r4, lr}\n"
#if defined(CHDK_NOT_IN_CANON_HEAP)
"    ldr     r4, =0x003c3998\n"
#else
    "ldr     r4, =new_sa\n"             // +
    "ldr     r4, [r4]\n"                // +
#endif
"    sub     sp, #0x78\n"
"    ldr     r0, =0x006ce000\n"
"    ldr     r1, =0x000b1fec\n"
"    subs    r0, r0, r4\n"
"    cmp     r0, r1\n"
"    bhs     loc_fc0558a6\n"
"loc_fc0558a4:\n"
"    b       loc_fc0558a4\n"
"loc_fc0558a6:\n"
"    ldr     r1, =0x00008074\n"
"    mov.w   r0, #0x80000\n"
"    str     r0, [r1]\n"
"    ldr     r1, =0x00008078\n"
"    ldr     r0, =0x421bcb00\n"
"    str     r0, [r1]\n"
"    ldr     r1, =0x0000807c\n"
"    ldr     r0, =0x421beb00\n"
"    str     r0, [r1]\n"
"    movs    r1, #0x78\n"
"    mov     r0, sp\n"
"    blx     sub_fc2c7d98\n" // j_bzero
"    ldr     r0, =0x0060e000\n"
"    mov.w   r1, #0xc0000\n"
"    stm.w   sp, {r0, r1, r4}\n"
"    ldr     r1, =0x00600014\n"
"    subs    r2, r1, r4\n"
"    strd    r2, r1, [sp, #0xc]\n"
"    str     r0, [sp, #0x14]\n"
"    movs    r0, #0x22\n"
"    str     r0, [sp, #0x18]\n"
"    movs    r0, #0xca\n"
"    str     r0, [sp, #0x1c]\n"
"    movw    r0, #0x2b0\n"
"    str     r0, [sp, #0x20]\n"
"    movs    r0, #0xfa\n"
"    str     r0, [sp, #0x24]\n"
"    movw    r0, #0x11a\n"
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
//"    ldr     r1, =0xfc055a25\n"
"    ldr     r1, =sub_fc055a24_my\n"
"    asrs    r0, r0, #4\n"
"    str     r0, [sp, #0x64]\n"
"    lsls    r0, r0, #5\n"
"    str     r0, [sp, #0x68]\n"
"    mov     r0, sp\n"
"    blx     sub_fc2c755c\n"
"    add     sp, #0x78\n"
"    pop     {r4, pc}\n"
".ltorg\n"
    );
}

//  -f=chdk -s=0xfc055a25 -c=62
void __attribute__((naked,noinline)) sub_fc055a24_my() {
    asm volatile (
"    push    {r4, lr}\n"
"    ldr     r4, =0xfc055acc\n" //  *"/_term"
"    bl      sub_fc056cc8\n"
"    ldr     r0, =0x000080ec\n"
"    ldr     r1, [r0]\n"
"    ldr     r0, =0x00008074\n"
"    ldr     r0, [r0]\n"
"    adds    r0, #0x10\n"
"    cmp     r1, r0\n"
"    bhs     loc_fc055a40\n"
"    ldr     r0, =0xfc055adc\n" //  *"USER_MEM size checking"
"    bl      sub_fc055ab6\n"
"loc_fc055a40:\n"
"    bl      sub_fc11f6e0\n"
"    ldr     r1, =0xbfe10000\n"
// note capdis bad output
//"    mov.w   r2, #-0x11111112\n"
"    mov.w   r2, #0xeeeeeeee\n"
"    ldr     r3, =0xbfe10800\n"
"loc_fc055a4c:\n"
"    stm     r1!, {r2}\n"
"    cmp     r1, r3\n"
"    blo     loc_fc055a4c\n"
"    bl      sub_fc11f6f2\n"
"    bl      sub_fc38d1bc\n"
"    cmp     r0, #0\n"
"    bge     loc_fc055a64\n"
"    ldr     r0, =0xfc055afc\n" //  *"dmSetup"
"    bl      sub_fc055ab6\n"
"loc_fc055a64:\n"
"    bl      sub_fc056268\n"
"    cmp     r0, #0\n"
"    bge     loc_fc055a72\n"
"    ldr     r0, =0xfc055b04\n" //  *"termDriverInit"
"    bl      sub_fc055ab6\n"
"loc_fc055a72:\n"
"    mov     r0, r4\n"
"    bl      sub_fc0562f6\n"
"    cmp     r0, #0\n"
"    bge     loc_fc055a82\n"
"    ldr     r0, =0xfc055b14\n" //  *"termDeviceCreate"
"    bl      sub_fc055ab6\n"
"loc_fc055a82:\n"
"    mov     r0, r4\n"
"    bl      sub_fc055c60\n"
"    cmp     r0, #0\n"
"    bge     loc_fc055a92\n"
"    ldr     r0, =0xfc055b28\n" //  *"stdioSetup"
"    bl      sub_fc055ab6\n"
"loc_fc055a92:\n"
"    bl      sub_fc055da4\n"
"    cmp     r0, #0\n"
"    bge     loc_fc055aa0\n"
"    ldr     r0, =0xfc055b34\n" //  *"stdlibSetup"
"    bl      sub_fc055ab6\n"
"loc_fc055aa0:\n"
"    bl      sub_fc058e3c\n"
"    cmp     r0, #0\n"
"    bge     loc_fc055aae\n"
"    ldr     r0, =0xfc055b40\n" //  *"extlib_setup"
"    bl      sub_fc055ab6\n"
"loc_fc055aae:\n"
"    pop.w   {r4, lr}\n"
//"    b.w     loc_fc055e2e\n"
"    b.w     sub_fc055e2e_my\n" // +
    ".ltorg\n"
    );
}

//  -f=chdk -s=0xfc055e2f -c=20
void __attribute__((naked,noinline)) sub_fc055e2e_my() {
    asm volatile (
"    push    {r3, lr}\n"
"    bl      sub_fc055f34\n"
"    bl      sub_fc078bfc\n" // IsNormalCameraMode_FW
"    bl      sub_fc0cf0ee_my\n" // startup checks equivalent of g7x fc0781f4, but doesn't seem affected by *(0x4ffc)=0x12345678
"    cbnz    r0, loc_fc055e44\n"
"    bl      sub_fc055f22\n"
"loc_fc055e42:\n"
"    b       loc_fc055e42\n"
"loc_fc055e44:\n"
"    blx     sub_fc2c75b4\n"
"    ldr     r1, =0x006ce000\n"
"    movs    r0, #0\n"
"    bl      sub_fc329100\n"
"    movs    r3, #0\n"
"    str     r3, [sp]\n"
//"    ldr     r3, =0xfc055dc9\n" //  task_Startup
"    ldr     r3, =task_Startup_my\n" //  ->
"    movs    r2, #0\n"
"    movs    r1, #0x19\n"
"    ldr     r0, =0xfc055e6c\n" //  *"Startup"
"    bl      _CreateTask\n"
//"    blx     sub_fc2c79a8\n" // j_CreateTask
"    movs    r0, #0\n"
"    pop     {r3, pc}\n"
    ".ltorg\n"
    );
}
// -f=chdk -s=0xfc0cf0ef -c=40
void __attribute__((naked,noinline)) sub_fc0cf0ee_my() {
    asm volatile (
"    push.w  {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}\n"
"    movs    r4, #0\n"
"    mov     sl, r0\n"
"    mov     r5, r4\n"
"    mov     sb, r4\n"
//"    bl      sub_fc086a00\n" // nullsub
"    movs    r0, #0x10\n"
"    bl      sub_fc0847ea\n"
"    movs    r6, #1\n"
"    bic.w   r8, r6, r0\n"
"    movs    r0, #0xf\n"
"    bl      sub_fc0847ea\n"
"    bic.w   r7, r6, r0\n"
"    movs    r0, #0\n"
"    bl      sub_fc0869fc\n"
"    cbz     r0, loc_fc0cf126\n"
"    movs    r0, #0x17\n"
"    bl      sub_fc0847ea\n"
"    bic.w   r5, r6, r0\n"
"loc_fc0cf126:\n"
"    movs    r0, #1\n"
"    bl      sub_fc0869fc\n"
"    cbz     r0, loc_fc0cf13a\n"
"    movw    r0, #0x1d8\n"
"    bl      sub_fc0847ea\n"
"    bic.w   r4, r6, r0\n"
"loc_fc0cf13a:\n"
"    cmp.w   sl, #0\n"
"    beq     loc_fc0cf14a\n" // skips checks if not IsNormalCameraMode
"    orr.w   r0, r8, r7\n"
"    orrs    r0, r5\n"
"    orrs    r0, r4\n" // check all hardware related bits checked above
//"    beq     loc_fc0cf15e\n" // old behavior, skip to return if none set
"    bne     loc_fc0cf14a\n" // new behavior, go to final code if any set
// otherwise, act as if play was held
    "mov  r7, #1\n"
"loc_fc0cf14a:\n"
"    mov     r3, sb\n"
"    mov     r2, r5\n"
"    mov     r1, r7\n"
"    mov     r0, r8\n"
"    str     r4, [sp]\n"
"    bl      sub_fc086a04\n"
//"    bl      sub_fc086a02\n" // nullsub
"    movs    r0, #1\n"
//"loc_fc0cf15e:\n"
"    pop.w   {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}\n"
    ".ltorg\n"
    );
}

// -f=chdk -s=task_Startup -c=26
void __attribute__((naked,noinline)) task_Startup_my() {
    asm volatile (
// task_Startup 0xfc055dc9
"    push    {r4, lr}\n"
"    bl      sub_fc0cf4d8\n" // CreateTask ClockSave
"    bl      sub_fc055f00\n" // ??
//"    bl      sub_fc056060\n" // ->nullsub
"    bl      sub_fc38d970\n"
// added for SD card UHS detection https://chdk.setepontos.com/index.php?topic=13089.msg132583#msg132583
"bl sub_010e173f\n" // ref in sub_010e182c following SD1stInit create
//"    bl      sub_fc0560b6\n" StartDiskboot
//"    bl      CreateTask_blinker\n"
"    bl      sub_fc0b337a\n"
"    bl      sub_fc0cf7dc\n"
"    bl      sub_fc0561a8\n"
"    bl      sub_fc055ff0\n"
"    bl      sub_fc38d9ae\n"
"    bl      sub_fc0917c4\n"
"    bl      sub_fc0cf7e2\n"
"    bl      sub_fc0cf014_my\n" // CreateTask PhySw
"    bl      CreateTask_spytask\n" 
"    bl      init_required_fw_features\n" // added
"    bl      sub_fc267314\n"
"    bl      sub_fc0cf7f8\n"
"    bl      sub_fc11fac8\n"
"    bl      sub_fc0b2fb0\n"
"    bl      sub_fc0cf636\n"
"    bl      sub_fc0b332a\n"
"    bl      sub_fc0b2f6c\n"
"    bl      sub_fc0561ac\n"
"    bl      sub_fc2d3370\n"
"    bl      sub_fc0b2f40\n"
"    pop.w   {r4, lr}\n"
//"    b.w     loc_fc0cf4ae\n"
"    ldr     pc,=0xfc0cf4af\n"
    ".ltorg\n"
    );
}

// -f=chdk -s=0xfc0cf015 -c=18
//taskcreate_physw
void __attribute__((naked,noinline)) sub_fc0cf014_my() {
    asm volatile (
"    push    {r3, r4, r5, lr}\n"
"    bl      sub_fc087d58\n"
"    bl      sub_fc078b7a\n" // IsFactoryMode_FW
"    cbnz    r0, loc_fc0cf024\n"
"    bl      sub_fc087cfc\n" // OpLog.Start_FW
"loc_fc0cf024:\n"
"    ldr     r4, =0x000082c8\n" //  physw_run
"    ldr     r0, [r4, #4]\n"
"    cmp     r0, #0\n"
"    bne     loc_fc0cf040\n"
"    movs    r3, #0\n"
"    str     r3, [sp]\n"
//"    ldr     r3, =0xfc0cefc7\n" //  task_PhySw
"    ldr     r3, =mykbd_task\n"
"    movs    r1, #0x17\n"
"    ldr     r0, =0xfc0cf36c\n" //  *"PhySw"
//"    movw    r2, #0x800\n"
"    movw    r2, #0x2000\n" // adjusted 0x800 -> 0x2000
"    blx     sub_fc2c7cc0\n" // j_CreateTaskStrictly
"    str     r0, [r4, #4]\n"
"loc_fc0cf040:\n"
"    pop     {r3, r4, r5, pc}\n"
    ".ltorg\n"
    );
}
 
// -f=chdk -s=task_InitFileModules -c=16
void __attribute__((naked,noinline)) init_file_modules_task() {
    asm volatile (
// task_InitFileModules 0xfc0d4309
"    push    {r4, r5, r6, lr}\n"
"    bl      sub_fc0d985c\n"
"    movs    r4, r0\n"
"    movw    r5, #0x5006\n"
"    beq     loc_fc0d431e\n"
"    movs    r1, #0\n"
"    mov     r0, r5\n"
"    bl      _PostLogicalEventToUI\n"
"loc_fc0d431e:\n"
"    bl      sub_fc0d9886\n"
"    BL      core_spytask_can_start\n" // + CHDK: Set "it's-safe-to-start" flag for spytask
"    cmp     r4, #0\n"
"    bne     loc_fc0d4332\n"
"    mov     r0, r5\n"
"    pop.w   {r4, r5, r6, lr}\n"
"    movs    r1, #0\n"
"    b.w     _PostLogicalEventToUI\n"
"loc_fc0d4332:\n"
"    pop     {r4, r5, r6, pc}\n"
    ".ltorg\n"
    );
}
/*
    *** workaround ***
    Init stuff to avoid asserts on cameras running DryOS r54+
    https://chdk.setepontos.com/index.php?topic=12516.0
    Execute this only once
 */
void init_required_fw_features(void) {
    extern void _init_focus_eventflag();

    _init_focus_eventflag();
    // for MoveIrisWithAv, based on fc540574 from Mecha.Create (but without registering eventprocs)
    extern int av_override_semaphore;
    extern int _CreateBinarySemaphoreStrictly(int x, int y);
    av_override_semaphore = _CreateBinarySemaphoreStrictly(0,0);
}

// fix for FI2 boot, see https://chdk.setepontos.com/index.php?topic=11316.msg136622#msg136622
// -f=chdk -s=task_TricInitTask -c=36
void __attribute__((naked,noinline)) TricInitTask_my()
{
    asm volatile(
   // task_TricInitTask 0xfc4417a1
"    push.w  {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, ip, lr}\n"
"    blx     sub_fc2c7d30\n"
"    movs    r0, #8\n"
"    ldr     r1, =0xfc4419d0\n" //  *"InitTskStart"
"    bl      sub_fc315ec6\n"
"    ldr.w   sl, =0x00020bb0\n"
"    movw    fp, #0x1000\n"
"    ldr     r4, =0x00020bac\n"
"    movs    r2, #0\n"
"    ldr     r1, =0x0703870f\n"
"    ldr     r0, [r4]\n"
"    blx     sub_fc2c7dd0\n" // j_WaitForAnyEventFlag
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc4417da\n"
"    movs    r0, #8\n"
"    ldr     r1, =0xfc4419e8\n" //  *"ER IniTskWait"
"    bl      sub_fc315f26\n"
"    ldr     r1, =0x00020b98\n"
"    movs    r0, #0\n"
"    str     r0, [r1]\n"
"    pop.w   {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, ip, pc}\n"
"loc_fc4417da:\n"
"    ldr     r4, =0x00020bac\n"
"    add     r1, sp, #0xc\n"
"    ldr     r0, [r4]\n"
"    blx     sub_fc2c7ba0\n" // j_GetEventFlagValue
"    ldr     r1, [sp, #0xc]\n"
"    ldr     r0, [r4]\n"
"    blx     sub_fc2c7dc8\n" // j_ClearEventFlag
"    ldr     r0, =0x02000003\n"
"    ldr     r7, [sp, #0xc]\n"
"    tst     r7, r0\n"
"    beq     sub_fc4418de\n" // loc -> sub
"    lsls    r0, r7, #0x1f\n"
"    beq     sub_fc4417fe\n" // loc -> sub

"    ldr     r0, =0xd2020074\n" // + MMIO ref'd from code jumped to at end of fc441c82
"    ldr     r0, [r0]\n"        // + nonzero when core already running
"    subs    r0, #0\n"          // +
"    beq     tric1\n"           // +
"    ldr     r0, [r4]\n"        // +
"    mov     r1, #0x80\n"       // +
"    bl      _SetEventFlag\n"   // + core already initialized, set the SmacIdleCmp eventflag here
"tric1:\n"                      // +

"    bl      sub_fc441c82\n"
//"    b       loc_fc44186a\n"
"    ldr     pc, =0xfc44186b\n" // b to ldr pc, continue in fw
".ltorg\n"
    );
}

#ifdef CAM_HAS_JOGDIAL
// jogdial override code called from kbd task
// -f=chdk -s=kbd_p2_f -c=77
// kbd_p2_f 0xfc0ced65
void __attribute__((naked,noinline)) kbd_p2_f_my() {
    asm volatile(
"    push.w  {r4, r5, r6, r7, r8, lr}\n"
"    ldr     r6, =0x00032734\n"
"    sub     sp, #0x18\n"
"    add     r7, sp, #8\n"
"    subs    r6, #0xc\n"
"    b       loc_fc0ceda6\n"
"loc_fc0ced72:\n"
"    ldr     r1, =0x00032734\n"
"    add     r3, sp, #8\n"
"    ldrb.w  r0, [sp, #4]\n"
"    add     r2, sp, #0x14\n"
"    subs    r1, #0x18\n"
"    bl      sub_fc086f30\n"
"    cbnz    r0, loc_fc0ced8c\n"
"    ldr     r1, [sp, #0x14]\n"
"    movs    r0, #0\n"
"    bl      sub_fc0cecd6\n"
"loc_fc0ced8c:\n"
"    movs    r0, #2\n"
"loc_fc0ced8e:\n"
"    ldr.w   r1, [r7, r0, lsl #2]\n"
"    cbz     r1, loc_fc0ced9e\n"
"    ldr.w   r2, [r6, r0, lsl #2]\n"
"    bics    r2, r1\n"
"    str.w   r2, [r6, r0, lsl #2]\n"
"loc_fc0ced9e:\n"
"    subs    r0, r0, #1\n"
"    sxtb    r0, r0\n"
"    cmp     r0, #0\n"
"    bge     loc_fc0ced8e\n"
"loc_fc0ceda6:\n"
"    ldr     r0, =0x00032734\n"
"    add     r1, sp, #4\n"
"    subs    r0, #0xc\n"
"    bl      sub_fc086c7c\n"
"    cmp     r0, #0\n"
"    bne     loc_fc0ced72\n"
"    ldr.w   r8, =0x00032734\n"
"    movs    r4, #0\n"
"loc_fc0cedba:\n"
"    movs    r5, #0\n"
"    ldr.w   r0, [r6, r4, lsl #2]\n"
"    ldr.w   r1, [r8, r4, lsl #2]\n"
"    ands    r0, r1\n"
"    str.w   r0, [r6, r4, lsl #2]\n"
"    b       loc_fc0cee12\n"
"loc_fc0cedcc:\n"
"    lsrs    r0, r5\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc0cee0a\n"
"    ldr     r1, =0x00032734\n"
"    add.w   r0, r5, r4, lsl #5\n"
"    add     r3, sp, #8\n"
"    subs    r1, #0x18\n"
"    add     r2, sp, #0x14\n"
"    uxtb    r0, r0\n"
"    bl      sub_fc086f30\n"
"    cbnz    r0, loc_fc0cedee\n"
"    ldr     r1, [sp, #0x14]\n"
"    movs    r0, #1\n"
"    bl      sub_fc0cecd6\n"
"loc_fc0cedee:\n"
"    mov     r0, r4\n"
"    b       loc_fc0cee06\n"
"loc_fc0cedf2:\n"
"    ldr.w   r1, [r7, r0, lsl #2]\n"
"    cbz     r1, loc_fc0cee02\n"
"    ldr.w   r2, [r6, r0, lsl #2]\n"
"    bics    r2, r1\n"
"    str.w   r2, [r6, r0, lsl #2]\n"
"loc_fc0cee02:\n"
"    adds    r0, r0, #1\n"
"    sxtb    r0, r0\n"
"loc_fc0cee06:\n"
"    cmp     r0, #3\n"
"    blt     loc_fc0cedf2\n"
"loc_fc0cee0a:\n"
"    ldr.w   r0, [r6, r4, lsl #2]\n"
"    adds    r5, r5, #1\n"
"    uxtb    r5, r5\n"
"loc_fc0cee12:\n"
"    cmp     r0, #0\n"
"    bne     loc_fc0cedcc\n"
"    adds    r4, r4, #1\n"
"    sxtb    r4, r4\n"
"    cmp     r4, #3\n"
"    blt     loc_fc0cedba\n"
//"    bl      sub_fc086af2\n"
"    bl      sub_fc086af2_my\n"
"    add     sp, #0x18\n"
"    pop.w   {r4, r5, r6, r7, r8, pc}\n"
".ltorg\n"
    );
}

// -f=chdk -s=0xfc086af3 -c=10
void __attribute__((naked,noinline)) sub_fc086af2_my() {
    asm volatile(
"    push    {r4, lr}\n"
"    ldr     r4, =0x0000960c\n"
"    subs    r4, #0x10\n"
"    ldr     r0, [r4, #8]\n"
"    bl      sub_fc08b410\n"
"    bl      sub_fc0f232c\n"
"    ldr     r0, [r4, #0xc]\n"
"    bl      sub_fc08b340\n"
// re-ordered
//"    pop.w   {r4, lr}\n"
//"    b.w     loc_fc08b6f6\n"
"    bl      handle_jogdial\n"  // +
"    cmp     r0, #0\n"          // +
"    beq     no_scroll\n"       // +
"    bl      sub_fc08b6f6\n"    // handles scrollwheel(s), void function, no args
"no_scroll:\n"                  // +
"    pop     {r4, pc}\n"        // +
".ltorg\n"
    );
}
#endif
