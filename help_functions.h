/* Prototypes */

/* Funktion til at skippe input i inputbufferen, hvis der er input, der ikke blev læst.
 * Funktionen har ikke nogen input parametre.
 * Returner ikke noget.
 */
void clear_input(void);

/* Funktion til at printe én enkelt opgave.
 * task1: Input parameter af typen task. Denne opgave printes.
 * Returner ikke noget.
 */
void print_task(task task1);

/* Funktion, som prompter muligheder for derefter at returnere svaret.
 * print: Input parameter. String som printes af funktionen.
 * amount_of_options: Input parameter. Antallet af muligheder bruger kan vælge i mellem.
 * Funktionen returnerer et tal mellem 1 og amount_of_options - begge inklusive.
 */
int prompt_user_options(char *print, int amount_of_options);

/* Funktion, som tjekker om brugeren indtastede "j" eller "n".
 * answer: Input parameter. Parameteren er brugerens input.
 * Returnerer -1 hvis answer er "j", "1" hvis anser er "n", eller 0, hvis answer hverken er "j" eller "n".
 */
int check_answer(char answer);

/* TEST */

CuSuite *check_answer_get_suite();
