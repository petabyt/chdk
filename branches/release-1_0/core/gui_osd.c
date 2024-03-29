#include "camera.h"
#include "stdlib.h"
#include "keyboard.h"
#include "platform.h"
#include "histogram.h"
#include "core.h"
#include "lang.h"
#include "conf.h"
#include "gui.h"
#include "gui_draw.h"
#include "gui_lang.h"
#include "gui_batt.h"
#include "gui_usb.h"
#include "gui_space.h"
#include "gui_grid.h"
#include "gui_osd.h"
#ifdef OPT_EDGEOVERLAY
    #include "edgeoverlay.h"
#endif

//-------------------------------------------------------------------
typedef struct {
    int     title;
    OSD_pos *pos;
    OSD_pos size;
} OSD_elem;

static OSD_elem osd[]={
    {LANG_OSD_LAYOUT_EDITOR_HISTO,      &conf.histo_pos,        {HISTO_WIDTH+2, HISTO_HEIGHT}   },
    {LANG_OSD_LAYOUT_EDITOR_DOF_CALC,   &conf.dof_pos,          {23*FONT_WIDTH, 2*FONT_HEIGHT}  },
    {LANG_OSD_LAYOUT_EDITOR_STATES,     &conf.mode_state_pos,   {12*FONT_WIDTH, 4*FONT_HEIGHT}   },
    {LANG_OSD_LAYOUT_EDITOR_RAW,     &conf.mode_raw_pos,   {7*FONT_WIDTH, FONT_HEIGHT}   },
    {LANG_OSD_LAYOUT_EDITOR_MISC,       &conf.values_pos,       {9*FONT_WIDTH, 9*FONT_HEIGHT}   },
    {LANG_OSD_LAYOUT_EDITOR_BAT_ICON,   &conf.batt_icon_pos,    {31, 12}                        },
    {LANG_OSD_LAYOUT_EDITOR_SPACE_ICON,   &conf.space_icon_pos,    {31, 19}                        },
    {LANG_OSD_LAYOUT_EDITOR_SPACE_ICON,   &conf.space_ver_pos,    {3, 50}                        },
    {LANG_OSD_LAYOUT_EDITOR_SPACE_ICON,   &conf.space_hor_pos,    {50, 3}                        },
    {LANG_OSD_LAYOUT_EDITOR_BAT_TEXT,   &conf.batt_txt_pos,     {5*FONT_WIDTH, FONT_HEIGHT}     },
    {LANG_OSD_LAYOUT_EDITOR_SPACE_TEXT,   &conf.space_txt_pos,     {5*FONT_WIDTH, FONT_HEIGHT}     },
    {LANG_OSD_LAYOUT_EDITOR_CLOCK,      &conf.clock_pos,        {5*FONT_WIDTH, FONT_HEIGHT}     },
    {LANG_OSD_LAYOUT_EDITOR_TEMP,      &conf.temp_pos,        {9*FONT_WIDTH, FONT_HEIGHT}     },
    {LANG_OSD_LAYOUT_EDITOR_VIDEO,     &conf.mode_video_pos,   {9*FONT_WIDTH, 4*FONT_HEIGHT}   },
    {LANG_OSD_LAYOUT_EDITOR_EV,     &conf.mode_ev_pos,   {12*FONT_WIDTH, FONT_HEIGHT}   },
#if CAM_EV_IN_VIDEO
    {LANG_OSD_LAYOUT_EDITOR_EV_VIDEO,         &conf.ev_video_pos,     {70,24}},
#endif
    {LANG_OSD_LAYOUT_EDITOR_USB_INFO,   &conf.usb_info_pos,    {31, 14}                        },
    {0}
};
static int osd_to_draw;
static int curr_item;
static char osd_buf[64];
static char osd_buf2[10];
static char osd_buf3[10];
static char osd_buf4[10];

static int step;


#if defined (CAM_ZEBRA_NOBUF) && !defined(CAM_ZEBRA_ASPECT_ADJUST)
// old sx20 #ifdefs were roughly equivalent of both
    #error "defined (CAM_ZEBRA_NOBUF) && !defined(CAM_ZEBRA_ASPECT_ADJUST). Remove this if you've verified it will work!"
#endif

#ifdef CAM_ZEBRA_ASPECT_ADJUST
// TODO should just not save anything at all instead of 1 px. Also, this shouldn't be tied to aspect correct
    #define ZEBRA_CANONOSD_BORDER_RESTORE   1
    #define ZFIX_TOP    1
    #define ZFIX_BOTTOM 1
#else
// Width (in pixels) of half-shoot Canon OSD area of the screen buffer, for restore during
// Zebra draw, to limit RAM usage of zebra. Only these border areas are stored in RAM.
// Only top and bottom are restored, not left&right.
    #define ZEBRA_CANONOSD_BORDER_RESTORE   1
    #define ZFIX_TOP    29
    #define ZFIX_BOTTOM 30
#endif

static unsigned char *img_buf, *scr_buf;
#if ZEBRA_CANONOSD_BORDER_RESTORE
static unsigned char *cur_buf_top, *cur_buf_bot;
#else
static unsigned char *cur_buf;
#endif
static int timer = 0;
static unsigned char *buf = NULL;

#ifdef CAM_ZEBRA_ASPECT_ADJUST
static int buffer_size;
#endif

DOF_TYPE dof_values;
static EXPO_TYPE expo;

#define OSD_STATE    0
#define OSD_MISC     1

unsigned char clip8(signed short x){ if (x<0) x=0; else if (x>255) x=255; return x; }

//-------------------------------------------------------------------
void gui_osd_init() {
    osd_to_draw = 1;
    curr_item = 0;
    step = 10;
    draw_restore();
}

//-------------------------------------------------------------------
void gui_osd_draw() {
    if (osd_to_draw) {
        int i;
        draw_restore();
        gui_osd_draw_histo();
        gui_osd_draw_dof();
        gui_batt_draw_osd();
        gui_space_draw_osd();
        gui_osd_draw_state();
        gui_osd_draw_raw_info();
        gui_osd_draw_values();
        gui_osd_draw_clock(0,0,0);
        gui_osd_draw_temp();
      #if CAM_EV_IN_VIDEO
        gui_osd_draw_ev_video(1);
      #endif
        gui_usb_draw_osd();
        for (i=1; i<=2; ++i) {
            draw_rect((osd[curr_item].pos->x>=i)?osd[curr_item].pos->x-i:0, (osd[curr_item].pos->y>=i)?osd[curr_item].pos->y-i:0,
                      osd[curr_item].pos->x+osd[curr_item].size.x+i-1, osd[curr_item].pos->y+osd[curr_item].size.y+i-1,
                      COLOR_GREEN);
        }
        sprintf(osd_buf, " %s:  x:%d y:%d s:%d ", lang_str(osd[curr_item].title), osd[curr_item].pos->x, osd[curr_item].pos->y, step);
        draw_string(0, (osd[curr_item].pos->x<strlen(osd_buf)*FONT_WIDTH+4 && osd[curr_item].pos->y<FONT_HEIGHT+4)?screen_height-FONT_HEIGHT:0,
                    osd_buf, MAKE_COLOR(COLOR_RED, COLOR_WHITE));
        osd_to_draw = 0;
    }
}

//-------------------------------------------------------------------
void gui_osd_kbd_process() {
    switch (kbd_get_autoclicked_key()) {
    case KEY_LEFT:
        if (osd[curr_item].pos->x > 0) {
            osd[curr_item].pos->x-=(osd[curr_item].pos->x>=step)?step:osd[curr_item].pos->x;
            osd_to_draw = 1;
        }
        break;
    case KEY_RIGHT:
        if (osd[curr_item].pos->x < screen_width-osd[curr_item].size.x) {
            osd[curr_item].pos->x+=(screen_width-osd[curr_item].size.x-osd[curr_item].pos->x>step)?step:screen_width-osd[curr_item].size.x-osd[curr_item].pos->x;
            osd_to_draw = 1;
        } else
            osd[curr_item].pos->x = screen_width-osd[curr_item].size.x;
        break;
    case KEY_UP:
        if (osd[curr_item].pos->y > 0) {
            osd[curr_item].pos->y-=(osd[curr_item].pos->y>=step)?step:osd[curr_item].pos->y;
            osd_to_draw = 1;
        }
        break;
    case KEY_DOWN:
        if (osd[curr_item].pos->y < screen_height-osd[curr_item].size.y) {
            osd[curr_item].pos->y+=(screen_height-osd[curr_item].size.y-osd[curr_item].pos->y>step)?step:screen_height-osd[curr_item].size.y-osd[curr_item].pos->y;
            osd_to_draw = 1;
        } else
            osd[curr_item].pos->y = screen_height-osd[curr_item].size.y;
        break;
    case KEY_SET:
        ++curr_item;
        if (!osd[curr_item].pos)
            curr_item = 0;
        osd_to_draw = 1;
        break;
    case KEY_DISPLAY:
        step=(step==1)?10:1;
        osd_to_draw = 1;
        break;
    }
}

