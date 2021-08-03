# Strings Manipulation


bcmp()	比較內存(字符串)的前n個字節是否相等
bcopy()	復制內存(字符串)
bzero()	將內存（字符串）前n個字節清零
memcpy()	復制內存內容(忽略\0)
memmove()	復制內存內容（可以處理重疊的內存塊）
memset()	將內存的前n個字節設置為特定的值
strcat()	連接字符串
strchr()	查找某字符在字符串中首次出現的位置
strcmp()	比較字符串（區分大小寫）
strcoll()	根據環境變量LC_COLLATE來比較字符串
strcspn()	計算字符串str中連續有幾個字符都不屬於字符串accept
strlen()	返回字符串的長度
strncat()	在字符串的結尾追加n個字符
strncpy()	復制字符串的前n個字符
strpbrk()	返回兩個字符串中首個相同字符的位置
strrchr()	查找某字符在字符串中最後一次出現的位置
strspn()	計算字符串str中連續有幾個字符都屬於字符串accept
strstr()	返回字符串中首次出現子串的地址
strtok()	字符串分割
stpcpy()	將字符串復制到數組
strcpy()	字符串復制
stricmp()	比較字符串（不區分大小寫）
strcmpi()	比較字符串(不區分大小寫)，stricmp()的宏定義
strlwr()	將字符串轉換為小寫
strupr()	將字符串轉換為大寫
strncmp()	比較字符串的前n個字符（區分大小寫）
strnicmp()	比較字符串的前n個字符（區分大小寫）
strncmpi()	比較兩個字符串的前n個字符（不區分大小寫）
strrev()	字符串逆置（倒序、逆序）
strset()	將字符串的所有字符設置為指定字符
strnset()	將字符串的前n個字符設置為指定字符


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