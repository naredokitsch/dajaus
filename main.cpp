//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno: NOE MARTINEZ NAREDO *****************//
//************************************************************//
//************************************************************//
//************************************************************//
#include "Main.h"
#include "texture.h"
#include "init.cpp"
#include "dibujo.cpp"

int screenW = 0.0;
int screenH = 0.0;

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_HEIGHT);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (screenW, screenH);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("DaJaus"); // Nombre de la Ventana
  //printf("Resolution H: %i \n", screenW);
  //printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}
