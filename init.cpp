float transX = 0.0f;
float transY = 0.0f;
float transZ = -20.0f;


float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;


void InitGL ( void )     // Inicializamos parametros
{




	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
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
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 400.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}



void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.3f;
			break;
		case 's':
		case 'S':
			transZ -= 0.3f;
			break;
		case 'l':
		case 'L':
			transX +=0.3f;
			break;
		case 'h':
		case 'H':
			transX -=0.3f;
			break;
		case 'k':
		case 'K':
			transY +=0.3f;
			break;
		case 'j':
		case 'J':
			transY -=0.3f;
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
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 10.0f;
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 10.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY += 10.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 10.0f;
		break;
	case GLUT_KEY_PAGE_DOWN:
		angleZ -= 10.0f;
		break;
	case GLUT_KEY_PAGE_UP:
		angleZ += 10.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}