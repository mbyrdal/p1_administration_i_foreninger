#include "include.h"

/* Funktion til styring af programmet hovedmenu, hvor der kan vælges blandt flere muligheder
 * Funktionen tager task-arrayet for at sende det videre til andre funktioner som vælges
 * Funktionen tager number_of_tasks til at sende videre til andre funktioner, som tæller den op eller ned
 */

task *main_menu(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories){
    int option = 0;

    do{
        option = prompt_user_options("Vaelg mellem en af ovenstaaende muligheder [indtast valgmulighedens nummer uden punktum \".\"]: \n\n"
                                     "1.  Opret opgave\n"
                                     "2.  Aendre opgave\n"
                                     "3.  Aendre sortering\n"
                                     "4.  Afslut programmet.\n\n"
                                     "> ",
                                     MAIN_MENU);
        if (option != 0){
            execute_user_input(option, tasks, categories, number_of_tasks, number_of_categories);
        }
    } while(option != MAIN_MENU);
    return tasks;
}

/* Funktion til at udføre brugerens handling
 * Tager valget som input samt med task-array og antal opgaver
 * intet output
 */
void execute_user_input(int option, task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories){
    int change_task_index;

    enum options{task_create = 1, task_change, task_sort};

    switch (option){
        case task_create:
            create_task(tasks, categories, number_of_tasks, number_of_categories);
            break;
        case task_change:
            change_task_index = prompt_user_options("Hvilken opgave vil du aendre? "
                                "(Indtast opgave nummer)\n"
                                "> ", *number_of_tasks);
            change_task(tasks, categories, *number_of_tasks, number_of_categories, change_task_index - 1);
            break;

        case task_sort:
            change_sorting(tasks, categories, *number_of_tasks, *number_of_categories);
            break;

        default:
            printf("Programmet blev afsluttet.\n");
    }
}
