#include "include.h"

int main(void){
    main_menu();
    return 0;
}

/*Funktion til styring af programmet hovedmenu, hvor der kan vælges bland 4 valgmuligheder*/
void main_menu(void){
    int selected_option = 0;
    do{
        printf("1.  Opret opgave\n"
               "2.  Ændre opgave\n"
               "3.  Ændre sortering\n"
               "4.  Afslut programmet.\n"
               "Vælg mellem en af ovenstående muligheder [indtast valgmulighedens nummer uden punktum \".\"]: ");
        selected_option = scan_user_input();

        /*Der tjekkes om input er en korrekt valgmulighed*/
        if (selected_option != MAIN_MENU && selected_option != 0){
            execute_user_input(selected_option);
        }
    } while(selected_option != MAIN_MENU);
}

/*Funktion brug af funktionen main_menu. Bruges til at verificere brugerens input, da bruger input skal være et heltal mellem 1 og 4, hvor begger er inklusiv*/
int scan_user_input(void){
    int user_input = 0, result_scanf = 0, selected_option = 0;
    result_scanf = scanf(" %d", &user_input);

    /*Hivs input er korrekt returneres den valgte mulighed*/
    if (result_scanf == 1 && user_input >= 1 && user_input <= MAIN_MENU){
        selected_option = user_input;
        clear_input();

    /*Hvis input er forkert printes følgende besked og 0 returneres af funktionen*/
    } else{
        printf("\n\nDet indtastede var ikke en mulighed. Prøv igen.\n");
        clear_input();
    }
    return selected_option;
}

void execute_user_input(int selected_option){
    switch (selected_option){
    
    /*Opret opgave*/
    case 1:
        
        break;

    /*Ændre opgave*/
    case 2:
        
        break;

    /*Ændre sortering*/
    case 3:

        break;
    
    /*Der er ikke andre muligheder end ovenstående. Fejl input er sorteret fra, så de kommer ikke i default case*/
    default:
        break;
    }
}

/*Funktion til at skippe input i inputbufferen, hvis der er input, der ikke blev læst*/
void clear_input(void){
    char skip_ch;
    do{
        scanf("%c", &skip_ch);
    } while(skip_ch != '\n');
}
