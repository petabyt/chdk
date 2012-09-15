#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

void CreateTask_spytask();
extern volatile int jogdial_stopped;
void JogDial_task_my(void);

const char * const new_sa = &_end;

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_RotaryEncoder();
extern void task_MovieRecord();
extern void task_ExpDrv();

void taskHook(context_t **context) {
    task_t *tcb=(task_t*)((char*)context-offsetof(task_t, context));

    if(tcb->entry == (void*)task_CaptSeq)           tcb->entry = (void*)capt_seq_task;
    if(tcb->entry == (void*)task_InitFileModules)   tcb->entry = (void*)init_file_modules_task;
    if(tcb->entry == (void*)task_RotaryEncoder)     tcb->entry = (void*)JogDial_task_my;
    if(tcb->entry == (void*)task_MovieRecord)       tcb->entry = (void*)movie_record_task;
    if(tcb->entry == (void*)task_ExpDrv)            tcb->entry = (void*)exp_drv_task;
}

// debug use only
int debug_blink(int save_R0) {
    int i;
    *((volatile int *) 0xC0223000) = 0x46;  // PRE Turn on LED
    for (i=0; i<800000; i++) {              // Wait a while
        asm volatile ( "nop\n" );
    }
    *((volatile int *) 0xC0223070) = 0x46;  // PRE Turn on LED
    for (i=0; i<800000; i++) {              // Wait a while
        asm volatile ( "nop\n" );
    }
    *((volatile int *) 0xC022C028) = 0x46;  // Turn on LED
    for (i=0; i<800000; i++) {              // Wait a while
        asm volatile ( "nop\n" );
    }
    *((volatile int *) 0xC022C028) = 0xCF;  // Turn off LED
    for (i=0; i<800000; i++) {              // Wait a while
        asm volatile ( "nop\n" );
    }
    return save_R0;
};

