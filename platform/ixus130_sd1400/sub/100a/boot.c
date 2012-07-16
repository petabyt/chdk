#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

const char * const new_sa = &_end;

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

void __attribute__((naked,noinline)) init_file_modules_task() {    // FF89467C
  asm volatile (
        "PUSH   {r4, r5, r6, lr}\n"
        "BL     sub_FF88CAC0\n" 
        "LDR    r5, =0x00005006\n" // was: "[pc, #408]  ; ff894874" 
        "MOVS   r4, r0\n"
        "LDRNE  r1, =0x0\n" // was: "mov ..., #0"
        "MOVNE  r0, r5\n"
        "BLNE   sub_FF8904CC\n" 
        "BL     sub_FF88CAEC\n" 
        //"BL     sub_ff88cb3c_my\n"
		"BL     core_spytask_can_start\n"
        "CMP    r4, #0\n"       // 0x0
        "MOVEQ  r0, r5\n"
        "POPEQ  {r4, r5, r6, lr}\n"
        "LDREQ  r1, =0x0\n" // was: "mov ..., #0"
        "BEQ    sub_FF8904CC\n" 
        "POP    {r4, r5, r6, pc}\n"
    );
};

void taskHook(context_t **context) {
  task_t * tcb = (task_t*)((char*)context - offsetof(task_t, context));
  if (!_strcmp(tcb->name, "PhySw"))           tcb->entry = (void*)mykbd_task;
  if (!_strcmp(tcb->name, "CaptSeqTask"))     tcb->entry = (void*)capt_seq_task;
  if (!_strcmp(tcb->name, "InitFileModules")) tcb->entry = (void*)init_file_modules_task;
  if (!_strcmp(tcb->name, "MovieRecord"))     tcb->entry = (void*)movie_record_task;
  if (!_strcmp(tcb->name, "ExpDrvTask"))      tcb->entry = (void*)exp_drv_task;
  //if (!_strcmp(tcb->name, "RotarySw"))        tcb->entry = (void*)JogDial_task_my;
  //led_flash(LED_GREEN, 1);
}

void CreateTask_spytask() {
  _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}

