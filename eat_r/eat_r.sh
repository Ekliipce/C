#!/bin/sh

count=1

for i in "$@";do
    if [ "$count" -eq "$#" ]; then
        echo -n "$i" | tr -d 'r''R'
    else
        echo -n "$i," | tr -d 'r''R'
    fi
    count=$(($count+1))
done
echo
exit 0