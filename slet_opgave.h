void delete_task(task tasks[], int *number_of_tasks);
int user_wrote_no(char *string);
int is_yes_or_no(char *string);
void delete_category(task tasks[], int *number_of_tasks, char category[]);

/* TESTS */

CuSuite *user_wrote_no_get_suite();
CuSuite *is_yes_or_no_get_suite();
