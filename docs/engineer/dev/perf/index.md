# Networking Performance

## Tools

### Linux Bandwidth Monitor Tools

- [bmon](https://en.wikipedia.org/wiki/Bmon)

### Windows Bandwidth Monitor Tools

- [Bandwidth Monitor](http://www.bwmonitor.com/)

### iperf3

- [iPerf](https://iperf.fr/): The ultimate speed test tool for TCP, UDP and SCTP

Install

```
$ sudo apt-get install iperf3
```

Server Side

```
$ iperf3 -s
```

Client Side

```
$ iperf3 -c ${SERVER_IP}
```

### FTP


### HTTP

``` bash
#!/bin/bash

URL="http://speedtest.tele2.net/1GB.zip"
LOGFILE="curl.log"

rm -rf ${LOGFILE}
curl -L -o /dev/null "$URL" 2>&1  2>&1 | tee ${LOGFILE}
cat ${LOGFILE}
```

- Reference
  - [Measuring Transfer Speed Over Time with cURL](https://copperlight.github.io/shell/measuring-transfer-speed-over-time-with-curl/)
  - [Tele2 Speedtest Service](http://speedtest.tele2.net/)
  - [Hinet FTP](http://speed.hinet.net/ftptest.html)

<!--

### IxChariot

- [IXCHARIOT/HAWKEYE PLATFORM ENDPOINTS](https://support.ixiacom.com/support-links/ixchariot/endpoint-library/platform-endpoints)

## Flash

```
$ mtd tool
```

- Reference
  - [採用dd 工具做Nand Flash磨損均衡](https://www.jianshu.com/p/763f8564edea)
  - [使用linux的MTD tests support測試flash性能](http://simple-is-beauty.blogspot.com/2018/12/linuxmtd-tests-supportflash.html)

~~ TBD ~~

-->