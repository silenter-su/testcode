/*
 * =====================================================================================
 *
 *       Filename:  macro_test.c
 *
 *    Description:  实验有参但不传参的宏.
 *
 *        Version:  1.0
 *        Created:  04/12/2018 09:18:21 AM
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

#define macrotest(f) do \
					{ \
						printf("in MACRO  !!!\n"); \
					} while(0);

#define DNP3_LINK_DIR(control) (control & 0x80)


void main() 
{
	int a;
	a = DNP3_LINK_DIR(0x80);
	printf("hello world!number is %d\n",a);
	macrotest();
	return;
}
