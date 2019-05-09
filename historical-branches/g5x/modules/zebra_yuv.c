#include "camera_info.h"
#include "conf.h"
#include "keyboard.h"
#include "modes.h"
#include "viewport.h"
#include "properties.h"
#include "gui.h"
#include "gui_draw.h"
#include "gui_lang.h"
#include "gui_osd.h"
#include "gui_mbox.h"
#include "gui_batt.h"
#include "gui_space.h"
#include "histogram.h"

#include "zebra.h"
#include "gui_grid.h"
#include "module_def.h"

//-------------------------------------------------------------------

// Notes on Zebra implementation.

// The zebra code examines the Y (luminance) values of the camera
// viewport to look for overexposed or underexposed pixels. The
// range of low and high values that determine over and under
// exposure is set with the 'zebra_over' and 'zebra_under' settings.

// There is an RGB mode controlled by zebra_multichannel that
// converts the viewport data from YUV to RGB and looks for exposure
// problems in each channel.

// Over and underexposed pixels are displayed on the bitmap screen
// using the zebra_color setting - foregound color is used of over
// exposure and background for under exposure.

// The code tries to allocate a memory buffer that is the same dimensions
// as the bitmap screen. The zebra display is written to this buffer
// and when done the buffer is copied into the camera bitmap screen memory.
// If the code can't allocate a memory buffer it writes the zebra data
// directly to the camera bitmap screen memory. Allocation of the memory
// buffer can also be overridden by setting CAM_ZEBRA_NOBUF in
// platform_camera.h. The code here uses the equivalent setting from
// camera_screen.zebra_nobuf for module platform indepedance.

// There are two variations of the basic zebra code to cater for
// different camera generations. Older cameras have a 360 byte wide
// bitmap screen (or 480 for wide screen cameras). This matches the
// CHDK virtual screen size so over and under exposed pixels are set
// in the bitmap image buffer directly.
// Newer cameras have a 720 (or 960) byte wide bitmap screen and the
// zebra code write two bytes (pixels) into the buffer for every
// over or underexposed pixel. Again the buffer is copied to the
// camera bitmap memory when done.

// Determining which code path is done with the CAM_USES_ASPECT_CORRECTION
// value in platform_camera.h (accessed via camera_screen.zebra_aspect_adjust).
// If CAM_USES_ASPECT_CORRECTION is not defined (or 0) the older code
// is used that assumes the bitmap screen is 360 bytes wide.
// Defining CAM_USES_ASPECT_CORRECTION as 1 will use the newer code.

// Another difference is that the old code path saves the top and bottom
// of the Canon OSD from the bitmap screen memory and overlays this on
// top of the zebra buffer. The new code version does not do this. The
// size of the strips saved is defined by ZFIX_TOP and ZFIX_BOTTOM.

// The final element comes from cameras that can capture images in
// different aspect ratios. Canon cameras all have a 4:3 ratio sensor
// but many can capture an image in different sizes - e.g. 1:1, 3:2 and 16:9.
// When these alternate ratios are selected the camera displays black
// bars at the top and bottom or left and right edges of the image in
// the viewport. The zebra code attempts to cater for this and not
// display underexposure indicators in these unused areas. The size
// and position of the black bars is also dependant on the aspect ratio
// of the camera LCD. Cameras with 4:3 LCD screens will show a 16:9 image
// with bars above and below. Cameras with 16:9 LCD screens will show
// a 4:3 image with bars to the left and right.

// For older cameras (that do not define CAM_USES_ASPECT_CORRECTION) the 
// aspect ratio is controlled by the CAM_HAS_VARIABLE_ASPECT value
// in platform_camera.h (camera_screen.has_variable_aspect). Defining
// this value tells the code that the camera has a 16:9 LCD but can
// also display a 4:3 image with black bars on the left and right.
// The value of the PROPCASE_ASPECT_RATIO property determines which
// image size if displayed. The code cannot handle other combinations
// of LCD size and image ratio.

