#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"
#include "core.h"
#include "callfunc.h"


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

extern unsigned _ExecuteEventProcedure(const char *name,...);
//extern unsigned _sprintf(char *stream, const char *format,...);

extern unsigned _LCDMsg_Create (unsigned, unsigned, unsigned);
extern void _LCDMsg_SetStr (unsigned, char * );
//extern long _VbattGet();


// code to support saving a romlog if started with some key combo
#ifdef BOOT_ROMLOG_SHORTCUT
void save_romlog2(void)
{
	unsigned args[4];
    args[0] = (unsigned)"SystemEventInit";
	call_func_ptr(_ExecuteEventProcedure,args,1);
		args[0] = (unsigned)"UI.CreatePublic";
		call_func_ptr(_ExecuteEventProcedure,args,1);
	args[0] = (unsigned)"System.Create";
	call_func_ptr(_ExecuteEventProcedure,args,1);
		args[0] = (unsigned)"Driver.Create";
		call_func_ptr(_ExecuteEventProcedure,args,1);

		args[0] = (unsigned)"GetLogToFile";
		args[1] = (unsigned)"A/ROMLOG.LOG";
		args[2] = 1;
		call_func_ptr(_ExecuteEventProcedure,args,3);

		args[0] = (unsigned)"BeepDrive";
		args[1] = (unsigned) 0x02;
		call_func_ptr(_ExecuteEventProcedure,args,2);

		 // *(int*)0xd20b0810  = 0x4d0002;	 // Orange Led = on

}


/*----------------------------------------------------------------------
    spytask  MY
-----------------------------------------------------------------------*/
void spytask_my(long ua, long ub, long uc, long ud, long ue, long uf)
{
    (void)ua; (void)ub; (void)uc; (void)ud; (void)ue; (void)uf;

	_SleepTask(2800);
	save_romlog2();

	while (1){
	_SleepTask(300);
	}
}
#endif // BOOT_ROMLOG_SHORTCUT

/*----------------------------------------------------------------------
    spytask
-----------------------------------------------------------------------*/
void spytask(long ua, long ub, long uc, long ud, long ue, long uf)
{
    (void)ua; (void)ub; (void)uc; (void)ud; (void)ue; (void)uf;
    core_spytask();
}


/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask()
{
    // workaround to avoid crashes on startup triggered by closing the battery cover or after attaching / removing the lens
    // see https://chdk.setepontos.com/index.php?topic=12542.msg145817#msg145817
	if ( *(int*)(0x9e78) & 0x00600000 )
    {
#ifdef BOOT_ROMLOG_SHORTCUT
		if (( *(int*)(0xD20BF4A0) & 0x00002000) == 0) _CreateTask("SpyTaskMY", 0x19, 0x2000, spytask_my, 0);
#endif
		_CreateTask("SpyTask", 0x19, 0x2000, spytask, 0);
    }
}

///*----------------------------------------------------------------------
// Pointer to stack location where jogdial task records previous and current
// jogdial positions
// short *jog_position;

/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/

/*************************************************************/
void __attribute__((naked,noinline)) boot() {
    asm volatile ( // 0xfc02000c
"       mov     r0, #0x4000\n"
"       mov     sp, r0\n"
"       bl      sub_fc02007e\n"
"       ldr     r2, =0xc0242010\n"
"       ldr     r1, [r2]\n"
"       orr.w   r1, r1, #1\n"
"       str     r1, [r2]\n"
"       ldr     r0, =0xfcc98870\n"
"       ldr     r1, =0x10e1000\n"
"       ldr     r3, =0x11074ac\n"
" loc_fc02002a:\n"
"       cmp     r1, r3\n"
"       itt cc\n"
"       ldrcc.w r2, [r0],#4\n"
"       strcc.w r2, [r1],#4\n"
"       bcc     loc_fc02002a\n"
"       ldr     r0, =0x10e1000\n"
"       ldr     r1, =0x264ac\n"
"       bl      sub_fc13019a\n"
"       ldr     r0, =0xfccbed1c\n"
"       ldr     r1, =0xbfe10800\n"
"       ldr     r3, =0xbfe17391\n"
" loc_fc020046:\n"
"       cmp     r1, r3\n"
"       itt cc\n"
"       ldrcc.w r2, [r0],#4\n"
"       strcc.w r2, [r1],#4\n"
"       bcc     loc_fc020046\n"
"       ldr     r0, =0xfcc50100\n"
"       ldr     r1, =0x8000\n"
"       ldr     r3, =0x50770\n"
" loc_fc02005a:\n"
"       cmp     r1, r3\n"
"       itt cc\n"
"       ldrcc.w r2, [r0],#4\n"
"       strcc.w r2, [r1],#4\n"
"       bcc     loc_fc02005a\n"

		// "mov.w     r3, #0x01\n" 			// Enable TIO
		// "ldr     r1, =0x00008000\n"		// Enable TIO
		// "str.w     r3, [r1]\n"				// Enable TIO

"       ldr     r3, =0x50770\n"
"       ldr     r1, =0x3a7cc8\n"
"       mov.w   r2, #0\n"
" loc_fc020070:\n"
"       cmp     r3, r1\n"
"       it cc\n"
"       strcc.w r2, [r3],#4\n"
"       bcc     loc_fc020070\n"

"       blx     patch_mzrm_sendmsg\n"

        // Install CreateTask patch
        "adr     r0, patch_CreateTask\n"    // Patch data
        "ldm     r0, {r1,r2}\n"             // Get two patch instructions
        "ldr     r0, =orig_CreateTask\n"    // Address to patch
        "bic     r0, #1\n"                  // clear thumb bit
        "stm     r0, {r1,r2}\n"             // Store patch instructions

		"b.w     sub_fc062f48_my\n" // continue

        "patch_CreateTask:\n"
        "ldr.w   pc, [pc,#0]\n"             // Do jump to absolute address CreateTask_my
        ".long   CreateTask_my + 1\n"           // has to be a thumb address
);
}

