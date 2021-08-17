# RaspAP (Draft)

Download and program to SD card.
(Raspberry Pi OS with desktop)[https://www.raspberrypi.org/software/operating-systems/#raspberry-pi-os-32-bit]

## Precondition

USB boot
https://codychen.me/2020/27/%E6%8A%8A-raspberry-pi-%E7%95%B6%E6%88%90-wifi-ap/

``` sh
# Show disk information
diskutil list

# Unmount the hard drive to be burned
diskutil unmount /dev/diskN

# Burn the hard drive
sudo dd bs=1m if={IMG Path}  of=/dev/rdiskN; sync

# Burn Finnish
diskutil eject /dev/rdiskN
```

Enable Raspberry pi 3 uart
https://www.slideshare.net/raspberrypi-tw/raspberry-pi-iot-bluetooth

/boot/config.txt

``` sh
core_freq=250
enable_uart=1
dtoverlay=pi3-miniuart-bt
dtoverlay=disable-bt
```

