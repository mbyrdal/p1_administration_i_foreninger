/* Compare function */

/* qsort sammenligning for deadlines. 
 * Tager 2 pointer til 2 elementer, som kan sammenlignes fra et array.
 * Returner en int, som siger om to opgaver skal byttes.
 */
int compare_deadline(const void *ip1, const void *ip2);

/* qsort sammenligning for priority.
 * Tager 2 pointer til 2 elementer, som kan sammenlignes fra et array.
 * Returner en int, som siger om to opgaver skal byttes.
 */
int compare_priority(const void *ip1, const void *ip2);

/* qsort sammenligning for admins.
 * Tager 2 pointer til 2 elementer, som kan sammenlignes fra et array.
 * Returner en int, som siger om to opgaver skal byttes.
 */
int compare_admins(const void *ip1, const void *ip2);

/* qsort sammenligning for title.
 * Tager 2 pointer til 2 elementer, som kan sammenlignes fra et array.
 * Returner en int, som siger om to opgaver skal byttes.
 */
int compare_title(const void *ip1, const void *ip2);

/* qsort sammenligning for category.
 * Tager 2 pointer til 2 elementer, som kan sammenlignes fra et array.
 * Returner en int, som siger om to opgaver skal byttes.
 */
int compare_category(const void *ip1, const void *ip2);
