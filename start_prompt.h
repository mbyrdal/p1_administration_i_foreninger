/* Prototypes */

/* Funktion som kører start prompten af programmet.
 * Funktionen tager tasks-arrayet som input, så den kan læse en fil og gøre klar til at ændre i tasks-arrayet.
 * Funktionen tager categories-arrayet som input, der sendes videre til funktionen file_managing().
 * Funktionen tager number_of_tasks som input, der sendes videre til funktionen file_managing.
 * Funktionen tager number_of_categories som input, der sendes videre til funktionen file_managing.
 * Outputter file_name, så den kan oprettes når programmet afsluttes.
 */
 void start_prompt(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories, char *file_name);

/* Funktion, som udskriver en besked til og gemmer input fra brugeren.
 * Først printes en besked til brugeren (%s), som prompter for input,
 * hvorefter brugerens input gemmes i en pointer (%s).
 */
void file_input(char *print, char *input);

/* Funktion, som opretter en mappe, hvis den ikke eksisterer og ellers åbnes, hvis at mappen eksisterer. 
 * Funktionen tager dir_name som input for at tjekke, om den givne mappe eksisterer og ellers oprette en mappe med dette navn.
 */
void create_dir(char *dir_name);

/* Funktion, som gør brug af boolsk logik til at afgøre, om et directory (mappe) eksisterer.
 * Funktionen tager dir_name (mappens navn) som input, hvis mappen eksisterer returneres 1, ellers 0.
 */
int dir_exists(char *dir_name);

/* Funktion der spørger brugeren, om der skal åbnes eller oprettes en fil.
 * Ved åbning af fil, læses der tasks fra angivne fil, ellers oprettes den nye fil.
 * Funktionen tager tasks-arrayet som input og sender det videre til funktionen file_read_task().
 * Funktionen tager categories-arrayet som input og sender det videre til funktionen category_read().
 * Funktionen tager number_of_tasks som input og sender det videre til funktionen file_read_task() og tæller number_of_tasks én op.
 * Funktionen tager number_of_categories som input og sender det videre til funktionen category_read().
 * Funktionen tager dir_name som input for at tilgå mappen, hvor .txt filen ligger.
 * Funktionen tager file_name som input, da dette skal opdateres filen, der bruges som input af programmet.
 */
 void file_managing(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *numer_of_tasks, int *number_of_categories, char *dir_name, char *file_name);

/* Funktion der skriver én opgave til en fil.
 * Funktionen tager fil som input, da det er denne fil der skrives til.
 * Funktionen tager én task som input, da denne task skrives til filen.
 */
void file_write_task(FILE *fil, task task1);

/* Funktionen scanner en fil for en opgave.
 * Funktionen tager fil som input, da den bestemmer hvilken fil, der læses fra.
 * Funktionen tager task1 som pointer, da task1 så opdateres.
 */
void file_read_task(FILE *fil, task *task1);

/* Funnktionen opretter en fil og skriver alle opgaver og kategorier ind i filen.
 * Funktionen tager file_name som input, da det er denne fil, der skal skrives til.
 * Funktionen tager tasks-arrayet som input, da det er disse opgaver, der skal skrives til filen.
 * Funktionen tager categories-arrayet som input, da det er disse kategorier, der skal skrives til filen.
 * Funktionen tager number_of_tasks som input, da den skal vide, hvor mange opgaver, der skal skrives til filen.
 * Funktionen tager number_of_categories som input, da den skal vide, hvor mange kategorier, der skal skrives til filen.
 */
 void create_file(char *file_name, task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int number_of_tasks, int number_of_categories);
 
 /* Funktion der læser alle kategorier fra en fil og opdaterer, hvor mange kategorier der er.
 * Funktionen tager fil som input, da det er den fil, der skal læses fra.
 * Funktionen tager categories-arrayet som input, da de indlæste kategorier skal skrives til dette array.
 * Funktionen tager number_of_categories som input, da den skal tælles op for hver kategori der læses.
 */
 void category_read(FILE *fil, char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_categories);
