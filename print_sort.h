/* Prototypes */

/* Funktion til sortering og printning opgaverne efter den valgte sortering.
 * Funktionen tager tasks-arrayet som input, så det kan sorteres.
 * Tager number_of_tasks som input, så den kun printer oprettede opgaver.
 */
void change_sorting(task tasks[], int number_of_tasks);


/* Funktion til at sortere tasks-arrayet efter valgt sortering.
 * Funktionen tager tasks-arrayet som input, da det skal sorteres.
 * Funktionen tager number_of_tasks som input, da qsort() skal kende antallet af elementer i arrayet.
 * Funktionen tager option som input, da dette skal benyttes til at bestemme sorteringen.
 */
void sort_tasks(task tasks[], int number_of_tasks, int option);

/* Funktion til at printe alle opgaver efter en valgt sortering.
 * Funktionen tager tasks-arrayet som input, da den skal alle opgaver.
 * Funktionen tager number_of_tasks som input, da den kun skal printe det antal gange.
 * Funktione tager option som input, da den valgte sortering påvirker, hvordan opgaverne vises.
 */
void print_sort(task tasks[], int number_of_tasks, int option);
