#include "platform.h"

// These F-numbers are the "mock" values shown by the cam.
// They're linked to FL (zoom) (surpisingly not ND filter as well).
const ApertureSize aperture_sizes_table[] = { // PROPCASE 23
    {  9, 305, "3.0" },
    { 10, 314, "3.2" }, 
    { 11, 350, "3.5" }, 
    { 12, 382, "4.0" },
    { 13, 411, "4.5" },
    { 14, 439, "5.0" },
    { 15, 472, "5.6" },
    { 16, 514, "6.3" },
    { 17, 543, "6.9" },
};

// OLD copied comment!
// TODO copied from 850
// Another set of "mock" values, which can probably
// be derived from the table found at FFB4E258 in FW.
// At the moment, I see no reason to amend it.
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
};

const ISOTable iso_table[] = {
    {  0,     0,  "Auto", -1},
    {  1,    80,    "80", -1},
    {  2,   100,   "100", -1},
    {  3,   200,   "200", -1},
    {  4,   400,   "400", -1},
    {  5,   800,   "800", -1},
    {  6,  1600,  "1600", -1},
    {  7,  3200,  "3200", -1},
    {  8,  6400,  "6400", -1},
};          

/*
http://www.usa.canon.com/cusa/consumer/products/cameras/digital_cameras/powershot_elph_330_hs#Specifications

Shooting Modes
    Auto, Hybrid Auto, P, Portrait, Smooth Skin, Smart Shutter (Smile, Wink
    Self-timer, Face Self-timer), High-Speed Burst, Handheld Night Scene,
    Fisheye Effect, Miniature Effect, Toy Camera Effect, Soft Focus,
    Monochrome, Super Vivid, Poster Effect, Color Accent, Color Swap, Snow,
    Fireworks, Long Shutter, Stitch Assist, Super Slow Motion Movie
	
Video Modes
    Full HD 1920 x 1080: 24 fps (23.976)
    HD 1280 x 720: 30 fps (29.97)
    Digest Movie HD 1280 x 720: 30 fps (29.97)
    Miniature Effect HD 1280 x 720: 6 fps / 3 fps / 1.5 fps
    Miniature Effect 640 x 480: 6 fps / 3 fps / 1.5 fps
    Super Slow Motion Movie 640 x 480: 120 fps
    Super Slow Motion Movie 320 x 240: 240 fps
    640 x 480: 30 fps (29.97)
*/
const CapturemodeMap modemap[] = {
    { MODE_LONG_SHUTTER,        32774 },
    { MODE_P,                   32772 },
    { MODE_STITCH,              33293 }, // either direction
    { MODE_MINIATURE,           33330 },
    { MODE_FISHEYE,             33329 },
    { MODE_TOY_CAMERA,          33333 }, // not really a SCN mode
    { MODE_COLOR_ACCENT,        33315 },
    { MODE_COLOR_SWAP,          33316 },
    { MODE_MONOCHROME,          33336 },
    { MODE_SUPER_VIVID,         33324 },
    { MODE_POSTER_EFFECT,       33325 },
    { MODE_PORTRAIT,            32787 },
    { MODE_SNOW,                32795 },
    { MODE_FIREWORK,            32797 },
    { MODE_AUTO,                32768 },
    { MODE_FACE_SELF_TIMER,     33326 },
    { MODE_SMART_SHUTTER,       33327 },
    { MODE_WINK_SELF_TIMER,     33328 },
    { MODE_SMOOTH_SKIN,         33300 },
    { MODE_HIGHSPEED_BURST | MODE_DISABLE_RAW, 32776 },
    { MODE_SOFTFOCUS,           33334 },
    { MODE_VIDEO_SUPER_SLOW,     2633 }, // 3657 when recording
    { MODE_NIGHT_SCENE | MODE_DISABLE_RAW, 33331 },
// Not in mode selection
//    { MODE_VIDEO_STD,           33796 }, // when recording; 33808 when recording in Hybrid Auto
//    { MODE_VIDEO_MINIATURE,     34354 }, // when recording in miniature mode
    { MODE_VIDEO_MOVIE_DIGEST,  32784 }
// stubs_entry.S says there are two more modes, but I can't find them
};

#include "../generic/shooting.c"

long get_file_next_counter() {
    return get_file_counter();
}

long get_target_file_num() {
    return get_exposure_counter();
}
#if defined(CAM_DATE_FOLDER_NAMING)
// ELPH330 camera uses date to name directory
// TODO currently returns something like A/DCIM/101___09/ETC_0112.TMP
// may need different params
void get_target_dir_name(char *out)
{
    static char buf[32];
    extern void _GetImageFolder(char*,int,int,int);
    _GetImageFolder(buf,get_file_next_counter(),CAM_DATE_FOLDER_NAMING,time(NULL));
    strncpy(out,buf,15);
    out[15] = 0;
}
#else
long get_target_dir_num() 
{
    return 0;
}
#endif
