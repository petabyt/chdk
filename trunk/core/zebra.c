#include "platform.h"
#include "zebra.h"
#include "conf.h"
#include "keyboard.h"
#include "stdlib.h"
#include "gui_draw.h"
#include "gui_menu.h"
#include "gui_lang.h"
#include "gui_osd.h"
#include "gui_batt.h"
#include "gui_space.h"

#include "modules.h"
#include "module_exportlist.h"

//-------------------------------------------------------------------

typedef struct
{
    color zebra_color;    // under/over
    int zebra_mode;
    int zebra_restore_screen;
    int zebra_restore_osd;
    int zebra_over;
    int zebra_under;
    int zebra_draw_osd;
    int zebra_multichannel;
} ZebraConf;

ZebraConf zconf;

static ConfInfo conf_info[] = {
    CONF_INFO( 1, zconf.zebra_color,            CONF_DEF_VALUE, cl:0, NULL),
    CONF_INFO( 2, zconf.zebra_mode,             CONF_DEF_VALUE, i:ZEBRA_MODE_BLINKED_2, NULL),
    CONF_INFO( 3, zconf.zebra_restore_screen,   CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO( 4, zconf.zebra_restore_osd,      CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO( 5, zconf.zebra_over,             CONF_DEF_VALUE, i:1, NULL),
    CONF_INFO( 6, zconf.zebra_under,            CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 7, zconf.zebra_draw_osd,         CONF_DEF_VALUE, i:ZEBRA_DRAW_HISTO, NULL),
    CONF_INFO( 8, zconf.zebra_multichannel,     CONF_DEF_VALUE, i:0, NULL),
};

//-------------------------------------------------------------------

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
static int cur_buf_size;
static int timer = 0;
static unsigned char *buf = NULL;

#ifdef CAM_ZEBRA_ASPECT_ADJUST
static int buffer_size;
#endif

unsigned char clip8(signed short x){ if (x<0) x=0; else if (x>255) x=255; return x; }

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
	unsigned i;

  if(show)
  {
    if (!buf)
    {
      timer = 0;
	  #if defined (CAM_ZEBRA_NOBUF)
        buffer_size=camera_screen.buffer_size-ZEBRA_HMARGIN0*camera_screen.buffer_width;
        buf=vid_get_bitmap_fb();
	  #elif defined (CAM_ZEBRA_ASPECT_ADJUST)
        buffer_size=camera_screen.buffer_size-ZEBRA_HMARGIN0*camera_screen.buffer_width;
        buf = malloc(buffer_size);
        //~ if (!buf) draw_txt_string(0, 14, "Warn: No space to allocate zebra buffer: restart camera", MAKE_COLOR(COLOR_ALT_BG, COLOR_FG));
        if (!buf)
          buf=vid_get_bitmap_fb(); //without new buffer: directly into screen buffer: we got some flickering in OSD and histogram but it's usable
        //~ msleep(50);
      #else
        buf = malloc(camera_screen.buffer_size);
      #endif
            scr_buf = vid_get_bitmap_fb();
#if ZEBRA_CANONOSD_BORDER_RESTORE
            cur_buf_top = malloc(camera_screen.buffer_width * ZFIX_TOP); 
            cur_buf_bot = malloc(camera_screen.buffer_width * ZFIX_BOTTOM); 
#if defined (CAM_ZEBRA_ASPECT_ADJUST)
            if (cur_buf_top) memset(cur_buf_top,0,camera_screen.buffer_width * ZFIX_TOP);
            if (cur_buf_bot) memset(cur_buf_bot,0,camera_screen.buffer_width * ZFIX_BOTTOM);
#endif
#else
            cur_buf = malloc(camera_screen.buffer_size);
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
				memset(buf,0,camera_screen.buffer_size);
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
#if ZEBRA_CANONOSD_BORDER_RESTORE
unsigned char get_cur_buf(unsigned int idx) {
    unsigned int a;
    
    a=camera_screen.buffer_size - camera_screen.buffer_width * ZFIX_BOTTOM;
    
    if (idx < camera_screen.buffer_width * ZFIX_TOP) return(cur_buf_top[idx]);
    if (idx >= a && idx < camera_screen.buffer_size) return(cur_buf_bot[idx - a]);
    return (COLOR_TRANSPARENT);
}
#endif

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
    unsigned char* buffer1 = vid_get_bitmap_fb()+camera_screen.buffer_size/2;
    unsigned char* buffer2 = buffer1+camera_screen.buffer_size;
    int has_disappeared=0;

    if(*buffer1!=COLOR_GREEN) has_disappeared=1;
    if(*buffer2!=COLOR_GREEN) has_disappeared=2;
    *buffer1 = *buffer2 = COLOR_GREEN;
    return has_disappeared;
}

//-------------------------------------------------------------------
static void gui_osd_draw_zebra_osd() {
    switch (zconf.zebra_draw_osd) {
        case ZEBRA_DRAW_NONE:
            break;
        case ZEBRA_DRAW_OSD:
            if (conf.show_osd) {
                draw_set_draw_proc(draw_pixel_buffered);
                if ((mode_get()&MODE_MASK) == MODE_REC) {
                    if (conf.show_dof != DOF_DONT_SHOW) gui_osd_calc_dof();
                    if (conf.show_grid_lines)
                        if (module_grids_load())
                            module_grids_load()->gui_grid_draw_osd(1);
                    if (conf.show_dof == DOF_SHOW_IN_DOF) {
                        gui_osd_draw_dof();
                    }
                    if (conf.show_state) {
                        gui_osd_draw_state();
                    }
                    if (conf.save_raw && conf.show_raw_state) {
                        gui_osd_draw_raw_info();
                    }
                    if (conf.show_values) {
                        gui_osd_draw_values();
                    }
                }
                gui_batt_draw_osd();
                gui_space_draw_osd();
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
//reyalp - applies to other cameras where the real bitmap width is is different from what lib.c reports. Also used on some other cameras ...
int gui_osd_draw_zebra(int show) {
    unsigned int v, s, x, y, f, over;
    color cl_under = BG_COLOR(zconf.zebra_color), cl_over = FG_COLOR(zconf.zebra_color);
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
    switch (zconf.zebra_mode) {
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
			memset(buf, COLOR_TRANSPARENT, viewport_yoffset*camera_screen.buffer_width);
			memset(buf+(viewport_yoffset+viewport_height)*camera_screen.buffer_width, COLOR_TRANSPARENT, viewport_yoffset*camera_screen.buffer_width);
		}
        int step_x, step_v, sy, sx;
        over = 255-zconf.zebra_over;
            if (zconf.zebra_multichannel) {step_x=2; step_v=6;} else {step_x=1; step_v=3;}
            for (y=viewport_yoffset, v=viewport_image_offset; y<viewport_yoffset+viewport_height; ++y) {
                sy=y*camera_screen.buffer_width;
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
                    if (zconf.zebra_multichannel) {
                        uu = (signed char)img_buf[v];
                        vv = (signed char)img_buf[v+2];
                        sel=0;
                        if (!((zconf.zebra_mode == ZEBRA_MODE_ZEBRA_1 || zconf.zebra_mode == ZEBRA_MODE_ZEBRA_2) && (y-x-timer)&f)) {
                            if (clip8(((yy<<12) +           vv*5743 + 2048)>>12)>over) sel  = 4; // R
                            if (clip8(((yy<<12) - uu*1411 - vv*2925 + 2048)>>12)>over) sel |= 2; // G
                            if (clip8(((yy<<12) + uu*7258           + 2048)>>12)>over) sel |= 1; // B
                        }
                        buf[s]=buf[s+1]=cls[sel];
                        buf[s+2]=buf[s+3]=cls[sel];
                    }
                    else if (((zconf.zebra_mode == ZEBRA_MODE_ZEBRA_1 || zconf.zebra_mode == ZEBRA_MODE_ZEBRA_2) && (y-x-timer)&f)) buf[s]=buf[s+1]=COLOR_TRANSPARENT;
                    else buf[s]=buf[s+1]=(yy>over)?cl_over:(yy<zconf.zebra_under)?cl_under:COLOR_TRANSPARENT;
                    if (buf[s] != COLOR_TRANSPARENT && !zebra_drawn) zebra_drawn = 1;
#if ZEBRA_CANONOSD_BORDER_RESTORE                        
                        if(get_cur_buf(s)!=COLOR_TRANSPARENT) buf[s]=get_cur_buf(s); 
                        if(zconf.zebra_multichannel && get_cur_buf(s+1)!=COLOR_TRANSPARENT) buf[s+1]=get_cur_buf(s+1); 
#else
                        if(cur_buf[s]!=COLOR_TRANSPARENT) buf[s]=cur_buf[s];
                        if(zconf.zebra_multichannel && cur_buf[s+1]!=COLOR_TRANSPARENT) buf[s+1]=cur_buf[s+1];
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
            if (zconf.zebra_restore_screen || zconf.zebra_restore_osd) {
                draw_restore();
            } else {  // clear buf[] of zebra, only leave Canon OSD
                if (mrec) { // REC mode
//~ #if ZEBRA_CANONOSD_BORDER_RESTORE
                    //~ // copy rescued Canon OSD to buf[] top/bottom parts and fill center with transparent color:
                    //~ memcpy(buf, cur_buf_top, camera_screen.buffer_width * ZFIX_TOP);
                    //~ memcpy(buf + camera_screen.buffer_size - camera_screen.buffer_width * ZFIX_BOTTOM, cur_buf_bot, camera_screen.buffer_width * ZFIX_BOTTOM);
                    //~ for (s = camera_screen.buffer_width*ZFIX_TOP; s < camera_screen.buffer_size-camera_screen.buffer_width*ZFIX_BOTTOM; s++) {
                        //~ buf[s]=COLOR_TRANSPARENT;
                    //~ }
//~ #else
                    //~ // copy from a complete Canon OSD rescue screen dump
                    //~ memcpy(buf, cur_buf, camera_screen.buffer_size); 
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
                  memcpy(scr_buf+camera_screen.buffer_size, buf, buffer_size);
            }
            need_restore=0;
        }
        return !(zconf.zebra_restore_screen && zconf.zebra_restore_osd);
    // if zebra was drawn
    } else {
        // draw CHDK osd and histogram to buf[] over zebra (if enabled in config)            
        gui_osd_draw_zebra_osd();
        // copy buf[] to both display buffers   
        if (buf!=scr_buf)
            memcpy(scr_buf, buf, buffer_size);
            memcpy(scr_buf+camera_screen.buffer_size, buf, buffer_size);

        need_restore=1;
        return 1;
    }
    return 0;
}
#else
//-------------------------------------------------------------------
int gui_osd_draw_zebra(int show) {
    unsigned int v, s, x, y, f, over;
    color cl_under = BG_COLOR(zconf.zebra_color), cl_over = FG_COLOR(zconf.zebra_color);
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
        //aspOffset = (camera_screen.width - (camera_screen.width * 12 / 16)) / 2; // = actual calculation, simplified below
        aspOffset = camera_screen.width / 8; // half of the difference in width between equal height 16:9 and 4:3 screens, = black bar width
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
            memcpy(cur_buf_top, scr_buf, camera_screen.buffer_width*ZFIX_TOP);
            memcpy(cur_buf_bot, scr_buf + camera_screen.buffer_size - camera_screen.buffer_width*ZFIX_BOTTOM, camera_screen.buffer_width*ZFIX_BOTTOM);
        }
        else {
            memcpy(cur_buf_top, scr_buf + camera_screen.buffer_size, camera_screen.buffer_width*ZFIX_TOP);
            memcpy(cur_buf_bot, scr_buf + 2*camera_screen.buffer_size - camera_screen.buffer_width*ZFIX_BOTTOM, camera_screen.buffer_width*ZFIX_BOTTOM);
        }
#else
        // rescue Canon OSD from cur_buf
        if(n==1) memcpy(cur_buf, scr_buf, camera_screen.buffer_size);
        else memcpy(cur_buf, scr_buf+camera_screen.buffer_size, camera_screen.buffer_size);
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
    switch (zconf.zebra_mode) {
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
        over = 255-zconf.zebra_over;
            if (zconf.zebra_multichannel) {step_x=2; step_v=6;} else {step_x=1; step_v=3;}
            s = aspOffset;
            for (y=1, v=0; y<=viewport_height; ++y) {
                for (x=0; x<camera_screen.width; x+=step_x, s+=step_x, v+=step_v) {
                    register int yy, uu, vv;
                    int sel;
										
                    if (!bWide && (x + aspOffset >= camera_screen.width - aspOffset)) continue; // do not draw "outside screen" 
										
                    yy = img_buf[v+1];
                    if (zconf.zebra_multichannel) {
                        uu = (signed char)img_buf[v];
                        vv = (signed char)img_buf[v+2];
                        sel=0;
                        if (!((zconf.zebra_mode == ZEBRA_MODE_ZEBRA_1 || zconf.zebra_mode == ZEBRA_MODE_ZEBRA_2) && (y-x-timer)&f)) {
                            if (clip8(((yy<<12) +           vv*5743 + 2048)>>12)>over) sel  = 4; // R
                            if (clip8(((yy<<12) - uu*1411 - vv*2925 + 2048)>>12)>over) sel |= 2; // G
                            if (clip8(((yy<<12) + uu*7258           + 2048)>>12)>over) sel |= 1; // B
                        }
                        buf[s]=buf[s+1]=cls[sel];
                    }
                    else if (((zconf.zebra_mode == ZEBRA_MODE_ZEBRA_1 || zconf.zebra_mode == ZEBRA_MODE_ZEBRA_2) && (y-x-timer)&f)) buf[s]=COLOR_TRANSPARENT;
                    else buf[s]=(yy>over)?cl_over:(yy<zconf.zebra_under)?cl_under:COLOR_TRANSPARENT;
                    if (buf[s] != COLOR_TRANSPARENT && !zebra_drawn) zebra_drawn = 1;
                    if (mrec) {
                        // draw Canon OSD to buf[] if in REC mode
#if ZEBRA_CANONOSD_BORDER_RESTORE                        
                        if(get_cur_buf(s)!=COLOR_TRANSPARENT) buf[s]=get_cur_buf(s); 
                        if(zconf.zebra_multichannel && get_cur_buf(s+1)!=COLOR_TRANSPARENT) buf[s+1]=get_cur_buf(s+1); 
#else
                        if(cur_buf[s]!=COLOR_TRANSPARENT) buf[s]=cur_buf[s];
                        if(zconf.zebra_multichannel && cur_buf[s+1]!=COLOR_TRANSPARENT) buf[s+1]=cur_buf[s+1];
#endif
                    }
                }
                s+=camera_screen.buffer_width-camera_screen.width;
                if (y*camera_screen.height/viewport_height == (s+camera_screen.buffer_width)/camera_screen.buffer_width) {
                    memcpy(buf+s, buf+s-camera_screen.buffer_width, camera_screen.buffer_width);
                    s+=camera_screen.buffer_width;
                }
            }
        if (!zebra_drawn) f=0;
    }
    // if blink mode is in no-zebra phase OR if there was no over/underexposed pixels to draw zebra on
    if (!f) {
        // if zebra was drawn during previous call of this function
        if (need_restore) {
            if (zconf.zebra_restore_screen || zconf.zebra_restore_osd) {
                draw_restore();
            } else {  // clear buf[] of zebra, only leave Canon OSD
                if (mrec) { // REC mode
#if ZEBRA_CANONOSD_BORDER_RESTORE
                    // copy rescued Canon OSD to buf[] top/bottom parts and fill center with transparent color:
                    memcpy(buf, cur_buf_top, camera_screen.buffer_width * ZFIX_TOP);
                    memcpy(buf + camera_screen.buffer_size - camera_screen.buffer_width * ZFIX_BOTTOM, cur_buf_bot, camera_screen.buffer_width * ZFIX_BOTTOM);
                    for (s = camera_screen.buffer_width*ZFIX_TOP; s < camera_screen.buffer_size-camera_screen.buffer_width*ZFIX_BOTTOM; s++) {
                        buf[s]=COLOR_TRANSPARENT;
                    }
#else
                    // copy from a complete Canon OSD rescue screen dump
                    memcpy(buf, cur_buf, camera_screen.buffer_size); 
#endif
                } else { // Not REC mode
                    // No Canon OSD restore, fill buf[] with transparent color:
                    memset(buf, COLOR_TRANSPARENT, camera_screen.buffer_size);
                }
                // draw CHDK osd and histogram to buf[] (if enabled in config)
                gui_osd_draw_zebra_osd();
                // copy buf[] to both display buffers
                memcpy(scr_buf, buf, camera_screen.buffer_size);
                memcpy(scr_buf+camera_screen.buffer_size, buf, camera_screen.buffer_size);
            }
            need_restore=0;
        }
        return !(zconf.zebra_restore_screen && zconf.zebra_restore_osd);
    // if zebra was drawn
    } else {
        // draw CHDK osd and histogram to buf[] over zebra (if enabled in config)            
        gui_osd_draw_zebra_osd();
        // copy buf[] to both display buffers          
        memcpy(scr_buf, buf, camera_screen.buffer_size);
        memcpy(scr_buf+camera_screen.buffer_size, buf, camera_screen.buffer_size);

        need_restore=1;
        return 1;
    }
    return 0;
}
#endif

//-------------------------------------------------------------------

void cb_zebra_restore_screen() {
    if (!zconf.zebra_restore_screen)
        zconf.zebra_restore_osd = 0;
}

void cb_zebra_restore_osd() {
    if (zconf.zebra_restore_osd)
        zconf.zebra_restore_screen = 1;
}

static const char* gui_zebra_mode_modes[] = { "Blink 1", "Blink 2", "Blink 3", "Solid", "Zebra 1", "Zebra 2" };
static const char* gui_zebra_draw_osd_modes[] = { "Nothing", "Histo", "OSD" };
static CMenuItem zebra_submenu_items[] = {
    MENU_ITEM(0x5c,LANG_MENU_ZEBRA_DRAW,              MENUITEM_BOOL,                            &conf.zebra_draw, 0 ),
    MENU_ENUM2(0x5f,LANG_MENU_ZEBRA_MODE,             &zconf.zebra_mode, gui_zebra_mode_modes ),
    MENU_ITEM(0x58,LANG_MENU_ZEBRA_UNDER,             MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,  &zconf.zebra_under,   MENU_MINMAX(0, 32) ),
    MENU_ITEM(0x57,LANG_MENU_ZEBRA_OVER,              MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX,  &zconf.zebra_over,    MENU_MINMAX(0, 32) ),
    MENU_ITEM(0x28,LANG_MENU_ZEBRA_RESTORE_SCREEN,    MENUITEM_BOOL|MENUITEM_ARG_CALLBACK,      &zconf.zebra_restore_screen,     cb_zebra_restore_screen ),
    MENU_ITEM(0x5c,LANG_MENU_ZEBRA_RESTORE_OSD,       MENUITEM_BOOL|MENUITEM_ARG_CALLBACK,      &zconf.zebra_restore_osd,        cb_zebra_restore_osd ),
    MENU_ENUM2(0x5f,LANG_MENU_ZEBRA_DRAW_OVER,        &zconf.zebra_draw_osd, gui_zebra_draw_osd_modes ),
    MENU_ITEM(0x5c,LANG_MENU_ZEBRA_MULTICHANNEL,      MENUITEM_BOOL,                            &zconf.zebra_multichannel, 0 ),
    MENU_ITEM(0x65,LANG_MENU_VIS_ZEBRA_UNDER,         MENUITEM_COLOR_BG,  &zconf.zebra_color, 0 ),
    MENU_ITEM(0x65,LANG_MENU_VIS_ZEBRA_OVER,          MENUITEM_COLOR_FG,  &zconf.zebra_color, 0 ),
    MENU_ITEM(0x51,LANG_MENU_BACK,                    MENUITEM_UP, 0, 0 ),
    {0}
};
static CMenu zebra_submenu = {0x26,LANG_MENU_ZEBRA_TITLE, NULL, zebra_submenu_items };


// =========  MODULE INIT =================

#include "module_load.h"
int module_idx=-1;

/***************** BEGIN OF AUXILARY PART *********************
  ATTENTION: DO NOT REMOVE OR CHANGE SIGNATURES IN THIS SECTION
 **************************************************************/

struct libzebra_sym libzebra = {
    MAKE_API_VERSION(1,0),		// apiver: increase major if incompatible changes made in module, 
							    // increase minor if compatible changes made(including extending this struct)
    gui_osd_draw_zebra
};


void* MODULE_EXPORT_LIST[] = {
	/* 0 */	(void*)EXPORTLIST_MAGIC_NUMBER,
	/* 1 */	(void*)1,

			&libzebra
		};


//---------------------------------------------------------
// PURPOSE:   Bind module symbols with chdk. 
//		Required function
// PARAMETERS: pointer to chdk list of export
// RETURN VALUE: 1 error, 0 ok
//---------------------------------------------------------
int _module_loader( unsigned int* chdk_export_list )
{
  if ( chdk_export_list[0] != EXPORTLIST_MAGIC_NUMBER )
     return 1;

  if ( !API_VERSION_MATCH_REQUIREMENT( conf.api_version, 2, 0 ) )
	 return 1;

  conf_info[0].cl = MAKE_COLOR(COLOR_RED, COLOR_RED);
  config_restore(&conf_info[0], "A/CHDK/MODULES/CFG/zebra.cfg", sizeof(conf_info)/sizeof(conf_info[0]), 0, 0);

  return 0;
}


//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{
    config_save(&conf_info[0], "A/CHDK/MODULES/CFG/zebra.cfg", sizeof(conf_info)/sizeof(conf_info[0]));
    gui_osd_zebra_free();
    return 0;
}


//---------------------------------------------------------
// PURPOSE: Default action for simple modules (direct run)
// NOTE: Please comment this function if no default action and this library module
//---------------------------------------------------------
int _module_run(int moduleidx, int argn, int* arguments)
{
  module_idx=moduleidx;

  gui_activate_sub_menu(&zebra_submenu, module_idx);

  return 0;
}

/******************** Module Information structure ******************/

struct ModuleInfo _module_info = {	MODULEINFO_V1_MAGICNUM,
									sizeof(struct ModuleInfo),

									ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
									ANY_PLATFORM_ALLOWED,		// Specify platform dependency
									MODULEINFO_FLAG_SYSTEM,		// flag
									(int32_t)"Zebra Overlay (dll)",// Module name
									1, 0,						// Module version
									(int32_t)"Zebra Overlay"
};


/*************** END OF AUXILARY PART *******************/

