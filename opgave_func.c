#include "include.h"

/* En funktion til at oprette en opgave i programmet
 * Funktion tager tasks-arrayet til at oprette den nye opgave i
 * Funktion tager number_of_tasks til at tælle antallet af opgaver op
 */
void create_task(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories){
    int month, year, i = *number_of_tasks;
    char answer[10];
    *number_of_tasks += 1;


    /* Spørg om kategori */
    prompt_for_category(tasks, categories, *number_of_tasks, number_of_categories , i);

    printf("Indtast titlen til opgaven - afslut med enter [Max 100 tegn]:\n");
    scanf(" %[^\n]", tasks[i].title);
    printf("Indtast de administrerende personer til opgaven - afslut med enter [Max 250 tegn]:\n");
    scanf(" %[^\n]", tasks[i].admins);
    printf("Beskriv opgaven - afslut med } og enter [Max 1000 tegn]:\n");
    scanf(" %[^}]%*c", tasks[i].description);
    printf("Indtast de frivillige personer til opgaven - afslut med enter [Max 250 tegn]:\n");
    scanf(" %[^\n]", tasks[i].volunteers);
    printf("Indtast den nuvaerende status paa opgaven - afslut med } og enter [Max 1000 tegn]:\n");
    scanf(" %[^}]%*c", tasks[i].status_str);
    printf("Indtast prioriteringen af opgaven - afslut med enter [fra 1 - 10]:\n");
    do {
        scanf(" %d", &tasks[i].priority);
        clear_input();
        if (tasks[i].priority < 1 || tasks[i].priority > 10){
            printf("Tallet var ikke mellem 1 og 10, indtast prioritering igen:\n");
        }
    } while (tasks[i].priority < 1 || tasks[i].priority > 10);
    printf("Indtast deadline paa formen timer.minutter dato.maaned.aar - afslut med enter [fx 17.00 09.12.2019]:\n");
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

    printf("\nOpgave %d vil blive oprettet med foelgende information:\n", i);
    print_task(tasks[i]);

    printf("Vil du aendre noget i opgaven? [Ja/Nej]:\n");
    do {
        scanf(" %s", answer);
        if (strcmp(answer, "ja") || strcmp(answer, "Ja") || strcmp(answer, "JA")){
            change_task(tasks, categories, *number_of_tasks, number_of_categories, i);
        }
    } while (strcmp(answer, "nej") && strcmp(answer, "Nej") && strcmp(answer, "NEJ"));
}

/* Funktion til at ændre en valgt opgave
 * Funktionen tager adressen til en opgave for at ændre værdierne
 */
void change_task(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int number_of_tasks, int *number_of_categories, int index){
    enum option {Title = 1, Category, Admins, Volunteers, Description, Status, Priority, Deadline};
    int month, year;
    int option = prompt_user_options("Hvad vil du gerne aendre? [indtast valgmulighedens nummer uden punktum \".\"]: \n\n"
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
            scanf(" %[^\n]", tasks[index].title);
            break;
        case Category:
            /* Spørg for kategori */
            prompt_for_category(tasks, categories, number_of_tasks, number_of_categories, index);
            break;
        case Admins:
            printf("Indtast de administrerende personer til opgaven - afslut med enter [Max 250 tegn]:\n");
            scanf(" %[^\n]", tasks[index].admins);
            break;
        case Volunteers:
            printf("Indtast de frivillige personer til opgaven - afslut med enter [Max 250 tegn]:\n");
            scanf(" %[^\n]", tasks[index].volunteers);
            break;
        case Description:
            printf("Beskriv opgaven - afslut med } og enter [Max 1000 tegn]:\n");
            scanf(" %[^}]%*c", tasks[index].description);
            break;
        case Status:
            printf("Indtast den nuvaerende status paa opgaven - afslut med } og enter [Max 1000 tegn]:\n");
            scanf(" %[^}]%*c", tasks[index].status_str);
            break;
        case Priority:
            printf("Indtast prioriteringen af opgaven - afslut med enter [fra 1 - 10]:\n");
            do {
                scanf(" %d", &tasks[index].priority);
                clear_input();
                if (tasks[index].priority < 1 || tasks[index].priority > 10){
                    printf("Tallet var ikke mellem 1 og 10, indtast prioritering igen:\n");
                }
            } while (tasks[index].priority < 1 || tasks[index].priority > 10);
            break;
        case Deadline:
            printf("Indtast deadline paa formen timer.minutter dato.maaned.aar - afslut med enter [fx 17.00 09.12.2019]:\n");
            do {
                scanf(" %d.%d %d.%d.%d",
                    &tasks[index].deadline.tm_hour,
                    &tasks[index].deadline.tm_min,
                    &tasks[index].deadline.tm_mday,
                    &month,
                    &year);

            } while (tasks[index].deadline.tm_hour < 0 || tasks[index].deadline.tm_hour > 23 ||
                     tasks[index].deadline.tm_min  < 0 || tasks[index].deadline.tm_min  > 59 ||
                     tasks[index].deadline.tm_mday < 1 || tasks[index].deadline.tm_mday > 31 ||
                     month < 1 || month  > 12 ||
                     year  < 0 || year   > 2100);
            tasks[index].deadline.tm_mon  = month - 1;
            tasks[index].deadline.tm_year = year  - 1900;
            break;
    }
}

void prompt_for_category(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int number_of_tasks, int *number_of_categories, int index){
    int i, option, selected_category;

    do {
        printf("Vaelg kategori:\n");
        for (i = 0; i < *number_of_categories; i++){
                printf("%d) %s\n", i + 1, categories[i]);
        }

        printf("%d) Opret kategori\n", ++i);
        printf("%d) Aendre kategori\n", ++i);

        option = prompt_user_options("> ", i);

        if (option == i - 1){
            add_category(categories, number_of_categories);
            printf("%s\n", categories[*number_of_categories - 1]);
        } else if (option == i){
            printf("Hvilken kategori vil du aendre: \n");
            selected_category = prompt_user_options("> ", *number_of_categories);
            edit_category(tasks, categories, selected_category - 1, number_of_tasks);
        } else{
            strcpy(tasks[index].category, categories[option - 1]);
        }
    } while (option < 0 || option >= i - 1);
}

void add_category(char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_categories){
    printf("Hvad skal den nye kategori hedde?\n"
           "> ");
    scanf(" %s", categories[*number_of_categories]);
    *number_of_categories += 1;
}

void edit_category(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int index, int number_of_tasks){
    int i;
    char temp_category[MAX_LENGTH_OF_CATEGORY];
    strcpy(temp_category, categories[index]);
    /*loop gennem alle kategorier med samme som skal ændre og ændre det */
    printf("Hvad skal kategorien '%s' aendres til?\n"
           "> ", categories[index]);
    scanf("%s", categories[index]);
    for (i = 0; i < number_of_tasks; i++){
        if (strcmp(temp_category, tasks[i].category) != 0){
            strcpy(tasks[i].category, categories[index]);
        }
    }
}
