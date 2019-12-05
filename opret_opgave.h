#include <time.h>
#define MAX_TASKS 100

struct task{
    char admins[250],
         title[100],
         description[1000],
         volunteers[250],
         status_str[1000];
    int priority,
        status_int,
        number;
    struct tm deadline;
};
typedef struct task task;

task create_task(task tasks[], int *new_task);
