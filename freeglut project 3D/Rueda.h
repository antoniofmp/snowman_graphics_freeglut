#include <GL/glut.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "ObjetoCompuesto.h"

class Rueda : public ObjetoCompuesto{
	public:
		//constructor y destructor
		Rueda();
		~Rueda();
};