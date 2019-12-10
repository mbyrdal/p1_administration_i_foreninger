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
    int i, task_index;
    char answer_delete_keep[10];

    for (i = 0; i < *number_of_tasks; i++){ /* Loop igennem array af tasks fra 0->number_of_tasks */
        printf("%-10d %-s\n", i+1, tasks[i].title);
    }

    task_index = prompt_user_options("Hvilken opgave vil du gerne slette? (Indtast opgavens nummer)\n>", *number_of_tasks) - 1;
    printf("Er du sikker paa, at du vil slette opgaven: %s? (Ja/Nej)\n> ", tasks[task_index].title);

    while (is_yes_or_no(answer_delete_keep)){ /* Hvis brugeren ikke har skrevet ja eller nej */
        scanf(" %s", answer_delete_keep);
    }

    if (!user_wrote_no(answer_delete_keep)){ /* Hvis brugeren enten skriver ja */
        if (task_index != (*number_of_tasks - 1)){
            tasks[task_index] = tasks[*number_of_tasks - 1];
        }
        *number_of_tasks -= 1;
    } else{ /* Hvis nej ... */
        printf("Vil du stadig slette en opgave? (Ja/Nej)\n> ");

        strcpy(answer_delete_keep, "");
        while (is_yes_or_no(answer_delete_keep)){
            scanf(" %s", answer_delete_keep);
        }

        if(!user_wrote_no(answer_delete_keep)){
            delete_task(tasks, number_of_tasks);
        }
    }
}

/* Funktion, som sletter en kategori og alle opgaver (tasks) med denne kategori
 * det sidste argument (char category[]) beskrive hvilken kategori der skal slettes
 * MANGLER Når en kategori er slettet SKAL number_of_categories TÆLLES NED
 * Herefter promptes brugeren for, om de er sikre på,*/
void delete_category(task tasks[], int *number_of_tasks, char category[]){
    int i;
    for (i = 0; i < *number_of_tasks; i++){
        if (strcmp(category, tasks[i].category) == 0 && i < *number_of_tasks - 1){
            tasks[i] = tasks[*number_of_tasks - 1];
            *number_of_tasks -= 1;
            i--;
        }
        else if (strcmp(category, tasks[i].category) == 0){
            *number_of_tasks -= 1;
        }
    }
}
