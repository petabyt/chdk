#ifndef GUI_DRAW_H
#define GUI_DRAW_H

#include "conf.h"       // load OSD_pos & OSD_scale

//-------------------------------------------------------------------

// Common colors that are the same in all palettes
#define COLOR_TRANSPARENT               0x00
#define COLOR_BLACK                     0xFF

//-------------------------------------------------------------------

// For CHDK core code use #define versions of color values
// For module and platform independent code use the module_colors[X] version (see below)
#ifndef CHDK_MODULE_CODE

#include "camera.h"     // ensure the camera definition is loaded

// Include the palette file for the camera model currently being compiled.
#include "platform_palette.h"

//-----------------------------------------------------------------------------------------
// Setup default colors not already defined above

#if !defined(COLOR_GREY_DK_TRANS)
    #define COLOR_GREY_DK_TRANS     COLOR_GREY_DK
#endif

// Define colors for cameras using custom colors (CHDK_COLOR_BASE)
#if defined(CAM_LOAD_CUSTOM_COLORS)
    // Default Canon colors that are the same in record and play modes
    #if !defined(COLOR_GREY_DK)
        #define COLOR_GREY_DK       0x1a
    #endif
    #if !defined(COLOR_GREY)
        #define COLOR_GREY          0x16
    #endif
    #if !defined(COLOR_GREY_LT)
        #define COLOR_GREY_LT       0x0E
    #endif
    #if !defined(COLOR_WHITE)
        #define COLOR_WHITE         0x01
    #endif
    #if !defined(COLOR_RED)
        // CHDK colors loaded into these locations in the camera palette by load_chdk_palette()
        #define COLOR_RED           (CHDK_COLOR_BASE+0)
        #define COLOR_RED_DK        (CHDK_COLOR_BASE+1)
        #define COLOR_RED_LT        (CHDK_COLOR_BASE+2)
        #define COLOR_GREEN         (CHDK_COLOR_BASE+3)
        #define COLOR_GREEN_DK      (CHDK_COLOR_BASE+4)
        #define COLOR_GREEN_LT      (CHDK_COLOR_BASE+5)
        #define COLOR_BLUE          (CHDK_COLOR_BASE+6)
        #define COLOR_BLUE_DK       (CHDK_COLOR_BASE+7)
        #define COLOR_BLUE_LT       (CHDK_COLOR_BASE+8)
        #define COLOR_MAGENTA       (CHDK_COLOR_BASE+9)
        #define COLOR_YELLOW        (CHDK_COLOR_BASE+10)
        #define COLOR_YELLOW_DK     (CHDK_COLOR_BASE+11)
        #define COLOR_YELLOW_LT     (CHDK_COLOR_BASE+12)
    #endif
    #if !defined(COLOR_ICON_REC_BLUE)
        #define COLOR_ICON_REC_BLUE     COLOR_BLUE
        #define COLOR_ICON_REC_BLUE_DK  COLOR_BLUE_DK
        #define COLOR_ICON_REC_BLUE_LT  COLOR_BLUE_LT
    #endif
    #if !defined(COLOR_ICON_PLY_BLUE)
        #define COLOR_ICON_PLY_BLUE     COLOR_BLUE
        #define COLOR_ICON_PLY_BLUE_DK  COLOR_BLUE_DK
        #define COLOR_ICON_PLY_BLUE_LT  COLOR_BLUE_LT
    #endif
    // Define default icon colors
    // 3 shades of Red, Green, Yellow and Grey
    // Playback colors are the same (set later)
    #define COLOR_ICON_REC_RED          COLOR_RED
    #define COLOR_ICON_REC_RED_DK       COLOR_RED_DK
    #define COLOR_ICON_REC_RED_LT       COLOR_RED_LT
    #define COLOR_ICON_REC_GREEN        COLOR_GREEN
    #define COLOR_ICON_REC_GREEN_DK     COLOR_GREEN_DK
    #define COLOR_ICON_REC_GREEN_LT     COLOR_GREEN_LT
    #define COLOR_ICON_REC_YELLOW       COLOR_YELLOW
    #define COLOR_ICON_REC_YELLOW_DK    COLOR_YELLOW_DK
    #define COLOR_ICON_REC_YELLOW_LT    COLOR_YELLOW_LT
    #define COLOR_ICON_REC_GREY         COLOR_GREY
    #define COLOR_ICON_REC_GREY_DK      COLOR_GREY_DK
    #define COLOR_ICON_REC_GREY_LT      COLOR_GREY_LT
#endif

// Define histogram colors if not already defined above
#if !defined(COLOR_REC_RED)
    #define COLOR_REC_RED               COLOR_RED
#endif
#if !defined(COLOR_PLY_RED)
    #define COLOR_PLY_RED               COLOR_RED
#endif
#if !defined(COLOR_REC_BLUE)
    #define COLOR_REC_BLUE              COLOR_BLUE
