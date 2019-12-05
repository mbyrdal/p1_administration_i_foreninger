
CFLAGS = -Wall -ansi -pedantic
NAME = -o task
FILES = opret_opgave.c main_menu.c Start_Prompt.c 

task:
	gcc $(CFLAGS) $(NAME) $(FILES)
