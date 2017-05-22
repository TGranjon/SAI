#ifndef ARBRE_H

#define ARBRE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

//Racine des arbres
#define PLEIN 1
#define VIDE 0
#define INTER -1

//Booléens
#define TRUE 1
#define FALSE 0

typedef int Element; // Type racine

typedef struct s_arbre // Structure s_arbre(Element,s_arbre**)
{
  Element racine;
  struct s_arbre** fils;
}s_arbre;
typedef s_arbre* Arbre; // Structure Arbre

Arbre ArbreVide();

Arbre ConsArbre(Element e, ...);

void vider(Arbre A);

int EstVide(Arbre A);

void Afficher(Arbre A);

#endif

