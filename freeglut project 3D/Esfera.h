#include <Windows.h>
#include <GL/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

class Esfera 
{
	public:
		// objetos para la construccion del roble
		GLUquadricObj* tronco;
		GLUquadricObj* copa;
		// constructor y destructor del roble
		Esfera();
		~Esfera();
	void dibuja();
};