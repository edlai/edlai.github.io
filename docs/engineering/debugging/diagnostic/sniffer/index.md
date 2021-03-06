# Wireless Sniffer -Wireshark

This chapter introduces how to capture Wi-Fi traffic in Ubuntu 20.10.

## Install Ubuntu

Download `Ubuntu 20.10` from [Ubuntu Website](https://www.ubuntu-tw.org/). Install to a USB dongle or a Disk.

Check the current Linux Kernel version. It's `5.8.x` now.

``` sh
$ uname -a
Linux ed-ThinkPad-X230 5.8.0-59-generic #66-Ubuntu SMP Thu Jun 17 00:46:01 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux
```

## Install Wireshark and some applications

``` sh
$ sudo rm -rf /bin/sh && sudo ln -s /bin/bash /bin/sh
$ sudo apt-get update && sudo apt-get upgrade
$ sudo apt-get install -y openssh-server vim net-tools wireshark
$ sudo apt-get install -y build-essential libncurses-dev bison flex libssl-dev libelf-dev
$ sudo apt-get install -y git fakeroot ncurses-dev xz-utils bc libtool
$ sudo apt-get install -y software-properties-common rsync
$ sudo apt-get install -y libncurses5-dev gcc grub2 wget dwarves tree curl
```

## Plug Wi-Fi dongle

Plug Wi-Fi dongle and confirm its interface name. The PID/VID is `0e8d:7612` for this MediaTek Wi-Fi dongle in this case.

``` sh
$ lsusb
Bus 002 Device 003: ID 0e8d:7612 MediaTek Inc.
```

And the current interface name is `wlx008e86000266` now.

``` sh
$ sudo ifconfig
wlx008e86000266: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
        ether 1e:a4:80:77:09:f3  txqueuelen 1000  (Ethernet)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
```

## Scan Wi-Fi Channel

Install `aircrack-ng` and run `airodump-ng` to check Wi-Fi channel. It's better to use `aircrack-ng 1.6` which is able to support WPA3-SAE.

``` sh
$ git clone https://github.com/aircrack-ng/aircrack-ng.git
$ cd aircrack-ng
$ ./autogen.sh
$ ./configure
$ make
$ sudo make install
$ sudo ldconfig
```

Run `airodump-ng`. it seems SSID `AP1` works on `Channel 13`.

``` sh
$ sudo airodump-ng wlx008e86000266

 CH  8 ][ Elapsed: 12 s ][ 2021-07-05 19:24 ][ Are you sure you want to quit? Press Q again to quit.

 BSSID              PWR  Beacons    #Data, #/s  CH   MB   ENC CIPHER  AUTH ESSID
 C4:E9:0A:6F:A5:1A  -20       12        0    0  13  270   WPA2 CCMP   PSK  AP1

 BSSID              STATION            PWR   Rate    Lost    Frames  Notes  Probes
 C4:E9:0A:2F:03:A2  40:31:3C:D1:BD:C9  -41    0 - 6      0        1
```



<!--
PS. try to use `gcc 9` if `gcc 10` cannot compile `aircrack-ng`.

- [?????????Ubuntu 18.04?????????GCC?????????](https://www.myfreax.com/how-to-install-gcc-compiler-on-ubuntu-18-04/)

```console
$ sudo apt install gcc-9; sudo apt install g++-9
$ sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 90 --slave /usr/bin/g++ g++ /usr/bin/g++-9 --slave /usr/bin/gcov gcov /usr/bin/gcov-9
$ sudo update-alternatives --config gcc
$ gcc -v
gcc version 9.3.0 (Ubuntu 9.3.0-18ubuntu1)
```

Back to Gcc10

```console
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 100 --slave /usr/bin/g++ g++ /usr/bin/g++-10 --slave /usr/bin/gcov gcov /usr/bin/gcov-10
```
-->

### Enable Monitor Mode

- Enable Monitor Mode, use below script ([Download](set_mon.sh)) to press

`$ ./set_mon.sh ${INTERFACE_NAME} ${WIFI_CHANNEL}`

``` sh
$ set_mon.sh wlx008e86000266 13

--8<--
docs/engineer/dev/diag/sniffer/set_mon.sh
--8<--
```

### Run Wireshark

- Run Wireshark
- Select Menu/View/Wireless Toolbar
- Set Filter to display beacon Frame. there is a sample filter if you would like to capture.

Filter:

Consider to below case to capture below traffices.

- MAC address: C4:E9:0A:6F:A5:1A
- Association Req/Rep
- Reassociation Req/Rep
- Probe Req/Rep
- Beacon ((wlan.fc.type_subtype <= 0x0008))
- Four way handshark (wlan.fc.type == 0x0002)

User needs to put below combination to the Filter rule.

``` sh
wlan.addr[4:2] == A5:1A and (wlan.fc.type_subtype < 0x0005 || wlan.fc.type == 0x0002)
```

## User Case

Try to add new IE Element to Realtek Wi-Fi platform and confirm its beacon frame did include the new IE Element from Wireshark.

### Vendor Specific IEEE 802.11 Information Element

Use below script to run `./set_ie.sh "000a00" "01234567"` adding new MTK IE element to Realtek AP.

set_ie.sh

``` sh
#!/bin/sh
if [ $# -lt 1 ]; then
    echo "Usage: $0 [OUI] [CONTENT]"
    exit 1
fi

oui=$1
content=$2

echo "set IE"
echo "  - OUI:      $oui"
echo "  - CONTENT:  $content"

iwpriv wlan1 setCIE ${oui},${content}

echo "Set WLAN IE done"
```

There is what we saw from Wireshark (Click `Packet` ??? `Copy` ??? `All Visible Selected Tree Items`)

```console
Tag: Vendor Specific: Mediatek Corp.
    Tag Number: Vendor Specific (221)
    Tag length: 10
    OUI: 00:0a:00 (Mediatek Corp.)
    Vendor Specific OUI Type: 48
    Vendor Specific Data: 30313233343536
```

## References

- Wireshark & Ethereal Network Protocol Analyzer Toolkit/CH6-Wireless Sniffing with Wireshark
- Network Analysis Using Wireshark Cookbook
- [802.11AX REMOTE PACKET CAPTURES USING THE JETSON NANO](https://semfionetworks.com/blog/80211ax-remote-packet-captures-using-the-jetson-nano/)
- [????????????Wi-Fi 6??????????????????Nvidia Jetson Nano ??????Intel AX200](https://blog.xmr.tw/2020/10/18/%e6%9c%80%e4%be%bf%e5%ae%9c%e7%9a%84ax200%e5%97%85%e6%8e%a2%e5%99%a8%ef%bc%8cnvidia-jetson-nano-%e5%ae%89%e8%a3%9dintel-ax200/#comment-16)

<!--

## tshark

Install

```console
$ sudo apt-get install tshark
```

Command to capture Beacon frame

```console
$ sudo tshark -i wlx008e86000266 -f "type mgt subtype beacon"
```

## tcpdump

Install tcpdump

```console
$ sudo apt-get install tcpdump
```
### VLAN packets

VLAN belongs to layer2, use below command to dump VLAN packets

- `-e`: Prints the link-level header on each dump line.
- `-n`:	Blocks converting the host addresses, and the port numbers to names.
- `-X`:	Prints each packet (minus its link level header) in hexadecimal and ASCII. This is very handy for analyzing new protocols.

```console
$ sudo tcpdump -i enp0s25 -en -XX
```

### PPPoE packets

- `0x8863`: PPPoE Discovery Stage
- `0x8864`: PPPoE Session Stage

```console
$ sudo tcpdump -i enp0s25 -en -XX ether[0x0c:2]==0x8863 or ether[0x0c:2]==0x8864
```

## Qualcomm QxDM

~~ TBD ~~
## MTK Catcher

~~ TBD ~~
-->
## Appendix

### Wireless Display Filter Reference

- [Wireshark Most Common 802.11 Filters v1.1
](https://semfionetworks.com/wp-content/uploads/2021/04/wireshark_802.11_filters_-_reference_sheet.pdf)

| Frame Name                 | Field Name                     |
|----------------------------|--------------------------------|
| Management frame           | wlan.fc.type == 0              |
| Control frame              | wlan.fc.type == 1              |
| Data frame                 | wlan.fc.type == 2              |
| Association request        | wlan.fc.type_subtype == 0x00   |
| Association response       | wlan.fc.type_subtype == 0x01   |
| Reassociation request      | wlan.fc.type_subtype == 0x02   |
| Reassociation response     | wlan.fc.type_subtype == 0x03   |
| Probe request              | wlan.fc.type_subtype == 0x04   |
| Probe response             | wlan.fc.type_subtype == 0x05   |
| Beacon                     | wlan.fc.type_subtype == 0x08   |
| Disassociate               | wlan.fc.type_subtype == 0x0A   |
| Authentication             | wlan.fc.type_subtype == 0x0B   |
| Deauthentication           | wlan.fc.type_subtype == 0x0C   |
| Action frame               | wlan.fc.type_subtype == 0x0D   |
| Block ACK requests         | wlan.fc.type_subtype == 0x18   |
| Block ACK                  | wlan.fc.type_subtype == 0x19   |
| Power save poll            | wlan.fc.type_subtype == 0x1A   |
| Request to send            | wlan.fc.type_subtype == 0x1B   |
| Clear to send              | wlan.fc.type_subtype == 0x1C   |
| ACK                        | wlan.fc.type_subtype == 0x1D   |
| Contention free period end | wlan.fc.type_subtype == 0x1E   |
| NULL data                  | wlan.fc.type_subtype == 0x24   |
| QoS data                   | wlan.fc.type_subtype == 0x28   |
| Null QoS data              | wlan.fc.type_subtype == 0x2C   |


### MCS Table (HT/VHT/HE)

~~ TBD ~~

<!--
### Promiscuous Mode

Enable Promiscuous Mode

```console
$ sudo ifconfig enp0s25 promisc

$ sudo ifconfig enp0s25
enp0s25: flags=4419<UP,BROADCAST,RUNNING,PROMISC,MULTICAST>  mtu 1500           # < = PROMISC
        inet 192.168.2.242  netmask 255.255.255.0  broadcast 192.168.2.255
        inet6 fe80::74fa:d87f:c697:6bff  prefixlen 64  scopeid 0x20<link>
        ether 3c:97:0e:51:72:df  txqueuelen 1000  (Ethernet)
        RX packets 309505  bytes 241920726 (230.7 MiB)
        RX errors 0  dropped 1  overruns 0  frame 0
        TX packets 279294  bytes 36722749 (35.0 MiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 264
        device interrupt 20  memory 0xf2600000-f2620000
```

Disable Promiscuous Mode

```console
$ sudo ifconfig enp0s25 -promisc

$ sudo ifconfig enp0s25
enp0s25: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.2.242  netmask 255.255.255.0  broadcast 192.168.2.255
        inet6 fe80::74fa:d87f:c697:6bff  prefixlen 64  scopeid 0x20<link>
        ether 3c:97:0e:51:72:df  txqueuelen 1000  (Ethernet)
        RX packets 309890  bytes 241950545 (230.7 MiB)
        RX errors 0  dropped 1  overruns 0  frame 0
        TX packets 279816  bytes 36788444 (35.0 MiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 266
        device interrupt 20  memory 0xf2600000-f2620000

```
-->
