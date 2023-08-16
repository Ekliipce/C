#!/bin/sh

[ "$2" != "triangle" ] && [ "$2" != "square" ] || [ $# -ne 2 ] || [ $1 -lt 0 ] &&
    exit 1

count=0
echo " _________________"

while [ $count -ne "$1" ]
do
        if [ "$2" = "square" ]
        then
            echo "|  ___       ___  |"
            echo "| |_|_|     |_|_| |"
            echo "| |_|_|     |_|_| |"
            echo "|                 |"
        else
            echo "|                 |"
            echo "|   /\\       /\\   |"
            echo "|  /__\\     /__\\  |"
            echo "|                 |"
        fi
        count=$(($count + 1))
done

echo "|        _        |"
echo "|       | |       |"
echo "|       | |       |"
echo "|_______| |_______|"
exit 0