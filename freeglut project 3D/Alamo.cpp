#include <iostream>
#include <fstream>
#include "Alamo.h"
#include "tallo.h"
#include "copa2.h"


using namespace std;

Alamo::Alamo()
{
	//----------------------------------------------------------------------------------- hijo 1 copa cono
	Objeto3D* hijo1= new copa2();
		hijo1->traslada(-5.5, 6, -5);
		//hijo1->rota(-90, 1, 0, 0);
		//hijo1->escala (2,2,2);
		this->introduceObjeto(hijo1);

//--------------------------------------------------------------------------------------- hijo 2 tallo
		Objeto3D* hijo2= new tallo();
		hijo2->traslada(-6.5, 0, -4.5);
		//hijo2->rota(-90, 1, 0, 0);
		//hijo2->escala (2,2,2);
		this->introduceObjeto(hijo2);

//--------------------------------------------------------------------------------------- hijo 3 copa
		Objeto3D* hijo3= new copa2();
		hijo3->traslada(-7.5, 6, -3.5);
		//hijo3->rota(-90, 1, 0, 0);
		//hijo3->escala (2,2,2);
		this->introduceObjeto(hijo3);


/*
	tronco=gluNewQuadric();
	copa=gluNewQuadric();
	copa2=gluNewQuadric();

	gluQuadricDrawStyle(tronco,GLU_FILL);
	gluQuadricDrawStyle(copa,GLU_FILL);
	gluQuadricDrawStyle(copa2,GLU_FILL);
	*/

}

Alamo::~Alamo()
{
/*
	gluDeleteQuadric(tronco);
	gluDeleteQuadric(copa);
	gluDeleteQuadric(copa2);
*/
}
/*
void Alamo::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//--------------------------------------------------- tronco
	glPushMatrix();
	glTranslatef(-6.5, -3, -4.5);
	glRotatef(-90, 1, 0, 0);
	glColor3f(0.5, 0.2, 0.0);
	gluCylinder(tronco, 0.8, 0.4, 7.2, 40, 40);
	glPopMatrix();
	//--------------------------------------------------- copa
	glPushMatrix();
	glTranslatef(-5.5, 4, -5);
	glColor3f(0.0, 0.8, 0.0);
	gluSphere(copa, 1.6, 200, 200);
	glPopMatrix();
	//--------------------------------------------------- copa2
	glPushMatrix();
	glTranslatef(-7.5, 4, -3.5);
	glColor3f(0.0, 0.8, 0.0);
	gluSphere(copa2, 1.8, 200, 200);
	glPopMatrix(); 
	

}
*/