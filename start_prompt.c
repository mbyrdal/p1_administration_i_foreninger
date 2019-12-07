#include "include.h"
#define SENTINEL 3

/* Funktion som kører start prompten af programmet
 * Tager tasks så den kan læse en fil og gøre klar til at ændre i tasks
 * Tager number_of_tasks så den kan opdateres med hvor mange der læses i filen
 * Outputter file_name, så den kan oprettes når programmet afsluttes
 */
void start_prompt(task tasks[], int *number_of_tasks, char *file_name){
    char dir_name[100];
    file_input("Skriv navn paa mappen: ", dir_name);
    create_dir(dir_name);
    file_managing(tasks, number_of_tasks, dir_name, file_name);
}

/* Funktion, som udskriver en besked til og gemmer input fra brugeren.
 * Først printes en besked til brugeren (%s), som prompter for input,
 * hvorefter brugerens input gemmes i en pointer (%s).
 */
void file_input(char *print, char *input){
    printf("%s", print);
    scanf(" %s", input);
    clear_input();
}

/* Opretter en mappe, hvis den ikke eksistere og ellers åbner, hvis den gør */
void create_dir(char *dir_name){
    char mk_dir[125];

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
    if (dir){
        return 1;
    } else{
        return 0;
    }
}

/* Loop der spørger om brugeren vil åbne / oprette ny fil
 * Ved åbning af fil, læses der tasks fra angivne fil
 * Ellers oprettes den nye fil
 */
void file_managing(task tasks[], int *numer_of_tasks, char *dir_name, char *file_name){
    int option, file_found = 0;
    char temp_file_name[100];
    FILE *file;

    option = prompt_user_options("Hvad vil du nu? \n\n"
                                 "1. aabne en fil (Læse fra fil)\n"
                                 "2. Oprette en ny fil (Skrive til fil)\n\n> ",
                                 2);

    switch (option) {
        case 1:
            do{
                file_input("Skriv navn paa filen: ", temp_file_name);
                sprintf(file_name, "%s/%s.txt", dir_name, temp_file_name);
                file = fopen(file_name, "r");
                if (file != NULL){
                    file_found = 1;
                    while (!feof(file)){
                        file_read_task(file, &tasks[(*numer_of_tasks)++]);
                    }
                } else{
                    printf("Fil ikke fundet\n");
                }
                fclose(file);
            } while (!file_found);
            break;
        case 2:
            file_input("Skriv det nye filnavn: ", temp_file_name);
            sprintf(file_name, "%s/%s.txt", dir_name, temp_file_name);
            break;
        default:
            printf("Noget er galt!!!!\n");
    }
}

/* printer en task (struc task) til en fil
 * hvilken fil der skrives til bestemmes i fil argumentet
 * og hvilken task angives i task1 argumentet
 */
void file_write_task(FILE *fil, task task1){

    /* fprintf(fil,"Kategori: %s\n", task1.category); */
    fprintf(fil,"Admins: %s\n", task1.admins);
    fprintf(fil,"Titel: %s\n", task1.title);
    fprintf(fil,"Beskrivelse: {%s}\n", task1.description);
    fprintf(fil,"Frivillige: %s\n", task1.volunteers);
    fprintf(fil,"Status: %s\n", task1.status_str);
    fprintf(fil,"Prioritet: %d\n", task1.priority);
    fprintf(fil,"Deadline: %d.%d %d.%d.%d\n\n",
         task1.deadline.tm_hour,
         task1.deadline.tm_min,
         task1.deadline.tm_mday,
         task1.deadline.tm_mon + 1,
         task1.deadline.tm_year + 1900);

}

/* Scanner en fil for en task (struct task)
 * hvilken fil der læses fra bestemmes i fil argumentet
 * og bliver gemt i task1 argumentet
 */
void file_read_task(FILE *fil, task *task1){
    int month, year;

    /*
     * ALLE FELTER SKAL SKRIVES TIL HVER FIL / TASK FØR DENNE VIRKER
     * (hvis et int felt står tom bliver deadline underlig)
     * KATEGORI MANGLER
     */
    /* fscanf(fil," %*[^:]%*c %[^\n]", task1.category); */
    fscanf(fil," %*[^:]%*c %[^\n]", task1->admins);
    fscanf(fil," %*[^:]%*c %[^\n]", task1->title);
    fscanf(fil," %*[^:]%*c { %[^}]", task1->description);
    fscanf(fil," %*[^:]%*c %[^\n]", task1->volunteers);
    fscanf(fil," %*[^:]%*c %[^\n]", task1->status_str);
    fscanf(fil," %*[^:]%*c %d", &task1->priority);
    fscanf(fil," %*[^:]%*c %d.%d %d.%d.%d %*c",
         &task1->deadline.tm_hour,
         &task1->deadline.tm_min,
         &task1->deadline.tm_mday,
         &month,
         &year);

    task1->deadline.tm_year = year - 1900;
    task1->deadline.tm_mon = month - 1;
}

/* Opretter en fil og skriver alle tasks ind i filen
 * Tager file_name for at oprette/skrive i filen med det ønskede navn
 * Tager tasks og number_of_tasks til at hente information om opgaverne
 */
void create_file(char *file_name, task tasks[], int number_of_tasks){
    FILE *file;
    int i;

    file = fopen(file_name, "w");
    if (file != NULL){
        for (i = 0; i < number_of_tasks; i++){
            file_write_task(file, tasks[i]);
        }
        fclose(file);
    } else{
        printf("Kunne ikke skrive til fil\n");
    }
}
