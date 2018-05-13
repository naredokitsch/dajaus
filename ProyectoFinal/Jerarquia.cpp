//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"


int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;

// Temp component manipulation
float height = 1.1;
float length = 1.1;
float depth = 1.1;


CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture textPasto; //Pasto

CTexture tree;

CFiguras sky;
CFiguras figuras;

void arbol()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, tree.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}

			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	

	// Importamos Texturas

	char textura_1[] = { "01.bmp" };
	char textura_2[] = {"logopumas.bmp"};
	char textura_3[] = { "city/arrow.tga" };
	char textura_4[] = { "tree01.tga" };
	char textura_5[] = { "texturas/Grass_tile_A_diffuse.tga" };

    text1.LoadBMP(textura_1);
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP(textura_2);
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA(textura_3);
	text3.BuildGLTexture();
	text3.ReleaseImage();


	tree.LoadTGA(textura_4);
	tree.BuildGLTexture();
	tree.ReleaseImage();

	textPasto.LoadTGA(textura_5);
	textPasto.BuildGLTexture();
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	textPasto.ReleaseImage();

	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				sky.skybox(130.0, 130.0, 130.0,text1.GLindex);
				
				glColor3f(1.0,1.0,1.0);
			glPopMatrix();

			// Creamos la plataforma con el pasto
			glPushMatrix();
				glTranslatef(0, 0, 0);
				figuras.prisma(0.1,100,100,textPasto.GLindex);
			glPopMatrix();
			glEnable(GL_LIGHTING);

			glPushMatrix(); // Arquitectura de la casa
			glTranslatef(5, 1.75, 0);
				glPushMatrix(); // Cocina, Sala Comedor
					glPushMatrix();
						glTranslatef(-2.3, -1.6, 7);
						figuras.prisma(0.001,17.5,14,0);//Suelo 
					glPopMatrix();
					glPushMatrix();
						glTranslatef(-8, -1.6, 15.2);
						figuras.prisma(0.001, 6, 2.7, 0);//Suelo 2
					glPopMatrix();
					figuras.prisma(3.5, 13, 0.1, 0); // Muro superior
					glPushMatrix(); // Ventana Superior Izquierda
						glTranslatef(-3.25, 0, 0);
						figuras.prisma(3.5, 6, 0.11, 1); //  superior izquierda
					glPopMatrix();
					glPushMatrix(); // Ventana Superior Izquierda
						glTranslatef(3.25, 0, 0);
						figuras.prisma(3.5, 6, 0.11, 1); //  superior Derecha
					glPopMatrix();
					glTranslatef(6.5, 0, 4.5);
					figuras.prisma(3.5, 0.1, 9, 0); //muro derecho
					glPushMatrix(); // Ventana Derecha
						glTranslatef(0.0, 0, -1);
						figuras.prisma(3.5, 0.11, 6, 1); // Ventana superior izquierda
					glPopMatrix();
					glTranslatef(0, 0, 8.5);
					figuras.prisma(3.5, 0.1, 2, 0); //muro derecho 2

					glTranslatef(-4, 0, 1);
					figuras.prisma(3.5, 8, 0.1, 0); //muro inferior
					glPushMatrix(); // Ventana Derecha
						glTranslatef(-1, 0.875, 0);
						figuras.prisma(1.75, 6, 0.11, 1); // Ventana superior izquierda
					glPopMatrix();
					glTranslatef(-4, 0, 3.5);
					figuras.prisma(3.5, 0.1, 7, 0); //muro inferior2
					glTranslatef(-3.5, 0, -2.25);
					figuras.prisma(3.5, 0.1, 2.5, 0); //muro inferior3
					glTranslatef(-3, 0, 1.25);
					figuras.prisma(3.5, 6, 0.1, 0); //muro inferior4
					glTranslatef(-3, 0, -8);
					figuras.prisma(3.5, 0.1, 16, 0); //muro izquierdo

					
				glPopMatrix();// Fin Cocina-Sala Comedor	

				glPushMatrix();	// Inicia Recamaras
					glTranslatef(-6.5, 0, -10);
					glPushMatrix();// Inicia Piso Interno
						glTranslatef(-5, -1.74, 0.4);
						figuras.prisma(0.1,10,21.01 ,0);
					glPopMatrix();//  Termina Piso Interno
					glPushMatrix();// Inicia Piso Madera Derecha
						glTranslatef(-10., -1.73, 3.5);
						figuras.prisma(0.1, 3, 7.0, 0);
					glPopMatrix();//  Termina Piso Madera Derecha

					figuras.prisma(3.5, 0.1, -20, 0); // Muro Derecha
					glPushMatrix(); // Ventana Derecha
						glTranslatef(0, 0, 3.5);
						figuras.prisma(3.5, 0.11, 7, 1); //  Ventana Larga Derecha
						
						glTranslatef(0, 0.85, -5);
						figuras.prisma(1, 0.11, 1, 1); //  Ventana Chica 1 Derecha

						glTranslatef(0, 0, -2);
						figuras.prisma(1, 0.11, 1, 1); //  Ventana Chica 2 Derecha

						glTranslatef(0, 0, -2);
						figuras.prisma(1, 0.11, 1, 1); //  Ventana Chica 2 Derecha

					glPopMatrix();
					glTranslatef(-5, 0, -10);
					figuras.prisma(3.5, -10, 0.1, 0); // Muro Superior

					glTranslatef(-5, 0, 5);
					figuras.prisma(3.5, 0.1, 10, 0); // Muro Izquierda 1
					glTranslatef(0.7, 0, 5);
					figuras.prisma(3.5, 1.5, 0.1, 0); // Muro Izquierda 2
					glTranslatef(0.7, 0, 3.5);
					figuras.prisma(3.5, 0.1, 7, 1); // Muro Izquierda 3
					// TODO Agregar Puiertas Vidrio
					glTranslatef(-0.7, 0, 3.5);
					figuras.prisma(3.5, 1.5, 0.1, 0); // Muro Izquierda 4

					glTranslatef(-0.7, 0, 1.9);
					figuras.prisma(3.5, 0.1, 3.8, 0); // Muro Izquierda 5

					glTranslatef(2.75, 0, 1.9);
					figuras.prisma(3.5, 5.5, 0.1, 0); // Muro Inferior 
					
				glPopMatrix(); //	Fin Recamaras

				glPushMatrix();	//	Inicio Zona Alberca
					glTranslatef(3.5, -1.73, -8.5);
					figuras.prisma(0.1, 20, 17, 0);
					glTranslatef(0, 0.01, 0);
					figuras.prisma(0.1, 8, 6.5, 1); // Alberca
					glTranslatef(6.45, 0, 15.5);
					figuras.prisma(0.1, 7.05, 14, 0); // Suelo Derecho
				glPopMatrix();	//	Fin Zona Alberca
				
				glPushMatrix();	//	Inicio Estacionamiento
					glTranslatef(-18, -1.74, 8.75);
					figuras.prisma(0.1, 13.8, 15.9, 0);
					glTranslatef(3.1, 0, 10.8);
					figuras.prisma(0.1, 20.0, 6, 0); // Ladrillo frente a entrada
					glTranslatef(11.5, 0, -1.6);
					figuras.prisma(0.1, 3.7, 9.2, 0); // Ladrillo frente a entrada 2
				glPopMatrix();	//	Fin Estacionamiento

			glPopMatrix();



		glPopMatrix(); 
		
	glPopMatrix();

	glutSwapBuffers ( );

}

void animacion()
{

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'o':
			length = length + 0.l;
			printf("(%f,%f,%f)", length,height,depth);
			break;
		case 'O':
			length = length - 0.l;
			printf("(%f,%f,%f)", length, height, depth);
			break;
		case 'l':
			height = height + 0.l;
			printf("(%f,%f,%f)", length, height, depth);
			break;
		case 'L':
			height = height - 0.l;
			printf("(%f,%f,%f)", length, height, depth);
			break;
		case 'k':
			depth = depth + 0.l; 
			printf("(%f,%f,%f)", length, height, depth);
			break;
		case 'K':
			depth = depth - 0.l;
			printf("(%f,%f,%f)", length, height, depth);
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (2000, 2000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Jerarquia"); // Nombre de la Ventana
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
