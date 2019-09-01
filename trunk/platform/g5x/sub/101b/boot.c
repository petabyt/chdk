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
 spytask
 -----------------------------------------------------------------------*/
void
spytask (long ua, long ub, long uc, long ud, long ue, long uf)
{
    core_spytask ();
}

/*----------------------------------------------------------------------
 CreateTask_spytask
 -----------------------------------------------------------------------*/
void
CreateTask_spytask ()
{
    _CreateTask ("SpyTask", 0x19, 0x2000, spytask, 0);
}

/*----------------------------------------------------------------------
 boot()

 Main entry point for the CHDK code
 -----------------------------------------------------------------------*/

/*************************************************************/
void __attribute__((naked,noinline))
boot ()
{
    asm volatile ( // 0xfc02000c
            //capdis -f=chdk -s=0xfc02000d -c=43 -stubs PRIMARY.BIN 0xfc000000
            "    movw    r0, #0x4000\n"
            "    movt    r0, #0\n"
            "    mov     sp, r0\n"
            "    bl      sub_fc02007e\n"
            "    ldr     r2, =0xc0242010\n"
            "    ldr     r1, [r2]\n"
            "    orr     r1, r1, #1\n"
            "    str     r1, [r2]\n"
            "    ldr     r0, =0xfcee2168\n"
            "    ldr     r1, =0x010e1000\n"
            "    ldr     r3, =0x010fbd18\n"
            "loc_fc02002a:\n"
            "    cmp     r1, r3\n"
            "    itt     lo\n"
            "    ldrlo   r2, [r0], #4\n"
            "    strlo   r2, [r1], #4\n"
            "    blo     loc_fc02002a\n"
            "    ldr     r0, =0x010e1000\n"
            "    ldr     r1, =0x0001ad18\n"
            "    bl      sub_fc150d5a\n"
            "    ldr     r0, =0xfcefce80\n"
            "    ldr     r1, =0xbfe10800\n"
            "    ldr     r3, =0xbfe176a9\n"
            "loc_fc020046:\n"
            "    cmp     r1, r3\n"
            "    itt     lo\n"
            "    ldrlo   r2, [r0], #4\n"
            "    strlo   r2, [r1], #4\n"
            "    blo     loc_fc020046\n"

            // Install CreateTask patch
            "    adr     r0, patch_CreateTask\n" // Patch data
            "    ldm     r0, {r1,r2}\n" // Get two patch instructions
            "    ldr     r0, =orig_CreateTask\n" // Address to patch
            "    bic     r0, #1\n" // clear thumb bit
            "    stm     r0, {r1,r2}\n" // Store patch instructions

            "    ldr     r0, =0xfceacaf4\n"
            "    ldr     r1, =0x00008000\n"
            "    ldr     r3, =0x0003d674\n"
            "loc_fc02005a:\n"
            "    cmp     r1, r3\n"
            "    itt     lo\n"
            "    ldrlo   r2, [r0], #4\n"
            "    strlo   r2, [r1], #4\n"
            "    blo     loc_fc02005a\n"
            "    ldr     r3, =0x0003d674\n"
            "    ldr     r1, =0x0039124c\n"
            "    mov.w   r2, #0\n"
            "loc_fc020070:\n"
            "    cmp     r3, r1\n"
            "    it      lo\n"
            "    strlo   r2, [r3], #4\n"
            "    blo     loc_fc020070\n"
            "    b.w     sub_fc066258_my\n" // Patched

            "patch_CreateTask:\n"
            "    ldr.w   pc, [pc,#0]\n" // Do jump to absolute address CreateTask_my
            "    .long   CreateTask_my + 1\n" // has to be a thumb address
    );
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
            "    ldr.w   pc, =(orig_CreateTask + 8) \n" // Continue in firmware
            ".ltorg\n"
    );
}

