#include "include.h"

/* En funktion til at oprettet en opgave i systemet */
task create_task(task tasks[], int *new_task){
    int month, year;
    char answer[10];

    tasks[*new_task].number = (*new_task) + 1;
    /* Spørg om alt det nødvendige information til at oprette en opgave */
    printf("Indtast de administrerende personer til opgaven - afslut med enter [Max 250 tegn]:\n");
    scanf(" %[^\n]", tasks[*new_task].admins);
    printf("Indtast titlen til opgaven - afslut med enter [Max 100 tegn]:\n");
    scanf(" %[^\n]", tasks[*new_task].title);
    printf("Beskriv opgaven - afslut med } og enter [Max 1000 tegn]:\n");
    scanf(" %[^}]%*c", tasks[*new_task].description);
    printf("Indtast de frivillige personer til opgaven - afslut med enter [Max 250 tegn]:\n");
    scanf(" %[^\n]", tasks[*new_task].volunteers);
    printf("Indtast den nuværende status på opgaven - afslut med enter [Max 1000 tegn]:\n");
    scanf(" %[^\n]", tasks[*new_task].status_str);
    printf("Indtast prioriteringen af opgaven - afslut med enter [fra 1 - 10]:\n");
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

    print_task(tasks[task]);

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
    (*new_task) += 1;
    return tasks[(*new_task) - 1];
}

void print_task(task task1){
    /* Print den givne information, så brugeren kan se om der skal ændres noget */
    printf("\nOpgave %d vil blive oprettet med følgende information:\n"
           "%-26s%s \n%-26s%s \n%-26s%s \n%-26s%s \n%-26s%s \n%-26s%d "
           "\n%-26s%02d.%02d %02d.%02d.%d\n",
           task1.number,
           "Titel: ", tasks1.title,
           "Administrerende personer: ", tasks1.admins,
           "Frivillige personer: ", tasks1.volunteers,
           "Beskrivelse: ", tasks1.description,
           "Status: ", tasks1.status_str,
           "Prioritering: ", tasks1.priority,
           "Deadline: ",
           tasks1.deadline.tm_hour, tasks1.deadline.tm_min,
           tasks1.deadline.tm_mday, tasks1.deadline.tm_mon + 1,
           tasks1.deadline.tm_year + 1900);
}
