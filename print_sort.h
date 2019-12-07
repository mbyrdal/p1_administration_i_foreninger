/* Prototypes */

/* Sorterer og printer opgaverne efter den valgte sortering
 * Tager task-arrayet, så den kan sorteres, som input
 * Tager number_of_tasks som input, så den kun printer oprettede opgaver
 */
void change_sorting(task tasks[], int number_of_tasks);

/* Tager sorteringsvalget som input
 * Printer herefter den valgte sortering
 */
void sort_tasks(task tasks[], int option, int number_of_tasks);

/* Tager sorteringsvalget som input
 * Sorterer herefter efter valgte sortering
 */
void print_sort(task tasks[], int option, int number_of_tasks);

void print_sort(task tasks[], char **categories, int option, int number_of_tasks, int number_of_categories);
