#ifndef LUASCRIPT_H
#define LUASCRIPT_H

#include "lua.h"

extern lua_State* L;
extern lua_State* Lt;

#define SET_STR_FIELD( KEY, VAL ) \
  lua_pushstring( L, VAL ); \
  lua_setfield( L, -2, KEY )

#define SET_INT_FIELD( KEY, VAL ) \
  lua_pushnumber( L, VAL ); \
  lua_setfield( L, -2, KEY )

#define SET_BOOL_FIELD( KEY, VAL ) \
  lua_pushboolean( L, VAL ); \
  lua_setfield( L, -2, KEY )

struct liblua_sym 
{
	int version;

    int (*lua_script_start)( char const* script,int is_ptp ); // initialize and load script
    void (*lua_script_run)( void ); // run script timeslice
    void (*lua_run_restore)( void );    // run the "restore" function at the end of a script
    void (*lua_script_reset)();
    void (*lua_set_variable)(int varnum, int value);

    void (*lua_pushnumber)(lua_Number n);
    void (*lua_pushlstring)(const char *s, size_t l);
    void (*lua_pushnil)();
    void (*lua_pushboolean)(int b);
};

extern struct liblua_sym* liblua;
extern struct liblua_sym* module_lua_load();		// 0fail, addr-ok
extern void module_lua_unload();

#endif
