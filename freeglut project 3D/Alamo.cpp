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
		this->introduceObjeto(hijo1);

//--------------------------------------------------------------------------------------- hijo 2 tallo
		Objeto3D* hijo2= new tallo();
		hijo2->traslada(-6.5, 0, -4.5);
		this->introduceObjeto(hijo2);

//--------------------------------------------------------------------------------------- hijo 3 copa
		Objeto3D* hijo3= new copa2();
		hijo3->traslada(-7.5, 6, -3.5);
		this->introduceObjeto(hijo3);
}