void __attribute__((naked,noinline)) boot() {

    asm volatile (
"loc_FF00000C:\n"
        //"BL     debug_blink\n"
        "LDR     R1, =0xC0410000\n"
        "MOV     R0, #0\n"
        "STR     R0, [R1]\n"
        "MOV     R1, #0x78\n"
        "MCR     p15, 0, R1,c1,c0\n"        // control reg
        "MOV     R1, #0\n"
        "MCR     p15, 0, R1,c7,c10, 4\n"    // drain write buffer
        "MCR     p15, 0, R1,c7,c5\n"        // flush instruction cache
        "MCR     p15, 0, R1,c7,c6\n"        // flush data cache
        "MOV     R0, #0x3D\n"               // size 2GB base 0x00000000
        "MCR     p15, 0, R0,c6,c0\n"        // protection region 0
        "MOV     R0, #0xC000002F\n"         // size 16M base 0xc0000000
        "MCR     p15, 0, R0,c6,c1\n"
        "MOV     R0, #0x37\n"               // asm1989 sx260 ->  0x37  vs SX230 0x35 size 128M base 0x00000000 (s90 is 64M)
        "MCR     p15, 0, R0,c6,c2\n"
        "MOV     R0, #0x40000037\n"         // asm1989 sx260 ->  ...037  vs SX230 size 128M base 0x40000000 (s90 is 64M)
        "MCR     p15, 0, R0,c6,c3\n"
        "MOV     R0, #0x80000017\n"         // size  4k base 0x80000000
        "MCR     p15, 0, R0,c6,c4\n"
        //"LDR     R0, =0xFF80002F\n"       // asm1989 ?? sx260 will we ok? SX230 size  8M base 0xff800000
        "LDR     R0, =0xFF00002F\n"         // asm1989 sx260 real
        "MCR     p15, 0, R0,c6,c5\n"
        "LDR     R0, =0xD000002B\n"         // asm1989 sx260 real & new
        "MCR     p15, 0, R0,c6,c7\n"        // asm1989 sx260 real & new
        "MOV     R0, #0x34\n"
        "MCR     p15, 0, R0,c2,c0\n"
        "MOV     R0, #0x34\n"
        "MCR     p15, 0, R0,c2,c0, 1\n"
        "MOV     R0, #0x34\n"
        "MCR     p15, 0, R0,c3,c0\n"
        "LDR     R0, =0x33333330\n"         //am1989  @ FF000194
        "MCR     p15, 0, R0,c5,c0, 2\n"
        "LDR     R0, =0x33333330\n"         //am1989  @ FF000194
        "MCR     p15, 0, R0,c5,c0, 3\n"
        "MRC     p15, 0, R0,c1,c0\n"
        "ORR     R0, R0, #0x1000\n"
        "ORR     R0, R0, #4\n"
        "ORR     R0, R0, #1\n"
        "MCR     p15, 0, R0,c1,c0\n"
        "MOV     R1, #0x80000006\n"
        "MCR     p15, 0, R1,c9,c1\n"
        "MOV     R1, #6\n"
        "MCR     p15, 0, R1,c9,c1, 1\n"
        "MRC     p15, 0, R1,c1,c0\n"
        "ORR     R1, R1, #0x50000\n"
        "MCR     p15, 0, R1,c1,c0\n"
        "LDR     R2, =0xC0200000\n"
        "MOV     R1, #1\n"
        "STR     R1, [R2,#0x10C]\n"
        "MOV     R1, #0xFF\n"
        "STR     R1, [R2,#0xC]\n"
        "STR     R1, [R2,#0x1C]\n"
        "STR     R1, [R2,#0x2C]\n"
        "STR     R1, [R2,#0x3C]\n"
        "STR     R1, [R2,#0x4C]\n"
        "STR     R1, [R2,#0x5C]\n"
        "STR     R1, [R2,#0x6C]\n"
        "STR     R1, [R2,#0x7C]\n"
        "STR     R1, [R2,#0x8C]\n"
        "STR     R1, [R2,#0x9C]\n"
        "STR     R1, [R2,#0xAC]\n"
        "STR     R1, [R2,#0xBC]\n"
        "STR     R1, [R2,#0xCC]\n"
        "STR     R1, [R2,#0xDC]\n"
        "STR     R1, [R2,#0xEC]\n"
        "STR     R1, [R2,#0xFC]\n"
        "LDR     R1, =0xC0400008\n"
        "LDR     R2, =0x430005\n"
        "STR     R2, [R1]\n"
        "MOV     R1, #1\n"
        "LDR     R2, =0xC0243100\n"
        "STR     R2, [R1]\n"
        "LDR     R2, =0xC0242010\n"
        "LDR     R1, [R2]\n"
        "ORR     R1, R1, #1\n"
        "STR     R1, [R2]\n"
        //"B     sub_FF000138\n"            // Testing back to code hangs
        "LDR     R0, =0xFF680924\n"         // asm1989 changed in sx260  from here down somehow
        "LDR     R1, =0x685000\n"
        "LDR     R3, =0x69544C\n"
"loc_FF000144:\n"
        "CMP     R1, R3\n"
        "LDRCC   R2, [R0],#4\n"
        "STRCC   R2, [R1],#4\n"
        "BCC     loc_FF000144\n"
        "LDR     R0, =0xFF66DAAC\n"
        "LDR     R1, =0x1900\n"
        "LDR     R3, =0x14778\n"
 "loc_FF000160:\n"
        "CMP     R1, R3\n"
        "LDRCC   R2, [R0],#4\n"
        "STRCC   R2, [R1],#4\n"
        "BCC     loc_FF000160\n"
        "LDR     R1, =0x193A24\n"
        "MOV     R2, #0\n"
"loc_FF000178:\n"
        "CMP     R3, R1\n"
        "STRCC   R2, [R3],#4\n"
        "BCC     loc_FF000178\n"
//PATCH
        //"B       sub_FF00038C\n"
        "B       sub_FF00038C_my\n"
//PATCH END
    );
}

