#include "include.h"

/* Funktion til at skippe input i inputbufferen,
 * hvis der er input, der ikke blev læst.
 * Funktionen har hverken input eller output.
 */
void clear_input(void){
    char skip_ch;
    do{
        scanf("%c", &skip_ch);
    } while(skip_ch != '\n');
}

/* Funktion til at printe én enkelt opgave.
 * Funktionen tager én enkelt opgave som argument.
 */
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

/* Funktion, som prompter brugeren for svar til muligheder,
 * der efterfølgende returneres (som heltal).
 * Funktionen tager højde for ugyldigt input.
 */
int prompt_user_options(char *print, int amount_of_options){
    int option, scanres;
    do{
        printf("%s", print);
        scanres = scanf(" %d", &option);
        clear_input();
    } while (scanres == 0 || option > amount_of_options || option < 0);
    return option;
}

int strcmp_lower(char *string, char *cmp_string){
    int i,
        string_len = strlen(string);

    if (string_len != strlen(cmp_string)){
        return 0;
    }

    for (i = 0; i < string_len; i++){
        if (tolower(string[i]) != tolower(cmp_string[i])){
            return 0;
        }
    }
    return 1;
}



/*/////////////////////////////////////////////////////////////////*/
/* TEST */

void test1_strcmp_lower(CuTest *tc){
    int actual, expected;
    actual = strcmp_lower("STRING", "string");
    expected = 1;
    CuAssertIntEquals(tc, expected, actual);
}

void test2_strcmp_lower(CuTest *tc){
    int actual, expected;
    actual = strcmp_lower("StRiNg", "sTrInG");
    expected = 1;
    CuAssertIntEquals(tc, expected, actual);
}

void test3_strcmp_lower(CuTest *tc){
    int actual, expected;
    actual = strcmp_lower("String1", "String2");
    expected = 0;
    CuAssertIntEquals(tc, expected, actual);
}

void test4_strcmp_lower(CuTest *tc){
    int actual, expected;
    actual = strcmp_lower("String", "String2");
    expected = 0;
    CuAssertIntEquals(tc, expected, actual);
}

void test5_strcmp_lower(CuTest *tc){
    int actual, expected;
    actual = strcmp_lower("qwertyui", "asdfg");
    expected = 0;
    CuAssertIntEquals(tc, expected, actual);
}

CuSuite *strcmp_lower_get_suite(){
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test1_strcmp_lower);
    SUITE_ADD_TEST(suite, test2_strcmp_lower);
    SUITE_ADD_TEST(suite, test3_strcmp_lower);
    SUITE_ADD_TEST(suite, test4_strcmp_lower);
    SUITE_ADD_TEST(suite, test5_strcmp_lower);
    return suite;
}
