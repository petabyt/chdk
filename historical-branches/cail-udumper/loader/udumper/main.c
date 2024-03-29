
#include <stdio.h>

#include <coproc.h>

/**
 * LED blinking code
 */
int leds[] = { 0xc0220080, 0xc0220084, 0xc0220088, 0 };

void leds_on() {
   int i = 0;
   for(i = 0; leds[i]; i++) {
     *(int*)(leds[i]) = 0x46;
   }
}
void leds_off() {
   int i = 0;
   for(i = 0; leds[i]; i++) {
     *(int*)(leds[i]) = 0x44;
   }
}

void leds_flash_f(int f)
{
   int i, j, a;

   leds_off();
   for(j = 0; j < 1; j++)
   {
     leds_on();
     for(i = 0; i < 10000*f; i++) {
       asm("nop\n");
       asm("nop\n");
     }
     leds_off();
     for(i = 0; i < 10000*f; i++) {
       asm("nop\n");
       asm("nop\n");
     }
   }
}

#define leds_flash() leds_flash_f(10)








// TODO: findout these values
// Basically these are at 0x8 and 0x10 offsets, but normally vxWorks puts there "LDR PC, #100"
#define PREFETCH_HANDLER ((int*)0x108)
#define DATA_HANDLER     ((int*)0x10C)
// TODO!!!
#define DATA_ABORT_INSTR ((int*)0x10)


// TODO: These addresses should be found analytically
// basing on RegisterEventTable functionality (extract_event_procedures.c)
FILE * (*my_fopen)(char *, char*) = 0xffb0a2c8;
void (*my_fclose)(FILE *) = 0xffb09bc0;
int (*my_fwrite)(void*, int, int, FILE*) = 0xffb0b068;
void (*my_CreateTask)(char *, int, int, void*, int) = 0xff82161c;

// To make life easier
#define fopen my_fopen
#define fclose my_fclose
#define fwrite my_fwrite
#define CreateTask my_CreateTask





//�This is just for the information - we don't need prefetch abort handler

int prefetch_count = 0;

void prefetch_abort_action()
{
    prefetch_count++;
}

void __attribute((naked)) prefetch_abort_handler()
{
    asm volatile
    (
        "STMDB	 sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, lr}\n"
        "BL      prefetch_abort_action\n"
        "LDMIA	 sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, lr}\n"
        "SUBS    PC, R14, #4\n" // Retries the instruction!

//        "LDR     pc, vxworks_prefetch_abort_handler\n"

        // vxWorks original handler stored here
        ".GLOBL  vxworks_prefetch_abort_handler;\n"
        "vxworks_prefetch_abort_handler:;\n"
        "MOV     R0, R0\n"
    
    );
}




/**
 * Our future!
 * This task should be activated from our hooking code after the vxWorks start
 * It simply uses FIO to dump ROM and BOOTLOADER onto flash
 */
void task_spywriter()
{
    int i;

    leds_on();

    FILE *fd = fopen("A/rom.dat", "w");
    for(i = 0; i < 0x400000; i += 0x1000){
      fwrite((void*)(0xFF800000+i), 0x1000, 1, fd);
    }
    fclose(fd);

    fd = fopen("A/boot.dat", "w");
    for(i = 0; i < 0x10000; i += 0x1000){
      fwrite((void*)(0xFFFF0000+i), 0x1000, 1, fd);
    }
    fclose(fd);

    leds_off();

    while(1){
      leds_flash();
    };
}

/**
 * Data Abort Handler!
 * The heart of the hack!
 */

int data_count = 0;

/**
 * Action to be executed in super mode
 * @param sp Stack pointer
 */