//asm1989 sx260 FF00038C
void __attribute__((naked,noinline)) sub_FF00038C_my() {
    *(int*)0x1938=(int)taskHook;            //Bigger Hang asm1989 Apr2012
    *(int*)0x193C=(int)taskHook;            //lesser Hang
    *(int*)(0x2618+0x4) = (*(int*)0xC022F48C)&4 ? 0x200000 : 0x100000;

   asm volatile (
"loc_FF00038C:\n"
        "LDR     R0, =0xFF000404\n"
        "MOV     R1, #0\n"
        "LDR     R3, =0xFF00043C\n"
"loc_FF000398:\n"
        "CMP     R0, R3\n"
        "LDRCC   R2, [R0],#4\n"
        "STRCC   R2, [R1],#4\n"
        "BCC     loc_FF000398\n"
        "LDR     R0, =0xFF00043C\n"
        "MOV     R1, #0x4B0\n"
        "LDR     R3, =0xFF000650\n"
"loc_FF0003B4:\n"
        "CMP     R0, R3\n"
        "LDRCC   R2, [R0],#4\n"
        "STRCC   R2, [R1],#4\n"
        "BCC     loc_FF0003B4\n"
        "MOV     R0, #0xD2\n"
        "MSR     CPSR_cxsf, R0\n"
        "MOV     SP, #0x1000\n"
        "MOV     R0, #0xD3\n"
        "MSR     CPSR_cxsf, R0\n"
        "MOV     SP, #0x1000\n"
        "LDR     R0, =0x6C4\n"
        "LDR     R2, =0xEEEEEEEE\n"
        "MOV     R3, #0x1000\n"
"loc_FF0003E8:\n"
        "CMP     R0, R3\n"
        "STRCC   R2, [R0],#4\n"
        "BCC     loc_FF0003E8\n"
//PATCH BEGIN     sx230: FF0011B0
        //"BL      sub_FF0011E4\n"
        "BL      sub_FF0011E4_my\n"
//PATCH END
    );
}

//asm1989 sx260 FF0011E4
void __attribute__((naked,noinline)) sub_FF0011E4_my() {

    asm volatile (
        "STR     LR, [SP,#-4]!\n"
        "SUB     SP, SP, #0x74\n"
        "MOV     R1, #0x74\n"
        "MOV     R0, SP\n"
        "BL      sub_00690448\n"            // RAM
        //"B         sub_FF0011F8\n"        // BACK TO CODE
        "MOV     R0, #0x67000\n"
        "STR     R0, [SP,#4]\n"
//PATCH BEGIN
        //"LDR     R0, =0x193A24\n"
        "LDR     R0, =new_sa\n"
        "LDR     R0, [R0]\n"
//PATCH END
        "LDR     R2, =0x55D440\n"
        "STR     R0, [SP,#8]\n"
        "SUB     R0, R2, R0\n"
        "STR     R0, [SP,#0xC]\n"
        "MOV     R0, #0x22\n"
        "STR     R0, [SP,#0x18]\n"
        "MOV     R0, #0x7C\n"
        "STR     R0, [SP,#0x1C]\n"
        "LDR     R1, =0x565C00\n"
        "LDR     R0, =0x1CD\n"
        "STR     R1, [SP]\n"
        "STR     R0, [SP,#0x20]\n"
        "MOV     R0, #0x96\n"
        "STR     R2, [SP,#0x10]\n"
        "STR     R1, [SP,#0x14]\n"
        "STR     R0, [SP,#0x24]\n"
        "STR     R0, [SP,#0x28]\n"
        "MOV     R0, #0x64\n"
        "STR     R0, [SP,#0x2C]\n"
        "MOV     R0, #0\n"
        "STR     R0, [SP,#0x30]\n"
        "STR     R0, [SP,#0x34]\n"
        "MOV     R0, #0x10\n"
        "STR     R0, [SP,#0x5C]\n"
        "MOV     R0, #0x800\n"
        "STR     R0, [SP,#0x60]\n"
        "MOV     R0, #0xA0\n"
        "STR     R0, [SP,#0x64]\n"
        "MOV     R0, #0x280\n"
        "STR     R0, [SP,#0x68]\n"
//PATCH BEGIN
        //"LDR     R1, =sub_FF004294\n"
        "LDR     R1, =sub_FF004294_my\n"
//PATCH END
        "MOV     R2, #0\n"
        "MOV     R0, SP\n"
        "BL      sub_00686778\n"            // RAM
        "ADD     SP, SP, #0x74\n"
        "LDR     PC, [SP],#4\n"
    );
}

