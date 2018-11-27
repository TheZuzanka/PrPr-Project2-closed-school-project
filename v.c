// Created by Susanka on 22. 11. 2018.

#include "functions.h"

void v(CAR** p_linked_list){
    CAR* aktual = *p_linked_list;
    int place = 1;

    while ( aktual != NULL){                                                                                            //pokiaľ je list prázdny, nevypíše sa nič
        printf("%d.\n"
                       "kategoria: %s\n"
                       "znacka: %s\n"
                       "predajca: %s\n"
                       "cena: %d\n"
                       "rok_vyroby: %d\n"
                       "stav_vozidla: %s\n", place++, aktual->category, aktual->brand, aktual->seller, aktual->price, aktual->year, aktual->condition);
        aktual = aktual->next;
    }
}