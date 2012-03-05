#ifndef LUASCRIPT_H
#define LUASCRIPT_H

#include "lua.h"

void lua_script_reset();
int lua_script_start( char const* script,int is_ptp ); // initialize and load script
void lua_script_run( void ); // run script timeslice
void lua_script_error( lua_State* L,int runtime );
void lua_script_finish( lua_State* L );
extern void register_lua_funcs( lua_State* L );
// run the "restore" function at the end of a script
void lua_run_restore();

extern lua_State* L;
extern lua_State* Lt;

#endif

#define SET_STR_FIELD( KEY, VAL ) \
  lua_pushstring( L, VAL ); \
  lua_setfield( L, -2, KEY )

#define SET_INT_FIELD( KEY, VAL ) \
  lua_pushnumber( L, VAL ); \
  lua_setfield( L, -2, KEY )

#define SET_BOOL_FIELD( KEY, VAL ) \
  lua_pushboolean( L, VAL ); \
  lua_setfield( L, -2, KEY )

