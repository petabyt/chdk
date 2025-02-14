/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

//#define NR_AUTO (0)                 // have to explictly reset value back to 0 to enable auto
static long *nrflag = (long*)(0xcf68+0xC); // sx510 101a Found @ 0xff2adfe4 (0xcf68) & 0xff2adfe8 (+0xC)
#define PAUSE_FOR_FILE_COUNTER 350  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF072DC4 - 0xFF0730E8, length=202
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R5, =0x2401C \n"
"    LDR     R7, =0x3670 \n"
"    MOV     R6, #0 \n"

"loc_FF072DD4:\n"
"    LDR     R0, [R7, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_006B84B8 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF072E04 \n"
"    LDR     R2, =0x4D4 \n"
"    LDR     R1, =0xFF072578 /*'SsShootTask.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF072E04:\n"
"    LDR     R0, [SP] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #1 \n"
"    BLNE    sub_FF1DB304 \n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x2C \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF0730AC \n"
"    B       loc_FF072ED8 \n"
"    B       loc_FF072EF0 \n"
"    B       loc_FF072EFC \n"
"    B       loc_FF072F10 \n"
"    B       loc_FF072F08 \n"
"    B       loc_FF072F1C \n"
"    B       loc_FF072F24 \n"
"    B       loc_FF072F2C \n"
"    B       loc_FF072F38 \n"
"    B       loc_FF072F7C \n"
"    B       loc_FF072F44 \n"
"    B       loc_FF072F50 \n"
"    B       loc_FF072F58 \n"
"    B       loc_FF072F64 \n"
"    B       loc_FF072F6C \n"
"    B       loc_FF072F74 \n"
"    B       loc_FF072F84 \n"
"    B       loc_FF072F8C \n"
"    B       loc_FF072F94 \n"
"    B       loc_FF072F9C \n"
"    B       loc_FF072FA4 \n"
"    B       loc_FF072FAC \n"
"    B       loc_FF072FB4 \n"
"    B       loc_FF072FBC \n"
"    B       loc_FF072FC4 \n"
"    B       loc_FF072FCC \n"
"    B       loc_FF072FD4 \n"
"    B       loc_FF072FDC \n"
"    B       loc_FF072FE8 \n"
"    B       loc_FF072FF0 \n"
"    B       loc_FF072FF8 \n"
"    B       loc_FF073004 \n"
"    B       loc_FF07300C \n"
"    B       loc_FF073014 \n"
"    B       loc_FF07301C \n"
"    B       loc_FF073024 \n"
"    B       loc_FF07302C \n"
"    B       loc_FF073034 \n"
"    B       loc_FF073040 \n"
"    B       loc_FF073048 \n"
"    B       loc_FF073054 \n"
"    B       loc_FF07308C \n"
"    B       loc_FF073098 \n"
"    B       loc_FF0730BC \n"

"loc_FF072ED8:\n"
//"    BL      shooting_expo_iso_override\n"      // extra ISO override call doesn't appear to be needed on elph130
"    BL      sub_FF0735E4 \n"
"    BL      shooting_expo_param_override\n"    // added
"    BL      sub_FF070364 \n"
// try avoid intermittetant override failues on quick press, not needed?
//"    MOV     R0, #0\n"                          // added
//"    STR     R0, [R5,#0x28]\n"                  // added
"    LDR     R0, [R5, #0x28] \n"
"    CMP     R0, #0 \n"
"    BLNE    sub_FF1D9B68_my \n"  // --> Patched. Old value = 0xFF1D9B68.
"    B       loc_FF0730BC \n"

"loc_FF072EF0:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF1D9A00_my \n"  // --> Patched. Old value = 0xFF1D9A00.
"    B       loc_FF0730BC \n"

"loc_FF072EFC:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF073920 \n"
"    B       loc_FF0730BC \n"

"loc_FF072F08:\n"
"    BL      sub_FF0732B0 \n"
"    B       loc_FF072F14 \n"

"loc_FF072F10:\n"
"    BL      sub_FF0735C0 \n"

"loc_FF072F14:\n"
"    STR     R6, [R5, #0x28] \n"
"    B       loc_FF0730BC \n"

"loc_FF072F1C:\n"
"    BL      sub_FF0735C8 \n"
"    B       loc_FF0730BC \n"

