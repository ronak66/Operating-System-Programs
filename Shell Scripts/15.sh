#!/bin/bash

# 1
file_path=$1
echo -n "Search pattern: "
read search_pattern
cat $file_path | grep $search_pattern

# 2
sed -n '/'$search_pattern'/p' $file_path 

# 3
echo -n "Second search pattern: "
read second_pattern
cat $file_path | grep "^$search_pattern" | grep "$second_paatern$"

# 4
echo -n "Line number: "
read number
sed -n $number',$p' $file_path

# 5
echo -n "Replace pattern: "
read replace_pattern
sed -i -e 's/'$search_pattern'/'$replace_pattern'/g' $file_path

# 6
echo "string to insert at the beginning of each line:"
read string
sed 's/^/'$string'/' $file_path

# 7
echo "string to insert at the end of each line:"
read string_end
sed 's/$/'$string_end'/' $file_path


