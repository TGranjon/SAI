#include "arbre.h"

Arbre ArbreVide() // Retourne un arbre vide
{
  return NULL;
}

Arbre ConsArbre(Element e, ...) // Construit un arbre avec les paramètres proposés
{
  Arbre k=(Arbre)malloc(1*sizeof(Arbre));
  va_list params;
  va_start(params, e);
  k->racine=e;
  k->fils=(Arbre*)malloc(4*sizeof(Arbre));
  int i;
  for(i=0;i<4;i++)
    {
      Arbre suiv = va_arg(params, Arbre);
      k->fils[i]=suiv;
    }
  return k;
}

void vider(Arbre A) // Libère la mémoire prise par un arbre et ses fils
{
    int i;
    for(i=0;i<4;i++)
    {
        if(EstVide(A->fils[i]) == FALSE)
            vider(A->fils[i]);
    }
    free(A);
}

int EstVide(Arbre A) // Est ce que A est un arbre vide ?
{
    if(A==NULL)
        return TRUE;
    return FALSE;
}

void Afficher(Arbre A) // Affiche le contenu de A
{
  if(EstVide(A) == TRUE)
    {
        fprintf(stdout,"Arbre vide\n");
    }
  fprintf(stdout,"%d\n",A->racine);
  int i;
  for(i=0;i<4;i++)
    {
      if(EstVide(A->fils[i]) == FALSE)
        {
          fprintf(stdout,"\tFils %d :\n",i);
          Afficher(A->fils[i]);
          fprintf(stdout,"\tFin du fils %d\n",i);
        }
    }
  fprintf(stdout,"Fin des fils\n");
}
