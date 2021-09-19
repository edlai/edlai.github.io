# OpenWRT


## Requirements

- [MT7688](https://labs.mediatek.com/zh-tw/chipset/MT7688)
## Quick Start

Clone the repository 

```bash
$ git clone https://github.com/openwrt/openwrt
$ cd openwrt
$ cp feeds.conf.default feeds.conf
$ echo src-git linkit https://github.com/MediaTek-Labs/linkit-smart-7688-feed.git >> feeds.conf
$ ./scripts/feeds update
$ ./scripts/feeds install -a
$ make menuconfig
```

Select profile as following,

- Target System: `MediaTek Ralink MIPS`
- Subtarget: `MT76x8 based board`
- Target Profile: `MediaTek LinkIt Smart 7688`  

make it

```
$ make V=99 2>&1 | tee build.log | grep -i error
```

Output images. There are in `bin/targets/ramips/mt76x8/`

- bin/targets/ramips/mt76x8/openwrt-ramips-mt76x8-mediatek_mt7628an-eval-board-initramfs-kernel.bin
- bin/targets/ramips/mt76x8/openwrt-ramips-mt76x8-mediatek_mt7628an-eval-board-squashfs-sysupgrade.bin

For package, There are in `targets/ramips/mt76x8/packages/`use `hostapd` as an example.

- targets/ramips/mt76x8/packages/hostapd-common_2021-05-22-b102f19b-17_mipsel_24kc.ipk

## Reference

- [LinkIt Smart MT7688](https://steward-fu.github.io/website/mcu/mt7688/build_openwrt.htm)
- [OpenWrt 建置 – 使用方法](https://openwrt.org/zh-tw/doc/howto/build)

~~ TBD~~~