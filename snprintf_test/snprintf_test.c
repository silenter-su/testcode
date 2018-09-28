/*
 * =====================================================================================
 *
 *       Filename:  snprintf_test.c
 *
 *    Description:  测试snprintf的C风格字符串处理.
 *
 *        Version:  1.0
 *        Created:  09/27/2018 02:45:39 PM
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



void main () 
{
	char alert_matched_key[2048] = { 0 };
	char *pmkey = alert_matched_key;
	
	int i = snprintf(alert_matched_key, sizeof(alert_matched_key),"apcitype\n");

	pmkey += i;
	printf("---%s---\n",alert_matched_key);
	printf("---%s---\n",pmkey);
	snprintf(pmkey, sizeof(alert_matched_key),"apcitype\n");





	int j = 1090;
	int b;

	char a[10] = { 0 };
	a[0] = ".";
	return;
}

