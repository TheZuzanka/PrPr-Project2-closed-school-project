// Created by Susanka on 22. 11. 2018.

#include "functions.h"

CAR* a(CAR* l_list){
    char new_brand[50 + 1], low_case_brand[50 + 1];
    int i, number_of_changes = 0, year;
    CAR* aktual = l_list;

    fgets(new_brand, 50, stdin);
    new_brand[strlen(new_brand) - 1] = '\0';
    for (i = 0; i < strlen(new_brand); i++){
        new_brand[i] = (char)tolower(new_brand[i]);
    }
    scanf("%d", &year);
    getchar();

    while(aktual != NULL){
        for (i = 0; i <= strlen(aktual->brand); i++){
            low_case_brand[i] = (char)tolower((aktual->brand)[i]);
        }

        if(strstr(low_case_brand, new_brand) != NULL && year == aktual->year){
            aktual->price = (aktual->price) - 100;
            number_of_changes++;
        }

        //printf("aktual = %s\n", aktual->brand);
        aktual = aktual->next;
    }

    printf("Aktualizovalo sa %d zaznamov\n", number_of_changes);
    return l_list;
}
