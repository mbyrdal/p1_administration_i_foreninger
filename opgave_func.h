/* Prototypes */

/* En funktion til at oprette en opgave i programmet
 * Funktion tager tasks-arrayet til at oprette den nye opgave i
 * Funktion tager number_of_tasks til at tælle antallet af opgaver op
 */
void create_task(task tasks[], char* categories, int *number_of_tasks, int *number_of_categories){


/* Funktion til at ændre en valgt opgave
 * Funktionen tager adressen til en opgave for at ændre værdierne
 */
void change_task(task *task1);

int prompt_for_category(char **categories, int *number_of_categories);
void add_category(char **categories, int *number_of_categories);
void edit_category(char **categories, int index);
