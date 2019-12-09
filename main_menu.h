/* Prototypes */

/* Funktion til styring af programmet hovedmenu, hvor der kan vælges blandt flere muligheder.
 * Funktionen tager tasks-arrayet og categories-arrayet for at sende det videre til andre funktioner som vælges gennem brugerens input.
 * Funktionen tager number_of_tasks og number_of_categories for at sende videre til andre funktioner, som vælges gennem brugerens input.
 * Intet output.
 */
void main_menu(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories);

/* Funktion til at udføre brugerens handling.
 * Funktionen tager tasks-arrayet og categories-arrayet for at sende det videre til andre funktioner som vælges gennem brugerens input.
 * Funktionen tager number_of_tasks og number_of_categories for at sende videre til andre funktioner, som vælges gennem brugerens input.
 * Funktionen bruger option til at vælge den rigtige funktion ud fra brugerens input.
 * Intet output.
 */
void execute_user_input(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories, int option);
