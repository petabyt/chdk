
#include "lolevel.h"
#include "platform.h"
#include "core.h"

// TODO:

#define USE_STUBS_NRFLAG 1
#define NR_AUTO (-1) // default value if NRTBL.SetDarkSubType not used is -1 (0 probably works the same), set to enable auto

#include "../../../generic/capt_seq.c"

char *current_raw_addr;
char *current_raw_alt_addr;

void captseq_get_raw_addr()
{
    extern char* raw_buffer_table[];
    extern int raw_buffer_index;
    current_raw_addr = raw_buffer_table[raw_buffer_index];
    current_raw_alt_addr = raw_buffer_table[(raw_buffer_index+1)&0xF];   // 16 buffers, select next one as alt
}

void clear_current_raw_addr(void)
{
    current_raw_addr = NULL;
}
