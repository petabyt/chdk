#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

#define LED_GREEN  0xC0220130
#define LED_ORANGE 0xC0220134
#define LED_AF     0xC0223030

const char * const new_sa = &_end;

// Forward declarations
void Battery_door_hack();

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_MovieRecord();
extern void task_ExpDrv();
extern void task_FileWrite();

void taskHook(context_t **context)
{
    task_t *tcb=(task_t*)((char*)context-offsetof(task_t, context));

    // Replace firmware task addresses with ours
    if(tcb->entry == (void*)task_CaptSeq)           tcb->entry = (void*)capt_seq_task;
    if(tcb->entry == (void*)task_InitFileModules)   tcb->entry = (void*)init_file_modules_task;
    if(tcb->entry == (void*)task_MovieRecord)       tcb->entry = (void*)movie_record_task;
    if(tcb->entry == (void*)task_ExpDrv)            tcb->entry = (void*)exp_drv_task;
    if(tcb->entry == (void*)task_FileWrite)         tcb->entry = (void*)filewritetask;
}

/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask() {
    _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
};

/*-------------------------------------------------------
	Memory Map:
		1900		MEMBASEADDR				start of data	used for initialized vars
		df03								end of data
		df04								start of bss - used for zeroed/uninited vars
		13ca17								end of bss
		13ca18		MEMISOSTART				start of our data / bss
		174000		MEMISOSTART+MEMIOSIZE	end of our data/bss (approx)
		???									end of memory

		400000								video buffers ??

		ff810000	ROMBASEADDR				start of rom
		ffffffff							end of rom
-------------------------------------------------------*/


/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/
