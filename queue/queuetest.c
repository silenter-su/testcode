/*
 * =====================================================================================
 *
 *       Filename:  queuetest.c
 *
 *    Description:  测试内核链表.
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
#include <sys/queue.h>
  
  
#define REPEAT 500  
#define NOBJECTS 1000000  
  
// 在程序中如果我们想使用queue.h中提供的东西来  
// 简便地将自己的数据存储在队列中，就要定义如下的结构体:  
// 结构体中前面几项是自己的数据，最后一项是 TAILQ_ENTRY(..)...  
// 当然，如果最后一项根据自己选择的队列类型也可以是  
// SLIST_ENTRY或LIST_ENTRY或SIMPLEQ_ENTRY或CIRCLEQ_ENTRY  
struct object{  
    char anything[7]; // 这里我们自己的数据很简单，是字符数组  
    TAILQ_ENTRY(object) tailq_entry;  
};  
  
  
  
struct object objects[NOBJECTS];   
  
TAILQ_HEAD(,object) the_tailq;   // 定义TAILQ队列头(definations)  
  
static void test_tailq(){  
    int t;  
    puts("Testing TAILQ...");  
    for (t = 0; t < REPEAT; t++) {  
        int i;  
  
        for (i = 0; i < NOBJECTS; i++) {  
            TAILQ_INSERT_TAIL(&the_tailq, objects+i, tailq_entry);  
        }  
        for (i = 0; i < NOBJECTS; i++) {  
            TAILQ_REMOVE_HEAD(&the_tailq, tailq_entry);  
        }  
    }  
}  
  
  
int main(){  
  
	TAILQ_INIT(&the_tailq);          // 初始化TAILQ队列头(functions)  
    test_stailq();  
  
    return 0;  
}  
