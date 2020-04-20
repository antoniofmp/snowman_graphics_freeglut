#include <Windows.h>
#include <GL/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Objeto3D.h"


class tallo: public Objeto3D {
        public:
			GLUquadricObj* tronco; //objeto para el tronco
			//GLUquadricObj* copa1; //objeto para la copa
//constructor y destructor
			tallo();
			~tallo();
			  void dibuja(); // para dibujar en el main.cpp

        private: 
           


};