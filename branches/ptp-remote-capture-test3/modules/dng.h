//DNG related stuff

#ifndef DNG_H
#define DNG_H

#include "flt.h"

// This is to minimize export list to different modules
typedef struct
{
    base_interface_t    base;

	void (*create_badpixel_bin)();
	int  (*raw_init_badpixel_bin)();
	void (*capture_data_for_exif)(void);
	void (*load_bad_pixels_list_b)(char* filename);
	int  (*badpixel_list_loaded_b)(void);

	int (*convert_dng_to_chdk_raw)(char* fn);
	void (*write_dng)(int fd, char* rawadr, char* altrawadr, unsigned long uncachedbit);
} libdng_sym;

extern libdng_sym* libdng;

#endif
