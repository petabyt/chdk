#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"
#include "gui_draw.h"
#include "asmsafe.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;
extern volatile int jogdial_stopped;

// Forward declarations

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_RotaryEncoder();
extern void task_MovieRecord();
extern void task_ExpDrv();

void JogDial_task_my(void);


/*----------------------------------------------------------------------
    spytask
-----------------------------------------------------------------------*/
void spytask(long ua, long ub, long uc, long ud, long ue, long uf)
{
    core_spytask();
}

void CreateTask_spytask()
{
    _CreateTask("SpyTask", 0x19, 0x2000, spytask, 0);
}

#ifdef DEBUG_BLINKING

    // ASM_SAFE("BL xblinker\n")
    #define LED_PR     0xd20b0994       // G16 green LED on OVF bezel   
    #define LED_PWR    0xd20b0884       // G16 green LED on power button
    #define LED_ORANGE 0xd20b0888       // G16 orange LED on OVF bezel   
    #define XDELAY 4000000 

    void xblinker() 
    {
        int j = 2;
        while(j-- > 0) {
            int i;
            *(volatile int*)LED_ORANGE = 0x4d0002;
            for(i=0;i<XDELAY/10;i++) {
                asm volatile(
                "nop\n"
                );
            }
            *(volatile int*)LED_ORANGE = 0x4c0003;
            for(i=0;i<XDELAY;i++) {
                asm volatile(
                "nop\n"
                );
            }
        }
    }

    /*----------------------------------------------------------------------
      blinker
    -----------------------------------------------------------------------*/

    void draw_pixel_std(unsigned int , unsigned short );

    void __attribute__((naked,noinline)) blinker() {

        int led_count = 50 ;
        unsigned int pxl;

        _SleepTask(2000);

        while(1)
        {
            switch led_count
            {
                case 3 :
                    *(volatile int*)0xd20b0994 = 0x4d0002;
                    break ;
                case 2 :
                    *(volatile int*)0xd20b0994 = 0x4c0003;
                    break ;
                case 1 :
                    *(volatile int*)0xd20b0994 = 0x4d0002;
                    break ;
                case 0 :
                   led_count = 21 ;
                   *(volatile int*)0xd20b0994 = 0x4c0003;

                    for (pxl=0 ; pxl<0x3FFF ; pxl++)
                    {
                        draw_pixel_std(pxl, MAKE_COLOR(COLOR_GREEN,COLOR_GREEN)) ;
                    }
                    break ;
                default :
                    break ;
            }
            led_count-- ;
            _SleepTask(100);
        }
    };

    void CreateTask_blinker() {
            _CreateTask("Blinker", 0x1, 0x200, blinker, 0);
    };
#endif


/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/
// G16 1.01b  0xfc02000d 33
void __attribute__((naked,noinline)) boot() {
    asm volatile (
"    ldr.w   sp, =0x80010000\n"

    #ifdef DEBUG_BLINKING
    ASM_SAFE("BL xblinker\n")
    #endif

"    bl      sub_fc020064\n"
"    ldr     r2, =0xc0242010\n"
"    ldr     r1, [r2]\n"
"    orr     r1, r1, #1\n"
"    str     r1, [r2]\n"
"    ldr     r0, =0xfcbebb70\n"   // code copied from ROM to RAM
"    ldr     r1, =0x010c1000\n"   // 
"    ldr     r3, =0x010df4e8\n"   //
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
        "add     r2, r0, #8\n"              // two words
"task_hook_loop:\n"
        "ldrh   r3, [r0],#2\n"
        "strh   r3, [r1],#2\n"
        "cmp    r0,r2\n"
        "blo    task_hook_loop\n"

"    ldr     r0, =0x010c1000\n"
"    ldr     r1, =0x0001e4e8\n"
"    bl      sub_fc13c50e\n"
"    ldr     r0, =0xfcbc22d0\n"
"    ldr     r1, =0x00008000\n"
"    ldr     r3, =0x000318a0\n"
"loc_fc020040:\n"
"    cmp     r1, r3\n"
"    itt     lo\n"
"    ldrlo   r2, [r0], #4\n"
"    strlo   r2, [r1], #4\n"
"    blo     loc_fc020040\n"
"    ldr     r3, =0x000318a0\n"
"    ldr     r1, =0x003077e0\n"
"    mov.w   r2, #0\n"
"loc_fc020056:\n"
"    cmp     r3, r1\n"
"    it      lo\n"
"    strlo   r2, [r3], #4\n"
"    blo     loc_fc020056\n"
"    b.w     sub_fc05e00c_my\n"   // --->>

"patch_CreateTask:\n"
"    ldr.w   pc, [pc,#0]\n"             // Do jump to absolute address CreateTask_my
"    .long   CreateTask_my + 1\n"       // has to be a thumb address
);
}

