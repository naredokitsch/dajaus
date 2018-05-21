//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): MARTINEZ NAREDO NOE *************//
//************************************************************//
//************************************************************//

#include "texture.cpp"
#include "texturas/def_textures.cpp"
#include "geometria/geo.cpp"
#include "muebleClass.cpp"

float pos_camX = 0, pos_camY = 0, pos_camZ = -5;

float swing_iron = 0;
float pos_iron [] = {0,0};
float dir_iron = 0;

int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;
bool til45 = true;

float posX =0, posY = 2.5, posZ =-3.5, rotRodIzq = 0;
float giroMonito = 0;

#define MAX_FRAMES 500
int i_max_steps = 90;
int i_curr_steps = 0;

typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotInc;
	float giroMonito;
	float giroMonitoInc;
	float swing_iron;
	
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex=0;			//introducir datos
bool play=false;
int playIndex=0;


CTexture ironman_body_texture;
CTexture ironman_head_texture;

void saveFrame ( void )
{
	

	printf("swing_iron %f\n", swing_iron);			

	/*KeyFrame[FrameIndex].posX=posX;
	KeyFrame[FrameIndex].posY=posY;
	KeyFrame[FrameIndex].posZ=posZ;

	KeyFrame[FrameIndex].rotRodIzq=rotRodIzq;
	KeyFrame[FrameIndex].giroMonito=giroMonito;
			
	FrameIndex++;*/

}


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

	ironman_body_texture.LoadTGA(ironman_body_);
	ironman_body_texture.BuildGLTexture();
	ironman_body_texture.ReleaseImage();

	ironman_head_texture.LoadTGA(ironman_head_);
	ironman_head_texture.BuildGLTexture();
	ironman_head_texture.ReleaseImage();
}


void cube(float width, float height, float depth, float* text_coord, GLuint text_coord_index) {
	glBindTexture(GL_TEXTURE_2D, text_coord_index);
	glBegin(GL_QUADS); //bottom
		glTexCoord2f(text_coord[0],text_coord[1]) ; glNormal3f(0,-1,0) ; glVertex3f( -(width/2.0) , -(height/2.0), depth/2.0);
		glTexCoord2f(text_coord[2],text_coord[3]) ; glNormal3f(0,-1,0) ; glVertex3f( width/2.0 , -(height/2.0), depth/2.0);
		glTexCoord2f(text_coord[4],text_coord[5]) ; glNormal3f(0,-1,0) ; glVertex3f( width/2.0 , -(height/2.0), -(depth/2.0));
		glTexCoord2f(text_coord[6],text_coord[7]) ; glNormal3f(0,-1,0) ; glVertex3f( -(width/2.0) , -(height/2.0), -(depth/2.0));
	glEnd();

	
	glBegin(GL_QUADS); //front
		glTexCoord2f(text_coord[8],text_coord[9]) ; glNormal3f(0,0,1) ; glVertex3f( -(width/2.0) , -(height/2.0), depth/2.0);
		glTexCoord2f(text_coord[10],text_coord[11]) ; glNormal3f(0,0,1) ; glVertex3f( width/2.0 , -(height/2.0), depth/2.0);
		glTexCoord2f(text_coord[12],text_coord[13]) ; glNormal3f(0,0,1) ; glVertex3f( width/2.0 , height/2.0, depth/2.0);
		glTexCoord2f(text_coord[14],text_coord[15]) ; glNormal3f(0,0,1) ;glVertex3f( -(width/2.0) , height/2.0, depth/2.0);
	glEnd();

	glBegin(GL_QUADS); //left
		glTexCoord2f(text_coord[16],text_coord[17]) ; glNormal3f(-1,0,0) ; glVertex3f( -(width/2.0) , -(height/2.0), depth/2.0);
		glTexCoord2f(text_coord[18],text_coord[19]) ; glNormal3f(-1,0,0) ; glVertex3f(-(width/2.0) , -(height/2.0), -(depth/2.0));
		glTexCoord2f(text_coord[20],text_coord[21]) ; glNormal3f(-1,0,0) ; glVertex3f(-(width/2.0) , height/2.0, -(depth/2.0));
		glTexCoord2f(text_coord[22],text_coord[23]) ; glNormal3f(-1,0,0) ; glVertex3f(-(width/2.0) , height/2.0, depth/2.0);
	glEnd();

	glBegin(GL_QUADS); //right
		glTexCoord2f(text_coord[24],text_coord[25]) ; glNormal3f(1,0,0) ; glVertex3f(width/2.0 , -(height/2.0), depth/2.0);
		glTexCoord2f(text_coord[26],text_coord[27]) ; glNormal3f(1,0,0) ; glVertex3f(width/2.0 , -(height/2.0), -(depth/2.0));
		glTexCoord2f(text_coord[28],text_coord[29]) ; glNormal3f(1,0,0) ; glVertex3f(width/2.0 , height/2.0, -(depth/2.0));
		glTexCoord2f(text_coord[30],text_coord[31]) ; glNormal3f(1,0,0) ; glVertex3f(width/2.0 , height/2.0, depth/2.0);
	glEnd();

	glBegin(GL_QUADS); //back
		glTexCoord2f(text_coord[32],text_coord[33]) ; glNormal3f(0,0,-1) ; glVertex3f( -(width/2.0) , -(height/2.0), -(depth/2.0));
		glTexCoord2f(text_coord[34],text_coord[35]) ; glNormal3f(0,0,-1) ; glVertex3f( width/2.0 , -(height/2.0), -(depth/2.0));
		glTexCoord2f(text_coord[36],text_coord[37]) ; glNormal3f(0,0,-1) ; glVertex3f(width/2.0 , height/2.0, -(depth/2.0));
		glTexCoord2f(text_coord[38],text_coord[39]) ; glNormal3f(0,0,-1) ; glVertex3f( -(width/2.0) , height/2.0, -(depth/2.0));
	glEnd();

	glBegin(GL_QUADS); //top
		glTexCoord2f(text_coord[40],text_coord[41]) ; glNormal3f(0,1,0) ; glVertex3f( -(width/2.0) , height/2.0, depth/2);
		glTexCoord2f(text_coord[42],text_coord[43]) ; glNormal3f(0,1,0) ; glVertex3f( width/2.0 , height/2.0, depth/2);
		glTexCoord2f(text_coord[44],text_coord[45]) ; glNormal3f(0,1,0) ; glVertex3f( width/2.0 , height/2.0, -(depth/2));
		glTexCoord2f(text_coord[46],text_coord[48]) ; glNormal3f(0,1,0) ; glVertex3f( -(width/2.0) , height/2.0, -(depth/2));
	glEnd();

}


