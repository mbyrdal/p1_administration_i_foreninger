#include "include.h"

/* Funktion til styring af programmet hovedmenu, hvor der kan vælges blandt flere muligheder.
 * Funktionen tager tasks-arrayet og categories-arrayet for at sende det videre til andre funktioner som vælges gennem brugerens input.
 * Funktionen tager number_of_tasks og number_of_categories for at sende videre til andre funktioner, som vælges gennem brugerens input.
 * Intet output.
 */
void main_menu(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories){
    int option = 0;

    do{
        option = prompt_user_options("\nVaelg mellem en af ovenstaaende muligheder [indtast valgmulighedens nummer uden punktum \".\"]: \n\n"
                                     "1.  Opret opgave\n"
                                     "2.  Aendre opgave\n"
                                     "3.  Vis opgaver / Aendre sortering\n"
                                     "4.  Slet opgave\n"
                                     "5.  Slet kategori\n"
                                     "6.  Afslut programmet\n"
                                     "> ",
                                     MAIN_MENU);
        execute_user_input(tasks, categories, number_of_tasks, number_of_categories, option);
    } while (option != MAIN_MENU);
}

/* Funktion til at udføre brugerens handling.
 * Funktionen tager tasks-arrayet og categories-arrayet for at sende det videre til andre funktioner som vælges gennem brugerens input.
 * Funktionen tager number_of_tasks og number_of_categories for at sende videre til andre funktioner, som vælges gennem brugerens input.
 * Funktionen bruger option til at vælge den rigtige funktion ud fra brugerens input.
 * Intet output.
 */
void execute_user_input(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories, int option){
    int i, change_task_index, category_delete_index, view_task_index;

    enum options{task_create = 1, task_change, task_sort, task_delete, category_delete};

    switch (option){
        case task_create:
            create_task(tasks, categories, number_of_tasks, number_of_categories);
            break;   

        case task_change:
            if (*number_of_tasks > 0){
                
                printf("\n%-10s %-10s\n", "Nummer:", "Titel:");
                for (i = 0; i < *number_of_tasks; i++){
                    printf("%-10d %-s\n", i+1, tasks[i].title);
                }
                change_task_index = prompt_user_options("Hvilken opgave vil du aendre? "
                                                        "(Indtast opgave nummer)\n"
                                                        "> ", *number_of_tasks) - 1;
                change_task(tasks, categories, *number_of_tasks, number_of_categories, change_task_index);
            } else{
                printf("Kan ikke aendre naar der ingen opgaver er!\n");
            }
            break;

        case task_sort:
            if (*number_of_tasks > 0){
                change_sorting(tasks, *number_of_tasks);

                printf("Hvilken opgave vil du gerne se? ('%d' for at gaa tilbage til menu)\n", *number_of_tasks + 1);
                view_task_index = prompt_user_options("> ", *number_of_tasks + 1) - 1;
                if (view_task_index < *number_of_tasks){
                    print_task(tasks[view_task_index]);
                }
            } else{
                printf("Kan ikke vise opgaverne naar der ingen opgaver er!\n");
            }
            break;

        case task_delete:
            if (*number_of_tasks > 0){
                delete_task(tasks, number_of_tasks);
            } else{
                printf("Kan ikke slette naar der ingen opgaver er!\n");
            }   
            break;

        case category_delete:
            if (*number_of_categories > 0){
                for (i = 0; i < *number_of_categories; i++){
                    printf("%d) %s\n", i + 1, categories[i]);
                }
                category_delete_index = prompt_user_options("Hvilken kategori med dens opgaver vil du slette? "
                                                            "(Indtast kategoriens nummer)\n"
                                                            "> ", *number_of_categories) - 1;
                delete_category(tasks, number_of_tasks, categories[category_delete_index]);
                if (category_delete_index < (*number_of_categories - 1)){
                    strcpy(categories[category_delete_index], categories[*number_of_categories - 1]);
                }
                *number_of_categories -= 1;
            } else{
                printf("Kan ikke slette en kategori naar der ingen er!\n");
            }
            break;
            
        default:
            printf("Programmet blev afsluttet.\n");
            break;
    }
}