void __attribute__((naked,noinline)) CreateTask_my() {
    asm volatile (
"    push   {r0}\n"
                                        // R3 = Pointer to task function to create
"    ldr     r0, =task_CaptSeq\n"       // DryOS original code function ptr.
"    cmp     r0, r3\n"                  // is the given taskptr equal to our searched function?
"    itt     eq\n"                      // EQ block
"    ldreq   r3, =capt_seq_task\n"      // if so replace with our task function base ptr.
"    orreq   r3, #1\n"                  // make sure it's a thumb address (may not be needed?)
"    beq     exitHook\n"                // below compares not necessary if this check has found something.
                                        //
"    LDR     R0, =task_ExpDrv\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =exp_drv_task\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"

"    ldr     r0, =task_InitFileModules\n"
"    cmp     r0, r3\n"
"    itt     eq\n"
"    ldreq   r3, =init_file_modules_task\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"

"    LDR     R0, =task_FileWrite\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =filewritetask\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"

/* FIXME

"    LDR     R0, =task_DvlpSeqTask\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =developseq_task\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"

"    LDR     R0, =task_MovieRecord\n" // NOTE : no video task hook for DIGIC6 cameras
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =movie_record_task\n"
"    BEQ     exitHook\n"

*/

"exitHook:\n"
"    pop    {r0}\n"     // restore overwritten register & execute overwritten instructions from original code
"    stmdb   sp!, {r1, r2, r3, r4, r5, r6, r7, r8, r9, lr}\n"
"    mov     r4, r0\n"
"    ldr     r0, =0x8158\n"
"    ldr.w   pc, =(hook_CreateTask + 8 + 1) \n"  // Continue in firmware, thumb bit set   
".ltorg\n"
);
}

// G16 1.01b  0xfc05e00d 61
void __attribute__((naked,noinline)) sub_fc05e00c_my() {
    asm volatile (
// no GPIO checks needed with 0x12345678 set, native fw handles long press
"    push    {r4, lr}\n"
#if defined(CHDK_NOT_IN_CANON_HEAP)
"    ldr     r4, =0x003077e0\n"         // heap start, modify here
#else
    "ldr     r4, =new_sa\n"             // +
    "ldr     r4, [r4]\n"                // +
#endif
"    sub     sp, #0x78\n"
"    ldr     r0, =0x006ce000\n"
"    ldr     r1, =0x0008eb94\n"
"    subs    r0, r0, r4\n"
"    cmp     r0, r1\n"
"    bhs     loc_fc05e01e\n"
"loc_fc05e01c:\n"
"    b       loc_fc05e01c\n"
"loc_fc05e01e:\n"
"    ldr     r1, =0x00008074\n"
"    mov.w   r0, #0x80000\n"
"    str     r0, [r1]\n"
"    ldr     r1, =0x00008078\n"
"    ldr     r0, =0x42b21000\n"
"    str     r0, [r1]\n"
"    ldr     r1, =0x0000807c\n"
"    ldr     r0, =0x42b23000\n"
"    str     r0, [r1]\n"
"    movs    r1, #0x74\n"
"    add     r0, sp, #4\n"
"    blx     sub_fc2a16d8\n" // j_bzero
"    add     r2, sp, #4\n"
"    ldr     r0, =0x0062e000\n"
"    mov.w   r1, #0xa0000\n"
"    stm     r2!, {r0, r1, r4}\n"
"    ldr     r1, =0x0062346c\n" //  *"l4b"
"    str     r0, [sp, #0x18]\n"
"    movs    r0, #0x22\n"
"    subs    r2, r1, r4\n"
"    str     r0, [sp, #0x1c]\n"
"    movs    r0, #0x98\n"
"    str     r0, [sp, #0x20]\n"
"    strd    r2, r1, [sp, #0x10]\n"
"    movw    r0, #0x1e8\n"
"    str     r0, [sp, #0x24]\n"
"    movs    r0, #0xfa\n"
"    str     r0, [sp, #0x28]\n"
"    movs    r0, #0xb6\n"
"    str     r0, [sp, #0x2c]\n"
"    movs    r0, #0x85\n"
"    str     r0, [sp, #0x30]\n"
"    movs    r0, #0x40\n"
"    str     r0, [sp, #0x34]\n"
"    movs    r0, #4\n"
"    str     r0, [sp, #0x38]\n"
"    movs    r0, #0\n"
"    str     r0, [sp, #0x3c]\n"
"    movs    r0, #0x10\n"
"    str     r0, [sp, #0x60]\n"
//"    ldr     r1, =0xfc05e19d\n"
"    ldr     r1, =sub_fc05e19d_my\n"    // -->>
"    movs    r2, #0\n"
"    lsls    r0, r0, #8\n"
"    str     r0, [sp, #0x64]\n"
"    asrs    r0, r0, #4\n"
"    str     r0, [sp, #0x68]\n"
"    lsls    r0, r0, #5\n"
"    str     r0, [sp, #0x6c]\n"
"    add     r0, sp, #4\n"
"    blx     sub_fc2a0d38\n"
"    add     sp, #0x78\n"
"    pop     {r4, pc}\n"

".ltorg\n"
);
}

