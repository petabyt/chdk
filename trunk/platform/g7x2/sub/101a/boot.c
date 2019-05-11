
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

void TestAssert()
{
    extern void _DebugAssert(int, char*, int);
    _DebugAssert(0, "Testing DebugAssert", __LINE__);
}

void blinker()
{
    // green LED
    volatile int* p = (int*)0xD20801E4;

    // blinker
    int i;
    while (1)
    {
        *p = 0x24D0002;
        for(i=0;i<10000000;i++) {
            asm volatile(
            "nop\n"
            );
        }
        *p = 0x24C0003;
        for(i=0;i<10000000;i++) {
            asm volatile(
            "nop\n"
            );
        }
    }
}

void blinktask(long ua, long ub, long uc, long ud, long ue, long uf)
{
    // green LED
    volatile int* p = (int*)0xD20801E4;

    // blinker
    while (1)
    {
        *p = 0x24D0002;
        _SleepTask(1000);
        *p = 0x24C0003;
        _SleepTask(1000);
    }
}

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
    extern int _CreateTask_Alt(const char *name, int prio, int stack_size /*?*/,void *entry, long parm /*?*/);
    _CreateTask_Alt("BlinkTask", 0x19, 0x800, blinktask, 0);
//    _CreateTask("SpyTask", 0x19, 0x2000, spytask, 0);
}

/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/

/*************************************************************/
void __attribute__((naked,noinline)) boot() {
    asm volatile ( // 0xfc02000c
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
            "    b.w     sub_e00200f8_my\n"
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

            // Install CreateTask patch
//            "    adr     r0, patch_CreateTask\n"    // Patch data
//            "    ldm     r0, {r1,r2}\n"             // Get two patch instructions
//            "    ldr     r0, =orig_CreateTask\n"    // Address to patch
//            "    bic     r0, #1\n"                  // clear thumb bit
//            "    stm     r0, {r1,r2}\n"             // Store patch instructions

            "    ldr     r0, =0xdffc4900\n"
            "    ldr     r1, =0x0000c008\n"
            "    bl      sub_e042eb74\n"
            "    ldr     r0, =0xdffc4900\n"
            "    ldr     r1, =0x0000c008\n"
            "    bl      sub_e042ec4c\n"
            "    ldr     r0, =loc_e0020032\n"
            "    orr     r0, r0, #1\n"
            "    bx      r0\n"

"patch_CreateTask:\n"
"    ldr.w   pc, [pc,#0]\n"             // Do jump to absolute address CreateTask_my
"    .long   CreateTask_my + 1\n"       // has to be a thumb address
);
}

/*************************************************************/
void __attribute__((naked,noinline)) CreateTask_my() {
asm volatile (
"    push   {r0}\n"
//R3 = Pointer to task function to create

//"    ldr     r0, =task_CaptSeq\n"       // DryOS original code function ptr.
//"    cmp     r0, r3\n"                  // is the given taskptr equal to our searched function?
//"    itt     eq\n"                      // EQ block
//"    ldreq   r3, =capt_seq_task\n"      // if so replace with our task function base ptr.
//"    beq     exitHook\n"                // below compares not necessary if this check has found something.
//
//"    ldr     r0, =task_ExpDrv\n"
//"    cmp     r0, R3\n"
//"    itt     eq\n"
//"    ldreq   r3, =exp_drv_task\n"
//"    beq     exitHook\n"

//"    ldr     r0, =task_DvlpSeq\n"
//"    cmp     r0, R3\n"
//"    itt     eq\n"
//"    LDREQ   r3, =developseq_task\n"
//"    BEQ     exitHook\n"
//
//"    ldr     r0, =task_FileWrite\n"
//"    cmp     r0, R3\n"
//"    itt     eq\n"
//"    ldreq   r3, =filewritetask\n"
//"    beq     exitHook\n"
//
//"    ldr     r0, =task_MovieRecord\n"
//"    cmp     r0, R3\n"
//"    itt     eq\n"
//"    ldreq   r3, =movie_record_task\n"
//"    beq     exitHook\n"

//"    ldr     r0, =task_InitFileModules\n"
//"    cmp     r0, r3\n"
//"    it      eq\n"
//"    ldreq   r3, =init_file_modules_task\n"

"exitHook:\n" 
// restore overwritten register(s)
"    pop    {r0}\n"
// Execute overwritten instructions from original code, then jump to firmware
"    push.w  {r1, r2, r3, r4, r5, r6, r7, r8, sb, lr}\n"
"    mov     r4, r0\n"
"    ldr     r0, =0x00008164\n"
"    ldr.w   pc, =(orig_CreateTask + 8) \n"  // Continue in firmware
".ltorg\n"
);
}