//-------------------------------------------------------------------
static void gui_osd_draw_single_histo(int hist, coord x, coord y, int small) {
    register unsigned int i, v, threshold;
    register color cl, cl_over, cl_bg=conf.histo_color>>8;
    coord w=HISTO_WIDTH, h=HISTO_HEIGHT;

    switch (hist) {
        case HISTO_R:
            cl=((mode_get()&MODE_MASK) == MODE_REC)?COLOR_HISTO_R:COLOR_HISTO_R_PLAY;
            break;
        case HISTO_G:
            cl=((mode_get()&MODE_MASK) == MODE_REC)?COLOR_HISTO_G:COLOR_HISTO_G_PLAY;
            break;
        case HISTO_B:
            cl=((mode_get()&MODE_MASK) == MODE_REC)?COLOR_HISTO_B:COLOR_HISTO_B_PLAY;
            break;
        case HISTO_RGB:
        case HISTO_Y:
        default:
            cl=conf.histo_color;
            break;
    }

    if (small) {
        h>>=1; w>>=1;
        for (i=0; i<w; ++i) {
            threshold = (histogram[hist][i<<1]+histogram[hist][(i<<1)+1])>>2;

            for (v=1; v<h-1; ++v)
                draw_pixel(x+1+i, y+h-v, (v<=threshold)?cl:cl_bg);
            cl_over = (threshold==h && conf.show_overexp)?conf.histo_color2>>8:cl;
            for (; v<h; ++v)
                draw_pixel(x+1+i, y+h-v, (v<=threshold)?cl_over:cl_bg);
        }
    } else {
        for (i=0; i<w; ++i) {
            threshold = histogram[hist][i];

            for (v=1; v<h-3; ++v)
                draw_pixel(x+1+i, y+h-v, (v<=threshold)?cl:cl_bg);
            cl_over = (threshold==h && conf.show_overexp)?conf.histo_color2>>8:cl;
            for (; v<h; ++v)
                draw_pixel(x+1+i, y+h-v, (v<=threshold)?cl_over:cl_bg);
        }
    }

    draw_rect(x, y, x+1+w, y+h, conf.histo_color2&0xFF);
    //Vertical Lines
    if (conf.histo_show_ev_grid) for (i=1;i<=4;i++) draw_line(x+(1+w)*i/5, y, x+(1+w)*i/5, y+h, conf.histo_color2&0xFF);
}

//-------------------------------------------------------------------
// free and NULL zebra buffers. free(NULL) is always OK.
static void gui_osd_zebra_free() {
#if !defined (CAM_ZEBRA_NOBUF)
    free(buf);
#endif
    buf=NULL;
#if ZEBRA_CANONOSD_BORDER_RESTORE
    free(cur_buf_top);
    cur_buf_top=NULL;
    free(cur_buf_bot);
    cur_buf_bot=NULL;
#else
    free(cur_buf);
    cur_buf=NULL;
#endif
}
// prepare zebra resources, or free them
// returns 1 if zebra should be drawn
static int gui_osd_zebra_init(int show) {
  if(show)
  {
    if (!buf)
    {
      timer = 0;
        #if defined (CAM_ZEBRA_NOBUF)
            buffer_size=screen_buffer_size-ZEBRA_HMARGIN0*screen_buffer_width;
            buf=vid_get_bitmap_fb();
        #elif defined (CAM_ZEBRA_ASPECT_ADJUST)
            buffer_size=screen_buffer_size-ZEBRA_HMARGIN0*screen_buffer_width;
            buf = malloc(buffer_size);
            //~ if (!buf) draw_txt_string(0, 14, "Warn: No space to allocate zebra buffer: restart camera", MAKE_COLOR(COLOR_ALT_BG, COLOR_FG));
            if (!buf)
            buf=vid_get_bitmap_fb(); //without new buffer: directly into screen buffer: we got some flickering in OSD and histogram but it's usable
            //~ msleep(50);
        #else
            buf = malloc(screen_buffer_size);
        #endif
            scr_buf = vid_get_bitmap_fb();
#if ZEBRA_CANONOSD_BORDER_RESTORE
            cur_buf_top = malloc(screen_buffer_width * ZFIX_TOP);
            cur_buf_bot = malloc(screen_buffer_width * ZFIX_BOTTOM);
    #if defined (CAM_ZEBRA_ASPECT_ADJUST)
            if (cur_buf_top) memset(cur_buf_top,0,screen_buffer_width * ZFIX_TOP);
            if (cur_buf_bot) memset(cur_buf_bot,0,screen_buffer_width * ZFIX_BOTTOM);
    #endif
#else
            cur_buf = malloc(screen_buffer_size);
#endif
            // cleanup and disable zebra if any mallocs failed
            if(!buf ||
#if ZEBRA_CANONOSD_BORDER_RESTORE
                !cur_buf_top ||
                !cur_buf_bot
#else
                !cur_buf
#endif
                ) {
                gui_osd_zebra_free();
            }
#if CAM_HAS_VARIABLE_ASPECT
            else // in variable aspect, the borders would never be cleared
                memset(buf,0,screen_buffer_size);
#endif
        }
    }
    else {
        if(buf) // if zebra was previously on, restore
            draw_restore();

        gui_osd_zebra_free();
    }
    return (buf != NULL);
}

//-------------------------------------------------------------------
static void draw_pixel_buffered(unsigned int offset, color cl) {
    // shouldn't this be checked on all cams ?
    #if defined CAM_ZEBRA_ASPECT_ADJUST
        if (offset < buffer_size)
            buf[offset] = cl;
   #else
        buf[offset] = cl;
   #endif
}

//-------------------------------------------------------------------
int draw_guard_pixel() {
    unsigned char* buffer1 = vid_get_bitmap_fb()+screen_buffer_size/2;
    unsigned char* buffer2 = buffer1+screen_buffer_size;
    int has_disappeared=0;

    if(*buffer1!=COLOR_GREEN) has_disappeared=1;
    if(*buffer2!=COLOR_GREEN) has_disappeared=2;
    *buffer1 = *buffer2 = COLOR_GREEN;
    return has_disappeared;
}

//-------------------------------------------------------------------
#if ZEBRA_CANONOSD_BORDER_RESTORE
unsigned char get_cur_buf(unsigned int idx) {
    unsigned int a;

    a=screen_buffer_size - screen_buffer_width * ZFIX_BOTTOM;

    if (idx < screen_buffer_width * ZFIX_TOP) return(cur_buf_top[idx]);
    if (idx >= a && idx < screen_buffer_size) return(cur_buf_bot[idx - a]);
    return (COLOR_TRANSPARENT);
}
#endif
//-------------------------------------------------------------------
static void gui_osd_draw_zebra_osd() {
    switch (conf.zebra_draw_osd) {
        case ZEBRA_DRAW_NONE:
            break;
        case ZEBRA_DRAW_OSD:
            if (conf.show_osd) {
                draw_set_draw_proc(draw_pixel_buffered);
                if ((mode_get()&MODE_MASK) == MODE_REC) {
                    if (conf.show_dof != DOF_DONT_SHOW) gui_osd_calc_dof();
                    if (conf.show_grid_lines) {
                        gui_grid_draw_osd(1);
                    }
                    if ((conf.show_dof == DOF_SHOW_IN_DOF) || (conf.show_dof == DOF_SHOW_IN_DOF_EX)) {
                        gui_osd_draw_dof();
                    }
                    if (conf.show_state) {
                        gui_osd_draw_state();
                    }
                    if (conf.show_remaining_raw) {
                        gui_osd_draw_raw_info();
                    }
                    if (conf.show_values) {
                        gui_osd_draw_values();
                    }
                }
                gui_batt_draw_osd();
                gui_space_draw_osd();
                gui_usb_draw_osd();
                if (conf.show_clock) {
                    gui_osd_draw_clock(0,0,0);
                }
                if (conf.show_temp>0) {
                    gui_osd_draw_temp();
                }
                draw_set_draw_proc(NULL);
            }
            /* no break here */
        case ZEBRA_DRAW_HISTO:
        default:
            if (conf.show_histo) {
                draw_set_draw_proc(draw_pixel_buffered);
                gui_osd_draw_histo();
                draw_set_draw_proc(NULL);
            }
            break;
    }
}

