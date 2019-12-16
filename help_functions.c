#include "include.h"

void clear_input(void){
    char skip_ch;
    do{
        scanf("%c", &skip_ch);
    } while(skip_ch != '\n');
}

void print_task(task task1){

    printf("%-26s%s \n%-26s%s \n%-26s%s \n%-26s%s \n%-26s%s \n%-26s%d "
           "\n%-26s%02d.%02d %02d.%02d.%d\n",
           "Titel: ", task1.title,
           "Administrerende personer: ", task1.admins,
           "Frivillige personer: ", task1.volunteers,
           "Beskrivelse: ", task1.description,
           "Status: ", task1.status_str,
           "Prioritering: ", task1.priority,
           "Deadline: ",
           task1.deadline.tm_hour, task1.deadline.tm_min,
           task1.deadline.tm_mday, task1.deadline.tm_mon,
           task1.deadline.tm_year);
}

int prompt_user_options(char *print, int amount_of_options){
    int option, scanres;
    do{
        printf("%s", print);
        scanres = scanf(" %d", &option);
        clear_input();
    } while (scanres == 0 || option > amount_of_options || option <= 0);
    return option;
}

int check_answer(char answer){
    if (tolower(answer) == 'j'){
        return 1;
    } else if (tolower(answer) == 'n'){
        return -1;
    } else{
        return 0;
    }
}

/*/////////////////////////////////////////////////////////////////*/
/* TEST */

void test_check_answer(CuTest *tc){
    int actual, expected;
    char test_char;

    for (test_char = 0; test_char <= 127 && test_char >= 0; test_char++){
        actual = check_answer(test_char);

        if (test_char == 'j' || test_char == 'J'){
            expected = 1;
        } else if (test_char == 'n' || test_char == 'N'){
            expected = -1;
        } else {
            expected = 0;
        }

        CuAssertIntEquals(tc, expected, actual);
    }
}

CuSuite *check_answer_get_suite(){
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_check_answer);
    return suite;
}
