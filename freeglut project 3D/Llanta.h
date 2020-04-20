#include <GL/glut.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Objeto3D.h"


class Llanta : public Objeto3D{
        public:
			GLUquadricObj* llanta1; //objeto para el tronco
			
//constructor y destructor
			Llanta();
			~Llanta();
			  void dibuja(); // para dibujar en el main.cpp

        private: 
           


};