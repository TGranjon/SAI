#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "arbre.h"
#include "modele.h"

#define NBOBJET 100 // Nombre d'objets générés aléatoirement //! Testé jusqu'à 500 -> peu d'espace où se déplacer
#define NBOBJECTIF 5 // Nombre d'objectifs générés aléatoirement //! Testé jusqu'à 10 -> crash arbre

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


typedef struct detailObjet // Structure DetailObjet(int, float, float, float, float)
{
	int typeObjet;
	float x;
	float y;
	float z;
	float r;
} DetailObjet;

typedef struct tableobjettotale // Structure TableObjetTotale(int, DetailObjet[])
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

int verification(float xP, float zP);

int pnpoly(int nvert, Point vert[], float testx, float testy);

int inclus(Point A[]);

int contenu(Point A[]);

Arbre Arbre4(Point A[]);

void objectifFin();

void vBitmapOutput(int x, int y, char *string, void *font);

void clavier(unsigned char touche, int x, int y);

void mouvement();

void Affichage();

void gameOver();

int main(int argc, char * argv[], char * envp[]);