int data_abort_action(int sp)
{
    int creg;

    leds_flash();

    if (data_count == 10) {
      
      // trying to signaling - no success yet ;(
      leds_flash_f(1);
      leds_flash_f(1);
      leds_flash_f(1);
      leds_flash_f(1);
      leds_flash_f(1);

      // Fallback to real mode
      MRC(creg, p15, c1, c0, 0, 0);
      MCR(creg & ~1, p15, c1, c0, 0, 0);
      // Changing our bank no.6 -  setting address and size
      MCR( (0x600000) + (0xb<<1) + 1, p15, c6, c6, 0, 0);
      // Go back to protected mode
      MCR(creg | 1, p15, c1, c0, 0, 0);
    }

    if (data_count > 10) {
      leds_flash_f(1);
      leds_flash_f(1);
      leds_flash_f(1);
      leds_flash_f(1);
      leds_flash_f(1);
      
      // remove this bank
      MRC(creg, p15, c1, c0, 0, 0);
      MCR(creg & ~1, p15, c1, c0, 0, 0);
      MCR( (0x0) + (0xb<<1) + 0, p15, c6, c6, 0, 0);
      MCR(creg | 1, p15, c1, c0, 0, 0);

      // we return "1" - thus triggering our hook task creation
      return 1;
    }

    data_count++;

    // abort_retval == 0 - perform no post action
    return 0;

}


/**
 * The data abort handler itself!
 */
void __attribute((naked)) data_abort_handler()
{
    asm volatile
    (
        // Store everything
        "STMDB	 sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}\n"
        
        // Store the instruction to reexecute (which we breaked on)
        "LDR     R0, [R14, #-8]\n"
        "STR     R0, reexecute\n"

        // Trying to reset the cache
        // WARNING: ARM946ES specific!!!
        "MOV     R0, #0\n"
        "MCR     p15, 0, r0, c7, c5, 0\n"

        // execute our supervisor-side action
        "MOV     R0, SP\n"
        "BL      data_abort_action\n"
        "STR     R0, abort_retval\n"

        // restoring all the registers
        "LDMIA	 sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}\n"

        // save real return address - next address (+4) after the trapped data access instruction
        "SUB     R14, R14, #4\n"
        "STR     R14, retlabel\n"
        "ADD     R14, R14, #4\n"

        // return from abort mode!!!
        "SUBS    PC, PC, #-4\n"
        "MOV     R0, R0\n"
        "MOV     R0, R0\n"
        "MOV     R0, R0\n"
        "MOV     R0, R0\n"

        // using our own stack
        "STR     SP, sp_value\n"
        "LDR     SP, mystack_addr\n"
        
        // execute our user-side action
        // Note! here we are already in normal execution mode, not _abt!
        "STMDB	 sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}\n"
        // Loading our stored parameter
        "LDR     R0, abort_retval\n"
        "BL      data_abort_action_usermode\n"
        "LDMIA	 sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}\n"

        "LDR     SP, sp_value\n"

        // Disable Protection Unit
        "STMDB	 sp!, {r0}\n"
        "MRC     p15, 0, r0, c1, c0, 0\n"
        "BIC     r0, #1\n"
        "MCR     p15, 0, r0, c1, c0, 0\n"
        "LDMIA	 sp!, {r0}\n"

        // Instruction to be re-executed, but with disabled Protection Unit!
        // Warning!!! 
        // Self modifying code - ARM cache should be invalidated!
        ".GLOBL  reexecute;\n"
        "reexecute:;\n"
        "MOV     R0, R0\n"

        // Enable PU back
        "STMDB	 sp!, {r0}\n"
        "MRC     p15, 0, r0, c1, c0, 0\n"
        "ORR     r0, #1\n"
        "MCR     p15, 0, r0, c1, c0, 0\n"
        "LDMIA	 sp!, {r0}\n"

        // jump back to saved return address
        "LDR     PC, retlabel\n"

        ///////////////// Variables //////////////////

        // location to store return addrress
        "retlabel:;\n"
        "MOV     R0, R0\n"

        // stored return value of the abort action handler
        "abort_retval:;\n"
        "MOV     R0, R0\n"

        "sp_value:;\n"
        "MOV     R0, R0\n"

        "mystack_addr:;\n"
        ".word   mystack\n"
        ".word   0\n"

        ".word   0, 0, 0, 0, 0, 0, 0, 0\n"
        ".word   0, 0, 0, 0, 0, 0, 0, 0\n"
        ".word   0, 0, 0, 0, 0, 0, 0, 0\n"
        ".word   0, 0, 0, 0, 0, 0, 0, 0\n"
        ".word   0, 0, 0, 0, 0, 0, 0, 0\n"
        ".word   0, 0, 0, 0, 0, 0, 0, 0\n"
        ".word   0, 0, 0, 0, 0, 0, 0, 0\n"
        ".word   0, 0, 0, 0, 0, 0, 0, 0\n"
        ".word   0, 0, 0, 0, 0, 0, 0, 0\n"
        ".word   0, 0, 0, 0, 0, 0, 0, 0\n"
        ".word   0, 0, 0, 0, 0, 0, 0, 0\n"
        ".word   0, 0, 0, 0, 0, 0, 0, 0\n"
        ".word   0, 0, 0, 0, 0, 0, 0, 0\n"
        ".word   0, 0, 0, 0, 0, 0, 0, 0\n"
        "mystack:;\n"
        ".word   0\n"

        // vxWorks original handler stored here
        // Not used for now
        ".GLOBL  vxworks_data_abort_handler;\n"
        "vxworks_data_abort_handler:;\n"
        "MOV     R0, R0\n"

        // Jump to VxWorks handler
//        "LDR     PC, vxworks_data_abort_handler\n"
        // These are from arm docs:
//        "SUBS    PC, R14, #8\n"    // Retries the instruction!
//        "SUBS    PC, R14, #4\n"    // Moves to the next instruction!    
    );

}

