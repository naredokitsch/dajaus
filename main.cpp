//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): MARTINEZ NAREDO NOE *************//
//************************************************************//
//************************************************************//

//#include "geometria/MineCraft_Character.cpp"
#include "texture.cpp"
//#include "muebleClass.cpp"
//#include "texturas/def_textures.cpp"


float pos_camX = 0, pos_camY = 0, pos_camZ = -5;
float rot_iron = 0;
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


void cube(float width, float height, float depth) {

	glBegin(GL_QUADS); //bottom
		glNormal3f(0,-1,0) ; glVertex3f( -(width/2.0) , -(height/2.0), depth/2.0);
		glNormal3f(0,-1,0) ; glVertex3f( width/2.0 , -(height/2.0), depth/2.0);
		glNormal3f(0,-1,0) ; glVertex3f( width/2.0 , -(height/2.0), -(depth/2.0));
		glNormal3f(0,-1,0) ; glVertex3f( -(width/2.0) , -(height/2.0), -(depth/2.0));
	glEnd();

	glBegin(GL_QUADS); //front
		glNormal3f(0,0,1) ; glVertex3f( -(width/2.0) , -(height/2.0), depth/2.0);
		glNormal3f(0,0,1) ; glVertex3f( width/2.0 , -(height/2.0), depth/2.0);
		glNormal3f(0,0,1) ; glVertex3f( width/2.0 , height/2.0, depth/2.0);
		glNormal3f(0,0,1) ; glVertex3f( -(width/2.0) , height/2.0, depth/2.0);
	glEnd();

	glBegin(GL_QUADS); //left
		glNormal3f(-1,0,0) ; glVertex3f( -(width/2.0) , -(height/2.0), depth/2.0);
		glNormal3f(-1,0,0) ; glVertex3f(-(width/2.0) , -(height/2.0), -(depth/2.0));
		glNormal3f(-1,0,0) ; glVertex3f(-(width/2.0) , height/2.0, -(depth/2.0));
		glNormal3f(-1,0,0) ; glVertex3f(-(width/2.0) , height/2.0, depth/2.0);
	glEnd();

	glBegin(GL_QUADS); //right
		glNormal3f(1,0,0) ; glVertex3f(width/2.0 , -(height/2.0), depth/2.0);
		glNormal3f(1,0,0) ; glVertex3f(width/2.0 , -(height/2.0), -(depth/2.0));
		glNormal3f(1,0,0) ; glVertex3f(width/2.0 , height/2.0, -(depth/2.0));
		glNormal3f(1,0,0) ; glVertex3f(width/2.0 , height/2.0, depth/2.0);
	glEnd();

	glBegin(GL_QUADS); //back
		glNormal3f(0,0,-1) ; glVertex3f( -(width/2.0) , -(height/2.0), -(depth/2.0));
		glNormal3f(0,0,-1) ; glVertex3f( width/2.0 , -(height/2.0), -(depth/2.0));
		glNormal3f(0,0,-1) ; glVertex3f(width/2.0 , height/2.0, -(depth/2.0));
		glNormal3f(0,0,-1) ; glVertex3f( -(width/2.0) , height/2.0, -(depth/2.0));
	glEnd();

	glBegin(GL_QUADS); //top
		glNormal3f(0,1,0) ; glVertex3f( -(width/2.0) , height/2.0, depth/2);
		glNormal3f(0,1,0) ; glVertex3f( width/2.0 , height/2.0, depth/2);
		glNormal3f(0,1,0) ; glVertex3f( width/2.0 , height/2.0, -(depth/2));
		glNormal3f(0,1,0) ; glVertex3f( -(width/2.0) , height/2.0, -(depth/2));
	glEnd();

}

void display ( void )  { // Creamos la funcion donde se dibuja

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(pos_camX, pos_camY, pos_camZ);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);


		glPushMatrix();//body
			glTranslatef(0,6,0);
			cube(8,12,4);//CUERPO
			glTranslatef(0,6,0);
			glRotatef(rot_iron, 0,1,0);//ROTACION DE CUELLO
			glTranslatef(0,4,0);
			cube(8,8,8);//CABEZA
			glTranslatef(4,-6,0);

		glPopMatrix();



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

		case 'c':
		case 'C':
		rot_iron += 0.5f;
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