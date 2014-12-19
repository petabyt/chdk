#ifndef GUI_DRAW_H
#define GUI_DRAW_H

#include "conf.h"       // load OSD_pos & OSD_scale
#include "palette.h"

//-------------------------------------------------------------------

extern  unsigned char   *chdk_colors;

#define IDX_COLOR_TRANSPARENT       0
#define IDX_COLOR_BLACK             1
#define IDX_COLOR_WHITE             2
#define IDX_COLOR_RED               3
#define IDX_COLOR_RED_DK            4
#define IDX_COLOR_RED_LT            5
#define IDX_COLOR_GREEN             6
#define IDX_COLOR_GREEN_DK          7
#define IDX_COLOR_GREEN_LT          8
#define IDX_COLOR_BLUE              9
#define IDX_COLOR_BLUE_DK           10
#define IDX_COLOR_BLUE_LT           11
#define IDX_COLOR_GREY              12
#define IDX_COLOR_GREY_DK           13
#define IDX_COLOR_GREY_LT           14
#define IDX_COLOR_YELLOW            15
#define IDX_COLOR_YELLOW_DK         16
#define IDX_COLOR_YELLOW_LT         17
#define IDX_COLOR_GREY_DK_TRANS     18
#define IDX_COLOR_MAGENTA           19
#define IDX_COLOR_CYAN              IDX_COLOR_BLUE_LT

#define IDX_COLOR_MAX               19

#define COLOR_WHITE             (chdk_colors[IDX_COLOR_WHITE])
#define COLOR_RED               (chdk_colors[IDX_COLOR_RED])
#define COLOR_RED_DK            (chdk_colors[IDX_COLOR_RED_DK])
#define COLOR_RED_LT            (chdk_colors[IDX_COLOR_RED_LT])
#define COLOR_GREEN             (chdk_colors[IDX_COLOR_GREEN])
#define COLOR_GREEN_DK          (chdk_colors[IDX_COLOR_GREEN_DK])
#define COLOR_GREEN_LT          (chdk_colors[IDX_COLOR_GREEN_LT])
#define COLOR_BLUE              (chdk_colors[IDX_COLOR_BLUE])
#define COLOR_BLUE_DK           (chdk_colors[IDX_COLOR_BLUE_DK])
#define COLOR_BLUE_LT           (chdk_colors[IDX_COLOR_BLUE_LT])
#define COLOR_GREY              (chdk_colors[IDX_COLOR_GREY])
#define COLOR_GREY_DK           (chdk_colors[IDX_COLOR_GREY_DK])
#define COLOR_GREY_LT           (chdk_colors[IDX_COLOR_GREY_LT])
#define COLOR_YELLOW            (chdk_colors[IDX_COLOR_YELLOW])
#define COLOR_YELLOW_DK         (chdk_colors[IDX_COLOR_YELLOW_DK])
#define COLOR_YELLOW_LT         (chdk_colors[IDX_COLOR_YELLOW_LT])
#define COLOR_GREY_DK_TRANS     (chdk_colors[IDX_COLOR_GREY_DK_TRANS])
#define COLOR_MAGENTA           (chdk_colors[IDX_COLOR_MAGENTA])
#define COLOR_CYAN              (chdk_colors[IDX_COLOR_CYAN])

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
extern void draw_filled_rect(coord x1, coord y1, coord x2, coord y2, twoColors cl);
extern void draw_filled_rect_thick(coord x1, coord y1, coord x2, coord y2, twoColors cl, int thickness);
extern void draw_filled_round_rect(coord x1, coord y1, coord x2, coord y2, twoColors cl);
extern void draw_filled_round_rect_thick(coord x1, coord y1, coord x2, coord y2, twoColors cl, int thickness);

extern void draw_char(coord x, coord y, const char ch, twoColors cl);
extern int  draw_string(coord x, coord y, const char *s, twoColors cl);
extern void draw_string_box(coord x, coord y, int left, int width, const char *buf, twoColors txtcol);
extern void draw_char_scaled(coord x, coord y, const char ch, twoColors cl, int xsize, int ysize);
extern void draw_string_scaled(coord x, coord y, const char *s, twoColors cl, int xsize, int ysize);
extern void draw_osd_string(OSD_pos pos, int xo, int yo, char *s, twoColors c, OSD_scale scale);

extern void draw_txt_rect(coord col, coord row, unsigned int length, unsigned int height, color cl);
extern void draw_txt_rect_exp(coord col, coord row, unsigned int length, unsigned int height, unsigned int exp, color cl);
extern void draw_txt_filled_rect(coord col, coord row, unsigned int length, unsigned int height, twoColors cl);
extern void draw_txt_filled_rect_exp(coord col, coord row, unsigned int length, unsigned int height, unsigned int exp, twoColors cl);
extern void draw_txt_string(coord col, coord row, const char *str, twoColors cl);
extern void draw_txt_char(coord col, coord row, const char ch, twoColors cl);

extern void draw_restore();

extern void draw_circle(coord x, coord y, const unsigned int r, color cl);
extern void draw_ellipse(coord xc, coord yc, unsigned int a, unsigned int b, color cl);
extern void draw_filled_ellipse(coord xc, coord yc, unsigned int a, unsigned int b, color cl);

extern color get_script_color(int cl);

extern color chdkColorToCanonColor(chdkColor c);
extern twoColors user_color(confColor c);

//-------------------------------------------------------------------
// Icon rendering using an array of drawing actions

// Allowed drawing actions for icons
enum icon_actions
{
    IA_END,
    IA_HLINE,
    IA_VLINE,
    IA_LINE,
    IA_RECT,
    IA_FILLED_RECT,
    IA_ROUND_RECT,
    IA_FILLED_ROUND_RECT
};

// Structure for a drawing action
typedef struct
{
    unsigned char   action;
    unsigned char   x1, y1;
    unsigned char   x2, y2;
    color           cb, cf;     // Note these should be IDX_COLOR_xxx values, converted to actual colors at runtime
} icon_cmd;

// Draw an icon from a list of actions
extern void draw_icon_cmds(coord x, coord y, icon_cmd *cmds);

//-------------------------------------------------------------------
#endif
