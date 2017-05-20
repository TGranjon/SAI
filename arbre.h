#ifndef ARBRE_H

#define ARBRE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define PLEIN 11
#define VIDE 10
#define INTER -9
#define TRUE 1
#define FALSE 0

typedef struct point // Structure Point(x,z)
{
    float x;
    float z;
} Point;

typedef int element;

typedef struct s_arbre
{
  element racine; // Racine de l'arbre (VIDE, PLEIN, INTER)
  Point A; // Point bas gauche du plateau correspondant
  Point B; // Point haut droit du plateau correspondant
  struct s_arbre** fils; // Fils de l'arbre
}s_arbre;
typedef s_arbre* arbre;

arbre ArbreVide();
arbre ConsArbre(element e, ...);
arbre Fils(int ieme, arbre A);
element kacine(arbre A);
int EstVide(arbre A);
void Afficher(arbre A);

#endif

