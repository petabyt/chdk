#include "platform.h"
#include "font.h"
#include "gui_draw.h"

#define GET_FONT_COMPRESSION_MODE 1
#include "../lib/font/font_8x16_uni_packed.h"
#undef  GET_FONT_COMPRESSION_MODE

//-------------------------------------------------------------------

// Low level draw functions for 8bpp palette based bitmap.

//-------------------------------------------------------------------

extern unsigned int rotate_base;

//-------------------------------------------------------------------

#ifdef DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY
extern char* bitmap_buffer[];
extern int active_bitmap_buffer;
#else
static char* frame_buffer[2];
#endif

//-------------------------------------------------------------------

void draw_init()
{
#ifndef DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY
    frame_buffer[0] = vid_get_bitmap_fb();
    frame_buffer[1] = frame_buffer[0] + camera_screen.buffer_size;
#endif
    draw_set_draw_proc(NULL);
    draw_set_guard();
}

//-------------------------------------------------------------------

void draw_pixel_std(unsigned int offset, color cl)
{
    // drawing on 8bpp paletted overlay
#ifdef DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY
    bitmap_buffer[active_bitmap_buffer][offset] = cl;
#else
    frame_buffer[0][offset] = frame_buffer[1][offset] = cl;
#endif
}

//-------------------------------------------------------------------

#define GUARD_VAL   COLOR_GREY_DK

void draw_set_guard()
{
#ifdef DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY
    *((unsigned char*)(bitmap_buffer[0])) = GUARD_VAL;
    *((unsigned char*)(bitmap_buffer[1])) = GUARD_VAL;
#else
    *((unsigned char*)(frame_buffer[0])) = GUARD_VAL;
    *((unsigned char*)(frame_buffer[1])) = GUARD_VAL;
#endif
}

int draw_test_guard()
{
#ifdef DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY
    if (*((unsigned char*)(bitmap_buffer[active_bitmap_buffer])) != GUARD_VAL) return 0;
#else
    if (*((unsigned char*)(frame_buffer[0])) != GUARD_VAL) return 0;
    if (*((unsigned char*)(frame_buffer[1])) != GUARD_VAL) return 0;
#endif
    return 1;
}

//-------------------------------------------------------------------

color draw_get_pixel(coord x, coord y)
{
    if ((x < 0) || (y < 0) || (x >= camera_screen.width) || (y >= camera_screen.height)) return 0;
    if (conf.rotate_osd)
    {
#ifdef DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY
        return bitmap_buffer[0][rotate_base - (y * camera_screen.buffer_width + ASPECT_XCORRECTION(x))];
#else
        return frame_buffer[0][rotate_base - (y * camera_screen.buffer_width + ASPECT_XCORRECTION(x))];
#endif
    }
    else
    {
#ifdef DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY
        return bitmap_buffer[0][y * camera_screen.buffer_width + ASPECT_XCORRECTION(x)];
#else
        return frame_buffer[0][y * camera_screen.buffer_width + ASPECT_XCORRECTION(x)];
#endif
    }
}

color draw_get_pixel_unrotated(coord x, coord y)
{
    if ((x < 0) || (y < 0) || (x >= camera_screen.width) || (y >= camera_screen.height)) return 0;
#ifdef DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY
    return bitmap_buffer[0][y * camera_screen.buffer_width + ASPECT_XCORRECTION(x)];
#else
    return frame_buffer[0][y * camera_screen.buffer_width + ASPECT_XCORRECTION(x)];
#endif
}

//-------------------------------------------------------------------
extern unsigned char* get_cdata(unsigned int *offset, unsigned int *size, const char ch);

// DIGIC II...5
void draw_char(coord x, coord y, const char ch, twoColors cl)
{
    int i, ii;

    unsigned int offset, size;
    unsigned char *sym = get_cdata(&offset, &size, ch);

    // First draw blank lines at top
    for (i=0; i<offset; i++)
        draw_hline(x, y+i, FONT_WIDTH, BG_COLOR(cl));

    // Now draw character data

    int j;
    for (j=i; i<size;)
    {
        unsigned int dsym;
        int rep;
#ifdef BUILTIN_FONT_RLE_COMPRESSED
        dsym = fontdata_lookup[sym[j] & 0x7f];
        rep = sym[j] & 0x80;
#else
        dsym = sym[j];
        rep = 0;
#endif
        for (ii=0; ii<FONT_WIDTH; ii++)
        {
            draw_pixel(x+ii, y+i, (dsym & (0x80>>ii))? FG_COLOR(cl) : BG_COLOR(cl));
        }
        if (rep)
        {
            i++;
            for (ii=0; ii<FONT_WIDTH; ii++)
            {
                draw_pixel(x+ii, y+i, (dsym & (0x80>>ii))? FG_COLOR(cl) : BG_COLOR(cl));
            }
        }
        i++;
        j++;
    }

    // Last draw blank lines at bottom
    for (; i<FONT_HEIGHT; i++)
        draw_hline(x, y+i, FONT_WIDTH, BG_COLOR(cl));
}

