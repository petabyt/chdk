
#define PARAM_FILE_COUNTER      0x3A // 58, SX130
#define PARAM_EXPOSURE_COUNTER  0x02 // ?

#include "platform.h"

// These F-numbers are the "mock" values shown by the cam.
// They're linked to FL (zoom) and ND8 filter.
// aperture_sizes_table[].id is just a serial number.
// Corrected for SX130
const ApertureSize aperture_sizes_table[] = { // PROPCASE 26
    {  9, 347, "3.4" }, 
    { 10, 384, "4.0" }, 
    { 11, 416, "4.5" },
    { 12, 448, "5.0" },
    { 13, 480, "5.6" },
    { 14, 512, "6.3" },
    { 15, 544, "7.1" },
    { 16, 576, "8.0" },
};


// Corrected for SX130
const ShutterSpeed shutter_speeds_table[] = {
    { -12, -384, "15", 15000000 },
    { -11, -352, "13", 13000000 },
    { -10, -320, "10", 10000000 },
    {  -9, -288, "8",   8000000 },
    {  -8, -256, "6",   6000000 },
    {  -7, -224, "5",   5000000 },
    {  -6, -192, "4",   4000000 },
    {  -5, -160, "3.2", 3200000 },
    {  -4, -128, "2.5", 2500000 },
    {  -3,  -96, "2",   2000000 },
    {  -2,  -64, "1.6", 1600000 },
    {  -1,  -32, "1.3", 1300000 },
    {   0,    0, "1",   1000000 },
    {   1,   32, "0.8",  800000 },
    {   2,   64, "0.6",  600000 },
    {   3,   96, "0.5",  500000 },
    {   4,  128, "0.4",  400000 },
    {   5,  160, "0.3",  300000 },
    {   6,  192, "1/4",  250000 },
    {   7,  224, "1/5",  200000 },
    {   8,  256, "1/6",  166667 },
    {   9,  288, "1/8",  125000 },
    {  10,  320, "1/10", 100000 },
    {  11,  352, "1/13",  76923 },
    {  12,  384, "1/15",  66667 },
    {  13,  416, "1/20",  50000 },
    {  14,  448, "1/25",  40000 },
    {  15,  480, "1/30",  33333 },
    {  16,  512, "1/40",  25000 },
    {  17,  544, "1/50",  20000 },
    {  18,  576, "1/60",  16667 },
    {  19,  608, "1/80",  12500 },
    {  20,  640, "1/100", 10000 },
    {  21,  672, "1/125",  8000 },
    {  22,  704, "1/160",  6250 },
    {  23,  736, "1/200",  5000 },
    {  24,  768, "1/250",  4000 },
    {  25,  800, "1/320",  3125 },
    {  26,  832, "1/400",  2500 },
    {  27,  864, "1/500",  2000 },
    {  28,  896, "1/640",  1563 },
    {  29,  928, "1/800",  1250 },
    {  30,  960, "1/1000", 1000 },
    {  31,  992, "1/1250",  800 },
    {  32, 1024, "1/1600",  625 },
    {  33, 1056, "1/2000",  500 },
    {  34, 1088, "1/2500",  400 }    
};

// Corrected for SX130
const ISOTable iso_table[] = {
    {  0,     0,  "Auto", -1},
    {  1,    80,    "80", -1},
    {  2,   100,   "100", -1},
    {  3,   200,   "200", -1},
    {  4,   400,   "400", -1},
    {  5,   800,   "800", -1},
    {  6,   1600,   "1600", -1}
};


/*
http://www.usa.canon.com/cusa/consumer/products/cameras/digital_cameras/powershot_sx130_is#Specifications
Shooting Modes:
    M, Av, Tv, P, Auto, Easy, Portrait, Landscape, Kids & Pets, SCN, Movie

SCN Scene Modes:
    Smart Shutter, Low Light, Super Vivid, Poster Effect, Color Accent, Color Swap, 
	Fish-eye Effect, Miniature Effect, Beach, Foliage, Snow, Fireworks

Movie Modes:
    Standard, Miniature Effect, Color Accent, Color Swap

Smart Shutter Modes:
    Smile, Wink Self-timer, Face Self-Timer
*/
// Corrected for SX130
const CapturemodeMap modemap[] = {
	{ MODE_AUTO,               32768  },
	{ MODE_P,                  32772  }, 
	{ MODE_TV,                 32771  },
	{ MODE_AV,                 32770  },
	{ MODE_M,                  32769  },
  	{ MODE_KIDS_PETS,          32786  },
	{ MODE_LANDSCAPE,          32782  },
	{ MODE_PORTRAIT,           32783  },
	{ MODE_EASY,               33314  },
	
	{ MODE_VIDEO_COLOR_ACCENT, 2612   },
	{ MODE_VIDEO_COLOR_SWAP,   2613   },
	{ MODE_VIDEO_STD,          2614   },
	{ MODE_VIDEO_MINIATURE,    2620   },

    { MODE_SCN_FACE_SELF_TIMER,16936  },
	{ MODE_SCN_SMART_SHUTTER,  16937  },
    { MODE_SCN_WINK_SELF_TIMER,16938  },
	{ MODE_SCN_LOWLIGHT,       16417  },
	{ MODE_SCN_SUPER_VIVID,    16934  },
	{ MODE_SCN_POSTER_EFFECT,  16935  },
	{ MODE_SCN_COLOR_ACCENT,   16925  },
	{ MODE_SCN_COLOR_SWAP,     16926  },
	{ MODE_SCN_FISHEYE,        16939  },
	{ MODE_SCN_MINIATURE,      16940  },
	{ MODE_SCN_BEACH,          16407  },
	{ MODE_SCN_FOLIAGE,        16405  },
	{ MODE_SCN_SNOW,           16406  },
	{ MODE_SCN_FIREWORK,       16408  }
};


#include "../generic/shooting.c"

const int dof_tbl[] = {6000, 6850, 7490, 8560, 9640, 10700, 12850, 14980, 18190, 22500};
const int dof_tbl_size = sizeof(dof_tbl)/sizeof(dof_tbl[0]);

long get_file_next_counter() {
    return get_file_counter();
}

long get_target_file_num() {
    long n;
    
    n = get_file_next_counter();
    n = (n>>4)&0x3FFF;
    return n;
}

#if defined(CAM_DATE_FOLDER_NAMING)
void get_target_dir_name(char *out)
{
	extern void _GetImageFolder(char*,int,int,int);
	out[0] = 'A';
	_GetImageFolder(out+1,get_file_next_counter(),CAM_DATE_FOLDER_NAMING,time(NULL));
}
#else
long get_target_dir_num() {
	long n;
	
	n = get_file_next_counter();
	n = (n>>18)&0x3FF;
	return n;
}
#endif