//fc066258
void __attribute__((naked,noinline))
sub_fc066258_my ()
{
    if (*(int*) (0xd20b0000 + 0x97 * 4) & 0x10000)
    {
        // see sub_FC0ECF20, sub_FC09B450
        // GPIO 0x10 (aka ON/OFF button) is not pressed -> play
        *(int*) (0x9c44 + 0x8) = 0x200000;
    }
    else
    {
        // GPIO 0x10 is pressed -> rec
        *(int*) (0x9c44 + 0x8) = 0x100000;
    }

    asm volatile (
            //capdis -f=chdk -s=0xfc066259 -c=60 -stubs PRIMARY.BIN 0xfc000000
            "    push    {r4, lr}\n"
#if defined(CHDK_NOT_IN_CANON_HEAP)
            "    ldr     r4, =0x0039124c\n"         // heap start, modify here
#else
            "    ldr     r4, =new_sa\n"             // +
            "    ldr     r4, [r4]\n" // +
#endif
            "    sub     sp, #0x78\n"
            "    ldr     r0, =0x006ce000\n"
            "    ldr     r1, =0x000b1fec\n"
            "    subs    r0, r0, r4\n"
            "    cmp     r0, r1\n"
            "    bhs     loc_fc06626a\n"
            "loc_fc066268:\n"
            "    b       loc_fc066268\n"            // too small heap, go into infinite loop
            "loc_fc06626a:\n"
            "    ldr     r1, =0x00008078\n"
            "    mov.w   r0, #0x80000\n"
            "    str     r0, [r1]\n"
            "    ldr     r1, =0x0000807c\n"
            "    ldr     r0, =0x42281000\n"
            "    str     r0, [r1]\n"
            "    ldr     r1, =0x00008080\n"
            "    ldr     r0, =0x42283000\n"
            "    str     r0, [r1]\n"
            "    movs    r1, #0x78\n"
            "    mov     r0, sp\n"
            "    blx     sub_fc34d25c\n"
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
            "    ldr     r1, =sub_fc0663e8_my\n" // -> continue here (init_task)
            "    asrs    r0, r0, #4\n"
            "    str     r0, [sp, #0x64]\n"
            "    lsls    r0, r0, #5\n"
            "    str     r0, [sp, #0x68]\n"
            "    mov     r0, sp\n"
            "    blx     sub_fc34c9b8\n"
            "    add     sp, #0x78\n"
            "    pop     {r4, pc}\n"
    );
}

//fc0663e8
void __attribute__((naked,noinline))
sub_fc0663e8_my ()
{
    asm volatile (
            //capdis -f=chdk -s=0xfc0663e9 -c=54 -stubs PRIMARY.BIN 0xfc000000
            "    push    {r4, lr}\n"
            "    ldr     r4, =0xfc066490\n" //  *"/_term"
            "    bl      sub_fc0672e4\n"
            "    ldr     r0, =0x000080f0\n"
            "    ldr     r1, [r0]\n"
            "    ldr     r0, =0x00008078\n"
            "    ldr     r0, [r0]\n"
            "    adds    r0, #0x10\n"
            "    cmp     r1, r0\n"
            "    bhs     loc_fc066404\n"
            "    ldr     r0, =0xfc0664a0\n" //  *"USER_MEM size checking"
            "    bl      sub_fc06647a\n"
            "loc_fc066404:\n"
            "    bl      sub_fc150e34\n"
            "    ldr     r1, =0xbfe10000\n"
            "    mov.w   r2, #-0x11111112\n"
            "    ldr     r3, =0xbfe10800\n"
            "loc_fc066410:\n"
            "    stm     r1!, {r2}\n"
            "    cmp     r1, r3\n"
            "    blo     loc_fc066410\n"
            "    bl      sub_fc150e46\n"
            "    bl      sub_fc150f60\n"
            "    cmp     r0, #0\n"
            "    bge     loc_fc066428\n"
            "    ldr     r0, =0xfc0664c0\n" //  *"dmSetup"
            "    bl      sub_fc06647a\n"
            "loc_fc066428:\n"
            "    bl      sub_fc0674fc\n"
            "    cmp     r0, #0\n"
            "    bge     loc_fc066436\n"
            "    ldr     r0, =0xfc0664c8\n" //  *"termDriverInit"
            "    bl      sub_fc06647a\n"
            "loc_fc066436:\n"
            "    mov     r0, r4\n"
            "    bl      sub_fc06758a\n"
            "    cmp     r0, #0\n"
            "    bge     loc_fc066446\n"
            "    ldr     r0, =0xfc0664d8\n" //  *"termDeviceCreate"
            "    bl      sub_fc06647a\n"
            "loc_fc066446:\n"
            "    mov     r0, r4\n"
            "    bl      sub_fc066610\n"
            "    cmp     r0, #0\n"
            "    bge     loc_fc066456\n"
            "    ldr     r0, =0xfc0664ec\n" //  *"stdioSetup"
            "    bl      sub_fc06647a\n"
            "loc_fc066456:\n"
            "    bl      sub_fc066754\n"
            "    cmp     r0, #0\n"
            "    bge     loc_fc066464\n"
            "    ldr     r0, =0xfc0664f8\n" //  *"stdlibSetup"
            "    bl      sub_fc06647a\n"
            "loc_fc066464:\n"
            "    bl      sub_fc0ec8e0\n"
            "    cmp     r0, #0\n"
            "    bge     loc_fc066472\n"
            "    ldr     r0, =0xfc066504\n" //  *"extlib_setup"
            "    bl      sub_fc06647a\n"
            "loc_fc066472:\n"
            "    pop.w   {r4, lr}\n"
            "    b.w     sub_fc0667de_my\n" // -> continue (taskcreate_startup)
    );
}

