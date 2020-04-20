#include <iostream>
#include <fstream>
#include "Abeto.h"
#include "copa.h"
#include "tallo.h"

using namespace std;

Abeto::Abeto()
{
//-----------------------------------------------------------------------------------hijo 1 copa cono
	Objeto3D* hijo1= new copa();
		hijo1->traslada(7.5, 5, 7.5);
		//hijo1->rota(-90, 1, 0, 0);
		//hijo1->escala (2,2,2);
		this->introduceObjeto(hijo1);
//-----------------------------------------------------------------------------------hijo 2 tallo
		Objeto3D* hijo2= new tallo();
		hijo2->traslada(7.5, 0, 7.5);
		//hijo2->rota(-90, 1, 0, 0);
		//hijo2->escala (2,2,2);
		this->introduceObjeto(hijo2);
		//objeto->dibuja();



	//tronco=gluNewQuadric();
	//copa=gluNewQuadric();

	//gluQuadricDrawStyle(tronco,GLU_FILL);
	//gluQuadricDrawStyle(copa,GLU_FILL);


}

Abeto::~Abeto()
{
	//gluDeleteQuadric(tronco);
	//gluDeleteQuadric(copa);
}
/*
void Abeto::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//--------------------------------------------------- tronco
	glPushMatrix();
	glTranslatef(7.5, 0, 7.5);
	glRotatef(-90, 1, 0, 0);
	glColor3f( 0.5, 0.2, 0.0);
	gluCylinder(tronco, 0.8, 0.4, 5, 40, 40);
	glPopMatrix();
	//--------------------------------------------------- copa
	glPushMatrix();
	glTranslatef(7.5, 5, 7.5);
	glRotatef(-90, 1, 0, 0);
	glColor3f( 0.0, 0.8, 0.0);
	gluCylinder(copa, 1.5, 0, 5, 40, 40);
	glPopMatrix(); 

}
*/