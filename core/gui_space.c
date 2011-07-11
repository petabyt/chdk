#include "stdlib.h"
#include "keyboard.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "gui.h"
#include "gui_draw.h"
#include "gui_batt.h"
#include "gui_space.h"
//-------------------------------------------------------------------

static char osd_buf[32];

//-------------------------------------------------------------------

unsigned long get_space_perc() {
    return GetFreeCardSpaceKb()*100/GetTotalCardSpaceKb();
}

static void gui_space_draw_spacebar_horizontal() {
    coord x;
    register coord xx, yy;
    
    xx = conf.space_hor_pos.x;
    yy = conf.space_hor_pos.y;

    color cl = conf.space_color;
    int perc = get_space_perc(),height = 2;
    int size = 0;
    if (conf.space_warn_type == 0) {
        cl = (perc<=conf.space_perc_warn)?conf.osd_color_warn:(conf.space_color);
    }
    if (conf.space_warn_type == 1) {
        cl = (GetFreeCardSpaceKb()/1024<=conf.space_mb_warn)?conf.osd_color_warn:(conf.space_color);
    }
    if (conf.space_warn_type == 2) {
        cl = conf.space_color;
    }
    // space icon / bar
    height = conf.space_bar_width+1;
    if (conf.space_bar_size == 0) {
        size = screen_width/4-4;
        if (xx>(screen_width-size)) {
            xx = screen_width-size;
        }
    }
    if (conf.space_bar_size == 1) {
        size = screen_width/2-4;
        if (xx>(screen_width-size)) {
            xx = screen_width-size;
        }
    }
    if (conf.space_bar_size == 2) {
        size = screen_width-4;
        if (xx>(screen_width-size)) {
            xx = 0;
        }
    }
    if (yy > (screen_height-height-3)) {
        yy = screen_height-height-3;
    }
    draw_rect(xx+1,    yy+1,     xx+1+size+2, yy+1+height+1,  cl);
    draw_vline(xx+1-1,    yy+1-1, 1+height+2, COLOR_BLACK);  // l
    draw_hline(xx+1-1,    yy+1-1,   1+size+3, COLOR_BLACK);  // t
    draw_hline(xx+1-1,    yy+1+height+2,  1+size+3, COLOR_BLACK);  // b
    draw_vline(xx+1+size+3, yy+1-1,  1+height+2,  COLOR_BLACK);  // r

    // space bar fill

    x = xx + size - ((perc*size)/100);
    if (x<=xx+1) x=xx+1;
    if (x>xx+size) x=xx+size;
    draw_filled_rect(xx+1+1, yy+1+1, x-1, yy+1+height, MAKE_COLOR(COLOR_TRANSPARENT, COLOR_BLACK));
    draw_filled_rect(x, yy+1+1, xx+1+size+2, yy+1+height, MAKE_COLOR(cl, cl));
}

static void gui_space_draw_spacebar_vertical() {
    coord y;
    register coord xx, yy;
    
    xx = conf.space_ver_pos.x;
    yy = conf.space_ver_pos.y;

    color cl = conf.space_color;
    int perc = get_space_perc(), width = 2;
    int size = 0;
    if (conf.space_warn_type == 0) {
        cl = (perc<=conf.space_perc_warn)?conf.osd_color_warn:(conf.space_color);
    }
    if (conf.space_warn_type == 1) {
        cl = (GetFreeCardSpaceKb()/1024<=conf.space_mb_warn)?conf.osd_color_warn:(conf.space_color);
    }
    if (conf.space_warn_type == 2) {
        cl = conf.space_color;
    }

    // space icon / bar
    width = conf.space_bar_width+1;
    if (conf.space_bar_size == 0) {
        size = screen_height/4-4;
        if (yy>(screen_height-size)) {
            yy = screen_height-size;
        }
    }
    if (conf.space_bar_size == 1) {
        size = screen_height/2-4;
        if (yy>(screen_height-size)) {
            yy = screen_height-size;
        }
    }
    if (conf.space_bar_size == 2) {
        size = screen_height-4;
        if (yy>(screen_height-size)) {
            yy = 0;
        }
    }
    if (xx > (screen_width-width-3)) {
        xx = screen_width-width-3;
    }
    draw_rect(xx+1,    yy+1,     xx+1+width+1, yy+1+size+2,  cl);
    draw_vline(xx+1-1,    yy+1-1, 1+5, COLOR_BLACK);   // l
    draw_hline(xx+1-1,    yy+1-1, 1+width+2, COLOR_BLACK);   // t
    draw_hline(xx+1-1,    yy+1+size+3, 1+width+2, COLOR_BLACK);   // b
    draw_vline(xx+1+width+2, yy+1-1,   1+size+3,  COLOR_BLACK);   // r

    // space bar fill
    y = yy + size - ((perc*size)/100);
    if (y<=yy+1) y=yy+1;
    if (y>yy+size) y=yy+size;
    draw_filled_rect(xx+1+1, yy+1+1, xx+1+width, y-1, MAKE_COLOR(COLOR_TRANSPARENT, COLOR_BLACK));
    draw_filled_rect(xx+1+1, y, xx+1+width, yy+1+size+2, MAKE_COLOR(cl, cl));
}

