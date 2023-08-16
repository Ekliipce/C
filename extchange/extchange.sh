#! /bin/sh

[ $# -ne 2 ] && echo "Usage: extchange.sh 'ext1' 'ext2'" && exit 1

for i in *.$1
do
    [ $i = "*.$1" ] && exit 2
    mv $i "${i%.*}.$2"
    echo "mv $i "${i%.*}.$2""
done
exit 0