#include "main.h"

float angle=0;
float posX=0;
float posZ=-1;
float visX=0;
float visZ=5;
float minX=-52;
float maxX=52;
float minZ=-55;
float maxZ=53;
TableTotale tableT;
int objectif_liste[10];

int appartient(float xP, float zP)
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

int dansPlateau(float xp, float zp){
	if(xp>=minX && xp<=maxX && zp>=minZ && zp<=maxZ){
		return TRUE;
	}
	return FALSE;
}

void clavier(unsigned char touche, int x, int y)
{
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
            if(appartient(posX+visX*0.1,posZ+visZ*0.1)==TRUE)
                break;
            if(dansPlateau(posX+visX*0.1,posZ+visZ*0.1)==TRUE){
            	posX += visX * 0.1;
        	    posZ += visZ * 0.1;
            }
            break;
        case 's' : // Risque de poser des problemes lors du 4-arbre
            if(appartient(posX-visX*0.1,posZ-visZ*0.1)==TRUE)
                break;
            if(dansPlateau(posX-visX*0.1,posZ-visZ*0.1)==TRUE){
          	  	posX -= visX * 0.1;
            	posZ -= visZ * 0.1;
            }
            break;
	}
}

void mouvement()
{
    glutKeyboardFunc(clavier);
    glutPostRedisplay();
}

void parallepipede(float x1, float y1, float z1, float x2, float y2, float z2) //Coordonnées du coté bas gauche et du coté haut droit
{
    glBegin(GL_QUADS);
    //Bas
    glVertex3f(x1,y1,z1);
    glVertex3f(x1,y1,z2);
    glVertex3f(x2,y1,z2);
    glVertex3f(x2,y1,z1);
    //Face
    glVertex3f(x1,y1,z1);
    glVertex3f(x1,y2,z1);
    glVertex3f(x2,y2,z1);
    glVertex3f(x2,y1,z1);
    //Gauche
    glVertex3f(x1,y1,z1);
    glVertex3f(x1,y1,z2);
    glVertex3f(x1,y2,z2);
    glVertex3f(x1,y2,z1);
    //Arrière
    glVertex3f(x1,y1,z2);
    glVertex3f(x2,y1,z2);
    glVertex3f(x2,y2,z2);
    glVertex3f(x1,y2,z2);
    //Droite
    glVertex3f(x2,y1,z1);
    glVertex3f(x2,y1,z2);
    glVertex3f(x2,y2,z2);
    glVertex3f(x2,y2,z1);
    //Sommet
    glVertex3f(x1,y2,z1);
    glVertex3f(x1,y2,z2);
    glVertex3f(x2,y2,z2);
    glVertex3f(x2,y2,z1);
    glEnd();
}

void carre(float x,float y,float z, float l) //Coordonnées du coté bas gauche et longueur d'un coté
{
    glBegin(GL_QUADS);
    glVertex3f(x,y,z);
    glVertex3f(x+l,y,z);
    glVertex3f(x+l,y+l,z);
    glVertex3f(x,y+l,z);
    glEnd();
}

void plateau(float x,float y,float z, float lar, float lon) //Coordonnées du coté bas gauche, largeur et longueur
{
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_QUADS);
    glVertex3f(x,y,z);
    glVertex3f(x+lar,y,z);
    glVertex3f(x+lar,y,z+lon);
    glVertex3f(x,y,z+lon);
    glEnd();
}

void pyramide(float x, float y, float z) //Coordonées du coin inférieur gauche du pied de la pyramide
{
    glBegin(GL_QUADS);
    glVertex3f(x,y,z);
    glVertex3f(x+3,y,z);
    glVertex3f(x+3,y,z+3);
    glVertex3f(x,y,z+3);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(x,y,z);
    glVertex3f(x+3,y,z);
    glVertex3f(x+1.5,y+1,z+1.5);
    glVertex3f(x,y,z);
    glVertex3f(x,y,z+3);
    glVertex3f(x+1.5,y+1,z+1.5);
    glVertex3f(x,y,z+3);
    glVertex3f(x+3,y,z+3);
    glVertex3f(x+1.5,y+1,z+1.5);
    glVertex3f(x+3,y,z+3);
    glVertex3f(x+3,y,z);
    glVertex3f(x+1.5,y+1,z+1.5);
    glEnd();

}

void Decor()
{
  glBegin(GL_QUADS);
  //Fond bleu
  glColor3f(0,0.4,0.8);
  glVertex3f(-5,0,-5);
  glVertex3f(-5,5,-5);
  glVertex3f(-5,5,5);
  glVertex3f(-5,0,5);
  glVertex3f(-5,0,5);
  glVertex3f(-5,5,5);
  glVertex3f(5,5,5);
  glVertex3f(5,0,5);
  glVertex3f(5,0,5);
  glVertex3f(5,5,5);
  glVertex3f(5,5,-5);
  glVertex3f(5,0,-5);
  glVertex3f(5,0,-5);
  glVertex3f(5,5,-5);
  glVertex3f(-5,5,-5);
  glVertex3f(-5,0,-5);
  glVertex3f(-5,5,-5);
  glVertex3f(5,5,-5);
  glVertex3f(5,5,5);
  glVertex3f(-5,5,5);
  glEnd();

}

