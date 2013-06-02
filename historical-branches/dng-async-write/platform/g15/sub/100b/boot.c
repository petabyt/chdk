#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

// Forward declarations
extern volatile int jogdial_stopped;
void JogDial_task_my(void);

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_RotaryEncoder();
extern void task_MovieRecord();
extern void task_ExpDrv();

/*----------------------------------------------------------------------
	boot()

	Main entry point for the CHDK code
-----------------------------------------------------------------------*/

void __attribute__((naked,noinline)) boot() {
    asm volatile (
      "    LDR     R1, =0xC0410000 \n" 
      "    MOV     R0, #0 \n" 
      "    STR     R0, [R1] \n" 
      "    MOV     R1, #0x78 \n" 
      "    MCR     p15, 0, R1, c1, c0 \n" 
      "    MOV     R1, #0 \n" 
      "    MCR     p15, 0, R1, c7, c10, 4 \n" 
      "    MCR     p15, 0, R1, c7, c5 \n" 
      "    MCR     p15, 0, R1, c7, c6 \n" 
      "    MOV     R0, #0x3D \n" 
      "    MCR     p15, 0, R0, c6, c0 \n" 
      "    MOV     R0, #0xC000002F \n" 
      "    MCR     p15, 0, R0, c6, c1 \n" 
      "    MOV     R0, #0x37 \n" 
      "    MCR     p15, 0, R0, c6, c2 \n" 
      "    MOV     R0, #0x40000037 \n" 
      "    MCR     p15, 0, R0, c6, c3 \n" 
      "    MOV     R0, #0x80000017 \n" 
      "    MCR     p15, 0, R0, c6, c4 \n" 
      "    LDR     R0, =0xFF00002F \n" 
      "    MCR     p15, 0, R0, c6, c5 \n" 
      "    LDR     R0, =0xD000002B \n" 
      "    MCR     p15, 0, R0, c6, c7 \n" 
      "    MOV     R0, #0x34 \n" 
      "    MCR     p15, 0, R0, c2, c0 \n" 
      "    MOV     R0, #0x34 \n" 
      "    MCR     p15, 0, R0, c2, c0, 1 \n" 
      "    MOV     R0, #0x34 \n" 
      "    MCR     p15, 0, R0, c3, c0 \n" 
      "    LDR     R0, =0x33333330 \n" 
      "    MCR     p15, 0, R0, c5, c0, 2 \n" 
      "    LDR     R0, =0x33333330 \n" 
      "    MCR     p15, 0, R0, c5, c0, 3 \n" 
      "    MRC     p15, 0, R0, c1, c0 \n" 
      "    ORR     R0, R0, #0x1000 \n" 
      "    ORR     R0, R0, #4 \n" 
      "    ORR     R0, R0, #1 \n" 
      "    MCR     p15, 0, R0, c1, c0 \n" 
      "    MOV     R1, #0x80000006 \n" 
      "    MCR     p15, 0, R1, c9, c1 \n" 
      "    MOV     R1, #6 \n" 
      "    MCR     p15, 0, R1, c9, c1, 1 \n" 
      "    MRC     p15, 0, R1, c1, c0 \n" 
      "    ORR     R1, R1, #0x50000 \n" 
      "    MCR     p15, 0, R1, c1, c0 \n" 
      "    LDR     R2, =0xC0200000 \n" 
      "    MOV     R1, #1 \n" 
      "    STR     R1, [R2, #0x10C] \n" 
      "    MOV     R1, #0xFF \n" 
      "    STR     R1, [R2, #0xC] \n" 
      "    STR     R1, [R2, #0x1C] \n" 
      "    STR     R1, [R2, #0x2C] \n" 
      "    STR     R1, [R2, #0x3C] \n" 
      "    STR     R1, [R2, #0x4C] \n" 
      "    STR     R1, [R2, #0x5C] \n" 
      "    STR     R1, [R2, #0x6C] \n" 
      "    STR     R1, [R2, #0x7C] \n" 
      "    STR     R1, [R2, #0x8C] \n" 
      "    STR     R1, [R2, #0x9C] \n" 
      "    STR     R1, [R2, #0xAC] \n" 
      "    STR     R1, [R2, #0xBC] \n" 
      "    STR     R1, [R2, #0xCC] \n" 
      "    STR     R1, [R2, #0xDC] \n" 
      "    STR     R1, [R2, #0xEC] \n" 
      "    STR     R1, [R2, #0xFC] \n" 
      "    LDR     R1, =0xC0400008 \n" 
      "    LDR     R2, =0x430005 \n" 
      "    STR     R2, [R1] \n" 
      "    MOV     R1, #1 \n" 
      "    LDR     R2, =0xC0243100 \n" 
      "    STR     R2, [R1] \n" 
      "    LDR     R2, =0xC0242010 \n" 
      "    LDR     R1, [R2] \n" 
      "    ORR     R1, R1, #1 \n" 
      "    STR     R1, [R2] \n" 
      "    LDR     R0, =0xFF745BC0 \n" 
      "    LDR     R1, =0x685000 \n" 
      "    LDR     R3, =0x695374 \n" 
"loc_FF000144:\n"
      "    CMP     R1, R3 \n" 
      "    LDRCC   R2, [R0], #4 \n" 
      "    STRCC   R2, [R1], #4 \n" 
      "    BCC     loc_FF000144 \n" 
      "    LDR     R0, =0xFF7309FC \n" 
      "    LDR     R1, =0x1900 \n" 
      "    LDR     R3, =0x16AC4 \n" 
"loc_FF000160:\n"
      "    CMP     R1, R3 \n" 
      "    LDRCC   R2, [R0], #4 \n" 
      "    STRCC   R2, [R1], #4 \n" 
      "    BCC     loc_FF000160 \n" 
      "    LDR     R1, =0x18B824 \n" //MEMISOSTART
      "    MOV     R2, #0 \n" 
"loc_FF000178:\n"
      "    CMP     R3, R1 \n" 
      "    STRCC   R2, [R3], #4 \n" 
      "    BCC     loc_FF000178 \n" 
		/* Install task hooks via 0x193x is not possible with this new dryos version
		   So the below call patches the taskcreate functions in RAM to install our
		   hook -- ERR99
		*/
		"BL      HookIntoTaskCreateFunktion\n"
//      "    B       sub_FF00038C \n" 
      "    B       sub_FF00038C_my \n" 
    );
}

