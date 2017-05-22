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

typedef int Element;

typedef struct s_arbre // Structure arbre(racine,fils[])
{
  Element racine;
  struct s_arbre** fils;
}s_arbre;
typedef s_arbre* Arbre;

Arbre ArbreVide();

Arbre ConsArbre(Element e, ...);

void vider(Arbre A);

int EstVide(Arbre A);

void Afficher(Arbre A);

#endif