void __attribute__((naked,noinline)) boot() {
  asm volatile (
	"LDR	r1, =0xc0410000\n" // was: "[pc, #336]	; ff810164" 
	"LDR	r0, =0x0\n" // was: "mov ..., #0"
	"STR	r0, [r1]\n"
	"LDR	r1, =0x78\n" // was: "mov ..., #120"
	"MCR	15, 0, r1, cr1, cr0, 0\n"
	"LDR	r1, =0x0\n" // was: "mov ..., #0"
	"MCR	15, 0, r1, cr7, cr10, 4\n"
	"MCR	15, 0, r1, cr7, cr5, 0\n"
	"MCR	15, 0, r1, cr7, cr6, 0\n"
	"LDR	r0, =0x3d\n" // was: "mov ..., #61"
	"MCR	15, 0, r0, cr6, cr0, 0\n"
	"LDR	r0, =0xc000002f\n" // was: "mov ..., #-1073741777"
	"MCR	15, 0, r0, cr6, cr1, 0\n"
	"LDR	r0, =0x33\n" // was: "mov ..., #51"
	"MCR	15, 0, r0, cr6, cr2, 0\n"
	"LDR	r0, =0x40000033\n" // was: "mov ..., #1073741875"
	"MCR	15, 0, r0, cr6, cr3, 0\n"
	"LDR	r0, =0x80000017\n" // was: "mov ..., #-2147483625"
	"MCR	15, 0, r0, cr6, cr4, 0\n"
	"LDR	r0, =0xff80002d\n" // was: "[pc, #264]	; ff810168" 
	"MCR	15, 0, r0, cr6, cr5, 0\n"
	"LDR	r0, =0x34\n" // was: "mov ..., #52"
	"MCR	15, 0, r0, cr2, cr0, 0\n"
	"LDR	r0, =0x34\n" // was: "mov ..., #52"
	"MCR	15, 0, r0, cr2, cr0, 1\n"
	"LDR	r0, =0x34\n" // was: "mov ..., #52"
	"MCR	15, 0, r0, cr3, cr0, 0\n"
	"LDR	r0, =0x03333330\n" // was: "[pc, #236]	; ff81016c" 
	"MCR	15, 0, r0, cr5, cr0, 2\n"
	"LDR	r0, =0x03333330\n" // was: "[pc, #228]	; ff81016c" 
	"MCR	15, 0, r0, cr5, cr0, 3\n"
	"MRC	15, 0, r0, cr1, cr0, 0\n"
	"ORR	r0, r0, #4096\n"	// 0x1000
	"ORR	r0, r0, #4\n"	// 0x4
	"ORR	r0, r0, #1\n"	// 0x1
	"MCR	15, 0, r0, cr1, cr0, 0\n"
	"LDR	r1, =0x80000006\n" // was: "mov ..., #-2147483642"
	"MCR	15, 0, r1, cr9, cr1, 0\n"
	"LDR	r1, =0x6\n" // was: "mov ..., #6"
	"MCR	15, 0, r1, cr9, cr1, 1\n"
	"MRC	15, 0, r1, cr1, cr0, 0\n"
	"ORR	r1, r1, #327680\n"	// 0x50000
	"MCR	15, 0, r1, cr1, cr0, 0\n"
	"LDR	r2, =0xc0200000\n" // was: "[pc, #176]	; ff810170" 
	"LDR	r1, =0x1\n" // was: "mov ..., #1"
	"STR	r1, [r2, #268]\n"
	"LDR	r1, =0xff\n" // was: "mov ..., #255"
	"STR	r1, [r2, #12]\n"
	"STR	r1, [r2, #28]\n"
	"STR	r1, [r2, #44]\n"
	"STR	r1, [r2, #60]\n"
	"STR	r1, [r2, #76]\n"
	"STR	r1, [r2, #92]\n"
	"STR	r1, [r2, #108]\n"
	"STR	r1, [r2, #124]\n"
	"STR	r1, [r2, #140]\n"
	"STR	r1, [r2, #156]\n"
	"STR	r1, [r2, #172]\n"
	"STR	r1, [r2, #188]\n"
	"STR	r1, [r2, #204]\n"
	"STR	r1, [r2, #220]\n"
	"STR	r1, [r2, #236]\n"
	"STR	r1, [r2, #252]\n"
	"LDR	r1, =0xc0400008\n" // was: "[pc, #100]	; ff810174" 
	"LDR	r2, =0x00430005\n" // was: "[pc, #100]	; ff810178" 
	"STR	r2, [r1]\n"
	"LDR	r1, =0x1\n" // was: "mov ..., #1"
	"LDR	r2, =0xc0243100\n" // was: "[pc, #92]	; ff81017c" 
	"STR	r2, [r1]\n"
	"LDR	r2, =0xc0242010\n" // was: "[pc, #88]	; ff810180" 
	"LDR	r1, [r2]\n"
	"ORR	r1, r1, #1\n"	// 0x1
	"STR	r1, [r2]\n"
	"LDR	r0, =0xFFBF837C\n" // canon_data_src 
	"LDR	r1, =0x1900\n"     // MEMBASEADDR 
	"LDR	r3, =0xebd0\n"     // canon_bss_start
"loc_ff81013c:\n"
	"CMP	r1, r3\n"
	"LDRCC	r2, [r0], #4\n"
	"STRCC	r2, [r1], #4\n"
	"BCC	loc_ff81013c\n"
	"LDR	r1, =0x0014fe20\n" // MEMISOSTART
	"LDR	r2, =0x0\n" // was: "mov ..., #0"
"loc_ff810154:\n"
	"CMP	r3, r1\n"
	"STRCC	r2, [r3], #4\n"
	"BCC	loc_ff810154\n"
	"B	sub_ff810354_my\n"
    );
}

