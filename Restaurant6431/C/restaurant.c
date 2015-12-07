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

pthread_t thread_diners[max_diners], thread_cooks[max_cooks];

struct Diner diners[max_diners];
struct Cook cooks[max_cooks];

void restaurant_scan(const char *filename) {
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

void restaurant_print(){
    int final_time = 0;
    for(int i = 0; i < number_of_diners; i++){
        printf("Diner %d: \n", diners[i].id_of_diner);
        printf("\t arrived at %d\n", diners[i].in_time);
        printf("\t was seated at table %d at %d\n", diners[i].assigned_id_table, diners[i].assigned_time_table);
        printf("\t was assigned cook %d\n", diners[i].assigned_id_cook);
        printf("\t Hurgers started at %d\n", diners[i].assigned_time_fries);
        if(diners[i].number_of_fries > 0) printf("\t Hries started at %d\n", diners[i].assigned_time_fries);
        if(diners[i].number_of_cokes > 0) printf("\t Cooks started at %d\n", diners[i].assigned_time_cook);
        if(diners[i].number_of_sundaes > 0) printf("\t Sundaes started at %d\n", diners[i].assigned_time_sundaes);
        printf("\t Food was brought to table at %d\n", diners[i].served_time_food);
        final_time = max(final_time, diners[i].served_time_food);
    }
    printf("The last diner leaves at %d\n", final_time+30);
    printf("*************************************************************\n");
    printf("Thank you for coming and have a nice day! $_$ \n\n\n");
}

void restaurant_process(){
    
    pthread_mutex_init(&mutex_diners, NULL);
    pthread_mutex_init(&mutex_tables, NULL);
    pthread_mutex_init(&mutex_cooks, NULL);
    pthread_mutex_init(&mutex_burgers, NULL);
    pthread_mutex_init(&mutex_fries, NULL);
    pthread_mutex_init(&mutex_cokes, NULL);
    pthread_mutex_init(&mutex_sundaes, NULL);
    
    for (int i = 0; i < number_of_cooks; i++){
        cooks[i].id_of_cook = i + 1;
        pthread_create(&thread_cooks[i], NULL, cookProcess, &i);
    }
    
    for (int i = 0, n = 0; i <= 120; i++){
        if (diners[n].in_time == i){
            diners[n].id_of_diner = n + 1;
            diners[n].isWaitingForTable = 1;
            diners[n].isWaitingForCook = 1;
            pthread_create(&thread_diners[n], NULL, dinerProcess, &i);
            n++;
        }
        if (available_tables == 0) return;
    }
    
    
}

void dinerProcess(void *arg){
    int index = *(int*) arg;
    pthread_mutex_lock(&mutex_tables);
    if(available_tables == 0){
        pthread_mutex_unlock(&mutex_tables);
        
    }
    diners[index].isWaitingForTable = 0;
    available_tables--;
    pthread_mutex_unlock(&mutex_tables);
    
    pthread_mutex_lock(&mutex_diners);
    available_diners--;
    pthread_mutex_unlock(&mutex_diners);
    pthread_mutex_lock(&mutex_tables);
}

void cookProcess(void *arg){
    int index = *(int*) arg;
    
}

void getTable(int id_of_cook, int id_of_diner){
    diners[id_of_diner-1].assigned_id_table = 0;
}

void getCook(int id_of_diner){
    
}

