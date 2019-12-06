/* Prototypes */

/* Funktion som kører start prompten af programmet
 * Tager tasks så den kan læse en fil og gøre klar til at ændre i tasks
 * Tager number_of_tasks så den kan opdateres med hvor mange der læses i filen
 * Outputter file_name, så den kan oprettes når programmet afsluttes
 */
void start_prompt(task tasks[], int *number_of_tasks, char *file_name);

/* Funktion, som udskriver en besked til og gemmer input fra brugeren.
 * Først printes en besked til brugeren (%s), som prompter for input,
 * hvorefter brugerens input gemmes i en pointer (%s).
 */
void file_input(char *print, char *input);

/* Opretter en mappe, hvis den ikke eksistere og ellers åbner, hvis den gør */
void create_dir(char *dir_name);

/* Funktion, som gør brug af bools logik til at afgøre,
 * om et directory (mappe) eksisterer ud fra argumentet
 * dir_name (mappens navn). Hvis det eksisterer returneres 1, ellers 0.
 */
int dir_exists(char *dir_name);

/* Loop der spørger om brugeren vil åbne / oprette ny fil
 * Ved åbning af fil, læses der tasks fra angivne fil
 * Ellers oprettes den nye fil
 * Loop afsluttes ved indtastning af SENTINEL, som er 3
 */
void file_managing(task tasks[], int number_of_tasks, char *dir_name, char *file_name);

/* printer en task (struc task) til en fil
 * hvilken fil der skrives til bestemmes i fil argumentet
 * og hvilken task angives i task1 argumentet
 */
void file_write_task(FILE *fil, task task1);

/* Scanner en fil for en task (struct task)
 * hvilken fil der læses fra bestemmes i fil argumentet
 * og bliver gemt i task1 argumentet
 */
void file_read_task(FILE *fil, task *task1);

/* Opretter en fil og skriver alle tasks ind i filen
 * Tager file_name for at oprette/skrive i filen med det ønskede navn
 * Tager tasks og number_of_tasks til at hente information om opgaverne
 */
void create_file(char *file_name, task tasks[], int number_of_tasks);
