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

void vider(arbre A)
{
    int i;
    for(i=0;i<4;i++)
    {
        if(EstVide(A->fils[i]) == FALSE)
            vider(A->fils[i]);
    }
    free(A);
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