void __attribute__((naked,noinline)) sub_ff810354_my() { //??? was FF8101A0
/*
ff85f3f0: 	e92d4010 	push	{r4, lr}
ff85f3f4: 	e59f46cc 	ldr	r4, [pc, #1740]	; ff85fac8: (00002480) 
ff85f3f8: 	e3a00000 	mov	r0, #0	; 0x0
ff85f3fc: 	e5840000 	str	r0, [r4]
ff85f400: 	ebff71a0 	bl	loc_ff83ba88
ff85f404: 	e3500000 	cmp	r0, #0	; 0x0
ff85f408: 	15940000 	ldrne	r0, [r4]
ff85f40c: 	13800502 	orrne	r0, r0, #8388608	; 0x800000
ff85f410: 	15840000 	strne	r0, [r4]
ff85f414: 	e59f06b0 	ldr	r0, [pc, #1712]	; ff85facc: (c0220128) 
ff85f418: 	eb0001c8 	bl	loc_ff85fb40
ff85f41c: 	e3500000 	cmp	r0, #0	; 0x0
ff85f420: 	05940000 	ldreq	r0, [r4]
ff85f424: 	03800602 	orreq	r0, r0, #2097152	; 0x200000
ff85f428: 	05840000 	streq	r0, [r4]
ff85f42c: 	e59f069c 	ldr	r0, [pc, #1692]	; ff85fad0: (c022012c) 
ff85f430: 	eb0001c2 	bl	loc_ff85fb40
ff85f434: 	e3500000 	cmp	r0, #0	; 0x0
ff85f438: 	05940000 	ldreq	r0, [r4]
ff85f43c: 	03800501 	orreq	r0, r0, #4194304	; 0x400000
ff85f440: 	05840000 	streq	r0, [r4]
ff85f444: 	e8bd8010 	pop	{r4, pc}
// Search on 0x12345678 finds function that is called from function with this code (SD780 0xFF842A90)
*/
  // Power Button detection (short press = playback mode, long press = record mode)
  // replacement for sub_ff834348
  *(int*)0x2480 = (*(int*)0xC0220128) & 1 ? 0x400000 : 0x200000;
  // Long press on play to start in playback mode:
  //*(int*)0x2480 = (*(int*)0xc022012c) & 1 ? 0x200000 : 0x400000;
	
  //*(int*)0x1934 = (int)taskHook;
  *(int*)0x1938 = (int)taskHook;
	
  asm volatile (
	"LDR	r0, =0xff8103cc\n" // was: "[pc, #1036]	; ff810768" 
	"LDR	r1, =0x0\n" // was: "mov ..., #0"
	"LDR	r3, =0xff810404\n" // was: "[pc, #1032]	; ff81076c" 
"loc_ff810360:\n"
	"CMP	r0, r3\n"
	"LDRCC	r2, [r0], #4\n"
	"STRCC	r2, [r1], #4\n"
	"BCC	loc_ff810360\n"
	"LDR	r0, =0xff810404\n" // was: "[pc, #1016]	; ff810770" 
	"LDR	r1, =0x4b0\n" // was: "mov ..., #1200"
	"LDR	r3, =0xff810618\n" // was: "[pc, #1012]	; ff810774" 
"loc_ff81037c:\n"
	"CMP	r0, r3\n"
	"LDRCC	r2, [r0], #4\n"
	"STRCC	r2, [r1], #4\n"
	"BCC	loc_ff81037c\n"
	"LDR	r0, =0xd2\n" // was: "mov ..., #210"
	"MSR	CPSR_fsxc, r0\n"
	"LDR	sp, =0x1000\n" // was: "mov ..., #4096"
	"LDR	r0, =0xd3\n" // was: "mov ..., #211"
	"MSR	CPSR_fsxc, r0\n"
	"LDR	sp, =0x1000\n" // was: "mov ..., #4096"
	"LDR	r0, =0x000006c4\n" // was: "[pc, #20]	; ff8103c0" 
	"LDR	r2, =0xeeeeeeee\n" // was: "[pc, #968]	; ff810778" 
	"LDR	r3, =0x1000\n" // was: "mov ..., #4096"
"loc_ff8103b0:\n"
	"CMP	r0, r3\n"
	"STRCC	r2, [r0], #4\n"
	"BCC	loc_ff8103b0\n"
	"BL	sub_ff811198_my\n"
        );
}

void __attribute__((naked,noinline)) sub_ff811198_my() {
  asm volatile (
	"PUSH	{lr}\n"		// (str lr, [sp, #-4]!)
	"SUB	sp, sp, #116\n"	// 0x74
	"MOV	r0, sp\n"
	"LDR	r1, =0x74\n" // was: "mov ..., #116"
	"BL	sub_FFB39910\n" 
	"LDR	r0, =0x53000\n" // was: "mov ..., #339968"
	"STR	r0, [sp, #4]\n"

	"LDR	r0, =new_sa\n" // Replaces original start location 0x14fe20
        "LDR    r0, [r0]\n"

	"LDR	r2, =0x00339c00\n" // was: "[pc, #136]	; ff811248" 
	"LDR	r1, =0x003324a8\n" // was: "[pc, #140]	; ff811250" 
	"STR	r0, [sp, #8]\n"
	"SUB	r0, r1, r0\n"
	"ADD	r3, sp, #12\n"	// 0xc
	"STR	r2, [sp]\n"
	"STM	r3, {r0, r1, r2}\n"
	"LDR	r0, =0x22\n" // was: "mov ..., #34"
	"STR	r0, [sp, #24]\n"
	"LDR	r0, =0x68\n" // was: "mov ..., #104"
	"STR	r0, [sp, #28]\n"
	"LDR	r0, =0x0000019b\n" // was: "[pc, #104]	; ff811254" 
	"LDR	r1, =uHwSetup_my\n" // was: "[pc, #104]	; ff811258"
	"STR	r0, [sp, #32]\n"
	"LDR	r0, =0x96\n" // was: "mov ..., #150"
	"STR	r0, [sp, #36]\n"
	"LDR	r0, =0x78\n" // was: "mov ..., #120"
	"STR	r0, [sp, #40]\n"
	"LDR	r0, =0x64\n" // was: "mov ..., #100"
	"STR	r0, [sp, #44]\n"
	"LDR	r0, =0x0\n" // was: "mov ..., #0"
	"STR	r0, [sp, #48]\n"
	"STR	r0, [sp, #52]\n"
	"LDR	r0, =0x10\n" // was: "mov ..., #16"
	"STR	r0, [sp, #92]\n"
	"LDR	r0, =0x800\n" // was: "mov ..., #2048"
	"STR	r0, [sp, #96]\n"
	"LDR	r0, =0xa0\n" // was: "mov ..., #160"
	"STR	r0, [sp, #100]\n"
	"LDR	r0, =0x280\n" // was: "mov ..., #640"
	"STR	r0, [sp, #104]\n"
	"MOV	r0, sp\n"
	"LDR	r2, =0x0\n" // was: "mov ..., #0"
	"BL	sub_ff813404\n"
	"ADD	sp, sp, #116\n"	// 0x74
	"POP	{pc}\n"		// (ldr pc, [sp], #4)
    );
}

