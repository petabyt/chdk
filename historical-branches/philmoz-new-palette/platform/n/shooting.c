// Powershot N

#include "platform.h"

// http://chdk.setepontos.com/index.php?topic=2031.msg27692#msg27692
// PROPCASE_AV (68)
const ApertureSize aperture_sizes_table[] = { // TODO : FIXME
    { 9, 352, "3.5" },
    { 10, 384, "4.0" },
    { 11, 416, "4.5" },
    { 12, 448, "5.0" },
    { 13, 480, "5.6" },
    { 14, 512, "6.3" },
    { 15, 544, "7.1" },
    { 16, 576, "8.0" }
};

const ShutterSpeed shutter_speeds_table[] = {   // TODO : FIXME
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
    {  34, 1088, "1/2500",  400 },
    {  35, 1120, "1/3200",  313 },
};

const ISOTable iso_table[] = {   // TODO : FIXME
    {  0,    0, "Auto", -1},
    {  1,  100,  "100", -1},
    {  2,  200,  "200", -1},
    {  3,  400,  "400", -1},
    {  4,  800,  "800", -1},
    {  5, 1600, "1600", -1},
    {  6, 3200, "3200", -1},
};


// Firmware modemap table found @ff3f2834 -> ff899458  -  cam has goofy hybrid modes for video that don't fit here
const CapturemodeMap modemap[] = {
    { MODE_AUTO,                32768 },
    { MODE_P,                   32772 },  
    { MODE_SCN_FISHEYE,         33329 },   
    { MODE_SCN_MINIATURE,       33330 },  
    { MODE_SCN_TOY_CAMERA,      33333 },  
    { MODE_SCN_MONOCHROME,      33336 },          
    { MODE_VIDEO_SUPER_SLOW,     2633 },    
    { MODE_SCN_CREATIVE_EFFECT, 32785 },
    { MODE_VIDEO_STD,           33792 },
    { MODE_VIDEO_SPEED,         33796 },
};

#include "../generic/shooting.c"

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

void get_target_dir_name(char *out) {

    extern void _GetImageFolder(char*,int,int,int);
    _GetImageFolder(out,get_file_next_counter(),CAM_DATE_FOLDER_NAMING,time(NULL));
}
#else
long get_target_dir_num() {
    long n;

    n = get_file_next_counter();
    n = (n>>18)&0x3FF;
    return n;
}
#endif
