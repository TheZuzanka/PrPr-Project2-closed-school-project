// Created by Susanka on 22. 11. 2018.

#include "functions.h"

CAR* a(CAR* p_linked_list){
    char new_brand[50 + 1], low_case_brand[50 + 1];                                                                     //pomocné polia použité na uloženie značky malými písmenami
    int number_of_changes = 0, year;
    CAR* aktual = p_linked_list;                                                                                        //ukazovateľ na aktuálny záznam

    fgets(new_brand, 50, stdin);
    new_brand[strlen(new_brand) - 1] = '\0';
    to_lower_case(new_brand, new_brand);
    scanf("%d", &year);
    getchar();

    while(aktual != NULL){
        to_lower_case(aktual->brand, low_case_brand);

        if(strcmp(low_case_brand, new_brand) == 0 && year == aktual->year){
            if(aktual->price - 100 < 0){
                aktual->price = 0;
            }
            else{
                aktualisation(&(aktual->price));
            }
            number_of_changes++;
        }

        aktual = aktual->next;
    }

    printf("Aktualizovalo sa %d zaznamov\n", number_of_changes);
    return p_linked_list;
}