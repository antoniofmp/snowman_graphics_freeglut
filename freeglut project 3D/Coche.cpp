#include <iostream>
#include <fstream>
#include "Coche.h"
#include "Polos.h"
#include "Luz.h"
#include "Rueda.h"


using namespace std;

Coche::Coche()
{
	//----------------------------------------------------------------------------------- hijo 1 polos cubo del coche
	//Objeto3D* hijo1= new Polos(rInt, rExt, h);
		//hijo1->traslada(-7.5 , 0.0 , 0.0);
		//hijo1->rota(-90, 1, 0, 0);
		//hijo1->escala (2,2,2);
		//this->introduceObjeto(hijo1);

//--------------------------------------------------------------------------------------- hijo 2 luz derecha
	Objeto3D* hijo2= new Luz();
		hijo2->traslada(2.5, 2.5, -1.5);
		//hijo2->rota(-90, 1, 0, 0);
		//hijo2->escala (2,2,2);
		this->introduceObjeto(hijo2);

//--------------------------------------------------------------------------------------- hijo 3 luz izquierda
	Objeto3D* hijo3= new Luz();
		hijo3->traslada(2.5, 2.5, 1.5);
		//hijo3->rota(-90, 1, 0, 0);
		//hijo3->escala (2,2,2);
		this->introduceObjeto(hijo3);

//--------------------------------------------------------------------------------------- hijo 4 rueda traseda I
		Objeto3D* hijo4= new Rueda();
		hijo4->traslada(-2.5, 0, 3.5);
		hijo4->rota(-180, 1, 0, 0);
		//hijo4->escala (2,2,2);
		this->introduceObjeto(hijo4);

//--------------------------------------------------------------------------------------- hijo 5 rueda delantera I
		Objeto3D* hijo5= new Rueda();
		hijo5->traslada(2.5, 0, 3.5);
		hijo5->rota(-180, 1, 0, 0);
		//hijo5->escala (2,2,2);
		this->introduceObjeto(hijo5);

//--------------------------------------------------------------------------------------- hijo 6 rueda trasera D
		Objeto3D* hijo6= new Rueda();
		hijo6->traslada(-2.5, 0, -3.5);
		//hijo6->rota(-90, 1, 0, 0);
		//hijo6->escala (2,2,2);
		this->introduceObjeto(hijo6);

//--------------------------------------------------------------------------------------- hijo 7 rueda delantera D
		Objeto3D* hijo7= new Rueda();
		hijo7->traslada(2.5, 0, -3.5);
		//hijo7->rota(-90, 1, 0, 0);
		//hijo7->escala (2,2,2);
		this->introduceObjeto(hijo7);

	
}