"loc_FF072F24:\n"
"    BL      sub_FF0737EC \n"
"    B       loc_FF072F3C \n"

"loc_FF072F2C:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF1D9BF8 \n"
"    B       loc_FF0730BC \n"

"loc_FF072F38:\n"
"    BL      sub_FF073874 \n"

"loc_FF072F3C:\n"
"    BL      sub_FF070364 \n"
"    B       loc_FF0730BC \n"

"loc_FF072F44:\n"
"    LDR     R0, [R5, #0x58] \n"
"    BL      sub_FF074138 \n"
"    B       loc_FF0730BC \n"

"loc_FF072F50:\n"
"    BL      sub_FF0744B8 \n"
"    B       loc_FF0730BC \n"

"loc_FF072F58:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF074520 \n"
"    B       loc_FF0730BC \n"

"loc_FF072F64:\n"
"    BL      sub_FF074720 \n"
"    B       loc_FF0730BC \n"

"loc_FF072F6C:\n"
"    BL      sub_FF074C14 \n"
"    B       loc_FF0730BC \n"

"loc_FF072F74:\n"
"    BL      sub_FF074CF4 \n"
"    B       loc_FF0730BC \n"

"loc_FF072F7C:\n"
"    BL      sub_FF0735C0 \n"
"    B       loc_FF0730BC \n"

"loc_FF072F84:\n"
"    BL      sub_FF1D8DFC \n"
"    B       loc_FF0730BC \n"

"loc_FF072F8C:\n"
"    BL      sub_FF1D9040 \n"
"    B       loc_FF0730BC \n"

"loc_FF072F94:\n"
"    BL      sub_FF1D90FC \n"
"    B       loc_FF0730BC \n"

"loc_FF072F9C:\n"
"    BL      sub_FF1D919C \n"
"    B       loc_FF0730BC \n"

"loc_FF072FA4:\n"
"    BL      sub_FF1D9274 \n"
"    B       loc_FF0730BC \n"

"loc_FF072FAC:\n"
"    MOV     R0, #0 \n"
"    B       loc_FF072FE0 \n"

"loc_FF072FB4:\n"
"    BL      sub_FF1D9694 \n"
"    B       loc_FF0730BC \n"

"loc_FF072FBC:\n"
"    BL      sub_FF07B6E0 \n"
"    B       loc_FF0730BC \n"

"loc_FF072FC4:\n"
"    BL      sub_FF07B6EC \n"
"    B       loc_FF0730BC \n"

"loc_FF072FCC:\n"
"    BL      sub_FF1D9730 \n"
"    B       loc_FF0730BC \n"

"loc_FF072FD4:\n"
"    BL      sub_FF1D97DC \n"
"    B       loc_FF0730BC \n"

"loc_FF072FDC:\n"
"    MOV     R0, #1 \n"

"loc_FF072FE0:\n"
"    BL      sub_FF1D9530 \n"
"    B       loc_FF0730BC \n"

"loc_FF072FE8:\n"
"    BL      sub_FF073AA4 \n"
"    B       loc_FF0730BC \n"

"loc_FF072FF0:\n"
"    MOV     R0, #0 \n"
"    B       loc_FF072FFC \n"

"loc_FF072FF8:\n"
"    LDR     R0, [R0, #0xC] \n"

"loc_FF072FFC:\n"
"    BL      sub_FF073B30 \n"
"    B       loc_FF0730BC \n"

"loc_FF073004:\n"
"    BL      sub_FF1D9404 \n"
"    B       loc_FF0730BC \n"

"loc_FF07300C:\n"
"    BL      sub_FF1D949C \n"
"    B       loc_FF0730BC \n"

"loc_FF073014:\n"
"    BL      sub_FF1DA9E8 \n"
"    B       loc_FF0730BC \n"

"loc_FF07301C:\n"
//"  BL      _sub_FF070C68 \n"  // --> Nullsub call removed.
"    B       loc_FF0730BC \n"

"loc_FF073024:\n"
"    BL      sub_FF077434 \n"
"    B       loc_FF0730BC \n"

"loc_FF07302C:\n"
"    BL      sub_FF077564 \n"
"    B       loc_FF0730BC \n"

