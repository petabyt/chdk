#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;

long def_table1[9]= {0x2000,0x38D,0x788,0x5800,0x9C5,0x14B8,0x10000,0x1C6A,0x3C45};    // ???
long def_table2[9]= {0x1CCD,-0x2E1,-0x579,0x4F33,-0x7EB,-0xF0C,0xE666,-0x170A,-0x2BC6};    // ???

long table1[9], table2[9];

void change_video_tables(int a, int b) {
    int i;
    for(i=0; i<9; i++) {
        table1[i]=(def_table1[i]*a)/b;
        table2[i]=(def_table2[i]*a)/b;
    }
}

//long CompressionRateTable[]={0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};   // from SD800
long CompressionRateTable[]= {0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};  // ??? ROM:FF986318

void __attribute__((naked,noinline)) movie_record_task() {
    asm volatile(
		"STMFD	SP!, {R4,LR}\n"
		"SUB	SP, SP,	#4\n"
		"MOV	R4, SP\n"
		"B	loc_FF9497E4\n"
 
"loc_FF949734:\n"
		"LDR	R3, =0x740C0\n"
		"LDR	R2, [R3]\n"
		"CMP	R2, #0\n"
		"BNE	loc_FF9497D0\n"	
		"SUB	R3, R12, #1\n"
		"CMP	R3, #0xA\n" 
		"LDRLS	PC, [PC,R3,LSL#2]\n" 
		"B	loc_FF9497D0\n"	

		".long loc_FF949780\n"	
		".long loc_FF949788\n"
		".long loc_FF9497A0\n"
		".long loc_FF9497A8\n"
		".long loc_FF9497B0\n"
		".long loc_FF949790\n"
		".long loc_FF9497B8\n"
		".long loc_FF949798\n"
		".long loc_FF9497D0\n"
		".long loc_FF9497C8\n"
		".long loc_FF9497C0\n"

"loc_FF949780:\n"
		"BL	sub_FF949864\n"
		"B	loc_FF9497CC\n"

"loc_FF949788:\n"
        "BL      unlock_optical_zoom\n"   // + like SD800
		"BL	sub_FF949A98\n"	
		"B	loc_FF9497CC\n"

"loc_FF949790:\n"
		"BL	sub_FF949F50\n"
		//"BL	sub_FF949F50_my\n"	;
		"B	loc_FF9497CC\n"


"loc_FF949798:\n"
		"BL	sub_FF94A3A4\n"	
		"B	loc_FF9497CC\n"


"loc_FF9497A0:\n"
		"BL	sub_FF94A1C8\n"
		"B	loc_FF9497CC\n"

"loc_FF9497A8:\n"
		"BL	sub_FF94A5B0\n"
		"B	loc_FF9497CC\n"

"loc_FF9497B0:\n"
		"BL	sub_FF94A7C8\n"
		"B	loc_FF9497CC\n"

"loc_FF9497B8:\n"
		"BL	sub_FF94A464\n"
		"B	loc_FF9497CC\n"

"loc_FF9497C0:\n"
		"BL	sub_FF94A544\n"
		"B	loc_FF9497CC\n"

"loc_FF9497C8:\n"
		"BL	sub_FF94A218\n"

"loc_FF9497CC:\n"
		"LDR	R1, [SP]\n"

"loc_FF9497D0:\n"
		"LDR	R3, =0x73FF0\n"
		"MOV	R2, #0\n"
		"STR	R2, [R1]\n"
		"LDR	R0, [R3]\n"
		"BL	sub_FF8207A0\n" //PostMessageQueue

"loc_FF9497E4:\n"				
		"LDR	R3, =0x73FEC\n"
		"MOV	R1, R4\n"
		"LDR	R0, [R3]\n"
		"MOV	R2, #0\n"
		"BL		sub_FF820388\n" //ReceiveMessageQueue
		"LDR	R0, [SP]\n"
		"LDR	R12, [R0]\n"
		"CMP	R12, #0xC\n" 
		"MOV	R1, R0\n"
		"BNE	loc_FF949734\n"
		"LDR	R3, =0x73FE4\n"
		"LDR	R0, [R3]\n"
		"BL		sub_FF82115C\n" //GiveSemaphore
		"BL		sub_FF821924\n" //ExitTask

		"ADD	SP, SP,	#4\n"
		"LDMFD	SP!, {R4,PC}\n"
 );
}