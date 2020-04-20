#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>
//#include <GL/glut.h>
#include <iostream>
#include "Abeto.h"
#include "Alamo.h"
#include "Pino.h"
#include "Roble.h"
#include "Camara.h"
#include "Esfera.h"
#include "farol.h"
#include "Polos.h"
#include "Luz.h"
#include "Rueda.h"
#include "Coche.h"
#include "ObjetoCompuesto.h"
#include "Objeto3D.h"

using namespace std;

//tipos de arboles
Abeto* abeto;
Alamo* alamo;
Pino* pino;
Roble* roble;
Esfera* esfera;
Farol* farol;
Polos* polos;
Luz* luz;
Rueda* rueda;
Coche* coche;

//------------------------------------------------variables para la scene o escena
ObjetoCompuesto* objeto = new ObjetoCompuesto();//-----------------------------------------------para objeto compuesto
Camara* camara;
int gx, gy, gz;
GLfloat angX, angY, angZ;
GLfloat anguloX, anguloY, anguloZ, s31, s32, s33; //----para movimiento
GLfloat d2[] = { anguloX, anguloY, anguloZ, 1.0f };
int mode;
boolean embaldosado;
int rInt = 5; //radio interior
int rExt = 10; //radio exterior
int h = 4; //altura

		   //------------------luces
GLfloat a[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat p2[] = { 55.0f, 0.0f, 0.0f, 1.0f }; //POSITION
GLfloat s2[] = { 1.0f, 0.0f, 1.0f };
GLfloat a2[] = { 1.0f, 1.0f, 1.0f, 1.0f }; //GL_DIFFUSE
GLfloat dir[] = { 0.0, 0.0, -5.0 };
GLfloat ap[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat s3[] = { s31, s32, s33, 1.0f };
GLfloat p3[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat spot_direction[] = { -1.0, 0.0, 0.0 };
GLfloat a4[] = { 0.3f, 0.3f, 0.3f, 1.0f };

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH = 500, HEIGHT = 500;
double scale = 1;

// Viewing frustum parameters
GLdouble xRight = 10, xLeft = -xRight, yTop = 10, yBot = -yTop, N = 1, F = 1000;

// Camera parameters
GLdouble eyeX = 100.0, eyeY = 100.0, eyeZ = 100.0;
GLdouble lookX = 0.0, lookY = 0.0, lookZ = 0.0;
GLdouble upX = 0, upY = 1, upZ = 0;

// Scene variables

void buildSceneObjects() {
	angX = 0.0f;
	angY = 0.0f;
	angZ = 0.0f;
	anguloX = 2.0f;
	anguloY = 3.0f;
	anguloZ = 4.0f;
	// tipos de arboles
	abeto = new Abeto();
	alamo = new Alamo();
	pino = new Pino();
	roble = new Roble();
	esfera = new Esfera();
	farol = new Farol();
	luz = new Luz();
	rueda = new Rueda();
	coche = new Coche();

	polos = new Polos(rInt, rExt, h);
	gx = 0;
	gy = 0;
	gz = 0;
	camara = new Camara();
	mode = 0;
	embaldosado = false;
}

void initGL() {
	glClearColor(0.6f, 0.7f, 0.8f, 1.0);

	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.9f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH); // Shading by default

	buildSceneObjects();

	GLfloat lmodel_ambient[] = { 0, 0, 0, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glEnable(GL_LIGHTING);

	//luz ambiente global
	GLfloat d[] = { 0.7f, 0.5f, 0.5f, 1.0f };
	GLfloat a[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat s[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat p[] = { 25.0f, 25.0f, -25.0f, 1.0f };

	//luz farola
	GLfloat p1[] = { -6.0f, 3.0f, -10.0f, 1.0f };
	glLightfv(GL_LIGHT1, GL_POSITION, p1);
	GLfloat d1[] = { 1.0f, 0.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, d1);
	GLfloat a1[] = { 0.3f, 0.0f, 0.3f, 1.0f };
	glLightfv(GL_LIGHT1, GL_AMBIENT, a1);
	GLfloat s1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT1, GL_SPECULAR, s1);

	//componente especular

	glEnable(GL_LIGHT5);

	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	// Frustum set up
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(xLeft, xRight, yBot, yTop, N, F);

	// Viewport set up
	glViewport(0, 0, WIDTH, HEIGHT);
}

void dibujarP() {
	//luz 45º
	GLfloat d2[] = { 0.0f, 1.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT2, GL_DIFFUSE, d2);
	GLfloat a2[] = { 0.4f, 0.4f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT2, GL_AMBIENT, a2);
	GLfloat p2[] = { 10.0f, 10.0f, 0.0f, 0.0f };
	glLightfv(GL_LIGHT2, GL_POSITION, p2);
	GLfloat s2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT2, GL_SPECULAR, s2);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 180.0);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);

	// Rotating the scene
	glRotatef(angX, 1.0f, 0.0f, 0.0f);
	glRotatef(angY, 0.0f, 1.0f, 0.0f);
	glRotatef(angZ, 0.0f, 0.0f, 1.0f);

	glLineWidth(1.5f);
	// Drawing axes
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(20, 0, 0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 20, 0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 20);
	glEnd();
	//--------------------------------------------------------------------------------------------dibuja los arboles y objetos

	glPushMatrix();
	abeto->dibuja();
	alamo->dibuja();
	pino->dibuja();
	roble->dibuja2();
	esfera->dibuja();
	farol->dibuja();
	glPushMatrix();
	glTranslatef(anguloX, 0.0f, 0.0f);
	coche->dibuja();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-8.0, 0.0, 0.0);
	glTranslatef(anguloX, 0.0f, 0.0f);
	polos->dibuja();
	glPopMatrix();
	glPopMatrix();
}

