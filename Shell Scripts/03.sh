#!/bin/bash

for var in "$@"
do
	echo "Creating file $var"
	touch $var
done
