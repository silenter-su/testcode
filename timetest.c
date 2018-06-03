/*
 * =====================================================================================
 *
 *       Filename:  timetest.c
 *
 *    Description:  实验转换时间函数.
 *
 *        Version:  1.0
 *        Created:  04/18/2018 01:09:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)  
{  
    time_t t;  
    t = time(NULL);  
    struct tm *lt;  
    int ii = time(&t);  
    printf("ii = %d\n", ii);  
    t = time(NULL);  
    lt = localtime(&t);  
    char nowtime[24];  
    memset(nowtime, 0, sizeof(nowtime));  
    strftime(nowtime, 24, "%Y-%m-%d %H:%M:%S", lt);  
    printf("nowtime = %s\n", nowtime);  
    return 1;  
}  

