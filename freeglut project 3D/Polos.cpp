#include "Polos.h"
#include "PuntoVector3D.h"


Polos::Polos(int rInt, int rExt, int h):Malla()
{
	numeroVertices=6;//32
    vertice= new PuntoVector3D*[numeroVertices];
    //todos los polos empieza con la esquina inferior izquierda
    //polo rojo
	vertice[0]=new PuntoVector3D (rExt, 0, -2.5, 1);
	vertice[1]=new PuntoVector3D (rInt, 0, -2.5, 1);
	vertice[2]=new PuntoVector3D (rInt, h, -2.5, 1);
	vertice[3]=new PuntoVector3D (rExt, h, -2.5, 1);

	vertice[4]=new PuntoVector3D (rExt, 0, 2.5, 1);
	vertice[5]=new PuntoVector3D (rInt, 0, 2.5, 1);
	vertice[6]=new PuntoVector3D (rInt, h, 2.5, 1);
	vertice[7]=new PuntoVector3D (rExt, h, 2.5, 1);

	numeroCaras=6;//24
	cara= new Cara*[numeroCaras];
	//cubo polo rojo
	VerticeNormal** arrayCara0= new VerticeNormal*[4];
	arrayCara0[0]=new VerticeNormal(0,0);
	arrayCara0[1]=new VerticeNormal(1,0);
	arrayCara0[2]=new VerticeNormal(2,0);
	arrayCara0[3]=new VerticeNormal(3,0);
	cara[0]=new Cara(4,arrayCara0);

	VerticeNormal** arrayCara1= new VerticeNormal*[4];
	arrayCara1[0]=new VerticeNormal(4,1);
	arrayCara1[1]=new VerticeNormal(0,1);
	arrayCara1[2]=new VerticeNormal(3,1);
	arrayCara1[3]=new VerticeNormal(7,1);
	cara[1]=new Cara(4,arrayCara1);

	VerticeNormal** arrayCara2= new VerticeNormal*[4];
	arrayCara2[0]=new VerticeNormal(4,2);
	arrayCara2[1]=new VerticeNormal(7,2);
	arrayCara2[2]=new VerticeNormal(6,2);
	arrayCara2[3]=new VerticeNormal(5,2);
	cara[2]=new Cara(4,arrayCara2);

	VerticeNormal** arrayCara3= new VerticeNormal*[4];
	arrayCara3[0]=new VerticeNormal(1,3);
	arrayCara3[1]=new VerticeNormal(5,3);
	arrayCara3[2]=new VerticeNormal(6,3);
	arrayCara3[3]=new VerticeNormal(2,3);
	cara[3]=new Cara(4,arrayCara3);


	VerticeNormal** arrayCara4= new VerticeNormal*[4];
	arrayCara4[0]=new VerticeNormal(0,4);
	arrayCara4[1]=new VerticeNormal(1,4);
	arrayCara4[2]=new VerticeNormal(5,4);
	arrayCara4[3]=new VerticeNormal(4,4);
	cara[4]=new Cara(4,arrayCara4);

	VerticeNormal** arrayCara5= new VerticeNormal*[4];
	arrayCara5[0]=new VerticeNormal(3,5);
	arrayCara5[1]=new VerticeNormal(2,5);
	arrayCara5[2]=new VerticeNormal(6,5);
	arrayCara5[3]=new VerticeNormal(7,5);
	cara[5]=new Cara(4,arrayCara5);


	normal=new  PuntoVector3D*[numeroCaras];
	
    for(int i=0; i<this->numeroCaras;i++)
	{   
		//hallamos las normales por newell
		PuntoVector3D* normal2=this->CalculoVectorNormalPorNewell(cara[i]);
		normal[i]= normal2;
	}
}

PuntoVector3D* Polos::CalculoVectorNormalPorNewell(Cara* c)
{
	GLfloat x=0;
	GLfloat y=0;
	GLfloat z=0;
	PuntoVector3D* Vi;//vertice inicial
	PuntoVector3D* Vf;// vertice final
	for(int i=0;i<c->getNumeroVertices();i++)
	{
		int indicek= c->getIndiceVerticeK(i);
		Vi=vertice[indicek];
		int indicesig=c->getIndiceVerticeK((i+1) % c->getNumeroVertices());
		Vf=vertice[indicesig];

		x+=(Vi->getY() - Vf->getY())*
			(Vi->getZ() + Vf->getZ());

		y+=(Vi->getZ() - Vf->getZ())*
			(Vi->getX() + Vf->getX());

		z+=(Vi->getX() - Vf->getX())*
			(Vi->getY() + Vf->getY());
	}
	PuntoVector3D* Normal=new PuntoVector3D(x,y,z,0);
   
    return Normal;
}

void Polos::dibuja()

{
	int suma=0;
       for (int i=0; i<numeroCaras; i++)
       {
            glLineWidth(1.0);
		    if(suma<numeroCaras/4)
            glColor3f(1,0,1);

		    suma++;
		    glBegin(GL_POLYGON);
			
			for (int j=0; j<cara[i]->getNumeroVertices();j++)
			{
				int iN=cara[i]->getIndiceNormalK(j);
				int iV=cara[i]->getIndiceVerticeK(j);
				glNormal3f(normal[iN]->getX(),normal[iN]->getY(),normal[iN]->getZ());
				glVertex3f(vertice[iV]->getX(),vertice[iV]->getY(),vertice[iV]->getZ());
			}
			glEnd();
       }
}

