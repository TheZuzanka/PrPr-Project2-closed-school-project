// Created by Susanka on 23. 11. 2018.

#include "functions.h"

void h(CAR** p_linked_list){
    char brand[50 + 1], low_case_brand[50 + 1];                                                                         //pomocné polia použité na uloženie značky malými písmenami
    int place = 1, price;
    CAR* aktual = *p_linked_list;                                                                                       //ukazovateľ na aktuálny prvok

    fgets(brand, 50, stdin);
    brand[strlen(brand) - 1] = '\0';
    to_lower_case(brand, brand);
    scanf("%d", &price);
    getchar();

    while(aktual != NULL){
        to_lower_case(aktual->brand,low_case_brand);

        if(strcmp(low_case_brand, brand) == 0 && aktual->price <= price){
            printf("%d.\n", place++);
            print_node(aktual);
        }
        aktual = aktual->next;
    }

    if(place == 1){                                                                                                     //ak sa prednastavená hodnota polohy nezmení, žiaden záznam nevyhovuje požiadavkám
        printf("V ponuke nie su pozadovane auta.\n");
    }
}