// Created by Susanka on 22. 11. 2018.

#include "functions.h"

CAR* z(CAR* l_list){
    char new_brand[50 + 1], low_case_brand[50 + 1];
    int i, number_of_deleted = 0;
    CAR* aktual = l_list, *deleting;

    fgets(new_brand, 50, stdin);
    new_brand[strlen(new_brand) - 1] = '\0';
    for (i = 0; i < strlen(new_brand); i++){
        new_brand[i] = (char)tolower(new_brand[i]);
    }

    while(aktual->next->next != NULL){
        for (i = 0; i < strlen(aktual->brand); i++){
            low_case_brand[i] = (char)tolower((aktual->next->brand)[i]);
        }

        if(strcmp(low_case_brand, new_brand) == 0){
            deleting = aktual->next;
            aktual->next = aktual->next->next;
            free(deleting);
        }
    }

    return l_list;
}