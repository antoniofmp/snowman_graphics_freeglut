#include <iostream>
#include <fstream>
#include "Llanta.h"
using namespace std;

Llanta::Llanta()
{
	llanta1=gluNewQuadric();

	gluQuadricDrawStyle(llanta1,GLU_FILL);
}

Llanta::~Llanta()
{
	gluDeleteQuadric(llanta1);
}

void Llanta::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	//---------------------------------------------llanta 
	glPushMatrix();
	glColor3f( 1,0,0);
	gluDisk(llanta1, 0, 1, 20, 20);
	glPopMatrix(); 
}