/*
 * =====================================================================================
 *
 *       Filename:  read_lua_conf.c
 *
 *    Description:  C语言读取lua语言配置信息测试代码.在lua脚本里面拿值.除了这个
 *    lua脚本还有什么其它的用处吗?
 *
 *        Version:  1.0
 *        Created:  07/20/2018 11:48:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <lua.hpp>
#include <lauxlib.h>
#include <lualib.h>

void load(lua_State* L, const char* fname, int* w, int* h) {
    if (luaL_loadfile(L,fname) || lua_pcall(L,0,0,0)) {
        printf("Error Msg is %s.\n",lua_tostring(L,-1));
        return;
    }
    lua_getglobal(L,"width");
    lua_getglobal(L,"height");
    if (!lua_isnumber(L,-2)) {
        printf("'width' should be a number\n" );
        return;
    }
    if (!lua_isnumber(L,-1)) {
        printf("'height' should be a number\n" );
        return;
    }
    *w = lua_tointeger(L,-2);
    *h = lua_tointeger(L,-1);
}


int main()
{
    lua_State* L = luaL_newstate();
    int w,h;
    load(L,"lua_conf",&w,&h);
    printf("width = %d, height = %d\n",w,h);
    lua_close(L);
    return 0;
}