/**
 * Action to be executed in user mode
 */
void data_abort_action_usermode(int abort_retval)
{
    int creg;

    MRC(creg, p15, c1, c0, 0, 0);
    MCR(creg & ~1, p15, c1, c0, 0, 0);
    *DATA_HANDLER = (int)data_abort_handler;
    MCR(creg | 1, p15, c1, c0, 0, 0);

    // Execute it only if data_abort_action returns TRUE
    if (abort_retval) {
        CreateTask("SpyWriter", 0x19, 0x4000, task_spywriter, 0);
    }
}




extern int vxworks_prefetch_abort_handler;
extern int vxworks_data_abort_handler;



int main()
{
    leds_flash();
    
    int creg = 0;
    int accperm_data = 0;
    int accperm_code = 0;

    // Disable Memory Protection Unit
    MRC(creg, p15, c1, c0, 0, 0);
    MCR(creg & ~1, p15, c1, c0, 0, 0);

    // Changing abort handlers: 0x0C and 0x10 (prefetch and data aborts)
//    vxworks_prefetch_abort_handler = *PREFETCH_HANDLER;
//    *PREFETCH_HANDLER = (int)prefetch_abort_handler;
//    vxworks_data_abort_handler = *DATA_HANDLER;
    *DATA_HANDLER = (int)data_abort_handler;
    
    asm volatile
    (
        // Add new memory bank to control //0x700000  0xb
        "LDR     r0, bank6\n"
        "MCR     p15, 0, r0, c6, c6, 0\n"
        
        "LDR     r0, const1\n"
        "MCR     p15, 0, r0, c5, c0, 2\n"
        "MCR     p15, 0, r0, c5, c0, 3\n"
        "B       jump\n"
        
        // Protection for all the regions. 3 - r/w full access, 6 - r/o access
        "const1:;\n"
        ".word 0x06333333\n"

        // Bank address and size encoding
        "bank6:;\n"
        //(0xb<<1) + 1
        ".word 0x17\n"

        "jump:;\n"

        ::: "r0"
    );

    leds_flash();
    
    // ReEnable Memory Protection Unit
    MCR(creg | 1, p15, c1, c0, 0, 0);

    leds_flash();


    while(1){

      *DATA_HANDLER = (int)data_abort_handler;

    }

    // Go to vxWorks!
    // Not working yet! ;(
    asm volatile
    (
        "LDR     SP, =0x1900\n"
        "LDR PC, startaddr\n"
        
        "startaddr:;\n"
        // TODO: fix this location??
        // Probably we have to find out it analytically
        ".word 0xFF8100E0\n"

    );

}
