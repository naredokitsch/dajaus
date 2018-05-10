#!/bin/bash

arr=$((grep -o ' [0-9]*/[0-9]* ' $1))

for i in "${arr[@]}"
do
	echo $i
done