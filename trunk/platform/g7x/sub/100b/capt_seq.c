#include "lolevel.h"
#include "platform.h"
#include "core.h"

// debug
//#define CAPTSEQ_DEBUG_LOG 1
extern void _LogCameraEvent(int id,const char *fmt,...);

#define USE_STUBS_NRFLAG 1
#define NR_AUTO (-1) // default value if NRTBL.SetDarkSubType not used is -1 (0 probalby works the same), set to enable auto

#ifdef CAPTSEQ_DEBUG_LOG
extern int active_raw_buffer;

extern char *hook_raw_image_addr(void);

void log_capt_seq(int m)
{
    _LogCameraEvent(0x60,"cs m:%d arb:%d rb:0x%08x i:%04d",
                    m,
                    active_raw_buffer,
                    hook_raw_image_addr(),
                    get_exposure_counter());
}
void log_capt_seq2(int m)
{
    _LogCameraEvent(0x60,"cs end m:%d arb:%d rb:0x%08x i:%04d",
                    m,
                    active_raw_buffer,
                    hook_raw_image_addr(),
                    get_exposure_counter());
}
void log_capt_seq_override(void)
{
    _LogCameraEvent(0x60,"cs override arb:%d rb:0x%08x i:%04d",
                    active_raw_buffer,
                    hook_raw_image_addr(),
                    get_exposure_counter());
}
#endif

#include "../../../generic/capt_seq.c"
// first paramter matches active_raw_buffer
// second is pointer to structure
extern int _captseq_raw_addr_init(int raw_index, char **ptr);
char *current_raw_addr;

void captseq_raw_addr_init_my(int raw_index,char **ptr) {
    _captseq_raw_addr_init(raw_index,ptr);
    current_raw_addr=*(ptr + 0x5c/4); // @0xfc1527b2, ptr+0x5c
#ifdef CAPTSEQ_DEBUG_LOG
    _LogCameraEvent(0x60,"rawinit i:0x%x p:0x%x v:0x%x",raw_index,ptr,current_raw_addr);
#endif
}

void clear_current_raw_addr(void) {
    current_raw_addr=NULL;
}

