#include "Rueda.h"
#include <iostream>
#include <fstream>
#include "Llanta.h"
#include "Neumatico.h"

using namespace std;

Rueda::Rueda()
{
	//----------------------------------------------------------------------------------- hijo 1 llanta
	Objeto3D* hijo1= new Llanta();
		//hijo1->traslada(-7.5, 6.5, 7.5);
		//hijo1->rota(-90, 1, 0, 0);
		//hijo1->escala (2,2,2);
		this->introduceObjeto(hijo1);

//--------------------------------------------------------------------------------------- hijo 2 neumatico
		Objeto3D* hijo2= new Neumatico();
		//hijo2->traslada(-7.5, 0, 7.5);
		//hijo2->rota(-90, 1, 0, 0);
		//hijo2->escala (2,2,2);
		this->introduceObjeto(hijo2);
	//llanta=gluNewQuadric();

	//gluQuadricDrawStyle(llanta,GLU_FILL);
	//gluQuadricDrawStyle(llanta,GLU_POINT);
}
/*
Rueda::~Rueda()
{
	gluDeleteQuadric(llanta);
}

void Rueda::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//---------------------------------------------llanta 
	glPushMatrix();
	glColor3f( 0,0,0);
	gluCylinder(llanta, 2, 2, 2, 20, 20);
	glPopMatrix(); 
}
*/