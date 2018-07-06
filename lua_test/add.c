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




//add.c


/*the lua interpreter*/
lua_State* L;

int
luaadd(int x, int y)
{
        int sum;
/*the function name*/
        lua_getglobal(L,"add");
/*the first argument*/
        lua_pushnumber(L, x);
/*the second argument*/
        lua_pushnumber(L, y);
/*call the function with 2 arguments, return 1 result.*/
        lua_call(L, 2, 1);
/*get the result.*/
        sum = (int)lua_tonumber(L, -1);
/*cleanup the return*/
        lua_pop(L,1);
        return sum;
}

int
main(int argc, char *argv[])
{
        int sum;
/*initialize Lua*/
        L = luaL_newstate();
/*load Lua base libraries*/
        luaL_openlibs(L);
/*load the script*/
        luaL_dofile(L, "add.lua");
/*call the add function*/
        sum = luaadd(10, 15);
/*print the result*/
        printf("The sum is %d \n",sum);
/*cleanup Lua*/
        lua_close(L);
        return 0;
}

