#include "platform.h"
#include "stdlib.h"
#include "touchscreen.h"
#include "conf.h"
#include "font.h"
#include "lang.h"
#include "gui_draw.h"

#define GET_FONT_COMPRESSION_MODE 1
#include "../lib/font/font_8x16_uni_packed.h"
#undef  GET_FONT_COMPRESSION_MODE

//-------------------------------------------------------------------
void            (*draw_pixel_proc)(unsigned int offset, color cl);
void            (*draw_pixel_proc_norm)(unsigned int offset, color cl);

#ifdef DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY
extern char* bitmap_buffer[];
extern int active_bitmap_buffer;
#else
static char* frame_buffer[2];
#endif
//-------------------------------------------------------------------

static void draw_pixel_std(unsigned int offset, color cl)
{
#ifndef THUMB_FW
    // drawing on 8bpp paletted overlay
#ifdef DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY
	bitmap_buffer[active_bitmap_buffer][offset] = cl;
#else
	frame_buffer[0][offset] = frame_buffer[1][offset] = cl;
#endif
#else
    // DIGIC 6, drawing on 16bpp YUV overlay

#ifndef DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY
#error DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY is required for DIGIC 6 ports
#endif

    register int cli = cl ^ 0xffffffff;
    extern volatile char *opacity_buffer[];
    //extern int active_bitmap_buffer;
    static unsigned int prev_offs = 0xffffffff;
    register unsigned int offs2 = (offset>>1)<<2;
    if (cli != 0xffffffff)
    {
        if (prev_offs != offs2)
        {
            bitmap_buffer[active_bitmap_buffer][offs2+2] = 0x80-((((int)cli)<<5)&0xe0);    // U?
            bitmap_buffer[active_bitmap_buffer][offs2+0] = 0x80-((((int)cli)<<2)&0xe0);    // V?
            prev_offs = offs2;
        }
        if (offset&1) // x is odd
        {
            bitmap_buffer[active_bitmap_buffer][offs2+3] = (cli&0xc0);    // Y
        }
        else // x is even
        {
            bitmap_buffer[active_bitmap_buffer][offs2+1] = (cli&0xc0);    // Y
        }
        // simple transparency
        opacity_buffer[active_bitmap_buffer][offset] = (cli&16)?0x60:0xff;
    }
    else // color==0, black, fully transparent
    {
        if (prev_offs != offs2)
        {
            bitmap_buffer[active_bitmap_buffer][offs2+2] = 0x80;    // U?
            bitmap_buffer[active_bitmap_buffer][offs2+0] = 0x80;    // V?
            prev_offs = offs2;
        }
        if (offset&1) // x is odd
        {
            bitmap_buffer[active_bitmap_buffer][offs2+3] = 0;    // Y
        }
        else // x is even
        {
            bitmap_buffer[active_bitmap_buffer][offs2+1] = 0;    // Y
        }
        // fully transparent
        opacity_buffer[active_bitmap_buffer][offset] = 0;
    }
#endif
}

//-------------------------------------------------------------------
unsigned int rotate_base;

void draw_pixel_proc_rotated(unsigned int offset, color cl)
{
    draw_pixel_proc_norm(rotate_base - offset, cl);
}

void draw_set_draw_proc(void (*pixel_proc)(unsigned int offset, color cl))
{
    draw_pixel_proc_norm = (pixel_proc)?pixel_proc:draw_pixel_std;
    if (conf.rotate_osd)
    {
        rotate_base = (camera_screen.height - 1) * camera_screen.buffer_width + ASPECT_XCORRECTION(camera_screen.width) - 1;
        draw_pixel_proc = draw_pixel_proc_rotated;
    }
    else
    {
        draw_pixel_proc = draw_pixel_proc_norm;
    }
}

void update_draw_proc()
{
    draw_set_draw_proc(draw_pixel_proc_norm);
}

//-------------------------------------------------------------------
#ifndef THUMB_FW

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

#else // DIGIC 6

extern volatile char *opacity_buffer[];

void draw_set_guard()
{
    opacity_buffer[active_bitmap_buffer][0] = 0x42;
}

int draw_test_guard()
{
    if (opacity_buffer[active_bitmap_buffer][0] != 0x42) return 0;
    return 1;
}

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

