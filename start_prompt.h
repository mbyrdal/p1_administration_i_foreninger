/* Prototypes */

/* Funktion, som kører start prompten af programmet.
 * tasks[]: Input parameter. Arrayet sendes videre til funktionen file_managing().
 * categories[][]: Input parameter. Arrayet sendes videre til funktionen file_managing().
 * number_of_tasks: Input parameter. Parameteren sendes videre til funktionen file_managing().
 * number_of_categories: Input parameter. Parameteren sendes videre til funktionen file_managing().
 * file_name: Input parameter. Parameteren sendes videre til funktionen file_managing().
 * Returnerer ikke noget.
 */
 void start_prompt(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories, char *file_name);

/* Funktion, som udskriver en besked til og gemmer input fra brugeren.
 * print: Input parameter. Denne string printes af funktionen.
 * input: Input parameter. Brugerens input gemmes i denne variabel.
 * Returnerer ikke noget.
 */
void file_input(char *print, char *input);

/* Funktion, som opretter en mappe, hvis den ikke eksisterer og ellers åbnes, hvis at mappen eksisterer. 
 * dir_name: Input parameter. Der tjekkes om en given mappe eksisterer. Hvis ikke oprettes denne mappe, hvis brugeren ønsker det.
 * Returnerer ikke noget.
 */
void create_dir(char *dir_name);

/* Funktion, som gør brug af boolsk logik til at afgøre, om et directory (mappe) eksisterer.
 * dir_name: Input parameter. Der tjekkes om denne mappe eksister.
 * Returnerer 1 hvis mappen findes. Ellers returneres 0.
 */
int dir_exists(char *dir_name);

/* Funktion, der spørger brugeren, om der skal åbnes eller oprettes en fil.
 * tasks[]: Input parameter. Arrayet sendes videre til funktionen file_read_task() eller til sig selv, hvis den kaldes rekursivt.
 * categories[]: Input parameter. Arrayet sendes videre til funktionen category_read().
 * number_of_tasks: Input parameter. Parameteren sendes videre til funktionen file_read_task() og tæller number_of_tasks én op.
 * number_of_categories: Input parameter. Parameteren sendes videre funktionen category_read().
 * dir_name: Input parameter. Bruges til at tilgå mappen, hvor filen der skal læses fra ligger.
 * file_name: Input/output parameter. Denne parameter opdateres med stien til input filen fra der hvor programmet ligger lokalt.
 * Returnerer ikke noget.
 */
 void file_managing(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *numer_of_tasks, int *number_of_categories, char *dir_name, char *file_name);

/* Funktion der skriver én opgave til en fil.
 * fil: Input parameter. Filen der skrives til.
 * tasks1: Input parameter. Opgaven der skal skrives til filen.
 * Returnerer ikke noget.
 */
void file_write_task(FILE *fil, task task1);

/* Funktionen scanner en fil for en opgave.
 * fil: Input parameter. Filen der læses fra.
 * task1: Input/output parameter. Opgaven der skrives til. 
 * Returnerer ikke noget.
 */
void file_read_task(FILE *fil, task *task1);

/* Funnktionen opretter en fil og skriver alle opgaver og kategorier ind i filen.
 * file_name: Input parameter. Filen der skal skrives til. 
 * tasks[]: Input parameter. Opgaverne fra dette array skrives til filen.
 * categories[][]: Input parameter. Kategorierne fra dette array skrives til filen.
 * number_of_tasks: Input parameter. Funktionen skal vide, hvor mange opgaver, der skal skrives til filen.
 * number_of_categories: Input parameter. Funktionen skal vide, hvor mange kategorier, der skal skrives til filen.
 * Returnerer ikke noget.
 */
 void create_file(char *file_name, task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int number_of_tasks, int number_of_categories);
 
/* Funktion der læser alle kategorier fra en fil og opdaterer, hvor mange kategorier der er.
 * fil: Input parameter. Filen der skal læses fra.
 * categories[][]: Input parameter. Indlæste kategorier skrives til dette array.
 * number_of_categories: Input parameter. Tælles op for hver kategori der læses.
 * Returnerer ikke noget.
 */
 void category_read(FILE *fil, char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_categories);
