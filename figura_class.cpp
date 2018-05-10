
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

			int i = 0;

			glColor3f(0,1,0);
			
			if(q[0] > 0) {
				for (i = 10 ; i <= q[0] ;  i+=12) {
				//printf("i = %i\n",i);
					glBegin(GL_LINE_LOOP);
						glVertex3f(c[(q[i - 9] * 3) - 2] , c[(q[i - 9] * 3) - 1] , c[q[i - 9] * 3]);
						glVertex3f(c[(q[i - 6] * 3) - 2] , c[(q[i - 6] * 3) - 1] , c[q[i - 6] * 3]);
						glVertex3f(c[(q[i - 3] * 3) - 2] , c[(q[i - 3] * 3) - 1] , c[q[i - 3] * 3]);
						glVertex3f(c[(q[i] * 3) - 2] , c[(q[i] * 3) - 1] , c[q[i] * 3]);
					glEnd();
				//	printf("%i\t=>   %f , %f , %f \n", q[i - 9] , c[(q[i - 9] * 3) - 2] , c[(q[i - 9] * 3) - 1] , c[q[i - 9] * 3]);
				//	printf("%i\t=>   %f , %f , %f \n", q[i - 6] , c[(q[i - 6] * 3) - 2] , c[(q[i - 6] * 3) - 1] , c[q[i - 6] * 3]);
				//	printf("%i\t=>   %f , %f , %f \n", q[i - 3] ,c[(q[i - 3] * 3) - 2] , c[(q[i - 3] * 3) - 1] , c[q[i - 3] * 3]);
				//	printf("%i\t=>   %f , %f , %f \n\n\n\n" , q[i],c[(q[i] * 3) - 2] , c[(q[i] * 3) - 1] , c[q[i] * 3]);
				}
			}
			
			glColor3f(1,0,0);

			if(t[0] > 0) {
				for (i = 7 ; i <= t[0] ;  i+=9) {
				//printf("i = %i\n",i);
					glBegin(GL_LINE_LOOP);
						glVertex3f(c[(t[i - 6] * 3) - 2] , c[(t[i - 6] * 3) - 1] , c[t[i - 6] * 3]);
						glVertex3f(c[(t[i - 3] * 3) - 2] , c[(t[i - 3] * 3) - 1] , c[t[i - 3] * 3]);
						glVertex3f(c[(t[i] * 3) - 2] , c[(t[i] * 3) - 1] , c[t[i] * 3]);
					glEnd();
				}
			}
			
			glColor3f(0,0,0);
		}

		void quads () {
			glBegin(GL_QUADS);
				for (int i = 4 ; i <= (int)q[0] ;  i+=6) {
					glVertex3f(c[(t[i - 3] * 3) - 2] , c[(t[i - 3] * 3) - 1] , c[t[i - 3] * 3]);
					glVertex3f(c[(t[i] * 3) - 2] , c[(t[i] * 3) - 1] , c[t[i] * 3]);
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

