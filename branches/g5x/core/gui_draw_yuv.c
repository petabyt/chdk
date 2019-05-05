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

// Low level draw functions for YUV bitmap with adjusted font size to accommodate 640 pixel wide YUV buffer while keeping 45 characters in the menu display
// 8x16 font is rendered at 14x32 pixels.

//-------------------------------------------------------------------

// macros for computing palette from a single byte color value
#define CALC_YUV_LUMA_OPACITY_FOR_COLOR(color,luma,opacity) \
    { \
        luma = ((color-1)^0xffffffff)&0xf0; \
        opacity = (color&0xf)?255:color; \
    }

#define CALC_YUV_CHROMA_FOR_COLOR(color,u,v) \
    { \
        v = color; \
        u = (v+1); \
        if (!(u&2)) \
        { \
            u = 128; \
            v = 128; \
        } \
        else \
        { \
            u *= 3; \
            v <<= 3; \
        } \
    }

//-------------------------------------------------------------------

extern char* bitmap_buffer[];
extern int active_bitmap_buffer;

unsigned int rotate_base;

//-------------------------------------------------------------------

void draw_init()
{
    draw_set_draw_proc(NULL);
    draw_set_guard();
}

//-------------------------------------------------------------------

extern volatile char *opacity_buffer[];

void draw_pixel_std(unsigned int offset, color cl)
{
    // DIGIC 6, drawing on 16bpp YUV overlay

    int active_buffer_index =  active_bitmap_buffer & 1;
    unsigned char *obu = (unsigned char *)(&opacity_buffer[active_buffer_index][0]);
    unsigned char *bbu = (unsigned char *)(&bitmap_buffer[active_buffer_index][0]);
    unsigned int y;
    unsigned int o;
    CALC_YUV_LUMA_OPACITY_FOR_COLOR(cl,y,o);
    obu[offset] = o;
    register unsigned int offs2 = (offset>>1)<<2;
    if (offset&1) // x is odd
    {
        bbu[offs2+3] = y; // Y
    }
    else // x is even
    {
        unsigned int u;
        unsigned int v;
        CALC_YUV_CHROMA_FOR_COLOR(cl,u,v);
        bbu[offs2+1] = y; // Y
        bbu[offs2+0] = u; // U?
        bbu[offs2+2] = v; // V?

    }
}

// pixel drawing functions for YUV, meant to be optimized for greater speed
// drawing is done directly, drawing function replacement is not supported
// OSD rotation is respected

static unsigned char *current_opacity_buf;
static unsigned char *current_bitmap_buf;
static unsigned char yuvclr[8]; // order of bytes: background u,y,v,opacity; foreground u,y,v,opacity

// sets up decoded colors and buffer addresses for the following drawing operation
static void draw_pixel_simple_start(twoColors tc)
{
    color cl;
    int active_buffer_index =  active_bitmap_buffer & 1;
    current_opacity_buf = (unsigned char *)(&opacity_buffer[active_buffer_index][0]);
    current_bitmap_buf = (unsigned char *)(&bitmap_buffer[active_buffer_index][0]);
    cl = BG_COLOR(tc);
    CALC_YUV_LUMA_OPACITY_FOR_COLOR(cl,yuvclr[1],yuvclr[3]);
    CALC_YUV_CHROMA_FOR_COLOR(cl,yuvclr[0],yuvclr[2]);
    cl = FG_COLOR(tc);
    CALC_YUV_LUMA_OPACITY_FOR_COLOR(cl,yuvclr[5],yuvclr[7]);
    CALC_YUV_CHROMA_FOR_COLOR(cl,yuvclr[4],yuvclr[6]);
}

