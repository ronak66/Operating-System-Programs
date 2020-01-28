#!/bin/bash

echo -n "number: "
read number
for ((i = 0 ; i < 11 ; i++)); do
	echo $number x  $i = $(($number * $i))
done

