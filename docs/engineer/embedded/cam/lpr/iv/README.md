# Surveillance System

## LPR - License Plate Recognition

## Intelli Vision

## Requirements

### Hardware

- HD-IP Cam
  - Default IP: http://192.168.1.110
  - Default ID/PW: admin/[empty]
  - 
- Aplex IPC (running Ubuntu 16.04)
- PoE Switch

### Software

- Ubuntu 16.04
- IntelliVision LPR
- Hisee App

## Background

### Topology

```
		    +---- IPCam      192.168.167.30
                    +---- IPCam      192.168.167.40
		    |
   Router -------- PoE -- IPC(Small) 192.168.167.68 http://192.168.167.68:1700/intelli-vision/Reports.html
 (192.168.167.1)    |
                    +---- IPC(Big)   192.168.167.57 http://192.168.167.57:1700/intelli-vision/Reports.html
                    |
                     ---- PC     192.168.167.X   (Optional)

```

## Installation

1. Install `Ubuntu 16.04` on Aplex IPC
  - tbd: fixed IP
2. Install `IntelliVision LPR`
  - package
    ```
    # apt-get update
    # apt-get install openssh-server
    # apt-get install openssh-client
    # apt-get install mysql-server       (KEY Point, using `empty password`)
    # apt-get install mysql-client
    ```
   - IV
    ```
    # chmod 777 ./install-deps.sh
    # ./install-deps.sh
    # dpkg -i iv_lpr_service_20180108_amd64.deb
      Selecting previously unselected package iv-lpr-service.
      (Reading database ... 193868 files and directories currently installed.)
      Preparing to unpack iv_lpr_service_20180108_amd64.deb ...
      Unpacking iv-lpr-service (18.01.08) ...
      /var/lib/dpkg/tmp.ci/preinst: line 9: /etc/init.d/ivlprserviceapp: No such file or directory  #<= normal?
      Setting up iv-lpr-service (18.01.08) ...
      insserv: warning: script 'ivlprserviceapp' missing LSB tags and overrides
      Processing triggers for systemd (229-4ubuntu21.1) ...
      Processing triggers for ureadahead (0.100.0-19) ...
    # ps ax | grep LPR
      5314 ?        Sl     0:00 ./LPRApp
    ```
  
3. Install `TeamViewer` (Optional)
  - setup TV
    ```
    # wget https://download.teamviewer.com/download/linux/teamviewer_amd64.deb
    # dpkg -i teamviewer_amd64.deb
    # apt-get install -f                 #<= run this if you get any dependency problems
    ```
  - setup fixed password on TV
  - enable "Start TeamViewer with system"

## Setting

1. Navigate to IV webpage
   ```
   http://192.168.167.68:1700/intelli-vision/Setting.html
   ```
2. Input Key
   ```
   Evrq96oCqwyqXqaabbuuvvCCyyEM
   ```
3. Navigate to `Settings` > `Common Settings`, using below `Country`
   ```
   Taiwan
   ```
4. Navigate to `Settings` > `Setting` > `Add New Camera`
   - Enter Camera Details > IP Camera > 
   ```
   rtsp://admin:@192.168.167.40/1/h264major               #<= Default
   rtsp://user:12345678@192.168.167.30/1/h264major        #<= with ID/PW
   ```
5. Navigate to `Reports`, make sure LPR can get some results
   - Playing TC#01 on the screen in the meantime

6. Navigate to `Watchlist` > `Import from file`
   - import the	`watchlist.txt` to IV-LPR

7. 

## Test case

- TC#1: 10 clean car-plant and repecting each 10 seconds
- TC#2: 


## Remove

- Remove 
  ```
  # dpkg -remove iv-lpr-service
  ```

## Troubleshooting 

### HD-IP Cam

1. `HD-IP Cam` did `restore-to-default` by it-self

2. 固定開啟夜視 (IR)

3. 如何手動對焦 (Focus)

### IV
2. IV
   ```
   /var/lib/dpkg/tmp.ci/preinst: line 9: /etc/init.d/ivlprserviceapp: No such file or directory  #<= normal?
   ```

3. Loading
  ```
  top - 12:56:58 up  1:31,  4 users,  load average: 6.83, 5.90, 5.34                #<= 6.83 ??
  Tasks: 223 total,   4 running, 219 sleeping,   0 stopped,   0 zombie
  %Cpu(s): 39.9 us, 21.1 sy, 36.4 ni,  2.5 id,  0.1 wa,  0.0 hi,  0.0 si,  0.0 st
  KiB Mem :  3962040 total,   213200 free,  1743808 used,  2005032 buff/cache
  KiB Swap:  4113404 total,  4113404 free,        0 used.  1730272 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
  5314 root      20   0 3362140 434092  60720 S 233.6 11.0 151:24.96 LPRApp         #<= 233.6 ??
  ```
  A:
  文件上有建議要有獨立顯卡 / i5 ,
  input解析度不要超過720p@30
  與可以input更小的解析度去看消耗cpu 的變化
## Document

1. IntelliVision USER GUIDE
2. Installation GUIDE
