
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"
#include "cache.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

// Forward declarations
extern volatile int jogdial_stopped;
void JogDial_task_my(void);

extern void task_CaptSeq();
extern void task_InitFileModules();
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
// short *jog_position;

/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/

/*************************************************************/
void __attribute__((naked,noinline)) boot() {
    asm volatile ( // capdis -f=chdk -s=0xfc02000d -c=43 PRIMARY.BIN 0xfc000000
"    movw    r0, #0x4000\n"
"    movt    r0, #0\n"
"    mov     sp, r0\n"
"    bl      sub_fc02007e\n"
"    ldr     r2, =0xc0242010\n"
"    ldr     r1, [r2]\n"
"    orr     r1, r1, #1\n"
"    str     r1, [r2]\n"
"    ldr     r0, =0xfceb1908\n"
"    ldr     r1, =0x010e1000\n"
"    ldr     r3, =0x01107d60\n"
"loc_fc02002a:\n"
"    cmp     r1, r3\n"
"    itt     lo\n"
"    ldrlo   r2, [r0], #4\n"
"    strlo   r2, [r1], #4\n"
"    blo     loc_fc02002a\n"
"    ldr     r0, =0x010e1000\n"
"    ldr     r1, =0x00026d60\n"
"    bl      sub_fc1267ca\n"
"    ldr     r0, =0xfced8668\n"
"    ldr     r1, =0xbfe10800\n"
"    ldr     r3, =0xbfe1741d\n"
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
        "add     r2, r0, #8\n"              // two words
"task_hook_loop:\n"
        "ldrh   r3, [r0],#2\n"
        "strh   r3, [r1],#2\n"
        "cmp    r0,r2\n"
        "blo    task_hook_loop\n"

"    ldr     r0, =0xfce645d4\n"
"    ldr     r1, =0x00008000\n"
"    ldr     r3, =0x00055334\n"
"loc_fc02005a:\n"
"    cmp     r1, r3\n"
"    itt     lo\n"
"    ldrlo   r2, [r0], #4\n"
"    strlo   r2, [r1], #4\n"
"    blo     loc_fc02005a\n"
"    ldr     r3, =0x00055334\n"
"    ldr     r1, =0x003d6ffc\n"
"    mov.w   r2, #0\n"
"loc_fc020070:\n"
"    cmp     r3, r1\n"
"    it      lo\n"
"    strlo   r2, [r3], #4\n"
"    blo     loc_fc020070\n"
"    b.w     sub_fc06c500_my\n"                // ->

// CreateTask patch, must be aligned as the original
        ".align  2\n"
"patch_CreateTask:\n"
        "ldr.w   pc, _createtask_my\n"      // Do jump to absolute address CreateTask_my
"_createtask_my:\n"
        ".long   CreateTask_my + 1\n"       // has to be a thumb address
        ".align  1\n"

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

"    LDR     R0, =task_FileWrite\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =filewritetask\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"
*/

"    LDR     R0, =0xFC255E7B\n" // TskCocoa0
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =task_cocoa0\n"
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
"    ldr     r0, =0x8160\n"
"    ldr.w   pc, =(hook_CreateTask + 8 + 1) \n"  // Continue in firmware, thumb bit set
".ltorg\n"
);
}

