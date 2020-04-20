#include <fstream>
#include "esfera.h"

using namespace std;

Esfera::Esfera()
{
	copa=gluNewQuadric();
	gluQuadricDrawStyle(copa,GLU_FILL);
}

Esfera::~Esfera()
{
	gluDeleteQuadric(copa);
}

void Esfera::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	//--------------------------------------------------- copa
	glPushMatrix();
	glTranslatef(12, 0, 0);
	glColor3f(1.0, 0.5, 0.0);
	gluSphere(copa, 4, 100, 100);
	glPopMatrix();
}