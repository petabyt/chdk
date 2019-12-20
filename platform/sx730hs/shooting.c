#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "keyboard.h"
#include "stdlib.h"
#include "platform.h"
#include "stdio.h"

#define PARAM_FILE_COUNTER      0x1        // see comments in ixus140 port

// aperture values recorded at wide angle, using propcase AV after half press 
// propcase USER_AV slightly different.
// Oddly most are ~1/3 stop from formal conversion
const ApertureSize aperture_sizes_table[] = {
    { 9,  333, "3.3" },
    { 10, 337, "3.5" },
    { 11, 369, "4.0" },
    { 12, 401, "4.5" },
    { 13, 433, "5.0" },
    { 14, 466, "5.6" },
    { 15, 497, "6.3" },
    { 16, 529, "7.1" },
    { 17, 561, "8.0" },
};

const ShutterSpeed shutter_speeds_table[] = {
    { -12, -384, "15",   15000000 },
    { -11, -352, "13",   13000000 },
    { -10, -320, "10",   10000000 },
    {  -9, -288, "8",     8000000 },
    {  -8, -256, "6",     6000000 },
    {  -7, -224, "5",     5000000 },
    {  -6, -192, "4",     4000000 },
    {  -5, -160, "3.2",   3200000 },
    {  -4, -128, "2.5",   2500000 },
    {  -3,  -96, "2",     2000000 },
    {  -2,  -64, "1.6",   1600000 },
    {  -1,  -32, "1.3",   1300000 },
    {   0,    0, "1",     1000000 },
    {   1,   32, "0.8",    800000 },
    {   2,   64, "0.6",    600000 },
    {   3,   96, "0.5",    500000 },
    {   4,  128, "0.4",    400000 },
    {   5,  160, "0.3",    300000 },
    {   6,  192, "1/4",    250000 },
    {   7,  224, "1/5",    200000 },
    {   8,  256, "1/6",    166667 },
    {   9,  288, "1/8",    125000 },
    {  10,  320, "1/10",   100000 },
    {  11,  352, "1/13",    76923 },
    {  12,  384, "1/15",    66667 },
    {  13,  416, "1/20",    50000 },
    {  14,  448, "1/25",    40000 },
    {  15,  480, "1/30",    33333 },
    {  16,  512, "1/40",    25000 },
    {  17,  544, "1/50",    20000 },
    {  18,  576, "1/60",    16667 },
    {  19,  608, "1/80",    12500 },
    {  20,  640, "1/100",   10000 },
    {  21,  672, "1/125",    8000 },
    {  22,  704, "1/160",    6250 },
    {  23,  736, "1/200",    5000 },
    {  24,  768, "1/250",    4000 },
    {  25,  800, "1/320",    3125 },
    {  26,  832, "1/400",    2500 },
    {  27,  864, "1/500",    2000 },
    {  28,  896, "1/640",    1563 },
    {  29,  928, "1/800",    1250 },
    {  30,  960, "1/1000",   1000 },
    {  31,  992, "1/1250",    800 },
    {  32, 1024, "1/1600",    625 },
    {  33, 1056, "1/2000",    500 },
    {  34, 1088, "1/2500",    400 },
    {  35, 1120, "1/3200",    313 },
};

const ISOTable iso_table[] = {
	{  0,    0, " Auto", -1},
	{  1,   80,    "80", -1},
	{  2,  100,   "100", -1},
	{  3,  200,   "200", -1},
	{  4,  400,   "400", -1},
	{  5,  800,   "800", -1},
	{  6, 1600,  "1600", -1},
	{  7, 3200,  "3200", -1},
};

const CapturemodeMap modemap[] = {
{ MODE_AUTO                 ,32768 },
{ MODE_M                    ,32770 },
{ MODE_AV                   ,32771 },
{ MODE_TV                   ,32772 },
{ MODE_P                    ,32773 },
{ MODE_FISHEYE              ,16953 },
{ MODE_MINIATURE            ,16954 },
{ MODE_TOY_CAMERA           ,16957 },
{ MODE_SOFTFOCUS            ,16959 },
{ MODE_MONOCHROME           ,16961 },
{ MODE_SUPER_VIVID          ,16948 },
{ MODE_POSTER_EFFECT        ,16949 },
{ MODE_PORTRAIT             ,16406 },
{ MODE_SMOOTH_SKIN          ,16919 },
{ MODE_SMART_SHUTTER        ,16951 }, // smile detection
{ MODE_WINK_SELF_TIMER      ,16952 },
{ MODE_FACE_SELF_TIMER      ,16950 },
{ MODE_NIGHT_SCENE          ,16955 }, // handheld night scene
{ MODE_LOWLIGHT             ,16431 },
{ MODE_FIREWORK             ,16416 },
{ MODE_CREATIVE_EFFECT      ,33299 }, // Creative shot, various sub modes all use same number
{ MODE_HYBRID_AUTO          ,33298 }, // like movie digest
{ MODE_SPORTS               ,33288 },
{ MODE_SELFIE               ,32806 },
//{                         ,33297 }, // ? seems to be related to face ID
{ MODE_VIDEO_STD             ,2646 }, // standard video on dial
{ MODE_VIDEO_SHORT_CLIP      ,2655 },
};

#include "../generic/shooting.c"

long get_file_next_counter() {
    return get_file_counter();
}

long get_target_file_num() {
    return get_exposure_counter();
}
/*
CAM_DATE_FOLDER_NAMING values - from sx710, presumed same since it works
0x000   A/DCIM/1nn___nn/MRK_nnnn.MRK
0x001   A/DCIM/1nn___nn/ETC_nnnn.TMP
0x002   A/DCIM/1nn___nn/IMG_nnnn.JPG
0x004   A/DCIM/1nn___nn/MVI_nnnn.THM
0x008   A/DCIM/1nn___nn/SND_nnnn.WAV
0x010   A/DCIM/1nn___nn/IMG_nnnn.CR2
0x020   A/DCIM/1nn___nn/MVI_nnnn.MOV
0x040   A/DCIM/1nn___nn/MVI_nnnn.MP4
0x080   A/DCIM/1nn___nn
0x100   A/DCIM/1nn___nn/ETC_nnnn.TMP
larger values and multiple bits also seem to be ETC_nnnn.TMP
*/
#if defined(CAM_DATE_FOLDER_NAMING)
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