#endif
#if !defined(COLOR_PLY_BLUE)
    #define COLOR_PLY_BLUE              COLOR_BLUE
#endif
#if !defined(COLOR_REC_GREEN)
    #define COLOR_REC_GREEN             COLOR_GREEN
#endif
#if !defined(COLOR_PLY_GREEN)
    #define COLOR_PLY_GREEN             COLOR_GREEN
#endif
#if !defined(COLOR_REC_CYAN)
    #define COLOR_REC_CYAN              COLOR_BLUE_LT
#endif
#if !defined(COLOR_PLY_CYAN)
    #define COLOR_PLY_CYAN              COLOR_BLUE_LT
#endif
#if !defined(COLOR_REC_YELLOW)
    #define COLOR_REC_YELLOW            COLOR_YELLOW
#endif
#if !defined(COLOR_PLY_YELLOW)
    #define COLOR_PLY_YELLOW            COLOR_YELLOW
#endif
#if !defined(COLOR_REC_MAGENTA)
    #define COLOR_REC_MAGENTA           COLOR_MAGENTA
#endif
#if !defined(COLOR_PLY_MAGENTA)
    #define COLOR_PLY_MAGENTA           COLOR_MAGENTA
#endif

// Define default icon colors if not already defined above
// 3 shades of Red, Green, Yellow and Grey
// Separate definitions for record and playback mode
// to cater for cameras with variable palettes
#if !defined(COLOR_ICON_REC_RED)        // Record mode colors
    #define COLOR_ICON_REC_RED          0x22
    #define COLOR_ICON_REC_RED_DK       0x2F
    #define COLOR_ICON_REC_RED_LT       0x26
    #define COLOR_ICON_REC_GREEN        0x5F
    #define COLOR_ICON_REC_GREEN_DK     0x25
    #define COLOR_ICON_REC_GREEN_LT     0x51
    #define COLOR_ICON_REC_YELLOW       0x6F
    #define COLOR_ICON_REC_YELLOW_DK    0x6F
    #define COLOR_ICON_REC_YELLOW_LT    0x66
    #define COLOR_ICON_REC_GREY         COLOR_GREY
    #define COLOR_ICON_REC_GREY_DK      0x33
    #define COLOR_ICON_REC_GREY_LT      0x13
#endif
#if !defined(COLOR_ICON_PLY_RED)        // Playback mode colors
    #define COLOR_ICON_PLY_RED          COLOR_ICON_REC_RED
    #define COLOR_ICON_PLY_RED_DK       COLOR_ICON_REC_RED_DK
    #define COLOR_ICON_PLY_RED_LT       COLOR_ICON_REC_RED_LT
    #define COLOR_ICON_PLY_GREEN        COLOR_ICON_REC_GREEN
    #define COLOR_ICON_PLY_GREEN_DK     COLOR_ICON_REC_GREEN_DK
    #define COLOR_ICON_PLY_GREEN_LT     COLOR_ICON_REC_GREEN_LT
    #define COLOR_ICON_PLY_YELLOW       COLOR_ICON_REC_YELLOW
    #define COLOR_ICON_PLY_YELLOW_DK    COLOR_ICON_REC_YELLOW_DK
    #define COLOR_ICON_PLY_YELLOW_LT    COLOR_ICON_REC_YELLOW_LT
    #define COLOR_ICON_PLY_GREY         COLOR_ICON_REC_GREY
    #define COLOR_ICON_PLY_GREY_DK      COLOR_ICON_REC_GREY_DK
    #define COLOR_ICON_PLY_GREY_LT      COLOR_ICON_REC_GREY_LT
#endif
// Special case for light & dark blue
// Currently only defined for cameras with custom colors, others will use same shade for all three
#if !defined(COLOR_ICON_REC_BLUE)
    #define COLOR_ICON_REC_BLUE         COLOR_REC_BLUE
    #define COLOR_ICON_REC_BLUE_DK      COLOR_REC_BLUE
    #define COLOR_ICON_REC_BLUE_LT      COLOR_REC_BLUE
#endif
#if !defined(COLOR_ICON_PLY_BLUE)
    #define COLOR_ICON_PLY_BLUE         COLOR_PLY_BLUE
    #define COLOR_ICON_PLY_BLUE_DK      COLOR_PLY_BLUE
    #define COLOR_ICON_PLY_BLUE_LT      COLOR_PLY_BLUE
#endif
// Transparent grey
#if !defined(COLOR_ICON_REC_GREY_DK_TRANS)
    #define COLOR_ICON_REC_GREY_DK_TRANS    COLOR_GREY_DK_TRANS
#endif
#if !defined(COLOR_ICON_PLY_GREY_DK_TRANS)
    #define COLOR_ICON_PLY_GREY_DK_TRANS    COLOR_GREY_DK_TRANS
#endif

//-----------------------------------------------------------------------------------------

#else

// Module & platform independent code color settings

