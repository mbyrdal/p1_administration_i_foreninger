#include "include.h"

/*Funktion til at skippe input i inputbufferen, hvis der er input, der ikke blev læst*/
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

/* Funktion, som prompter brugeren for svar til muligheder,
 * der efterfølgende returneres (som tal).
 * Funktionen tager højde for ugyldigt input (NaN).
 */
int prompt_user_options(char *print, int amount_of_options){
    int option, scanres;
    do {
        printf("%s", print);
        scanres = scanf(" %d", &option);
        clear_input();
    } while(scanres == 0 || option > amount_of_options || option < 0);
    return option;
}
