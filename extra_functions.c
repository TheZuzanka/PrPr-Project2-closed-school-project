// Created by Susanka on 22. 11. 2018.

#include "functions.h"

void free_linked_list(CAR** l_list) {                                                                                   //vymaže celý linked list
    CAR* aktual;

    while (*l_list != NULL){
        aktual = *l_list;
        (*l_list) = (*l_list)->next;                                                                                    //presmeruje hlavičkový pointer na ďdalšiu štruktúru
        free(aktual);                                                                                                   //vymaže prvý prvok
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
    if (*price - 100 < 0){
        *price = 0;
    }
    else{
        *price = *price - 100;
    }
}