#include "Luz.h"
#include <iostream>
#include <fstream>

using namespace std;

Luz::Luz()
{
	Foco=gluNewQuadric();

	gluQuadricDrawStyle(Foco,GLU_FILL);
}

Luz::~Luz()
{
	gluDeleteQuadric(Foco);
}

void Luz::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	//---------------------------------------------- luz foco coche
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glColor3f( 0.0,1.0,0.0);
	gluCylinder(Foco, 0.5, 1, 1, 20, 20);
	glPopMatrix();
//--------------------------------------------------------------luz para el coche
    GLfloat d[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT3, GL_DIFFUSE, d);
	GLfloat s[]={1.0f,0.0f,0.0f};
	glLightf(GL_LIGHT3, GL_SPOT_DIRECTION, *s);
	GLfloat p[] = { 1.2f, 0.4f, 1.4f, 1.0f };
	glLightfv(GL_LIGHT3, GL_POSITION, p);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 10.0);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 64.0);

//  --------------------------------------------------------------------------------------------------Light1
	GLfloat d2[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT4, GL_DIFFUSE, d2);
	GLfloat s2[] = { 1.0f, 0.0f, 0.0f };
	glLightf(GL_LIGHT4, GL_SPOT_DIRECTION, *s2);
	GLfloat p2[] = { 1.2f, 0.4f,-1.4f, 1.0f };
	glLightfv(GL_LIGHT4, GL_POSITION, p2);
	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 10.0);
	glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 64.0);
}