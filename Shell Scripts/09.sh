#!/bin/bash

echo -n "Input filename: "
read file_name
echo -n "Input starting line number: "
read start
echo -n "Input ending line number: "
read end
sed -n "$start","$end"p $file_name
