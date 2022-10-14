
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1
#define NR_AUTO (-1) // default value if NRTBL.SetDarkSubType not used is -1 (0 probalby works the same), set to enable auto

#include "../../../generic/capt_seq.c"

// first parameter matches active_raw_buffer
// second is pointer to structure
extern int _captseq_raw_addr_init (int raw_index, char **ptr);
char *current_raw_addr;

void
captseq_raw_addr_init_my (int raw_index, char **ptr)
{
    _captseq_raw_addr_init (raw_index, ptr);
    current_raw_addr = *(ptr + 0x5c / 4); // @0xfc09bf88, ptr+0x5c
}

void
clear_current_raw_addr (void)
{
    current_raw_addr = NULL;
}

// TODO:
// task_DvlpSeq 0xfc091e67
void __attribute__((naked,noinline))
developseq_task ()
{
    asm volatile (
            "    nop\n"
    );
}
