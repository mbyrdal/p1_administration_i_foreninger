/* Prototypes */

/* Funktion til styring af programmet hovedmenu, hvor der kan vælges blandt 4 valgmuligheder */
task *main_menu(task tasks[], char categories[][], int *number_of_tasks, int *number_of_categories);

/* Funktion til at udføre brugerens handling
 * Tager valget som input samt med task-array og antal opgaver
 * intet output
 */
void execute_user_input(int option, task tasks[], char categories[][], int *number_of_tasks, int *number_of_categories);
