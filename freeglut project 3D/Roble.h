#include <Windows.h>
#include <GL/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "ObjetoCompuesto.h"

class Roble : public ObjetoCompuesto{
        public:
// objetos para la construccion del roble
			//GLUquadricObj* tronco;
			//GLUquadricObj* copa;
// constructor y destructor del roble
                Roble();
                ~Roble();
				GLfloat esp[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
				
			  //void dibuja();
				void especularInc();
				void especularDes();

        private:     
};