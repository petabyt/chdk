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

extern void draw_pixel_std(unsigned int offset, color cl);
extern void draw_char_scaled(coord x, coord y, const char ch, twoColors cl, int xsize, int ysize);
extern void draw_char_unscaled(coord x, coord y, const char ch, twoColors cl);

//-------------------------------------------------------------------
void    (*draw_pixel_proc)(unsigned int offset, color cl);
void    (*draw_pixel_proc_norm)(unsigned int offset, color cl);

unsigned int rotate_base;

//-------------------------------------------------------------------
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
#pragma pack(1)
// Format of header block for each character in the 'font_data' array
// This is immediately followed by '16 - top - bottom' bytes of character data.
typedef struct {
    unsigned char skips;    // Top and Bottom skip counts for blank rows (4 bits each - ((top << 4) | bottom))
} FontData;
#pragma pack()

unsigned char* get_cdata(unsigned int *offset, unsigned int *size, const char ch)
{
    FontData *f = (FontData*)get_current_font_data(ch);

    *offset = f->skips >> 4;            // # of blank lines at top
    *size = 16 - (f->skips & 0xF);      // last line of non-blank data
    if (*size == *offset)               // special case for blank char (top == 15 && bottom == 1)
        *offset += 1;

    return (unsigned char*)f + sizeof(FontData) - *offset;
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

// Draw single line string, with optional X and Y scaling
void draw_string_scaled(coord x, coord y, const char *s, twoColors cl, int xsize, int ysize)
{
    if ((xsize==0) || (ysize==0))
    {
        while (*s && (*s != '\n'))
        {
            draw_char_unscaled(x, y, *s, cl);
            s++;
            x+=FONT_REAL_WIDTH;
            if ((x>=camera_screen.width) && (*s))
            {
                draw_char_unscaled(x-FONT_REAL_WIDTH,y, '>', cl);
                break;
            }
        }
    }
    else
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
}

//-------------------------------------------------------------------
// Draw single line string at 'character' screen position (row, col)
// Pixel co-ordinate conversion --> x = col * FONT_WIDTH, y = row * FONT_HEIGHT
void draw_txt_string(coord col, coord row, const char *str, twoColors cl)
{
    draw_string(col*FONT_WIDTH, row*FONT_HEIGHT, str, cl);
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
    if (conf.rotate_osd)
    {
        if ((y == camera_screen.height-1) && ((x+len) >= camera_screen.width-1)) { x--; len--; }   // Skip guard pixel
    }
    else
    {
        if ((y == 0) && (x == 0)) { x++; len--; }   // Skip guard pixel
    }
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
    int x1, y1, x2, y2;
    while (1)
    {
        if (FONT_HEIGHT > 16)
        {
            x1 = cmds->x1<<1;
            y1 = cmds->y1<<1;
            x2 = cmds->x2<<1;
            y2 = cmds->y2<<1;
        }
        else
        {
            x1 = cmds->x1;
            y1 = cmds->y1;
            x2 = cmds->x2;
            y2 = cmds->y2;
        }
        color cf = CHDK_2_CANON_COLOR(cmds->cf);       // Convert color indexes to actual colors
        color cb = CHDK_2_CANON_COLOR(cmds->cb);
        switch (cmds->action)
        {
        default:
        case IA_END:
            return;
        case IA_HLINE:
            draw_hline(x+x1, y+y1, x2, cb);
            break;
        case IA_VLINE:
            draw_vline(x+x1, y+y1, y2, cb);
            break;
        case IA_LINE:
            draw_line(x+x1, y+y1, x+x2, y+y2, cb);
            break;
        case IA_RECT:
            draw_rectangle(x+x1, y+y1, x+x2, y+y2, MAKE_COLOR(cb,cf), RECT_BORDER1);
            break;
        case IA_FILLED_RECT:
            draw_rectangle(x+x1, y+y1, x+x2, y+y2, MAKE_COLOR(cb,cf), RECT_BORDER1|DRAW_FILLED);
            break;
        case IA_ROUND_RECT:
            draw_rectangle(x+x1, y+y1, x+x2, y+y2, MAKE_COLOR(cb,cf), RECT_BORDER1|RECT_ROUND_CORNERS);
            break;
        case IA_FILLED_ROUND_RECT:
            draw_rectangle(x+x1, y+y1, x+x2, y+y2, MAKE_COLOR(cb,cf), RECT_BORDER1|DRAW_FILLED|RECT_ROUND_CORNERS);
            break;
        }
        cmds++;
    }
}

//-------------------------------------------------------------------
