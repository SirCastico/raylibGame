game : src/main.c src/physics.c src/struct.c src/draw.c src/sMath.c
#	windows
#	gcc src/main.c src/sMath.c src/physics.c src/struct.c src/draw.c -o game -O1 -Wall -I include/ -L libWindows/ -lraylib -lgdi32 -lwinmm -lm
#	linux
	gcc src/main.c src/sMath.c src/physics.c src/struct.c src/draw.c -o game -O1 -Wall -I include/ -L libLinux/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11