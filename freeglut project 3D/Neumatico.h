#include <GL/glut.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Objeto3D.h"

class Neumatico : public Objeto3D{
	public:
		GLUquadricObj* Neumatico1; //objeto para el tronco
			
		//constructor y destructor
		Neumatico();
		~Neumatico();
	void dibuja(); // para dibujar en el main.cpp
};