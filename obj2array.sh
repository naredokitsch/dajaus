#!/bin/bash

tres=3
numberOfVertices=$(grep "v " $1 | wc -l); 
fichier=$(echo $1 | cut -d. -f1)

#echo $numberOfVertices
vertex=( $(cat $1 | grep "v " | sed 's/v *//g') )
quads=( $(cat $1 | sed 's/\/\//\/0\//g' | grep -o "^f *[0-9]*/[0-9]*/[0-9]* *[0-9]*/[0-9]*/[0-9]* *[0-9]*/[0-9]*/[0-9]* *[0-9]*/[0-9]*/[0-9]* *$" | sed 's/f *//g' | sed 's/\// /g') )
trng=( $(cat $1 | sed 's/\/\//\/0\//g' | grep -o "^f *[0-9]*/[0-9]*/[0-9]* *[0-9]*/[0-9]*/[0-9]* *[0-9]*/[0-9]*/[0-9]* *$" | sed 's/f *//g' | sed 's/\// /g') )

#echo ${#vertices[@]} # numero de elementos en array
#echo $(( ${#vertices[@]} / tres))

if [ $numberOfVertices -eq $(( ${#vertex[@]} / tres)) ]; then
	echo "vertex checked!"
	echo float coord_$fichier [] = { $(echo ${#vertex[@]} ${vertex[@]} | sed 's/ / , /g' | tr -d '\r' | tr -d '\n') "} ;" > $fichier.cpp
	echo int quads_$fichier [] = { $(echo ${#quads[@]} ${quads[@]} | sed 's/ / , /g' | tr -d '\r' | tr -d '\n') "} ;" >> $fichier.cpp
	echo int trng_$fichier [] = { $(echo ${#trng[@]} ${trng[@]} | sed 's/ / , /g' | tr -d '\r' | tr -d '\n') "} ;" >> $fichier.cpp
fi