"loc_FF073034:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF1D98EC \n"
"    B       loc_FF0730BC \n"

"loc_FF073040:\n"
"    BL      sub_FF1D9974 \n"
"    B       loc_FF0730BC \n"

"loc_FF073048:\n"
"    BL      sub_FF0776D4 \n"
"    BL      sub_FF0775C0 \n"
"    B       loc_FF0730BC \n"

"loc_FF073054:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF1DA3F4 \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF1DA520 \n"
"    LDR     R0, =0x2411C \n"
"    LDRH    R0, [R0, #0xB0] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R5] \n"
"    SUBNE   R1, R0, #0x8000 \n"
"    SUBNES  R1, R1, #0x230 \n"
"    BNE     loc_FF0730BC \n"
"    BL      sub_FF077564 \n"
"    BL      sub_FF077A98 \n"
"    B       loc_FF0730BC \n"

"loc_FF07308C:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0x10 \n"
"    B       loc_FF0730A0 \n"

"loc_FF073098:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0xF \n"

"loc_FF0730A0:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF070E2C \n"
"    B       loc_FF0730BC \n"

"loc_FF0730AC:\n"
"    LDR     R2, =0x65A \n"
"    LDR     R1, =0xFF072578 /*'SsShootTask.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"

"loc_FF0730BC:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R7] \n"
"    BL      sub_006B82C8 /*_SetEventFlag*/ \n"
"    LDR     R4, [SP] \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R2, =0x126 \n"
"    LDREQ   R1, =0xFF072578 /*'SsShootTask.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    STR     R6, [R4, #8] \n"
"    B       loc_FF072DD4 \n"
);
}

/*************************************************************/
//** sub_FF1D9B68_my @ 0xFF1D9B68 - 0xFF1D9BF4, length=36
void __attribute__((naked,noinline)) sub_FF1D9B68_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF072154 \n"
"    MOV     R4, R0 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF079E78 \n"
"    LDR     R6, =0x969C \n"
"    TST     R0, #1 \n"
"    MOV     R5, #1 \n"
"    BNE     loc_FF1D9BF0 \n"
"    BL      sub_FF0735D0 \n"
"    BL      sub_FF074FD4 \n"
"    MOV     R1, R4 \n"
"    BL      sub_FF075030 \n"
"    LDR     R0, =0x10E \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #0x34 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #8 \n"
"    MOV     R0, #0x3F \n"
"    BL      _SetPropertyCase \n"
"    BL      sub_FF1DA6E0 \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_006B82FC /*_ClearEventFlag*/ \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF3718DC \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF371CF4_my \n"  // --> Patched. Old value = 0xFF371CF4.
"    BL      capt_seq_hook_raw_here \n"         // added
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"

"loc_FF1D9BF0:\n"
"    STR     R5, [R6] \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FF1D9A00_my @ 0xFF1D9A00 - 0xFF1D9B64, length=90
void __attribute__((naked,noinline)) sub_FF1D9A00_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x2401C \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R7, #0x28] \n"
"    MOV     R4, #0 \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF1D9A4C \n"
"    LDR     R0, =0x969C \n"
"    MOV     R2, R5 \n"
"    LDR     R0, [R0] \n"
"    MOV     R1, #1 \n"
"    CMP     R0, #0 \n"
"    MOVNE   R4, #0x1D \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF070E2C \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF1DB08C \n"
"    B       loc_FF1D9B5C \n"

"loc_FF1D9A4C:\n"
"    BL      sub_FF074FD4 \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF075030 \n"
"    LDR     R0, =0x10E \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x34 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"
"    LDR     R0, [R7, #0x134] \n"
"    LDR     R6, =0x2411C \n"
"    CMP     R0, #0 \n"
"    LDRNEH  R0, [R6, #0xAE] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R5, #8] \n"
"    CMPNE   R0, #1 \n"
"    BLS     loc_FF1D9AB8 \n"
"    LDR     R0, [R7, #0xEC] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF1D9AD0 \n"
"    BL      sub_FF00AB68 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF1D9AD0 \n"
"    BL      sub_FF079ED8 \n"
"    B       loc_FF1D9ACC \n"

"loc_FF1D9AB8:\n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF079E78 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF1D9AD0 \n"
"    BL      sub_FF070C58 \n"

