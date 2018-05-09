
#include <iostream>
#include <math.h>

using namespace std;

class figura {

	//static float white [3] = {1.0,1.0,1.0};
	float* c;
	int* q;
	int* t;

	float escala;
	//int coordenadasLength = 0;

	public:

		figura(float* coordenadas, int* quadrilateral, int* triangles){
			c = coordenadas;
			q = quadrilateral;
			t = triangles;
			//int coordenadasLength = sizeof(coordenadas)/sizeof(float);
			//escala = escala_0;

			//cout << "coordenadasLength = " << coordenadas[0] << endl;
		}

		void cloudPoints () {	
			glBegin(GL_POINTS);
				for (int i = 3 ; i <= (int)c[0] ; i+=3 ) {
					glVertex3f(c[i - 2] , c[i - 1] ,c[i]);
				}
			glEnd();
		}

		void mesh () {
			glBegin(GL_LINES);
				for (int i = 4 ; i <= (int)q[0] ;  i+=6) {
					if (true){
						glVertex3f(c[(q[i - 3] * 3) - 2] , c[(q[i - 3] * 3) - 1] , c[q[i - 3] * 3]);
						glVertex3f(c[(q[i] * 3) - 2] , c[(q[i] * 3) - 1] , c[q[i] * 3]);
					}
				}
			glEnd();
		}

		void quads () {
			glBegin(GL_QUADS);
				for (int i = 4 ; i <= (int)q[0] ;  i+=6) {
					if (true){
						glVertex3f(c[(t[i - 3] * 3) - 2] , c[(t[i - 3] * 3) - 1] , c[t[i - 3] * 3]);
						glVertex3f(c[(t[i] * 3) - 2] , c[(t[i] * 3) - 1] , c[t[i] * 3]);
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

