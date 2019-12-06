#include "include.h"

/*Prototypes*/
int prompt_user_for_sort(void);
void sort_tasks(task tasks[], int option, int number_of_tasks);
void print_sort(task tasks[], int option, int number_of_tasks);

int main(void){
    task tasks[MAX_TASKS];
    int number_of_tasks = 0, option = 0;
    int exit_info=0;

    create_task(tasks, &number_of_tasks);
    
    while (exit_info != 1){
    option = prompt_user_for_sort();
    sort_tasks(tasks, option, number_of_tasks);
    print_tasks(tasks, option, number_of_tasks);
    printf("Vil du gå tilbage ? 0 for tilbage 1 for exit");
    scanf(" %d", &exit_info);
    }
    return 0;
}

int prompt_user_for_sort(void){
    int option;
    printf("Hvilken slags sortering vil du have?\n (Indtast tal fra 1-5 efter følgende muligheder)\n\n"
            "1) Kategori\n"
            "2) Titel\n"
            "3) Ansvarlig\n"
            "4) Prioriteringsgrad\n"
            "5) Deadline\n");
    scanf(" %d", &option);
    return option;
}

void print_sort(task tasks[], int option, int number_of_tasks){
    int i;
    enum sort{category = 1, title, admins, priority, deadline};
    
    switch (option){
        case category:
            printf("Sorteret for Kategori:\n");
            for (i=0; i < number_of_tasks; i++){
                printf("%s: %d\n%s: %s\n%s: %s\n\n", "Nummer", tasks[i].number, "Kategori", tasks[i].category, "Titel", tasks[i].title);
            }
            break;
        case title:
            printf("Sorteret for Titel:\n");
            printf("%-10s %-10s\n", "Nummer:", "Titel");
            for (i=0; i < number_of_tasks; i++){
                printf("%-10d %-s\n", tasks[i].number, tasks[i].title);
            }
            break;
        case admins:
            printf("Sorteret for Ansvarlig:\n");
            for (i=0; i < number_of_tasks; i++){
               printf("%s: %d\n%s: %s\n%s: %s\n\n", "Nummer", tasks[i].number, "Ansvarlig", tasks[i].admins, "Titel", tasks[i].title);
            }
            break;
        case priority:
            printf("Sorteret for Prioritering:\n");
            printf("%-10s %-14s %-10s\n", "Nummer:", "Prioritering:", "Titel:");
            for (i=0; i < number_of_tasks; i++){
                printf("%-10d %-14d %-s\n", tasks[i].number, tasks[i].priority, tasks[i].title);
            }
            break;
        case deadline:
            printf("Sorteret for Deadline:\n");
            printf("%-10s %-17s %-10s\n", "Nummer:","Deadline:" ,"Titel:");
            for (i=0; i < number_of_tasks; i++){
                printf("%-10d %02d.%02d %02d.%02d.%5d %-s\n", tasks[i].number, tasks[i].deadline.tm_hour,
                tasks[i].deadline.tm_min, tasks[i].deadline.tm_mday, tasks[i].deadline.tm_mon + 1, tasks[i].deadline.tm_year + 1900, tasks[i].title);
            }
            break;
        default:
            printf("Something went wrong");
    }
}

void sort_tasks(task tasks[], int option, int number_of_tasks){
    enum sort{category = 1, title, admins, priority, deadline};
    
    switch (option){
        case category:
            qsort(tasks, number_of_tasks, sizeof(task), compare_category);
            break;
        case title:
            qsort(tasks, number_of_tasks, sizeof(task), compare_title);
            break;
        case admins:
            qsort(tasks, number_of_tasks, sizeof(task), compare_admins);
            break;
        case priority:
            qsort(tasks, number_of_tasks, sizeof(task), compare_priority);
            break;
        case deadline:
            qsort(tasks, number_of_tasks, sizeof(task), compare_deadline);
            break;
        default:
            printf("Something went wrong");
    }
}