//fc0667de
void __attribute__((naked,noinline))
sub_fc0667de_my ()
{
    asm volatile (
            //capdis -f=chdk -s=0xfc0667df -c=20 -stubs PRIMARY.BIN 0xfc000000
            "    push    {r3, lr}\n"
            "    bl      sub_fc0668ec\n"
            "    bl      sub_fc088984\n"
            "    bl      sub_fc0ecf20_my\n" // -> power-on mode handling & startupchecks here
            "    cbnz    r0, loc_fc0667f4\n"
            "    bl      sub_fc0668da\n"
            "loc_fc0667f2:\n"
            "    b       loc_fc0667f2\n" // infinite loop
            "loc_fc0667f4:\n"
            "    blx     sub_fc34ca10\n"
            "    ldr     r1, =0x006ce000\n"
            "    movs    r0, #0\n"
            "    bl      sub_fc3bf9a4\n"
            "    movs    r3, #0\n"
            "    str     r3, [sp]\n"
            "    ldr     r3, =task_Startup_my\n" // Patched
            "    movs    r2, #0\n"
            "    movs    r1, #0x19\n"
            "    ldr     r0, =0xfc06681c\n" //  *"Startup"
            "    blx     sub_fc34ce3c\n"
            "    movs    r0, #0\n"
            "    pop     {r3, pc}\n"
    );
}

//fc0ecf20
void __attribute__((naked,noinline))
sub_fc0ecf20_my ()
{
    asm volatile (
            //capdis -f=chdk -s=0xfc0ecf21 -c=54 -stubs PRIMARY.BIN 0xfc000000
            "    push.w  {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}\n"
            "    movs    r4, #0\n"
            "    mov     sl, r0\n"
            "    mov     r6, r4\n"
            "    bl      sub_fc09b44c\n"
            "    movs    r0, #0x97\n"
            "    bl      sub_fc09bcca\n"
            "    mov.w   r8, #1\n"
            "    bic.w   r7, r8, r0\n"
            "    mov     r5, r8\n"
            "    movs    r0, #0x8a\n"
            "    bl      sub_fc09bcca\n"
            "    bics    r5, r0\n"
            "    movs    r0, #0\n"
            "    bl      sub_fc09b448\n"
            "    cbz     r0, loc_fc0ecf58\n"
            "    movs    r0, #0x98\n"
            "    bl      sub_fc09bcca\n"
            "    bic.w   r6, r8, r0\n"
            "loc_fc0ecf58:\n"
            "    movw    r0, #0x10e\n"
            "    bl      sub_fc09bcca\n"
            "    bic.w   sb, r8, r0\n"
            "    movs    r0, #1\n"
            "    bl      sub_fc09b448\n"
            "    cbz     r0, loc_fc0ecf76\n"
            "    movs    r0, #2\n"
            "    bl      sub_fc09bcca\n"
            "    bic.w   r4, r8, r0\n"
            "loc_fc0ecf76:\n"
            "    cmp.w   sl, #0\n"
            "    beq     loc_fc0ecfa6\n"
            "    cbz     r5, loc_fc0ecf98\n"
            "    movs    r0, #0x5a\n"
            "    blx     sub_fc34d1b4\n"
            "    movs    r0, #0x8a\n"
            "    bl      sub_fc09bcca\n"
            "    bic.w   r5, r8, r0\n"
            "    mov     r7, r8\n"
            "    movs    r0, #0x97\n"
            "    bl      sub_fc09bcca\n"
            "    bics    r7, r0\n"
            "loc_fc0ecf98:\n"
            "    orr.w   r0, r7, r5\n"
            "    orr.w   r1, r6, sb\n"
            "    orrs    r0, r1\n"
            "    orrs    r0, r4\n"
            //"    beq     loc_fc0ecfba\n" // -
            "loc_fc0ecfa6:\n"
            "    mov     r3, sb\n"
            "    mov     r2, r6\n"
            "    mov     r1, r5\n"
            "    mov     r0, r7\n"
            "    str     r4, [sp]\n"
            //"    bl      sub_fc09b450\n" // -
            //"    bl      sub_fc09b44e\n" // -
            "    movs    r0, #1\n"
            "loc_fc0ecfba:\n"
            "    pop.w   {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}\n"
    );
}