//e00200f8
void __attribute__((naked,noinline)) sub_e00200f8_my() {

//    if (*(int*)(0xd20b0000 + 0x97 * 4) & 0x10000) {
//        // see sub_FC0ECF20, sub_FC09B450
//        // GPIO 0x10 (aka ON/OFF button) is not pressed -> play
//        *(int*)(0x9c44+0x8) = 0x200000;
//    }
//    else {
//        // GPIO 0x10 is pressed -> rec
//        *(int*)(0x9c44+0x8) = 0x100000;
//    }

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
            "    ldr     r1, =sub_e0020398_my\n"
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
            //capdis -f=chdk -s=0xe0020751 -c=21 -stubs PRIMARY.BIN 0xe0000000
            "    push    {r3, lr}\n"
            "    bl      sub_e002088c\n"
            "    bl      sub_e0020848\n"
            "    movs    r0, #1\n"
//            "    bl      sub_e051e07c\n"    // ********** Hangs if this is called
            "    bl      sub_e003e3bc\n"
            "    bl      sub_e005b418_my\n"  // -> power-on mode handling & startupchecks here
            "    cbz     r0, loc_e002078a\n"
            "    bl      sub_dffc9094\n"
            "    ldr     r1, =0x006ce000\n"
            "    movs    r0, #0\n"
            "    bl      sub_e037e5d0\n"
            "    ldr     r3, =task_Startup_my\n"
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
            "    bl      sub_e004e4d6\n"
            "    bl      sub_e004e4d4\n"
            "    movs    r0, #1\n"
            "loc_e005b49a:\n"
            "    pop.w   {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}\n"
    );
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
            "    bl      sub_e046e3dc_my\n"       // - startdiskboot
            "    bl      sub_e005a122\n"
            "    bl      sub_e0425880\n"
            "    bl      sub_e0020924\n"
            "    bl      sub_e00208be\n"
            "    bl      sub_e052fde2\n"
            "    bl      sub_e0056650\n"
//            "    bl      TestAssert\n"          // +++
            "    bl      sub_e0425886\n"
            "    bl      sub_e005b33e\n"    //_my\n"     // -> taskcreate_physw
            "    BL      CreateTask_spytask\n"  // +
//            "    bl      init_required_fw_features\n" // added TODO: Check if needed on G7X2
            "    bl      sub_e0297df6\n"
            "    bl      sub_e042589c\n"
            "    bl      sub_e052fd44\n"
            "    bl      sub_e04914a0\n"
            "    bl      sub_e005b870\n"
            "    bl      sub_e005a0d2\n"
            "    bl      sub_e049145c\n"
            "    bl      sub_e0020928\n"
            "    bl      sub_e037bccc_my\n"        // ********** Hangs in here (see extracted code below)
            "    bl      sub_e049142e\n"
            "    pop.w   {r4, lr}\n"
            "    b.w     sub_e013a496\n"
    );
}

