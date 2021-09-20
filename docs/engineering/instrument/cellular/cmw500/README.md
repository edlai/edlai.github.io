# Cellular Technologies

## LTE Call Box - Rohde & Schwarz CMW500 LTE Tester

A basic practice/an basic introduction of how to operator LTE Tester.

## Requirements

- Rohde & Schwarz CMW500
- Windows PC (for RemoteAPP) 

## Topology

- Back View

```
|Internet Access|  |Security Scan| |+| |+| |PWR|
                                    \---/
                                    SHORT
```

- Front View

```
|LAN Port|
```


## Function

### Security Scan and Throughput Test

- Standalone

```
|WAN-PC     | -- |CMW500      | -- |DUT         |
|172.22.1.99|    |172.22.1.201|    |172.22.1.100|
```

### Internet Access

- DHCP (able to access Internet Network.

```
|Internet| == {PPPoE} == |Router     | -- |CMW500         | -- |DUT            |
                         |192.168.0.1|    |192.168.168.100|    |192.168.168.101|
```

- IP
- DNS

### Remote Access and Debug

- take `Standalone` mode as an example

```
|WAN-PC     | -- |    CMW500             | -- |DUT         |
|172.22.1.99|    |LAN Front: 172.22.1.201|    |172.22.1.100|
                 |LAN Front: 192.168.8.1 |
```

### d