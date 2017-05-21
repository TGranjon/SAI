#include "arbre.h"

arbre ArbreVide() // Retourne un arbre vide
{
  return NULL;
}

arbre ConsArbre(element e, ...) // Construit un arbre avec les param�tres propos�s
{
  arbre k=(arbre)malloc(1*sizeof(arbre));
  va_list params;
  va_start(params, e);
  k->racine=e;
  k->fils=(arbre*)malloc(4*sizeof(arbre));
  int i;
  for(i=0;i<4;i++)
    {
      arbre suiv = va_arg(params, arbre);
      k->fils[i]=suiv;
    }
  return k;
}

void vider(arbre A) // Lib�re la m�moire prise par un arbre
{
    int i;
    for(i=0;i<4;i++)
    {
        if(EstVide(A->fils[i]) == FALSE)
            vider(A->fils[i]);
    }
    free(A);
}

int EstVide(arbre A) // Est-ce que A est un arbre vide ?
{
    if(A==NULL)
        return TRUE;
    return FALSE;
}

void Afficher(arbre A) // Affiche le contenu de A
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
