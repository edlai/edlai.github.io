//https://ithelp.ithome.com.tw/articles/10160745

int const          = a constant integer
int const *        = a (variable) pointer to a constant integer
int * const        = a constant pointer to a (variable) integer
int * const *      = a pointer to a constant pointer(常數指標) to an integer
int const * *      = a pointer to a pointer to a constant integer(常數)
int const *const * = a pointer to a constant pointer to a constant integer(常數)

int const 和const int 是一樣的。但const * 和* const 是不一樣的。