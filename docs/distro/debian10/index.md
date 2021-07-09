# Debian 10.10

This chapter describes

- how to upgrade and rebuild Linux Kernel in Debian 10.10.
- how to insert and remove Linux Device Driver.


## Rebuild Linux Kernel

Download and install Wireshark from Internet.For `Debian 10.10`, becasue its Linux Kernel version is 4.x, we need to upgrade to Linux Kernel 5.x which can support more WiFi dongles. There are the steps as following to upgrade Linux Kernel from 4.x to 5.x in Debian 10.10.


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
$ sudo apt-get install -y libncurses5-dev gcc grub2 wget dwarves tree curl
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

Revise CONFIG_DEBUG_INFO_BTF to avoid build error
<!--
BTF: .tmp_vmlinux.btf: pahole version v1.12 is too old, need at least v1.16
Failed to generate BTF for vmlinux
Try to disable CONFIG_DEBUG_INFO_BTF
make: *** [Makefile:1167: vmlinux] Error 1
-->
```
CONFIG_DEBUG_INFO_BTF=n
```

Compile and Install the Kernel

```console
$ sudo add-apt-repository 'deb http://http.us.debian.org/debian/ buster main contrib non-free'
$ sudo make -j $(nproc) V=99 deb-pkg
$ cd ..
```

Result

```console
$ls -lah | grep deb
-rw-r--r--  1 ed   ed   7.7M Jul  8 23:56 linux-headers-5.10.40_5.10.40-5_amd64.deb
-rw-r--r--  1 ed   ed    50M Jul  8 23:58 linux-image-5.10.40_5.10.40-5_amd64.deb
-rw-r--r--  1 ed   ed   893M Jul  9 00:25 linux-image-5.10.40-dbg_5.10.40-5_amd64.deb
-rw-r--r--  1 ed   ed   1.1M Jul  8 23:57 linux-libc-dev_5.10.40-5_amd64.deb
```

Install

```console
$ sudo dpkg -i linux-image-5.10.40_5.10.40-5_amd64.deb
$ sudo dpkg -i linux-headers-5.10.40_5.10.40-5_amd64.deb
$ sync
$ sudo reboot
```

Verification

```console
$ uname -a
$ Linux ed-pc 5.10.40 #5 SMP Thu Jul 8 21:17:59 CST 2021 x86_64 GNU/Linux
```

## Linux Kernel Module

### Hello, world

``` python fct_label="Python 2"
print "Bonjour" 
```

``` python fct_label="Python 3"
print("Bonjour")
```

``` c fct_label="hello.c"
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

Makefile

```makefile
PWD := $(shell pwd)
KVERSION := $(shell uname -r)
KERNEL_DIR = /usr/src/linux-headers-$(KVERSION)/

MODULE_NAME = hello
obj-m := $(MODULE_NAME).o

all:
  make -C $(KERNEL_DIR) M=$(PWD) modules

test:
  dmesg -c
  sudo insmod ./hello.ko
  sudo lsmod | grep hello
  cat /proc/modules  | grep hello
  sudo rmmod hello

clean:
  make -C $(KERNEL_DIR) M=$(PWD) clean
```

Make

```console
$ make
make -C /usr/src/linux-headers-5.10.40/ M=/home/ed/hello  modules
make[1]: Entering directory '/usr/src/linux-headers-5.10.40'
  CC [M]  /home/ed/hello/hello.o
  MODPOST /home/ed/hello/Module.symvers
  LD [M]  /home/ed/hello/hello.ko
make[1]: Leaving directory '/usr/src/linux-headers-5.10.40'
```

Result

```bash
$ tree
.
├── hello.c
├── hello.ko
├── hello.mod
├── hello.mod.c
├── hello.mod.o
├── hello.o
├── Makefile
├── modules.order
└── Module.symvers

0 directories, 9 files
```

Verification

```console
$ make test
[ 5163.936243] hello: loading out-of-tree module taints kernel.
[ 5163.936708] Hello world !

hello                  16384  0

hello 16384 0 - Live 0x0000000000000000 (OE)

[ 5360.557612] Bye !
```

### Proc

hello_proc.c

```c
#include <linux/kernel.h> /* We're doing kernel work */
#include <linux/module.h> /* Specifically, a module */
#include <linux/proc_fs.h>    /* Necessary because we use the proc fs */
#include <asm/uaccess.h>  /* for copy_from_user */
#include <linux/fs.h>
#include <linux/seq_file.h>
#include <linux/slab.h>

#include "hello.h"

#define PROCFS_MAX_SIZE     1024
#define PROCFS_NAME         "hello"
static char procfs_buffer[PROCFS_MAX_SIZE];
static unsigned long procfs_buffer_size = 0;
static struct proc_dir_entry *entry;
static struct proc_dir_entry *parent;

