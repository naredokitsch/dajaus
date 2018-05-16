//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): MARTINEZ NAREDO NOE *************//
//************************************************************//
//************************************************************//

#include "geometria/geo.cpp"
#include "texture.cpp"
#include "muebleClass.cpp"
#include "texturas/def_textures.cpp"


float pos_camX = 0, pos_camY = 0, pos_camZ = -5; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;

//CTexture cedro;


void InitGL ( GLvoid )  {   // Inicializamos parametros

	glEnable(GL_TEXTURE_2D);

   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 100.0 };
   GLfloat light_position[] = { -1.0, 1.0, 1.0, 0.0 };
   glClearColor (94.0/255, 140.0/255, 141.0/255, 0.0);
   glShadeModel (GL_SMOOTH);

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);

   //SE CREAN LAS TEXTURAS

	/*cedro.LoadTGA(cedro_);
	cedro.BuildGLTexture();
	cedro.ReleaseImage();*/
}

/*void muebles_dining_room() {

	mueble BigTable( coord_BigTable, quads_BigTable, trng_BigTable, n_vertex_BigTable, t_vertex_BigTable );
	mueble florero( coord_flowers, quads_flowers, trng_flowers, n_vertex_flowers );
	mueble chair1( coord_chair, quads_chair, trng_chair, n_vertex_chair );
	mueble chair2( coord_chair, quads_chair, trng_chair, n_vertex_chair );
	mueble chair3( coord_chair, quads_chair, trng_chair, n_vertex_chair );
	mueble chair4( coord_chair, quads_chair, trng_chair, n_vertex_chair );
	mueble chair5( coord_chair, quads_chair, trng_chair, n_vertex_chair );
	mueble chair6( coord_chair, quads_chair, trng_chair, n_vertex_chair );


	glPushMatrix();
		glPushMatrix();									// MESA COMEDOR
			glScalef(0.004,0.004,0.004);
			glTranslatef(700.0049 , 0,-300);
			glBindTexture(GL_TEXTURE_2D, cedro.GLindex);
				BigTable.texturized();
		glPopMatrix();

		glPushMatrix();									//FLORERO COMEDOR
			glScalef(0.02,0.02,0.02);
			glTranslatef(140, 115,-60);
				florero.solid();
		glPopMatrix();

		glPushMatrix();									// SILLAS COMEDOR
				chair1.solid();
			glTranslatef(0, 0, -2.4);	
				chair2.solid();
			glTranslatef(5.5, 0, 0);
			glRotatef(180, 0, 1, 0 );
				chair3.solid();
			glTranslatef(0, 0, -2.4);
				chair4.solid();
			glTranslatef(2.7, 0, -2.8);
			glRotatef(-90, 0, 1, 0 );
				chair5.solid();
			glTranslatef(8, 0, 0);
			glRotatef(180, 0, 1, 0 );
				chair6.solid();
		glPopMatrix();
	glPopMatrix();
}*/

/*void muebles_living_room() {

	mueble centerTable( coord_centerTable, quads_centerTable, trng_centerTable, n_vertex_centerTable);
	mueble armchair( coord_armchair, quads_armchair, trng_armchair, n_vertex_armchair);

	//glBindTexture(GL_TEXTURE_2D, cedro.GLindex);
	centerTable.cloudPoints();

	glScalef(0.02,0.02,0.02);
	armchair.cloudPoints();

}*/

void muebles_bathroom () {
	mueble toilet( coord_toilet, quads_toilet, trng_toilet, n_vertex_toilet );
	mueble sink( coord_sink, quads_sink, trng_sink, n_vertex_sink );
	mueble shower( coord_shower, quads_shower, trng_shower, n_vertex_shower );

	//toilet.solid();
	//sink.solid();
	shower.solid();


}


void display ( void )  { // Creamos la funcion donde se dibuja

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(pos_camX, pos_camY, pos_camZ);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);


	//muebles_dining_room();
	muebles_bathroom();


	glutSwapBuffers ( );
}

void reshape ( int width , int height )  { // Creamos funcion Reshape

  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);		// Tipo de Vista

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion() {

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )  {// Create Keyboard Function

	switch ( key ) {
		case 's':   //Movimientos de camara
		case 'S':
			pos_camZ += 0.5f;
			//eye_camZ -= 0.5f;
			break;

		case 'w':
		case 'W':
			pos_camZ -= 0.5f;
			//eye_camZ += 0.5f;
			break;

		case 'd':
		case 'D':
			pos_camX += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'a':
		case 'A':
			pos_camX -= 0.5f;
			//eye_camX += 0.5f;
			break;

		case 'l':
		case 'L':
		pos_camY -= 0.5f;
		//eye_camY -= 0.5f;
		break;

    	case 'o':
		case 'O':
		pos_camY += 0.5f;
		break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  {// Funcion para manejo de teclas especiales (arrow keys)

  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX-15) % 360;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX+15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY-15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY+15) % 360;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   {// Main Function


  int screenH = glutGet(GLUT_SCREEN_HEIGHT);


  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (screenH , screenH);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Dajaus"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}