
# Accessories for Firmware Development

## USB-to-RS232 console cable

Try to buy it from [Taobao](https://www.taobao.com/). It(PL2303 chipset) is not very expensive.

- [PL2303](http://www.prolific.com.tw/US/ShowProduct.aspx?p_id=225&pcid=41) 
- [FTDI chipsets](https://ftdichip.com/drivers/)

## Wi-Fi Adaptor: Network Packet Capturer

There are some Wi-Fi USB dongle which can capture wireless packets in Linux OS, but MTK chipsets may have problem to capture `RTS` packets.

- MediaTek 7610 chipset(0e8d:7610)
- MediaTek 7612 chipset(0e8d:7612)
- MediaTek AC-1200 Mbps mt76x2u chipset (0e8d:2870)
- [D-Link DWA-140 rev D1](https://deviwiki.com/wiki/D-Link_DWA-140_rev_D1) Ralink RT5372 chipset (rt2800usb, 2001:3c20)

clear syslog using `dmesg -c` then plug the dongle and run `dmesg` and `ifconfig` to make sure this device is enabled in your machine. 

```console
$ dmesg -c  
$ dmesg
[ 7355.421533] usb 2-2: new high-speed USB device number 11 using xhci_hcd
[ 7355.586303] usb 2-2: New USB device found, idVendor=2001, idProduct=3c20, bcdDevice= 1.01
[ 7355.586309] usb 2-2: New USB device strings: Mfr=1, Product=2, SerialNumber=3
[ 7355.586313] usb 2-2: Product: 802.11 n WLAN
[ 7355.586315] usb 2-2: Manufacturer: Ralink
[ 7355.586317] usb 2-2: SerialNumber: 1.0
[ 7355.713930] usb 2-2: reset high-speed USB device number 11 using xhci_hcd
[ 7355.871253] ieee80211 phy8: rt2x00_set_rt: Info - RT chipset 5392, rev 0222 detected
[ 7355.884821] ieee80211 phy8: rt2x00_set_rf: Info - RF chipset 5372 detected
[ 7355.884997] ieee80211 phy8: Selected rate control algorithm 'minstrel_ht'
[ 7355.899487] rt2800usb 2-2:1.0 wlxd8fee3d7ae29: renamed from wlan0
[ 7355.919436] ieee80211 phy8: rt2x00lib_request_firmware: Info - Loading firmware file 'rt2870.bin'
[ 7355.919471] rt2800usb 2-2:1.0: firmware: direct-loading firmware rt2870.bin
[ 7355.919475] ieee80211 phy8: rt2x00lib_request_firmware: Info - Firmware detected - version: 0.36

# sudo ifconfig 
wlxd8fee3d7ae29: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
        ether 96:4f:c3:ae:3b:c2  txqueuelen 1000  (Ethernet)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

```
