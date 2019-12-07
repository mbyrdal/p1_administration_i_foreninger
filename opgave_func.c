#include "include.h"

/* En funktion til at oprette en opgave i programmet
 * Funktion tager tasks-arrayet til at oprette den nye opgave i
 * Funktion tager number_of_tasks til at tælle antallet af opgaver op
 */
void create_task(task tasks[], char **categories, int *number_of_tasks, int *number_of_categories){
    int month, year, i = *number_of_tasks;
    char answer[10];
    *number_of_tasks += 1;


    /* Spørg om kategori */
    printf("num = %d\n", *number_of_categories);
    prompt_for_category(categories, number_of_categories);

    printf("Indtast titlen til opgaven - afslut med enter [Max 100 tegn]:\n");
    scanf(" %[^\n]", tasks[i].title);
    printf("Indtast de administrerende personer til opgaven - afslut med enter [Max 250 tegn]:\n");
    scanf(" %[^\n]", tasks[i].admins);
    printf("Beskriv opgaven - afslut med } og enter [Max 1000 tegn]:\n");
    scanf(" %[^}]%*c", tasks[i].description);
    printf("Indtast de frivillige personer til opgaven - afslut med enter [Max 250 tegn]:\n");
    scanf(" %[^\n]", tasks[i].volunteers);
    printf("Indtast den nuværende status på opgaven - afslut med } og enter [Max 1000 tegn]:\n");
    scanf(" %[^}]%*c", tasks[i].status_str);
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

    printf("\nOpgave %d vil blive oprettet med følgende information:\n", i);
    print_task(tasks[i]);

    printf("Vil du ændre noget i opgaven? [Ja/Nej]:\n");
    do {
        scanf(" %s", answer);
    } while (strcmp(answer, "ja") && strcmp(answer, "Ja") && strcmp(answer, "JA") &&
             strcmp(answer, "nej") && strcmp(answer, "Nej") && strcmp(answer, "NEJ"));

    if (strcmp(answer, "ja") && strcmp(answer, "Ja") && strcmp(answer, "JA")){
        /* Edit task */
    }
}

/* Funktion til at ændre en valgt opgave
 * Funktionen tager adressen til en opgave for at ændre værdierne
 */
void change_task(task *task1, char **categories, int number_of_categories){
    enum option {Title = 1, Category, Admins, Volunteers, Description, Status, Priority, Deadline};
    int month, year;
    int option = prompt_user_options("Hvad vil du gerne ændre? [indtast valgmulighedens nummer uden punktum \".\"]: \n\n"
                                     "1.  Titel\n"
                                     "2.  Kategori\n"
                                     "3.  Administrerende personer\n"
                                     "4.  Frivillige personer\n"
                                     "5.  Beskrivelsen\n"
                                     "6.  Status\n"
                                     "7.  Prioritet\n"
                                     "8.  Deadline\n\n"
                                     "Dit valg: ",
                                     8);

    switch (option){
        case Title:
            printf("Indtast titlen til opgaven - afslut med enter [Max 100 tegn]:\n");
            scanf(" %[^\n]", task1->title);
        case Category:
            /* Spørg for kategori */
            prompt_for_category(categories, &number_of_categories);
        case Admins:
            printf("Indtast de administrerende personer til opgaven - afslut med enter [Max 250 tegn]:\n");
            scanf(" %[^\n]", task1->admins);
        case Volunteers:
            printf("Indtast de frivillige personer til opgaven - afslut med enter [Max 250 tegn]:\n");
            scanf(" %[^\n]", task1->volunteers);
        case Description:
            printf("Beskriv opgaven - afslut med } og enter [Max 1000 tegn]:\n");
            scanf(" %[^}]%*c", task1->description);
        case Status:
            printf("Indtast den nuværende status på opgaven - afslut med } og enter [Max 1000 tegn]:\n");
            scanf(" %[^}]%*c", task1->status_str);
        case Priority:
            printf("Indtast prioriteringen af opgaven - afslut med enter [fra 1 - 10]:\n");
            do {
                scanf(" %d", &task1->priority);
                clear_input();
                if (task1->priority < 1 || task1->priority > 10){
                    printf("Tallet var ikke mellem 1 og 10, indtast prioritering igen:\n");
                }
            } while (task1->priority < 1 || task1->priority > 10);
        case Deadline:
            printf("Indtast deadline på formen timer.minutter dato.måned.år - afslut med enter [fx 17.00 09.12.2019]:\n");
            do {
                scanf(" %d.%d %d.%d.%d",
                    &task1->deadline.tm_hour,
                    &task1->deadline.tm_min,
                    &task1->deadline.tm_mday,
                    &month,
                    &year);

            } while (task1->deadline.tm_hour < 0 || task1->deadline.tm_hour > 23 ||
                     task1->deadline.tm_min  < 0 || task1->deadline.tm_min  > 59 ||
                     task1->deadline.tm_mday < 1 || task1->deadline.tm_mday > 31 ||
                     month < 1 || month  > 12 ||
                     year  < 0 || year   > 2100);
            task1->deadline.tm_mon  = month - 1;
            task1->deadline.tm_year = year  - 1900;
    }
}

int prompt_for_category(char **categories, int *number_of_categories){
    int i, option, selected_category;

    do {
        printf("Vaelg kategori:\n");
        printf("num = %d\n", *number_of_categories);
        for (i = 0; i < *number_of_categories; i++){
            /*if (categories[i] != NULL){*/
                printf("%d) %s\n", i + 1, categories[i]);
            /*}*/
        }

        printf("%d) Opret kategori\n", i++);
        printf("%d) Aendre kategori\n", i++);

        option = prompt_user_options("> ", i);

        if (option == i - 2){
            add_category(categories, number_of_categories);
        } else if (option == i - 1){
            printf("Hvilken kategori vil du aendre: \n");
            selected_category = prompt_user_options("> ", *number_of_categories);
            edit_category(categories, selected_category - 1);
        } else{
            return option;
        }
    } while (1/*option < 0 && option >= i - 2*/);

    /*burde aldrig ske*/
    return 0;
}

void add_category(char **categories, int *number_of_categories){
    char temp_string[100];
    printf("Hvad skal den nye kategori hedde?\n"
           "> ");
    scanf(" %s", categories[*number_of_categories]/*temp_string*/);
    /*printf("number_of_categories = %d\n", *number_of_categories);*/
    /*strcpy(categories[*number_of_categories], temp_string);*/
    printf("%s\n", categories[*number_of_categories]);
    *number_of_categories += 1;
}

void edit_category(char **categories, int index){
    /*loop gennem alle kategorier med samme som skal ændre og ændre det */
    printf("Hvad skal kategorien '%s' aendres til?\n"
           "> ", categories[index]);
    scanf("%s", categories[index]);
}
