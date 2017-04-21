#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

float posX=0;
float posZ=-3;

void clavier(unsigned char touche, int x, int y)
{
    if(touche=='z')
        posZ+=0.1;
    else if(touche=='s')
        posZ-=0.1;
    else if(touche=='q')
        posX+=0.1;
    else if(touche=='d')
        posX-=0.1;

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

void carre(int x,int y,int z, int l) //Coordonnées du coté bas gauche et longueur d'un coté
{
    glBegin(GL_QUADS);
    glVertex3f(x,y,z);
    glVertex3f(x+l,y,z);
    glVertex3f(x+l,y+l,z);
    glVertex3f(x,y+l,z);
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
  //bas gris
  glColor3f(0.5,0.5,0.5);
  glVertex3f(-5,0,-5);
  glVertex3f(-5,0,5);
  glVertex3f(5,0,5);
  glVertex3f(5,0,-5);
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

void Bonhomme(int x, int y, int z) //Coordonnées du coté bas gauche du pied gauche
{
    glColor3ub(255,255,255); //On pourra changer le couleur pour chaque pnj
    parallepipede(x,y,z,x+1,y+2,z+1); //Pied gauche
    parallepipede(x+2,y,z,x+3,y+2,z+1); //Pied droit
    parallepipede(x,y+2,z,x+3,y+4,z+1); //Torse
    parallepipede(x-1,y+3,z,x,y+4,z+1); //Bras gauche
    parallepipede(x+3,y+3,z,x+4,y+4,z+1); //Bras droit
    glTranslatef(x+1.5,y+4.5,z+0.5);
    glutSolidSphere(1,20,20); //Tête
    glTranslatef(0,0,0);

}

void Immeuble(int x, int y, int z) //Coordonnées du coté bas gauche
{
    glColor3f(0.6,0.6,0.6);
    parallepipede(x,y,z,x+5,y+8,z+5);
    //Pour la suite on a le choix entre dessiner des carrés pour les fenêtres ou appliquer une texture avec des fenetres
}

void Arbre(int x, int y, int z, int r) //Coordonées du bas gauche du tronc et longueur d'un coté
{
    glColor3ub(139,69,19);
    /*GLUquadric* cylinder = gluNewQuadric();
    glTranslatef(x,y,z);
    glRotatef(90,1,0,0);
    gluCylinder(cylinder,r,r,2,20,20);
    gluDeleteQuadric(cylinder);
    glRotatef(-90,1,0,0);
    glTranslatef(0,0,0);*/
    parallepipede(x,y,z,x+r,y+2,z+r);
    glColor3ub(34,139,34);
    pyramide(x-r,y+2,z-r);
    pyramide(x-r,y+2.5,z-r);
    pyramide(x-r,y+3,z-r);
}

void Lampadaire(int x, int y, int z) //Coordonnées du pied
{
    glColor3ub(166,166,166);
    parallepipede(x,y,z,x+0.5,y+3,z+0.5);
    parallepipede(x-2,y+3,z,x+0.5,y+3.5,z+0.5);
    glTranslatef(x-2,y+2.7,z+0.3);
    glutSolidSphere(0.6,20,20);
    glTranslatef(0,0,0);
}

void Affichage(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //Mise en place de l'observateur
  glFrustum(posX-1,posX+1,-1,1,0.5,30);
  //Fin de mise en place de l'observateur

  gluLookAt(posX,1,posZ, posX,1,posZ+2, posX,2,posZ);

  //Decor();
  //Immeuble(-1,-2,0);
  //Arbre(-1,-2,0,1);
  Bonhomme(-1,-2,2);
  //Lampadaire(-1,-2,2);

  glutSwapBuffers();
}

int main(int argc, char * argv[], char * envp[]){

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(600,600);
  glutInitWindowPosition(350,60);
  glutCreateWindow("Projet - Main");
  glEnable(GL_DEPTH_TEST);


  glutDisplayFunc(Affichage);
  glutIdleFunc(mouvement);

  glutMainLoop();
  return 0;
}

