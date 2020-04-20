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
		this->introduceObjeto(hijo1);
//-----------------------------------------------------------------------------------hijo 2 tallo
		Objeto3D* hijo2= new tallo();
		hijo2->traslada(7.5, 0, 7.5);
		this->introduceObjeto(hijo2);
}