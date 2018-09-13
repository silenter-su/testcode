/*
 * =====================================================================================
 *
 *       Filename:  strsep_test.c
 *
 *    Description:  测试strsep函数在使用两个字符作为delim时的效果.
 *
 *        Version:  1.0
 *        Created:  09/13/2018 11:00:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 *
 *   结论:关键词为一个字符.如果strsep的第一个参数delime是个字符串的话,那么每个字符都是关键词.
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main()
{
	char str[] = "eeeeeeeeeeeeeeeecbbbbbbbbbbbbbbbbduuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuucdaaaaaaaaaaaaaaaaaaaabcdefg";
	char *p = str;
	char *key_point = NULL;
	while(p)
	{
		while ( key_point = strsep(&p,"cd"))//关键字为c或d，它们连续出现了
		{
			//函数遇到c时，key_point指向c返回，遇到d时key_point指向d返回（注意此时d已经被改写为'\0'了）
			if (*key_point == 0)
				continue;//遇到连续的关键字，返回一个指向\0的指针，继续往后找就是
			else
			break;//分割出一个正常的字符串，快去打印吧！
		}
		printf("%s\n",key_point);
	}
}
