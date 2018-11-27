// Created by Susanka on 22. 11. 2018.

#include "functions.h"

void free_linked_list(CAR** l_list)
{
    CAR* aktual;

    while (*l_list != NULL){
        aktual = *l_list;
        (*l_list) = (*l_list)->next;
        free(aktual);
        //TOTO JE MOJ PEKNY KOMENTAR WIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
        //WIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
    }

}

char* to_lower_case(char* string, char* low_case_string){                                                               //prevedie daný string na malé písmená a vráti v novom stringu
    int position;

    for (position = 0; position <= strlen(string); position++){
        low_case_string[position] = (char)tolower((string)[position]);
    }
    return low_case_string;
}

void aktualisation(int* price){
    price = price - 100;
}