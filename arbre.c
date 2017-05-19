#include "arbre.h"

arbre ArbreVide()
{
  return NULL;
}

arbre ConsArbre(element e, ...)
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

arbre Fils(int ieme, arbre A)
{
  return A->fils[ieme];
}

element Racine(arbre A)
{
  return A->racine;
}

int EstVide(arbre A)
{
    if(A==NULL)
        return TRUE;
    return FALSE;
}

void Afficher(arbre A)
{
  if(EstVide(A) == TRUE)
    {
    }
  fprintf(stdout,"%d",A->racine);
  int i;
  fprintf(stdout,"\nSes fils :\n");
  for(i=0;i<4;i++)
    {
      if(EstVide(Fils(i,A)) == 1)
	{
	  Afficher(Fils(i,A));
	}
    }
  fprintf(stdout,"Fin des fils\n");
}
