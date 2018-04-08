#include "lolevel.h"
#include "platform.h"
#include "core.h"

//#define CAPTSEQ_DEBUG 1
#undef CAPTSEQ_DEBUG

#define USE_STUBS_NRFLAG 1
#define NR_AUTO (0)                 // have to explictly reset value back to 0 to enable auto

extern int active_raw_buffer;
// debug
extern void _LogCameraEvent(int id,const char *fmt,...);

extern char *hook_raw_image_addr(void);

#ifdef CAPTSEQ_DEBUG
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
void log_remote_hook(void) {
    _LogCameraEvent(0x60,"remote hook1 %d", *(unsigned*)0xc0242014);
}
void log_remote_hook2(void) {
    _LogCameraEvent(0x60,"remote hook2 %d", *(unsigned*)0xc0242014);
}
void log_rh(void) {
    _LogCameraEvent(0x60,"raw hook");
}
#endif

#include "../../../generic/capt_seq.c"
// -f=chdk -s=task_CaptSeqTask -c=179
void __attribute__((naked,noinline)) capt_seq_task() {
    asm volatile (
// task_CaptSeqTask 0xfc0bce67
"    push    {r3, r4, r5, r6, r7, lr}\n"
"    ldr     r4, =0x0005dd60\n"
"    movs    r6, #0\n"
"    ldr     r5, =0x0000b1f8\n"
"loc_fc0bce6e:\n"
"    movs    r2, #0\n"
"    mov     r1, sp\n"
"    ldr     r0, [r5, #8]\n"
"    blx     sub_fc314c7c\n" // j_ReceiveMessageQueue
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc0bce90\n"
"    movw    r2, #0x455\n"
"    ldr     r1, =0xfc0bca88\n" //  *"SsShootTask.c"
"    movs    r0, #0\n"
"    blx     sub_fc314dec\n" // j_DebugAssert
"    blx     sub_fc314ca4\n" // -> ExitTask_FW
"    pop     {r3, r4, r5, r6, r7, pc}\n"
"loc_fc0bce90:\n"
"    ldr     r0, [sp]\n"
"    ldr     r0, [r0]\n"
"    cmp     r0, #1\n"
"    beq     loc_fc0bcea8\n"
"    cmp     r0, #0x27\n"
"    beq     loc_fc0bcea8\n"
"    cmp     r0, #0x1c\n"
"    beq     loc_fc0bcea8\n"
"    cmp     r0, #0x1f\n"
"    beq     loc_fc0bcea8\n"
"    bl      sub_fc18c164\n"
"loc_fc0bcea8:\n"
#ifdef CAPTSEQ_DEBUG
"ldr     r0, [sp]\n"
"ldr     r0, [r0]\n"
"bl log_capt_seq\n"
#endif
"    ldr     r0, [sp]\n"
"    ldr     r1, [r0]\n"
"    cmp     r1, #0x2e\n"
"    bhs     loc_fc0bcf6a\n"
"    tbb     [pc, r1]\n" // (jumptable r1 46 elements)
"branchtable_fc0bceb4:\n"
"    .byte((loc_fc0bcee2 - branchtable_fc0bceb4) / 2)\n" // (case 0)
"    .byte((loc_fc0bcef8 - branchtable_fc0bceb4) / 2)\n" // (case 1)
"    .byte((loc_fc0bcf00 - branchtable_fc0bceb4) / 2)\n" // (case 2)
"    .byte((loc_fc0bcf0e - branchtable_fc0bceb4) / 2)\n" // (case 3)
"    .byte((loc_fc0bcf08 - branchtable_fc0bceb4) / 2)\n" // (case 4)
"    .byte((loc_fc0bcf18 - branchtable_fc0bceb4) / 2)\n" // (case 5)
"    .byte((loc_fc0bcf1e - branchtable_fc0bceb4) / 2)\n" // (case 6)
"    .byte((loc_fc0bcf5c - branchtable_fc0bceb4) / 2)\n" // (case 7)
"    .byte((loc_fc0bcf2e - branchtable_fc0bceb4) / 2)\n" // (case 8)
"    .byte((loc_fc0bcf36 - branchtable_fc0bceb4) / 2)\n" // (case 9)
"    .byte((loc_fc0bcf3c - branchtable_fc0bceb4) / 2)\n" // (case 10)
"    .byte((loc_fc0bcf44 - branchtable_fc0bceb4) / 2)\n" // (case 11)
"    .byte((loc_fc0bcf4a - branchtable_fc0bceb4) / 2)\n" // (case 12)
"    .byte((loc_fc0bcf50 - branchtable_fc0bceb4) / 2)\n" // (case 13)
"    .byte((loc_fc0bcf56 - branchtable_fc0bceb4) / 2)\n" // (case 14)
"    .byte((loc_fc0bcf64 - branchtable_fc0bceb4) / 2)\n" // (case 15)
"    .byte((loc_fc0bcf78 - branchtable_fc0bceb4) / 2)\n" // (case 16)
"    .byte((loc_fc0bcf7e - branchtable_fc0bceb4) / 2)\n" // (case 17)
"    .byte((loc_fc0bcf84 - branchtable_fc0bceb4) / 2)\n" // (case 18)
"    .byte((loc_fc0bcf8a - branchtable_fc0bceb4) / 2)\n" // (case 19)
"    .byte((loc_fc0bcf8e - branchtable_fc0bceb4) / 2)\n" // (case 20)
"    .byte((loc_fc0bcf94 - branchtable_fc0bceb4) / 2)\n" // (case 21)
"    .byte((loc_fc0bcf9a - branchtable_fc0bceb4) / 2)\n" // (case 22)
"    .byte((loc_fc0bcfa0 - branchtable_fc0bceb4) / 2)\n" // (case 23)
"    .byte((loc_fc0bcfa6 - branchtable_fc0bceb4) / 2)\n" // (case 24)
"    .byte((loc_fc0bcfac - branchtable_fc0bceb4) / 2)\n" // (case 25)
"    .byte((loc_fc0bcfb4 - branchtable_fc0bceb4) / 2)\n" // (case 26)
"    .byte((loc_fc0bcfba - branchtable_fc0bceb4) / 2)\n" // (case 27)
"    .byte((loc_fc0bcfbe - branchtable_fc0bceb4) / 2)\n" // (case 28)
"    .byte((loc_fc0bcfc6 - branchtable_fc0bceb4) / 2)\n" // (case 29)
"    .byte((loc_fc0bcfcc - branchtable_fc0bceb4) / 2)\n" // (case 30)
"    .byte((loc_fc0bcfd2 - branchtable_fc0bceb4) / 2)\n" // (case 31)
"    .byte((loc_fc0bcfd8 - branchtable_fc0bceb4) / 2)\n" // (case 32)
"    .byte((loc_fc0bcfde - branchtable_fc0bceb4) / 2)\n" // (case 33)
"    .byte((loc_fc0bcfe4 - branchtable_fc0bceb4) / 2)\n" // (case 34)
"    .byte((loc_fc0bcfea - branchtable_fc0bceb4) / 2)\n" // (case 35)
"    .byte((loc_fc0bcff2 - branchtable_fc0bceb4) / 2)\n" // (case 36)
"    .byte((loc_fc0bcff8 - branchtable_fc0bceb4) / 2)\n" // (case 37)
"    .byte((loc_fc0bd01c - branchtable_fc0bceb4) / 2)\n" // (case 38)
"    .byte((loc_fc0bd022 - branchtable_fc0bceb4) / 2)\n" // (case 39)
"    .byte((loc_fc0bd05a - branchtable_fc0bceb4) / 2)\n" // (case 40)
"    .byte((loc_fc0bd02e - branchtable_fc0bceb4) / 2)\n" // (case 41)
"    .byte((loc_fc0bd034 - branchtable_fc0bceb4) / 2)\n" // (case 42)
"    .byte((loc_fc0bd03a - branchtable_fc0bceb4) / 2)\n" // (case 43)
"    .byte((loc_fc0bd040 - branchtable_fc0bceb4) / 2)\n" // (case 44)
"    .byte((loc_fc0bd046 - branchtable_fc0bceb4) / 2)\n" // (case 45)
".align 1\n"
"loc_fc0bcee2:\n"
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc0d4f20\n"
#ifdef CAPTSEQ_DEBUG
"bl log_capt_seq_override\n" // debug
#endif
"    bl      shooting_expo_param_override\n" // +
"    bl      sub_fc101d70\n"
"    ldr     r0, [r4, #0x28]\n"
"    cmp     r0, #0\n"
"    beq     loc_fc0bcef6\n"
"    bl      sub_fc0dd248_my\n" // ->
"loc_fc0bcef6:\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcef8:\n"
"    ldr     r0, [r0, #0x10]\n"
"    bl      sub_fc0dd0dc_my\n" // ->
"    b       loc_fc0bd05a\n"
"loc_fc0bcf00:\n"
"    movs    r0, #1\n"
"    bl      sub_fc0d51b0\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf08:\n"
"    bl      sub_fc0d4c64\n"
"    b       loc_fc0bcf14\n"
"loc_fc0bcf0e:\n"
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc0d4f08\n"
"loc_fc0bcf14:\n"
"    str     r6, [r4, #0x28]\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf18:\n"
"    bl      sub_fc0d4f0e\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf1e:\n"
"    bl      sub_fc0d5152\n"
"    bl      sub_fc101d70\n"
"    movs    r0, #0\n"
"    bl      sub_fc2a5046\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf2e:\n"
"    ldr     r0, [r4, #0x54]\n"
"    bl      sub_fc0d5756\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf36:\n"
"    bl      sub_fc0d59e2\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf3c:\n"
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc0d5a2e\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf44:\n"
"    bl      sub_fc0d5bf4\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf4a:\n"
"    bl      sub_fc0d5c52\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf50:\n"
"    bl      sub_fc0d6008\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf56:\n"
"    bl      sub_fc0d609e\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf5c:\n"
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc0d4f08\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf64:\n"
"    bl      sub_fc0dc83c\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf6a:\n"
"    b       loc_fc0bd04c\n"
// - literal pool removed
".ltorg\n"
"loc_fc0bcf78:\n"
"    bl      sub_fc0dc9f4\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf7e:\n"
"    bl      sub_fc0dca98\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf84:\n"
"    bl      sub_fc0dcb2a\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf8a:\n"
"    movs    r0, #0\n"
"    b       loc_fc0bcfae\n"
"loc_fc0bcf8e:\n"
"    bl      sub_fc0dce20\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf94:\n"
"    bl      sub_fc0dce80\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcf9a:\n"
"    bl      sub_fc0dce84\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcfa0:\n"
"    bl      sub_fc0dce94\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcfa6:\n"
"    bl      sub_fc0dcf28\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcfac:\n"
"    movs    r0, #1\n"
"loc_fc0bcfae:\n"
"    bl      sub_fc0dcd00\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcfb4:\n"
"    bl      sub_fc0d5276\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcfba:\n"
"    movs    r0, #0\n"
"    b       loc_fc0bcfc0\n"
"loc_fc0bcfbe:\n"
"    ldr     r0, [r0, #0xc]\n"
"loc_fc0bcfc0:\n"
"    bl      sub_fc0d52a8\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcfc6:\n"
"    bl      sub_fc0dcc46\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcfcc:\n"
"    bl      sub_fc0dccb2\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcfd2:\n"
"    bl      sub_fc10fd1c\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcfd8:\n"
"    bl      sub_fc10256c\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcfde:\n"
"    bl      sub_fc0d67ca\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcfe4:\n"
"    bl      sub_fc0d6884\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcfea:\n"
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc0dd008\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcff2:\n"
"    bl      sub_fc0dd05a\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bcff8:\n"
"    bl      sub_fc0d71b8\n"
"    bl      sub_fc0d7ffe\n"
"    ldrh.w  r0, [r4, #0x1a4]\n"
"    cmp     r0, #4\n"
"    beq     loc_fc0bd012\n"
"    ldrh    r0, [r4]\n"
"    sub.w   r1, r0, #0x8200\n"
"    subs    r1, #0x36\n"
"    bne     loc_fc0bd05a\n"
"loc_fc0bd012:\n"
"    bl      sub_fc0d6884\n"
"    bl      sub_fc0d6c06\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bd01c:\n"
"    movs    r2, #0\n"
"    movs    r1, #0x11\n"
"    b       loc_fc0bd026\n"
"loc_fc0bd022:\n"
"    movs    r2, #0\n"
"    movs    r1, #0x10\n"
"loc_fc0bd026:\n"
"    movs    r0, #0\n"
"    bl      sub_fc1026fa\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bd02e:\n"
"    bl      sub_fc110468\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bd034:\n"
"    bl      sub_fc1104e4\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bd03a:\n"
"    bl      sub_fc110524\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bd040:\n"
"    bl      sub_fc1103ac\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bd046:\n"
"    bl      sub_fc1103ae\n"
"    b       loc_fc0bd05a\n"
"loc_fc0bd04c:\n"
"    movw    r2, #0x588\n"
"    ldr     r1, =0xfc0bca88\n" //  *"SsShootTask.c"
"    movs    r0, #0\n"
"    blx     sub_fc314dec\n" // j_DebugAssert
"loc_fc0bd05a:\n"
#ifdef CAPTSEQ_DEBUG
// debug after message handled
"ldr     r0, [sp]\n"
"ldr     r0, [r0]\n"
"bl log_capt_seq2\n"
#endif
"    ldr     r0, [sp]\n"
"    ldr     r1, [r0, #4]\n"
"    ldr     r0, [r5, #4]\n"
"    blx     sub_fc314c94\n" // j_SetEventFlag
"    ldr     r7, [sp]\n"
"    ldr     r0, [r7, #8]\n"
"    cbnz    r0, loc_fc0bd078\n"
"    movw    r2, #0x12b\n"
"    ldr     r1, =0xfc0bca88\n" //  *"SsShootTask.c"
"    movs    r0, #0\n"
"    blx     sub_fc314dec\n" // j_DebugAssert
"loc_fc0bd078:\n"
"    str     r6, [r7, #8]\n"
"    b       loc_fc0bce6e\n"
".ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc0dd248_my() {
    asm volatile (
// PRIMARY.BIN size:0x2000000 start:0xfc0dd249 instructions:34 opts:0xef
"    push    {r4, lr}\n"
"    bl      sub_fc102c38\n"
"    mov     r4, r0\n"
"    bl      sub_fc0d4f14\n"
"    bl      sub_fc137bd8\n"
"    mov     r1, r4\n"
"    bl      sub_fc137c26\n"
"    movs    r2, #4\n"
"    movw    r0, #0x118\n"
"    add.w   r1, r4, #0x34\n"
"    bl      sub_fc3880d8\n" // SetPropertyCase
"    movs    r2, #4\n"
"    movs    r0, #0x32\n"
"    add.w   r1, r4, #0x38\n"
"    bl      sub_fc3880d8\n" // SetPropertyCase
"    movs    r2, #4\n"
"    movs    r0, #0x46\n"
"    add.w   r1, r4, #8\n"
"    bl      sub_fc3880d8\n" // SetPropertyCase
"    bl      sub_fc18bc92\n"
"    mvn     r1, #0x1000\n"
"    blx     sub_fc314d3c\n" // j_ClearEventFlag
"    mov     r0, r4\n"
"    bl      sub_fc18b978\n"
"    bl      sub_fc2494d4\n"
"    bl      sub_fc2a6a1e\n"
"    mov     r0, r4\n"
"    bl      sub_fc116fa2_my\n" // ->
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc0dd2ae\n"
"    ldr     r1, =0x00012db4\n"
"    movs    r0, #1\n"
"    str     r0, [r1]\n"
"loc_fc0dd2ae:\n"
"    pop     {r4, pc}\n"
".ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc0dd0dc_my() {
    asm volatile (
// PRIMARY.BIN size:0x2000000 start:0xfc0dd0dd instructions:136 opts:0xef
"    push    {r3, r4, r5, r6, r7, lr}\n"
"    ldr     r6, =0x0005dd60\n"
"    mov     r5, r0\n"
"    movs    r4, #0\n"
"    ldr     r0, [r6, #0x28]\n"
"    cbz     r0, loc_fc0dd104\n"
"    ldr     r0, =0x00012db4\n"
"    ldr     r0, [r0]\n"
"    cbz     r0, loc_fc0dd0f0\n"
"    movs    r4, #0x1d\n"
"loc_fc0dd0f0:\n"
"    mov     r2, r5\n"
"    movs    r1, #2\n"
"    mov     r0, r4\n"
"    bl      sub_fc1026fa\n"
"    mov     r1, r4\n"
"    mov     r0, r5\n"
"    bl      sub_fc18bff0\n"
"    b       loc_fc0dd23e\n"
"loc_fc0dd104:\n"
"    bl      sub_fc137bd8\n"
"    mov     r1, r5\n"
"    bl      sub_fc137c26\n"
"    movs    r2, #4\n"
"    movw    r0, #0x118\n"
"    add.w   r1, r5, #0x34\n"
"    bl      sub_fc3880d8\n" // SetPropertyCase
"    movs    r2, #4\n"
"    movs    r0, #0x32\n"
"    add.w   r1, r5, #0x38\n"
"    bl      sub_fc3880d8\n" // SetPropertyCase
"    ldr.w   r0, [r6, #0x10c]\n"
"    cbnz    r0, loc_fc0dd13e\n"
"    ldrh.w  r0, [r6, #0x1a2]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc0dd144\n"
"    ldr     r0, [r5, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc0dd154\n"
"    b       loc_fc0dd144\n"
"loc_fc0dd13e:\n"
"    ldr     r0, [r5, #0xc]\n"
"    cmp     r0, #1\n"
"    bne     loc_fc0dd154\n"
"loc_fc0dd144:\n"
"    movs    r0, #0xc\n"
"    bl      sub_fc33e0c8\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc0dd154\n"
"    bl      sub_fc102562\n"
"    movs    r4, #1\n"
"loc_fc0dd154:\n"
"    lsls    r0, r4, #0x1f\n"
"    bne     loc_fc0dd22c\n"
"    ldr.w   r0, [r6, #0xec]\n"
"    cbz     r0, loc_fc0dd178\n"
"    ldrh.w  r0, [r6, #0x1a2]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc0dd16c\n"
"    ldr     r0, [r5, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc0dd1be\n"
"loc_fc0dd16c:\n"
"    ldr.w   r0, [r6, #0x10c]\n"
"    cbz     r0, loc_fc0dd178\n"
"    ldr     r0, [r5, #0xc]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc0dd1be\n"
"loc_fc0dd178:\n"
"    bl      sub_fc1105c8\n"
"    cbnz    r0, loc_fc0dd1be\n"
"    movs    r2, #2\n"
"    mov     r1, sp\n"
"    movw    r0, #0x112\n"
"    bl      sub_fc38822a\n" // GetPropertyCase
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc0dd198\n"
"    movs    r2, #0xcb\n"
"    movs    r0, #0\n"
"    ldr     r1, =0xfc0dd2bc\n" //  *"SsCaptureCtrl.c"
"    blx     sub_fc314dec\n" // j_DebugAssert
"loc_fc0dd198:\n"
"    ldrsh.w r0, [sp]\n"
"    bl      sub_fc1271a6\n"
"    bl      sub_fc127068\n"
"    cmp     r0, #1\n"
"    bls     loc_fc0dd1b0\n"
"    movs    r0, #0\n"
"    bl      sub_fc127130\n"
"    b       loc_fc0dd1be\n"
"loc_fc0dd1b0:\n"
"    bl      sub_fc102562\n"
"    bl      sub_fc33e108\n"
"    movs    r4, #1\n"
"    lsls    r0, r4, #0x1f\n"
"    bne     loc_fc0dd22c\n"
"loc_fc0dd1be:\n"
"    mov     r0, r5\n"
"    bl      sub_fc10fd82\n"
"    mov     r4, r0\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc0dd22c\n"
"    bl      sub_fc18bc92\n"
"    mvn     r1, #0x1000\n"
"    blx     sub_fc314d3c\n" // j_ClearEventFlag
"    bl      sub_fc2494d4\n"
"    bl      sub_fc2a6a1e\n"
"    mov     r0, r5\n"
"    bl      sub_fc116cec\n"
"    mov     r4, r0\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc0dd22c\n"
"    bl      sub_fc0d4f14\n"
"    mov     r0, r5\n"
"    bl      sub_fc18b978\n"
"    movs    r0, #2\n"
"    bl      sub_fc0d7a2e\n"
"    ldr.w   r0, [r6, #0xb0]\n"
"    cbz     r0, loc_fc0dd208\n"
"    mov     r0, r5\n"
"    bl      sub_fc1175a8\n"
"    b       loc_fc0dd23e\n"
"loc_fc0dd208:\n"
"    ldr.w   r0, [r6, #0xb4]\n"
"    cbz     r0, loc_fc0dd216\n"
"    mov     r0, r5\n"
"    bl      sub_fc11721e\n"
"    b       loc_fc0dd23e\n"
"loc_fc0dd216:\n"
"    ldr.w   r0, [r6, #0xb8]\n"
"    cmp     r0, #0\n"
"    mov     r0, r5\n"
"    beq     loc_fc0dd226\n"
"    bl      sub_fc1178a4\n"
"    b       loc_fc0dd23e\n"
"loc_fc0dd226:\n"
"    bl      sub_fc116fa2_my\n" // ->
"    b       loc_fc0dd23e\n"
"loc_fc0dd22c:\n"
"    movs    r1, #2\n"
"    mov     r2, r5\n"
"    mov     r0, r4\n"
"    bl      sub_fc1026fa\n"
"    mov     r1, r4\n"
"    mov     r0, r5\n"
"    bl      sub_fc18c126\n"
"loc_fc0dd23e:\n"
"    bl      sub_fc0d5c44\n"
"    movs    r0, #0\n"
"    str     r0, [r6, #0x28]\n"
"    pop     {r3, r4, r5, r6, r7, pc}\n"
".ltorg\n"
    );
}


void __attribute__((naked,noinline)) sub_fc116fa2_my() {
    asm volatile (
// PRIMARY.BIN size:0x2000000 start:0xfc116fa3 instructions:207 opts:0xef
"    push.w  {r1, r2, r3, r4, r5, r6, r7, r8, sb, lr}\n"
"    ldr     r6, =0xfc116f7d\n"
"    mov     r5, r0\n"
"    bl      sub_fc18b90e\n"
"    bl      sub_fc0dd712\n"
"    ldr     r7, =0x0005dd60\n"
"    ldr.w   r0, [r7, #0xa4]\n"
"    cbnz    r0, loc_fc116fd0\n"
"    ldrh.w  r0, [r7, #0x1a2]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc116fc8\n"
"    ldr     r0, [r5, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc116fd0\n"
"loc_fc116fc8:\n"
"    bl      sub_fc0d5298\n"
"    bl      sub_fc0dd2de\n"
"loc_fc116fd0:\n"
"    movs    r2, #4\n"
"    movw    r0, #0x139\n"
"    add     r1, sp, #8\n"
"    bl      sub_fc38822a\n" // GetPropertyCase
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc116fec\n"
"    movs    r0, #0\n"
"    movw    r2, #0x150\n"
"    ldr     r1, =0xfc1171c8\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc314dec\n" // j_DebugAssert
"loc_fc116fec:\n"
#ifdef CAPTSEQ_DEBUG
// Ant's remote hook location
"bl log_remote_hook\n"
#endif
"    ldr     r0, [sp, #8]\n"
"    ubfx    r0, r0, #8, #8\n"
"    cmp     r0, #6\n"
"    bne     loc_fc116ffc\n"
"    ldr     r0, =0xfc116f7d\n"
"    movs    r1, #0\n"
"    b       loc_fc117000\n"
"loc_fc116ffc:\n"
"    ldr     r0, =0xfc18b687\n"
"    mov     r1, r5\n"
"loc_fc117000:\n"
"    bl      sub_fc144f10\n"
"    movs    r2, #2\n"
"    movw    r0, #0x114\n"
"    add     r1, sp, #4\n"
"    bl      sub_fc38822a\n" // GetPropertyCase
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc117020\n"
"    movs    r0, #0\n"
"    movw    r2, #0x159\n"
"    ldr     r1, =0xfc1171c8\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc314dec\n" // j_DebugAssert
"loc_fc117020:\n"
"    ldr.w   r0, [r7, #0x18c]\n"
"    cbz     r0, loc_fc11702a\n"
"    bl      sub_fc18b7e2\n"
"loc_fc11702a:\n"
"    movs    r0, #0\n"
"    bl      sub_fc0bd154\n"
"    bl      sub_fc110676\n"
"    ldr.w   r8, =0xfc116f7d\n"
"    mov     r4, r0\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc11713c\n"

#ifdef CAPTSEQ_DEBUG
"bl log_remote_hook2\n"
#endif
"    BL      wait_until_remote_button_is_released\n" // + remote hook
"    BL      capt_seq_hook_set_nr\n" // +

"    mov     r0, r5\n"
"    bl      sub_fc18ba76\n" // NR evaluation and more
"    mov     r0, r5\n"
"    bl      sub_fc110580\n"
"    ldr     r1, =0x0002f888\n"
"    movs    r2, #4\n"
"    movs    r0, #0x92\n"
"    bl      sub_fc38822a\n" // GetPropertyCase
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc117064\n"
"    movs    r0, #0\n"
"    movw    r2, #0x16e\n"
"    ldr     r1, =0xfc1171c8\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc314dec\n" // j_DebugAssert
"loc_fc117064:\n"
"    bl      sub_fc0bd288\n"
"    bl      sub_fc18bb08\n"
"    movs    r1, #0\n"
"    mov     r0, r5\n"
"    bl      sub_fc116f7e\n"
"    mov     r6, r0\n"
"    ldr     r0, [sp, #8]\n"
"    ubfx    r0, r0, #8, #8\n"
"    cmp     r0, #6\n"
"    bne     loc_fc117084\n"
"    ldr     r2, =0xfc18b7ad\n"
"    b       loc_fc117086\n"
"loc_fc117084:\n"
"    ldr     r2, =0xfc18b7c3\n"
"loc_fc117086:\n"
"    ldrh    r0, [r5, #0x18]\n"
"    ldr     r4, =0x0002f888\n"
"    cbz     r0, loc_fc117094\n"
"    cmp     r0, #1\n"
"    beq     loc_fc1170aa\n"
"    cmp     r0, #4\n"
"    bne     loc_fc1170fa\n"
"loc_fc117094:\n"
"    str     r6, [sp]\n"
"    mov     r3, r2\n"
"    ldr     r1, [r5, #0x38]\n"
"    mov     r0, r5\n"
"    ldr     r2, [r4]\n"
"    bl      sub_fc18b4b2\n"
"    mov     r4, r0\n"
"    bl      sub_fc2cd132\n"
"    b       loc_fc117108\n"
"loc_fc1170aa:\n"
"    str     r6, [sp]\n"
"    mov     r3, r2\n"
"    ldr     r1, [r5, #0x38]\n"
"    mov     sb, r4\n"
"    ldr     r2, [r4]\n"
"    mov     r0, r5\n"
"    bl      sub_fc18b51c\n"
"    movs    r2, #1\n"
"    mov     r4, r0\n"
"    movs    r1, #0\n"
"    movs    r0, #0x45\n"
"    bl      sub_fc2a6bb8\n"
"    lsls    r0, r4, #0x1f\n"
"    bne     loc_fc117108\n"
"    ldr     r0, =0xfc116f7d\n"
"    movs    r1, #0\n"
"    bl      sub_fc144f10\n"
"    movs    r1, #1\n"
"    mov     r0, r5\n"
"    bl      sub_fc116f7e\n"
"    mov     r6, r0\n"
"    ldr.w   r0, [sb]\n"
"    mov     r4, sb\n"
"    bl      sub_fc18b8b0\n"
"    ldr     r1, [r5, #0x38]\n"
"    mov     r3, r6\n"
"    ldr     r2, [r4]\n"
"    mov     r0, r5\n"
"    bl      sub_fc18b594\n"
"    mov     r4, r0\n"
"    bl      sub_fc18b45a\n"
"    b       loc_fc117108\n"
"loc_fc1170fa:\n"
"    movs    r0, #0\n"
"    movw    r2, #0x1a7\n"
"    ldr     r1, =0xfc1171c8\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc314dec\n" // j_DebugAssert
"    movs    r4, #0x1d\n"
"loc_fc117108:\n"
"    bl      sub_fc18bb0c\n"
"    lsls    r0, r4, #0x1f\n"
"    bne     loc_fc117172\n"
"    mov     r0, r5\n"
"    bl      sub_fc18bb22\n"
"    ldr.w   r0, [r7, #0x108]\n"
"    cbnz    r0, loc_fc11713a\n"
"    mov     r0, r5\n"
"    bl      sub_fc1105c2\n"
"    cbnz    r0, loc_fc11713a\n"
"    mov     r0, r5\n"
"    bl      sub_fc18c262\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc11713a\n"
"    movs    r0, #0\n"
"    movw    r2, #0x1c8\n"
"    ldr     r1, =0xfc1171c8\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc314dec\n" // j_DebugAssert
"loc_fc11713a:\n"
"    b       loc_fc11713e\n"
"loc_fc11713c:\n"
"    b       loc_fc117172\n"
"loc_fc11713e:\n"
#ifdef CAPTSEQ_DEBUG
"bl log_rh\n"
#endif
"    bl      capt_seq_hook_raw_here\n" //----------------------------------- ???? ----------
"    mov     r0, r5\n"
"    bl      sub_fc18baf8\n"
"    mov     r0, r5\n"
"    bl      sub_fc18bacc\n"
"    cmp     r6, r8\n"
"    beq     loc_fc117172\n"
"    bl      sub_fc18bc92\n"
"    movs    r1, #4\n"
"    movw    sb, #0x1d5\n"
"    ldr     r3, =0xfc1171c8\n" //  *"SsStandardCaptureSeq.c"
"    movw    r2, #0x3a98\n"
"    str.w   sb, [sp]\n"
"    bl      sub_fc33e280\n"
"    cbz     r0, loc_fc117172\n"
"    movs    r0, #0\n"
"    mov     r2, sb\n"
"    ldr     r1, =0xfc1171c8\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc314dec\n" // j_DebugAssert
"loc_fc117172:\n"
"    ldr.w   r0, [r7, #0x18c]\n"
"    cbz     r0, loc_fc117182\n"
"    movs    r2, #1\n"
"    movs    r1, #0\n"
"    movs    r0, #0x46\n"
"    bl      sub_fc2a6bb8\n"
"loc_fc117182:\n"
"    movs    r1, #2\n"
"    mov     r2, r5\n"
"    mov     r0, r4\n"
"    bl      sub_fc1026fa\n"
"    ldr     r0, [r7, #0x28]\n"
"    cmp     r0, #0\n"
"    mov     r0, r8\n"
"    beq     loc_fc1171a8\n"
"    cmp     r6, r0\n"
"    beq     loc_fc11719c\n"
"    movs    r1, #1\n"
"    b       loc_fc11719e\n"
"loc_fc11719c:\n"
"    movs    r1, #0\n"
"loc_fc11719e:\n"
"    mov     r2, r4\n"
"    mov     r0, r5\n"
"    bl      sub_fc18bfae\n"
"    b       loc_fc1171ba\n"
"loc_fc1171a8:\n"
"    cmp     r6, r0\n"
"    beq     loc_fc1171b0\n"
"    movs    r1, #1\n"
"    b       loc_fc1171b2\n"
"loc_fc1171b0:\n"
"    movs    r1, #0\n"
"loc_fc1171b2:\n"
"    mov     r2, r4\n"
"    mov     r0, r5\n"
"    bl      sub_fc18bf68\n"
"loc_fc1171ba:\n"
"    mov     r0, r4\n"
"    pop.w   {r1, r2, r3, r4, r5, r6, r7, r8, sb, pc}\n"
".ltorg\n"
    );
}



