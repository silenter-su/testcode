#!/usr/bin/expect
set timeout 30  
spawn scp root@192.168.1.30:/root/work/audit-integration/dpi-engine/build/suricata/src/.libs/suricata /usr/local/bin/suricata
expect "password:"
send "cy888888\r\n"
sleep 10
chmod 777 /usr/local/bin/suricata