// px: bit0 unset for background, set for foreground
static void draw_1pixel_simple(coord x, coord y, int px, int vrepeat)
{
    if ((x < 0) || (y < 0) || (x >= camera_screen.width) || (y+vrepeat >= camera_screen.height)/* || ((x == 0) && (y == 0))*/) return;
    unsigned char *obu = current_opacity_buf;
    unsigned char *bbu = current_bitmap_buf;
    unsigned int offset = y * camera_screen.buffer_width + x;
    int plus = camera_screen.buffer_width;
    if (conf.rotate_osd)
    {
        offset = rotate_base - offset;
        plus = -plus;
    }

    if (!offset) return; // skip guard pixel

    int fg = px<<2;
    register unsigned int offs2 = (offset>>1)<<2;

    if (offset&1) // x is odd
    {
        while (1)
        {
            obu[offset] = yuvclr[fg+3];
            bbu[offs2+3] = yuvclr[fg+1]; // Y
            if (!vrepeat) return;
            vrepeat--;
            offset += plus;
            offs2 += (plus<<1);
        }
    }
    else // x is even
    {
        while (1)
        {
            obu[offset] = yuvclr[fg+3];
            bbu[offs2+1] = yuvclr[fg+1]; // Y
            bbu[offs2+0] = yuvclr[fg]; // U
            bbu[offs2+2] = yuvclr[fg+2]; // V
            if (!vrepeat) return;
            vrepeat--;
            offset += plus;
            offs2 += (plus<<1);
        }
    }

}

// px: 2 bits, describing 2 pixels (foreground when set, background when not), LSB is the second pixel
// first pixel specifies chroma
static void draw_2pixels_simple(coord x, coord y, int px, int vrepeat)
{
    if ((x < 0) || (y < 0) || (x+1 >= camera_screen.width) || (y+vrepeat >= camera_screen.height)/* || ((x == 0) && (y == 0))*/) return;
    unsigned int y1, y2;
    unsigned int offset = (y * camera_screen.buffer_width + x)>>1;
    int plus;
    unsigned short co;
    unsigned int yuv;
    if (conf.rotate_osd)
    {
        offset = (rotate_base>>1) - offset;
        plus = -(camera_screen.buffer_width>>1);
        y1 = px&1?4:0;
        y2 = px&2?4+1:0+1;
    }
    else
    {
        plus = camera_screen.buffer_width>>1;
        y1 = px&2?4:0;
        y2 = px&1?4+1:0+1;
    }

    if (!offset) return; // skip guard pixel

    co = yuvclr[y1+3]+(yuvclr[y1+3]<<8);
    yuv = (*(unsigned int*)(&yuvclr[y1]) & 0xffffff) + (yuvclr[y2]<<24);
    unsigned short *obu = (unsigned short *)current_opacity_buf;
    unsigned int *bbu = (unsigned int *)current_bitmap_buf;
    while (1)
    {
        obu[offset] = co;
        bbu[offset] = yuv;
        if (!vrepeat) return;
        vrepeat--;
        offset += plus;
    }

}

void draw_hline_simple(coord x, coord y, int len, int px)
{
    if ((y < 0) || (x >= camera_screen.width) || (y >= camera_screen.height)) return;
    if (x < 0) { len += x; x = 0; }
    if ((x + len) > camera_screen.width) len = camera_screen.width - x;
    /*if ((x == 0) && (y == 0)) { x++; len--; }   // Skip guard pixel*/

    register unsigned int offset = y * camera_screen.buffer_width + (x);
    if (conf.rotate_osd)
    {
        offset = rotate_base - offset - len;
    }

    // Skip guard pixel
    if (!offset)
    {
        offset++;
        len--;
    }

    int fg = px<<2;
    if (offset & 1)
    {
        unsigned char *obu = current_opacity_buf;
        unsigned char *bbu = current_bitmap_buf;
        register unsigned int offs2 = (offset>>1)<<2;
        obu[offset] = yuvclr[fg+3];
        bbu[offs2+3] = yuvclr[fg+1]; // Y
        offset++;
        len--;
    }
    unsigned short co = yuvclr[fg+3]+(yuvclr[fg+3]<<8);
    unsigned int yuv = (*(unsigned int*)(&yuvclr[fg]) & 0xffffff) + (yuvclr[fg+1]<<24);
    unsigned short *obud = (unsigned short *)current_opacity_buf;
    unsigned int *bbud = (unsigned int *)current_bitmap_buf;
    for (; len>0; len-=2, offset+=2)
    {
        obud[offset>>1] = co;
        bbud[offset>>1] = yuv;
    }
    if (len == -1)
    {
        offset--;
        unsigned char *obu = current_opacity_buf;
        unsigned char *bbu = current_bitmap_buf;
        register unsigned int offs2 = (offset>>1)<<2;
        obu[offset] = yuvclr[fg+3];
        bbu[offs2+3] = yuvclr[fg+1]; // Y
    }
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

    _memset32(&bitmap_buffer[active_buffer_index][offst], n_pixel<<1, w_pattern);
    _bzero((char*)&opacity_buffer[active_buffer_index][offset], n_pixel);

}

