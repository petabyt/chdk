#include "lolevel.h"
#include "platform.h"
#include "core.h"

const char * const new_sa = &_end;

void taskCreateHook(int *p)
{
	p-=16;
	if (p[0]==0xFF821ACC)  p[0]=(int)mykbd_task; // OK // WORK!
	if (p[0]==0xFF859DF8)  p[0]=(int)movie_record_task; // OK // WORK!
	if (p[0]==0xFF85DE30)  p[0]=(int)capt_seq_task; // OK
	if (p[0]==0xFF87719C)  p[0]=(int)init_file_modules_task; // OK // WORK!
	if (p[0]==0xFF8B478C)  p[0]=(int)exp_drv_task; // OK
}

void CreateTask_spytask()
{
	_CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}

void boot()
{
	long *canon_data_src = (void*)0xFFB15AA4;
	long *canon_data_dst = (void*)0x1900;
	long canon_data_len = 0xEFE4 - 0x1900; // data_end - data_start
	long *canon_bss_start = (void*)0xEFE4; // just after data
	long canon_bss_len = 0xCBA08 - 0xEFE4;

	long i;

	// enable caches and write buffer
	asm volatile (
		"MRC     p15, 0, R0,c1,c0\n"
		"ORR     R0, R0, #0x1000\n"
		"ORR     R0, R0, #4\n"
		"ORR     R0, R0, #1\n"
		"MCR     p15, 0, R0,c1,c0\n"
		:::"r0"
		);

	for(i=0;i<canon_data_len/4;i++)
		canon_data_dst[i]=canon_data_src[i];

	for(i=0;i<canon_bss_len/4;i++)
		canon_bss_start[i]=0;

	// Captain Hook
	*(int*)0x1930 = (int)taskCreateHook;

	// jump to init-sequence that follows the data-copy-routine
	asm volatile ("B  sub_FF8101A4_my\n");
}

void __attribute__((naked,noinline)) sub_FF8101A4_my() // OK
{
	asm volatile (
		"LDR     R0, =0xFF81021C\n" // exception handler code
		"MOV     R1, #0\n"
		"LDR     R3, =0xFF810254\n"

		"loc_FF8101B0:\n"
		"CMP     R0, R3\n" // load exception vector
		"LDRCC   R2, [R0],#4\n"
		"STRCC   R2, [R1],#4\n"
		"BCC     loc_FF8101B0\n"
		"LDR     R0, =0xFF810254\n"
		"MOV     R1, #0x4B0\n"
		"LDR     R3, =0xFF810468\n"

		"loc_FF8101CC:\n"
		"CMP     R0, R3\n" // copy IRQ handler to ITCM starting at 0x4b0, 532 bytes up to 0x6C4
		"LDRCC   R2, [R0],#4\n"
		"STRCC   R2, [R1],#4\n"
		"BCC     loc_FF8101CC\n"
		"MOV     R0, #0xD2\n"
		"MSR     CPSR_cxsf, R0\n" // set CPSR mode = IRQ, ints disabled
		"MOV     SP, #0x1000\n" // irq mode SP
		"MOV     R0, #0xD3\n"
		"MSR     CPSR_cxsf, R0\n" // set CPSR mode = Super, ints disabled
		"MOV     SP, #0x1000\n" // super mode SP
        //"LDR     R0, loc_FF810210\n"
		"LDR     R0, =0x6C4\n" // +
		"LDR     R2, =0xEEEEEEEE\n"
		"MOV     R3, #0x1000\n"

		"loc_FF810200:\n"
		"CMP     R0, R3\n" // clear ITCM 0x6C4-end with EEEEEEEE
		"STRCC   R2, [R0],#4\n"
		"BCC     loc_FF810200\n"
		"BL      sub_FF810FA0_my\n" //------------->
		);
}

