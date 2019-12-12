/* Prototypes */

/* En funktion til at oprette en opgave i programmet.
 * tasks[]: Input parameter. Arrayet får tilføjet et element.
 * categories[][]: Input parameter. Arrayet sendes videre til funktionen prompt_for_category().
 * number_of_tasks: Input parameter. Tælles én op, da der tilføjes en opgave.
 * number_of_categories: Input parameter. Parameteren sendes videre til funktionen prompt_for_category().
 * Returnerer ikke noget.
 */
void create_task(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories);


/* Funktion til at ændre en valgt opgave.
 * tasks[]: Input parameter. Et element i dette array skal ændres.
 * categories[][]: Input parameter. Arrayet sendes videre til funktionen prompt_for_category().
 * number_of_tasks: Input parameter. Parameteren sendes videre til til funktionen prompt_for_category().
 * number_of_categories: Input parameter. Parameteren sendes videre til til funktionen prompt_for_category().
 * index: Input parameter. Index til opgaven, der skal ændres i tasks[].
 * Returnerer ikke noget.
 */
void change_task(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int number_of_tasks, int *number_of_categories, int index);

/* Funktion til at spørge om en kategori, som eksisterer i categories-arrayet.
 * tasks[]: Input parameter. Et element i dette array får sin kategori ændret.
 * categories[][]: Input parameter. Alle kategorier printes. Arrayet sendes vider til funktionerne add_category() og edit_category().
 * number_of_tasks: Input parameter. Parameteren sendes videre til funktionen edit_category().
 * number_of_categories: Input parameter. Brugestil at printe alle kategorier. Parameteren sendes videre til funktionen add_category().
 * index: Input parameter. Index til opgaven, der skal ændres i tasks[].
 * Returnerer ikke noget.
 */
void prompt_for_category(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int number_of_tasks, int *number_of_categories, int index);

/* Funktion til at tilføje en kategori.
 * categories[][]: Input parameter. Der tilføjes et element til dette array.
 * number_of_categories: Input parameter. Parameteren tælles én op, da der tilføjes et element i categories[][].
 * Returnerer ikke noget.
 */
void add_category(char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_categories);

/* Funktion til at ændre en kategori.
 * tasks[]: Input parameter. Alle elementer i tasks[] men en bestemt kategori, skal have ændret denne kategori til den nye kategori.
 * categories[][]: Input parameter. En eksisterende kategori i dette array ændres.
 * index: Input parameter. Index til kategorien i categories[][], der skal ændres.
 * number_of_tasks: Input parameter. Alle opgaver skal tjekkes igennem for at se, om kategorien skal opdateres.
 * Returnerer ikke noget.
 */
void edit_category(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int index, int number_of_tasks);
