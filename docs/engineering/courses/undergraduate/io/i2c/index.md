# Man-Machine Interfaces

## Inter-Integrated Circuit

## Content

- [Conpect](#conpect)
- [Requirements](#requirements)
- [Installation](Installation)
- [Programming]()

## Conpect


| Function | I2C                     | SMBus  |
|----------|-------------------------|--------|
| Clock    | SLC (Serial clock line) | SMBCLK |
| Data     | SDA (Serial data line)  | SMBDAT |




## Requirements

- BeagleBone Black

## Precondition

```
# apt-get install libi2c-dev
# apt-get install i2c-tools
# apt-get install python-smbus
```


## Programming



### Shell

| CLI      | Description                  |
|----------|------------------------------|
|i2cdetect | i2c device detects |
|i2cdump   | Dump register value     |
|i2cget    | Read register value    |
|i2cset    | Write register         |



# i2cdetect -l
i2c-1   i2c             OMAP I2C adapter                        I2C adapter
i2c-2   i2c             OMAP I2C adapter                        I2C adapter  #<= Cap
i2c-0   i2c             OMAP I2C adapter                        I2C adapter  #<= Internal

# i2cdetect -y -r 0
     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- --
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
20: -- -- -- -- UU -- -- -- -- -- -- -- -- -- -- --
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
50: UU -- -- -- -- -- -- -- -- -- -- -- -- -- -- --     #<= EEPROM, accessing by 24c256
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
70: -- -- -- -- -- -- -- --

# i2cdetect -y -r 2
     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- --
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
50: -- -- -- -- UU UU UU UU -- -- -- -- -- -- -- --      #<= Cap
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
70: -- -- -- -- -- -- -- --

-


```
# i2cset -y 0 0x20 0x12 0x00
```

- Reading Serial number from EEPROM of BBG (offset 4 byte then hexdump 24 byte)
```
# hexdump -e '8/1 "%c"' /sys/bus/i2c/devices/0-0050/eeprom -s 4 -n 24
A335BNLTBBG1BBG216113134
```
# cat /sys/bus/i2c/devices/0-0050/modalias
  i2c:24c256

# dmesg | grep 24c
[    1.527894] at24 2-0054: 32768 byte 24c256 EEPROM, writable, 1 bytes/write
[    1.528408] at24 2-0055: 32768 byte 24c256 EEPROM, writable, 1 bytes/write
[    1.528654] at24 2-0056: 32768 byte 24c256 EEPROM, writable, 1 bytes/write
[    1.528866] at24 2-0057: 32768 byte 24c256 EEPROM, writable, 1 bytes/write
[    1.943267] at24 0-0050: 32768 byte 24c256 EEPROM, writable, 1 bytes/write


# cat /proc/kallsyms | grep at24
c08fb370 t at24_remove
c08fb3c4 t at24_write
c08fb468 t at24_read
c08fb514 t at24_eeprom_write_i2c
c08fb6cc t at24_eeprom_write_smbus_byte
c08fb7e0 t at24_eeprom_write_smbus_block
c08fb928 t at24_eeprom_read_i2c
c08fbad4 t at24_eeprom_read_mac
c08fbbf4 t at24_eeprom_read_serial
c08fbd2c t at24_eeprom_read_smbus
c08fbe58 t at24_probe
c0d86410 r at24_ids
c13556c8 t at24_init
c136dbe8 t at24_exit
c13bedec t __initcall_at24_init6
c14b5808 d at24_driver

### C

- C Function List

| Function         | User Space (SMBus)        | Kernel Space  |
|------------------|---------------------------|---------------|
| HEADER File      | `i2c.h` `i2c-dev.h`       |             |
| START  Condition |                           | i2c_start() |
| STOP   Condition |                           | i2c_stop()  |
| Read             | i2c_smbus_read_byte_data  | sendbytes() |
| Write            | i2c_smbus_write_word_data | readbytes() |

## Case

### Reading Serial number from EEPROM of BBG  

### Monitor the CPU temperature of IPC
```
# apt-get install lm-sensors 
# sensors-detect
```

## Advanced

- Reading AM335x Thermal Considerations

## Appendix

### BBG

## Reference

- [Beaglebone BBB eeprom的擦写](https://yixiaoyang.github.io/articles/2015-07/bbb-eeprom)