/* ATTENTION: This function does not save any registers,
              the calling functions saves&restores the used registers
*/
void __attribute__((naked,noinline)) code_copy() {
    asm volatile (
"copy_loop:\n" // Copy patch code to RAM location
        "LDR     R3, [R0], #4\n"
        "STR     R3, [R1], #4\n"
        "SUBS    R2, R2, #1\n"
        "BNE     copy_loop\n"
		"BX      LR\n"
		);
}

/* ERR99: PATCH the TASK CREATE functions in RAM to install our hooks.
   To catch all TaskCreate calls (need edto install our own task functions),
   it is necessary to patch to different TaskCreate functions in RAM. 
 */

void __attribute__((naked,noinline)) HookIntoTaskCreateFunktion() {

    asm volatile (


		"STMFD   SP!, {R0-R3,LR}\n" // Save all register which are used below
		/* Install HOOK #1 */
		"LDR     R0, =PatchCodeHook1\n" // R0 = Start adr. of our hook code call (SRC)
		"LDR     R1, =0x68AF04\n"	     // Get start adress of function to patch (DST)
		"MOV     R2, #(PatchCodeHook1End-PatchCodeHook1)/4\n" // WORDs to copy (lenght of patch bytes/4)
		"BL      code_copy\n"

		/* Install HOOK #2 */
		"LDR     R0, =PatchCodeHook2\n" // Get start adr. of our hook code call (SRC)
		"LDR     R1, =0x68AB8C\n"	// Get start adress of function to patch (DST) (_CreateTask)
		"MOV     R2, #(PatchCodeHook2End-PatchCodeHook2)/4\n" // WORDs to copy (lenght of patch bytes/4)
		"BL      code_copy\n"

		"LDMFD   SP!, {R0-R3,PC}\n" // Restore all used registers

		/* Our hook code payload for HOOK #1*/
"PatchCodeHook1:\n"
		"ldr PC,[PC,#-0x4]\n"	// Do jump to absolute adress TaskHookFnc1
		".long TaskHookFnc1\n"
"PatchCodeHook1End:\n"
		/* Our hook code payload for HOOK #2*/
"PatchCodeHook2:\n"
		"ldr PC,[PC,#-0x4]\n"  // Do jump to absolute adress TaskHookFnc2
		".long TaskHookFnc2\n"
"PatchCodeHook2End:\n"
	 );
}

