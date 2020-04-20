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
	this->introduceObjeto(hijo1);

//-----------------------------------------------------------------------------------hijo 1 copa cono
	Objeto3D* hijo2= new copa();
	hijo2->traslada(7.5, 4, -7.5);
	this->introduceObjeto(hijo2);

//-----------------------------------------------------------------------------------hijo 3 copa cono
	Objeto3D* hijo3= new copa();
	hijo3->traslada(7.5, 6, -7.5);
	this->introduceObjeto(hijo3);
}