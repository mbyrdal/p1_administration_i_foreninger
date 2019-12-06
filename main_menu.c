#include "include.h"

/* Funktion til styring af programmet hovedmenu, hvor der kan vælges blandt 4 valgmuligheder */
void main_menu(task tasks[], int *number_of_tasks){
    int option = 0;
    do{
        option = prompt_user_options("1.  Opret opgave\n"      
                                     "2.  Ændre opgave\n"
                                     "3.  Ændre sortering\n"
                                     "4.  Afslut programmet.\n"
                                     "Vælg mellem en af ovenstående muligheder [indtast valgmulighedens nummer uden punktum \".\"]: ",
                                     MAIN_MENU);
        /*
        printf("1.  Opret opgave\n"
               "2.  Ændre opgave\n"
               "3.  Ændre sortering\n"
               "4.  Afslut programmet.\n"
               "Vælg mellem en af ovenstående muligheder [indtast valgmulighedens nummer uden punktum \".\"]: ");

        Der tjekkes om input er en korrekt valgmulighed */
        if (option != 0){
            execute_user_input(option, tasks, number_of_tasks);
        }
    } while(option != MAIN_MENU);
}

/* Funktion til at udføre brugerens handling
 * Tager valget som input samt med task-array og antal opgaver
 * intet output
 */
void execute_user_input(int option, task tasks[], int *number_of_tasks){
    enum options{task_create = 1, task_change, task_sort};
    switch (option){

    case task_create:
        create_task(tasks, number_of_tasks);
        break;
    case task_change:
        
        break;

    case task_sort:
        change_sorting(tasks, *number_of_tasks);
        break;

    /*Der er ikke andre muligheder end ovenstående. Fejl input er sorteret fra, så de kommer ikke i default case*/
    default:
        printf("Programmet blev afsluttet.");
        break;
    }
}
