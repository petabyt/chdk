/*
functions for operating on raw framebuffer from script hooks
*/
#include "camera_info.h"
#include "stdlib.h"
#include "conf.h"
#include "raw.h"
#include "math.h"

#include "../lib/lua/lualib.h"
#include "../lib/lua/lauxlib.h"

extern void set_number_field(lua_State *L, const char *name, int value);

// TODO not really the same for R,G,B
// raw value of a neutral exposure, including black level
unsigned raw_neutral;
// log2(raw_neutral - blacklevel), i.e. the range of significant raw values
static double log2_raw_neutral_count; 

// offsets of bayer elements from an even pixel coordinate
// [r,g,g,b][x,y]
unsigned cfa_offsets[4][2];
const char *cfa_names[]={"r","g1","g2","b"};
#define CFA_R 0
#define CFA_G1 1
#define CFA_G2 2
#define CFA_B 3

static void set_rect_field(lua_State *L, const char * name, int x1, int y1, int x2, int y2) {
    lua_createtable(L, 0, 4);
    // not clear if we want corners, width/height or both
    set_number_field(L,"x1",x1);
    set_number_field(L,"y1",y1);
    set_number_field(L,"x2",x2);
    set_number_field(L,"y2",y2);
    lua_setfield(L, -2, name);
}

// TODO maybe this should just go into the rawop table?
static int rawop_fb_info(lua_State *L) {
    lua_createtable(L, 0, 9);
    set_number_field(L,"width",camera_sensor.raw_rowpix);
    set_number_field(L,"height",camera_sensor.raw_rows);
    set_number_field(L,"bits_per_pixel",camera_sensor.bits_per_pixel);
    // TODO may want to use a more friendly format
    set_number_field(L,"cfa_pattern",camera_sensor.cfa_pattern);
    set_number_field(L,"black_level",camera_sensor.black_level);
    set_number_field(L,"white_level",camera_sensor.white_level);
    set_number_field(L,"raw_neutral",(int)raw_neutral);
    // not clear if we want corners, width/height or both
    set_rect_field(L,"active_area",
        camera_sensor.active_area.x1,
        camera_sensor.active_area.y1,
        camera_sensor.active_area.x2,
        camera_sensor.active_area.y2);
    // jpeg size area, not use selected default crop
    // in absolute coordinates
    set_rect_field(L,"jpeg_area",
        camera_sensor.active_area.x1 + camera_sensor.jpeg.x,
        camera_sensor.active_area.y1 + camera_sensor.jpeg.y,
        camera_sensor.active_area.x1 + camera_sensor.jpeg.x + camera_sensor.jpeg.width,
        camera_sensor.active_area.y1 + camera_sensor.jpeg.y + camera_sensor.jpeg.height
    );
    lua_createtable(L, 0, 4);
    int i;
    for(i=0;i<4;i++) {
        lua_createtable(L, 0, 2);
        set_number_field(L,"x",cfa_offsets[i][0]);
        set_number_field(L,"y",cfa_offsets[i][1]);
        lua_setfield(L, -2, cfa_names[i]);
    }
    lua_setfield(L, -2, "cfa_offsets");
    return 1;
}

/*
v=rawop.get_pixel(x,y)
returns raw value, or nil if out of bounds
*/
static int rawop_get_pixel(lua_State *L) {
  	unsigned x=luaL_checknumber(L,1);
  	unsigned y=luaL_checknumber(L,2);
    // TODO return nil for out of bounds
    // might not want to check, or return 0, or error()?
    if(x >= (unsigned)camera_sensor.raw_rowpix || y >= (unsigned)camera_sensor.raw_rows) {
        return 0;
    }
    // TODO could check if in raw hook
    lua_pushnumber(L,get_raw_pixel(x,y));
    return 1;
}

/*
rawop.set_pixel(x,y,v)
sets pixel to v
*/
static int rawop_set_pixel(lua_State *L) {
  	unsigned int x=luaL_checknumber(L,1);
  	unsigned int y=luaL_checknumber(L,2);
  	unsigned short v=luaL_checknumber(L,3);
    // TODO
    // might want to or error()?
    if(x >= (unsigned)camera_sensor.raw_rowpix || y >= (unsigned)camera_sensor.raw_rows) {
        return 0;
    }
    // TODO could check if in raw hook
    // TODO could check v
    set_raw_pixel(x,y,v);
    return 0;
}

