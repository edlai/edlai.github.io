# System Timer

## Alarm

***Example:***

=== "C"

``` c linenums="1""
--8<--
docs/engineer/prog/linux_c/src/timer_alarm/main.c
--8<--
```

***Result:***

``` sh
```

<!--
## Select
-->

## Settime

***Example:***

=== "C"

``` c linenums="1""
--8<--
docs/engineer/prog/linux_c/src/timer_settime/main.c
--8<--
```

***Result:***

``` sh
```

## Setitimer

***Example:***

=== "C"

``` c linenums="1""
--8<--
docs/engineer/prog/linux_c/src/timer_setitimer/main.c
--8<--
```

***Result:***

``` sh
```

## Timerfd

***Example:***

=== "C"

``` c linenums="1""
--8<--
docs/engineer/prog/linux_c/src/timer_timerfd/main.c
--8<--
```

***Result:***

``` sh
$ ./a.out 0 1 3
0.000: timer started
0.000: read: 1; total=1
1.000: read: 1; total=2
2.000: read: 1; total=3
```



timer_alarm/     timer_select/    timer_setitimer/ timer_settime/   timer_timerfd/