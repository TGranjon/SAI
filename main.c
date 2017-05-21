#include "main.h"
// Pour les déplacements
float angle=0;
float posX=0;
float posZ=-1;
float visX=0;
float visZ=5;
// Fin des déplacements
int finDuJeu=FALSE, perdu=FALSE; // booleens de fin de partie
TableTotale tableT; // Liste des carrés de collision
TableObjetTotale tabObj;//Tableau contenant les objets
arbre Ar; // 4-arbre
TableTotale tableT; // Liste des carrés de collision
TableObjectif objectif_liste[NBOBJECTIF]; // Liste des objectifs
Point fov[4]; // FOV de l'utilisateur

int appartient(float xP, float zP) // Est ce que le point(xP,0,zP) appartient à un objet ?
{
    int a;
    for(a=0;a<tableT.taille;a++)
    {
        if((xP>=tableT.forme[a].minP.x)&&(xP<=tableT.forme[a].maxP.x))
        {
            if((zP>=tableT.forme[a].minP.z)&&(zP<=tableT.forme[a].maxP.z))
                return TRUE;
        }
    }
    return FALSE;
}

int toucheObjectif(float xP, float zP) // Un objectif est-il touché par le joueur ?
{
    int i;
    for(i=0;i<NBOBJECTIF;i++)
    {
        if((xP>=objectif_liste[i].coordonnees.x-0.6)&&(xP<=objectif_liste[i].coordonnees.x+0.6))
        {
            if((zP>=objectif_liste[i].coordonnees.z-0.6)&&(zP<=objectif_liste[i].coordonnees.z+0.6))
                return i;
        }
    }
    return -1;
}

int dansPlateau(float xP, float zP) // Est ce que le point(xP,0,zP) est dans le plateau ?
{
	if(xP>=-52 && xP<=52 && zP>=-55 && zP<=53){
		return TRUE;
	}
	return FALSE;
}

int pnpoly(int nvert, Point vert[], float testx, float testz) // Est ce que le point(x,y) est dans un polygone ? (0 = non, 1 = oui)
//nvert est le nombre de cotés
//vert est le polygone
//testx et testz sont les coordonnees du point a tester
{
  int i, j, c = 0;
  float vertx[nvert];
  float vertz[nvert];
  for(i=0;i<nvert;i++)
  {
      vertx[i]=vert[i].x;
      vertz[i]=vert[i].z;
  }
  for (i = 0, j = nvert-1; i < nvert; j = i++) {
    if ( ((vertz[i]>testz) != (vertz[j]>testz)) &&
     (testx < (vertx[j]-vertx[i]) * (testz-vertz[i]) / (vertz[j]-vertz[i]) + vertx[i]) )
       c = !c;
  }
  return c;
}

int inclus(Point A[]) // Est ce que le FOV est inclus dans A ?
{
    int i;
    for(i=0;i<4;i++)
    {
        if(pnpoly(4,A,fov[i].x,fov[i].z)==1)
            return TRUE; //Le FOV est dans A -> contenu()
    }
    return FALSE; //Le FOV n'est pas dans A -> Arbre VIDE
}

int contenu(Point A[]) // Est ce que A est contenu dans le FOV ?
{
    int i;
    int c=0;
    for(i=0;i<4;i++)
    {
        if(pnpoly(4,fov,A[i].x,A[i].z)==1)
            c++;
    }
    if(c==4)
        return 3; //A est intégralement dans le FOV -> Arbre PLEIN
    if(c>0)
        return 2; //A est partiellement dans le FOV -> Arbre INTER
    return 1; //A n'est pas dans le FOV -> Arbre VIDE
}