/*
r,g1,b,g2=rawop.get_pixels_rgbg(x,y)
returns the values of the CFA quad containing x,y or nil if out of bounds
x and y are truncated to the nearest even value.
*/
static int rawop_get_pixels_rgbg(lua_State *L) {
  	unsigned int x=luaL_checknumber(L,1);
  	unsigned int y=luaL_checknumber(L,2);

	x &= 0xFFFFFFFE;
	y &= 0xFFFFFFFE;

    if(x >= (unsigned)camera_sensor.raw_rowpix || y >= (unsigned)camera_sensor.raw_rows) {
        return 0;
    }
    lua_pushnumber(L,get_raw_pixel(x+cfa_offsets[CFA_R][0],y+cfa_offsets[CFA_R][1]));
    lua_pushnumber(L,get_raw_pixel(x+cfa_offsets[CFA_G1][0],y+cfa_offsets[CFA_G1][1]));
    lua_pushnumber(L,get_raw_pixel(x+cfa_offsets[CFA_B][0],y+cfa_offsets[CFA_B][1]));
    lua_pushnumber(L,get_raw_pixel(x+cfa_offsets[CFA_G2][0],y+cfa_offsets[CFA_G2][1]));
    return 4;
}

/*
rawop.set_pixels_rgbg(x,y,r,g1,b[,g2])
sets the values of the CFA quad containing x,y
if g2 is not specified, it is set to g1
x and y are truncated to the nearest even value.
*/
static int rawop_set_pixels_rgbg(lua_State *L) {
  	unsigned int x=luaL_checknumber(L,1);
  	unsigned int y=luaL_checknumber(L,2);
  	unsigned short r=luaL_checknumber(L,3);
  	unsigned short g1=luaL_checknumber(L,4);
  	unsigned short b=luaL_checknumber(L,5);
  	unsigned short g2=luaL_optnumber(L,6,g1);

	x &= 0xFFFFFFFE;
	y &= 0xFFFFFFFE;

    if(x >= (unsigned)camera_sensor.raw_rowpix - 1 || y >= (unsigned)camera_sensor.raw_rows - 1) {
        return 0;
    }
    set_raw_pixel(x+cfa_offsets[CFA_R][0],y+cfa_offsets[CFA_R][1],r);
    set_raw_pixel(x+cfa_offsets[CFA_G1][0],y+cfa_offsets[CFA_G1][1],g1);
    set_raw_pixel(x+cfa_offsets[CFA_B][0],y+cfa_offsets[CFA_B][1],b);
    set_raw_pixel(x+cfa_offsets[CFA_G2][0],y+cfa_offsets[CFA_G2][1],g2);
    return 0;
}
/*
rawop.fill_rect_rgbg(x,y,width,height,r,g1,b[,g2])
fills the specified rectangle with the specified r,g,b values
if g2 is not specified, it is set to g1
x, y, width and height are truncated to the nearest even value.
width and hight out of bounds are clipped
*/

static int rawop_fill_rect_rgbg(lua_State *L) {
  	unsigned int xstart=luaL_checknumber(L,1);
  	unsigned int ystart=luaL_checknumber(L,2);
  	unsigned int width=luaL_checknumber(L,3);
  	unsigned int height=luaL_checknumber(L,4);
    unsigned int vals[4];
    vals[CFA_R]=luaL_checknumber(L,5);
    vals[CFA_G1]=luaL_checknumber(L,6);
    vals[CFA_B]=luaL_checknumber(L,7);
    vals[CFA_G2]=luaL_optnumber(L,8,vals[CFA_G1]);
    // clamp to even
    xstart = xstart & 0xFFFFFFFE;
    ystart = ystart & 0xFFFFFFFE;
    width = width & 0xFFFFFFFE;
    height = height & 0xFFFFFFFE;
    unsigned int xmax = xstart + width;
    unsigned int ymax = ystart + height;
    int x,y;
    if(xstart >= (unsigned)camera_sensor.raw_rowpix || ystart >= (unsigned)camera_sensor.raw_rows) {
        return 0;
    }
    if(xmax > (unsigned)camera_sensor.raw_rowpix) {
        xmax = (unsigned)camera_sensor.raw_rowpix; 
    }
    if(ymax > (unsigned)camera_sensor.raw_rows) {
        ymax = (unsigned)camera_sensor.raw_rows;
    }
    int i;
    // TODO setting full rows would probably be faster
    for(i=0; i<4; i++) {
        unsigned short c=vals[i];
        for(y=ystart+cfa_offsets[i][1]; y<ymax; y+=2) {
            for(x=xstart+cfa_offsets[i][0]; x<xmax; x+=2) {
                set_raw_pixel(x,y,c);
            }
        }
    }
    return 0;
}

