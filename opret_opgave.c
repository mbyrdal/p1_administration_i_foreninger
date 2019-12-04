#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

struct task{
    char category[100],
         admins[250],
         title[100],
         description[1000],
         volunteers[250],
         status_str[1000];
    int priority,
        number;
    struct tm deadline;
};
typedef struct task task;

/* En funktion til at oprettet en opgave i systemet */
task create_task(task tasks[], int *new_task){
    int month, year;
    char answer[10];

    *new_task += 1;

    /* Spørg om alt det nødvendige information til at oprette en opgave */
    printf("Intast de administrerende personer til opgaven - afslut med enter [Max 250 tegn]:\n");
    scanf(" %[^\n]", tasks[*new_task].admins);
    printf("Intast titlen til opgaven - afslut med enter [Max 100 tegn]:\n");
    scanf(" %[^\n]", tasks[*new_task].title);
    printf("Beskriv opgaven - afslut med } og enter [Max 1000 tegn]:\n");
    scanf(" %[^}]%*c", tasks[*new_task].description);
    printf("Intast de frivillige personer til opgaven - afslut med enter [Max 250 tegn]:\n");
    scanf(" %[^\n]", tasks[*new_task].volunteers);
    printf("Intast den nuværende status på opgaven - afslut med enter [Max 1000 tegn]:\n");
    scanf(" %[^\n]", tasks[*new_task].status_str);
    printf("Intast prioriteringen af opgaven - afslut med enter [fra 1 - 10]:\n");
    do {
        scanf(" %d", &tasks[*new_task].priority);
        if (tasks[*new_task].priority < 1 || tasks[*new_task].priority > 10){
            printf("Tallet var ikke mellem 1 og 10, indtast prioritering igen:\n");
        }
    } while (tasks[*new_task].priority < 1 || tasks[*new_task].priority > 10);
    printf("Indtast deadline på formen timer.minutter dato.måned.år - afslut med enter [fx 17.00 09.12.2019]:\n");
    do {
        scanf(" %d.%d %d.%d.%d",
             &tasks[*new_task].deadline.tm_hour,
             &tasks[*new_task].deadline.tm_min,
             &tasks[*new_task].deadline.tm_mday,
             &month,
             &year);
        
    } while (tasks[*new_task].deadline.tm_hour < 0 || tasks[*new_task].deadline.tm_hour > 23 ||
             tasks[*new_task].deadline.tm_min  < 0 || tasks[*new_task].deadline.tm_min  > 59 ||
             tasks[*new_task].deadline.tm_mday < 1 || tasks[*new_task].deadline.tm_mday > 31 ||
             month < 1 || month  > 12 ||
             year  < 0 || year   > 2100);
    tasks[*new_task].deadline.tm_mon  = month - 1;
    tasks[*new_task].deadline.tm_year = year  - 1900;

    /* Print den givne information, så brugeren kan se om der skal ændres noget */
    printf("\nOpgave %d vil blive oprettet med følgende information:\n"
           "%-26s%s \n%-26s%s \n%-26s%s \n%-26s%s \n%-26s%s \n%-26s%d "
           "\n%-26s%02d.%02d %02d.%02d.%d\n",
           *new_task,
           "Titel: ", tasks[*new_task].title,
           "Administrerende personer: ", tasks[*new_task].admins,
           "Frivillige personer: ", tasks[*new_task].volunteers,
           "Beskrivelse: ", tasks[*new_task].description,
           "Status: ", tasks[*new_task].status_str,
           "Prioritering: ", tasks[*new_task].priority,
           "Deadline: ",
           tasks[*new_task].deadline.tm_hour, tasks[*new_task].deadline.tm_min,
           tasks[*new_task].deadline.tm_mday, tasks[*new_task].deadline.tm_mon + 1,
           tasks[*new_task].deadline.tm_year + 1900);
    
    /* Spørg om der skal ændres noget */
    printf("Vil du ændre noget i opgaven? [Ja/Nej]:\n");
    do {
        scanf(" %s", answer);
    } while (strcmp(answer, "ja") && strcmp(answer, "Ja") && strcmp(answer, "JA") &&
             strcmp(answer, "nej") && strcmp(answer, "Nej") && strcmp(answer, "NEJ"));
    
    /* Hvis der skal ændres noget så gør funktionen til at ændre en opgave */
    if (strcmp(answer, "ja") && strcmp(answer, "Ja") && strcmp(answer, "JA")){
        /* Edit task */ 
    }
    return tasks[*new_task - 1];
}
