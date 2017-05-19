#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct point
{
    float x;
    float z;
} Point;

typedef struct tableforme
{
    Point minP;
    Point maxP;
} TableForme;

typedef struct tabletotale
{
    int taille;
    TableForme forme[21]; // A determiner avec le 4-arbre
} TableTotale;

typedef struct tableobjectif
{
    int cache;
    Point coordonnees;
} TableObjectif;

int appartient(float xP, float zP);

int toucheObjectif(float xP, float zP);

int dansPlateau(float xp, float zp);

void clavier(unsigned char touche, int x, int y);

void mouvement();

void parallepipede(float x1, float y1, float z1, float x2, float y2, float z2);

void carre(float x,float y,float z, float l);

void plateau(float x,float y,float z, float lar, float lon);

void pyramide(float x, float y, float z);

void Decor(float x,float y,float z, float lar, float lon);

void Bonhomme(float x, float y, float z);

void Immeuble(float x, float y, float z);

void Arbre(float x, float y, float z, float r);

void Lampadaire(float x, float y, float z);

void Objectif(float x, float y, float z, int num);

void Affichage();

int main(int argc, char * argv[], char * envp[]);