// *** TEMPORARY? workaround ***
// Init stuff to avoid asserts on cameras running DryOS r54+
// https://chdk.setepontos.com/index.php?topic=12516.0
// Execute this only once
//void init_required_fw_features(void)
//{
//    extern void _init_focus_eventflag();
//    _init_focus_eventflag();
//    extern void _init_nd_eventflag();
//    _init_nd_eventflag();
//}

// task_Startup fc066778
void __attribute__((naked,noinline))
task_Startup_my ()
{
    asm volatile (
            //capdis -f=chdk -s=0xfc066779 -c=26 -stubs PRIMARY.BIN 0xfc000000
            "    push    {r4, lr}\n"
            "    bl      sub_fc0c2dfc\n"
            "    bl      sub_fc0668b8\n"
            "    bl      sub_fc0ed2d0\n"
            "    bl      sub_fc44f2f4\n"
            // added for SD card UHS detection https://chdk.setepontos.com/index.php?topic=13089.msg132583#msg132583
            "    bl      sub_010e1746\n" // ref in sub_010e1746 following SD1stInit create
            //"    bl      sub_fc0ed356\n"   // - startdiskboot
            "    bl      sub_fc0b277e\n"
            "    bl      sub_fc0ed448\n"
            "    bl      sub_fc066a44\n"
            "    bl      sub_fc0669c0\n"
            "    bl      sub_fc44f332\n"
            "    bl      sub_fc0a2498\n"
            "    bl      sub_fc0ed44e\n"
            "    bl      sub_fc0ece46_my\n" // -> taskcreate_physw
            "    BL      CreateTask_spytask\n"          // +
//            "    bl      init_required_fw_features\n"   // + TODO: Check if needed on G5X
            "    bl      sub_fc2d2a06\n"
            "    bl      sub_fc0ed464\n"
            "    bl      sub_fc0ec9ac\n"
            "    bl      sub_fc0c29fc\n"
            "    bl      sub_fc0c2f62\n"
            "    bl      sub_fc0c2d4a\n"
            "    bl      sub_fc0c29b8\n"
            "    bl      sub_fc066a48\n"
            "    bl      sub_fc3691d0\n"
            "    bl      sub_fc0c298a\n"
            "    pop.w   {r4, lr}\n"
            "    b.w     sub_fc0c2dd2\n" // continue in firmware
    );
}