"loc_FF1D9ACC:\n"
"    MOV     R4, #1 \n"

"loc_FF1D9AD0:\n"
"    TST     R4, #1 \n"
"    BNE     loc_FF1D9B40 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF1DAA5C \n"
"    BL      sub_FF1DA6E0 \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_006B82FC /*_ClearEventFlag*/ \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF370F34 \n"
"    TST     R0, #1 \n"
"    MOV     R4, R0 \n"
"    BNE     loc_FF1D9B40 \n"
"    BL      sub_FF0735D0 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF3718DC \n"
"    LDR     R0, [R7, #0x130] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF1D9B2C \n"
"    LDRH    R0, [R6, #0xAE] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R5, #8] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FF1D9B34 \n"

"loc_FF1D9B2C:\n"
"    MOV     R0, #2 \n"
"    BL      sub_FF07B858 \n"

"loc_FF1D9B34:\n"
"    MOV     R0, R5 \n"
"    BL      sub_FF371CF4_my \n"  // --> Patched. Old value = 0xFF371CF4.
"    BL      capt_seq_hook_raw_here \n"         // added
"    B       loc_FF1D9B5C \n"

"loc_FF1D9B40:\n"
"    MOV     R2, R5 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF070E2C \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF1DB2A0 \n"

"loc_FF1D9B5C:\n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    LDMFD   SP!, {R4-R8,PC} \n"
);
}

