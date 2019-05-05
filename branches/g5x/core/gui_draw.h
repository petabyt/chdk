#ifndef GUI_DRAW_H
#define GUI_DRAW_H

#include "conf.h"       // load OSD_pos & OSD_scale
#include "palette.h"

//-------------------------------------------------------------------
#define FONT_REAL_WIDTH         8
#define FONT_REAL_HEIGHT        16

#define FONT_WIDTH              8
#define FONT_HEIGHT             16
// Name of default symbol file (for reset)
#define DEFAULT_SYMBOL_FILE "A/CHDK/SYMBOLS/icon_10.rbf"

#ifdef THUMB_FW
#ifndef BITMAP_YUV2

#undef FONT_WIDTH
#undef FONT_HEIGHT
#undef DEFAULT_SYMBOL_FILE

#define FONT_WIDTH              14
#define FONT_HEIGHT             32
// Name of default symbol file (for reset)
#define DEFAULT_SYMBOL_FILE "A/CHDK/SYMBOLS/icon_16.rbf"

#endif
#endif

// Text justification & options
#define TEXT_LEFT               0
#define TEXT_CENTER             1
#define TEXT_RIGHT              2
#define TEXT_FILL               16

// Drawing flag options for rectangle and ellipse
#define RECT_BORDER0            0       // Border widths
#define RECT_BORDER1            1
#define RECT_BORDER2            2
#define RECT_BORDER3            3
#define RECT_BORDER4            4
#define RECT_BORDER5            5
#define RECT_BORDER6            6
#define RECT_BORDER7            7
#define RECT_BORDER_MASK        7
#define DRAW_FILLED             8       // Filled rectangle or ellipse
#define RECT_SHADOW0            0       // Drop shadow widths
#define RECT_SHADOW1            0x10
#define RECT_SHADOW2            0x20
#define RECT_SHADOW3            0x30
#define RECT_SHADOW_MASK        0x30
#define RECT_ROUND_CORNERS      0x40    // Round corners on rectangle

//-------------------------------------------------------------------
extern void draw_init();
extern void draw_set_draw_proc(void (*pixel_proc)(unsigned int offset, color cl));
extern void update_draw_proc();

extern void draw_set_guard();
extern int draw_test_guard();

extern color draw_get_pixel_unrotated(coord x, coord y);

extern void draw_pixel(coord x, coord y, color cl);
extern void draw_pixel_unrotated(coord x, coord y, color cl);

extern void draw_dblpixel_raw(unsigned int offset, unsigned int px, unsigned int op);
extern void set_transparent(unsigned int offset, int n_pixel);
extern unsigned int color_to_rawpx(color cl, unsigned int *op);

extern void draw_line(coord x1, coord y1, coord x2, coord y2, color cl);
extern void draw_hline(coord x, coord y, int len, color cl);
extern void draw_vline(coord x, coord y, int len, color cl);

// draw shapes
extern void draw_rectangle(coord x1, coord y1, coord x2, coord y2, twoColors cl, int flags);
extern void draw_ellipse(coord xc, coord yc, unsigned int a, unsigned int b, color cl, int flags);

// draw text
extern int  text_dimensions(const char *s, int width, int max_chars, int *max_lines);
extern void draw_char(coord x, coord y, const char ch, twoColors cl);
extern int  draw_string_clipped(coord x, coord y, const char *s, twoColors cl, int max_width);
extern int  draw_string(coord x, coord y, const char *s, twoColors cl);
extern int  draw_string_justified(coord x, coord y, const char *s, twoColors cl, int xo, int max_width, int justification);
extern int  draw_text_justified(coord x, coord y, const char *s, twoColors cl, int max_chars, int max_lines, int justification);
extern void draw_string_scaled(coord x, coord y, const char *s, twoColors cl, int xsize, int ysize);
extern void draw_osd_string(OSD_pos pos, int xo, int yo, char *s, twoColors c, OSD_scale scale);
extern void draw_button(int x, int y, int w, int str_id, int active);

extern void draw_txt_string(coord col, coord row, const char *str, twoColors cl);

extern void draw_restore();

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
