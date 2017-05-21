#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "arbre.h"
#include "modele.h"

#define NBOBJET 20 // Nombre d'objet généré aléatoirement
#define NBOBJECTIF 1 // Nombre d'objet généré aléatoirement
#define TRUE 1
#define FALSE 0

typedef struct point // Structure Point(x,z)
{
    float x;
    float z;
} Point;

typedef struct tableforme // Structure TableForme(minP,maxP)
{
    Point minP;
    Point maxP;
} TableForme;

typedef struct tabletotale // Structure TableTotale(taille, forme[])
{
    int taille;
    TableForme forme[NBOBJET];
} TableTotale;


typedef struct detailObjet
{
	int typeObjet;
	float x;
	float y;
	float z;
	float r;
} DetailObjet;

typedef struct tableobjettotale
{
    int taille;
    DetailObjet objet[NBOBJET];
} TableObjetTotale;

typedef struct tableobjectif // Structure TableObjectif(cache,coordonnees)
{
    int cache;
    Point coordonnees;
} TableObjectif;


int appartient(float xP, float zP);

int toucheObjectif(float xP, float zP);

int dansPlateau(float xp, float zp);

int pnpoly(int nvert, Point vert[], float testx, float testy);

int inclus(Point A[]);

int contenu(Point A[]);

arbre Arbre4(Point A[]);

void objectifFin();

void vBitmapOutput(int x, int y, char *string, void *font);

void clavier(unsigned char touche, int x, int y);

void mouvement();

void Affichage();

void gameOver();

int main(int argc, char * argv[], char * envp[]);
