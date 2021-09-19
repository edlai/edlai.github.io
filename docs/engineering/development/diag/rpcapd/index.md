# Computer Networks

## Remote Packet Capture

- 在嵌入式系統(`Embedded Linux`)中, 有時我們需要抓取某一個對外網口 (e.q `wan0`)來回的封包, 以便確認其封包內容是我們所期望的.
- 通常我們會透過 `tcpdump`. 但透過 `tcpdump` 抓取的封包還需傳送至桌上型電腦端，再行解開，一來一回浪費掉許多時間.
- `rpcapd` 是一個不錯的選擇，可以直接將網口的封包直接轉送到電腦的 [`Wireshark`](https://www.wireshark.org/download.html).

## Topology

```
+-------------------+        +-----------------------------------+
| Running Wireshark |        | Running rpcapd                    |
|         on PC     |        |  on Embedded Linux                |
+-------------------+        +-----------------------------------+
|                   |        |                                   |
|   +---------------+        +---------------+   +---------------+
|   |     adapter   |========+       br0     +===+      wan0     |
|   | (192.168.0.10)|        | (192.168.0.1) |   | (192.168.2.2) |
|   +---------------+        +-------++------+   +---------------+
|                   |        |       ||                          |
|                   |        |       ||          +---------------+      +----------+
|                   |        |       ||          |      wlan0    |      | Smart    |
|                   |        |       ++==========| (192.168.0.1) | ))(( |    Phone |
|                   |        |                   +---------------+      |          |
|                   |        |                                   |      |          |
+-------------------+        +-----------------------------------+      +----------+
```

## Installation

Use Beaglebone Black (BBB) as an Embedded Devceis.

- Install

  - Precondition (Optional)
    ``` sh
    $ sudo apt-get install build-essential libpcap-dev
    $ sudo apt-get install flex bison
    ```

  - Build libpcap
    ``` sh
    $ wget http://www.tcpdump.org/release/libpcap-1.9.0.tar.gz
    $ tar xvf libpcap-1.9.0.tar.gz
    $ cd libpcap-1.9.0
    $ ./configure --with-pcap=linux
    $ make
    $ make install
    ```
 - Build rpcapd
    ``` sh
    $ ldconfig
    $ cp
    $ make build-rpcapd   (Go next step if something wrong)
    $ cd rpcapd
    $ gcc -fvisibility=hidden -g -O2 -o rpcapd daemon.o fileconf.o log-stderr.o rpcapd.o rpcap-protocol.o sockutils.o ../fmtutils.o ../libpcap.a -lpthread -lcrypt
    $ ls -la rpcapd
      -rwxr-xr-x 1 root root 1145032 Oct 27 05:10 rpcapd
    ```

<!--

LDFLAGS="-L$OUT_DIR/lib -lcrypt" ./configure --with-pcap=linux --target=${ARCH} --host=${ARCH} --prefix=${OUT_DIR} 

-->

<!--
$ cp rpcapd/rpcap-protocol.o .
$ cp rpcapd/sockutils.o .
-->

## Running

### Linux Server side

  ``` sh
  $ ./rpcapd -p 2002 -n -4 -b 192.168.0.1           #<= -b <address>: the address to bind to (either numeric or literal).
                                                            Default: it binds to all local IPv4 addresses
                                                        -p <port>: the port to bind to. Default: it binds to port 2002
                                                        -t <data port>: the port to transfer data.
                                                        -4: use only IPv4 (default both IPv4 and IPv6 waiting sockets are used)
                                                        -l <host_list>: a file that keeps the list of the hosts which are allowed
                                                            to connect to this server (if more than one, list them one per line).
                                                            We suggest to use literal names (instead of numeric ones) in order to
                                                            avoid problems with different address families
                                                        -n: permit NULL authentication (usually used with '-l')
                                                        -a <host,port>: run in active mode when connecting to 'host' on port 'port'
                                                            In case 'port' is omitted, the default port (2003) is used
                                                        -v: run in active mode only (default: if '-a' is specified, it accepts
                                                            passive connections as well
                                                        -d: run in daemon mode (UNIX only) or as a service (Win32 only)
                                                            Warning (Win32): this switch is provided automatically when the service
                                                            is started from the control panel
                                                        -s <file>: save the current configuration to file
                                                        -f <file>: load the current configuration from file; all the switches
                                                            specified from the command line are ignored
                                                        -h: print this help screen

  ```


### Windows Side

- Install [Wireshark](https://www.wireshark.org/download.html)

- Invoke `Wireshark`
  - `Capture` >  `Options` > `Manage Interfaces` > `Remote Interfaces` > `Add`

- Please click `▶` to play below video for more detail.
  <video width="800" controls>
    <source src="rpcapd.mp4" type="video/mp4">
    Your browser does not support HTML5 video.
  </video>

## Reference

- [rpcapd與netcat-測試嵌入式系統的好工具](http://daydreamer.idv.tw/rewrite.php/read-56.html)
- [rpcapd: Capture Remote System Network Traffic](http://roan.logdown.com/posts/230705-rpcapd-remote-capture-remote-system-network-traffic)
- [Sysdig: 容器故障排除工具](https://blog.pichuang.com.tw/sysdig-container-troubleshooting-and-visibility/#more-171)
- [How can I sniff the traffic of remote machine with wireshark?](https://serverfault.com/questions/362529/how-can-i-sniff-the-traffic-of-remote-machine-with-wireshark)
- [ttysnoop](http://daydreamer.idv.tw/rewrite.php/read-64.html)

## Comment

- [Win32(winpcap)](https://github.com/ExtraHop/rpcapd.git)