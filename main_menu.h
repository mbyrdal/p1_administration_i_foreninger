/* Prototypes */

/* Funktion til styring af programmet hovedmenu, hvor der kan vælges blandt 4 valgmuligheder */
void main_menu(task tasks[], int *number_of_tasks);

/* Funktion til at udføre brugerens handling
 * Tager valget som input samt med task-array og antal opgaver
 * intet output
 */
void execute_user_input(int option, task tasks[], int *number_of_tasks);