//e046e3dc
void __attribute__((naked,noinline)) sub_e046e3dc_my() {
    asm volatile (
            //capdis -f=chdk -s=0xe046e3dd -c=28 -stubs PRIMARY.BIN 0xe0000000
            "    push    {r4, lr}\n"
            "    ldr     r0, =0xe046e3dd\n"
            "    lsrs    r0, r0, #0x18\n"
            "    beq     loc_e046e426\n"
            "    movs    r0, #0\n"
            "    bl      sub_e0531c8c\n"
            "    lsls    r0, r0, #0x1f\n"
            "    bne     loc_e046e426\n"
            "    bl      sub_e04d9a1e\n"
            "    movs    r0, #1\n"
            "    bl      sub_e0531c8c\n"
            "    lsls    r0, r0, #0x1f\n"
            "    beq     loc_e046e426\n"
            "    bl      sub_e0531c8a\n"
            "    movs    r0, #0\n"
            "    bl      sub_e0375014\n"
            "    movs    r0, #0\n"
            "    bl      sub_e0375042\n"
            "    cbz     r0, loc_e046e426\n"
            "    ldr     r0, =0xe046e4f8\n" //  *"\nStartDiskboot"
            "    bl      sub_e037e664\n"
            "    movs    r0, #0\n"
            "    bl      sub_e0375070\n"
//            "    bl      sub_e046e4b0\n"  // Check for diskboot.bin
            "    movs    r0, #0\n"
            "    bl      sub_e0374fc6\n"
            "loc_e046e426:\n"
            "    pop.w   {r4, lr}\n"
            "    bx      lr\n"
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
            "    ldr     r3, =0xe005b319\n" //=mykbd_task\n" // task_PhySw replacement
            "    lsls    r2, r1, #0xb\n"
            "    strd    r0, r1, [sp]\n"
            "    movs    r1, #0x17\n"
            "    ldr     r0, =0xe005b6a4\n" //  *"PhySw"
            "    bl      sub_dffc95d8\n"    // ??? stack size set in here not as param - may need replacing
            "    str     r0, [r4, #4]\n"
            "loc_e005b36a:\n"
            "    pop     {r2, r3, r4, pc}\n"
    );
}

//e037bccc
void __attribute__((naked,noinline)) sub_e037bccc_my() {
    asm volatile (
//capdis -f=chdk -s=0xe037bccd -c=18 -stubs PRIMARY.BIN 0xe0000000
            "    push    {r4, lr}\n"
            "    bl      sub_e03bf1fc\n"
            "    bl      sub_e003e33c\n"
            "    cmp     r0, #1\n"
            "    beq     loc_e037bcf2\n"
            "    bl      sub_e035f864\n"
            "    ldr     r4, =0x00008270\n"
            "    ldr     r0, [r4, #4]\n"
            "    cmp     r0, #0\n"
            "    bne     loc_e037bcf0\n"
            "    movs    r1, #0\n"
            "    ldr     r0, =0xe037b94d\n"
            "    bl      sub_e0371490_my\n"     // +
            "    str     r0, [r4, #4]\n"
            "loc_e037bcf0:\n"
            "    pop     {r4, pc}\n"
            "loc_e037bcf2:\n"
            "    bl      sub_e04201b8\n"
            "    pop.w   {r4, lr}\n"
            "    b.w     sub_e003e3ca\n"
    );
}

