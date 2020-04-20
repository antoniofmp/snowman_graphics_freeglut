#include <Windows.h>
#include <GL/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Objeto3D.h"


class tallo: public Objeto3D {
	public:
		GLUquadricObj* tronco; //objeto para el tronco
			//constructor y destructor
		tallo();
		~tallo();
    void dibuja();
};