//
//  restaurant.c
//  Restaurant6431
//
//  Created by Alan on 12/6/15.
//  Copyright © 2015 Xu Zhang. All rights reserved.
//

#include "restaurant.h"

int
number_of_diners,
number_of_tables,
number_of_cooks,
available_diners,
available_tables,
available_cooks;

pthread_mutex_t
mutex_diners,
mutex_tables,
mutex_cooks,
mutex_burgers,
mutex_fries,
mutex_cokes,
mutex_sundaes;

struct Diner diners[max_diners];
struct Cook cooks[max_cooks];

void diner_read(const char *filename) {
    FILE *fp;
    if((fp = fopen(filename,"r")) == NULL){
        printf("Cannot open file strike any key exit!");
        exit(1);
    }
    fscanf(fp, "%d", &number_of_diners);
    fscanf(fp, "%d", &number_of_tables);
    fscanf(fp, "%d", &number_of_cooks);
    available_diners = number_of_diners;
    available_tables = number_of_tables;
    if(number_of_cooks > 4) number_of_cooks = 4;
    available_cooks = number_of_cooks;
    printf("Welcome to restaurant 6431! $_$ \n");
    printf("*************************************************************\n");
    printf("Diners:\t%d \n", number_of_diners);
    printf("Tables:\t%d \n", number_of_tables);
    printf("Cooks:\t%d \n", number_of_cooks);
    printf("*************************************************************\n");
    for(int i = 0; i < number_of_diners; i++){
        fscanf(fp, "%d", &diners[i].in_time);
        fscanf(fp, "%d", &diners[i].number_of_burgers);
        fscanf(fp, "%d", &diners[i].number_of_fries);
        fscanf(fp, "%d", &diners[i].number_of_cokes);
        fscanf(fp, "%d", &diners[i].number_of_sundaes);
    }
    fclose(fp);
}