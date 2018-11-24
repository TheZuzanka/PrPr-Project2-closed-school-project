// Created by Susanka on 22. 11. 2018.

#include "functions.h"

CAR* a(CAR* l_list){
    char new_brand[50 + 1], low_case_brand[50 + 1];                                                                     //pomocné polia použité na uloženie značky malými písmenami
    int i, number_of_changes = 0, year;
    CAR* aktual = l_list;                                                                                               //ukazovateľ na aktuálny záznam

    fgets(new_brand, 50, stdin);
    new_brand[strlen(new_brand) - 1] = '\0';
    for (i = 0; i < strlen(new_brand); i++){                                                                            //zadaná značka sa prevedie na malé znaky
        new_brand[i] = (char)tolower(new_brand[i]);
    }
    scanf("%d", &year);
    getchar();

    while(aktual != NULL){
        for (i = 0; i <= strlen(aktual->brand); i++){                                                                   //aktuálna značka zo zoznamu sa prevedie na malé znaky
            low_case_brand[i] = (char)tolower((aktual->brand)[i]);
        }

        if(strcmp(low_case_brand, new_brand) == 0 && year == aktual->year){                                             //ak sa značky a rok rovnajú (obe premenené na malé písmená = zanedbané veľké písmená)
            aktual->price = (aktual->price) - 100;                                                                      //cena sa zníži o jedna
            number_of_changes++;
        }

        aktual = aktual->next;
    }

    printf("Aktualizovalo sa %d zaznamov\n", number_of_changes);
    return l_list;
}