// function for drawing a whole yuv unit (2 pixels, aligned)
// opacity is a single byte, used for both pixels
// drawing offset is pixel offset, calculated by caller
void draw_dblpixel_raw(unsigned int offset, unsigned int px, unsigned int op)
{
    int active_buffer_index =  active_bitmap_buffer & 1;
    offset >>= 2;
    unsigned short * opbuf = (unsigned short*)(opacity_buffer[active_buffer_index]);
    unsigned int * bmbuf = (unsigned int*)(bitmap_buffer[active_buffer_index]);
    bmbuf[offset] = px;
    opbuf[offset] = op | (op<<8);
}

// translate single byte CHDK color to a whole yuv unit (2 pixels)
// opacity is returned via the second argument
unsigned int color_to_rawpx(color cl, unsigned int *op)
{
    unsigned int y,u,v,o;
    CALC_YUV_CHROMA_FOR_COLOR(cl,u,v);
    CALC_YUV_LUMA_OPACITY_FOR_COLOR(cl,y,o);
    if (op) *op = o;
    return (u&255)+((y&255)<<8)+((v&255)<<16)+(y<<24);
}

//-------------------------------------------------------------------

void draw_set_guard()
{
    opacity_buffer[active_bitmap_buffer][0] = 0x42;
}

int draw_test_guard()
{
    if (opacity_buffer[active_bitmap_buffer][0] != 0x42) return 0;
    return 1;
}

//-------------------------------------------------------------------

color draw_get_pixel_unrotated(coord x, coord y)
{
    // DIGIC 6 not supported
    return 0;
}

//-------------------------------------------------------------------
unsigned char* get_cdata(unsigned int *offset, unsigned int *size, const char ch);

// DIGIC 6: "optimizations" to improve speed
void draw_char(coord x, coord y, const char ch, twoColors cl)
{
    int i, ii;

    unsigned int offset, size;
    unsigned char *sym = get_cdata(&offset, &size, ch);
    color fg = FG_COLOR(cl);
    color bg = BG_COLOR(cl);
    unsigned int fw = FONT_WIDTH;

    draw_pixel_simple_start(cl);

    // First draw blank lines at top
    for (i=0; i<offset; i++)
    {
        int j;
        j = i<<1;
        draw_hline_simple(x, y+j, fw, 0);
        draw_hline_simple(x, y+j+1, fw, 0);
    }

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
        {
            // upscaling 8 pixels to 14
            ii = 0;
            ii += (dsym&1)?3:0;
            ii += (dsym&2)?4:0;
            ii += (dsym&4)?0x18:0;
            ii += (dsym&8)?0x60:0;
            ii += (dsym&16)?0x180:0;
            ii += (dsym&32)?0x600:0;
            ii += (dsym&64)?0x1800:0;
            ii += (dsym&128)?0x2000:0;
            dsym = ii;
        }

        while (rep >= 0)
        {
            unsigned int px;
            unsigned int yt = y+(i<<1);
            ii = 0;
            if (x&1)
            {
                draw_1pixel_simple(x+ii, yt, dsym>>(fw-1), 1);
                ii++;
            }
            for (; ii<fw; ii+=2)
            {
                px = (dsym & ((3<<(fw-2))>>ii))>>(fw-2-ii);
                draw_2pixels_simple(x+ii, yt, px, 1);
            }
            if (x&1)
            {
                draw_1pixel_simple(x+ii-1, yt, dsym&1, 1);
            }
            rep -= 0x80;
            i++;
        }

        j++;
    }

    // Last draw blank lines at bottom
    for (; i<FONT_REAL_HEIGHT; i++)
    {
        int j;
        j = i<<1;
        draw_hline_simple(x, y+j, fw, 0);
        draw_hline_simple(x, y+j+1, fw, 0);
    }
}

