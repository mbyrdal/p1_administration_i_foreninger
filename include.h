/* Include fil for every preprocessor */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <dirent.h>


/* Structs */
struct task{
    char title[100],
         admins[250],
         volunteers[250],
         description[1000],
         status_str[1000];
    int category_index,
        priority;

    struct tm deadline;
};
typedef struct task task;

#include "help_functions.h"
#include "opgave_func.h"
#include "start_prompt.h"
#include "main_menu.h"
#include "print_sort.h"
#include "cmp_func.h"

#define MAX_TASKS 100
#define MAIN_MENU 4
#define MAX_NUMBER_OF_CATEGORIES 50
#define MAX_LENGTH_OF_CATEGORY 100
