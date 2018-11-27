// Created by Susanka on 23. 11. 2018.

#include "functions.h"

void h(CAR** p_linked_list){
    char brand[50 + 1], low_case_brand[50 + 1];                                                                         //pomocné polia použité na uloženie značky malými písmenami
    int i, place = 1, price;
    CAR* aktual = *p_linked_list;                                                                                       //ukazovateľ na aktuálny prvok

    fgets(brand, 50, stdin);
    brand[strlen(brand) - 1] = '\0';
    to_lower_case(brand, brand);
    scanf("%d", &price);
    getchar();

    while(aktual != NULL){
        to_lower_case(aktual->brand,low_case_brand);

        //printf("%s %s\n", low_case_brand, brand);
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

    if(place == 1){                                                                                                     //ak sa prednastavená hodnota polohy nezmení, žiaden záznam nevyhovuje požiadavkám
        printf("V ponuke nie su pozadovane auta.\n");
    }
}