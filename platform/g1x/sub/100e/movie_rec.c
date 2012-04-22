#include "conf.h"

void change_video_tables(int a, int b){
}

void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

// @ 0xff1ca86c
void __attribute__((naked,noinline)) movie_record_task(){ 

 asm volatile(
		"STMFD   SP!, {R2-R10,LR}\n"
		"LDR     R6, =0xFF1C98BC\n" //nullsub_163
		"LDR     R7, =0xFF1CA2D8\n" //sub_FF1CA2D8
		"LDR     R4, =0x9D98\n"
		"LDR     R9, =0x6D6\n"
		"LDR     R10, =0x2710\n"
		"MOV     R8, #1\n"
		"MOV     R5, #0\n"
"loc_FF1CA88C:\n"
		"LDR     R0, [R4,#0x24]\n"
		"MOV     R2, #0\n"
		"ADD     R1, SP, #4\n"
		"BL      sub_FF029EA8\n"
		"LDR     R0, [R4,#0x2C]\n"
		"CMP     R0, #0\n"
		"LDRNE   R0, [R4,#0xC]\n"
		"CMPNE   R0, #2\n"
		"LDRNE   R0, [R4,#0x44]\n"
		"CMPNE   R0, #6\n"
		"BNE     loc_FF1CA9C8\n"
		"LDR     R0, [SP,#4]\n"
		"LDR     R1, [R0]\n"
		"SUB     R1, R1, #2\n"
		"CMP     R1, #0xD\n"
		"ADDCC   PC, PC, R1,LSL#2\n"
		"B       loc_FF1CA9C8\n"
		"B       loc_FF1CA968\n"
		"B       loc_FF1CA98C\n"
		"B       loc_FF1CA99C\n"
		"B       loc_FF1CA9A4\n"
		"B       loc_FF1CA9AC\n"
		"B       loc_FF1CA9B4\n"
		"B       loc_FF1CA970\n"
		"B       loc_FF1CA9BC\n"
		"B       loc_FF1CA97C\n"
		"B       loc_FF1CA9C8\n"
		"B       loc_FF1CA9C4\n"
		"B       loc_FF1CA934\n"
		"B       loc_FF1CA904\n"
"loc_FF1CA904:\n"
// jumptable FF1CA8C8 entry 12
		"STR     R5, [R4,#0x40]\n"
		"STR     R5, [R4,#0x30]\n"
		"STR     R5, [R4,#0x34]\n"
		"STRH    R5, [R4,#6]\n"
		"STR     R6, [R4,#0xD8]\n"
		"STR     R7, [R4,#0xF4]\n"
		"LDR     R0, [R4,#0xC]\n"
		"ADD     R0, R0, #1\n"
		"STR     R0, [R4,#0xC]\n"
		"MOV     R0, #6\n"
		"STR     R0, [R4,#0x44]\n"
		"B       loc_FF1CA954\n"
"loc_FF1CA934:\n"
// jumptable FF1CA8C8 entry 11
		"STR     R5, [R4,#0x40]\n"
		"STR     R5, [R4,#0x30]\n"
		"STR     R6, [R4,#0xD8]\n"
		"STR     R7, [R4,#0xF4]\n"
		"LDR     R0, [R4,#0xC]\n"
		"ADD     R0, R0, #1\n"
		"STR     R0, [R4,#0xC]\n"
		"STR     R8, [R4,#0x44]\n"
"loc_FF1CA954:\n"
		"LDR     R2, =0xFF1C8E50\n" //sub_FF1C8E50
		"LDR     R1, =0xC4620\n"
		"LDR     R0, =0xFF1C8F64\n" //sub_FF1C8F64
		"BL      sub_FF046660\n"
		"B       loc_FF1CA9C8\n"
"loc_FF1CA968:\n"
// jumptable FF1CA8C8 entry 0
		"BL      sub_FF1C9DE8\n"
		"B       loc_FF1CA9C8\n"
"loc_FF1CA970:\n"
// jumptable FF1CA8C8 entry 6
		"LDR     R1, [R4,#0xF4]\n"
		"BLX     R1\n"

"                LDR 	 R0, =0x9E1C \n"         //added - Found @FF1CA7C8 & FF1CA7D8 (0x9E20 - 4)
"                BL		 set_quality \n"         //added

		"B       loc_FF1CA9C8\n"
"loc_FF1CA97C:\n"
// jumptable FF1CA8C8 entry 8
		"LDR     R1, [R0,#0x18]\n"
		"LDR     R0, [R0,#4]\n"
		"BL      sub_FF369944\n"
		"B       loc_FF1CA9C8\n"
"loc_FF1CA98C:\n"
// jumptable FF1CA8C8 entry 1
		"LDR     R0, [R4,#0x44]\n"
		"CMP     R0, #5\n"
		"STRNE   R8, [R4,#0x34]\n"
		"B       loc_FF1CA9C8\n"
"loc_FF1CA99C:\n"
// jumptable FF1CA8C8 entry 2
		"BL      sub_FF1C9520\n"
		"B       loc_FF1CA9C8\n"
"loc_FF1CA9A4:\n"
// jumptable FF1CA8C8 entry 3
		"BL      sub_FF1C9218\n"
		"B       loc_FF1CA9C8\n"
"loc_FF1CA9AC:\n"
// jumptable FF1CA8C8 entry 4
		"BL      sub_FF1C8FBC\n"
		"B       loc_FF1CA9C8\n"
"loc_FF1CA9B4:\n"
// jumptable FF1CA8C8 entry 5
		"BL      sub_FF1C8BE4\n"
		"B       loc_FF1CA9C8\n"
"loc_FF1CA9BC:\n"
// jumptable FF1CA8C8 entry 7
		"BL      sub_FF1C8B64\n"
		"B       loc_FF1CA9C8\n"
"loc_FF1CA9C4:\n"
// jumptable FF1CA8C8 entry 10
		"BL      sub_FF1CAF04\n"
"loc_FF1CA9C8:\n"
// jumptable FF1CA8C8 default entry
// jumptable FF1CA8C8 entry 9
		"LDR     R1, [SP,#4]\n"
		"LDR     R3, =0xFF1C8900\n" //aMovierecorder_ ; "MovieRecorder.c"
		"STR     R5, [R1]\n"
		"STR     R9, [SP]\n"
		"LDR     R0, [R4,#0x28]\n"
		"MOV     R2, R10\n"
		"BL      sub_FF02A820\n"
		"B       loc_FF1CA88C\n"
 );
}

