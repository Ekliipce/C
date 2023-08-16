#! /bin/sh

[ $# -ne 1 ] && exit 1;
if test ! -r $1
then
    exit 1;
fi

while IFS= read -r line
do
    curr=$(echo "$line" | wc -c)
    if [ $curr -gt 80 ]
    then
        printf "%s\n" "$line"
    fi
done < $1
exit 0
