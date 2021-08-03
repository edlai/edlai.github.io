# Strings Manipulation

## string.h

### asprintf

***Example:***

=== C

``` c linenums="1""
--8<--
docs/engineer/prog/linux_c/src/time_time/main.c
--8<--

***Result:**

``` sh linenums="1""
```


### bcmp
### strtol

***Example:***

=== C

``` c linenums="1""
--8<--
docs/engineer/prog/linux_c/src/time_time/main.c
--8<--

***Result:**

``` sh linenums="1""
```

### strtoll

***Example:***

=== C

``` c linenums="1""
--8<--
docs/engineer/prog/linux_c/src/time_time/main.c
--8<--

***Result:**

``` sh linenums="1""
```

### strtok_r

***Example:***

=== C

``` c linenums="1""
--8<--
docs/engineer/prog/linux_c/src/time_time/main.c
--8<--

***Result:**

``` sh linenums="1""
```


## Extend
## App

[Difference between <string.h> and <strings.h>](https://stackoverflow.com/questions/4291149/difference-between-string-h-and-strings-h)

```
Typically <strings.h> just adds some useful but non-standard additional string functions to the standard header <string.h>. For maximum portability you should only use <string.h> but if you need the functions in <strings.h> more than you need portability then you can use <strings.h> instead of <string.h>.
```