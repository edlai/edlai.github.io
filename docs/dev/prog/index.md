# Computer Programmer Skills

## ANSI C

### [autofree](https://hackmd.io/@ofAlpaca/rJ1NAv8K7?type=view)

### [strtol v.s. atoi](https://stackoverflow.com/questions/3792663/atol-v-s-strtol)

the weakless of `atoi`
```c
int val;

printf("abc to int =", atoi("abc"));
printf("string 0 to int =", atoi("0"));
```
the advantage of `strtol`
```c
errno = 0;    /* To distinguish success/failure after call */
val = strtol(str, &endptr, base);

/* Check for various possible errors */
if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) || (errno != 0 && val == 0)) {
  perror("strtol");
  exit(EXIT_FAILURE);
}
```

`strtol` support different base(hex, dec and so on)
```c
#include <stdlib.h>
int atoi(const char *nptr);
```
 
```c
#include <stdlib.h>
long int
strtol(const char *nptr, char **endptr, int base);
```

### [strdupa v.s. strdup](https://hackmd.io/@ofAlpaca/rJ1NAv8K7?type=view)

### snprintf v.s. sprintf

- Memory Leak

### gethostbyname/gethostbyaddr v.s getaddrinfo/getnameinfo

- IPv6

### Memory Overflow v.s. Memory Leak

### Function Point

### Flexible Array

### SQLite

### evhttp/libevent

~~ TBD ~~