# Memory Layout

- understand memory layout to write clean code.

## Layout

- text: code
- data:
- bss: Uninitialized data segment
- stack: Stack segment. For example, Recursion.
- heap: malloc
- system:

## Examples

***Example:*** m1.c

=== "C"

``` c linenums="1"
--8<--
docs/engineer/prog/linux_c/src/memory_layout/m1.c
--8<--
```

***Result:***

``` sh
$ gcc -o m1 m1.c
$ size m1
   text    data     bss     dec     hex filename
   1415     544       8    1967     7af m1
```

***Example:*** m2.c

=== "C"

``` c linenums="1" hl_lines="3"
--8<--
docs/engineer/prog/linux_c/src/memory_layout/m2.c
--8<--
```

***Result:***

``` sh
$ gcc -o m2 m2.c
$ size m2
   text    data     bss     dec     hex filename
   1415     544       8    1967     7af m2
```

***Example:*** m3.c

=== "C"

``` c linenums="1" hl_lines="7"
--8<--
docs/engineer/prog/linux_c/src/memory_layout/m3.c
--8<--
```

***Result:***

bss
```
$ size a.out
   text    data     bss     dec     hex filename
   1415     544      16    1975     7b7 a.out
```

***Example:*** m4.c

=== "C"

``` c linenums="1"  hl_lines="7"
--8<--
docs/engineer/prog/linux_c/src/memory_layout/m4.c
--8<--
```

***Result:***

data
```
   text    data     bss     dec     hex filename
   1415     548      12    1975     7b7 a.out
```

***Example:*** m5.c

=== "C"

``` c linenums="1"  hl_lines="3"
--8<--
docs/engineer/prog/linux_c/src/memory_layout/m5.c
--8<--
```

***Result:***

data
```
   text    data     bss     dec     hex filename
   1415     552       8    1975     7b7 a.out
```

##Usage

It's better to check the return value from `malloc`.

``` c
int *arr = malloc(sizeof(*arr));

if (arr == NULL)
{
  printf("Memory allocation failed");
  return;
}

```

It's better to free useless memory and point to Null.

```
if (arr)
{
  free (addr);
  addr = NULL;
}
```

## bcopy

https://doc.bccnsoft.com/docs/cfuncs/string/bcopy.html