//taskcreate_physw fc0ece46
void __attribute__((naked,noinline))
sub_fc0ece46_my ()
{
    asm volatile (
            //capdis -f=chdk -s=0xfc0ece47 -c=18 -stubs PRIMARY.BIN 0xfc000000
            "    push    {r3, r4, r5, lr}\n"
            "    bl      sub_fc09da2c\n"
            "    bl      sub_fc088902\n"
            "    cbnz    r0, loc_fc0ece56\n"
            "    bl      sub_fc09d9d0\n"
            "loc_fc0ece56:\n"
            "    ldr     r4, =0x000082d8\n"
            "    ldr     r0, [r4, #4]\n"
            "    cmp     r0, #0\n"
            "    bne     loc_fc0ece72\n"
            "    movs    r3, #0\n"
            "    str     r3, [sp]\n"
            "    ldr     r3, =mykbd_task\n" // task_PhySw replacement
            "    movs    r1, #0x17\n"
            "    ldr     r0, =0xfc0ed1c8\n" //  *"PhySw"
            "    movw    r2, #0x2000\n" // original value 0x800
            "    blx     sub_fc34d0b4\n"
            "    str     r0, [r4, #4]\n"
            "loc_fc0ece72:\n"
            "    pop     {r3, r4, r5, pc}\n"
    );
}

//fc157608
void __attribute__((naked,noinline))
init_file_modules_task ()
{
    asm volatile (
            //capdis -f=chdk -s=0xfc157609 -c=18 -stubs PRIMARY.BIN 0xfc000000
            "    push    {r4, r5, r6, lr}\n"
            "    movs    r0, #6\n"
            "    bl      sub_fc368a2c\n"
            "    bl      sub_fc0c994c\n"
            "    movs    r4, r0\n"
            "    movw    r5, #0x5006\n"
            "    beq     loc_fc157624\n"
            "    movs    r1, #0\n"
            "    mov     r0, r5\n"
            "    bl      sub_fc3bd7a8\n"
            "loc_fc157624:\n"
            "    bl      sub_fc0c9976\n"
            "    bl      core_spytask_can_start\n" // + CHDK: Set "it's-safe-to-start" flag for spytask
            "    cmp     r4, #0\n"
            "    bne     loc_fc157638\n"
            "    mov     r0, r5\n"
            "    pop.w   {r4, r5, r6, lr}\n"
            "    movs    r1, #1\n"
            "    b.w     sub_fc3bd7a8\n" // continue in firmware
            "loc_fc157638:\n"
            "    pop     {r4, r5, r6, pc}\n"
    );
}

