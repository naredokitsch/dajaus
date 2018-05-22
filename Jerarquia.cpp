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
#include "anima_vars.cpp"

CFiguras sky;
CFiguras figuras;

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture ironman_body_texture;
CTexture ironman_head_texture;

void getFramesValues();

void falcon_reset( void ) {

	//printf("Se han reseteado los elementos\n");
	falcon_X = falcon_KeyFrame[0].falcon_X;
	falcon_Y = falcon_KeyFrame[0].falcon_Y;
	falcon_Z = falcon_KeyFrame[0].falcon_Z;

	falcon_rot_X = falcon_KeyFrame[0].falcon_rot_X;
	falcon_rot_Y = falcon_KeyFrame[0].falcon_rot_Y;
	falcon_rot_Z = falcon_KeyFrame[0].falcon_rot_Z;
}

void pong_reset( void ) {

	//printf("Se han reseteado los elementos\n");
	leftbar_Y = pong_KeyFrame[0].leftbar_Y;
	rightbar_Y = pong_KeyFrame[0].rightbar_Y;

	ball_X = pong_KeyFrame[0].ball_X;
	ball_Y = pong_KeyFrame[0].ball_Y;
}

void falcon_interpolation ( void ) {

	falcon_KeyFrame[falcon_playIndex].falcon_X_INC = (falcon_KeyFrame[falcon_playIndex + 1].falcon_X - falcon_KeyFrame[falcon_playIndex].falcon_X) / falcon_max_steps;	
	falcon_KeyFrame[falcon_playIndex].falcon_Y_INC = (falcon_KeyFrame[falcon_playIndex + 1].falcon_Y - falcon_KeyFrame[falcon_playIndex].falcon_Y) / falcon_max_steps;	
	falcon_KeyFrame[falcon_playIndex].falcon_Z_INC = (falcon_KeyFrame[falcon_playIndex + 1].falcon_Z - falcon_KeyFrame[falcon_playIndex].falcon_Z) / falcon_max_steps;	

	falcon_KeyFrame[falcon_playIndex].falcon_rot_X_INC = (falcon_KeyFrame[falcon_playIndex + 1].falcon_rot_X - falcon_KeyFrame[falcon_playIndex].falcon_rot_X) / falcon_max_steps;	
	falcon_KeyFrame[falcon_playIndex].falcon_rot_Y_INC = (falcon_KeyFrame[falcon_playIndex + 1].falcon_rot_Y - falcon_KeyFrame[falcon_playIndex].falcon_rot_Y) / falcon_max_steps;	
	falcon_KeyFrame[falcon_playIndex].falcon_rot_Z_INC = (falcon_KeyFrame[falcon_playIndex + 1].falcon_rot_Z - falcon_KeyFrame[falcon_playIndex].falcon_rot_Z) / falcon_max_steps;
}