void draw_char_unscaled(coord x, coord y, const char ch, twoColors cl)
{
    draw_char(x, y, ch, cl);
}

void draw_char_scaled(coord x, coord y, const char ch, twoColors cl, int xsize, int ysize)
{
    int i, ii;

    twoColors clf = MAKE_COLOR(FG_COLOR(cl),FG_COLOR(cl));
    twoColors clb = MAKE_COLOR(BG_COLOR(cl),BG_COLOR(cl));

    unsigned int offset, size;
    unsigned char *sym = get_cdata(&offset, &size, ch);

    // First draw blank lines at top
    if (offset > 0)
        draw_rectangle(x,y,x+FONT_WIDTH*xsize-1,y+offset*ysize+ysize-1,clb,RECT_BORDER0|DRAW_FILLED);

    // Now draw character data
    int j;
    for (j=i=offset; i<size;)
    {
        unsigned int dsym;
        int rep;
        unsigned int last;
        int len;
#ifdef BUILTIN_FONT_RLE_COMPRESSED
        dsym = fontdata_lookup[sym[j] & 0x7f];
        rep = sym[j] & 0x80;
#else
        dsym = sym[j];
        rep = 0;
#endif
        while (rep >= 0)
        {
            last = dsym & 0x80;
            len = 1;
            for (ii=1; ii<FONT_WIDTH; ii++)
            {
                if (((dsym << ii) & 0x80) != last)
                {
                    draw_rectangle(x+(ii-len)*xsize,y+i*ysize,x+ii*xsize-1,y+i*ysize+ysize-1,(last)?clf:clb,RECT_BORDER0|DRAW_FILLED);
                    last = (dsym << ii) & 0x80;
                    len = 1;
                }
                else
                {
                    len++;
                }
            }
            draw_rectangle(x+(ii-len)*xsize,y+i*ysize,x+ii*xsize-1,y+i*ysize+ysize-1,(last)?clf:clb,RECT_BORDER0|DRAW_FILLED);
            i++;
            rep -= 0x80;
        }
        j++;
    }

    // Last draw blank lines at bottom
    if (i < FONT_HEIGHT)
        draw_rectangle(x,y+i*ysize,x+FONT_WIDTH*xsize-1,y+FONT_HEIGHT*ysize+ysize-1,clb,RECT_BORDER0|DRAW_FILLED);
}

//-------------------------------------------------------------------

// Draw CHDK OSD string at user defined position and scale
void draw_osd_string(OSD_pos pos, int xo, int yo, char *s, twoColors c, OSD_scale scale)
{
    if ((scale.x == 0) || (scale.y == 0) || ((scale.x == 1) && (scale.y == 1)))
        draw_string(pos.x+xo, pos.y+yo, s, c);
    else
        draw_string_scaled(pos.x+(xo*scale.x), pos.y+(yo*scale.y), s, c, scale.x, scale.y);
}

//-------------------------------------------------------------------

extern unsigned char ply_colors[];
extern unsigned char rec_colors[];

unsigned char *chdk_colors = ply_colors;

void set_palette()
{
    if (camera_info.state.mode_rec)
        chdk_colors = rec_colors;
    else
        chdk_colors = ply_colors;
}

color get_script_color(int cl)
{
    if (cl < 256)
        return cl;
    else
        return chdk_colors[cl-256];
}

// Convert user adjustable color (from conf struct) to Canon colors
color chdkColorToCanonColor(chdkColor col)
{
    if (col.type)
        return chdk_colors[col.col];
    return col.col;
}

twoColors user_color(confColor cc)
{
    color fg = chdkColorToCanonColor(cc.fg);
    color bg = chdkColorToCanonColor(cc.bg);

    return MAKE_COLOR(bg,fg);
}

//-------------------------------------------------------------------

// Only required for YUV bitmap - dummy function for others
void draw_dblpixel_raw(unsigned int offset, unsigned int px, unsigned int op)
{
}

// Only required for YUV bitmap - dummy function for others
void set_transparent(unsigned int offst, int n_pixel)
{
}

unsigned int color_to_rawpx(color cl, unsigned int *op)
{
    return 0;
}

//-------------------------------------------------------------------