void __attribute__((naked,noinline)) uHwSetup_my() { // 0xff815e58
  asm volatile (
	"PUSH	{r4, lr}\n"
	"BL	sub_ff810b20\n"
	"BL	sub_ff81a244\n"
	"CMP	r0, #0\n"	// 0x0
	"LDRLT	r0, =0xff815f6c\n" // was: "addlt	r0, pc, #252"   *"dmSetup"
	"BLLT	sub_ff815f4c\n"
	"BL	sub_ff815a94\n"
	"CMP	r0, #0\n"	// 0x0
	"LDRLT	r0, =0xff815f74\n" // was: "addlt	r0, pc, #244"   *"termDriverInit"
	"BLLT	sub_ff815f4c\n"
	"LDR	r0, =0xff815f84\n" // was: "add	r0, pc, #252"   *"/_term"
	"BL	sub_ff815b7c\n"
	"CMP	r0, #0\n"	// 0x0
	"LDRLT	r0, =0xff815f8c\n" // was: "addlt	r0, pc, #248"   *"termDeviceCreate"
	"BLLT	sub_ff815f4c\n"
	"LDR	r0, =0xff815f84\n" // was: "add	r0, pc, #232"   *"/_term"
	"BL	sub_ff813bf0\n"
	"CMP	r0, #0\n"	// 0x0
	"LDRLT	r0, =0xff815fa0\n" // was: "addlt	r0, pc, #248"   *"stdioSetup"
	"BLLT	sub_ff815f4c\n"
	"BL	sub_ff819c3c\n"
	"CMP	r0, #0\n"	// 0x0
	"LDRLT	r0, =0xff815fac\n" // was: "addlt	r0, pc, #244"   *"stdlibSetup"
	"BLLT	sub_ff815f4c\n"
	"BL	sub_ff81167c\n"
	"CMP	r0, #0\n"	// 0x0
	"LDRLT	r0, =0xff815fb8\n" // was: "addlt	r0, pc, #240"   *"armlib_setup"
	"BLLT	sub_ff815f4c\n"
	"POP	{r4, lr}\n"
	"B	taskcreate_Startup_my\n" // ff81faf0
    );	
}

void __attribute__((naked,noinline)) taskcreate_Startup_my() { // 0xff81faf0
  asm volatile (
	"PUSH	{r3, lr}\n"
	"BL	sub_ff834340\n"
	"BL	sub_ff83ba88\n"
	"CMP	r0, #0\n"	// 0x0
	"BNE	loc_ff81fb34\n"
	"BL	sub_ff835b2c\n"
	"CMP	r0, #0\n"	// 0x0
	"BEQ	loc_ff81fb34\n"
	"BL	sub_ff83433c\n"
	"CMP	r0, #0\n"	// 0x0
	"BNE	loc_ff81fb34\n"
	"BL	sub_ff8339dc\n"
	"LDR	r1, =0xc0220000\n" // was: "[pc, #76]	; ff81fb74" 
	"LDR	r0, =0x44\n" // was: "mov ..., #68"
	"STR	r0, [r1, #28]\n"
	"BL	sub_ff833bc8\n"
"loc_ff81fb30:\n"
	"B	loc_ff81fb30\n"
"loc_ff81fb34:\n" // 3 refs
	//"BL	sub_ff834348\n" // disabled for correct Power Button detection
	//"BL	sub_ff834344\n" // nullsub
	"BL	sub_ff839cb0\n"
	"LDR	r1, =0x0038e000\n" // was: "[pc, #48]	; ff81fb78" 
	"LDR	r0, =0x0\n" // was: "mov ..., #0"
	"BL	sub_ff83a0f8\n"
	"BL	sub_ff839ea4\n"
	"LDR	r3, =0x0\n" // was: "mov ..., #0"
	"STR	r3, [sp]\n"
	"LDR    r3, =task_Startup_my\n" // was: "sub	r3, pc, #212\n"	// ff81fa8c: (e92d4010) 
	"LDR	r2, =0x0\n" // was: "mov ..., #0"
	"LDR	r1, =0x19\n" // was: "mov ..., #25"
	"ADD	r0, pc, #16\n"	// ff81fb7c: (72617453)  *"Startup"
	"BL	sub_ff81e83c\n"
	"LDR	r0, =0x0\n" // was: "mov ..., #0"
	"POP	{ip, pc}\n"
    );
}

