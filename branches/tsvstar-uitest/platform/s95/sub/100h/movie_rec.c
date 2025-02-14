#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;


/*----------------------------------------------------------------------
	set_quality()
-----------------------------------------------------------------------*/
void  set_quality (int *x)  // -17 highest; +12 lowest
{
	if (conf.video_mode)
		*x = 12 - ((conf.video_quality-1) * (12+17) / (99-1));
}


/*----------------------------------------------------------------------
	change_video_tables()
-----------------------------------------------------------------------*/
void change_video_tables(int a, int b)
{
}


/*----------------------------------------------------------------------
	movie_record_task()
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) movie_record_task()
{
	asm volatile (
"		STMFD	SP!, {R2-R10,LR} \n"
"		LDR	R9, =0x5EE \n"
"		LDR	R8, =0x2710 \n"
"		LDR	R4, =0x7128 \n"
"		MOV	R7, #1 \n"
"		LDR	R6, =0xFF98611C \n"			// nullsub_322
"		MOV	R5, #0 \n"
"loc_FF986444: \n"
"		LDR	R0, [R4,#0x24] \n"
"		MOV	R2, #0 \n"
"		ADD	R1, SP,	#4 \n"
"		BL	sub_FF83A2F8 \n"
"		LDR	R0, [R4,#0x2C] \n"
"		CMP	R0, #0 \n"
"		LDRNE	R0, [R4,#0xC] \n"
"		CMPNE	R0, #2 \n"
"		LDRNE	R0, [R4,#0x44] \n"
"		CMPNE	R0, #6 \n"
"		BNE	loc_FF98655C \n"
"		LDR	R0, [SP,#0x4] \n"
"		LDR	R1, [R0] \n"
"		SUB	R1, R1,	#2 \n"
"		CMP	R1, #0xA \n"
"		ADDLS	PC, PC,	R1,LSL#2 \n"
"		B	loc_FF98655C \n"
"loc_FF986488: \n"
"		B	loc_FF986510 \n"
"loc_FF98648C: \n"
"		B	loc_FF986530 \n"
"loc_FF986490: \n"
"		B	loc_FF986540 \n"
"loc_FF986494: \n"
"		B	loc_FF986548 \n"
"loc_FF986498: \n"
"		B	loc_FF986518 \n"
"loc_FF98649C: \n"
"		B	loc_FF986550 \n"
"loc_FF9864A0: \n"
"		B	loc_FF986520 \n"
"loc_FF9864A4: \n"
"		B	loc_FF98655C \n"
"loc_FF9864A8: \n"
"		B	loc_FF986558 \n"
"loc_FF9864AC: \n"
"		B	loc_FF9864E0 \n"
"loc_FF9864B0: \n"
"		B	loc_FF9864B4 \n"

"loc_FF9864B4: \n"
// jumptable FF986480 entry 10
"		STR	R5, [R4,#0x40] \n"
"		STR	R5, [R4,#0x30] \n"
"		STR	R5, [R4,#0x34] \n"
"		STRH	R5, [R4,#6] \n"
"		STR	R6, [R4,#0xB4] \n"
"		LDR	R0, [R4,#0xC] \n"
"		ADD	R0, R0,	#1 \n"
"		STR	R0, [R4,#0xC] \n"
"		MOV	R0, #6 \n"
"		STR	R0, [R4,#0x44] \n"
"		B	loc_FF9864FC \n"

"loc_FF9864E0: \n"
// jumptable FF986480 entry 9
"		STR	R5, [R4,#0x40] \n"
"		STR	R5, [R4,#0x30] \n"
"		STR	R6, [R4,#0xB4] \n"
"		LDR	R0, [R4,#0xC] \n"
"		ADD	R0, R0,	#1 \n"
"		STR	R0, [R4,#0xC] \n"
"		STR	R7, [R4,#0x44] \n"
"loc_FF9864FC: \n"
"		LDR	R2, =0xFF985334 \n"
"		LDR	R1, =0xB45D0 \n"

//"		LDR	R0, =sub_FF985430 \n"
"		LDR	R0, =0xFF985430 \n"

"		BL	sub_FF8530D0 \n"
"		B	loc_FF98655C \n"

"loc_FF986510: \n"
// jumptable FF986480 entry 0

"		BL	unlock_optical_zoom\n" 			// added to unlock the zoom

"		BL	sub_FF986244 \n"
"		B	loc_FF98655C \n"

"loc_FF986518: \n"
// jumptable FF986480 entry 4
//"		BL	sub_FF985B84 \n"
"		BL	sub_FF985B84_my \n"				// patched

"		B	loc_FF98655C \n"

"loc_FF986520: \n"
// jumptable FF986480 entry 6
"		LDR	R1, [R0,#0x18] \n"
"		LDR	R0, [R0,#4] \n"
"		BL	sub_FFAF2B24 \n"
"		B	loc_FF98655C \n"

"loc_FF986530: \n"
// jumptable FF986480 entry 1
"		LDR	R0, [R4,#0x44] \n"
"		CMP	R0, #5 \n"
"		STRNE	R7, [R4,#0x34] \n"
"		B	loc_FF98655C \n"

"loc_FF986540: \n"
// jumptable FF986480 entry 2
"		BL	sub_FF9857CC \n"
"		B	loc_FF98655C \n"

"loc_FF986548: \n"
// jumptable FF986480 entry 3
"		BL	sub_FF98547C \n"
"		B	loc_FF98655C \n"

"loc_FF986550: \n"
// jumptable FF986480 entry 5
"		BL	sub_FF9852C0 \n"
"		B	loc_FF98655C \n"

"loc_FF986558: \n"
// jumptable FF986480 entry 8
"		BL	sub_FF98698C \n"

"loc_FF98655C: \n"
// jumptable FF986480 default entry
// jumptable FF986480 entry 7
"		LDR	R1, [SP,#0x4] \n"
"		STR	R5, [R1] \n"
"		LDR	R3, =0xFF985124 \n"			// MovieRecorder.c
"		MOV	R2, R8 \n"
"		STR	R9, [SP,#0x0] \n"
"		LDR	R0, [R4,#0x28] \n"
"		BL	sub_FF83AC4C \n"
"		B	loc_FF986444 \n"
	);
}


/*----------------------------------------------------------------------
	sub_FF985B84_my()
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) sub_FF985B84_my()
{
	asm volatile (
"		STMFD	SP!, {R4-R11,LR} \n"
"		SUB	SP, SP,	#0x64 \n"
"		MOV	R8, #0 \n"
"		LDR	R6, =0x7128 \n"
"		MOV	R4, R0 \n"
"		STR	R8, [SP,#0x54] \n"
"		STR	R8, [SP,#0x4c] \n"
"		LDR	R0, [R6,#0x44] \n"
"		MOV	R11, #4 \n"
"		CMP	R0, #3 \n"
"		STREQ	R11, [R6,#0x44] \n"
"		LDR	R0, [R6,#0xB4] \n"
"		MOV	R9, #0 \n"
"		MOV	R7, #0 \n"
"		MOV	R5, #1 \n"
"		BLX	R0 \n"
"		LDR	R0, [R6,#0x44] \n"
"		CMP	R0, #6 \n"
"		BEQ	loc_FF985BE4 \n"
"		LDR	R1, [R6,#0xC] \n"
"		CMP	R1, #2 \n"
"		BNE	loc_FF985C04 \n"
"		CMP	R0, #5 \n"
"		BEQ	loc_FF985C7C \n"
"loc_FF985BE4: \n"
"		LDR	R0, =0xFF985124 \n"				// Movierecorder.c
"		MOV	R7, #1 \n"
"		MOV	R1, #0x7F0 \n"
"		BL	sub_FF81EB78 \n"				// DebugAssert
"		LDR	R0, [R6,#0x44] \n"
"		CMP	R0, #4 \n"
"		MOVNE	R5, #0 \n"
"		B	loc_FF985C0C \n"
"loc_FF985C04: \n"
"		CMP	R0, #4 \n"
"		BNE	loc_FF985C7C \n"
"loc_FF985C0C: \n"
"		LDRH	R0, [R6,#6] \n"
"		CMP	R0, #1 \n"
"		LDREQ	R1, =0x809 \n"
"		LDREQ	R0, =0xFF985124 \n"			// Movierecorder.c
"		BLEQ	sub_FF81EB78 \n"			// DebugAssert
"		LDRH	R0, [R6,#6] \n"
"		CMP	R0, #3 \n"
"		BNE	loc_FF985C40 \n"
"		LDR	R0, [R6,#0x6C] \n"
"		LDR	R1, [R6,#0xB8] \n"
"		BL	sub_FFBA189C \n"
"		CMP	R1, #0 \n"
"		MOVNE	R5, #0 \n"
"loc_FF985C40: \n"
"		LDR	R0, [R6,#0x44] \n"
"		CMP	R0, #6 \n"
"		CMPNE	R0, #1 \n"
"		CMPNE	R0, #3 \n"
"		BNE	loc_FF985C84 \n"
"		CMP	R7, #1 \n"
"		CMPEQ	R5, #0 \n"
"		BNE	loc_FF985C84 \n"
"		LDR	R0, [R6,#0x18] \n"
"		MOV	R1, #0x3E8 \n"
"		BL	sub_FF83A714 \n"			// eventproc_export_TakeSemaphore
"		CMP	R0, #9 \n"
"		BNE	loc_FF9860A4 \n"
"		MOV	R0, #0x90000 \n"
"		BL	sub_FF89D31C \n"			// eventproc_export_HardwareDefect
"loc_FF985C7C: \n"
"		ADD	SP, SP,	#0x64 \n"
"		LDMFD	SP!, {R4-R11,PC} \n"
"loc_FF985C84: \n"
"		CMP	R5, #1 \n"
"		MOV	R10, #1 \n"
"		BNE	loc_FF985CAC \n"
"		ADD	R3, SP,	#0x4c \n"
"		ADD	R2, SP,	#0x50 \n"
"		ADD	R1, SP,	#0x54 \n"
"		ADD	R0, SP,	#0x58 \n"
"		BL	sub_FFAF2BE4 \n"
"		MOVS	R9, R0 \n"
"		BNE	loc_FF985CC8 \n"
"loc_FF985CAC: \n"
"		LDR	R0, [R6,#0x34] \n"
"		CMP	R0, #1 \n"
"		BNE	loc_FF985E24 \n"
"		LDR	R0, [R6,#0x6C] \n"
"		LDR	R1, [R6,#0x48] \n"
"		CMP	R0, R1 \n"
"		BCC	loc_FF985E24 \n"
"loc_FF985CC8: \n"
"		CMP	R9, #0x80000001 \n"
"		STREQ	R11, [R6,#0x70] \n"
"		BEQ	loc_FF985D00 \n"
"		CMP	R9, #0x80000003 \n"
"		STREQ	R10, [R6,#0x70] \n"
"		BEQ	loc_FF985D00 \n"
"		CMP	R9, #0x80000005 \n"
"		MOVEQ	R0, #2 \n"
"		BEQ	loc_FF985CFC \n"
"		CMP	R9, #0x80000007 \n"
"		STRNE	R8, [R6,#0x70] \n"
"		BNE	loc_FF985D00 \n"
"		MOV	R0, #3 \n"
"loc_FF985CFC: \n"
"		STR	R0, [R6,#0x70] \n"
"loc_FF985D00: \n"
"		LDR	R0, [R6,#0xC] \n"
"		CMP	R0, #2 \n"
"		BNE	loc_FF985D68 \n"
"		MOV	R1, #0 \n"
"		LDR	R0, =0xFF985B78 \n"
"		BL	sub_FFAAD410 \n"
"		LDR	R2, [R6,#0x64] \n"
"		ADD	R3, SP,	#0x5c \n"
"		STRD	R2, [SP,#0x28] \n"
"		MOV	R2, #0x18 \n"
"		ADD	R1, SP,	#0x34 \n"
"		ADD	R0, SP,	#0x10 \n"
"		BL	sub_FFB9F23C \n"
"		LDR	R1, [R6,#0x84] \n"
"		LDR	R2, [R6,#0x88] \n"
"		MVN     R3, #1 \n"
"		ADD	R0, SP,	#0x60 \n"
"		STMEA	SP, {R0-R3} \n"
"		LDR	R0, =0xB4618 \n"
"		MOV	R3, #0 \n"
"		MOV	R2, #0 \n"
"		MOV	R1, #0x40 \n"
"		BL	sub_FFAAD368 \n"
"		B	loc_FF985DBC \n"
"loc_FF985D60: \n"
"		MOV	R1, #1 \n"
"		B	loc_FF986030 \n"
"loc_FF985D68: \n"
"		BL	loc_FF986A38 \n"
"		LDR	R2, [R6,#0x64] \n"
"		ADD	R3, SP,	#0x5c \n"
"		MVN     R1, #1 \n"
"		MOV	R0, #0 \n"
"		ADD	R5, SP,	#0x1c \n"
"		STMIA	R5, {R0-R3} \n"
"		LDR	R3, [R4,#0x1C] \n"
"		LDR	R1, [R6,#0x84] \n"
"		LDR	R2, [R6,#0x88] \n"
"		ADD	R4, SP,	#0x0c \n"
"		ADD	R0, SP,	#0x60 \n"
"		STMIA	R4, {R0-R3} \n"
"		MOV	R3, #0 \n"
"		MOV	R1, #0x40 \n"
"		MOV	R2, #0 \n"
"		STMEA	SP, {R1-R3} \n"
"		LDR	R3, =0xB4618 \n"
"		MOV	R1, #0 \n"
"		MOV	R0, #0 \n"
"		BL	sub_FFAAC1D8 \n"
"loc_FF985DBC: \n"
"		LDR	R0, [R6,#0x18] \n"
"		LDR	R1, [R6,#0x60] \n"
"		BL	sub_FF83A714 \n"			// eventproc_export_TakeSemaphore
"		CMP	R0, #9 \n"
"		BEQ	loc_FF985D60 \n"
"		LDR	R0, [SP,#0x5c] \n"
"		CMP	R0, #0 \n"
"		BEQ	loc_FF985DE4 \n"
"loc_FF985DDC: \n"
"		MOV	R1, #1 \n"
"		B	loc_FF986048 \n"
"loc_FF985DE4: \n"
"		LDR	R0, [R6,#0xC] \n"
"		MOV	R4, #5 \n"
"		CMP	R0, #2 \n"
"		MOV	R0, #1 \n"
"		BNE	loc_FF985E10 \n"
"		BL	sub_FFAAD3D0 \n"
"		BL	sub_FFAAD3F8 \n"
"		STR	R4, [R6,#0x44] \n"
"		BL	loc_FF986A38 \n"
"		STR	R10, [R6,#0x44] \n"
"		B	loc_FF985E1C \n"
"loc_FF985E10: \n"
"		BL	sub_FFAAC28C \n"
"		BL	sub_FFAAC2EC \n"
"		STR	R4, [R6,#0x44] \n"
"loc_FF985E1C: \n"
"		STR	R8, [R6,#0x34] \n"
"		B	loc_FF985C7C \n"
"loc_FF985E24: \n"
"		CMP	R5, #1 \n"
"		BNE	loc_FF9860A4 \n"
"		STR	R10, [R6,#0x38] \n"
"		LDR	R0, [R6,#0x6C] \n"
"		LDR	R11, [R4,#0xC] \n"
"		CMP	R0, #0 \n"
"		LDRNE	R9, [SP,#0x58] \n"
"		LDRNE	R10, [SP,#0x54] \n"
"		BNE	loc_FF985F6C \n"
"		LDR	R0, [R6,#0xC] \n"
"		CMP	R0, #2 \n"
"		BNE	loc_FF985EC8 \n"
"		MOV	R1, #0 \n"
"		LDR	R0, =0xFF985B78 \n"
"		BL	sub_FFAAD410 \n"
"		LDR	R2, [R6,#0x64] \n"
"		ADD	R3, SP,	#0x5c \n"
"		STRD	R2, [SP,#0x28] \n"
"		MOV	R2, #0x18 \n"
"		ADD	R1, SP,	#0x34 \n"
"		ADD	R0, SP,	#0x10 \n"
"		BL	sub_FFB9F23C \n"
"		LDR	R1, [R6,#0x84] \n"
"		LDR	R2, [R6,#0x88] \n"
"		MVN     R3, #0 \n"
"		ADD	R0, SP,	#0x60 \n"
"		STMEA	SP, {R0-R3} \n"
"		LDR	R0, [SP,#0x58] \n"
"		LDR	R1, [SP,#0x54] \n"
"		LDR	R2, [SP,#0x50] \n"
"		LDR	R3, [SP,#0x4c] \n"
"		BL	sub_FFAAD368 \n"
"		LDR	R0, [R6,#0x18] \n"
"		LDR	R1, [R6,#0x60] \n"
"		BL	sub_FF83A714 \n"			// eventproc_export_TakeSemaphore
"		CMP	R0, #9 \n"
"		BEQ	loc_FF985D60 \n"
"		MOV	R1, #0 \n"
"		LDR	R0, =0xFF985B6C \n"
"		BL	sub_FFAAD410 \n"
"		B	loc_FF985F30 \n"
"loc_FF985EC8: \n"
"		LDR	R0, [R4,#0x20] \n"
"		LDR	R2, [R6,#0x64] \n"
"		ADD	R3, SP,	#0x5c \n"
"		MVN     R1, #0 \n"
"		ADD	R9, SP,	#0x1c \n"
"		STMIA	R9, {R0-R3} \n"
"		LDR	R3, [R4,#0x1C] \n"
"		LDR	R1, [R6,#0x84] \n"
"		LDR	R2, [R6,#0x88] \n"
"		ADD	R0, SP,	#0x60 \n"
"		ADD	R9, SP,	#0x0c \n"
"		STMIA	R9, {R0-R3} \n"
"		LDR	R1, [SP,#0x50] \n"
"		LDR	R2, [SP,#0x54] \n"
"		LDR	R3, [SP,#0x4c] \n"
"		STMFA	SP, {R1,R3} \n"
"		STR	R2, [SP,#0x0] \n"
"		LDMIB	R4, {R0,R1} \n"
"		LDR	R3, [SP,#0x58] \n"
"		MOV	R2, R11 \n"
"		BL	sub_FFAAC1D8 \n"
"		LDR	R0, [R6,#0x18] \n"
"		LDR	R1, [R6,#0x60] \n"
"		BL	sub_FF83A714 \n"			// eventproc_export_TakeSemaphore
"		CMP	R0, #9 \n"
"		BEQ	loc_FF985D60 \n"
"loc_FF985F30: \n"
"		LDR	R0, [SP,#0x5c] \n"
"		CMP	R0, #0 \n"
"		BNE	loc_FF985DDC \n"
"		LDR	R0, [R6,#0xC] \n"
"		CMP	R0, #2 \n"
"		MOV	R0, #1 \n"
"		BNE	loc_FF985F54 \n"
"		BL	sub_FFAAD3D0 \n"
"		B	loc_FF985F58 \n"
"loc_FF985F54: \n"
"		BL	sub_FFAAC28C \n"
"loc_FF985F58: \n"
"		LDR	R0, [SP,#0x60] \n"
"		LDR	R1, [SP,#0x58] \n"
"		ADD	R9, R1,	R0 \n"
"		LDR	R1, [SP,#0x54] \n"
"		SUB	R10, R1, R0 \n"
"loc_FF985F6C: \n"
"		LDR	R0, [R6,#0xC] \n"
"		LDR	R2, [R6,#0x64] \n"
"		CMP	R0, #2 \n"
"		ADD	R3, SP,	#0x5c \n"
"		BNE	loc_FF985FC0 \n"
"		STRD	R2, [SP,#0x28] \n"
"		MOV	R2, #0x18 \n"
"		ADD	R1, SP,	#0x34 \n"
"		ADD	R0, SP,	#0x10 \n"
"		BL	sub_FFB9F23C \n"
"		LDR	R1, [R6,#0x84] \n"
"		LDR	R2, [R6,#0x88] \n"
"		LDR	R3, [R6,#0x68] \n"
"		ADD	R0, SP,	#0x60 \n"
"		STMEA	SP, {R0-R3} \n"
"		LDR	R2, [SP,#0x50] \n"
"		LDR	R3, [SP,#0x4c] \n"
"		MOV	R1, R10 \n"
"		MOV	R0, R9 \n"
"		BL	sub_FFAAD368 \n"
"		B	loc_FF986018 \n"
"loc_FF985FC0: \n"
"		LDR	R1, [R6,#0x68] \n"
"		LDR	R0, [R4,#0x20] \n"
"		STR	R1, [SP,#0x20] \n"
"		STR	R0, [SP,#0x1c] \n"
"		STR	R2, [SP,#0x24] \n"
"		STR	R3, [SP,#0x28] \n"
"		LDR	R3, [R4,#0x1C] \n"
"		LDR	R1, [R6,#0x84] \n"
"		LDR	R2, [R6,#0x88] \n"
"		ADD	R0, SP,	#0x60 \n"
"		STR	R2, [SP,#0x14] \n"
"		LDR	R2, [SP,#0x50] \n"
"		STR	R1, [SP,#0x10] \n"
"		STR	R3, [SP,#0x18] \n"
"		LDR	R3, [SP,#0x4c] \n"
"		STR	R0, [SP,#0x0c] \n"
"		STMFA	SP, {R2,R3} \n"
"		STR	R10, [SP,#0x0] \n"
"		LDMIB	R4, {R0,R1} \n"
"		MOV	R3, R9 \n"
"		MOV	R2, R11 \n"
"		BL	sub_FFAAC1D8 \n"
"loc_FF986018: \n"
"		LDR	R0, [R6,#0x18] \n"
"		LDR	R1, [R6,#0x60] \n"
"		BL	sub_FF83A714 \n"			// eventproc_export_TakeSemaphore
"		CMP	R0, #9 \n"
"		BNE	loc_FF986038 \n"
"		MOV	R1, #0 \n"
"loc_FF986030: \n"
"		MOV	R0, #0x90000 \n"
"		B	loc_FF98604C \n"
"loc_FF986038: \n"
"		LDR	R0, [SP,#0x5c] \n"
"		CMP	R0, #0 \n"
"		BEQ	loc_FF986054 \n"
"		MOV	R1, #0 \n"
"loc_FF986048: \n"
"		MOV	R0, #0xA0000 \n"
"loc_FF98604C: \n"
"		BL	sub_FF985B0C \n"
"		B	loc_FF985C7C \n"
"loc_FF986054: \n"
"		LDR	R0, [R6,#0xC] \n"
"		CMP	R0, #2 \n"
"		MOV	R0, #0 \n"
"		BNE	loc_FF98606C \n"
"		BL	sub_FFAAD3D0 \n"
"		B	loc_FF986070 \n"
"loc_FF98606C: \n"
"		BL	sub_FFAAC28C \n"
"loc_FF986070: \n"
"		LDR	R0, [SP,#0x58] \n"
"		LDR	R1, [SP,#0x60] \n"
"		BL	sub_FFAF2E1C \n"
"		LDR	R0, [R6,#0x68] \n"

"		LDR	R3, =0x71B0 \n"				// 71b0
"		ADD	R1, R0,	#1 \n"
"		STR	R1, [R6,#0x68] \n"
"		STR	R3, [SP,#0x0] \n"
"		LDR	R0, [R6,#0x64] \n"
"		SUB	R3, R3,	#4 \n"				// 4
"		AND	R2, R0,	#0xFF \n"
"		LDR	R0, [SP,#0x60] \n"
"		BL	sub_FFAF0964 \n"

"		LDR R0, =0x71AC \n"				// added  (71b0 - 4)
"		BL		set_quality \n"			// added

"loc_FF9860A4: \n"
"		CMP	R5, #1 \n"
"		LDRNEH	R0, [R6,#6] \n"
"		CMPNE	R0, #3 \n"
"		BNE	loc_FF985C7C \n"
"		LDR	R0, [R6,#0x6C] \n"
"		ADD	R0, R0,	#1 \n"
"		STR	R0, [R6,#0x6C] \n"
"		LDRH	R1, [R6,#6] \n"
"		CMP	R1, #3 \n"
"		LDRNE	R1, [R6,#0x54] \n"
"		LDREQ	R1, =0x3E9 \n"
"		MUL	R0, R1,	R0 \n"
"		LDREQ	R1, =0x1770 \n"
"		LDRNE	R1, [R6,#0x50] \n"
"		BL	sub_FFBA189C \n"
"		MOV	R4, R0 \n"
"		BL	sub_FFAF3198 \n"
"		LDR	R0, [R6,#0x8C] \n"
"		CMP	R0, R4 \n"
"		BNE	loc_FF986100 \n"
"		LDR	R0, [R6,#0x3C] \n"
"		CMP	R0, #1 \n"
"		BNE	loc_FF986114 \n"
"loc_FF986100: \n"
"		LDR	R1, [R6,#0x98] \n"
"		MOV	R0, R4 \n"
"		BLX	R1 \n"
"		STR	R4, [R6,#0x8C] \n"
"		STR	R8, [R6,#0x3C] \n"
"loc_FF986114: \n"
"		STR	R8, [R6,#0x38] \n"
"		B	loc_FF985C7C \n"

"loc_FF986A38: \n"
"		B	sub_FF986A38 \n"
	);
}
