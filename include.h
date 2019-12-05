/* Include fil for every preprocessor */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "opret_opgave.h"
#include "Start_Prompt.h"

#define MAX_TASKS 100


/* Structs */

struct task{
    char category[100],
         admins[250],
         title[100],
         description[1000],
         volunteers[250],
         status_str[1000];
    int priority,
        number;
    struct tm deadline;
};
typedef struct task task;

