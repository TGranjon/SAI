CC = gcc
OPTION1 = -Wall
OPTION2 = -o
OPTION3 = -c
GL = -lglut -lGLU -lGL
MATH = -lm

main: main.o modele.o arbre.o
	$(CC) $(OPTION2) main main.o modele.o arbre.o $(MATH) $(GL)

arbre.o:
	$(CC) $(OPTION1) $(OPTION3) arbre.c arbre.h
	
modele.o:
	$(CC) $(OPTION1) $(OPTION3) modele.c modele.h

main.o:
	$(CC) $(OPTION1) $(OPTION3) main.c main.h

clean:
	rm -rf *.o main
