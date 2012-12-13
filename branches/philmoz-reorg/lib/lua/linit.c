/*
** $Id: linit.c,v 1.14.1.1 2007/12/27 13:02:25 roberto Exp $
** Initialization of libraries for lua.c
** See Copyright Notice in lua.h
*/


#define linit_c
#define LUA_LIB

#include "lua.h"

#include "lualib.h"
#include "lauxlib.h"


static const luaL_Reg lualibs[] = {
  {"", (void*)luaopen_base},
  {LUA_LOADLIBNAME, (void*)luaopen_package},
  {LUA_TABLIBNAME, (void*)luaopen_table},
#ifdef OPT_LUA_IOLIB
  {LUA_IOLIBNAME, (void*)luaopen_io},
#endif
#ifdef OPT_LUA_OSLIB
  {LUA_OSLIBNAME, (void*)luaopen_os},
#endif
#ifdef OPT_LUA_STRLIB
  {LUA_STRLIBNAME, (void*)luaopen_string},
#endif
  {LUA_MATHLIBNAME, (void*)luaopen_math},
  {LUA_DBLIBNAME, (void*)luaopen_debug},
  {NULL, NULL}
};


LUALIB_API void luaL_openlibs (lua_State *L) {
  const luaL_Reg *lib = lualibs;
  for (; lib->func; lib++) {
    lua_pushcfunction(L, lib->func);
    lua_pushstring(L, lib->name);
    lua_call(L, 1, 0);
  }
}

