/*
 * =====================================================================================
 *
 *       Filename:  catstring_test.c
 *
 *    Description:  测试宏函数中的# ##连接字符串能不能在函数中使用.
 *
 *        Version:  1.0
 *        Created:  10/09/2018 04:27:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#if 0
#include <stdio.h>
#include <stdlib.h>

#define STR(s) #s
#define CAT(a,b) a##b

void main(void)
{
#if 0
	for(int i = 0; i < 10; i++) {
		printf("cat:---%s---\n",STR(i));
	}
#endif
	printf("---%s---\n",CAT(bac,888));
}
#endif




#include <stdio.h>
#include <stdlib.h>
 
#define STR(a) #a  //把a替换成一个“a”形式的字符串.

#define PRINTF pri##ntf  //link the two token together.  //合并两个token。
#define MYPRINTF(a,b,c) printf(#a"-"#b"-"#c"\n")


 
int main(void) {
	int tmp = 0;
	printf(STR(guoxu the nake name is gx)"\n");
	printf("11""22""33""\n"); //Yes,it works.
	PRINTF("AAAAAAAAA""\n");
	printf(""); //This line works.
	MYPRINTF(gx,wlp,gmx);
	/*
	tmp = CHAR(1);
	printf("The tmp value is %d",tmp);
	*/
	return 0;
}