// For newer cameras the code can handle any combination of LCD size
// and image aspect ratio provided the vid_get_viewport_height(), 
// vid_get_viewport_width(), vid_get_viewport_image_offset(),
// vid_get_viewport_row_offset(), vid_get_viewport_display_xoffset(),
// and vid_get_viewport_display_yoffset() functions have been correctly
// implemented for the camera.

// philmoz. Jan 2012.

//-------------------------------------------------------------------

// Height (in pixels) of half-shoot Canon OSD area of the screen buffer, for restore during 
// Zebra draw, to limit RAM usage of zebra. Only these border areas are stored in RAM.
// Only top and bottom are restored, not left & right.
#define ZFIX_TOP    29
#define ZFIX_BOTTOM 30

static unsigned char *img_buf, *scr_buf;
static unsigned char *cur_buf_top, *cur_buf_bot;
static int timer = 0;
static unsigned char *buf = NULL;
static int buffer_size;
static color cl_under, cl_over;

unsigned char clip8(signed short x){ if (x<0) x=0; else if (x>255) x=255; return x; }

typedef struct
{
    unsigned int yuv;
    unsigned int op;
} rawcolor_s;

rawcolor_s clr[8];

rawcolor_s rawcl_overunder[3];

// D6 version draws directly, no allocs
static void gui_osd_zebra_free()
{
    buf = NULL;
}

// prepare zebra resources, or free them
// returns 1 if zebra should be drawn
static int gui_osd_zebra_init(int show)
{
    color cls[] =
    {
        COLOR_TRANSPARENT,
        COLOR_BLUE,
        COLOR_GREEN,
        COLOR_CYAN,
        COLOR_RED,
        COLOR_MAGENTA,
        COLOR_YELLOW,
        COLOR_BLACK
    };

    cl_under = BG_COLOR(user_color(conf.zebra_color));
    cl_over = FG_COLOR(user_color(conf.zebra_color));

    if (show)
    {
        if (!buf)
        {
            timer = 0;
            scr_buf = vid_get_bitmap_fb();
            buf = scr_buf;
        }
        int f;
        for (f=0; f<8; f++)
        {
            clr[f].yuv = color_to_rawpx(cls[f], &(clr[f].op));
        }
        rawcl_overunder[1].yuv = color_to_rawpx(cl_under, &(rawcl_overunder[1].op));
        rawcl_overunder[0].yuv = color_to_rawpx(cl_over, &(rawcl_overunder[0].op));
        rawcl_overunder[2].yuv = color_to_rawpx(COLOR_TRANSPARENT, &(rawcl_overunder[2].op));
    }
    else
    {
        if (buf) // if zebra was previously on, restore
        {
            gui_set_need_restore();
        }
        gui_osd_zebra_free();
    }
    return (buf != NULL);
}

 

//-------------------------------------------------------------------
int draw_guard_pixel() {
    unsigned char* buffer1 = vid_get_bitmap_fb()+camera_screen.buffer_size/2;
    unsigned char* buffer2 = buffer1+camera_screen.buffer_size;
    int has_disappeared=0;

    if (*buffer1!=COLOR_GREEN) has_disappeared=1;
    if (*buffer2!=COLOR_GREEN) has_disappeared=2;
    *buffer1 = *buffer2 = COLOR_GREEN;
    return has_disappeared;
}

//-------------------------------------------------------------------
// neither OSD nor histogram can be drawn over zebra
// draw_set_draw_proc() is not respected by the current D6 drawing code anyway
static void gui_osd_draw_zebra_osd() {
    switch (conf.zebra_draw_osd) {
        case ZEBRA_DRAW_NONE:
            break;
        case ZEBRA_DRAW_OSD:
            if (conf.show_osd) {
                //draw_set_draw_proc(draw_dblpixel_raw);
               // gui_draw_osd_elements(0,1);
                //draw_set_draw_proc(NULL);
            }
            /* no break here */
        case ZEBRA_DRAW_HISTO:
        default:
            //draw_set_draw_proc(draw_dblpixel_raw);
            //libhisto->gui_osd_draw_histo(0);
            //draw_set_draw_proc(NULL);
            break;
    }
}