/* Task HOOK function #1. Called if TaskCreate is called. */
void __attribute__((naked,noinline)) TaskHookFnc1() {
    asm volatile (

	"STMFD   SP!, {R0-R1}\n"
	//R3 = Pointer to task function to create

	/*** INSTALL capt_seq_task() hook ***/
	"LDR     R0, =task_CaptSeq\n"	// DryOS original code function ptr.
	"LDR     R1, =capt_seq_task\n"	// our task function base ptr.
	"CMP     R0, R3\n"	       // is the given taskptr.  equal to our searched function?
	"MOVEQ   R3, R1\n"        // if so, overwrite original task pointer in R12 with our task (R1)
	"BEQ     exitHook\n"       // below compares not necessary if this check has found something.

	/*** INSTALL exp_drv_task() hook ***/
	"LDR     R0, =task_ExpDrv\n"
	"LDR     R1, =exp_drv_task\n"
	"CMP     R0, R3\n"
	"MOVEQ   R3, R1\n"
	"BEQ     exitHook\n"

	/*** INSTALL JogDial() hook ***/
	"LDR     R0, =task_RotaryEncoder\n"
	"LDR     R1, =JogDial_task_my\n"
	"CMP     R0, R3\n"
	"MOVEQ   R3, R1\n"
	"BEQ     exitHook\n"

	/*** INSTALL movie_record_task() hook ***/
	"LDR     R0, =task_MovieRecord\n"
	"LDR     R1, =movie_record_task\n"
	"CMP     R0, R3\n"
	"MOVEQ   R3, R1\n"

"exitHook:\n" // restore overwritten registers
	"LDMFD   SP!, {R0-R1}\n"

    // how to find the Original Task create function:
    // 1) find original TaskHookFnc2
    // 2) go to the caller
    // 3) adjust addresses ROM->RAM
      "    STMFD   SP!, {R3-R5,LR} \n" 
      "    MOV     R12, R3 \n" 
      "    LDR     R3, [SP, #0x10] \n" 
      "    STR     R3, [SP] \n" 
      "    MOV     R3, R12 \n" 
      "   BL       _CreateTask \n" // FF74B74C−ff745bc0+685000
      "    CMP     R0, #5 \n" 
      "    MOV     R4, R0 \n" 
      "    MOVEQ   R1, #0x13 \n" 
      "    LDREQ   R0, =0x68B0F4 \n" // FF74BCB4−ff745bc0+685000
      "   BLEQ     _DebugAssert \n" // FF74BCC4−ff745bc0+685000
      "    MOV     R0, R4 \n" 
      "    LDMFD   SP!, {R3-R5,PC} \n" 
	);
}

void __attribute__((naked,noinline)) TaskHookFnc2() {
    asm volatile (

	"STMFD   SP!, {R0-R1}\n"
	//R3 = Pointer to task to create
	"LDR     R0, =task_InitFileModules\n"
	"LDR     R1, =init_file_modules_task\n"
	"CMP     R0, R3\n"
	"MOVEQ   R3, R1\n"

"exitHook2:\n"
	"LDMFD   SP!, {R0-R1}\n"

	// how to find the function:
    // 1) jump to ROM-to-be-copied-to-RAM address
    // 2) search for KerTask.c, you have your function
    // 3) adjust addresses ROM->RAM
      "    STMFD   SP!, {R1-R9,LR} \n" 
      "    MOV     R4, R0 \n" 
      "    LDR     R0, =0xFF0003FC \n" 
      "    LDR     R8, [SP, #0x28] \n" 
      "    LDR     R0, [R0] \n" 
      "    MOV     R6, R1 \n" 
      "    LDR     R0, [R0] \n" 
      "    MOV     R5, R2 \n" 
      "    CMP     R0, #0 \n" 
      "    MOV     R7, R3 \n" 
      "    MOVGT   R1, #0xA3 \n" 
      "    LDRGT   R0, =0x68ADB8 \n" // FF74B978−ff745bc0+685000
      "   BLGT     _DebugAssert \n"  // FF74BCC4−ff745bc0+685000
      "    LDR     R0, =0x1B08 \n" 
      "    CMP     R4, #0 \n" 
      "    LDREQ   R4, [R0] \n" 
      "    SUB     R1, R6, #1 \n" 
      "    CMP     R1, #0x20 \n" 
      "    BCS     loc_68ABE0 \n" // FF74B7A0−ff745bc0+685000
      "    CMP     R7, #0 \n" 
      "    BNE     loc_68ABE8 \n" // FF74B7A8−ff745bc0+685000
"loc_68ABE0:\n"
      "    MOV     R0, #3 \n" 
      "    LDMFD   SP!, {R1-R9,PC} \n" 
"loc_68ABE8:\n"
      "    CMP     R5, #0 \n" 
      "    LDREQ   R5, [R0, #4] \n" 
      "    MOV     R2, #0 \n" 
      "    STMFA   SP, {R2,R4} \n" 
      "    MOV     R3, R5 \n" 
      "    MOV     R1, R8 \n" 
      "    MOV     R0, R7 \n" 
      "    STR     R6, [SP] \n" 
      "    BL      sub_6855A4 \n" // FF746164−ff745bc0+685000
      "    CMN     R0, #1 \n" 
      "    MOV     R4, R0 \n" 
      "    BNE     loc_68AC2C \n" // FF74B7EC−ff745bc0+685000
      "    MOV     R1, #0xB9 \n" 
      "    LDR     R0, =0x68ADB8 \n" // FF74B978−ff745bc0+685000
      "   BL       _DebugAssert \n" // FF74BCC4−ff745bc0+685000
      "    MOV     R0, #5 \n" 
      "    LDMFD   SP!, {R1-R9,PC} \n" 
"loc_68AC2C:\n"
      "    MOV     R0, R4 \n" 
      "    BL      sub_6858AC \n" // FF74646C−ff745bc0+685000
      "    MOV     R0, R4, LSL #1 \n" 
      "    LDMFD   SP!, {R1-R9,PC} \n" 

	);
}

