#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h>

int gd_atoi(char *str){
    int i = 0;
    int reg;
    int neg = 1;

    while(str[i]){
        if((str[i] >=48 && str[i] <= 59) || (str[i] == 4))
            break;
        i++;
    }
    //and && // or ||
    if(str[i] == 43 || str[i] == 45){
        if(str[i] == 45)
            neg = -1;
        i++;
    }
    int first_nb = str[i] - 48;





    gd_putnbr(first_nb);
    return(ret*neg);
}

int main(void){
    int nb = gd_atoi("-51234");
    gd_putnbr(nb);
    gd_putchar("\n");
}