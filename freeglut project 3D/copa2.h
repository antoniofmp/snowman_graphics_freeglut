#include <Windows.h>
#include <GL/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Objeto3D.h"


class copa2 : public Objeto3D{
        public:
//objetos para el tronco y las copas
			//GLUquadricObj* tronco;
			//GLUquadricObj* copa;
			GLUquadricObj* copaup;

//constructor y destructor
			copa2();
			~copa2();
			 void dibuja();

        private:     
           


};