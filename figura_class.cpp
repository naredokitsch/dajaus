
#include <iostream>

using namespace std;

class figura {

	//static float white [3] = {1.0,1.0,1.0};
	float* coordenadas;
	float escala;
	//int coordenadasLength = 0;

	public:

		figura(float* coordenadas_0, float escala_0 = 1.0){
			coordenadas = coordenadas_0;
			//int coordenadasLength = sizeof(coordenadas)/sizeof(float);
			escala = escala_0;

			cout << "coordenadasLength = " << coordenadas[0] << endl;
		}

		void cloudPoints () {
			//glColor3f(kolor[0],kolor[1],kolor[2]);
			//glPointSize(tam_punto);	

			glBegin(GL_POINTS);
				for (int i = 1 ; i < (coordenadas[0] - 2) ; i+=3 ) {
					glVertex3f(coordenadas[i] , coordenadas[i + 1] , coordenadas[i + 2]);
				}
			glEnd();
		}
};

