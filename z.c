// Created by Susanka on 22. 11. 2018.

#include "functions.h"

CAR* z(CAR* l_list){
    char new_brand[50 + 1], low_case_brand[50 + 1];
    int i, number_of_deleted = 0;
    CAR* aktual = l_list, *deleting, *previous = l_list;

    fgets(new_brand, 50, stdin);
    new_brand[strlen(new_brand) - 1] = '\0';
    for (i = 0; i < strlen(new_brand); i++){
        new_brand[i] = (char)tolower(new_brand[i]);
    }

    while(aktual->next != NULL){
        for (i = 0; i <= strlen(aktual->brand); i++){
            low_case_brand[i] = (char)tolower((aktual->brand)[i]);
        }

        if(strstr(low_case_brand, new_brand) != NULL){
            if(aktual == l_list){
                deleting = aktual;
                l_list = aktual->next;
                aktual = aktual->next;
                free(deleting);
                number_of_deleted++;
            }
            else{
                previous->next = aktual->next;
                deleting = aktual;
                aktual = aktual->next;
                free(deleting);
                number_of_deleted++;
            }
        }
        else{
            previous = aktual;
            aktual = aktual->next;
        }
    }

    for (i = 0; i <= strlen(aktual->brand); i++){
        low_case_brand[i] = (char)tolower((aktual->brand)[i]);
    }
    if(strstr(low_case_brand, new_brand) != NULL){
        if(previous->next == NULL){
            free_linked_list(&l_list);
            printf("Vymazalo sa 1 zaznamov\n");
            return NULL;
        }
        previous->next = NULL;
        deleting = aktual;
        free(deleting);
        number_of_deleted++;
    }

    printf("Vymazalo sa %d zaznamov\n", number_of_deleted);

    return l_list;
}