#include "includes.h"
#include <stdlib.h>
#define INT_ARRAY_COUNT 5

int intComparator ( const void * first, const void * second ) {
    int firstInt = * (const int *) first;
    int secondInt = * (const int *) second;
    return firstInt - secondInt;
}
int taille_lst(type_lst * lst){
    int i = 0;
    while(lst){
        lst = lst->next;
        i++;
    }
    return i;
}

type_lst *rajouter(type_lst *lst, int var){
    type_lst *r = lst;
    while(lst->next){ 
        lst = lst->next;
    }
    type_lst *lst2;
    lst2 = (type_lst *)malloc(sizeof(lst2));
    lst2->nbr = var;
    lst2->next = NULL;
    lst->next = lst2;
    return r;
}

type_lst *creer_list(int var){
    type_lst *lst;
    lst = (type_lst *)malloc(sizeof(lst));
    lst->nbr = var;
    return lst;
}

void afficher(type_lst *lst){
    type_lst *r = lst;
    while(lst){
        printf("%i \n", lst->nbr);
        lst = lst->next;
        if(lst == r)
            break;
    }
}
void liberer_memoire(type_lst *lst){
    while(lst){
        type_lst *r = lst->next;
        free(lst);
        lst = r;
    }
}

int main(void){
    int array_list[5] = {5,6,4,2,1};
    //int i = 0;
    //int j = 0;
    qsort( array_list, INT_ARRAY_COUNT, sizeof(int), intComparator );

    //Initialisation premiere lst
    type_lst *lst = creer_list(array_list[0]);
    
    //Ajouter une liste
    lst = rajouter(lst,array_list[1]);
    lst = rajouter(lst,array_list[2]);
    lst = rajouter(lst,array_list[3]);
    //printf("%i \n", taille_lst(lst));
    afficher(lst);
    //liberer_memoire(lst);

}