arbre Arbre4(Point A[]) // Cree le 4-arbre qui represente ce qui est vu par le joueur
{
    if(inclus(A)==FALSE)
        return ConsArbre(VIDE,ArbreVide(),ArbreVide(),ArbreVide(),ArbreVide());
    if(contenu(A)==3)
        return ConsArbre(PLEIN,ArbreVide(),ArbreVide(),ArbreVide(),ArbreVide());
    if(contenu(A)==1)
        return ConsArbre(VIDE,ArbreVide(),ArbreVide(),ArbreVide(),ArbreVide());
    if(contenu(A)==2)
    {
        Point B1[4], B2[4], B3[4], B4[4];
        B1[0].x=A[0].x;
        B1[0].z=A[0].z;
        B1[1].x=A[0].x;
        B1[1].z=A[1].z-A[0].z;
        B1[2].x=A[3].x-A[0].x;
        B1[2].z=A[1].z-A[0].z;
        B1[3].x=A[3].x-A[0].x;
        B1[3].z=A[0].z;

        B2[0].x=A[0].x;
        B2[0].z=A[1].z-A[0].z;
        B2[1].x=A[0].x;
        B2[1].z=A[1].z;
        B2[2].x=A[3].x-A[0].x;
        B2[2].z=A[1].z;
        B2[3].x=A[3].x-A[0].x;
        B2[3].z=A[1].z-A[0].z;

        B3[0].x=A[3].x-A[0].x;
        B3[0].z=A[1].z-A[0].z;
        B3[1].x=A[3].x-A[0].x;
        B3[1].z=A[1].z;
        B3[2].x=A[3].x;
        B3[2].z=A[1].z;
        B3[3].x=A[3].x;
        B3[3].z=A[1].z-A[0].z;

        B4[0].x=A[3].x-A[0].x;
        B4[0].z=A[0].z;
        B4[1].x=A[3].x-A[0].x;
        B4[1].z=A[1].z-A[0].z;
        B4[2].x=A[3].x;
        B4[2].z=A[1].z-A[0].z;
        B4[3].x=A[3].x;
        B4[3].z=A[0].z;
        return ConsArbre(INTER,Arbre4(B1),Arbre4(B2),Arbre4(B3),Arbre4(B4));
    }
    return ArbreVide(); // Cas d'erreur
}

void objectifFin() // Est ce que tous les objectifs ont ete trouves ?
{
	int i,finJeu = TRUE;
	for(i=0; i<NBOBJECTIF; i++){
		if(objectif_liste[i].cache == TRUE){
			finJeu = FALSE;
		}
	}
	if(finJeu == TRUE){
		finDuJeu = TRUE;
	}
}

void vBitmapOutput(int x, int z, char *string, void *font) // Fonction d'affichage du message de fin
{
	int len,i; //len donne la longueur de la chaîne de caractères
	glRasterPos3f(x,0,z); //Positionne le premier caractère de la chaîne
	len = (int) strlen(string); //Calcule la longueur de la chaîne
	for (i = 0; i < len; i++){ //Affiche chaque caractère de la chaîne
	 glutBitmapCharacter(font,string[i]);
	}
}

void clavier(unsigned char touche, int x, int y) // Fonction de gestion du clavier
{
    if(perdu == FALSE && finDuJeu == FALSE)
  	{
		int o;
		switch(touche)
		{
		    case 'q' :
		        angle -= 0.05;
		        visX = sin(angle);
		        visZ = -cos(angle);
		        break;
		    case 'd' :
		        angle += 0.05;
		        visX = sin(angle);
		        visZ = -cos(angle);
		        break;
		    case 'z' :
		        if(appartient(posX+visX*0.3,posZ+visZ*0.3)==TRUE) //Rentre dans un objet solide ?
		            break;
		        o=toucheObjectif(posX+visX*0.3,posZ+visZ*0.3); //Rentre dans un objectif ?
		        if(o>-1)
		        {
		            objectif_liste[o].cache=FALSE;
					objectifFin();
				}
		        if(dansPlateau(posX+visX*0.3,posZ+visZ*0.3)==TRUE) //Sort du plateau ?
		        {
		        	posX += visX * 0.3;
		    	    posZ += visZ * 0.3;
		        }
		        break;
		    case 's' :
		        if(appartient(posX-visX*0.3,posZ-visZ*0.3)==TRUE) //Rentre dans un objet solide
		            break;
		        o=toucheObjectif(posX-visX*0.3,posZ-visZ*0.3); //Rentre dans un objectif
		        if(o>-1)
		        {
		            objectif_liste[o].cache=FALSE;
					objectifFin();
				}
		        if(dansPlateau(posX-visX*0.3,posZ-visZ*0.3)==TRUE) //Sort du plateau ?
		        {
		      	  	posX -= visX * 0.3;
		        	posZ -= visZ * 0.3;
		        }
		        break;
		}
	}
}

