// Created by Susanka on 22. 11. 2018.

#include "functions.h"

void free_linked_list(CAR** p_linked_list)
{
    CAR* aktual;

    while (*p_linked_list != NULL){                                                                                     //dealokovanie celého linked listu
        aktual = *p_linked_list;                                                                                        //adresu uložíme do pomocnej premennej aby sme nestratili jej referenciu
        (*p_linked_list) = (*p_linked_list)->next;                                                                      //začiatok listu o jedno posunieme
        free(aktual);                                                                                                   //prvý prvok pôvodnélo zoznamu dealokujeme
    }

}