//-------------------------------------------------------------------
static void disp_zebra()
{
    // draw CHDK osd and histogram to buf[] (if enabled in config)

    gui_osd_draw_zebra_osd();
}

//-------------------------------------------------------------------
// CHDK uses a virtual screen size of 360 x 240 pixels (480x240 for wide screen models)
static int draw_zebra_no_aspect_adjust(int mrec, unsigned int f)
{
    unsigned int v, s, x, y, over, bitmap_byte;
    static int need_restore=0;
    int viewport_height;
    int viewport_width; 
    int viewport_byte_width;

    int viewport_xoffset;    // used when image size != viewport size
    int viewport_yoffset;    // used when image size != viewport size
    int zebra_drawn=0;
    int fd;
    int fd2;
    int ll;
    char bl[80];
    static int d_cnt =0;
    static int d_wrt =0;
    d_cnt++;

    viewport_height = vid_get_viewport_height();
    viewport_width = vid_get_viewport_width(); 
    viewport_byte_width = vid_get_viewport_byte_width();
    viewport_xoffset = vid_get_viewport_display_xoffset(); //columns
    viewport_yoffset = vid_get_viewport_display_yoffset();
    int  vo=vid_get_viewport_image_offset();

    // if not in no-zebra phase of blink mode zebra, draw zebra  
    if (f)
    {

        if (viewport_yoffset > 0)
        {
            // clear top & bottom areas of buffer if image height if smaller than viewport
        }
        int step_x, step_v;
        over = 255-conf.zebra_over;
    // start with all transparent, set the whole LCD causes too much blink
    //    set_transparent(0,buffer_size/2); 
        step_x = 2; //anything larger makes solid consist of alternating columns...

        for (y=0; y<viewport_height ; ++y)
        {
//e.g. on SX60hs LCD is 640x480
// 
// 16:9     f:8 vh:360 vw:640 vbw:1280 vxo:0 vyo:60
//1x1        f:8 vh:480 vw:480 vbw:1280 vxo:80 vyo:0
            //this can be made more efficient, but for now want clarity 
            for (x=0; x<viewport_width; x+=step_x)
            {
                register int y1,  uu, vv;
                v = y*(viewport_byte_width)  + x + x ; //v is the byte number in img-buf  0...480,480+320...960,
                bitmap_byte = (y + viewport_yoffset) * viewport_byte_width + 2*(x + viewport_xoffset);
                unsigned int ibuf = *(unsigned int*)(&img_buf[v&0xfffffffc]);
                vv =(signed char)((ibuf&0xff)-128);
                uu =(signed char)(((ibuf>>16)&0xff)-128);
                y1 = (unsigned char)((ibuf>>8)&0xff);

                int sel = 0;
                if (conf.zebra_multichannel)
                {
                    // for simplicity check only first pixel y1
                    sel = 0;
                    if (!((conf.zebra_mode == ZEBRA_MODE_ZEBRA_1 || conf.zebra_mode == ZEBRA_MODE_ZEBRA_2) && (y-x-timer)&f))
                    {
                        if (clip8(((y1<<12) +           vv*5743 + 2048)>>12)>over) sel  = 4; // R
                        if (clip8(((y1<<12) - uu*1411 - vv*2925 + 2048)>>12)>over) sel |= 2; // G
                        if (clip8(((y1<<12) + uu*7258           + 2048)>>12)>over) sel |= 1; // B
                    }
                    //set two pixels (4 bytes ) to color sel
                    if (sel > 0 )
                    {
                        draw_dblpixel_raw(bitmap_byte,  clr[sel].yuv, clr[sel].op);
                        zebra_drawn = 1;
                    }
                    else
                    {
                        draw_dblpixel_raw(bitmap_byte, 0x800080, 0);
                    }
                }
                else if (((conf.zebra_mode == ZEBRA_MODE_ZEBRA_1 || conf.zebra_mode == ZEBRA_MODE_ZEBRA_2) && (y-x-timer)&f))
                {
                    // set two pixels transparent 
                    draw_dblpixel_raw(bitmap_byte, 0x800080, 0); 
                }
                else
                {
                    // if y1 is over or under
                    // set two pixels to under color
                    sel = (y1>over)?0:(y1<conf.zebra_under)?1:2;
                     //set two pixels (4 bytes ) to either overexposed, underexposed or transparent color
                    draw_dblpixel_raw(bitmap_byte, rawcl_overunder[sel].yuv, rawcl_overunder[sel].op);
                    if (sel < 2) {
                        zebra_drawn = 1;
                    }
                }
            }
        }
        if (!zebra_drawn) f=0;
    }
    // if blink mode is in no-zebra phase OR if there was no over/underexposed pixels to draw zebra on
    if (!f)
    {
        // if zebra was drawn during previous call of this function
        if (need_restore)
        {
            if (conf.zebra_restore_screen || conf.zebra_restore_osd)
            {
                gui_set_need_restore();
            }
            else
            {
                // clear buf[] of zebra, only leave Canon OSD
                if (!mrec)
                {
                    // Not REC mode
                    set_transparent(0, buffer_size/2);  //blink
                }
                disp_zebra();
            }
            need_restore=0;
        }
        return !(conf.zebra_restore_screen && conf.zebra_restore_osd);
        // if zebra was drawn
    }
    else
    {
        disp_zebra();
        need_restore=1;
        return 1;
    }
    return 0;
}

