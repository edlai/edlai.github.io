# Lifetime Measurement

## Memory Endurance Test/Capacity Check

Enable `CONFIG_MTD_TESTS`

```
"Device Drivers" -> "Memory Technology Device (MTD) support" -> "MTD tests support"
```

Make

```
make ARCH=mips CROSS_COMPILE=arm-linux-gnueabihf- modules
```


- [使用linux的MTD tests support测试flash性能](https://blog.csdn.net/gp_scoprius/article/details/53257056)