// Created by Susanka on 22. 11. 2018.

#include "functions.h"

void k(CAR** l_list){
    if(l_list == NULL){
        exit(0);
    }

    free_linked_list(l_list);
    exit(0);
}

