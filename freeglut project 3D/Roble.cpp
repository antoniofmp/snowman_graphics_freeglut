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
	this->introduceObjeto(hijo1);

//--------------------------------------------------------------------------------------- hijo 2 tallo
	Objeto3D* hijo2= new tallo();
	hijo2->traslada(-7.5, 0, 7.5);
	this->introduceObjeto(hijo2);
}

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