/*************************************************************/
//** sub_FF371CF4_my @ 0xFF371CF4 - 0xFF371DC0, length=52
void __attribute__((naked,noinline)) sub_FF371CF4_my() {
asm volatile (
"    STMFD   SP!, {R2-R10,LR} \n"
"    LDR     R7, =0x2401C \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x174] \n"
"    ADD     R5, R7, #0x100 \n"
"    CMP     R0, #0 \n"
"    LDRNEH  R0, [R5, #0xAE] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FF371D2C \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF371854 \n"
"    BL      sub_FF1DA1B0 \n"

"loc_FF371D2C:\n"
"    LDR     R0, [R7, #0x16C] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF371D50 \n"
"    LDRH    R0, [R5, #0xAE] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #3 \n"
"    BLS     loc_FF371D74 \n"

"loc_FF371D50:\n"
"    LDR     R0, [R7, #0x1A4] \n"
"    CMP     R0, #2 \n"
"    BNE     loc_FF371D78 \n"
"    LDRH    R0, [R5, #0xAE] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FF371D78 \n"
"    MOV     R0, #4 \n"

"loc_FF371D74:\n"
"    BL      sub_FF123B7C \n"

"loc_FF371D78:\n"
"    LDR     R0, =0x12F \n"
"    MOV     R2, #4 \n"
"    ADD     R1, SP, #4 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    LDRNE   R2, =0x17B \n"
"    LDRNE   R1, =0xFF371FA4 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #4] \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x600 \n"
"    LDRNE   R0, =0xFF37149C \n"
"    LDREQ   R0, =0xFF371CBC \n"
"    MOVNE   R1, R4 \n"
"    MOVEQ   R1, #0 \n"
"    BL      sub_FF0D0290 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF3719D8_my \n"  // --> Patched. Old value = 0xFF3719D8.
"    LDR     PC, =0xFF371DC4 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF3719D8_my @ 0xFF3719D8 - 0xFF371A28, length=21
void __attribute__((naked,noinline)) sub_FF3719D8_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R6, =0x2401C \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R6, #0xFC] \n"
"    LDR     R5, =0x101D8 \n"
"    CMP     R0, #0 \n"
"    ADDNE   R0, R6, #0x100 \n"
"    LDRNEH  R0, [R0, #0xAE] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FF371A28 \n"
"    BL      _GetCCDTemperature \n"
"    MOV     R1, R0 \n"
"    STRH    R0, [R4, #0xB0] \n"
"    LDR     R0, =0x24214 \n"
"    LDRSH   R2, [R0, #0xC] \n"
"    LDRH    R0, [R6, #0x5E] \n"
"    BL      sub_FF2ADF44 \n"
"    STR     R0, [R5] \n"

"loc_FF371A28:\n"
"    BL      wait_until_remote_button_is_released\n" // added
"    BL      capt_seq_hook_set_nr\n"                 // added
"    LDR     R0, [R4, #0x20] \n"
"    LDR     PC, =0xFF371A2C \n"  // Continue in firmware
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF0DECE0 - 0xFF0DF364, length=418
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    SUB     SP, SP, #0x2C \n"
"    LDR     R6, =0x4BB0 \n"
"    LDR     R7, =0xBB8 \n"
"    LDR     R4, =0x63EFC \n"
"    MOV     R0, #0 \n"
"    ADD     R5, SP, #0x1C \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF0DED00:\n"
"    LDR     R0, [R6, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x28 \n"
"    BL      sub_006B84B8 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF0DED4C \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    CMPNE   R0, #0x17 \n"
"    BEQ     loc_FF0DEEB0 \n"
"    CMP     R0, #0x2A \n"
"    BEQ     loc_FF0DEE34 \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0DEC8C \n"

"loc_FF0DED4C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x30 \n"
"    BNE     loc_FF0DED78 \n"
"    BL      sub_FF0E0324 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_006B82C8 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x2C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"

"loc_FF0DED78:\n"
"    CMP     R1, #0x2F \n"
"    BNE     loc_FF0DED94 \n"
"    LDR     R2, [R0, #0xA8]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF0DF35C \n"

"loc_FF0DED94:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_FF0DEDE4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_006B82FC /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF0D9848 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF069300 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_006B81FC /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R2, =0x16EF \n"
"    BNE     loc_FF0DEEA0 \n"

"loc_FF0DEDD0:\n"
"    LDR     R1, [SP, #0x28] \n"
"    LDR     R0, [R1, #0xAC] \n"
"    LDR     R1, [R1, #0xA8] \n"
"    BLX     R1 \n"
"    B       loc_FF0DF35C \n"

"loc_FF0DEDE4:\n"
"    CMP     R1, #0x29 \n"
"    BNE     loc_FF0DEE2C \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF0DEC8C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_006B82FC /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF0D9858 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF06A0D4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_006B81FC /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF0DEDD0 \n"
"    LDR     R2, =0x16F9 \n"
"    B       loc_FF0DEEA0 \n"

"loc_FF0DEE2C:\n"
"    CMP     R1, #0x2A \n"
"    BNE     loc_FF0DEE44 \n"

"loc_FF0DEE34:\n"
"    LDR     R0, [SP, #0x28] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF0DEC8C \n"
"    B       loc_FF0DEDD0 \n"

"loc_FF0DEE44:\n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF0DEE5C \n"
"    BL      sub_FF0C7B88 \n"
"    BL      sub_FF0C89F0 \n"
"    BL      sub_FF0C84D0 \n"
"    B       loc_FF0DEDD0 \n"

"loc_FF0DEE5C:\n"
"    CMP     R1, #0x2E \n"
"    BNE     loc_FF0DEEB0 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #4 \n"
"    BL      sub_006B82FC /*_ClearEventFlag*/ \n"
"    LDR     R1, =0xFF0D9878 \n"
"    LDR     R0, =0xFFFFF400 \n"
"    MOV     R2, #4 \n"
"    BL      sub_FF0C756C \n"
"    BL      sub_FF0C781C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #4 \n"
"    BL      sub_006B8110 /*_WaitForAnyEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF0DEDD0 \n"
"    LDR     R2, =0x1721 \n"

"loc_FF0DEEA0:\n"
"    LDR     R1, =0xFF0D9EF4 /*'ExpDrv.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    B       loc_FF0DEDD0 \n"

"loc_FF0DEEB0:\n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R8, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x12 \n"
"    CMPNE   R1, #0x13 \n"
"    BNE     loc_FF0DEF18 \n"
"    LDR     R1, [R0, #0x94] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF0DCE50 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R3, [R0, #0xA8] \n"
"    LDR     R2, [R0, #0xAC] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF0E0654 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R2, [R0, #0xB4] \n"
"    LDR     R3, [R0, #0xB0] \n"
"    B       loc_FF0DF220 \n"

"loc_FF0DEF18:\n"
"    CMP     R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    CMPNE   R1, #0x17 \n"
"    BNE     loc_FF0DEFC0 \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF0DD0C0 \n"
"    CMP     R0, #1 \n"
"    MOV     R9, R0 \n"
"    CMPNE   R9, #5 \n"
"    BNE     loc_FF0DEF6C \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, R9 \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R12, [R0, #0xA8] \n"
"    LDR     R3, [R0, #0xAC] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R12 \n"
"    B       loc_FF0DEFA4 \n"

"loc_FF0DEF6C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R9, #2 \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R12, [R0, #0xA8] \n"
"    LDR     R3, [R0, #0xAC] \n"
"    CMPNE   R9, #6 \n"
"    MOV     R2, R9 \n"
"    ADD     R0, R0, #4 \n"
"    BNE     loc_FF0DEFB8 \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF0DE970 \n"

"loc_FF0DEFA4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R9 \n"
"    BL      sub_FF0DEBC4 \n"
"    B       loc_FF0DF228 \n"

"loc_FF0DEFB8:\n"
"    BLX     R12 \n"
"    B       loc_FF0DF228 \n"

"loc_FF0DEFC0:\n"
"    CMP     R1, #0x24 \n"
"    CMPNE   R1, #0x25 \n"
"    BNE     loc_FF0DF00C \n"
"    LDR     R1, [R0, #0x94] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF0DBA58 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R3, [R0, #0xA8] \n"
"    LDR     R2, [R0, #0xAC] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF0DBFB0 \n"
"    B       loc_FF0DF228 \n"

"loc_FF0DF00C:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x28 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF0DF210 \n"
"    B       loc_FF0DF0C8 \n"
"    B       loc_FF0DF0C8 \n"
"    B       loc_FF0DF0D0 \n"
"    B       loc_FF0DF0D8 \n"
"    B       loc_FF0DF0D8 \n"
"    B       loc_FF0DF0D8 \n"
"    B       loc_FF0DF0C8 \n"
"    B       loc_FF0DF0D0 \n"
"    B       loc_FF0DF0D8 \n"
"    B       loc_FF0DF0D8 \n"
"    B       loc_FF0DF0F0 \n"
"    B       loc_FF0DF0F0 \n"
"    B       loc_FF0DF1FC \n"
"    B       loc_FF0DF204 \n"
"    B       loc_FF0DF204 \n"
"    B       loc_FF0DF204 \n"
"    B       loc_FF0DF204 \n"
"    B       loc_FF0DF20C \n"
"    B       loc_FF0DF210 \n"
"    B       loc_FF0DF210 \n"
"    B       loc_FF0DF210 \n"
"    B       loc_FF0DF210 \n"
"    B       loc_FF0DF210 \n"
"    B       loc_FF0DF210 \n"
"    B       loc_FF0DF0E0 \n"
"    B       loc_FF0DF0E8 \n"
"    B       loc_FF0DF0E8 \n"
"    B       loc_FF0DF0E8 \n"
"    B       loc_FF0DF0FC \n"
"    B       loc_FF0DF0FC \n"
"    B       loc_FF0DF104 \n"
"    B       loc_FF0DF13C \n"
"    B       loc_FF0DF174 \n"
"    B       loc_FF0DF1AC \n"
"    B       loc_FF0DF1E4 \n"
"    B       loc_FF0DF1E4 \n"
"    B       loc_FF0DF210 \n"
"    B       loc_FF0DF210 \n"
"    B       loc_FF0DF1EC \n"
"    B       loc_FF0DF1F4 \n"

"loc_FF0DF0C8:\n"
"    BL      sub_FF0D9F14 \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF0D0:\n"
"    BL      sub_FF0DA220 \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF0D8:\n"
"    BL      sub_FF0DA4A4 \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF0E0:\n"
"    BL      sub_FF0DA7BC \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF0E8:\n"
"    BL      sub_FF0DA9EC \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF0F0:\n"
"    BL      sub_FF0DAFC4_my \n"  // --> Patched. Old value = 0xFF0DAFC4.
"    MOV     R8, #0 \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF0FC:\n"
"    BL      sub_FF0DB110 \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF104:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF0DB6C4 \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF13C:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF0E03CC \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF174:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R0, #6] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF0E0500 \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF1AC:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF0E05AC \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF1E4:\n"
"    BL      sub_FF0DB7D8 \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF1EC:\n"
"    BL      sub_FF0DC0C8 \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF1F4:\n"
"    BL      sub_FF0DC5E4 \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF1FC:\n"
"    BL      sub_FF0DC854 \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF204:\n"
"    BL      sub_FF0DCA20 \n"
"    B       loc_FF0DF210 \n"

"loc_FF0DF20C:\n"
"    BL      sub_FF0DCB98 \n"

"loc_FF0DF210:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R2, [R0, #0xAC] \n"
"    LDR     R3, [R0, #0xA8] \n"

"loc_FF0DF220:\n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"

"loc_FF0DF228:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x10 \n"
"    BEQ     loc_FF0DF260 \n"
"    BGT     loc_FF0DF250 \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #4 \n"
"    CMPNE   R0, #0xE \n"
"    BNE     loc_FF0DF294 \n"
"    B       loc_FF0DF260 \n"

"loc_FF0DF250:\n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x17 \n"
"    CMPNE   R0, #0x1A \n"
"    BNE     loc_FF0DF294 \n"

"loc_FF0DF260:\n"
"    LDRSH   R0, [R4] \n"
"    CMN     R0, #0xC00 \n"
"    LDRNESH R1, [R4, #8] \n"
"    CMNNE   R1, #0xC00 \n"
"    STRNEH  R0, [SP, #0x1C] \n"
"    STRNEH  R1, [SP, #0x24] \n"
"    BNE     loc_FF0DF294 \n"
"    ADD     R0, SP, #0x10 \n"
"    BL      sub_FF0E086C \n"
"    LDRH    R0, [SP, #0x10] \n"
"    STRH    R0, [SP, #0x1C] \n"
"    LDRH    R0, [SP, #0x18] \n"
"    STRH    R0, [SP, #0x24] \n"

"loc_FF0DF294:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF0DF2E4 \n"
"    LDR     R1, [R0, #0x94] \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R8, R0, #8 \n"
"    LDR     R0, =0x63EFC \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_006D4A08 \n"
"    LDR     R0, =0x63F08 \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_006D4A08 \n"
"    LDR     R0, =0x63F14 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R8 \n"
"    BL      sub_006D4A08 \n"
"    B       loc_FF0DF35C \n"

"loc_FF0DF2E4:\n"
"    LDR     R0, [R0] \n"
"    MOV     R3, #1 \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF0DF328 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0D9C90 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF0DF358 \n"

"loc_FF0DF328:\n"
"    MOV     R2, #1 \n"
"    STRD    R2, [SP] \n"
"    MOV     R3, R2 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_FF0D9C90 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, R3 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"

"loc_FF0DF358:\n"
"    BL      sub_FF0D9E18 \n"

"loc_FF0DF35C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF0E0324 \n"
"    B       loc_FF0DED00 \n"
);
}

