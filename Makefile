game : src/main.c src/physics.c src/struct.c
#	windows
#	gcc src/main.c -o game -O1 -Wall -I include/ -L libWindows/ -lraylib -lgdi32 -lwinmm
#	linux
	gcc src/main.c src/physics.c src/struct.c -o game -O1 -Wall -I include/ -L libLinux/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11