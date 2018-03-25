#include "lolevel.h"
#include "platform.h"
#include "core.h"

// debug
//#define CAPTSEQ_DEBUG_LOG 1

#define USE_STUBS_NRFLAG 1
#define NR_AUTO (0) // For sx700v100e; method from G16 -- default value if NRTBL.SetDarkSubType not used is -1 (0 probalby works the same), set to enable auto

#ifdef CAPTSEQ_DEBUG_LOG
extern void _LogCameraEvent(int id,const char *fmt,...);   // debug
extern int active_raw_buffer;
extern char *hook_raw_image_addr(void);

void log_remote_hook(void)
{
    _LogCameraEvent(0x60,"Remote Hook:");
}

void log_raw_hook(void) {
#ifdef VARIABLE_RAW_BUFFER
    _LogCameraEvent(0x60,"Raw Hook: arb:%d rb:0x%08x rbc:0x%08x",active_raw_buffer,hook_raw_image_addr(),current_raw_addr2);
#else
    _LogCameraEvent(0x60,"Raw Hook: arb:%d rb:0x%08x",active_raw_buffer,hook_raw_image_addr());
#endif
}

void log_capt_seq1(int m)
{
    _LogCameraEvent(0x60,"Capture Sequence Start: m:%d arb:%d rb:0x%08x i:%04d",
                    m,
                    active_raw_buffer,
                    hook_raw_image_addr(),
                    get_exposure_counter());
}
void log_capt_seq2(int m)
{
    _LogCameraEvent(0x60,"Capture Sequence End: m:%d arb:%d rb:0x%08x i:%04d",
                    m,
                    active_raw_buffer,
                    hook_raw_image_addr(),
                    get_exposure_counter());
}
void log_capt_seq3(void)
{
    _LogCameraEvent(0x60,"Capture Sequence Override: arb:%d rb:0x%08x i:%04d",
                    active_raw_buffer,
                    hook_raw_image_addr(),
                    get_exposure_counter());

}
#endif

#include "../../../generic/capt_seq.c"


//***  capt_seq_task *****

