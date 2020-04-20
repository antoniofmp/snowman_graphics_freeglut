#include <GL/glut.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Objeto3D.h"

class Luz : public Objeto3D{
	public:
		GLUquadricObj* Foco; //objeto para el foco
			
		//constructor y destructor
		Luz();
		~Luz();
    void dibuja(); // para dibujar en el main.cpp
};