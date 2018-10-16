/*
 * =====================================================================================
 *
 *       Filename:  strtest.c
 *
 *    Description:  main1测试宏+字符串在赋值给char型指针时,是否会被拼接.
 *    main2测试指针数组初始化.
 *    main3 测试结构体数组能不能在初始化时赋值全0
 *
 *        Version:  1.0
 *        Created:  10/12/2018 11:15:35 AM
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


#define AAA "hello"



typedef struct foo_ {

	int a;
	char b;
} foo;

#if 1

void main(void) {

	char *c = "you are not a lazy man";

	char* b = c " world\n";

	printf("%s",b);

}

#endif

#if 0

void main(void) {

	char *b[10] = {0};

//	printf("%s",b);
	return;

}


#endif

#if 0
void main(void) {

	char *b[10] = {0};
	foo test[10] = {0};

//	printf("%s",b);
	return;

}

#endif
