# C Programming Tips


## Resource

- [Data structures and algorithms](https://github.com/nicehorse06/data-structures-and-algorithms)
- [log2base2](https://www.log2base2.com/): World's First Visual Learning Platform

## Code Snippets

### GCC version

- __STDC_VERSION__
- __STRICT_ANSI__


### Parsing Arguments

- Parsing Arguments with getopt
- Check function input

### Function Call

- Pass a value to a function (call-by-value) (swap two numbers)
- Pass a pointer to a function  (call-by-address)
- Pass a dobule-pointer to a function
- Pass a triple-pointer to a function
- Pass a structure to to a function
- Pass a structure-in-structure to to a function

### String

- [reverse a string]()
- [asprintf]()
- append string
- insert string

### Time

- time(0): get current time stamp

``` c
#include <time.h>
time_t time(time_t* timer)
```

- gettimeofday (thread safe): calculate time consuming

``` c
#include <sys/time.h>
int gettimeofday(struct timeval *restrict tv,
                 struct timezone *restrict tz);
int settimeofday(const struct timeval *tv,
                 const struct timezone *tz);
```

<!--
- timespec_get (C11)
- clock_gettime


```
#include <time.h>

int clock_getres(clockid_t clk_id, struct timespec *res);
int clock_gettime(clockid_t clk_id, struct timespec *tp);
int clock_settime(clockid_t clk_id, const struct timespec *tp);
```
-->

### Timer

- sleep: `while(1)` with `sleep(int)`

``` c
#include <unistd.h>
unsigned int sleep(unsigned int seconds);
```

- alarm: `alarm()` and `signal()`

``` c
#include <unistd.h>
unsigned int alarm(unsigned int seconds);
```

``` c
#include <signal.h>
typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);
```

- select:

- timer_settime

``` c
#include <signal.h>           /* Definition of SIGEV_* constants */
#include <time.h>

int timer_create(clockid_t clockid, struct sigevent *restrict sevp,
                 timer_t *restrict timerid);


int timer_settime(timer_t timerid, int flags,
                  const struct itimerspec *restrict new_value,
                  struct itimerspec *restrict old_value);

Link with -lrt.
```

- setitimer:

``` c
int setitimer(int which, const struct itimerval *value, struct itimerval *ovalue));
  * which
    - ITIMER_REAL : 以系統真實的時間來計算，它送出SIGALRM信號。
    - ITIMER_VIRTUAL : 以該進程在用戶態下花費的時間來計算，它送出SIGVTALRM信號。
    - ITIMER_PROF : 以該進程在用戶態下和內核態下所費的時間來計算，它送出SIGPROF信號。
  * itimerval
    - itimerval的一個實例
```

- timerfd

``` c
#include <sys/timerfd.h>
int timerfd_create(int clockid, int flags);
int timerfd_settime(int fd, int flags, const struct itimerspec *new_value, struct itimerspec *old_value);
int timerfd_gettime(int fd, struct itimerspec *curr_value);
```

Reference

- [高效 Web 伺服器開發](https://hackmd.io/@sysprog/fast-web-server)
- [Patterns in C - Part 5: REACTOR](https://www.adamtornhill.com/Patterns%20in%20C%205,%20REACTOR.pdf)

<!--
### Keyword

auto break case char const continue default do double else enum extern float for goto if int long register return short signed sizeof static struct switch typedef union unsigned void volatile while

### Variant

- volatile, alignment

### Goto

- goto, setjump, longjump






### Number

- [strtol v.s. atoi](src/strtol_and_atoi/main.c)

### File

- read an entire file

### Point
- the usages of pointer

```
$ sudo apt-get install cdecl
$ explain char *(*fptab[])(int)
```
- gcc and glibc versions
- endian
- framebuffer
- volu
- opts
- unset, autofree
- revise process name

- avoid to double free memory point
- check for fuction input
- atoi v.s. strtol
- append log to a log file
- hexdump
- printk
- scanf and ignore the remaining

- Queue



## Library

- enable verbose for libcurl
- evhttpd of libevent

## Resource

- [The Linux Programming Interface](https://man7.org/tlpi/code/online/index.html)
- [軟件開發平台及語言筆記大全(超詳細)](https://www.cntofu.com/book/46/index.html)

- [C 語言入門](https://www.youtube.com/playlist?list=PLY_qIufNHc293YnIjVeEwNDuqGo8y2Emx)
  - [【C 語言入門】20.4 - 使用 scanf 讀入資料的問題](https://www.youtube.com/watch?v=my-0xCJNgoM&ab_channel=FeisStudio)

-[你所不知道的 C 語言：技巧篇 (2017-03-20)](https://www.youtube.com/watch?v=H4Efd9zN00A&ab_channel=.GUTS)
  - [你所不知道的 C 語言：技巧篇 (2019-07-11)](https://www.youtube.com/watch?v=lUFdjk8Nmbg&ab_channel=.GUTS)

- Jserv Homework

-->