/*************************************************************/
/*
    Custom function called in mzrm_sendmsg via logging function pointer (normally disabled)
    Checks if called from function that is updating the Canon UI.
    Updates CHDK bitmap settings and sets flag to update CHDK UI.
*/
void __attribute__((naked,noinline))
debug_logging_my(char* fmt, ...)
{
    (void)fmt;  // unused parameter
    asm volatile (
            //LR = Return address
            "    ldr     r0, =mzrm_sendmsg_ret_adr\n"   // Is return address in mzrm_sendmsg function?
            "    cmp     r0, lr\n"
            "    beq     chk_msg_type\n"
            "exit_debug_logging_my:"
            "    bx      lr\n"

            "chk_msg_type:"
            // mzrm_sendmsg 'msg' value (2nd parameter, saved in r11)
            "    ldr     r1, [r11]\n"
            "    cmp     r1, 0x23\n"                    // message type XimrExe
            "    beq     do_ui_update\n"
            "    cmp     r1, 0x24\n"                    // message type XimrExeGain
            "    bne     exit_debug_logging_my\n"
            "do_ui_update:"
            "    ldr     r0, [r11, 0x0c]\n"             // address of Ximr context in 'msg'
            "    b       update_ui\n"
    );
}

/*
    Install and enable custom logging function for mzrm_sendmsg.
*/
void
patch_mzrm_sendmsg ()
{
    extern int debug_logging_flag;
    extern void (*debug_logging_ptr)(char* fmt, ...);

    // Each bit in debug_logging_flag enables logging in different areas of the firmware code - only set the bit required for mzrm logging.
    debug_logging_flag = 0x200;
    debug_logging_ptr = debug_logging_my;
}

/*************************************************************/
void __attribute__((naked,noinline)) CreateTask_my() {

//   *(int*)0xd20b0810  = 0x4d0002;
asm volatile (
"    push   {r0}\n"

/* "    push   {r1}\n"
"	ldr r0, =#0x4d0002\n"
"	ldr r1, =#0xd20b0810\n"    // beam address
"	str r0, [r1]\n"
"    pop    {r1}\n"
*/

//R3 = Pointer to task function to create

"    ldr     r0, =task_CaptSeq\n"       // DryOS original code function ptr.
"    cmp     r0, r3\n"                  // is the given taskptr equal to our searched function?
"    itt     eq\n"                      // EQ block
"    ldreq   r3, =capt_seq_task\n"      // if so replace with our task function base ptr.
"    orreq   r3, #1\n"                  // make sure it's a thumb address (may not be needed?)
"    beq     exitHook\n"                // below compares not necessary if this check has found something.


"    LDR     R0, =task_ExpDrv\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =exp_drv_task\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"

/*
"    LDR     R0, =task_DvlpSeq\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =developseq_task\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"
*/


"    LDR     R0, =task_FileWrite\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =filewritetask\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"

"    LDR     R0, =0xFC2623F1\n" // TskCocoa0
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =task_cocoa0\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"

"    LDR     R0, =task_MovieRecord\n"
"    CMP     R0, R3\n"
"    itt     eq\n"
"    LDREQ   R3, =movie_record_task\n"
"    orreq   r3, #1\n"
"    BEQ     exitHook\n"

"    ldr     r0, =task_InitFileModules\n"
"    cmp     r0, r3\n"
"    itt     eq\n"
"    ldreq   r3, =init_file_modules_task\n"
"    orreq   r3, #1\n"
"exitHook:\n"


// restore overwritten register(s)
"    pop    {r0}\n"
// Execute overwritten instructions from original code, then jump to firmware
"    stmdb   sp!, {r1, r2, r3, r4, r5, r6, r7, r8, r9, lr}\n"
"    mov     r4, r0\n"
"    ldr     r0, =0x8160\n"
"    ldr.w   pc, =(orig_CreateTask + 8) \n"  // Continue in firmware
".ltorg\n"
);
}

//fc04f194 ??????????????
void __attribute__((naked,noinline)) sub_fc062f48_my() {

    asm volatile (
    "push    {r4, lr}\n"
#if defined(CHDK_NOT_IN_CANON_HEAP)
"        ldr     r4, =0x3a7cc8\n"         // heap start, modify here
#else
    "ldr     r4, =new_sa\n"             // +
    "ldr     r4, [r4]\n"                // +
#endif
"        sub     sp, sp, #0x78\n"
"        ldr     r0, =0x74e000\n"
"        ldr     r1, =0xafd8c\n"
"        subs    r0, r0, r4\n"
"        cmp     r0, r1\n"
"        bcs     loc_fc062f5a\n"
"  loc_fc062f58:\n"
"        b       loc_fc062f58\n"
"  loc_fc062f5a:\n"
"        ldr     r1, =0x8074\n"
"        mov.w   r0, #0x80000\n"
"        str     r0, [r1]\n"
"        ldr     r1, =0x8078\n"
"        ldr     r0, =0x42a41000\n"
"        str     r0, [r1]\n"
"        ldr     r1, =0x807c\n"
"        ldr     r0, =0x42a43000\n"
"        str     r0, [r1]\n"
"        movs    r1, #0x78\n"
"        mov     r0, sp\n"
"        blx     sub_fc30243c\n"
"        ldr     r0, =0x68e000\n"
"        mov.w   r1, #0xc0000\n"
"        stmea.w sp, {r0,r1,r4}\n"
"        ldr     r1, =0x682274\n"
"        subs    r2, r1, r4\n"
"        strd.w  r2, r1, [sp,#0xc]\n"
"        str     r0, [sp,#0x14]\n"
"        movs    r0, #0x22\n"
"        str     r0, [sp,#0x18]\n"
"        movs    r0, #0x98\n"
"        str     r0, [sp,#0x1c]\n"
"        movw    r0, #0x24c\n"
"        str     r0, [sp,#0x20]\n"
"        movs    r0, #0xfa\n"
"        str     r0, [sp,#0x24]\n"
"        movs    r0, #0xe8\n"
"        str     r0, [sp,#0x28]\n"
"        movs    r0, #0x85\n"
"        str     r0, [sp,#0x2c]\n"
"        movs    r0, #0x40\n"
"        str     r0, [sp,#0x30]\n"
"        movs    r0, #4\n"
"        str     r0, [sp,#0x34]\n"
"        movs    r0, #0\n"
"        str     r0, [sp,#0x38]\n"
"        movs    r0, #0x10\n"
"        str     r0, [sp,#0x5c]\n"
"        movs    r2, #0\n"
"        lsls    r0, r0, #8\n"
"        str     r0, [sp,#0x60]\n"
"        ldr     r1, =sub_fc0630d9_my\n"
"        asrs    r0, r0, #4\n"
"        str     r0, [sp,#0x64]\n"
"        lsls    r0, r0, #5\n"
"        str     r0, [sp,#0x68]\n"
"        mov     r0, sp\n"
"        blx     sub_fc301ba0\n"
"        add     sp, sp, #0x78\n"
"        pop     {r4,pc}\n"
".ltorg\n"
    );
}

