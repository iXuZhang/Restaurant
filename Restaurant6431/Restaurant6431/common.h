//
//  common.h
//  Restaurant6431
//  Created by Xu Zhang on 12/5/15.
//  Copyright © 2015 Xu Zhang. All rights reserved.
//

#ifndef common_h
#define common_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

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

// read info from a file
void file_read(char *filename);

#endif /* common_h */
