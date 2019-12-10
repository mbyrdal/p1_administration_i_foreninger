/* Prototypes */

/* Funktion til at skippe input i inputbufferen,
 * hvis der er input, der ikke blev læst.
 * Funktionen har hverken input eller output.
 */
void clear_input(void);

/* Funktion til at printe én enkelt opgave.
 * Funktionen tager én enkelt opgave som argument.
 */
void print_task(task task1);

/* Funktion, som prompter brugeren for svar til muligheder,
 * der efterfølgende returneres (som heltal).
 * Funktionen tager højde for ugyldigt input.
 */
int prompt_user_options(char *print, int amount_of_options);

/* TEST */

CuSuite *strcmp_lower_get_suite();
