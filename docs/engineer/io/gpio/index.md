# Man-Machine Interfaces

## General Purpose Input Output

An exercise of General Purpose Input Output. Blink LED on target device.

## Content

- [Requirements](#requirements)
- [User Space](#user-space)
- [Kernel Space](#kernel-space)
- [Userspace I/O](#userspace-i-o)
- [Reference](#reference)

## Requirements

- BBG

## User Space

### SHELL

- Using `sysfs` interface    
``` sh
echo 49 > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio49/direction

while :
do
  echo "Press [CTRL+C] to stop.."
  echo "LED ON  -O-"
  echo 0 > /sys/class/gpio/gpio49/value
  sleep 1
  echo "LED OFF -X-"
  echo 1 > /sys/class/gpio/gpio49/value
  sleep 1
done

# do this manually if user pressed "Ctrl-C"
echo 49 > /sys/class/gpio/unexport
```

- PILI
```
TBD
```

### C 

- Using `/dev/mem`

### Python

- Using `mraa`

## Kernel Space

```
#include <linux/gpio.h>
```

## Userspace I/O

Userspace I/O (UIO) 

- Interrupt
- Digital I/O (DIO)



## Requirements

- [Linux PSP GPIO Driver Guide](http://processors.wiki.ti.com/index.php/Linux_PSP_GPIO_Driver_Guide#Useful_docs)
- [gpio.txt](https://www.mjmwired.net/kernel/Documentation/gpio.txt)
- [BeagleBone Green](https://beagleboard.org/green)
- [Raspberry Pi 3 Model B+](https://www.raspberrypi.org/products/raspberry-pi-3-model-b-plus/)
- [MediaTek LinkIt Smart 7688](https://labs.mediatek.com/en/platform/linkit-smart-7688)

## Reference

http://www.righto.com/2016/08/the-beaglebones-io-pins-inside-software.html
https://vadl.github.io/beagleboneblack/2016/07/29/setting-up-bbb-gpio
https://vadl.github.io/images/bbb/P8Header.png
https://vadl.github.io/images/bbb/P9Header.png


## Appendix

### GPIO Pin of BBG

- P9 (starting from ETH port)

| PIN          | NO     | NO     | PIN           |
|--------------|--------|--------|---------------|
| GND          | **1**  | **2**  | GND           |
| 3.3V(VDD)    | **3**  | **4**  | 3.3V (VDD)    |
| 5V (VDD)     | **5**  | **6**  | 5V(VDD)       |
| 5V (SYS)     | **7**  | **8**  | 5V (SYS)      |
|              | **9**  | **10** |               |
| GPIO 30      | **11** | **12** | GPIO 60       |
| GPIO 31      | **13** | **14** | GPIO 40 (PWM) |
| GPIO 48      | **15** | **16** | GPIO 51       |
| GPIO 4       | **17** | **18** | GPIO 5        |
|              | **19** | **20** |               |
| GPIO 3 (PWM) | **21** | **22** | GPIO 2 (PWM)  |
| GPIO 49      | **23** | **24** | GPIO 15       |
| GPIO 117     | **25** | **26** | GPIO 14       |
| GPIO 125     | **27** | **28** |               |
|              | **29** | **30** | GPIO 122      |
|              | **31** | **32** | VDD_ADC       |
| AIN4         | **33** | **34** | GND_ADC       |
| AIN6         | **35** | **36** | AIN5          |
| AIN2         | **37** | **38** | AIN3          |
| AIN0         | **39** | **40** | AIN1          |
| GPIO 20      | **41** | **42** | GPIO 7 (PWM)  |
| GND          | **43** | **44** | GPIO          |
| GND          | **45** | **46** | GPIO          |


- P8 (starting from ETH port)

| PIN           | NO     | NO     | PIN     |
|---------------|--------|--------|---------|
| GND           | **1**  | **2**  | GND     |
|               | **3**  | **4**  |         |
|               | **5**  | **6**  |         |
| GPIO 66       | **7**  | **8**  | GPIO 67 |
| GPIO 69       | **9**  | **10** | GPIO 68 |
| GPIO 45       | **11** | **12** | GPIO 44 |
| GPIO 23 (PWM) | **13** | **14** | GPIO 26 |
| GPIO 47       | **15** | **16** | GPIO 46 |
| GPIO 27       | **17** | **18** | GPIO 65 |
| GPIO 22 (PWM) | **19** | **20** |         |
|               | **21** | **22** |         |
|               | **23** | **24** |         |
|               | **25** | **26** | GPIO 61 |
|               | **27** | **28** |         |
|               | **29** | **30** |         |
|               | **31** | **32** |         |
|               | **33** | **34** |         |
|               | **35** | **36** |         |
|               | **37** | **38** |         |
|               | **39** | **40** |         |
|               | **41** | **42** |         |
|               | **43** | **44** |         |
|               | **45** | **46** |         |

- pingroups

```
# cat /sys/kernel/debug/pinctrl/44e10800.pinmux/pingroups
registered pin groups:
group: pinmux_uart0_pins
pin 92 (PIN92)
pin 93 (PIN93)
```
