# Flash Memory Endurance Test

Linux provides several modules for flash endurance lifetime measurement test/capacity check.

- mtd_nandecctest.ko：nand flash的ECC校驗測試
- mtd_pagetest.ko：nand flash的page讀寫測試
- mtd_subpagetest.ko：nand flash的sub-page接口測試
- mtd_oobtest.ko：nand falsh的OOB區域讀寫測試
- mtd_speedtest.ko：MTD分區的讀寫速度測試
- mtd_readtest.ko：讀取整個MTD分區
- mtd_stresstest.ko：隨機讀寫，擦除操作測試
- mtd_torturetest.ko：該功能可用於做穩定性或者壽命測試，隨機操作直到發生錯誤

## Enable MTD test module

enable `CONFIG_MTD_TESTS=m`

``` console
"Device Drivers" -> "Memory Technology Device (MTD) support" -> "MTD tests support"
```

## Build the Linux Kernel

Execute `make` command to build the image.

``` console
$ make ARCH=mips CROSS_COMPILE=arm-linux-gnueabihf- modules
```

## Running Test

Confirm current MTD layout

``` console
$ cat /proc/mtd
dev:    size   erasesize  name
mtd0: 00020000 00010000 "boot"
mtd1: 00010000 00010000 "MAC"
mtd2: 00010000 00010000 "config"
mtd3: 00260000 00010000 "kernel"
mtd4: 00a60000 00010000 "rootfs"
mtd5: 00cc0000 00010000 "Linux"
mtd6: 00100000 00010000 "data1"   # < = test this paration
mtd7: 00200000 00010000 "data2"
mtd8: 01000000 00010000 "ALL"
```

Issue test

``` console
$ dmesg -c;                                       # < = purge syslog
$ time modprobe mtd_stresstest dev=6 count=1000;  # < = insert module to perform the test
$ dmesg -c;                                       # < = check syslog
$ rmmod mtd_stresstest                            # < = remove module
```

## Check Result


``` console
<6>mtd_stresstest: MTD device: 6
<6>mtd_stresstest: not NAND flash, assume page size is 512 bytes.
<6>mtd_stresstest: MTD device size 1048576, eraseblock size 65536, page size 512, count of eraseblocks 16, pages per eraseblock 128, OOB size 0
<6>mtd_stresstest: doing operations
<6>mtd_stresstest: 0 operations done
<6>mtd_stresstest: 1024 operations done
<6>mtd_stresstest: 2048 operations done
<6>mtd_stresstest: 3072 operations done
<6>mtd_stresstest: 4096 operations done
<6>mtd_stresstest: 5120 operations done
<6>mtd_stresstest: 6144 operations done
<6>mtd_stresstest: 7168 operations done
<6>mtd_stresstest: 8192 operations done
<6>mtd_stresstest: 9216 operations done
<6>mtd_stresstest: finished, 10000 operations done
```
 ### Script

``` bash
#!/bin/sh

rm -rf /media/local/
count=1
while [ ${count} -lt 600 ]; do
    TSTAMP="`date`  | ---> ${count}"
    echo "$TSTAMP"
    mkdir -p /media
    time cp /usr/local /media/ -raf
    diff /usr/local /media/local -r || exit -1
    rm -rf /media/local;
    sync

    let count=${count}+1
done
```

## Reference

- [使用linux的MTD tests support测试flash性能](https://blog.csdn.net/gp_scoprius/article/details/53257056)
- [關於NAND Flash調試的一點總結](https://zhuanlan.zhihu.com/p/131298394)

<!--

dmesg -c; time modprobe mtd_speedtest dev=6 count=1000; dmesg -c ; rmmod mtd_speedtest
dmesg -c; time modprobe mtd_readtest dev=6 count=1000;dmesg -c ; rmmod mtd_readtest
dmesg -c; time modprobe mtd_stresstest dev=6 count=1000;dmesg -c ; rmmod mtd_stresstest
dmesg -c; time modprobe mtd_torturetest dev=6 count=1000;dmesg -c ; rmmod mtd_torturetest

-->

<!--
dmesg grep mtd_stresstest

sync

mfc reboot


time dd if=/dev/zero of=test.img bs=1M count=500

awk 'BEGIN { while (1) printf("%c%c", 0x5a,0xa5) }' | dd of=/dev/mtd6 bs=1 count=1048576

hexdump -n40 /dev/mtd6

awk 'BEGIN { while (1) printf("%c%c", 0x5a,0xa5) }' | dd of=/tmp/a bs=1 count=1048576
dd if=/tmp/a of=/dev/mtd6 bs=1 count=1048576

hexdump -b -C -n1048576 /tmp/1M


dd if=/dev/urandom of=/tmp/10M bs=1M count=1

/tmp/a

awk 'BEGIN { while (1) printf("%c%c", 0x5a,0xa5) }' | dd of=/tmp/1M bs=4 count=262144

hexdump -b -C /tmp/1M

while true; do echo -n 'x'; done | dd of=/dev/mtd6 bs=4k conv=notrunc iflag=fullblock


Lichee Pi https://licheezero.readthedocs.io/zh/latest/index.html

CONFIG_TIME

SDK Framework

-->