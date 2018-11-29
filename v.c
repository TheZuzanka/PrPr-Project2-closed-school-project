// Created by Susanka on 22. 11. 2018.

#include "functions.h"

void v(CAR** p_linked_list){
    CAR* aktual = *p_linked_list;
    int place = 1;

    while ( aktual != NULL){                                                                                            //pokiaľ je list prázdny, nevypíše sa nič
        printf("%d.\n", place++);
        print_node(aktual);
        aktual = aktual->next;
    }
}