//--------------------------------------------------------------------metodo para embaldosar las 4 camaras
void embaldosar(int nCol) {
	GLdouble SVAratio = (xRight - xLeft) / (yTop - yBot);
	GLdouble w = (GLdouble)WIDTH / (GLdouble)nCol;
	GLdouble h = w / SVAratio;
	//--------------------------------------------------------------------------camara lateral	
	glViewport((GLint)(0), (GLint)0, (GLint)w, (GLint)h);
	glColor3f(1.0, 1.0, 1.0);
	camara->lateral();
	dibujarP();
	//--------------------------------------------------------------------------camara frontal
	glViewport((GLint)(0), (GLint)h, (GLint)w, (GLint)h);
	glColor3f(1.0, 1.0, 1.0);
	camara->frontal();
	dibujarP();
	//--------------------------------------------------------------------------camara cenital
	glViewport((GLint)(w), (GLint)0, (GLint)w, (GLint)h);
	glColor3f(1.0, 1.0, 1.0);
	camara->cenital();
	dibujarP();
	//--------------------------------------------------------------------------camara rincon
	glViewport((GLint)(w), (GLint)h, (GLint)w, (GLint)h);
	glColor3f(1.0, 1.0, 1.0);
	camara->rincon();
	dibujarP();
}
//-------------------------------------------------------------------------fin de la funcion para embaldosar
//------------------------------------------------------------------------- funcion para desembaldosar
void desembaldosar() {
	glViewport(0, 0, WIDTH, HEIGHT);
}
//------------------------------------------------se usa un nuevo display para dibujar lo de arriba de dibujar
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	if (embaldosado) embaldosar(2); //-----------------------------------para usar el modo embaldosar
	else {
		dibujarP();
	}

	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}


void resize(int newWidth, int newHeight) {
	WIDTH = newWidth;
	HEIGHT = newHeight;
	GLdouble RatioViewPort = (float)WIDTH / (float)HEIGHT;
	glViewport(0, 0, WIDTH, HEIGHT);

	GLdouble SVAWidth = xRight - xLeft;
	GLdouble SVAHeight = yTop - yBot;
	GLdouble SVARatio = SVAWidth / SVAHeight;
	if (SVARatio >= RatioViewPort) {
		GLdouble newHeight = SVAWidth / RatioViewPort;
		GLdouble yMiddle = (yBot + yTop) / 2.0;
		yTop = yMiddle + newHeight / 2.0;
		yBot = yMiddle - newHeight / 2.0;
	}
	else {
		GLdouble newWidth = SVAHeight*RatioViewPort;
		GLdouble xMiddle = (xLeft + xRight) / 2.0;
		xRight = (xMiddle + newWidth / 2.0);
		xLeft = xMiddle - newWidth / 2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(xLeft / scale, xRight / scale, yBot / scale, yTop / scale, N, F);
}

void key(unsigned char key, int x, int y) {
	bool need_redisplay = true;
	switch (key) {
	case 27:  /* Escape key */
			  //continue_in_main_loop = false; // (**)
			  //Freeglut's sentence for stopping glut's main loop (*)
		glutLeaveMainLoop();
		break;
		//------------------------------------------------------------------------------------//para los zoom
	case 'i': scale += 0.05; resize(WIDTH, HEIGHT); break;
	case 'k': scale -= 0.05; resize(WIDTH, HEIGHT); break;
		//---------------------------------------------
	case 'n': anguloX = anguloX + 5; break;
	case 'm': anguloX = anguloX - 5; break;
	case 'a': angX = angX + 5; break;
	case 'z': angX = angX - 5; break;
	case 's': angY = angY + 5; break;
	case 'x': angY = angY - 5; break;
	case 'd': angZ = angZ + 5; break;
	case 'c': angZ = angZ - 5; break;
	case '1': camara->giraX(gx); gx++; break;
	case '2': camara->giraY(gy); gy++; break;
	case '3': camara->giraZ(gz); gz++; break;
	case '4': camara->lateral(); break;
	case '5': camara->frontal(); break;
	case '6': camara->cenital(); break;
	case '7': camara->rincon(); break;
	case 'p': mode = (mode + 1) % 2;
		camara->setProjection(mode);
		// camara->setView();
		break;

	case 'q':  camara->roll(0.1); break;
	case 'w':  camara->yaw(0.1); break;
	case 'e':  camara->pitch(0.1); break;
	case '8':  embaldosado = true; break;
	case '9':  embaldosado = false; desembaldosar(); break;
		//------------------------------luces

	case 'r':
		glEnable(GL_LIGHT1);
		break;
	case 'f':
		glDisable(GL_LIGHT1);
		break;
	case 't':
		glEnable(GL_LIGHT3);
		glEnable(GL_LIGHT4);
		break;
	case 'g':
		glDisable(GL_LIGHT3);
		glDisable(GL_LIGHT4);
		break;
	case 'y':
		glEnable(GL_LIGHT2);
		break;
	case 'h':
		glDisable(GL_LIGHT2);
		break;
	case 'u':
		glEnable(GL_LIGHT0);
		break;
	case 'j':
		glDisable(GL_LIGHT0);
		break;
	case 'l':
		roble->especularInc();
		break;
	case 'o':
		roble->especularDes();
		break;

	default:
		need_redisplay = false;
		break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]) {
	cout << "Starting console..." << endl;

	int my_window; // my window's identifier

				   // Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	//glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Freeglut 3D-project");

	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop();

	// We would never reach this point using classic glut
	system("PAUSE");

	return 0;
}