//  sx700v100d -f=chdk -s=task_CaptSeq -c=174 
// task_CaptSeq 0xfc12ded5
void __attribute__((naked,noinline)) capt_seq_task() {
    asm volatile (
"    push    {r3, r4, r5, r6, r7, lr}\n"
"    ldr     r4, =0x00037518\n"
"    movs    r6, #0\n"
"    ldr     r5, =0x0000ba6c\n"
"loc_fc12dedc:\n"
"    movs    r2, #0\n"
"    mov     r1, sp\n"
"    ldr     r0, [r5, #4]\n"
"    blx     sub_fc29b440\n" // j_ReceiveMessageQueue
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc12defe\n"
"    movw    r2, #0x429\n"
"    ldr     r1, =0xfc12db64\n" //  *"SsShootTask.c"
"    movs    r0, #0\n"
"    blx     sub_fc29b538\n" // j_DebugAssert
"    blx     sub_fc29b458\n" // -> ExitTask
"    pop     {r3, r4, r5, r6, r7, pc}\n"
"loc_fc12defe:\n"
"    ldr     r0, [sp]\n"
"    ldr     r0, [r0]\n"
"    cmp     r0, #1\n"
"    beq     loc_fc12df16\n"
"    cmp     r0, #0x2a\n"
"    beq     loc_fc12df16\n"
"    cmp     r0, #0x1e\n"
"    beq     loc_fc12df16\n"
"    cmp     r0, #0x21\n"
"    beq     loc_fc12df16\n"
"    bl      sub_fc1ba538\n"
"loc_fc12df16:\n"
#ifdef CAPTSEQ_DEBUG_LOG
// debug message
"ldr     r0, [sp]\n"
"ldr     r0, [r0]\n"
"bl log_capt_seq1\n"
#endif
"    ldr     r0, [sp]\n"
"    ldr     r1, [r0]\n"
"    cmp     r1, #0x2c\n"
"    bhs     loc_fc12dffe\n"
"    tbb     [pc, r1]\n" // (jumptable r1 44 elements)
"branchtable_fc12df22:\n"
"    .byte((loc_fc12df4e - branchtable_fc12df22) / 2)\n" // (case 0)
"    .byte((loc_fc12df62 - branchtable_fc12df22) / 2)\n" // (case 1)
"    .byte((loc_fc12df6a - branchtable_fc12df22) / 2)\n" // (case 2)
"    .byte((loc_fc12df78 - branchtable_fc12df22) / 2)\n" // (case 3)
"    .byte((loc_fc12df72 - branchtable_fc12df22) / 2)\n" // (case 4)
"    .byte((loc_fc12df80 - branchtable_fc12df22) / 2)\n" // (case 5)
"    .byte((loc_fc12df86 - branchtable_fc12df22) / 2)\n" // (case 6)
"    .byte((loc_fc12df8c - branchtable_fc12df22) / 2)\n" // (case 7)
"    .byte((loc_fc12df94 - branchtable_fc12df22) / 2)\n" // (case 8)
"    .byte((loc_fc12dfd0 - branchtable_fc12df22) / 2)\n" // (case 9)
"    .byte((loc_fc12df9e - branchtable_fc12df22) / 2)\n" // (case 10)
"    .byte((loc_fc12dfa6 - branchtable_fc12df22) / 2)\n" // (case 11)
"    .byte((loc_fc12dfac - branchtable_fc12df22) / 2)\n" // (case 12)
"    .byte((loc_fc12dfb4 - branchtable_fc12df22) / 2)\n" // (case 13)
"    .byte((loc_fc12dfc4 - branchtable_fc12df22) / 2)\n" // (case 14)
"    .byte((loc_fc12dfca - branchtable_fc12df22) / 2)\n" // (case 15)
"    .byte((loc_fc12dfd6 - branchtable_fc12df22) / 2)\n" // (case 16)
"    .byte((loc_fc12dfdc - branchtable_fc12df22) / 2)\n" // (case 17)
"    .byte((loc_fc12dfe2 - branchtable_fc12df22) / 2)\n" // (case 18)
"    .byte((loc_fc12dfe8 - branchtable_fc12df22) / 2)\n" // (case 19)
"    .byte((loc_fc12dfee - branchtable_fc12df22) / 2)\n" // (case 20)
"    .byte((loc_fc12dff4 - branchtable_fc12df22) / 2)\n" // (case 21)
"    .byte((loc_fc12dff8 - branchtable_fc12df22) / 2)\n" // (case 22)
"    .byte((loc_fc12e000 - branchtable_fc12df22) / 2)\n" // (case 23)
"    .byte((loc_fc12e006 - branchtable_fc12df22) / 2)\n" // (case 24)
"    .byte((loc_fc12e00c - branchtable_fc12df22) / 2)\n" // (case 25)
"    .byte((loc_fc12e012 - branchtable_fc12df22) / 2)\n" // (case 26)
"    .byte((loc_fc12e018 - branchtable_fc12df22) / 2)\n" // (case 27)
"    .byte((loc_fc12e020 - branchtable_fc12df22) / 2)\n" // (case 28)
"    .byte((loc_fc12e026 - branchtable_fc12df22) / 2)\n" // (case 29)
"    .byte((loc_fc12e02a - branchtable_fc12df22) / 2)\n" // (case 30)
"    .byte((loc_fc12e032 - branchtable_fc12df22) / 2)\n" // (case 31)
"    .byte((loc_fc12e038 - branchtable_fc12df22) / 2)\n" // (case 32)
"    .byte((loc_fc12e03e - branchtable_fc12df22) / 2)\n" // (case 33)
"    .byte((loc_fc12e044 - branchtable_fc12df22) / 2)\n" // (case 34)
"    .byte((loc_fc12e04a - branchtable_fc12df22) / 2)\n" // (case 35)
"    .byte((loc_fc12e050 - branchtable_fc12df22) / 2)\n" // (case 36)
"    .byte((loc_fc12e056 - branchtable_fc12df22) / 2)\n" // (case 37)
"    .byte((loc_fc12e05e - branchtable_fc12df22) / 2)\n" // (case 38)
"    .byte((loc_fc12e064 - branchtable_fc12df22) / 2)\n" // (case 39)
"    .byte((loc_fc12e06e - branchtable_fc12df22) / 2)\n" // (case 40)
"    .byte((loc_fc12e09a - branchtable_fc12df22) / 2)\n" // (case 41)
"    .byte((loc_fc12e0a0 - branchtable_fc12df22) / 2)\n" // (case 42)
"    .byte((loc_fc12e0ba - branchtable_fc12df22) / 2)\n" // (case 43)
".align 1\n"
"loc_fc12df4e:\n" // case 0: preshoot, quick press shoot
"    bl      sub_fc12e3f2\n"
#ifdef CAPTSEQ_DEBUG_LOG
"bl log_capt_seq3\n"
#endif
"    BL      shooting_expo_param_override\n" // +
"    bl      sub_fc12bbfa\n"
"    ldr     r0, [r4, #0x28]\n"
"    cmp     r0, #0\n"
"    beq     loc_fc12df60\n"
//"    bl      sub_fc1b9426\n"
"    bl      sub_fc1b9426_my\n" // quick press
"loc_fc12df60:\n"
"    b       loc_fc12e0ba\n"
"loc_fc12df62:\n"  // case 1: normal shoot
"    ldr     r0, [r0, #0x10]\n"
//"    bl      sub_fc1b929a\n"
"    bl      sub_fc1b929a_my\n" // +
"    b       loc_fc12e0ba\n"
"loc_fc12df6a:\n"
"    movs    r0, #1\n"
"    bl      sub_fc12e672\n"
"    b       loc_fc12e0ba\n"
"loc_fc12df72:\n"
"    bl      sub_fc12e1be\n"
"    b       loc_fc12df7c\n"
"loc_fc12df78:\n"
"    bl      sub_fc12e3de\n"
"loc_fc12df7c:\n"
"    str     r6, [r4, #0x28]\n"
"    b       loc_fc12e0ba\n"
"loc_fc12df80:\n"
"    bl      sub_fc12e3e2\n"
"    b       loc_fc12e0ba\n"
"loc_fc12df86:\n"
"    bl      sub_fc12e57a\n"
"    b       loc_fc12df98\n"
"loc_fc12df8c:\n"
"    ldr     r0, [r0, #0x10]\n"
"    bl      sub_fc1b949a\n"
"    b       loc_fc12e0ba\n"
"loc_fc12df94:\n"
"    bl      sub_fc12e600\n"
"loc_fc12df98:\n"
"    bl      sub_fc12bbfa\n"
"    b       loc_fc12e0ba\n"
"loc_fc12df9e:\n"
"    ldr     r0, [r4, #0x50]\n"
"    bl      sub_fc12ebd8\n"
"    b       loc_fc12e0ba\n"
"loc_fc12dfa6:\n"
"    bl      sub_fc12ee6c\n"
"    b       loc_fc12e0ba\n"
"loc_fc12dfac:\n"
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc12eeb8\n"
"    b       loc_fc12e0ba\n"
"loc_fc12dfb4:\n"
"    bl      sub_fc12f032\n"
"    b       loc_fc12e0ba\n"
// literal pool in original firmware
".ltorg\n"
/*
"    movs    r0, r0\n"
"    strb    r0, [r3, #0x14]\n"
"    movs    r3, r0\n"
"    rev16   r4, r5\n"
"    movs    r0, r0\n"
*/
"loc_fc12dfc4:\n"
"    bl      sub_fc12f3f4\n"
"    b       loc_fc12e0ba\n"
"loc_fc12dfca:\n"
"    bl      sub_fc12f484\n"
"    b       loc_fc12e0ba\n"
"loc_fc12dfd0:\n"
"    bl      sub_fc12e3de\n"
"    b       loc_fc12e0ba\n"
"loc_fc12dfd6:\n"
"    bl      sub_fc1b8874\n"
"    b       loc_fc12e0ba\n"
"loc_fc12dfdc:\n"
"    bl      sub_fc1b8a02\n"
"    b       loc_fc12e0ba\n"
"loc_fc12dfe2:\n"
"    bl      sub_fc1b8a76\n"
"    b       loc_fc12e0ba\n"
"loc_fc12dfe8:\n"
"    bl      sub_fc1b8b08\n"
"    b       loc_fc12e0ba\n"
"loc_fc12dfee:\n"
"    bl      sub_fc1b8ba4\n"
"    b       loc_fc12e0ba\n"
"loc_fc12dff4:\n"
"    movs    r0, #0\n"
"    b       loc_fc12e01a\n"
"loc_fc12dff8:\n"
"    bl      sub_fc1b8e98\n"
"    b       loc_fc12e0ba\n"
"loc_fc12dffe:\n"
"    b       loc_fc12e0ac\n"
"loc_fc12e000:\n"
"    bl      sub_fc1b8ef6\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e006:\n"
"    bl      sub_fc1b8efa\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e00c:\n"
"    bl      sub_fc1b8f0c\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e012:\n"
"    bl      sub_fc1b8f88\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e018:\n"
"    movs    r0, #1\n"
"loc_fc12e01a:\n"
"    bl      sub_fc1b8d8c\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e020:\n"
"    bl      sub_fc12e77e\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e026:\n"
"    movs    r0, #0\n"
"    b       loc_fc12e02c\n"
"loc_fc12e02a:\n"
"    ldr     r0, [r0, #0xc]\n"
"loc_fc12e02c:\n"
"    bl      sub_fc12e7ce\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e032:\n"
"    bl      sub_fc1b8cc0\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e038:\n"
"    bl      sub_fc1b8d22\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e03e:\n"
"    bl      sub_fc1b9ef6\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e044:\n"
"    bl      sub_fc12c430\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e04a:\n"
"    bl      sub_fc131580\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e050:\n"
"    bl      sub_fc131630\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e056:\n"
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc1b9048\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e05e:\n"
"    bl      sub_fc1b90aa\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e064:\n"
"    bl      sub_fc131720\n"
"    bl      sub_fc13166e\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e06e:\n"
"    movs    r0, #1\n"
"    bl      sub_fc1b9b38\n"
"    movs    r0, #1\n"
"    bl      sub_fc1b9c02\n"
"    ldrh.w  r0, [r4, #0x198]\n"
"    cmp     r0, #4\n"
"    beq     loc_fc12e08c\n"
"    ldrh    r0, [r4]\n"
"    sub.w   r1, r0, #0x4200\n"
"    subs    r1, #0x31\n"
"    bne     loc_fc12e0ba\n"
"loc_fc12e08c:\n"
"    bl      sub_fc131630\n"
"    bl      sub_fc131b10\n"
"    bl      sub_fc131958\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e09a:\n"
"    movs    r2, #0\n"
"    movs    r1, #0x10\n"
"    b       loc_fc12e0a4\n"
"loc_fc12e0a0:\n"
"    movs    r2, #0\n"
"    movs    r1, #0xf\n"
"loc_fc12e0a4:\n"
"    movs    r0, #0\n"
"    bl      sub_fc12c5fc\n"
"    b       loc_fc12e0ba\n"
"loc_fc12e0ac:\n"
"    movw    r2, #0x54d\n"
"    ldr     r1, =0xfc12db64\n" //  *"SsShootTask.c"
"    movs    r0, #0\n"
"    blx     sub_fc29b538\n" // j_DebugAssert
"loc_fc12e0ba:\n"
// debug after message handled
#ifdef CAPTSEQ_DEBUG_LOG
"ldr     r0, [sp]\n"
"ldr     r0, [r0]\n"
"bl log_capt_seq2\n"
#endif
"    bl      capt_seq_hook_set_nr\n" //  ---->> dark frame control
"    ldr     r0, [sp]\n"
"    ldr     r1, [r0, #4]\n"
"    ldr     r0, [r5]\n"
"    blx     sub_fc29b420\n" // j_SetEventFlag
"    ldr     r7, [sp]\n"
"    ldr     r0, [r7, #8]\n"
"    cbnz    r0, loc_fc12e0d8\n"
"    movw    r2, #0x11e\n"
"    ldr     r1, =0xfc12db64\n" //  *"SsShootTask.c"
"    movs    r0, #0\n"
"    blx     sub_fc29b538\n" // j_DebugAssert
"loc_fc12e0d8:\n"
"    str     r6, [r7, #8]\n"
"    b       loc_fc12dedc\n"
".ltorg\n"
    );
}