// reyalp - TODO this should be rewritten so there is one generic zebra func for all cameras
#if defined(CAM_ZEBRA_ASPECT_ADJUST)
//nandoide sept-2009
// viewport is 360x240 and screen buffer 960x270, we need to expand the x coordinate
// reyalp - applies to other cameras where the real bitmap width is is different from what lib.c reports. Also used on some other cameras ...
int gui_osd_draw_zebra(int show) {
    unsigned int v, s, x, y, f, over;
    color cl_under=conf.zebra_color>>8, cl_over=conf.zebra_color&0xFF;
    static int need_restore=0;
    int viewport_height;
    int viewport_width; 
    int viewport_image_offset;  // for when viewport memory buffer is wider than viewport
    int viewport_row_offset;    // for when viewport memory buffer is wider than viewport
    int viewport_xoffset;	// used when image size != viewport size
    int viewport_yoffset;	// used when image size != viewport size
    int mrec = ((mode_get()&MODE_MASK) == MODE_REC);
    int zebra_drawn=0;
    color cls[] = {
        COLOR_TRANSPARENT,
        (mrec)?COLOR_HISTO_B:COLOR_HISTO_B_PLAY,
        (mrec)?COLOR_HISTO_G:COLOR_HISTO_G_PLAY,
        (mrec)?COLOR_HISTO_BG:COLOR_HISTO_BG_PLAY,
        (mrec)?COLOR_HISTO_R:COLOR_HISTO_R_PLAY,
        (mrec)?COLOR_HISTO_RB:COLOR_HISTO_RB_PLAY,
        (mrec)?COLOR_HISTO_RG:COLOR_HISTO_RG_PLAY,
        COLOR_BLACK
    };

    if (!gui_osd_zebra_init(show))
        return 0;

    if(timer==0) {
        draw_guard_pixel();
        timer=1;
        return 0;
    }
    if(timer==1) {
        int ready;
        static int n=0;
        if (!mrec) ready=1;
        else get_property_case(PROPCASE_SHOOTING, &ready, 4);
        n=draw_guard_pixel(); // will be 0 in PLAY mode, should be 1 or 2 in REC mode.
        if(!ready) return 0;
    }
    ++timer;
    // Try to get the best viewport buffer. In playmode its the _d one, in
    // record mode we try to get the fast live one first
    if (!mrec) {
        img_buf = vid_get_viewport_fb_d();
    }
    else {
        img_buf = vid_get_viewport_live_fb();
        if( !img_buf ) {
            img_buf = vid_get_viewport_fb();
        }
    }
    viewport_height = vid_get_viewport_height();
    viewport_width = vid_get_viewport_width(); 
    viewport_image_offset = vid_get_viewport_image_offset(); 
    viewport_row_offset = vid_get_viewport_row_offset(); 
	viewport_xoffset = vid_get_viewport_xoffset();
	viewport_yoffset = vid_get_viewport_yoffset();
    switch (conf.zebra_mode) {
        case ZEBRA_MODE_ZEBRA_1:
            f = 4;
            break;
        case ZEBRA_MODE_ZEBRA_2:
            f = 8;
            break;
        case ZEBRA_MODE_SOLID:
            f = 1;
            break;
        case ZEBRA_MODE_BLINKED_1:
            f = timer&1;
            break;
        case ZEBRA_MODE_BLINKED_3:
            f = timer&4;
            break;
        case ZEBRA_MODE_BLINKED_2:
        default:
            f = timer&2;
            break;
    }
    // if not in no-zebra phase of blink mode zebra, draw zebra to buf[]
    if (f) {
        if (viewport_yoffset > 0) { // clear top & bottom areas of buffer if image height if smaller than viewport
            memset(buf, COLOR_TRANSPARENT, viewport_yoffset*screen_buffer_width);
            memset(buf+(viewport_yoffset+viewport_height)*screen_buffer_width, COLOR_TRANSPARENT, viewport_yoffset*screen_buffer_width);
        }
        int step_x, step_v, sy, sx;
        over = 255-conf.zebra_over;
            if (conf.zebra_multichannel) {step_x=2; step_v=6;} else {step_x=1; step_v=3;}
            for (y=viewport_yoffset, v=viewport_image_offset; y<viewport_yoffset+viewport_height; ++y) {
                sy=y*screen_buffer_width;
                sx=viewport_xoffset;
                if (viewport_xoffset > 0) { // clear left & right areas of buffer if image width if smaller than viewport
                    memset(buf+sy, COLOR_TRANSPARENT, sx*2);
                    memset(buf+sy+(sx+viewport_width)*2, COLOR_TRANSPARENT, sx*2);
                }
                for (x=viewport_xoffset; x<viewport_xoffset+viewport_width; x+=step_x, sx+=step_x, v+=step_v) {
                    register int yy, uu, vv;
                    int sel;
                    yy = img_buf[v+1];
                    s=sy+sx*2;
                    if (conf.zebra_multichannel) {
                        uu = (signed char)img_buf[v];
                        vv = (signed char)img_buf[v+2];
                        sel=0;
                        if (!((conf.zebra_mode == ZEBRA_MODE_ZEBRA_1 || conf.zebra_mode == ZEBRA_MODE_ZEBRA_2) && (y-x-timer)&f)) {
                            if (clip8(((yy<<12) +           vv*5743 + 2048)>>12)>over) sel  = 4; // R
                            if (clip8(((yy<<12) - uu*1411 - vv*2925 + 2048)>>12)>over) sel |= 2; // G
                            if (clip8(((yy<<12) + uu*7258           + 2048)>>12)>over) sel |= 1; // B
                        }
                        buf[s]=buf[s+1]=cls[sel];
                        buf[s+2]=buf[s+3]=cls[sel];
                    }
                    else if (((conf.zebra_mode == ZEBRA_MODE_ZEBRA_1 || conf.zebra_mode == ZEBRA_MODE_ZEBRA_2) && (y-x-timer)&f)) buf[s]=buf[s+1]=COLOR_TRANSPARENT;
                    else buf[s]=buf[s+1]=(yy>over)?cl_over:(yy<conf.zebra_under)?cl_under:COLOR_TRANSPARENT;
                    if (buf[s] != COLOR_TRANSPARENT && !zebra_drawn) zebra_drawn = 1;
#if ZEBRA_CANONOSD_BORDER_RESTORE
                        if(get_cur_buf(s)!=COLOR_TRANSPARENT) buf[s]=get_cur_buf(s);
                        if(conf.zebra_multichannel && get_cur_buf(s+1)!=COLOR_TRANSPARENT) buf[s+1]=get_cur_buf(s+1);
#else
                        if(cur_buf[s]!=COLOR_TRANSPARENT) buf[s]=cur_buf[s];
                        if(conf.zebra_multichannel && cur_buf[s+1]!=COLOR_TRANSPARENT) buf[s+1]=cur_buf[s+1];
#endif

                    if (mrec) {
                    }
				}
				// adjust for cases where buffer is wider than viewport (e.g. on G12)
				v += viewport_row_offset;
            }
        if (!zebra_drawn) f=0;
    }
    // if blink mode is in no-zebra phase OR if there was no over/underexposed pixels to draw zebra on
    if (!f) {
        // if zebra was drawn during previous call of this function
        if (need_restore) {
            if (conf.zebra_restore_screen || conf.zebra_restore_osd) {
                draw_restore();
            } else {  // clear buf[] of zebra, only leave Canon OSD
                if (mrec) { // REC mode
//~ #if ZEBRA_CANONOSD_BORDER_RESTORE
                    //~ // copy rescued Canon OSD to buf[] top/bottom parts and fill center with transparent color:
                    //~ memcpy(buf, cur_buf_top, screen_buffer_width * ZFIX_TOP);
                    //~ memcpy(buf + screen_buffer_size - screen_buffer_width * ZFIX_BOTTOM, cur_buf_bot, screen_buffer_width * ZFIX_BOTTOM);
                    //~ for (s = screen_buffer_width*ZFIX_TOP; s < screen_buffer_size-screen_buffer_width*ZFIX_BOTTOM; s++) {
                        //~ buf[s]=COLOR_TRANSPARENT;
                    //~ }
//~ #else
                    //~ // copy from a complete Canon OSD rescue screen dump
                    //~ memcpy(buf, cur_buf, screen_buffer_size);
//~ #endif
                } else { // Not REC mode
                    // No Canon OSD restore, fill buf[] with transparent color:
                    memset(buf, COLOR_TRANSPARENT, buffer_size);
                }
                // draw CHDK osd and histogram to buf[] (if enabled in config)
                gui_osd_draw_zebra_osd();
                // copy buf[] to both display buffers

                if (buf!=scr_buf)
                  memcpy(scr_buf, buf, buffer_size);
                  memcpy(scr_buf+screen_buffer_size, buf, buffer_size);
            }
            need_restore=0;
        }
        return !(conf.zebra_restore_screen && conf.zebra_restore_osd);
    // if zebra was drawn
    } else {
        // draw CHDK osd and histogram to buf[] over zebra (if enabled in config)
        gui_osd_draw_zebra_osd();
        // copy buf[] to both display buffers
        if (buf!=scr_buf)
            memcpy(scr_buf, buf, buffer_size);
            memcpy(scr_buf+screen_buffer_size, buf, buffer_size);

        need_restore=1;
        return 1;
    }
    return 0;
}
#else
//-------------------------------------------------------------------
int gui_osd_draw_zebra(int show) {
    unsigned int v, s, x, y, f, over;
    color cl_under=conf.zebra_color>>8, cl_over=conf.zebra_color&0xFF;
    static int need_restore=0;
    int viewport_height;
    int mrec = ((mode_get()&MODE_MASK) == MODE_REC);
    int zebra_drawn=0;
    color cls[] = {
        COLOR_TRANSPARENT,
        (mrec)?COLOR_HISTO_B:COLOR_HISTO_B_PLAY,
        (mrec)?COLOR_HISTO_G:COLOR_HISTO_G_PLAY,
        (mrec)?COLOR_HISTO_BG:COLOR_HISTO_BG_PLAY,
        (mrec)?COLOR_HISTO_R:COLOR_HISTO_R_PLAY,
        (mrec)?COLOR_HISTO_RB:COLOR_HISTO_RB_PLAY,
        (mrec)?COLOR_HISTO_RG:COLOR_HISTO_RG_PLAY,
        COLOR_BLACK
    };

    unsigned bWide = 1; // if wide (16:9) or standard (4:3) aspect ratio (but 1 in cameras that only have 4:3)
    unsigned aspOffset = 0; // offset to add to x-coord (or buffer address) when drawing zebra

#if CAM_HAS_VARIABLE_ASPECT
    if (shooting_get_prop(PROPCASE_ASPECT_RATIO) == 0) // standard requires x-shift to overlay drawing
    {
        bWide = 0;
        //aspOffset = (screen_width - (screen_width * 12 / 16)) / 2; // = actual calculation, simplified below
        aspOffset = screen_width / 8; // half of the difference in width between equal height 16:9 and 4:3 screens, = black bar width
    }
#endif

    if (!gui_osd_zebra_init(show))
        return 0;

    if(timer==0) {
        draw_guard_pixel();
        timer=1;
        return 0;
    }
    if(timer==1) {
        int ready;
        static int n=0;
        if (!mrec) ready=1;
        else get_property_case(PROPCASE_SHOOTING, &ready, 4);
        n=draw_guard_pixel(); // will be 0 in PLAY mode, should be 1 or 2 in REC mode.
        if(!ready) return 0;
#if ZEBRA_CANONOSD_BORDER_RESTORE
        // rescue Canon OSD from scr_buf to cur_buf_top and _bot:
        if (n==1) {
            memcpy(cur_buf_top, scr_buf, screen_buffer_width*ZFIX_TOP);
            memcpy(cur_buf_bot, scr_buf + screen_buffer_size - screen_buffer_width*ZFIX_BOTTOM, screen_buffer_width*ZFIX_BOTTOM);
        }
        else {
            memcpy(cur_buf_top, scr_buf + screen_buffer_size, screen_buffer_width*ZFIX_TOP);
            memcpy(cur_buf_bot, scr_buf + 2*screen_buffer_size - screen_buffer_width*ZFIX_BOTTOM, screen_buffer_width*ZFIX_BOTTOM);
        }
#else
        // rescue Canon OSD from cur_buf
        if(n==1) memcpy(cur_buf, scr_buf, screen_buffer_size);
        else memcpy(cur_buf, scr_buf+screen_buffer_size, screen_buffer_size);
#endif
    }
    ++timer;
    // Try to get the best viewport buffer. In playmode its the _d one, in
    // record mode we try to get the fast live one first
    if (!mrec) {
        img_buf = vid_get_viewport_fb_d();
    }
    else {
        img_buf = vid_get_viewport_live_fb();
        if( !img_buf ) {
            img_buf = vid_get_viewport_fb();
        }
    }
    viewport_height = vid_get_viewport_height();
    switch (conf.zebra_mode) {
        case ZEBRA_MODE_ZEBRA_1:
            f = 4;
            break;
        case ZEBRA_MODE_ZEBRA_2:
            f = 8;
            break;
        case ZEBRA_MODE_SOLID:
            f = 1;
            break;
        case ZEBRA_MODE_BLINKED_1:
            f = timer&1;
            break;
        case ZEBRA_MODE_BLINKED_3:
            f = timer&4;
            break;
        case ZEBRA_MODE_BLINKED_2:
        default:
            f = timer&2;
            break;
    }
    // if not in no-zebra phase of blink mode zebra, draw zebra to buf[]
    if (f) {
        int step_x, step_v;
        over = 255-conf.zebra_over;
            if (conf.zebra_multichannel) {step_x=2; step_v=6;} else {step_x=1; step_v=3;}
            s = aspOffset;
            for (y=1, v=0; y<=viewport_height; ++y) {
                for (x=0; x<screen_width; x+=step_x, s+=step_x, v+=step_v) {
                    register int yy, uu, vv;
                    int sel;

                    if (!bWide && (x + aspOffset >= screen_width - aspOffset)) continue; // do not draw "outside screen"

                    yy = img_buf[v+1];
                    if (conf.zebra_multichannel) {
                        uu = (signed char)img_buf[v];
                        vv = (signed char)img_buf[v+2];
                        sel=0;
                        if (!((conf.zebra_mode == ZEBRA_MODE_ZEBRA_1 || conf.zebra_mode == ZEBRA_MODE_ZEBRA_2) && (y-x-timer)&f)) {
                            if (clip8(((yy<<12) +           vv*5743 + 2048)>>12)>over) sel  = 4; // R
                            if (clip8(((yy<<12) - uu*1411 - vv*2925 + 2048)>>12)>over) sel |= 2; // G
                            if (clip8(((yy<<12) + uu*7258           + 2048)>>12)>over) sel |= 1; // B
                        }
                        buf[s]=buf[s+1]=cls[sel];
                    }
                    else if (((conf.zebra_mode == ZEBRA_MODE_ZEBRA_1 || conf.zebra_mode == ZEBRA_MODE_ZEBRA_2) && (y-x-timer)&f)) buf[s]=COLOR_TRANSPARENT;
                    else buf[s]=(yy>over)?cl_over:(yy<conf.zebra_under)?cl_under:COLOR_TRANSPARENT;
                    if (buf[s] != COLOR_TRANSPARENT && !zebra_drawn) zebra_drawn = 1;
                    if (mrec) {
                        // draw Canon OSD to buf[] if in REC mode
#if ZEBRA_CANONOSD_BORDER_RESTORE
                        if(get_cur_buf(s)!=COLOR_TRANSPARENT) buf[s]=get_cur_buf(s);
                        if(conf.zebra_multichannel && get_cur_buf(s+1)!=COLOR_TRANSPARENT) buf[s+1]=get_cur_buf(s+1);
#else
                        if(cur_buf[s]!=COLOR_TRANSPARENT) buf[s]=cur_buf[s];
                        if(conf.zebra_multichannel && cur_buf[s+1]!=COLOR_TRANSPARENT) buf[s+1]=cur_buf[s+1];
#endif
                    }
                }
                s+=screen_buffer_width-screen_width;
                if (y*screen_height/viewport_height == (s+screen_buffer_width)/screen_buffer_width) {
                    memcpy(buf+s, buf+s-screen_buffer_width, screen_buffer_width);
                    s+=screen_buffer_width;
                }
            }
        if (!zebra_drawn) f=0;
    }
    // if blink mode is in no-zebra phase OR if there was no over/underexposed pixels to draw zebra on
    if (!f) {
        // if zebra was drawn during previous call of this function
        if (need_restore) {
            if (conf.zebra_restore_screen || conf.zebra_restore_osd) {
                draw_restore();
            } else {  // clear buf[] of zebra, only leave Canon OSD
                if (mrec) { // REC mode
#if ZEBRA_CANONOSD_BORDER_RESTORE
                    // copy rescued Canon OSD to buf[] top/bottom parts and fill center with transparent color:
                    memcpy(buf, cur_buf_top, screen_buffer_width * ZFIX_TOP);
                    memcpy(buf + screen_buffer_size - screen_buffer_width * ZFIX_BOTTOM, cur_buf_bot, screen_buffer_width * ZFIX_BOTTOM);
                    for (s = screen_buffer_width*ZFIX_TOP; s < screen_buffer_size-screen_buffer_width*ZFIX_BOTTOM; s++) {
                        buf[s]=COLOR_TRANSPARENT;
                    }
#else
                    // copy from a complete Canon OSD rescue screen dump
                    memcpy(buf, cur_buf, screen_buffer_size);
#endif
                } else { // Not REC mode
                    // No Canon OSD restore, fill buf[] with transparent color:
                    memset(buf, COLOR_TRANSPARENT, screen_buffer_size);
                }
                // draw CHDK osd and histogram to buf[] (if enabled in config)
                gui_osd_draw_zebra_osd();
                // copy buf[] to both display buffers
                memcpy(scr_buf, buf, screen_buffer_size);
                memcpy(scr_buf+screen_buffer_size, buf, screen_buffer_size);
            }
            need_restore=0;
        }
        return !(conf.zebra_restore_screen && conf.zebra_restore_osd);
    // if zebra was drawn
    } else {
        // draw CHDK osd and histogram to buf[] over zebra (if enabled in config)
        gui_osd_draw_zebra_osd();
        // copy buf[] to both display buffers
        memcpy(scr_buf, buf, screen_buffer_size);
        memcpy(scr_buf+screen_buffer_size, buf, screen_buffer_size);

        need_restore=1;
        return 1;
    }
    return 0;
}
#endif
//-------------------------------------------------------------------
static void gui_osd_draw_blended_histo(coord x, coord y) {
    register unsigned int i, v, red, grn, blu, sel;
    int m = ((mode_get()&MODE_MASK) == MODE_REC);
    color cls[] = {
        conf.histo_color>>8,
        (m)?COLOR_HISTO_B:COLOR_HISTO_B_PLAY,
        (m)?COLOR_HISTO_G:COLOR_HISTO_G_PLAY,
        (m)?COLOR_HISTO_BG:COLOR_HISTO_BG_PLAY,
        (m)?COLOR_HISTO_R:COLOR_HISTO_R_PLAY,
        (m)?COLOR_HISTO_RB:COLOR_HISTO_RB_PLAY,
        (m)?COLOR_HISTO_RG:COLOR_HISTO_RG_PLAY,
        COLOR_WHITE
    };

    for (i=0; i<HISTO_WIDTH; ++i) {
        red = histogram[HISTO_R][i];
        grn = histogram[HISTO_G][i];
        blu = histogram[HISTO_B][i];

        for (v=1; v<HISTO_HEIGHT; ++v) {
            sel = 0;

            if (v < red) sel = 4;
            if (v < grn) sel |= 2;
            if (v < blu) sel |= 1;

            draw_pixel(x+1+i, y+HISTO_HEIGHT-v, cls[sel]);
        }
    }

    draw_rect(x, y, x+1+HISTO_WIDTH, y+HISTO_HEIGHT, conf.histo_color2&0xFF);
    //Vertical lines
    if (conf.histo_show_ev_grid) for (i=1;i<=4;i++) draw_line(x+(1+HISTO_WIDTH)*i/5, y, x+(1+HISTO_WIDTH)*i/5, y+HISTO_HEIGHT, conf.histo_color2&0xFF);

}

