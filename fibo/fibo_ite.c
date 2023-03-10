#include <stdio.h>
int fibonacci(int max_fib) {
    int ret_fib;
    int first;
    int second;

    first = 0; 
    second = 1;

    //0 1   2   3   4   5   6   7   8
    //0	1	1	2	3	5	8	13	21
    if(max_fib > 1){
        while(max_fib > 1){
            ret_fib = first + second;
            first = second;
            second = ret_fib;
            max_fib--;
        }
    }
    else{
        return max_fib;
    }
    return ret_fib;
}

int main(void) {
    int fib;

    fib = fibonacci(6);
    printf("%i\n", fib);
    return(1);
}