// Restore CANON_OSD
//-------------------------------------------------------------------
void draw_restore()
{
    vid_bitmap_refresh();

    draw_set_guard();
#ifdef CAM_TOUCHSCREEN_UI
    redraw_buttons = 1;
#endif
}

//-------------------------------------------------------------------
void draw_pixel(coord x, coord y, color cl)
{
    // Make sure pixel is on screen. Skip top left pixel if screen erase detection is on to avoid triggering the detector.
    if ((x < 0) || (y < 0) || (x >= camera_screen.width) || (y >= camera_screen.height) || ((x == 0) && (y == 0))) return;
    else
    {
        register unsigned int offset = y * camera_screen.buffer_width + ASPECT_XCORRECTION(x);
        draw_pixel_proc(offset,   cl);
#if CAM_USES_ASPECT_CORRECTION
        draw_pixel_proc(offset+1, cl);  // Draw second pixel if screen scaling is needed
#endif
   }
}

void draw_pixel_unrotated(coord x, coord y, color cl)
{
    // Make sure pixel is on screen. Skip top left pixel if screen erase detection is on to avoid triggering the detector.
    if ((x < 0) || (y < 0) || (x >= camera_screen.width) || (y >= camera_screen.height) || ((x == 0) && (y == 0))) return;
    else
    {
        register unsigned int offset = y * camera_screen.buffer_width + ASPECT_XCORRECTION(x);
        draw_pixel_proc_norm(offset,   cl);
#if CAM_USES_ASPECT_CORRECTION
        draw_pixel_proc_norm(offset+1, cl);  // Draw second pixel if screen scaling is needed
#endif
   }
}

//-------------------------------------------------------------------
color draw_get_pixel(coord x, coord y)
{
#ifndef THUMB_FW
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
#else
    // DIGIC 6 not supported
    return 0;
#endif
}

color draw_get_pixel_unrotated(coord x, coord y)
{
#ifndef THUMB_FW
    if ((x < 0) || (y < 0) || (x >= camera_screen.width) || (y >= camera_screen.height)) return 0;
#ifdef DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY
    return bitmap_buffer[0][y * camera_screen.buffer_width + ASPECT_XCORRECTION(x)];
#else
    return frame_buffer[0][y * camera_screen.buffer_width + ASPECT_XCORRECTION(x)];
#endif
#else
    // DIGIC 6 not supported
    return 0;
#endif
}

//-------------------------------------------------------------------
#define swap(v1, v2)   {v1^=v2; v2^=v1; v1^=v2;}
//-------------------------------------------------------------------
void draw_line(coord x1, coord y1, coord x2, coord y2, color cl)
{
     unsigned char steep = abs(y2 - y1) > abs(x2 - x1);
     if (steep)
     {
         swap(x1, y1);
         swap(x2, y2);
     }
     if (x1 > x2)
     {
         swap(x1, x2);
         swap(y1, y2);
     }
     int deltax = x2 - x1;
     int deltay = abs(y2 - y1);
     int error = 0;
     int y = y1;
     int ystep = (y1 < y2)?1:-1;
     int x;
     for (x=x1; x<=x2; ++x)
     {
         if (steep) draw_pixel(y, x, cl);
         else draw_pixel(x, y, cl);
         error += deltay;
         if ((error<<1) >= deltax)
         {
             y += ystep;
             error -= deltax;
         }
     }
}

//-------------------------------------------------------------------
void draw_hline(coord x, coord y, int len, color cl)
{
    if ((y < 0) || (x >= camera_screen.width) || (y >= camera_screen.height)) return;
    if (x < 0) { len += x; x = 0; }
    if ((x + len) > camera_screen.width) len = camera_screen.width - x;
    if ((x == 0) && (y == 0)) { x++; len--; }   // Skip guard pixel
    register unsigned int offset = y * camera_screen.buffer_width + ASPECT_XCORRECTION(x);
    len = ASPECT_XCORRECTION(len);      // Scale the line length if needed
    for (; len>0; len--, offset++)
        draw_pixel_proc(offset, cl);
}

void draw_vline(coord x, coord y, int len, color cl)
{
    if ((x < 0) || (x >= camera_screen.width) || (y >= camera_screen.height)) return;
    if (y < 0) { len += y; y = 0; }
    if ((y + len) > camera_screen.height) len = camera_screen.height - y;
    for (; len>0; len--, y++)
        draw_pixel(x, y, cl);
}

