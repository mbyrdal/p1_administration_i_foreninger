#include "include.h"
#define SENTINEL 3

void start_prompt(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories, char *file_name){
    char dir_name[100];

    while (!dir_exists(dir_name)) {
        file_input("Skriv navn paa mappen du vil aabne:\n> ", dir_name);
        create_dir(dir_name);
    }
    file_managing(tasks, categories, number_of_tasks, number_of_categories, dir_name, file_name);
}

void file_input(char *print, char *input){
    printf("%s", print);
    scanf(" %s", input);
    clear_input();
}

void create_dir(char *dir_name){
    char mk_dir[125], option;

    if (dir_exists(dir_name)){
        printf("Mappe fundet!\n");
    } else{

        printf("Mappe findes ikke, vi du oprette en ny med dette navn? [j/n]\n> ");
        do{
            scanf(" %c", &option);
            clear_input();
        } while (check_answer(option) == 0);

        if(check_answer(option) == 1){
            sprintf(mk_dir, "mkdir %s", dir_name);
            printf("Mappe oprettet!\n");
            system(mk_dir);
        }
    }
}

int dir_exists(char *dir_name){
    DIR* dir;
    dir = opendir(dir_name);
    if (dir){
        return 1;
    } else{
        return 0;
    }
}

void file_managing(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories, char *dir_name, char *file_name){
    int option, file_found = 0;
    char temp_file_name[100];
    char temp_answer;
    FILE *file;
    enum file_managing{file_open = 1, file_create = 2};

    option = prompt_user_options("Hvad vil du nu? \n\n"
                                 "1.  Aabne en fil (Laese fra fil)\n"
                                 "2.  Oprette en ny fil (Skrive til fil)\n> ",
                                 2);

    switch (option){
        case file_open:
            do{
                file_input("\nSkriv navn paa filen:\n> ", temp_file_name);
                sprintf(file_name, "%s/%s.txt", dir_name, temp_file_name);
                file = fopen(file_name, "r");
                if (file != NULL){
                    file_found = 1;
                    category_read(file, categories, number_of_categories);
                    while (!feof(file)){
                        file_read_task(file, &tasks[(*number_of_tasks)++]);
                        fscanf(file, "%*[^a-zA-Z]");
                    }
                } else{
                    do{
                        printf("\nFil ikke fundet. Vil du oprette en ny fil med dette navn? [j/n]\n> ");
                        scanf(" %c", &temp_answer);
                        clear_input();
                    } while (check_answer(temp_answer) == 0);
                }
                fclose(file);
            } while (!file_found && check_answer(temp_answer) != 1);
            break;

        case file_create:
            file_input("\nSkriv det nye filnavn:\n> ", temp_file_name);
            sprintf(file_name, "%s/%s.txt", dir_name, temp_file_name);
            file = fopen(file_name, "r");
            if (file != NULL){
                do{
                    printf("Filen \"%s\" findes allerede! Vil du overskrive denne fil? [j/n]\n> ", temp_file_name);
                    scanf(" %c", &temp_answer);
                    clear_input();
                } while (check_answer(temp_answer) == 0);
                if (temp_answer == 'j'){
                    printf("Filen overskrives.");
                } else{
                    file_managing(tasks, categories, number_of_tasks, number_of_categories, dir_name, file_name);
                }

            } else{
                printf("Fil oprettet.");
            }
            break;

        default:
            printf("Noget er galt!!!!\n");
            break;
    }
}

void file_write_task(FILE *fil, task task1){


    fprintf(fil, "Kategori: %s\n", task1.category);
    fprintf(fil, "Admins: %s\n", task1.admins);
    fprintf(fil, "Titel: %s\n", task1.title);
    fprintf(fil, "Beskrivelse: {%s}\n", task1.description);
    fprintf(fil, "Frivillige: %s\n", task1.volunteers);
    fprintf(fil, "Status: {%s}\n", task1.status_str);
    fprintf(fil, "Prioritet: %d\n", task1.priority);
    fprintf(fil, "Deadline: %02d.%02d %02d.%02d.%d\n\n",
         task1.deadline.tm_hour,
         task1.deadline.tm_min,
         task1.deadline.tm_mday,
         task1.deadline.tm_mon,
         task1.deadline.tm_year);

}

void file_read_task(FILE *fil, task *task1){
    fscanf(fil," %*[^:]%*c %[^\n]", task1->category);
    fscanf(fil," %*[^:]%*c %[^\n]", task1->admins);
    fscanf(fil," %*[^:]%*c %[^\n]", task1->title);
    fscanf(fil," %*[^:]%*c { %[^}]", task1->description);
    fscanf(fil," %*[^:]%*c %[^\n]", task1->volunteers);
    fscanf(fil," %*[^:]%*c { %[^}]", task1->status_str);
    fscanf(fil," %*[^:]%*c %d", &task1->priority);
    fscanf(fil," %*[^:]%*c %d.%d %d.%d.%d %*c",
         &task1->deadline.tm_hour,
         &task1->deadline.tm_min,
         &task1->deadline.tm_mday,
         &task1->deadline.tm_mon,
         &task1->deadline.tm_year);
}

void create_file(char *file_name, task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int number_of_tasks, int number_of_categories){
    FILE *file;
    int i;

    file = fopen(file_name, "w");
    if (file != NULL){

        fprintf(file, "Kategorier: ");
        for (i = 0; i < number_of_categories; i++){
            fprintf(file, "{%s} ", categories[i]);
        }
        fprintf(file, "\n\n");

        for (i = 0; i < number_of_tasks; i++){
            file_write_task(file, tasks[i]);
        }
        fclose(file);
    } else{
        printf("Kunne ikke skrive til fil\n");
    }
}

void category_read(FILE *fil, char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_categories){
    char skip_ch;

    fscanf(fil, " %*[^:]%*c");

    do {
        skip_ch = fgetc(fil);
        if (skip_ch == '{'){
            fscanf(fil, " %[^}]%*c", categories[*number_of_categories]);
            *number_of_categories += 1;
        }
    } while (skip_ch != '\n');

    /* takes the last '\n'*/
    fscanf(fil, "%*[^a-zA-Z]");
}
