cc=cc
flags=-g -Wall -Wextra -Wint-conversion
goom.out: main.c 
	$(cc) $(flags) -I. -L/lib ./*.c -lm -lraylib -o goom.out
