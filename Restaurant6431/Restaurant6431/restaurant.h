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
    int in_time;
    int out_time;
    int number_of_burgers;
    int number_of_fries;
    int number_of_cokes;
    int number_of_sundaes;
    int isWaitingForCook;
    int isWaitingForDiner;
    int food_served_time;
    
    int assigned_number_cook;
    int assigned_number_table;
    int assigned_time_cook;
    int assigned_time_table;
    int assigned_time_burgers;
    int assigned_time_fries;
    int assigned_time_cokes;
    int assigned_time_sundaes;
};

struct Cook
{
    int number;
    
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

//  read diner info from a file
void diner_read(const char *filename);


#endif /* restaurant_h */
