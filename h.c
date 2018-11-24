// Created by Susanka on 23. 11. 2018.

#include "functions.h"

void h(CAR** p_linked_list){
    char brand[50 + 1], low_case_brand[50 + 1];                                                                         //pomocné polia použité na uloženie značky malými písmenami
    int i, place = 1, price;
    CAR* aktual = *p_linked_list;                                                                                       //ukazovateľ na aktuálny prvok

    fgets(brand, 50, stdin);
    brand[strlen(brand) - 1] = '\0';
    for (i = 0; i < strlen(brand); i++){                                                                                //prevedenie zadanej značky na malé písmená
        brand[i] = (char)tolower(brand[i]);
    }
    scanf("%d", &price);
    getchar();

    while(aktual != NULL){
        for (i = 0; i <= strlen(aktual->brand); i++){                                                                   //prevedenie aktuálne značky v zozname na malé písmená
            low_case_brand[i] = (char)tolower((aktual->brand)[i]);
        }

        printf("%s %s\n", low_case_brand, brand);
        if(strcmp(low_case_brand, brand) == 0 && aktual->price <= price){                                               //ak sa značky rovnajú (obe premenené na malé písmená = zanedbané veľké písmená) a cena v zozname je menšia rovná ako zadaná
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