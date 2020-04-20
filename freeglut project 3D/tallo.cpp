#include <iostream>
#include <fstream>
#include "tallo.h"

using namespace std;

tallo::tallo()
{
	tronco=gluNewQuadric();

	gluQuadricDrawStyle(tronco,GLU_FILL);
}
tallo::~tallo()
{
	gluDeleteQuadric(tronco);
}

void tallo::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	
	//--------------------------------------------------- tronco
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glColor3f( 0.5, 0.2, 0.0);
	gluCylinder(tronco, 0.8, 0.4, 5, 40, 40);
	glPopMatrix();
}