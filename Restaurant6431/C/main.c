//
//  main.c
//  Restaurant6431
//  Created by Xu Zhang on 12/5/15.
//  Copyright © 2015 Xu Zhang. All rights reserved.
//

#include "common.h"
#include "restaurant.h"

int main(int argc, const char * argv[]) {
    restaurant_scan(argv[1]);
    restaurant_process();
    restaurant_print();
    return 0;
}