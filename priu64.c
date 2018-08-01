/*
 * =====================================================================================
 *
 *       Filename:  priu64.c
 *
 *    Description:  测试PRIu64宏.
 *
 *        Version:  1.0
 *        Created:  07/27/2018 07:28:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <inttypes.h>
#include <stdio.h>
int main()
{
    uint64_t t = 111111111111111142;
    printf("1. %d\n",t);
    printf("2. %lu\n",t);
    printf("3. " "%" PRIu64 "\n", t);
    return 0;
}

