#/bin/bash

./sync_app.sh

scp -r root@192.168.1.30:/root/work/audit-integration/dpi-engine/build /root/work/audit-integration/dpi-engine

scp -r root@192.168.1.30:/root/work/audit-integration/dpi-engine/src-ext /root/work/audit-integration/dpi-engine/