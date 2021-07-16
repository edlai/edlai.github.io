# Docker and Macvlan

If you are not familiar with Docker Compose, pleasr take a look [Get started with Docker Compose](https://docs.docker.com/compose/gettingstarted/).
## Docker

- Docker File
- Docker Compose YAML File
### Install

Install docker.

``` console
$ wget -qO- https://get.docker.com/ | sh
```

<!--
Follow [Install Docker Engine on Ubuntu](https://docs.docker.com/engine/install/ubuntu/) to install Docker in Ubuntu 20.10.

``` console
$ sudo apt-get remove docker docker-engine docker.io containerd runc
$ sudo apt-get install apt-transport-https ca-certificates curl gnupg lsb-release
$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg
$ echo "deb [arch=amd64 signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
$ sudo apt-get update
$ sudo apt-get install docker-ce docker-ce-cli containerd.io
```
-->

Show Docker version you installed.

``` console
$ docker version
```

Add User and logout then re-login again

```console
$ sudo groupadd docker
$ sudo usermod -aG docker $USER
$ logout
```

Run it. (Hello World)

``` console
$ docker run hello-world

or Run it. (Nginx)

```console
$ docker run -d -p 80:80 nginx
$ netstat -alnp | grep 80
tcp        0      0 0.0.0.0:80              0.0.0.0:*               LISTEN      12680/docker-proxy
tcp6       0      0 :::80                   :::*                    LISTEN      12689/docker-proxy
```

Run it using interactive(`-it`) then press `uname -a` to check the current Ubuntu version docker installed.

```console
$ docker run -it ubuntu bash
...
root@7a58af80ae6b:/# uname -a
Linux 7a58af80ae6b 5.8.0-59-generic #66-Ubuntu SMP Thu Jun 17 00:46:01 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux
root@7a58af80ae6b:/# exit
```

Check Image

``` console
$ docker images
REPOSITORY    TAG       IMAGE ID       CREATED        SIZE
ubuntu        latest    c29284518f49   2 days ago     72.8MB
nginx         latest    4cdc5dd7eaad   9 days ago     133MB
hello-world   latest    d1165f221234   4 months ago   13.3kB
```

<!--
Check Socket

```console
$ ll /var/run/docker.sock
srw-rw---- 1 root docker 0 Jul 16 02:19 /var/run/docker.sock=
```
-->

### Docker File

Dockerfile

```
FROM centos:7
MAINTAINER ed

RUN yum install -y wget

RUN cd /

ADD jdk-8u152-linux-x64.tar.gz /

RUN wget http://apache.stu.edu.tw/tomcat/tomcat-7/v7.0.82/bin/apache-tomcat-7.0.82.tar.gz
RUN tar zxvf apache-tomcat-7.0.82.tar.gz

ENV JAVA_HOME=/jdk1.8.0_152
ENV PATH=$PATH:/jdk1.8.0_152/bin
CMD ["/apache-tomcat-7.0.82/bin/catalina.sh", "run"]
```

Run it. (docker build)

```
$ docker build -t mytomcat . --no-cache
```

## Docker Compose

Follow [Install Docker Compose](https://docs.docker.com/compose/install/) to install Docker Compose.

``` console
$ sudo curl -L "https://github.com/docker/compose/releases/download/1.29.2/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
$ sudo chmod +x /usr/local/bin/docker-compose

$ docker-compose --version
docker-compose version 1.29.2, build 5becea4c
```

### YAML

`docker-compose.yml`

```
version: '3'

services:

  otrecorder:
    image: owntracks/recorder
    ports:
      - 8083:8083
    volumes:
      - config:/config
      - store:/store
    restart: unless-stopped
    environment:
      OTR_HOST: mosquitto

  mosquitto:
    image: eclipse-mosquitto
    ports:
      - 1883:1883
      - 8883:8883
    volumes:
      - mosquitto-data:/mosquitto/data
      - mosquitto-logs:/mosquitto/logs
      - mosquitto-conf:/mosquitto/config
    restart: unless-stopped

volumes:
  store:
  config:
  mosquitto-data:
  mosquitto-logs:
  mosquitto-conf:
```

### up

```
$ docker-compose up
```

## MACVLAN

### Install

```
$ modprobe macvlan
$ lsmod | grep macvlan
macvlan                24576  0
```

### Topology

```
Home Router       (192.168.0.1)
├── MQTT Broker   (192.168.0.2)
├── MQTT Client 1 (192.168.0.3)
└── MQTT Client 2 (192.168.0.4)

```

## MQTT
### Run MQTT

## Reference

- [How To List Docker Images](https://devconnected.com/how-to-list-docker-images/)
- [[容器] 如何寫 Dockerfile](https://blog.kevinyang.net/2020/08/03/docker-101-note-3/)
- [[Docker] MACVLAN Network 簡介](https://godleon.github.io/blog/Docker/docker-network-macvlan/)