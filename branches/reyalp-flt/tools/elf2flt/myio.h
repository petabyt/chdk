#ifndef __MYIO_H__
#define __MYIO_H__

#include <stdio.h>


#ifndef O_BINARY
#define O_BINARY 0 //not defined on linux
#endif


int b_file_preload(char* filename);
int b_read (int fd, void* buf, unsigned int count);
int b_seek(int fd, long offset, int whence);
char* b_get_buf();

int b_seek_read(unsigned int offset, char *buf, int len);

int load_import(char* importfile);
int find_import_symbol(char* sym);

extern int FLAG_DUMP_SOURCE;
extern int FLAG_DUMP_SYMBOLS;
extern int FLAG_DUMP_RELOC;
extern int FLAG_DUMP_FLT_HEADERS;
extern int FLAG_DUMP_FLAT;
extern int FLAG_VERBOSE;
extern int FLAG_DUMP_SECTIONS;
extern int FLAG_WARNSYMBOL;

extern char* filename_elf;
void raise_error();
#define PRINTERR(...) { raise_error(); fprintf(__VA_ARGS__);}


#endif /* __MYIO_H__ */
