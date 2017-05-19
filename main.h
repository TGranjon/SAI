#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

#define NBOBJET 20 //Nombre d'objet généré aléatoirement
#define NBOBJECTIF 1 //Nombre d'objet généré aléatoirement
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
    TableForme forme[NBOBJET]; // A determiner avec le 4-arbre
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
    DetailObjet objet[NBOBJET]; // A determiner avec le 4-arbre
} TableObjetTotale;

typedef struct tableobjectif // Structure TableObjectif(cache,coordonnees)
{
    int cache;
    Point coordonnees;
} TableObjectif;


int appartient(float xP, float zP);

int toucheObjectif(float xP, float zP);

int dansPlateau(float xp, float zp);

void objectifFin();

void vBitmapOutput(int x, int y, char *string, void *font);

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
