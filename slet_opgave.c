#include "include.h"

void delete_task(task tasks[], int *number_of_tasks){
    int i, task_index;
    char answer = '0';

    printf("\n%-10s %-10s\n", "Nummer:", "Titel:");
    for (i = 0; i < *number_of_tasks; i++){
        printf("%-10d %-s\n", i+1, tasks[i].title);
    }
    task_index = prompt_user_options("Hvilken opgave vil du gerne slette? (Indtast opgavens nummer)\n>", *number_of_tasks) - 1;
    printf("Er du sikker paa, at du vil slette opgaven: %s? (j/n)\n> ", tasks[task_index].title);
    while (check_answer(answer) == 0){
        scanf(" %c", &answer);
        clear_input();
    }
    if (check_answer(answer) == 1){
        if (task_index != (*number_of_tasks - 1)){
            tasks[task_index] = tasks[*number_of_tasks - 1];
        }
        *number_of_tasks -= 1;
    } else{
        do{
            printf("Vil du stadig slette en opgave? (j/n)\n> ");
            scanf(" %c", &answer);
            clear_input();
        } while (check_answer(answer) == 0);
        if (check_answer(answer) == 1){
            delete_task(tasks, number_of_tasks);
        }
    }
}
    
void delete_category(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories, int category_delete_index){
    int i;
    for (i = 0; i < *number_of_tasks - 1; i++){
        if (strcmp(categories[category_delete_index], tasks[i].category) == 0){
            tasks[i] = tasks[*number_of_tasks - 1];
            *number_of_tasks -= 1;
            i--;
        }
    }
    if (strcmp(categories[category_delete_index], tasks[i].category) == 0){
        *number_of_tasks -= 1;
    }
    if (category_delete_index < (*number_of_categories - 1)){
        strcpy(categories[category_delete_index], categories[*number_of_categories - 1]);
    }
    *number_of_categories -= 1;
}

/*/////////////////////////////////////*/
/* TEST */

void test1_delete_category(CuTest *tc){
    task tasks[2];
    int number_of_tasks = 2,
        number_of_categories = 2,
        category_delete_index = 0;
    char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY] = {"category1", "category2"};


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

    delete_category(tasks, categories, &number_of_tasks, &number_of_categories, category_delete_index);

    CuAssertIntEquals(tc, number_of_tasks, 1);
    CuAssertIntEquals(tc, number_of_categories, 1);
    CuAssertStrEquals(tc, tasks[0].category, "category2");
    CuAssertStrEquals(tc, categories[0], "category2");
}

void test2_delete_category(CuTest *tc){
    task tasks[5];
    int number_of_tasks = 5,
        number_of_categories = 3,
        category_delete_index = 0;
    char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY] = {"category1", "category3", "category5"};

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

    delete_category(tasks, categories, &number_of_tasks, &number_of_categories, category_delete_index);

    CuAssertIntEquals(tc, number_of_tasks, 2);
    CuAssertIntEquals(tc, number_of_categories, 2);
    CuAssertStrEquals(tc, tasks[0].category, "category5");
    CuAssertStrEquals(tc, tasks[1].category, "category3");
    CuAssertStrEquals(tc, categories[0], "category5");
    CuAssertStrEquals(tc, categories[1], "category3");
}

CuSuite *delete_category_get_suite(){
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test1_delete_category);
    SUITE_ADD_TEST(suite, test2_delete_category);
    return suite;
}
