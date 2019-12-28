PROGRAM = neo-ball
CC 		= gcc
CFLAGS  = -g -std=c99 -Wall
LDFLAGS	= -lm -lGL -lGLU -lglut
PROG    = src/main.c src/display.c src/lighting.c src/floor.c src/keyboard.c src/timer.c src/move.c src/image.c
HEADER  = include/init.h include/display.h include/lighting.h include/floor.h include/keyboard.h include/timer.h include/move.h include/image.h

$(PROGRAM): $(PROG) $(HEADER)
	$(CC) -o $(PROGRAM) $(PROG) $(LDFLAGS) 

.PHONY: run makerun clean

run:
	./$(PROGRAM)

makerun:
	make
	make run

clean:
	rm -f $(PROGRAM) ./src/*.o