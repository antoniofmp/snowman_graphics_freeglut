#include <Windows.h>
#include <GL/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "ObjetoCompuesto.h"

class Coche : public ObjetoCompuesto{
	public:
	//constructor y destructor
	Coche();
	~Coche();
};