// Created by Susanka on 22. 11. 2018.

#ifndef PRPR_2POJEKT_FUNCTIONS_H
#define PRPR_2POJEKT_FUNCTIONS_H
#endif //PRPR_2POJEKT_FUNCTIONS_H

#include <stdio.h>                                                                                                      //použité knižnice
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct car{                                                                                                     //definícia štruktúry typu CAR
    char category[50 + 1];
    char brand[50 + 1];
    char seller[100 + 1];
    int price;
    int year;
    char condition[200 + 1];
    struct car *next;
}CAR;

CAR* n(CAR* l_list, int* number_of_cars);
void k(CAR** l_list);
void v(CAR** l_list);
CAR* p(CAR* l_list, int *number_of_cars);
CAR* z(CAR* l_list);
CAR* a(CAR* l_list);
void h(CAR** l_list);
char* to_lower_case(char* string, char* low_case_string);
void free_linked_list(CAR** l_list);
void aktualisation(int* price);