#ifndef ARBRE_H

#define ARBRE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define PLEIN 1
#define VIDE 0
#define INTER -1
#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct s_arbre
{
  element racine;
  struct s_arbre** fils;
}s_arbre;
typedef s_arbre* arbre;

arbre ArbreVide();

arbre ConsArbre(element e, ...);

void vider(arbre A);

int EstVide(arbre A);

void Afficher(arbre A);

#endif

