/* Prototyper */

/* Funktion til styring af programmets hovedmenu, hvor der kan vælges blandt flere muligheder.
 * tasks[]: Input/output parameter. Arrayet sendes videre til funktionen execute_user_input().
 * categories[][]: Input/output parameter. Arrayet sendes videre til funktionen execute_user_input().
 * number_of_tasks: Input/output parameter. Parameteren sendes videre til funktionen execute_user_input().
 * number_of_categories: Input/output parameter. Parameteren sendes videre til funktionen execute_user_input().
 * Returnerer ikke noget.
 */
void main_menu(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories);

/* Funktion til at udføre brugerens handling.
 * tasks[]: Input/output parameter. Arrayet sendes videre til andre funktioner og bruges ikke direkte af funktionen selv.
 * categories[][]: Input/output parameter. Arrayet sendes videre til andre funktioner og bruges ikke direkte af funktionen selv.
 * number_of_tasks: Input/output parameter. Parameteren sendes videre til andre funktioner og bruges ikke direkte af funktionen selv.
 * number_of_categories: Input/output parameter. Parameteren sendes videre til andre funktioner og bruges ikke direkte af funktionen selv.
 * option: Input/output parameter. Funktionen udfører valget associeret med denne parameters værdi.
 * Returnerer ikke noget.
 */
void execute_user_input(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories, int option);