//-------------------------------------------------------------------
// Generic rectangle
// 'flags' defines type - filled, round corners, shadow and border thickness
void draw_rectangle(coord x1, coord y1, coord x2, coord y2, twoColors cl, int flags)
{
    // Normalise values
    if (x1 > x2)
        swap(x1, x2);
    if (y1 > y2)
        swap(y1, y2);

    // Check if completely off screen
    if ((x2 < 0) || (y2 < 0) || (x1 >= camera_screen.width) || (y1 >= camera_screen.height))
        return;

    int round = (flags & RECT_ROUND_CORNERS) ? 1 : 0;
    int thickness;
    int i;

    // Shadow (do this first, as edge draw shrinks rectangle for fill)
    if (flags & RECT_SHADOW_MASK)
    {
        thickness = ((flags & RECT_SHADOW_MASK) >> 4);
        for (i=1; i<=thickness; i++)
        {
            draw_vline(x2+i, y1+1, y2 - y1, COLOR_BLACK);
            draw_hline(x1+1, y2+i, x2 - x1 + thickness, COLOR_BLACK);
        }
    }

    // Edge
    thickness = flags & RECT_BORDER_MASK;
    for (i=0; i<thickness; i++)
    {
        // Clipping done in draw_hline and draw_vline
        draw_vline(x1, y1 + round * 2, y2 - y1 - round * 4 + 1, FG_COLOR(cl));
        draw_vline(x2, y1 + round * 2, y2 - y1 - round * 4 + 1, FG_COLOR(cl));
        draw_hline(x1 + 1 + round, y1, x2 - x1 - round * 2 - 1, FG_COLOR(cl));
        draw_hline(x1 + 1 + round, y2, x2 - x1 - round * 2 - 1, FG_COLOR(cl));

        x1++; x2--;
        y1++; y2--;

        round = 0;
    }

    // Fill
    if (flags & DRAW_FILLED)
    {
        // Clip values
        if (x1 < 0) x1 = 0;
        if (y1 < 0) y1 = 0;
        if (x2 >= camera_screen.width)  x2 = camera_screen.width - 1;
        if (y2 >= camera_screen.height) y2 = camera_screen.height - 1;

        coord y;
        for (y = y1; y <= y2; ++y)
            draw_hline(x1, y, x2 - x1 + 1, BG_COLOR(cl));
    }
}

//-------------------------------------------------------------------
#pragma pack(1)
// Format of header block for each character in the 'font_data' array
// This is immediately followed by '16 - top - bottom' bytes of character data.
typedef struct {
    unsigned char skips;    // Top and Bottom skip counts for blank rows (4 bits each - ((top << 4) | bottom))
} FontData;
#pragma pack()

static unsigned char* get_cdata(unsigned int *offset, unsigned int *size, const char ch)
{
    FontData *f = (FontData*)get_current_font_data(ch);

    *offset = f->skips >> 4;            // # of blank lines at top
    *size = 16 - (f->skips & 0xF);      // last line of non-blank data
    if (*size == *offset)               // special case for blank char (top == 15 && bottom == 1)
        *offset++;

    return (unsigned char*)f + sizeof(FontData) - *offset;
}

