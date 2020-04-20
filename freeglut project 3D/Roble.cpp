#include <iostream>
#include <fstream>
#include "Roble.h"
#include "copa2.h"
#include "tallo.h"


using namespace std;

Roble::Roble()
{
//----------------------------------------------------------------------------------- hijo 1 copa cono
	Objeto3D* hijo1= new copa2();
		hijo1->traslada(-7.5, 6.5, 7.5);
		//hijo1->rota(-90, 1, 0, 0);
		//hijo1->escala (2,2,2);
		this->introduceObjeto(hijo1);

//--------------------------------------------------------------------------------------- hijo 2 tallo
		Objeto3D* hijo2= new tallo();
		hijo2->traslada(-7.5, 0, 7.5);
		//hijo2->rota(-90, 1, 0, 0);
		//hijo2->escala (2,2,2);
		this->introduceObjeto(hijo2);
/*
	tronco=gluNewQuadric();
	copa=gluNewQuadric();

	gluQuadricDrawStyle(tronco,GLU_FILL);
	gluQuadricDrawStyle(copa,GLU_FILL);
*/
}
/*
Roble::~Roble()
{
	gluDeleteQuadric(tronco);
	gluDeleteQuadric(copa);
}

void Roble::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//--------------------------------------------------- tronco
	glPushMatrix();
	glTranslatef(-7.5, 0, 7.5);
	glRotatef(-90, 1, 0, 0);
	glColor3f( 0.5, 0.2, 0.0);
	gluCylinder(tronco, 0.8, 0.3, 6, 20, 20);
	glPopMatrix();
	//--------------------------------------------------- copa
	glPushMatrix();
	glTranslatef(-7.5, 7, 7.5);
	glColor3f(0.0, 0.8, 0.0);
	gluSphere(copa, 1.6, 200, 200);
	glPopMatrix(); 
	

}
*/

void Roble::especularInc() {
	if (this->esp[0] < 2.0) {
	 this->esp[0] += 0.1;
	 this->esp[1] += 0.1;
	 this->esp[2] += 0.1;
	 glLightfv(GL_LIGHT5, GL_SPECULAR, this->esp);
	}
}

void Roble::especularDes() {
	if (this->esp[0] > 0.0) {
	 this->esp[0] -= 0.1;
	 this->esp[1] -= 0.1;
	 this->esp[2] -= 0.1;
	 glLightfv(GL_LIGHT5, GL_SPECULAR, this->esp);
	}
}