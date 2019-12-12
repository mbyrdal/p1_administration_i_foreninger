/* Prototypes */

/* Funktion til styring af programmet hovedmenu, hvor der kan vælges blandt flere muligheder.
 * tasks[]: Input parameter. Arrayet sendes videre til funktionen execute_user_input().
 * categories[][]: Input parameter. Arrayet sendes videre til funktionen execute_user_input().
 * number_of_tasks: Input parameter. Parameteren sendes videre til funktionen execute_user_input().
 * number_of_categories: Input parameter. Parameteren sendes videre til funktionen execute_user_input().
 * Returner ikke noget.
 */
void main_menu(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories);

/* Funktion til at udføre brugerens handling.
 * tasks[]: Input parameter. Arrayet sendes videre til andre funktioner og bruges ikke direkte af funktionen selv.
 * categories[][]: Input parameter. Arrayet sendes videre til andre funktioner og bruges ikke direkte af funktionen selv.
 * number_of_tasks: Input parameter. Parameteren sendes videre til andre funktioner og bruges ikke direkte af funktionen selv.
 * number_of_categories: Input parameter. Parameteren sendes videre til andre funktioner og bruges ikke direkte af funktionen selv.
 * option: Input parameter. Funktionen udfører valget associeret med denne parameters værdi.
 * Returner ikke noget.
 */
void execute_user_input(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories, int option);
