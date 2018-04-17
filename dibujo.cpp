
#include "rick.cpp"
#include "hellboy.cpp"
#include "chica.cpp"
#include "toilet.cpp"
#include "some_functions.cpp"

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX,transY,transZ);
	glRotatef(angleY,0.0f,1.0f,0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glRotatef(angleZ, 0.0f, 0.0, 1.0);


////DIBUJA CHICA
		glTranslatef(-150,-150,-200);
		dibuja_puntos(chica);


//		dibuja_puntos(toilet);


//		dibuja_puntos(rick);


//		dibuja_puntos(hellboy);

  											
  glutSwapBuffers ( );
}