//fc0ecb7c
void __attribute__((naked,noinline))
kbd_p2_f_my ()
{
    asm volatile(
            //capdis -f=chdk -s=0xfc0ecb7d -c=77 -stubs PRIMARY.BIN 0xfc000000
            "    push.w  {r4, r5, r6, r7, r8, lr}\n"
            "    ldr     r6, =0x0003ef70\n"
            "    sub     sp, #0x18\n"
            "    add     r7, sp, #8\n"
            "    subs    r6, #0xc\n"
            "    b       loc_fc0ecbbe\n"
            "loc_fc0ecb8a:\n"
            "    ldr     r1, =0x0003ef70\n"
            "    add     r3, sp, #8\n"
            "    ldrb.w  r0, [sp, #4]\n"
            "    add     r2, sp, #0x14\n"
            "    subs    r1, #0x18\n"
            "    bl      sub_fc09bb10\n"
            "    cbnz    r0, loc_fc0ecba4\n"
            "    ldr     r1, [sp, #0x14]\n"
            "    movs    r0, #0\n"
            "    bl      sub_fc0ecaee\n"
            "loc_fc0ecba4:\n"
            "    movs    r0, #2\n"
            "loc_fc0ecba6:\n"
            "    ldr.w   r1, [r7, r0, lsl #2]\n"
            "    cbz     r1, loc_fc0ecbb6\n"
            "    ldr.w   r2, [r6, r0, lsl #2]\n"
            "    bics    r2, r1\n"
            "    str.w   r2, [r6, r0, lsl #2]\n"
            "loc_fc0ecbb6:\n"
            "    subs    r0, r0, #1\n"
            "    sxtb    r0, r0\n"
            "    cmp     r0, #0\n"
            "    bge     loc_fc0ecba6\n"
            "loc_fc0ecbbe:\n"
            "    ldr     r0, =0x0003ef70\n"
            "    add     r1, sp, #4\n"
            "    subs    r0, #0xc\n"
            "    bl      sub_fc09b7f6\n"
            "    cmp     r0, #0\n"
            "    bne     loc_fc0ecb8a\n"
            "    ldr.w   r8, =0x0003ef70\n"
            "    movs    r4, #0\n"
            "loc_fc0ecbd2:\n"
            "    movs    r5, #0\n"
            "    ldr.w   r0, [r6, r4, lsl #2]\n"
            "    ldr.w   r1, [r8, r4, lsl #2]\n"
            "    ands    r0, r1\n"
            "    str.w   r0, [r6, r4, lsl #2]\n"
            "    b       loc_fc0ecc2a\n"
            "loc_fc0ecbe4:\n"
            "    lsrs    r0, r5\n"
            "    lsls    r0, r0, #0x1f\n"
            "    beq     loc_fc0ecc22\n"
            "    ldr     r1, =0x0003ef70\n"
            "    add.w   r0, r5, r4, lsl #5\n"
            "    add     r3, sp, #8\n"
            "    subs    r1, #0x18\n"
            "    add     r2, sp, #0x14\n"
            "    uxtb    r0, r0\n"
            "    bl      sub_fc09bb10\n"
            "    cbnz    r0, loc_fc0ecc06\n"
            "    ldr     r1, [sp, #0x14]\n"
            "    movs    r0, #1\n"
            "    bl      sub_fc0ecaee\n"
            "loc_fc0ecc06:\n"
            "    mov     r0, r4\n"
            "    b       loc_fc0ecc1e\n"
            "loc_fc0ecc0a:\n"
            "    ldr.w   r1, [r7, r0, lsl #2]\n"
            "    cbz     r1, loc_fc0ecc1a\n"
            "    ldr.w   r2, [r6, r0, lsl #2]\n"
            "    bics    r2, r1\n"
            "    str.w   r2, [r6, r0, lsl #2]\n"
            "loc_fc0ecc1a:\n"
            "    adds    r0, r0, #1\n"
            "    sxtb    r0, r0\n"
            "loc_fc0ecc1e:\n"
            "    cmp     r0, #3\n"
            "    blt     loc_fc0ecc0a\n"
            "loc_fc0ecc22:\n"
            "    ldr.w   r0, [r6, r4, lsl #2]\n"
            "    adds    r5, r5, #1\n"
            "    uxtb    r5, r5\n"
            "loc_fc0ecc2a:\n"
            "    cmp     r0, #0\n"
            "    bne     loc_fc0ecbe4\n"
            "    adds    r4, r4, #1\n"
            "    sxtb    r4, r4\n"
            "    cmp     r4, #3\n"
            "    blt     loc_fc0ecbd2\n"
            "    bl      sub_fc09b570_my\n" // Patched
            "    add     sp, #0x18\n"
            "    pop.w   {r4, r5, r6, r7, r8, pc}\n"
    );
}

//fc09b570
void __attribute__((naked,noinline))
sub_fc09b570_my ()
{
    asm volatile(
            //capdis -f=chdk -s=0xfc09b571 -c=14 -stubs PRIMARY.BIN 0xfc000000
            "    push    {r4, lr}\n"
            "    ldr     r4, =0x00009c44\n"
            "    ldr     r0, [r4, #0xc]\n"
            "    bl      sub_fc0a3b54\n"
            "    ldr     r0, [r4, #0x10]\n"
            "    bl      sub_fc0a3bde\n"
            "    bl      sub_fc0a3c66\n"
            "    bl      sub_fc10b3f4\n"
            "    ldr     r0, [r4, #0x14]\n"
            "    bl      sub_fc0a3a84\n"
            "    ldr     r0, [r4, #0x18]\n"
            "    bl      sub_fc0a3a84\n"

            "    bl      handle_jogdial\n" // +
            "    cmp     r0, #0\n" // +
            "    beq     no_scroll\n" // +

            "    pop.w   {r4, lr}\n"
            "    b.w     sub_fc0a3fc2\n" // continue in firmware

            "no_scroll:\n" // +
            "    pop     {r4, pc}\n" // +
    );
}

