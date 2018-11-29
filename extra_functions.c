// Created by Susanka on 22. 11. 2018.

#include "functions.h"

void free_linked_list(CAR** l_list) {                                                                                   //uvoľní celý linked list
    CAR* aktual;

    while (*l_list != NULL){
        aktual = *l_list;
        (*l_list) = (*l_list)->next;
        free(aktual);
    }

}

char* to_lower_case(char* string, char* low_case_string){                                                               //prevedie daný string na malé písmená a vráti v novom stringu
    int position;

    for (position = 0; position <= strlen(string); position++){
        low_case_string[position] = (char)tolower((string)[position]);
    }
    return low_case_string;
}

void aktualisation(int* price){                                                                                         //aktualizuje cenu
    *price = *price - 100;
}

void print_node(CAR* aktual_node){                                                                                      //vypíše aktuálny záznam
    printf(        "kategoria: %s\n"
                   "znacka: %s\n"
                   "predajca: %s\n"
                   "cena: %d\n"
                   "rok_vyroby: %d\n"
                   "stav_vozidla: %s\n", aktual_node->category, aktual_node->brand, aktual_node->seller, aktual_node->price, aktual_node->year, aktual_node->condition);

}