// G16 1.01b  0xfc05e19d 54
void __attribute__((naked,noinline)) sub_fc05e19d_my() {
    asm volatile (
"    push    {r4, lr}\n"
"    ldr     r4, =0xfc05e248\n" //  *"/_term"
"    bl      sub_fc05f3c8\n"
"    ldr     r0, =0x000080ec\n"
"    ldr     r1, [r0]\n"
"    ldr     r0, =0x00008074\n"
"    ldr     r0, [r0]\n"
"    adds    r0, #0x10\n"
"    cmp     r1, r0\n"
"    bhs     loc_fc05e1b8\n"
"    ldr     r0, =0xfc05e258\n" //  *"USER_MEM size checking"
"    bl      sub_fc05e230\n"
"loc_fc05e1b8:\n"
"    bl      sub_fc13c5e8\n"
"    ldr     r3, =0x80000800\n"
"    mov.w   r1, #-0x80000000\n"
"    mov.w   r2, #-0x11111112\n"
"loc_fc05e1c6:\n"
"    stm     r1!, {r2}\n"
"    cmp     r1, r3\n"
"    blo     loc_fc05e1c6\n"
"    bl      sub_fc13c5fa\n"
"    bl      sub_fc13cba4\n"
"    cmp     r0, #0\n"
"    bge     loc_fc05e1de\n"
"    ldr     r0, =0xfc05e274\n" //  *"dmSetup"
"    bl      sub_fc05e230\n"
"loc_fc05e1de:\n"
"    bl      sub_fc05ea08\n"
"    cmp     r0, #0\n"
"    bge     loc_fc05e1ec\n"
"    ldr     r0, =0xfc05e27c\n" //  *"termDriverInit"
"    bl      sub_fc05e230\n"
"loc_fc05e1ec:\n"
"    mov     r0, r4\n"
"    bl      sub_fc05ea9c\n"
"    cmp     r0, #0\n"
"    bge     loc_fc05e1fc\n"
"    ldr     r0, =0xfc05e28c\n" //  *"termDeviceCreate"
"    bl      sub_fc05e230\n"
"loc_fc05e1fc:\n"
"    mov     r0, r4\n"
"    bl      sub_fc05e3d4\n"
"    cmp     r0, #0\n"
"    bge     loc_fc05e20c\n"
"    ldr     r0, =0xfc05e2a0\n" //  *"stdioSetup"
"    bl      sub_fc05e230\n"
"loc_fc05e20c:\n"
"    bl      sub_fc05e518\n"
"    cmp     r0, #0\n"
"    bge     loc_fc05e21a\n"
"    ldr     r0, =0xfc05e2ac\n" //  *"stdlibSetup"
"    bl      sub_fc05e230\n"
"loc_fc05e21a:\n"
"    bl      sub_fc0617d0\n"
"    cmp     r0, #0\n"
"    bge     loc_fc05e228\n"
"    ldr     r0, =0xfc05e2b8\n" //  *"extlib_setup"
"    bl      sub_fc05e230\n"
"loc_fc05e228:\n"
"    pop.w   {r4, lr}\n"
"    b.w     sub_fc05e5a2_my\n"  // --->>

".ltorg\n"
    );
}

