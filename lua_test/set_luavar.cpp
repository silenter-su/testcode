/*
 * =====================================================================================
 *
 *       Filename:  set_luavar.cpp
 *
 *    Description:  C给lua变量值,在lua中使用C设置的值.
 *
 *        Version:  1.0
 *        Created:  08/13/2018 11:36:56 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  

extern "C" { /* CPP中包含C代码. */
  #include "lua.h"  
  #include "lualib.h"  
  #include "lauxlib.h"  
};

int main(void)
{
	lua_State *L = luaL_newstate();

	if(luaL_loadfile(L,"Set_luavar.lua") || lua_pcall(L,0,0,0))
	{
		printf("cannot run config.file:%s",lua_tostring(L,-1));
	}
	luaL_openlibs(L);
	
	
	int iNum = 100;
	
	lua_pushnumber(L,iNum);
	lua_setglobal(L,"g_Num");
	lua_getglobal(L,"TestFun");
	lua_pcall(L,0,0,0);
	
	lua_close(L);
	return 0;
}
