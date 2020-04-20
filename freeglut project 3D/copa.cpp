#include <iostream>
#include <fstream>
#include "copa.h"

using namespace std;

copa::copa()
{
	//tronco=gluNewQuadric();
	copa1=gluNewQuadric();

	//gluQuadricDrawStyle(tronco,GLU_FILL);
	gluQuadricDrawStyle(copa1,GLU_FILL);


}
copa::~copa()
{
	//gluDeleteQuadric(tronco);
	gluDeleteQuadric(copa1);
}

void copa::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	/*
	//glLoadIdentity();
	//--------------------------------------------------- tronco
	glPushMatrix();
	glTranslatef(7.5, 0, 7.5);
	glRotatef(-90, 1, 0, 0);
	glColor3f( 0.5, 0.2, 0.0);
	gluCylinder(tronco, 0.8, 0.4, 5, 40, 40);
	glPopMatrix();
	*/
	//--------------------------------------------------- copa
	glPushMatrix();
	//glTranslatef(7.5, 5, 7.5);
	glRotatef(-90, 1, 0, 0);
	glColor3f( 0.0, 0.8, 0.0);
	gluCylinder(copa1, 1.5, 0, 5, 40, 40);
	glPopMatrix(); 

}