#ifndef LANG_H
#define LANG_H

//-------------------------------------------------------------------
extern void lang_init(int num);

extern void lang_load_from_file(const char *filename);
extern void lang_map_preparsed_from_mem( char* gui_lang_default, int num );

extern char* lang_str(int str);
extern unsigned lang_strhash31(int langid);

//-------------------------------------------------------------------

#endif
