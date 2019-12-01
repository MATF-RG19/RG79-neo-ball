PROGRAM = neo-ball
CC 		= gcc
CFLAGS  = -g -std=c99 -Wall
LDFLAGS	= -lm -lGL -lGLU -lglut
PROG    = src/main.c src/display.c src/lighting.c src/floor.c src/keyboard.c src/timer.c
HEADER  = include/init.h include/display.h include/lighting.h include/floor.h include/keyboard.h include/timer.h

$(PROGRAM): $(PROG) $(HEADER)
	$(CC) -o $(PROGRAM) $(PROG) $(LDFLAGS) 

run: 
	./$(PROGRAM)