/*************************************************************/
//** sub_FF0DAFC4_my @ 0xFF0DAFC4 - 0xFF0DB088, length=50
void __attribute__((naked,noinline)) sub_FF0DAFC4_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x4BB0 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_006B82FC /*_ClearEventFlag*/ \n"
"    MOV     R2, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R3, #1 \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF0D98E0 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF0D9A9C \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF0D9AF4 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF0D9B4C \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF0D9BA4 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x63F14 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, R6 \n"
"    BEQ     loc_FF0DB05C \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF0DB05C \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF0D9838 \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF06962C \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF0DB064 \n"

"loc_FF0DB05C:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF0DB064:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF0DB080 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF0D98BC \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF0E0388 \n"

"loc_FF0DB080:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF0C7894_my \n"  // --> Patched. Old value = 0xFF0C7894.
"    LDR     PC, =0xFF0DB08C \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF0C7894_my @ 0xFF0C7894 - 0xFF0C78DC, length=19
void __attribute__((naked,noinline)) sub_FF0C7894_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x4818 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    MOVNE   R2, #0x154 \n"
"    LDRNE   R1, =0xFF0C765C /*'Shutter.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R2, =0x15A \n"
"    LDREQ   R1, =0xFF0C765C /*'Shutter.c'*/ \n"
"    MOVEQ   R0, #0 \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    LDR     PC, =0xFF0C78E0 \n"  // Continue in firmware
);
}
