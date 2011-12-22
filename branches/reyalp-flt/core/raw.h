#ifndef RAW_H
#define RAW_H

#include "camera.h"

//-------------------------------------------------------------------
#define RAW_PREFIX_IMG          0
#define RAW_PREFIX_CRW          1
#define RAW_PREFIX_SND          2

#define RAW_EXT_JPG             0
#define RAW_EXT_CRW             1
#define RAW_EXT_CR2             2
#define RAW_EXT_THM             3
#define RAW_EXT_WAV             4

//-------------------------------------------------------------------

#define RAW_ROWLEN ((CAM_RAW_ROWPIX*CAM_SENSOR_BITS_PER_PIXEL)/8)

//-------------------------------------------------------------------
extern int raw_savefile();
extern void raw_postprocess();
extern void raw_prepare_develop(const char* filename);
extern void load_bad_pixels_list(const char* filename);
extern unsigned short get_raw_pixel(unsigned int x,unsigned  int y);
extern char* get_raw_image_addr(void);
extern void patch_bad_pixel(unsigned int x,unsigned  int y);

//-------------------------------------------------------------------
#endif
