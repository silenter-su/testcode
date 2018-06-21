/*
 * =====================================================================================
 *
 *       Filename:  malloc_test.c
 *
 *    Description:  测试malloc崩溃.
 *
 *        Version:  1.0
 *        Created:  06/14/2018 06:54:06 PM
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
#include <stdint.h>

void main()
{
	uint8_t *test;
	test = calloc(1,sizeof(uint8_t));
	*test = 10;
	printf("num = %d\n",*test);
}
