#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "keyboard.h"

#define PARAM_FILE_COUNTER      0x1        // see comments in ixus140 port

// aperture values recorded at wide angle

const ApertureSize aperture_sizes_table[] = {
    { 9, 352, "3.5" },
    { 10, 384, "4.0" },
    { 11, 416, "4.5" },
    { 12, 448, "5.0" },
    { 13, 480, "5.6" },
    { 14, 512, "6.3" },
    { 15, 544, "7.1" },
    { 16, 576, "8.0" }
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
};

const ISOTable iso_table[] = {
    {  0,    0, "Auto", -1},
    {  1,  100,  "100", -1},
    {  2,  200,  "200", -1},
    {  3,  400,  "400", -1},
    {  4,  800,  "800", -1},
    {  5, 1600, "1600", -1},
    {  6, 3200, "3200", -1},
};

/*
http://www.usa.canon.com/cusa/consumer/products/cameras/digital_cameras/powershot_sx280_hs#Specifications
*/
/*
modelist @ 0xfc731150
fc731150: 8001
fc731152: 8003
fc731154: 8002
fc731156: 8004
fc731158: 823b
fc73115a: 823a
fc73115c: 820d
fc73115e: 2232
fc731160: 2231
fc731162: 2235
fc731164: 2236
fc731166: 2238
fc731168: 8223
fc73116a: 8224
fc73116c: 222c
fc73116e: 222d
fc731170: 401b
fc731172: 4013
fc731174: 8214
fc731176: 4233
fc731178: 4009
fc73117a: 401e
fc73117c: 401d
fc73117e: 8207
fc731180: 820f
fc731182: 8010
fc731184: 8000
fc731186: 422e
fc731188: 422f
fc73118a: 4230
fc73118c: 8037
fc73118e: 0a44
fc731190: 0a49
fc731192: ffff
*/

const CapturemodeMap modemap[] = {

{ MODE_VIDEO_STD             ,2628 },
{ MODE_VIDEO_SUPER_SLOW      ,2633 },
{ MODE_SUPER_VIVID           ,8748 },
{ MODE_POSTER_EFFECT         ,8749 },
{ MODE_FISHEYE               ,8753 },
{ MODE_MINIATURE             ,8754 },
{ MODE_TOY_CAMERA            ,8757 },
{ MODE_SOFTFOCUS             ,8758 },
{ MODE_MONOCHROME            ,8760 },
{ MODE_HIGHSPEED_BURST | MODE_DISABLE_RAW ,16393 }, // highspeed burst hq
{ MODE_PORTRAIT             ,16403 },
{ MODE_SNOW                 ,16411 },
{ MODE_FIREWORK             ,16413 },
{ MODE_UNDERWATER           ,16414 },
{ MODE_FACE_SELF_TIMER      ,16942 }, // smart shutter, face self timer
{ MODE_SMART_SHUTTER        ,16943 }, // smart shutter, smile detection
{ MODE_WINK_SELF_TIMER      ,16944 }, // smart shutter, wink self timer
{ MODE_NIGHT_SCENE | MODE_DISABLE_RAW ,16947 }, // handheld night scene
{ MODE_AUTO | MODE_DISABLE_RAW ,32768 },
{ MODE_M                    ,32769 },
{ MODE_AV                   ,32770 },
{ MODE_TV                   ,32771 },
{ MODE_P                    ,32772 },
{ MODE_HYBRID_AUTO | MODE_DISABLE_RAW ,32784 },
{ MODE_DISCREET             ,32823 },
{ MODE_SPORTS | MODE_DISABLE_RAW ,33287 },
{ MODE_STITCH               ,33293 }, // stitch, unofficial, may crash
//{                         ,  33295 }, // crash and lock up :(
{ MODE_SMOOTH_SKIN          ,33300 }, // unofficial?
{ MODE_COLOR_ACCENT         ,33315 }, // color accent
{ MODE_COLOR_SWAP           ,33316 }, // color swap
{ MODE_LIVE                 ,33338 },
{ MODE_VIDEO_MOVIE_DIGEST   ,33339 }  // movie digest, unofficial (same functionality under hybrid auto)

};

#include "../generic/shooting.c"

long get_file_next_counter() {
    return get_file_counter();
}

long get_target_file_num() {
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