// Quick Press
// sx700v100d -f=chdk -s=0xfc1b9427 -c=39
void __attribute__((naked,noinline)) sub_fc1b9426_my() {
    asm volatile (
"    push    {r4, r5, r6, lr}\n"
"    bl      sub_fc12d5f8\n"
"    mov     r4, r0\n"
"    movs    r0, #0xc\n"
"    bl      sub_fc2b71dc\n"
"    ldr     r6, =0x00014778\n"
"    lsls    r0, r0, #0x1f\n"
"    mov.w   r5, #1\n"
"    bne     loc_fc1b9496\n"
"    bl      sub_fc2b720e\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc1b9496\n"
"    bl      sub_fc12e3e6\n"
"    bl      sub_fc12ff64\n"
"    mov     r1, r4\n"
"    bl      sub_fc12ffaa\n"
"    movs    r2, #4\n"
"    movw    r0, #0x10e\n"
"    add.w   r1, r4, #0x50\n"
"    bl      _SetPropertyCase\n" //  (270)
"    movs    r2, #4\n"
"    movs    r0, #0x2c\n"
"    add.w   r1, r4, #0x54\n"
"    bl      _SetPropertyCase\n" //  (44)
"    movs    r2, #4\n"
"    movs    r0, #0x3f\n"
"    add.w   r1, r4, #8\n"
"    bl      _SetPropertyCase\n" //  (63)
"    bl      sub_fc1b9cf2\n"
"    mvn     r1, #0x1000\n"
"    blx     sub_fc29b460\n" // j_ClearEventFlag
"    mov     r0, r4\n"
"    bl      sub_fc36f908\n"
"    mov     r0, r4\n"
//"    bl      sub_fc36fb9e\n"
"    bl      sub_fc36fb9e_my\n" // ->
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc1b9498\n"
"loc_fc1b9496:\n"
"    str     r5, [r6]\n"
"loc_fc1b9498:\n"
"    pop     {r4, r5, r6, pc}\n"
".ltorg\n"
    );
}