//-s=task_CaptSeq -c=173 -f=chdk
// task_CaptSeq 0xfc1501d9
void __attribute__((naked,noinline)) capt_seq_task() {
    asm volatile (
"    push    {r3, r4, r5, r6, r7, lr}\n"
"    ldr     r4, =0x0003fad4\n"
"    movs    r6, #0\n"
"    ldr     r5, =0x0000bd84\n"
"loc_fc1501e0:\n"
"    movs    r2, #0\n"
"    mov     r1, sp\n"
"    ldr     r0, [r5, #8]\n"
"    blx     sub_fc2ef8f8\n" // j_ReceiveMessageQueue
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc150202\n"
"    movw    r2, #0x449\n"
"    ldr     r1, =0xfc14fe88\n" //  *"SsShootTask.c"
"    movs    r0, #0\n"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"    blx     sub_fc2ef918\n" // -> ExitTask
"    pop     {r3, r4, r5, r6, r7, pc}\n"
"loc_fc150202:\n"
"    ldr     r0, [sp]\n"
"    ldr     r0, [r0]\n"
"    cmp     r0, #1\n"
"    beq     loc_fc15021a\n"
"    cmp     r0, #0x28\n"
"    beq     loc_fc15021a\n"
"    cmp     r0, #0x1d\n"
"    beq     loc_fc15021a\n"
"    cmp     r0, #0x20\n"
"    beq     loc_fc15021a\n"
"    bl      sub_fc1e67ac\n"
"loc_fc15021a:\n"
#ifdef CAPTSEQ_DEBUG_LOG
// debug message
"ldr     r0, [sp]\n"
"ldr     r0, [r0]\n"
"bl log_capt_seq\n"
#endif
"    ldr     r0, [sp]\n"
"    ldr     r1, [r0]\n"
"    cmp     r1, #0x2b\n"
"    bhs     loc_fc150304\n"
"    tbb     [pc, r1]\n" // (jumptable r1 43 elements)
"branchtable_fc150226:\n"
"    .byte((loc_fc150252 - branchtable_fc150226) / 2)\n" // (case 0)
"    .byte((loc_fc150268 - branchtable_fc150226) / 2)\n" // (case 1)
"    .byte((loc_fc150270 - branchtable_fc150226) / 2)\n" // (case 2)
"    .byte((loc_fc15027e - branchtable_fc150226) / 2)\n" // (case 3)
"    .byte((loc_fc150278 - branchtable_fc150226) / 2)\n" // (case 4)
"    .byte((loc_fc150288 - branchtable_fc150226) / 2)\n" // (case 5)
"    .byte((loc_fc15028e - branchtable_fc150226) / 2)\n" // (case 6)
"    .byte((loc_fc150294 - branchtable_fc150226) / 2)\n" // (case 7)
"    .byte((loc_fc15029c - branchtable_fc150226) / 2)\n" // (case 8)
"    .byte((loc_fc1502da - branchtable_fc150226) / 2)\n" // (case 9)
"    .byte((loc_fc1502a6 - branchtable_fc150226) / 2)\n" // (case 10)
"    .byte((loc_fc1502ae - branchtable_fc150226) / 2)\n" // (case 11)
"    .byte((loc_fc1502c0 - branchtable_fc150226) / 2)\n" // (case 12)
"    .byte((loc_fc1502c8 - branchtable_fc150226) / 2)\n" // (case 13)
"    .byte((loc_fc1502ce - branchtable_fc150226) / 2)\n" // (case 14)
"    .byte((loc_fc1502d4 - branchtable_fc150226) / 2)\n" // (case 15)
"    .byte((loc_fc1502e2 - branchtable_fc150226) / 2)\n" // (case 16)
"    .byte((loc_fc1502e8 - branchtable_fc150226) / 2)\n" // (case 17)
"    .byte((loc_fc1502ee - branchtable_fc150226) / 2)\n" // (case 18)
"    .byte((loc_fc1502f4 - branchtable_fc150226) / 2)\n" // (case 19)
"    .byte((loc_fc1502fa - branchtable_fc150226) / 2)\n" // (case 20)
"    .byte((loc_fc1502fe - branchtable_fc150226) / 2)\n" // (case 21)
"    .byte((loc_fc150306 - branchtable_fc150226) / 2)\n" // (case 22)
"    .byte((loc_fc15030c - branchtable_fc150226) / 2)\n" // (case 23)
"    .byte((loc_fc150312 - branchtable_fc150226) / 2)\n" // (case 24)
"    .byte((loc_fc150318 - branchtable_fc150226) / 2)\n" // (case 25)
"    .byte((loc_fc15031e - branchtable_fc150226) / 2)\n" // (case 26)
"    .byte((loc_fc150326 - branchtable_fc150226) / 2)\n" // (case 27)
"    .byte((loc_fc15032c - branchtable_fc150226) / 2)\n" // (case 28)
"    .byte((loc_fc150330 - branchtable_fc150226) / 2)\n" // (case 29)
"    .byte((loc_fc150338 - branchtable_fc150226) / 2)\n" // (case 30)
"    .byte((loc_fc15033e - branchtable_fc150226) / 2)\n" // (case 31)
"    .byte((loc_fc150344 - branchtable_fc150226) / 2)\n" // (case 32)
"    .byte((loc_fc15034a - branchtable_fc150226) / 2)\n" // (case 33)
"    .byte((loc_fc150350 - branchtable_fc150226) / 2)\n" // (case 34)
"    .byte((loc_fc150356 - branchtable_fc150226) / 2)\n" // (case 35)
"    .byte((loc_fc15035c - branchtable_fc150226) / 2)\n" // (case 36)
"    .byte((loc_fc150364 - branchtable_fc150226) / 2)\n" // (case 37)
"    .byte((loc_fc15036a - branchtable_fc150226) / 2)\n" // (case 38)
"    .byte((loc_fc15039a - branchtable_fc150226) / 2)\n" // (case 39)
"    .byte((loc_fc1503a0 - branchtable_fc150226) / 2)\n" // (case 40)
"    .byte((loc_fc15038e - branchtable_fc150226) / 2)\n" // (case 41)
"    .byte((loc_fc1503ba - branchtable_fc150226) / 2)\n" // (case 42)
".align 1\n"
"loc_fc150252:\n" // case 0: preshoot, quick press shoot
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc15073a\n"
#ifdef CAPTSEQ_DEBUG_LOG
"bl log_capt_seq_override\n"
#endif
"    BL      clear_current_raw_addr\n" // +
"    BL      shooting_expo_param_override\n" // +
"    bl      sub_fc14dc2e\n"
"    ldr     r0, [r4, #0x28]\n"
"    cmp     r0, #0\n"
"    beq     loc_fc150266\n"
"    bl      sub_fc1e58d8_my\n" // -> nr?, remote hook, raw hook (quick, no half press)
"loc_fc150266:\n"
"    b       loc_fc1503ba\n"
"loc_fc150268:\n" // case 1: (normal shoot)
"    ldr     r0, [r0, #0x10]\n"
"    bl      sub_fc1e56a6_my\n" // ->  nr?, remote hook, raw hook
"    b       loc_fc1503ba\n"
"loc_fc150270:\n"
"    movs    r0, #1\n"
"    bl      sub_fc1509dc\n"
"    b       loc_fc1503ba\n"
"loc_fc150278:\n"
"    bl      sub_fc1504c2\n"
"    b       loc_fc150284\n"
"loc_fc15027e:\n"
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc150722\n"
"loc_fc150284:\n"
"    str     r6, [r4, #0x28]\n"
"    b       loc_fc1503ba\n"
"loc_fc150288:\n"
"    bl      sub_fc150728\n"
"    b       loc_fc1503ba\n"
"loc_fc15028e:\n"
"    bl      sub_fc150902\n"
"    b       loc_fc1502a0\n"
"loc_fc150294:\n"
"    ldr     r0, [r0, #0x10]\n"
"    bl      sub_fc1e5980\n"
"    b       loc_fc1503ba\n"
"loc_fc15029c:\n"
"    bl      sub_fc150964\n"
"loc_fc1502a0:\n"
"    bl      sub_fc14dc2e\n"
"    b       loc_fc1503ba\n"
"loc_fc1502a6:\n"
"    ldr     r0, [r4, #0x54]\n"
"    bl      sub_fc150f38\n"
"    b       loc_fc1503ba\n"
"loc_fc1502ae:\n"
"    bl      sub_fc15118a\n"
"    b       loc_fc1503ba\n"
".ltorg\n"
// firmware had literal pool here
/*
fcd0 0003
fad4 0003
bd84 0000
*/
"loc_fc1502c0:\n"
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc1511d6\n"
"    b       loc_fc1503ba\n"
"loc_fc1502c8:\n"
"    bl      sub_fc15138e\n"
"    b       loc_fc1503ba\n"
"loc_fc1502ce:\n"
"    bl      sub_fc151770\n"
"    b       loc_fc1503ba\n"
"loc_fc1502d4:\n"
"    bl      sub_fc151806\n"
"    b       loc_fc1503ba\n"
"loc_fc1502da:\n"
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc150722\n"
"    b       loc_fc1503ba\n"
"loc_fc1502e2:\n"
"    bl      sub_fc1e432c\n"
"    b       loc_fc1503ba\n"
"loc_fc1502e8:\n"
"    bl      sub_fc1e44d4\n"
"    b       loc_fc1503ba\n"
"loc_fc1502ee:\n"
"    bl      sub_fc1e4568\n"
"    b       loc_fc1503ba\n"
"loc_fc1502f4:\n"
"    bl      sub_fc1e45f4\n"
"    b       loc_fc1503ba\n"
"loc_fc1502fa:\n"
"    movs    r0, #0\n"
"    b       loc_fc150320\n"
"loc_fc1502fe:\n"
"    bl      sub_fc1e48e8\n"
"    b       loc_fc1503ba\n"
"loc_fc150304:\n"
"    b       loc_fc1503ac\n"
"loc_fc150306:\n"
"    bl      sub_fc1e4948\n"
"    b       loc_fc1503ba\n"
"loc_fc15030c:\n"
"    bl      sub_fc1e494c\n"
"    b       loc_fc1503ba\n"
"loc_fc150312:\n"
"    bl      sub_fc1e495c\n"
"    b       loc_fc1503ba\n"
"loc_fc150318:\n"
"    bl      sub_fc1e49d4\n"
"    b       loc_fc1503ba\n"
"loc_fc15031e:\n"
"    movs    r0, #1\n"
"loc_fc150320:\n"
"    bl      sub_fc1e47c8\n"
"    b       loc_fc1503ba\n"
"loc_fc150326:\n"
"    bl      sub_fc150abe\n"
"    b       loc_fc1503ba\n"
"loc_fc15032c:\n"
"    movs    r0, #0\n"
"    b       loc_fc150332\n"
"loc_fc150330:\n"
"    ldr     r0, [r0, #0xc]\n"
"loc_fc150332:\n"
"    bl      sub_fc150b1e\n"
"    b       loc_fc1503ba\n"
"loc_fc150338:\n"
"    bl      sub_fc1e46f2\n"
"    b       loc_fc1503ba\n"
"loc_fc15033e:\n"
"    bl      sub_fc1e4758\n"
"    b       loc_fc1503ba\n"
"loc_fc150344:\n"
"    bl      sub_fc1e6188\n"
"    b       loc_fc1503ba\n"
"loc_fc15034a:\n"
"    bl      sub_fc14e6c0\n"
"    b       loc_fc1503ba\n"
"loc_fc150350:\n"
"    bl      sub_fc2bff72\n"
"    b       loc_fc1503ba\n"
"loc_fc150356:\n"
"    bl      sub_fc2c004c\n"
"    b       loc_fc1503ba\n"
"loc_fc15035c:\n"
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc1e4aa8\n"
"    b       loc_fc1503ba\n"
"loc_fc150364:\n"
"    bl      sub_fc1e4b10\n"
"    b       loc_fc1503ba\n"
"loc_fc15036a:\n"
"    bl      sub_fc155bea\n"
"    ldrh.w  r0, [r4, #0x1a4]\n"
"    cmp     r0, #4\n"
"    beq     loc_fc150380\n"
"    ldrh    r0, [r4]\n"
"    sub.w   r1, r0, #0x4200\n"
"    subs    r1, #0x36\n"
"    bne     loc_fc1503ba\n"
"loc_fc150380:\n"
"    bl      sub_fc2c004c\n"
"    bl      sub_fc2c0562\n"
"    bl      sub_fc2c03aa\n"
"    b       loc_fc1503ba\n"
"loc_fc15038e:\n"
"    bl      sub_fc151a02\n"
"    movs    r0, #1\n"
"    bl      sub_fc154066\n"
"    b       loc_fc1503ba\n"
"loc_fc15039a:\n"
"    movs    r2, #0\n"
"    movs    r1, #0x11\n"
"    b       loc_fc1503a4\n"
"loc_fc1503a0:\n"
"    movs    r2, #0\n"
"    movs    r1, #0x10\n"
"loc_fc1503a4:\n"
"    movs    r0, #0\n"
"    bl      sub_fc14e934\n"
"    b       loc_fc1503ba\n"
"loc_fc1503ac:\n"
"    movw    r2, #0x575\n"
"    ldr     r1, =0xfc14fe88\n" //  *"SsShootTask.c"
"    movs    r0, #0\n"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc1503ba:\n"
#ifdef CAPTSEQ_DEBUG_LOG
// debug after message handled
"ldr     r0, [sp]\n"
"ldr     r0, [r0]\n"
"bl log_capt_seq2\n"
#endif
"    ldr     r0, [sp]\n"
"    ldr     r1, [r0, #4]\n"
"    ldr     r0, [r5, #4]\n"
"    blx     sub_fc2ef858\n" // j_SetEventFlag
"    ldr     r7, [sp]\n"
"    ldr     r0, [r7, #8]\n"
"    cbnz    r0, loc_fc1503d8\n"
"    movw    r2, #0x12a\n"
"    ldr     r1, =0xfc14fe88\n" //  *"SsShootTask.c"
"    movs    r0, #0\n"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc1503d8:\n"
"    str     r6, [r7, #8]\n"
"    b       loc_fc1501e0\n"
".ltorg\n"
    );
}

