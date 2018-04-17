UNA CASA

Este programa pretende diseñar una casa de acuerdo a las especificaciones del proyecto Proyecto_Final_2018_2.pdf y al plano escogido en el archivo plano_casa.jpeg.

El archivo principal lleva el nombre de main.cpp. Contiene la función main, así como los callbacks necesarios para openGL. También comprende directivas incluyendo otros archivos con los que se trabajan.

El archivo init.cpp contiene las funciones utilizadas por los callbacks. Dentro de las configuraciones de estas funciones se determinaron las siguientes teclas y su uso

		W  ------  zoom in
		S  ------  zoom out
		H  ------  left
		L  ------  right
		J  ------  down
		J  ------  up


		left-right arrows -------- Rotate Z
		up-down arrows -------- Rotate X

El archivo some_functions.cpp llevará las diferentes funciones de dibujo.

dibuja.cpp será el archivo con la función en la que se programará la secuencia de dibujo.

obj2array.sh es un programa en bash que toma los vértices de archivos OBJ y los convierte en un arreglo.

	Ejemplo:

		nombre_archivo.obj   ----->   nombre_archivo.cpp

		donde nombre_archivo.cpp contiene:

				float nombre_archivo [] = { cantidad_de_coordenadas*3, x , y , z , x , y , z , . . . , x , y , z , x , y , z} ;