//-------------------------------------------------------------------
void gui_osd_draw_histo() {
    switch (conf.histo_layout) {
        case OSD_HISTO_LAYOUT_Y:
                gui_osd_draw_single_histo(HISTO_Y, conf.histo_pos.x, conf.histo_pos.y, 0);
                break;
        case OSD_HISTO_LAYOUT_A_Y:
                gui_osd_draw_single_histo(HISTO_RGB, conf.histo_pos.x, conf.histo_pos.y, 0);
                gui_osd_draw_single_histo(HISTO_Y, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT, 0);
                break;
        case OSD_HISTO_LAYOUT_R_G_B:
                gui_osd_draw_single_histo(HISTO_R, conf.histo_pos.x, conf.histo_pos.y, 0);
                gui_osd_draw_single_histo(HISTO_G, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT, 0);
                gui_osd_draw_single_histo(HISTO_B, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT*2, 0);
                break;
        case OSD_HISTO_LAYOUT_A_yrgb:
                gui_osd_draw_single_histo(HISTO_RGB, conf.histo_pos.x, conf.histo_pos.y, 0);
                gui_osd_draw_single_histo(HISTO_Y, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT, 1);
                gui_osd_draw_single_histo(HISTO_R, conf.histo_pos.x+HISTO_WIDTH/2+1, conf.histo_pos.y+HISTO_HEIGHT, 1);
                gui_osd_draw_single_histo(HISTO_G, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT+HISTO_HEIGHT/2, 1);
                gui_osd_draw_single_histo(HISTO_B, conf.histo_pos.x+HISTO_WIDTH/2+1, conf.histo_pos.y+HISTO_HEIGHT+HISTO_HEIGHT/2, 1);
                break;
        case OSD_HISTO_LAYOUT_Y_argb:
                gui_osd_draw_single_histo(HISTO_Y, conf.histo_pos.x, conf.histo_pos.y, 0);
                gui_osd_draw_single_histo(HISTO_RGB, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT, 1);
                gui_osd_draw_single_histo(HISTO_R, conf.histo_pos.x+HISTO_WIDTH/2+1, conf.histo_pos.y+HISTO_HEIGHT, 1);
                gui_osd_draw_single_histo(HISTO_G, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT+HISTO_HEIGHT/2, 1);
                gui_osd_draw_single_histo(HISTO_B, conf.histo_pos.x+HISTO_WIDTH/2+1, conf.histo_pos.y+HISTO_HEIGHT+HISTO_HEIGHT/2, 1);
                break;
        case OSD_HISTO_LAYOUT_BLEND:
                gui_osd_draw_blended_histo(conf.histo_pos.x, conf.histo_pos.y);
                break;
        case OSD_HISTO_LAYOUT_BLEND_Y:
                gui_osd_draw_blended_histo(conf.histo_pos.x, conf.histo_pos.y);
                gui_osd_draw_single_histo(HISTO_Y, conf.histo_pos.x, conf.histo_pos.y+HISTO_HEIGHT, 0);
                break;
        case OSD_HISTO_LAYOUT_A:
        default:
                gui_osd_draw_single_histo(HISTO_RGB, conf.histo_pos.x, conf.histo_pos.y, 0);
                break;
    }

    if (conf.histo_layout != OSD_HISTO_LAYOUT_R_G_B) {
        if (under_exposed && conf.show_overexp) {
            draw_filled_ellipse(conf.histo_pos.x+5, conf.histo_pos.y+5, 3, 3, MAKE_COLOR(conf.histo_color2>>8, conf.histo_color2>>8));
        }

        if (over_exposed && conf.show_overexp) {
            draw_filled_ellipse(conf.histo_pos.x+HISTO_WIDTH-5, conf.histo_pos.y+5, 3, 3, MAKE_COLOR(conf.histo_color2>>8, conf.histo_color2>>8));
        }
    }
    if ((conf.show_overexp ) && kbd_is_key_pressed(KEY_SHOOT_HALF) && (under_exposed || over_exposed))
      draw_string(conf.histo_pos.x+HISTO_WIDTH-FONT_WIDTH*3, conf.histo_pos.y-FONT_HEIGHT, "EXP", conf.histo_color);
    if (conf.histo_auto_ajust){
      if (histo_magnification) {
        sprintf(osd_buf, " %d.%02dx ", histo_magnification/1000, histo_magnification/10%100);
        draw_string(conf.histo_pos.x, conf.histo_pos.y-FONT_HEIGHT, osd_buf, conf.histo_color);
      } else if (gui_get_mode()==GUI_MODE_OSD){
        draw_string(conf.histo_pos.x, conf.histo_pos.y-FONT_HEIGHT, " 9.99x ", conf.histo_color);
      } else {
        draw_filled_rect(conf.histo_pos.x, conf.histo_pos.y-FONT_HEIGHT, conf.histo_pos.x+8*FONT_WIDTH, conf.histo_pos.y-1, MAKE_COLOR(COLOR_TRANSPARENT, COLOR_TRANSPARENT));
      }
    }
}

