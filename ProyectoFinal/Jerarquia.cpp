//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//
#include<Windows.h>
#include<MMSystem.h>

#include "texture.h"
#include "figuras.h"
#include "Camera.h"


#include "cmodel/CModel.h"

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
int deltaTime = 0;

float height = 1.1;
float length = 1.1;
float depth = 1.1;

#if (_MSC_VER >= 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


									//NEW// Keyframes
									//Variables de dibujo y manipulacion
									//float posX =0, posY = 2.5, posZ =-3.5, rotRodIzq = 0;
float MovPato2 = -3.5;
float MovPato1, MovPato3 = 0;
float ventana2 = 9;//9   28
float ventana3 = -10;//-10    29
float offset = 0;
float cortinaizq = 1;
float cortinader = 0;
int i = 0;
float rotacion = 180;

bool prendertele = false;
bool prenderwii = false;
bool puertaabierta = false;
bool puertacerrada = false;
bool inundacion = false;

bool cortinacerrada = true;

bool cortinaabierta = false;
bool g_fanimacion = false;
bool g_fanimacion2 = false;
bool g_fanimacion3 = false;
bool g_fanimacion4 = false;


int PosAlien = 0;



CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font = (int)GLUT_BITMAP_HELVETICA_18;


//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = { 18 };

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = { 22 };

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01


				//NEW///////////////////////////7
CTexture textJuego;
CTexture textZelda1;
CTexture textZelda2;
CTexture textCosas1;
CTexture textCosasRopero;
CTexture textCosasNegro;
CTexture textCosasNegro2;
CTexture textCobija;
CTexture textventana;
CTexture textfachada;
CTexture textColadera;
CTexture textPared;
CTexture textMesa;
CTexture textPata;
CTexture textWall;
CTexture textSilla;
CTexture textTecho;
CTexture textMarble;
CTexture textPiso;
CTexture textGlassWasser;
CTexture textBarrote;
CTexture textPoster1;
CTexture textPoster2;
CTexture textPoster3;
CTexture textPoster4;
CTexture textPoster5;
CTexture textPoster6;
CTexture textPoster7;
CTexture textPoster8;
CTexture textPoster9;
CTexture textPoster10;
CTexture textPoster11;
CTexture textRopero;
CTexture textCajon1;
CTexture textCajon2;
CTexture textCajon3;
CTexture textCajon4;
CTexture textPuertaRopero;
CTexture textRevista;
CTexture textJuegos;
CTexture textShini;
CTexture textAlien;
CTexture textTransparente;
CTexture textPelea;

CTexture textMarco;
CTexture textLibroCG;
CTexture textPB;
CTexture textPuerta;
CTexture textPuerta_princ;
CTexture textMarco_1;
CTexture textMarco_2;
CTexture textMarco_3;
CTexture textGrass;
CTexture textSky;
CTexture textLibrero;
CTexture textPisoA;


CTexture textAlmohada;
CTexture textColcha;
CTexture textMaderaBuro;
CTexture textMaderaCama;
CTexture textLampara;
CTexture textLaptop;
CTexture textPantalla;
CTexture textTeclado;
CTexture textTouchPad;
CTexture textGW;
CTexture textClairo;

CFiguras tablaMesa;
CFiguras pata1Mesa;
CFiguras pata2Mesa;
CFiguras pata3Mesa;
CFiguras pata4Mesa;
CFiguras asientoSilla;
CFiguras respaldoSilla1;
CFiguras respaldoSilla2;
CFiguras respaldoSilla3;
CFiguras respaldoSilla4;
CFiguras techoCasa;
CFiguras pisoCasa;
CFiguras cubo;
CFiguras sky;
CFiguras pared;
CFiguras mueble;
CFiguras cama;
CFiguras buro;
CFiguras cono;
CFiguras lampara;
CFiguras laptop;
CFiguras figuras;
//char Poster[];
float abrirPuertaR = 0;
float abrirPuerta = 0;
float abrircajones = -3.5;
float abrircajones2 = -6;

//END NEW//////////////////////////////////////////

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito

				//modelos
CModel silla;
CModel carrito;
CModel crt;
CModel wii;
CModel sofa;
CModel sofa2;
CModel gc;
CModel ojos;


void arbol()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
	glAlphaFunc(GL_GREATER, 0.1);
	//glEnable(GL_BLEND);     // Turn Blending On
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, textMaderaBuro.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
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
	glNormal3f(0.0f, 0.0f, 1.0f);
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
	glNormal3f(0.0f, 0.0f, 1.0f);
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
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glDisable(GL_BLEND);        // Turn Blending Off
	//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glEnable(GL_LIGHTING);

	glPopMatrix();
}


void libros(void) {
	glPushMatrix();
	glTranslatef(-1, -8, 25);
	cubo.prisma(1, 2, 2, textLibroCG.GLindex);
	glPopMatrix();

	glPushMatrix();
	glRotatef(30, 0, 1, 0);
	glTranslatef(-10, -8, 25);
	//cubo.prisma(.7,2,2, textPB.GLindex);
	glPopMatrix();
	return;
}
//END CASA////////////////////////////////////


//void tele() {
//	glTranslatef(-7, -15.2, -38);
//	mueble.prisma(.5, 17, 7.5, textMarco.GLindex);
//	glTranslatef(0, 1, -1);
//	mueble.prisma(2, 3, 3, textMarco.GLindex);
//	glTranslatef(0, 9, 1);
//	mueble.prisma(17.5, 30, 1.5, textMarco.GLindex);
//	glTranslatef(0, 0, .5);
//	mueble.prisma(15.5, 28, 1.1, textClairo.GLindex);
//
//}



