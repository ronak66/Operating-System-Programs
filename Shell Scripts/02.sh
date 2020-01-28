#!/bin/bash
if [ "$#" == 3 ]
then
	echo "$1 $2 $3"
else
	echo "Error: More than three arguments"
fi
