#!/bin/bash

URL="http://speedtest.tele2.net/1GB.zip"
LOGFILE="curl.log"

rm -rf ${LOGFILE}
curl -L -o /dev/null "$URL" 2>&1  2>&1 | tee ${LOGFILE}
cat ${LOGFILE}
