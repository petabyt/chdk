#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "keyboard.h"

#define PARAM_FILE_COUNTER      0x1        // see comments in ixus140 port

// aperture values recorded at wide angle

const ApertureSize aperture_sizes_table[] = {
    { 9,  171, "1.8" },
    { 10, 192, "2.0" },
    { 11, 224, "2.2" },
    { 12, 256, "2.5" },
    { 13, 288, "2.8" },
    { 14, 320, "3.2" },
    { 15, 352, "3.5" },
    { 16, 369, "4.0" },
    { 17, 401, "4.5" },
    { 18, 433, "5.0" },
    { 19, 465, "5.6" },
    { 20, 497, "6.3" },
    { 21, 529, "7.1" },
    { 22, 561, "8.0" },
};

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
    {  34, 1088, "1/2500",  400 },
    {  35, 1120, "1/3200",  313 },
    {  36, 1152, "1/4000",  250 },
};

const ISOTable iso_table[] = {
    {  0,    0, " Auto", -1},
    {  1,   80,   "80", -1},
    {  2,  100,   "100", -1},
    {  3,  125,   "125", -1},
    {  4,  160,   "160", -1},
    {  5,  200,   "200", -1},
    {  6,  250,   "250", -1},
    {  7,  320,   "320", -1},
    {  8,  400,   "400", -1},
    {  9,  500,   "500", -1},
    { 10,  640,   "640", -1},
    { 11,  800,   "800", -1},
    { 12, 1000,  "1000", -1},
    { 13, 1250,  "1250", -1},
    { 14, 1600,  "1600", -1},
    { 15, 2000,  "2000", -1},
    { 16, 2500,  "2500", -1},
    { 18, 3200,  "3200", -1},
    { 19, 4000,  "4000", -1},
    { 20, 5000,  "5000", -1},
    { 21, 6400,  "6400", -1},
    { 22, 8000,  "8000", -1},
    { 23,10000, "10000", -1},
    { 24,12800, "12800", -1},
};

// Unknown values from canon_mode_list 0xfc7f8a3c Found @0xfc124510
// 32830  0x803e In firmware but not in current modemap 
// 32777  0x8009 In firmware but not in current modemap
// 33332  0x8234 In firmware but not in current modemap
// 33295  0x820f In firmware but not in current modemap
//  4163  0x1043 In firmware but not in current modemap  <- invokes C1 when written to PROPCASE_SHOOTING_MODE 
//  4164  0x1044 In firmware but not in current modemap  <- invokes C2 when written to PROPCASE_SHOOTING_MODE

const CapturemodeMap modemap[] = {

{ MODE_VIDEO_STD             ,2633 }, //
{ MODE_VIDEO_SUPER_SLOW      ,2638 }, //
{ MODE_NOSTALGIC             ,8747 }, //
{ MODE_SUPER_VIVID           ,8748 }, //
{ MODE_POSTER_EFFECT         ,8749 }, //
{ MODE_FISHEYE               ,8753 }, //
{ MODE_MINIATURE             ,8754 }, //
{ MODE_TOY_CAMERA            ,8757 }, //
{ MODE_BACKGROUND_DEFOCUS    ,8758 }, //
{ MODE_SOFTFOCUS             ,8759 }, //
{ MODE_MONOCHROME            ,8761 }, //
{ MODE_HDR                   ,8769 }, //


{ MODE_PORTRAIT             ,16403 }, //
{ MODE_SNOW                 ,16411 }, //
{ MODE_FIREWORK             ,16413 }, //
{ MODE_STAR_NIGHTSCAPE      ,16447 }, //
{ MODE_STAR_TRAILS          ,16448 }, //
{ MODE_VIDEO_STAR_TIME_LAPSE,16465 }, //
{ MODE_UNDERWATER           ,16926 }, //
{ MODE_FACE_SELF_TIMER      ,16942 }, //
{ MODE_SMART_SHUTTER        ,16943 }, //
{ MODE_WINK_SELF_TIMER      ,16944 }, //
{ MODE_NIGHT_SCENE          ,16947 }, //

{ MODE_AUTO                 ,32768 }, //
{ MODE_M                    ,32769 }, //
{ MODE_AV                   ,32770 }, //
{ MODE_TV                   ,32771 }, //
{ MODE_P                    ,32772 }, //
{ MODE_HYBRID_AUTO          ,33296 }, //

};

#include "../generic/shooting.c"

long get_file_next_counter() 
{
    return get_file_counter();
}

long get_target_file_num() 
{
    return get_exposure_counter();
}

#if defined(CAM_DATE_FOLDER_NAMING)
/*
  CAM_DATE_FOLDER_NAMING should be 0x80, otherwise various filenames are returned
  this _GetImageFolder version only seems to take 3 arguments, but it doesn't hurt if a 4th one is provided
*/
void get_target_dir_name(char *out)
{
    extern void _GetImageFolder(char*,int,int,int);
    _GetImageFolder(out,get_file_next_counter(),CAM_DATE_FOLDER_NAMING,time(NULL));
}
#else
long get_target_dir_num()
{
    return 0;
}
#endif
