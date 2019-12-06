/* Prototypes */

/* Indtager int variabel option, som fortæller den hvilken slags sortering den skal printe
 * Printer herefter den relevante sortering
 */
void sort_tasks(task tasks[], int option, int number_of_tasks);

/* Indtager en int variabel og udfører den valgte sortering i form af en qsort funktion
 * Og rykker rundt i arrayet så den valgte sortering ligger ordentligt
 */
void print_sort(task tasks[], int option, int number_of_tasks);
