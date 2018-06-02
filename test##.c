#include <stdio.h>


/* 在宏定义中,#是把传递进来的参数当成字符串来替换.##是用来联接两个子串.*/
/* token##n被联成了变量token9, 传入的9被联接成了smg9. */

#define a(n) printf("smg" #n "=%d\n",token##n)

void main()
{
	int token9 = 90;

	a(9);
}
