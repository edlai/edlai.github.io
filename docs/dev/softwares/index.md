# Software Tools for Firmware Development

This chapter introduces some software development tools.

## Code Editor

### Visual Studio Code

Instead of `vi`, highly recommended to use Visual Studio Code(VSC) as a firmware development tools. First of all, just install
[Visual Studio Code](https://code.visualstudio.com/) as a foundation of code editor then don't forget to install its [Recommended extensions](https://code.visualstudio.com/docs/editor/extension-gallery) as following as well.

### VSC Extensions

- [Visual Studio Code Remote - SSH](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-ssh) (Highly Recommended)
- [C/C++ for Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) (Highly Recommended)
- [GitLens](https://marketplace.visualstudio.com/items?itemName=eamodio.gitlens): easy to check git history and so on.
- [Git Graph](https://marketplace.visualstudio.com/items?itemName=mhutchie.git-graph)
- [Bracket Pair Colorizer 2](https://marketplace.visualstudio.com/items?itemName=CoenraadS.bracket-pair-colorizer-2)
- [Indent one space](https://marketplace.visualstudio.com/items?itemName=usernamehw.indent-one-space)
- [XML (Red Hat)](https://marketplace.visualstudio.com/items?itemName=redhat.vscode-xml)
- [shell-format](https://marketplace.visualstudio.com/items?itemName=foxundermoon.shell-format)
- [Peacock](https://marketplace.visualstudio.com/items?itemName=johnpapa.vscode-peacock)
- [PlantUML](https://marketplace.visualstudio.com/items?itemName=jebbs.plantuml)

better to enlarge `max_user_watches` also.

```console
$ echo fs.inotify.max_user_watches=524288 >> /etc/sysctl.conf
$ cat /proc/sys/fs/inotify/max_user_watches
$ sudo sysctl -p
```

There is [Visual Studio Code Keyboard shortcuts for Windows](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-windows.pdf) and it userful shortcuts as following

- Deleting tabs when using tabs as spaces: <kbd>⇧ Shift</kbd>+<kbd>⇥ Tab</kbd>
- Switch to next Tab: <kbd>Ctrl</kbd>+<kbd>⇥ Tab</kbd>
- Go back / forward: <kbd>Alt</kbd>+ <kbd>←</kbd> / <kbd>→</kbd>

### Code Server

VSC also provides Web IDE called [Code Server](https://github.com/cdr/code-server/releases), use below command to install Code Server.

```console
$ wget https://github.com/cdr/code-server/releases/download/v3.5.0/code-server_3.5.0_amd64.deb
```

Its setting file is in `.config/code-server/config.yaml`. You can revise `Bind-addr` and `Password` to allow external access.

```console
Bind-addr: 0.0.0.0:9786   # < = Use IP 0.0.0.0 and port 9786 to allow external access
Password: 11111111        # < = define your password, this case is 11111111
```

Now, you can run code server with below command.

```console
$ code-server .
```

### WSL2

By the way, if you use Windows 10 OS, this OS also provides [WSL2](https://github.com/microsoft/WSL2-Linux-Kernel/releases
) after [Windows 10 Versions 1903 and 1909](https://devblogs.microsoft.com/commandline/wsl-2-support-is-coming-to-windows-10-versions-1903-and-1909/). Install Windows 10 and WSL 2 with [Remote - WSL extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl). You can develop your code in VSC via WSL2 also. 

## Terminal Tools

- [ZOC](https://www.emtec.com/zoc/): SSH Client and Terminal Emulator for Windows and macOS.
- [Xshell](https://www.netsarang.com/en/xshell/): The Industry's Most Powerful SSH Client.
- [MobaXterm](https://mobaxterm.mobatek.net/): Enhanced terminal for tabbed SSH client, network tools and so on.


## TFTP Tools

There are some TFTP tools, most of all I use `tftp64` beacuse my development environment is Windows 10.

- [tftp64](http://tftpd32.jounin.net/tftpd32_download.html): for Windows, tftp server, client and syslog server.
- [tftpd-hpa](https://git.kernel.org/pub/scm/network/tftp/tftp-hpa.git): for Linux OS.
- [TftpServer for Mac](https://www.macupdate.com/app/mac/11116/tftpserver): for Mac OS.


## HFS

There is HTTP file server which can run in Windows OS.

- [HFS Server](https://www.rejetto.com/hfs/): HTTP file server.
## Code Comparer

- [Code Compare](https://www.devart.com/codecompare/): a free compare tool designed to compare and merge differing files and folders.

## Coding Convention

Suggest to use default coding configuration by `clang-format` of Visual Studio Code.

- [AStyle](http://astyle.sourceforge.net/): code formatter for the C, C++, C​++/CLI, Objective‑C, C# and Java.

Install `astyle` and there is a case for coding convention as following to format `main.c` or `*.c` and `*.h` files
`style: K&R`, and `Indent: 2`

```cosnole
$ sudo apt-get install astyle
$ astyle --style=kr --indent=spaces=2 -p -U -f main.c
- OR -
$ astyle --style=kr --indent=spaces=2 -p -U -f *.c *.h
```

Below script can help use to fomat all `*.c`, `*.h` and `java` files.
```console
#!/bin/sh

echo "running this script for doing code convention"

astyle -V

for f in $(find ../ -name '*.c' -or -name '*.cpp' -or -name '*.h' -type f)
do
  astyle --style=kr --indent=spaces=2 -p -U -f $f
done

for f in $(find ../ -name '*.java' -type f)
do
  astyle --style=java --indent=spaces=2 -p -U -f $f
done

# after formate the code,we need to rm '*.orig' file
for f in $(find ../ -name '*.orig' -type f)
do
  rm -rf $f
done
```

- [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html): the default formattering tool in VSC.

Below script format `main.c` by `clang-format`.
```console
$ sudo apt-get install clang-format
$ clang-format -i main.c
```

## Source Code Tagging System

- [CScope](http://cscope.sourceforge.net/)
- [GNU Global](https://www.gnu.org/software/global/): source code tagging system.

Use [hostapd](https://w1.fi/hostapd/) as an example, fetch the code and untar it.

```console
$ wget https://w1.fi/releases/hostapd-2.9.tar.gz
$ tar xvf hostapd-2.9.tar.gz
$ cd hostapd-2.9
```

Install global

```console
$ sudo apt-get install global
$ sudo ldconfig
$ global
Usage: global [-adEFGilMnNqrstTvx][-S dir][-e] pattern
       global -c[dFiIMoOPrsT] prefix
       global -f[adlnqrstvx][-L file-list][-S dir] files
       global -g[aEGilMnoOqtvVx][-L file-list][-S dir][-e] pattern [files]
       global -I[ailMnqtvx][-S dir][-e] pattern
       global -P[aEGilMnoOqtvVx][-S dir][-e] pattern
       global -p[qrv]
       global -u[qv]
$ gtags --help
Usage: gtags [-ciIOqvw][-d tag-file][-f file][dbpath]
Options:
--accept-dotfiles
       Accept files and directories whose names begin with a dot.
       By default, gtags ignores them.
-c, --compact
       Make GTAGS in compact format.
       This option does not influence GRTAGS,
       because that is always made in compact format.
--config[=name]
       Print the value of config variable name.
       If name is not specified then print all names and values.
       In addition to the variables listed in the ENVIRONMENT section,
       you can refer to install directories by read only variables:
       bindir, libdir, datadir, localstatedir and sysconfdir.
...
```

in short, the usage of `global` is

```console
$ global (find definition of pattern)
$ global -r (find references of pattern)
$ global -x (shows the detail)
$ global -xg (locates the lines which have specified pattern)
```

Run gtags, make sure it products `GPATH`, `GRTAGS` and `GTAGS` files.

```console
$ gtags
$ ls
CONTRIBUTIONS  COPYING  GPATH  GRTAGS  GTAGS  hostapd  README  src
```

Find definition of pattern

```console
$ global eloop_sock
src/utils/eloop.c
src/utils/eloop_win.c
```

Update database.

```console
$ global -u
```

product HTML file and copy to HTTP folder.

```console
$ htags -ffnsa   # < = w/. Searching
$ sudo cp -r HTML/ /var/www/html/hostapd
```

- [Doxygen](https://www.doxygen.nl/index.html): Generate documentation from source code.

An example for `hostapd` to generate Doxygen document

```console
$ cd ${code_path}
$ doxygen Doxygen
```

## Static Code Analysis Tools

### Lint

- [clang-tidy](https://docs.microsoft.com/zh-tw/cpp/code-quality/clang-tidy?view=msvc-160)
- [CPPCheck](http://cppcheck.sourceforge.net/)

```
# - INSTALL -
$ sudo apt-get update -y; sudo apt-get install cppcheck
# - RUN -
$ cppcheck -j 3 ~/Project         # < = open 3 threads to check source code from Project folder，--enable==error by default
$ cppcheck -j 3 --enable=all ~/Project 
$ cppcheck -j 3 --enable=all --xml 2>err.xml ./   # < = Get Report
```

- [splint](https://splint.org/)

```
$ sudo apt-get update -y; sudo apt-get install -y splint
$ splint test.c +bounds -varuse
```

- [CodeQL](https://securitylab.github.com/tools/codeql/)

## Dynamic Code Analysis Tools 

### [Valgrind](https://www.valgrind.org/)

## Terminal multiplexer

- [Tmux Terminal](https://github.com/tmux/tmux/wiki)

```console
# - INSTALL -
$ sudo apt-get install tmux
# - USAGE -
$ tmux
# - RUN BELOW COMMANDS THEN EXIT -
$ ping 8.8.8.8
$ tmux deattach
# - RUN BELOW COMMAND TO ATTACH AGAIN -
$ tmux attach

```
## Documentation

- Markdown

markdown to pdf.

```console
$ echo "test" > doc.md
$ pandoc doc.md
```

- reStructuredText 

rst to pdf.

```console
$ echo "test" > doc.rst
$ rst2pdf doc.rst 
```

- [Swagger](https://swagger.io/): API Documentation & Design Tools for Teams

~ TBD ~

## Wi-Fi Tool

- [Wireshark](https://www.wireshark.org/)
- [InSSIDer 5](https://www.metageek.com/products/inssider/)
- [wifiinfoview](https://www.nirsoft.net/utils/wifi_information_view.html)
- [airodump-ng](https://www.aircrack-ng.org/doku.php?id=airodump-ng)

## Services

### Web, Mail, FTP, and Telnet server. (Optional)

- [LiteServe](http://www.cmfperception.com/liteserve.html)

## Web Debugging Proxy

- [Fiddler](https://www.telerik.com/fiddler)
