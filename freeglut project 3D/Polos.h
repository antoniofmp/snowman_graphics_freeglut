#include "Malla.h"
#include <GL/glut.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Objeto3D.h"
#include "Malla.h"

class Polos : public Malla{
	private:
	PuntoVector3D** perfil; //perfil original en el plano XY
	
	int rInt;
	int rExt;
	int h;

	public:
		Polos(int rInt, int rExt, int h);
		~Polos();
		PuntoVector3D* CalculoVectorNormalPorNewell(Cara* c);
		void dibuja();
};