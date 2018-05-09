
#include <iostream>
#include <math.h>

using namespace std;

class figura {

	//static float white [3] = {1.0,1.0,1.0};
	float* coordenadas;
	int* reglaUnion;
	float escala;
	//int coordenadasLength = 0;

	public:

		figura(float* coord, int* regla){
			coordenadas = coord;
			reglaUnion = regla;
			//int coordenadasLength = sizeof(coordenadas)/sizeof(float);
			//escala = escala_0;

			//cout << "coordenadasLength = " << coordenadas[0] << endl;
		}

		void cloudPoints () {	


			//glPointSize(10);


			glBegin(GL_POINTS);
				for (int i = 3 ; i <= (int)coordenadas[0] ; i+=3 ) {
					glVertex3f(coordenadas[i - 2] , coordenadas[i - 1] , coordenadas[i]);
				}
			glEnd();
		}

		void mesh () {
			glBegin(GL_LINES);
				for (int i = 4 ; i <= (int)reglaUnion[0] ;  i+=6) {
					if (true){
						glVertex3f(coordenadas[(reglaUnion[i - 3] * 3) - 2] , coordenadas[(reglaUnion[i - 3] * 3) - 1] , coordenadas[reglaUnion[i - 3] * 3]);
						glVertex3f(coordenadas[(reglaUnion[i] * 3) - 2] , coordenadas[(reglaUnion[i] * 3) - 1] , coordenadas[reglaUnion[i] * 3]);
					}
				}
			glEnd();
		}

		void quads () {
			glBegin(GL_QUADS);
				for (int i = 4 ; i <= (int)reglaUnion[0] ;  i+=6) {
					if (true){
						glVertex3f(coordenadas[(reglaUnion[i - 3] * 3) - 2] , coordenadas[(reglaUnion[i - 3] * 3) - 1] , coordenadas[reglaUnion[i - 3] * 3]);
						glVertex3f(coordenadas[(reglaUnion[i] * 3) - 2] , coordenadas[(reglaUnion[i] * 3) - 1] , coordenadas[reglaUnion[i] * 3]);
					}
				}
			glEnd();
		}
/*
		void solid () {

			glBegin(GL_TRIANGLES);
				for (int i = 1 ; i <= (int)reglaUnion[0] ; i+=3 ) {
					glVertex3f(coordenadas[(reglaUnion[i] * 3) - 2] , coordenadas[(reglaUnion[i] * 3) - 1] , coordenadas[reglaUnion[i] * 3]);

				}
			glEnd();

		}
*/

};