void __attribute__((naked,noinline)) sub_FF00038C_my() {

    if ( (*(int*)0xC022F48C & 0x800000) )
		*(int*)(0x2D30+0x4) = 0x2000000;  // Playmode "PhySwConfig.c" @ FF05DE7C
	else
		*(int*)(0x2D30+0x4) = 0x1000000; // Shootingmode

	asm volatile (
      "    LDR     R0, =0xFF000404 \n" 
      "    MOV     R1, #0 \n" 
      "    LDR     R3, =0xFF00043C \n" 
"loc_FF000398:\n"
      "    CMP     R0, R3 \n" 
      "    LDRCC   R2, [R0], #4 \n" 
      "    STRCC   R2, [R1], #4 \n" 
      "    BCC     loc_FF000398 \n" 
      "    LDR     R0, =0xFF00043C \n" 
      "    MOV     R1, #0x4B0 \n" 
      "    LDR     R3, =0xFF000624 \n" 
"loc_FF0003B4:\n"
      "    CMP     R0, R3 \n" 
      "    LDRCC   R2, [R0], #4 \n" 
      "    STRCC   R2, [R1], #4 \n" 
      "    BCC     loc_FF0003B4 \n" 
      "    MOV     R0, #0xD2 \n" 
      "    MSR     CPSR_cxsf, R0 \n" 
      "    MOV     SP, #0x1000 \n" 
      "    MOV     R0, #0xD3 \n" 
      "    MSR     CPSR_cxsf, R0 \n" 
      "    MOV     SP, #0x1000 \n" 
      "    LDR     R0, =0x698 \n" 
      "    LDR     R2, =0xEEEEEEEE \n" 
      "    MOV     R3, #0x1000 \n" 
"loc_FF0003E8:\n"
      "    CMP     R0, R3 \n" 
      "    STRCC   R2, [R0], #4 \n" 
      "    BCC     loc_FF0003E8 \n" 
//      "    BL      sub_FF00116C \n" 
      "    BL      sub_FF00116C_my \n" 
     );
}

void __attribute__((naked,noinline)) sub_FF00116C_my() {

     asm volatile (
      "    STR     LR, [SP, #-4]! \n" 
      "    SUB     SP, SP, #0x74 \n" 
      "    MOV     R1, #0x74 \n" 
      "    MOV     R0, SP \n" 
      "    BL      sub_690440 \n" 
      "    MOV     R0, #0x67000 \n" 
      "    STR     R0, [SP, #4] \n" 
#if defined(OPT_CHDK_IN_EXMEM)
               "LDR     R0, =0x18B824\n" // use original heap offset since CHDK is loaded in high memory
#else
               "LDR     R0, =new_sa\n"   // otherwise use patched value
               "LDR     R0, [R0]\n"      // 
#endif
      "    LDR     R2, =0x55D440 \n" 
      "    STR     R0, [SP, #8] \n" 
      "    SUB     R0, R2, R0 \n" 
      "    STR     R0, [SP, #0xC] \n" 
      "    MOV     R0, #0x22 \n" 
      "    STR     R0, [SP, #0x18] \n" 
      "    MOV     R0, #0x7C \n" 
      "    STR     R0, [SP, #0x1C] \n" 
      "    LDR     R1, =0x565C00 \n" 
      "    LDR     R0, =0x1CD \n" 
      "    STR     R1, [SP] \n" 
      "    STR     R0, [SP, #0x20] \n" 
      "    MOV     R0, #0x96 \n" 
      "    STR     R2, [SP, #0x10] \n" 
      "    STR     R1, [SP, #0x14] \n" 
      "    STR     R0, [SP, #0x24] \n" 
      "    STR     R0, [SP, #0x28] \n" 
      "    MOV     R0, #0x64 \n" 
      "    STR     R0, [SP, #0x2C] \n" 
      "    MOV     R0, #0 \n" 
      "    STR     R0, [SP, #0x30] \n" 
      "    STR     R0, [SP, #0x34] \n" 
      "    MOV     R0, #0x10 \n" 
      "    STR     R0, [SP, #0x5C] \n" 
      "    MOV     R0, #0x800 \n" 
      "    STR     R0, [SP, #0x60] \n" 
      "    MOV     R0, #0xA0 \n" 
      "    STR     R0, [SP, #0x64] \n" 
      "    MOV     R0, #0x280 \n" 
      "    STR     R0, [SP, #0x68] \n" 
      "    LDR     R1, =sub_FF00421C_my \n" // patched
      "    MOV     R2, #0 \n" 
      "    MOV     R0, SP \n" 
      "    BL      sub_6867E8 \n" 
      "    ADD     SP, SP, #0x74 \n" 
      "    LDR     PC, [SP], #4 \n" 
     );
}

