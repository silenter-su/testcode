/*
 * =====================================================================================
 *
 *       Filename:  add.c
 *
 *    Description:  试图在C语言中调用lua脚本,网上找的测试程序.
 *    网址:https://www.cnblogs.com/pied/archive/2012/10/26/2741601.html
 *    
 *
 *        Version:  1.0
 *        Created:  07/06/2018 03:45:35 PM
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

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>





/*the lua interpreter*/
lua_State* L;

int
main(int argc, char *argv[])
{
    int sum;
	/*initialize Lua*/
    L = luaL_newstate();

	/*load Lua base libraries*/
	luaL_openlibs(L);

	/*load the script*/
    luaL_dofile(L, "sayhello.lua");
	
    lua_getglobal(L,"printmsg"); /* 将状态机要执行的函数设置为printmsg. */

    lua_call(L, 0, 0); /*  执行printmsg函数. */


	/*cleanup Lua*/
    lua_close(L);
    return 0;
}

