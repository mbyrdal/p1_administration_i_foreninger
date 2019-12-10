#include "include.h"

/* Funktion, som sletter en opgave (task) efter behov
 * Først printes alle opgaverne i en fil under kategori
 * Der promptes for et opgaveindex, som skal slettes
 * Herefter promptes brugeren for, om de er sikre på,
   at de vil slette opgaven på det bestemte index
 * Hvis brugeren svarer ja, så nulstilles en opgave
   og antallet af opgaver i filen tælles ned med 1 (number_of_tasks--)
 * Hvis brugeren derimod svarer nej, så promptes der for,
   om brugeren stadigvæk vil slette en opgave
 * Hvis brugeren svarer ja, så køres funktionen delete_task igen
 * Hvis brugeren svarer nej, så kommer brugeren ud af funktionen */
void delete_task(task tasks[], int *number_of_tasks){
    int i, task_index;
    char answer_delete_keep[10];

    for (i = 0; i < *number_of_tasks; i++){ /* Loop igennem array af tasks fra 0->number_of_tasks */
        printf("%-10d %-s\n", i+1, tasks[i].title);
    }
    task_index = prompt_user_options("Hvilken opgave vil du gerne slette? (Indtast opgavens nummer)\n>", *number_of_tasks) - 1;
    printf("Er du sikker paa, at du vil slette opgaven: %s? (j/n)\n> ", tasks[task_index].title);
    /* Hvis brugeren ikke har skrevet ja eller nej */
    while (!(strcmp_lower(answer_delete_keep, "j") || strcmp_lower(answer_delete_keep, "n"))){
        scanf(" %1s", answer_delete_keep);
        clear_input();
    }
    /* Hvis brugeren skriver j (ja) */
    if (strcmp_lower(answer_delete_keep, "j")){
        if (task_index != (*number_of_tasks - 1)){
            tasks[task_index] = tasks[*number_of_tasks - 1];
        }
        *number_of_tasks -= 1;
    /* Hvis brugeren skriver n (nej) */
    } else{
        printf("Vil du stadig slette en opgave? (j/n)\n> ");
        strcpy(answer_delete_keep, "");
        while (!(strcmp_lower(answer_delete_keep, "j") || strcmp_lower(answer_delete_keep, "n"))){
            scanf(" %1s", answer_delete_keep);
            clear_input();
        }
        if (strcmp_lower(answer_delete_keep, "j")){
            delete_task(tasks, number_of_tasks);
        }
    }
}

/* Funktion, som sletter en kategori og alle opgaver (tasks) med denne kategori
 * det sidste argument (char category[]) beskrive hvilken kategori der skal slettes
 * MANGLER Når en kategori er slettet SKAL number_of_categories TÆLLES NED
 * Herefter promptes brugeren for, om de er sikre på,*/
void delete_category(task tasks[], int *number_of_tasks, char category[]){
    int i;
    for (i = 0; i < *number_of_tasks; i++){
        if (strcmp(category, tasks[i].category) == 0 && i < *number_of_tasks - 1){
            tasks[i] = tasks[*number_of_tasks - 1];
            *number_of_tasks -= 1;
            i--;
        }
        else if (strcmp(category, tasks[i].category) == 0){
            *number_of_tasks -= 1;
        }
    }
}

/*/////////////////////////////////////*/
/* TEST */

void test1_delete_task(CuTest *tc){
    task tasks[2];
    int number_of_tasks = 2;

    strcpy(tasks[0].category,"category1");
    strcpy(tasks[0].title, "title1");
    strcpy(tasks[0].admins, "admin1");
    strcpy(tasks[0].volunteers, "Volunteer1");
    strcpy(tasks[0].description, "description1");
    strcpy(tasks[0].status_str, "status1");
    tasks[0].priority = 2;
    tasks[0].deadline.tm_hour = 20;
    tasks[0].deadline.tm_min = 15;
    tasks[0].deadline.tm_mday = 20;
    tasks[0].deadline.tm_mon = 3;
    tasks[0].deadline.tm_year = 29;

    strcpy(tasks[1].category, "category2");
    strcpy(tasks[1].title, "title2");
    strcpy(tasks[1].admins, "admin2");
    strcpy(tasks[1].volunteers, "Volunteer2");
    strcpy(tasks[1].description, "description2");
    strcpy(tasks[1].status_str, "status2");
    tasks[1].priority = 5;
    tasks[1].deadline.tm_hour = 30;
    tasks[1].deadline.tm_min = 45;
    tasks[1].deadline.tm_mday = 25;
    tasks[1].deadline.tm_mon = 6;
    tasks[1].deadline.tm_year = 59;

    delete_category(tasks, &number_of_tasks, "category1");

    CuAssertIntEquals(tc, number_of_tasks, 1);
    CuAssertStrEquals(tc, tasks[0].category, "category2");
}

