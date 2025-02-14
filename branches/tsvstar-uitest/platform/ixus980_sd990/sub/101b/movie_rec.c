#include "conf.h"

// from sx10
void change_video_tables(int a, int b){
}

// from sx10, not sure if the values are right, seems to work
void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

void __attribute__((naked,noinline)) movie_record_task(){ 
 asm volatile(
"                STMFD   SP!, {R2-R8,LR}\n"
"                LDR     R7, =0x2710\n"
"                LDR     R4, =0x53A0\n"
"                MOV     R6, #0\n"
"                MOV     R5, #1\n"
"loc_FF86215C:\n" // main loop
"                LDR     R0, [R4,#0x1C]\n"
"                MOV     R2, #0\n"
"                ADD     R1, SP, #4\n"
"                BL      sub_FF82746C\n" // LOCATION: KerQueue.c:0
"                LDR     R0, [R4,#0x24]\n"
"                CMP     R0, #0\n"
"                BNE     loc_FF86222C\n"
"                LDR     R0, [SP,#4]\n"
"                LDR     R1, [R0]\n"
"                SUB     R1, R1, #2\n"
"                CMP     R1, #9\n"
"                ADDLS   PC, PC, R1,LSL#2\n"
"                B       loc_FF86222C\n"
"                B       loc_FF8621E0\n"
"                B       loc_FF862200\n"
"                B       loc_FF862210\n"
"                B       loc_FF862218\n"
"                B       loc_FF8621E8\n"
"                B       loc_FF862220\n"
"                B       loc_FF8621F0\n"
"                B       loc_FF86222C\n"
"                B       loc_FF862228\n"
"                B       loc_FF8621B8\n"
"loc_FF8621B8:\n"
// jumptable FF862188 entry 9
"                LDR     R0, =0xFF861E30\n" // loc_ret
"                STR     R6, [R4,#0x38]\n"
"                STR     R0, [R4,#0xA0]\n"
"                LDR     R2, =0xFF8613B0\n" // sub_FF8613B0
"                LDR     R1, =0x1AE50\n"
"                LDR     R0, =0xFF861494\n" //loc_FF861494
"                STR     R6, [R4,#0x28]\n"
"                BL      sub_FF83BBFC\n"
"                STR     R5, [R4,#0x3C]\n"
"                B       loc_FF86222C\n" // -> jt 7, loop
"loc_FF8621E0:\n"
// jumptable FF862188 entry 0
"                BL      unlock_optical_zoom\n" //  +
"                BL      sub_FF861F28\n" // __MovieRecorder_c__0
"                B       loc_FF86222C\n"
"loc_FF8621E8:\n"
// jumptable FF862188 entry 4
"                BL      sub_FF861AA8_my\n" // -> _for quality overrides
"                B       loc_FF86222C\n"
"loc_FF8621F0:\n"
// jumptable FF862188 entry 6
"                LDR     R1, [R0,#0x10]\n"
"                LDR     R0, [R0,#4]\n"
"                BL      sub_FF937EF8\n" // LOCATION: MovWriter.c:0
"                B       loc_FF86222C\n" // -> jt 7, loop
"loc_FF862200:\n"
// jumptable FF862188 entry 1
"                LDR     R0, [R4,#0x3C]\n"
"                CMP     R0, #5\n"
"                STRNE   R5, [R4,#0x2C]\n"
"                B       loc_FF86222C\n" // -> jt 7, loop
"loc_FF862210:\n"
// jumptable FF862188 entry 2
"                BL      sub_FF8617F0\n" // __MovieRecorder_c__0
"                B       loc_FF86222C\n" // -> jt 7, loop
"loc_FF862218:\n"
// jumptable FF862188 entry 3
"                BL      sub_FF8614E0\n" // __MovieRecorder_c__0
"                B       loc_FF86222C\n" // -> jt 7, loop
"loc_FF862220:\n"
// jumptable FF862188 entry 5
"                BL      sub_FF86133C\n" //__MovieRecorder_c__100
"                B       loc_FF86222C\n" // -> jt 7, loop
"loc_FF862228:\n"
// jumptable FF862188 entry 8
"                BL      sub_FF862398\n" /// __MovieRecorder_c__100
"loc_FF86222C:\n"
// jumptable FF862188 default entry
// jumptable FF862188 entry 7
"                LDR     R1, [SP,#4]\n"
"                MOV     R3, #0x430\n"
"                STR     R6, [R1]\n"
"                STR     R3, [SP]\n"
"                LDR     R0, [R4,#0x20]\n"
"                LDR     R3, =0xFF86113C\n"// =aMovierecorder_
"                MOV     R2, R7\n"
"                BL      sub_FF827DC0\n"
"                B       loc_FF86215C\n" // -> main loop
 );
}