//e0371490
void __attribute__((naked,noinline)) sub_e0371490_my() {
    asm volatile (
            //capdis -f=chdk -s=0xe0371491 -c=56 -stubs PRIMARY.BIN 0xe0000000
            "    push.w  {r4, r5, r6, r7, r8, lr}\n"
            "    mov     r7, r0\n"
            "    ldr     r5, =0x0000c518\n"
            "    movs    r6, #0\n"
            "    mov     r8, r1\n"
            "    ldrb    r0, [r5]\n"
            "    lsls    r0, r0, #0x1f\n"
            "    beq     loc_e03714a6\n"
            "loc_e03714a2:\n"
            "    movs    r0, #0x11\n"
            "    b       sub_e037134a\n"
            "loc_e03714a6:\n"
            "    movs    r0, #0x28\n"
            "    bl      sub_e0371f08\n"
            "    ldr     r1, =0x0001d4c0\n"
            "    mov     r4, r0\n"
            "    ldr     r0, [r5]\n"
            "    mov.w   r3, #0x288\n"
            "    ldr     r2, =0xe037173c\n" //  *"CtrlMan.c"
            "    bl      sub_dffca338\n"
            "    cbz     r0, loc_e03714c6\n"
            "    mov     r0, r4\n"
            "    bl      sub_e0371f0e\n"
            "    b       loc_e03714a2\n"
            "loc_e03714c6:\n"
            "    ldr     r0, [r5, #0xc]\n"
            "    cbz     r0, loc_e03714cc\n"
            "    mov     r6, r0\n"
            "loc_e03714cc:\n"
            "    str     r7, [r4]\n"
            "    strd    r8, r0, [r4, #4]\n"
            "    movs    r0, #0x19\n"
            "    str     r0, [r4, #0xc]\n"
            "    movs    r1, #0x19\n"
            "    ldr     r0, [r5, #0x14]\n"
            "    str     r0, [r4, #0x10]\n"
            "    movs    r0, #0\n"
            "    str     r0, [r4, #0x18]\n"
            "    str     r0, [r4, #0x1c]\n"
            "    str     r0, [r4, #0x20]\n"
            "    ldr     r0, [r5, #0x1c]\n"
            "    str     r0, [r4, #0x24]\n"
            "    adds    r0, r0, #1\n"
            "    str     r0, [r5, #0x1c]\n"
            "    ldr     r0, =0xe03713bd\n"
            "    str     r0, [r4, #0x14]\n"
            "    mov     r0, r4\n"
            "    bl      sub_e03713f4\n"
            "    ldr     r0, [r5]\n"
            "    bl      sub_dffcad46\n"
            "    movs    r3, #0\n"
            "    movw    r1, #0x803\n"
            "    mov     r2, r3\n"
            "    mov     r0, r4\n"
            "    bl      sub_e0371330_my\n"     // +
            "    mov     r1, r4\n"
            "    mov     r0, r6\n"
            "    bl      sub_e03719b8\n"
            "    mov     r0, r4\n"
            "    b       sub_e037134a\n"
    );
}

//e0371330
void __attribute__((naked,noinline)) sub_e0371330_my() {
    asm volatile (
            //capdis -f=chdk -s=0xe0371331 -c=31 -stubs PRIMARY.BIN 0xe0000000
            "    push.w  {r4, r5, r6, r7, r8, lr}\n"
            "    movs    r4, r0\n"
            "    mov     r6, r3\n"
            "    mov     r7, r2\n"
            "    mov     r8, r1\n"
            "    beq     loc_e0371348\n"
            "    ldr     r5, =0x0000c518\n"
            "    ldr     r0, [r5, #0x18]\n"
            "    cmp     r0, #0xe\n"
            "    bne     loc_e0371358\n"
            "    b       loc_e037134e\n"
            "loc_e0371348:\n"
            "    movs    r0, #1\n"
            "loc_e037134a:\n"
            "    pop.w   {r4, r5, r6, r7, r8, pc}\n"
            "loc_e037134e:\n"
            "    movs    r2, #0x7e\n"
            "    movs    r0, #0\n"
            "    ldr     r1, =0xe037173c\n" //  *"CtrlMan.c"
            "    bl      sub_dffc96f4\n"
            "loc_e0371358:\n"
            "    ldr     r2, =0x0005ba58\n"
            "    mov     r3, r6\n"
            "    ldr     r0, [r5, #0x18]\n"
            "    mov     r1, r8\n"
            "    str.w   r4, [r2, r0, lsl #2]\n"
            "    adds    r0, r0, #1\n"
            "    str     r0, [r5, #0x18]\n"
            "    mov     r2, r7\n"
            "    ldrd    r4, r0, [r4]\n"
//            "    blx     r4\n"                  // ********** Hangs here ???
            "    ldr     r1, [r5, #0x18]\n"
            "    subs    r1, r1, #1\n"
            "    str     r1, [r5, #0x18]\n"
            "    b       loc_e037134a\n"
    );
}

