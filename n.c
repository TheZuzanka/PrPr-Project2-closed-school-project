// Created by Susanka on 22. 11. 2018.

#include "functions.h"

CAR* n(CAR* p_linked_list, int* number_of_cars){
    FILE* fr;
    char string[300];                                                                                                   //pomocný string pre načítavanie
    int character, i;
    CAR* aktual;                                                                                                        //ukazovateľ na aktuálny prvok

    if (p_linked_list != NULL){                                                                                         //ak už bol list vytvorený dealokuje sa a počet záznamov sa nastaví na 0
        free_linked_list(&p_linked_list);
        *number_of_cars = 0;
    }

    if( (fr = fopen("auta.txt", "r")) == NULL ){                                                                        //ak sa nepodarí otvoriť súbor vypíše sa hláška
        printf("Zaznamy neboli nacitane\n");
        return  NULL;
    }

    while ((character = fgetc(fr)) != EOF){                                                                             //spočíta sa počet záznamov poocov znakov '$' v súbore
        if(character == '$'){
            (*number_of_cars)++;
        }
    }
    rewind(fr);
    if(*number_of_cars == 0){                                                                                           //ak je súbor prázdny (0 záznaomv) vypíše sa hláška a vráti sa prázdny zoznam
        fclose(fr);
        printf("Nacitalo sa %d zaznamov\n", *number_of_cars);
        return NULL;
    }

    p_linked_list = (CAR*)malloc(sizeof(CAR));                                                                          //načítanie zo súboru do príslušných kategórií 1. štruktúry spájaného zoznamu
    fgets(string, 299, fr);

    fgets(string, 299, fr);
    string[strlen(string) - 1] = '\0';
    strcpy(p_linked_list->category, string);

    fgets(string, 299, fr);
    string[strlen(string) - 1] = '\0';
    strcpy(p_linked_list->brand, string);

    fgets(string, 299, fr);
    string[strlen(string) - 1] = '\0';
    strcpy(p_linked_list->seller, string);

    fscanf(fr,"%d", &p_linked_list->price);
    fscanf(fr,"%d", &p_linked_list->year);
    fgetc(fr);

    fgets(string, 299, fr);
    string[strlen(string) - 1] = '\0';
    strcpy(p_linked_list->condition, string);

    p_linked_list->next = NULL;
    aktual = p_linked_list;

    for(i = 0; i < (*number_of_cars) -1; i++){                                                                          //načítanie všetkých ostatných záznamov
        aktual->next = (CAR*)malloc(sizeof(CAR));
        aktual = aktual->next;
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

        aktual->next = NULL;                                                                                            //každý záznam sa považuje za posleddný. Ak ide cyklus ďalej aktual->next sa prepíše
    }

    printf("Nacitalo sa %d zaznamov\n", *number_of_cars);                                                               //výpis počtu záznamomv
    if(fclose(fr) == EOF){
        exit(-1);
    }

    return p_linked_list;
}