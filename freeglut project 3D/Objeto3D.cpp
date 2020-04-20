
#include "Objeto3D.h"

Objeto3D:: Objeto3D() { 	 
    matriz = new TAfin();
}

 
Objeto3D:: ~Objeto3D() {
    delete matriz;
}

GLfloat* Objeto3D:: dameMatrizAfin() {
	return matriz->dameMatrizModelado();
}

void Objeto3D:: traslada(GLfloat fX,GLfloat fY,GLfloat fZ) {
	matriz->traslada(fX,fY, fZ);
}

void Objeto3D:: escala(GLfloat fX,GLfloat fY,GLfloat fZ) {
	matriz->escala(fX,fY, fZ);
}

void Objeto3D:: rota(GLfloat alfa,GLfloat fX,GLfloat fY,GLfloat fZ) {
	matriz->rota (alfa,fX,fY,fZ);
}

void Objeto3D:: mover(GLfloat fX,GLfloat fY,GLfloat fZ) {
	matriz->mover (fX,fY,fZ);
}

