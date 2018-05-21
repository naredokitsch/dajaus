//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.cpp"
#include "figuras.cpp"
#include "Camera.cpp"
#include "texturas/def_textures.cpp"
#include "geometria/geo.cpp"
#include "muebleClass.cpp"

CFiguras sky;
CFiguras figuras;

////// VARIABLES DE IRON MAN /////
bool til45 = true;
bool r1 = true;
bool r2 = false;
bool r3 = false;
bool r4 = false;
bool r5 = false;
bool r6 = false;
bool r7 = false;
bool r8 = false;
float pos_iron [] = {0,0};
float giro = 0;
float swing_iron = 0;
/////////////////////////////////

float fan_rot ;

// Temp component manipulation
float height = 1.1;
float length = 1.1;
float depth = 1.1;


//////MOVIMIENTOS DE FALCON
float falcon_X ;
float falcon_Y ;
float falcon_Z ;

float falcon_rot_X ;
float falcon_rot_Y ;
float falcon_rot_Z ;
//////////////////////////

///VARIABLES DE FRAMES
#define MAX_FRAMES 80
int i_max_steps = 50;
int i_curr_steps = 0;
/////////////////////

typedef struct _frame {
	float falcon_X;
	float falcon_X_INC;
	float falcon_Y;
	float falcon_Y_INC;
	float falcon_Z;
	float falcon_Z_INC;

	float falcon_rot_X;
	float falcon_rot_X_INC;	
	float falcon_rot_Y;
	float falcon_rot_Y_INC;
	float falcon_rot_Z;
	float falcon_rot_Z_INC;
} FRAME ;



FRAME KeyFrame[MAX_FRAMES];
int FrameIndex=0;			//introducir datos
bool play=false;
int playIndex=0;

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture ironman_body_texture;
CTexture ironman_head_texture;

void saveFrame ( void )
{
	
	KeyFrame[FrameIndex].falcon_X = falcon_X;

	printf("KeyFrame[%i].falcon_X = %f ;\n",FrameIndex,KeyFrame[FrameIndex].falcon_X);

	KeyFrame[FrameIndex].falcon_Y = falcon_Y;

	printf("KeyFrame[%i].falcon_Y = %f ;\n",FrameIndex,KeyFrame[FrameIndex].falcon_Y);

	KeyFrame[FrameIndex].falcon_Z = falcon_Z;

	printf("KeyFrame[%i].falcon_Z = %f ;\n",FrameIndex,KeyFrame[FrameIndex].falcon_Z);

	KeyFrame[FrameIndex].falcon_rot_X = falcon_rot_X;

	printf("KeyFrame[%i].falcon_rot_X = %f ;\n",FrameIndex,KeyFrame[FrameIndex].falcon_rot_X);

	KeyFrame[FrameIndex].falcon_rot_Y = falcon_rot_Y;

	printf("KeyFrame[%i].falcon_rot_Y = %f ;\n",FrameIndex,KeyFrame[FrameIndex].falcon_rot_Y);

	KeyFrame[FrameIndex].falcon_rot_Z = falcon_rot_Z;

	printf("KeyFrame[%i].falcon_rot_Z = %f ;\n",FrameIndex,KeyFrame[FrameIndex].falcon_rot_Z);

	//printf("Frame %i Guardado!!!!!\n\n\n\n\n\n\n", FrameIndex);
			
	FrameIndex++;
}


void resetElements( void ) {

	//printf("Se han reseteado los elementos\n");
	falcon_X = KeyFrame[0].falcon_X;
	falcon_Y = KeyFrame[0].falcon_Y;
	falcon_Z = KeyFrame[0].falcon_Z;

	falcon_rot_X = KeyFrame[0].falcon_rot_X;
	falcon_rot_Y = KeyFrame[0].falcon_rot_Y;
	falcon_rot_Z = KeyFrame[0].falcon_rot_Z;
}

