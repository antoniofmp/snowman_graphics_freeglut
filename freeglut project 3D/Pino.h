#include <Windows.h>
#include <GL/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "ObjetoCompuesto.h"

class Pino : public ObjetoCompuesto{
	public:
	// objetos para la construccion del pino
	// constructor y destructor del pino
		Pino();
		~Pino();
};