//asm1989 sx260 is FF004294
void __attribute__((naked,noinline)) sub_FF004294_my() {

    asm volatile (
        "STMFD   SP!, {R4,LR}\n"
        "BL      sub_FF000B5C\n"
        "BL      sub_FF0053B8\n"            // BL dmSetup
        "CMP     R0, #0\n"
        "LDRLT   R0, =0xFF0043A8\n"         // "dmSetup"
        "BLLT    sub_FF004388\n"
        "BL      sub_FF003ECC\n"
        "CMP     R0, #0\n"
        "LDRLT   R0, =0xFF0043B0\n"         // "termDriverInit"
        "BLLT    sub_FF004388\n"
        "LDR     R0, =0xFF0043C0\n"         // "/_term"
        "BL      sub_FF003FB4\n"
        "CMP     R0, #0\n"
        "LDRLT   R0, =0xFF0043C8\n"         // "termDeviceCreate"
        "BLLT    sub_FF004388\n"
        "LDR     R0, =0xFF0043C0\n"         //  "/_term"
        "BL      sub_FF0029D4\n"
        "CMP     R0, #0\n"
        "LDRLT   R0, =0xFF0043DC\n"         // "stdioSetup"
        "BLLT    sub_FF004388\n"
        "BL      sub_FF004D54\n"
        "CMP     R0, #0\n"
        "LDRLT   R0, =0xFF0043E8\n"         // "stdlibSetup"
        "BLLT    sub_FF004388\n"
        "BL      sub_FF0016D4\n"
        "CMP     R0, #0\n"
        "LDRLT   R0, =0xFF0043F4\n"         // "armlib_setup"
        "BLLT    sub_FF004388\n"
        "LDMFD   SP!, {R4,LR}\n"
//PATCH BEGIN
        //"B  sub_FF00B1C0\n"
        //"B       sub_FF00B1C0_my\n"       //asm1989 inserted sx260
        "B       taskcreate_Startup_my\n"
//PATCH END
    );
};

//asm1989 FF00B1C0
void __attribute__((naked,noinline)) taskcreate_Startup_my() {

    asm volatile (
        "STMFD   SP!, {R3,LR}\n"
        "BL      sub_0068C118\n"            // RAM
        "BL      sub_0068C330\n"            // RAM
        "MOV     R3, #0\n"
        "STR     R3, [SP]\n"
//PATCH BEGIN
        //"LDR     R3, =0xFF00B19C\n"       // Sx230: FF00FC6C
        "LDR     R3, =sub_FF00B19C_my \n"   //-->
        //"LDR     R3, =taskcreate_Startup_my\n"
//PATCH END
        "MOV     R2, #0x200\n"
        "MOV     R1, #0x19\n"
        "LDR     R0, =0xFF00B2C8\n"         //   "Booting"
        "BL      sub_0068AB00\n"            // RAM
        "MOV     R0, #0\n"
        "LDMFD   SP!, {R3,PC}\n"
    );
}

//asm1989 sx260: FF00B19C
 void __attribute__((naked,noinline)) sub_FF00B19C_my(){
    asm volatile (
        "STMFD   SP!, {R4,LR}\n"
        "BL      sub_FF01F2E8\n"            // j_nullsub_33
        "BL      sub_FF02040C\n"
        "BL      sub_FF01E134\n"
        "BL      sub_FF0272DC\n"
        "BL      sub_FF01E854\n"
        "BL      sub_FF01D8E8\n"
        "LDMFD   SP!, {R4,LR}\n"
        //"B      sub_FF00B1F0\n"
        "B      sub_FF00B1F0_my\n"          // Guess here
    );
}