void __attribute__((naked,noinline)) sub_FF00421C_my() {

	asm volatile (
      "    STMFD   SP!, {R4,LR} \n" 
      "    BL      sub_FF000AE8 \n" 
      "    BL      sub_FF005358 \n" 
      "    CMP     R0, #0 \n" 
      "    LDRLT   R0, =0xFF004330 \n" 
      "   BLLT     _err_init_task \n"
      "    BL      sub_FF003E54 \n" 
      "    CMP     R0, #0 \n" 
      "    LDRLT   R0, =0xFF004338 \n" 
      "   BLLT     _err_init_task \n"
      "    LDR     R0, =0xFF004348 \n" 
      "    BL      sub_FF003F3C \n" 
      "    CMP     R0, #0 \n" 
      "    LDRLT   R0, =0xFF004350 \n" 
      "   BLLT     _err_init_task \n"
      "    LDR     R0, =0xFF004348 \n" 
      "    BL      sub_FF00295C \n" 
      "    CMP     R0, #0 \n" 
      "    LDRLT   R0, =0xFF004364 \n" 
      "   BLLT     _err_init_task \n"
      "    BL      sub_FF004CF4 \n" 
      "    CMP     R0, #0 \n" 
      "    LDRLT   R0, =0xFF004370 \n" 
      "   BLLT     _err_init_task \n"
      "    BL      sub_FF00165C \n" 
      "    CMP     R0, #0 \n" 
      "    LDRLT   R0, =0xFF00437C \n" 
      "   BLLT     _err_init_task \n"
      "    LDMFD   SP!, {R4,LR} \n" 
      "    B	sub_FF00AE5C_my \n"		// patched
        );
};

void __attribute__((naked,noinline)) sub_FF00AE5C_my() {

	asm volatile (
      "    STMFD   SP!, {R3,LR} \n" 
      "    BL      sub_FF02213C \n" 
      "    CMP     R0, #0 \n" 
      "    BNE     loc_FF00AE7C \n" 
      "    BL      sub_FF01BBF4 \n" 
      "    CMP     R0, #0 \n" 
      "    MOVNE   R0, #1 \n" 
      "    BNE     loc_FF00AE80 \n" 
"loc_FF00AE7C:\n"
      "    MOV     R0, #0 \n" 
"loc_FF00AE80:\n"
      "    BL      sub_FF01A09C_my \n" // patched 
      "    CMP     R0, #0 \n" 
      "    BNE     loc_FF00AEA0 \n" 
      "    BL      sub_FF019458 \n" 
      "    LDR     R1, =0x83DC00 \n" 
      "    MOV     R0, #0x54 \n" 
      "    BL      sub_FF020704 \n" 
"loc_FF00AE9C:\n"
      "    B       loc_FF00AE9C \n" 
"loc_FF00AEA0:\n"
      "    BL      sub_68C314 \n" 
      "    LDR     R1, =0x5CE000 \n" 
      "    MOV     R0, #0 \n" 
      "    BL      sub_FF020500 \n" 
      "    BL      sub_68C52C \n" 
      "    MOV     R3, #0 \n" 
      "    STR     R3, [SP] \n" 
      //"    LDR     R3, =0xFF00ADF4 \n" 
      "    LDR     R3, =task_Startup_my \n"
      "    MOV     R2, #0 \n" 
      "    MOV     R1, #0x19 \n" 
      "    LDR     R0, =0xFF00AEE4 \n" 
      "   BL       _CreateTask \n"
      "    MOV     R0, #0 \n" 
      "    LDMFD   SP!, {R3,PC} \n" 
        );
};

void __attribute__((naked,noinline)) sub_FF01A09C_my() {

	asm volatile (
      "    STMFD   SP!, {R4-R6,LR} \n" 
      "    MOV     R6, R0 \n" 
      "    BL      sub_FF05DE74 \n" 
      "    MOV     R0, #0x4B \n" 
      "    BL      sub_FF05EA90 \n" 
      "    MOV     R4, #1 \n" 
      "    BIC     R5, R4, R0 \n" 
      "    MOV     R0, #0x4F \n" 
      "    BL      sub_FF05EA90 \n" 
      "    CMP     R6, #0 \n" 
      "    BIC     R4, R4, R0 \n" 
      "    BEQ     loc_FF01A0D4 \n" 
      "    ORRS    R0, R5, R4 \n" 
      "    LDMEQFD SP!, {R4-R6,PC} \n" 
"loc_FF01A0D4:\n"
      "    BL      sub_FF02213C \n" 
      "    MOV     R2, R0 \n" 
      "    MOV     R3, #0 \n" 
      "    MOV     R1, R4 \n" 
      "    MOV     R0, R5 \n" 
      //"    BL      sub_FF05DE7C \n" // disable startup checks
      "    BL      sub_FF05DE78 \n" 
      "    MOV     R0, #1 \n" 
      "    LDMFD   SP!, {R4-R6,PC} \n" 
     );
}



/*----------------------------------------------------------------------
	spytask
-----------------------------------------------------------------------*/
void spytask(long ua, long ub, long uc, long ud, long ue, long uf)
{
    core_spytask();
}

