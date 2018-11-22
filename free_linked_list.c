// Created by Susanka on 22. 11. 2018.

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void free_linked_list(CAR** l_list)
{
    CAR* aktual;

    while (*l_list != NULL) {
        aktual = *l_list;
        (*l_list) = (*l_list)->next;
        free(aktual);
    }

}