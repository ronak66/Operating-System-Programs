#!/bin/bash

time=$(date "+%H")
if [ $time -lt 12 ]; then
	echo "Good Morning"
elif [ $time -lt 5 ]; then
	echo "Good Afternoon"
else
	echo "Good Evening"
fi

