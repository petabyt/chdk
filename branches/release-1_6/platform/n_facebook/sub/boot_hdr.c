// Powershot N Facebook
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_MovieRecord();
extern void task_ExpDrv();
extern void task_FileWrite();
extern void task_TouchPanel();

/*----------------------------------------------------------------------
    Blink - flash power LED a couple of times
-----------------------------------------------------------------------*/
void pause()
{
 int i ;
 for (i=0; i<1000000; i++) { asm volatile ("nop\n"); }
}

void led_on() { *(int*)0xc022c30c = ( (*(int*)0xc022c30c) & 0xffffffcf ) | 0x20; }

void led_off() { *(int*)0xc022c30c = (*(int*)0xc022c30c) & 0xffffffcf; }

void blink() {
   int i ;
   for (i=1 ; i < 6 ; i++)
   {
      led_on() ;
      pause() ;
      led_off() ;
      pause() ;
   }
}

/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask()
{
    _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}

/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/


