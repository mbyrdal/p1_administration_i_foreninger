#include "include.h"

/* Funktion, som sletter en opgave (task) efter behov
 * Først printes alle opgaverne i en fil under kategori
 * Der promptes for et opgaveindex, som skal slettes
 * Herefter promptes brugeren for, om de er sikre på,
   at de vil slette opgaven på det bestemte index
 * Hvis brugeren svarer ja, så nulstilles en opgave
   og antallet af opgaver i filen tælles ned med 1 (number_of_tasks--)
 * Hvis brugeren derimod svarer nej, så promptes der for,
   om brugeren stadigvæk vil slette en opgave
 * Hvis brugeren svarer ja, så køres funktionen delete_task igen
 * Hvis brugeren svarer nej, så kommer brugeren ud af funktionen */
void delete_task(task tasks[], int *number_of_tasks){
    int i, task_index, scanres = 0, user_did_not_write_yes_or_no = 1, user_wrote_no = 0;
    char answer_delete_keep[10];
    user_did_not_write_yes_or_no = (strcmp(answer_delete_keep, "ja") && strcmp(answer_delete_keep, "Ja") && strcmp(answer_delete_keep, "JA") &&
                                    strcmp(answer_delete_keep, "nej") && strcmp(answer_delete_keep, "Nej") && strcmp(answer_delete_keep, "NEJ"));
    user_wrote_no = (strcmp(answer_delete_keep, "ja") && strcmp(answer_delete_keep, "Ja") && strcmp(answer_delete_keep, "JA"));

    for (i = 0; i < number_of_tasks; i++){ /* Loop igennem array af tasks fra 0->number_of_tasks */
        printf("%-10d %-s\n", i+1, tasks[i].title);
    }

    while(scanres == 0){ /* Så længe, at scanres ikke læser et input */
        printf("Hvilken opgave vil du gerne slette? (Indtast opgavens nummer)\n\n");
        scanres = scanf(" %d", &task_index);
        clear_input();
    }

    task_index--; /* Der tælles ned med en, eftersom brugeren indtaster en task i+1 */
    printf("Er du sikker på, at du vil slette opgaven: %s? (Ja/Nej)\n\n", tasks[task_index]->title);

    while(user_did_not_write_yes_or_no){ /* Hvis brugeren ikke har skrevet ja eller nej */
        scanf(" %s", answer_delete_keep);
    }

    if (!user_wrote_no){ /* Hvis brugeren enten skriver ja */
        tasks[task_index]->title = "";
        tasks[task_index]->admins = "";
        tasks[task_index]->volunteers = "";
        tasks[task_index]->description = "";
        tasks[task_index]->status_str = "";
        tasks[task_index]->priority = 0;
        tasks[task_index]->deadline.tm_min = 0;
        tasks[task_index]->deadline.tm_hour = 0;
        tasks[task_index]->deadline.tm_mday = 0;
        tasks[task_index]->deadline.tm_mon = 0;
        tasks[task_index]->deadline.tm_year = 0;
        qsort(tasks, number_of_tasks, sizeof(task), compare_priority);
        *number_of_tasks--;
    } else{ /* Hvis nej ... */
        printf("Vil du stadig slette en opgave? (Ja/Nej)\n\n");

        while(user_did_not_write_yes_or_no){
            scanf(" %s", answer_delete_keep);
        }

        if(!user_wrote_no){

            delete_task(tasks[], *number_of_tasks);
        }
    }
}
