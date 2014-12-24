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

// raw value of a neutral exposure
// TODO should probably be R,G,B
static double raw_neutral, log2_raw_neutral; 

static void set_rect_field(lua_State *L, const char * name, int x1, int y1, int x2, int y2) {
    lua_createtable(L, 0, 4);
    // not clear if we want corners, width/height or both
    set_number_field(L,"x1",x1);
    set_number_field(L,"y1",y1);
    set_number_field(L,"x2",x2);
    set_number_field(L,"y2",y2);
    lua_setfield(L, -2, name);
}

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
    return 1;
}

static int rawop_get_pixel(lua_State *L) {
  	unsigned x=luaL_checknumber(L,1);
  	unsigned y=luaL_checknumber(L,2);
    // TODO return nil for out of bounds
    // might not want to check, or return 0, or error()?
    if(x >= (unsigned)camera_sensor.raw_rowpix || y > (unsigned)camera_sensor.raw_rows) {
        lua_pushnil(L);
        return 1;
    }
    // TODO could check if in raw hook
    lua_pushnumber(L,get_raw_pixel(x,y));
    return 1;
}

static int rawop_set_pixel(lua_State *L) {
  	unsigned int x=luaL_checknumber(L,1);
  	unsigned int y=luaL_checknumber(L,2);
  	unsigned short v=luaL_checknumber(L,3);
    // TODO
    // might want to or error()?
    if(x >= (unsigned)camera_sensor.raw_rowpix || y > (unsigned)camera_sensor.raw_rows) {
        return 0;
    }
    // TODO could check if in raw hook
    // TODO could check v
    set_raw_pixel(x,y,v);
    return 0;
}

static int rawop_raw_to_ev96(lua_State *L) {
    int v=luaL_checknumber(L,1);
    // TODO not clear what we should return, minimum real value for now
    if( v <= camera_sensor.black_level) {
        v = camera_sensor.black_level+1;
    }
    int r=96.0*(log2(v - camera_sensor.black_level) - log2_raw_neutral);
    lua_pushnumber(L,r);
    return 1;
}

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
  {"raw_to_ev96", rawop_raw_to_ev96},
  {"meter", rawop_meter},
  {NULL, NULL}
};

int luaopen_rawop(lua_State *L) {
    // initialize globals
    // emperical guestimate
    raw_neutral = (double)(camera_sensor.white_level - camera_sensor.black_level)/(6.669);
    log2_raw_neutral = log2(raw_neutral);
	/* global lib*/
	lua_newtable(L);
	luaL_register(L, "rawop", rawop_funcs);  
	return 1;
}
