#define PARAM_FILE_COUNTER      0x34
#define PARAM_EXPOSURE_COUNTER  0x01

#include "platform.h"

const ApertureSize aperture_sizes_table[] = {
    {  9, 288, "2.8" },
    { 10, 302, "3.2" },
    { 11, 318, "3.5" },
    { 12, 339, "3.5" },
    { 13, 363, "4.0" },
    { 14, 390, "4.5" },
    { 15, 420, "5.0" },
    { 16, 457, "5.8" },
    { 17, 449, "8.0 ND" },
    { 18, 466, "9.0 ND" },
    { 19, 485, "10.0 ND" },
    { 20, 510, "10.0 ND" },
    { 21, 536, "11.0 ND" },
    { 22, 565, "13.0 ND" },
    { 23, 597, "16.0 ND" },
    { 24, 635, "18.0 ND" },
};// from a460, second column updated (propcase 68)

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
    {  32, 1021, "1/1600",  625 },
    {  33, 1053, "1/2000",  500 },
};

const ISOTable iso_table[] = {
    {  0,    0, "Auto", -1},
    {  1,   64,   "64", -1},
    {  2,  100,  "100", -1},
    {  3,  200,  "200", -1},
    {  4,  400,  "400", -1},
};

/*
http://www.usa.canon.com/cusa/support/consumer/digital_cameras/powershot_a_series/powershot_a430#Specifications
canon mode list FFD588D4 in 100b
*/          
const CapturemodeMap modemap[] = {
//    { MODE_M,                  32769 },
    { MODE_P,                  32772 },
    { MODE_AUTO,               32768 },
    { MODE_PORTRAIT,           16396 },
//    { MODE_NIGHT_SCENE,        32782 }, // "night scene" on dial, different from "night snapshot" under "scene" below
    { MODE_STITCH,             33289 }, //
    { MODE_SCN_NIGHT_SNAPSHOT, 16394 }, // "night snapshot"
    { MODE_SCN_KIDS_PETS,      16398 }, // "kids and pets"
    { MODE_SCN_INDOOR,         16399 }, // "indoor"
    { MODE_SCN_FOLIAGE,        16400 }, // "foliage"
    { MODE_SCN_SNOW,           16401 }, // "snow"
    { MODE_SCN_BEACH,          16402 }, // "beach"
    { MODE_SCN_FIREWORK,       16403 }, // "fireworks"
    { MODE_SCN_COLOR_ACCENT,   33303 }, // "color accent"
    { MODE_SCN_COLOR_SWAP,     33304 }, // "color swap"
    { MODE_SUPER_MACRO,        33288 }, // 
    { MODE_VIDEO_STD,          3613  }, //
/*    { MODE_VIDEO_SPEED,        2594  }, // "fast frame rate"
    { MODE_VIDEO_COMPACT,      2595  }, // "compact"
    { MODE_VIDEO_COLOR_ACCENT, 2591  }, // "color accent"
    { MODE_VIDEO_COLOR_SWAP,   2592  }, // "color swap"
*/
};
#include "../generic/shooting.c"

long get_file_next_counter() { //looks like this hack is needed for old vxworks
    return ((get_file_counter()>>4)+1)<<4;
}

long get_target_file_num() {
    long n;
    
    n = get_file_next_counter();
    n = (n>>4)&0x3FFF;
    return n;
}

long get_target_dir_num() {
    long n;
    
    n = get_file_next_counter();
    n = (n>>18)&0x3FF;
    return n;
}

int circle_of_confusion = 5;