//-------------------------------------------------------------------
static void print_dist(char *buf, float dist, short is_hyp) {
// length of printed string is always 4
    if (dist<=0 || (!(is_hyp) && shooting_is_infinity_distance())) {
        sprintf(buf, " inf");
    } else if (dist<1000) {
        sprintf(buf, ".%03d", (int)dist);
    } else if (dist<10000) {
        sprintf(buf, "%d.%02d", (int)(dist/1000), (int)(dist/10)%100);
    } else if (dist<100000) {
        sprintf(buf, "%02d.%d", (int)(dist/1000), (int)(dist/100)%10);
    } else {
        sprintf(buf, "%4d", (int)(dist/1000));
    }
}

static void sprintf_dist(char *buf, float dist)
{
    print_dist(buf, dist, 0);
}

static void sprintf_dist_hyp(char *buf, float dist)
{
    print_dist(buf, dist, 1);
}

static void sprintf_canon_values(char *buf, short dist)
{
short v=((dist<0)?-dist:dist);
sprintf(buf, "%s%d.%02d", ((dist<0)?"-":""), v/96, v%96);
}


//-------------------------------------------------------------------

void gui_osd_calc_dof() {

  shooting_update_dof_values();
}

void gui_osd_calc_expo_param() {

    expo.av96=shooting_get_av96();
    expo.tv96=shooting_get_tv96();
    expo.sv96=shooting_get_sv96();
    expo.iso=shooting_get_iso_real();
    expo.sv96_market=shooting_get_svm96();
    expo.iso_market=shooting_get_iso_market();
    expo.bv96_measured=shooting_get_bv96();
    expo.ev96_seted=expo.tv96+expo.av96; //Tv96+Av96
    expo.ev96_measured=expo.bv96_measured+expo.sv96;//Bv96+Sv96
    expo.dev96=expo.ev96_measured-expo.ev96_seted;// Ev96_external-Ev96_internal
    expo.bv96_seted=expo.ev96_seted-expo.sv96;
    expo.dev96_canon=shooting_get_canon_overexposure_value();
    expo.b=shooting_get_luminance();
}

void gui_osd_draw_dof() {

    color valid_col = (conf.osd_color & 0xff00) | COLOR_HISTO_G;
    int i=8;
    short f_ex = (conf.show_dof==DOF_SHOW_IN_DOF_EX);
    draw_string(conf.dof_pos.x, conf.dof_pos.y, "S/NL/FL:", conf.osd_color);
    sprintf_dist(osd_buf, (float)dof_values.subject_distance);
    int j=strlen(osd_buf);
    draw_string(conf.dof_pos.x+i*FONT_WIDTH, conf.dof_pos.y, osd_buf,
      (f_ex && (dof_values.distance_valid || shooting_get_focus_mode()))?valid_col:conf.osd_color);
    i=i+j;
    draw_string(conf.dof_pos.x+i*FONT_WIDTH, conf.dof_pos.y, "/", conf.osd_color);
    sprintf_dist(osd_buf, (float)dof_values.near_limit);
    j=strlen(osd_buf);
    draw_string(conf.dof_pos.x+(++i)*FONT_WIDTH, conf.dof_pos.y, osd_buf,
      (f_ex && dof_values.distance_valid)?valid_col:conf.osd_color);
    i=i+j;
    draw_string(conf.dof_pos.x+i*FONT_WIDTH, conf.dof_pos.y, "/", conf.osd_color);
    sprintf_dist(osd_buf, (float)dof_values.far_limit);
    draw_string(conf.dof_pos.x+(++i)*FONT_WIDTH, conf.dof_pos.y, osd_buf,
      (f_ex && dof_values.distance_valid)?valid_col:conf.osd_color);
    i=8;
      draw_string(conf.dof_pos.x, conf.dof_pos.y+FONT_HEIGHT, "DOF/HYP:", conf.osd_color);
    sprintf_dist(osd_buf, (float)dof_values.depth_of_field);
    j=strlen(osd_buf);
    draw_string(conf.dof_pos.x+i*FONT_WIDTH, conf.dof_pos.y+FONT_HEIGHT, osd_buf,
      (f_ex && dof_values.distance_valid)?valid_col:conf.osd_color);
    i=i+j;
    draw_string(conf.dof_pos.x+i*FONT_WIDTH, conf.dof_pos.y+FONT_HEIGHT, "/", conf.osd_color);
    sprintf_dist_hyp(osd_buf, (float)dof_values.hyperfocal_distance);
    draw_string(conf.dof_pos.x+(++i)*FONT_WIDTH, conf.dof_pos.y+FONT_HEIGHT, osd_buf,
      (f_ex && dof_values.hyperfocal_valid)?valid_col:conf.osd_color);
}

static short n, m; //string number

void gui_print_osd_state_string_int(const char * title, int value) {
  strcpy(osd_buf, title);
  sprintf(osd_buf+strlen(osd_buf), "%d", value);
  sprintf(osd_buf+strlen(osd_buf), "%12s", "");
  osd_buf[12]=0;
  draw_string(conf.mode_state_pos.x, conf.mode_state_pos.y+n, osd_buf, conf.osd_color_override);
  n+=FONT_HEIGHT;
}

