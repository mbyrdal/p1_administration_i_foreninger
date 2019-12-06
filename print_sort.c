#include "include.h"

/*Prototypes*/
int prompt_user_for_sort(void);
void sort_tasks(task tasks[], int option, int number_of_tasks);
int compare_deadline(const void *ip1, const void *ip2);
int compare_priority(const void *ip1, const void *ip2);
int compare_admins(const void *ip1, const void *ip2);
int compare_title(const void *ip1, const void *ip2);
int compare_category(const void *ip1, const void *ip2);
void print_sort(task tasks[], int option, int number_of_tasks);

/*Mangler input_clear
* Printer en Menu for hvilen slags sortering brugeren vil have
* Returnere et output af en int variable, og sender den til print_sort funktionen hvor den valgte sortering bliver udført*/
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

/*Indtager int variabel option, som fortæller den hvilken slags sortering den skal printe
* Printer herefter den relevante sortering*/
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

/*Indtager en int variabel og udfører den valgte sortering i form af en qsort funktion
* Og rykker rundt i arrayet så den valgte sortering ligger ordentligt*/
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

int compare_deadline(const void *ip1, const void *ip2){
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

int compare_priority(const void *ip1, const void *ip2){
    task *prio1= (task*)ip1,
         *prio2= (task*)ip2;

    if (prio1->priority < prio2->priority){ 
        return -1;
    } else if (prio1->priority > prio2->priority){
        return 1;
    } else{
        return 0;
    }
}

int compare_admins(const void *ip1, const void *ip2){
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
    } else{
        return 0;
    } 
}

int compare_title(const void *ip1, const void *ip2){
    int i;
    task *name1 = (task *)ip1,
         *name2 = (task *)ip2;
    
    for (i = 0; (name1->title[i] =! '\n'); i++){
        name1->title[i] = tolower(name1->title[i]);
    }
    for (i = 0; (name2->title[i] =! '\n'); i++){
        name2->title[i] = tolower(name2->title[i]);
    }

    if (strcmp(name1->title, name2->title) < 0){
        return -1;
    } else if (strcmp(name1->title, name2->title) > 0){
        return 1;
    } else{
        return 0;
    } 
}

int compare_category(const void *ip1, const void *ip2){
    int i;
    task *name1 = (task *)ip1,
         *name2 = (task *)ip2;
    
    for (i = 0; (name1->category[i] =! '\n'); i++){
        name1->category[i] = tolower(name1->category[i]);
    }
    for (i = 0; (name2->category[i] =! '\n'); i++){
        name2->category[i] = tolower(name2->category[i]);
    }

    if (strcmp(name1->category, name2->category) < 0){
        return -1;
    } else if (strcmp(name1->category, name2->category) > 0){
        return 1;
    } else{
        return 0;
    } 
}