/*
ev96=rawop.raw_to_ev96(rawval)
convert a raw value (blacklevel+1 to whitelevel) into an APEX96 EV relative to neutral
if rawval is <= to blacklevel, it is clamped to blacklevel.
values > whitelevel are converted normally
*/
static int rawop_raw_to_ev96(lua_State *L) {
    int v=luaL_checknumber(L,1);
    // TODO not clear what we should return, minimum real value for now
    if( v <= camera_sensor.black_level) {
        v = camera_sensor.black_level+1;
    }
    int r=96.0*(log2(v - camera_sensor.black_level) - log2_raw_neutral_count);
    lua_pushnumber(L,r);
    return 1;
}

/*
rawval=rawop.ev96_to_raw(ev96)
Convert an APEX96 EV (offset from raw_neutral) to a raw value. No range checking is done
*/
static int rawop_ev96_to_raw(lua_State *L) {
    int v=luaL_checknumber(L,1);
    // TODO not clear if this should be clamped to valid raw ranges?
    lua_pushnumber(L,pow(2,(double)v/96+log2_raw_neutral_count)+camera_sensor.black_level);
    return 1;
}

/*
mean_raw_val=rawop.meter(x,y,x_count,y_count,x_step,y_step)
return the average values of count pixels in x and y, sampled at step size step,
or nil if the range is invalid or the total number of pixels could result in overflow

To prevent overflow, the total number of pixels must less unsigned_max / white_level.
Limits are roughly 
10 bpp = 4 Mpix
12 bpp = 1 Mpix
14 bpp = 256 Kpix
To meter larger numbers of pixels, use multiple calls and average the results

To meter R G B separately, use multiple meter calls with the appropriate CFA offset and even steps
To ensure all CFA colors are included in a single call, use odd steps
*/
static int rawop_meter(lua_State *L) {
  	unsigned x1=luaL_checknumber(L,1);
  	unsigned y1=luaL_checknumber(L,2);
  	unsigned x_count=luaL_checknumber(L,3);
  	unsigned y_count=luaL_checknumber(L,4);
  	unsigned x_step=luaL_checknumber(L,5);
  	unsigned y_step=luaL_checknumber(L,6);

    // no pixels
    if(!x_count || !y_count) {
        return 0;
    }

    unsigned x_max = x1 + x_step * x_count;
    unsigned y_max = y1 + y_step * y_count;
    // x out of range
    if(x_max > (unsigned)camera_sensor.raw_rowpix) {
        return 0;
    }
    // y out of range
    if(y_max > (unsigned)camera_sensor.raw_rows) {
        return 0;
    }
    // overflow possible (int max)/total  < max value 
    if(x_count*y_count > (unsigned)0xFFFFFFFF >> camera_sensor.bits_per_pixel) {
        return 0;
    }
    unsigned t=0;
    unsigned x,y;
    for(y = y1; y < y_max; y += y_step) {
        for(x = x1; x < x_max; x += x_step) {
            t+=get_raw_pixel(x,y);
        }
    }
    lua_pushnumber(L,t/(x_count*y_count));
    return 1;
}

static const luaL_Reg rawop_funcs[] = {
  {"fb_info", rawop_fb_info},
  {"get_pixel", rawop_get_pixel},
  {"set_pixel", rawop_set_pixel},
  {"get_pixels_rgbg", rawop_get_pixels_rgbg},
  {"set_pixels_rgbg", rawop_set_pixels_rgbg},
  {"fill_rect_rgbg", rawop_fill_rect_rgbg},
  {"raw_to_ev96", rawop_raw_to_ev96},
  {"ev96_to_raw", rawop_ev96_to_raw},
  {"meter", rawop_meter},
  {NULL, NULL}
};

int luaopen_rawop(lua_State *L) {
    // initialize globals
    int i;
    int g1=1;
	for(i=0; i<4; i++) {
		int c = (camera_sensor.cfa_pattern >> 8*i) & 0xFF;
        int ci=0;
        switch(c) {
            case 0:
                ci=0;
            break;
            case 1:
                if(g1) {
                    ci=1;
                    g1=0;
                } else {
                    ci=2;
                }
            break;
            case 2:
                ci=3;
            break;
        }
        cfa_offsets[ci][0] = i&1;
        cfa_offsets[ci][1] = (i&2)>>1;
    }

    // emperical guestimate
    double raw_neutral_count = (double)(camera_sensor.white_level - camera_sensor.black_level)/(6.669);
    log2_raw_neutral_count = log2(raw_neutral_count);
    // cast to int to avoid missing __fixunsdfsi assigning to unsigned
    raw_neutral = (int)(raw_neutral_count + camera_sensor.black_level);
	/* global lib*/
	lua_newtable(L);
	luaL_register(L, "rawop", rawop_funcs);  
	return 1;
}
