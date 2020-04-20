#include <iostream>
#include <fstream>
#include "Llanta.h"
using namespace std;

Llanta::Llanta()
{
	llanta1=gluNewQuadric();

	gluQuadricDrawStyle(llanta1,GLU_FILL);
	//gluQuadricDrawStyle(llanta,GLU_POINT);
	//gluQuadricNormals( llanta1, GLU_SMOOTH); // For if lighting is to be used.
	//gluQuadricOrientation( llanta1,GLU_OUTSIDE);
	//gluQuadricTexture( llanta1, GL_TRUE);// if you want to map a texture to it.

}

Llanta::~Llanta()
{
	gluDeleteQuadric(llanta1);
}

void Llanta::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//---------------------------------------------llanta 
	glPushMatrix();
	glColor3f( 1,0,0);
	//gluDisk(llanta1, 2, 2, 2, 20);
	gluDisk(llanta1, 0, 1, 20, 20);
	glPopMatrix(); 
}