#include <time.h>

struct task{
    char category[100],
         admins[250],
         title[100],
         description[1000],
         volunteers[250],
         status_str[1000];
    int priority,
        number;
    struct tm deadline;
};
typedef struct task task;