void __attribute__((naked,noinline)) task_Startup_my() { // ff81fa8c
  asm volatile (
	"PUSH	{r4, lr}\n"
	"BL	sub_ff81650c\n" // taskcreate_ClockSave
	"BL	sub_ff83543c\n"
	"BL	sub_ff833638\n"
	"BL	sub_ff83bac8\n" // j_nullsub
	"BL	sub_ff83bcb4\n"
	//"bl	sub_ff83bb5c\n" // original: StartSdInit() -> StartDiskboot()
    );

  CreateTask_spytask();
  //led_flash(LED_RED, 1);
   //CreateTask_blinker();

  asm volatile (
	"BL	sub_ff83be58\n"
	"BL	sub_ff8322e4\n"
	"BL	sub_ff83bce4\n"
	"BL	sub_ff839454\n"
	"BL	sub_ff83be5c\n"
	"BL	taskcreate_PhySw_my\n" // sub_ff834230
	//"BL	sub_ff834230\n"
	"BL	task_ShootSeqTask_my\n" // sub_ff8377a8 taskcreate_SsTask -> for shoot seq stuff
	//"BL	sub_ff8377a8\n" // sub_ff8377a8 taskcreate_SsTask -> for shoot seq stuff
	"BL	sub_ff83be74\n"
	//"BL	sub_ff8316a8\n" // nullsub
	"BL	sub_ff833090\n" // Battery.c:0
	"BL	sub_ff83b860\n" // taskcreate_Bye
	"BL	sub_ff8335ec\n"
	"BL	sub_ff83302c\n" // taskcreate_BatteryTask / taskcreate_TempCheck
	"BL	sub_ff832318\n"
	"BL	sub_ff83c8f4\n" // taskcreate_FactoryModeController
	"BL	sub_ff833004\n" // taskcreate_Ui
	"POP	{r4, lr}\n"
	"B	sub_ff81662c\n" // MLHClock.c:992
    );
}

void __attribute__((naked,noinline)) taskcreate_PhySw_my() { // 0xff834230
  asm volatile (
	"PUSH	{r3, r4, r5, lr}\n"
	"LDR	r4, =0x00001c20\n" // was: "[pc, #476]	; ff834418" 
	"LDR	r0, [r4, #16]\n"
	"CMP	r0, #0\n"	// 0x0
	"BNE	loc_ff834264\n"
	"LDR	r3, =0x0\n" // was: "mov ..., #0"
	"STR	r3, [sp]\n"
	//"LDR	r3, =0xff8341fc\n" //   
	"LDR	r3, =mykbd_task\n" // 0xff8341fc  
        // Increate stack size from 0x800 to 0x2000 for new task_PhySw so we don't have to do stack switch
	"LDR	r2, =0x2000\n"
	//"LDR	r2, =0x800\n" // was: "mov ..., #2048"
	"LDR	r1, =0x17\n" // was: "mov ..., #23"
	"LDR	r0, =0xff834438\n" // was: "add	r0, pc, #472"   *"PhySw"
	"BL	sub_ff839ef8\n" // KernelCreateTask
	"STR	r0, [r4, #16]\n"
"loc_ff834264:\n"
	"BL	sub_FF88A5F4\n" 
	"BL	sub_ff835aa4\n" // IsFactoryMode
	"CMP	r0, #0\n"	// 0x0
	"LDREQ	r1, =0x0003280c\n" // was: "[pc, #428]	; ff834424" 
	"POPEQ	{r3, r4, r5, lr}\n"
	"BEQ	sub_FF88A57C\n" // eventproc_export_OpLog_Start
	"POP	{r3, r4, r5, pc}\n"
    );
}

void __attribute__((naked,noinline)) task_ShootSeqTask_my() { //FF8377A8
asm volatile (
	"PUSH	{r4, lr}\n"
	"LDR	r1, =0x0\n" // was: "mov ..., #0"
	"LDR	r0, =0x0\n" // was: "mov ..., #0"
	"BL	sub_ff839f50\n"
	"LDR	r4, =0x00001c7c\n" // was: "[pc, #-492]	; ff8375d4" 
	"STR	r0, [r4, #16]\n"
	"BL	sub_FF87F19C\n" 
	"BL	sub_FF8808E4\n" // taskcreate_SsTask 
	"BL	sub_FF87E2E4\n" 
	"BL	sub_ff878d6c_my\n" 
	"BL	sub_FF87F480\n" 
	"LDR	r0, [r4, #16]\n"
	"POP	{r4, lr}\n"
	"LDR	r1, =0x1000\n" // was: "mov ..., #4096"
	"B	sub_FF883F4C\n" 
  );
}