void gui_print_osd_state_string_chr(const char *title, const char *value) {
  strcpy(osd_buf, title);
  sprintf(osd_buf+strlen(osd_buf), "%s", value);
  sprintf(osd_buf+strlen(osd_buf), "%12s", "");
  osd_buf[12]=0;
  draw_string(conf.mode_state_pos.x, conf.mode_state_pos.y+n, osd_buf, conf.osd_color_override);
  n+=FONT_HEIGHT;
}

void gui_print_osd_state_string_float(const char * title, const char * fmt, int divisor, int value) {
  strcpy(osd_buf, title);
  sprintf(osd_buf+strlen(osd_buf), fmt, (int)(value/divisor), (int)(value%divisor));
  sprintf(osd_buf+strlen(osd_buf), "%12s", "");
  osd_buf[12]=0;
  draw_string(conf.mode_state_pos.x, conf.mode_state_pos.y+n, osd_buf, conf.osd_color_override);
  n+=FONT_HEIGHT;
}

void gui_print_osd_misc_string_int(const char * title, int value) {
  strcpy(osd_buf, title);
  sprintf(osd_buf+strlen(osd_buf), "%d", value);
  sprintf(osd_buf+strlen(osd_buf), "%9s", "");
  osd_buf[9]=0;
  draw_string(conf.values_pos.x, conf.values_pos.y+m, osd_buf, conf.osd_color);
  m+=FONT_HEIGHT;
}

/*
void gui_print_osd_misc_string_float(const char * title, const char * fmt, int divisor, int value) {
  char s[16];
  strcpy(osd_buf, title);
  sprintf(s, fmt, (int)(value/divisor), (int)(value%divisor));
  sprintf(osd_buf+strlen(osd_buf), "%6s", s);
  //osd_buf[8]=0;
  draw_string(conf.values_pos.x, conf.values_pos.y+m, osd_buf, conf.osd_color);
  m+=FONT_HEIGHT;
}
*/

void gui_print_osd_misc_string_float(const char * title, const char * fmt, int divisor, int value) {
  strcpy(osd_buf, title);
  sprintf(osd_buf+strlen(osd_buf), fmt, (int)(value/divisor), (int)(value%divisor));
  sprintf(osd_buf+strlen(osd_buf), "%9s", "");
  osd_buf[9]=0;
  draw_string(conf.values_pos.x, conf.values_pos.y+m, osd_buf, conf.osd_color);
  m+=FONT_HEIGHT;
}

/*
void gui_print_osd_misc_string_dist(const char * title, int value) {
  strcpy(osd_buf, title);
  sprintf_dist(osd_buf+strlen(osd_buf), (float)value);
  sprintf(osd_buf+strlen(osd_buf), "%9s", "");
  osd_buf[9]=0;
  draw_string(conf.values_pos.x, conf.values_pos.y+m, osd_buf, conf.osd_color);
  m+=FONT_HEIGHT;
}
*/

void gui_print_osd_dof_string_dist(const char * title, int value, short use_good_color, short is_hyp) {
  strcpy(osd_buf, title);
  int i=strlen(osd_buf);
  if (i<8) {
    draw_string(conf.values_pos.x, conf.values_pos.y+m, osd_buf, conf.osd_color);
    if (is_hyp) {
        sprintf_dist_hyp(osd_buf, (float)value);
    } else {
        sprintf_dist(osd_buf, (float)value);
    }
    sprintf(osd_buf+strlen(osd_buf), "%9s", "");
    osd_buf[9-i]=0;
    draw_string(conf.values_pos.x+i*FONT_WIDTH, conf.values_pos.y+m, osd_buf, use_good_color?((conf.osd_color & 0xff00) | COLOR_GREEN):conf.osd_color);
  } else {
    osd_buf[9]=0;
    draw_string(conf.values_pos.x, conf.values_pos.y+m, osd_buf, conf.osd_color);
  }
  m+=FONT_HEIGHT;
}

void gui_print_osd_misc_string_canon_values(const char * title, short value) {
  strcpy(osd_buf, title);
  sprintf_canon_values(osd_buf+strlen(osd_buf), value);
  sprintf(osd_buf+strlen(osd_buf), "%9s", "");
  osd_buf[9]=0;
  draw_string(conf.values_pos.x, conf.values_pos.y+m, osd_buf, conf.osd_color);
  m+=FONT_HEIGHT;
}

//-------------------------------------------------------------------
void gui_osd_draw_raw_info() 
    {
    static int b;
    if (is_raw_enabled())
    { 
        if (conf.show_remaining_raw) 
        {
            int raw_count=GetRawCount();  
            if (raw_count>conf.remaining_raw_treshold)
            {
                sprintf(osd_buf, "%s:%3d", (conf.dng_raw)?"DNG":"RAW", raw_count);
                draw_string(conf.mode_raw_pos.x, conf.mode_raw_pos.y, osd_buf, conf.osd_color);
            }
            else
            {
                sprintf(osd_buf, "%s:%3d", (conf.dng_raw)?"DNG":"RAW", raw_count);
                
                if (b > 6)
                    {
                    draw_string(conf.mode_raw_pos.x, conf.mode_raw_pos.y, osd_buf, conf.osd_color_warn); 
                    b = (b>12) ? 0 : b+1;
                    }
                else
                    {
                    draw_string(conf.mode_raw_pos.x, conf.mode_raw_pos.y, osd_buf, conf.osd_color); 
                    b = b+1;
                    } 
                }
        }
        else
            draw_string(conf.mode_raw_pos.x, conf.mode_raw_pos.y, (conf.dng_raw)?"DNG":"RAW", conf.osd_color); 
    }   
    else if (conf.raw_exceptions_warn)
    {
        gui_print_osd_state_string_chr((conf.dng_raw)?"DNG Disabled":"RAW Disabled",""); 
    }
}
//-------------------------------------------------------------------
void gui_osd_draw_state() {
    int gui_mode=gui_get_mode(), m=(mode_get()&MODE_SHOOTING_MASK);
    long t;

    n=0;
   ///////////////////////////
   //sprintf(osd_buf,"%s",get_debug());
   //draw_string(conf.mode_state_pos.x, conf.mode_state_pos.y+6*FONT_HEIGHT, osd_buf, conf.osd_color);
   ////////////////////////////


    if ((((conf.tv_enum_type) || (conf.tv_override_value)) && (conf.tv_override_koef)  && !(conf.override_disable==1)) || gui_mode==GUI_MODE_OSD){
        if(kbd_is_key_pressed(KEY_SHOOT_HALF))
         {
          t=(int)(shooting_get_shutter_speed_from_tv96(shooting_get_tv96())*100000);
          gui_print_osd_state_string_float("TV:", "%d.%05d ", 100000, t);
         }
        else
         {
         if (conf.tv_enum_type)
           gui_print_osd_state_string_chr("TV:",shooting_get_tv_override_value());
         else
          {
          t=(int)(shooting_get_shutter_speed_override_value()*100000);
          gui_print_osd_state_string_float("TV:", "%d.%05d ", 100000, t);
          }
       }
    }
    if ((conf.av_override_value && !(conf.override_disable==1))|| gui_mode==GUI_MODE_OSD)
       gui_print_osd_state_string_float("AV:", "%d.%02d ", 100, shooting_get_aperture_from_av96(shooting_get_av96_override_value()));
#if CAM_HAS_ND_FILTER
    if ((conf.nd_filter_state && !(conf.override_disable==1))|| gui_mode==GUI_MODE_OSD)
       gui_print_osd_state_string_chr("NDFILTER:", ((conf.nd_filter_state==1)?"IN":"OUT"));
#endif
    if ((conf.autoiso_enable && shooting_get_iso_mode()<=0 && !(m==MODE_M || m==MODE_TV) && shooting_get_flash_mode() && (!(conf.override_disable==1 && conf.override_disable_all))) || gui_mode==GUI_MODE_OSD)
        gui_print_osd_state_string_chr("AUTOISO:", ((conf.autoiso_enable==1)?"ON":"OFF"));
    if ((conf.subj_dist_override_value && conf.subj_dist_override_koef && shooting_can_focus() && !(conf.override_disable==1)) || ((gui_get_mode()==GUI_MODE_ALT) && shooting_get_common_focus_mode())	|| gui_mode==GUI_MODE_OSD)   {
        extern const char* gui_subj_dist_override_value_enum(int change, int arg);
        extern const char* gui_subj_dist_override_koef_enum(int change, int arg);
    	gui_print_osd_state_string_chr("SD:",gui_subj_dist_override_value_enum(0,0));
        if (gui_mode==GUI_MODE_ALT)
		  gui_print_osd_state_string_chr("FACTOR:",gui_subj_dist_override_koef_enum(0,0));
      }
    if ((conf.iso_override_value && conf.iso_override_koef && !(conf.override_disable==1))   || gui_mode==GUI_MODE_OSD)
        gui_print_osd_state_string_int("ISO:", shooting_get_iso_override_value());
    if ((gui_mode==GUI_MODE_OSD) || (shooting_get_drive_mode() && m!=MODE_STITCH && m!=MODE_SCN_BEST_IMAGE)) {
    if ((conf.tv_bracket_value && !(conf.override_disable==1 && conf.override_disable_all)) || (conf.av_bracket_value && !(conf.override_disable==1 && conf.override_disable_all))  || (conf.iso_bracket_value && conf.iso_bracket_koef && !(conf.override_disable==1 && conf.override_disable_all)) || ((conf.subj_dist_bracket_value) && (conf.subj_dist_bracket_koef) && (shooting_can_focus() && !(conf.override_disable==1 && conf.override_disable_all))))
        gui_print_osd_state_string_chr("BRACKET:", shooting_get_bracket_type());
      if (conf.tv_bracket_value && !(conf.override_disable==1 && conf.override_disable_all))
        gui_print_osd_state_string_chr("TV:", shooting_get_tv_bracket_value());
      else if  (conf.av_bracket_value && !(conf.override_disable==1 && conf.override_disable_all))
        gui_print_osd_state_string_chr("AV:", shooting_get_av_bracket_value());
      else if  (conf.iso_bracket_value && conf.iso_bracket_koef   && !(conf.override_disable==1 && conf.override_disable_all))
        gui_print_osd_state_string_int("ISO:", shooting_get_iso_bracket_value());
      else if  ((conf.subj_dist_bracket_value  && !(conf.override_disable==1 && conf.override_disable_all)) && (conf.subj_dist_bracket_koef) && (shooting_can_focus()))
        gui_print_osd_state_string_int("SD:",shooting_get_subject_distance_bracket_value());
     }
#ifdef OPT_CURVES
    if (conf.curve_enable || gui_mode==GUI_MODE_OSD) {
        if (conf.curve_enable==1) gui_print_osd_state_string_chr("CURVES:", "CSTM");
        else if (conf.curve_enable==4) gui_print_osd_state_string_chr("CURVES:", "AUTO");
        else if (conf.curve_enable==3) gui_print_osd_state_string_chr("CURVES:", "+2EV");
        else if (conf.curve_enable==2) gui_print_osd_state_string_chr("CURVES:", "+1EV");
    }
#endif
    if (conf.override_disable == 1) gui_print_osd_state_string_chr("NO ", "OVERRIDES");
    if (conf.flash_manual_override) gui_print_osd_state_string_chr("Flash:", "Manual Override");
#ifdef OPT_EDGEOVERLAY
    // edgeoverlay state
    if (conf.edge_overlay_enable || gui_mode==GUI_MODE_OSD) {
        if (edge_state_draw==0) gui_print_osd_state_string_chr("EDGE:", "LIVE");
        else if (edge_state_draw==1) gui_print_osd_state_string_chr("EDGE:", ((conf.edge_overlay_pano==0)?"FROZEN":"PANO"));
    }
#endif
#ifdef CAM_QUALITY_OVERRIDE
    // displaying the overriding picture quality if active
    if (!(conf.fast_image_quality==3) || gui_mode==GUI_MODE_OSD) {
        if (conf.fast_image_quality==0) gui_print_osd_state_string_chr("QUALI:", "super");
        else if (conf.fast_image_quality==1) gui_print_osd_state_string_chr("QUALI:", "fine");
        else if (conf.fast_image_quality==2) gui_print_osd_state_string_chr("QUALI:", "normal");
    }
#endif

/*
 draw_string(conf.mode_state_pos.x, conf.mode_state_pos.y+n, get_debug(), conf.osd_color);
        n+=FONT_HEIGHT;*/
}

