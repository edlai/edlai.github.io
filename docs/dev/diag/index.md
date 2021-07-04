
# Diagnostic Tools

## Wireshare

Download and install Wireshark from Internet. If you would like to capture Wireless packets in Linux OS, you may need to find a suitable WiFi dongle which can support monitor mode. For `Debian 10.10`, becasue its Linux Kernel version is 4.x, you might consider to upgrade to Linux Kernel 5.x which can support more WiFi dongles. There are the steps as following to upgrade Linux Kernel from 4.x to 5.x in Debian 10.10. 

### Upgrade Linux Kernel to support Wi-Fi dongle 

In my case, I choose [`debian-live-10.10.0-amd64-xfce.iso`](https://cdimage.debian.org/debian-cd/current-live/amd64/iso-hybrid/)

- Check the current Linux Kernel version, it's `4.19.x` now.
```console
$ sudo uname -a
config-4.19.0-17-amd64
```

- Upgrade the essential packages
```console
$ sudo apt-get update && sudo apt-get upgrade
$ sudo apt-get install -y build-essential libncurses-dev bison flex libssl-dev libelf-dev
$ sudo apt-get install -y git fakeroot ncurses-dev xz-utils bc
$ sudo apt-get install -y software-properties-common rsync
$ sudo apt-get install -y libncurses5-dev gcc grub2 wget
```

- Add apt repository to support `linux-image-5.10.x`
``` console
$ sudo add-apt-repository 'deb http://deb.debian.org/debian buster-backports main'
$ sudo apt-get update
$ sudo apt-get install linux-image-5.10.0-0.bpo.7-amd64
$ sudo apt-get install firmware-misc-nonfree (Optional)
$ sync; sudo reboot
```

- After rebooted. Check current Linux version to make sure its `Linux Kernel 5.10`
``` console
$ uname -a
Linux vultr.guest 5.10.0-0.bpo.7-amd64 #1 SMP Debian 5.10.40-1~bpo10+1 (2021-06-04) x86_64 GNU/Linux
```

### Check Wi-Fi channel and so on

- Insert Wi-Fi dongle and confirm Interface name. The PID/VID is `0e8d:7612`. and the interface name is `wlx008e86000266` now.
```
$ lsusb
Bus 002 Device 003: ID 0e8d:7612 MediaTek Inc.

$ sudo ifconfig
wlx008e86000266: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
        ether 1e:a4:80:77:09:f3  txqueuelen 1000  (Ethernet)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
```

install `aircrack-ng` to check Wi-Fi channel. 

```
$ wget https://github.com/aircrack-ng/aircrack-ng/archive/refs/tags/1.6.tar.gz
$ tar xvf 1.6.tar.gz 
$ cd aircrack-ng-1.6
$ ./autogen.sh 
$ ./configure 
$ make
$ sudo make install
$ sudo airodump-ng wlx008e86000266
CH  2 ][ Elapsed: 0 s ][ 2021-07-04 12:03 

 BSSID              PWR  Beacons    #Data, #/s  CH   MB   ENC CIPHER  AUTH ESSID

 C4:E9:0A:2F:03:A2  -52        2        0    0   6  130   WPA2 CCMP   PSK  AccessPoint1                               
 C4:E9:0A:01:71:FA  -43        2        0    0   6  130   WPA2 CCMP   PSK  AccessPoint1                               

  BSSID              STATION            PWR   Rate    Lost    Frames  Notes  Probes

 84:0B:7C:5C:FC:BE  D8:42:AC:08:D3:14  -63    0 - 1e     0        1                                           
 BE:4F:DA:40:92:33  94:7B:E7:0B:E5:1A  -78    0 - 0e     0        7 
```

### Enable Monitor Mode

- Enable Monitor Mode 

```
$ ifconfig wlan0 down
$ iwconfig wlan0 mond monitor
$ ifconfig wlan0 up
$ ifconfig channel 1
```

### Run Wireshark and set filter  

```
wlan.addr[4:2] == 8f:c6 and (wlan.fc.type_subtype <3 || wlan.fc.type ==2)
```

### IE element

try to add new IE element and confirm again

~~ TBD ~~
## tshark


~~ TBD ~~

## tcpdump

```
$ sudo apt-get install tcpdump
```
### VLAN packets

VLAN belongs to layer2, use below command to dump VLAN packets

```
$ sudo tcpdump -i enp0s25 -en -XX
```

### PPPoE packets

`0x8863` and `0x8864` 

```
$ sudo tcpdump -i enpos25 -en -XX ether[0x0c:2]==0x8863 or ether[0x0c:2]==0x8864
```

## Qualcomm QxDM

~~ TBD ~~
## MTK Catcher

~~ TBD ~~