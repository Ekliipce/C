#!/bin/sh

file=$1
nbr=$2
n=1

[ "$#" -eq 2 ] &&
    while read line 
    do
        if [ $n -eq $nbr ] 
        then
            val1=$(echo $line | sed -n "s/[^;]*;\([^;]*\);.*/\1/p")
            val2=$(echo $line | sed -n "s/[^;]*;[^;]*;\([^;]*\).*/\1/p")
            echo $val1 is $val2
        fi
        n=$(($n+1))
    done < $file