#!/bin/sh

cut -d " " -f 1 ~/.bash_history | sort | uniq -c | sort -g -r | head -n 10 |
while read -r line; 
do
    echo "$line"
done