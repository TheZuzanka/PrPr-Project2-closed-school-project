// Created by Susanka on 22. 11. 2018.

#include "functions.h"

CAR* p(CAR* l_list, int *number_of_cars){
    CAR* new = (CAR*)malloc(sizeof(CAR)), *aktual = l_list;
    char string[300];
    int position, aktual_position = 1;


    scanf("%d", &position);
    fgets(string, 299, stdin);

    fgets(string, 299, stdin);
    string[strlen(string) - 1] = '\0';
    strcpy(new->category, string);

    fgets(string, 299, stdin);
    string[strlen(string) - 1] = '\0';
    strcpy(new->brand, string);

    fgets(string, 299, stdin);
    string[strlen(string) - 1] = '\0';
    strcpy(new->seller, string);

    scanf("%d", &new->price);
    scanf("%d", &new->year);
    getchar();

    fgets(string, 299, stdin);
    string[strlen(string) - 1] = '\0';
    strcpy(new->condition, string);

    new->next = NULL;


    if (l_list == NULL){
        return new;
    }

    else if (position <= *number_of_cars){
        while(aktual_position < position-1) {
            aktual = aktual->next;
            aktual_position++;
        }

        new->next = aktual->next;
        aktual->next = new;

        (*number_of_cars)++;
        return l_list;
    }
    else if(position > *number_of_cars){
        while(aktual->next != NULL) {
            aktual = aktual->next;
        }
        aktual->next = new;
        return l_list;
    }
    else{
        new->next = l_list;
        return new;
    }
}