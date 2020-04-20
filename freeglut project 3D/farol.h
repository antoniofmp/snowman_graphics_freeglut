#include <Windows.h>
#include <GL/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Objeto3D.h"

class Farol  : public Objeto3D
{
	public:
		// objetos para la construccion del roble
		GLUquadricObj* tuvo;
		GLUquadricObj* lampara;
		// constructor y destructor del roble
		Farol();
		~Farol();
   void dibuja();
};