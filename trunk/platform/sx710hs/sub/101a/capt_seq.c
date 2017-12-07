#include "lolevel.h"
#include "platform.h"
#include "core.h"

// debug
#define CAPTSEQ_DEBUG_LOG 1
extern void _LogCameraEvent(int id,const char *fmt,...);

#define USE_STUBS_NRFLAG 1
#define NR_AUTO (-1) // default value if NRTBL.SetDarkSubType not used is -1 (0 probalby works the same), set to enable auto

#ifdef CAPTSEQ_DEBUG_LOG
//extern int active_raw_buffer;

extern char *hook_raw_image_addr(void);

void log_capt_seq(int m)
{
    _LogCameraEvent(0x60,"cs m:%d rb:0x%08x i:%04d",
                    m,
                    hook_raw_image_addr(),
                    get_exposure_counter());
}
void log_capt_seq2(int m)
{
    _LogCameraEvent(0x60,"cs end m:%d rb:0x%08x i:%04d",
                    m,
                    hook_raw_image_addr(),
                    get_exposure_counter());
}
void log_capt_seq_override(void)
{
    _LogCameraEvent(0x60,"cs override rb:0x%08x i:%04d",
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
    current_raw_addr=*(ptr + 0x5c/4); // @0xfc082212, ptr+0x5c
#ifdef CAPTSEQ_DEBUG_LOG
    _LogCameraEvent(0x60,"rawinit i:0x%x p:0x%x v:0x%x",raw_index,ptr,current_raw_addr);
#endif
}

void clear_current_raw_addr(void) {
    current_raw_addr=NULL;
}

// -f=chdk -s=task_CaptSeq -c=172
// task_CaptSeq 0xfc0646b3
void __attribute__((naked,noinline)) capt_seq_task() {
    asm volatile (
"    push    {r3, r4, r5, r6, r7, lr}\n"
"    ldr     r4, =0x00039e5c\n"
"    movs    r6, #0\n"
"    ldr     r5, =0x0000ba40\n"
"loc_fc0646ba:\n"
"    movs    r2, #0\n"
"    mov     r1, sp\n"
"    ldr     r0, [r5, #8]\n"
"    blx     sub_fc2c7ca8\n" // j_ReceiveMessageQueue
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc0646dc\n"
"    movw    r2, #0x44e\n"
"    ldr     r1, =0xfc064364\n" //  *"SsShootTask.c"
"    movs    r0, #0\n"
"    blx     sub_fc2c7de8\n" // j_DebugAssert
"    blx     sub_fc2c7d00\n" // -> ExitTask
"    pop     {r3, r4, r5, r6, r7, pc}\n"
"loc_fc0646dc:\n"
"    ldr     r0, [sp]\n"
"    ldr     r0, [r0]\n"
"    cmp     r0, #1\n"
"    beq     loc_fc0646f4\n"
"    cmp     r0, #0x29\n"
"    beq     loc_fc0646f4\n"
"    cmp     r0, #0x1e\n"
"    beq     loc_fc0646f4\n"
"    cmp     r0, #0x21\n"
"    beq     loc_fc0646f4\n"
"    bl      sub_fc080fbc\n"
"loc_fc0646f4:\n"
#ifdef CAPTSEQ_DEBUG_LOG
// debug message
"ldr     r0, [sp]\n"
"ldr     r0, [r0]\n"
"bl log_capt_seq\n"
#endif
"    ldr     r0, [sp]\n"
"    ldr     r1, [r0]\n"
"    cmp     r1, #0x2b\n"
"    bhs     loc_fc0647b6\n"
"    tbb     [pc, r1]\n" // (jumptable r1 43 elements)
"branchtable_fc064700:\n"
"    .byte((loc_fc06472c - branchtable_fc064700) / 2)\n" // (case 0)
"    .byte((loc_fc064742 - branchtable_fc064700) / 2)\n" // (case 1)
"    .byte((loc_fc06474a - branchtable_fc064700) / 2)\n" // (case 2)
"    .byte((loc_fc064758 - branchtable_fc064700) / 2)\n" // (case 3)
"    .byte((loc_fc064752 - branchtable_fc064700) / 2)\n" // (case 4)
"    .byte((loc_fc064762 - branchtable_fc064700) / 2)\n" // (case 5)
"    .byte((loc_fc064768 - branchtable_fc064700) / 2)\n" // (case 6)
"    .byte((loc_fc06476e - branchtable_fc064700) / 2)\n" // (case 7)
"    .byte((loc_fc064776 - branchtable_fc064700) / 2)\n" // (case 8)
"    .byte((loc_fc0647a8 - branchtable_fc064700) / 2)\n" // (case 9)
"    .byte((loc_fc064780 - branchtable_fc064700) / 2)\n" // (case 10)
"    .byte((loc_fc064788 - branchtable_fc064700) / 2)\n" // (case 11)
"    .byte((loc_fc06478e - branchtable_fc064700) / 2)\n" // (case 12)
"    .byte((loc_fc064796 - branchtable_fc064700) / 2)\n" // (case 13)
"    .byte((loc_fc06479c - branchtable_fc064700) / 2)\n" // (case 14)
"    .byte((loc_fc0647a2 - branchtable_fc064700) / 2)\n" // (case 15)
"    .byte((loc_fc0647b0 - branchtable_fc064700) / 2)\n" // (case 16)
"    .byte((loc_fc0647c4 - branchtable_fc064700) / 2)\n" // (case 17)
"    .byte((loc_fc0647ca - branchtable_fc064700) / 2)\n" // (case 18)
"    .byte((loc_fc0647d0 - branchtable_fc064700) / 2)\n" // (case 19)
"    .byte((loc_fc0647d6 - branchtable_fc064700) / 2)\n" // (case 20)
"    .byte((loc_fc0647dc - branchtable_fc064700) / 2)\n" // (case 21)
"    .byte((loc_fc0647e0 - branchtable_fc064700) / 2)\n" // (case 22)
"    .byte((loc_fc0647e6 - branchtable_fc064700) / 2)\n" // (case 23)
"    .byte((loc_fc0647ec - branchtable_fc064700) / 2)\n" // (case 24)
"    .byte((loc_fc0647f2 - branchtable_fc064700) / 2)\n" // (case 25)
"    .byte((loc_fc0647f8 - branchtable_fc064700) / 2)\n" // (case 26)
"    .byte((loc_fc0647fe - branchtable_fc064700) / 2)\n" // (case 27)
"    .byte((loc_fc064806 - branchtable_fc064700) / 2)\n" // (case 28)
"    .byte((loc_fc06480c - branchtable_fc064700) / 2)\n" // (case 29)
"    .byte((loc_fc064810 - branchtable_fc064700) / 2)\n" // (case 30)
"    .byte((loc_fc064818 - branchtable_fc064700) / 2)\n" // (case 31)
"    .byte((loc_fc06481e - branchtable_fc064700) / 2)\n" // (case 32)
"    .byte((loc_fc064824 - branchtable_fc064700) / 2)\n" // (case 33)
"    .byte((loc_fc06482a - branchtable_fc064700) / 2)\n" // (case 34)
"    .byte((loc_fc064830 - branchtable_fc064700) / 2)\n" // (case 35)
"    .byte((loc_fc064836 - branchtable_fc064700) / 2)\n" // (case 36)
"    .byte((loc_fc06483c - branchtable_fc064700) / 2)\n" // (case 37)
"    .byte((loc_fc064844 - branchtable_fc064700) / 2)\n" // (case 38)
"    .byte((loc_fc06484a - branchtable_fc064700) / 2)\n" // (case 39)
"    .byte((loc_fc06486e - branchtable_fc064700) / 2)\n" // (case 40)
"    .byte((loc_fc064874 - branchtable_fc064700) / 2)\n" // (case 41)
"    .byte((loc_fc06488e - branchtable_fc064700) / 2)\n" // (case 42)
".align 1\n"
"loc_fc06472c:\n"  // case 0: preshoot, quick press shoot
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc073cbc\n"
#ifdef CAPTSEQ_DEBUG_LOG
"bl log_capt_seq_override\n"
#endif
"    BL      clear_current_raw_addr\n" // +
"    BL      shooting_expo_param_override\n" // +
"    bl      sub_fc079112\n"
"    ldr     r0, [r4, #0x28]\n"
"    cmp     r0, #0\n"
"    beq     loc_fc064740\n"
"    bl      sub_fc07b6ba_my\n" // quick press
"loc_fc064740:\n"
"    b       loc_fc06488e\n"
"loc_fc064742:\n" // case 1: normal shoot
"    ldr     r0, [r0, #0x10]\n"
"    bl      sub_fc07b4ee_my\n" // regular shoot
"    b       loc_fc06488e\n"
"loc_fc06474a:\n"
"    movs    r0, #1\n"
"    bl      sub_fc073f74\n"
"    b       loc_fc06488e\n"
"loc_fc064752:\n"
"    bl      sub_fc073a32\n"
"    b       loc_fc06475e\n"
"loc_fc064758:\n"
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc073ca4\n"
"loc_fc06475e:\n"
"    str     r6, [r4, #0x28]\n"
"    b       loc_fc06488e\n"
"loc_fc064762:\n"
"    bl      sub_fc073caa\n"
"    b       loc_fc06488e\n"
"loc_fc064768:\n"
"    bl      sub_fc073e9a\n"
"    b       loc_fc06477a\n"
"loc_fc06476e:\n"
"    ldr     r0, [r0, #0x10]\n"
"    bl      sub_fc07b766\n"
"    b       loc_fc06488e\n"
"loc_fc064776:\n"
"    bl      sub_fc073efc\n"
"loc_fc06477a:\n"
"    bl      sub_fc079112\n"
"    b       loc_fc06488e\n"
"loc_fc064780:\n"
"    ldr     r0, [r4, #0x54]\n"
"    bl      sub_fc06f596\n"
"    b       loc_fc06488e\n"
"loc_fc064788:\n"
"    bl      sub_fc06f806\n"
"    b       loc_fc06488e\n"
"loc_fc06478e:\n"
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc06f852\n"
"    b       loc_fc06488e\n"
"loc_fc064796:\n"
"    bl      sub_fc06f986\n"
"    b       loc_fc06488e\n"
"loc_fc06479c:\n"
"    bl      sub_fc06fd52\n"
"    b       loc_fc06488e\n"
"loc_fc0647a2:\n"
"    bl      sub_fc06fde8\n"
"    b       loc_fc06488e\n"
"loc_fc0647a8:\n"
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc073ca4\n"
"    b       loc_fc06488e\n"
"loc_fc0647b0:\n"
"    bl      sub_fc071190\n"
"    b       loc_fc06488e\n"
"loc_fc0647b6:\n"
"    b       loc_fc064880\n"
".ltorg\n" 
// firmware had literal pool here
// 0x0003a05c
// 0x00039e5c
// 0x0000ba40
"loc_fc0647c4:\n"
"    bl      sub_fc071338\n"
"    b       loc_fc06488e\n"
"loc_fc0647ca:\n"
"    bl      sub_fc0713b0\n"
"    b       loc_fc06488e\n"
"loc_fc0647d0:\n"
"    bl      sub_fc07144c\n"
"    b       loc_fc06488e\n"
"loc_fc0647d6:\n"
"    bl      sub_fc0714ee\n"
"    b       loc_fc06488e\n"
"loc_fc0647dc:\n"
"    movs    r0, #0\n"
"    b       loc_fc064800\n"
"loc_fc0647e0:\n"
"    bl      sub_fc071808\n"
"    b       loc_fc06488e\n"
"loc_fc0647e6:\n"
"    bl      sub_fc071868\n"
"    b       loc_fc06488e\n"
"loc_fc0647ec:\n"
"    bl      sub_fc07186c\n"
"    b       loc_fc06488e\n"
"loc_fc0647f2:\n"
"    bl      sub_fc07187c\n"
"    b       loc_fc06488e\n"
"loc_fc0647f8:\n"
"    bl      sub_fc0718f4\n"
"    b       loc_fc06488e\n"
"loc_fc0647fe:\n"
"    movs    r0, #1\n"
"loc_fc064800:\n"
"    bl      sub_fc0716e8\n"
"    b       loc_fc06488e\n"
"loc_fc064806:\n"
"    bl      sub_fc074056\n"
"    b       loc_fc06488e\n"
"loc_fc06480c:\n"
"    movs    r0, #0\n"
"    b       loc_fc064812\n"
"loc_fc064810:\n"
"    ldr     r0, [r0, #0xc]\n"
"loc_fc064812:\n"
"    bl      sub_fc0740b6\n"
"    b       loc_fc06488e\n"
"loc_fc064818:\n"
"    bl      sub_fc071614\n"
"    b       loc_fc06488e\n"
"loc_fc06481e:\n"
"    bl      sub_fc07167a\n"
"    b       loc_fc06488e\n"
"loc_fc064824:\n"
"    bl      sub_fc07bf10\n"
"    b       loc_fc06488e\n"
"loc_fc06482a:\n"
"    bl      sub_fc079a30\n"
"    b       loc_fc06488e\n"
"loc_fc064830:\n"
"    bl      sub_fc29d326\n"
"    b       loc_fc06488e\n"
"loc_fc064836:\n"
"    bl      sub_fc29d3e0\n"
"    b       loc_fc06488e\n"
"loc_fc06483c:\n"
"    ldr     r0, [r0, #0xc]\n"
"    bl      sub_fc0719d0\n"
"    b       loc_fc06488e\n"
"loc_fc064844:\n"
"    bl      sub_fc071a38\n"
"    b       loc_fc06488e\n"
"loc_fc06484a:\n"
"    bl      sub_fc0748be\n"
"    ldrh.w  r0, [r4, #0x1a4]\n"
"    cmp     r0, #4\n"
"    beq     loc_fc064860\n"
"    ldrh    r0, [r4]\n"
"    sub.w   r1, r0, #0x4200\n"
"    subs    r1, #0x36\n"
"    bne     loc_fc06488e\n"
"loc_fc064860:\n"
"    bl      sub_fc29d3e0\n"
"    bl      sub_fc29d8f6\n"
"    bl      sub_fc29d73e\n"
"    b       loc_fc06488e\n"
"loc_fc06486e:\n"
"    movs    r2, #0\n"
"    movs    r1, #0x11\n"
"    b       loc_fc064878\n"
"loc_fc064874:\n"
"    movs    r2, #0\n"
"    movs    r1, #0x10\n"
"loc_fc064878:\n"
"    movs    r0, #0\n"
"    bl      sub_fc079cf0\n"
"    b       loc_fc06488e\n"
"loc_fc064880:\n"
"    movw    r2, #0x57e\n"
"    ldr     r1, =0xfc064364\n" //  *"SsShootTask.c"
"    movs    r0, #0\n"
"    blx     sub_fc2c7de8\n" // j_DebugAssert
"loc_fc06488e:\n"
// debug after message handled
#ifdef CAPTSEQ_DEBUG_LOG
"ldr     r0, [sp]\n"
"ldr     r0, [r0]\n"
"bl log_capt_seq2\n"
#endif
"    ldr     r0, [sp]\n"
"    ldr     r1, [r0, #4]\n"
"    ldr     r0, [r5, #4]\n"
"    blx     sub_fc2c7cd0\n" // j_SetEventFlag
"    ldr     r7, [sp]\n"
"    ldr     r0, [r7, #8]\n"
"    cbnz    r0, loc_fc0648ac\n"
"    movw    r2, #0x12b\n"
"    ldr     r1, =0xfc064364\n" //  *"SsShootTask.c"
"    movs    r0, #0\n"
"    blx     sub_fc2c7de8\n" // j_DebugAssert
"loc_fc0648ac:\n"
"    str     r6, [r7, #8]\n"
"    b       loc_fc0646ba\n"
".ltorg\n"
    );
}

//-f=chdk -s=0xfc07b6bb -c=57 
void __attribute__((naked,noinline)) sub_fc07b6ba_my() {
    asm volatile (
"    push    {r3, r4, r5, r6, r7, lr}\n"
"    bl      sub_fc07fa84\n"
"    mov     r4, r0\n"
"    movs    r0, #0xc\n"
"    bl      sub_fc29dbfc\n"
"    ldr     r6, =0x00014684\n"
"    lsls    r0, r0, #0x1f\n"
"    mov.w   r5, #1\n"
"    bne     loc_fc07b758\n"
"    movs    r2, #2\n"
"    mov     r1, sp\n"
"    movw    r0, #0x110\n"
"    bl      _GetPropertyCase\n" //  PROPCASE_TV (272)
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc07b6ee\n"
"    movs    r0, #0\n"
"    movw    r2, #0x17d\n"
"    ldr     r1, =0xfc07b838\n" //  *"SsCaptureCtrl.c"
"    blx     sub_fc2c7de8\n" // j_DebugAssert
"loc_fc07b6ee:\n"
"    ldrsh.w r0, [sp]\n"
"    bl      sub_fc0b2f18\n"
"    bl      sub_fc0b2d2e\n"
"    cmp     r0, #1\n"
"    bls     loc_fc07b75c\n"
"    movs    r0, #0\n"
"    bl      sub_fc0b2de6\n"
"    bl      sub_fc0a8f60\n"
"    bl      sub_fc073cb0\n"
"    bl      sub_fc082184\n"
"    mov     r1, r4\n"
//"    bl      sub_fc0821d2\n"
"bl captseq_raw_addr_init_my\n"
"    movs    r2, #4\n"
"    movw    r0, #0x116\n"
"    add.w   r1, r4, #0x58\n"
"    bl      _SetPropertyCase\n" //  (278)
"    movs    r2, #4\n"
"    movs    r0, #0x30\n"
"    add.w   r1, r4, #0x5c\n"
"    bl      _SetPropertyCase\n" //  (48)
"    movs    r2, #4\n"
"    movs    r0, #0x44\n"
"    add.w   r1, r4, #8\n"
"    bl      _SetPropertyCase\n" //  (68)
"    bl      sub_fc080b66\n"
"    mvn     r1, #0x1000\n"
"    blx     sub_fc2c7dd0\n" // j_ClearEventFlag
"    mov     r0, r4\n"
"    bl      sub_fc07b29a\n"
"    mov     r0, r4\n"
"    bl      sub_fc083ab0_my\n" // -> remote hook, raw hook
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc07b75a\n"
"loc_fc07b758:\n"
"    str     r5, [r6]\n"
"loc_fc07b75a:\n"
"    pop     {r3, r4, r5, r6, r7, pc}\n"
"loc_fc07b75c:\n"
"    bl      sub_fc079a26\n"
"    bl      sub_fc29dc34\n"
"    pop     {r3, r4, r5, r6, r7, pc}\n"
".ltorg\n"
    );
}

// -f=chdk -s=0xfc07b4ef -c=173
void __attribute__((naked,noinline)) sub_fc07b4ee_my() {
    asm volatile (
"    push    {r2, r3, r4, r5, r6, lr}\n"
"    ldr     r6, =0x00039e5c\n"
"    mov     r4, r0\n"
"    movs    r5, #0\n"
"    ldr     r0, [r6, #0x28]\n"
"    cbz     r0, loc_fc07b516\n"
"    ldr     r0, =0x00014684\n"
"    ldr     r0, [r0]\n"
"    cbz     r0, loc_fc07b502\n"
"    movs    r5, #0x1d\n"
"loc_fc07b502:\n"
"    mov     r2, r4\n"
"    movs    r1, #2\n"
"    mov     r0, r5\n"
"    bl      sub_fc079cf0\n"
"    mov     r1, r5\n"
"    mov     r0, r4\n"
"    bl      sub_fc080e1a\n"
"    b       loc_fc07b6b4\n"
"loc_fc07b516:\n"
"    bl      sub_fc082184\n"
"    mov     r1, r4\n"
//"    bl      sub_fc0821d2\n"
"bl captseq_raw_addr_init_my\n"
"    movs    r2, #4\n"
"    movw    r0, #0x116\n"
"    add.w   r1, r4, #0x58\n"
"    bl      _SetPropertyCase\n" //  (278)
"    movs    r2, #4\n"
"    movs    r0, #0x30\n"
"    add.w   r1, r4, #0x5c\n"
"    bl      _SetPropertyCase\n" //  (48)
"    ldr.w   r0, [r6, #0x10c]\n"
"    cbnz    r0, loc_fc07b550\n"
"    ldrh.w  r0, [r6, #0x1a2]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc07b556\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc07b566\n"
"    b       loc_fc07b556\n"
"loc_fc07b550:\n"
"    ldr     r0, [r4, #0xc]\n"
"    cmp     r0, #1\n"
"    bne     loc_fc07b566\n"
"loc_fc07b556:\n"
"    movs    r0, #0xc\n"
"    bl      sub_fc29dbfc\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc07b566\n"
"    bl      sub_fc079a26\n"
"    movs    r5, #1\n"
"loc_fc07b566:\n"
"    lsls    r0, r5, #0x1f\n"
"    bne     loc_fc07b668\n"
"    ldr.w   r0, [r6, #0xec]\n"
"    cbz     r0, loc_fc07b58a\n"
"    ldrh.w  r0, [r6, #0x1a2]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc07b57e\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc07b5ca\n"
"loc_fc07b57e:\n"
"    ldr.w   r0, [r6, #0x10c]\n"
"    cbz     r0, loc_fc07b58a\n"
"    ldr     r0, [r4, #0xc]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc07b5ca\n"
"loc_fc07b58a:\n"
"    movs    r2, #2\n"
"    movw    r0, #0x110\n"
"    add     r1, sp, #4\n"
"    bl      _GetPropertyCase\n" //  PROPCASE_TV (272)
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc07b5a4\n"
"    movs    r2, #0xcd\n"
"    movs    r0, #0\n"
"    ldr     r1, =0xfc07b838\n" //  *"SsCaptureCtrl.c"
"    blx     sub_fc2c7de8\n" // j_DebugAssert
"loc_fc07b5a4:\n"
"    ldrsh.w r0, [sp, #4]\n"
"    bl      sub_fc0b2f18\n"
"    bl      sub_fc0b2d2e\n"
"    cmp     r0, #1\n"
"    bls     loc_fc07b5bc\n"
"    movs    r0, #0\n"
"    bl      sub_fc0b2de6\n"
"    b       loc_fc07b5ca\n"
"loc_fc07b5bc:\n"
"    bl      sub_fc079a26\n"
"    bl      sub_fc29dc34\n"
"    movs    r5, #1\n"
"    lsls    r0, r5, #0x1f\n"
"    bne     loc_fc07b6a2\n"
"loc_fc07b5ca:\n"
"    mov     r0, r4\n"
"    bl      sub_fc07bf5a\n"
"    mov     r5, r0\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc07b6a2\n"
"    bl      sub_fc080b66\n"
"    mvn     r1, #0x1000\n"
"    blx     sub_fc2c7dd0\n" // j_ClearEventFlag
"    mov     r0, r4\n"
"    bl      sub_fc07d3c6\n"
"    mov     r5, r0\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc07b6a2\n"
"    bl      sub_fc0a8f60\n"
"    bl      sub_fc073cb0\n"
"    mov     r0, r4\n"
"    bl      sub_fc07b29a\n"
"    ldr.w   r0, [r6, #0x130]\n"
"    cbnz    r0, loc_fc07b610\n"
"    ldrh.w  r0, [r6, #0x1a2]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc07b610\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc07b616\n"
"loc_fc07b610:\n"
"    movs    r0, #2\n"
"    bl      sub_fc074942\n"
"loc_fc07b616:\n"
"    ldr.w   r0, [r6, #0xa8]\n"
"    cmp     r0, #0\n"
"    beq     loc_fc07b68c\n"
"    ldrh.w  r0, [r6, #0x1a2]\n"
"    movw    r5, #0x1000\n"
"    cmp     r0, #3\n"
"    beq     loc_fc07b646\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bls     loc_fc07b646\n"
"    bl      sub_fc080b66\n"
"    movw    r3, #0x119\n"
"    movw    r2, #0x3a98\n"
"    mov     r1, r5\n"
"    str     r3, [sp]\n"
"    ldr     r3, =0xfc07b838\n" //  *"SsCaptureCtrl.c"
"    bl      sub_fc29ddac\n"
"loc_fc07b646:\n"
"    movs    r2, #4\n"
"    movw    r0, #0x188\n"
"    add     r1, sp, #4\n"
"    bl      _GetPropertyCase\n" //  (392)
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc07b662\n"
"    movs    r0, #0\n"
"    movw    r2, #0x11d\n"
"    ldr     r1, =0xfc07b838\n" //  *"SsCaptureCtrl.c"
"    blx     sub_fc2c7de8\n" // j_DebugAssert
"loc_fc07b662:\n"
"    ldr     r0, [sp, #4]\n"
"    cbnz    r0, loc_fc07b676\n"
"    b       loc_fc07b66a\n"
"loc_fc07b668:\n"
"    b       loc_fc07b6a2\n"
"loc_fc07b66a:\n"
"    bl      sub_fc080b66\n"
"    mov     r1, r5\n"
"    blx     sub_fc2c7cd0\n" // j_SetEventFlag
"    b       loc_fc07b68c\n"
"loc_fc07b676:\n"
"    bl      sub_fc080b66\n"
"    mov     r1, r5\n"
"    blx     sub_fc2c7dd0\n" // j_ClearEventFlag
"    ldr     r2, =0xfc07b4dd\n"
"    mov     r3, r5\n"
"    ldr     r0, [sp, #4]\n"
"    mov     r1, r2\n"
"    bl      sub_fc326f00\n"
"loc_fc07b68c:\n"
"    ldr.w   r0, [r6, #0xb4]\n"
"    cmp     r0, #0\n"
"    mov     r0, r4\n"
"    beq     loc_fc07b69c\n"
"    bl      sub_fc083f42\n"
"    b       loc_fc07b6b4\n"
"loc_fc07b69c:\n"
"    bl      sub_fc083ab0_my\n" // -> remote, raw hook etc
"    b       loc_fc07b6b4\n"
"loc_fc07b6a2:\n"
"    movs    r1, #2\n"
"    mov     r2, r4\n"
"    mov     r0, r5\n"
"    bl      sub_fc079cf0\n"
"    mov     r1, r5\n"
"    mov     r0, r4\n"
"    bl      sub_fc080f50\n"
"loc_fc07b6b4:\n"
"    movs    r0, #0\n"
"    str     r0, [r6, #0x28]\n"
"    pop     {r2, r3, r4, r5, r6, pc}\n"
".ltorg\n"
    );
}

#ifdef CAPTSEQ_DEBUG_LOG
void log_nr_call(void) {
    _LogCameraEvent(0x60,"nr hook %d",_nrflag);
}
void log_remote_hook(void) {
    _LogCameraEvent(0x60,"remote hook");
}
void log_rh(void) {
    _LogCameraEvent(0x60,"raw hook rb:0x%08x rbc:0x%08x",hook_raw_image_addr(),current_raw_addr);
}
#endif

// -f=chdk -s=0xfc083ab1 -c=210
void __attribute__((naked,noinline)) sub_fc083ab0_my() {
    asm volatile (
"    push.w  {r1, r2, r3, r4, r5, r6, r7, r8, sb, lr}\n"
"    ldr     r7, =0x00039e5c\n"
"    mov     r4, r0\n"
"    ldr.w   r0, [r7, #0x16c]\n"
"    cbz     r0, loc_fc083acc\n"
"    ldrh.w  r0, [r7, #0x1a2]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc083acc\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc083ad6\n"
"loc_fc083acc:\n"
"    mov     r0, r4\n"
"    bl      sub_fc07b230\n"
"    bl      sub_fc07bc88\n"
"loc_fc083ad6:\n"
"    ldr.w   r0, [r7, #0xa4]\n"
"    cbnz    r0, loc_fc083af2\n"
"    ldrh.w  r0, [r7, #0x1a2]\n"
"    cmp     r0, #3\n"
"    beq     loc_fc083aea\n"
"    ldr     r0, [r4, #8]\n"
"    cmp     r0, #1\n"
"    bhi     loc_fc083af2\n"
"loc_fc083aea:\n"
"    bl      sub_fc0740a6\n"
"    bl      sub_fc07b86a\n"
"loc_fc083af2:\n"
"    movs    r2, #4\n"
"    movw    r0, #0x137\n"
"    add     r1, sp, #8\n"
"    bl      _GetPropertyCase\n" //  (311)
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc083b0e\n"
"    movs    r0, #0\n"
"    movw    r2, #0x150\n"
"    ldr     r1, =0xfc083e94\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc2c7de8\n" // j_DebugAssert
"loc_fc083b0e:\n"
"    ldr     r0, [sp, #8]\n"
"    ubfx    r0, r0, #8, #8\n"
"    cmp     r0, #6\n"
"    bne     loc_fc083b1e\n"
"    ldr     r0, =0xfc083a79\n"
"    movs    r1, #0\n"
"    b       loc_fc083b22\n"
"loc_fc083b1e:\n"
"    ldr     r0, =0xfc07ae63\n"
"    mov     r1, r4\n"
"loc_fc083b22:\n"
"    bl      sub_fc0b8fc8\n"
"    movs    r2, #2\n"
"    movw    r0, #0x112\n"
"    add     r1, sp, #4\n"
"    bl      _GetPropertyCase\n" //  PROPCASE_USER_TV (274)
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc083b42\n"
"    movs    r0, #0\n"
"    movw    r2, #0x159\n"
"    ldr     r1, =0xfc083e94\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc2c7de8\n" // j_DebugAssert
"loc_fc083b42:\n"
"    ldr.w   r0, [r7, #0x18c]\n"
"    cbz     r0, loc_fc083b4c\n"
"    bl      sub_fc07b168\n"
"loc_fc083b4c:\n"
"    movs    r0, #0\n"
"    bl      sub_fc0743b6\n"
"bl capt_seq_hook_set_nr\n"
#ifdef CAPTSEQ_DEBUG_LOG
"bl log_nr_call\n"
#endif
"    mov     r0, r4\n"
"    bl      sub_fc07b360\n"
"    ldr     r1, =0x000219e4\n"
"    movs    r2, #4\n"
"    movs    r0, #0x90\n"
"    bl      _GetPropertyCase\n" //  (144)
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc083b72\n"
"    movs    r0, #0\n"
"    movw    r2, #0x16e\n"
"    ldr     r1, =0xfc083e94\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc2c7de8\n" // j_DebugAssert
"loc_fc083b72:\n"
"    bl      sub_fc074470\n"
"    bl      sub_fc07b3f2\n"
"    movs    r1, #0\n"
"    mov     r0, r4\n"
"    bl      sub_fc083a7a\n"
"    mov     r6, r0\n"
"    BL      wait_until_remote_button_is_released\n" // + remote hook, might be able to go later
#ifdef CAPTSEQ_DEBUG_LOG
"bl log_remote_hook\n"
#endif
"    ldr     r0, [sp, #8]\n"
"    ubfx    r0, r0, #8, #8\n"
"    cmp     r0, #6\n"
"    bne     loc_fc083b92\n"
"    ldr     r2, =0xfc07b137\n"
"    b       loc_fc083b94\n"
"loc_fc083b92:\n"
"    ldr     r2, =0xfc07b14d\n"
"loc_fc083b94:\n"
"    ldrh    r0, [r4, #0x18]\n"
"    ldr     r5, =0x000219e4\n"
"    cbz     r0, loc_fc083ba2\n"
"    cmp     r0, #1\n"
"    beq     loc_fc083bb8\n"
"    cmp     r0, #4\n"
"    bne     loc_fc083c1e\n"
"loc_fc083ba2:\n"
"    str     r6, [sp]\n"
"    mov     r3, r2\n"
"    ldr     r1, [r4, #0x5c]\n"
"    mov     r0, r4\n"
"    ldr     r2, [r5]\n"
"    bl      sub_fc07ac8e\n"
"    mov     r5, r0\n"
"    bl      sub_fc13400e\n"
"    b       loc_fc083c2c\n"
"loc_fc083bb8:\n"
"    str     r6, [sp]\n"
"    mov     r3, r2\n"
"    ldr     r1, [r4, #0x5c]\n"
"    mov     r8, r5\n"
"    ldr     r2, [r5]\n"
"    mov     r0, r4\n"
"    bl      sub_fc07acf8\n"
"    movs    r2, #1\n"
"    mov     r5, r0\n"
"    movs    r1, #0\n"
"    movs    r0, #0x45\n"
"    bl      sub_fc268cac\n"
"    lsls    r0, r5, #0x1f\n"
"    bne     loc_fc083c2c\n"
"    ldr.w   r0, [r7, #0x100]\n"
"    cbz     r0, loc_fc083bee\n"
"    ldr     r1, [r4, #8]\n"
"    ldr     r2, =0x001d7f7c\n"
"    ldr     r0, [r4, #0x5c]\n"
"    add.w   r1, r2, r1, lsl #2\n"
"    str     r0, [r1, #-0x4]\n"
"    b       loc_fc083c18\n"
"loc_fc083bee:\n"
"    ldr     r0, =0xfc083a79\n"
"    movs    r1, #0\n"
"    bl      sub_fc0b8fc8\n"
"    movs    r1, #1\n"
"    mov     r0, r4\n"
"    bl      sub_fc083a7a\n"
"    mov     r6, r0\n"
"    ldr.w   r0, [r8]\n"
"    mov     r5, r8\n"
"    bl      sub_fc07b1d2\n"
"    ldr     r1, [r4, #0x5c]\n"
"    mov     r3, r6\n"
"    ldr     r2, [r5]\n"
"    mov     r0, r4\n"
"    bl      sub_fc07ad70\n"
"    mov     r5, r0\n"
"loc_fc083c18:\n"
"    bl      sub_fc07ac38\n"
"    b       loc_fc083c2c\n"
"loc_fc083c1e:\n"
"    movs    r0, #0\n"
"    movw    r2, #0x1a7\n"
"    ldr     r1, =0xfc083e94\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc2c7de8\n" // j_DebugAssert
"    movs    r5, #0x1d\n"
"loc_fc083c2c:\n"
"    bl      sub_fc07b3f6\n"
"    ldr.w   r8, =0xfc083a79\n"
"    lsls    r0, r5, #0x1f\n"
"    bne     loc_fc083c88\n"
"    ldr.w   r0, [r7, #0x108]\n"
"    cbnz    r0, loc_fc083c54\n"
"    mov     r0, r4\n"
"    bl      sub_fc08107a\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc083c54\n"
"    movs    r0, #0\n"
"    movw    r2, #0x1cd\n"
"    ldr     r1, =0xfc083e94\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc2c7de8\n" // j_DebugAssert
"loc_fc083c54:\n"
#ifdef CAPTSEQ_DEBUG_LOG
"bl log_rh\n"
#endif
"    BL      capt_seq_hook_raw_here\n"
"    BL      clear_current_raw_addr\n"
"    mov     r0, r4\n"
"    bl      sub_fc07b3e2\n"
"    mov     r0, r4\n"
"    bl      sub_fc07b3b6\n"
"    cmp     r6, r8\n"
"    beq     loc_fc083c88\n"
"    bl      sub_fc080b66\n"
"    movs    r1, #4\n"
"    movw    sb, #0x1da\n"
"    ldr     r3, =0xfc083e94\n" //  *"SsStandardCaptureSeq.c"
"    movw    r2, #0x3a98\n"
"    str.w   sb, [sp]\n"
"    bl      sub_fc29ddac\n"
"    cbz     r0, loc_fc083c88\n"
"    movs    r0, #0\n"
"    mov     r2, sb\n"
"    ldr     r1, =0xfc083e94\n" //  *"SsStandardCaptureSeq.c"
"    blx     sub_fc2c7de8\n" // j_DebugAssert
"loc_fc083c88:\n"
"    ldr.w   r0, [r7, #0x18c]\n"
"    cbz     r0, loc_fc083c98\n"
"    movs    r2, #1\n"
"    movs    r1, #0\n"
"    movs    r0, #0x46\n"
"    bl      sub_fc268cac\n"
"loc_fc083c98:\n"
"    movs    r1, #2\n"
"    mov     r2, r4\n"
"    mov     r0, r5\n"
"    bl      sub_fc079cf0\n"
"    ldr     r0, [r7, #0x28]\n"
"    cmp     r0, #0\n"
"    mov     r0, r8\n"
"    beq     loc_fc083cbe\n"
"    cmp     r6, r0\n"
"    beq     loc_fc083cb2\n"
"    movs    r1, #1\n"
"    b       loc_fc083cb4\n"
"loc_fc083cb2:\n"
"    movs    r1, #0\n"
"loc_fc083cb4:\n"
"    mov     r2, r5\n"
"    mov     r0, r4\n"
"    bl      sub_fc080dd8\n"
"    b       loc_fc083cd0\n"
"loc_fc083cbe:\n"
"    cmp     r6, r0\n"
"    beq     loc_fc083cc6\n"
"    movs    r1, #1\n"
"    b       loc_fc083cc8\n"
"loc_fc083cc6:\n"
"    movs    r1, #0\n"
"loc_fc083cc8:\n"
"    mov     r2, r5\n"
"    mov     r0, r4\n"
"    bl      sub_fc080d92\n"
"loc_fc083cd0:\n"
"    mov     r0, r5\n"
"    pop.w   {r1, r2, r3, r4, r5, r6, r7, r8, sb, pc}\n"
".ltorg\n"
    );
}
