#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#define SENTINEL -1

void bruger_input(char *print, char *input);
int dir_exists(char *dir_name);
int prompt_bruger_for_muligheder(char *print);

int main(void) {
    char dir_name[200]; /* PATH til en mappe. Maksimum længde = 200 tegn. */
    char temp_file_name[50]; /* Buffer/midlertidig filnavn. Maksimum længde = 50 tegn. */
    char file_name[50]; /* Filnavn. Maksimum længde = 50 tegn. */
    char mk_dir[15]; /* Make-directory kommando. Maksimum længde = 15 tegn. */
    FILE *file; /* Typecast file som FILE. */
    int option; /* Bruger-input omformuleret til talværdi. */

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
                                            " 1) åbne en fil\n"
                                            " 2) Oprette en ny fil\n"
                                            "-1) Afslut program \n\n> ");

      if (option == 1){
          /* Hvis brugeren vælger at åbne en eksisterende fil. */
          bruger_input("Skriv navn paa filen: ", temp_file_name);
          sprintf(file_name, "%s/%s.txt", dir_name, temp_file_name);

          file = fopen(file_name, "r");
          if(file != NULL){
              /* Hvis filen eksisterer og kan åbnes. */
              printf("Fil aabnet!\n");
          }else{
              /* Hvis ikke ... */
              printf("Fil ikke fundet!\n");
          }
          fclose(file); /* Lukker filen. */
      }else if (option == 2){
          /* Hvis brugeren vælger at oprette en ny fil. */
          bruger_input("Skriv det nye filnavn: ", temp_file_name);
          sprintf(file_name, "%s/%s.txt", dir_name, temp_file_name);

          file = fopen(file_name, "w"); /* Producerer en tom fil, som kan skrives i. */
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
    printf("%s", print);
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
      printf("%s", print);
      scanres = scanf(" %d", &option);
      if(scanres == 0 && option != SENTINEL) {
        printf("Fejl: Ulaeseligt input. Skriv venligst input igen> \n");
        scanres = scanf(" %*s");
      }
    } while(scanres == 0);
    return option;
}
