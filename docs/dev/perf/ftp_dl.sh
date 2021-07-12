#!/bin/sh

# Precondition:
#   $ time dd if=/dev/urandom of=test_1024m.zip bs=1 count=0 seek=1G
# Monitor:
#   bwm-ng
#     $ sudo apt-get install bwm-ng
#     $ bwm-ng -I eno1 -u bits -d
#   speedometer
#     $ sudo apt-get install speedometer
#     $ speedometer -r eno1 -t eno1

HOST='ftp.speed.hinet.net'
USER='ftp'
PASSWD='ftp'
FILE='test_1024m.zip'

_ftp() {
  ftp -n $HOST <<END_SCRIPT
  quote USER $USER
  quote PASS $PASSWD
  passive
  bin
  hash
  get $FILE /dev/null
  quit
END_SCRIPT
}

while :
do
  echo "Do something; hit [CTRL+C] to stop!"
  _ftp
done

exit 0