//void muebletele(){
//
//	glPushMatrix();
//	glTranslatef(-15,-27.8,-38);
//	mueble.prisma(23, 1, 10, textMaderaBuro.GLindex);
//	glTranslatef(16.5, 0, 0);
//	mueble.prisma(23, 1, 10, textMaderaBuro.GLindex);
//	glTranslatef(-8.25,12, 0);
//	mueble.prisma(1, 20, 10, textMaderaBuro.GLindex);
//	glTranslatef(0, -11, 0);
//	mueble.prisma(1, 16.5, 10, textMaderaBuro.GLindex);
//	glPopMatrix();
//}
//
//void mueblerevistas(){
//
//	glPushMatrix();
//	glTranslatef(10, -27.8, -38);
//	mueble.prisma(23, 1, 10, textMaderaBuro.GLindex);
//	glTranslatef(13, 0, 0);
//	mueble.prisma(23, 1, 10, textMaderaBuro.GLindex);
//	glTranslatef(-6.5, 12, 0);
//	mueble.prisma(1, 15, 10, textMaderaBuro.GLindex);
//	glTranslatef(0, -21, 0);
//	mueble.prisma(1, 12.5, 10, textMaderaBuro.GLindex);
//	glPopMatrix();
//}
//
//void ropero() {
//	glPushMatrix();
//	glEnable(GL_ALPHA_TEST); //para la transparencia
//	glAlphaFunc(GL_GREATER, .1f);
//	glTranslatef(-33, 12, 73.8);
//	glRotated(270, 1, 0, 0);
//	cubo.prismaJ(13, 32, 16, textCosasRopero.GLindex, textTransparente.GLindex);
//	glDisable(GL_ALPHA_TEST);
//		glPopMatrix();
//
//
//	glPushMatrix();
//	glTranslatef(-50, -12, 70);
//	mueble.prisma(33, 1, 19, textRopero.GLindex);
//	glTranslatef(1.2, -3, -9);
//	mueble.prisma(39, 2.5, 1, textRopero.GLindex);
//	glTranslatef(33, 3, 9);
//	mueble.prisma(33, 1, 19, textRopero.GLindex);
//	glTranslatef(-1.2, -3, -9);
//	mueble.prisma(39, 2.5, 1, textRopero.GLindex);
//	glTranslatef(0, 0, 17.5);
//	mueble.prisma(39, 2.5, 1, textRopero.GLindex);
//	glTranslatef(-32, 0, 0);
//	mueble.prisma(39, 2.5, 1, textRopero.GLindex);
//	glTranslatef(16, 3, .5);
//	mueble.prisma(33, 33, 1, textRopero.GLindex);
//	glTranslatef(0, 16.2, -9);
//	mueble.prisma(1, 34.9,20, textRopero.GLindex);//arriba
//	glTranslatef(0, -32.4, 0);
//	mueble.prisma(1, 33, 18, textRopero.GLindex);//abajo
//
//	glTranslatef(-7, 16, -9);
//	mueble.prisma(33, 16.5, 1, textRopero.GLindex);//frente
//	//cajones	
//		glTranslatef(0, -4, 0);
//		glPushMatrix();
//		glRotated(180,0,1,0);
//		glTranslatef(0, 8, abrircajones); //abrir cajones
//		mueble.prismaJ(6, 14, 10, textRopero.GLindex, textCajon2.GLindex);//cajon2
//		glTranslatef(0, 7.5, 0);
//		mueble.prismaJ(6, 14, 10, textRopero.GLindex, textCajon1.GLindex);//cajon1
//		glTranslatef(0, -22, 0);
//		mueble.prismaJ(6, 14, 10, textRopero.GLindex, textCajon4.GLindex);//cajon4
//		glTranslatef(0, 7.3, 0);
//		mueble.prismaJ(6, 14, 10, textRopero.GLindex, textCajon3.GLindex);//cajon3
//		glPopMatrix();
//
//	glTranslatef(22, 4.2, 0);
//	glRotated(abrirPuertaR, 0, 1, 0);
//	glTranslatef(-7, 0, 0);
//	mueble.prismaJ(33, 13.5, 1, textPuertaRopero.GLindex, textRopero.GLindex);//puerta
//	glPopMatrix();
//
//}


void mueblecama() {
	glScalef(1, .9, 1);
	glTranslatef(0, -3.5, 0);
	glPushMatrix();
	glTranslatef(38, -16, 74.5);
	glTranslatef(1.2, -3, -9);
	mueble.prisma(31, 2.5, 1, textMaderaBuro.GLindex);
	glTranslatef(29, 3, 7);
	glTranslatef(-1.2, -3, -7);
	mueble.prisma(31, 2.5, 1, textMaderaBuro.GLindex);

	glTranslated(0, 0, -4.5);
	glTranslatef(0, 0, 18);
	mueble.prisma(31, 2.5, 1, textMaderaBuro.GLindex);
	glTranslatef(-28, 0, 0);
	mueble.prisma(31, 2.5, 1, textMaderaBuro.GLindex);
	glTranslatef(16, 3, .5);

	glTranslatef(-2, 8, -7.5);
	mueble.prisma(8.5, 30.4, 14.5, textMaderaBuro.GLindex);//arriba
	glTranslatef(0, 4, 0);  //parte de arriba de lo de arriba xD
	mueble.prisma(2, 30.4, 15.5, textMaderaBuro.GLindex);//arriba
	glTranslatef(0, -20, 0);
	mueble.prisma(2, 28.4, 13, textMaderaBuro.GLindex);
	//cajones
	glTranslatef(-6, 15.5, abrircajones2);
	mueble.prisma(5, 10, 5, textMaderaBuro.GLindex);
	glTranslatef(0, 0, -3);
	mueble.esfera(1, 5, 5, textMaderaBuro.GLindex);

	glTranslatef(13, 0, 3);
	mueble.prisma(5, 10, 5, textMaderaBuro.GLindex);
	glTranslatef(0, 0, -3);
	mueble.esfera(1, 5, 5, textMaderaBuro.GLindex);

	glPopMatrix();

}


void mueblenegro() {

	glPushMatrix();
	glColor3f(.4, .4, .4);
	glScalef(1.1, 1.5, 1);
	glTranslatef(18, -12, 74);
	mueble.prisma(23, 1, 10, textMaderaBuro.GLindex);
	glTranslatef(13, 0, 0);
	mueble.prisma(23, 1, 10, textMaderaBuro.GLindex);
	glTranslatef(-6.5, 12, 0);
	mueble.prisma(1, 15, 10, textMaderaBuro.GLindex);
	glTranslatef(0, -21, 0);
	mueble.prisma(1, 12.5, 10, textMaderaBuro.GLindex);

	//cosas
	glColor3f(1, 1, 1);

	glPopMatrix();
}

void juegos() {
	glPushMatrix();
	glTranslatef(20, -30, 38);
	cubo.prisma(11, 13, 8, textJuegos.GLindex);//10 13

	glTranslatef(0, 13, 0); //shinigami
	cubo.prisma(16, 13, 8, textShini.GLindex);//
											  //lampara y demás
	glTranslatef(0, 17, 0); //cosas
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, .1f);
	glRotated(180, 0, 1, 0);
	cubo.prismaJ(16, 13, 8, textCosasNegro2.GLindex, textCosasNegro.GLindex);//
	glDisable(GL_ALPHA_TEST);

	glPopMatrix();

}

