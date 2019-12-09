/* Include fil for every preprocessor */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <dirent.h>

#define MAX_TASKS 100
#define MAIN_MENU 4
#define MAX_NUMBER_OF_CATEGORIES 50
#define MAX_LENGTH_OF_CATEGORY 100

/* Structs */
struct task{
    char category[MAX_LENGTH_OF_CATEGORY],
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
#include "opgave_func.h"
#include "start_prompt.h"
#include "main_menu.h"
#include "cmp_func.h"
#include "print_sort.h"

