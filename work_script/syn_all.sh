#/bin/bash

mkdir -p /home/smg/works/dpi-engine
scp root@192.168.1.30:/home/smg/works/dpi-engine/build/suricata/src/.libs/suricata /usr/local/bin/suricata
scp -r root@192.168.1.30:/home/smg/works/dpi-engine/build /home/smg/works/dpi-engine

scp -r root@192.168.1.30:/home/smg/works/dpi-engine/src-ext /home/smg/works/dpi-engine/