void draw_char(coord x, coord y, const char ch, twoColors cl)
{
    int i, ii;

    unsigned int offset, size;
    unsigned char *sym = get_cdata(&offset, &size, ch);

    // First draw blank lines at top
    for (i=0; i<offset; i++)
        draw_hline(x, y+i, FONT_WIDTH, BG_COLOR(cl));

    // Now draw character data

#ifdef BUILTIN_FONT_RLE_COMPRESSED
    int j;
    for (j=i; i<size;)
    {
        unsigned int dsym;
        int rep;
        dsym = fontdata_lookup[sym[j] & 0x7f];
        rep = sym[j] & 0x80;
#if 0 // size optimized (-16 bytes...)
        while (rep >= 0)
        {
            for (ii=0; ii<FONT_WIDTH; ii++)
            {
                draw_pixel(x+ii, y+i, (dsym & (0x80>>ii))? FG_COLOR(cl) : BG_COLOR(cl));
            }
            rep -= 0x80;
            i++;
        }
#else // little faster
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
#endif
        j++;
    }
#else
    for (; i<size; i++)
    {
        for (ii=0; ii<FONT_WIDTH; ii++)
        {
            draw_pixel(x+ii, y+i, (sym[i] & (0x80>>ii))? FG_COLOR(cl) : BG_COLOR(cl));
        }
    }
#endif // BUILTIN_FONT_RLE_COMPRESSED

    // Last draw blank lines at bottom
    for (; i<FONT_HEIGHT; i++)
        draw_hline(x, y+i, FONT_WIDTH, BG_COLOR(cl));
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
#ifdef BUILTIN_FONT_RLE_COMPRESSED
    int j;
    for (j=i=offset; i<size;)
    {
        unsigned int dsym;
        int rep;
        unsigned int last;
        int len;
        dsym = fontdata_lookup[sym[j] & 0x7f];
        rep = sym[j] & 0x80;
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
#else
    for (i=offset; i<size; i++)
    {
        unsigned int last = sym[i] & 0x80;
        int len = 1;
        for (ii=1; ii<FONT_WIDTH; ii++)
        {
            if (((sym[i] << ii) & 0x80) != last)
            {
                draw_rectangle(x+(ii-len)*xsize,y+i*ysize,x+ii*xsize-1,y+i*ysize+ysize-1,(last)?clf:clb,RECT_BORDER0|DRAW_FILLED);
                last = (sym[i] << ii) & 0x80;
                len = 1;
            }
            else
            {
                len++;
            }
        }
        draw_rectangle(x+(ii-len)*xsize,y+i*ysize,x+ii*xsize-1,y+i*ysize+ysize-1,(last)?clf:clb,RECT_BORDER0|DRAW_FILLED);
    }
#endif // BUILTIN_FONT_RLE_COMPRESSED

    // Last draw blank lines at bottom
    if (i < FONT_HEIGHT)
        draw_rectangle(x,y+i*ysize,x+FONT_WIDTH*xsize-1,y+FONT_HEIGHT*ysize+ysize-1,clb,RECT_BORDER0|DRAW_FILLED);
}

//-------------------------------------------------------------------
// String & text functions

// Draw a single line string up to a maximum pixel width
int draw_string_clipped(coord x, coord y, const char *s, twoColors cl, int max_width)
{
    while (*s && (*s != '\n') && (max_width >= FONT_WIDTH))
    {
	    draw_char(x, y, *s, cl);
	    s++;
        max_width -= FONT_WIDTH;
	    x += FONT_WIDTH;
	    if ((x>=camera_screen.width) && (*s))
        {
	        draw_char(x-FONT_WIDTH,y, '>', cl);
	        break;
	    }
    }
    return x;
}

// Draw a single line string
int draw_string(coord x, coord y, const char *s, twoColors cl)
{
    return draw_string_clipped(x, y, s, cl, camera_screen.width);
}

// Draw a single line string:
//      - xo = left offset to start text (only applies to left justified text)
//      - max_width = maximum pixel width to use (staring from x)
//      - justification = left, center or right justified, also controls if unused area to be filled with background color
// Returns x position of first character drawn
int draw_string_justified(coord x, coord y, const char *s, twoColors cl, int xo, int max_width, int justification)
{
    // Get length in pixels
    const char *e = strchr(s, '\n');
    int l;
    if (e)
        l = (e - s) * FONT_WIDTH;
    else
        l = strlen(s) * FONT_WIDTH;
    if (l > max_width) l = max_width;

    // Calculate justification offset
    switch (justification & 0xF)
    {
    case TEXT_RIGHT:
        xo = (max_width - l);
        break;
    case TEXT_CENTER:
        xo = ((max_width - l) >> 1);
        break;
    }

    // Fill left side
    if ((justification & TEXT_FILL) && (xo > 0))
        draw_rectangle(x, y, x+xo-1, y+FONT_HEIGHT-1, cl, RECT_BORDER0|DRAW_FILLED);

    // Draw string (get length drawn in pixels)
    l = draw_string_clipped(x+xo, y, s, cl, max_width - xo) - x;

    // Fill right side
    if ((justification & TEXT_FILL) && (l < max_width))
        draw_rectangle(x+l, y, x+max_width-1, y+FONT_HEIGHT-1, cl, RECT_BORDER0|DRAW_FILLED);

    // Return start of first character
    return x+xo;
}

// Calculate the max line length and number of lines of a multi line string
// Lines are separated by newline '\n' characters
// Returns:
//      - max line length (return value)
//      - number of lines (in *max_lines)
int text_dimensions(const char *s, int width, int max_chars, int *max_lines)
{
    int l = 0, n;
    while (s && *s && (l < *max_lines))
    {
        const char *e = strchr(s, '\n');
        if (e)
        {
            n = e - s;
            e++;
        }
        else
        {
            n = strlen(s);
        }

        if (n > width) width = n;

        s = e;
        l++;
    }
    *max_lines = l;
    if (width > max_chars) width = max_chars;
    return width;
}

// Draw multi-line text string:
//      - max_chars = max # of chars to draw
//      - max_lines = max # of lines to draw
//      - justification = left, center or right justified, with optional fill of unused space
// Returns x position of first character on last line
int draw_text_justified(coord x, coord y, const char *s, twoColors cl, int max_chars, int max_lines, int justification)
{
    int rx = 0;
    while (s && *s && (max_lines > 0))
    {
        const char *e = strchr(s, '\n');
        if (e) e++;

        rx = draw_string_justified(x, y, s, cl, 0, max_chars*FONT_WIDTH, justification);

        s = e;
        y += FONT_HEIGHT;
        max_lines--;
    }
    return rx;
}

// Draw single line string, with optiona X and Y scaling
void draw_string_scaled(coord x, coord y, const char *s, twoColors cl, int xsize, int ysize)
{
    while (*s && (*s != '\n'))
    {
	    draw_char_scaled(x, y, *s, cl, xsize, ysize);
	    s++;
	    x+=FONT_WIDTH*xsize;
	    if ((x>=camera_screen.width) && (*s))
        {
	        draw_char_scaled(x-FONT_WIDTH*xsize,y, '>', cl, xsize, ysize);
	        break;
	    }
    }
}

// Draw CHDK OSD string at user defined position and scale
void draw_osd_string(OSD_pos pos, int xo, int yo, char *s, twoColors c, OSD_scale scale)
{
    if ((scale.x == 0) || (scale.y == 0) || ((scale.x == 1) && (scale.y == 1)))
        draw_string(pos.x+xo, pos.y+yo, s, c);
    else
        draw_string_scaled(pos.x+(xo*scale.x), pos.y+(yo*scale.y), s, c, scale.x, scale.y);
}

//-------------------------------------------------------------------
// Draw single line string at 'character' screen position (row, col)
// Pixel co-ordinate conversion --> x = col * FONT_WIDTH, y = row * FONT_HEIGHT
void draw_txt_string(coord col, coord row, const char *str, twoColors cl)
{
    draw_string(col*FONT_WIDTH, row*FONT_HEIGHT, str, cl);
}

//-------------------------------------------------------------------
// *** Not used ***
//void draw_circle(coord x, coord y, const unsigned int r, color cl)
//{
//    int dx = 0;
//    int dy = r;
//    int p=(3-(r<<1));
//
//    do {
//        draw_pixel((x+dx),(y+dy),cl);
//        draw_pixel((x+dy),(y+dx),cl);
//        draw_pixel((x+dy),(y-dx),cl);
//        draw_pixel((x+dx),(y-dy),cl);
//        draw_pixel((x-dx),(y-dy),cl);
//        draw_pixel((x-dy),(y-dx),cl);
//        draw_pixel((x-dy),(y+dx),cl);
//        draw_pixel((x-dx),(y+dy),cl);
//
//        ++dx;
//
//        if (p<0)
//            p += ((dx<<2)+6);
//        else {
//            --dy;
//            p += (((dx-dy)<<2)+10);
//        }
//    } while (dx<=dy);
//}

//-------------------------------------------------------------------
void draw_ellipse(coord CX, coord CY, unsigned int XRadius, unsigned int YRadius, color cl, int flags)
{
    // Bresenham fast ellipse algorithm - http://homepage.smc.edu/kennedy_john/BELIPSE.PDF
    int X, Y;
    int XChange, YChange;
    int EllipseError;
    int TwoASquare, TwoBSquare;
    int StoppingX, StoppingY;
    TwoASquare = 2*XRadius*XRadius;
    TwoBSquare = 2*YRadius*YRadius;
    X = XRadius;
    Y = 0;
    XChange = YRadius*YRadius*(1-2*XRadius);
    YChange = XRadius*XRadius;
    EllipseError = 0;
    StoppingX = TwoBSquare*XRadius;
    StoppingY = 0;
    while ( StoppingX >= StoppingY ) 
    {
        if (flags & DRAW_FILLED)
        {
            draw_hline(CX-X,CY-Y,X*2+1,cl);
            draw_hline(CX-X,CY+Y,X*2+1,cl);
        }
        else
        {
            draw_pixel(CX-X,CY-Y,cl);
            draw_pixel(CX-X,CY+Y,cl);
            draw_pixel(CX+X,CY-Y,cl);
            draw_pixel(CX+X,CY+Y,cl);
        }
        Y++;
        StoppingY += TwoASquare;
        EllipseError += YChange;
        YChange += TwoASquare;
        if ((2*EllipseError + XChange) > 0 )
        {
            X--;
            StoppingX -= TwoBSquare;
            EllipseError += XChange;
            XChange += TwoBSquare;
        }
    }
    X = 0;
    Y = YRadius;
    XChange = YRadius*YRadius;
    YChange = XRadius*XRadius*(1-2*YRadius);
    EllipseError = 0;
    StoppingX = 0;
    StoppingY = TwoASquare*YRadius;
    int lastY = Y + 1;
    while ( StoppingX <= StoppingY )
    {
        if (flags & DRAW_FILLED)
        {
            // Only draw lines if Y has changed
            if (lastY != Y)
            {
                draw_hline(CX-X,CY-Y,X*2+1,cl);
                draw_hline(CX-X,CY+Y,X*2+1,cl);
                lastY = Y;
            }
        }
        else
        {
            draw_pixel(CX-X,CY-Y,cl);
            draw_pixel(CX-X,CY+Y,cl);
            draw_pixel(CX+X,CY-Y,cl);
            draw_pixel(CX+X,CY+Y,cl);
        }
        X++;
        StoppingX += TwoBSquare;
        EllipseError += XChange;
        XChange += TwoBSquare;
        if ((2*EllipseError + YChange) > 0 )
        {
            Y--;
            StoppingY -= TwoASquare;
            EllipseError += YChange;
            YChange += TwoASquare;
        }
    }
}

//-------------------------------------------------------------------
// Draw a button
void draw_button(int x, int y, int w, int str_id, int active)
{
    twoColors cl = MAKE_COLOR((active) ? COLOR_RED : COLOR_BLACK, COLOR_WHITE);
    w = w * FONT_WIDTH;

    draw_rectangle(x-2, y-2, x+w+2, y+FONT_HEIGHT+2, cl, RECT_BORDER1|DRAW_FILLED|RECT_SHADOW1);     // main box
    draw_string(x+((w-(strlen(lang_str(str_id))*FONT_WIDTH))>>1), y, lang_str(str_id), cl);
}

//-------------------------------------------------------------------
// Draw an OSD icon from an array of actions
void draw_icon_cmds(coord x, coord y, icon_cmd *cmds)
{
    while (1)
    {
        color cf = chdk_colors[cmds->cf];       // Convert color indexes to actual colors
        color cb = chdk_colors[cmds->cb];
        switch (cmds->action)
        {
        default:
        case IA_END:
            return;
        case IA_HLINE:
            draw_hline(x+cmds->x1, y+cmds->y1, cmds->x2, cb);
            break;
        case IA_VLINE:
            draw_vline(x+cmds->x1, y+cmds->y1, cmds->y2, cb);
            break;
        case IA_LINE:
            draw_line(x+cmds->x1, y+cmds->y1, x+cmds->x2, y+cmds->y2, cb);
            break;
        case IA_RECT:
            draw_rectangle(x+cmds->x1, y+cmds->y1, x+cmds->x2, y+cmds->y2, MAKE_COLOR(cb,cf), RECT_BORDER1);
            break;
        case IA_FILLED_RECT:
            draw_rectangle(x+cmds->x1, y+cmds->y1, x+cmds->x2, y+cmds->y2, MAKE_COLOR(cb,cf), RECT_BORDER1|DRAW_FILLED);
            break;
        case IA_ROUND_RECT:
            draw_rectangle(x+cmds->x1, y+cmds->y1, x+cmds->x2, y+cmds->y2, MAKE_COLOR(cb,cf), RECT_BORDER1|RECT_ROUND_CORNERS);
            break;
        case IA_FILLED_ROUND_RECT:
            draw_rectangle(x+cmds->x1, y+cmds->y1, x+cmds->x2, y+cmds->y2, MAKE_COLOR(cb,cf), RECT_BORDER1|DRAW_FILLED|RECT_ROUND_CORNERS);
            break;
        }
        cmds++;
    }
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