void __attribute__((naked,noinline)) sub_ff878d6c_my() { // was FF878D1C_my FF878D1C 
  asm volatile (
	"PUSH	{r4, lr}\n"
	"LDR	r4, =0x00002b64\n" // was: "[pc, #-3512]	; ff877fc0" 
	"LDR	r0, [r4, #12]\n"
	"CMP	r0, #0\n"	// 0x0
	"BNE	loc_FF878D88\n"
	"BL	sub_FF87C848\n" // nullsub 
	"LDR	r1, =0x1\n" // was: "mov ..., #1"
	"LDR	r0, =0x0\n" // was: "mov ..., #0"
	"BL	sub_ff839f74\n" // KernelMisc.c:55
	"STR	r0, [r4, #4]\n"
	"LDR	r0, =0x0\n" // was: "mov ..., #0"
	"LDR	r1, =0x8\n" // was: "mov ..., #8"
	"BL	sub_ff839f50\n" // KernelMisc.c:43
	"STR	r0, [r4, #8]\n"
	"BL	sub_FF8790FC\n" 
	"BL	sub_FF879884\n" 
	"LDR	r0, =0x0\n" // was: "mov ..., #0"
	"STR	r0, [r4]\n"
	"ADD	r0, r4, #16\n"	// 0x10
	"LDR	r1, =0x0\n" // was: "mov ..., #0"
	"STR	r1, [r0], #4\n"
	"STR	r1, [r0]\n"
	"BL	sub_FF879A94\n" 
	"BL	sub_FF87F680\n" 
	"BL	sub_FF87CC74\n" 
	"BL	sub_ff87a5d8_my\n" // taskcreate_CaptSeqTask
	"BL	sub_ff87b688\n" 
"loc_FF878D88:\n"
	"LDR	r0, =0x1\n" // was: "mov ..., #1"
	"STR	r0, [r4, #12]\n"
	"POP	{r4, pc}\n"
    );
}

void __attribute__((naked,noinline)) sub_ff87a5d8_my() { // was sub_ff87a5d8_my
  asm volatile (  //FF87A5D8
	"PUSH	{r3, r4, r5, lr}\n"
	"LDR	r2, =0x00039578\n" // was: "[pc, #-1920]	; ff879eb4" 
	"LDR	r0, =0x0\n" // was: "mov ..., #0"
	"LDR	r1, =0x0\n" // was: "mov ..., #0"
"loc_FF87A5E8:\n"  //WAS loc_ff87a638
	"ADD	r3, r2, r0, lsl #4\n"
	"ADD	r0, r0, #1\n"	// 0x1
	"CMP	r0, #5\n"	// 0x5
	"STR	r1, [r3, #8]\n"
	"BCC	loc_FF87A5E8\n" 
	"BL	sub_FF87B1C4\n" 
	"BL	sub_FF95F3A0\n" // nullsub 
	"BL	sub_FF95FF60\n" 
	"LDR	r1, =0x5\n" // was: "mov ..., #5"
	"LDR	r0, =0x0\n" // was: "mov ..., #0"
	"BL	sub_ff839f2c\n" // KernelMisc.c:31
	"LDR	r4, =0x00002b9c\n" // was: "[pc, #-2000]	; ff879e9c" 
	"LDR	r1, =0x00101dff\n" // was: "[pc, #-1968]	; ff879ec0" 
	"STR	r0, [r4, #4]\n"
	"LDR	r0, =0x0\n" // was: "mov ..., #0"
	"BL	sub_ff839f50\n" // KernelMisc.c:43
	"STR	r0, [r4]\n"
	"LDR	r0, =0x0\n" // was: "mov ..., #0"
	"LDR	r1, =0x1\n" // was: "mov ..., #1"
	"BL	sub_ff839f74\n" // KernelMisc.c:55
	"STR	r0, [r4, #8]\n"
	"LDR	r3, =0x0\n" // was: "mov ..., #0"
	"STR	r3, [sp]\n"
	//"LDR    r3, =capt_seq_task\n"
	"LDR    r3, =0xFF87A2C0\n" // capt_seq_task 
	"LDR    r0, =0xFF87A848\n" // *"CaptSeqTask" 
	"LDR	r2, =0x1000\n" // was: "mov ..., #4096"
	"LDR	r1, =0x17\n" // was: "mov ..., #23"
	"BL	sub_ff839ef8\n" // was FF839EF8 KernelCreateTask ; LOCATION: KernelMisc.c:19
	"POP	{r3, r4, r5, pc}\n"
    );
}