/*----------------------------------------------------------------------
	CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask()
{
	_CreateTask("SpyTask", 0x19, 0x2000, spytask, 0);
}

void __attribute__((naked,noinline)) task_Startup_my() {

	asm volatile (
      "    STMFD   SP!, {R4,LR} \n" 
      "    BL      sub_FF00485C \n" 
      "    BL      sub_FF01B218 \n" 
      "    BL      sub_FF0192C0 \n" 
      //"    BL      sub_FF022184 \n" // null sub
      "    BL      sub_FF022370 \n" 
      //"    BL      sub_FF022218 \n" // DISKBOOT.BIN
      "    BL      sub_FF0224D8 \n" 
      "    BL      sub_FF0226A4 \n" 
      //"    BL      sub_FF0224CC \n" // null sub
      "    BL      sub_FF0223A0 \n" 

      "    BL      sub_FF020434 \n"
      "    BL      sub_FF0226AC \n" 
      "    BL      CreateTask_spytask\n" // added
      //"    BL      sub_FF019F44 \n"  //taskcreate_PhySw\n"
      "    BL      taskcreatePhySw_my\n"  // we do this here rather than hook so we don't waste the original stack
      "    BL      sub_FF01DAE0 \n" 
      "    BL      sub_FF0226C4 \n" 
      "    BL      sub_FF016E50 \n" 
      "    BL      sub_FF018C28 \n" 
      "    BL      sub_FF021EFC \n" 
      "    BL      sub_FF019274 \n" 
      "    BL      sub_FF018BC4 \n" 
      "    BL      sub_FF0224D0 \n" 
      "    BL      sub_FF017B84 \n" 
      "    BL      sub_FF018B88 \n" 
      "    LDMFD   SP!, {R4,LR} \n" 
      "    B       sub_FF004998 \n"
     );
}

void __attribute__((naked,noinline)) taskcreatePhySw_my() {
	asm volatile (
      "    STMFD   SP!, {R3-R5,LR} \n" 
      "    LDR     R4, =0x1D64 \n" 
      "    LDR     R0, [R4, #4] \n" 
      "    CMP     R0, #0 \n" 
      "    BNE     loc_FF019F78 \n" 
      "    MOV     R3, #0 \n" 
      "    STR     R3, [SP] \n" 
      //"    LDR     R3, =0xFF019F10 \n" 
      "    LDR     R3, =mykbd_task\n" // task_PhySw
      //"    MOV     R2, #0x800 \n"
      "    MOV     R2, #0x2000 \n" // stack size for new task_PhySw so we don't have to do stack switch
      "    MOV     R1, #0x17 \n" 
      "    LDR     R0, =0xFF01A1EC \n" 
      "    BL      sub_68AF04 \n" 
      "    STR     R0, [R4, #4] \n" 
"loc_FF019F78:\n"
      "    BL      sub_FF05EEE0 \n" 
      "    BL      sub_FF0979BC \n" 
      "    BL      sub_FF01BB44 \n" 
      "    CMP     R0, #0 \n" 
      "    BNE     loc_FF019F98 \n" 
      "    LDR     R1, =0x3AC18 \n" 
      "    MOV     R0, #0 \n" 
      "    BL      sub_FF097928 \n" 
"loc_FF019F98:\n"
      "    LDMFD   SP!, {R3-R5,PC} \n" 
	);
}


///*----------------------------------------------------------------------
// original @ 0xff04a77c
void __attribute__((naked,noinline)) init_file_modules_task() {
 asm volatile(
      "    STMFD   SP!, {R4-R6,LR} \n" 
      "    BL      sub_FF099F34 \n" 
      "    LDR     R5, =0x5006 \n" 
      "    MOVS    R4, R0 \n" 
      "    MOVNE   R1, #0 \n" 
      "    MOVNE   R0, R5 \n" 
      "    BLNE     _PostLogicalEventToUI \n"
      "    BL      sub_FF099F60 \n" 
"BL      core_spytask_can_start\n"      // CHDK: Set "it's-safe-to-start" flag for spytask
      "    CMP     R4, #0 \n" 
      "    LDMNEFD SP!, {R4-R6,PC} \n" 
      "    MOV     R0, R5 \n" 
      "    LDMFD   SP!, {R4-R6,LR} \n" 
      "    MOV     R1, #0 \n" 
      "    B        _PostLogicalEventToUI \n"
 );
}

///*----------------------------------------------------------------------
// Pointer to stack location where jogdial task records previous and current
// jogdial positions
short *jog_position;

// original @ 0xFF05EBB4
void __attribute__((naked,noinline)) JogDial_task_my() {
 asm volatile(
      "    STMFD   SP!, {R4-R11,LR} \n" 
      "    SUB     SP, SP, #0x24 \n" 
      "    BL      sub_FF05EF4C \n" 
      "    LDR     R12, =0x2D54 \n" 
      "    LDR     R6, =0xFF4A0F0C \n" 
      "    MOV     R0, #0 \n" 

// Save pointer for kbd.c routine
" ADD R10, SP, #0x18 \n"
" LDR R9, =jog_position \n"
" STR R10, [R9] \n"

      "    ADD     R10, SP, #8 \n" 
      "    ADD     R9, SP, #0x10 \n" 
"loc_FF05EBD4:\n"
      "    ADD     R2, SP, #0x1C \n" 
      "    MOV     R1, #0 \n" 
      "    ADD     R4, R2, R0, LSL #1 \n" 
      "    ADD     R3, SP, #0x18 \n" 
      "    STRH    R1, [R4] \n" 
      "    ADD     R4, R3, R0, LSL #1 \n" 
      "    STRH    R1, [R4] \n" 
      "    STR     R1, [R9, R0, LSL #2] \n" 
      "    STR     R1, [R10, R0, LSL #2] \n" 
      "    ADD     R0, R0, #1 \n" 
      "    CMP     R0, #2 \n" 
      "    BLT     loc_FF05EBD4 \n" 

"loc_FF05EC04:\n"
      "    LDR     R0, =0x2D54 \n" 
      "    MOV     R2, #0 \n" 
      "    LDR     R0, [R0, #8] \n" 
      "    MOV     R1, SP \n" 
      "    BL      sub_0068BDE0 \n" 
      "    CMP     R0, #0 \n" 
      "    LDRNE   R1, =0x20B \n" 
      "    LDRNE   R0, =0xFF05EE64 \n" 
      "   BLNE     _DebugAssert \n"
      "    LDR     R0, [SP] \n" 
      "    AND     R4, R0, #0xFF \n" 
      "    AND     R0, R0, #0xFF00 \n" 
      "    CMP     R0, #0x100 \n" 
      "    BEQ     loc_FF05EC74 \n" 
      "    CMP     R0, #0x200 \n" 
      "    BEQ     loc_FF05ECAC \n" 
      "    CMP     R0, #0x300 \n" 
      "    BEQ     sub_FF05EEB0 \n" 
      "    CMP     R0, #0x400 \n" 
      "    BNE     loc_FF05EC04 \n" 
      "    CMP     R4, #0 \n" 
      "    LDRNE   R1, =0x285 \n" 
      "    LDRNE   R0, =0xFF05EE64 \n" 
      "   BLNE     _DebugAssert \n"
      "    RSB     R0, R4, R4, LSL #3 \n" 
      "    LDR     R0, [R6, R0, LSL #2] \n" 

"loc_FF05EC6C:\n"
      "    BL      sub_FF05EF30 \n" 
      "    B       loc_FF05EC04 \n" 

"loc_FF05EC74:\n"
//------------------  added code ---------------------
"labelA:\n"
                "LDR     R0, =jogdial_stopped\n"
                "LDR     R0, [R0]\n"
                "CMP     R0, #1\n"
                "BNE     labelB\n"
                "MOV     R0, #40\n"
                "BL      _SleepTask\n" //sleep
                "B       labelA\n"
"labelB:\n"
//------------------  original code ------------------
      "    LDR     R0, =0x2D64 \n" 
      "    LDR     R0, [R0, R4, LSL #2] \n" 
      "    BL      sub_FF020CF0 \n" 
      "    LDR     R2, =0xFF05EB00 \n" 
      "    ORR     R3, R4, #0x200 \n" 
      "    ADD     R1, R2, #0 \n" 
      "    MOV     R0, #0x28 \n" 
      "    BL      sub_FF020C0C \n" 
      "    TST     R0, #1 \n" 
      "    CMPNE   R0, #0x15 \n" 
      "    STR     R0, [R10, R4, LSL #2] \n" 
      "    BEQ     loc_FF05EC04 \n" 
      "    LDR     R1, =0x21D \n" 
      "    B       loc_FF05EE50 \n" 

"loc_FF05ECAC:\n"
      "    RSB     R5, R4, R4, LSL #3 \n" 
      "    LDR     R0, [R6, R5, LSL #2] \n" 
      "    LDR     R1, =0xC0240000 \n" 
      "    ADD     R0, R1, R0, LSL #8 \n" 
      "    LDR     R0, [R0, #0x104] \n" 
      "    MOV     R1, R0, ASR #0x10 \n" 
      "    ADD     R0, SP, #0x1C \n" 
      "    ADD     R11, R0, R4, LSL #1 \n" 
      "    ADD     R0, SP, #0x18 \n" 
      "    ADD     R0, R0, R4, LSL #1 \n" 
      "    STRH    R1, [R11] \n" 
      "    STR     R0, [SP, #0x20] \n" 
      "    LDRSH   R3, [R0] \n" 
      "    SUB     R2, R1, R3 \n" 
      "    CMP     R2, #0 \n" 
      "    BNE     loc_FF05ED30 \n" 
      "    LDR     R0, [R9, R4, LSL #2] \n" 
      "    CMP     R0, #0 \n" 
      "    BEQ     loc_FF05EE0C \n" 
      "    LDR     R7, =0x2D64 \n" 
      "    LDR     R0, [R7, R4, LSL #2] \n" 
      "    BL      sub_FF020CF0 \n" 
      "    LDR     R2, =0xFF05EB0C \n" 
      "    ORR     R3, R4, #0x300 \n" 
      "    ADD     R1, R2, #0 \n" 
      "    MOV     R0, #0x1F4 \n" 
      "    BL      sub_FF020C0C \n" 
      "    TST     R0, #1 \n" 
      "    CMPNE   R0, #0x15 \n" 
      "    STR     R0, [R7, R4, LSL #2] \n" 
      "    BEQ     loc_FF05EE0C \n" 
      "    LDR     R1, =0x236 \n" 
      "    B       loc_FF05EE04 \n" 

"loc_FF05ED30:\n"
      "    MOV     R0, R2 \n" 
      "    RSBLT   R0, R0, #0 \n" 
      "    MOVLE   R7, #0 \n" 
      "    MOVGT   R7, #1 \n" 
      "    CMP     R0, #0xFF \n" 
      "    BLS     loc_FF05ED6C \n" 
      "    LDR     R0, =0x7FFF \n" 
      "    CMP     R2, #0 \n" 
      "    SUBLE   R0, R0, R3 \n" 
      "    ADDLE   R0, R0, R1 \n" 
      "    SUBGT   R0, R0, R1 \n" 
      "    ADDGT   R0, R0, R3 \n" 
      "    MVN     R1, #0x8000 \n" 
      "    SUB     R0, R0, R1 \n" 
      "    EOR     R7, R7, #1 \n" 
"loc_FF05ED6C:\n"
      "    STR     R0, [SP, #4] \n" 
      "    LDR     R0, [R9, R4, LSL #2] \n" 
      "    CMP     R0, #0 \n" 
      "    ADDEQ   R0, R6, R5, LSL #2 \n" 
      "    LDREQ   R0, [R0, #8] \n" 
      "    BEQ     loc_FF05EDA4 \n" 
      "    ADD     R8, R6, R5, LSL #2 \n" 
      "    ADD     R1, R8, R7, LSL #2 \n" 
      "    LDR     R1, [R1, #0x10] \n" 
      "    CMP     R1, R0 \n" 
      "    BEQ     loc_FF05EDA8 \n" 
      "    LDR     R0, [R8, #0xC] \n" 
      "    BL      sub_FF019F9C \n" 
      "    LDR     R0, [R8, #8] \n" 

"loc_FF05EDA4:\n"
      "    BL      sub_FF019F9C \n" 
"loc_FF05EDA8:\n"
      "    ADD     R0, R6, R5, LSL #2 \n" 
      "    ADD     R7, R0, R7, LSL #2 \n" 
      "    LDR     R0, [R7, #0x10] \n" 
      "    LDR     R1, [SP, #4] \n" 
      "    BL      sub_FF019FAC \n" 
      "    LDR     R0, [R7, #0x10] \n" 
      "    LDR     R7, =0x2D64 \n" 
      "    STR     R0, [R9, R4, LSL #2] \n" 
      "    LDRH    R1, [R11] \n" 
      "    LDR     R0, [SP, #0x20] \n" 
      "    STRH    R1, [R0] \n" 
      "    LDR     R0, [R7, R4, LSL #2] \n" 
      "    BL      sub_FF020CF0 \n" 
      "    LDR     R2, =0xFF05EB0C \n" 
      "    ORR     R3, R4, #0x300 \n" 
      "    ADD     R1, R2, #0 \n" 
      "    MOV     R0, #0x1F4 \n" 
      "    BL      sub_FF020C0C \n" 
      "    TST     R0, #1 \n" 
      "    CMPNE   R0, #0x15 \n" 
      "    STR     R0, [R7, R4, LSL #2] \n" 
      "    BEQ     loc_FF05EE0C \n" 
      "    LDR     R1, =0x267 \n" 
"loc_FF05EE04:\n"
      "    LDR     R0, =0xFF05EE64 \n" 
      "   BL       _DebugAssert \n"

"loc_FF05EE0C:\n"
      "    ADD     R0, R6, R5, LSL #2 \n" 
      "    LDR     R0, [R0, #0x18] \n" 
      "    CMP     R0, #1 \n" 
      "    BNE     sub_FF05EEA8 \n" 
      "    LDR     R0, =0x2D54 \n" 
      "    LDR     R0, [R0, #0xC] \n" 
      "    CMP     R0, #0 \n" 
      "    BEQ     sub_FF05EEA8 \n" 
      "    LDR     R2, =0xFF05EB00 \n" 
      "    ORR     R3, R4, #0x400 \n" 
      "    ADD     R1, R2, #0 \n" 
      "    BL      sub_FF020C0C \n" 
      "    TST     R0, #1 \n" 
      "    CMPNE   R0, #0x15 \n" 
      "    STR     R0, [R10, R4, LSL #2] \n" 
      "    BEQ     loc_FF05EC04 \n" 
      "    LDR     R1, =0x26E \n" 
"loc_FF05EE50:\n"
      "    LDR     R0, =0xFF05EE64 \n" 
      "   BL       _DebugAssert \n"
      "    B       loc_FF05EC04 \n" 
);
}
