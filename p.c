// Created by Susanka on 22. 11. 2018.

#include "functions.h"

CAR* p(CAR* p_linked_list, int *number_of_cars){
    CAR* new_node = (CAR*)malloc(sizeof(CAR)), *aktual = p_linked_list;
    char string[300];
    int position, aktual_position = 1;


    scanf("%d", &position);
    fgets(string, 299, stdin);                                                                                          //načítanie nového záznamu do novoalokovanej štruktúry

    fgets(string, 299, stdin);
    string[strlen(string) - 1] = '\0';
    strcpy(new_node->category, string);

    fgets(string, 299, stdin);
    string[strlen(string) - 1] = '\0';
    strcpy(new_node->brand, string);

    fgets(string, 299, stdin);
    string[strlen(string) - 1] = '\0';
    strcpy(new_node->seller, string);

    scanf("%d", &new_node->price);
    scanf("%d", &new_node->year);
    getchar();

    fgets(string, 299, stdin);
    string[strlen(string) - 1] = '\0';
    strcpy(new_node->condition, string);

    new_node->next = NULL;                                                                                              //vytvorím samostatný oddelený záznam


    if (p_linked_list == NULL){                                                                                         //ak je pôvodný list prázdny, nový list bude tvoriť len jeden pridaný záznam
        return new_node;
    }

    else if (position <= *number_of_cars && position != 1){                                                             //ak je zadaná pozícia menšia ako počet záznamov a nie je prvá, vkladám do stredu
        while(aktual_position < position-1) {
            aktual = aktual->next;                                                                                      //pomocou while cyklu sa presuniem na pozíciu pred tú, kam potrebujem pridať
            aktual_position++;
        }

        new_node->next = aktual->next;                                                                                  //vložím záznam na správnu pozíciu
        aktual->next = new_node;

        (*number_of_cars)++;
        return p_linked_list;
    }
    else if(position > *number_of_cars){                                                                                //ak je zadaná pozícia väčšia ako počet záznamov, budem pridávať na koniec
        while(aktual->next != NULL) {
            aktual = aktual->next;
        }
        aktual->next = new_node;                                                                                        //nový záznam pripojím za aktuálny posledný
        return p_linked_list;
    }
    else{                                                                                                               //vkladáma na začiatok listu
        new_node->next = p_linked_list;                                                                                 //pôvodny list napojím na koniec jednoprvkového listu
        return new_node;                                                                                                //ukazovateľ na nový prvok bude teraz ukazovateľom na prvý prvok nového listu
    }
}