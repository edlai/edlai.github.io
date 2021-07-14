#/bin/sh

echo out > /sys/class/gpio/gpio49/direction

while :
do
  echo "Press [CTRL+C] to stop.."
  echo "LED ON  -O-"
  echo 0 > /sys/class/gpio/gpio49/value
  sleep 1
  echo "LED OFF -X-"
  echo 1 > /sys/class/gpio/gpio49/value
  sleep 1
done

