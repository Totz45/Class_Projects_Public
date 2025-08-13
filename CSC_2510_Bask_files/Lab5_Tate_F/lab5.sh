#!/bin/bash


check_file_for_newline() {
	[[ -s "$1" && -z "$(tail -c 1 $1)" ]]
}

if [ $# -ne 2 ]
then
	echo "You need 2 arguments to execute this program"
	echo "Usage: Argument1(file) Argument2(username)"
	exit 1
fi

if ! [ -f "$1" ]
then
	echo "The file $1 does not exist"
	exit 1
fi

while read line
do
	if [[ $line == $2 ]]
	then
		echo "$2 is already in the file"
		exit 1
	fi	
done<$1

echo "$2 does not exist in the file. Appending to end"

if ! check_file_for_newline $1 2 3
then
        echo "" >> $1
fi

echo $2 >> $1

while read line
do
	echo "$line"       
done<$1

if ! check_file_for_newline $1 2 3
then
        echo "" >> $1
fi
