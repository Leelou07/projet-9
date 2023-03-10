#include <stdio.h>
int fibonacci(int max_fib) {
    int ret_fib;
    if(max_fib>=2){
        ret_fib = fibonacci(max_fib-1) + fibonacci(max_fib-2);
    }
    else if(max_fib == 0){
        ret_fib = 0;
    }
    else if(max_fib > 0 && max_fib < 3){
        ret_fib = 1;
    }
    return ret_fib;
}

int main(void) {
    int fib;

    fib = fibonacci(3);
    printf("%i\n", fib);
    return(1);
}