void mouvement() // Idle function
{
		glutKeyboardFunc(clavier);
		glutPostRedisplay();
}

void Affichage(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if(finDuJeu == FALSE && perdu == FALSE){

	  glMatrixMode(GL_PROJECTION);
	  glLoadIdentity();
	  //Mise en place de l'observateur
	  glFrustum(-1,1, -1,1, 0.5,40);
	  //Fin de mise en place de l'observateur
	  gluLookAt(posX,1,posZ, posX+visX,1,posZ+visZ, 0,1,0);

	  //Calcul FOV
      fov[0].x=posX+visX-1; // Bas gauche
      fov[0].z=posZ+visZ+0.5;
      fov[1].x=posX+visX+1; // Bas droit
      fov[1].z=posZ+visZ+0.5;
      fov[2].x=posX+visX+80; // Haut droit
      fov[2].z=posZ+visZ+40;
      fov[3].x=posX+visX-80; // Haut gauche
      fov[3].z=posZ+visZ+40;

	  //Creation du plateau
	  plateau(-52,0,-55,104,108);
	  Point P[4];
      P[0].x=-52;
      P[0].z=-55;
      P[1].x=-52;
      P[1].z=53;
      P[2].x=52;
      P[2].z=53;
      P[3].z=52;
      P[3].z=-55;
      //Fonctions arbre
      /*Ar = Arbre4(P);
      vider(Ar);*/

	  //Affichage des objets générés aléatoirement
	  int typeObjet, j;
	  float x,y,z,r;
	  for(j=0; j<NBOBJET; j++){
			typeObjet = tabObj.objet[j].typeObjet;
			x = tabObj.objet[j].x;
	   		y = tabObj.objet[j].y;
			z = tabObj.objet[j].z;
	   		switch(typeObjet){
		   	//Immeuble
		   	case 1:
		   		Immeuble(x,y,z);
		   		break;

		   	//Sapin
		   	case 2:
		   		r = tabObj.objet[j].r;
				Sapin(x,y,z,r);
				break;

			//Lampadaire
			case 3:
				Lampadaire(x,y,z);
				break;
			default:
				break;
			}
	  }
	  int i;
	  for(i=0; i<NBOBJECTIF;i++){
	  	if(objectif_liste[i].cache == TRUE){
	  		Objectif(objectif_liste[i].coordonnees.x,1,objectif_liste[i].coordonnees.z,i);
	  	}
	  }

	//Le jeu est fini
	}else if(perdu == TRUE){
		glClearColor(0,0,0,1);
		vBitmapOutput(visX+posX,visZ+posZ-25,"Game Over",GLUT_BITMAP_TIMES_ROMAN_24);
	}else if(finDuJeu == TRUE){
		glClearColor(0,0,0,1);
		vBitmapOutput(visX+posX-5,visZ+posZ-25,"VOUS AVEZ GAGNE !",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	glutSwapBuffers();
}

void gameOver()
{
    perdu=TRUE;
}

int main(int argc, char * argv[], char * envp[]){

  tableT.taille=0;
  tabObj.taille=0;
  srand(time(NULL));
  //Ar = ArbreVide();

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(600,600);
  glutInitWindowPosition(350,60);
  glutCreateWindow("Projet - Main");
  glEnable(GL_DEPTH_TEST);

  glutDisplayFunc(Affichage);
  glutIdleFunc(mouvement);
  glClearColor(0,0.4,0.8,0);
  //Generation des objets
  float x,y,z,r;
  int i;

  //Boucle de creation des NBOBJET objets
  for(i=0; i<NBOBJET; i++){
  	int objet = rand()%(4-1)+1;
   	x=0;y=0;z=0;r=0;

   	switch(objet){
   	//Immeuble
   	case 1:
   		//Vérification que le point choisi n'est pas en collision avec un autre objet
		do{
			x=(rand()%(104)+1)-52;
			z=(rand()%(108)+1)-55;
		}while(appartient(x,z)==TRUE);
		y=0;
		tabObj.objet[tabObj.taille].typeObjet=objet;
		tabObj.objet[tabObj.taille].x=x;
		tabObj.objet[tabObj.taille].y=y;
		tabObj.objet[tabObj.taille].z=z;

   		tableT.forme[tableT.taille].minP.x=x-0.2;
        tableT.forme[tableT.taille].minP.z=z-0.2;
        tableT.forme[tableT.taille].maxP.x=x+5.2;
        tableT.forme[tableT.taille].maxP.z=z+5.2;

        tabObj.taille++;
        tableT.taille++;
   		break;

   	//Sapin
   	case 2:
   	   	//Vérification que le point choisi n'est pas en collision avec un autre objet
   		do{
			x=(rand()%(104)+1)-52;
			z=(rand()%(108)+1)-55;
		}while(appartient(x,z)==TRUE);
   		y=0;
   		r=1;
	 	tabObj.objet[tabObj.taille].typeObjet=objet;
		tabObj.objet[tabObj.taille].x=x;
		tabObj.objet[tabObj.taille].y=y;
		tabObj.objet[tabObj.taille].z=z;
		tabObj.objet[tabObj.taille].r=r;

    	tableT.forme[tableT.taille].minP.x=x-0.2;
        tableT.forme[tableT.taille].minP.z=z-0.2;
        tableT.forme[tableT.taille].maxP.x=x+r+0.2;
        tableT.forme[tableT.taille].maxP.z=z+r+0.2;

        tabObj.taille++;
        tableT.taille++;
    	break;

    //Lampadaire
    case 3:
  		//Vérification que le point choisi n'est pas en collision avec un autre objet
   		do{
			x=(rand()%(104)+1)-52;
			z=(rand()%(108)+1)-55;
		}while(appartient(x,z)==TRUE);
    	y=0;
	 	tabObj.objet[tabObj.taille].typeObjet=objet;
		tabObj.objet[tabObj.taille].x=x;
		tabObj.objet[tabObj.taille].y=y;
		tabObj.objet[tabObj.taille].z=z;
    	tableT.forme[tableT.taille].minP.x=x-0.3;
        tableT.forme[tableT.taille].minP.z=z-0.3;
        tableT.forme[tableT.taille].maxP.x=x+0.7;
        tableT.forme[tableT.taille].maxP.z=z+0.7;

        tabObj.taille++;
        tableT.taille++;
    	break;
    default:
    	break;
    }
  }

  for(i=0;i<NBOBJECTIF;i++) // Initialisation des objectifs
  {
      do{
        x=(rand()%(104)+1)-52;
        z=(rand()%(108)+1)-55;
      }while(appartient(x,z)==TRUE);
      objectif_liste[i].cache=TRUE;
      objectif_liste[i].coordonnees.x=x;
      objectif_liste[i].coordonnees.z=z;
  }
  //Initialisation position joueur
  do{
      x=(rand()%(104)+1)-52;
      z=(rand()%(108)+1)-55;
  }while((appartient(x,z)==TRUE)&&(toucheObjectif(x,z)==TRUE));
  posX=x;
  posZ=z;
  visX=sin(angle);
  visZ=-cos(angle);

  //Initialisation FOV
  fov[0].x=posX+visX-1; // Bas gauche
  fov[0].z=posZ+visZ+0.5;
  fov[1].x=posX+visX+1; // Bas droit
  fov[1].z=posZ+visZ+0.5;
  fov[2].x=posX+visX+80; // Haut droit
  fov[2].z=posZ+visZ+40;
  fov[3].x=posX+visX-80; // Haut gauche
  fov[3].z=posZ+visZ+40;

  //Timer
  glutTimerFunc(60000,gameOver,0); // 60000 ms = 1 min

  glutMainLoop();
  return 0;
}
