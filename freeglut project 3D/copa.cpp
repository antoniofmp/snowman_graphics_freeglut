#include <iostream>
#include <fstream>
#include "copa.h"

using namespace std;

copa::copa()
{
	copa1=gluNewQuadric();
	gluQuadricDrawStyle(copa1,GLU_FILL);
}
copa::~copa()
{
	gluDeleteQuadric(copa1);
}

void copa::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	/*
	//--------------------------------------------------- tronco
	*/
	//--------------------------------------------------- copa
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glColor3f( 0.0, 0.8, 0.0);
	gluCylinder(copa1, 1.5, 0, 5, 40, 40);
	glPopMatrix(); 
}