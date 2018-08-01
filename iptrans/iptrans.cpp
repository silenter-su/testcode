/*
 * =====================================================================================
 *
 *       Filename:  iptrans.cpp
 *
 *    Description:  转换ip小例子.
 *
 *        Version:  1.0
 *        Created:  08/01/2018 10:57:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

//输入点分十进制的IP，将其转换成整型后，再反向转换进行验证
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>

using namespace std;

unsigned int IPtoInt(char *str_ip)
{
    in_addr addr;
    unsigned int int_ip;
    if(inet_aton(str_ip,&addr))
    {
        int_ip = ntohl(addr.s_addr);
    }
    return int_ip;
}

string IpToDot(unsigned int nIp){
    in_addr addr;
    addr.s_addr = htonl(nIp); 
    string strip = inet_ntoa(addr);
    if(!strip.empty()){
        return strip;
    }
    return NULL;
}

int main(int argc, char** argv)
{
	string DotIp;
	unsigned int a = 2148139018;
	
	cout <<IpToDot(a) << endl;
	
    for(int i = 1 ; i < argc ; ++i){
        unsigned int nIp = IPtoInt(argv[i]);
        cout<<nIp<<endl;
        cout<<IpToDot(nIp)<<endl;
    }
}
