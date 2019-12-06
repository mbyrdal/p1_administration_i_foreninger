
CFLAGS = -Wall -ansi -pedantic
NAME = -o task
ORI = main.c
FILES = opret_opgave.c main_menu.c start_prompt.c print_sort.c
FILES1 = help_function.c cmp_func.c
task: main.c
	gcc $(CFLAGS) $(ORI) $(NAME) $(FILES) $(FILES1)
