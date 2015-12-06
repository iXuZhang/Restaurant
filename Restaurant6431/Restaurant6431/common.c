//
//  common.c
//  Restaurant6431
//  Created by Alan on 12/5/15.
//  Copyright © 2015 Xu Zhang. All rights reserved.
//

#include "common.h"

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

void file_read(char *filename) {
    FILE *fp;
    char diner[3], table[3], cook[3], diner_info[80];
    if((fp = fopen("filename","r")) == NULL){
        printf("Cannot open file strike any key exit!");
        exit(1);
    }
    printf("********************************************************\n");
    fscanf(fp, "%d", &number_of_diners);
    fscanf(fp, "%d", &number_of_tables);
    fscanf(fp, "%d", &number_of_cooks);
    available_diners = number_of_diners;
    available_tables = number_of_tables;
    available_cooks = number_of_cooks;
    printf("Diners:\t%d \n", number_of_diners);
    printf("Tables:\t%d \n", number_of_tables);
    printf("Cooks:\t%d \n", number_of_cooks);
    printf("********************************************************\n");
    fclose(fp);
}