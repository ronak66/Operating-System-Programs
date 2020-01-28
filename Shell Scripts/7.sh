#!/bin/bash

echo -n "Input (1-Copying, 2-Removing, 3-Rename): "
read ans
if [ $ans == "1" ]; then
	echo "file_path:"
	read file_path
	echo "copy_path:"
	read copy_path
	cp $file_path $copy_path
elif [ $ans == "2" ]; then
	echo "file_path"
	rm $filepath
elif [ $ans == "3" ]; then
	echo file_name
	read file_name
	echo new_name
	read new_name
	mv $file_name $new_name
fi

