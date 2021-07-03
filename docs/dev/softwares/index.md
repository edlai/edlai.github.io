# Software Tools for Firmware Development

## Code Editor

### Visual Studio Code

Instead of `vi`, highly recommended to use Visual Studio Code(VSC) as a firmware development tools. First of all, just install
[Visual Studio Code](https://code.visualstudio.com/) as a foundation of code editor then don't forget to install its [Recommended extensions](https://code.visualstudio.com/docs/editor/extension-gallery) as following as well.

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

There is [Visual Studio Code Keyboard shortcuts for Windows](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-windows.pdf) and it userful shortcuts as following

- Deleting tabs when using tabs as spaces: <kbd>⇧ Shift</kbd>+<kbd>⇥ Tab</kbd>
- Switch to next Tab: <kbd>Ctrl</kbd>+<kbd>⇥ Tab</kbd>
- Go back / forward: <kbd>Alt</kbd>+ <kbd>←</kbd> / <kbd>→</kbd>

## Terminal Tools

- [ZOC](https://www.emtec.com/zoc/): SSH Client and Terminal Emulator for Windows and macOS.
- [Xshell](https://www.netsarang.com/en/xshell/): The Industry's Most Powerful SSH Client.
- [MobaXterm](https://mobaxterm.mobatek.net/): Enhanced terminal for Windows with X11 server, tabbed SSH client, network tools and so on.

## TFTP tool

- [tftp64](http://tftpd32.jounin.net/tftpd32_download.html)
- [tftpd-hpa](https://git.kernel.org/pub/scm/network/tftp/tftp-hpa.git)


## Code Comparer

- [Code Compare](https://www.devart.com/codecompare/): a free compare tool designed to compare and merge differing files and folders.

## Coding Convention

Suggest to use default coding configuration by `clang-format` of Visual Studio Code.

- [AStyle](http://astyle.sourceforge.net/)
- [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html): the default formattering tool in VSC.



## Source Code Tagging System

- [CScope](http://cscope.sourceforge.net/): I used to use it long time ago.
- [GNU Global](https://www.gnu.org/software/global/)
- [Doxygen](https://www.doxygen.nl/index.html)

An example for `dem` to generate Doxygen document

```console
$ cd ${code_path}
$ doxygen Doxygen
```

## Static Code Analysis Tools

### Lint

- [clang-tidy](https://docs.microsoft.com/zh-tw/cpp/code-quality/clang-tidy?view=msvc-160)
- [CPPCheck](http://cppcheck.sourceforge.net/)
- [CodeQL](https://securitylab.github.com/tools/codeql/)
- [splint](https://splint.org/)
```
$ sudo apt-get update -y; sudo apt-get install -y splint
```

## Dynamic Code Analysis Tools 

### [Valgrind](https://www.valgrind.org/)

## Wi-Fi Tool

- [Wireshark](https://www.wireshark.org/)
- [InSSIDer 5](https://www.metageek.com/products/inssider/)
- [wifiinfoview](https://www.nirsoft.net/utils/wifi_information_view.html)
- [airodump-ng](https://www.aircrack-ng.org/doku.php?id=airodump-ng)

## Web Debugging Proxy

- [Fiddler](https://www.telerik.com/fiddler)