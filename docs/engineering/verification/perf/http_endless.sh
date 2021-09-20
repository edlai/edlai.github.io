#!/bin/sh

# Monitor:
#   Monitor
#     $ sudo iftop

HOST='172.17.2.205'
FILE='test_1024m.zip'

i=0
rm -rf http_dl.log

while :
do
  echo "Do something; hit [CTRL+C][CTRL+D][CTRL+Z] to stop!"
  curl -vv http://${HOST}/ftp1/${FILE} > /dev/null
  i=$((i=i+1))
  echo "$i: $(date) | $(awk -v OFS=, '/eno1:/ { print $2, $10 }' /proc/net/dev)" >> http_dl.log
done

exit 0
