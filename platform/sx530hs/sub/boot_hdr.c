#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_RotaryEncoder();
//extern void task_MovieRecord();
extern void task_ExpDrv();
//extern void task_FileWrite();

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
	_CreateTask("SpyTask", 0x19, 0x2000, spytask, 0);
}

///*----------------------------------------------------------------------
// Pointer to stack location where jogdial task records previous and current
// jogdial positions
short *jog_position;

#define GREEN_LED       0xC022D1FC
#define AF_LED          0xC022D034
//debug use only

int debug_blink(int save_R0) {
	int i;
	*((volatile int *) GREEN_LED) = 0x93d800; // Turn on LED
	for (i=0; i<800000; i++) // Wait a while
		{
    		asm volatile ( "nop\n" );
		}

	*((volatile int *) GREEN_LED) = 0x83dc00; // Turn off LED
	for (i=0; i<800000; i++) // Wait a while
		{
    		asm volatile ( "nop\n" );
		}
	return save_R0;
};

void __attribute__((naked,noinline)) my_blinker(int n) {
	asm volatile (
      "            STMFD   SP!, {R0-R9,LR}\n"
);
	int i, j;
	for (j=0; j<n; j++)
	{
		*((volatile int *) GREEN_LED) = 0x93d800; // Turn on LED
		for (i=0; i<0x200000; i++) { asm volatile ( "nop \n" ); }

		*((volatile int *) GREEN_LED) = 0x83dc00; // Turn off LED
		for (i=0; i<0x400000; i++) { asm volatile ( "nop \n" ); }
	}
	for (i=0; i<0x900000; i++) { asm volatile ( "nop \n" ); }
	asm volatile (
      "            LDMFD   SP!, {R0-R9,PC}\n"
	);
}

/*----------------------------------------------------------------------
	boot()

	Main entry point for the CHDK code
-----------------------------------------------------------------------*/