void __attribute__((naked,noinline)) sub_FF00B1F0_my(){
    asm volatile (
        "STMFD   SP!, {R3-R7,LR}\n"
        "BL      sub_FF027078\n"
        "MOVS    R6, R0\n"
        "BNE     loc_FF00B254\n"
        "BL      sub_FF020D40\n"
        "CMP     R0, #0\n"
        "BEQ     loc_FF00B254\n"
        "MOV     R0, #0x37\n"
        "BL      sub_FF0255E8\n"
        "RSBS    R5, R0, #1\n"
        "MOVCC   R5, #0\n"
        "MOV     R0, #0x36\n"
        "BL      sub_FF0255E8\n"
        "RSBS    R4, R0, #1\n"
        "MOVCC   R4, #0\n"
        "ORRS    R0, R4, R5\n"
        "BNE     loc_FF00B274\n"
        "BL      sub_FF01E2C0\n"
        "BL      sub_0068A7F8\n"            // RAM
        "LDR     R2, =0xC022C000\n"
        "LDR     R1, [R2,#0x30C]\n"
        "BIC     R1, R1, #0x300\n"
        "STR     R1, [R2,#0x30C]\n"
        "BL      sub_0068A7FC\n"            // RAM
"loc_FF00B250:\n"
        "B       loc_FF00B250\n"
"loc_FF00B254:\n"
        "MOV     R0, #0x36\n"
        "BL      sub_FF0255E8\n"
        "RSBS    R4, R0, #1\n"
        "MOVCC   R4, #0\n"
        "MOV     R0, #0x37\n"
        "BL      sub_FF0255E8\n"
        "RSBS    R5, R0, #1\n"
        "MOVCC   R5, #0\n"
"loc_FF00B274:\n"
        "MOV     R3, #0\n"
        "MOV     R2, R6\n"
        "MOV     R1, R5\n"
        "MOV     R0, R4\n"
//PATCH START
        //"BL      sub_FF01F2F0\n"          //asm1989 for sx260 we must remove this for power-on mode handling to work
//PATCH END
        "BL      sub_FF01F2EC\n"            //j_nullsub_34
        "BL      sub_0068C118\n"            // RAM
        "LDR     R1, =0x5CE000\n"
        "MOV     R0, #0\n"
        "BL      sub_FF0253D4\n"
        "BL      sub_0068C330\n"            // RAM
        "MOV     R3, #0\n"
        "STR     R3, [SP]\n"
//BEGIN PATCH
        //"LDR    R3, =0xFF00B140\n"
        "LDR     R3, =task_Startup_my\n"
//END PATCH
        "MOV     R2, #0\n"
        "MOV     R1, #0x19\n"
        "LDR     R0, =0xFF00B2DC\n"         // changed ADR to LDR; "Startup"
        "BL      sub_0068AB00\n"            // RAM
        "LDMFD   SP!, {R3-R7,PC}\n"
    );
}

//asm1989 sx260 FF00B140
void __attribute__((naked,noinline)) task_Startup_my() {

   asm volatile (
        "STMFD   SP!, {R4,LR}\n"
        "BL      sub_FF0048D4\n"            //clocksave
        //"BL      sub_FF0270F0\n"          //j_nullsub_42
//PATCH BEGIN
        //"BL      sub_FF027184\n"          //asm1989 looks like start diskboot.bin
//PATCH END
        "BL      sub_FF027444\n"
        "BL      sub_FF027610\n"            //Looks new of this cam?
        "BL      sub_FF027438\n"            //nullsub_3
        "BL      sub_FF02730C\n"
        "BL      sub_FF025308\n"
        "BL      sub_FF027618\n"
//PATCH START
        "BL      CreateTask_spytask\n"
        //"BL      sub_FF01F188\n"          //physw
        "BL      taskcreatePhySw_my\n"
//PATCH END
        "BL      sub_FF022C40\n"
        "BL      sub_FF027630\n"
        "BL      sub_FF01C544\n"
        "BL      sub_FF01D244\n"            //battery
        "BL      sub_FF026DE8\n"
        "BL      sub_FF01D88C\n"
        "BL      sub_FF01D1E0\n"            // "BatteryTask"
        "BL      sub_FF02743C\n"            //nullsub_4
        "BL      sub_FF028280\n"            //StartFactoryModeController
        "BL      sub_FF01D1A4\n"
        "LDMFD   SP!, {R4,LR}\n"
        "B       sub_FF004A10\n"
    );
}

//asm1989 sx260 -> FF01F188
void __attribute__((naked,noinline)) taskcreatePhySw_my() {

    asm volatile (
         "STMFD   SP!, {R3-R5,LR}\n"
         "LDR     R4, =0x1C60\n"
         "LDR     R0, [R4,#4]\n"
         "CMP     R0, #0\n"
         "BNE     sub_FF01F1BC\n"
         "MOV     R3, #0\n"
         "STR     R3, [SP]\n"
//PATCH BEGIN
        "LDR     R3, =mykbd_task\n"
        //"LDR     R3, =0xFF01F154 \n"
        //"MOV     R2, #0x800\n"
        "MOV     R2, #0x2000\n"             // stack size for new task_PhySw so we don't have to do stack switch
//PATCH END
        //"B       sub_FF01F1AC\n"          // Back to code
        "MOV     R1, #0x17 \n"
        "LDR     R0, =0xFF01F3E8 \n"
        "BL      sub_0068ADD8 \n"           //RAM
        "STR     R0, [R4, #4] \n"
"loc_FF01F1BC:\n"
        "BL      sub_FF04E1D0 \n"
        "BL      sub_FF07E750 \n"
        "BL      sub_FF020C90 \n"
        "CMP     R0, #0 \n"
        "BNE     loc_FF01F1DC \n"
        "LDR     R1, =0x388F0 \n"
        "MOV     R0, #0 \n"
        "BL      sub_FF07E6C0 \n"
"loc_FF01F1DC:\n"
        "LDMFD   SP!, {R3-R5,PC} \n"
    );
}

