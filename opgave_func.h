/* Prototypes */

/* En funktion til at oprette en opgave i programmet.
 * Funktionen tager tasks-arrayet som input, da det får tilføjet et element.
 * Funktionen tager categories-arrayet som input, da brugeren skal vælge mellem forskellige funktionaliter tilhørende kategorierne.
 * Funktionen tager number_of_tasks som input, da den bliver talt én op, da der er kommet en ny opgave.
 * Funktionen tager number_of_categories som input, da den skal tælles én op alt efter om der oprettes en ny kategori.
 */
void create_task(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories);


/* Funktion til at ændre en valgt opgave.
 * Funktionen tager tasks-arrayet som input, da det bliver ændret et element i arrayet.
 * Funktionen tager categories-arrayet som input, da brugeren skal vælge mellem forskellige funktionaliter tilhørende kategorierne.
 * Funktionen tager number_of_tasks som input, da det skal benyttes af funktionen prompt_for_category().
 * Funktionen tager number_of_categories som input, da det skal benyttes af funktionen prompt_for_category().
 * Funktionen tager index som input, da det er den task i tasks-arrayet, der skal ændres.
 */
void change_task(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int number_of_tasks, int *number_of_categories, int index);

/* Funktion til at spørge om en kategori, som eksisterer i categories-arrayet.
 * Funktionen tager tasks-arrayet som input, da et elements kategori bliver ændret.
 * Funktionen tager categories-arrayet som input, da brugeren skal vælge mellem forskellige funktionaliter tilhørende kategorierne.
 * Funktionen tager number_of_tasks som input, da det skal benyttes af funktionen edit_category().
 * Funktionen tager number_of_categories som input, da det skal benyttes af funktionen add_categoryy().
 * Funktionen tager index som input, da det er den task i tasks-arrayet, der skal ændres.
 */
void prompt_for_category(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int number_of_tasks, int *number_of_categories, int index);

/* Funktion til at tilføje en kategori.
 * Funktionen tager categories-arrayet som input, da der skal tilføjes et element til dette array.
 * Funktionen tager number_of_categories som input, da den skal tælles op med én.
 */
void add_category(char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_categories);

/* Funktion til at tilføje en kategori.
 * Funktionen tager tasks-arrayet som input, da alle tasks med en bestemt kategori skal have ændret deres kategori til den nye kategori.
 * Funktionen tager catagories-arrayet som input, da en eksisterende kategori skal ændres.
 * Funktionen tager index som input, da det er den kategori, der skal have ændret navn.
 * Funktionen tager number_of_tasks som input, da den skal iterere gennem alle tasks.
 */
void edit_category(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int index, int number_of_tasks);
