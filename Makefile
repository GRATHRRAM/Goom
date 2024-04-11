cc=clang
flags=-g -Wall -Wextra -fsanitize=address -fsanitize=undefined
goom.out: main.c 
	$(cc) $(flags) -I. -L/lib ./*.c -lm -lraylib -o goom.out
