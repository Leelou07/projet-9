#include <unistd.h>
#include <stdio.h>

//fonction initiale
void gd_putchar(char c){
    write(1, &c, 1);
}

void gd_putint(int a){
    int b, c;
   
    if(a <= 9){
        a = a + '0';
        write(1, &a, 1);
    }
 
    else if(a <= 99){
        b = a / 10;
        a = a % 10;
        
        b = '0' + b;
        a = '0' + a;
    
        write(1, &b, 1);
        write(1, &a, 1);
    
    }
 
    else if(a <= 999){
        b = a / 100;
        c = (a % 100) / 10;
        a = a % 10;
    
        b = '0' + b;
        c = '0' + c;
        a = '0' + a;
    
        write(1, &b, 1);
        write(1, &c, 1); 
        write(1, &a, 1);
    }
}

//calcule la taille du str
int gd_strlen(char *str){
    int i;
    i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

//affiche le str
int gd_putstr(char *str){
    int size = gd_strlen(str);
    write(1, str, size);

    return size;
}

//fonction primaire
int main(void) {
    int nb_put = gd_putstr("Coucou");
    printf("\nLa taille est de : %d", nb_put);
    printf("\n");
    gd_putint(999);
    printf("\n");
    /*nb=put =6*/
}