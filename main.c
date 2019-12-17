#include "include.h"

/* Main funktion til at køre programmet */
int main(int argc, char *argv[]){
    int number_of_tasks = 0, number_of_categories = 0;
    char file_name[100];
    task tasks[MAX_TASKS];
    char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY];

    if (argc == 2 && strcmp(argv[1], "--test") == 0){
        run_all_tests();
    }else{
        start_prompt(tasks, categories, &number_of_tasks, &number_of_categories, file_name);
        main_menu(tasks, categories, &number_of_tasks, &number_of_categories);
        create_file(file_name, tasks, categories, number_of_tasks, number_of_categories);
    }
    return 0;
}
