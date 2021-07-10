# RTK 8197F

Run `Ubuntu 16.04` (VPS), it cannot work in `Ubuntu 18.04`.


Prepare

```console
$ rm -rf /bin/sh && ln -s /bin/bash /bin/sh
```

Install below packages

```console
$ cat /etc/lsb-release
$ apt-get -y update > /dev/null 2> /dev/null
$ apt-get -y upgrade > /dev/null 2> /dev/null

$ apt-get -y install wget git build-essential gcc-multilib g++-multilib
$ apt-get -y install lsb-core autoconf automake libjson-* libmpc-dev lib32stdc++6 p7zip-full tree
$ apt-get -y install gcc g++ binutils patch bzip2 flex bison make autoconf gettext texinfo unzip
$ apt-get -y install sharutils subversion libncurses5-dev ncurses-term zlib1g-dev subversion
$ apt-get -y install gawk libz-dev asciidoc libtool libssl-dev
$ apt-get -y install intltool libiconv* glib2.0 ccache sshfs mtd-utils rst2pdf
```

Build Image

```
$ export TERMINFO=/lib/terminfo
$ make clean
$ make distclean
$ make menuconfig
```

Select Target

```
$ make 2>&1 | tee mk.log
```