// -s=0xfc1e58d9 -c=56 -f=chdk
void __attribute__((naked,noinline)) sub_fc1e58d8_my() {
    asm volatile (
"    push    {r3, r4, r5, r6, r7, lr}\n"
"    bl      sub_fc14f946\n"
"    mov     r4, r0\n"
"    movs    r0, #0xc\n"
"    bl      sub_fc2f7768\n"
"    ldr     r6, =0x0001474c\n"
"    lsls    r0, r0, #0x1f\n"
"    mov.w   r5, #1\n"
"    bne     loc_fc1e5972\n"
"    movs    r2, #2\n"
"    mov     r1, sp\n"
"    movw    r0, #0x110\n"
"    bl      _GetPropertyCase\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc1e590c\n"
"    movs    r0, #0\n"
"    movw    r2, #0x174\n"
"    ldr     r1, =0xfc1e5a5c\n" //  *"SsCaptureCtrl.c"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc1e590c:\n"
"    ldrsh.w r0, [sp]\n"
"    bl      sub_fc134e86\n"
"    bl      sub_fc134d5e\n"
"    cmp     r0, #1\n"
"    bls     loc_fc1e5976\n"
"    movs    r0, #0\n"
"    bl      sub_fc134e16\n"
"    bl      sub_fc15072e\n"
"    bl      sub_fc152724\n"
"    mov     r1, r4\n"
//"    bl      sub_fc152772\n"
"bl captseq_raw_addr_init_my\n"
"    movs    r2, #4\n"
"    movw    r0, #0x116\n"
"    add.w   r1, r4, #0x58\n"
"    bl      _SetPropertyCase\n"
"    movs    r2, #4\n"
"    movs    r0, #0x30\n"
"    add.w   r1, r4, #0x5c\n"
"    bl      _SetPropertyCase\n"
"    movs    r2, #4\n"
"    movs    r0, #0x44\n"
"    add.w   r1, r4, #8\n"
"    bl      _SetPropertyCase\n"
"    bl      sub_fc1e5fb2\n"
"    mvn     r1, #0x1000\n"
"    blx     sub_fc2ef928\n" // j_ClearEventFlag
"    mov     r0, r4\n"
"    bl      sub_fc1e5450\n"
"    mov     r0, r4\n"
"    bl      sub_fc3d387e_my\n" // -> remote hook, raw hook
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc1e5974\n"
"loc_fc1e5972:\n"
"    str     r5, [r6]\n"
"loc_fc1e5974:\n"
"    pop     {r3, r4, r5, r6, r7, pc}\n"
"loc_fc1e5976:\n"
"    bl      sub_fc14e6b6\n"
"    bl      sub_fc2f77a8\n"
"    pop     {r3, r4, r5, r6, r7, pc}\n"
".ltorg\n"
    );
}