void Bonhomme(float x, float y, float z) //Coordonnées du coté bas gauche du pied gauche
{
    glColor3ub(255,255,255); //On pourra changer le couleur pour chaque pnj
    parallepipede(x,y,z,x+1,y+2,z+1); //Pied gauche
    parallepipede(x+2,y,z,x+3,y+2,z+1); //Pied droit
    parallepipede(x,y+2,z,x+3,y+4,z+1); //Torse
    parallepipede(x-1,y+3,z,x,y+4,z+1); //Bras gauche
    parallepipede(x+3,y+3,z,x+4,y+4,z+1); //Bras droit
    glPushMatrix();
    glTranslatef(x+1.5,y+4.5,z+0.5);
    glutSolidSphere(1,20,20); //Tête
    glPopMatrix();

}

void Immeuble(float x, float y, float z) //Coordonnées du coté bas gauche
{
    glColor3f(0.6,0.6,0.6);
    parallepipede(x,y,z,x+5,y+8,z+5);
    //Pour la suite on a le choix entre dessiner des carrés pour les fenêtres ou appliquer une texture avec des fenetres
}

void Arbre(float x, float y, float z, float r) //Coordonées du bas gauche du tronc et longueur d'un coté
{
    glColor3ub(139,69,19);
    parallepipede(x,y,z,x+r,y+2,z+r);
    glColor3ub(34,139,34);
    pyramide(x-r,y+2,z-r);
    pyramide(x-r,y+2.5,z-r);
    pyramide(x-r,y+3,z-r);
}

void Lampadaire(float x, float y, float z) //Coordonnées du pied
{
    glColor3ub(166,166,166);
    parallepipede(x,y,z,x+0.5,y+3,z+0.5);
    parallepipede(x-2,y+3,z,x+0.5,y+3.5,z+0.5);
    glPushMatrix();
    glTranslatef(x-2,y+2.7,z+0.3);
    glutSolidSphere(0.6,20,20);
    glPopMatrix();
}

void Objectif(float x, float y, float z, int num) //Coordonées du centre et numero de l'objectif
{
    glColor3ub(0,0,200);
    glPushMatrix();
    glTranslatef(x,y,z);
    glutSolidSphere(0.6,10,10);
    glPopMatrix();
    objectif_liste[num]=TRUE; //Signifie que l'objectif est encore présent (non trouvé)
}

void Affichage(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //Mise en place de l'observateur
  glFrustum(-1,1, -1,1, 0.5,40);
  //Fin de mise en place de l'observateur

  gluLookAt(posX,1,posZ, posX+visX,1,posZ+visZ, 0,1,0);

  //Creation du plateau
  plateau(-52,0,-55,104,108);

  //Decor();
  Immeuble(-3,0,-8);
  Arbre(5,0,0,1);
  Bonhomme(0,0,5);
  Lampadaire(-5,0,0);
  Objectif(0,1,2,0);

  glutSwapBuffers();
}

int main(int argc, char * argv[], char * envp[]){

  tableT.taille=0;
  int i;
  for(i=0;i<10;i++)
  {
      objectif_liste[i]=FALSE;
  }
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(600,600);
  glutInitWindowPosition(350,60);
  glutCreateWindow("Projet - Main");
  glEnable(GL_DEPTH_TEST);

  glutDisplayFunc(Affichage);
  glutIdleFunc(mouvement);


  tableT.forme[tableT.taille].minP.x=-3; //Immeuble
  tableT.forme[tableT.taille].minP.z=-8;
  tableT.forme[tableT.taille].maxP.x=2;
  tableT.forme[tableT.taille].maxP.z=-3;
  tableT.taille++;
  tableT.forme[tableT.taille].minP.x=5; //Arbre
  tableT.forme[tableT.taille].minP.z=0;
  tableT.forme[tableT.taille].maxP.x=6;
  tableT.forme[tableT.taille].maxP.z=1;
  tableT.taille++;
  tableT.forme[tableT.taille].minP.x=-5; //Lampadaire
  tableT.forme[tableT.taille].minP.z=0;
  tableT.forme[tableT.taille].maxP.x=-4.5;
  tableT.forme[tableT.taille].maxP.z=0.5;
  tableT.taille++;
  tableT.forme[tableT.taille].minP.x=0; //Bonhomme
  tableT.forme[tableT.taille].minP.z=5;
  tableT.forme[tableT.taille].maxP.x=3;
  tableT.forme[tableT.taille].maxP.z=6;
  tableT.taille++;

  glutMainLoop();
  return 0;
}
