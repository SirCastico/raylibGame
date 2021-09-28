game : src/main.c src/physics.c src/ecs.c src/draw.c src/sMath.c src/physics.h src/ecs.h src/draw.h src/sMath.h
#	windows
	gcc src/main.c src/sMath.c src/physics.c src/draw.c src/ecs.c -o game -O1 -Wall -L libWindows/ -lraylib -lgdi32 -lwinmm -lm
#	linux
#	gcc src/main.c src/sMath.c src/physics.c src/draw.c src/ecs.c -o game -O1 -Wall -L libLinux/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11