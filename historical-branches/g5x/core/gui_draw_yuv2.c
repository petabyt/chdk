#include "platform.h"
#include "font.h"
#include "gui_draw.h"

#define GET_FONT_COMPRESSION_MODE 1
#include "../lib/font/font_8x16_uni_packed.h"
#undef  GET_FONT_COMPRESSION_MODE

#ifndef DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY
#error DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY is required for DIGIC 6 ports
#endif

//-------------------------------------------------------------------

// Low level draw functions for YUV bitmap with 2x horizontal & vertical scaling handled.
// Bitmap buffer is 720 x 480 pixels.
// CHDK pixels are rendered as 2x2 YUV pixels.

//-------------------------------------------------------------------

void draw_init()
{
    draw_set_draw_proc(NULL);
    draw_set_guard();
}

//-------------------------------------------------------------------

// CHDK palette colors for the YUV bitmap using 2x vertical & horizontal scaling - e.g. G5X

// YUV color values = each int represents 2 screen pixels YVYU
unsigned int yuv_colors[] =
{
        0x00800080,                 // Transparent
        0x00800080,                 // Black
        0xFF80FF80,                 // White
        0x4CFF4C54,                 // Red
        0x30D03065,                 // Dark Red
        0xA6BFA66A,                 // Light Red
        0x9615962B,                 // Green
        0x5E3D5E4A,                 // Dark Green
        0xCB4ACB55,                 // Light Green
        0x1D6B1DFF,                 // Blue
        0x127212D0,                 // Dark Blue
        0xB300B3AB,                 // Light Blue / Cyan
        0x80808080,                 // Grey
        0x40804080,                 // Dark Grey
        0xC080C080,                 // Light Grey
        0xE294E200,                 // Yellow
        0x8E8D8E30,                 // Dark Yellow
        0xF18AF140,                 // Light Yellow
        0x40804080,                 // Transparent Dark Grey
        0x69EA69D4,                 // Magenta
};

// YUV color opacity values = each short represents opacity for two YUV pixels
unsigned short yuv_opacity[] =
{
        0x0000,                 // Transparent
        0xFFFF,                 // Black
        0xFFFF,                 // White
        0xFFFF,                 // Red
        0xFFFF,                 // Dark Red
        0xFFFF,                 // Light Red
        0xFFFF,                 // Green
        0xFFFF,                 // Dark Green
        0xFFFF,                 // Light Green
        0xFFFF,                 // Blue
        0xFFFF,                 // Dark Blue
        0xFFFF,                 // Light Blue / Cyan
        0xFFFF,                 // Grey
        0xFFFF,                 // Dark Grey
        0xFFFF,                 // Light Grey
        0xFFFF,                 // Yellow
        0xFFFF,                 // Dark Yellow
        0xFFFF,                 // Light Yellow
        0x8080,                 // Transparent Dark Grey
        0xFFFF,                 // Magenta
};

// Convert 8 bit palette number / CHDK color index into YUV table index
// Simulates 256 colors for palette display & scripts
unsigned char color_2_idx[] =
{
        0, 1, 2,                                                        // transparent, black, white,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,    // colors + trans grey
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19,        // colors
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        1                                                               // black
};

//-------------------------------------------------------------------

extern int active_bitmap_buffer;
extern unsigned int* yuv_buffers[];
extern unsigned short* opacity_buffers[];

void draw_pixel_std(unsigned int offset, color cl)
{
    cl = color_2_idx[cl];
    unsigned int c = yuv_colors[cl];
    unsigned short o = yuv_opacity[cl];

    unsigned short *ob = (unsigned short *)(opacity_buffers[active_bitmap_buffer]);
    unsigned int *bb = (unsigned int *)(yuv_buffers[active_bitmap_buffer]);

    ob[offset] = o;                                 // 1st row - 2 pixels
    ob[offset+camera_screen.buffer_width/2] = o;    // 2nd row - 2 pixels

    bb[offset] = c;                                 // 1st row - 2 pixels
    bb[offset+camera_screen.buffer_width/2] = c;    // 2nd row - 2 pixels
}

//-------------------------------------------------------------------

// TODO:
void draw_set_guard()
{
}

// TODO:
int draw_test_guard()
{
    return 1;
}

//-------------------------------------------------------------------

color draw_get_pixel_unrotated(coord x, coord y)
{
    if ((x < 0) || (y < 0) || (x >= camera_screen.width) || (y >= camera_screen.height))
        return 0;
    unsigned int *bb = (unsigned int *)(yuv_buffers[active_bitmap_buffer]);
    unsigned int v = bb[y * camera_screen.buffer_width + x];
    for (int i = 0; i < IDX_COLOR_MAX; i += 1)
        if (yuv_colors[i] == v)
            return i;
    return 0;
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

// Placeholder for module build - not used for this bitmap type
unsigned char *chdk_colors;

void set_palette()
{
}

color get_script_color(int cl)
{
    return cl;
}

// Convert user adjustable color (from conf struct) to Canon colors
color chdkColorToCanonColor(chdkColor col)
{
    return col.col;
}

twoColors user_color(confColor cc)
{
    return MAKE_COLOR(cc.bg.col,cc.fg.col);
}

//-------------------------------------------------------------------

// direct drawing functions for YUV overlay, currently used by the zebra module
// ATTENTION: these functions do not support guard pixels or rotation

// function for setting part of the overlay transparent (DIGIC 6 only), used in zebra module
// n_pixel is the number of pixels to set
// offst is the byte offset in bitmap_buffer, 2 bytes per pixel
void set_transparent(unsigned int offst, int n_pixel)
{
    extern void _bzero(char *s, int n);
    extern void _memset32(char *s, int n, unsigned int pattern);

    //offset is the byte (same as pixel) offset in the opacity buffer
    unsigned int offset = offst>>2;
    unsigned int w_pattern = 0x00800080;

    int active_buffer_index = active_bitmap_buffer & 1;

    _memset32((char*)&yuv_buffers[active_buffer_index][offst], n_pixel<<1, w_pattern);
    _bzero((char*)&opacity_buffers[active_buffer_index][offset], n_pixel);

}

// function for drawing a whole yuv unit (2 pixels, aligned)
// opacity is a single byte, used for both pixels
// drawing offset is pixel offset, calculated by caller
void draw_dblpixel_raw(unsigned int offset, unsigned int px, unsigned int op)
{
    offset >>= 2;
    unsigned short * opbuf = (unsigned short*)(opacity_buffers[active_bitmap_buffer]);
    unsigned int * bmbuf = (unsigned int*)(yuv_buffers[active_bitmap_buffer]);
    bmbuf[offset] = px;
    opbuf[offset] = op | (op<<8);
}

// translate single byte CHDK color to a whole yuv unit (2 pixels)
// opacity is returned via the second argument
unsigned int color_to_rawpx(color cl, unsigned int *op)
{
    cl = color_2_idx[cl];
    if (op)
        *op = yuv_opacity[cl];
    return yuv_colors[cl];
}

//-------------------------------------------------------------------
