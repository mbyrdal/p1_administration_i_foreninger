/* Sammenligningsfunktioner */

/* Funktionen benyttet af qsort til sammenligning af deadlines. 
 * ip1: Input parameter. Pointer til element i et array. I dette tilfælde tasks-arrayet.
 * ip2: Input parameter. Pointer til element i et array. I dette tilfælde tasks-arrayet.
 * Returnerer en int, som siger om to opgaver skal byttes.
 */
int compare_deadline(const void *ip1, const void *ip2);

/* Funktionen benyttet af qsort til sammenligning af prioritet.
 * ip1: Input parameter. Pointer til element i et array. I dette tilfælde tasks-arrayet.
 * ip2: Input parameter. Pointer til element i et array. I dette tilfælde tasks-arrayet.
 * Returnerer en int, som siger om to opgaver skal byttes.
 */
int compare_priority(const void *ip1, const void *ip2);

/* Funktionen benyttet af qsort til sammenligning af admins.
 * ip1: Input parameter. Pointer til element i et array. I dette tilfælde tasks-arrayet.
 * ip2: Input parameter. Pointer til element i et array. I dette tilfælde tasks-arrayet.
 * Returnerer en int, som siger om to opgaver skal byttes.
 */
int compare_admins(const void *ip1, const void *ip2);

/* Funktionen benyttet af qsort til sammenligning af titel.
 * ip1: Input parameter. Pointer til element i et array. I dette tilfælde tasks-arrayet.
 * ip2: Input parameter. Pointer til element i et array. I dette tilfælde tasks-arrayet.
 * Returnerer en int, som siger om to opgaver skal byttes.
 */
int compare_title(const void *ip1, const void *ip2);

/* Funktionen benyttet af qsort til sammenligning af kategori.
 * ip1: Input parameter. Pointer til element i et array. I dette tilfælde tasks-arrayet.
 * ip2: Input parameter. Pointer til element i et array. I dette tilfælde tasks-arrayet.
 * Returnerer en int, som siger om to opgaver skal byttes.
 */
int compare_category(const void *ip1, const void *ip2);
