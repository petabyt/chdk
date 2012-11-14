//DNG related stuff

#ifndef DNG_H
#define DNG_H

#include "remotecap.h"

// This is to minimize export list to different modules
struct libdng_sym {
	int  version;
	void (*create_badpixel_bin)();
	int  (*raw_init_badpixel_bin)();
	void (*capture_data_for_exif)(void);
	void (*load_bad_pixels_list_b)(char* filename);
	int  (*badpixel_list_loaded_b)(void);

	void (*convert_dng_to_chdk_raw)(char* fn);
	void (*write_dng)(int fd, char* rawadr, char* altrawadr, unsigned long uncachedbit);

    // added in module API version 1.1
	void (*create_dng_for_ptp)(ptp_data_chunk *pdc, char* rawadr, char* altrawadr, unsigned long uncachedbit, int startline, int linecount);
	void (*free_dng_for_ptp)(char* rawadr, char* altrawadr);
};

// Defines of exported to chdk symbols
#ifdef THIS_IS_CHDK_CORE
    // This section is for CHDK core

    // values of semaphore
    #define LIBDNG_OWNED_BY_RAW 			0x1
    #define LIBDNG_OWNED_BY_CONVERT 		0x2
    #define LIBDNG_OWNED_BY_CREATEBADPIXEL	0x4
	extern struct libdng_sym* libdng;
    extern struct libdng_sym* module_dng_load(int owner);		// 0fail, addr-ok
    extern void module_dng_unload(int owner);

#else
	
	extern void create_badpixel_bin();
    extern int raw_init_badpixel_bin();
    extern void capture_data_for_exif(void);
	extern void load_bad_pixels_list_b(char* filename);
	extern int  badpixel_list_loaded_b(void);

    extern void convert_dng_to_chdk_raw(char* fn);
	extern void write_dng(int fd, char* rawadr, char* altrawadr, unsigned long uncachedbit);

    extern void unload_bad_pixels_list_b(void);

    extern void create_dng_for_ptp(ptp_data_chunk *pdc, char* rawadr, char* altrawadr, unsigned long uncachedbit, int startline, int linecount);
    extern void free_dng_for_ptp(char* rawadr, char* altrawadr);
#endif

extern int module_convert_dng_to_chdk_raw(char* fn);		// Return: 0-fail, 1-ok

#endif
