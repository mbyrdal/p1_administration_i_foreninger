#include "include.h"

#define SENTINEL 3


int main(void) {
    char dir_name[100]; /* PATH til en mappe. Maksimum længde = 100 tegn. */
    task tasks[MAX_TASKS];
    int amount_of_tasks = 0;

    /* Prompt en bruger for input navn (PATH) til en mappe */
    bruger_input("Skriv navn paa mappen: ", dir_name);

    create_dir(dir_name);
    file_managing(tasks, amount_of_tasks, dir_name);

    return 0;
}

/* Funktion, som udskriver en besked til og gemmer input fra brugeren.
 * Først printes en besked til brugeren (%s), som prompter for input,
 * hvorefter brugerens input gemmes i en pointer (%s).
 */
void bruger_input(char *print, char *input){
    printf("%s", print);
    scanf("%s%*[^\n]", input);
}

void create_dir(char *dir_name){
    char mk_dir[125]; /* Make-directory kommando. Maksimum længde = 125 tegn. */

    /* Hvis mappen findes, så print "Mappe fundet". */
    /* Hvis mappen ikke findes, så oprettes en mappe efter det indtastede input. */
    if (dir_exists(dir_name)){
        printf("Mappe fundet!\n");
    } else{
        sprintf(mk_dir, "mkdir %s", dir_name);
        printf("Mappe oprettet!\n");
        system(mk_dir);
        }
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

/* Loop der spørger om brugeren vil åbne / oprette ny fil
 * Ved åbning af fil, læses der task fra angivne file
 * ved oprettelse af ny fil oprettes en opgave (task) i den angivne fil
 * Loop afsluttes ved indtastning af SENTINEL, som er 3
 */
void file_managing(task *tasks, int amount_of_tasks, char *dir_name){
    int option; /* Bruger-input omformuleret til talværdi. */
    char temp_file_name[100]; /* Buffer/midlertidig filnavn. Maksimum længde = 100 tegn. */
    char file_name[100]; /* Filnavn. Maksimum længde = 100 tegn. */
    FILE *file; /* Typecast file som FILE. */

    do {
        /* Prompt brugeren for, om programmet skal åbne eller oprette en fil. */
        option = prompt_prompt_user_options("Hvad vil du nu? \n\n"
                                              " 1) aabne en fil (Læse fra fil)\n"
                                              " 2) Oprette en ny fil (Skrive til fil)\n"
                                              " 3) Afslut program \n\n> ", 3);

        if (option == 1){
            /* Hvis brugeren vælger at åbne en eksisterende fil. */
            bruger_input("Skriv navn paa filen: ", temp_file_name);
            sprintf(file_name, "%s/%s.txt", dir_name, temp_file_name);

            file = fopen(file_name, "r");

            if(file != NULL){
                /*create_task(tasks, &amount_of_tasks);*/
/*                file_write_task(file, tasks[amount_of_tasks - 1]);*/
                file_read_task(file, tasks[amount_of_tasks]);
            }

            fclose(file);
        }else if (option == 2){
            /* Hvis brugeren vælger at oprette en ny fil. */
            bruger_input("Skriv det nye filnavn: ", temp_file_name);
            sprintf(file_name, "%s/%s.txt", dir_name, temp_file_name);

            file = fopen(file_name, "w");
                create_task(tasks, &amount_of_tasks);
                file_write_task(file, tasks[amount_of_tasks - 1]);
                fclose(file);
        }else if (option != SENTINEL){
            /* Hvis programmet aflæser et ugyldigt input. */
            printf("Ikke en mulighed!\n");
        }
    } while(option != SENTINEL);
}

/* printer en task (struc task) til en fil
 * hvilken fil der skrives til bestemmes i fil argumentet
 * og hvilken task angives i task1 argumentet
 */
void file_write_task(FILE *fil, task task1){

    fprintf(fil,"Kategori: %s\n", task1.category);
    fprintf(fil,"Admins: %s\n", task1.admins);
    fprintf(fil,"Titel: %s\n", task1.title);
    fprintf(fil,"Beskrivelse: {%s}\n", task1.description);
    fprintf(fil,"Frivillige: %s\n", task1.volunteers);
    fprintf(fil,"Status: %s\n", task1.status_str);
    fprintf(fil,"Prioritet: %d\n", task1.priority);
    fprintf(fil,"Deadline: %d.%d %d.%d.%d\n",
         task1.deadline.tm_hour,
         task1.deadline.tm_min,
         task1.deadline.tm_mday,
         task1.deadline.tm_mon + 1,
         task1.deadline.tm_year + 1900);

}

/* Scanner en fil for en task (struc task)
 * hvilken fil der læses fra bestemmes i fil argumentet
 * og bliver gemt i task1 argumentet
 */
void file_read_task(FILE *fil, task task1){
    int month, year;


    /*
     * ALLE FELTER SKAL SKRIVES TIL HVER FIL / TASK FØR DENNE VIRKER
     * (hvis et int felt står tom bliver deadline underlig)
     * KATEGORI MANGLER
     */
    fscanf(fil,"%*[^:]%*c %[^\n]", task1.category);
    fscanf(fil," %*[^:]%*c %[^\n]", task1.admins);
    fscanf(fil," %*[^:]%*c %[^\n]", task1.title);
    fscanf(fil," %*[^:]%*c { %[^}]", task1.description);
    fscanf(fil," %*[^:]%*c %[^\n]", task1.volunteers);
    fscanf(fil," %*[^:]%*c %[^\n]", task1.status_str);
    fscanf(fil," %*[^:]%*c %d", &task1.priority);
    fscanf(fil," %*[^:]%*c %d.%d %d.%d.%d",
         &task1.deadline.tm_hour,
         &task1.deadline.tm_min,
         &task1.deadline.tm_mday,
         &month,
         &year);

    task1.deadline.tm_year = year - 1900;
    task1.deadline.tm_mon = month - 1;

    /* Task1 printes (til debug)*/
    print_task(task1);
}
