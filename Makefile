CC = gcc
OPTION1 = -Wall
OPTION2 = -o
OPTION3 = -c
OPTION4 = -lglut -lGLU -lGL -lm

all: main

main.o:
	$(CC) $(OPTION1) $(OPTION2) main.o $(OPTION3) main.c main.h
main: main.o
	$(CC) $(OPTION2) main main.o $(OPTION4)

clean:
	rm -rf *.o main