void __attribute__((naked,noinline)) sub_FF810FA0_my() // OK
{
	asm volatile (
		"STR     LR, [SP,#-4]!\n"
		"SUB     SP, SP, #0x74\n"
		"MOV     R0, SP\n"
		"MOV     R1, #0x74\n"
		"BL      sub_FFAA6FAC\n"
		"MOV     R0, #0x53000\n"
		"STR     R0, [SP,#0x74-0x70]\n"
//		"LDR     R0, =0xCBA08\n"
		"LDR     R0, =new_sa\n" // +
		"LDR     R0, [R0]\n" // +
		"LDR     R2, =0x279C00\n"
		"LDR     R1, =0x272968\n"
		"STR     R0, [SP,#0x74-0x6C]\n"
		"SUB     R0, R1, R0\n"
		"ADD     R3, SP, #0x74-0x68\n"
		"STR     R2, [SP,#0x74-0x74]\n"
		"STMIA   R3, {R0-R2}\n"
		"MOV     R0, #0x22\n"
		"STR     R0, [SP,#0x74-0x5C]\n"
		"MOV     R0, #0x68\n"
		"STR     R0, [SP,#0x74-0x58]\n"
		"LDR     R0, =0x19B\n"
		"MOV     R1, #0x64\n"
		"STRD    R0, [SP,#0x74-0x54]\n"
		"MOV     R0, #0x78\n"
		"STRD    R0, [SP,#0x74-0x4C]\n"
		"MOV     R0, #0\n"
		"STR     R0, [SP,#0x74-0x44]\n"
		"STR     R0, [SP,#0x74-0x40]\n"
		"MOV     R0, #0x10\n"
		"STR     R0, [SP,#0x74-0x18]\n"
		"MOV     R0, #0x800\n"
		"STR     R0, [SP,#0x74-0x14]\n"
		"MOV     R0, #0xA0\n"
		"STR     R0, [SP,#0x74-0x10]\n"
		"MOV     R0, #0x280\n"
		"STR     R0, [SP,#0x74-0xC]\n"
//		"LDR     R1, =0xFF814DA4\n"
		"LDR     R1, =uHwSetup_my\n" //------------->
		"MOV     R0, SP\n"
		"MOV     R2, #0\n"
		"BL      sub_FF812D58\n"
		"ADD     SP, SP, #0x74\n"
		"LDR     PC, [SP],#4\n"
		);
}

// Extracted method: uHwSetup (FF814DA4)
void __attribute__((naked,noinline)) uHwSetup_my() // OK
{
	asm volatile (
		"STMFD   SP!, {R4,LR}\n"
		"BL      sub_FF81094C\n"
		"BL      sub_FF819664\n"
		"CMP     R0, #0\n"
		"LDRLT   R0, =0xFF814EB8\n" // "dmSetup"
		"BLLT    sub_FF814E98\n"
		"BL      sub_FF8149C8\n"
		"CMP     R0, #0\n"
		"LDRLT   R0, =0xFF814EC0\n" // "termDriverInit"
		"BLLT    sub_FF814E98\n"
		"LDR     R0, =0xFF814ED0\n" // "/_term"
		"BL      sub_FF814AB4\n"
		"CMP     R0, #0\n"
		"LDRLT   R0, =0xFF814ED8\n" // "termDeviceCreate"
		"BLLT    sub_FF814E98\n"
		"LDR     R0, =0xFF814ED0\n" // "/_term"
		"BL      sub_FF813564\n"
		"CMP     R0, #0\n"
		"LDRLT   R0, =0xFF814EEC\n" // "stdioSetup"
		"BLLT    sub_FF814E98\n"
		"BL      sub_FF8191EC\n"
		"CMP     R0, #0\n"
		"LDRLT   R0, =0xFF814EF8\n" // "stdlibSetup"
		"BLLT    sub_FF814E98\n"
		"BL      sub_FF8114B8\n"
		"CMP     R0, #0\n"
		"LDRLT   R0, =0xFF814F04\n" // "armlib_setup"
		"BLLT    sub_FF814E98\n"
		"LDMFD   SP!, {R4,LR}\n"
		"B       taskcreate_Startup_my\n" //------------->
		);
}

