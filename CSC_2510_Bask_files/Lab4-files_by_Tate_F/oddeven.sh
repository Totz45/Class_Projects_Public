#!/bin/bash
minute=$(date +%-M) #number of minutes
if [[ $(($minute%2)) -eq 1 ]]
then
	echo "The time is odd"
else
	echo "The time is even"
fi