/**
 * This function is called when the /proc file is read.
 */
static ssize_t procfile_read(struct file *file, char __user *buffer, size_t count, loff_t *offset)
{
    if (*offset > 0 || count < PROCFS_MAX_SIZE) /* we have finished to read, return 0 */
        return 0;

    /* fill the buffer, return the buffer size */
    if(copy_to_user(buffer, procfs_buffer, procfs_buffer_size))
        return -EFAULT;
    *offset = procfs_buffer_size;
    return procfs_buffer_size;
}

/**
 * This function is called when the /proc file is written
 */
static ssize_t procfile_write(struct file* file,const char __user *buffer,size_t count,loff_t *f_pos){
    int tlen;
    char *tmp = kzalloc((count+1),GFP_KERNEL);
    if(!tmp)return -ENOMEM;
    if(copy_from_user(tmp,buffer,count)){
        kfree(tmp);
        return EFAULT;
    }

    tlen = PROCFS_MAX_SIZE;
    if (count < PROCFS_MAX_SIZE)
        tlen = count;
    memcpy(&procfs_buffer,tmp,tlen);
    procfs_buffer_size = tlen;
    kfree(tmp);
    printk("Procfs Input: %s\n", procfs_buffer);
    return tlen;
}

static int procfile_show(struct seq_file *m,void *v){
    static char *str = NULL;
    seq_printf(m,"%s\n",str);
    return 0;
}

/**
 * Open the procfile
 */
static int procfile_open(struct inode *inode,struct file *file){
    return single_open(file,procfile_show,NULL);
}

static struct proc_ops proc_fops = {
    .proc_lseek = seq_lseek,
    .proc_open = procfile_open,
    .proc_read = procfile_read,
    .proc_release = single_release,
    .proc_write = procfile_write,
};

/**
 *This function is called from main.c when the module is loaded
 */
 int __init my_proc_init(void)
{
    parent = proc_mkdir(PROCFS_NAME,NULL);
    entry = proc_create("system",0777,parent,&proc_fops);
    if(!entry) {
        printk(KERN_INFO "unable to create /proc/hello/system");
        return -1;
    }
    printk(KERN_INFO "/proc/hello/system is created");
    return 0;
}

/**
 *This function is called from main.c when the module is unloaded
 */
void __exit my_proc_cleanup(void)
{
    remove_proc_entry("system", parent);
    remove_proc_entry(PROCFS_NAME, NULL);
}

static int __init hello_init(void)
{
    int rc;
    printk(KERN_INFO "Hello, Procfs!\n");

    /* create the /proc file */
    rc = my_proc_init();
    if (rc == -1)
        return -1;

    return 0;
}

static void __exit hello_exit(void)
{
    my_proc_cleanup();
    printk(KERN_INFO "Goodbye, Procfs!\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello Procfs example.");
MODULE_SUPPORTED_DEVICE("hello");
```

Makefile

```makefile
PWD := $(shell pwd)
KVERSION := $(shell uname -r)
KERNEL_DIR = /usr/src/linux-headers-$(KVERSION)/

MODULE_NAME = hello
obj-m := $(MODULE_NAME).o

all:
	make -C $(KERNEL_DIR) M=$(PWD) modules

test:
	sudo dmesg -c
	sudo insmod ./hello.ko
	echo "procfs hello test" >> /proc/hello/system
	sudo dmesg -c
	sudo rmmod hello.ko

clean:
	make -C $(KERNEL_DIR) M=$(PWD) clean
```
### IO Access

### seq_file interface

## BPF

### Precondition

```
$ sudo apt-get install clang
```

### Hello, BPF

a.c

```console
int f(int x) {
    return x + 1;
}
```

Make

```console
$ clang -c -S -emit-llvm a.c                   # < = a.ll (LLVM IR)
$ clang -c -S -target bpf a.c                  # < = a.s  (eBPF)
$ clang -c -target bpf a.c                     # < = a.o  (eBPF bytecode)
$ objcopy -I elf64-little -O binary a.o a.bin  # < = Extract eBPF bytecode
```
~~ TBD ~~

## Coredump

## Reference


- [Kernel Module Snippets – Part 1 – Hello World](https://www.craftypenguins.net/kernel-module-snippets-part-1-hello-world/)
- (https://hackmd.io/@sysprog/linux-ebpf)
<!--
sudo apt-get install build-essential autoconf automake libtool pkg-config libnl-3-dev libnl-genl-3-dev libssl-dev ethtool shtool rfkill zlib1g-dev libpcap-dev libsqlite3-dev libpcre3-dev libhwloc-dev libcmocka-dev hostapd wpasupplicant tcpdump screen iw usbutils
-->