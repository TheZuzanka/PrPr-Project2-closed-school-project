// Created by Susanka on 22. 11. 2018.

#include "functions.h"

CAR* z(CAR* p_linked_list){
    char new_brand[50 + 1], low_case_brand[50 + 1];
    int number_of_deleted = 0;
    CAR* aktual = p_linked_list, *deleting, *previous = p_linked_list;

    fgets(new_brand, 50, stdin);
    new_brand[strlen(new_brand) - 1] = '\0';
    to_lower_case(new_brand, new_brand);

    while(aktual != NULL){                                                                                              //vykoná pre vśetky okrem poslednej
        to_lower_case(aktual->brand, low_case_brand);

        if(strstr(low_case_brand, new_brand) != NULL){                                                                  //ak je zadaná značka podreťazcom značky v štruktúre buem mazať
            if(aktual == p_linked_list){                                                                                //ak sa jedná o pprvý prvok, smerník na list presmerujem na druhý prvok
                deleting = aktual;                                                                                      //označím, ktorú štruktúru idem mazať
                p_linked_list = aktual->next;
            }
            else if(aktual->next == NULL){                                                                              //pridávam na koniec
                if(previous->next == NULL){                                                                             //ak mám len jeden záznam, delokujem celý linked list a vrátim NULL
                    free_linked_list(&p_linked_list);
                    printf("Vymazalo sa 1 zaznamov\n");
                    return NULL;
                }
                previous->next = NULL;                                                                                  //predposledný prvok nastavím na posledný
                deleting = aktual;                                                                                      //označím, ktorú štruktúru idem mazať
            }
            else{                                                                                                       //ak sa nejedná o prvý prvok presmerujem predchádzajúcu štruktúru na nasledujúcu = vynechám aktuálnu
                previous->next = aktual->next;
                deleting = aktual;                                                                                      //označím, ktorú štruktúru idem mazať
            }
            aktual = aktual->next;                                                                                      //posinuniem sa na ďalšiu štruktúru
            free(deleting);                                                                                             //štruktúru označenú ako "vymazať" dealokujem
            number_of_deleted++;
        }
        else{                                                                                                           //ak sa značky nezhodujú, prejdem na ďalšiu a nič sa nevymaže
            previous = aktual;
            aktual = aktual->next;
        }
    }

    printf("Vymazalo sa %d zaznamov\n", number_of_deleted);

    return p_linked_list;
}