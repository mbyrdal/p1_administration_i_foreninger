#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include "opret_opgave.h"
#include "Start_Prompt.h"

#define SENTINEL 3


int main(void) {
    char dir_name[200]; /* PATH til en mappe. Maksimum længde = 200 tegn. */
    char temp_file_name[50]; /* Buffer/midlertidig filnavn. Maksimum længde = 50 tegn. */
    char file_name[50]; /* Filnavn. Maksimum længde = 50 tegn. */
    char mk_dir[15]; /* Make-directory kommando. Maksimum længde = 15 tegn. */
    FILE *file; /* Typecast file som FILE. */
    int option; /* Bruger-input omformuleret til talværdi. */
    task tasks[1];
    int amount_of_tasks = -1;

    /* Prompt en bruger for input navn (PATH) til en mappe */
    bruger_input("Skriv navn paa mappen: ", dir_name);

    /* Hvis mappen findes, så print "Mappe fundet". */
    /* Hvis mappen ikke findes, så oprettes en mappe efter det indtastede input. */
    if (dir_exists(dir_name)){
        printf("Mappe fundet!\n");
    } else{
        sprintf(mk_dir, "mkdir %s", dir_name);
        printf("Mappe oprettet!\n");
        system(mk_dir);
        }
    do {
        /* Prompt brugeren for, om programmet skal åbne eller oprette en fil. */
        option = prompt_bruger_for_muligheder("Hvad vil du nu? \n\n"
                                              " 1) aabne en fil\n"
                                              " 2) Oprette en ny fil\n"
                                              " 3) Afslut program \n\n> ");

        if (option == 1){
            /* Hvis brugeren vælger at åbne en eksisterende fil. */
            bruger_input("Skriv navn paa filen: ", temp_file_name);
            sprintf(file_name, "%s/%s.txt", dir_name, temp_file_name);

            file = fopen(file_name, "w");

            if(file != NULL){

                printf("amount_of_tasks = %d\n", amount_of_tasks);
                tasks[0] = create_task(tasks, &amount_of_tasks);
                printf("amount_of_tasks = %d\n", amount_of_tasks);
                file_write_task(file, tasks[amount_of_tasks]);
            }

            fclose(file); /* Lukker filen. */
        }else if (option == 2){
            /* Hvis brugeren vælger at oprette en ny fil. */
            bruger_input("Skriv det nye filnavn: ", temp_file_name);
            sprintf(file_name, "%s/%s.txt", dir_name, temp_file_name);

            file = fopen(file_name, "w");
                tasks[0] = create_task(tasks, &amount_of_tasks);
                file_write_task(file, tasks[0]);
                fclose(file);
        }else if (option != SENTINEL){
            /* Hvis programmet aflæser et ugyldigt input. */
            printf("Ikke en mulighed!\n");
        }
    } while(option != SENTINEL);
    return 0;
}

/* Funktion, som udskriver en besked til og gemmer input fra brugeren.
 * Først printes en besked til brugeren (%s), som prompter for input,
 * hvorefter brugerens input gemmes i en pointer (%s).
 */
void bruger_input(char *print, char *input){
    printf(print);
    scanf("%s", input);
}
/* Funktion, som gør brug af bools logik til at afgøre,
 * om et directory (mappe) eksisterer ud fra argumentet
 * dir_name (mappens navn). Hvis det eksisterer returneres 1, ellers 0.
 */
int dir_exists(char *dir_name){
    DIR* dir;
    dir = opendir(dir_name);
    if (dir) {
        return 1;
    } else{
        return 0;
    }
}
/* Funktion, som prompter brugeren for svar til muligheder,
 * der efterfølgende returneres (som tal).
 * Funktionen tager højde for ugyldigt input (NaN).
 */
int prompt_bruger_for_muligheder(char *print){
    int option, scanres;
    do {
        printf(print);
        scanres = scanf(" %d", &option);
        if(scanres == 0 && option != SENTINEL) {
            printf("Fejl: Ulaeseligt input. Skriv venligst input igen> \n");
            scanres = scanf(" %*s");
        }
    } while(scanres == 0);
    return option;
}

void file_write_task(FILE *fil, task task1){

    fprintf(fil,"Admins: %s\n", task1.admins);
    fprintf(fil,"Titel: %s\n", task1.title);
    fprintf(fil,"Beskrivelse: { %s}\n", task1.description);
    fprintf(fil,"Frivillige: %s\n", task1.volunteers);
    fprintf(fil,"Status: %s\n", task1.status_str);
    fprintf(fil,"Prioritet: %s\n", task1.priority);
    fprintf(fil,"Status: %s\n", task1.status_int);
    fprintf(fil,"Deadline: %d.%d %d.%d.%d\n",
         task1.deadline.tm_hour,
         task1.deadline.tm_min,
         task1.deadline.tm_mday,
         task1.deadline.tm_mon + 1,
         task1.deadline.tm_year + 1900);

}

void file_read_task(FILE *fil, task task1){
    int month, year;

    fscanf(fil," %*[^:]%*c %[^\n]", task1.admins);
    fscanf(fil," %*[^:]%*c %[^\n]", task1.title);
    fscanf(fil," %*[^:]%*c { %[^}]", task1.description);
    fscanf(fil," %*[^:]%*c %[^\n]", task1.volunteers);
    fscanf(fil," %*[^:]%*c %[^\n]", task1.status_str);
    fscanf(fil," %*[^:]%*c %d", &task1.priority);
    fscanf(fil," %*[^:]%*c %d", &task1.status_int);
    fscanf(fil," %*[^:]%*c %d.%d %d.%d.%d",
         &task1.deadline.tm_hour,
         &task1.deadline.tm_min,
         &task1.deadline.tm_mday,
         &month,
         &year);

    task1.deadline.tm_year = year - 1900;
    task1.deadline.tm_mon = month - 1;

}
