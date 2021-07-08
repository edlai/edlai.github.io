# Buildroot

There are some resource for buildroot.

- [Buildroot](https://buildroot.org/): Making Embedded Linux Easy
- [Buildroot in GitHub](https://github.com/buildroot/buildroot)
- [Buildroot's Packages](https://github.com/buildroot/buildroot/tree/master/package)

## Requirements

- Raspberry Pi 3

## Quick Start

Download source code and set configuration to Raspberry Pi 3, then make it.

```bash
$ mkdir br2
$ wget https://buildroot.org/downloads/buildroot-2021.05.tar.bz2
$ tar xvf buildroot-2021.05.tar.bz2
$ cd buildroot-2021.05
$ make raspberrypi3_64_defconfig
$ make
$ ls -lah output/images/sdcard.img
-rw-r--r-- 1 ed ed 153M Jul  3 20:29 output/images/sdcard.img

```

Programming image to SD card. insert SD card to RPI3 and try to power on RPI3. If you uses Windows OS, you can programming image to SD card by using `Rufus`.

## Package

### One single package manually

try to build one single package manually. Use `make <PKG>` to build package, there is an examples to build one single package `tcpdump` 

```bash
$ make tcodump
$ ls -lah output/target/usr/bin/tcpdump
-rwxr-xr-x 1 ed ed 1.2M Jul  3 20:48 output/target/usr/bin/tcpdump
```

If you would like to rebuild it again, press `<PKG>-dirclean` the `<PKG>-rebuild`

```bash
$ make tcpdump-dirclean
$ make tcpdump-rebuild
```

### Hello


[Add hello app to buildroot](https://hackmd.io/@c_0KKCwzQE2rsd39mpvNQQ/rklPsoKaI)

### Add some useful Packages

There are some useful packages and its location when pressing `make menuconfig`. Consider to enable them then make the image again.

- wget (Target packages > Networking Applications > wget)
- tcpdump (Target packages > Networking Applications > tcpdump)
- hostapd (Target packages > Networking Applications > hostapd)
- wpa_supplicant (Target packages > Networking Applications > wpa_supplicant)
- cJSON (Libraries > JSON/XML >  cJSON)
- libcurl (Libraries > Networking > libcurl)

## Linux Kernel

There are the commands for make linux kerenl. 

```
$ make linux-menuconfig
$ make linux-rebuild
```

## Busybox

There are the commands to make busybox. Use `mkfifo` as an example, try to step into `Coreutils > mkfifo` and rebuild busybox.
```
$ busybox-menuconfig 
$ make busybox-rebuild
```

## Reference

- [buildroot使用介绍](https://www.cnblogs.com/arnoldlu/p/9553995.html)

~~ TBD~~~