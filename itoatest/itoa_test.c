/*
 * =====================================================================================
 *
 *       Filename:  itoa_test.c
 *
 *    Description:  测试itoa函数.
 *
 *        Version:  1.0
 *        Created:  10/09/2018 06:19:48 PM
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

int main(void)
{
	int a = 888899999;
	char string[25];
	sprintf(string,"%d",a);
	printf("%s\n",string);
	return 0;
}
