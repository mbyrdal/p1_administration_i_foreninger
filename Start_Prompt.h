void bruger_input(char *print, char *input);
void create_dir(char *dir_name);
void file_managing(task *tasks, int amount_of_tasks, char *dir_name);
int dir_exists(char *dir_name);
int prompt_bruger_for_muligheder(char *print);
void file_write_task(FILE *fil, task task1);
void file_read_task(FILE *fil, task task);
