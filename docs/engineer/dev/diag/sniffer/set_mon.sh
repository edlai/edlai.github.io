#!/bin/sh
if [ $# -lt 2 ]; then
    echo "Usage: $0 [DEV_NAME] [CHANNEL]"
    exit 1
fi

dev=$1
ch=$2

sudo ifconfig ${dev} down
sudo iwconfig ${dev} mode monitor
sudo ifconfig ${dev} up
sudo iwconfig ${dev} channel ${ch}