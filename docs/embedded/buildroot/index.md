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


### Add Your first Package

(Reference)[https://wiki.t-firefly.com/en/Firefly-RK3399/debug.html]

hello.c

```console
#include <stdio.h>

int main()
{
    printf("buildroot helloworld\n");
    return 0;
}
```

```console
Makefile:

OPT    = -O2
DEBUG  = -g
OTHER  = -Wall -Wno-deprecated
CFLAGS = $(OPT) $(OTHER)
INCDIR = -I
LIBDIR = -L
LIBS =
APP=helloworld
SRCS=hello.c

all:
    $(CC) -o $(APP) $(SRCS) $(CFLAGS) $(LIBDIR) $(INCDIR) $(LIBS)
clean:
    rm $(APP)
```

Config.in

```console
package/Config.in

……
menu "Text editors and viewers"
    source "package/ed/Config.in"
    source "package/joe/Config.in"
    source "package/less/Config.in"
    source "package/mc/Config.in"
    source "package/most/Config.in"
    source "package/nano/Config.in"
    source "package/uemacs/Config.in"
    source "package/vim/Config.in"
endmenu

menu "myown helloworld"
    source "package/helloworld/Config.in"
endmenu

endmenu
注意要在最後這個 endmenu 前插入。

2. 新建 ～/buildroot-2020.08.1/package/helloworld/Config.in

config BR2_PACKAGE_HELLOWORLD
bool "helloworld"
help
  This is a demo to add myown helloworld.
此時menuconfig就有了。

3. 新建～/buildroot-2020.08.1/package/helloworld/helloworld.mk

################################################################################
#
# helloworld
#
################################################################################

HELLOWORLD_VERSION:= 1.0.0
HELLOWORLD_SITE:= $(CURDIR)/dl/helloworld
HELLOWORLD_SITE_METHOD:=local
HELLOWORLD_INSTALL_TARGET:=YES

define HELLOWORLD_BUILD_CMDS
    $(MAKE) CC="$(TARGET_CC)" LD="$(TARGET_LD)" -C $(@D) all
endef

define HELLOWORLD_INSTALL_TARGET_CMDS
    $(INSTALL) -D -m 0755 $(@D)/helloworld $(TARGET_DIR)/bin
endef

define HELLOWORLD_PERMISSIONS
    /bin/helloworld f 4755 0 0 - - - - -
endef

$(eval $(generic-package))
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