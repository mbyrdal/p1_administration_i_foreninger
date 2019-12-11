/* Prototypes */

/* Funktionen sletter en opgave efter brugerens valg.
 * Funktionen tager tasks-arrayet som input, da en opgave skal slettes, og alle opgaver skal printes.
 * Funktionen tager number_of_tasks som input, da det skal tælles ned, hvis en opgave slettes.
 * Derudover skal number_of_tasks bruges til at printe alle opgaver.
 */
void delete_task(task tasks[], int *number_of_tasks);

/* Funktion, som sletter en kategori og alle opgaver (tasks) med denne kategori.
 * Funktionen tager tasks-arrayet som input, da den skal lede efter en bestemt kategori, der skal slettes.
 * Funktionen tager number_of_tasks som input, da det skal tælles ned, hvis en opgave slettes.
 * Funktionen tager category[] som input, og det er den kategori, der skal slettes.
 */
void delete_category(task tasks[], int *number_of_tasks, char category[]);

/* TEST */
CuSuite *delete_category_get_suite();