static void gui_space_draw_icon() {
    coord x;
    register coord xx, yy;
    
    xx = conf.space_icon_pos.x;
    yy = conf.space_icon_pos.y;

    color cl = conf.space_color;
    int perc = get_space_perc();
    if (conf.space_warn_type == 0) {
        cl = (perc<=conf.space_perc_warn)?conf.osd_color_warn:(conf.space_color);
    }
    if (conf.space_warn_type == 1) {
        cl = (GetFreeCardSpaceKb()/1024<=conf.space_mb_warn)?conf.osd_color_warn:(conf.space_color);
    }
    if (conf.space_warn_type == 2) {
        cl = conf.space_color;
    }
    int i;
#define LE  23
#define WI  15
//    int le = 23;    // length
//    int wi = 15;    // width

    draw_hline(xx+5,      yy,      LE-5,     COLOR_BLACK);          // outer top
    draw_hline(xx+6,      yy+1,    LE-7,     MAKE_COLOR(cl, cl));   // inner top
    draw_vline(xx,        yy+5,    WI-5,     COLOR_BLACK);          // outer left
    draw_vline(xx+1,      yy+6,    WI-7,     MAKE_COLOR(cl, cl));   // inner left
    draw_hline(xx,        yy+WI,   LE,       COLOR_BLACK);          // outer bottom
    draw_hline(xx+1,      yy+WI-1, LE-2,     MAKE_COLOR(cl, cl));   // inner bottom
    draw_vline(xx+LE,     yy,      WI,       COLOR_BLACK);          // outer right
    draw_vline(xx+LE-1,   yy+1,    WI-2,     MAKE_COLOR(cl, cl));   // inner right
    draw_line(xx+5,      yy,       xx,        yy+5,     COLOR_BLACK);          // edge
    draw_line(xx+5,      yy+1,     xx+1,      yy+5,     MAKE_COLOR(cl, cl));   // edge
    draw_line(xx+6,      yy+1,     xx+1,      yy+6,     MAKE_COLOR(cl, cl));   // edge

    // memory fill
    x = LE - (perc*(LE-3)/100) - 2;
    if (x>5) draw_hline(xx+6,      yy+2,     x-6,     COLOR_BLACK);
    if (x>2) draw_hline(xx+x+1,    yy+2,     LE-x-3,  MAKE_COLOR(cl, cl));
    else     draw_hline(xx+4,      yy+2,     LE-6,    MAKE_COLOR(cl, cl));
    for(i=3; i<7; i++) {                                                                                                     //          /--------------|
        if (x>7-i) draw_pixel(xx+8-i,     yy+i,     COLOR_BLACK);                      //        /  1st for loop  |
        if (x>7-i) draw_pixel(xx+x,       yy+i,     COLOR_BLACK);                      //      /__________________|
        draw_hline(xx+x+1,                 yy+i,     LE-x-3,    MAKE_COLOR(cl, cl));   //     |                   |
    }                                                                                                                        //     |     2nd for loop  |
    for(i=7; i<WI-2; i++) {                                                                                                  //     |                   |
        if (x>1) draw_pixel(xx+2,         yy+i,     COLOR_BLACK);                      //     |-------------------|
        if (x>1) draw_pixel(xx+x,         yy+i,     COLOR_BLACK);
        draw_hline(xx+x+1,                 yy+i,     LE-x-3,    MAKE_COLOR(cl, cl));
    }
    if (x>1) draw_hline(xx+2,      yy+WI-2,    x-2,     COLOR_BLACK);
    draw_hline(xx+x+1,             yy+WI-2,    LE-x-3,  MAKE_COLOR(cl, cl));
}

//-------------------------------------------------------------------
static void gui_space_draw_percent() {
    int perc = get_space_perc();
    color cl = conf.space_color;
    if (conf.space_warn_type == 0) {
        cl = (perc<=conf.space_perc_warn)?conf.osd_color_warn:(conf.space_color);
    }
    if (conf.space_warn_type == 1) {
        cl = (GetFreeCardSpaceKb()/1024<=conf.space_mb_warn)?conf.osd_color_warn:(conf.space_color);
    }
    if (conf.space_warn_type == 2) {
        cl = conf.space_color;
    }
    sprintf(osd_buf, "%3d%%", get_space_perc());
    osd_buf[5]=0;
    draw_string(conf.space_txt_pos.x, conf.space_txt_pos.y, osd_buf, cl);
}

//-------------------------------------------------------------------
static void gui_space_draw_mb() {
    int perc = get_space_perc();
    color cl = conf.space_color;
    if (conf.space_warn_type == 0) {
        cl = (perc<=conf.space_perc_warn)?conf.osd_color_warn:(conf.space_color);
    }
    if (conf.space_warn_type == 1) {
        cl = (GetFreeCardSpaceKb()/1024<=conf.space_mb_warn)?conf.osd_color_warn:(conf.space_color);
    }
    if (conf.space_warn_type == 2) {
        cl = conf.space_color;
    }
    unsigned int freemb=GetFreeCardSpaceKb()/1024;
    if (freemb < 10000) sprintf(osd_buf, "%3d%M",freemb);
    else sprintf(osd_buf, "%3d%G",freemb/1024);   // if 10 GiB or more free, print in GiB instead of MiB
    osd_buf[5]=0;
    draw_string(conf.space_txt_pos.x, conf.space_txt_pos.y, osd_buf, cl);
}

//-------------------------------------------------------------------

void gui_space_draw_osd() {
    if (conf.space_icon_show) {
        gui_space_draw_icon();
    }
    if (conf.space_perc_show) {
        gui_space_draw_percent();
    } else if (conf.space_mb_show) {
        gui_space_draw_mb();
    }
    if (conf.space_bar_show==1) {
        gui_space_draw_spacebar_horizontal();
    }
    if (conf.space_bar_show==2) {
        gui_space_draw_spacebar_vertical();
    }
}