// G16 1.01b  0xffc05e5a3 27
void __attribute__((naked,noinline)) sub_fc05e5a2_my() {
    asm volatile (
"    push    {r3, lr}\n"
"    bl      sub_fc05e6a4\n"
"    bl      sub_fc0b5a00\n"
"    cbnz    r0, loc_fc05e5b8\n"
"    bl      sub_fc07e9a8\n" // IsNormalCameraMode_FW
"    cbz     r0, loc_fc05e5b8\n"
"    movs    r0, #1\n"
"    b       loc_fc05e5ba\n"
"loc_fc05e5b8:\n"
"    movs    r0, #0\n"
"loc_fc05e5ba:\n"
"    bl      sub_fc070e98\n" // power-on mode handling & startupchecks here, no override needed with 0x12345678 set
"    cbnz    r0, loc_fc05e5c6\n"
"    bl      sub_fc05e692\n"
"loc_fc05e5c4:\n"
"    b       loc_fc05e5c4\n"
"loc_fc05e5c6:\n"
"    blx     sub_fc2a0d90\n"
"    ldr     r1, =0x006ce000\n"
"    movs    r0, #0\n"
"    bl      sub_fc30d864\n"
"    blx     sub_fc2a12c8\n"
"    movs    r3, #0\n"
"    str     r3, [sp]\n"
//"    ldr     r3, =0xfc05e53d\n" //  task_Startup
"    ldr     r3, =task_Startup_my\n"   //  --->>
"    movs    r2, #0\n"
"    movs    r1, #0x19\n"
"    ldr     r0, =0xfc05e5f4\n" //  *"Startup"
"    blx     sub_fc2a12e8\n" // j_CreateTask
"    movs    r0, #0\n"
"    pop     {r3, pc}\n"

".ltorg\n"
    );
}

// G16 1.01b  0xfc05e53d 26
// task_Startup 0xfc05e53d
void __attribute__((naked,noinline)) task_Startup_my() {
    asm volatile (
"    push    {r4, lr}\n"
"    bl      sub_fc0e4714\n"
"    bl      sub_fc05e670\n"
"    bl      sub_fc05e7e4\n"
"    bl      sub_fc0e47ac\n"
//"  bl      sub_fc05e83a\n"              //  startdiskboot commented out to avoid infinite boot loop

// added for SD card UHS detection https://chdk.setepontos.com/index.php?topic=13089.msg132583#msg132583
"    bl      sub_fc08f5b8\n"             // + switch off card per m10 and g7x ports

"    bl      sub_fc0895ae\n"
"    bl      sub_fc0e48f0\n"
"    bl      sub_fc05e948\n"
"    bl      sub_fc05e780\n"
"    bl      sub_fc0e47ea\n"
"    bl      sub_fc0999fc\n"
"    bl      sub_fc0e48f6\n"
//"    bl      sub_fc070d8a\n"
"    bl      sub_fc070d8a_my\n"            // CreateTask PhySw

#if defined(OPT_RUN_WITH_BATT_COVER_OPEN)
"    LDR     R0, =0x1C0000\n"              // Pause for startup with battery door open
"batt_delay:\n"
"    NOP\n"
"    SUBS    R0,R0,#1\n"
"    BNE     batt_delay\n"
#endif
"    bl      CreateTask_spytask\n"
//"    bl      init_required_fw_features\n" // added
#ifdef DEBUG_BLINKING
"    bl      CreateTask_blinker\n"
#endif

"    bl      sub_fc254046\n"
"    bl      sub_fc0e490c\n"
"    bl      sub_fc0b57a4\n"
"    bl      sub_fc0e44fc\n"
"    bl      sub_fc0b58d0\n"
"    bl      sub_fc0999ae\n"
"    bl      sub_fc0e44bc\n"
"    bl      sub_fc05e94c\n"
"    bl      sub_fc307d98\n"
"    bl      sub_fc0e4496\n"
"    pop.w   {r4, lr}\n"
"    b.w     sub_fc0e46ea\n"

".ltorg\n"
    );
}

