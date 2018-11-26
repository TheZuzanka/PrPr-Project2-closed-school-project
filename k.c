// Created by Susanka on 22. 11. 2018.

#include "functions.h"

void k(CAR** p_linked_list){
    if(p_linked_list == NULL){                                                                                          //ak list nebol vytvorený ukončí sa program
        exit(0);
    }

    free_linked_list(p_linked_list);                                                                                    //ak bol list vytvorený a nie je prázdny dealokuje sa a končí sa program
    exit(0);
}

