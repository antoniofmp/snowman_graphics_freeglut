 
#include "ObjetoCompuesto.h"

ObjetoCompuesto:: ObjetoCompuesto() {
	hijos = new Objeto3D*[1000000];
	numHijos = 0;
}

ObjetoCompuesto:: ~ObjetoCompuesto() {
	for(int i =0; i < numHijos; i++) {     
		delete hijos[i];
    }  
}

void ObjetoCompuesto::dibuja() {
	//To do
	for (int i = 0; i< numHijos; i++) {
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glMultMatrixf(hijos[i]->dameMatrizAfin());
		hijos[i]->dibuja();
		glPopMatrix();
	}
}

void ObjetoCompuesto::dibuja2() {
	//To do
	GLfloat previous_esp[4];
	GLfloat esp[4] = { 0.5f, 0.5f, 0.5f, 1.0f };

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	for (int i = 0; i< numHijos; i++) {
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glMultMatrixf(hijos[i]->dameMatrizAfin());

		// Si es copa, le ponemos la componente especular
		if (i == 0) {
			glGetMaterialfv(GL_FRONT, GL_SPECULAR, previous_esp); // Recuperamos la  especular previa, para despues volver a ponerla
			glMaterialfv(GL_FRONT, GL_SPECULAR, esp);
		}

		hijos[i]->dibuja();

		// Si es copa, recuperamos la especular previa 
		if (i == 0) {
			glMaterialfv(GL_FRONT, GL_SPECULAR, previous_esp);
		}

		glPopMatrix();
	}

	glPopMatrix();
}

void ObjetoCompuesto:: introduceObjeto(Objeto3D* objeto) {
	//To do
	hijos [numHijos]= objeto;
	numHijos++;
}