// Extracted method: taskcreate_Startup (FF81CCBC)
void __attribute__((naked,noinline)) taskcreate_Startup_my() // OK
{
	asm volatile (
		"STMFD   SP!, {R3,LR}\n"
		"BL      sub_FF821BEC\n" // j_nullsub_214
		"BL      sub_FF829EDC\n"
		"CMP     R0, #0\n"
		"BNE     loc_FF81CCEC\n"
		"BL      sub_FF821BE8\n"
		"CMP     R0, #0\n"
		"BNE     loc_FF81CCEC\n"
		"LDR     R1, =0xC0220000\n"
		"MOV     R0, #0x44\n"
		"STR     R0, [R4,#0x4C]\n"

		"loc_FF81CCE8:\n"
		"B       loc_FF81CCE8\n"

		"loc_FF81CCEC:\n"
		"BL      sub_FF821BF4\n"
		"BL      sub_FF821BF0\n"
		"BL      sub_FF828264\n"
		"LDR     R1, =0x2CE000\n"
		"MOV     R0, #0\n"
		"BL      sub_FF8284AC\n"
		"BL      sub_FF828458\n" // LOCATION: KerSys.c:548
		"MOV     R3, #0\n"
		"STR     R3, [SP,#0x8-0x8]\n"
//		"ADR     R3, 0xFF81CC60\n" // task_Startup
		"LDR     R3, =task_Startup_my\n" //------------->
		"MOV     R2, #0\n"
		"MOV     R1, #0x19\n"
		"LDR     R0, =0xFF81CD34\n" // "Startup"
		"BL      sub_FF81B818\n" // eventproc_export_CreateTask
		"MOV     R0, #0\n"
		"LDMFD   SP!, {R12,PC}\n"
		);
}

// Extracted method: task_Startup (FF81CC60) // OK
void __attribute__((naked,noinline)) task_Startup_my()
{
	asm volatile (
		"STMFD   SP!, {R4,LR}\n"
		"BL      sub_FF81516C\n" // taskcreate_ClockSave
		"BL      sub_FF822D50\n"
		"BL      sub_FF81FDF0\n"
		"BL      sub_FF829F1C\n"
		"BL      sub_FF82A0E4\n"
//		"BL      sub_FF829FA4\n" // StartDiskBoot
		"BL      CreateTask_spytask\n" // +
		"BL      sub_FF82A298\n"
		"BL      sub_FF82A134\n"
		"BL      sub_FF8277A4\n"
		"BL      sub_FF82A29C\n"
		"BL      sub_FF821B00\n" // taskcreate_PhySw
		"BL      sub_FF824CB4\n" // task_ShootSeqTask
		"BL      sub_FF82A2B4\n"
		"BL      sub_FF81FB10\n" // nullsub_2
		"BL      sub_FF820FBC\n"
		"BL      sub_FF829CA4\n" // taskcreate_Bye
		"BL      sub_FF821630\n"
		"BL      sub_FF820EAC\n" // taskcreate_TempCheck
		"BL      sub_FF82ABFC\n"
		"BL      sub_FF820E68\n"
		"LDMFD   SP!, {R4,PC}\n"
		"BL      sub_FF815070\n" // LOCATION: ClkEnabler.c:144
		);
}

//Extracted method: task_InitFileModules (FF87719C)
void __attribute__((naked,noinline)) init_file_modules_task() // OK
{
	asm volatile (
		"STMFD   SP!, {R4-R6,LR}\n"
		"BL      sub_FF86D668\n"
		"LDR     R5, =0x5006\n"
		"MOVS    R4, R0\n"
		"MOVNE   R1, #0\n"
		"MOVNE   R0, R5\n"
		"BLNE    sub_FF872FAC\n" // PostLogicalEventToUI
//		"BL      sub_FF86D694\n"
		"BL      sub_FF86D694_my\n" //------------->
		"BL      core_spytask_can_start\n" // + safe to start spytask
		"CMP     R4, #0\n"
		"MOVEQ   R0, R5\n"
		"LDMEQFD SP!, {R4-R6,LR}\n"
		"MOVEQ   R1, #0\n"
		"BEQ     sub_FF872FAC\n" // PostLogicalEventToUI
		"LDMFD   SP!, {R4-R6,PC}\n"
		);
} 

