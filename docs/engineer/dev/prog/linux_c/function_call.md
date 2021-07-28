# Function Argument

## Call by Value

## Call by Address

### Pass a value to a function (swap two numbers)

### Pass a address to a function  (call-by-address)

### Pass a dobule-pointer to a function

### Pass a triple-pointer to a function

### Pass a structure to to a function

### Pass a structure-in-structure to to a function

### Pass a function point to a function

## D

### 


``` c
#define DUMP(func, call) \
  printf("%s: func = %p, called by = %p\n", __FUNCTION__, func, call)

void __attribute__((no_instrument_function))
__cyg_profile_func_enter(void *this_func, void *call_site)
{
  DUMP(this_func, call_site);
}

void __attribute__((no_instrument_function))
__cyg_profile_func_exit(void *this_func, void *call_site)
{
  DUMP(this_func, call_site);
}
```

Print function point

``` c
int do_calc(int a, int b)
{
  return do_multi(a, b);
}

printf("The address of the do_calc  is = %p\n", do_calc);
```