//-s=0xfc1e56a7 -c=211 -f=chdk
void __attribute__((naked,noinline)) sub_fc1e56a6_my() {
    asm volatile (
"    push.w  {r2, r3, r4, r5, r6, r7, r8, lr}\n"
"    ldr     r5, =0x0003fad4\n"
"    mov     r4, r0\n"
"    movs    r6, #0\n"
"    ldr     r0, [r5, #0x28]\n"
"    cbz     r0, loc_fc1e56d0\n"
"    ldr     r0, =0x0001474c\n"
"    ldr     r0, [r0]\n"
"    cbz     r0, loc_fc1e56bc\n"
"    movs    r6, #0x1d\n"
"loc_fc1e56bc:\n"
"    mov     r2, r4\n"
"    movs    r1, #2\n"
"    mov     r0, r6\n"
"    bl      sub_fc14e934\n"
"    mov     r1, r6\n"
"    mov     r0, r4\n"
"    bl      sub_fc1e660a\n"
"    b       loc_fc1e58d0\n"
"loc_fc1e56d0:\n"
"    bl      sub_fc152724\n"
"    mov     r1, r4\n"
//"    bl      sub_fc152772\n"
"bl captseq_raw_addr_init_my\n"
"    movw    r7, #0x116\n"
"    movs    r2, #4\n"
"    mov     r0, r7\n"
"    add.w   r1, r4, #0x58\n"
"    bl      _SetPropertyCase\n"
"    movs    r2, #4\n"
"    movs    r0, #0x30\n"
"    add.w   r1, r4, #0x5c\n"
"    bl      _SetPropertyCase\n"
"    ldr.w   r0, [r5, #0x10c]\n"
"    cbnz    r0, loc_fc1e570c\n"
"    ldrh.w  r0, [r5, #0x1a2]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc1e5712\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc1e5722\n"
"    b       loc_fc1e5712\n"
"loc_fc1e570c:\n"
"    ldr     r0, [r4, #0xc]\n"
"    cmp     r0, #1\n"
"    bne     loc_fc1e5722\n"
"loc_fc1e5712:\n"
"    movs    r0, #0xc\n"
"    bl      sub_fc2f7768\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc1e5722\n"
"    bl      sub_fc14e6b6\n"
"    movs    r6, #1\n"
"loc_fc1e5722:\n"
"    lsls    r0, r6, #0x1f\n"
"    bne     loc_fc1e5782\n"
"    ldr.w   r0, [r5, #0xec]\n"
"    cbz     r0, loc_fc1e5746\n"
"    ldrh.w  r0, [r5, #0x1a2]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc1e573a\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc1e5782\n"
"loc_fc1e573a:\n"
"    ldr.w   r0, [r5, #0x10c]\n"
"    cbz     r0, loc_fc1e5746\n"
"    ldr     r0, [r4, #0xc]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc1e5782\n"
"loc_fc1e5746:\n"
"    movs    r2, #2\n"
"    movw    r0, #0x110\n"
"    add     r1, sp, #4\n"
"    bl      _GetPropertyCase\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc1e5760\n"
"    movs    r2, #0xc9\n"
"    movs    r0, #0\n"
"    ldr     r1, =0xfc1e5a5c\n" //  *"SsCaptureCtrl.c"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc1e5760:\n"
"    ldrsh.w r0, [sp, #4]\n"
"    bl      sub_fc134e86\n"
"    bl      sub_fc134d5e\n"
"    cmp     r0, #1\n"
"    bls     loc_fc1e5778\n"
"    movs    r0, #0\n"
"    bl      sub_fc134e16\n"
"    b       loc_fc1e5782\n"
"loc_fc1e5778:\n"
"    bl      sub_fc14e6b6\n"
"    bl      sub_fc2f77a8\n"
"    movs    r6, #1\n"
"loc_fc1e5782:\n"
"    ldr.w   r0, [r5, #0x1cc]\n"
"    cbz     r0, loc_fc1e579e\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    beq     loc_fc1e579e\n"
"    movs    r0, #1\n"
"    bl      sub_fc154066\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc1e579e\n"
"    bl      sub_fc14e6b6\n"
"    movs    r6, #1\n"
"loc_fc1e579e:\n"
"    lsls    r0, r6, #0x1f\n"
"loc_fc1e57a0:\n"
"    bne     loc_fc1e5884\n"
"    mov     r0, r4\n"
"    bl      sub_fc1e61d2\n"
"    mov     r6, r0\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc1e57a0\n"
"    bl      sub_fc1e5fb2\n"
"    mvn     r1, #0x1000\n"
"    blx     sub_fc2ef928\n" // j_ClearEventFlag
"    mov     r0, r4\n"
"    bl      sub_fc3d35ba\n"
"    mov     r6, r0\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc1e58be\n"
"    bl      sub_fc15072e\n"
"    mov     r0, r4\n"
"    bl      sub_fc1e5450\n"
"    ldr.w   r0, [r5, #0x130]\n"
"    cbnz    r0, loc_fc1e57e4\n"
"    ldrh.w  r0, [r5, #0x1a2]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc1e57e4\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc1e57ea\n"
"loc_fc1e57e4:\n"
"    movs    r0, #2\n"
"    bl      sub_fc156a86\n"
"loc_fc1e57ea:\n"
"    ldr.w   r0, [r5, #0xa8]\n"
"    cmp     r0, #0\n"
"    beq     loc_fc1e585a\n"
"    ldrh.w  r0, [r5, #0x1a2]\n"
"    movw    r6, #0x1000\n"
"    cmp     r0, #3\n"
"    beq     loc_fc1e581a\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bls     loc_fc1e581a\n"
"    bl      sub_fc1e5fb2\n"
"    movw    r3, #0x112\n"
"    movw    r2, #0x3a98\n"
"    mov     r1, r6\n"
"    str     r3, [sp]\n"
"    ldr     r3, =0xfc1e5a5c\n" //  *"SsCaptureCtrl.c"
"    bl      sub_fc2f7920\n"
"loc_fc1e581a:\n"
"    movs    r2, #4\n"
"    movw    r0, #0x188\n"
"    add     r1, sp, #4\n"
"    bl      _GetPropertyCase\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc1e5834\n"
"    movs    r0, #0\n"
"    mov     r2, r7\n"
"    ldr     r1, =0xfc1e5a5c\n" //  *"SsCaptureCtrl.c"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc1e5834:\n"
"    ldr     r0, [sp, #4]\n"
"    cbnz    r0, loc_fc1e5844\n"
"    bl      sub_fc1e5fb2\n"
"    mov     r1, r6\n"
"    blx     sub_fc2ef858\n" // j_SetEventFlag
"    b       loc_fc1e585a\n"
"loc_fc1e5844:\n"
"    bl      sub_fc1e5fb2\n"
"    mov     r1, r6\n"
"    blx     sub_fc2ef928\n" // j_ClearEventFlag
"    ldr     r2, =0xfc1e5695\n"
"    mov     r3, r6\n"
"    ldr     r0, [sp, #4]\n"
"    mov     r1, r2\n"
"    bl      sub_fc359114\n"
"loc_fc1e585a:\n"
"    ldr.w   r0, [r5, #0xb0]\n"
"    cbz     r0, loc_fc1e5868\n"
"    mov     r0, r4\n"
"    bl      sub_fc3d40d8\n"
"    b       loc_fc1e58ae\n"
"loc_fc1e5868:\n"
"    ldr.w   r0, [r5, #0xb4]\n"
"    cbz     r0, loc_fc1e5876\n"
"    mov     r0, r4\n"
"    bl      sub_fc3d3d4a\n"
"    b       loc_fc1e58ae\n"
"loc_fc1e5876:\n"
"    ldr.w   r0, [r5, #0xb8]\n"
"    cbz     r0, loc_fc1e5886\n"
"    mov     r0, r4\n"
"    bl      sub_fc3d43dc\n"
"    b       loc_fc1e58ae\n"
"loc_fc1e5884:\n"
"    b       loc_fc1e58be\n"
"loc_fc1e5886:\n"
"    ldr.w   r0, [r5, #0xbc]\n"
"    cbz     r0, loc_fc1e589a\n"
"    ldr     r0, =0x0003fcd0\n"
"    ldr     r0, [r0]\n"
"    cbz     r0, loc_fc1e589a\n"
"    mov     r0, r4\n"
"    bl      sub_fc3d46ce\n"
"    b       loc_fc1e58ae\n"
"loc_fc1e589a:\n"
"    ldr.w   r0, [r5, #0xc0]\n"
"    cmp     r0, #0\n"
"    mov     r0, r4\n"
"    beq     loc_fc1e58aa\n"
"    bl      sub_fc3d49dc\n"
"    b       loc_fc1e58ae\n"
"loc_fc1e58aa:\n"
"    bl      sub_fc3d387e_my\n" // SsStandardCaptureSeq.c -> hook for remote, nr?, raw
"loc_fc1e58ae:\n"
"    ldr.w   r0, [r5, #0x1cc]\n"
"    cbz     r0, loc_fc1e58d0\n"
"    movs    r1, #0\n"
"    movs    r0, #1\n"
"    bl      sub_fc1540ac\n"
"    b       loc_fc1e58d0\n"
"loc_fc1e58be:\n"
"    movs    r1, #2\n"
"    mov     r2, r4\n"
"    mov     r0, r6\n"
"    bl      sub_fc14e934\n"
"    mov     r1, r6\n"
"    mov     r0, r4\n"
"    bl      sub_fc1e6740\n"
"loc_fc1e58d0:\n"
"    movs    r0, #0\n"
"    str     r0, [r5, #0x28]\n"
"    pop.w   {r2, r3, r4, r5, r6, r7, r8, pc}\n"
".ltorg\n"
    );
}