// G16 1.01b  0xfc070d8b 18 = taskcreate_physw
void __attribute__((naked,noinline)) sub_fc070d8a_my() {
    asm volatile (
"    push    {r3, r4, r5, lr}\n"
"    bl      sub_fc0701d8\n"
"    bl      sub_fc07e932\n"        // IsFactoryMode_FW
"    cbnz    r0, loc_fc070d9a\n"
"    bl      sub_fc07017c\n"        // OpLog.Start_FW
"loc_fc070d9a:\n"
"    ldr     r4, =0x00008324\n"     //  physw_run
"    ldr     r0, [r4, #4]\n"
"    cmp     r0, #0\n"
"    bne     loc_fc070db6\n"
"    movs    r3, #0\n"
"    str     r3, [sp]\n"
//  "    ldr     r3, =0xfc070d65\n" //  task_PhySw
"    ldr     r3, =mykbd_task\n"     //   --->>
"    movs    r1, #0x17\n"
"    ldr     r0, =0xfc070de4\n"     //  *"PhySw"
"    movw    r2, #0x2000\n"         // stack adjusted from 0x800 to 0x2000
"    blx     sub_fc2a1620\n"        // j_CreateTaskStrictly
"    str     r0, [r4, #4]\n"
"loc_fc070db6:\n"
"    pop     {r3, r4, r5, pc}\n"

".ltorg\n"
    );
}

// G16 1.01b  0xfc0b9259 16
// task_InitFileModules 0xfc0b9259
void __attribute__((naked,noinline)) init_file_modules_task() {
    asm volatile (
"    push    {r4, r5, r6, lr}\n"
"    bl      sub_fc0bba04\n"
"    movs    r4, r0\n"
"    movw    r5, #0x5006\n"
"    beq     loc_fc0b926e\n"
"    movs    r1, #0\n"
"    mov     r0, r5\n"
"    bl      _PostLogicalEventToUI\n"
"loc_fc0b926e:\n"
"    bl      sub_fc0bba32\n"
"    bl      core_spytask_can_start\n" // + CHDK: Set "it's-safe-to-start" flag for spytask
"    cmp     r4, #0\n"
"    bne     loc_fc0b9282\n"
"    mov     r0, r5\n"
"    pop.w   {r4, r5, r6, lr}\n"
"    movs    r1, #0\n"
"    b.w     _PostLogicalEventToUI\n"
"loc_fc0b9282:\n"
"    pop     {r4, r5, r6, pc}\n"

".ltorg\n"
    );
}

/*
    *** Workarounds ***
    Stuff to avoid asserts on cameras running DryOS r54+
    Note : G16 runs DryOS r52 so this hooked but not needed. See : https://chdk.setepontos.com/index.php?topic=12516.0
*/
/* FIXME if necessary
void init_required_fw_features(void) {

    extern void _init_focus_eventflag();
    _init_focus_eventflag();

    extern void _init_nd_eventflag();
    extern void _init_nd_semaphore();
    _init_nd_eventflag();
    _init_nd_semaphore();

    extern int av_override_semaphore;
    extern int _CreateBinarySemaphoreStrictly(int x, int y);
    av_override_semaphore = _CreateBinarySemaphoreStrictly(0,0);
}
*/

