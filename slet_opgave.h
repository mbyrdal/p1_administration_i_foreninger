/* Prototyper */

/* Funktionen printer alle opgaver og sletter derefter en opgave efter brugerens valg.
 * tasks[]: Input/output parameter. En opgave fra arrayet skal slettes.
 * number_of_tasks: Input/output parameter. Skal tælles ned, hvis en opgave slettes.
 * Returnerer ikke noget.
 */
void delete_task(task tasks[], int *number_of_tasks);

/* Funktion, som sletter en kategori og alle opgaver (tasks) i denne kategori.
 * tasks[]: Input/output parameter. Opgaver i en bestemt kategori slettes.
 * categories[][]: Input/output parameter. Kategori skal slettes.
 * number_of_tasks: Input/output parameter. Skal tælles ned, for hver opgave, der slettes.
 * number_of_categories: Input/output parameter. Skal tælles ned, når kategori slettes.
 * category_delete_index: Input parameter. Index til kategorien, der skal slettes.
 * Returnerer ikke noget.
 */
void delete_category(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories, int category_delete_index);

/* TEST */
CuSuite *delete_category_get_suite();
