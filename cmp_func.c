#include "include.h"

int compare_deadline(const void *ip1, const void *ip2){
    task *tm1= (task *)ip1,
         *tm2= (task *)ip2;

    if (tm1->deadline.tm_year < tm2->deadline.tm_year){
        return -1;
    } else if (tm1->deadline.tm_year > tm2->deadline.tm_year){
        return 1;
    } else if (tm1->deadline.tm_mon < tm2->deadline.tm_mon){
        return -1;
    } else if (tm1->deadline.tm_mon > tm2->deadline.tm_mon){
        return 1;
    } else if (tm1->deadline.tm_mday < tm2->deadline.tm_mday){
        return -1;
    } else if (tm1->deadline.tm_mday > tm2->deadline.tm_mday){
        return 1;
    } else if (tm1->deadline.tm_hour < tm2->deadline.tm_hour){
        return -1;
    } else if (tm1->deadline.tm_hour > tm2->deadline.tm_hour){
        return 1;
    } else if (tm1->deadline.tm_min < tm2->deadline.tm_min){
        return -1;
    } else if (tm1->deadline.tm_min > tm2->deadline.tm_min){
        return 1;
    } else{
        return 0;
    }
}

int compare_priority(const void *ip1, const void *ip2){
    task *prio1= (task*)ip1,
         *prio2= (task*)ip2;

    if (prio1->priority < prio2->priority){
        return 1;
    } else if (prio1->priority > prio2->priority){
        return -1;
    } else{
        return 0;
    }
}

int compare_admins(const void *ip1, const void *ip2){
    task *name1 = (task *)ip1,
         *name2 = (task *)ip2;
    return strcmp(name1->admins, name2->admins);
}

int compare_title(const void *ip1, const void *ip2){
    task *name1 = (task *)ip1,
         *name2 = (task *)ip2;
    return strcmp(name1->title, name2->title);
}

int compare_category(const void *ip1, const void *ip2){
    task *name1 = (task *)ip1,
         *name2 = (task *)ip2;

    if(strcmp(name1->category, name2->category) == 0) {
        return strcmp(name1->title, name2->title);
    }

    return strcmp(name1->category, name2->category);
}
