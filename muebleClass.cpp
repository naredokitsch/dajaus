
#include <iostream>

using namespace std;

class mueble {

	float* c;  //Coordenadas de la nube de puntos del mueble
	float* n;  //Vectores Normales
	float* x;  //Vertices de Textura

	int* q;	   //Regla de Union de para QUADS
	int* t;	   //Regla de Union para TRIANGLES

	public:
		mueble(float* coordenadas, int* quadrilateral, int* triangles, float* normals) {
			c = coordenadas;
			q = quadrilateral;
			t = triangles;
			n = normals;
		}

		mueble(float* coordenadas, int* quadrilateral, int* triangles, float* normals, float* v_textura) {
			c = coordenadas;
			q = quadrilateral;
			t = triangles;
			n = normals;
			x = v_textura;
		}

		void cloudPoints () {
			glColor3f(0,1,0);
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
					glBegin(GL_LINE_LOOP);
						glVertex3f(c[(q[i - 9] * 3) - 2] , c[(q[i - 9] * 3) - 1] , c[q[i - 9] * 3]);
						glVertex3f(c[(q[i - 6] * 3) - 2] , c[(q[i - 6] * 3) - 1] , c[q[i - 6] * 3]);
						glVertex3f(c[(q[i - 3] * 3) - 2] , c[(q[i - 3] * 3) - 1] , c[q[i - 3] * 3]);
						glVertex3f(c[(q[i] * 3) - 2] , c[(q[i] * 3) - 1] , c[q[i] * 3]);
					glEnd();
				}
			}
			
			glColor3f(1,0,0);

			if(t[0] > 0) {
				for (i = 7 ; i <= t[0] ;  i+=9) {
					glBegin(GL_LINE_LOOP);
						glVertex3f(c[(t[i - 6] * 3) - 2] , c[(t[i - 6] * 3) - 1] , c[t[i - 6] * 3]);
						glVertex3f(c[(t[i - 3] * 3) - 2] , c[(t[i - 3] * 3) - 1] , c[t[i - 3] * 3]);
						glVertex3f(c[(t[i] * 3) - 2] , c[(t[i] * 3) - 1] , c[t[i] * 3]);
					glEnd();
				}
			}
			
			glColor3f(0,0,0);
		}

		void solid () {
			int i = 0;
			if(q[0] > 0) {
				for (i = 10 ; i <= q[0] ;  i+=12) {
					glBegin(GL_QUADS);
						glNormal3f(n[(q[i - 7] * 3) - 2] , n[(q[i - 7] * 3) - 1] , n[q[i - 7] * 3]) ; glVertex3f(c[(q[i - 9] * 3) - 2] , c[(q[i - 9] * 3) - 1] , c[q[i - 9] * 3]);
						glNormal3f(n[(q[i - 4] * 3) - 2] , n[(q[i - 4] * 3) - 1] , n[q[i - 4] * 3]) ; glVertex3f(c[(q[i - 6] * 3) - 2] , c[(q[i - 6] * 3) - 1] , c[q[i - 6] * 3]);
						glNormal3f(n[(q[i - 1] * 3) - 2] , n[(q[i - 1] * 3) - 1] , n[q[i - 1] * 3]) ; glVertex3f(c[(q[i - 3] * 3) - 2] , c[(q[i - 3] * 3) - 1] , c[q[i - 3] * 3]);
						glNormal3f(n[(q[i + 2] * 3) - 2] , n[(q[i + 2] * 3) - 1] , n[q[i + 2] * 3]) ; glVertex3f(c[(q[i] * 3) - 2] , c[(q[i] * 3) - 1] , c[q[i] * 3]);
					glEnd();
				}
			}

			if(t[0] > 0) {
				for (i = 7 ; i <= t[0] ;  i+=9) {
					glBegin(GL_TRIANGLES);
						glNormal3f(n[(t[i - 4] * 3) - 2] , n[(t[i - 4] * 3) - 1] , n[t[i - 4] * 3]) ; glVertex3f(c[(t[i - 6] * 3) - 2] , c[(t[i - 6] * 3) - 1] , c[t[i - 6] * 3]);
						glNormal3f(n[(t[i - 1] * 3) - 2] , n[(t[i - 1] * 3) - 1] , n[t[i - 1] * 3]) ; glVertex3f(c[(t[i - 3] * 3) - 2] , c[(t[i - 3] * 3) - 1] , c[t[i - 3] * 3]);
						glNormal3f(n[(t[i + 2] * 3) - 2] , n[(t[i + 2] * 3) - 1] , n[t[i + 2] * 3]) ; glVertex3f(c[(t[i] * 3) - 2] , c[(t[i] * 3) - 1] , c[t[i] * 3]);
					glEnd();
				}
			}
		}


		void texturized() {
			int i = 0;
			if(q[0] > 0) {
					glBegin(GL_QUADS);
					for (i = 1 ; i <= q[0] ;  i+=3) {
						glTexCoord2f(x[(q[i + 1] * 2) - 1] , x[q[i + 1] * 2]) ; glNormal3f(n[(q[i + 2] * 3) - 2] , n[(q[i + 2] * 3) - 1] , n[q[i + 2] * 3]) ; glVertex3f(c[(q[i] * 3) - 2] , c[(q[i] * 3) - 1] , c[q[i] * 3]);
					}
					glEnd();
			}

			if(t[0] > 0) {
					glBegin(GL_TRIANGLES);
					for (i = 1 ; i <= t[0] ;  i+=3) {
						glTexCoord2f(x[(t[i + 1] * 2) - 1] , x[t[i + 1] * 2]) ; glNormal3f(n[(t[i + 2] * 3) - 2] , n[(t[i + 2] * 3) - 1] , n[t[i + 2] * 3]) ; glVertex3f(c[(t[i] * 3) - 2] , c[(t[i] * 3) - 1] , c[t[i] * 3]);
					}
					glEnd();
				
			}
		}

};