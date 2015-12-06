//
//  main.c
//  Restaurant6431
//  Created by Xu Zhang on 12/5/15.
//  Copyright © 2015 Xu Zhang. All rights reserved.
//

#include "common.h"
#include "diner.h"
#include "cook.h"

int main(int argc, const char * argv[]) {
    printf("%s\n",argv[1]);
    FILE *fp;
    char buff[255];
    fp = fopen("data.txt", "r");
    fscanf(fp, "%s", buff);
    printf("1 : %s\n", buff );
    fclose(fp);
    
    //file_read(argv[1]);
    struct Diner diners[number_of_diners];
    struct Cook cooks[number_of_cooks];
    return 0;
}