void draw_char_scaled(coord x, coord y, const char ch, twoColors cl, int xsize, int ysize)
{
    int i, ii;

    twoColors clf = MAKE_COLOR(FG_COLOR(cl),FG_COLOR(cl));
    twoColors clb = MAKE_COLOR(BG_COLOR(cl),BG_COLOR(cl));

    unsigned int offset, size;
    unsigned char *sym = get_cdata(&offset, &size, ch);

    ysize <<= 1;

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
        unsigned int lastmask = 1 << (FONT_WIDTH-1);
#ifdef BUILTIN_FONT_RLE_COMPRESSED
        dsym = fontdata_lookup[sym[j] & 0x7f];
        rep = sym[j] & 0x80;
#else
        dsym = sym[j];
        rep = 0;
#endif
        {
            // upscaling 8 pixels to 14
            ii = 0;
            ii += (dsym&1)?3:0;
            ii += (dsym&2)?4:0;
            ii += (dsym&4)?0x18:0;
            ii += (dsym&8)?0x60:0;
            ii += (dsym&16)?0x180:0;
            ii += (dsym&32)?0x600:0;
            ii += (dsym&64)?0x1800:0;
            ii += (dsym&128)?0x2000:0;
            dsym = ii;
        }
        while (rep >= 0)
        {
            last = dsym & lastmask;
            len = 1;
            for (ii=1; ii<FONT_WIDTH; ii++)
            {
                if (((dsym << ii) & lastmask) != last)
                {
                    draw_rectangle(x+(ii-len)*xsize,y+i*ysize,x+ii*xsize-1,y+i*ysize+ysize-1,(last)?clf:clb,RECT_BORDER0|DRAW_FILLED);
                    last = (dsym << ii) & lastmask;
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
    if (i < FONT_REAL_HEIGHT)
        draw_rectangle(x,y+i*ysize,x+FONT_WIDTH*xsize-1,y+FONT_REAL_HEIGHT*ysize+ysize-1,clb,RECT_BORDER0|DRAW_FILLED);
}

//-------------------------------------------------------------------

void draw_char_unscaled(coord x, coord y, const char ch, twoColors cl)
{
    int i, ii;

    unsigned int offset, size;
    unsigned char *sym = get_cdata(&offset, &size, ch);
    color fg = FG_COLOR(cl);
    color bg = BG_COLOR(cl);
    unsigned int fw = FONT_REAL_WIDTH;

    draw_pixel_simple_start(cl);

    // First draw blank lines at top
    for (i=0; i<offset; i++)
    {
        draw_hline_simple(x, y+i, fw, 0);
    }

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

        while (rep >= 0)
        {
            unsigned int px;
            unsigned int yt = y+(i);
            ii = 0;
            if (x&1)
            {
                draw_1pixel_simple(x+ii, yt, dsym>>(fw-1), 0);
                ii++;
            }
            for (; ii<fw; ii+=2)
            {
                px = (dsym & ((3<<(fw-2))>>ii))>>(fw-2-ii);
                draw_2pixels_simple(x+ii, yt, px, 0);
            }
            if (x&1)
            {
                draw_1pixel_simple(x+ii-1, yt, dsym&1, 0);
            }
            rep -= 0x80;
            i++;
        }

        j++;
    }

    // Last draw blank lines at bottom
    for (; i<FONT_REAL_HEIGHT; i++)
    {
        draw_hline_simple(x, y+i, fw, 0);
    }
}

// Draw CHDK OSD string at user defined position and scale
void draw_osd_string(OSD_pos pos, int xo, int yo, char *s, twoColors c, OSD_scale scale)
{
    if ((scale.x == 1) && (scale.y == 1))
    {
        draw_string(pos.x+xo, pos.y+yo, s, c);
    }
    else if ((scale.x == 0) || (scale.y == 0))
    {
        draw_string_scaled(pos.x+(xo>>1), pos.y+(yo>>1), s, c, scale.x, scale.y);
    }
    else
    {
        draw_string_scaled(pos.x+(xo*scale.x), pos.y+(yo*scale.y), s, c, scale.x, scale.y);
    }
}

//-------------------------------------------------------------------

extern unsigned char ply_colors[];

unsigned char *chdk_colors = ply_colors;

void set_palette()
{
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
