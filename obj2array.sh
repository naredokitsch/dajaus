#!/bin/bash

tres=3
numberOfVertices=$(grep "v " $1 | wc -l); 
fichier=$(echo $1 | cut -d. -f1)

#echo $numberOfVertices
vertices=( $(cat $1 | grep "v " | sed 's/v *//g') )

#echo ${#vertices[@]} # numero de elementos en array
#echo $(( ${#vertices[@]} / tres))

if [ $numberOfVertices -eq $(( ${#vertices[@]} / tres)) ]; then
	echo "vertices checked!"
	echo float $fichier [] = { $(echo ${#vertices[@]} ${vertices[@]} | sed 's/ / , /g' | tr -d '\r' | tr -d '\n') "} ;" > $fichier.cpp
fi


