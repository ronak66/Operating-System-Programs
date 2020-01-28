#!/bin/bash

# arrgumrnt 1 : file name
# arrgument 2 : pattern

#8
awk '{print;}' $1

#9
awk "/$2/" $1

#10
awk '{print $2;}' $1

# 11
awk 'BEGIN {print "Name\tDesignation\tDepartment\tSalary";}
{print $2,"\t",$3,"\t",$4,"\t",$NF;}
END {print "Report Generated\n";
}' $1

# 12
awk '$1 > 200' $1

# 13
awk '{print $2;}' $1
awk '$4 ~/Technology/' $1

# 14
awk 'BEGIN { count=0;
$4 ~ /Technology/ { count++; }

