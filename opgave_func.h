#define MAX_NUMBER_OF_CATEGORIES 50
#define MAX_LENGTH_OF_CATEGORY 100
/* Prototypes */

/* En funktion til at oprette en opgave i programmet
 * Funktion tager tasks-arrayet til at oprette den nye opgave i
 * Funktion tager number_of_tasks til at tælle antallet af opgaver op
 */
void create_task(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_tasks, int *number_of_categories);


/* Funktion til at ændre en valgt opgave
 * Funktionen tager adressen til en opgave for at ændre værdierne
 */
/* void change_task(task *task1); */
void change_task(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int number_of_tasks, int number_of_categories, int index);


void prompt_for_category(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int number_of_tasks, int *number_of_categories, int index);
void add_category(char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int *number_of_categories);
void edit_category(task tasks[], char categories[MAX_NUMBER_OF_CATEGORIES][MAX_LENGTH_OF_CATEGORY], int index, int number_of_tasks);