//AMS1989 TESTED almost til here!!
void spytask(long ua, long ub, long uc, long ud, long ue, long uf) {
    core_spytask();
}

void CreateTask_spytask() {
    _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
};

//asm1989 sx260 looks like FF08BBC4
void __attribute__((naked,noinline)) init_file_modules_task() {
    asm volatile(
//FF08BBC4
        "STMFD   SP!, {R4-R6,LR}\n"
        "BL      sub_FF080D64\n"
        "LDR     R5, =0x5006\n"
        "MOVS    R4, R0\n"
        "MOVNE   R1, #0\n"
        "MOVNE   R0, R5\n"
        "BLNE    sub_FF0859D8\n"
//PATCH BEGIN
        "BL      sub_FF080D98\n"
        "BL      core_spytask_can_start\n"
//PATCH END

//TODO REMOVE REST OF FUNCTION
        "CMP     R4, #0\n"
        "LDMNEFD SP!, {R4-R6,PC}\n"
        "MOV     R0, R5\n"
        "LDMFD   SP!, {R4-R6,LR}\n"
        "MOV     R1, #0\n"
        "B       sub_FF0859D8\n"
    );
}

short *jog_position;

//asm1989 sx260 looks like FF04DEB0  sx230 :FF0579AC
void __attribute__((naked,noinline)) JogDial_task_my() {
 asm volatile(
        "STMFD   SP!, {R4-R11,LR}\n"
        "SUB     SP, SP, #0x1C\n"
        "BL      sub_FF04E23C\n"
        "LDR     R12, =0x262C\n"
        "LDR     R6, =0xFF441730\n"
        "MOV     R0, #0\n"
        "ADD     R10, SP, #8\n"
        "ADD     R9, SP, #0xC\n"
//PATCH
        // Save pointer for kbd.c routine
        "LDR     R2, =jog_position\n"
        "STR     R9, [R2]\n"
//END PATCH

"loc_FF04DED0:\n"
        "ADD     R2, SP, #0x14\n"
        "MOV     R1, #0\n"
        "ADD     R4, R2, R0,LSL#1\n"
        "ADD     R3, SP, #0x10\n"
        "STRH    R1, [R4]\n"
        "ADD     R4, R3, R0,LSL#1\n"
        "STRH    R1, [R4]\n"
        "STR     R1, [R9,R0,LSL#2]\n"
        "STR     R1, [R10,R0,LSL#2]\n"
        "ADD     R0, R0, #1\n"
        "CMP     R0, #1\n"
        "BLT     loc_FF04DED0\n"
"loc_FF04DF00:\n"
        "LDR     R0, =0x262C\n"
        "MOV     R2, #0\n"
        "LDR     R0, [R0,#8]\n"
        "MOV     R1, SP\n"
        "BL      sub_0068BBE4\n"            // RAM
        "CMP     R0, #0\n"
        "LDRNE   R1, =0x200\n"
        "LDRNE   R0, =0xFF04E15C\n"         //aRotaryencoder_ ; "RotaryEncoder.c" ADRNE to LDRNE
        "BLNE    sub_0068AFD8\n"            // RAM
        "LDR     R0, [SP]\n"
        "AND     R4, R0, #0xFF\n"
        "AND     R0, R0, #0xFF00\n"
        "CMP     R0, #0x100\n"
        "BEQ     loc_FF04DF70\n"
        "CMP     R0, #0x200\n"
        "BEQ     loc_FF04DFA8\n"
        "CMP     R0, #0x300\n"
        "BEQ     loc_FF04E1A0\n"
        "CMP     R0, #0x400\n"
        "BNE     loc_FF04DF00\n"
        "CMP     R4, #0\n"
        "LDRNE   R1, =0x27A\n"
        "LDRNE   R0, =0xFF04E15C\n"         //aRotaryencoder_ ; "RotaryEncoder.c" ADRNE to LDRNE
        "BLNE    sub_0068AFD8\n"            // RAM
        "RSB     R0, R4, R4,LSL#3\n"
        "LDR     R0, [R6,R0,LSL#2]\n"
"loc_FF04DF68:\n"
        "BL      sub_FF04E220\n"
        "B       loc_FF04DF00\n"
"loc_FF04DF70:\n"
//PATCH BEGIN
"labelA:\n"
        "LDR     R0, =jogdial_stopped\n"
        "LDR     R0, [R0]\n"
        "CMP     R0, #1\n"
        "BNE     labelB\n"
        "MOV     R0, #40\n"
//asm1989 Maybe wrong!!!
        //"LDR     R1, =0x68C2E8\n"         //asm1989 couldnt find sleeptask useg
        //"LDR     R0, =0xFF1BA27C\n"       //asm1989 couldnt find sleeptask useg
        "BL      sub_0068C2E8\n"            //sleeptask
        "B       labelA\n"
"labelB:\n"
//PATCH END
        "LDR     R0, =0x2638\n"
        "LDR     R0, [R0,R4,LSL#2]\n"
        "BL      sub_FF025BC4\n"
        "LDR     R2, =0xFF04DDFC\n"
        "ORR     R3, R4, #0x200\n"
        "ADD     R1, R2, #0\n"
        "MOV     R0, #0x28\n"
        "BL      sub_FF025AE0\n"
        "TST     R0, #1\n"
        "CMPNE   R0, #0x15\n"
        "STR     R0, [R10,R4,LSL#2]\n"
        "BEQ     loc_FF04DF00\n"
        "LDR     R1, =0x212\n"
        "B       loc_FF04E14C\n"
"loc_FF04DFA8:\n"
        "RSB     R5, R4, R4,LSL#3\n"
        "LDR     R0, [R6,R5,LSL#2]\n"
        "LDR     R1, =0xC0240000\n"
        "ADD     R0, R1, R0,LSL#8\n"
        "LDR     R0, [R0,#0x104]\n"
        "MOV     R1, R0,ASR#16\n"
        "ADD     R0, SP, #0x14\n"
        "ADD     R11, R0, R4,LSL#1\n"
        "ADD     R0, SP, #0x10\n"
        "ADD     R0, R0, R4,LSL#1\n"
        "STRH    R1, [R11]\n"
        "STR     R0, [SP,#0x18]\n"
        "LDRSH   R3, [R0]\n"
        "SUB     R2, R1, R3\n"
        "CMP     R2, #0\n"
        "BNE     loc_FF04E02C\n"
        "LDR     R0, [R9,R4,LSL#2]\n"
        "CMP     R0, #0\n"
        "BEQ     loc_FF04E108\n"
        "LDR     R7, =0x2638\n"
        "LDR     R0, [R7,R4,LSL#2]\n"
        "BL      sub_FF025BC4\n"
        "LDR     R2, =sub_FF04DE08\n"       //don't delete this comment! add address to stubs_auto.S: "B sub_FF04DE08"
        "ORR     R3, R4, #0x300\n"
        "ADD     R1, R2, #0\n"
        "MOV     R0, #0x1F4\n"
        "BL      sub_FF025AE0\n"
        "TST     R0, #1\n"
        "CMPNE   R0, #0x15\n"
        "STR     R0, [R7,R4,LSL#2]\n"
        "BEQ     loc_FF04E108\n"
        "LDR     R1, =0x22B\n"
        "B       loc_FF04E100\n"
"loc_FF04E02C:\n"
        "MOV     R0, R2\n"
        "RSBLT   R0, R0, #0\n"
        "MOVLE   R7, #0\n"
        "MOVGT   R7, #1\n"
        "CMP     R0, #0xFF\n"
        "BLS     loc_FF04E068\n"
        "LDR     R0, =0x7FFF\n"
        "CMP     R2, #0\n"
        "SUBLE   R0, R0, R3\n"
        "ADDLE   R0, R0, R1\n"
        "SUBGT   R0, R0, R1\n"
        "ADDGT   R0, R0, R3\n"
        "MVN     R1, #0x8000\n"
        "SUB     R0, R0, R1\n"
        "EOR     R7, R7, #1\n"
"loc_FF04E068:\n"
        "STR     R0, [SP,#0x4]\n"
        "LDR     R0, [R9,R4,LSL#2]\n"
        "CMP     R0, #0\n"
        "ADDEQ   R0, R6, R5,LSL#2\n"
        "LDREQ   R0, [R0,#8]\n"
        "BEQ     loc_FF04E0A0\n"
        "ADD     R8, R6, R5,LSL#2\n"
        "ADD     R1, R8, R7,LSL#2\n"
        "LDR     R1, [R1,#0x10]\n"
        "CMP     R1, R0\n"
        "BEQ     loc_FF04E0A4\n"
        "LDR     R0, [R8,#0xC]\n"
        //"MOV     R1, #0\n"                // not in sx260
        "BL      sub_FF01F1E0\n"
        "LDR     R0, [R8,#8]\n"
"loc_FF04E0A0:\n"
        //"MOV     R1, #0\n"
        "BL      sub_FF01F1E0\n"
"loc_FF04E0A4:\n"
        "ADD     R0, R6, R5,LSL#2\n"
        "ADD     R7, R0, R7,LSL#2\n"
        "LDR     R0, [R7,#0x10]\n"
        "LDR     R1, [SP,#0x4]\n"
        "BL      sub_FF01F1F0\n"
        "LDR     R0, [R7,#0x10]\n"
        "LDR     R7, =0x2638\n"
        "STR     R0, [R9,R4,LSL#2]\n"
        "LDRH    R1, [R11]\n"
        "LDR     R0, [SP,#0x18]\n"
        "STRH    R1, [R0]\n"
        "LDR     R0, [R7,R4,LSL#2]\n"
        "BL      sub_FF025BC4\n"
        "LDR     R2, =0xFF04DE08\n"
        "ORR     R3, R4, #0x300\n"
        "ADD     R1, R2, #0\n"
        "MOV     R0, #0x1F4\n"
        "BL      sub_FF025AE0\n"
        "TST     R0, #1\n"
        "CMPNE   R0, #0x15\n"
        "STR     R0, [R7,R4,LSL#2]\n"
        "BEQ     loc_FF04E108\n"
        "LDR     R1, =0x25C\n"
"loc_FF04E100:\n"
        "LDR     R0, =0xFF04E15C\n"         // ; "RotaryEncoder.c"
        "BL      sub_0068AFD8\n"            // RAM
"loc_FF04E108:\n"
        "ADD     R0, R6, R5,LSL#2\n"
        "LDR     R0, [R0,#0x18]\n"
        "CMP     R0, #1\n"
        "BNE     loc_FF04E198\n"            // ---> (1)
        "LDR     R0, =0x262C\n"
        "LDR     R0, [R0,#0x10]\n"
        "CMP     R0, #0\n"
        "BEQ     loc_FF04E198\n"
        "LDR     R2, =0xFF04DDFC\n"
        "ORR     R3, R4, #0x400\n"
        "ADD     R1, R2, #0\n"
        "BL      sub_FF025AE0\n"
        "TST     R0, #1\n"
        "CMPNE   R0, #0x15\n"
        "STR     R0, [R10,R4,LSL#2]\n"
        "BEQ     loc_FF04DF00\n"
        "LDR     R1, =0x263\n"
"loc_FF04E14C:\n"
        "LDR     R0, =0xFF04E15C\n"         // ; "RotaryEncoder.c"
        "BL      sub_0068AFD8\n"            // RAM
        "B       loc_FF04DF00\n"
"loc_FF04E198:\n"                           // (1) <---
        "LDR     R0, [R6,R5,LSL#2]\n"
        "B       loc_FF04DF68\n"
"loc_FF04E1A0:\n"
        "LDR     R0, [R9,R4,LSL#2]\n"
        "CMP     R0, #0\n"
        "LDREQ   R1, =0x26D\n"
        "LDREQ   R0, =0xFF04E15C\n"         // ; "RotaryEncoder.c"
        "BLEQ    sub_0068AFD8\n"            //RAM
        "RSB     R0, R4, R4,LSL#3\n"
        "ADD     R0, R6, R0,LSL#2\n"
        "LDR     R0, [R0,#0xC]\n"
        //"MOV     R1, #0\n"
        "BL      sub_FF01F1E0\n"
        "MOV     R0, #0\n"
        "STR     R0, [R9,R4,LSL#2]\n"
        "B       loc_FF04DF00\n"
    );

}
