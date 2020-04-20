#include "Objeto3D.h"

class copa: public Objeto3D {
        public:
			//GLUquadricObj* tronco; //objeto para el tronco
			GLUquadricObj* copa1; //objeto para la copa
//constructor y destructor
                copa();
                ~copa();
			  void dibuja(); // para dibujar en el main.cpp

        private: 
           


};