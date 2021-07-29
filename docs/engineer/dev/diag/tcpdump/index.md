# Tcpdump

Tcpdump can capture Network traffice in console mode.

## Install tcpdump

``` sh
$ sudo apt-get install tcpdump
```

## User Cases
### Dump VLAN packets

VLAN belongs to layer2, use below command to dump VLAN packets.

``` sh
$ sudo tcpdump -i enp0s25 -en -XX
```

- `-e`: Prints the link-level header on each dump line.
- `-n`:	Blocks converting the host addresses, and the port numbers to names.
- `-X`:	Prints each packet (minus its link level header) in hexadecimal and ASCII. This is very handy for analyzing new protocols.

### Dump PPPoE packets

VLAN belongs to layer3, use below command to dump PPPoE packets.


``` sh
$ sudo tcpdump -i enp0s25 -en -XX ether[0x0c:2]==0x8863 or ether[0x0c:2]==0x8864
```

- `0x8863`: PPPoE Discovery Stage
- `0x8864`: PPPoE Session Stage


## Appendix
### Promiscuous Mode

Enable Promiscuous Mode

``` sh
$ sudo ifconfig enp0s25 promisc

$ sudo ifconfig enp0s25
enp0s25: flags=4419<UP,BROADCAST,RUNNING,PROMISC,MULTICAST>  mtu 1500           # < = PROMISC
        inet 192.168.2.242  netmask 255.255.255.0  broadcast 192.168.2.255
        inet6 fe80::74fa:d87f:c697:6bff  prefixlen 64  scopeid 0x20<link>
        ether 3c:97:0e:51:72:df  txqueuelen 1000  (Ethernet)
        RX packets 309505  bytes 241920726 (230.7 MiB)
        RX errors 0  dropped 1  overruns 0  frame 0
        TX packets 279294  bytes 36722749 (35.0 MiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 264
        device interrupt 20  memory 0xf2600000-f2620000
```

Disable Promiscuous Mode

``` sh
$ sudo ifconfig enp0s25 -promisc

$ sudo ifconfig enp0s25
enp0s25: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.2.242  netmask 255.255.255.0  broadcast 192.168.2.255
        inet6 fe80::74fa:d87f:c697:6bff  prefixlen 64  scopeid 0x20<link>
        ether 3c:97:0e:51:72:df  txqueuelen 1000  (Ethernet)
        RX packets 309890  bytes 241950545 (230.7 MiB)
        RX errors 0  dropped 1  overruns 0  frame 0
        TX packets 279816  bytes 36788444 (35.0 MiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 266
        device interrupt 20  memory 0xf2600000-f2620000

```