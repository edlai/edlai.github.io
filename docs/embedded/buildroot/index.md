# Buildroot

There are some resources for buildroot.

- [GitHub](https://github.com/buildroot/buildroot): source code in GitHub.
- [Buildroot](https://buildroot.org/): official website.
- [Packages](https://github.com/buildroot/buildroot/tree/master/package): official packages.

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

Programming image to SD card. Insert SD card to RPI3 and power on RPI3. If you use Windows OS, you can programming image to SD card by using [`Rufus`](https://rufus.ie/).

## Packages

### Add one single package manually

Use `make <PKG>` to build package, there is an examples to build one single package `tcpdump` 

```bash
$ make tcpdump
$ ls -lah output/target/usr/bin/tcpdump
-rwxr-xr-x 1 ed ed 1.2M Jul  3 20:48 output/target/usr/bin/tcpdump
```

If you would like to rebuild it again, press `<PKG>-dirclean` the `<PKG>-rebuild`

```bash
$ make tcpdump-dirclean
$ make tcpdump-rebuild
```

### Add some useful packages

There are some useful packages and its location when pressing `make menuconfig`. Consider to enable them then make the image again.

- wget (Target packages > Networking Applications > wget)
- tcpdump (Target packages > Networking Applications > tcpdump)
- hostapd (Target packages > Networking Applications > hostapd)
- wpa_supplicant (Target packages > Networking Applications > wpa_supplicant)
- cJSON (Libraries > JSON/XML >  cJSON)
- libcurl (Libraries > Networking > libcurl)


### Add Your first Package

Package file Layout

```
package
├── Config.in
└── hello
    ├── Config.in
    ├── hello.mk
    └── src
        ├── .gitignore
        ├── hello.c
        └── Makefile

```

package/Config.in: add `Misc`

``` makefile
menu "Misc"
        source "package/hello/Config.in"
endmenu
```

package/hello/Config.in: add `BR2_PACKAGE_HELLO`

``` makefile
config BR2_PACKAGE_HELLO
        bool "hello"
        help
                Hello world package.
                http://example.com
```

package/hello/hello.mk

``` makefile
HELLO_VERSION = 1.0
HELLO_SITE = ./package/hello/src
HELLO_SITE_METHOD = local

define HELLO_BUILD_CMDS
        $(MAKE) CC="$(TARGET_CC)" LD="$(TARGET_LD)" -C $(@D)
endef

define HELLO_INSTALL_TARGET_CMDS
        $(INSTALL) -D -m 0755 $(@D)/hello $(TARGET_DIR)/usr/bin
endef

$(eval $(generic-package))
```

package/hello/src/.gitignore

```
hello
```

package/hello/src/hello.c

```c
#include <stdio.h>

int main(void)
{
  printf("buildroot helloworld\n");
  return 0;
}
```

package/hello/src/Makefile

```makefile
CC = gcc

.PHONY: clean

hello: hello.c
        $(CC) -o '$@' '$<'

clean:
        rm hello
```

Manually

```
$ make hello-dirclean

$ make hello-rebuild

$ tree output/build/hello-1.0/
output/build/hello-1.0/
├── hello
├── hello.c
└── Makefile

$ make hello-install

$ file output/target/usr/bin/hello
output/target/usr/bin/hello: ELF 64-bit LSB shared object, ARM aarch64, version 1 (SYSV), dynamically linked, interpreter /lib/ld-uClibc.so.0, not stripped

```

Build Image

```
$ make raspberrypi3_64_defconfig           # < = (Optional)
$ echo 'BR2_PACKAGE_HELLO=y' >> .config
$ make BR2_JLEVEL=2
```

Program Image to SD card and Power on PRI3, run `hello` in Traget Board.

```console
# hello
buildroot helloworld
```

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


## Qemu

### Build

```console
$ make clean
$ make qemu_arm_vexpress_defconfig
$ make

```

### Run

run it via `qemu-system-arm`.

<!-- -nographic  -->

```console
$ qemu-system-arm -M vexpress-a9 -smp 1 -m 256 -kernel output/images/zImage -dtb output/images/vexpress-v2p-ca9.dtb -drive file=output/images/rootfs.ext2,if=sd,format=raw -append "console=ttyAMA0,115200 root=/dev/mmcblk0" -serial stdio -net nic,model=lan9118 -net user -nographic
```
### Result

- Username: root
- Password: [blank]

```console
...
udhcpc: lease of 10.0.2.15 obtained, lease time 86400
deleting routers
adding dns 10.0.2.3
OK

Welcome to Buildroot
buildroot login: root
# uname -a
Linux buildroot 5.10.7 #1 SMP Sat Jul 10 15:43:17 CST 2021 armv7l GNU/Linux
# ifconfig
eth0      Link encap:Ethernet  HWaddr 52:54:00:12:34:56
          inet addr:10.0.2.15  Bcast:10.0.2.255  Mask:255.255.255.0
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:2 errors:0 dropped:0 overruns:0 frame:0
          TX packets:2 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000
          RX bytes:1180 (1.1 KiB)  TX bytes:688 (688.0 B)
          Interrupt:30

lo        Link encap:Local Loopback
          inet addr:127.0.0.1  Mask:255.0.0.0
          UP LOOPBACK RUNNING  MTU:65536  Metric:1
          RX packets:0 errors:0 dropped:0 overruns:0 frame:0
          TX packets:0 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000
          RX bytes:0 (0.0 B)  TX bytes:0 (0.0 B)
```

## Reference

- [buildroot使用介绍](https://www.cnblogs.com/arnoldlu/p/9553995.html)
- [Buildroot development](https://wiki.t-firefly.com/en/Firefly-RK3399/debug.html)

~~ TBD~~~