//-------------------------------------------------------------------
int gui_osd_draw_zebra(int show)
{
    unsigned int f;

    if (!gui_osd_zebra_init(show))
        return 0;

    img_buf = vid_get_viewport_active_buffer();
    if (!img_buf) return 0;
    // img_buf += vid_get_viewport_image_offset(); //always zero anyway

    if (timer==0)
    {
        draw_guard_pixel();
        timer = 1;
        return 0;
    }

    if (timer==1)
    {
        int ready;
        static int n=0;
        if (!camera_info.state.mode_rec) ready=1;
        else get_property_case(camera_info.props.shooting, &ready, 4);
        n=draw_guard_pixel(); // will be 0 in PLAY mode, should be 1 or 2 in REC mode.
        if(!ready) return 0;

    }
    ++timer;

    switch (conf.zebra_mode)
    {
        case ZEBRA_MODE_ZEBRA_1:    f = 4;          break;
        case ZEBRA_MODE_ZEBRA_2:    f = 8;          break;
        case ZEBRA_MODE_SOLID:      f = 1;          break;
        case ZEBRA_MODE_BLINKED_1:  f = timer&1;    break;
        case ZEBRA_MODE_BLINKED_3:  f = timer&4;    break;
        case ZEBRA_MODE_BLINKED_2:  
        default:                    f = timer&2;    break;
    }

    return draw_zebra_no_aspect_adjust(camera_info.state.mode_rec,f);
}

// =========  MODULE INIT =================

/***************** BEGIN OF AUXILARY PART *********************
  ATTENTION: DO NOT REMOVE OR CHANGE SIGNATURES IN THIS SECTION
 **************************************************************/

//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{
    gui_osd_zebra_free();
    return 0;
}

int _module_can_unload()
{
    return conf.zebra_draw == 0;
}

/******************** Module Information structure ******************/

libzebra_sym _libzebra =
{
    {
         0, _module_unloader, _module_can_unload, 0, 0
    },

    gui_osd_draw_zebra
};

ModuleInfo _module_info =
{
    MODULEINFO_V1_MAGICNUM,
    sizeof(ModuleInfo),
    ZEBRA_VERSION,				// Module version

    ANY_CHDK_BRANCH, 0, OPT_ARCHITECTURE,			// Requirements of CHDK version
    ANY_PLATFORM_ALLOWED,		// Specify platform dependency

    (int32_t)"Zebra Overlay (dll)",
    MTYPE_EXTENSION,

    &_libzebra.base,

    CONF_VERSION,               // CONF version
    CAM_SCREEN_VERSION,         // CAM SCREEN version
    ANY_VERSION,                // CAM SENSOR version
    CAM_INFO_VERSION,           // CAM INFO version
};

/*************** END OF AUXILARY PART *******************/