#ifdef CAPTSEQ_DEBUG_LOG
void log_nr_call(void) {
    _LogCameraEvent(0x60,"nr call %d",_nrflag);
}
void log_remote_hook(void) {
    _LogCameraEvent(0x60,"remote hook");
}
void log_rh(void) {
    _LogCameraEvent(0x60,"raw hook arb:%d rb:0x%08x rbc:0x%08x",active_raw_buffer,hook_raw_image_addr(),current_raw_addr);
}
/*
void log_p1(void) {
    _LogCameraEvent(0x60,"p1");
}
void log_p2(void) {
    _LogCameraEvent(0x60,"p2");
}
void log_t1(void) {
    _LogCameraEvent(0x60,"t1");
}
void log_t2(void) {
    _LogCameraEvent(0x60,"t2");
}
void log_t3(void) {
    _LogCameraEvent(0x60,"t3");
}
void log_t4(void) {
    _LogCameraEvent(0x60,"t4");
}
void log_t5(void) {
    _LogCameraEvent(0x60,"t5");
}
*/
#endif

// -s=0xfc3d387f -e=0xfc3d3abc -f=chdk
void __attribute__((naked,noinline)) sub_fc3d387e_my() {
    asm volatile (
"    push.w  {r2, r3, r4, r5, r6, r7, r8, sb, sl, lr}\n"
"    ldr     r7, =0x0003fad4\n"
"    mov     r4, r0\n"
"    ldr.w   r0, [r7, #0x16c]\n"
"    cbz     r0, loc_fc3d389a\n"
"    ldrh.w  r0, [r7, #0x1a2]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc3d389a\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc3d38a4\n"
"loc_fc3d389a:\n"
"    mov     r0, r4\n"
"    bl      sub_fc1e53e6\n"
"    bl      sub_fc1e5e72\n"
"loc_fc3d38a4:\n"
"    ldr.w   r0, [r7, #0xa4]\n"
"    cbnz    r0, loc_fc3d38c0\n"
"    ldrh.w  r0, [r7, #0x1a2]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc3d38b8\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc3d38c0\n"
"loc_fc3d38b8:\n"
"    bl      sub_fc150b0e\n"
"    bl      sub_fc1e5a92\n"
"loc_fc3d38c0:\n"
"    movs    r2, #4\n"
"    movw    r0, #0x137\n"
"    add     r1, sp, #4\n"
"    bl      _GetPropertyCase\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc3d38dc\n"
"    movs    r0, #0\n"
"    movw    r2, #0x156\n"
"    ldr     r1, =0xfc3d3c44\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc3d38dc:\n"
"    ldr     r0, [sp, #4]\n"
"    ubfx    r0, r0, #8, #8\n"
"    cmp     r0, #6\n"
"    bne     loc_fc3d38ec\n"
"    ldr     r0, =0xfc3d3835\n"
"    movs    r1, #0\n"
"    b       loc_fc3d38f0\n"
"loc_fc3d38ec:\n"
"    ldr     r0, =0xfc1e50bf\n"
"    mov     r1, r4\n"
"loc_fc3d38f0:\n"
"    bl      sub_fc1714a0\n"
"    ldr.w   r0, [r7, #0x18c]\n"
"    cbz     r0, loc_fc3d38fe\n"
"    bl      sub_fc1e531e\n"
"loc_fc3d38fe:\n"
"    movs    r0, #0\n"
"    bl      sub_fc15405e\n"
"bl capt_seq_hook_set_nr\n"
#ifdef CAPTSEQ_DEBUG_LOG
"bl log_nr_call\n"
#endif
"    mov     r0, r4\n"
"    bl      sub_fc1e5500\n"
"    ldr     r1, =0x00027eec\n"
"    movs    r2, #4\n"
"    movs    r0, #0x90\n"
"    bl      _GetPropertyCase\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc3d3924\n"
"    movs    r0, #0\n"
"    movw    r2, #0x171\n"
"    ldr     r1, =0xfc3d3c44\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc3d3924:\n"
"    bl      sub_fc154118\n"
"    bl      sub_fc1e5592\n"
"    movs    r1, #0\n"
"    mov     r0, r4\n"
"    bl      sub_fc3d3836\n"
"    mov     r6, r0\n"
"    BL      wait_until_remote_button_is_released\n" // + remote hook
// Could probaby go later, somewhere after loc_fc3d393a, before call to sub_fc1e5582?
#ifdef CAPTSEQ_DEBUG_LOG
"bl log_remote_hook\n"
#endif
"    ldr     r0, [sp, #4]\n"
"    ubfx    r0, r0, #8, #8\n"
"    cmp     r0, #6\n"
"    bne     loc_fc3d3944\n"
"    ldr     r2, =0xfc1e52ed\n"
"    b       loc_fc3d3946\n"
"loc_fc3d3944:\n"
"    ldr     r2, =0xfc1e5303\n"
"loc_fc3d3946:\n"
"    ldrh    r0, [r4, #0x18]\n"
"    ldr     r5, =0x00027eec\n"
"    cbz     r0, loc_fc3d3954\n"
"    cmp     r0, #1\n"
"    beq     loc_fc3d396a\n"
"    cmp     r0, #4\n"
"    bne     loc_fc3d39d6\n"
"loc_fc3d3954:\n"
"    str     r6, [sp]\n"
"    mov     r3, r2\n"
"    ldr     r1, [r4, #0x5c]\n"
"    mov     r0, r4\n"
"    ldr     r2, [r5]\n"
"    bl      sub_fc1e4f12\n"
"    mov     r5, r0\n"
"    bl      sub_fc298492\n"
"    b       loc_fc3d39e4\n"
"loc_fc3d396a:\n"
"    str     r6, [sp]\n"
"    mov     r3, r2\n"
"    ldr     r1, [r4, #0x5c]\n"
"    mov     r8, r5\n"
"    ldr     r2, [r5]\n"
"    mov     r0, r4\n"
"    bl      sub_fc1e4f72\n"
"    mov     r5, r0\n"
"    bl      sub_fc171488\n"
"    cbnz    r0, loc_fc3d398c\n"
"    movs    r2, #1\n"
"    movs    r1, #0\n"
"    movs    r0, #0x45\n"
"    bl      sub_fc28444e\n"
"loc_fc3d398c:\n"
"    lsls    r0, r5, #0x1f\n"
"    bne     loc_fc3d39e4\n"
"    ldr.w   r0, [r7, #0x100]\n"
"    cbz     r0, loc_fc3d39a6\n"
"    ldr     r1, [r4, #8]\n"
"    ldr     r2, =0x001d8cac\n"
"    ldr     r0, [r4, #0x5c]\n"
"    add.w   r1, r2, r1, lsl #2\n"
"    str     r0, [r1, #-0x4]\n"
"    b       loc_fc3d39d0\n"
"loc_fc3d39a6:\n"
"    ldr     r0, =0xfc3d3835\n"
"    movs    r1, #0\n"
"    bl      sub_fc1714a0\n"
"    movs    r1, #1\n"
"    mov     r0, r4\n"
"    bl      sub_fc3d3836\n"
"    mov     r6, r0\n"
"    ldr.w   r0, [r8]\n"
"    mov     r5, r8\n"
"    bl      sub_fc1e5388\n"
"    ldr     r1, [r4, #0x5c]\n"
"    mov     r3, r6\n"
"    ldr     r2, [r5]\n"
"    mov     r0, r4\n"
"    bl      sub_fc1e4fe0\n"
"    mov     r5, r0\n"
"loc_fc3d39d0:\n"
"    bl      sub_fc1e4ebc\n"
"    b       loc_fc3d39e4\n"
"loc_fc3d39d6:\n"
"    movs    r0, #0\n"
"    movw    r2, #0x1aa\n"
"    ldr     r1, =0xfc3d3c44\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"    movs    r5, #0x1d\n"
"loc_fc3d39e4:\n"
"    bl      sub_fc171488\n"
"    cbz     r0, loc_fc3d39ec\n"
"    movs    r5, #1\n"
"loc_fc3d39ec:\n"
"    bl      sub_fc1e5596\n"
"    ldr.w   r8, =0xfc3d3835\n"
"    lsls    r0, r5, #0x1f\n"
"    bne     loc_fc3d3a66\n"
"    ldr.w   r0, [r7, #0x108]\n"
"    cbnz    r0, loc_fc3d3a32\n"
"    ldr.w   r0, [r7, #0x1cc]\n"
"    cbz     r0, loc_fc3d3a1c\n"
"    ldrh.w  r0, [r7, #0x1ec]\n"
"    cmp     r0, #1\n"
"    bne     loc_fc3d3a32\n"
"    mov     r0, r4\n"
"    bl      sub_fc1e6c8a\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc3d3a32\n"
"    movw    r2, #0x1ca\n"
"    b       loc_fc3d3a2a\n"
"loc_fc3d3a1c:\n"
"    mov     r0, r4\n"
"    bl      sub_fc1e6c8a\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc3d3a32\n"
"    movw    r2, #0x1cd\n"
"loc_fc3d3a2a:\n"
"    movs    r0, #0\n"
"    ldr     r1, =0xfc3d3c44\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc3d3a32:\n"
#ifdef CAPTSEQ_DEBUG_LOG
"bl log_rh\n"
#endif
"    BL      capt_seq_hook_raw_here\n"
"    BL      clear_current_raw_addr\n"
"    mov     r0, r4\n"
"    bl      sub_fc1e5582\n"
"    mov     r0, r4\n"
"    bl      sub_fc1e5556\n"
"    cmp     r6, r8\n"
"    beq     loc_fc3d3a66\n"
"    bl      sub_fc1e5fb2\n"
"    movs    r1, #4\n"
"    movw    sb, #0x1dd\n"
"    ldr     r3, =0xfc3d3c44\n" //  *"SsStandardCaptureSeq.c"
"    movw    r2, #0x3a98\n"
"    str.w   sb, [sp]\n"
"    bl      sub_fc2f7920\n"
"    cbz     r0, loc_fc3d3a66\n"
"    movs    r0, #0\n"
"    mov     r2, sb\n"
"    ldr     r1, =0xfc3d3c44\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc3d3a66:\n"
"    ldrh    r0, [r7]\n"
"    sub.w   r1, r0, #0x4000\n"
"    subs    r1, #0x44\n"
"    bne     loc_fc3d3a88\n"
"    bl      sub_fc1e5fb2\n"
"    movw    r1, #0x8000\n"
"    blx     sub_fc2ef928\n" // j_ClearEventFlag
"    ldr     r0, =0xfc3d386d\n"
"    movs    r1, #0\n"
"    bl      sub_fc284af4\n"
"    bl      sub_fc284ae6\n"
"loc_fc3d3a88:\n"
"    ldr.w   r0, [r7, #0x18c]\n"
"    cbz     r0, loc_fc3d3a98\n"
"    movs    r2, #1\n"
"    movs    r1, #0\n"
"    movs    r0, #0x46\n"
"    bl      sub_fc28444e\n"
"loc_fc3d3a98:\n"
"    movs    r1, #2\n"
"    mov     r2, r4\n"
"    mov     r0, r5\n"
"    bl      sub_fc14e934\n"
"    ldr     r0, [r7, #0x28]\n"
"    cmp     r0, #0\n"
"    mov     r0, r8\n"
"    beq     loc_fc3d3abe\n"
"    cmp     r6, r0\n"
"    beq     loc_fc3d3ab2\n"
"    movs    r1, #1\n"
"    b       loc_fc3d3ab4\n"
"loc_fc3d3ab2:\n"
"    movs    r1, #0\n"
"loc_fc3d3ab4:\n"
"    mov     r2, r5\n"
"    mov     r0, r4\n"
"    bl      sub_fc1e65c8\n"
"    b       loc_fc3d3ad0\n"
"loc_fc3d3abe:\n"
"    cmp     r6, r0\n"
"    beq     loc_fc3d3ac6\n"
"    movs    r1, #1\n"
"    b       loc_fc3d3ac8\n"
"loc_fc3d3ac6:\n"
"    movs    r1, #0\n"
"loc_fc3d3ac8:\n"
"    mov     r2, r5\n"
"    mov     r0, r4\n"
"    bl      sub_fc1e6582\n"
"loc_fc3d3ad0:\n"
"    mov     r0, r5\n"
"    pop.w   {r2, r3, r4, r5, r6, r7, r8, sb, sl, pc}\n"
".ltorg\n"
    );
}

