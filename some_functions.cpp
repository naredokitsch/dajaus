
float white [] = {1.0,1.0,1.0};

void dibuja_puntos (float* coordenadas , float tam = 1.0 , float kolor [] = white  ) {
	glColor3f(kolor[0],kolor[1],kolor[2]);
	glPointSize(tam);

	glBegin(GL_POINTS);
		for (int i = 1 ; i < (coordenadas[0] - 2) ; i+=3 ) {
			glVertex3f(coordenadas[i] , coordenadas[i + 1] , coordenadas[i + 2]);
		}
	glEnd();
}

