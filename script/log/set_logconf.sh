#!/bin/bash

#==========================================================
#
#		日志功能配置脚本
#	
#	Filename:		set_logconf.sh
#	
#	Description:	配置日志是否发送至远程服务器.
#	
#	Version:  1.0
#   Created:  03/22/2018 09:54:07 PM
#               
#  	Author:  苏明刚 (minggang.su@cy-tech.net), 
#   Organization:  cy-tech
#
#==========================================================

#公共变量(暂时写入系统syslog,如果将来日志量变大,有可能更改日志路径,独立文件提高解析速度.)
AUDITSYS_LOGPATH=/var/log/syslog.log
LOGCONF_PATH=/etc/rsyslog.conf

helpinfo() {
    echo "请输入参数:"
    echo "   -d 删除配置文件中的所有远程日志服务器IP地址."
    echo "   -a 向现有的配置文件中追加远程日志服务器IP地址."
    echo "   -u 以UDP方式向远程服务器发送日志."
    echo "   -t 以TCP方式向远程服务器发送日志."
    echo "   示例:$0 -u -a 192.168.1.1:514 "
}

#未写参数时退出.
if [ ! -n "$1" ]; then
	helpinfo
	exit 1
fi

#选项变量初始化为0.
opt_a=0
opt_u=0
opt_t=0

if [ ! -f "$LOGCONF_PATH" ]; then
	logger "日志配置文件不存在!"
else
	while getopts :a:dut OPTION;do
    case $OPTION in
    a)
		opt_a=1
		save_arg=$OPTARG
    ;;  
    u)
		opt_u=1
	;;
	t)
		opt_t=1
	;;
    d)
		#sed命令删除现有的远程服务器IP.
		sed -i '/@[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}/d' /etc/rsyslog.conf
    ;;  
    \?)
		helpinfo
		exit 1
    ;;  
    esac
	done
fi

#在man rsyslog.conf中有详细说明.发送方式为TCP使用'@@' UDP使用'@' .
if [ $opt_a -eq 1 ] ; then
	
	if [ $opt_u -eq 1 ] ; then
		echo "*.*		@$save_arg" >> $LOGCONF_PATH
	fi

	if [ $opt_t -eq 1 ] ;then
		echo "*.*		@@$save_arg" >> $LOGCONF_PATH
	fi

fi

#重启日志服务
systemctl restart rsyslog.service

exit 0
