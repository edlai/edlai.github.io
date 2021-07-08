# Debian 10.10


Download and install Wireshark from Internet. If you would like to capture Wireless packets in Linux OS, you may need to find a suitable WiFi dongle which can support monitor mode. For `Debian 10.10`, becasue its Linux Kernel version is 4.x, you might consider to upgrade to Linux Kernel 5.x which can support more WiFi dongles. There are the steps as following to upgrade Linux Kernel from 4.x to 5.x in Debian 10.10.


Programming Live CD, in my case I choose [`debian-live-10.10.0-amd64-xfce.iso`](https://cdimage.debian.org/debian-cd/current-live/amd64/iso-hybrid/)

Check the current Linux Kernel version.

```console
# uname -a
config-4.19.0-17-amd64
```

Upgrade the essential packages for wireless capture

```console
$ sudo apt-get update && sudo apt-get upgrade
$ sudo apt-get install -y openssh-server vim net-tools usbutils pciutils
$ sudo apt-get install -y build-essential libncurses-dev bison flex libssl-dev libelf-dev
$ sudo apt-get install -y git fakeroot ncurses-dev xz-utils bc
$ sudo apt-get install -y software-properties-common rsync
$ sudo apt-get install -y libncurses5-dev gcc grub2 wget
$ sudo service sshd restart
```

Add apt repository to support `linux-image-5.10.0`

``` console
$ sudo add-apt-repository 'deb http://deb.debian.org/debian buster-backports main'
$ sudo apt-get update
$ sudo apt-get install linux-image-5.10.0-0.bpo.7-amd64
$ sync reboot
```

After rebooted. Check current Linux version to make sure its `Linux Kernel 5.10`

``` console
# uname -a
Linux vultr.guest 5.10.0-0.bpo.7-amd64 #1 SMP Debian 5.10.40-1~bpo10+1 (2021-06-04) x86_64 GNU/Linux
```

Add apt repository to support `firmware-misc-nonfree` (Optional)

```console
$ sudo add-apt-repository 'deb http://ftp.de.debian.org/debian stretch main non-free'
$ sudo apt-get update
$ sudo apt-get install firmware-misc-nonfree
$ sync; sudo reboot
```


Rebuild the kernel

```console
$ sudo apt-get update ; sudo apt-get upgrade; sudo apt autoremove
$ sudo apt-cache search kernel | grep source | grep 5.10
linux-source-5.10 - Linux kernel source for version 5.10 with Debian patches
$ sudo apt-get install linux-source-5.10
$ sudo cp /usr/src/linux-source-5.10.tar.xz .
$ sudo chgrp ed linux-source-5.10.tar.xz
$ sudo chown ed linux-source-5.10.tar.xz
$ tar xvf linux-source-5.10.tar.xz
$ cd linux-source-5.10/
$ cp /boot/config-$(uname -r) .config
$ scripts/config --set-str SYSTEM_TRUSTED_KEYS ""
```

Compile and Install the Kernel

```console
$ sudo add-apt-repository 'deb http://http.us.debian.org/debian/ buster main contrib non-free'
$ sudo make -j $(nproc) V=99 deb-pkg
```

Install

```console
$ 
```

```c
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
  printk(KERN_INFO "Hello, world\n");
  return 0;
}

static void hello_exit(void)
{
  printk(KERN_INFO "Goodbye, Hello world\n");
}

module_init(hello_init);
module_exit(hello_exit);
```


```
cat /proc/modules
```

## Reference


- [Kernel Module Snippets – Part 1 – Hello World](https://www.craftypenguins.net/kernel-module-snippets-part-1-hello-world/)

<!--
sudo apt-get install build-essential autoconf automake libtool pkg-config libnl-3-dev libnl-genl-3-dev libssl-dev ethtool shtool rfkill zlib1g-dev libpcap-dev libsqlite3-dev libpcre3-dev libhwloc-dev libcmocka-dev hostapd wpasupplicant tcpdump screen iw usbutils
-->