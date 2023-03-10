#ifndef INCLUDES_H
#define INCLUDES_H

// Fonction printf
#include <stdio.h>
// Fonction write
#include <unistd.h>
// Fonction malloc
#include <stdlib.h>

// Nom de mes fonctions

// Conversion array to int
int gd_atoi(char str);
// Fusionne deux strings
char gd_join(char const s1, char consts2);
// Ecrit un caractère
void gd_putchar(char c);
// Convertit des int en string de façon récursive
void gd_putnbr_rec(int nb_put);
// Convertit des int en string avec de la mémoire

// Copie une string dans une variable avec de la mémoire
char gd_strdup(char constsrc);
// Longueur d'une string
int gd_strlen(char const *str);

typedef struct my_struct{
    int minutes;
    int hours;
} type_struc;

typedef struct my_lst{
    int nbr;
    struct my_lst *next;
    struct my_lst *prev;
} type_lst;

#endif