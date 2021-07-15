# Personal Cloud Recordings

<!--
```
$author:   Ching-Wen (Ed) Lai
$date:     May. 2018
$keywords: personal, cloud, recording, mt7688, cellular, uav
```
-->

An exercise of an implementation of personal cloud recordings. Recording the streaming from Surveillance Camera via 4G LTE Cellular Network.

<!--
## Content

* [Concept](#concept)
* [Requirements](#requirements)
* [Background](#background)
* [IP CAM Side](#ip-cam-side)
* [Cloud Server Side](#cloud-server-side)
* [Observation](#observation)
* [Advanced](#advanced)
* [Troubleshooting](#troubleshooting)
-->

## Concept

- Recording the streaming from Surveillance Camera via 4G LTE Cellular Network.

## Requirements

### Hardware


- **Platform:** MT7688 Target Board
- **Webcam:**   Logitech C270 UVC Webcam
- **Cellular:** 4G LTE Modem
- **Finished Goods:**
  ![r](cpe.png)

### Software

- OpenWRT Linux

## Background

### Topology

```
 ---------------------------------
/ Cloud Server (running ffmpeg)  /
---------------------------------
	      /   Cloud:   [2001:19f0:7001:111a:5400:1ff:fe5c:4f86]
        ______
             /
          .-~~~-.
  .- ~ ~-(       )_ _
 /                     ~ -.
|         4G LTE NW         \
 \                         .'
   ~- . _____________ . -~
              /
             /  IPCam:   http://[2001:b400:e25b:d8b6:26c:ac02:cccd:6e8f]:8080/?action=stream
 ----------------------------------
/ IP CAMs (running mjpg-streamer) /
----------------------------------
```

## Running

### IPCam Side

- Issue `mjpg_streamer` command and to enable streaming service

  ``` console
  # mjpg_streamer -i "/usr/lib/input_uvc.so -d /dev/video0 " -o "/usr/lib/output_http.so -w /www/webcam -p 8080"
  MJPG Streamer Version.: 2.0
   i: Using V4L2 device.: /dev/video0
   i: Desired Resolution: 640 x 480
   i: Frames Per Second.: not limited
   i: Format............: JPEG
   i: TV-Norm...........: DEFAULT
   o: www-folder-path...: /www/webcam/
   o: HTTP TCP port.....: 8080
   o: username:password.: disabled
   o: commands..........: enabled
  ```

### Cloud Server Side

- Install required packages

  ``` console
  # apt-get install ffmpeg
  # apt-get install iftop    # (Optional)
  ```

- Issue `ffmpeg` command and point out the IPcam address

  ``` console
  # ffmpeg -f mjpeg -r 5 -i "http://[2001:b400:e25b:d8b6:26c:ac02:cccd:6e8f]:8080/?action=stream" -r 5 ./video.avi
  ```

- To force the frame rate of the input file (valid for raw formats only) to 5 fps and the frame rate of the output file to 5 fps:
  [man](https://linux.die.net/man/1/ffmpeg)
  - **- i:** filename, input file name
  - **- b:** bitrate, Set the video bitrate in bit/s (default = 200 kb/s).
  - **- vcodec:** codec, Force video codec to codec. Use the "copy" special value to tell that the raw codec data must be copied as is.
  - **- r:** fps, Set frame rate (Hz value, fraction or abbreviation), (default = 25).
  - **- y:** Overwrite output files.

- System will record the streaming

  ``` console
  ffmpeg version 3.2.10-1~deb9u1 Copyright (c) 2000-2018 the FFmpeg developers
    built with gcc 6.3.0 (Debian 6.3.0-18) 20170516
    configuration: --prefix=/usr --extra-version='1~deb9u1' --toolchain=hardened --libdir=/usr/lib/x86_64-linux-gnu --incdir=/usr/include/x86_64-linux-gnu --enable-gpl --disable-stripping --enable-avresample --enable-avisynth --enable-gnutls --enable-ladspa --enable-libass --enable-libbluray --enable-libbs2b --enable-libcaca --enable-libcdio --enable-libebur128 --enable-libflite --enable-libfontconfig --enable-libfreetype --enable-libfribidi --enable-libgme --enable-libgsm --enable-libmp3lame --enable-libopenjpeg --enable-libopenmpt --enable-libopus --enable-libpulse --enable-librubberband --enable-libshine --enable-libsnappy --enable-libsoxr --enable-libspeex --enable-libssh --enable-libtheora --enable-libtwolame --enable-libvorbis --enable-libvpx --enable-libwavpack --enable-libwebp --enable-libx265 --enable-libxvid --enable-libzmq --enable-libzvbi --enable-omx --enable-openal --enable-opengl --enable-sdl2 --enable-libdc1394 --enable-libiec61883 --enable-chromaprint --enable-frei0r --enable-libopencv --enable-libx264 --enable-shared
    libavutil      55. 34.101 / 55. 34.101
    libavcodec     57. 64.101 / 57. 64.101
    libavformat    57. 56.101 / 57. 56.101
    libavdevice    57.  1.100 / 57.  1.100
    libavfilter     6. 65.100 /  6. 65.100
    libavresample   3.  1.  0 /  3.  1.  0
    libswscale      4.  2.100 /  4.  2.100
    libswresample   2.  3.100 /  2.  3.100
    libpostproc    54.  1.100 / 54.  1.100
  Input #0, mjpeg, from 'http://[2001:b400:e25b:d8b6:26c:ac02:cccd:6e8f]:8080/?action=stream':
    Duration: N/A, bitrate: N/A
      Stream #0:0: Video: mjpeg, yuvj422p(pc, bt470bg/unknown/unknown), 640x480, 5 tbr, 1200k tbn, 5 tbc
  [swscaler @ 0x5636a0d10480] deprecated pixel format used, make sure you did set range correctly
  Output #0, avi, to './video1.avi':
  ```


<!--
# ffmpeg -f mjpeg -r 5 -i "http://openwrt:openwrt@localhost:8080/?action=stream" -r 5 ./video.avi
-->

## Observation

### Data Usage (iftop) on Cloud Recording Server

- Package Observation of `iftop`
  ![r](speed.png)

- Observation of `ffmpeg`
  ![r](ffmpeg.png)

- Observation of CPU Usage for VPS
  ![r](usage-cpu.png)

- Observation of Disk Operations  for VPS
  ![r](usage-disk.png)

 - Observation of Network Usage for VPS
  ![r](usage-network.png)

- Observation of Price for renting the Cloud Server
  - TBD

### Advanced

#### OnViF

- [OnViF](https://www.onvif.org/)
- [onvif-qt-server-client](https://github.com/hummatli/onvif-qt-server-client)

#### Fail-Safe

- The Fail-Safe by SMS

#### Natted

- For IPv4 Cellular Network (Natted or NAT’d), we can do so via VPN (Virtual Private Server) Network.

#### Network Remote Management

- Network Management Server can monitor the Package usages of `Cloud Server` and `IP CAMs`.
- If there is any Device which is not working then Supervisor can perform the Fail-Safe (Redundancy) actions
- There is the Recommendation Topology (Ideally) in this case.

  ```
   ---------------------------------------------
  /       Network Management Server (NMS)       /
  ---------------------------------------------
              /              /  NMS: to Monitor Cloud Server and IPCam's actions
             /              /
            /              /
           /   --------------------------------
          /   / Cloud Server (running ffmpeg) /
         /    --------------------------------
        /                /  Cloud: [2001:19f0:7001:111a:5400:1ff:fe5c:4f86]
       /                /
      /                /  IPCam: http://[2001:b400:e25b:d8b6:26c:ac02:cccd:6e8f]:8080/?action=stream
   ------------------------------------------
  /      IP CAMs (running mjpg-streamer)     /
  -------------------------------------------
  ```

### PlayBack

- Possible to Playback/Play on the WebUI/Screen (2x2 by Bootstrap)
  ```
  <html>
    <head>
      <title>MJPG-Streamer - Stream Example</title>
    </head>
    <body>
      <center>
        <img src="http://[2001:b011:200b:120c:2e0:4cff:fe00:e1b]:8080/?action=stream" />
      </center>
     </body>
  </html>
  ```

### Recognition

- Export to JPG file pre second [man](https://trac.ffmpeg.org/wiki/Chinese_Font_%E4%BB%8E%E8%A7%86%E9%A2%91%E4%B8%AD%E6%AF%8FX%E7%A7%92%E5%88%9B%E5%BB%BA%E4%B8%80%E4%B8%AA%E7%BC%A9%E7%95%A5%E5%9B%BE)
  ```
  # ffmpeg -i stream.mp4 -vf fps=1 out%02d.jpg
  ```

- Delect the duplication

- Inmport to Application (LPR or Face recognition)

### Warpped

- How to warp RTSP stream to HTML5
- [video.js](https://github.com/videojs/video.js)
- [m3u8](https://zh.wikipedia.org/wiki/M3U#M3U8)

## Reference

- [7 ways to stream RTSP on the page](https://flashphoner.com/7-ways-to-stream-rtsp-on-the-page/)


<!--
## Troubleshooting

### Modem Driver crashed

- WWAN driver was crashed but caming back again

  ```
  [15811.934613] ------------[ cut here ]------------
  [15811.939404] WARNING: CPU: 0 PID: 0 at net/sched/sch_generic.c:320 dev_watchdog+0x174/0x260
  [15811.947857] NETDEV WATCHDOG: wwan0 (qmi_wwan): transmit queue 0 timed out
  [15811.954778] Modules linked in: uvcvideo videobuf2_v4l2 input_core videobuf2_vmalloc videobuf2_memops videobuf2_core v4l2_common videodev i2c_dev i2c_core dma_shared_buffer pppoe ppp_async option usb_wwan qmi_wwan pppox ppp_generic nf_conntrack_ipv6 mt76x2e mt7603e mt76 mac80211 iptable_nat ipt_REJECT ipt_MASQUERADE cfg80211 cdc_ncm cdc_ether xt_time xt_tcpudp xt_state xt_nat xt_multiport xt_mark xt_mac xt_limit xt_conntrack xt_comment xt_TCPMSS xt_REDIRECT xt_LOG xt_FLOWOFFLOAD xt_CT usbserial usbnet slhc nf_reject_ipv4 nf_nat_redirect nf_nat_masquerade_ipv4 nf_conntrack_ipv4 nf_nat_ipv4 nf_nat nf_log_ipv4 nf_flow_table_hw nf_flow_table nf_defrag_ipv6 nf_defrag_ipv4 nf_conntrack_rtcache nf_conntrack iptable_mangle iptable_filter ip_tables crc_ccitt compat cdc_wdm cdc_acm ip6t_REJECT nf_reject_ipv6
  [15812.026616]  nf_log_ipv6 nf_log_common ip6table_mangle ip6table_filter ip6_tables x_tables mii leds_gpio ohci_platform ohci_hcd ehci_platform ehci_hcd gpio_button_hotplug usbcore nls_base usb_common
  [15812.044564] CPU: 0 PID: 0 Comm: swapper Not tainted 4.14.32 #0
  [15812.050473] Stack : 00000000 00000000 804b7502 00000032 80457d44 80457967 80401a2c 00000000
  [15812.058980]         804b3650 00000140 ffffffff 00000200 00200000 00000001 87c09de0 b3f6da09
  [15812.067476]         00000000 00000000 804b0000 00000108 00000000 34206465 2e34312e 23203233
  [15812.075972]         74747562 77f4a2c0 00000000 685f6e6f 00000000 00000000 80281e64 80426418
  [15812.084456]         00000009 00000140 ffffffff 00000200 00000001 801e4130 00000000 804b0000
  [15812.092954]         ...
  [15812.095442] Call Trace:
  [15812.097946] [<8000e374>] show_stack+0x74/0x104
  [15812.102473] [<800244f0>] __warn+0x110/0x118
  [15812.106730] [<80024528>] warn_slowpath_fmt+0x30/0x3c
  [15812.111778] [<80281e64>] dev_watchdog+0x174/0x260
  [15812.116593] [<8005970c>] call_timer_fn.isra.4+0x24/0x84
  [15812.121894] [<80059954>] run_timer_softirq+0x1e8/0x1f4
  [15812.127135] [<803782e4>] __do_softirq+0x164/0x2a0
  [15812.131923] [<80009658>] handle_int+0x138/0x144
  [15812.136537] [<8000b14c>] r4k_wait_irqoff+0x18/0x24
  [15812.141400] [<80049554>] do_idle+0xac/0xd8
  [15812.145565] [<80049768>] cpu_startup_entry+0x18/0x20
  [15812.150605] [<8047ebb8>] start_kernel+0x45c/0x47c
  [15812.155390] ---[ end trace f5d4343920baff44 ]---

  root@OpenWrt:/# ping 8.8.8.8
  PING 8.8.8.8 (8.8.8.8): 56 data bytes
  ^C
  --- 8.8.8.8 ping statistics ---
  33 packets transmitted, 0 packets received, 100% packet loss
  root@OpenWrt:/# ping ipv6.google.com
  PING ipv6.google.com (2404:6800:4008:c00::64): 56 data bytes
  64 bytes from 2404:6800:4008:c00::64: seq=0 ttl=44 time=46.217 ms
  64 bytes from 2404:6800:4008:c00::64: seq=1 ttl=44 time=46.256 ms
  64 bytes from 2404:6800:4008:c00::64: seq=2 ttl=44 time=45.440 ms
  ^C
  --- ipv6.google.com ping statistics ---
  3 packets transmitted, 3 packets received, 0% packet loss
  round-trip min/avg/max = 45.440/45.971/46.256 ms
  root@OpenWrt:/# ping 8.8.8.8
  PING 8.8.8.8 (8.8.8.8): 56 data bytes
  64 bytes from 8.8.8.8: seq=0 ttl=55 time=41.590 ms
  64 bytes from 8.8.8.8: seq=1 ttl=55 time=39.984 ms
  64 bytes from 8.8.8.8: seq=2 ttl=55 time=39.218 ms
  ^C
  --- 8.8.8.8 ping statistics ---
  3 packets transmitted, 3 packets received, 0% packet loss
  round-trip min/avg/max = 39.218/40.264/41.590 ms
  ```

### Dormancy

- Modem ran into `Dormancy` if Cloud recording Server doesn't grab any streaming and Modem also not any Internet access.

  ```
  http://[2001:b400:e25b:d8b6:26c:ac02:cccd:6e8f]:8080/?action=stream: Connection timed out
  ```

- we have to ask modem sending any package then modem will re-accessing Internet again(RRC idle -> RRC Connected)
  ```
  root@OpenWrt:~# ping 8.8.8.8
  PING 8.8.8.8 (8.8.8.8): 56 data bytes
  64 bytes from 8.8.8.8: seq=0 ttl=55 time=65.649 ms
  64 bytes from 8.8.8.8: seq=1 ttl=55 time=52.223 ms
  64 bytes from 8.8.8.8: seq=2 ttl=55 time=52.929 ms
  ```
-->

