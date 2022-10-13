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
    { 23, 593, "9.0" },
    { 24, 625, "10.0" },
    { 25, 657, "11.0" },
};

// note camera supports up to 250s shutter
const ShutterSpeed shutter_speeds_table[] = {
    { -24, -768, "250", 250000000 },
    { -23, -736, "200", 200000000 },
    { -22, -704, "160", 160000000 },
    { -21, -672, "125", 125000000 },
    { -20, -640, "100", 100000000 },
    { -19, -608, "80",   80000000 },
    { -18, -576, "60",   60000000 },
    { -17, -544, "50",   50000000 },
    { -16, -512, "40",   40000000 },
    { -15, -480, "30",   30000000 },
    { -14, -448, "25",   25000000 },
    { -13, -416, "20",   20000000 },
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
};

const ISOTable iso_table[] = {
	{  0,    0, " Auto", -1},
	{  1,  125,   "125", -1},
	{  2,  160,   "160", -1},
	{  3,  200,   "200", -1},
	{  4,  250,   "250", -1},
	{  5,  320,   "320", -1},
	{  6,  400,   "400", -1},
	{  7,  500,   "500", -1},
	{  8,  640,   "640", -1},
	{  9,  800,   "800", -1},
	{ 10, 1000,  "1000", -1},
	{ 11, 1250,  "1250", -1},
	{ 12, 1600,  "1600", -1},
	{ 13, 2000,  "2000", -1},
	{ 14, 2500,  "2500", -1},
	{ 15, 3200,  "3200", -1},
	{ 16, 4000,  "4000", -1},
	{ 17, 5000,  "5000", -1},
	{ 18, 6400,  "6400", -1},
	{ 19, 8000,  "8000", -1},
	{ 20,10000, "10000", -1},
	{ 21,12800, "12800", -1},
};

const CapturemodeMap modemap[] = {
// note canon values for P, M etc have shifted by one 
{ MODE_AUTO                 ,32768 },
{ MODE_M                    ,32770 },
{ MODE_AV                   ,32771 },
{ MODE_TV                   ,32772 },
{ MODE_P                    ,32773 },
{ MODE_HDR | MODE_DISABLE_RAW ,8775 },
{ MODE_NOSTALGIC            ,8753 },
{ MODE_FISHEYE              ,8759 },
{ MODE_MINIATURE            ,8760 },
{ MODE_TOY_CAMERA           ,8763 },
{ MODE_BACKGROUND_DEFOCUS   ,8764 },
{ MODE_SOFTFOCUS            ,8765 },
{ MODE_MONOCHROME           ,8767 },
{ MODE_SUPER_VIVID          ,8754 },
{ MODE_POSTER_EFFECT        ,8755 },
{ MODE_PORTRAIT             ,16406 },
{ MODE_FACE_SELF_TIMER      ,16948 },
{ MODE_SMART_SHUTTER        ,16949 }, // smile detection
{ MODE_WINK_SELF_TIMER      ,16950 },
{ MODE_STAR_PORTRAIT        ,16452 },
{ MODE_STAR_NIGHTSCAPE      ,16453 },
{ MODE_STAR_TRAILS          ,16454 },
{ MODE_NIGHT_SCENE | MODE_DISABLE_RAW ,16953 }, // handheld night scene
{ MODE_UNDERWATER           ,16929 },
{ MODE_SNOW                 ,16414 },
{ MODE_FIREWORK             ,16416 },
{ MODE_CREATIVE_EFFECT      ,33299 }, // Creative shot, various sub modes all use same number
{ MODE_HYBRID_AUTO | MODE_DISABLE_RAW ,33298 }, // like movie digest. RAW in hybrid auto actually works if you enable "unsafe IO", otherwise hangs
//{                         ,33297 }, // ???
{ MODE_VIDEO_STD             ,2643 }, // standard video on dial, regardless of res or FPS
{ MODE_VIDEO_IFRAME_MOVIE    ,2650 },
{ MODE_VIDEO_M               ,2651 }, // M video
{ MODE_VIDEO_STAR_TIME_LAPSE,16459 }, // VIDEO?
//{                         ,4172 }, // C, in propcase 54
};

#include "../generic/shooting.c"

long get_file_next_counter() {
    return get_file_counter();
}

long get_target_file_num() {
    return get_exposure_counter();
}
/*
CAM_DATE_FOLDER_NAMING values
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