// sx700v100d -f=chdk -s=0xfc1b929b -c=147
void __attribute__((naked,noinline)) sub_fc1b929a_my() { // SUB2
    asm volatile (
"    push    {r2, r3, r4, r5, r6, lr}\n"
"    ldr     r6, =0x00037518\n"
"    mov     r4, r0\n"
"    movs    r5, #0\n"
"    ldr     r0, [r6, #0x28]\n"
"    cbz     r0, loc_fc1b92c2\n"
"    ldr     r0, =0x00014778\n"
"    ldr     r0, [r0]\n"
"    cbz     r0, loc_fc1b92ae\n"
"    movs    r5, #0x1d\n"
"loc_fc1b92ae:\n"
"    mov     r2, r4\n"
"    movs    r1, #1\n"
"    mov     r0, r5\n"
"    bl      sub_fc12c5fc\n"
"    mov     r1, r5\n"
"    mov     r0, r4\n"
"    bl      sub_fc1ba396\n"
"    b       loc_fc1b9420\n"
"loc_fc1b92c2:\n"
"    bl      sub_fc12ff64\n"
"    mov     r1, r4\n"
"    bl      sub_fc12ffaa\n"
"    movs    r2, #4\n"
"    movw    r0, #0x10e\n"
"    add.w   r1, r4, #0x50\n"
"    bl      _SetPropertyCase\n" //  (270)
"    movs    r2, #4\n"
"    movs    r0, #0x2c\n"
"    add.w   r1, r4, #0x54\n"
"    bl      _SetPropertyCase\n" //  (44)
"    ldr.w   r0, [r6, #0x12c]\n"
"    cbz     r0, loc_fc1b931a\n"
"    ldrh.w  r0, [r6, #0x196]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc1b92fa\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc1b9306\n"
"loc_fc1b92fa:\n"
"    ldr.w   r0, [r6, #0x104]\n"
"    cbz     r0, loc_fc1b931a\n"
"    ldr     r0, [r4, #0xc]\n"
"    cmp     r0, #1\n"
"    bls     loc_fc1b931a\n"
"loc_fc1b9306:\n"
"    ldr.w   r0, [r6, #0xe4]\n"
"    cbnz    r0, loc_fc1b9332\n"
"    bl      sub_fc11a472\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc1b9332\n"
"    bl      sub_fc2b7248\n"
"    b       loc_fc1b9330\n"
"loc_fc1b931a:\n"
"    movs    r0, #0xc\n"
"    bl      sub_fc2b71dc\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc1b932c\n"
"    bl      sub_fc2b720e\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc1b9332\n"
"loc_fc1b932c:\n"
"    bl      sub_fc12c426\n"
"loc_fc1b9330:\n"
"    movs    r5, #1\n"
"loc_fc1b9332:\n"
"    lsls    r0, r5, #0x1f\n"
"    bne     loc_fc1b940e\n"
"    mov     r0, r4\n"
"    bl      sub_fc1b9f40\n"
"    bl      sub_fc1b9cf2\n"
"    mvn     r1, #0x1000\n"
"    blx     sub_fc29b460\n" // j_ClearEventFlag
"    mov     r0, r4\n"
"    bl      sub_fc36f1a0\n"
"    mov     r5, r0\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc1b940e\n"
"    bl      sub_fc12e3e6\n"
"    mov     r0, r4\n"
"    bl      sub_fc36f908\n"
"    ldr.w   r0, [r6, #0x128]\n"
"    cbnz    r0, loc_fc1b9372\n"
"    ldrh.w  r0, [r6, #0x196]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc1b9372\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc1b9378\n"
"loc_fc1b9372:\n"
"    movs    r0, #2\n"
"    bl      sub_fc1342ba\n"
"loc_fc1b9378:\n"
"    ldr.w   r0, [r6, #0xa0]\n"
"    cmp     r0, #0\n"
"    beq     loc_fc1b93ea\n"
"    ldrh.w  r0, [r6, #0x196]\n"
"    movw    r5, #0x1000\n"
"    cmp     r0, #3\n"
"    beq     loc_fc1b93a8\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bls     loc_fc1b93a8\n"
"    bl      sub_fc1b9cf2\n"
"    movw    r3, #0x119\n"
"    movw    r2, #0x3a98\n"
"    mov     r1, r5\n"
"    str     r3, [sp]\n"
"    ldr     r3, =0xfc1b9570\n" //  *"SsCaptureCtrl.c"
"    bl      sub_fc2b73b4\n"
"loc_fc1b93a8:\n"
"    movs    r2, #4\n"
"    movw    r0, #0x180\n"
"    add     r1, sp, #4\n"
"    bl      _GetPropertyCase\n" //  (384)
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc1b93c4\n"
"    movs    r0, #0\n"
"    movw    r2, #0x11d\n"
"    ldr     r1, =0xfc1b9570\n" //  *"SsCaptureCtrl.c"
"    blx     sub_fc29b538\n" // j_DebugAssert
"loc_fc1b93c4:\n"
"    ldr     r0, [sp, #4]\n"
"    cbnz    r0, loc_fc1b93d4\n"
"    bl      sub_fc1b9cf2\n"
"    mov     r1, r5\n"
"    blx     sub_fc29b420\n" // j_SetEventFlag
"    b       loc_fc1b93ea\n"
"loc_fc1b93d4:\n"
"    bl      sub_fc1b9cf2\n"
"    mov     r1, r5\n"
"    blx     sub_fc29b460\n" // j_ClearEventFlag
"    ldr     r2, =0xfc1b9289\n"
"    mov     r3, r5\n"
"    ldr     r0, [sp, #4]\n"
"    mov     r1, r2\n"
"    bl      sub_fc3005e0\n"
"loc_fc1b93ea:\n"
"    ldr.w   r0, [r6, #0xac]\n"
"    cbz     r0, loc_fc1b93f8\n"
"    mov     r0, r4\n"
"    bl      sub_fc36ffe4\n"
"    b       loc_fc1b9420\n"
"loc_fc1b93f8:\n"
"    ldr.w   r0, [r6, #0xb0]\n"
"    cmp     r0, #0\n"
"    mov     r0, r4\n"
"    beq     loc_fc1b9408\n"
"    bl      sub_fc3702de\n"
"    b       loc_fc1b9420\n"
"loc_fc1b9408:\n"
//"    bl      sub_fc36fb9e\n"
"    bl      sub_fc36fb9e_my\n" // ->
"    b       loc_fc1b9420\n"
"loc_fc1b940e:\n"
"    movs    r1, #1\n"
"    mov     r2, r4\n"
"    mov     r0, r5\n"
"    bl      sub_fc12c5fc\n"
"    mov     r1, r5\n"
"    mov     r0, r4\n"
"    bl      sub_fc1ba4cc\n"
"loc_fc1b9420:\n"
"    movs    r0, #0\n"
"    str     r0, [r6, #0x28]\n"
"    pop     {r2, r3, r4, r5, r6, pc}\n"
".ltorg\n"
    );
}


