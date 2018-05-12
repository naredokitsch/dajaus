#include "objects/figura_class.cpp"
#include "objects/figura_objects.cpp"



void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX ,transY,transZ);
	glRotatef(angleY,0.0f,1.0f,0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glRotatef(angleZ, 0.0f, 0.0, 1.0);

	glColor3f( 160.0/255.0 , 22.0/255.0 , 11.0/255.0 );


	// MESA COMEDOR
	glPushMatrix();
		glScalef(0.01,0.01,0.01);
		glTranslatef(50.0049 , -600.6093,-100);
		BigTable.texturized();
	glPopMatrix();



	//chair.solid();


	
	//chair.solid();
	



	//glScalef(0.1,0.1,0.1);
	//glutSolidSphere(1,70,50);


  											
  glutSwapBuffers ( );
}