void __attribute__((naked,noinline)) sub_FF86D694_my() // OK
{
	asm volatile (
		"STMFD   SP!, {R4,LR}\n"
//		"BL      sub_FF84ECF4\n"
		"BL      sub_FF84ECF4_my\n" //------------->
		"LDR     R4, =0x57A8\n"
		"LDR     R0, [R4,#4]\n"
		"CMP     R0, #0\n"
		"BNE     loc_FF86D6C4\n"
		"BL      sub_FF87FBB0\n"
		"BL      sub_FF902FEC\n"
		"BL      sub_FF87FBB0\n"
		"BL      sub_FF84C6E4\n"
		"BL      sub_FF87FBC0\n"
		"BL      sub_FF9030B8\n"

		"loc_FF86D6C4:\n"
		"MOV     R0, #1\n"
		"STR     R0, [R4]\n"
		"LDMFD   SP!, {R4,PC}\n"
		);
} 

void __attribute__((naked,noinline)) sub_FF84ECF4_my() // OK
{
	asm volatile (
		"STMFD   SP!, {R4-R6,LR}\n"
		"MOV     R6, #0\n"
		"MOV     R0, R6\n"
		"BL      sub_FF84E7B4\n"
		"LDR     R4, =0x11750\n"
		"MOV     R5, #0\n"
		"LDR     R0, [R4,#0x38]\n"
		"BL      sub_FF84F1E8\n"
		"CMP     R0, #0\n"
		"LDREQ   R0, =0x29AC\n"
		"STREQ   R5, [R0,#0x10]\n"
		"STREQ   R5, [R0,#0x14]\n"
		"STREQ   R5, [R0,#0x18]\n"
		"MOV     R0, R6\n"
		"BL      sub_FF84E7F4\n" // LOCATION: Mounter.c:0
		"MOV     R0, R6\n"
//		"BL      sub_FF84EB30"
		"BL      sub_FF84EB30_my\n" //------------->
		"MOV     R5, R0\n"
		"MOV     R0, R6\n"
		"BL      sub_FF84EB9C\n" // LOCATION: Mounter.c:8
		"LDR     R1, [R4,#0x3C]\n"
		"AND     R2, R5, R0\n"
		"CMP     R1, #0\n"
		"MOV     R0, #0\n"
		"MOVEQ   R0, #0x80000001\n"
		"BEQ     loc_FF84ED88\n"
		"LDR     R3, [R4,#0x2C]\n"
		"CMP     R3, #2\n"
		"MOVEQ   R0, #4\n"
		"CMP     R1, #5\n"
		"ORRNE   R0, R0, #1\n"
		"BICEQ   R0, R0, #1\n"
		"CMP     R2, #0\n"
		"BICEQ   R0, R0, #2\n"
		"ORREQ   R0, R0, #0x80000000\n"
		"BICNE   R0, R0, #0x80000000\n"
		"ORRNE   R0, R0, #2\n"

		"loc_FF84ED88:\n"
		"STR     R0, [R4,#0x40]\n"
		"LDMFD   SP!, {R4-R6,PC}\n"
		);
}

void __attribute__((naked,noinline)) sub_FF84EB30_my() // OK
{
	asm volatile (
		"STMFD   SP!, {R4-R6,LR}\n"
		"LDR     R5, =0x29AC\n"
		"MOV     R6, R0\n"
		"LDR     R0, [R5,#0x14]\n"
		"CMP     R0, #0\n"
		"MOVNE   R0, #1\n"
		"LDMNEFD SP!, {R4-R6,PC}\n"
		"MOV     R0, #0x17\n"
		"MUL     R1, R0, R6\n"
		"LDR     R0, =0x11750\n"
		"ADD     R4, R0, R1,LSL#2\n"
		"LDR     R0, [R4,#0x38]\n"
		"MOV     R1, R6\n"
//		"BL      sub_FF84E8C0\n" // LOCATION: Mounter.c:884
		"BL      sub_FF84E8C0_my\n" //------------->
		"CMP     R0, #0\n"
		"LDMEQFD SP!, {R4-R6,PC}\n"
		"LDR     R0, [R4,#0x38]\n"
		"MOV     R1, R6\n"
		"BL      sub_FF84EA28\n" // LOCATION: Mounter.c:0
		"CMP     R0, #0\n"
		"LDMEQFD SP!, {R4-R6,PC}\n"
		"MOV     R0, R6\n"
		"BL      sub_FF84E3BC\n"
		"CMP     R0, #0\n"
		"MOVNE   R1, #1\n"
		"STRNE   R1, [R5,#0x14]\n"
		"LDMFD   SP!, {R4-R6,PC}\n"
		);
}

