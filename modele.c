#include "modele.h"

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

void Bonhomme(float x, float y, float z) //Coordonnées du coté bas gauche du pied gauche
{
    glColor3ub(255,255,255);
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
}

void Sapin(float x, float y, float z, float r) //Coordonées du bas gauche du tronc et longueur d'un coté
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
}
