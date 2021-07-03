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
$ make v=99
```

output

```

```

## Reference

- [LinkIt Smart MT7688](https://steward-fu.github.io/website/mcu/mt7688/build_openwrt.htm)
~~ TBD~~~