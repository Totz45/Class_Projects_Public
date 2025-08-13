#!/bin/bash
month=$(date +%-m) #number of months
minute=$(date +%-M) #number of minutes
numOfLoops=$(($month+$minute)) #number of loops equals month + minutes
for (( i=1; i <= $numOfLoops; ++i))
do
	echo "Iteration $i out of $numOfLoops. $(($numOfLoops-$i)) iterations remaining"
done
