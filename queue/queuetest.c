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
#include <stdlib.h>
  
#include <sys/queue.h>
  
/* 定义队列成员节点结构体,其中包含的宏就是定义这个结构体本身的向后指针和指向前一个成员的指针,
 * 但是这个指针正好落在前一个成员的next上,所以解引用后就是目前结构体的指针. */
struct tail_ql_entry
{
    TAILQ_ENTRY(tail_ql_entry) next;
    int data;
};

/* 定义链表头结构体. */
TAILQ_HEAD(tail_list,tail_ql_entry); 

/* 声明一个链表头. */
struct tail_list list1;

int main()
{

	/* 初始化链表头. */
    TAILQ_INIT(&list1);
    printf("list1 is empty? %s.\n",TAILQ_EMPTY(&list1)? "YES":"NO");

	/*  内核链表使用时只能把数据分配在堆上. */
    struct tail_ql_entry * elm1 = malloc(sizeof(struct tail_ql_entry));
    elm1->data = 0;
	/* 使用头插法.新插入的结构体在链表最前边(不包含链表头,链表头独立于整个链表结构). */
    TAILQ_INSERT_HEAD(&list1,elm1,next);

	/* 分配第二个成员. */
    struct tail_ql_entry * elm2 = malloc(sizeof(struct tail_ql_entry));
    elm2->data = 1;

	/* 指定插入位置.可以指定插在哪个成员后. */
    TAILQ_INSERT_AFTER(&list1,elm1,elm2,next);

	/* 用一个成员指针拿到每个数据的内容.顺序遍历. */
    struct tail_ql_entry *var = NULL;
    TAILQ_FOREACH(var,&list1,next)
    {
        printf("foreach:%d\n",var->data);
    }

	/* 拿到成员值,从后往前,倒序遍历. */
    TAILQ_FOREACH_REVERSE(var,&list1,tail_list,next)
    {
        printf("foreach_reverse:%d\n",var->data);
    }

    printf("elm1 next=%d\n",TAILQ_NEXT(elm1,next)->data);

    printf("elm2 pre=%d\n",TAILQ_PREV(elm2,tail_list,next)->data);

    printf("list1 is empty? %s.\n",TAILQ_EMPTY(&list1)? "YES":"NO");

	/* 移除成员,并释放内存,项目中一般是成员里面就有释放函数? */
    TAILQ_REMOVE(&list1,elm1,next);
    free(elm1);
    TAILQ_REMOVE(&list1,elm2,next);
    free(elm2);

    printf("list1 is empty? %s.\n",TAILQ_EMPTY(&list1)? "YES":"NO");



#ifdef DEBUG
	printf("Debug...\n");
#else
	printf("No Debug...\n");
#endif

    return 0;
}