void test2_delete_task(CuTest *tc){
    task tasks[5];
    int number_of_tasks = 5;

    strcpy(tasks[0].category, "category1");
    strcpy(tasks[0].title, "titas");
    strcpy(tasks[0].admins, "admisdn1");
    strcpy(tasks[0].volunteers, "Voluntddeer1");
    strcpy(tasks[0].description, "descdasription1");
    strcpy(tasks[0].status_str, "staasdtus1");
    tasks[0].priority = 5;
    tasks[0].deadline.tm_hour = 30;
    tasks[0].deadline.tm_min = 45;
    tasks[0].deadline.tm_mday = 25;
    tasks[0].deadline.tm_mon = 6;
    tasks[0].deadline.tm_year = 59;

    strcpy(tasks[1].category,"category3");
    strcpy(tasks[1].title, "title3");
    strcpy(tasks[1].admins, "admin3");
    strcpy(tasks[1].volunteers, "Volunteer3");
    strcpy(tasks[1].description, "description3");
    strcpy(tasks[1].status_str, "status3");
    tasks[1].priority = 2;
    tasks[1].deadline.tm_hour = 20;
    tasks[1].deadline.tm_min = 15;
    tasks[1].deadline.tm_mday = 20;
    tasks[1].deadline.tm_mon = 3;
    tasks[1].deadline.tm_year = 29;

    strcpy(tasks[2].category, "category1");
    strcpy(tasks[2].title, "title1");
    strcpy(tasks[2].admins, "admin1");
    strcpy(tasks[2].volunteers, "Volunteer1");
    strcpy(tasks[2].description, "description1");
    strcpy(tasks[2].status_str, "status1");
    tasks[2].priority = 5;
    tasks[2].deadline.tm_hour = 30;
    tasks[2].deadline.tm_min = 45;
    tasks[2].deadline.tm_mday = 25;
    tasks[2].deadline.tm_mon = 6;
    tasks[2].deadline.tm_year = 59;

    strcpy(tasks[3].category,"category5");
    strcpy(tasks[3].title, "title5");
    strcpy(tasks[3].admins, "admin5");
    strcpy(tasks[3].volunteers, "Volunteer5");
    strcpy(tasks[3].description, "description5");
    strcpy(tasks[3].status_str, "status5");
    tasks[3].priority = 2;
    tasks[3].deadline.tm_hour = 20;
    tasks[3].deadline.tm_min = 15;
    tasks[3].deadline.tm_mday = 20;
    tasks[3].deadline.tm_mon = 3;
    tasks[3].deadline.tm_year = 29;

    strcpy(tasks[4].category, "category1");
    strcpy(tasks[4].title, "title1");
    strcpy(tasks[4].admins, "admin1");
    strcpy(tasks[4].volunteers, "Volunteer1");
    strcpy(tasks[4].description, "description1");
    strcpy(tasks[4].status_str, "status1");
    tasks[4].priority = 5;
    tasks[4].deadline.tm_hour = 30;
    tasks[4].deadline.tm_min = 45;
    tasks[4].deadline.tm_mday = 25;
    tasks[4].deadline.tm_mon = 6;
    tasks[4].deadline.tm_year = 59;

    delete_category(tasks, &number_of_tasks, "category1");

    CuAssertIntEquals(tc, number_of_tasks, 2);
    CuAssertStrEquals(tc, tasks[0].category, "category5");
    CuAssertStrEquals(tc, tasks[1].category, "category3");
}

CuSuite *delete_category_get_suite(){
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test1_delete_task);
    SUITE_ADD_TEST(suite, test2_delete_task);
    return suite;
}
