#include "figura_class.cpp"

#include "cubo.cpp"
#include "toilet_.cpp"
#include "hellboy.cpp"


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX,transY,transZ);
	glRotatef(angleY,0.0f,1.0f,0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glRotatef(angleZ, 0.0f, 0.0, 1.0);


	figura cube(coo_hellboy, fac_hellboy);
	//cube.cloudPoints();
	cube.quads();


  											
  glutSwapBuffers ( );
}