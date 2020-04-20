#include <iostream>
#include <fstream>
#include "Neumatico.h"
using namespace std;

Neumatico::Neumatico()
{
	Neumatico1=gluNewQuadric();

	gluQuadricDrawStyle(Neumatico1,GLU_FILL);
	//gluQuadricDrawStyle(llanta,GLU_POINT);
}

Neumatico::~Neumatico()
{
	gluDeleteQuadric(Neumatico1);
}

void Neumatico::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//--------------------------------------------- neumatico
	glPushMatrix();
	glColor3f( 0,0,0);
	gluCylinder(Neumatico1, 1, 1, 1, 20, 20);
	glPopMatrix(); 
}