void __attribute__((naked,noinline)) sub_FF861AA8_my(){ 
 asm volatile(
"                STMFD   SP!, {R4-R10,LR}\n"
"                SUB     SP, SP, #0x40\n"
"                MOV     R7, #0\n"
"                LDR     R6, =0x53A0\n"
"                MOV     R4, R0\n"
"                STR     R7, [SP,#0x30]\n"
"                STR     R7, [SP,#0x28]\n"
"                LDR     R0, [R6,#0x3C]\n"
"                MOV     R9, #4\n"
"                CMP     R0, #3\n"
"                STREQ   R9, [R6,#0x3C]\n"
"                LDR     R0, [R6,#0xA0]\n"
"                MOV     R8, #0\n"
"                BLX     R0\n"
"                LDR     R0, [R6,#0x3C]\n"
"                CMP     R0, #4\n"
"                BNE     loc_FF861C2C\n"
"                LDRH    R0, [R6,#2]\n"
"                MOV     R5, #1\n"
"                CMP     R0, #1\n"
"                BNE     loc_FF861B24\n"
"                LDRH    R1, [R6,#4]\n"
"                LDR     R0, [R6,#0x48]\n"
"                MUL     R0, R1, R0\n"
"                MOV     R1, #0x3E8\n"
"                BL      sub_FFAE072C\n"
"                MOV     R1, R0\n"
"                LDR     R0, [R6,#0x50]\n"
"                BL      sub_FFAE072C\n"
"                CMP     R1, #0\n"
"                BNE     loc_FF861B40\n"
"loc_FF861B24:\n"
"                ADD     R3, SP, #0x28\n"
"                ADD     R2, SP, #0x2C\n"
"                ADD     R1, SP, #0x30\n"
"                ADD     R0, SP, #0x34\n"
"                BL      sub_FF937F94\n" //__MovWriter_c__0 ; LOCATION: MovWriter.c:0
"                MOVS    R8, R0\n"
"                BNE     loc_FF861B5C\n"
"loc_FF861B40:\n"
"                LDR     R0, [R6,#0x2C]\n"
"                CMP     R0, #1\n"
"                BNE     loc_FF861C40\n"
"                LDR     R0, [R6,#0x50]\n"
"                LDR     R1, [R6,#0x40]\n"
"                CMP     R0, R1\n"
"                BCC     loc_FF861C40\n"
"loc_FF861B5C:\n"
"                CMP     R8, #0x80000001\n"
"                STREQ   R9, [R6,#0x54]\n"
"                BEQ     loc_FF861B94\n"
"                CMP     R8, #0x80000003\n"
"                STREQ   R5, [R6,#0x54]\n"
"                BEQ     loc_FF861B94\n"
"                CMP     R8, #0x80000005\n"
"                MOVEQ   R0, #2\n"
"                BEQ     loc_FF861B90\n"
"                CMP     R8, #0x80000007\n"
"                STRNE   R7, [R6,#0x54]\n"
"                BNE     loc_FF861B94\n"
"                MOV     R0, #3\n"
"loc_FF861B90:\n"
"                STR     R0, [R6,#0x54]\n"
"loc_FF861B94:\n"
"                LDR     R0, =0x1AE84\n"
"                LDR     R0, [R0,#8]\n"
"                CMP     R0, #0\n"
"                BEQ     loc_FF861BAC\n"
"                BL      sub_FF84BCCC\n"
"                B       loc_FF861BB0\n"
"loc_FF861BAC:\n"
"                BL      sub_FF86133C\n" //__MovieRecorder_c__100
"loc_FF861BB0:\n"
"                LDR     R0, [R4,#0x14]\n"
"                LDR     R1, [R4,#0x18]\n"
"                ADD     R3, SP, #0x38\n"
"                MVN     R2, #1\n"
"                ADD     R7, SP, #0x18\n"
"                STMIA   R7, {R0-R3}\n"
"                MOV     R0, #0\n"
"                ADD     R1, SP, #0x3C\n"
"                ADD     R7, SP, #8\n"
"                LDRD    R2, [R6,#0x68]\n"
"                STMIA   R7, {R0-R3}\n"
"                MOV     R3, #0\n"
"                MOV     R2, #0x40\n"
"                STRD    R2, [SP]\n"
"                LDMIB   R4, {R0,R1}\n"
"                LDR     R3, =0x1AE9C\n"
"                MOV     R2, R10\n"
"                BL      sub_FF8F5C40\n"
"                LDR     R0, [R6,#0x14]\n"
"                MOV     R1, #0x3E8\n"
"                BL      sub_FF827888\n" //eventproc_export_TakeSemaphore ; LOCATION: KerSem.c:0
"                CMP     R0, #9\n"
"                BEQ     loc_FF861CC0\n"
"                LDR     R0, [SP,#0x38]\n"
"                CMP     R0, #0\n"
"                BNE     loc_FF861CDC\n"
"                MOV     R0, #1\n"
"                BL      sub_FF8F5CE8\n"
"                BL      sub_FF8F5D24\n"
"                MOV     R0, #5\n"
"                STR     R0, [R6,#0x3C]\n"
"loc_FF861C2C:\n"
"                ADD     SP, SP, #0x40\n"
"                LDMFD   SP!, {R4-R10,PC}\n"
"loc_FF861C34:\n"
"                BL      sub_FF87DD18\n" // eventproc_export_HardwareDefect
"                MOV     R0, #1\n"
"                B       loc_FF861D78\n"
"loc_FF861C40:\n"
"                LDR     R12, [SP,#0x30]\n"
"                CMP     R12, #0\n"
"                BEQ     loc_FF861DD8\n"
"                STR     R5, [R6,#0x30]\n"
"                LDR     R0, [R6,#0x50]\n"
"                LDR     R8, [R4,#0xC]\n"
"                CMP     R0, #0\n"
"                LDRNE   LR, [SP,#0x34]\n"
"                BNE     loc_FF861D08\n"
"                LDR     R0, [R4,#0x14]\n"
"                LDR     R1, [R4,#0x18]\n"
"                ADD     R3, SP, #0x38\n"
"                MVN     R2, #0\n"
"                ADD     R9, SP, #0x18\n"
"                STMIA   R9, {R0-R3}\n"
"                LDRD    R2, [R6,#0x68]\n"
"                LDR     R0, [SP,#0x28]\n"
"                ADD     R1, SP, #0x3C\n"
"                ADD     R9, SP, #8\n"
"                STMIA   R9, {R0-R3}\n"
"                LDR     R3, [SP,#0x2C]\n"
"                STR     R12, [SP]\n"
"                STR     R3, [SP,#4]\n"
"                LDMIB   R4, {R0,R1}\n"
"                LDR     R3, [SP,#0x34]\n"
"                MOV     R2, R8\n"
"                BL      sub_FF8F5C40\n"
"                LDR     R0, [R6,#0x14]\n"
"                MOV     R1, #0x3E8\n"
"                BL      sub_FF827888\n" // eventproc_export_TakeSemaphore ; LOCATION: KerSem.c:0
"                CMP     R0, #9\n"
"                BNE     loc_FF861CD0\n"
"loc_FF861CC0:\n"
"                BL      sub_FF938460\n"
"                MOV     R0, #0x90000\n"
"                STR     R5, [R6,#0x3C]\n"
"                B       loc_FF861C34\n"
"loc_FF861CD0:\n"
"                LDR     R0, [SP,#0x38]\n"
"                CMP     R0, #0\n"
"                BEQ     loc_FF861CEC\n"
"loc_FF861CDC:\n"
"                BL      sub_FF938460\n"
"                MOV     R0, #0xA0000\n"
"                STR     R5, [R6,#0x3C]\n"
"                B       loc_FF861C34\n"
"loc_FF861CEC:\n"
"                MOV     R0, #1\n"
"                BL      sub_FF8F5CE8\n"
"                LDR     R0, [SP,#0x3C]\n"
"                LDR     R1, [SP,#0x34]\n"
"                ADD     LR, R1, R0\n"
"                LDR     R1, [SP,#0x30]\n"
"                SUB     R12, R1, R0\n"
"loc_FF861D08:\n"
"                LDR     R0, [R4,#0x14]\n"
"                LDR     R2, [R6,#0x4C]\n"
"                LDR     R1, [R4,#0x18]\n"
"                ADD     R3, SP, #0x38\n"
"                ADD     R9, SP, #0x18\n"
"                STMIA   R9, {R0-R3}\n"
"                LDRD    R2, [R6,#0x68]\n"
"                LDR     R0, [SP,#0x28]\n"
"                ADD     R1, SP, #0x3C\n"
"                ADD     R9, SP, #8\n"
"                STMIA   R9, {R0-R3}\n"
"                LDR     R3, [SP,#0x2C]\n"
"                STR     R12, [SP]\n"
"                STR     R3, [SP,#4]\n"
"                LDMIB   R4, {R0,R1}\n"
"                MOV     R3, LR\n"
"                MOV     R2, R8\n"
"                BL      sub_FF8F5C40\n"
"                LDR     R0, [R6,#0x14]\n"
"                MOV     R1, #0x3E8\n"
"                BL      sub_FF827888\n" // eventproc_export_TakeSemaphore ; LOCATION: KerSem.c:0
"                CMP     R0, #9\n"
"                BNE     loc_FF861D80\n"
"                BL      sub_FF938460\n"
"                MOV     R0, #0x90000\n"
"                STR     R5, [R6,#0x3C]\n"
"                BL      sub_FF87DD18\n" // eventproc_export_HardwareDefect
"                MOV     R0, #0\n"
"loc_FF861D78:\n"
"                BL      sub_FF8F5CE8\n"
"                B       loc_FF861C2C\n"
"loc_FF861D80:\n"
"                LDR     R0, [SP,#0x38]\n"
"                CMP     R0, #0\n"
"                BEQ     loc_FF861DA0\n"
"                BL      sub_FF938460\n"
"                MOV     R0, #0xA0000\n"
"                STR     R5, [R6,#0x3C]\n"
"                BL      sub_FF87DD18\n" // eventproc_export_HardwareDefect
"                B       loc_FF861C2C\n"
"loc_FF861DA0:\n"
"                MOV     R0, #0\n"
"                BL      sub_FF8F5CE8\n"
"                LDR     R0, [SP,#0x34]\n"
"                LDR     R1, [SP,#0x3C]\n"
"                BL      sub_FF9381BC\n" // __MovWriter_c__0 ; LOCATION: MovWriter.c:0
"                LDR     R0, [R6,#0x4C]\n"
"                LDR     R3, =0x540C\n"
"                ADD     R1, R0, #1\n"
"                STR     R1, [R6,#0x4C]\n"
"                STR     R3, [SP]\n"
"                LDR     R0, [SP,#0x3C]\n"
"                SUB     R3, R3, #4\n"
"                MOV     R2, #0xF\n"
"                BL      sub_FF9364B8\n"
"                LDR     R0, =0x540C-4\n" // +
"                BL      set_quality\n" // +
"loc_FF861DD8:\n"
"                LDR     R0, [R6,#0x50]\n"
"                ADD     R0, R0, #1\n"
"                STR     R0, [R6,#0x50]\n"
"                LDR     R1, [R6,#0x78]\n"
"                MUL     R0, R1, R0\n"
"                LDR     R1, [R6,#0x74]\n"
"                BL      sub_FFAE072C\n"
"                MOV     R4, R0\n"
"                BL      sub_FF938498\n"
"                LDR     R1, [R6,#0x70]\n"
"                CMP     R1, R4\n"
"                BNE     loc_FF861E14\n"
"                LDR     R0, [R6,#0x34]\n"
"                CMP     R0, #1\n"
"                BNE     loc_FF861E28\n"
"loc_FF861E14:\n"
"                LDR     R1, [R6,#0x84]\n"
"                MOV     R0, R4\n"
"                BLX     R1\n"
"                STR     R4, [R6,#0x70]\n"
"                STR     R7, [R6,#0x34]\n"
"loc_FF861E28:\n"
"                STR     R7, [R6,#0x30]\n"
"                B       loc_FF861C2C\n"
 );
}

