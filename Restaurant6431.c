#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<semaphore.h>
#include<unistd.h>

#define MAX_DINERS 121

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

struct Diner
{
	bool isWaitingForCook;
    bool isWaitingForDiner;
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

struct Cook
{
	int number;
};

void get_file(char *filename);

int main(int argc, char *argv[])
{
	get_file(argv[1]);
	Diner diners[number_of_diners];
	Cook cooks[number_of_cooks];
}

void get_file(char *filename)
{
    int i, j, k;
    FILE *fp;
    char diner[3], table[3], cook[3], diner_info[80];
    char in_time[4], no_burgers[2], no_fries[2], no_coke[2];

    fp = fopen(filename, "r");
    fgets(diner, 1024, fp);
    number_of_diners = atoi(diner);
    dinersAvailable = number_of_diners;
    printf("Number of Diners:\t%d \n", no_of_diners);
    fgets(table, 1024, fp);
    number_of_tables = atoi(table);
    tablesAvailable = number_of_tables;
    printf("Number of Tables:\t%d \n", no_of_tables);
    fgets(cook, 1024, fp);
    number_of_cooks = atoi(cook);
    cooksAvailable = number_of_cooks;
    printf("Number of Cooks:\t%d \n", no_of_cooks);
    for (i = 0; i < no_of_diners; i++)
    {
        diners[i].diner_no = i;
        diners[i].cook_assigned = 0;
        diners[i].table_assigned = 0;
    }

    for (i = 0; i < no_of_cooks; i++)
    {
        cooks[i].cook_no = i;
        cooks[i].cook_avail = 1;
        cooks[i].diner_assigned = 0;
    }

    while (fgets(diner_info, 1024, fp) != NULL)
    {
        strcpy(in_time, "\0");
        strcpy(no_burgers, "\0");
        strcpy(no_fries, "\0");
        strcpy(no_coke, "\0");
        static int i = -1;
        i++;
        j = 0;
        k = 0;
        while (diner_info[j] != ' ')
        {
            in_time[k] = diner_info[j];
            j++; k++;
        }
        in_time[k] = '\0';
        diners[i].in_time = atoi(in_time);

        while (diner_info[j] == ' ')
            j++;
        k = 0;
        while (diner_info[j] != ' ')
        {
            no_burgers[k] = diner_info[j];
            j++; k++;
        }
        no_burgers[k] = '\0';
        diners[i].foodorder.burgers = atoi(no_burgers);

        while (diner_info[j] == ' ')
            j++;
        k = 0;
        while (diner_info[j] != ' ')
        {
            no_fries[k] = diner_info[j];
            j++; k++;
        }
        no_fries[k] = '\0';
        diners[i].foodorder.fries = atoi(no_fries);

        while (diner_info[j] == ' ')
            j++;
        k = 0;
        while (diner_info[j] != '\0')
        {
            no_coke[k] = diner_info[j];
            j++; k++;
        }
        no_coke[k] = '\0';
        diners[i].foodorder.coke = atoi(no_coke);
        strcpy(diner_info, "\0");
    }
    fclose(fp);
    for (i = 0; i < diners[i].foodorder.burgers; i++)
    {
        diners[i].machine.burger_assign_time[i] = 0;
    }
    for (i = 0; i < diners[i].foodorder.fries; i++)
    {
        diners[i].machine.fries_assign_time[i] = 0;
    }
    diners[i].machine.coke_assign_time = 0;
}
