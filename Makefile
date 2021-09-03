game : src/main.c src/physics.c src/struct.c src/draw.c
#	windows
#	gcc src/main.c src/physics.c src/struct.c src/draw.c -o game -O1 -Wall -I include/ -L libWindows/ -lraylib -lgdi32 -lwinmm -lm
#	linux
	gcc src/main.c src/physics.c src/struct.c src/draw.c -o game -O1 -Wall -I include/ -L libLinux/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11