// G16 1.01b  0xfc070b31 77
void __attribute__((naked,noinline)) kbd_p2_f_my() {
    asm volatile(
"    push.w  {r4, r5, r6, r7, r8, lr}\n"
"    ldr     r6, =0x0003313c\n"
"    sub     sp, #0x18\n"
"    add     r7, sp, #8\n"
"    subs    r6, #0xc\n"
"    b       loc_fc070b72\n"
"loc_fc070b3e:\n"
"    ldr     r1, =0x0003313c\n"
"    add     r3, sp, #8\n"
"    ldrb.w  r0, [sp, #4]\n"
"    add     r2, sp, #0x14\n"
"    subs    r1, #0x18\n"
"    bl      sub_fc071856\n"
"    cbnz    r0, loc_fc070b58\n"
"    ldr     r1, [sp, #0x14]\n"
"    movs    r0, #0\n"
"    bl      sub_fc070aa2\n"
"loc_fc070b58:\n"
"    movs    r0, #2\n"
"loc_fc070b5a:\n"
"    ldr.w   r1, [r7, r0, lsl #2]\n"
"    cbz     r1, loc_fc070b6a\n"
"    ldr.w   r2, [r6, r0, lsl #2]\n"
"    bics    r2, r1\n"
"    str.w   r2, [r6, r0, lsl #2]\n"
"loc_fc070b6a:\n"
"    subs    r0, r0, #1\n"
"    sxtb    r0, r0\n"
"    cmp     r0, #0\n"
"    bge     loc_fc070b5a\n"
"loc_fc070b72:\n"
"    ldr     r0, =0x0003313c\n"
"    add     r1, sp, #4\n"
"    subs    r0, #0xc\n"
"    bl      sub_fc071584\n"
"    cmp     r0, #0\n"
"    bne     loc_fc070b3e\n"
"    ldr.w   r8, =0x0003313c\n"
"    movs    r4, #0\n"
"loc_fc070b86:\n"
"    movs    r5, #0\n"
"    ldr.w   r0, [r6, r4, lsl #2]\n"
"    ldr.w   r1, [r8, r4, lsl #2]\n"
"    ands    r0, r1\n"
"    str.w   r0, [r6, r4, lsl #2]\n"
"    b       loc_fc070bde\n"
"loc_fc070b98:\n"
"    lsrs    r0, r5\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc070bd6\n"
"    ldr     r1, =0x0003313c\n"
"    add.w   r0, r5, r4, lsl #5\n"
"    add     r3, sp, #8\n"
"    subs    r1, #0x18\n"
"    add     r2, sp, #0x14\n"
"    uxtb    r0, r0\n"
"    bl      sub_fc071856\n"
"    cbnz    r0, loc_fc070bba\n"
"    ldr     r1, [sp, #0x14]\n"
"    movs    r0, #1\n"
"    bl      sub_fc070aa2\n"
"loc_fc070bba:\n"
"    mov     r0, r4\n"
"    b       loc_fc070bd2\n"
"loc_fc070bbe:\n"
"    ldr.w   r1, [r7, r0, lsl #2]\n"
"    cbz     r1, loc_fc070bce\n"
"    ldr.w   r2, [r6, r0, lsl #2]\n"
"    bics    r2, r1\n"
"    str.w   r2, [r6, r0, lsl #2]\n"
"loc_fc070bce:\n"
"    adds    r0, r0, #1\n"
"    sxtb    r0, r0\n"
"loc_fc070bd2:\n"
"    cmp     r0, #3\n"
"    blt     loc_fc070bbe\n"
"loc_fc070bd6:\n"
"    ldr.w   r0, [r6, r4, lsl #2]\n"
"    adds    r5, r5, #1\n"
"    uxtb    r5, r5\n"
"loc_fc070bde:\n"
"    cmp     r0, #0\n"
"    bne     loc_fc070b98\n"
"    adds    r4, r4, #1\n"
"    sxtb    r4, r4\n"
"    cmp     r4, #3\n"
"    blt     loc_fc070b86\n"
"    bl      sub_fc07147a_my\n"   //  --->>
"    add     sp, #0x18\n"
"    pop.w   {r4, r5, r6, r7, r8, pc}\n"

".ltorg\n"
  );
}

// G16 1.01b  0xfc07147b 11
void __attribute__((naked,noinline)) sub_fc07147a_my() {
    asm volatile(
"    push    {r4, lr}\n"
"    ldr     r4, =0x00009494\n"
"    ldr     r0, [r4, #8]\n"
"    bl      sub_fc0721b4\n"
"    bl      sub_fc0c784c\n"
"    ldr     r0, [r4, #0xc]\n"
"    bl      sub_fc0720d0\n"
"    ldr     r0, [r4, #0x10]\n"
"    bl      sub_fc0720d0\n"
//"    pop.w   {r4, lr}\n"
//"    b.w     loc_fc06befe\n"
"    bl      handle_jogdial\n"  // +
"    cmp     r0, #0\n"          // +
"    beq     no_scroll\n"       // +
"    bl      sub_fc06befe\n"    // handles scrollwheel(s), void function, no args
"no_scroll:\n"                  // +
"    pop     {r4, pc}\n"        // +
".ltorg\n"
    );
}


