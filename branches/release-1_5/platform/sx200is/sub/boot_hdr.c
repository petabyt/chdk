#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

extern void task_CaptSeq();
extern void task_PhySw();
extern void task_RotaryEncoder();
extern void task_InitFileModules();
extern void task_MovieRecord();
extern void task_ExpDrv();
extern void task_FileWrite();

void JogDial_task_my(void);

void taskCreateHook(context_t **context) {
    task_t *tcb=(task_t*)((char*)context-offsetof(task_t, context));

    if (tcb->entry == (void*)task_CaptSeq)           tcb->entry = (void*)capt_seq_task;
    if (tcb->entry == (void*)task_PhySw)             tcb->entry = (void*)mykbd_task;
    if (tcb->entry == (void*)task_RotaryEncoder)     tcb->entry = (void*)JogDial_task_my;
    if (tcb->entry == (void*)task_InitFileModules)   tcb->entry = (void*)init_file_modules_task;
    if (tcb->entry == (void*)task_MovieRecord)       tcb->entry = (void*)movie_record_task;
    if (tcb->entry == (void*)task_ExpDrv)            tcb->entry = (void*)exp_drv_task;
    if (tcb->entry == (void*)task_FileWrite)         tcb->entry = (void*)filewritetask;
}

void CreateTask_spytask() {
        _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
};