void __attribute__((naked,noinline)) sub_FF84E8C0_my() // OK
{
	asm volatile (
		"STMFD   SP!, {R4-R8,LR}\n"
		"MOV     R8, R0\n"
		"MOV     R0, #0x17\n"
		"MUL     R1, R0, R1\n"
		"LDR     R0, =0x11750\n"
		"MOV     R6, #0\n"
		"ADD     R7, R0, R1,LSL#2\n"
		"LDR     R0, [R7,#0x3C]\n"
		"MOV     R5, #0\n"
		"CMP     R0, #6\n"
		"ADDLS   PC, PC, R0,LSL#2\n"
		"B       loc_FF84EA0C\n"

		"loc_FF84E8F0:\n"
		"B       loc_FF84E924\n"

		"loc_FF84E8F4:\n"
		"B       loc_FF84E90C\n"

		"loc_FF84E8F8:\n"
		"B       loc_FF84E90C\n"

		"loc_FF84E8FC:\n"
		"B       loc_FF84E90C\n"

		"loc_FF84E900:\n"
		"B       loc_FF84E90C\n"

		"loc_FF84E904:\n"
		"B       loc_FF84EA04\n"

		"loc_FF84E908:\n"
		"B       loc_FF84E90C\n"

		"loc_FF84E90C:\n"
		// jumptable FF858EAC entries 1-4,6
		"MOV     R2, #0\n"
		"MOV     R1, #0x200\n"
		"MOV     R0, #3\n"
		"BL      sub_FF867814\n"
		"MOVS    R4, R0\n"
		"BNE     loc_FF84E92C\n"

		"loc_FF84E924:\n"
		// jumptable FF858EAC entry 0
		"MOV     R0, #0\n"
		"LDMFD   SP!, {R4-R8,PC}\n"

		"loc_FF84E92C:\n"
		"LDR     R12, [R7,#0x4C]\n"
		"MOV     R3, R4\n"
		"MOV     R2, #1\n"
		"MOV     R1, #0\n"
		"MOV     R0, R8\n"
		"BLX     R12\n"
		"CMP     R0, #1\n"
		"BNE     loc_FF84E958\n"
		"MOV     R0, #3\n"
		"BL      sub_FF867954\n" // LOCATION: ExMemMan.c:0
		"B       loc_FF84E924\n"

		"loc_FF84E958:\n"
		"MOV     R0, R8\n"
		"BL      sub_FF920814\n"

		"MOV   R1, R4\n"           //  pointer to MBR in R1
		"BL    mbr_read_dryos\n"   //  total sectors count in R0 before and after call

		// Start of DataGhost's FAT32 autodetection code
		// Policy: If there is a partition which has type W95 FAT32, use the first one of those for image storage
		// According to the code below, we can use R1, R2, R3 and R12.
		// LR wasn't really used anywhere but for storing a part of the partition signature. This is the only thing
		// that won't work with an offset, but since we can load from LR+offset into LR, we can use this to do that :)
		"MOV     R12, R4\n"                    // Copy the MBR start address so we have something to work with
		"MOV     LR, R4\n"                     // Save old offset for MBR signature
		"MOV     R1, #1\n"                     // Note the current partition number
		"B       dg_sd_fat32_enter\n"          // We actually need to check the first partition as well, no increments yet!

		"dg_sd_fat32:\n"
		"CMP     R1, #4\n"                     // Did we already see the 4th partition?
		"BEQ     dg_sd_fat32_end\n"            // Yes, break. We didn't find anything, so don't change anything.
		"ADD     R12, R12, #0x10\n"            // Second partition
		"ADD     R1, R1, #1\n"                 // Second partition for the loop

		"dg_sd_fat32_enter:\n"
		"LDRB    R2, [R12, #0x1BE]\n"          // Partition status
		"LDRB    R3, [R12, #0x1C2]\n"          // Partition type (FAT32 = 0xB)
		"CMP     R3, #0xB\n"                   // Is this a FAT32 partition?
		"CMPNE   R3, #0xC\n"                   // Not 0xB, is it 0xC (FAT32 LBA) then?
		"BNE     dg_sd_fat32\n"                // No, it isn't. Loop again.
		"CMP     R2, #0x00\n"                  // It is, check the validity of the partition type
		"CMPNE   R2, #0x80\n"
		"BNE     dg_sd_fat32\n"                // Invalid, go to next partition
		// This partition is valid, it's the first one, bingo!
		"MOV     R4, R12\n"                    // Move the new MBR offset for the partition detection.

		"dg_sd_fat32_end:\n"
		// End of DataGhost's FAT32 autodetection code

		"LDRB    R1, [R4,#0x1C9]\n"
		"LDRB    R3, [R4,#0x1C8]\n"
		"LDRB    R12, [R4,#0x1CC]\n"
		"MOV     R1, R1,LSL#24\n"
		"ORR     R1, R1, R3,LSL#16\n"
		"LDRB    R3, [R4,#0x1C7]\n"
		"LDRB    R2, [R4,#0x1BE]\n"
		//"LDRB    LR, [R4,#0x1FF]\n" // -
		"ORR     R1, R1, R3,LSL#8\n"
		"LDRB    R3, [R4,#0x1C6]\n"
		"CMP     R2, #0\n"
		"CMPNE   R2, #0x80\n"
		"ORR     R1, R1, R3\n"
		"LDRB    R3, [R4,#0x1CD]\n"
		"MOV     R3, R3,LSL#24\n"
		"ORR     R3, R3, R12,LSL#16\n"
		"LDRB    R12, [R4,#0x1CB]\n"
		"ORR     R3, R3, R12,LSL#8\n"
		"LDRB    R12, [R4,#0x1CA]\n"
		"ORR     R3, R3, R12\n"
		//"LDRB    R12, [R4,#0x1FE]\n" // -
		"LDRB    R12, [LR,#0x1FE]\n" // +
		"LDRB    LR, [LR,#0x1FF]\n" // +
		"MOV     R4, #0\n"
		"BNE     loc_FF84E9E0\n"
		"CMP     R0, R1\n"
		"BCC     loc_FF84E9E0\n"
		"ADD     R2, R1, R3\n"
		"CMP     R2, R0\n"
		"CMPLS   R12, #0x55\n"
		"CMPEQ   LR, #0xAA\n"
		"MOVEQ   R6, R1\n"
		"MOVEQ   R5, R3\n"
		"MOVEQ   R4, #1\n"

		"loc_FF84E9E0:\n"
		"MOV     R0, #3\n"
		"BL      sub_FF867954\n" // LOCATION: ExMemMan.c:0
		"CMP     R4, #0\n"
		"BNE     loc_FF84EA18\n"
		"MOV     R6, #0\n"
		"MOV     R0, R8\n"
		"BL      sub_FF920814\n"
		"MOV     R5, R0\n"
		"B       loc_FF84EA18\n"

		"loc_FF84EA04:\n"
		// jumptable FF858EAC entry 5
		"MOV     R5, #0x40\n"
		"B       loc_FF84EA18\n"

		"loc_FF84EA0C:\n"
		// jumptable FF858EAC default entry
		"LDR     R1, =0x374\n"
		"LDR     R0, =0xFF858E78\n" // "Mounter.c"
		"BL      _DebugAssert\n"

		"loc_FF84EA18:\n"
		"STR     R6, [R7,#0x44]!\n"
		"MOV     R0, #1\n"
		"STR     R5, [R7,#4]\n"
		"LDMFD   SP!, {R4-R8,PC}\n"
		);
}

