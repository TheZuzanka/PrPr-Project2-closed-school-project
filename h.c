// Created by Susanka on 23. 11. 2018.

#include "functions.h"

void h(CAR** l_list){
    char brand[50 + 1], low_case_brand[50 + 1];
    int i, place = 1, price;
    CAR* aktual = *l_list;

    fgets(brand, 50, stdin);
    brand[strlen(brand) - 1] = '\0';
    for (i = 0; i < strlen(brand); i++){
        brand[i] = (char)tolower(brand[i]);
    }
    scanf("%d", &price);
    getchar();

    while(aktual != NULL){
        for (i = 0; i <= strlen(aktual->brand); i++){
            low_case_brand[i] = (char)tolower((aktual->brand)[i]);
        }

        printf("%s %s\n", low_case_brand, brand);
        if(strcmp(low_case_brand, brand) == 0 && aktual->price <= price){
            printf("%d.\n"
                           "kategoria: %s\n"
                           "znacka: %s\n"
                           "predajca: %s\n"
                           "cena: %d\n"
                           "rok_vyroby: %d\n"
                           "stav_vozidla: %s\n", place++, aktual->category, aktual->brand, aktual->seller, aktual->price, aktual->year, aktual->condition);
        }
        aktual = aktual->next;
    }

    if(place == 1){
        printf("V ponuke nie su pozadovane auta.\n");
    }
}