extern  const unsigned char const module_colors[];

#define COLOR_WHITE         (module_colors[0])
#define COLOR_RED           (module_colors[1])
#define COLOR_GREY          (module_colors[2])
#define COLOR_GREY_DK       (module_colors[3])
#define COLOR_GREEN         (module_colors[4])
#define COLOR_BLUE_LT       (module_colors[5])
#define COLOR_BLUE          (module_colors[6])
#define COLOR_YELLOW        (module_colors[7])
#define COLOR_RED_DK        (module_colors[8])
#define COLOR_RED_LT        (module_colors[9])
#define COLOR_GREY_LT       (module_colors[10])
// Histogram colors (defined for both record and playback mode)
#define COLOR_REC_RED       (module_colors[11])
#define COLOR_PLY_RED       (module_colors[12])
#define COLOR_REC_GREEN     (module_colors[13])
#define COLOR_PLY_GREEN     (module_colors[14])
#define COLOR_REC_BLUE      (module_colors[15])
#define COLOR_PLY_BLUE      (module_colors[16])
#define COLOR_REC_CYAN      (module_colors[17])
#define COLOR_PLY_CYAN      (module_colors[18])
#define COLOR_REC_MAGENTA   (module_colors[19])
#define COLOR_PLY_MAGENTA   (module_colors[20])
#define COLOR_REC_YELLOW    (module_colors[21])
#define COLOR_PLY_YELLOW    (module_colors[22])

#endif  // CHDK_MODULE_CODE

//-------------------------------------------------------------------

#define FONT_WIDTH                      8
#define FONT_HEIGHT                     16

//-------------------------------------------------------------------
extern void draw_init();
extern void draw_set_draw_proc(void (*pixel_proc)(unsigned int offset, color cl));

extern void draw_set_guard();
extern int draw_test_guard();

extern color draw_get_pixel(coord x, coord y);

extern void draw_pixel(coord x, coord y, color cl);

extern void draw_line(coord x1, coord y1, coord x2, coord y2, color cl);
extern void draw_hline(coord x, coord y, int len, color cl);
extern void draw_vline(coord x, coord y, int len, color cl);

// draw frame
extern void draw_rect(coord x1, coord y1, coord x2, coord y2, color cl);
extern void draw_rect_thick(coord x1, coord y1, coord x2, coord y2, color cl, int thickness);
extern void draw_rect_shadow(coord x1, coord y1, coord x2, coord y2, color cl, int thickness);
extern void draw_round_rect(coord x1, coord y1, coord x2, coord y2, color cl);
extern void draw_round_rect_thick(coord x1, coord y1, coord x2, coord y2, color cl, int thickness);
// color: hi_byte - BG; lo_byte - FG
extern void draw_filled_rect(coord x1, coord y1, coord x2, coord y2, color cl);
extern void draw_filled_rect_thick(coord x1, coord y1, coord x2, coord y2, color cl, int thickness);
extern void draw_filled_round_rect(coord x1, coord y1, coord x2, coord y2, color cl);
extern void draw_filled_round_rect_thick(coord x1, coord y1, coord x2, coord y2, color cl, int thickness);

extern void draw_char(coord x, coord y, const char ch, color cl);
extern void draw_string(coord x, coord y, const char *s, color cl);
extern void draw_char_scaled(coord x, coord y, const char ch, color cl, int xsize, int ysize);
extern void draw_string_scaled(coord x, coord y, const char *s, color cl, int xsize, int ysize);
extern void draw_osd_string(OSD_pos pos, int xo, int yo, char *s, color c, OSD_scale scale);

extern void draw_txt_rect(coord col, coord row, unsigned int length, unsigned int height, color cl);
extern void draw_txt_rect_exp(coord col, coord row, unsigned int length, unsigned int height, unsigned int exp, color cl);
extern void draw_txt_filled_rect(coord col, coord row, unsigned int length, unsigned int height, color cl);
extern void draw_txt_filled_rect_exp(coord col, coord row, unsigned int length, unsigned int height, unsigned int exp, color cl);
extern void draw_txt_string(coord col, coord row, const char *str, color cl);
extern void draw_txt_char(coord col, coord row, const char ch, color cl);

extern void draw_restore();

extern void draw_fill(coord x, coord y, color cl_fill, color cl_bound);
extern void draw_circle(coord x, coord y, const unsigned int r, color cl);
extern void draw_ellipse(coord xc, coord yc, unsigned int a, unsigned int b, color cl);
extern void draw_filled_ellipse(coord xc, coord yc, unsigned int a, unsigned int b, color cl);

extern void draw_get_icon_colors();
extern color icon_green[3], icon_red[3], icon_yellow[3], icon_grey[3];

//-------------------------------------------------------------------

#define NUM_SCRIPT_COLORS   19
extern const unsigned char const script_colors[NUM_SCRIPT_COLORS][2];

//-------------------------------------------------------------------
#endif
