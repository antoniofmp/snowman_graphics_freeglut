#include "Malla.h"
#include <GL/glut.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Objeto3D.h"
#include "Malla.h"

class Polos : public Malla{
	private:
	//int m; //numero de puntos en el perfil original
	PuntoVector3D** perfil; //perfil original en el plano XY
	
	//int nQ; //numero de rotaciones
	int rInt;
	int rExt;
	int h;
	//PuntoVector3D* CalculoVectorNormal(Cara* c); //------------------------------DESCOMENTAR PARA CALCULO NORMAL
        public:
                Polos(int rInt, int rExt, int h);
                ~Polos();
				PuntoVector3D* CalculoVectorNormalPorNewell(Cara* c);
				void dibuja();
};