//
//  diner.h
//  Restaurant6431
//  Created by Alan on 12/5/15.
//  Copyright © 2015 Xu Zhang. All rights reserved.
//

#ifndef diner_h
#define diner_h

#include "common.h"

struct Diner {
    int isWaitingForCook;
    int isWaitingForDiner;
    int food_served_time;
    int in_time;
    int out_time;
    int number_of_cook;
    int number_of_table;
    int number_of_burgers;
    int number_of_fries;
    int number_of_cokes;
    int number_of_sundaes;
    int assigned_time_cook;
    int assigned_time_table;
    int assigned_time_burgers;
    int assigned_time_fries;
    int assigned_time_cokes;
    int assigned_time_sundaes;
};

#endif /* diner_h */
