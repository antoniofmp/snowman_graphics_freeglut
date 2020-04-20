#include <iostream>
#include <fstream>
#include "copa2.h"

using namespace std;

copa2::copa2()
{
	copaup=gluNewQuadric();
	gluQuadricDrawStyle(copaup,GLU_FILL);
}

copa2::~copa2()
{
	gluDeleteQuadric(copaup);
}

void copa2::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	//--------------------------------------------------- copa2
	glPushMatrix();
	glColor3f(0.0, 0.8, 0.0);
	gluSphere(copaup, 1.6, 200, 200);
	glPopMatrix();
}