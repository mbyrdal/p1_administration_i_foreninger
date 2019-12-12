/* Prototypes */

/* Funktionen printer alle opgaver og sletter derefter en opgave efter brugerens valg.
 * tasks[]: Input parameter. En opgave fra arrayet skal slettes.
 * number_of_tasks: Input parameter. Skal tælles ned, hvis en opgave slettes.
 * Returnerer ikke noget.
 */
void delete_task(task tasks[], int *number_of_tasks);

/* Funktion, som sletter en kategori og alle opgaver (tasks) med denne kategori.
 * tasks[]: Input parameter. Opgaver med en bestemt kategori slettes.
 * number_of_tasks: Input parameter. Skal tælles ned, hvis en opgave slettes.
 * category[]: Input parameter. Kategorien der skal slettes.
 * Returnerer ikke noget.
 */
void delete_category(task tasks[], int *number_of_tasks, char category[]);

/* TEST */
CuSuite *delete_category_get_suite();
