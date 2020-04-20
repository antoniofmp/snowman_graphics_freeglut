#include <iostream>
#include <fstream>
#include "Farol.h"

using namespace std;

Farol::Farol()
{
	tuvo=gluNewQuadric();
	lampara=gluNewQuadric();

	gluQuadricDrawStyle(tuvo,GLU_FILL);
	gluQuadricDrawStyle(lampara,GLU_FILL);
}

Farol::~Farol()
{
	gluDeleteQuadric(tuvo);
	gluDeleteQuadric(lampara);
}

void Farol::dibuja()
{
	//--------------------------------------------------- tuvo
	glPushMatrix();
	glTranslatef(-18, 0, -6.5);
	glRotatef(-90, 1, 0, 0);
	glColor3f( 0.0, 0.0, 0.0);
	gluCylinder(tuvo, 0.3, 0.3, 13, 20, 20);
	glPopMatrix();
	//--------------------------------------------------- lampara
	glPushMatrix();
	glTranslatef(-18, 13, -6.5);
	glColor3f(1.0, 1.0, 1.0);
	gluSphere(lampara, 1, 100, 100);

	glPopMatrix(); 
}