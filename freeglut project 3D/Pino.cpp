#include <iostream>
#include <fstream>
#include "Pino.h"
#include "copa.h"
#include "tallo.h"


using namespace std;

Pino::Pino()
{
//-----------------------------------------------------------------------------------hijo 2 tallo
		Objeto3D* hijo1= new tallo();
		hijo1->traslada(7.5, 0, -7.5);
		//hijo1->rota(-90, 1, 0, 0);
		//hijo1->escala (2,2,2);
		this->introduceObjeto(hijo1);

//-----------------------------------------------------------------------------------hijo 1 copa cono
	Objeto3D* hijo2= new copa();
		hijo2->traslada(7.5, 4, -7.5);
		//hijo2->rota(-90, 1, 0, 0);
		//hijo2->escala (2,2,2);
		this->introduceObjeto(hijo2);



//-----------------------------------------------------------------------------------hijo 3 copa cono
	Objeto3D* hijo3= new copa();
		hijo3->traslada(7.5, 6, -7.5);
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
/*
Pino::~Pino()
{
	gluDeleteQuadric(tronco);
	gluDeleteQuadric(copa);
	gluDeleteQuadric(copa2);
}

void Pino::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//--------------------------------------------------- tronco
	glPushMatrix();
	glTranslatef(7.5, -3, -7.5);
	glRotatef(-90, 1, 0, 0);
	glColor3f( 0.5, 0.2, 0.0);
	gluCylinder(tronco, 0.8, 0.4, 7, 40, 40);
	glPopMatrix();
	//--------------------------------------------------- copa
	glPushMatrix();
	glTranslatef(7.5, 4, -7.5);
	glRotatef(-90, 1, 0, 0);
	glColor3f( 0.0, 0.8, 0.0);
	gluCylinder(copa, 1.5, 0.8, 2, 40, 40);
	glPopMatrix();
	//--------------------------------------------------- copa2
	glPushMatrix();
	glTranslatef(7.5, 6, -7.5);
	glRotatef(-90, 1, 0, 0);
	glColor3f( 0.0, 0.8, 0.0);
	gluCylinder(copa2, 1.5, 0, 5, 40, 40);
	glPopMatrix(); 


}
*/