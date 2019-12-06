#include "include.h"

/* qsort sammenligning for deadlines. 
 * Tager 2 pointer til 2 elementer, som kan sammenlignes fra et array
 * Returner en int, som siger om to opgaver skal byttes
 */
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

/* qsort sammenligning for priority
 * Tager 2 pointer til 2 elementer, som kan sammenlignes fra et array
 * Returner en int, som siger om to opgaver skal byttes
 */
int compare_priority(const void *ip1, const void *ip2){
    task *prio1= (task*)ip1,
         *prio2= (task*)ip2;

    if (prio1->priority < prio2->priority){ 
        return -1;
    } else if (prio1->priority > prio2->priority){
        return 1;
    } else{
        return 0;
    }
}

/* qsort sammenligning for admins
 * Tager 2 pointer til 2 elementer, som kan sammenlignes fra et array
 * Returner en int, som siger om to opgaver skal byttes
 */
int compare_admins(const void *ip1, const void *ip2){
    int i;
    task *name1 = (task *)ip1,
         *name2 = (task *)ip2;
    
    for (i = 0; (name1->admins[i] =! '\n'); i++){
        name1->admins[i] = tolower(name1->admins[i]);
    }
    for (i = 0; (name2->admins[i] =! '\n'); i++){
        name2->admins[i] = tolower(name2->admins[i]);
    }

    if (strcmp(name1->admins, name2->admins) < 0){
        return -1;
    } else if (strcmp(name1->admins, name2->admins) > 0){
        return 1;
    } else{
        return 0;
    } 
}

/* qsort sammenligning for title
 * Tager 2 pointer til 2 elementer, som kan sammenlignes fra et array
 * Returner en int, som siger om to opgaver skal byttes
 */
int compare_title(const void *ip1, const void *ip2){
    int i;
    task *name1 = (task *)ip1,
         *name2 = (task *)ip2;
    
    for (i = 0; (name1->title[i] =! '\n'); i++){
        name1->title[i] = tolower(name1->title[i]);
    }
    for (i = 0; (name2->title[i] =! '\n'); i++){
        name2->title[i] = tolower(name2->title[i]);
    }

    if (strcmp(name1->title, name2->title) < 0){
        return -1;
    } else if (strcmp(name1->title, name2->title) > 0){
        return 1;
    } else{
        return 0;
    } 
}

/* qsort sammenligning for category
 * Tager 2 pointer til 2 elementer, som kan sammenlignes fra et array
 * Returner en int, som siger om to opgaver skal byttes
 */
int compare_category(const void *ip1, const void *ip2){
    int i;
    task *name1 = (task *)ip1,
         *name2 = (task *)ip2;
    
    for (i = 0; (name1->category[i] =! '\n'); i++){
        name1->category[i] = tolower(name1->category[i]);
    }
    for (i = 0; (name2->category[i] =! '\n'); i++){
        name2->category[i] = tolower(name2->category[i]);
    }

    if (strcmp(name1->category, name2->category) < 0){
        return -1;
    } else if (strcmp(name1->category, name2->category) > 0){
        return 1;
    } else{
        return 0;
    } 
}
