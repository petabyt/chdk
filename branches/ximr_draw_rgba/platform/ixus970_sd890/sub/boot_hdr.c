#include "lolevel.h"
#include "platform.h"
#include "core.h"

const char * const new_sa = &_end;

void __attribute__((naked,noinline)) jogdial_task_my();

/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask() {
        _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
};


