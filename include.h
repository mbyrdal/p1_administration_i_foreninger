/* Include fil for every preprocessor */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <dirent.h>


/* Structs */

struct task{
    char category[100],
         title[100],
         admins[250],
         volunteers[250],
         description[1000],
         status_str[1000];
    int priority;

    struct tm deadline;
};
typedef struct task task;

#include "help_functions.h"
#include "opret_opgave.h"
#include "start_prompt.h"
#include "main_menu.h"
#include "print_sort.h"
#include "cmp_func.h"

#define MAX_TASKS 100
#define MAIN_MENU 4
