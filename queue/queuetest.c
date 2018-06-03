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
  
struct tail_ql_entry   
{  
    TAILQ_ENTRY(tail_ql_entry) next;  
    int data;  
};  
  
TAILQ_HEAD(tail_list,tail_ql_entry);  
  
struct tail_list list1;  
  
int main()  
{  
  
    TAILQ_INIT(&list1);  
    printf("list1 is empty? %s.\n",TAILQ_EMPTY(&list1)? "YES":"NO");  
  
    struct tail_ql_entry * elm1 = malloc(sizeof(struct tail_ql_entry));  
    elm1->data = 0;  
    TAILQ_INSERT_HEAD(&list1,elm1,next);  
  
    struct tail_ql_entry * elm2 = malloc(sizeof(struct tail_ql_entry));  
    elm2->data = 1;  
    TAILQ_INSERT_AFTER(&list1,elm1,elm2,next);  
  
    struct tail_ql_entry *var = NULL;  
    TAILQ_FOREACH(var,&list1,next)  
    {  
        printf("foreach:%d\n",var->data);  
    }  
  
    TAILQ_FOREACH_REVERSE(var,&list1,tail_list,next)  
    {  
        printf("foreach_reverse:%d\n",var->data);  
    }  
  
    printf("elm1 next=%d\n",TAILQ_NEXT(elm1,next)->data);  
  
    printf("elm2 pre=%d\n",TAILQ_PREV(elm2,tail_list,next)->data);  
  
    printf("list1 is empty? %s.\n",TAILQ_EMPTY(&list1)? "YES":"NO");  
  
    TAILQ_REMOVE(&list1,elm1,next);  
    free(elm1);  
    TAILQ_REMOVE(&list1,elm2,next);  
    free(elm2);  
      
    printf("list1 is empty? %s.\n",TAILQ_EMPTY(&list1)? "YES":"NO");  
      
    return 0;  
}
