#!/bin/bash

x=1
k=$1
while [ $x -le 10 ]
do
	ARG=$(python3 getrandom.py $k);
	# echo "$ARG"
	./push_swap $ARG | wc -l
	x=$(( $x + 1 ))

done