void interpolation ( void ) {

	KeyFrame[playIndex].falcon_X_INC = (KeyFrame[playIndex + 1].falcon_X - KeyFrame[playIndex].falcon_X) / i_max_steps;	
	KeyFrame[playIndex].falcon_Y_INC = (KeyFrame[playIndex + 1].falcon_Y - KeyFrame[playIndex].falcon_Y) / i_max_steps;	
	KeyFrame[playIndex].falcon_Z_INC = (KeyFrame[playIndex + 1].falcon_Z - KeyFrame[playIndex].falcon_Z) / i_max_steps;	

	KeyFrame[playIndex].falcon_rot_X_INC = (KeyFrame[playIndex + 1].falcon_rot_X - KeyFrame[playIndex].falcon_rot_X) / i_max_steps;	
	KeyFrame[playIndex].falcon_rot_Y_INC = (KeyFrame[playIndex + 1].falcon_rot_Y - KeyFrame[playIndex].falcon_rot_Y) / i_max_steps;	
	KeyFrame[playIndex].falcon_rot_Z_INC = (KeyFrame[playIndex + 1].falcon_rot_Z - KeyFrame[playIndex].falcon_rot_Z) / i_max_steps;
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

	ironman_body_texture.LoadTGA(ironman_body_);
	ironman_body_texture.BuildGLTexture();
	ironman_body_texture.ReleaseImage();

	ironman_head_texture.LoadTGA(ironman_head_);
	ironman_head_texture.BuildGLTexture();
	ironman_head_texture.ReleaseImage();
	

	// SE INICIAN VARIABLES DE KEYFRAMES

	for(int i=0; i<MAX_FRAMES; i++) {
	
		KeyFrame[i].falcon_X = 0;
		KeyFrame[i].falcon_X_INC = 0;
		KeyFrame[i].falcon_Y = 0;
		KeyFrame[i].falcon_Y_INC = 0;
		KeyFrame[i].falcon_Z = 0;
		KeyFrame[i].falcon_Z_INC = 0;

		KeyFrame[i].falcon_rot_X = 0;
		KeyFrame[i].falcon_rot_X_INC = 0;
		KeyFrame[i].falcon_rot_Y = 0;
		KeyFrame[i].falcon_rot_Y_INC = 0;
		KeyFrame[i].falcon_rot_Z = 0;
		KeyFrame[i].falcon_rot_Z_INC = 0;
	}

	printf("typedef struct _frame {\n\tfloat falcon_X;\n\tfloat falcon_X_INC;\n\tfloat falcon_Y;\n\tfloat falcon_Y_INC;\n\tfloat falcon_Z;\n\tfloat falcon_Z_INC;\n\tfloat falcon_rot_X;\n\tfloat falcon_rot_X_INC;\n\tfloat falcon_rot_Y;\n\tfloat falcon_rot_Y_INC;\n\tfloat falcon_rot_Z;\n\tfloat falcon_rot_Z_INC;\n} FRAME ;\n\n\n");

	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

}

void ventiladores () {

	fan_rot += 15;

	glPushMatrix();
		glScalef(3.5,3.5,3.5);
		glTranslatef(0,0.825,0);

		glPushMatrix();
			glTranslatef(-0.5, 0, 2);
			glRotatef(fan_rot, 0,1,0);
			mueble fan1(coord_fan,quads_fan,trng_fan,n_vertex_fan);
			fan1.solid();
		glPopMatrix();


		glPushMatrix();
			glTranslatef(2, 0, 2);
			glRotatef(fan_rot, 0,1,0);
			mueble fan2(coord_fan,quads_fan,trng_fan,n_vertex_fan);
			fan2.solid();
		glPopMatrix();
	glPopMatrix();
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

		/// LOGICA DE BRACEO Y MOVIMIENTO DE CUELLO
		if (til45 == true) {
			swing_iron += 5;
			if(swing_iron == 45) {
				//saveFrame();
				til45 = false;
			}
		} 
		
		if (til45 == false) {
			swing_iron -= 5;
			if (swing_iron == -45) {
				//saveFrame();
				til45 = true;
			}
		}
		///////////////////////////////////////////


		if (r1 == true) {
			pos_iron[1] += 1;
			if (pos_iron[1] == 160) {
				giro = 90;
				r2 = true;
				r1 = false;
			}
		}

		if (r2 == true) {
			pos_iron[0] += 1;
			if (pos_iron[0] == 80) {
				giro = 0;
				r3 = true;
				r2 = false;
			}
		}

		if (r3 == true) {
			pos_iron[1] += 1;
			if (pos_iron[1] == 550) {
				giro = 180;
				r3 = false;
				r4 = true;
			}
		}

		if (r4 == true) {
			pos_iron[1] -= 1;
			if (pos_iron[1] == 65) {
				giro = -90;
				r4 = false;
				r5 = true;
			}
		}

		if (r5 == true) {
			pos_iron[0] -= 1;
			if (pos_iron[0] == -170) {
				giro = 180;
				r5 = false;
				r6 = true;
			}
		}

		if (r6 == true) {
			pos_iron[1] -= 1;
			if (pos_iron[1] == -120) {
				giro = 90;
				r6 = false;
				r7 = true;
			}
		}

		if (r7 == true) {
			pos_iron[0] += 1;
			if (pos_iron[0] == 0) {
				giro = 0;
				r7 = false;
				r8 = true;
			}
		}

		if (r8 == true) {
			pos_iron[1] += 1;
			if (pos_iron[1] == 0) {
				//giro = -90;
				r1 = true;
				r8 = false;
			}
		}



		glPushMatrix();

			//////// POSICION Y ESCALA INICIALES /////////
			glTranslatef(1.8,1.2,15);
			glRotatef(180,0,1,0);
			glScalef(0.06, 0.06, 0.06);
			//////////////////////////////////////////////

			glTranslatef(pos_iron[0],0,pos_iron[1]);

			//if (giro != 0)
				glRotatef(giro, 0, 1, 0);

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
		glPopMatrix();
}


