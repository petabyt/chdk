#include "conf.h"

void change_video_tables(int a, int b){
}

void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

// @ 0xff078534
void __attribute__((naked,noinline)) movie_record_task(){ 

 asm volatile(
"                STMFD   SP!, {R2-R12,LR} \n"
"                LDR     R11, =0x68E \n"
"                LDR     R7, =0xFF07728C \n"
"                LDR     R8, =0xFF077F18 \n"
"                LDR     R9, =0xFF075670 \n"
"                LDR     R4, =0x2ED8 \n"
"                LDR     R10, =0x2710 \n"
"                MOV     R5, #1 \n"
"                MOV     R6, #0 \n"

"loc_FF078558: \n"
"                LDR     R0, [R4,#0x24] \n"
"                MOV     R2, #0 \n"
"                ADD     R1, SP, #4 \n"
"                BL      sub_FF02B0F4 \n"
"                LDR     R2, =0xFF074F24 \n"	// aMovierecorder_
"                LDR     R0, [R4,#0x12C] \n"
"                MOV     R3, R11 \n"
"                MOV     R1, R10 \n"
"                BL      sub_FF02BA14 \n"
"                LDR     R0, [R4,#0x2C] \n"
"                CMP     R0, #0 \n"
"                LDRNE   R0, [R4,#0xC] \n"
"                CMPNE   R0, #2 \n"
"                LDRNE   R0, [R4,#0x44] \n"
"                CMPNE   R0, #6 \n"
"                BNE     loc_FF0786C4 \n"
"                LDR     R0, [SP,#4] \n"
"                LDR     R1, [R0] \n"
"                SUB     R1, R1, #2 \n"
"                CMP     R1, #0xF \n"
"                ADDCC   PC, PC, R1,LSL#2 \n"

"                B       loc_FF0786C4 \n"
"                B       loc_FF078658 \n"
"                B       loc_FF078674 \n"
"                B       loc_FF078684 \n"
"                B       loc_FF07868C \n"
"                B       loc_FF078694 \n"
"                B       loc_FF07869C \n"
"                B       loc_FF078660 \n"
"                B       loc_FF0786A4 \n"
"                B       loc_FF07866C \n"
"                B       loc_FF0786C4 \n"
"                B       loc_FF0786B4 \n"
"                B       loc_FF0786BC \n"
"                B       loc_FF0786AC \n"
"                B       loc_FF078620 \n"
"                B       loc_FF0785EC \n"

"loc_FF0785EC: \n"
//"; jumptable FF8833B8 entry 14 \n"
"                STR     R6, [R4,#0x40] \n"
"                STR     R6, [R4,#0x30] \n"
"                STR     R6, [R4,#0x34] \n"
"                STRH    R6, [R4,#6] \n"
"                STR     R7, [R4,#0xD8] \n"
"                STR     R8, [R4,#0xF4] \n"
"                STR     R9, [R4,#0xF8] \n"
"                LDR     R0, [R4,#0xC] \n"
"                ADD     R0, R0, #1 \n"
"                STR     R0, [R4,#0xC] \n"
"                MOV     R0, #6 \n"
"                STR     R0, [R4,#0x44] \n"
"                B       loc_FF078644 \n"

"loc_FF078620: \n"
//"; jumptable FF8833B8 entry 13 \n"
"                STR     R6, [R4,#0x40] \n"
"                STR     R6, [R4,#0x30] \n"
"                STR     R7, [R4,#0xD8] \n"
"                STR     R8, [R4,#0xF4] \n"
"                STR     R9, [R4,#0xF8] \n"
"                LDR     R0, [R4,#0xC] \n"
"                ADD     R0, R0, #1 \n"
"                STR     R0, [R4,#0xC] \n"
"                STR     R5, [R4,#0x44] \n"

"loc_FF078644: \n"
"                LDR     R2, =0xFF075674 \n"
"                LDR     R1, =0x3F118 \n"
"                LDR     R0, =0xFF0757BC \n"
"                BL      sub_FF0472A0 \n"
"                B       loc_FF0786C4 \n"

"loc_FF078658: \n"
//"; jumptable FF8833B8 entry 0
"                BL      sub_FF077A90 \n"
"                B       loc_FF0786C4 \n"

"loc_FF078660: \n"
//"; jumptable FF8833B8 entry 6
"                LDR     R1, [R4,#0xF4] \n"
"                BLX     R1 \n"

"                LDR 	 R0, =0x2F5C \n"         //added - Found @FF0784A8
"                BL		 set_quality \n"         //added

"                B       loc_FF0786C4 \n"

"loc_FF07866C: \n"
//"; jumptable FF8833B8 entry 8
"                BL      sub_FF078D6C \n"
"                B       loc_FF0786C4 \n"

"loc_FF078674: \n"
//"; jumptable FF8833B8 entry 1
"                LDR     R0, [R4,#0x44] \n"
"                CMP     R0, #5 \n"
"                STRNE   R5, [R4,#0x34] \n"
"                B       loc_FF0786C4 \n"

"loc_FF078684: \n"
//"; jumptable FF8833B8 entry 2
"                BL      sub_FF076F24 \n"
"                B       loc_FF0786C4 \n"

"loc_FF07868C: \n"
//"; jumptable FF8833B8 entry 3
"                BL      sub_FF076C38 \n"
"                B       loc_FF0786C4 \n"

"loc_FF078694: \n"
//"; jumptable FF8833B8 entry 4
"                BL      sub_FF0769F4 \n"
"                B       loc_FF0786C4 \n"

"loc_FF07869C: \n"
//"; jumptable FF8833B8 entry 5
"                BL      sub_FF076788 \n"
"                B       loc_FF0786C4 \n"

"loc_FF0786A4: \n"
//"; jumptable FF8833B8 entry 7
"                BL      sub_FF075830 \n"
"                B       loc_FF0786C4 \n"

"loc_FF0786AC: \n"
//"; jumptable FF8833B8 entry 12
"                BL      sub_FF078C94 \n"
"                B       loc_FF0786C4 \n"

"loc_FF0786B4: \n"
//"; jumptable FF8833B8 entry 10
"                BL      sub_FF0765A0 \n"
"                B       loc_FF0786C4 \n"

"loc_FF0786BC: \n"
//"; jumptable FF8833B8 entry 11
"                BL      sub_FF076414 \n"
"                STR     R5, [R4,#0x158] \n"

"loc_FF0786C4: \n"
//"; jumptable FF8833B8 default entry \n"
//"; jumptable FF8833B8 entry 9 \n"
"                LDR     R1, [SP,#4] \n"
"                LDR     R3, =0x6D6 \n"
"                STR     R6, [R1] \n"
"                STR     R3, [SP] \n"
"                LDR     R3, =0xFF074F24 \n" //;aMovierecorder_
"                LDR     R0, [R4,#0x28] \n"
"                MOV     R2, R10 \n"
"                BL      sub_FF02BA6C \n"
"                LDR     R0, [R4,#0x12C] \n"
"                BL      _GiveSemaphore \n"
"                B       loc_FF078558 \n"
 );
}

