/*
 * =====================================================================================
 *
 *       Filename:  test_constructor.c
 *
 *    Description:  测试GCC编译器编译特性关键词constructor和destructor.
 *
 *        Version:  1.0
 *        Created:  09/03/2018 04:11:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>


static void __attribute__((constructor)) pre_main1(void)
{
	printf("Come to %s\n", __func__);

}

static void __attribute__((constructor)) pre_main2(void)
{
	printf("Come to %s\n", __func__);

}

static void __attribute__((constructor)) pre_main3(void)
{
	printf("Come to %s\n", __func__);

}

int main(void)
{
	printf("Exiting.....\n");
	return 0;

}

static void __attribute__((destructor)) back_main1(void)
{
	printf("Come to %s\n", __func__);

}

static void __attribute__((destructor)) back_main2(void)
{
	printf("Come to %s\n", __func__);

}