void millenary_falcon() {
	glPushMatrix();
		glScalef(0.001,0.001,0.001);
		glTranslatef(falcon_X , 3000.9930 + falcon_Y , -4984.5935 + falcon_Z);
		glRotatef(falcon_rot_X, 1 , 0, 0);
		glRotatef(falcon_rot_Y, 0 , 1, 0);
		glRotatef(falcon_rot_Z, 0 , 0, 1);
		mueble falcon(coord_falcon, quads_falcon,trng_falcon, n_vertex_falcon);
		falcon.solid();
	glPopMatrix();	
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
	
		glEnable(GL_TEXTURE_2D);

		//dibuja_ironman();
		
		glDisable(GL_TEXTURE_2D);

		//ventiladores();

		millenary_falcon();


		glPushMatrix();		
			/*glPushMatrix(); //Creamos cielo
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
			glEnable(GL_LIGHTING);*/

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

					glPushMatrix();
						glTranslatef(-2.5, 0.5, 0);
						figuras.prisma(1, 1, 0.11, 1);	// Ventana Horizontal banio
						glTranslatef(-0.5, 0, -0.5);
						figuras.prisma(1, 0.11, 1.0, 1);	// Ventana Vertical Banio
					glPopMatrix();

					glPushMatrix();
						glTranslatef(-1.5,0,-3);
						figuras.prisma(3.5,3,0.1,0);	// Muro Horizontal banio
						glTranslatef(1.5, 0, 0.5);
						figuras.prisma(3.5, 0.1, 1.0, 0);	// Muro Vertical Banio
					glPopMatrix();

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

					// Inicia Muros internos
					glPushMatrix();
						glTranslatef(2.75, 0, -1.9);
						figuras.prisma(3.5, 0.1, 3.8, 0); // Muro Inferior

						glTranslatef(0, 0, -5.5);
						figuras.prisma(3.5, 0.1, 3.8, 0); // Muros Centro Vertical 1

						glPushMatrix();
							glTranslatef(-2.7, 0, 0.0);
							figuras.prisma(3.5, 0.1, 1.9, 0); // Muros Centro Vertical 2
						glPopMatrix();

						glTranslatef(-2.0, 0, 0.0);
						figuras.prisma(3.5, 4, 0.1, 0); // Muros Centro 2

						glPushMatrix();
							glTranslatef(0.5, 0, 1.9);
							figuras.prisma(3.5, 3, 0.1, 0); // Muros Centro Horizontal 1
						glPopMatrix();

						glPushMatrix();
							glTranslatef(0.5, 0, -1.9);
							figuras.prisma(3.5, 3, 0.1, 0); // Muros Centro Horizontal 2
						glPopMatrix();

						glTranslatef(2, 0, -5.5);
						figuras.prisma(3.5, 0.1, 3.8, 0); // Muro Inferior

						glTranslatef(-2.5, 0, -1.9);
						figuras.prisma(3.5, 6, 0.1, 0); // Muro Inferior


					glPopMatrix();
					
				glPopMatrix(); //	Fin Recamaras
				/*
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
				*/
			glPopMatrix();



		glPopMatrix(); 
		
	glPopMatrix();

	glutSwapBuffers ( );

}

