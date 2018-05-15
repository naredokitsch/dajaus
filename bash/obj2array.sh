#!/bin/bash

tres=3
zero=0
numberOfVertices=$(grep "v " $1 | wc -l); 
fichier=$(echo $1 | cut -d. -f1)

echo hola1

#echo $numberOfVertices
vertex=( $(cat $1 | grep "v " | sed 's/v *//g') )
n_vertex=( $(cat $1 | grep "vn " | sed 's/vn *//g') )
t_vertex=( $(cat $1 | grep -Eo "^vt *-?[0-9]*.?[0-9]* *-?[0-9]*.?[0-9]*" | sed 's/vt *//g') )
quads=( $(cat $1 | sed 's/\/\//\/0\//g' | grep -oE "^f *-?[0-9]*/-?[0-9]*/-?[0-9]* *-?[0-9]*/-?[0-9]*/-?[0-9]* *-?[0-9]*/-?[0-9]*/-?[0-9]* *-?[0-9]*/-?[0-9]*/-?[0-9]* *.?$" | sed 's/f *//g' | sed 's/\// /g' | sed 's/.$//g') )
trng=( $(cat $1 | sed 's/\/\//\/0\//g' | grep -oE "^f *-?[0-9]*/-?[0-9]*/-?[0-9]* *-?[0-9]*/-?[0-9]*/-?[0-9]* *-?[0-9]*/-?[0-9]*/-?[0-9]* *.?$" | sed 's/f *//g' | sed 's/\// /g' | sed 's/.$//g') )

#echo coord_$fichier = $((${#vertex[@]} / 3 ))
echo hola2


# for (( i = 0; i <= ${#quads[@]}; i+=3 )) ; do
#     if (( zero  >  quads[i] )) ; then
#     	quads[i]=$(( ( ${#vertex[@]} / 3 ) + ${quads[i]} + 1 ))
#         #echo revirtiendo quads
#     fi

#     if (( zero  >  quads[$((i + 1))] )) ; then
#     	quads[$((i + 1))]=$(( ( ${#t_vertex[@]} / 2 ) + ${quads[$((i + 1))]} + 1 ))
#     fi

#     if (( zero  >  quads[$((i + 2))] )) ; then
#     	quads[$((i + 2))]=$(( ( ${#n_vertex[@]} / 3 ) + ${quads[$((i + 2))]} + 1 ))
#     fi
# done

echo hola3


# for (( i = 0; i <= ${#trng[@]}; i+=3 )) ; do
#     if (( zero  >  trng[i] )) ; then
#     	trng[i]=$(( ( ${#vertex[@]} / 3 ) + ${trng[i]} + 1 ))
#         #echo revirtiendo triangles
#     fi

#     if (( zero  >  trng[$((i + 1))] )) ; then
#     	trng[$((i + 1))]=$(( ( ${#t_vertex[@]} / 2 ) + ${trng[$((i + 1))]} + 1 ))
#     fi

#     if (( zero  >  trng[$((i + 2))] )) ; then
#     	trng[$((i + 2))]=$(( ( ${#n_vertex[@]} / 3 ) + ${trng[$((i + 2))]} + 1 ))
#     fi
# done

echo hola4

if [ $numberOfVertices -eq $(( ${#vertex[@]} / tres)) ]; then
	echo "vertex checked!"

	echo float coord_$fichier [] = { $(echo ${#vertex[@]} ${vertex[@]} | sed 's/ / , /g' | tr -d '\r' | tr -d '\n') "} ;" > $fichier.cpp
	echo coord_$fichier = ${#vertex[@]}

	echo float t_vertex_$fichier [] = { $(echo ${#t_vertex[@]} ${t_vertex[@]} | sed 's/ / , /g' | tr -d '\r' | tr -d '\n') "} ;" >> $fichier.cpp
	echo t_vertex_$fichier = ${#t_vertex[@]}

	echo float n_vertex_$fichier [] = { $(echo ${#n_vertex[@]} ${n_vertex[@]} | sed 's/ / , /g' | tr -d '\r' | tr -d '\n') "} ;" >> $fichier.cpp
	echo n_vertex_$fichier = ${#n_vertex[@]}

	echo int quads_$fichier [] = { $(echo ${#quads[@]} ${quads[@]} | sed 's/ / , /g' | tr -d '\r' | tr -d '\n') "} ;" >> $fichier.cpp
	echo quads_$fichier = ${#quads[@]}

	echo int trng_$fichier [] = { $(echo ${#trng[@]} ${trng[@]} | sed 's/ / , /g' | tr -d '\r' | tr -d '\n') "} ;" >> $fichier.cpp
	echo trng_$fichier = ${#trng[@]}
fi


