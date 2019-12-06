#include "include.h"

/* En funktion til at oprettet en opgave i systemet */
void create_task(task tasks[], int *new_task){
    int month, year, i = *new_task;
    char answer[10];
    *new_task += 1;

    /* Spørg om alt det nødvendige information til at oprette en opgave */
    printf("Indtast de administrerende personer til opgaven - afslut med enter [Max 250 tegn]:\n");
    scanf(" %[^\n]", tasks[i].admins);
    printf("Indtast titlen til opgaven - afslut med enter [Max 100 tegn]:\n");
    scanf(" %[^\n]", tasks[i].title);
    printf("Beskriv opgaven - afslut med } og enter [Max 1000 tegn]:\n");
    scanf(" %[^}]%*c", tasks[i].description);
    printf("Indtast de frivillige personer til opgaven - afslut med enter [Max 250 tegn]:\n");
    scanf(" %[^\n]", tasks[i].volunteers);
    printf("Indtast den nuværende status på opgaven - afslut med } og enter [Max 1000 tegn]:\n");
    scanf(" %[^}]", tasks[i].status_str);
    printf("Indtast prioriteringen af opgaven - afslut med enter [fra 1 - 10]:\n");
    do {
        scanf(" %d", &tasks[i].priority);
        clear_input();
        if (tasks[i].priority < 1 || tasks[i].priority > 10){
            printf("Tallet var ikke mellem 1 og 10, indtast prioritering igen:\n");
        }
    } while (tasks[i].priority < 1 || tasks[i].priority > 10);
    printf("Indtast deadline på formen timer.minutter dato.måned.år - afslut med enter [fx 17.00 09.12.2019]:\n");
    do {
        scanf(" %d.%d %d.%d.%d",
             &tasks[i].deadline.tm_hour,
             &tasks[i].deadline.tm_min,
             &tasks[i].deadline.tm_mday,
             &month,
             &year);

    } while (tasks[i].deadline.tm_hour < 0 || tasks[i].deadline.tm_hour > 23 ||
             tasks[i].deadline.tm_min  < 0 || tasks[i].deadline.tm_min  > 59 ||
             tasks[i].deadline.tm_mday < 1 || tasks[i].deadline.tm_mday > 31 ||
             month < 1 || month  > 12 ||
             year  < 0 || year   > 2100);
    tasks[i].deadline.tm_mon  = month - 1;
    tasks[i].deadline.tm_year = year  - 1900;

    /* Print den givne information, så brugeren kan se om der skal ændres noget */
    printf("\nOpgave %d vil blive oprettet med følgende information:\n", i);
    print_task(tasks[i]);

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
}

void print_task(task task1){

    printf("%-26s%d \n%-26s%s \n%-26s%s \n%-26s%s \n%-26s%s \n%-26s%s \n%-26s%d "
           "\n%-26s%02d.%02d %02d.%02d.%d\n",
           "Nummer:", task1.number,
           "Titel: ", task1.title,
           "Administrerende personer: ", task1.admins,
           "Frivillige personer: ", task1.volunteers,
           "Beskrivelse: ", task1.description,
           "Status: ", task1.status_str,
           "Prioritering: ", task1.priority,
           "Deadline: ",
           task1.deadline.tm_hour, task1.deadline.tm_min,
           task1.deadline.tm_mday, task1.deadline.tm_mon + 1,
           task1.deadline.tm_year + 1900);
}
