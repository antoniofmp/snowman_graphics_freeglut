 
#include "Camara.h"
#define PI 3.14159265358979323846

//float PI= 3.14159265358979323846;

Camara::Camara() {           
	eye=new PuntoVector3D(30, 30, 30, 1);
    look=new PuntoVector3D(0, 0, 0, 1);
    up=new PuntoVector3D(0, 1, 0, 0);
       
    left=-10; right=-left; bottom=-10; top=-bottom; 
	Near=1; Far=1000;
	fovy=5; aspect=2.5; 
	  
	setView();  
	setProjection(0);
	setCameraCoordinateSystem();		     
}

void Camara::setView() {
	//Define la matriz de vista con el comando gluLookAt()  
	glMatrixMode(GL_MODELVIEW);   // VIEW
	glLoadIdentity();
	gluLookAt(eye->getX(),eye->getY(),eye->getZ(),look->getX(),look->getY(),look->getZ(),up->getX(),up->getY(),up->getZ());
	//TO DO	 
}

void Camara::setCameraCoordinateSystem() {
	//Obtiene el valor de los vectores u, v, n 
	n = new PuntoVector3D(eye->getX()-look->getX(),eye->getY()-look->getY(),eye->getZ()-look->getZ(),0);
	n->normalizar();
	u = up->productoVectorial(n);
	u->normalizar();
	v = n->productoVectorial(u);	
	//TO DO	 
}

void Camara::setProjection(int i) {
	//Define la matriz de proyección con el comando 
	//glOrtho() o glFrustum()/gluPerspective()
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
		switch(i){
			case 0: glOrtho(left,right,bottom,top,Near,Far);
				break;
			case 1: gluPerspective(fovy,aspect,Near,Far);
				break;   
        }
	//TO DO		 
}

void Camara::setModelViewMatrix() {
    glMatrixMode(GL_MODELVIEW);		 
    GLfloat m[16];  
    m[0]=u->getX(); m[4]=u->getY(); m[8]=u->getZ(); m[12]=-eye->productoEscalar(u);
    m[1]=v->getX(); m[5]=v->getY(); m[9]=v->getZ(); m[13]=-eye->productoEscalar(v);
    m[2]=n->getX(); m[6]=n->getY(); m[10]=n->getZ(); m[14]=-eye->productoEscalar(n);
    m[3]=0; m[7]=0; m[11]=0; m[15]=1;
    glLoadMatrixf(m); 
}
//---------------------------------------------------------------------------------gira la camara en X
void Camara::giraX(int i) {
	//Gira la cámara alrededor del eje X sobre un plano perpendicular a este eje
	//TO DO	 
	float inc = PI/16;
	float eyeX = eye->getX();
	float eyeY = eye->getY();
	float eyeZ = eye->getZ();
	float radio = 30;
	eye->setY(radio*cos(2* PI - i*inc));
	eye->setZ(radio*sin(2* PI - i*inc));
    setView();
    setCameraCoordinateSystem();     
}
//---------------------------------------------------------------------------------gira la camara en Y
void Camara::giraY(int i) {
	//Gira la cámara alrededor del eje Y sobre un plano perpendicular a este eje
	//TO DO
	float inc = PI/16;
	float eyeX = eye->getX();
	float eyeY = eye->getY();
	float eyeZ = eye->getZ();
	float radio = 30;
	eye->setX(radio*cos(2* PI - i*inc));
	eye->setZ(radio*sin(2* PI - i*inc));
    setView();
    setCameraCoordinateSystem();    
}
//-----------------------------------------------------------------------gira en la camara en Z
void Camara::giraZ(int i) {
	//Gira la cámara alrededor del eje Z sobre un plano perpendicular a este eje
	//TO DO
	float inc =  PI/16;
	float eyeX = eye->getX();
	float eyeY = eye->getY();
	float eyeZ = eye->getZ();
	float radio = 30;
	eye->setX(radio*cos(2* PI - i*inc));
	eye->setY(radio*sin(2* PI - i*inc));
    setView();
    setCameraCoordinateSystem();    
}
//------------------------------------------------------------------------vista lateral en X
void Camara::lateral() {
	//Coloca la cámara de forma que se muestra una visión lateral 
	//de la escena (desde el eje X) 
	//TO DO
	eye->setX(100);
	eye->setY(0);
	eye->setZ(0);
	up->setX(0);
	up->setY(1);
	up->setZ(0);
	setView();
	setCameraCoordinateSystem();
}
//--------------------------------------------------------------------------vista frontal en Z
void Camara::frontal() {
	//Coloca la cámara de forma que se muestra una visión frontal 
	//de la escena (desde el eje Z) 
	//TO DO
	eye->setX(0);
	eye->setY(0);
	eye->setZ(100);
	up->setX(0);
	up->setY(1);
	up->setZ(0);
	setView();
	setCameraCoordinateSystem();
}
//---------------------------------------------------------------------------------vista cenital es desde Y
void Camara::cenital() {
    //Coloca la cámara de forma que se muestra una visión cenital 
	//de la escena (desde el eje Y) 
	//TO DO
	eye->setX(0);
	eye->setY(100);
	eye->setZ(0);
	up->setX(1);
	up->setY(0);
	up->setZ(0);
	setView();
	setCameraCoordinateSystem();
}
//---------------------------------------------------------------------------vista de rincon que saca toda la escena
void Camara::rincon() {
    //Coloca la cámara de forma que se muestra
	//la escena en un rincón
	//TO DO
	eye->setX(30);
	eye->setY(30);
	eye->setZ(30);
	up->setX(0);
	up->setY(1);
	up->setZ(0);
	setView();
	setCameraCoordinateSystem();
}
 //---------------------------------------------------------------------------giro en roll
void Camara::roll(float ang) {
	//Rota la cámara tal como se explica en las transparencias
	//TO DO	
	float s = sin(ang);
	float c = cos(ang);
	PuntoVector3D* nU = u->productoNumero(c)->sumarVectores(v->productoNumero(s));
	PuntoVector3D* nV = u->productoNumero(-s)->sumarVectores(v->productoNumero(c));
	u->setX(nU->getX());
	u->setY(nU->getY());
	u->setZ(nU->getZ());
	v->setX(nV->getX());
	v->setY(nV->getY());
	v->setZ(nV->getZ());
	setModelViewMatrix();
}
//----------------------------------------------------------------------------------giro en yaw
void Camara::yaw(float ang) {		
    //TO DO
	float s = sin(ang);
	float c = cos(ang);
	PuntoVector3D* nU = u->productoNumero(c)->sumarVectores(n->productoNumero(-s));
	PuntoVector3D* nN = u->productoNumero(s)->sumarVectores(n->productoNumero(c));
	u->setX(nU->getX());
	u->setY(nU->getY());
	u->setZ(nU->getZ());
	n->setX(nN->getX());
	n->setY(nN->getY());
	n->setZ(nN->getZ());
	setModelViewMatrix();
}
//----------------------------------------------------------------------------------giro en pitch
void Camara::pitch(float ang) {		
    //TO DO
	float s = sin(ang);
	float c = cos(ang);
	PuntoVector3D* nV = n->productoNumero(s)->sumarVectores(v->productoNumero(c));
	PuntoVector3D* nN = n->productoNumero(c)->sumarVectores(v->productoNumero(-s));
	n->setX(nN->getX());
	n->setY(nN->getY());
	n->setZ(nN->getZ());
	v->setX(nV->getX());
	v->setY(nV->getY());
	v->setZ(nV->getZ());
	setModelViewMatrix();
}


