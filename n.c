// Created by Susanka on 22. 11. 2018.

#include "functions.h"

CAR* n(CAR* l_list, int* number_of_cars){
    FILE* fr;
    char string[300];
    int character, i;
    CAR* aktual;

    if (l_list != NULL){
        free_linked_list(&l_list);
        *number_of_cars = 0;
    }

    if( (fr = fopen("auta.txt", "r")) == NULL ){
        printf("Zaznamy neboli nacitane\n");
        return  NULL;
    }

    while ((character = fgetc(fr)) != EOF){
        if(character == '$'){
            (*number_of_cars)++;
        }
    }
    rewind(fr);
    if(*number_of_cars == 0){
        fclose(fr);
        printf("Nacitalo sa %d zaznamov\n", *number_of_cars);
        return NULL;
    }

    l_list = (CAR*)malloc(sizeof(CAR));
    fgets(string, 299, fr);

    fgets(string, 299, fr);
    string[strlen(string) - 1] = '\0';
    strcpy(l_list->category, string);

    fgets(string, 299, fr);
    string[strlen(string) - 1] = '\0';
    strcpy(l_list->brand, string);

    fgets(string, 299, fr);
    string[strlen(string) - 1] = '\0';
    strcpy(l_list->seller, string);

    fscanf(fr,"%d", &l_list->price);
    fscanf(fr,"%d", &l_list->year);
    fgetc(fr);

    fgets(string, 299, fr);
    string[strlen(string) - 1] = '\0';
    strcpy(l_list->condition, string);

    l_list->next = NULL;
    aktual = l_list;

    for(i = 0; i < (*number_of_cars) -1; i++){
        aktual->next = (CAR*)malloc(sizeof(CAR));
        aktual = aktual->next;
        //printf("l_list -> next = %p\n", l_list->next);
        fgets(string, 299, fr);

        fgets(string, 299, fr);
        string[strlen(string) - 1] = '\0';
        strcpy(aktual->category, string);

        fgets(string, 299, fr);
        string[strlen(string) - 1] = '\0';
        strcpy(aktual->brand, string);

        fgets(string, 299, fr);
        string[strlen(string) - 1] = '\0';
        strcpy(aktual->seller, string);

        fscanf(fr,"%d", &aktual->price);
        fscanf(fr,"%d", &aktual->year);
        fgetc(fr);

        fgets(string, 299, fr);
        string[strlen(string) - 1] = '\0';
        strcpy(aktual->condition, string);

        aktual->next = NULL;
    }

    printf("Nacitalo sa %d zaznamov\n", *number_of_cars);
    if(fclose(fr) == EOF){
        printf("nezavrete..\n");
    }

    return l_list;
}