void dibuja_ironman () {


		if (til45 == true) {
			swing_iron += 0.25;
			if(swing_iron == 45) {
				saveFrame();
				til45 = false;
			}
		} 
		
		if (til45 == false) {
			swing_iron -= 0.25;
			if (swing_iron == -45) {
				saveFrame();
				til45 = true;
			}
		}

		//PARTE SUPERIOR DEL CUERPO
		glPushMatrix();//body
			//glPointSize(10); 

			glTranslatef(0,6,0); 
			cube(8,12,4, text_coord_body, ironman_body_texture.GLindex);//CUERPO
			glTranslatef(0,4,0);				//ALTURA HOMBROS
			
			glPushMatrix();					
				glTranslatef(0,2,0);
				glRotatef(swing_iron, 0,1,0);//ROTACION DE CUELLO
				glTranslatef(0,4,0);
				cube(8,8,8, text_coord_head, ironman_head_texture.GLindex);					//CABEZA
			glPopMatrix();
			
			
			glTranslatef(4,0,0);				//HOMBRO DERECHO

			glPushMatrix();
				glRotatef(swing_iron, 1,0,0);
				glTranslatef(2,-4,0);
				cube(4,12,4, text_coord_arm_leg, ironman_body_texture.GLindex); //BRAZO DERECHO
			glPopMatrix();

			glTranslatef(-8,0,0);			//HOMBRO IZQUIERDO
			//glBegin(GL_POINTS); glVertex3f(0,0,0); glEnd();

			glPushMatrix();
				glRotatef(swing_iron, -1,0,0);
				glTranslatef(-2,-4,0);
				cube(4,12,4, text_coord_arm_leg, ironman_body_texture.GLindex);	//BRAZO IZQUIERDO
			glPopMatrix();
		glPopMatrix();
		
		//PARTE INFERIOR DEL CUERPO
		glPushMatrix();

			glTranslatef(-2,0,0);

			glPushMatrix();
				glRotatef(swing_iron, 1,0,0);
				glTranslatef(0,-6,0);
				cube(4,12,4, text_coord_arm_leg, ironman_body_texture.GLindex);	// PIERNA IZQUIERDA
			glPopMatrix();

			glTranslatef(4,0,0);

			glPushMatrix();
				glRotatef(swing_iron, -1,0,0);
				glTranslatef(0,-6,0);
				cube(4,12,4, text_coord_arm_leg, ironman_body_texture.GLindex);	//PIERNA DERECHA
			glPopMatrix();
		
		glPopMatrix();
}

void display ( void )  { // Creamos la funcion donde se dibuja

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glTranslatef(pos_camX, pos_camY, pos_camZ);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);

	glPushMatrix();
		glScalef(0.005,0.005,0.005);
		glTranslatef(0 , 37.9930 , 2984.5935);
		
		mueble falcon(coord_falcon, quads_falcon,trng_falcon, n_vertex_falcon);
		falcon.solid();
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

	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 5000.0);		// Tipo de Vista

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
		swing_iron += 0.5f;
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

void menuKeyFrame( int id)
{
	/*switch (id)
	{
		case 0:	//Save KeyFrame
			if(FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}
			break;

		case 1:	//Play animation
			if(play==false && FrameIndex >1)
			{

				resetElements();
				//First Interpolation
				interpolation();

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;


	}*/
}

void menu( int id)
{
	
}

int main ( int argc, char** argv )   {// Main Function


  int screenH = glutGet(GLUT_SCREEN_HEIGHT);

  int submenu;
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

  submenu = glutCreateMenu	  ( menuKeyFrame );
  glutAddMenuEntry	  ("Guardar KeyFrame", 0);
  glutAddMenuEntry	  ("Reproducir Animacion", 1);
  glutCreateMenu	  ( menu );
  glutAddSubMenu	  ("Animacion IroMan", submenu);
 
  glutAttachMenu	  (GLUT_RIGHT_BUTTON);

  glutMainLoop        ( );          // 

  return 0;
}