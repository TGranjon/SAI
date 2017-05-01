#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    int x;
    int z;
} Point;

typedef struct tableforme
{
    Point minP;
    Point maxP;
} TableForme;

typedef struct tabletotale
{
    int taille;
    TableForme forme[20]; // A determiner avec le 4-arbre
} TableTotale;