//****************
/*
void __attribute__((naked,noinline)) sub_ff88cb3c_my() {    // sub_FF88FF58_my
  asm volatile (
        "PUSH   {r4, lr}\n"
        "LDR    r0, =0x3\n" // was: "mov ..., #3"
        "BL     sub_ff86f084_my\n"
        "BL     sub_ff94002c\n"
        "LDR    r4, =0x00002f54\n" // was: "[pc, #112]  ; ff88cbc4" 
        "LDR    r0, [r4, #4]\n"
        "CMP    r0, #0\n"       // 0x0
        "BNE    loc_ff88cb74\n"
        "BL     sub_ff86e2cc\n"
        "BL     sub_ff9344f0\n"
        "BL     sub_ff86e2cc\n"
        "BL     sub_ff86a6f0\n"
        "BL     sub_ff86e1cc\n"
        "BL     sub_ff93458c\n"
"loc_ff88cb74:\n"
        "LDR    r0, =0x1\n" // was: "mov ..., #1"
        "STR    r0, [r4]\n"
        "POP    {r4, pc}\n"
    );
};

void __attribute__((naked,noinline)) sub_ff86f084_my() {    // sub_FF871A04_my
  asm volatile (
        "PUSH   {r4, r5, r6, r7, r8, lr}\n"
        "MOV    r8, r0\n"
        "BL     sub_ff86f004\n"
        "LDR    r1, =0x00038448\n" // was: "[pc, #-2052]        ; ff86e894" 
        "MOV    r6, r0\n"
        "ADD    r4, r1, r0, lsl #7\n"
        "LDR    r0, [r4, #108]\n"
        "CMP    r0, #4\n"       // 0x4
        "LDREQ  r1, =0x0000085a\n" // was: "[pc, #208]  ; ff86f17c" 
        "LDREQ  r0, =0xff86eb44\n" // was: "[pc, #200]  ; ff86f178"  **"Mounter.c"
        "BLEQ   sub_ff81eb14\n"
        "MOV    r1, r8\n"
        "MOV    r0, r6\n"
        "BL     sub_ff86e8bc\n"
        "LDR    r0, [r4, #56]\n"
        "BL     sub_ff86f724\n"
        "CMP    r0, #0\n"       // 0x0
        "STREQ  r0, [r4, #108]\n"
        "MOV    r0, r6\n"
        "BL     sub_ff86e94c\n"
        "MOV    r0, r6\n"
        "BL     sub_ff86ecac\n"
        "MOV    r5, r0\n"
        "MOV    r0, r6\n"
        "BL     sub_ff86eedc_my\n"
        "LDR    r6, [r4, #60]\n"
        "AND    r7, r5, r0\n"
        "CMP    r6, #0\n"       // 0x0
        "LDR    r1, [r4, #56]\n"
        "LDREQ  r0, =0x80000001\n" // was: "mov ..., #-2147483647"
        "LDR    r5, =0x0\n" // was: "mov ..., #0"
        "BEQ    loc_ff86f134\n"
        "MOV    r0, r1\n"
        "BL     sub_ff86e434\n"
        "CMP    r0, #0\n"       // 0x0
        "LDRNE  r5, =0x4\n" // was: "mov ..., #4"
        "CMP    r6, #5\n"       // 0x5
        "ORRNE  r0, r5, #1\n"   // 0x1
        "BICEQ  r0, r5, #1\n"   // 0x1
        "CMP    r7, #0\n"       // 0x0
        "BICEQ  r0, r0, #2\n"   // 0x2
        "ORREQ  r0, r0, #0x80000000\n"
        "BICNE  r0, r0, #0x80000000\n"
        "ORRNE  r0, r0, #2\n"   // 0x2
"loc_ff86f134:\n"
        "CMP    r8, #7\n"       // 0x7
        "STR    r0, [r4, #64]\n"
        "POPNE  {r4, r5, r6, r7, r8, pc}\n"
        "MOV    r0, r8\n"
        "BL     sub_ff86f054\n"
        "CMP    r0, #0\n"       // 0x0
        "POPEQ  {r4, r5, r6, r7, r8, lr}\n"
        "LDREQ  r0, =0xff86f180\n" // was: "addeq       r0, pc, #40"   *"EMEM MOUNT ERROR!!!"
        "BEQ    sub_ff81177c\n"
        "POP    {r4, r5, r6, r7, r8, pc}\n"
    );
};

void __attribute__((naked,noinline)) sub_ff86eedc_my() {    // FF87185C
  asm volatile (
	"PUSH	{r3, r4, r5, r6, r7, r8, r9, lr}\n"
	"MOV	r5, r0\n"
	"LDR	r0, =0xff86f16c\n" // was: "add	r0, pc, #640"  
	"LDR	r0, [r0]\n"
	"LDR	r9, =0x00038448\n" // was: "[pc, #-1632]	; ff86e894" 
	"STR	r0, [sp]\n"
	"ADD	r4, r9, r5, lsl #7\n"
	"LDR	r0, [r4, #108]\n"
	"TST	r0, #4\n"	// 0x4
	"LDRNE	r0, =0x1\n" // was: "mov ..., #1"
	"BNE	loc_ff86ef48\n"
	"LDR	r0, [r4, #60]\n"
	"LDR	r6, =0x00002968\n" // was: "[pc, #-1672]	; ff86e88c" 
	"CMP	r0, #6\n"	// 0x6
	"LDR	r8, =0x1\n" // was: "mov ..., #1"
	"LDR	r7, =0x0\n" // was: "mov ..., #0"
	"ADDLS	pc, pc, r0, lsl #2\n"
	"B	loc_ff86efa8\n"
	"B	loc_ff86ef40\n"
	"B	loc_ff86ef4c\n"
	"B	loc_ff86ef4c\n"
	"B	loc_ff86ef4c\n"
	"B	loc_ff86ef4c\n"
	"B	loc_ff86ef64\n"
	"B	loc_ff86ef4c\n"
"loc_ff86ef40:\n" // jumptable entry 0
	"LDR	r0, =0x0\n" // was: "mov ..., #0"
	"STR	r7, [r4, #108]\n"
"loc_ff86ef48:\n"
	"POP	{r3, r4, r5, r6, r7, r8, r9, pc}\n"
"loc_ff86ef4c:\n" // 5 refs, jumptable entries 1-4,6
	"LDR	r0, [r4, #56]\n"
	"BL	sub_ff86e434\n"
	"CMP	r0, #0\n"	// 0x0
	"STREQ	r7, [r6, #16]\n"
	"STRNE	r8, [r6, #16]\n"
	"B	loc_ff86efb4\n"
"loc_ff86ef64:\n" // jumptable entry 5
	"LDR	r2, =0x0\n" // was: "mov ..., #0"
	"LDR	r1, =0x8000\n" // was: "mov ..., #32768"
	"LDR	r0, =0x0\n" // was: "mov ..., #0"
	"STR	r8, [r6, #16]\n"
	"BL	sub_ff886bc0\n"
	"MOV	r6, r0\n"
	"MOV	r2, r4\n"
	"LDR	r1, =0x8000\n" // was: "mov ..., #32768"
	"BL	sub_ff941dd8\n"
	"LDR	r0, [r9, r5, lsl #7]\n"
	"MOV	r1, r6\n"
	"STR	r0, [r4, #80]\n"
	"LDR	r0, [r4, #4]\n"
	"STR	r0, [r4, #84]\n"
	"MOV	r0, r5\n"
	"BL	sub_ff86e578\n"
	"B	loc_ff86efb4\n"
"loc_ff86efa8:\n" // jumptable default entry
	"LDR	r1, =0x000006c1\n" // was: "[pc, #448]	; ff86f170" 
	"LDR	r0, =0xff86eb44\n" // was: "sub	r0, pc, #1136"   *"Mounter.c"
	"BL	sub_ff81eb14\n"
"loc_ff86efb4:\n" // 2 refs
	"MOV	r0, r5\n"
	"BL	sub_ff86e1d4\n"
	"STRB	r0, [sp]\n"
	"MOV	r0, r5\n"
	"MOV	r1, sp\n"
	"BL	sub_ff86edac\n"
	"CMN	r0, #1\n"	// 0x1
	"BNE	loc_ff86eff4\n"
	"LDR	r1, =0x000384c8\n" // was: "[pc, #-1860]	; ff86e898" 
	"ADD	r0, r5, r5, lsl #4\n"
	"STR	r7, [r1, r0, lsl #2]\n"
	"LDR	r1, [r4, #108]\n"
	"LDR	r0, =0x0\n" // was: "mov ..., #0"
	"BIC	r1, r1, #6\n"	// 0x6
"loc_ff86efec:\n"
	"STR	r1, [r4, #108]\n"
	"POP	{r3, r4, r5, r6, r7, r8, r9, pc}\n"
"loc_ff86eff4:\n"
	"LDR	r1, [r4, #108]\n"
	"LDR	r0, =0x1\n" // was: "mov ..., #1"
	"ORR	r1, r1, #4\n"	// 0x4
	"B	loc_ff86efec\n"
    );
};
*/
