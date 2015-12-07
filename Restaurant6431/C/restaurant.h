//
//  restaurant.h
//  Restaurant6431
//
//  Created by Alan on 12/6/15.
//  Copyright © 2015 Xu Zhang. All rights reserved.
//

#ifndef restaurant_h
#define restaurant_h

#include "common.h"

#define max_diners 121
#define max_tables 200
#define max_cooks 4
#define max_burgers 100
#define max_fries 100

struct Diner {
    int id_of_diner;
    int in_time;
    int number_of_burgers;
    int number_of_fries;
    int number_of_cokes;
    int number_of_sundaes;
    
    int isWaitingForTable;
    int isWaitingForCook;
    
    int assigned_id_table;
    int assigned_id_cook;
    int assigned_time_table;
    int assigned_time_cook;
    int assigned_time_burgers;
    int assigned_time_fries;
    int assigned_time_cokes;
    int assigned_time_sundaes;
    int served_time_food;
};

struct Cook {
    int id_of_cook;
    int id_of_diner;
    int isAssigned;
};

extern int
number_of_diners,
number_of_tables,
number_of_cooks,
available_diners,
available_tables,
available_cooks;

extern pthread_mutex_t
mutex_diners,
mutex_tables,
mutex_cooks,
mutex_burgers,
mutex_fries,
mutex_cokes,
mutex_sundaes;

extern struct Diner diners[max_diners];
extern struct Cook cooks[max_cooks];

//  read restaurant info from a file
void restaurant_scan(const char *filename);
//  print restaurant info
void restaurant_print();
//  threads initialization and process
void restaurant_process();

void dinerProcess(void *arg);
void cookProcess(void *arg);


#endif /* restaurant_h */