void pong_interpolation ( void ) {

	pong_KeyFrame[pong_playIndex].leftbar_Y_INC = (pong_KeyFrame[pong_playIndex + 1].leftbar_Y - pong_KeyFrame[pong_playIndex].leftbar_Y) / pong_max_steps;
	pong_KeyFrame[pong_playIndex].rightbar_Y_INC = (pong_KeyFrame[pong_playIndex + 1].rightbar_Y - pong_KeyFrame[pong_playIndex].rightbar_Y) / pong_max_steps;
	pong_KeyFrame[pong_playIndex].ball_X_INC = (pong_KeyFrame[pong_playIndex + 1].ball_X - pong_KeyFrame[pong_playIndex].ball_X) / pong_max_steps;	
	pong_KeyFrame[pong_playIndex].ball_Y_INC = (pong_KeyFrame[pong_playIndex + 1].ball_Y - pong_KeyFrame[pong_playIndex].ball_Y) / pong_max_steps;	

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

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

	getFramesValues();
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


void television() {


	if( pong_play == false && pong_FrameIndex > 0 ) {
		pong_reset();
		//First Interpolation
		pong_interpolation();

		pong_play = true ;
		pong_playIndex = 0 ;
		pong_curr_steps = 0 ;
	}

	glPushMatrix();

		glScalef(0.2,0.2,0.2);
		glTranslatef(10,0.7,4);
		glRotatef(-90, 1, 0, 0);

		
		mueble tv(coord_tv, quads_tv, trng_tv, n_vertex_tv);
		glColor3f(0,0,0);
		tv.solid();

		glColor3f(0,1,0);

		glPushMatrix();
			glTranslatef(-9,0, leftbar_Y);
			glBegin(GL_QUADS); //left bar
				glNormal3f( 1.0f, 1.0f, 1.0f);
				glVertex3f(6.104019 , -0.383025 , 0.932411);
				glVertex3f(6.104019 , -0.383025 , 1.932411);
				glVertex3f(5.9 , -0.383025 , 1.932411);
				glVertex3f(5.9 , -0.383025 , 0.932411);
			glEnd();
		glPopMatrix();

		
		glPushMatrix();	// BARRA DERECHA
			glTranslatef(-3,0, rightbar_Y);
			glBegin(GL_QUADS); //left bar
				glNormal3f( 0.0f, 0.0f, 1.0f);
				glVertex3f(6.104019 , -0.383025 , 0.932411);
				glVertex3f(6.104019 , -0.383025 , 1.932411);
				glVertex3f(5.9 , -0.383025 , 1.932411);
				glVertex3f(5.9 , -0.383025 , 0.932411);
			glEnd();
		glPopMatrix();

		glPushMatrix();	// BARRA DERECHA
			glTranslatef(ball_X,0, ball_Y);
			glBegin(GL_QUADS); //left bar
				glNormal3f( 0.0f, 0.0f, 1.0f);
				glVertex3f(6.1 , -0.383025 , 0.932411);
				glVertex3f(6.1 , -0.383025 , 0.932411 + 0.2);
				glVertex3f(5.9 , -0.383025 , 0.932411 + 0.2);
				glVertex3f(5.9 , -0.383025 , 0.932411);
			glEnd();
		glPopMatrix();

		glColor3f(1,1,1);

	glPopMatrix();
}

void millenary_falcon() {

	if( falcon_play == false && falcon_FrameIndex > 0 ) {
	falcon_reset();
	//First Interpolation
	falcon_interpolation();

	falcon_play = true ;
	falcon_playIndex = 0 ;
	falcon_curr_steps = 0 ;
	}

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


		dibuja_ironman();
		
		glDisable(GL_TEXTURE_2D);

		ventiladores();

		millenary_falcon();

		television();


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
	if(falcon_play)
	{		

		if(	falcon_curr_steps >= falcon_max_steps) { //end of animation between frames? 	
			falcon_playIndex++ ;
			if( falcon_playIndex > falcon_FrameIndex - 1) { //end of total animation?
				falcon_playIndex = 0;
				falcon_play = false;
			}
			else { //Next frame falcon_interpolations
				falcon_curr_steps = 0; //Reset counter
				falcon_interpolation();
			}
		}
		else { //Draw animation
			falcon_X += falcon_KeyFrame[falcon_playIndex].falcon_X_INC;
			falcon_Y += falcon_KeyFrame[falcon_playIndex].falcon_Y_INC;
			falcon_Z += falcon_KeyFrame[falcon_playIndex].falcon_Z_INC;
			falcon_rot_X += falcon_KeyFrame[falcon_playIndex].falcon_rot_X_INC;
			falcon_rot_Y += falcon_KeyFrame[falcon_playIndex].falcon_rot_Y_INC;
			falcon_rot_Z += falcon_KeyFrame[falcon_playIndex].falcon_rot_Z_INC;
			falcon_curr_steps++;
		}
	}

	if(pong_play)
	{		

		if(	pong_curr_steps >= pong_max_steps) { //end of animation between frames? 	
			pong_playIndex++ ;
			if( pong_playIndex > pong_FrameIndex - 1) { //end of total animation?
				pong_playIndex = 0;
				pong_play = false;
			}
			else { //Next frame pong_interpolations
				pong_curr_steps = 0; //Reset counter
				pong_interpolation();
			}
		}
		else { //Draw animation
			leftbar_Y += pong_KeyFrame[pong_playIndex].leftbar_Y_INC;
			rightbar_Y += pong_KeyFrame[pong_playIndex].rightbar_Y_INC;
			ball_X += pong_KeyFrame[pong_playIndex].ball_X_INC;
			ball_Y += pong_KeyFrame[pong_playIndex].ball_Y_INC;

			pong_curr_steps++;
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
			//length = length + 0.l;
			//printf("(%f,%f,%f)", length,height,depth);
			break;
		case 'O':
			//length = length - 0.l;
			//printf("(%f,%f,%f)", length, height, depth);
			break;
		case 'l':
			//height = height + 0.l;
			//printf("(%f,%f,%f)", length, height, depth);
			break;
		case 'L':
			//height = height - 0.l;
			//printf("(%f,%f,%f)", length, height, depth);
			break;
		case 'k':
			//depth = depth + 0.l; 
			//printf("(%f,%f,%f)", length, height, depth);
			break;
		case 'K':
			//depth = depth - 0.l;
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

void diningroom () {

	mueble BigTable( coord_BigTable, quads_BigTable, trng_BigTable, n_vertex_BigTable, t_vertex_BigTable);
	mueble chair( coord_chair, quads_chair, trng_chair, n_vertex_chair);
	glPushMatrix();
	//chair.solid();

	//glScalef(0.004,0.004,0.004);
	glTranslatef(500.0049 , 0,-300);
	BigTable.solid();
	glPopMatrix();

}


int main ( int argc, char** argv )   // Main Function
{

	int submenu;

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Disfalcon_play Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (700, 700);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("DaJaus"); // Nombre de la Ventana
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


void getFramesValues() {


	//Se declaran los valores para los frames del vuelo del halcOn milenario
	falcon_KeyFrame[0].falcon_X = 0.000000 ;
	falcon_KeyFrame[0].falcon_Y = 0.000000 ;
	falcon_KeyFrame[0].falcon_Z = 0.000000 ;
	falcon_KeyFrame[0].falcon_rot_X = 0.000000 ;
	falcon_KeyFrame[0].falcon_rot_Y = 0.000000 ;
	falcon_KeyFrame[0].falcon_rot_Z = 0.000000 ;
	falcon_KeyFrame[1].falcon_X = 0.000000 ;
	falcon_KeyFrame[1].falcon_Y = 0.000000 ;
	falcon_KeyFrame[1].falcon_Z = -13700.000000 ;
	falcon_KeyFrame[1].falcon_rot_X = 3.000000 ;
	falcon_KeyFrame[1].falcon_rot_Y = -104.000000 ;
	falcon_KeyFrame[1].falcon_rot_Z = -58.000000 ;
	falcon_KeyFrame[2].falcon_X = 16600.000000 ;
	falcon_KeyFrame[2].falcon_Y = -700.000000 ;
	falcon_KeyFrame[2].falcon_Z = -1400.000000 ;
	falcon_KeyFrame[2].falcon_rot_X = -1.000000 ;
	falcon_KeyFrame[2].falcon_rot_Y = -179.000000 ;
	falcon_KeyFrame[2].falcon_rot_Z = -92.000000 ;
	falcon_KeyFrame[3].falcon_X = 14700.000000 ;
	falcon_KeyFrame[3].falcon_Y = -1500.000000 ;
	falcon_KeyFrame[3].falcon_Z = 20200.000000 ;
	falcon_KeyFrame[3].falcon_rot_X = -1.000001 ;
	falcon_KeyFrame[3].falcon_rot_Y = -179.000061 ;
	falcon_KeyFrame[3].falcon_rot_Z = -55.000008 ;
	falcon_KeyFrame[4].falcon_X = 14500.000000 ;
	falcon_KeyFrame[4].falcon_Y = -1800.000000 ;
	falcon_KeyFrame[4].falcon_Z = 24800.000000 ;
	falcon_KeyFrame[4].falcon_rot_X = -1.000001 ;
	falcon_KeyFrame[4].falcon_rot_Y = -255.000061 ;
	falcon_KeyFrame[4].falcon_rot_Z = -6.000065 ;
	falcon_KeyFrame[5].falcon_X = 7200.000000 ;
	falcon_KeyFrame[5].falcon_Y = 2600.000000 ;
	falcon_KeyFrame[5].falcon_Z = 26700.000000 ;
	falcon_KeyFrame[5].falcon_rot_X = -89.000000 ;
	falcon_KeyFrame[5].falcon_rot_Y = -167.000275 ;
	falcon_KeyFrame[5].falcon_rot_Z = 52.999901 ;
	falcon_KeyFrame[6].falcon_X = 7200.000000 ;
	falcon_KeyFrame[6].falcon_Y = 18100.000000 ;
	falcon_KeyFrame[6].falcon_Z = 26700.000000 ;
	falcon_KeyFrame[6].falcon_rot_X = -89.000000 ;
	falcon_KeyFrame[6].falcon_rot_Y = -167.000275 ;
	falcon_KeyFrame[6].falcon_rot_Z = 52.999901 ;
	falcon_KeyFrame[7].falcon_X = -4100.000000 ;
	falcon_KeyFrame[7].falcon_Y = 26000.000000 ;
	falcon_KeyFrame[7].falcon_Z = 32400.000000 ;
	falcon_KeyFrame[7].falcon_rot_X = 100.999992 ;
	falcon_KeyFrame[7].falcon_rot_Y = -176.000549 ;
	falcon_KeyFrame[7].falcon_rot_Z = 70.999893 ;
	falcon_KeyFrame[8].falcon_X = -4100.000000 ;
	falcon_KeyFrame[8].falcon_Y = 26000.000000 ;
	falcon_KeyFrame[8].falcon_Z = 32400.000000 ;
	falcon_KeyFrame[8].falcon_rot_X = 77.999992 ;
	falcon_KeyFrame[8].falcon_rot_Y = 173.999451 ;
	falcon_KeyFrame[8].falcon_rot_Z = 70.999893 ;
	falcon_KeyFrame[9].falcon_X = -4100.000000 ;
	falcon_KeyFrame[9].falcon_Y = 17800.000000 ;
	falcon_KeyFrame[9].falcon_Z = 32400.000000 ;
	falcon_KeyFrame[9].falcon_rot_X = 77.999992 ;
	falcon_KeyFrame[9].falcon_rot_Y = 173.999451 ;
	falcon_KeyFrame[9].falcon_rot_Z = 122.999893 ;
	falcon_KeyFrame[10].falcon_X = -4100.000000 ;
	falcon_KeyFrame[10].falcon_Y = 2800.000000 ;
	falcon_KeyFrame[10].falcon_Z = 32400.000000 ;
	falcon_KeyFrame[10].falcon_rot_X = 77.999992 ;
	falcon_KeyFrame[10].falcon_rot_Y = 173.999451 ;
	falcon_KeyFrame[10].falcon_rot_Z = 19.999893 ;
	falcon_KeyFrame[11].falcon_X = -4100.000000 ;
	falcon_KeyFrame[11].falcon_Y = -2200.000000 ;
	falcon_KeyFrame[11].falcon_Z = 32400.000000 ;
	falcon_KeyFrame[11].falcon_rot_X = 208.000000 ;
	falcon_KeyFrame[11].falcon_rot_Y = 497.999451 ;
	falcon_KeyFrame[11].falcon_rot_Z = 19.999893 ;
	falcon_KeyFrame[12].falcon_X = -13300.000000 ;
	falcon_KeyFrame[12].falcon_Y = -2200.000000 ;
	falcon_KeyFrame[12].falcon_Z = 22700.000000 ;
	falcon_KeyFrame[12].falcon_rot_X = 208.000000 ;
	falcon_KeyFrame[12].falcon_rot_Y = 535.999451 ;
	falcon_KeyFrame[12].falcon_rot_Z = -39.000107 ;
	falcon_KeyFrame[13].falcon_X = -13300.000000 ;
	falcon_KeyFrame[13].falcon_Y = -2200.000000 ;
	falcon_KeyFrame[13].falcon_Z = -5400.000000 ;
	falcon_KeyFrame[13].falcon_rot_X = 208.000000 ;
	falcon_KeyFrame[13].falcon_rot_Y = 535.999451 ;
	falcon_KeyFrame[13].falcon_rot_Z = -3.000107 ;
	falcon_KeyFrame[14].falcon_X = -13300.000000 ;
	falcon_KeyFrame[14].falcon_Y = -2200.000000 ;
	falcon_KeyFrame[14].falcon_Z = -16200.000000 ;
	falcon_KeyFrame[14].falcon_rot_X = 222.000000 ;
	falcon_KeyFrame[14].falcon_rot_Y = 595.999451 ;
	falcon_KeyFrame[14].falcon_rot_Z = -66.000107 ;
	falcon_KeyFrame[15].falcon_X = 400.000000 ;
	falcon_KeyFrame[15].falcon_Y = -2300.000000 ;
	falcon_KeyFrame[15].falcon_Z = -20100.000000 ;
	falcon_KeyFrame[15].falcon_rot_X = 200.000183 ;
	falcon_KeyFrame[15].falcon_rot_Y = 682.000488 ;
	falcon_KeyFrame[15].falcon_rot_Z = 182.000046 ;
	falcon_KeyFrame[16].falcon_X = 7500.000000 ;
	falcon_KeyFrame[16].falcon_Y = 4100.000000 ;
	falcon_KeyFrame[16].falcon_Z = -20500.000000 ;
	falcon_KeyFrame[16].falcon_rot_X = 200.000046 ;
	falcon_KeyFrame[16].falcon_rot_Y = 711.002075 ;
	falcon_KeyFrame[16].falcon_rot_Z = 185.000275 ;
	falcon_KeyFrame[17].falcon_X = 7500.000000 ;
	falcon_KeyFrame[17].falcon_Y = 4100.000000 ;
	falcon_KeyFrame[17].falcon_Z = 5700.000000 ;
	falcon_KeyFrame[17].falcon_rot_X = 200.000046 ;
	falcon_KeyFrame[17].falcon_rot_Y = 777.002075 ;
	falcon_KeyFrame[17].falcon_rot_Z = 88.000275 ;
	falcon_KeyFrame[18].falcon_X = 0.000000 ;
	falcon_KeyFrame[18].falcon_Y = 10000.000000 ;
	falcon_KeyFrame[18].falcon_Z = 0.000000 ;
	falcon_KeyFrame[18].falcon_rot_X = 0.000000 ;
	falcon_KeyFrame[18].falcon_rot_Y = 0.000000 ;
	falcon_KeyFrame[18].falcon_rot_Z = 0.000000 ;
	falcon_KeyFrame[19].falcon_X = 0.000000 ;
	falcon_KeyFrame[19].falcon_Y = 0.000000 ;
	falcon_KeyFrame[19].falcon_Z = 0.000000 ;
	falcon_KeyFrame[19].falcon_rot_X = 0.000000 ;
	falcon_KeyFrame[19].falcon_rot_Y = 0.000000 ;
	falcon_KeyFrame[19].falcon_rot_Z = 0.000000 ;



	//Se declaran los valores para el juego de pong
	pong_KeyFrame[0].leftbar_Y = 0.200000 ;
	pong_KeyFrame[0].rightbar_Y = 5.199999 ;
	pong_KeyFrame[0].ball_X = -3.200001 ;
	pong_KeyFrame[0].ball_Y = 5.599999 ;
	pong_KeyFrame[1].leftbar_Y = 3.600001 ;
	pong_KeyFrame[1].rightbar_Y = 1.800000 ;
	pong_KeyFrame[1].ball_X = -8.799996 ;
	pong_KeyFrame[1].ball_Y = 4.200000 ;
	pong_KeyFrame[2].leftbar_Y = 0.800001 ;
	pong_KeyFrame[2].rightbar_Y = 0.800000 ;
	pong_KeyFrame[2].ball_X = -3.200001 ;
	pong_KeyFrame[2].ball_Y = 1.600005 ;
	pong_KeyFrame[3].leftbar_Y = 2.200002 ;
	pong_KeyFrame[3].rightbar_Y = 0.800001 ;
	pong_KeyFrame[3].ball_X = -8.799996 ;
	pong_KeyFrame[3].ball_Y = 2.400013 ;
	pong_KeyFrame[4].leftbar_Y = 2.200002 ;
	pong_KeyFrame[4].rightbar_Y = 3.400001 ;
	pong_KeyFrame[4].ball_X = -3.200001 ;
	pong_KeyFrame[4].ball_Y = 3.600024 ;
	pong_KeyFrame[5].leftbar_Y = 5.400002 ;
	pong_KeyFrame[5].rightbar_Y = 3.400003 ;
	pong_KeyFrame[5].ball_X = -8.799996 ;
	pong_KeyFrame[5].ball_Y = 6.000030 ;
	pong_KeyFrame[6].leftbar_Y = 5.400002 ;
	pong_KeyFrame[6].rightbar_Y = 0.800002 ;
	pong_KeyFrame[6].ball_X = -3.200001 ;
	pong_KeyFrame[6].ball_Y = 1.000048 ;
	pong_KeyFrame[7].leftbar_Y = 2.800003 ;
	pong_KeyFrame[7].rightbar_Y = 0.800001 ;
	pong_KeyFrame[7].ball_X = -8.799996 ;
	pong_KeyFrame[7].ball_Y = 3.000069 ;
	pong_KeyFrame[8].leftbar_Y = 0.200000 ;
	pong_KeyFrame[8].rightbar_Y = 5.199999 ;
	pong_KeyFrame[8].ball_X = -3.200001 ;
	pong_KeyFrame[8].ball_Y = 5.599999 ;
}