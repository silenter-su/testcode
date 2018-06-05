/*
 * =====================================================================================
 *
 *       Filename:  queuetest.c
 *
 *    Description:  测试DEBUG宏. 使用make命令来编译此文件.
 *    使用make debugtest 打印NO Debug...
 *    使用make CFLAGS=-DDEBUG debugtest会启动DEBUG宏.打印Debug...
 *    引出问题:gcc和环境变量的关系.
 *			make命令和makefile的理解.
 *			automake的理解.
 *
 *        Version:  1.0
 *        Created:  06/03/2018 04:30:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  smg
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
  

int main()
{


#ifdef DEBUG
	printf("Debug...\n");
#else
	printf("No Debug...\n");
#endif

    return 0;
}
