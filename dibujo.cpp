#include "figura_class.cpp"

//#include "chair.cpp"
#include "umbrella.cpp"


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX,transY,transZ);
	glRotatef(angleY,0.0f,1.0f,0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glRotatef(angleZ, 0.0f, 0.0, 1.0);


	figura cube( coord_umbrella, quads_umbrella, trng_umbrella);

	//cube.cloudPoints();

	glScalef(0.1,0.1,0.1);
	cube.mesh();


  											
  glutSwapBuffers ( );
}