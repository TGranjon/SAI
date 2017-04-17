#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

float angle=0;

void animer()
{
    angle += 0.05;
    if(angle >360)
        angle=0;
  glutPostRedisplay();
}

void parallepipede(float x1, float y1, float z1, float x2, float y2, float z2) //Coordonn�es du cot� bas gauche et du cot� haut droit
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
    //Arri�re
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

void carre(int x,int y,int z, int l) //Coordonn�es du cot� bas gauche et longueur d'un cot�
{
    glBegin(GL_QUADS);
    glVertex3f(x,y,z);
    glVertex3f(x+l,y,z);
    glVertex3f(x+l,y+l,z);
    glVertex3f(x,y+l,z);
    glEnd();
}

void pyramide(float x, float y, float z) //Coordon�es du coin inf�rieur gauche du pied de la pyramide
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

void Bonhomme(int x, int y, int z) //Coordonn�es du cot� bas gauche du pied gauche
{
    glColor3ub(255,255,255); //On pourra changer le couleur pour chaque pnj
    parallepipede(x,y,z,x+1,y+2,z+1); //Pied gauche
    parallepipede(x+2,y,z,x+3,y+2,z+1); //Pied droit
    parallepipede(x,y+2,z,x+3,y+4,z+1); //Torse
    parallepipede(x-1,y+3,z,x,y+4,z+1); //Bras gauche
    parallepipede(x+3,y+3,z,x+4,y+4,z+1); //Bras droit
    glTranslatef(x+1.5,y+4.5,z+0.5);
    glutSolidSphere(1,20,20); //T�te
    glTranslatef(0,0,0);

}

void Immeuble(int x, int y, int z) //Coordonn�es du cot� bas gauche
{
    glColor3f(0.6,0.6,0.6);
    parallepipede(x,y,z,x+3,y+5,z+3);
    //Pour la suite on a le choix entre dessiner des carr�s pour les fen�tres ou appliquer une texture avec des fenetres
}

void Arbre(int x, int y, int z, int r) //Coordon�es du bas gauche du tronc et longueur d'un cot�
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

void Lampadaire(int x, int y, int z) //Coordonn�es du pied
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
  glFrustum(-1,1, -1,1, 0.5,30);
  gluLookAt(1,2,-3, 0,0,0 ,0,2,0);
  //Fin de mise en place de l'observateur

  glTranslatef(1,1,1);
  glRotatef(angle,0,1,0);
  glTranslatef(-1,-1,-1);

  //Decor();
  //Immeuble(-1,-2,0);
  //Arbre(-1,-2,0,1);
  //Bonhomme(-1,-2,2);
  Lampadaire(-1,-2,2);

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
  glutIdleFunc(animer);

  glutMainLoop();
  return 0;
}