// below from 100d, not checked
// not using DvlpSeq, multiple shots may be taken before task runs, out of sync with file counter
#if 0
void log_dvlp_seq(int m,int m2)
{
    _LogCameraEvent(0x60,"dvlp m:%d m2:0x%x arb:%d rb:0x%08x i:%04d",
                    m,
                    m2,
                    active_raw_buffer,
                    hook_raw_image_addr(),
                    get_exposure_counter());

}
void log_dvlp_raw_hook(int m)
{
    _LogCameraEvent(0x60,"dvlp rh m:%d arb:%d rb:0x%08x i:%04d",
                    m,
                    active_raw_buffer,
                    hook_raw_image_addr(),
                    get_exposure_counter());
}
void log_dvlp_seq_1(void)
{
    _LogCameraEvent(0x60,"dvlp seq loop");
}
void log_dvlp_seq_start(void)
{
    _LogCameraEvent(0x60,"dvlp seq start");
}
// -s=task_DvlpSeqTask -c=100 -f=chdk
// task_DvlpSeqTask 0xfc1e6837
void __attribute__((naked,noinline)) developseq_task() {
    asm volatile (
"    push.w  {r2, r3, r4, r5, r6, r7, r8, lr}\n"
"bl log_dvlp_seq_start\n"
"    ldr     r7, =0x0003fad4\n"
"    movs    r5, #0\n"
"    ldr     r6, =0x00014780\n"
"loc_fc1e6840:\n"
"bl log_dvlp_seq_1\n"
"    movs    r2, #0\n"
"    ldr     r1, [r6, #0x10]\n"
"    ldr     r0, [r6, #8]\n"
"    blx     sub_fc2ef87c\n" // j_PostMessageQueue
"    ldr     r0, [r6, #4]\n"
"    movs    r2, #0\n"
"    add     r1, sp, #4\n"
"    blx     sub_fc2ef8ec\n" // j_ReceiveMessageQueue
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc1e685e\n"
"    movw    r2, #0x1c4\n"
"    b       loc_fc1e686e\n"
"loc_fc1e685e:\n"
"    ldr     r0, [r6, #8]\n"
"    mov     r1, sp\n"
"    blx     sub_fc2ef70c\n" // j_TryReceiveMessageQueue
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc1e687e\n"
"    movw    r2, #0x1ca\n"
"loc_fc1e686e:\n"
"    movs    r0, #0\n"
"    ldr     r1, =0xfc1e6bd8\n" //  *"SsDvlpSeq.c"
"    blx     sub_fc2ef9e4\n" // j_DebugAssert
"    blx     sub_fc2ef90c\n"
"    pop.w   {r2, r3, r4, r5, r6, r7, r8, pc}\n"
"loc_fc1e687e:\n"
"    ldr.w   r0, [r7, #0x18c]\n"
"    cbz     r0, loc_fc1e688c\n"
"    ldr     r0, [sp, #4]\n"
"    ldr     r0, [r0]\n"
"    cmp     r0, #5\n"
"    bne     loc_fc1e6898\n"
"loc_fc1e688c:\n"
"    bl      sub_fc3d4f92\n"
"    bl      sub_fc1524bc\n"
"    bl      sub_fc1e8680\n"
"loc_fc1e6898:\n"
"ldr     r0, [sp, #4]\n"
"ldr     r0, [r0]\n"
"ldr     r1, [sp]\n"
"bl      log_dvlp_seq\n"
"    ldr     r0, [sp, #4]\n"
"    ldr     r1, [r0]\n"
"    cmp     r1, #6\n"
"    bhs     loc_fc1e691e\n"
"    tbb     [pc, r1]\n" // (jumptable r1 6 elements)
"branchtable_fc1e68a4:\n"
"    .byte((loc_fc1e68aa - branchtable_fc1e68a4) / 2)\n" // (case 0)
"    .byte((loc_fc1e68b2 - branchtable_fc1e68a4) / 2)\n" // (case 1)
"    .byte((loc_fc1e68b8 - branchtable_fc1e68a4) / 2)\n" // (case 2)
"    .byte((loc_fc1e68dc - branchtable_fc1e68a4) / 2)\n" // (case 3)
"    .byte((loc_fc1e690e - branchtable_fc1e68a4) / 2)\n" // (case 4)
"    .byte((loc_fc1e6914 - branchtable_fc1e68a4) / 2)\n" // (case 5)
".align 1\n"
"loc_fc1e68aa:\n" // case 0
"ldr     r0, [sp, #4]\n"
"ldr     r0, [r0]\n"
"bl      log_dvlp_raw_hook\n"
//"    BL      capt_seq_hook_raw_here\n" // test
"ldr     r0, [sp, #4]\n"
"ldr     r1, [r0]\n"
"    ldr     r0, [r0, #8]\n"
"    bl      sub_fc1e7a2a\n"
"    b       loc_fc1e691e\n"
"loc_fc1e68b2:\n"
"    bl      sub_fc3d5050\n"
"    b       loc_fc1e691e\n"
"loc_fc1e68b8:\n"
"    ldr     r2, [r0, #8]\n"
"    movs    r1, #1\n"
"    str.w   r1, [r2, #0x108]\n"
"    ldr     r0, [r0, #8]\n"
"    bl      sub_fc1e783a\n"
"    ldr     r0, [sp, #4]\n"
"    ldr     r0, [r0, #8]\n"
"    str.w   r5, [r0, #0x108]\n"
"    ldr     r0, [r6, #0xc]\n"
"    blx     sub_fc2ef96c\n"
"    ldr     r0, [sp, #4]\n"
"    movs    r1, #0xd\n"
"    ldr     r2, [r0, #8]\n"
"    b       loc_fc1e6918\n"
"loc_fc1e68dc:\n"
"    ldr.w   r1, [r7, #0xc0]\n"
"    cbz     r1, loc_fc1e68f8\n"
"    ldr     r0, [r0, #8]\n"
"    ldr.w   r1, [r0, #0xfc]\n"
"    cmp     r1, #1\n"
"    bne     loc_fc1e68f0\n"
"loc_fc1e68ec:\n"
"    movs    r1, #1\n"
"    b       loc_fc1e68f2\n"
"loc_fc1e68f0:\n"
"    movs    r1, #0\n"
"loc_fc1e68f2:\n"
"    bl      sub_fc1e75fa\n"
"    b       loc_fc1e691e\n"
"loc_fc1e68f8:\n"
"    ldr.w   r1, [r7, #0x1cc]\n"
"    cbz     r1, loc_fc1e690a\n"
"    ldrh.w  r1, [r7, #0x1ec]\n"
"    cmp     r1, #1\n"
"    beq     loc_fc1e690a\n"
"    ldr     r0, [r0, #8]\n"
"    b       loc_fc1e68f0\n"
"loc_fc1e690a:\n"
"    ldr     r0, [r0, #8]\n"
"    b       loc_fc1e68ec\n"
"loc_fc1e690e:\n"
"    bl      sub_fc1515f6\n"
"    b       loc_fc1e691e\n"
"loc_fc1e6914:\n"
"    movs    r2, #0\n"
"    movs    r1, #0x12\n"
"loc_fc1e6918:\n"
"    movs    r0, #0\n"
"    bl      sub_fc14e934\n"
"loc_fc1e691e:\n"
/*
"ldr     r0, [sp, #4]\n"
"ldr     r0, [r0]\n"
"bl      log_dvlp_raw_hook\n"
"    BL      capt_seq_hook_raw_here\n" // test
*/
"    ldr     r4, [sp, #4]\n"
"    ldr     r0, [r4, #4]\n"
"    cbnz    r0, loc_fc1e692e\n"
"    movs    r2, #0x86\n"
"    movs    r0, #0\n"
"    ldr     r1, =0xfc1e6bd8\n" //  *"SsDvlpSeq.c"
"    blx     sub_fc2ef9e4\n" // j_DebugAssert
"loc_fc1e692e:\n"
"    str     r5, [r4, #4]\n"
"    add     r1, sp, #4\n"
"    ldr     r0, [r6, #4]\n"
"    blx     sub_fc2ef70c\n" // j_TryReceiveMessageQueue
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc1e687e\n"
"    b       loc_fc1e6840\n"
".ltorg\n"
    );
}
#endif
