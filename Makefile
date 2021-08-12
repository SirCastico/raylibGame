game : src/main.c	
	gcc src/main.c -o game -O1 -Wall -I include/ -L lib/ -lraylib -lgdi32 -lwinmm