#include "include.h"
#define SENTINEL 3

/* Funktion som kører start prompten af programmet.
 * Funktionen tager tasks-arrayet som input, så den kan læse en fil og gøre klar til at ændre i tasks-arrayet.
 * Funktionen tager categories-arrayet som input, der sendes videre til funktionen file_managing().
 * Funktionen tager number_of_tasks som input, der sendes videre til funktionen file_managing.
 * Funktionen tager number_of_categories som input, der sendes videre til funktionen file_managing.
 * Outputter file_name, så den kan oprettes når programmet afsluttes.
 */
void start_prompt(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories, char *file_name){
    char dir_name[100];

    while (!dir_exists(dir_name)) {
        file_input("Skriv navn paa mappen du vil aabne:\n> ", dir_name);
        create_dir(dir_name);
    }
    file_managing(tasks, categories, number_of_tasks, number_of_categories, dir_name, file_name);
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

/* Funktion, som opretter en mappe, hvis den ikke eksisterer og ellers åbnes, hvis at mappen eksisterer.
 * Funktionen tager dir_name som input for at tjekke, om den givne mappe eksisterer og ellers oprette en mappe med dette navn.
 */
void create_dir(char *dir_name){
    char mk_dir[125], option[4];

    if (dir_exists(dir_name)){
        printf("Mappe fundet!\n");
    } else{
        printf("Mappe findes ikke, vi du oprette en ny med dette navn? [ja/nej]\n> ");
        scanf(" %4s", option);
        clear_input();
        if(strcmp(option, "ja") == 0 || strcmp(option, "Ja") == 0 || strcmp(option, "JA") == 0){
            sprintf(mk_dir, "mkdir %s", dir_name);
            printf("Mappe oprettet!\n");
            system(mk_dir);
        }
    }
}

/* Funktion, som gør brug af boolsk logik til at afgøre, om et directory (mappe) eksisterer.
 * Funktionen tager dir_name (mappens navn) som input, hvis mappen eksisterer returneres 1, ellers 0.
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

/* Funktion der spørger brugeren, om der skal åbnes eller oprettes en fil.
 * Ved åbning af fil, læses der tasks fra angivne fil, ellers oprettes den nye fil.
 * Funktionen tager tasks-arrayet som input og sender det videre til funktionen file_read_task().
 * Funktionen tager categories-arrayet som input og sender det videre til funktionen category_read().
 * Funktionen tager number_of_tasks som input og sender det videre til funktionen file_read_task() og tæller number_of_tasks én op.
 * Funktionen tager number_of_categories som input og sender det videre til funktionen category_read().
 * Funktionen tager dir_name som input for at tilgå mappen, hvor .txt filen ligger.
 * Funktionen tager file_name som input, da dette skal opdateres filen, der bruges som input af programmet.
 */
void file_managing(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories, char *dir_name, char *file_name){
    int option, file_found = 0;
    char temp_file_name[100];
    char temp[] = "nej";
    FILE *file;

    option = prompt_user_options("Hvad vil du nu? \n\n"
                                 "1.  Aabne en fil (Laese fra fil)\n"
                                 "2.  Oprette en ny fil (Skrive til fil)\n> ",
                                 2);

    switch (option){
        case 1:
            do{
                /* 2 newline*/
                file_input("\nSkriv navn paa filen:\n> ", temp_file_name);
                sprintf(file_name, "%s/%s.txt", dir_name, temp_file_name);
                file = fopen(file_name, "r");
                if (file != NULL){
                    file_found = 1;
                    category_read(file, categories, number_of_categories);
                    while (!feof(file)){
                        file_read_task(file, &tasks[(*number_of_tasks)++]);
                        fscanf(file, "%*[^a-zA-Z]");
                    }
                } else{
                    printf("\nFil ikke fundet. Vil du oprette en ny fil med dette navn? [ja/nej]\n> ");
                    scanf(" %s", temp);
                }
                fclose(file);
            } while (!file_found && (strcmp(temp, "ja") && strcmp(temp, "Ja") && strcmp(temp, "JA")));
            break;

        case 2:
            /* 1 newline*/
            file_input("\nSkriv det nye filnavn:\n> ", temp_file_name);
            sprintf(file_name, "%s/%s.txt", dir_name, temp_file_name);
            break;
            
        default:
            printf("Noget er galt!!!!\n");
            break;
    }
}

/* Funktion der skriver én opgave til en fil.
 * Funktionen tager fil som input, da det er denne fil der skrives til.
 * Funktionen tager én task som input, da denne task skrives til filen.
 */
void file_write_task(FILE *fil, task task1){


    fprintf(fil,"Kategori: %s\n", task1.category);
    fprintf(fil,"Admins: %s\n", task1.admins);
    fprintf(fil,"Titel: %s\n", task1.title);
    fprintf(fil,"Beskrivelse: {%s}\n", task1.description);
    fprintf(fil,"Frivillige: %s\n", task1.volunteers);
    fprintf(fil,"Status: {%s}\n", task1.status_str);
    fprintf(fil,"Prioritet: %d\n", task1.priority);
    fprintf(fil,"Deadline: %d.%d %d.%d.%d\n\n",
         task1.deadline.tm_hour,
         task1.deadline.tm_min,
         task1.deadline.tm_mday,
         task1.deadline.tm_mon,
         task1.deadline.tm_year);

}

/* Funktionen scanner en fil for en opgave.
 * Funktionen tager fil som input, da den bestemmer hvilken fil, der læses fra.
 * Funktionen tager task1 som pointer, da task1 så opdateres.
 */
void file_read_task(FILE *fil, task *task1){
    fscanf(fil," %*[^:]%*c %[^\n]", task1->category);
    fscanf(fil," %*[^:]%*c %[^\n]", task1->admins);
    fscanf(fil," %*[^:]%*c %[^\n]", task1->title);
    fscanf(fil," %*[^:]%*c { %[^}]", task1->description);
    fscanf(fil," %*[^:]%*c %[^\n]", task1->volunteers);
    fscanf(fil," %*[^:]%*c { %[^}]", task1->status_str);
    fscanf(fil," %*[^:]%*c %d", &task1->priority);
    fscanf(fil," %*[^:]%*c %d.%d %d.%d.%d %*c",
         &task1->deadline.tm_hour,
         &task1->deadline.tm_min,
         &task1->deadline.tm_mday,
         &task1->deadline.tm_mon,
         &task1->deadline.tm_year);
}

/* Funnktionen opretter en fil og skriver alle opgaver og kategorier ind i filen.
 * Funktionen tager file_name som input, da det er denne fil, der skal skrives til.
 * Funktionen tager tasks-arrayet som input, da det er disse opgaver, der skal skrives til filen.
 * Funktionen tager categories-arrayet som input, da det er disse kategorier, der skal skrives til filen.
 * Funktionen tager number_of_tasks som input, da den skal vide, hvor mange opgaver, der skal skrives til filen.
 * Funktionen tager number_of_categories som input, da den skal vide, hvor mange kategorier, der skal skrives til filen.
 */
void create_file(char *file_name, task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int number_of_tasks, int number_of_categories){
    FILE *file;
    int i;

    file = fopen(file_name, "w");
    if (file != NULL){

        fprintf(file, "Kategorier: ");
        for (i = 0; i < number_of_categories; i++){
            fprintf(file, "{%s} ", categories[i]);
        }
        fprintf(file, "\n\n");

        for (i = 0; i < number_of_tasks; i++){
            file_write_task(file, tasks[i]);
        }
        fclose(file);
    } else{
        printf("Kunne ikke skrive til fil\n");
    }
}

/* Funktion der læser alle kategorier fra en fil og opdaterer, hvor mange kategorier der er.
 * Funktionen tager fil som input, da det er den fil, der skal læses fra.
 * Funktionen tager categories-arrayet som input, da de indlæste kategorier skal skrives til dette array.
 * Funktionen tager number_of_categories som input, da den skal tælles op for hver kategori der læses.
 */
void category_read(FILE *fil, char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_categories){
    char skip_ch;

    fscanf(fil, " %*[^:]%*c");

    do {
        skip_ch = fgetc(fil);
        if (skip_ch == '{'){
            fscanf(fil, " %[^}]%*c", categories[*number_of_categories]);
            *number_of_categories += 1;
        }
    } while (skip_ch != '\n');

    /* takes the last '\n'*/
    fscanf(fil, "%*[^a-zA-Z]");
}
