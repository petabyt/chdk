#ifndef _DBG_DUMP_H
#define _DBG_DUMP_H

// to keep format simple, we always write meminfo for each
// but can skip actual getmeminfo since call might crash on mem corruption
#define DBG_DUMP_FL_NOMEMINFO   0x1
#define DBG_DUMP_FL_NOEXMEMINFO 0x2

/*
name = full path of file to write
flags = *FL above
user_data = pointer to user_data_len additional data to write at the end of the dump
if user_data is null, user_data_len is stored as user_val in dump header
otherwise, the user_data pointer is stored in user_val
*/
#ifdef OPT_DBG_DUMP
void dbg_dump_write(char *name, unsigned flags, int user_data_len, char *user_data);
#else
// if not enabled make it a no-op so dumps can be left in place without code changes
#define dbg_dump_write(...)
#endif // OPT_DBG_DUMP
#endif // _DBG_DUMP_H
