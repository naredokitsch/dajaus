#include "figura_class.cpp"

#include "BigTable.cpp"
//#include "umbrella.cpp"

char archi [] = { 't','i','l','e','_','6','_','d','i','f','.','t','g','a','\0'};


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX ,transY,transZ);
	glRotatef(angleY,0.0f,1.0f,0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glRotatef(angleZ, 0.0f, 0.0, 1.0);

	figura BigTable( coord_BigTable, quads_BigTable, trng_BigTable, n_vertex_BigTable, t_vertex_BigTable, archi);

	glPushMatrix();
		glScalef(0.01,0.01,0.01);
		glTranslatef(50.0049 , -600.6093,-100);
		//BigTable.texturized();
	glPopMatrix();


	



	//glScalef(0.1,0.1,0.1);
	//glutSolidSphere(1,70,50);


  											
  glutSwapBuffers ( );
}