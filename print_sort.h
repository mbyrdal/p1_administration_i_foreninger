/* Prototypes */

/* Funktionerne kaldes på funktiorne sort_tasks() og print_sort() efter brugeren har valgt sortering.
 * tasks[]: Input parameter. Arrayet sendes videre til funktionerne sort_tasks() og print_sort().
 * number_of_tasks: Input parameter. Parameteren sendes videre til funktionerne sort_tasks() og print_sort().
 * Returnerer ikke noget.
 */
void change_sorting(task tasks[], int number_of_tasks);


/* Funktion til at sortere tasks-arrayet efter valgt sortering.
 * tasks[]: Input parameter. Arrayet sorteres efter den valgte sortering.
 * number_of_tasks: Input parameter. qsort() skal kende antallet af elementer i arrayet.
 * option: Input parameter. Brugerens valg af sortering.
 * Returnerer ikke noget.
 */
void sort_tasks(task tasks[], int number_of_tasks, int option);

/* Funktion til at printe alle opgaver efter en valgt sortering.
 * tasks[]: Input parameter. Informationer fra hver opgave printes.
 * number_of_task: Input parameter. Information til hvor mange opgaver der skal printes.
 * option: Input parameter. Den valgte sortering afgør, hvordan tasks[] blvier printet.
 * Returnerer ikke noget.
 */
void print_sort(task tasks[], int number_of_tasks, int option);