void __attribute__((naked,noinline)) sub_fc06c500_my() {
    asm volatile ( // capdis -f=chdk -s=0xfc06c501 -c=60 PRIMARY.BIN 0xfc000000
"    push    {r4, lr}\n"
#if defined(CHDK_NOT_IN_CANON_HEAP)
    "ldr     r4, =0x003d6ffc\n"     // heap start, modify here
#else
    "ldr     r4, =new_sa\n"         // +
    "ldr     r4, [r4]\n"            // +
#endif
"    sub     sp, #0x78\n"
"    ldr     r0, =0x0074e000\n"
"    ldr     r1, =0x000b1fec\n"
"    subs    r0, r0, r4\n"
"    cmp     r0, r1\n"
"    bhs     loc_fc06c512\n"
"loc_fc06c510:\n"
"    b       loc_fc06c510\n"
"loc_fc06c512:\n"
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
"    blx     sub_fc314e30\n"
"    ldr     r0, =0x0068e000\n"
"    mov.w   r1, #0xc0000\n"
"    stm.w   sp, {r0, r1, r4}\n"
"    ldr     r1, =0x00680014\n"
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
"    ldr     r1, =sub_fc06c691_my\n" // ->
"    asrs    r0, r0, #4\n"
"    str     r0, [sp, #0x64]\n"
"    lsls    r0, r0, #5\n"
"    str     r0, [sp, #0x68]\n"
"    mov     r0, sp\n"
"    blx     sub_fc314594\n"
"    add     sp, #0x78\n"
"    pop     {r4, pc}\n"
"    .ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc06c691_my() {
    asm volatile ( // capdis -f=chdk -s=0xfc06c691 -c=54 PRIMARY.BIN 0xfc000000
"    push    {r4, lr}\n"
"    ldr     r4, =0xfc06c738\n" //  *"/_term"
"    bl      sub_fc06d938\n"
"    ldr     r0, =0x000080ec\n"
"    ldr     r1, [r0]\n"
"    ldr     r0, =0x00008074\n"
"    ldr     r0, [r0]\n"
"    adds    r0, #0x10\n"
"    cmp     r1, r0\n"
"    bhs     loc_fc06c6ac\n"
"    ldr     r0, =0xfc06c748\n" //  *"USER_MEM size checking"
"    bl      sub_fc06c722\n"
"loc_fc06c6ac:\n"
"    bl      sub_fc1268a4\n"
"    ldr     r1, =0xbfe10000\n"
"    mov.w   r2, #0xeeeeeeee\n"
"    ldr     r3, =0xbfe10800\n"
"loc_fc06c6b8:\n"
"    stm     r1!, {r2}\n"
"    cmp     r1, r3\n"
"    blo     loc_fc06c6b8\n"
"    bl      sub_fc1268b6\n"
"    bl      sub_fc1eb838\n"
"    cmp     r0, #0\n"
"    bge     loc_fc06c6d0\n"
"    ldr     r0, =0xfc06c768\n" //  *"dmSetup"
"    bl      sub_fc06c722\n"
"loc_fc06c6d0:\n"
"    bl      sub_fc06cedc\n"
"    cmp     r0, #0\n"
"    bge     loc_fc06c6de\n"
"    ldr     r0, =0xfc06c770\n" //  *"termDriverInit"
"    bl      sub_fc06c722\n"
"loc_fc06c6de:\n"
"    mov     r0, r4\n"
"    bl      sub_fc06cf6a\n"
"    cmp     r0, #0\n"
"    bge     loc_fc06c6ee\n"
"    ldr     r0, =0xfc06c780\n" //  *"termDeviceCreate"
"    bl      sub_fc06c722\n"
"loc_fc06c6ee:\n"
"    mov     r0, r4\n"
"    bl      sub_fc06c8cc\n"
"    cmp     r0, #0\n"
"    bge     loc_fc06c6fe\n"
"    ldr     r0, =0xfc06c794\n" //  *"stdioSetup"
"    bl      sub_fc06c722\n"
"loc_fc06c6fe:\n"
"    bl      sub_fc06ca10\n"
"    cmp     r0, #0\n"
"    bge     loc_fc06c70c\n"
"    ldr     r0, =0xfc06c7a0\n" //  *"stdlibSetup"
"    bl      sub_fc06c722\n"
"loc_fc06c70c:\n"
"    bl      sub_fc1268f8\n"
"    cmp     r0, #0\n"
"    bge     loc_fc06c71a\n"
"    ldr     r0, =0xfc06c7ac\n" //  *"extlib_setup"
"    bl      sub_fc06c722\n"
"loc_fc06c71a:\n"
"    pop.w   {r4, lr}\n"
"    b.w     sub_fc06ca9a_my\n"     // -> continue (taskcreate_startup)
"    .ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc06ca9a_my() {
    asm volatile ( // capdis -f=chdk -s=0xfc06ca9b -c=20 PRIMARY.BIN 0xfc000000
"    push    {r3, lr}\n"
"    bl      sub_fc06cba0\n"
"    bl      sub_fc07ea92\n"
"    bl      sub_fc08c9c8\n"
"    cbnz    r0, loc_fc06cab0\n"
"    bl      sub_fc06cb8e\n"
"loc_fc06caae:\n"
"    b       loc_fc06caae\n"
"loc_fc06cab0:\n"
"    blx     sub_fc3145ec\n"
"    ldr     r1, =0x0074e000\n"
"    movs    r0, #0\n"
"    bl      sub_fc38cd24\n"
"    movs    r3, #0\n"
"    str     r3, [sp]\n"
"    ldr     r3, =sub_fc06ca35_my\n" //  task_Startup
"    movs    r2, #0\n"
"    movs    r1, #0x19\n"
"    ldr     r0, =0xfc06cad8\n" //  *"Startup"
"    blx     sub_fc314b28\n"
"    movs    r0, #0\n"
"    pop     {r3, pc}\n"
    ".ltorg\n"
    );
}

// task_Startup
void __attribute__((naked,noinline)) sub_fc06ca35_my() {
    asm volatile ( // capdis -f=chdk -s=0xfc06ca35 -c=26 PRIMARY.BIN 0xfc000000
"    push    {r4, lr}\n"
"    bl      sub_fc127668\n"
"    bl      sub_fc06cb6c\n"
"    bl      sub_fc06cccc\n"
"    bl      sub_fc0f947c\n"
//"    bl      sub_fc06cd28\n"      // - startdiskboot

"    bl      sub_10e173c\n"         // + switch off card, trial

"    bl      sub_fc37255e\n"
"    bl      sub_fc0f95d4\n"
"    bl      sub_fc06ce1c\n"
"    bl      sub_fc06cc5c\n"
"    bl      sub_fc0f94ae\n"
"    bl      sub_fc1ebfec\n"
"    bl      sub_fc0f95da\n"
//"    bl      sub_fc08c8ee\n"      // -
"    bl      sub_fc08c8ee_my\n"     // -> taskcreate_physw
"    bl      CreateTask_spytask\n"  // +
"    bl      init_required_fw_features\n" // +
"    bl      sub_fc2a51a2\n"
"    bl      sub_fc0f95f0\n"
"    bl      sub_fc0d1748\n"
"    bl      sub_fc127236\n"
"    bl      sub_fc127816\n"
"    bl      sub_fc1275b6\n"
"    bl      sub_fc1271f2\n"
"    bl      sub_fc06ce20\n"
"    bl      sub_fc363828\n"
"    bl      sub_fc1271c6\n"
"    bl      sut_done \n"           // + CHDK: startuptask (almost) finished - port specific function
"    pop.w   {r4, lr}\n"
"    b.w     sub_fc12763e\n"
    ".ltorg\n"
    );
}

/*
    *** workaround ***
    Init stuff to avoid asserts on cameras running DryOS r54+
    Execute this only once
 */
void init_required_fw_features(void) {
    extern int _CreateBinarySemaphore(int, int);

    // aperture related semaphore
    *(int*)0x2E804 = _CreateBinarySemaphore(0, 0);
    // focuslens related semaphore (may not be needed as sd override does not work)
    *(int*)(0x2E7E0+0xC) = _CreateBinarySemaphore(0, 0);
}

//taskcreate_physw
void __attribute__((naked,noinline)) sub_fc08c8ee_my() {
    asm volatile ( // capdis -f=chdk -s=0xfc08c8ef -c=18 PRIMARY.BIN 0xfc000000
"    push    {r3, r4, r5, lr}\n"
"    bl      sub_fc08029c\n"
"    bl      sub_fc07ea10\n"
"    cbnz    r0, loc_fc08c8fe\n"
"    bl      sub_fc080240\n"
"loc_fc08c8fe:\n"
"    ldr     r4, =0x000082cc\n"
"    ldr     r0, [r4, #4]\n"
"    cmp     r0, #0\n"
"    bne     loc_fc08c91a\n"
"    movs    r3, #0\n"
"    str     r3, [sp]\n"
"    ldr     r3, =mykbd_task\n"     // original: 0xfc08c8c9, task_PhySw
"    movs    r1, #0x17\n"
"    ldr     r0, =0xfc08cc2c\n"     //  *"PhySw"
"    movw    r2, #0x2000\n"         // original: 0x800
"    blx     sub_fc314cc0\n"
"    str     r0, [r4, #4]\n"
"loc_fc08c91a:\n"
"    pop     {r3, r4, r5, pc}\n"
    ".ltorg\n"
    );
}

void __attribute__((naked,noinline)) init_file_modules_task() {
    asm volatile ( // capdis -stubs -f=chdk -s=task_InitFileModules -c=18 PRIMARY.BIN 0xfc000000
// task_InitFileModules 0xfc0d4a01
"    push    {r4, r5, r6, lr}\n"
"    movs    r0, #6\n"
"    bl      sub_fc363076\n"
"    bl      sub_fc138bc0\n"
"    movs    r4, r0\n"
"    movw    r5, #0x5006\n"
"    beq     loc_fc0d4a1c\n"
"    movs    r1, #0\n"
"    mov     r0, r5\n"
"    bl      sub_fc385930\n" // PostLogicalEventToUI_FW
"loc_fc0d4a1c:\n"
"    bl      sub_fc138bea\n"
"    BL      ifm_done\n"            // + CHDK: file modules inited (port specific function)
"    cmp     r4, #0\n"
"    bne     loc_fc0d4a30\n"
"    mov     r0, r5\n"
"    pop.w   {r4, r5, r6, lr}\n"
"    movs    r1, #1\n"
"    b.w     sub_fc385930\n" // PostLogicalEventToUI_FW
"loc_fc0d4a30:\n"
"    pop     {r4, r5, r6, pc}\n"
    ".ltorg\n"
    );
}

void __attribute__((naked,noinline)) kbd_p2_f_my() {
    asm volatile( // capdis -stubs -f=chdk -s=kbd_p2_f -c=77 PRIMARY.BIN 0xfc000000
// kbd_p2_f 0xfc08c625
"    push.w  {r4, r5, r6, r7, r8, lr}\n"
"    ldr     r6, =0x00056c10\n"
"    sub     sp, #0x18\n"
"    add     r7, sp, #8\n"
"    subs    r6, #0xc\n"
"    b       loc_fc08c666\n"
"loc_fc08c632:\n"
"    ldr     r1, =0x00056c10\n"
"    add     r3, sp, #8\n"
"    ldrb.w  r0, [sp, #4]\n"
"    add     r2, sp, #0x14\n"
"    subs    r1, #0x18\n"
"    bl      sub_fc07f358\n"
"    cbnz    r0, loc_fc08c64c\n"
"    ldr     r1, [sp, #0x14]\n"
"    movs    r0, #0\n"
"    bl      sub_fc08c596\n"
"loc_fc08c64c:\n"
"    movs    r0, #2\n"
"loc_fc08c64e:\n"
"    ldr.w   r1, [r7, r0, lsl #2]\n"
"    cbz     r1, loc_fc08c65e\n"
"    ldr.w   r2, [r6, r0, lsl #2]\n"
"    bics    r2, r1\n"
"    str.w   r2, [r6, r0, lsl #2]\n"
"loc_fc08c65e:\n"
"    subs    r0, r0, #1\n"
"    sxtb    r0, r0\n"
"    cmp     r0, #0\n"
"    bge     loc_fc08c64e\n"
"loc_fc08c666:\n"
"    ldr     r0, =0x00056c10\n"
"    add     r1, sp, #4\n"
"    subs    r0, #0xc\n"
"    bl      sub_fc07f072\n"
"    cmp     r0, #0\n"
"    bne     loc_fc08c632\n"
"    ldr.w   r8, =0x00056c10\n"
"    movs    r4, #0\n"
"loc_fc08c67a:\n"
"    movs    r5, #0\n"
"    ldr.w   r0, [r6, r4, lsl #2]\n"
"    ldr.w   r1, [r8, r4, lsl #2]\n"
"    ands    r0, r1\n"
"    str.w   r0, [r6, r4, lsl #2]\n"
"    b       loc_fc08c6d2\n"
"loc_fc08c68c:\n"
"    lsrs    r0, r5\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc08c6ca\n"
"    ldr     r1, =0x00056c10\n"
"    add.w   r0, r5, r4, lsl #5\n"
"    add     r3, sp, #8\n"
"    subs    r1, #0x18\n"
"    add     r2, sp, #0x14\n"
"    uxtb    r0, r0\n"
"    bl      sub_fc07f358\n"
"    cbnz    r0, loc_fc08c6ae\n"
"    ldr     r1, [sp, #0x14]\n"
"    movs    r0, #1\n"
"    bl      sub_fc08c596\n"
"loc_fc08c6ae:\n"
"    mov     r0, r4\n"
"    b       loc_fc08c6c6\n"
"loc_fc08c6b2:\n"
"    ldr.w   r1, [r7, r0, lsl #2]\n"
"    cbz     r1, loc_fc08c6c2\n"
"    ldr.w   r2, [r6, r0, lsl #2]\n"
"    bics    r2, r1\n"
"    str.w   r2, [r6, r0, lsl #2]\n"
"loc_fc08c6c2:\n"
"    adds    r0, r0, #1\n"
"    sxtb    r0, r0\n"
"loc_fc08c6c6:\n"
"    cmp     r0, #3\n"
"    blt     loc_fc08c6b2\n"
"loc_fc08c6ca:\n"
"    ldr.w   r0, [r6, r4, lsl #2]\n"
"    adds    r5, r5, #1\n"
"    uxtb    r5, r5\n"
"loc_fc08c6d2:\n"
"    cmp     r0, #0\n"
"    bne     loc_fc08c68c\n"
"    adds    r4, r4, #1\n"
"    sxtb    r4, r4\n"
"    cmp     r4, #3\n"
"    blt     loc_fc08c67a\n"
"    bl      sub_fc07eeac_my\n"     // ->
"    add     sp, #0x18\n"
"    pop.w   {r4, r5, r6, r7, r8, pc}\n"
".ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc07eeac_my() {
    asm volatile( // capdis -stubs -f=chdk -s=0xfc07eead -c=12 PRIMARY.BIN 0xfc000000
"    push    {r4, lr}\n"
"    ldr     r4, =0x00009bd0\n"
"    subs    r4, #0x1c\n"
"    ldr     r0, [r4, #0xc]\n"
"    bl      sub_fc0804c0\n"
"    ldr     r0, [r4, #0x10]\n"
"    bl      sub_fc08054a\n"
"    bl      sub_fc17a004\n"
"    ldr     r0, [r4, #0x14]\n"
"    bl      sub_fc0803f0\n"
//"    pop.w   {r4, lr}\n"          // -
//"    b.w     sub_fc0c3b3c\n"      // -
"    bl      handle_jogdial\n"      // +
"    cmp     r0, #0\n"              // +
"    beq     no_scroll\n"           // +
"    bl      sub_fc0c3b3c\n"        // handles scrollwheel(s), void function, no args
"no_scroll:\n"                      // +
"    pop     {r4, pc}\n"            // +
".ltorg\n"
    );
}

void __attribute__((naked,noinline)) kbd_p1_f_cont_my() {
    asm volatile( // capdis -stubs -f=chdk -s=kbd_p1_f_cont -c=41 PRIMARY.BIN 0xfc000000
// kbd_p1_f_cont 0xfc08cbb5
"    ldr     r3, =0x00056bec\n"
"    movs    r0, #2\n"
"    mov     r5, sp\n"
"    add.w   r6, r3, #0x24\n"
"loc_fc08cbbe:\n"
"    add.w   r1, r6, r0, lsl #2\n"
"    ldr.w   r2, [r3, r0, lsl #2]\n"
"    ldr     r7, [r1, #0xc]\n"
"    ldr     r1, [r1, #0x18]\n"
"    and.w   r2, r2, r7\n"
"    eor.w   r2, r2, r1\n"
"    str.w   r2, [r5, r0, lsl #2]\n"
"    subs    r0, r0, #1\n"
"    bpl     loc_fc08cbbe\n"
"    bl      xtra_kbd_cb \n"            // +
"    mov     r3, r0 \n"                 // +
"    ldr     r2, =0x00056bec\n"
"    mov     r0, sp\n"
"    adds    r2, #0x18\n"
"    sub.w   r1, r2, #0xc\n"
"    bl      sub_fc08c6e8_my\n"         // -> some physical status is re-read here (not into physw_status)
"    ldr     r0, =0x00056bec\n"
"    adds    r0, #0xc\n"
"    bl      sub_fc07ee60\n"
"    cmp     r0, #1\n"
"    bne     loc_fc08cbf6\n"
"    movs    r4, #1\n"
"loc_fc08cbf6:\n"
"    ldr     r2, =0x00056bec\n"
"    movs    r0, #2\n"
"    adds    r2, #0x18\n"
"    sub.w   r3, r2, #0xc\n"
"loc_fc08cc00:\n"
"    ldr.w   r1, [r2, r0, lsl #2]\n"
"    cbz     r1, loc_fc08cc1a\n"
"    ldr.w   r4, [r3, r0, lsl #2]\n"
"    ldr.w   r6, [r5, r0, lsl #2]\n"
"    bics    r4, r1\n"
"    ands    r1, r6\n"
"    orrs    r4, r1\n"
"    str.w   r4, [r3, r0, lsl #2]\n"
"    movs    r4, #1\n"
"loc_fc08cc1a:\n"
"    subs    r0, r0, #1\n"
"    bpl     loc_fc08cc00\n"
"    mov     r0, r4\n"
"    pop     {r1, r2, r3, r4, r5, r6, r7, pc}\n"
".ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc08c6e8_my() {
    asm volatile( // capdis -stubs -f=chdk -s=0xfc08c6e9 -c=4 PRIMARY.BIN 0xfc000000
"    push.w  {r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, fp, ip, lr}\n"
"    ldr     r4, =0x00056c10\n"
"    mov     r5, r0\n"
//"    mov.w   r0, #-1\n"               // - should be (physw_status[1] & 0x41fe9) when overriding, -1 otherwise
"    mov     r0, r3 \n"                 // + (new argument to allow passing our variable)
"    b       sub_fc08c6f4\n"            // jump back to ROM
    );
}

