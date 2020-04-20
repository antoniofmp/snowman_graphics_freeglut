
#include "TAfin.h"
#include <math.h>

TAfin:: TAfin() {
	m = new GLfloat[16];
	
	for(int i=0; i<16;i++){
		m[i]=0;
	}
	m[0]=1;
	m[5]=1;
	m[10]=1;
	m[15]=1;
}

TAfin:: ~TAfin() {
	delete[] m;
}

GLfloat* TAfin::dameMatrizModelado() {
	return m;
}

void TAfin:: traslada(GLfloat X, GLfloat Y, GLfloat Z) {   
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(X,Y,Z);
	GLfloat* mm = new GLfloat[16];
	//Dejar la matriz actual de modelado‐vista en m1
	//Los 16 datos están enumerados por columnas
	glGetFloatv(GL_MODELVIEW_MATRIX, mm);
	glPopMatrix();
	postMultiplica(mm);
}

void TAfin:: escala(GLfloat fX, GLfloat fY, GLfloat fZ) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glScalef(fX,fY,fZ);
	GLfloat* mm = new GLfloat[16];
	glGetFloatv(GL_MODELVIEW_MATRIX,mm);
	glPopMatrix();
	postMultiplica(mm);
}

void TAfin:: rota(GLfloat alfa, GLfloat fX, GLfloat fY, GLfloat fZ) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRotatef(alfa,fX,fY,fZ);
	GLfloat* mm = new GLfloat[16];
	glGetFloatv(GL_MODELVIEW_MATRIX,mm);
	glPopMatrix();
	postMultiplica(mm);
}

void TAfin:: mover(GLfloat X, GLfloat Y, GLfloat Z) {   
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(X,Y,Z);
	GLfloat* mm = new GLfloat[16];
	
	//Dejar la matriz actual de modelado‐vista en m1
	//Los 16 datos están enumerados por columnas
	glGetFloatv(GL_MODELVIEW_MATRIX, mm);
	glPopMatrix();
	postMultiplica(mm);
}

void TAfin:: postMultiplica(GLfloat* mm) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	//Cargar m como matriz actual de modelado‐vista
	glLoadMatrixf(m);
	//Post‐multiplicar por m1
	glMultMatrixf(mm);
	//Dejar el resultado en m
	//GLfloat* m = new GLfloat[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, m);
	glPopMatrix();
}