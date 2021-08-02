# Debugging Skills

## Trace Function Enter and Exit

Use `__cyg_profile_func_enter` and `__cyg_profile_func_exit` to trace entering and exiting a function.

***Example:***

=== "C"

``` c linenums="1""
--8<--
docs/engineer/prog/linux_c/src/trace_func_enter_exit/main.c
--8<--
```

***Result:***

``` sh
$ ./main
__cyg_profile_func_enter: func = 0x56206e5437b2, called by = 0x7fa8fc459bf7
__cyg_profile_func_enter: func = 0x56206e543763, called by = 0x56206e5437eb
__cyg_profile_func_enter: func = 0x56206e54371c, called by = 0x56206e543794
__cyg_profile_func_exit: func = 0x56206e54371c, called by = 0x56206e543794
__cyg_profile_func_exit: func = 0x56206e543763, called by = 0x56206e5437eb
result: 20
The address of main:               0x56206e5437b2 0x56206e5437b2
The address of do_calc  function:  0x56206e543763 0x56206e543763
The address of do_multi function:  0x56206e54371c 0x56206e54371c
__cyg_profile_func_exit: func = 0x56206e5437b2, called by = 0x7fa8fc459bf7
```

## Debug Macro

***Example:***

=== "C"

``` c linenums="1""
--8<--
docs/engineer/prog/linux_c/src/trace_print_function_name/main.c
--8<--
```

***Result:***

``` sh
[1627893524 | main.c:27:main()] Here I am
[1627893524 | main.c:22:silly_function()] Here I am
```


## Deassemable

~~ TBD ~~