//fc0ed152
void __attribute__((naked,noinline))
kbd_p1_f_cont_my ()
{
    asm volatile(
            //capdis -f=chdk -s=0xfc0ed153 -c=18 -jfw -stubs PRIMARY.BIN 0xfc000000
            "    ldr     r3, =0x0003ef4c\n"
            "    movs    r0, #2\n"
            "    mov     r5, sp\n"
            "    add.w   r6, r3, #0x24\n"
            "loc_fc0ed15c:\n"
            "    add.w   r1, r6, r0, lsl #2\n"
            "    ldr.w   r2, [r3, r0, lsl #2]\n"
            "    ldr     r7, [r1, #0xc]\n"
            "    ldr     r1, [r1, #0x18]\n"
            "    and.w   r2, r2, r7\n"
            "    eor.w   r2, r2, r1\n"
            "    str.w   r2, [r5, r0, lsl #2]\n"
            "    subs    r0, r0, #1\n"
            "    bpl     loc_fc0ed15c\n"
            "    ldr     r2, =0x0003ef4c\n"
            "    mov     r0, sp\n"
            "    adds    r2, #0x18\n"
            "    sub.w   r1, r2, #0xc\n"
            "    bl      sub_fc0ecc40_my\n" // -> some physical status is re-read here (not into physw_status)
            "    ldr     pc, =0xfc0ed187\n" // Continue in firmware
    );
}

extern int physw0_override;

//fc0ecc40
void __attribute__((naked,noinline))
sub_fc0ecc40_my ()
{
    asm volatile(
            //capdis -f=chdk -s=0xfc0ecc41 -c=4 -jfw -stubs PRIMARY.BIN 0xfc000000
            "    push.w  {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, ip, lr}\n"
            "    ldr     r4, =0x0003ef70\n"
            "    mov     r5, r0\n"
            "    ldr     r0, =physw0_override\n" // +
            "    ldr.w   r0, [r0]\n" // + use CHDK override value
            //"    mov.w   r0, #-1\n"           // -
            "    ldr     pc, =0xfc0ecc4d\n" // Continue in firmware
    );
}

void __attribute__((naked,noinline)) task_TricInitTask_my() {
    asm volatile(
            //capdis -f=chdk -s=0xfc542289 -c=35 -stubs PRIMARY.BIN 0xfc000000
            "    push.w  {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, ip, lr}\n"
            "    movs    r0, #8\n"
            "    ldr     r1, =0xfc5424b4\n" //  *"InitTskStart"
            "    bl      sub_fc3b782e\n"
            "    ldr.w   sl, =0x000222dc\n"
            "    movw    fp, #0x1000\n"
            "    ldr     r4, =0x000222d8\n"
            "    movs    r2, #0\n"
            "    ldr     r1, =0x0703870f\n"
            "    ldr     r0, [r4]\n"
            "    blx     sub_fc34d22c\n"
            "    lsls    r0, r0, #0x1f\n"
            "    bne     sub_fc5422ac\n"    // + jump to FW
            "    ldr     r4, =0x000222d8\n"
            "    add     r1, sp, #0xc\n"
            "    ldr     r0, [r4]\n"
            "    blx     sub_fc34d014\n"
            "    ldr     r1, [sp, #0xc]\n"
            "    ldr     r0, [r4]\n"
            "    blx     sub_fc34d1e4\n"
            "    ldr     r0, =0x02000003\n"
            "    ldr     r7, [sp, #0xc]\n"
            "    tst     r7, r0\n"
            "    beq     sub_fc5423c2\n"    // + jump to FW
            "    lsls    r0, r7, #0x1f\n"
            "    beq     sub_fc5422e2\n"    // + jump to FW

            "    ldr     r0, =0xd2020074\n" // +
            "    ldr     r0, [r0]\n"        // + nonzero when core already running
            "    subs    r0, #0\n"          // +
            "    beq     tric1\n"           // +
            "    ldr     r0, [r4]\n"        // +
            "    mov     r1, #0x80\n"       // +
            "    bl      _SetEventFlag\n"   // + core already initialized, set the SmacIdleCmp eventflag here
            "tric1:\n"                      // +

            "    bl      sub_fc542766\n"
            "    b       sub_fc54234e\n"    // + jump to FW
    );
}
