#include "include.h"

void change_sorting(task tasks[], int number_of_tasks){
    int option = prompt_user_options("Hvilken slags sortering vil du have?\n (Indtast tal fra 1-5 efter foelgende muligheder)\n\n"
                                     "1.  Kategori\n"
                                     "2.  Titel\n"
                                     "3.  Ansvarlig\n"
                                     "4.  Prioriteringsgrad\n"
                                     "5.  Deadline\n"
                                     "> ",
                                     5);
    sort_tasks(tasks, number_of_tasks, option);
    print_sort(tasks, number_of_tasks, option);
}

void sort_tasks(task tasks[], int number_of_tasks, int option){

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
            printf("Noget gik galt!!!\n");
            break;
    }
}

void print_sort(task tasks[], int number_of_tasks, int option){
    int i;
    enum sort{category = 1, title, admins, priority, deadline};

    switch (option){
        case category:
            printf("\nSorteret for Kategori:\n");
            for (i = 0; i < number_of_tasks; i++){
                printf("%s: %d\n%s: %s\n%s: %s\n\n", "Nummer", i+1, "Kategori", tasks[i].category, "Titel", tasks[i].title);
            } break;

        case title:
            printf("\nSorteret for Titel:\n");
            printf("%-10s %-10s\n", "Nummer:", "Titel");
            for (i = 0; i < number_of_tasks; i++){
                printf("%-10d %-s\n", i+1, tasks[i].title);
            } break;

        case admins:
            printf("\nSorteret for Ansvarlig:\n");
            for (i = 0; i < number_of_tasks; i++){
               printf("%s: %d\n%s: %s\n%s: %s\n\n", "Nummer", i+1, "Ansvarlig", tasks[i].admins, "Titel", tasks[i].title);
            } break;

        case priority:
            printf("\nSorteret for Prioritering:\n");
            printf("%-10s %-14s %-10s\n", "Nummer:", "Prioritering:", "Titel:");
            for (i = 0; i < number_of_tasks; i++){
                printf("%-10d %-14d %-s\n", i+1, tasks[i].priority, tasks[i].title);
            } break;

        case deadline:
            printf("\nSorteret for Deadline:\n");
            printf("%-10s %-17s %-10s\n", "Nummer:","Deadline:" ,"Titel:");
            for (i = 0; i < number_of_tasks; i++){
                printf("%-10d %02d.%02d %02d.%02d.%-5d %-s\n", i+1, tasks[i].deadline.tm_hour,
                tasks[i].deadline.tm_min, tasks[i].deadline.tm_mday, tasks[i].deadline.tm_mon, tasks[i].deadline.tm_year, tasks[i].title);
            } break;

        default:
            printf("Noget gik galt!!!\n");
            break;
    }
}
