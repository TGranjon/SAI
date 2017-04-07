#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

float angle=0;

void animer()
{
    angle += 0.05;
    if(angle >360)
        angle=0;
  glutPostRedisplay();
}

void parallepipede(int x1, int y1, int z1, int x2, int y2, int z2) //Coordonnées du coté bas gauche et du coté haut droit
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
    parallepipede(x,y,z,x+1,y+2,z+1); //Pied gauche
    parallepipede(x+2,y,z,x+3,y+2,z+1); //Pied droit
    parallepipede(x,y+2,z,x+3,y+4,z+1); //Torse
    parallepipede(x-1,y+3,z,x,y+4,z+1); //Bras gauche
    parallepipede(x+3,y+3,z,x+4,y+4,z+1); //Bras droit
    glTranslatef(x+1.5,y+4.5,z+0.5);
    glutSolidSphere(1,20,20); //Tête
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
  Bonhomme(-1,-2,0);

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

