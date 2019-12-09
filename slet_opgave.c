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

    task_index = prompt_user_options("Hvilken opgave vil du gerne slette? (Indtast opgavens nummer)\n\n>", *number_of_tasks) - 1;
    printf("Er du sikker paa, at du vil slette opgaven: %s? (Ja/Nej)\n\n> ", tasks[task_index].title);

    while (is_yes_or_no(answer_delete_keep)){ /* Hvis brugeren ikke har skrevet ja eller nej */
        scanf(" %s", answer_delete_keep);
    }

    if (!user_wrote_no(answer_delete_keep)){ /* Hvis brugeren enten skriver ja */
        if (task_index != (*number_of_tasks - 1)){
            tasks[task_index] = tasks[*number_of_tasks - 1];
        }
        *number_of_tasks -= 1;
    } else{ /* Hvis nej ... */
        printf("Vil du stadig slette en opgave? (Ja/Nej)\n\n> ");

        strcpy(answer_delete_keep, "");
        while (is_yes_or_no(answer_delete_keep)){
            scanf(" %s", answer_delete_keep);
        }

        if(!user_wrote_no(answer_delete_keep)){
            delete_task(tasks, number_of_tasks);
        }
    }
}

/*Funktionen tager en string som argument og returnere en boolsk
 * returværdien beskriver om denne string er er ja/Ja/JA (return 1) eller andet (return 0)*/
int user_wrote_no(char *string){
    /* FEJL TESTER IKKE OM STRING ER NEJ MEN OM DEN ER JA SE TEST5*/
    return (strcmp(string, "ja") && strcmp(string, "Ja") && strcmp(string, "JA"));
}

/*Funktionen tager en string som argument og returnere en boolsk
 * returværdien beskriver om denne string er er ja/Ja/JA/nej/Nej/NEJ (return 1) eller andet (return 0)*/
int is_yes_or_no(char *string){
    return (strcmp(string, "ja") && strcmp(string, "Ja") && strcmp(string, "JA") &&
    strcmp(string, "nej") && strcmp(string, "Nej") && strcmp(string, "NEJ"));
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


/*/////////////////////////////////////////////////////////////////*/
/*TEST*/

void test1_user_wrote_no(CuTest *tc){
    int actual, expected;
    actual = user_wrote_no("Ja");
    expected = 0;
    CuAssertIntEquals(tc, expected, actual);
}

void test2_user_wrote_no(CuTest *tc){
    int actual, expected;
    actual = user_wrote_no("nej");
    expected = 1;
    CuAssertIntEquals(tc, expected, actual);
}

void test3_user_wrote_no(CuTest *tc){
    int actual, expected;
    actual = user_wrote_no("Nej");
    expected = 1;
    CuAssertIntEquals(tc, expected, actual);
}

void test4_user_wrote_no(CuTest *tc){
    int actual, expected;
    actual = user_wrote_no("NEJ");
    expected = 1;
    CuAssertIntEquals(tc, expected, actual);
}

void test5_user_wrote_no(CuTest *tc){
    int actual, expected;
    actual = user_wrote_no("neje");
    expected = 0;
    CuAssertIntEquals(tc, expected, actual);
}

CuSuite *user_wrote_no_get_suite(){
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test1_user_wrote_no);
    SUITE_ADD_TEST(suite, test2_user_wrote_no);
    SUITE_ADD_TEST(suite, test3_user_wrote_no);
    SUITE_ADD_TEST(suite, test4_user_wrote_no);
    SUITE_ADD_TEST(suite, test5_user_wrote_no);
    return suite;
}

void test1_is_yes_or_no(CuTest *tc){
    int actual, expected;
    actual = is_yes_or_no("nej");
    expected = 1;
    CuAssertIntEquals(tc, expected, actual);
}

void test2_is_yes_or_no(CuTest *tc){
    int actual, expected;
    actual = is_yes_or_no("Nej");
    expected = 1;
    CuAssertIntEquals(tc, expected, actual);
}

void test3_is_yes_or_no(CuTest *tc){
    int actual, expected;
    actual = is_yes_or_no("NEJ");
    expected = 1;
    CuAssertIntEquals(tc, expected, actual);
}

void test4_is_yes_or_no(CuTest *tc){
    int actual, expected;
    actual = is_yes_or_no("ja");
    expected = 1;
    CuAssertIntEquals(tc, expected, actual);
}

void test5_is_yes_or_no(CuTest *tc){
    int actual, expected;
    actual = is_yes_or_no("Ja");
    expected = 1;
    CuAssertIntEquals(tc, expected, actual);
}

void test6_is_yes_or_no(CuTest *tc){
    int actual, expected;
    actual = is_yes_or_no("JA");
    expected = 1;
    CuAssertIntEquals(tc, expected, actual);
}

void test7_is_yes_or_no(CuTest *tc){
    int actual, expected;
    actual = is_yes_or_no("JAS");
    expected = 0;
    CuAssertIntEquals(tc, expected, actual);
}

void test8_is_yes_or_no(CuTest *tc){
    int actual, expected;
    actual = is_yes_or_no("neje");
    expected = 0;
    CuAssertIntEquals(tc, expected, actual);
}

CuSuite *is_yes_or_no_get_suite(){
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test1_is_yes_or_no);
    SUITE_ADD_TEST(suite, test2_is_yes_or_no);
    SUITE_ADD_TEST(suite, test3_is_yes_or_no);
    SUITE_ADD_TEST(suite, test4_is_yes_or_no);
    SUITE_ADD_TEST(suite, test5_is_yes_or_no);
    SUITE_ADD_TEST(suite, test6_is_yes_or_no);
    SUITE_ADD_TEST(suite, test7_is_yes_or_no);
    SUITE_ADD_TEST(suite, test8_is_yes_or_no);
    return suite;
}
