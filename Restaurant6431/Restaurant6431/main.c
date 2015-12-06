//
//  main.c
//  Restaurant6431
//  Created by Xu Zhang on 12/5/15.
//  Copyright © 2015 Xu Zhang. All rights reserved.
//

#include "common.h"
#include "restaurant.h"

int main(int argc, const char * argv[]) {
    diner_read(argv[1]);
    
    for(int i = 0; i < number_of_diners; i++){
        printf("%d\t", diners[i].in_time);
        printf("%d\t", diners[i].number_of_burgers);
        printf("%d\t", diners[i].number_of_fries);
        printf("%d\t", diners[i].number_of_cokes);
        printf("%d\t\n", diners[i].number_of_sundaes);
    }
    printf("*************************************************************\n");
    printf("Bye and have a nice day! $_$ \n");
    return 0;
}
