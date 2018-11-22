#include "functions.h"

int main() {
    int function, number_of_cars = 0;
    CAR* cars_list = NULL, *aktual;
    CAR** p_cars_list = &cars_list;

    while ( (function = getchar()) ){
        getchar();

        switch (function){
            case 'n':
                cars_list = n(*p_cars_list, &number_of_cars);
                p_cars_list = &cars_list;
                break;

            case 'v':
                v(p_cars_list);
                break;

            case 'p':
                cars_list = p(*p_cars_list, &number_of_cars);
                p_cars_list = &cars_list;
                break;

            case 'z':
                cars_list = z(*p_cars_list);
                p_cars_list = &cars_list;
                break;

            case 'a':
                cars_list = a(*p_cars_list);
                p_cars_list = &cars_list;
                break;

            case 'k':
                k(p_cars_list);

            default:
                break;
        }
    }
    return 0;
}