void animacion()
{
	//Movimiento del monito
	if(play)
	{		
		
		if(	i_curr_steps >= i_max_steps) //end of animation between frames?
		{			
			playIndex++;		
			if(playIndex>FrameIndex-2)	//end of total animation?
			{
				//printf("termina anim\n");
				playIndex=0;
				play=false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
				//Interpolation
				interpolation();

			}
		}
		else
		{
			//Draw animation
			falcon_X += KeyFrame[playIndex].falcon_X_INC;
			falcon_Y += KeyFrame[playIndex].falcon_Y_INC;
			falcon_Z += KeyFrame[playIndex].falcon_Z_INC;

			falcon_rot_X += KeyFrame[playIndex].falcon_rot_X_INC;
			falcon_rot_Y += KeyFrame[playIndex].falcon_rot_Y_INC;
			falcon_rot_Z += KeyFrame[playIndex].falcon_rot_Z_INC;

			i_curr_steps++;
		}
		
	}

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


		////////temporales
		case 'x':   //Movimientos de camara
			falcon_X = falcon_X + 100;
			break;

		case 'X':   //Movimientos de camara
			falcon_X = falcon_X - 100;
			break;

		case 'y':   //Movimientos de camara
			falcon_Y = falcon_Y + 100;
			break;

		case 'Y':   //Movimientos de camara
			falcon_Y = falcon_Y - 100;
			break;

		case 'z':   //Movimientos de camara
			falcon_Z = falcon_Z - 100;
			break;

		case 'Z':   //Movimientos de camara
			falcon_Z = falcon_Z + 100;
			break;

		case 'b':   //Movimientos de camara
			falcon_rot_X = falcon_rot_X + 1;
			break;

		case 'B':   //Movimientos de camara
			falcon_rot_X = falcon_rot_X - 1;
			break;

		case 'n':   //Movimientos de camara
			falcon_rot_Y = falcon_rot_Y + 1;
			break;

		case 'N':   //Movimientos de camara
			falcon_rot_Y = falcon_rot_Y - 1;
			break;

		case 'm':   //Movimientos de camara
			falcon_rot_Z = falcon_rot_Z + 1;
			break;

		case 'M':   //Movimientos de camara
			falcon_rot_Z = falcon_rot_Z - 1;
			break;

		//////////////////////



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
			//printf("(%f,%f,%f)", length,height,depth);
			break;
		case 'O':
			length = length - 0.l;
			//printf("(%f,%f,%f)", length, height, depth);
			break;
		case 'l':
			height = height + 0.l;
			//printf("(%f,%f,%f)", length, height, depth);
			break;
		case 'L':
			height = height - 0.l;
			//printf("(%f,%f,%f)", length, height, depth);
			break;
		case 'k':
			depth = depth + 0.l; 
			//printf("(%f,%f,%f)", length, height, depth);
			break;
		case 'K':
			depth = depth - 0.l;
			//printf("(%f,%f,%f)", length, height, depth);
			break;
		case 'u':
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

		case 'j':
		objCamera.UpDown_Camera(-CAMERASPEED);
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

void menuKeyFrame( int id)
{
	switch (id)
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
				//printf("\nAnimacion Iniciada\n");
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


	}
}


void menu( int id)
{
	
}


int main ( int argc, char** argv )   // Main Function
{

	int submenu;

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

   submenu = glutCreateMenu	  ( menuKeyFrame );
  printf("submenu = %i\n", submenu);
  glutAddMenuEntry	  ("Guardar KeyFrame", 0);
  glutAddMenuEntry	  ("Reproducir Animacion", 1);
  glutCreateMenu	  ( menu );
  glutAddSubMenu	  ("Animacion Monito", submenu);
 
  glutAttachMenu	  (GLUT_RIGHT_BUTTON);

  glutMainLoop        ( );          // 

  return 0;
}
