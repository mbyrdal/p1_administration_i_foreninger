#include "include.h"

/* 
 * Main funktion til at køre programmet
 */
int main(void){
    int number_of_tasks = 0, number_of_categories = 0;
    char file_name[100];
    task tasks[MAX_TASKS];

    start_prompt(tasks, &number_of_tasks, file_name);
    main_menu(tasks, &number_of_tasks);
    create_file(file_name, tasks, number_of_tasks);
    return 0;
}