//-------------------------------------------------------------------
void gui_osd_draw_values(int showtype) {
    int iso_mode=shooting_get_iso_mode();

    m=0;

    //gui_osd_calc_expo_param();

    if (conf.values_show_zoom) {
     int fl, zp=lens_get_zoom_point(), fl1=get_focal_length(zp);
     switch (conf.zoom_value) {
         case ZOOM_SHOW_FL:
             sprintf(osd_buf, "Z:%d.%dmm%8s", fl1/1000, fl1%1000/100, "");
             break;
         case ZOOM_SHOW_EFL:
             fl=get_effective_focal_length(zp);
             // scale by users adapter lens eg. Canon Wide .42 or Canon Tele 1.75
             fl = fl * conf.zoom_scale / 100;
             sprintf(osd_buf, "Z:%3dmm%8s", fl/1000, "");
             break;
         case ZOOM_SHOW_X:
         default:
             fl=get_zoom_x(zp);
             sprintf(osd_buf, "Z:%ld/%d.%dx%8s", zp, fl/10, fl%10, "");
             break;
     }
     osd_buf[9]=0;
     draw_string(conf.values_pos.x, conf.values_pos.y, osd_buf, conf.osd_color);
     m+=FONT_HEIGHT;
    }

    if ((conf.values_show_real_aperture) && (showtype==1))
         gui_print_osd_misc_string_float("Av :", "%d.%02d ", 100, shooting_get_real_aperture());
    short f_ex = (conf.show_dof==DOF_SHOW_IN_MISC_EX);
    if (((conf.show_dof==DOF_SHOW_IN_MISC) && (showtype)) || f_ex) {
      if (f_ex) gui_osd_calc_dof();
      if (conf.dof_subj_dist_in_misc) gui_print_osd_dof_string_dist("SD :", dof_values.subject_distance,
         f_ex && (dof_values.distance_valid || shooting_get_focus_mode()), 0);
      if (conf.dof_near_limit_in_misc) gui_print_osd_dof_string_dist("NL :", dof_values.near_limit,
         f_ex && dof_values.distance_valid, 0);
      if (conf.dof_far_limit_in_misc) gui_print_osd_dof_string_dist("FL :", dof_values.far_limit,
         f_ex && dof_values.distance_valid, 0);
      if (conf.dof_depth_in_misc) gui_print_osd_dof_string_dist("DOF:", dof_values.depth_of_field,
         f_ex && dof_values.distance_valid, 0);
      if (conf.dof_hyperfocal_in_misc) gui_print_osd_dof_string_dist("HYP:", dof_values.hyperfocal_distance,
         f_ex && dof_values.hyperfocal_valid, 1);
    }
    if (showtype==1) {
      if ((iso_mode <= 0) || !(conf.values_show_iso_only_in_autoiso_mode)) {
          if (conf.values_show_real_iso) gui_print_osd_misc_string_int("I-R:", expo.iso);
          if (conf.values_show_market_iso) gui_print_osd_misc_string_int("I-M:", expo.iso_market);
      }
      if (conf.values_show_bv_measured) gui_print_osd_misc_string_canon_values("Bvm:", expo.bv96_measured   );
      if (conf.values_show_bv_seted) gui_print_osd_misc_string_canon_values("Bvs:", expo.bv96_seted );
      if (conf.values_show_ev_measured) gui_print_osd_misc_string_canon_values("Evm:", expo.ev96_measured);
      if (conf.values_show_ev_seted ) gui_print_osd_misc_string_canon_values("Evs:", expo.ev96_seted    );
      if (conf.values_show_overexposure) gui_print_osd_misc_string_canon_values("dE :", expo.dev96);
      if (conf.values_show_canon_overexposure   ) gui_print_osd_misc_string_canon_values("dEc:", expo.dev96_canon);
      if (conf.values_show_luminance) gui_print_osd_misc_string_float("B  :", "%d.%02d ", 100, expo.b);

    }

}

#define CLOCK_FORMAT_24 0
#define CLOCK_FORMAT_12 1
#define CLOCK_WITHOUT_SEC 1
#define CLOCK_WITH_SEC 2

//-------------------------------------------------------------------
void gui_osd_draw_clock(int x, int y, color cl) {
    unsigned long t;
    static struct tm *ttm;
    int w = 0;
    int z;
    static char am[4];
    static char pm[4];
    static char curr[4];
    t = time(NULL);
    ttm = localtime(&t);
    unsigned int hour=(ttm->tm_hour);
    if (conf.clock_format == CLOCK_FORMAT_12) {
     switch(conf.clock_indicator)
      {
        case 1:
            sprintf(pm, "P");
            sprintf(am, "A");
            w = 1;
            break;
        case 2:
            sprintf(pm, ".");
            sprintf(am, " ");
            w = 1;
            break;
        default:
            sprintf(pm, " PM");
            sprintf(am, " AM");
            w = 3;
            break;
      }
     sprintf(curr,((hour>=12)?pm:am));
     if ((ttm->tm_hour)==00)  hour=12;
     else if ((ttm->tm_hour)>12)  hour=hour-12;
    }
    switch(conf.show_clock)
    {
      case CLOCK_WITHOUT_SEC:
        if (conf.clock_format == CLOCK_FORMAT_24)
          sprintf(osd_buf, "%2u:%02u", hour, ttm->tm_min);
        else
          sprintf(osd_buf, "%2u:%02u%s", hour, ttm->tm_min,curr);
        z=0;
        break;
      case CLOCK_WITH_SEC:
      default:
         if (conf.clock_format == CLOCK_FORMAT_24)
           sprintf(osd_buf, "%2u:%02u:%02u", hour, ttm->tm_min,ttm->tm_sec);
         else
           sprintf(osd_buf, "%2u:%02u:%02u%s", hour, ttm->tm_min,ttm->tm_sec,curr);
         z=3;
         break;
    }
    if ((conf.show_clock==CLOCK_WITH_SEC || (conf.clock_format==CLOCK_FORMAT_12)) && (conf.clock_pos.x>=(z+w)*FONT_WIDTH) )
       draw_string((x)?x-(z+w)*FONT_WIDTH:conf.clock_pos.x-(z+w)*FONT_WIDTH, (y)?y:conf.clock_pos.y, osd_buf, (cl)?cl:conf.osd_color);
    else
       draw_string((x)?x:conf.clock_pos.x, (y)?y:conf.clock_pos.y, osd_buf, (cl)?cl:conf.osd_color);
}


void gui_osd_draw_seconds() {
    unsigned long t;
    static struct tm *ttm;

    t = time(NULL);
    ttm = localtime(&t);
    sprintf(osd_buf, "%02u", ttm->tm_sec);
    if (conf.clock_pos.x<4*FONT_WIDTH){
    draw_string(conf.clock_pos.x, conf.clock_pos.y, osd_buf, conf.osd_color);
    }
    else
    {
    draw_string(conf.clock_pos.x+(3*FONT_WIDTH), conf.clock_pos.y, osd_buf, conf.osd_color);
    }


}

