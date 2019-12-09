/* Prototypes */

/* Sorterer og printer opgaverne efter den valgte sortering
 * Tager task-arrayet, så den kan sorteres, som input
 * Tager number_of_tasks som input, så den kun printer oprettede opgaver
 */
void change_sorting(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int number_of_tasks, int number_of_categories);


/* Tager sorteringsvalget som input
 * Printer herefter den valgte sortering
 */
void sort_tasks(task tasks[], int option, int number_of_tasks);

/* Tager sorteringsvalget som input
 * Sorterer herefter efter valgte sortering
 */
void print_sort(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int option, int number_of_tasks, int number_of_categories);
