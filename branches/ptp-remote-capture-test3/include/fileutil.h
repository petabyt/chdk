#ifndef FILEUTIL_H
#define FILEUTIL_H

//-------------------------------------------------------------------

// fileutil.c functions

typedef int (*callback_process_file)(char* buf, int size);
extern int load_from_file(const char *filename, callback_process_file callback) ;
extern char* load_file( const char* name, int* rv_size );
extern char* load_file_to_cached( const char* name, int* rv_size );

extern int load_int_value_file( const char* filename, int* value_p );
extern void save_int_value_file( const char* filename, int value );

extern int is_file_exists(const char* fn);                  // 0-not exist, otherwise exist (=-1 mean empty, =1 mean nonempty)

//-------------------------------------------------------------------


#endif
