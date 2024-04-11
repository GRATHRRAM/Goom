cc=cc
flags=-g -Wall -Wextra -fsanitize=address
goom.out: main.c 
	$(cc) $(flags) -I. -L/lib ./*.c -lm -lraylib -o goom.out
