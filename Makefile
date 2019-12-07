
CFLAGS = -Wall -ansi -pedantic
NAME = -o task.out
ORI = main.c
FILES = cmp_func.c help_functions.c main_menu.c opgave_func.c
FILES1 = print_sort.c start_prompt.c
task: main.c
	gcc $(CFLAGS) $(ORI) $(NAME) $(FILES) $(FILES1)