// sx700v100d -f=chdk -s=0xfc36fb9f -c=188
void __attribute__((naked,noinline)) sub_fc36fb9e_my() { // SUB3
    asm volatile (
"    push.w  {r2, r3, r4, r5, r6, r7, r8, sb, sl, lr}\n"
"    ldr     r7, =0x00037518\n"
"    mov     r4, r0\n"
"    ldr.w   r0, [r7, #0x164]\n"
"    cbz     r0, loc_fc36fbba\n"
"    ldrh.w  r0, [r7, #0x196]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc36fbba\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc36fbc4\n"
"loc_fc36fbba:\n"
"    mov     r0, r4\n"
"    bl      sub_fc36f89e\n"
"    bl      sub_fc1b9962\n"
"loc_fc36fbc4:\n"
"    ldr.w   r0, [r7, #0x9c]\n"
"    cbnz    r0, loc_fc36fbe0\n"
"    ldrh.w  r0, [r7, #0x196]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc36fbd8\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc36fbe0\n"
"loc_fc36fbd8:\n"
"    bl      sub_fc12e7ca\n"
"    bl      sub_fc1b95a2\n"
"loc_fc36fbe0:\n"
"    movs    r2, #4\n"
"    movw    r0, #0x12f\n"
"    add     r1, sp, #4\n"
"    bl      _GetPropertyCase\n" //  (303)
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc36fbfc\n"
"    movs    r0, #0\n"
"    movw    r2, #0x18c\n"
"    ldr     r1, =0xfc36ff48\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc29b538\n" // j_DebugAssert
"loc_fc36fbfc:\n"
"    ldr     r0, [sp, #4]\n"
"    ubfx    r0, r0, #8, #8\n"
"    cmp     r0, #6\n"
"    bne     loc_fc36fc0c\n"
"    ldr     r0, =0xfc36fb77\n"
"    movs    r1, #0\n"
"    b       loc_fc36fc10\n"
"loc_fc36fc0c:\n"
"    ldr     r0, =0xfc36f5c7\n"
"    mov     r1, r4\n"
"loc_fc36fc10:\n"
"    bl      sub_fc14f878\n"
"    mov     r0, r4\n"
"    bl      sub_fc36f9b4\n"
"    ldr     r1, =0x00023450\n"
"    movs    r2, #4\n"
"    movs    r0, #0x8a\n"
"    bl      _GetPropertyCase\n" //  (138)
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc36fc34\n"
"    movs    r0, #0\n"
"    movw    r2, #0x19b\n"
"    ldr     r1, =0xfc36ff48\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc29b538\n" // j_DebugAssert
"loc_fc36fc34:\n"
"    bl      sub_fc130afc\n"
"    bl      sub_fc36fa50\n"
"    movs    r1, #0\n"
"    mov     r0, r4\n"
"    bl      sub_fc36ff1a\n"
"    mov     r6, r0\n"
"    bl      wait_until_remote_button_is_released\n" // ---->> remote hook
#ifdef CAPT_SEQ_DEBUG
"    bl      log_remote_hook\n"   // ---->>
#endif
"    ldr     r0, [sp, #4]\n"
"    ubfx    r0, r0, #8, #8\n"
"    cmp     r0, #6\n"
"    bne     loc_fc36fc54\n"
"    ldr     r2, =0xfc36f72f\n"
"    b       loc_fc36fc56\n"
"loc_fc36fc54:\n"
"    ldr     r2, =0xfc36f7b7\n"
"loc_fc36fc56:\n"
"    ldrh    r0, [r4, #0x18]\n"
"    ldr     r5, =0x00023450\n"
"    cbz     r0, loc_fc36fc64\n"
"    cmp     r0, #1\n"
"    beq     loc_fc36fc7a\n"
"    cmp     r0, #4\n"
"    bne     loc_fc36fcde\n"
"loc_fc36fc64:\n"
"    str     r6, [sp]\n"
"    mov     r3, r2\n"
"    ldr     r1, [r4, #0x54]\n"
"    mov     r0, r4\n"
"    ldr     r2, [r5]\n"
"    bl      sub_fc36f492\n"
"    mov     r5, r0\n"
"    bl      sub_fc14d3f4\n"
"    b       loc_fc36fcec\n"
"loc_fc36fc7a:\n"
"    str     r6, [sp]\n"
"    mov     r3, r2\n"
"    ldr     r1, [r4, #0x54]\n"
"    mov     r8, r5\n"
"    ldr     r2, [r5]\n"
"    mov     r0, r4\n"
"    bl      sub_fc36f4de\n"
"    movs    r1, #0\n"
"    mov     r5, r0\n"
"    movs    r0, #0x45\n"
"    bl      sub_fc25cd04\n"
"    lsls    r0, r5, #0x1f\n"
"    bne     loc_fc36fcec\n"
"    ldr.w   r0, [r7, #0xf8]\n"
"    cbz     r0, loc_fc36fcae\n"
"    ldr     r1, [r4, #8]\n"
"    ldr     r2, =0x001caa04\n"
"    ldr     r0, [r4, #0x54]\n"
"    add.w   r1, r2, r1, lsl #2\n"
"    str     r0, [r1, #-0x4]\n"
"    b       loc_fc36fcd8\n"
"loc_fc36fcae:\n"
"    ldr     r0, =0xfc36fb77\n"
"    movs    r1, #0\n"
"    bl      sub_fc14f878\n"
"    movs    r1, #1\n"
"    mov     r0, r4\n"
"    bl      sub_fc36ff1a\n"
"    mov     r6, r0\n"
"    ldr.w   r0, [r8]\n"
"    mov     r5, r8\n"
"    bl      sub_fc36f840\n"
"    ldr     r1, [r4, #0x54]\n"
"    mov     r3, r6\n"
"    ldr     r2, [r5]\n"
"    mov     r0, r4\n"
"    bl      sub_fc36f52e\n"
"    mov     r5, r0\n"
"loc_fc36fcd8:\n"
"    bl      sub_fc36f43c\n"
"    b       loc_fc36fcec\n"
"loc_fc36fcde:\n"
"    movs    r0, #0\n"
"    movw    r2, #0x1d5\n"
"    ldr     r1, =0xfc36ff48\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc29b538\n" // j_DebugAssert
"    movs    r5, #0x1d\n"
"loc_fc36fcec:\n"
"    bl      sub_fc36fa54\n"
"    ldr.w   r8, =0xfc36fb77\n"
"    lsls    r0, r5, #0x1f\n"
"    bne     loc_fc36fd48\n"
"    ldr.w   r0, [r7, #0x100]\n"
"    cbnz    r0, loc_fc36fd14\n"
"    mov     r0, r4\n"
"    bl      sub_fc1ba95e\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc36fd14\n"
"    movs    r0, #0\n"
"    movw    r2, #0x1ef\n"
"    ldr     r1, =0xfc36ff48\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc29b538\n" // j_DebugAssert
"loc_fc36fd14:\n"
#ifdef CAPT_SEQ_DEBUG
"  BL log_raw_hook\n"                  // ---->>
#endif
"    BL      capt_seq_hook_raw_here\n" // ---->>
"    mov     r0, r4\n"
"    bl      sub_fc36fa40\n"
"    mov     r0, r4\n"
"    bl      sub_fc36fa14\n"
"    cmp     r6, r8\n"
"    beq     loc_fc36fd48\n"
"    bl      sub_fc1b9cf2\n"
"    movs    r1, #4\n"
"    movw    sb, #0x1fc\n"
"    ldr     r3, =0xfc36ff48\n" //  *"SsStandardCaptureSeq.c"
"    movw    r2, #0x3a98\n"
"    str.w   sb, [sp]\n"
"    bl      sub_fc2b73b4\n"
"    cbz     r0, loc_fc36fd48\n"
"    movs    r0, #0\n"
"    mov     r2, sb\n"
"    ldr     r1, =0xfc36ff48\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc29b538\n" // j_DebugAssert
"loc_fc36fd48:\n"
"    movs    r1, #1\n"
"    mov     r2, r4\n"
"    mov     r0, r5\n"
"    bl      sub_fc12c5fc\n"
"    ldr     r0, [r7, #0x28]\n"
"    cmp     r0, #0\n"
"    mov     r0, r8\n"
"    beq     loc_fc36fd6e\n"
"    cmp     r6, r0\n"
"    beq     loc_fc36fd62\n"
"    movs    r1, #1\n"
"    b       loc_fc36fd64\n"
"loc_fc36fd62:\n"
"    movs    r1, #0\n"
"loc_fc36fd64:\n"
"    mov     r2, r5\n"
"    mov     r0, r4\n"
"    bl      sub_fc1ba354\n"
"    b       loc_fc36fd80\n"
"loc_fc36fd6e:\n"
"    cmp     r6, r0\n"
"    beq     loc_fc36fd76\n"
"    movs    r1, #1\n"
"    b       loc_fc36fd78\n"
"loc_fc36fd76:\n"
"    movs    r1, #0\n"
"loc_fc36fd78:\n"
"    mov     r2, r5\n"
"    mov     r0, r4\n"
"    bl      sub_fc1ba30e\n"
"loc_fc36fd80:\n"
"    mov     r0, r5\n"
"    pop.w   {r2, r3, r4, r5, r6, r7, r8, sb, sl, pc}\n"
".ltorg\n"
    );
}