//fc0630d9
void __attribute__((naked,noinline)) sub_fc0630d9_my() {
    asm volatile (
"       push    {r4,lr}\n"
"       ldr     r4, =0xfc063180\n"
"       bl      sub_fc0643d4\n"
"       ldr     r0, =0x80ec\n"
"       ldr     r1, [r0]\n"
"       ldr     r0, =0x8074\n"
"       ldr     r0, [r0]\n"
"       adds    r0, #0x10\n"
"       cmp     r1, r0\n"
"       bcs     loc_fc0630f4\n"
"       ldr     r0, =0xfc063190\n"
"       bl      sub_fc06316a\n"
" loc_fc0630f4:\n"
"       bl      sub_fc130274\n"
"       ldr     r1, =0xbfe10000\n"
"       mov.w   r2, #0xeeeeeeee\n"
"       ldr     r3, =0xbfe10800\n"
" loc_fc063100:\n"
"       stmia   r1!, {r2}\n"
"       cmp     r1, r3\n"
"       bcc     loc_fc063100\n"
"       bl      sub_fc130286\n"
"       bl      sub_fc1edfbc\n"
"       cmp     r0, #0\n"
"       bge     loc_fc063118\n"
"       ldr     r0, =0xfc0631b0\n"
"       bl      sub_fc06316a\n"
" loc_fc063118:\n"
"       bl      sub_fc063964\n"
"       cmp     r0, #0\n"
"       bge     loc_fc063126\n"
"       ldr     r0, =0xfc0631b8\n"
"       bl      sub_fc06316a\n"
" loc_fc063126:\n"
"       mov     r0, r4\n"
"       bl      sub_fc0639f2\n"
"       cmp     r0, #0\n"
"       bge     loc_fc063136\n"
"       ldr     r0, =0xfc0631c8\n"
"       bl      sub_fc06316a\n"
" loc_fc063136:\n"
"       mov     r0, r4\n"
"       bl      sub_fc063314\n"
"       cmp     r0, #0\n"
"       bge     loc_fc063146\n"
"       ldr     r0, =0xfc0631dc\n"
"       bl      sub_fc06316a\n"
" loc_fc063146:\n"
"       bl      sub_fc063458\n"
"       cmp     r0, #0\n"
"       bge     loc_fc063154\n"
"       ldr     r0, =0xfc0631e8\n"
"       bl      sub_fc06316a\n"
" loc_fc063154:\n"
"       bl      sub_fc0665ac\n"
"       cmp     r0, #0\n"
"       bge     loc_fc063162\n"
"       ldr     r0, =0xfc0631f4\n"
"       bl      sub_fc06316a\n"
" loc_fc063162:\n"
"       pop.w   {r4,lr}\n"
"       b.w     sub_fc0634e2_my\n" // -> continue (taskcreate_startup)
".ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc0634e2_my() {
    asm volatile (
"       push    {r3,lr}\n"
"       bl      sub_fc0635fc\n"
"       bl      sub_fc13131c\n"
"       cbnz    r0, loc_fc0634f8\n"
"       bl      sub_fc07803e\n"
"       cbz     r0, loc_fc0634f8\n"
"       movs    r0, #1\n"
"       b       loc_fc0634fa\n"
" loc_fc0634f8:\n"
"       movs    r0, #0\n"
" loc_fc0634fa:\n"
"       bl      sub_fc083cc4\n"
"       cbnz    r0, loc_fc063506\n"
"       bl      sub_fc0635ea\n"
" loc_fc063504:\n"
"       b       loc_fc063504\n"
" loc_fc063506:\n"
"       blx     sub_fc301bf8\n"
"       ldr     r1, =0x74e000\n"
"       movs    r0, #0\n"
"       bl      sub_fc37a758\n"
"       blx     sub_fc301fdc\n"
"       movs    r3, #0\n"
"       str     r3, [sp]\n"
"       ldr     r3, =sub_fc06347d_my\n"
"       movs    r2, #0\n"
"       movs    r1, #0x19\n"
"       ldr     r0, =0xfc063534\n"
"       blx     sub_fc3021d4\n"
"       movs    r0, #0\n"
"       pop     {r3,pc}\n"
".ltorg\n"
    );
}

// task_Startup
void __attribute__((naked,noinline)) sub_fc06347d_my() {
    asm volatile (
"  push    {r4,lr}\n"
"  bl      sub_fc131030\n"
"  bl      sub_fc0635c8\n"
// "  bl      j_nullsub_20\n"
"  bl      sub_fc0f41f0\n"
//"  bl      sub_fc0637b2\n"  // - startdiskboot
"  bl  	   sub_010e16c8\n" // + Switch off SD power
"  bl      sub_fc36dfa6\n"
"  bl      sub_fc0f4348\n"
"  bl      sub_fc0638a4\n"
"  bl      sub_fc0636dc\n"
"  bl      sub_fc0f4222\n"
"  bl      sub_fc1ee770\n"
"  bl      sub_fc0f434e\n"
"  bl      CreateTask_spytask\n"  // +
"  bl      sub_fc083bea_my\n"     // -> taskcreate_physw
"  bl      sub_fc0a9870\n"
"  bl      sub_fc0f4364\n"
"  bl      sub_fc0d2610\n"
"  bl      sub_fc130de8\n"
"  bl      sub_fc1311da\n"
"  bl      sub_fc0f41a2\n"
"  bl      sub_fc130da4\n"
// "  bl      nullsub_9\n"
"  bl      sub_fc363020\n"
"  bl      sub_fc130d78\n"
// "	bl agent_orange\n"
"  pop.w   {r4,lr}\n"
//"  b.w     sub_fc131006\n" // - (not recognized automatically yet, transformed into ldr pc)
"ldr     pc, =0xfc131007\n"     // + thumb address must be used
".ltorg\n"
    );
}

//taskcreate_physw
void __attribute__((naked,noinline)) sub_fc083bea_my() {
    asm volatile (
"       push    {r3-r5,lr}\n"
"       bl      sub_fc0763a4\n"
"       bl      sub_fc077fbc\n"
"       cbnz    r0, loc_fc083bfa\n"
"       bl      sub_fc076348\n"
" loc_fc083bfa:\n"
"       ldr     r4, =0x82cc\n"
"       ldr     r0, [r4,#4]\n"
"       cmp     r0, #0\n"
"       bne     locret_fc083c16\n"
"       movs    r3, #0\n"
"       str     r3, [sp]\n"
"       ldr     r3, =mykbd_task\n" //=0xfc083bc5\n"
//"       ldr     r3, =0xfc083bc5\n" // -orig kbd_task
"       movs    r1, #0x17\n"
"       ldr     r0, =0xfc083f2c\n" // "PhySw"
"       movw    r2, #0x2000\n"	 // original value 0x800
"       blx     sub_fc3022e4\n"
"       str     r0, [r4,#4]\n"
" locret_fc083c16:\n"
"       pop     {r3-r5,pc}\n"
".ltorg\n"
    );
}

void __attribute__((naked,noinline)) init_file_modules_task() { //sub_FC0F79A0_my()
    asm volatile (
"       push    {r4-r6,lr}\n"
"       bl      sub_fc0f9dec\n"
"       movs    r4, r0\n"
"       movw    r5, #0x5006\n"
"       beq     loc_fc0f79b6\n"
"       movs    r1, #0\n"
"       mov     r0, r5\n"
"       bl      sub_fc37eba4\n"
" loc_fc0f79b6:\n"
"       bl      sub_fc0f9e16_my\n" // -> for multipartition
"    BL      core_spytask_can_start\n" // + CHDK: Set "it's-safe-to-start" flag for spytask
"       cmp     r4, #0\n"
"       bne     locret_fc0f79ca\n"
"       mov     r0, r5\n"
"       pop.w   {r4-r6,lr}\n"
"       movs    r1, #0\n"
"       b.w     sub_fc37eba4\n"
" locret_fc0f79ca:\n"
"       pop     {r4-r6,pc}\n"
".ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc0f9e16_my() {
    asm volatile(
// -s=0xfc0f9e17 -c=3 -jfw
"    movs    r0, #3\n"
"    push    {r4, lr}\n"
"    bl      sub_fc37a0f6_my\n" // ->
"    ldr     pc, =0xfc0f9e1f\n" // Continue in firmware
    );
}

void __attribute__((naked,noinline)) sub_fc37a0f6_my() {
    asm volatile(
// -s=0xfc37a0f7 -c=25 -jfw
"    push.w  {r4, r5, r6, r7, r8, lr}\n"
"    mov     r6, r0\n"
"    bl      sub_fc37a0c8\n"
"    ldr     r1, =0x000581f8\n"
"    mov     r5, r0\n"
"    add.w   r4, r1, r0, lsl #7\n"
"    ldr     r0, [r4, #0x6c]\n"
"    lsls    r0, r0, #0x1d\n"
"    bpl     loc_fc37a11c\n"
"    movw    r2, #0xa73\n"
"    ldr     r1, =0xfc379bb0\n" //  *"Mounter.c"
"    movs    r0, #0\n"
"    blx     sub_fc302434\n" // j_DebugAssert
"loc_fc37a11c:\n"
"    mov     r1, r6\n"
"    mov     r0, r5\n"
"    bl      sub_fc379a26\n"
"    ldr     r0, [r4, #0x38]\n"
"    bl      sub_fc37a63e\n"
"    cbnz    r0, loc_fc37a130\n"
"    movs    r0, #0\n"
"    str     r0, [r4, #0x6c]\n"
"loc_fc37a130:\n"
"    mov     r0, r5\n"
"    bl      sub_fc379a7e\n"
"    mov     r0, r5\n"
"    bl      sub_fc379cc6_my\n" // ->
"    ldr     pc, =0xfc37a13d\n" // Continue in firmware
    );
}

void __attribute__((naked,noinline)) sub_fc379cc6_my() {
    asm volatile(
// -s=0xfc379cc7 -c=10 -jfw
"    push    {r4, r5, r6, lr}\n"
"    mov     r5, r0\n"
"    ldr     r0, =0x000581f8\n"
"    add.w   r4, r0, r5, lsl #7\n"
"    ldr     r0, [r4, #0x6c]\n"
"    lsls    r0, r0, #0x1e\n"
"    bmi     sub_fc379cf8\n" //  return 0x1 // jump to FW
"    ldr     r0, [r4, #0x38]\n"
"    mov     r1, r5\n"
"    bl      sub_fc379adc_my\n" // ->
"    ldr     pc, =0xfc379cdf\n" // Continue in firmware
    );
}

void __attribute__((naked,noinline)) sub_fc379adc_my() {
    asm volatile(
// -s=0xfc379add -c=112
"    push.w  {r4, r5, r6, r7, r8, sb, sl, lr}\n"
"    mov     sl, r0\n"
"    ldr     r0, =0x000581f8\n"
"    mov.w   r8, #0\n"
"    add.w   r5, r0, r1, lsl #7\n"
"    mov     r6, r8\n"
"    mov     sb, r8\n"
"    ldr     r0, [r5, #0x3c]\n"
"    cmp     r0, #7\n"
"    bhs     loc_fc379bde\n"
"    tbb     [pc, r0]\n" // (jumptable r0 7 elements)
"branchtable_fc379afa:\n"
"    .byte((loc_fc379b12 - branchtable_fc379afa) / 2)\n" // (case 0)
"    .byte((loc_fc379b02 - branchtable_fc379afa) / 2)\n" // (case 1)
"    .byte((loc_fc379b02 - branchtable_fc379afa) / 2)\n" // (case 2)
"    .byte((loc_fc379b02 - branchtable_fc379afa) / 2)\n" // (case 3)
"    .byte((loc_fc379b02 - branchtable_fc379afa) / 2)\n" // (case 4)
"    .byte((loc_fc379bda - branchtable_fc379afa) / 2)\n" // (case 5)
"    .byte((loc_fc379b02 - branchtable_fc379afa) / 2)\n" // (case 6)
".align 1\n"
"loc_fc379b02:\n"
"    movs    r2, #0\n"
"    movw    r1, #0x200\n"
"    movs    r0, #2\n"
"    bl      _exmem_ualloc\n"
"    movs    r4, r0\n"
"    bne     loc_fc379b18\n"
"loc_fc379b12:\n"
"    movs    r0, #0\n"
"loc_fc379b14:\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, sl, pc}\n"
"loc_fc379b18:\n"
"    ldr     r7, [r5, #0x50]\n"
"    movs    r2, #1\n"
"    movs    r1, #0\n"
"    mov     r3, r4\n"
"    mov     r0, sl\n"
"    blx     r7\n"
"    cmp     r0, #1\n"
"    bne     loc_fc379b30\n"
"    movs    r0, #2\n"
"    bl      _exmem_ufree\n"
"    b       loc_fc379b12\n" //  return 0
"loc_fc379b30:\n"
"    ldr     r1, [r5, #0x64]\n"
"    mov     r0, sl\n"
"    blx     r1\n"

"    mov     r1, r4\n"              //  pointer to MBR in r1
"    bl      mbr_read_dryos\n"      //  total sectors count in r0 before and after call

// Start of DataGhost's FAT32 autodetection code (Digic6+ version by philmoz)
// Policy: If there is a partition which has type FAT32 or exFat, use the first one of those for image storage
// According to the code below, we can use r1, r2, r3 and r12.
// LR wasn't really used anywhere but for storing a part of the partition signature. This is the only thing
// that won't work with an offset, but since we can load from LR+offset into LR, we can use this to do that :)
"    mov     r7, r4\n"              // Copy the MBR start address so we have something to work with
"    mov     lr, r4\n"              // Save old offset for MBR signature
"    mov     r1, #1\n"              // Note the current partition number
"    b       dg_sd_fat32_enter\n"   // We actually need to check the first partition as well, no increments yet!
"dg_sd_fat32:\n"
"    cmp     r1, #4\n"              // Did we already see the 4th partition?
"    beq     dg_sd_fat32_end\n"     // Yes, break. We didn't find anything, so don't change anything.
"    add     r7, r7, #0x10\n"       // Second partition
"    add     r1, r1, #1\n"          // Second partition for the loop
"dg_sd_fat32_enter:\n"
"    ldrb.w  r2, [r7, #0x1BE]\n"    // Partition status
"    ldrb.w  r3, [r7, #0x1C2]\n"    // Partition type (FAT32 = 0xB)
"    cmp     r3, #0xB\n"            // Is this a FAT32 partition?
"    beq     dg_sd_valid\n"
"    cmp     r3, #0xC\n"            // Not 0xB, is it 0xC (FAT32 LBA) then?
"    beq     dg_sd_valid\n"
"    cmp     r3, #0x7\n"            // exFat?
"    bne     dg_sd_fat32\n"         // No, it isn't. Loop again.
"dg_sd_valid:\n"
"    cmp     r2, #0x00\n"           // It is, check the validity of the partition type
"    beq     dg_sd_ok\n"
"    cmp     r2, #0x80\n"
"    bne     dg_sd_fat32\n"         // Invalid, go to next partition
"dg_sd_ok:\n"
                                    // This partition is valid, it's the first one, bingo!
"    mov     r4, r7\n"              // Move the new MBR offset for the partition detection.

"dg_sd_fat32_end:\n"
// End of DataGhost's FAT32 autodetection code

"    ldr.w   r2, [r4, #0x1c7]\n"
"    mov     r1, r0\n"
"    ldrb.w  r0, [r4, #0x1c6]\n"
"    ldr.w   r7, [r4, #0x1cb]\n"
"    orr.w   r0, r0, r2, lsl #8\n"
"    ldrb.w  r2, [r4, #0x1ca]\n"
"    ldrb.w  r3, [r4, #0x1be]\n"
"    orr.w   r2, r2, r7, lsl #8\n"
//"    ldrb.w  r7, [r4, #0x1fe]\n" // replaced below
//"    ldrb.w  r4, [r4, #0x1ff]\n" // replaced below
"    ldrb.w  r7, [lr, #0x1fe]\n"    // replace instructions above
"    ldrb.w  r4, [lr, #0x1ff]\n"    // replace instructions above
"    cbz     r3, loc_fc379b62\n"
"    cmp     r3, #0x80\n"
"    bne     loc_fc379b74\n"
"loc_fc379b62:\n"
"    cmp     r1, r0\n"
"    blo     loc_fc379b74\n"
"    adds    r3, r0, r2\n"
"    cmp     r3, r1\n"
"    bhi     loc_fc379b74\n"
"    cmp     r7, #0x55\n"
"    bne     loc_fc379b74\n"
"    cmp     r4, #0xaa\n"
"    beq     loc_fc379bbc\n"
"loc_fc379b74:\n"
"    mov     r4, sb\n"
"    b       loc_fc379bc2\n"
".ltorg\n" // canon fw had literal pool here
"loc_fc379bbc:\n"
"    movs    r4, #1\n"
"    mov     r8, r0\n"
"    mov     r6, r2\n"
"loc_fc379bc2:\n"
"    movs    r0, #2\n"
"    bl      _exmem_ufree\n"
"    cbnz    r4, loc_fc379bec\n"
"    ldr     r1, [r5, #0x64]\n"
"    mov.w   r8, #0\n"
"    mov     r0, sl\n"
"    blx     r1\n"
"    mov     r6, r0\n"
"    b       loc_fc379bec\n"
"    b       loc_fc379bde\n"
"loc_fc379bda:\n"
"    movs    r6, #0x40\n"
"    b       loc_fc379bec\n"
"loc_fc379bde:\n"
"    movw    r2, #0x688\n"
"    ldr     r1, =0xfc379bb0\n" //  *"Mounter.c"
"    movs    r0, #0\n"
"    blx     sub_fc302434\n" // j_DebugAssert
"loc_fc379bec:\n"
"    strd    r6, sb, [r5, #0x48]\n"
"    movs    r0, #1\n"
"    str.w   r8, [r5, #0x44]\n"
"    b       loc_fc379b14\n" //  return
    );
}

void __attribute__((naked,noinline)) kbd_p2_f_my() { // sub_FC083914
    asm volatile(
"       push.w  {r4-r8,lr}\n"
"       ldr     r6, =0x520ec\n"
"       sub     sp, sp, #0x18\n"
"       add     r7, sp, #8\n"
"       subs    r6, #0xc\n"
"       b       loc_fc083956\n"
" loc_fc083922:\n"
"       ldr     r1, =0x520ec\n"
"       add     r3, sp, #0x8\n"
"       ldrb.w  r0, [sp,#0x4]\n"
"       add     r2, sp, #0x14\n"
"       subs    r1, #0x18\n"
"       bl      sub_fc075420\n"
"       cbnz    r0, loc_fc08393c\n"
"       ldr     r1, [sp,#0x14]\n"
"       movs    r0, #0\n"
"       bl      sub_fc083886\n"
" loc_fc08393c:\n"
"       movs    r0, #2\n"
" loc_fc08393e:\n"
"       ldr.w   r1, [r7,r0,lsl#2]\n"
"       cbz     r1, loc_fc08394e\n"
"       ldr.w   r2, [r6,r0,lsl#2]\n"
"       bics    r2, r1\n"
"       str.w   r2, [r6,r0,lsl#2]\n"
" loc_fc08394e:\n"
"       subs    r0, r0, #1\n"
"       sxtb    r0, r0\n"
"       cmp     r0, #0\n"
"       bge     loc_fc08393e\n"
" loc_fc083956:\n"
"       ldr     r0, =0x520ec\n"
"       add     r1, sp, #0x4\n"
"       subs    r0, #0xc\n"
"       bl      sub_fc0750d2\n"
"       cmp     r0, #0\n"
"       bne     loc_fc083922\n"
"       ldr.w   r8, =0x520ec\n"
"       movs    r4, #0\n"
" loc_fc08396a:\n"
"       movs    r5, #0\n"
"       ldr.w   r0, [r6,r4,lsl#2]\n"
"       ldr.w   r1, [r8,r4,lsl#2]\n"
"       ands    r0, r1\n"
"       str.w   r0, [r6,r4,lsl#2]\n"
"       b       loc_fc0839c2\n"
" loc_fc08397c:\n"
"       lsrs    r0, r5\n"
"       lsls    r0, r0, #0x1f\n"
"       beq     loc_fc0839ba\n"
"       ldr     r1, =0x520ec\n"
"       add.w   r0, r5, r4,lsl#5\n"
"       add     r3, sp, #0x8\n"
"       subs    r1, #0x18\n"
"       add     r2, sp, #0x14\n"
"       uxtb    r0, r0\n"
"       bl      sub_fc075420\n"
"       cbnz    r0, loc_fc08399e\n"
"       ldr     r1, [sp,#0x14]\n"
"       movs    r0, #1\n"
"       bl      sub_fc083886\n"
" loc_fc08399e:\n"
"       mov     r0, r4\n"
"       b       loc_fc0839b6\n"
" loc_fc0839a2:\n"
"       ldr.w   r1, [r7,r0,lsl#2]\n"
"       cbz     r1, loc_fc0839b2\n"
"       ldr.w   r2, [r6,r0,lsl#2]\n"
"       bics    r2, r1\n"
"       str.w   r2, [r6,r0,lsl#2]\n"
" loc_fc0839b2:\n"
"       adds    r0, r0, #1\n"
"       sxtb    r0, r0\n"
" loc_fc0839b6:\n"
"       cmp     r0, #3\n"
"       blt     loc_fc0839a2\n"
" loc_fc0839ba:\n"
"       ldr.w   r0, [r6,r4,lsl#2]\n"
"       adds    r5, r5, #1\n"
"       uxtb    r5, r5\n"
" loc_fc0839c2:\n"
"       cmp     r0, #0\n"
"       bne     loc_fc08397c\n"
"       adds    r4, r4, #1\n"
"       sxtb    r4, r4\n"
"       cmp     r4, #3\n"
"       blt     loc_fc08396a\n"
"       bl      sub_fc074e8a_my\n" // ->
"       add     sp, sp, #0x18\n"
"       pop.w   {r4-r8,pc}\n"
".ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc074e8a_my() {
    asm volatile(
"  push    {r4,lr}\n"
"  ldr     r4, =0x9e6c\n"
"  ldr     r0, [r4,#0x10]\n"
"  bl      sub_fc0765e4\n"
"  ldr     r0, [r4,#0x14]\n"
"  bl      sub_fc07666e\n"
"  bl      sub_fc0766f6\n"
"  bl      sub_fc17b378\n"
"  ldr     r0, [r4,#0x18]\n"
"  bl      sub_fc076500\n"
"  ldr     r0, [r4,#0x1C]\n"
"  bl      sub_fc076500\n"
// "  pop.w   {r4,lr}\n"		  // - (reordered below)
// "  b.w     sub_fc076948\n"    // - (reordered below)

"    bl      handle_jogdial\n"  // +
"    cmp     r0, #0\n"          // +
"    beq     no_scroll\n"       // +
"                 b.w     sub_fc076948\n"// handles scrollwheel(s), void function, no args
"no_scroll:\n"                  // +
"    pop     {r4, pc}\n"        // +
    );
}


long __attribute__((naked,noinline)) wrap_kbd_p1_f() {

asm volatile(
"       push    {r1-r7,lr}\n"
"       movs    r4, #0\n"
"       bl      my_kbd_read_keys\n"
" kbd_p1_f_cont:\n"
"       ldr     r3, =physw_status\n"
"       movs    r0, #2\n"
"       mov     r5, sp\n"
"       add.w   r6, r3, #0x24\n"
" loc_fc083ebe:\n"
"       add.w   r1, r6, r0,lsl#2\n"
"       ldr.w   r2, [r3,r0,lsl#2]\n"
"       ldr     r7, [r1,#0xc]\n"
"       ldr     r1, [r1,#0x18]\n"
"       and.w   r2, r2, r7\n"
"       eor.w   r2, r2, r1\n"
"       str.w   r2, [r5,r0,lsl#2]\n"
"       subs    r0, r0, #1\n"
"       bpl     loc_fc083ebe\n"
"       ldr     r2, =physw_status\n"
"       mov     r0, sp\n"
"       adds    r2, #0x18\n"
"       sub.w   r1, r2, #0xc\n"
"       bl      sub_fc0839d8_my\n" //kbd_read_keys2\n"
"       ldr     r0, =physw_status\n"
"       adds    r0, #0xc\n"
"       bl      sub_fc074e34\n"
"       cmp     r0, #1\n"
"       bne     loc_fc083ef6\n"
"       movs    r4, #1\n"
" loc_fc083ef6:\n"
"       ldr     r2, =physw_status\n"
"       movs    r0, #2\n"
"       adds    r2, #0x18\n"
"       sub.w   r3, r2, #0xc\n"
" loc_fc083f00:\n"
"       ldr.w   r1, [r2,r0,lsl#2]\n"
"       cbz     r1, loc_fc083f1a\n"
"       ldr.w   r4, [r3,r0,lsl#2]\n"
"       ldr.w   r6, [r5,r0,lsl#2]\n"
"       bics    r4, r1\n"
"       ands    r1, r6\n"
"       orrs    r4, r1\n"
"       str.w   r4, [r3,r0,lsl#2]\n"
"       movs    r4, #1\n"
" loc_fc083f1a:\n"
"       subs    r0, r0, #1\n"
"       bpl     loc_fc083f00\n"
"       mov     r0, r4\n"
"       pop     {r1-r7,pc}\n"
".ltorg\n"
);
return 0;
}

void __attribute__((naked,noinline)) sub_fc0839d8_my() {
asm volatile(
"       push.w  {r0-r12,lr}\n"
"       ldr     r7, =0x520ec\n"
"       mov     r5, r0\n"
"       mov.w   r0, #0xffffffff\n"
"       mov     r9, r1\n"
"       str     r0, [sp]\n"
"       movs    r0, #2\n"
"       adds    r7, #0x24\n"
"       mov     r6, r2\n"
" loc_fc0839ee:\n"
"       ldr.w   r1, [r5,r0,lsl#2]\n"
"       ldr.w   r2, [r9,r0,lsl#2]\n"
"       eors    r1, r2\n"
"       add.w   r2, r7, r0,lsl#2\n"
"       ldr.w   r2, [r2,#0xc0]\n"
"       ands    r1, r2\n"
"       str.w   r1, [r6,r0,lsl#2]\n"
"       subs    r0, r0, #1\n"
"       sxtb    r0, r0\n"
"       cmp     r0, #0\n"
"       bge     loc_fc0839ee\n"
"       movs    r0, #2\n"
" loc_fc083a10:\n"
"       ldrh    r1, [r7,#0x30]\n"
"       add.w   r1, r1, r1,lsl#1\n"
"       ldr.w   r2, [r5,r0,lsl#2]\n"
"       add.w   r1, r7, r1,lsl#2\n"
"       add.w   r1, r1, r0,lsl#2\n"
"       subs    r0, r0, #1\n"
"       sxtb    r0, r0\n"
"       cmp     r0, #0\n"
"       str     r2, [r1,#0xc]\n"
"       bge     loc_fc083a10\n"
"       ldrh    r0, [r7,#0x30]\n"
"       mov.w   r12, #0\n"
"       adds    r0, r0, #1\n"
"       cmp     r0, #3\n"
"       bcc     loc_fc083a3e\n"
"       strh.w  r12, [r7,#0x30]\n"
"       b       loc_fc083a40\n"
" loc_fc083a3e:\n"
"       strh    r0, [r7,#0x30]\n"
" loc_fc083a40:\n"
"       movs    r0, #2\n"
" loc_fc083a42:\n"
"       movs    r2, #0\n"
"       mov     r1, r2\n"
" loc_fc083a46:\n"
"       add.w   r3, r1, r1,lsl#1\n"
"       adds    r1, r1, #1\n"
"       add.w   r3, r7, r3,lsl#2\n"
"       add.w   r3, r3, r0,lsl#2\n"
"       sxtb    r1, r1\n"
"       ldr     r4, [r3,#0xc]\n"
"       ldr     r3, [r3,#0x18]\n"
"       eors    r4, r3\n"
"       orrs    r2, r4\n"
"       cmp     r1, #2\n"
"       blt     loc_fc083a46\n"
"       ldr.w   r1, [r5,r0,lsl#2]\n"
"       ldr.w   r3, [r9,r0,lsl#2]\n"
"       eors    r1, r3\n"
"       bics    r1, r2\n"
"       ldr.w   r2, [r7,r0,lsl#2]\n"
"       ands    r1, r2\n"
"       ldr.w   r2, [r6,r0,lsl#2]\n"
"       orrs    r1, r2\n"
"       str.w   r1, [r6,r0,lsl#2]\n"
"       subs    r0, r0, #1\n"
"       sxtb    r0, r0\n"
"       cmp     r0, #0\n"
"       bge     loc_fc083a42\n"
"       add.w   r10, sp, #4\n"
"       mov.w   r8, #4\n"
"       mov     r11, r12\n"
" loc_fc083a90:\n"
"       ldr     r3, =0x520ec\n"
"       movs    r1, #0\n"
"       mov     r12, r10\n"
"       movs    r0, #2\n"
"       rsb.w   r2, r8, r8,lsl#3\n"
"       adds    r3, #0x24\n"
"       add.w   r4, r3, r2,lsl#2\n"
" loc_fc083aa2:\n"
"       mov     r10, r12\n"
"       add.w   r2, r4, r0,lsl#2\n"
"       str.w   r11, [r12,r0,lsl#2]\n"
"       ldr     r2, [r2,#0x38]\n"
"       cbz     r2, loc_fc083ac2\n"
"       ldr.w   r3, [r9,r0,lsl#2]\n"
"       ldr.w   r7, [r5,r0,lsl#2]\n"
"       eors    r3, r7\n"
"       ands    r3, r2\n"
"       orrs    r1, r3\n"
"       str.w   r3, [r10,r0,lsl#2]\n"
" loc_fc083ac2:\n"
"       subs    r0, r0, #1\n"
"       sxtb    r0, r0\n"
"       cmp     r0, #0\n"
"       bge     loc_fc083aa2\n"
"       cbnz    r1, loc_fc083ad2\n"
"       strb.w  r11, [r4,#0x36]\n"
"       b       loc_fc083b86\n"
" loc_fc083ad2:\n"
"       ldrb.w  r0, [r4,#0x36]\n"
"       cbz     r0, loc_fc083afa\n"
"       movs    r0, #2\n"
" loc_fc083ada:\n"
"       add.w   r1, r4, r0,lsl#2\n"
"       ldr.w   r3, [r5,r0,lsl#2]\n"
"       ldr     r2, [r1,#0x44]\n"
"       ldr     r1, [r1,#0x38]\n"
"       eors    r2, r3\n"
"       tst     r2, r1\n"
"       beq     loc_fc083af2\n"
"       strb.w  r11, [r4,#0x36]\n"
"       b       loc_fc083afa\n"
" loc_fc083af2:\n"
"       subs    r0, r0, #1\n"
"       sxtb    r0, r0\n"
"       cmp     r0, #0\n"
"       bge     loc_fc083ada\n"
" loc_fc083afa:\n"
"       add.w   r4, r4, #0x34\n"
"       ldrb    r0, [r4,#2]\n"
"       add.w   r0, r0, #1\n"
"       strb    r0, [r4,#2]\n"
"       ldrb.w  r0, [r4],#-0x34\n"
"       lsls    r0, r0, #0x18\n"
"       bpl     loc_fc083b34\n"
"       ldr     r0, [r5]\n"
"       ldr     r1, [r4,#0x38]\n"
"       ldr     r2, [r4,#0x3c]\n"
"       ands    r0, r1\n"
"       ldr     r1, [r5,#4]\n"
"       ands    r1, r2\n"
"       ldr     r2, [r4,#0x40]\n"
"       orrs    r0, r1\n"
"       ldr     r1, [r5,#8]\n"
"       ands    r1, r2\n"
"       orrs    r0, r1\n"
"       ldrb.w  r0, [r4,#0x35]\n"
"       beq     loc_fc083b2e\n"
"       lsrs    r7, r0, #4\n"
"       b       loc_fc083b38\n"
" loc_fc083b2e:\n"
"       and.w   r7, r0, #0xf\n"
"       b       loc_fc083b38\n"
" loc_fc083b34:\n"
"       ldrsb.w r7, [r4,#0x35]\n"
" loc_fc083b38:\n"
"       cmp     r7, #1\n"
"       bne     loc_fc083b4a\n"
"       ldr     r2, =0x520ec\n"
"       add.w   r3, r4, #0x34\n"
"       mov     r1, r5\n"
"       mov     r0, sp\n"
"       bl      sub_fc07507e_my\n" //getkbdstate2
" loc_fc083b4a:\n"
"       ldrb.w  r0, [r4,#0x36]\n"
"       cmp     r0, r7\n"
"       blt     loc_fc083b72\n"
"       movs    r0, #2\n"
"       mov     r2, r10\n"
" loc_fc083b56:\n"
"       ldr.w   r1, [r2,r0,lsl#2]\n"
"       cbz     r1, loc_fc083b66\n"
"       ldr.w   r3, [r6,r0,lsl#2]\n"
"       orrs    r3, r1\n"
"       str.w   r3, [r6,r0,lsl#2]\n"
" loc_fc083b66:\n"
"       subs    r0, r0, #1\n"
"       sxtb    r0, r0\n"
"       cmp     r0, #0\n"
"       bge     loc_fc083b56\n"
"       strb.w  r11, [r4,#0x36]\n"
" loc_fc083b72:\n"
"       movs    r0, #2\n"
" loc_fc083b74:\n"
"       add.w   r2, r4, r0,lsl#2\n"
"       ldr.w   r1, [r5,r0,lsl#2]\n"
"       subs    r0, r0, #1\n"
"       sxtb    r0, r0\n"
"       cmp     r0, #0\n"
"       str     r1, [r2,#0x44]\n"
"       bge     loc_fc083b74\n"
" loc_fc083b86:\n"
"       sub.w   r0, r8, #1\n"
"       sxtb.w  r8, r0\n"
"       cmp.w   r8, #0\n"
"       bge.w   loc_fc083a90\n"
"       pop.w   {r0-r12,pc}\n"
".ltorg\n"
);
}


void __attribute__((naked,noinline)) sub_fc07507e_my() {

extern long kbd_mod_state[];
(void)kbd_mod_state;
asm volatile(
"       push    {r4-r8,lr}\n"
"       ldr     r4, [r0]\n"
"       adds    r4, r4, #1\n"
"       bne     loc_fc075090\n"
"       ldr     r4, =0xd20bf4a0\n"
"       ldr     r4, [r4]\n"
"       ldr     r5, =0x43ff9\n"
"ldr     r8, =kbd_mod_state\n"
"ldr     r8, [r8,#4]\n"
"ands    r4, r8\n"
"       ands    r4, r5\n"
"       str     r4, [r0]\n"
" loc_fc075090:\n"
"       movs    r4, #2\n"
" loc_fc075092:\n"
"       add.w   r5, r3, r4,lsl#2\n"
"       ldr     r5, [r5,#4]\n"
"       cbnz    r5, loc_fc07509e\n"
"       subs    r4, r4, #1\n"
"       bpl     loc_fc075092\n"
" loc_fc07509e:\n"
"       ldr     r5, [r0]\n"
"       add.w   r0, r2, r4,lsl#2\n"
"       add.w   r7, r3, r4,lsl#2\n"
"       ldr     r2, [r0,#0xc]\n"
"       ldr     r0, [r0,#0x18]\n"
"       ands    r5, r2\n"
"       ldr.w   r2, [r1,r4,lsl#2]\n"
"       eors    r5, r0\n"
"       ldr     r0, [r7,#4]\n"
"       ands    r5, r0\n"
"       and.w   r6, r2, r0\n"
"       cmp     r6, r5\n"
"       beq     locret_fc0750d0\n"
"       ldr     r5, [r7,#0x10]\n"
"       bics    r2, r0\n"
"       ands    r5, r0\n"
"       orrs    r2, r5\n"
"       str.w   r2, [r1,r4,lsl#2]\n"
"       movs    r0, #0\n"
"       strb    r0, [r3,#2]\n"
" locret_fc0750d0:\n"
"       pop     {r4-r8,pc}\n"
".ltorg\n"
);
}

void agent_orange(){
*(int*)0xd20b0810  = 0x4d0002;	 // Orange Led = on
}

