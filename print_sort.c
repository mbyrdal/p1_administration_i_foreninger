#include "include.h"

/*Prototypes*/
int prompt_user_for_sort(void);
void sort_tasks(task x[], int option);
int sort_deadline(const void *ip1, const void *ip2);
int sort_priority(const void *ip1, const void *ip2);
int sort_admins(const void *ip1, const void *ip2);
void print_tasks(task x[], int option);

int main(void){
    task tasks[MAX_TASKS];
    int number_of_tasks = 0, option = 0;
    int exit_info=0;

    create_task(tasks, &number_of_tasks);
    
    while (exit_info != 1){
    option = prompt_user_for_sort();
    sort_tasks(tasks, option);
    print_tasks(tasks, option);
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

void print_tasks(task x[], int option){
    int i;
    enum sort{category = 1, title, admins, priority, deadline};
    
    switch (option){
        case category:
            printf("Sorteret for Kategori:\n");
            printf("%-10s %-10s", "Nummer:", "Titel\n");
            /*for (i=0; i < NUM_OF_TASK; i++){
                printf("%-10d %-10s %-10s", x[i].number, x[i].category, x[i].title);
            }*/
            break;
        case title:
            printf("Sorteret for Titel:\n");
            printf("%-10s %-10s", "Nummer:", "Titel\n");
            for (i=0; i < NUM_OF_TASK; i++){
                printf("%-10d %-10s\n", x[i].number, x[i].title);
            }
            break;
        case admins:
            printf("Sorteret for Ansvarlig:\n");
            printf("%-10s %-10s %-10s\n", "Nummer:", "Ansvarlig:", "Titel:");
            for (i=0; i < NUM_OF_TASK; i++){
                printf("%-10d %-10s %-10s\n", x[i].number, x[i].admins, x[i].title);
            }
            break;
        case priority:
            printf("Sorteret for Prioriteringsgrad:\n");
            printf("%-10s %-19s %-10s\n", "Nummer:", "Prioriteringsgrad:", "Titel:");
            for (i=0; i < NUM_OF_TASK; i++){
                printf("%-10d %-10s %-10d\n", x[i].number, x[i].priority, x[i].title);
            }
            break;
        case deadline:
            printf("Sorteret for Deadline:\n");
            printf("%-10s %-16s %-10s\n", "Nummer:","Deadline:" ,"Titel:");
            for (i=0; i < NUM_OF_TASK; i++){
                printf("%-10d %02d.%02d %02d.%02d.%4d %-s\n", x[i].number, x[i].deadline.tm_hour,
                x[i].deadline.tm_min, x[i].deadline.tm_mday, x[i].deadline.tm_mon + 1, x[i].deadline.tm_year + 1900, x[i].title);
            }
            break;
        default:
            printf("Something went wrong");
            break;
    }
}

void sort_tasks(task x[], int option){
    enum sort{category = 1, title, admins, priority, deadline};
    
    switch (option){
        case category:
            
            break;
        case title:

            break;
        case admins:
            qsort(x, NUM_OF_TASK, sizeof(task), sort_admins);
            break;
        case priority:
            qsort(x, NUM_OF_TASK, sizeof(task), sort_priority);
            break;
        case deadline:
            qsort(x, NUM_OF_TASK, sizeof(task), sort_deadline);
            break;
        default:
            printf("Something went wrong");
            break;
    }
}

int sort_deadline(const void *ip1, const void *ip2){
    task *tm1= (task *)ip1,
         *tm2= (task *)ip2;
    
    if (tm1->deadline.tm_year < tm2->deadline.tm_year){ 
        return -1;
    } else if (tm1->deadline.tm_year > tm2->deadline.tm_year){
        return 1;
    } else if (tm1->deadline.tm_mon < tm2->deadline.tm_mon){
        return -1;
    } else if (tm1->deadline.tm_mon > tm2->deadline.tm_mon){
        return 1;
    } else if (tm1->deadline.tm_mday < tm2->deadline.tm_mday){
        return -1;
    } else if (tm1->deadline.tm_mday > tm2->deadline.tm_mday){
        return 1;
    } else if (tm1->deadline.tm_hour < tm2->deadline.tm_hour){
        return -1;
    } else if (tm1->deadline.tm_hour > tm2->deadline.tm_hour){
        return 1;
    } else if (tm1->deadline.tm_min < tm2->deadline.tm_min){
        return -1;
    } else if (tm1->deadline.tm_min > tm2->deadline.tm_min){
        return 1;
    } else{
        return 0;
    }
            
            
        
     
}

int sort_priority(const void *ip1, const void *ip2){
    task *prio1= (task *)ip1,
         *prio2= (task *)ip2;

    if (prio1->priority < prio2->priority){ 
        return -1;
    } else if (prio1->priority > prio2->priority){
        return 1;
    } else{
        return 0;
    }
}

int sort_admins(const void *ip1, const void *ip2){
    int i;
    task *name1 = (task *)ip1,
         *name2 = (task *)ip2;
    
    for (i = 0; (name1->admins[i] =! '\n'); i++){
        name1->admins[i] = tolower(name1->admins[i]);
    }
    for (i = 0; (name2->admins[i] =! '\n'); i++){
        name2->admins[i] = tolower(name2->admins[i]);
    }

    if (strcmp(name1->admins, name2->admins) < 0){
        return -1;
    } else if (strcmp(name1->admins, name2->admins) > 0){
        return 1;
    } else {
        return 0;
    } 
}