void Cama() {
	glPushMatrix();

	glColor3f(.7, 0, 0);
	glTranslatef(28, -21, 25);
	glRotated(180, 0, 0, 1);
	cama.cilindro(1, 19, 20, 0); //  radio,altura, resolucion
	glColor3f(.7, .7, 0);
	glTranslatef(0, -.5, 0);
	cama.cilindro(1.3, .4, 20, 0);

	glColor3f(.7, 0, 0);
	glTranslatef(-33, .5, 0);
	cama.cilindro(1, 19, 20, 0);
	glColor3f(.7, .7, 0);
	glTranslatef(0, -.5, 0);
	cama.cilindro(1.3, .4, 20, 0);

	glColor3f(.7, 0, 0);
	glTranslatef(0, .5, -66);
	cama.cilindro(1, 19, 20, 0);
	glColor3f(.7, .7, 0);
	glTranslatef(0, -.5, 0);
	cama.cilindro(1.3, .4, 20, 0);

	glColor3f(.7, 0, 0);
	glTranslatef(33, .5, 0);
	cama.cilindro(1, 19, 20, 0);
	glColor3f(.7, .7, 0);
	glTranslatef(0, -.5, 0);
	cama.cilindro(1.3, .4, 20, 0);
	glColor3f(1, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(44, -28, -8);
	glColor3f(.7, .7, .7);
	cama.prisma(8, 34, 64, textPared.GLindex);

	glTranslatef(0, -1, -2);
	//glColor3f(0, 0, 1);
	cama.prisma(14, 35, 58, textCobija.GLindex);

	glTranslatef(0, 8, 24);

	cama.prisma(3, 18, 14, textAlmohada.GLindex);
	glColor3f(1, 1, 1);
	glPopMatrix();



}


void cuarto(void) {
	glScalef(1, 1, 1.5);
	glPushMatrix();//pared sillon
	glTranslatef(0, 0, 43);
	pared.prismaJ(80.0, 126.0, 1, textPared.GLindex, textfachada.GLindex);
	glPopMatrix();

	glPushMatrix();//pared cama
	glRotatef(270, 0, 1, 0);
	glTranslatef(0, 0, 63);
	pared.prismaJ(80.0, 86.0, 1, textPared.GLindex, textfachada.GLindex);
	glPopMatrix();

	glPushMatrix();//pared ventana
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, -22.5, 63);
	pared.prismaJ(35.0, 86.0, 1, textPared.GLindex, textfachada.GLindex);
	glPopMatrix();

	glPushMatrix();//pared costado ventana
	glRotatef(90, 0, 1, 0);
	glTranslatef(40, 0, 63);
	pared.prismaJ(80.0, 6.0, 1, textPared.GLindex, textfachada.GLindex);

	//cortina der
	glTranslatef(-1, 0, 0);
	glTranslatef(-(cortinader / 2), 15, -2);
	pared.prisma(40.0, cortinader + 3, .5, textMarco.GLindex);
	glPopMatrix();


	glPushMatrix();//pared costado ventana
	glRotatef(90, 0, 1, 0);
	glTranslatef(-40.5, 0, 63);
	pared.prismaJ(80.0, 5.5, 1, textPared.GLindex, textfachada.GLindex);

	//cortina derecha
	glTranslatef(37.8, 0, 0);
	glTranslatef(cortinaizq / 2, 15, -2);
	pared.prisma(40.0, cortinaizq + 2, .5, textMarco.GLindex);
	glPopMatrix();


	glPushMatrix();//pared arriba ventana
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 36.7, 63);
	pared.prismaJ(6.3, 80.0, 1, textPared.GLindex, textfachada.GLindex);
	glPopMatrix();

	glPushMatrix();//cortina tubo

	glTranslatef(62, 35, -43);
	glRotatef(90, 1, 0, 0);
	cama.cilindro(.2, 48, 5, textMaderaBuro.GLindex); //  radio,altura, resolucion
	glPopMatrix();


	glPushMatrix();// ventana1
	glRotatef(90, 0, 1, 0);
	glTranslatef(28, 8.2, 63);
	glEnable(GL_ALPHA_TEST); //para la transparencia
	glAlphaFunc(GL_GREATER, .1f);
	pared.prismaJ(26.6, 19.0, 1.5, textventana.GLindex, textventana.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();// ventana2 DESLIZANTE
	glRotatef(90, 0, 1, 0);
	glTranslatef(ventana2, 8.2, 63);
	glEnable(GL_ALPHA_TEST); //para la transparencia
	glAlphaFunc(GL_GREATER, .1f);
	pared.prismaJ(26.6, 19.0, 1.5, textventana.GLindex, textventana.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();// ventana3 DEZLIZANTE
	glRotatef(90, 0, 1, 0);
	glTranslatef(ventana3, 8.2, 63);
	glEnable(GL_ALPHA_TEST); //para la transparencia
	glAlphaFunc(GL_GREATER, .1f);
	pared.prismaJ(26.6, 19.0, 1.5, textPared.GLindex, textfachada.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();// ventana4
	glRotatef(90, 0, 1, 0);
	glTranslatef(-29, 8.2, 63);
	glEnable(GL_ALPHA_TEST); //para la transparencia
	glAlphaFunc(GL_GREATER, .1f);
	pared.prismaJ(26.6, 19.0, 1.5, textPared.GLindex, textfachada.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();// ventana arriba1
	glRotatef(90, 0, 1, 0);
	glTranslatef(28, 27.5, 63);
	glEnable(GL_ALPHA_TEST); //para la transparencia
	glAlphaFunc(GL_GREATER, .1f);
	pared.prismaJ(12.5, 19.0, 1.5, textventana.GLindex, textventana.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();// ventana arriba2
	glRotatef(90, 0, 1, 0);
	glTranslatef(9, 27.5, 63);
	glEnable(GL_ALPHA_TEST); //para la transparencia
	glAlphaFunc(GL_GREATER, .1f);
	pared.prismaJ(12.5, 19.0, 1.5, textventana.GLindex, textventana.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();// ventana arriba3
	glRotatef(90, 0, 1, 0);
	glTranslatef(-10, 27.5, 63);
	glEnable(GL_ALPHA_TEST); //para la transparencia
	glAlphaFunc(GL_GREATER, .1f);
	pared.prismaJ(12.5, 19.0, 1.5, textPared.GLindex, textfachada.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();// ventana arriba4
	glRotatef(90, 0, 1, 0);
	glTranslatef(-29, 27.5, 63);
	glEnable(GL_ALPHA_TEST); //para la transparencia
	glAlphaFunc(GL_GREATER, .1f);
	pared.prismaJ(12.5, 19.0, 1.5, textPared.GLindex, textfachada.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();


	//pared del baño
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(44, 0, 10);
	pared.prismaJ(80, 38, 1, textPared.GLindex, textfachada.GLindex);
	glPopMatrix();
	//otra pared
	glPushMatrix();
	glTranslatef(-25, 0, 28);
	glRotatef(90, 0, 1, 0);
	pared.prismaJ(80, 30, 1, textPared.GLindex, textfachada.GLindex);
	glPopMatrix();

	glPushMatrix();//coladera
	glTranslatef(-43.5, -38, 33);
	techoCasa.prisma(.5, 38, 23, textColadera.GLindex);
	glPopMatrix();

	glPushMatrix();//pared encima de la puerta
	glTranslatef(-68, 0, 51);
	glRotatef(90, 0, 1, 0);
	glTranslatef(48.5, 36, 43);
	pared.prismaJ(8, 26, 1, textPared.GLindex, textfachada.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-24.5, -3, -10);//x
	glRotatef(270, 0, 1, 0);
	glRotatef(abrirPuerta - 5, 0, -10, 0);
	glTranslatef(12, 0, 0);//x
	pisoCasa.prismaJ(70, 24, 1.5, textPuerta_princ.GLindex, textPuerta.GLindex);
	//glTranslatef(0, 0, +1);
	//pisoCasa.prisma(72, 26, 1.6, textPuerta.GLindex);
	glPopMatrix();







	glPushMatrix();//pared fachada
	glRotatef(180, 0, 1, 0);
	glTranslatef(-14, 0, 43);
	pared.prismaJ(80.0, 98.0, 1, textPared.GLindex, textfachada.GLindex);
	glPopMatrix();

	glPushMatrix();//pared encima de la puerta
	glRotatef(180, 0, 1, 0);
	glTranslatef(48.5, 36, 43);
	pared.prismaJ(8, 29.5, 1, textPared.GLindex, textfachada.GLindex);
	glPopMatrix();

	glPushMatrix();//pared a lado de la puerta
	glRotatef(180, 0, 1, 0);
	glTranslatef(62, -4, 43);
	pared.prismaJ(72, 2.5, 1, textPared.GLindex, textfachada.GLindex);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0, 40, 0);
	techoCasa.prisma(.5, 126.0, 85, textTecho.GLindex);  //techo blanco
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -40, 0);
	techoCasa.prisma(.5, 126.0, 85, textPiso.GLindex);  //piso
														//glTranslatef(0, -.5, 0);
														//techoCasa.prisma(.5, 200.0, 200, textPisoA.GLindex); //aufera piso
														//glTranslatef(0, -.5, 0);
														//techoCasa.prisma(.5, 600.0, 600, text5.GLindex); //aufera piso
	glPopMatrix();



	glPushMatrix();
	glTranslatef(-60, -4, -43);//x
	glRotatef(abrirPuerta, 0, -10, 0);
	glTranslatef(12, 0, 0);//x
	pisoCasa.prismaJ(72, 26, 1.5, textPuerta_princ.GLindex, textPuerta.GLindex);
	//glTranslatef(0, 0, +1);
	//pisoCasa.prisma(72, 26, 1.6, textPuerta.GLindex);
	glPopMatrix();





	//ropero

	glPushMatrix();

	glTranslatef(56.5, 8, 55.5);
	glScalef(1, 1.5, .8);
	glRotated(270, 0, 1, 0);

	glTranslatef(-50, -12, 70);
	mueble.prisma(33, 1, 19, textRopero.GLindex);
	glTranslatef(1.2, -3, -9);
	mueble.prisma(39, 2.5, 1, textRopero.GLindex);
	glTranslatef(33, 3, 9);
	mueble.prisma(33, 1, 19, textRopero.GLindex);
	glTranslatef(-1.2, -3, -9);
	mueble.prisma(39, 2.5, 1, textRopero.GLindex);
	glTranslatef(0, 0, 17.5);
	mueble.prisma(39, 2.5, 1, textRopero.GLindex);
	glTranslatef(-32, 0, 0);
	mueble.prisma(39, 2.5, 1, textRopero.GLindex);
	glTranslatef(16, 3, .5);
	mueble.prisma(33, 33, 1, textRopero.GLindex);
	glTranslatef(0, 16.2, -9);
	mueble.prisma(1, 34.9, 20, textRopero.GLindex);//arriba
	glTranslatef(0, -32.4, 0);
	mueble.prisma(1, 33, 18, textRopero.GLindex);//abajo

	glTranslatef(-7, 16, -9);
	mueble.prisma(33, 16.5, 1, textRopero.GLindex);//frente
												   //cajones	
	glTranslatef(0, -4, 0);
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	glTranslatef(0, 8, abrircajones); //abrir cajones
	mueble.prismaJ(6, 14, 10, textRopero.GLindex, textCajon2.GLindex);//cajon2
	glTranslatef(0, 7.5, 0);
	mueble.prismaJ(6, 14, 10, textRopero.GLindex, textCajon1.GLindex);//cajon1
	glTranslatef(0, -22, 0);
	mueble.prismaJ(6, 14, 10, textRopero.GLindex, textCajon4.GLindex);//cajon4
	glTranslatef(0, 7.3, 0);
	mueble.prismaJ(6, 14, 10, textRopero.GLindex, textCajon3.GLindex);//cajon3
	glPopMatrix();

	glTranslatef(22, 4.2, 0);
	glRotated(abrirPuertaR, 0, 1, 0);
	glTranslatef(-7, 0, 0);
	mueble.prismaJ(33, 13.5, 1, textPuertaRopero.GLindex, textRopero.GLindex);//puerta
	glPopMatrix();



	//CAMA

	glPushMatrix();
	glTranslatef(-18, 0, 28);
	glScalef(1, 1, .5);


	glPushMatrix();

	glColor3f(.7, 0, 0);
	glTranslatef(28, -21, 25);
	glRotated(180, 0, 0, 1);
	cama.cilindro(1, 19, 20, 0); //  radio,altura, resolucion
	glColor3f(.7, .7, 0);
	glTranslatef(0, -.5, 0);
	cama.cilindro(1.3, .4, 20, 0);

	glColor3f(.7, 0, 0);
	glTranslatef(-33, .5, 0);
	cama.cilindro(1, 19, 20, 0);
	glColor3f(.7, .7, 0);
	glTranslatef(0, -.5, 0);
	cama.cilindro(1.3, .4, 20, 0);

	glColor3f(.7, 0, 0);
	glTranslatef(0, .5, -66);
	cama.cilindro(1, 19, 20, 0);
	glColor3f(.7, .7, 0);
	glTranslatef(0, -.5, 0);
	cama.cilindro(1.3, .4, 20, 0);

	glColor3f(.7, 0, 0);
	glTranslatef(33, .5, 0);
	cama.cilindro(1, 19, 20, 0);
	glColor3f(.7, .7, 0);
	glTranslatef(0, -.5, 0);
	cama.cilindro(1.3, .4, 20, 0);
	glColor3f(1, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(44, -28, -8);
	glColor3f(.7, .7, .7);
	cama.prisma(8, 34, 64, textPared.GLindex);

	glTranslatef(0, -1, -10);
	//glColor3f(0, 0, 1);
	cama.prisma(14, 35, 45, textCobija.GLindex);

	glTranslatef(0, 8, 31);
	cama.prisma(3, 18, 14, textAlmohada.GLindex);
	glColor3f(1, 1, 1);
	glPopMatrix();
	glPopMatrix();



	//mueble y tele
	glPushMatrix();
	glRotated(270, 0, 1, 0);
	glTranslatef(-15, 0, -20);


	glPushMatrix();//tele
	glRotatef(20, 0, 1, 0);
	glTranslatef(-5, -15.2, -42);
	glScalef(.5, .6, .6);
	mueble.prisma(.5, 17, 7.5, textMarco.GLindex);
	glTranslatef(0, 1, -1);
	mueble.prisma(2, 3, 3, textMarco.GLindex);
	glTranslatef(0, 9, 1);
	mueble.prisma(17.5, 30, 1.5, textMarco.GLindex);
	glTranslatef(0, 0, .5);
	mueble.prisma(15.5, 28, 1.1, textClairo.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(1.4, 1, 1);
	glTranslatef(-17, -27.8, -38);
	mueble.prisma(23, 1, 10, textMaderaBuro.GLindex);
	glTranslatef(16.5, 0, 0);
	mueble.prisma(23, 1, 10, textMaderaBuro.GLindex);
	glTranslatef(-8.25, 12, 0);
	mueble.prisma(1, 20, 10, textMaderaBuro.GLindex);
	glTranslatef(0, -11, 0);
	mueble.prisma(1, 16.5, 10, textMaderaBuro.GLindex);
	glPopMatrix();
	glPopMatrix();

	//otro mueblesin
	glPushMatrix();
	glTranslatef(29, 0, 0);
	glPushMatrix();
	glTranslatef(10, -27.8, -38);
	mueble.prisma(23, 1, 10, textMaderaBuro.GLindex);
	glTranslatef(13, 0, 0);
	mueble.prisma(23, 1, 10, textMaderaBuro.GLindex);
	glTranslatef(-6.5, 12, 0);
	mueble.prisma(1, 15, 10, textMaderaBuro.GLindex);
	glTranslatef(0, -21, 0);
	mueble.prisma(1, 12.5, 10, textMaderaBuro.GLindex);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_ALPHA_TEST); //para la transparencia
	glAlphaFunc(GL_GREATER, .1f);
	glPushMatrix();
	glTranslatef(16.4, -26.5, -38);
	cubo.prisma(19.5, 13, 8, textRevista.GLindex);
	glTranslatef(0, 21, -7);//comics
	cubo.prismaJ(20, 14, 8, textTransparente.GLindex, textCosas1.GLindex);


	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();








	return;
}

GLuint createDL()
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL, GL_COMPILE);
	// call the function that contains 
	// the rendering commands
	//ciudad();
	//monito();
	// endList
	glEndList();

	return(ciudadDL);
}




void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	char textt_1[] = "casa/Chair/chair.3ds";
	char textt_2[]= "casa/crt.3ds";
	char textt_3[] = "casa/Wii.3ds";
	char textt_4[] = "casa/ojos.3ds";
	char textt_5[] = "casa/duck.3ds";
	char textt_6[] = "casa/couch.3ds";
	char textt_7[] = "casa/Sofa1.3ds";
	char textt_8[] = "casa/gamecube.3ds";
	char textt_9[] = {"casa/01.tga"};
	char textt_10[] = {"casa/tele.tga"};
	char textt_11[] = {"city/pavimento.tga"};
	char textt_12[] = {"city/pasto01.tga"};
	char textt_13[] = {"city/casa01.tga"};
	char textt_14[] = {"casa/feebles.tga"};
	char textt_15[] = {"casa/mueblenegrocosas.tga"};
	char textt_16[] = {"casa/mueblenegrocosas2.tga"};
	char textt_17[] = {"casa/cosasmueble.tga"};
	char textt_18[] = {"casa/starman.tga"};
	char textt_19[] = {"casa/pelea.tga"};
	char textt_20[] = {"casa/transparente.tga"};
	char textt_21[] = {"casa/puertaF2.tga"};
	char textt_22[] = {"casa/puertaD2.tga"};
	char textt_23[] = {"casa/techo.tga"};
	char textt_24[] = {"casa/cobija.tga"};
	char textt_25[] = {"casa/pared.tga"};
	char textt_26[] = {"casa/fachada.tga"};
	char textt_27[] = {"casa/coladera.tga"};
	char textt_28[] = {"casa/ventana.tga"};
	char textt_29[] = {"casa/piso2.tga"};
	char textt_30[] = {"casa/pisoA.tga"};
	char textt_31[] = {"casa/poster1.tga"};
	char textt_32[] = {"casa/poster2.tga"};
	char textt_33[] = {"casa/poster3.tga"};
	char textt_34[] = {"casa/poster4.tga"};
	char textt_35[] = {"casa/dibujo2.tga"};
	char textt_36[] = {"casa/dibujo1.tga"};
	char textt_37[] = {"casa/evangelion.tga"};
	char textt_38[] = {"casa/conejo.tga"};
	char textt_39[] = {"casa/shenlong.tga"};
	char textt_40[] = {"casa/smash.tga"};
	char textt_41[] = {"casa/zelda1.tga"};
	char textt_42[] = {"casa/zelda2.tga"};
	char textt_43[] = {"casa/concierto.tga"};
	char textt_44[] = {"casa/madera.tga"};
	char textt_45[] = {"casa/clairo.tga"};
	char textt_46[] = {"casa/revistas.tga"};
	char textt_47[] = {"casa/juegos.tga"};
	char textt_48[] = {"casa/juegotele.tga"};
	char textt_49[] = {"casa/shini.tga"};
	char textt_50[] = {"casa/Ropero1.tga"};
	char textt_51[] = {"casa/cajon1.tga"};
	char textt_52[] = {"casa/cajon2.tga"};
	char textt_53[] = {"casa/cajon3.tga"};
	char textt_54[] = {"casa/cajon4.tga"};
	char textt_55[] = {"casa/puertaropero.tga"};
	char textt_56[] = {"casa/almohada.tga"};
	char textt_57[] = {"casa/negro.tga"};
	char textt_58[] = {"casa/blue-sky-texture.tga"};

	//glEnable(GL_BLEND);
	
	silla._3dsLoad(textt_1);
	crt._3dsLoad(textt_2);
	//wii._3dsLoad(	textt_3);
	ojos._3dsLoad(textt_4);
	carrito._3dsLoad(textt_5);
	sofa._3dsLoad(textt_6);
	sofa2._3dsLoad(textt_7);
	//gc._3dsLoad(	textt_8);


	text1.LoadTGA(textt_9);
	text1.BuildGLTexture();
	text1.ReleaseImage();


	text3.LoadTGA(textt_10);
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA(textt_11);
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA(textt_12);
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA(textt_13);
	text6.BuildGLTexture();
	text6.ReleaseImage();

	textCosas1.LoadTGA(textt_14);
	textCosas1.BuildGLTexture();
	textCosas1.ReleaseImage();

	textCosasNegro.LoadTGA(textt_15);
	textCosasNegro.BuildGLTexture();
	textCosasNegro.ReleaseImage();

	textCosasNegro2.LoadTGA(textt_16);
	textCosasNegro2.BuildGLTexture();
	textCosasNegro2.ReleaseImage();

	textCosasRopero.LoadTGA(textt_17);
	textCosasRopero.BuildGLTexture();
	textCosasRopero.ReleaseImage();


	textAlien.LoadTGA(textt_18);
	textAlien.BuildGLTexture();
	textAlien.ReleaseImage();

	textPelea.LoadTGA(textt_19);
	textPelea.BuildGLTexture();
	textPelea.ReleaseImage();

	textTransparente.LoadTGA(textt_20);
	textTransparente.BuildGLTexture();
	textTransparente.ReleaseImage();

	textPuerta_princ.LoadTGA(textt_21);
	textPuerta_princ.BuildGLTexture();
	textPuerta_princ.ReleaseImage();

	textPuerta.LoadTGA(textt_22);
	textPuerta.BuildGLTexture();
	textPuerta.ReleaseImage();

	textTecho.LoadTGA(textt_23);
	textTecho.BuildGLTexture();
	textTecho.ReleaseImage();

	textCobija.LoadTGA(textt_24);
	textCobija.BuildGLTexture();
	textCobija.ReleaseImage();

	textPared.LoadTGA(textt_25);
	textPared.BuildGLTexture();
	textPared.ReleaseImage();

	textfachada.LoadTGA(textt_26);
	textfachada.BuildGLTexture();
	textfachada.ReleaseImage();

	textColadera.LoadTGA(textt_27);
	textColadera.BuildGLTexture();
	textColadera.ReleaseImage();

	textventana.LoadTGA(textt_28);
	textventana.BuildGLTexture();
	textventana.ReleaseImage();

	textPiso.LoadTGA(textt_29);
	textPiso.BuildGLTexture();
	textPiso.ReleaseImage();

	textPisoA.LoadTGA(textt_30);
	textPisoA.BuildGLTexture();
	textPisoA.ReleaseImage();

	//posters
	textPoster1.LoadTGA(textt_31);
	textPoster1.BuildGLTexture();
	textPoster1.ReleaseImage();

	textPoster2.LoadTGA(textt_32);
	textPoster2.BuildGLTexture();
	textPoster2.ReleaseImage();

	textPoster3.LoadTGA(textt_33);
	textPoster3.BuildGLTexture();
	textPoster3.ReleaseImage();

	textPoster4.LoadTGA(textt_34);
	textPoster4.BuildGLTexture();
	textPoster4.ReleaseImage();

	textPoster9.LoadTGA(textt_35);
	textPoster9.BuildGLTexture();
	textPoster9.ReleaseImage();

	textPoster10.LoadTGA(textt_36);
	textPoster10.BuildGLTexture();
	textPoster10.ReleaseImage();

	textPoster11.LoadTGA(textt_37);
	textPoster11.BuildGLTexture();
	textPoster11.ReleaseImage();

	textPoster5.LoadTGA(textt_38);
	textPoster5.BuildGLTexture();
	textPoster5.ReleaseImage();

	textPoster6.LoadTGA(textt_39);
	textPoster6.BuildGLTexture();
	textPoster6.ReleaseImage();

	textPoster7.LoadTGA(textt_40);
	textPoster7.BuildGLTexture();
	textPoster7.ReleaseImage();

	textZelda1.LoadTGA(textt_41);
	textZelda1.BuildGLTexture();
	textZelda1.ReleaseImage();

	textZelda2.LoadTGA(textt_42);
	textZelda2.BuildGLTexture();
	textZelda2.ReleaseImage();

	textPoster8.LoadTGA(textt_43);
	textPoster8.BuildGLTexture();
	textPoster8.ReleaseImage();


	textMaderaBuro.LoadTGA(textt_44);
	textMaderaBuro.BuildGLTexture();
	textMaderaBuro.ReleaseImage();

	textClairo.LoadTGA(textt_45);
	textClairo.BuildGLTexture();
	textClairo.ReleaseImage();

	textRevista.LoadTGA(textt_46);
	textRevista.BuildGLTexture();
	textRevista.ReleaseImage();

	textJuegos.LoadTGA(textt_47);
	textJuegos.BuildGLTexture();
	textJuegos.ReleaseImage();

	textJuego.LoadTGA(textt_48);
	textJuego.BuildGLTexture();
	textJuego.ReleaseImage();

	textShini.LoadTGA(textt_49);
	textShini.BuildGLTexture();
	textShini.ReleaseImage();

	textRopero.LoadTGA(textt_50);
	textRopero.BuildGLTexture();
	textRopero.ReleaseImage();

	textCajon1.LoadTGA(textt_51);
	textCajon1.BuildGLTexture();
	textCajon1.ReleaseImage();
	textCajon2.LoadTGA(textt_52);
	textCajon2.BuildGLTexture();
	textCajon2.ReleaseImage();
	textCajon3.LoadTGA(textt_53);
	textCajon3.BuildGLTexture();
	textCajon3.ReleaseImage();
	textCajon4.LoadTGA(textt_54);
	textCajon4.BuildGLTexture();
	textCajon4.ReleaseImage();
	textPuertaRopero.LoadTGA(textt_55);
	textPuertaRopero.BuildGLTexture();
	textPuertaRopero.ReleaseImage();

	textAlmohada.LoadTGA(textt_56);
	textAlmohada.BuildGLTexture();
	textAlmohada.ReleaseImage();

	textMarco.LoadTGA(textt_57);
	textMarco.BuildGLTexture();
	textMarco.ReleaseImage();

	textSky.LoadTGA(textt_58);
	textSky.BuildGLTexture();
	textSky.ReleaseImage();





	//END NEW//////////////////////////////

	objCamera.Position_Camera(0, 2.5f, 3, 0, 2.5f, 0, 0, 1, 0);

	//objCamera.Position_Camera(0, 15, 8, 0, 8, 0, 0, 1, 0);
	// x y  z


	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();



}

void pintaTexto(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
							//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}





void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glPushMatrix();



	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);

	//apagar y prender luz xD
	/*glDisable(GL_LIGHTING);
	glColor3f(0.1, 0.1, 0.1);*/

	glTranslatef(0, -10, -50); //desplazar camara

							   ////crt
							   //glPushMatrix();
							   //glTranslatef(-32+20, 11, -10);
							   //glScalef(0.02, 0.023, 0.02);
							   //crt.GLrender(NULL, _SHADED, 1.0);
							   //
							   //glPopMatrix();

							   //wii
							   /*glPushMatrix();
							   glTranslatef(-36+20, 8.8, -8.5);
							   glScalef(0.01, 0.01, 0.01);
							   glRotated(270, 0, 1, 0);
							   wii.GLrender(NULL, _SHADED, 1.0);
							   glPopMatrix();*/



	glPushMatrix(); //Creamos cielo
	glDisable(GL_LIGHTING);
	glTranslatef(0, 60, 0);
	fig1.skybox(130.0, 130.0, 130.0, text1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();



	glPushMatrix(); ///////////con esto movi y escalé el cuarto
	glScalef(.26, .145, .15);
	glTranslatef(-25, 0, -113);


	glPushMatrix();
	glTranslatef(-12, 0, 7);
	glRotated(-45, 0, 1, 0);

	glScalef(0.06, 0.06, .06);
	silla.GLrender(NULL, _SHADED, 1.0);

	glPopMatrix();


	//pato
	glPushMatrix();
	glTranslatef(MovPato1, MovPato2, MovPato3);
	glTranslatef(2, 0, 11);
	glScalef(0.008, 0.008, 0.008);
	glRotated(rotacion, 0, 1, 0);
	carrito.GLrender(NULL, _SHADED, 1.0);

	glTranslatef(0, 130, -10);
	ojos.GLrender(NULL, _SHADED, 1.0);

	if (MovPato3 == 0 && MovPato2 == 2.5) {
		inundacion = false;
		g_fanimacion = true;
	}
	//glTranslatef(0, movKit2, movKit);

	if (MovPato3 == -16) {
		g_fanimacion = false;
		g_fanimacion2 = true;
	}
	if (MovPato1 == 15) {
		g_fanimacion2 = false;
		g_fanimacion3 = true;
	}
	if (MovPato1 == 15 && MovPato3 == -2) {
		g_fanimacion3 = false;
		g_fanimacion4 = true;
		printf("activacion falsa %f %f %f", MovPato1, MovPato2, MovPato3);
	}
	if (MovPato3 == -2 && MovPato1 == 0) {
		g_fanimacion4 = false;
		g_fanimacion = true;
		rotacion = 180;
	}


	glPopMatrix();


	//sillon
	//glPushMatrix();
	////glRotated(0, 0, 1, 0);
	//glTranslatef(-18.5+20, 0, -9);
	//glScalef(.8, 1.8, 1.5);
	//sofa2.GLrender(NULL, _SHADED, 1.0);
	//glDisable(GL_COLOR_MATERIAL);
	//glColor3f(1, 1, 1);
	////glBindTexture(GL_TEXTURE_2D, 0);
	//glPopMatrix();


	//
	///////////////////////////////////////  ALCOBA3

	//¨****casa*****
	glPushMatrix();
	glScalef(1.0, 1, 1.0);
	glTranslatef(0, 12, 0);
	glRotatef(180, 0, 1, 0);
	glDisable(GL_LIGHTING);
	glScalef(0.3, 0.3, 0.3);



	cuarto();

	////psoter1
	//glPushMatrix();
	//glTranslatef(19.5, -25,-45);   //zyx
	//glRotatef(90, 0, 1, 0);
	//poster1();
	//glPopMatrix();

	//glPushMatrix();//poster3
	//glTranslatef(19.5, -32, 6);
	//glRotatef(90, 0, 1, 0);
	//poster3();
	//glPopMatrix();

	//dibujo kh
	//glPushMatrix();
	//glTranslatef(25, -21, -.5); //xyz
	//glRotatef(180, 0, 1, 0);
	////poster4();
	//glPopMatrix();

	/*conejo();
	posterganon();
	shenlong();
	poster7();
	poster8();*/
	//juegos();
	//muebletele();
	//Cama();
	//mueblerevistas();

	//revistas();

	//tele();
	//ropero();
	/*mueblecama();
	mueblenegro();*/

	glEnable(GL_LIGHTING);
	glPopMatrix();

	if (abrirPuerta == 90) {
		puertaabierta = false;
	}

	if (abrirPuerta == 0) {
		puertacerrada = false;
	}

	if (cortinaizq == 20) {
		cortinaabierta = false;
	}

	if (cortinaizq == 0) {
		cortinacerrada = false;
	}



	glPushMatrix();



	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
	{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
	{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
	{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
	{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
	{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
	{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
	{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};
	//TELE
	glPushMatrix();
	glRotated(90, 0, 1, 0);//TRASLADAR TELEVISION
						   //glTranslatef(1,-1.1,-8);
	glScalef(.6, .6, .6);
	glTranslatef(-2, 3.7, -19);

	glPushMatrix();
	glTranslatef(-32 + 20, 11, -10);
	glScalef(0.02, 0.023, 0.02);
	crt.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	if (prendertele) {
		glTranslatef(20, 0, 0);
		glPushMatrix(); //ruido
						//glRotated(90,1,0,0);
		glTranslated(-32, 11.3, -10.3);//x z y
		glScalef(4.3, 3.4, 4);
		glDisable(GL_LIGHTING);

		if (prenderwii) {
			glBindTexture(GL_TEXTURE_2D, textJuego.GLindex);
			glBegin(GL_POLYGON);	//Front
									//glColor3f(0.0,0.0,1.0);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f - (offset * 2), 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(0.0f - (offset * 2), 1.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f - (offset * 2), 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f - (offset * 2), 0.0f); glVertex3fv(vertice[1]);
			glEnd();
			glBindTexture(GL_TEXTURE_2D, 0);
			glEnable(GL_LIGHTING);
		}
		else
		{
			glBindTexture(GL_TEXTURE_2D, text3.GLindex);
			glBegin(GL_POLYGON);	//Front
									//glColor3f(0.0,0.0,1.0);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f + offset, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f + offset, 0.0f); glVertex3fv(vertice[1]);
			glEnd();
			glBindTexture(GL_TEXTURE_2D, 0);
			glEnable(GL_LIGHTING);
		}

		glPopMatrix();
	}


	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glPopMatrix();



	//STARMAN
	if (ventana2 >= 27) {//VENTANAS ABIERTAS
						 //if (ventana3 >= -28) {//CERRADAS
						 //cancion =true;

		PosAlien = 3;
		glTranslatef(20, 0, 0);

		glPushMatrix();
		glRotated(180, 0, 1, 0);
		glDisable(GL_LIGHTING);
		glTranslatef(37, 10, PosAlien - 5); //POSICION ALIEN 3
		glEnable(GL_ALPHA_TEST); //para la transparencia
		glAlphaFunc(GL_GREATER, .1f);
		glRotated(270, 0, 1, 0);
		cubo.prismaJ(20, 8, .5, textTransparente.GLindex, textAlien.GLindex);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
		//printf("se prendio la musica?");

		/////

		glPushMatrix(); //FONDOPELEA
						//glRotated(90,1,0,0);
		glTranslated(0, 0, -21);//x z y 
		glScalef(40, 40, 40);
		glDisable(GL_LIGHTING);


		glBindTexture(GL_TEXTURE_2D, textPelea.GLindex);//TEXTURAS DE PELEA

														//glBindTexture(GL_TEXTURE_2D, texture[filter]);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
								//glColor3f(0.0,0.0,1.0);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f + offset, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.0f, 1.0f - offset); glVertex3fv(vertice[4]);
		glTexCoord2f(1.0f, 1.0f + offset); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0f - offset, 0.0f); glVertex3fv(vertice[1]);
		glEnd();

		glPushMatrix();
		glTranslatef(0, 0, .9);
		glRotated(90, 0, 0, 1);
		glBegin(GL_POLYGON);	//Front
								//glColor3f(0.0,0.0,1.0);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f - offset, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.0f, 1.0f + offset); glVertex3fv(vertice[4]);
		glTexCoord2f(1.0f, 1.0f - offset); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0f + offset, 0.0f); glVertex3fv(vertice[1]);
		glEnd();

		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, .84, 1);
		glRotated(90, 1, 0, 0);
		glBegin(GL_POLYGON);	//Front
								//glColor3f(0.0,0.0,1.0);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f - offset, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.0f, 1.0f + offset); glVertex3fv(vertice[4]);
		glTexCoord2f(1.0f, 1.0f + offset); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0f - offset, 0.0f); glVertex3fv(vertice[1]);
		glEnd();

		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0.26, 1);
		glRotated(90, 1, 0, 0);
		glBegin(GL_POLYGON);	//Front
								//glColor3f(0.0,0.0,1.0);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f + offset, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.0f, 1.0f + offset); glVertex3fv(vertice[4]);
		glTexCoord2f(1.0f, 1.0f + offset); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0f + offset, 0.0f); glVertex3fv(vertice[1]);
		glEnd();

		glPopMatrix();
		//glBindTexture(GL_TEXTURE_2D, 0);
		//glPopMatrix();

		////
		glTranslatef(-.2, 0, 1);
		glRotated(90, 0, 1, 0);
		glBegin(GL_POLYGON);	//Front
								//glColor3f(0.0,0.0,1.0);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f + offset, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.0f, 1.0f + offset); glVertex3fv(vertice[4]);
		glTexCoord2f(1.0f, 1.0f + offset); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0f + offset, 0.0f); glVertex3fv(vertice[1]);
		glEnd();
		//glBindTexture(GL_TEXTURE_2D, 0);
		//glPopMatrix();

		glTranslatef(0, 0, -.6);
		//glRotated(180, 0, 1, 0);
		glBegin(GL_POLYGON);	//Front
								//glColor3f(0.0,0.0,1.0);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f + offset, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.0f, 1.0f + offset); glVertex3fv(vertice[4]);
		glTexCoord2f(1.0f, 1.0f + offset); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0f + offset, 0.0f); glVertex3fv(vertice[1]);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
		glPopMatrix();



		glEnable(GL_LIGHTING);

		glPopMatrix();
		//}
	}
	else //VENTANAS CERRADAS
	{
		glRotated(180, 0, 1, 0);
		glTranslatef(20, 0, 0);

		PosAlien = -30;
		//cancion = false;
		/*printf("prendida");
		PlaySound(TEXT("casa/starman.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);///cancion de los cojones*/
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glRotated(270, 0, 1, 0);
		glTranslatef(0, 10, PosAlien);   //POSICION ALIENA -30
		glEnable(GL_ALPHA_TEST); //para la transparencia
		glAlphaFunc(GL_GREATER, .1f);
		cubo.prismaJ(20, 8, .5, textTransparente.GLindex, textAlien.GLindex);
		glDisable(GL_ALPHA_TEST);

		glEnable(GL_LIGHTING);

		glPopMatrix();
		////////////////////////////////////////////////////

	}

	glPopMatrix();





	glPushMatrix();

	glTranslatef(0, 0, 0);
	figuras.prisma(0.1, 100, 100, text3.GLindex);
	glPopMatrix();
	glEnable(GL_LIGHTING);

	glPushMatrix(); // Arquitectura de la casa
					//glScalef(3, 3, 3);
	glTranslatef(5, 1.75, 0);
	glPushMatrix(); // Cocina, Sala Comedor
	glPushMatrix();
	glTranslatef(-2.3, -1.6, 7);
	figuras.prisma(0.001, 17.5, 14, 0);//Suelo 
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
	glTranslatef(-1.5, 0, -3);
	figuras.prisma(3.5, 3, 0.1, 0);	// Muro Horizontal banio
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
	figuras.prisma(0.1, 10, 21.01, 0);
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
	glutSwapBuffers();

}






void animacion()
{
	offset -= .001;
	fig3.text_izq -= 0.001;
	fig3.text_der -= 0.001;
	if (offset<-1)
		offset = 0;
	if (offset<0)
		offset = 1;

	if (puertaabierta)
	{
		abrirPuerta += 1.0;
	}

	if (puertacerrada)
	{
		abrirPuerta -= 1.0;
	}

	if (cortinaabierta)
	{
		cortinader += 1.0;
		cortinaizq += 1.0;
	}

	if (cortinacerrada)
	{
		cortinader -= 1.0;
		cortinaizq -= 1.0;
	}
	//pato recorrido
	if (inundacion) {
		MovPato2 += .5;
	}

	if (g_fanimacion)
	{

		MovPato3 -= .25;
	}

	if (g_fanimacion2)
	{
		rotacion = 90;
		MovPato1 += .25;
	}
	if (g_fanimacion3)
	{
		rotacion = 0;
		MovPato3 += .25;
	}
	if (g_fanimacion4)
	{
		rotacion = 270;
		MovPato1 -= .25;
	}





	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);
		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		break;

	case 'd':
	case 'D':

		objCamera.Strafe_Camera(CAMERASPEED + 0.4);
		break;

	case 'b':
		abrirPuertaR--;

		break;

	case 'B':

		abrirPuertaR++;
		break;

	case 'C'://///////////////////////////////////////////////////////////////
		abrircajones--;
		abrircajones2++;
		break;
	case 'c':
		abrircajones++;
		abrircajones2--;
		break;

	case 'V'://///////////////////////////////////////////////////////////////

		prenderwii ^= true;

		break;
	case 'v':

		if (abrirPuerta == 90) {
			puertacerrada = true;
		}
		puertaabierta = true;

		break;

	case 'p':
		ventana2++;
		//ventana3--;

		if (ventana2 == 27) {
			PlaySound(TEXT("casa/starman.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);///cancion de los cojones*/
		}

		break;

	case 'P':
		ventana2--;
		//ventana3++;
		if (ventana2 < 27) {
			PlaySound(NULL, NULL, 0);
		}

		break;

	case ' ':		//Poner algo en movimiento
		prendertele ^= true; //Activamos/desactivamos la animacíon

		break;

	case 'N':
		//cortinaizq++;
		//cortinader++;
		break;
	case 'n':
		if (cortinaizq == 20) {
			cortinacerrada = true;
			//cortinaabierta = false;
		}
		cortinaabierta = true;

		//cortinaizq--;
		//cortinader--;
		break;

	case'h':
		inundacion = true;
		//MovPato2++;
		//printf("%f    ", MovPato2);
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
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
		objCamera.Rotate_View(CAMERASPEED);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}




void menu(int id)
{

}

int main(int argc, char** argv)   // Main Function
{
	//int submenu;
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(700, 700);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Proyecto"); // Nombre de la Ventana
								  //glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);


	glutMainLoop();          // 

	return 0;
}