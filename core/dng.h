//DNG related stuff

#ifndef DNG_H
#define DNG_H

#if DNG_SUPPORT

extern int raw_init_badpixel_bin();
extern void capture_data_for_exif(void);
extern void create_dng_header();
extern void free_dng_header(void);
extern void write_dng_header(int fd);

extern void convert_dng_to_chdk_raw(char* fn);

extern void load_bad_pixels_list_b(char* filename);
extern void unload_bad_pixels_list_b(void);
extern int badpixel_list_loaded_b(void);
extern void create_badpixel_bin();

#endif

#endif
