#!/bin/bash

tres=3
numberOfVertices=$(grep "v " $1 | wc -l); 
fichier=$(echo $1 | cut -d. -f1)

#echo $numberOfVertices
vertices=( $(cat $1 | grep "v " | sed 's/v *//g') )
faces=( $(cat $1 | grep "f " | sed 's/f *//g'  | sed 's/\// /g') )

#echo ${#vertices[@]} # numero de elementos en array
#echo $(( ${#vertices[@]} / tres))

if [ $numberOfVertices -eq $(( ${#vertices[@]} / tres)) ]; then
	echo "vertices checked!"
	echo float coo_$fichier [] = { $(echo ${#vertices[@]} ${vertices[@]} | sed 's/ / , /g' | tr -d '\r' | tr -d '\n') "} ;" > $fichier.cpp
	echo int fac_$fichier [] = { $(echo ${#faces[@]} ${faces[@]} | sed 's/ / , /g' | tr -d '\r' | tr -d '\n') "} ;" >> $fichier.cpp
fi