//fc157608
void __attribute__((naked,noinline)) init_file_modules_task() {
    asm volatile (
////capdis -f=chdk -s=0xfc157609 -c=18 -stubs PRIMARY.BIN 0xfc000000
//"    push    {r4, r5, r6, lr}\n"
//"    movs    r0, #6\n"
//"    bl      sub_fc368a14\n"
//"    bl      sub_fc0c994c\n"
//"    movs    r4, r0\n"
//"    movw    r5, #0x5006\n"
//"    beq     loc_fc157624\n"
//"    movs    r1, #0\n"
//"    mov     r0, r5\n"
//"    bl      sub_fc3bd76c\n"
//"loc_fc157624:\n"
//"    bl      sub_fc0c9976\n"
//"    bl      core_spytask_can_start\n" // + CHDK: Set "it's-safe-to-start" flag for spytask
//"    cmp     r4, #0\n"
//"    bne     loc_fc157638\n"
//"    mov     r0, r5\n"
//"    pop.w   {r4, r5, r6, lr}\n"
//"    movs    r1, #1\n"
//"    b.w     sub_fc3bd76c\n"
//"loc_fc157638:\n"
//"    pop     {r4, r5, r6, pc}\n"
".ltorg\n"
    );
}

//fc0ecb7c
void __attribute__((naked,noinline)) kbd_p2_f_my() {
    asm volatile(
////capdis -f=chdk -s=0xfc0ecb7d -c=77 -stubs PRIMARY.BIN 0xfc000000
//"    push.w  {r4, r5, r6, r7, r8, lr}\n"
//"    ldr     r6, =0x0003ef70\n"
//"    sub     sp, #0x18\n"
//"    add     r7, sp, #8\n"
//"    subs    r6, #0xc\n"
//"    b       loc_fc0ecbbe\n"
//"loc_fc0ecb8a:\n"
//"    ldr     r1, =0x0003ef70\n"
//"    add     r3, sp, #8\n"
//"    ldrb.w  r0, [sp, #4]\n"
//"    add     r2, sp, #0x14\n"
//"    subs    r1, #0x18\n"
//"    bl      sub_fc09bb10\n"
//"    cbnz    r0, loc_fc0ecba4\n"
//"    ldr     r1, [sp, #0x14]\n"
//"    movs    r0, #0\n"
//"    bl      sub_fc0ecaee\n"
//"loc_fc0ecba4:\n"
//"    movs    r0, #2\n"
//"loc_fc0ecba6:\n"
//"    ldr.w   r1, [r7, r0, lsl #2]\n"
//"    cbz     r1, loc_fc0ecbb6\n"
//"    ldr.w   r2, [r6, r0, lsl #2]\n"
//"    bics    r2, r1\n"
//"    str.w   r2, [r6, r0, lsl #2]\n"
//"loc_fc0ecbb6:\n"
//"    subs    r0, r0, #1\n"
//"    sxtb    r0, r0\n"
//"    cmp     r0, #0\n"
//"    bge     loc_fc0ecba6\n"
//"loc_fc0ecbbe:\n"
//"    ldr     r0, =0x0003ef70\n"
//"    add     r1, sp, #4\n"
//"    subs    r0, #0xc\n"
//"    bl      sub_fc09b7f6\n"
//"    cmp     r0, #0\n"
//"    bne     loc_fc0ecb8a\n"
//"    ldr.w   r8, =0x0003ef70\n"
//"    movs    r4, #0\n"
//"loc_fc0ecbd2:\n"
//"    movs    r5, #0\n"
//"    ldr.w   r0, [r6, r4, lsl #2]\n"
//"    ldr.w   r1, [r8, r4, lsl #2]\n"
//"    ands    r0, r1\n"
//"    str.w   r0, [r6, r4, lsl #2]\n"
//"    b       loc_fc0ecc2a\n"
//"loc_fc0ecbe4:\n"
//"    lsrs    r0, r5\n"
//"    lsls    r0, r0, #0x1f\n"
//"    beq     loc_fc0ecc22\n"
//"    ldr     r1, =0x0003ef70\n"
//"    add.w   r0, r5, r4, lsl #5\n"
//"    add     r3, sp, #8\n"
//"    subs    r1, #0x18\n"
//"    add     r2, sp, #0x14\n"
//"    uxtb    r0, r0\n"
//"    bl      sub_fc09bb10\n"
//"    cbnz    r0, loc_fc0ecc06\n"
//"    ldr     r1, [sp, #0x14]\n"
//"    movs    r0, #1\n"
//"    bl      sub_fc0ecaee\n"
//"loc_fc0ecc06:\n"
//"    mov     r0, r4\n"
//"    b       loc_fc0ecc1e\n"
//"loc_fc0ecc0a:\n"
//"    ldr.w   r1, [r7, r0, lsl #2]\n"
//"    cbz     r1, loc_fc0ecc1a\n"
//"    ldr.w   r2, [r6, r0, lsl #2]\n"
//"    bics    r2, r1\n"
//"    str.w   r2, [r6, r0, lsl #2]\n"
//"loc_fc0ecc1a:\n"
//"    adds    r0, r0, #1\n"
//"    sxtb    r0, r0\n"
//"loc_fc0ecc1e:\n"
//"    cmp     r0, #3\n"
//"    blt     loc_fc0ecc0a\n"
//"loc_fc0ecc22:\n"
//"    ldr.w   r0, [r6, r4, lsl #2]\n"
//"    adds    r5, r5, #1\n"
//"    uxtb    r5, r5\n"
//"loc_fc0ecc2a:\n"
//"    cmp     r0, #0\n"
//"    bne     loc_fc0ecbe4\n"
//"    adds    r4, r4, #1\n"
//"    sxtb    r4, r4\n"
//"    cmp     r4, #3\n"
//"    blt     loc_fc0ecbd2\n"
//"    bl      sub_fc09b570_my\n"
//"    add     sp, #0x18\n"
//"    pop.w   {r4, r5, r6, r7, r8, pc}\n"
".ltorg\n"
    );
}

//fc09b570
void __attribute__((naked,noinline)) sub_fc09b570_my() {
    asm volatile(
////capdis -f=chdk -s=0xfc09b571 -c=14 -stubs PRIMARY.BIN 0xfc000000
//"    push    {r4, lr}\n"
//"    ldr     r4, =0x00009c44\n"
//"    ldr     r0, [r4, #0xc]\n"
//"    bl      sub_fc0a3b54\n"
//"    ldr     r0, [r4, #0x10]\n"
//"    bl      sub_fc0a3bde\n"
//"    bl      sub_fc0a3c66\n"
//"    bl      sub_fc10b3f4\n"
//"    ldr     r0, [r4, #0x14]\n"
//"    bl      sub_fc0a3a84\n"
//"    ldr     r0, [r4, #0x18]\n"
//"    bl      sub_fc0a3a84\n"
//"    bl      handle_jogdial\n"  // +
//"    cmp     r0, #0\n"          // +
//"    beq     no_scroll\n"       // +
//"    pop.w   {r4, lr}\n"
//"    b.w     sub_fc0a3fc2\n"
//"no_scroll:\n"                  // +
//"    pop     {r4, pc}\n"        // +
".ltorg\n"
    );
}
