#include <iostream>
#include <fstream>
#include "copa2.h"


using namespace std;

copa2::copa2()
{

	//tronco=gluNewQuadric();
	//copa=gluNewQuadric();
	copaup=gluNewQuadric();

	//gluQuadricDrawStyle(tronco,GLU_FILL);
	//gluQuadricDrawStyle(copa,GLU_FILL);
	gluQuadricDrawStyle(copaup,GLU_FILL);
	

}

copa2::~copa2()
{

	//gluDeleteQuadric(tronco);
	//gluDeleteQuadric(copa);
	gluDeleteQuadric(copaup);

}

void copa2::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//--------------------------------------------------- copa2
	glPushMatrix();
	//glTranslatef(-5.5, 4, -5);
	glColor3f(0.0, 0.8, 0.0);
	gluSphere(copaup, 1.6, 200, 200);
	glPopMatrix();
	

}