#ifndef LANG_H
#define LANG_H

//-------------------------------------------------------------------
extern void lang_init(int num);

extern void lang_load_from_file(const char *filename);
extern void lang_map_preparsed_from_mem( char* gui_lang_default, int num );

typedef int (*callback_process_file)(char* buf, int size);
extern int load_from_file(const char *filename, callback_process_file callback) ;
extern char* load_file( const char* name, int* rv_size );
extern char* load_file_to_cached( const char* name, int* rv_size );

int load_int_value_file( char* filename, int* value_p );
void save_int_value_file( char* filename, int value );

extern char* lang_str(int str);
extern unsigned lang_strhash31(int langid);

//-------------------------------------------------------------------
#endif
