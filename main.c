#include "include.h"

/* Main funktion til at køre programmet 
 */
int main(void){
    int number_of_tasks = 0, number_of_categories = 0;
    char file_name[100];
    task tasks[MAX_TASKS];
    char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY];

    start_prompt(tasks, categories, &number_of_tasks, &number_of_categories, file_name);
    main_menu(tasks, categories, &number_of_tasks, &number_of_categories);
    create_file(file_name, tasks, categories, number_of_tasks, number_of_categories);
    return 0;
}