void gui_osd_draw_movie_time_left()  {

static int card_used, init_space, elapsed, avg_use, time_left;
static long init_time;
static int record_running = 0;
static int init = 0;
static unsigned int skipcalls = 1;
unsigned int hour=0, min=0, sec=0;
int mode_video = MODE_IS_VIDEO(m);


#if CAM_CHDK_HAS_EXT_VIDEO_MENU
if (mode_video || movie_status > 1) {
    // if manual adjust, show the field item to be adjusted
   // if any value overriden, show the override value
#if !CAM_VIDEO_QUALITY_ONLY
   if ((conf.video_mode == 0 && conf.fast_movie_quality_control==1) || conf.video_bitrate != VIDEO_DEFAULT_BITRATE) {
       // gui_print_osd_state_string_chr("Bitrate: ",video_bitrate_strings[conf.video_bitrate]);
       sprintf(osd_buf3, "Bit:%5s",video_bitrate_strings[conf.video_bitrate]);
       draw_string( conf.mode_video_pos.x, conf.mode_video_pos.y+2*FONT_HEIGHT, osd_buf3, conf.osd_color);
   }
#endif
   if ((conf.video_mode == 1 && conf.fast_movie_quality_control==1) || conf.video_quality != VIDEO_DEFAULT_QUALITY) {
       // gui_print_osd_state_string_int("Quality: ",conf.video_quality);
             sprintf(osd_buf4, "Qual:%2i",conf.video_quality);
       draw_string( conf.mode_video_pos.x, conf.mode_video_pos.y+3*FONT_HEIGHT, osd_buf4, conf.osd_color);
   }
   // everything else is for stills
     if(mode_video)
     return;
    }
#endif

if (movie_reset == 1)
    {
        init = 0;
        movie_reset = 0;
    }
    if (movie_status > 1) record_running = 1;
    else
    {record_running = 0;
    init = 0;
    }

    if (record_running == 1 && init == 0)
    {
    init = 1;
    init_space = GetFreeCardSpaceKb();
    init_time  = get_tick_count();
    }
    if (init == 1)
    {

    card_used = init_space - GetFreeCardSpaceKb();
    elapsed = (int) ( get_tick_count() - init_time ) / 1000;
    avg_use = card_used / elapsed;  // running average Kb/sec
    time_left = (GetFreeCardSpaceKb() / avg_use);
    hour = time_left / 3600;
    min = (time_left % 3600) / 60;
    sec = (time_left % 3600) % 60;

       if (elapsed<1)
   {
  sprintf(osd_buf, "Calc...");
   draw_string( conf.mode_video_pos.x, conf.mode_video_pos.y, osd_buf, conf.osd_color);
    }

   if (--skipcalls ==0) {
    if (elapsed>1)
     {
     if (conf.show_movie_time == 3){
      sprintf(osd_buf, "%04d KB/s", avg_use);
      draw_string( conf.mode_video_pos.x, conf.mode_video_pos.y, osd_buf, conf.osd_color);
      sprintf(osd_buf2, "-%02d:%02d:%02d", hour, min, sec);
      draw_string( conf.mode_video_pos.x, conf.mode_video_pos.y+FONT_HEIGHT, osd_buf2, conf.osd_color);
    }
     if (conf.show_movie_time == 2)
      {sprintf(osd_buf, "%04d KB/s", avg_use);
      draw_string( conf.mode_video_pos.x, conf.mode_video_pos.y, osd_buf, conf.osd_color);
    }
      if (conf.show_movie_time == 1)
       {
        sprintf(osd_buf, "-%02d:%02d:%02d", hour, min, sec);
        draw_string( conf.mode_video_pos.x, conf.mode_video_pos.y, osd_buf, conf.osd_color);
                }
#if CAM_CHDK_HAS_EXT_VIDEO_TIME
		if( (int)conf.ext_video_time == 1 )
		{
			draw_txt_string(0, 13, lang_str(LANG_WARN_VIDEO_EXT_TIME), conf.osd_color_warn);
		}		
#endif

      }

     skipcalls = conf.show_movie_refresh*5;
    }
    }
        }

void gui_osd_draw_ev() {
    static char *s[6]={"   ", "1/6", "1/3", "1/2", "2/3", "5/6"};
    short ev=shooting_get_prop(PROPCASE_EV_CORRECTION_1);
    if (ev/96 || (ev==0)) sprintf(osd_buf, "EV:  %d %s", abs(ev/96), s[abs(ev/16%6)]);
    else sprintf(osd_buf, "EV:  %s   ", s[abs(ev/16%6)]);
    if (ev>0) osd_buf[4]='+'; else if (ev<0) osd_buf[4]='-';
    draw_string(conf.mode_ev_pos.x, conf.mode_ev_pos.y, osd_buf, conf.osd_color);

}


void gui_osd_draw_temp() {
        if (conf.show_temp == 1)
            {
                if (conf.temperature_unit == 0)
                        {
                            sprintf(osd_buf," opt: %i�",get_optical_temp());
                        }
                else
                        {
                            sprintf(osd_buf,"opt: %i�",(get_optical_temp()*18+320)/10);
                        }
                draw_string(conf.temp_pos.x, conf.temp_pos.y, osd_buf, conf.osd_color);
            }
        if (conf.show_temp==2)
            {
                if (conf.temperature_unit == 0)
                        {
                            #ifdef CAM_HAS_CMOS
                                sprintf(osd_buf," CMOS: %i�", get_ccd_temp());
                            #else
                                sprintf(osd_buf," CCD: %i�", get_ccd_temp());
                            #endif
                        }
                else
                        {
                            #ifdef CAM_HAS_CMOS
                                sprintf(osd_buf,"CMOS: %i�",(get_ccd_temp()*18+320)/10);
                            #else
                                sprintf(osd_buf,"CCD: %i�",(get_ccd_temp()*18+320)/10);
                            #endif
                        }
                draw_string(conf.temp_pos.x, conf.temp_pos.y, osd_buf, conf.osd_color);
            }
        if (conf.show_temp==3)
            {
                if (conf.temperature_unit == 0)
                        {
                            sprintf(osd_buf," batt: %i�",get_battery_temp());
                        }
                else
                        {
                            sprintf(osd_buf,"batt: %i�",(get_battery_temp()*18+320)/10);
                        }
                draw_string(conf.temp_pos.x, conf.temp_pos.y, osd_buf, conf.osd_color);
            }
        if (conf.show_temp==4)
            {
                if (conf.temperature_unit == 0)
                    {
                        sprintf(osd_buf," opt:  %i�",get_optical_temp());
                        draw_string(conf.temp_pos.x, conf.temp_pos.y, osd_buf, conf.osd_color);
                        #ifdef CAM_HAS_CMOS
                            sprintf(osd_buf," CMOS: %i�",get_ccd_temp());
                        #else
                            sprintf(osd_buf," CCD: %i�",get_ccd_temp());
                        #endif
                        draw_string(conf.temp_pos.x, conf.temp_pos.y+FONT_HEIGHT, osd_buf, conf.osd_color);
                        sprintf(osd_buf," batt: %i�",get_battery_temp());
                        draw_string(conf.temp_pos.x, conf.temp_pos.y+2*FONT_HEIGHT, osd_buf, conf.osd_color);
                    }
            else
                    {
                        sprintf(osd_buf,"opt: %i�",(get_optical_temp()*18+320)/10);
                        draw_string(conf.temp_pos.x, conf.temp_pos.y, osd_buf, conf.osd_color);
                        #ifdef CAM_HAS_CMOS
                            sprintf(osd_buf,"CMOS: %i�",(get_ccd_temp()*18+320)/10);
                        #else
                            sprintf(osd_buf,"CCD: %i�",(get_ccd_temp()*18+320)/10);
                        #endif
                        draw_string(conf.temp_pos.x, conf.temp_pos.y+FONT_HEIGHT, osd_buf, conf.osd_color);
                        sprintf(osd_buf,"batt: %i�",(get_battery_temp()*18+320)/10);
                        draw_string(conf.temp_pos.x, conf.temp_pos.y+2*FONT_HEIGHT, osd_buf, conf.osd_color);
                    }
    }
}



//-------------------------------------------------------------------
#if CAM_EV_IN_VIDEO
void gui_osd_draw_ev_video(int visible){
 int x0=conf.ev_video_pos.x, y0=conf.ev_video_pos.y;
 int i, deltax;

 draw_filled_rect(x0,y0,x0+70,y0+24, visible? ((conf.osd_color&0xFF00))|(conf.osd_color>>8): COLOR_TRANSPARENT);

 if (!visible) { return; }

 for (i=0;i<9;i++) draw_line(x0+2+i*8,   y0+12, x0+2+i*8,   y0+12-(i&1 ? 5 : 10), conf.osd_color);
 for (i=0;i<9;i++) draw_line(x0+2+i*8+1, y0+12, x0+2+i*8+1, y0+12-(i&1 ? 5 : 10), conf.osd_color);

 deltax=8*get_ev_video();

 x0+=deltax;

 draw_line(x0+34,y0+16,x0+34,y0+22,conf.osd_color);
 draw_line(x0+35,y0+16,x0+35,y0+22,conf.osd_color);

 draw_line(x0+32,y0+19,x0+32,y0+22,conf.osd_color);
 draw_line(x0+33,y0+18,x0+33,y0+22,conf.osd_color);
 draw_line(x0+36,y0+18,x0+36,y0+22,conf.osd_color);
 draw_line(x0+37,y0+19,x0+37,y0+22,conf.osd_color);

}
#endif
