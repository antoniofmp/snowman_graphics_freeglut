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
	this->introduceObjeto(hijo1);

	//--------------------------------------------------------------------------------------- hijo 2 neumatico
	Objeto3D* hijo2= new Neumatico();
	this->introduceObjeto(hijo2);
}