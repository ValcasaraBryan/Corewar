#!/bin/sh

cor=".cor"
dir="champs"

mkdir -p tev_dir
mkdir -p zaz_dir
for f in $dir/*.s
do
	./zaz $f >/dev/null 2>&1
	if [ -f "$(echo $f | rev | cut -c3- | rev)$cor" ]
	then
		hexdump -C $(echo $f | rev | cut -c3- | rev)$cor > zaz_dir/$(echo $f | cut -c8- | rev | cut -c3- | rev)
		rm -f $(echo $f | rev | cut -c3- | rev)$cor
	fi
	./tev $f >/dev/null 2>&1
	echo "$(valgrind --leak-check=yes ./tev -a $f >/dev/null 2>&1 | grep lost)"
	if [ -f "$(echo $f | rev | cut -c3- | rev)$cor" ]
	then
		hexdump -C $(echo $f | rev | cut -c3- | rev)$cor > tev_dir/$(echo $f | cut -c8- | rev | cut -c3- | rev)
		rm -f $(echo $f | rev | cut -c3- | rev)$cor
	fi
	if [ -f zaz_dir/$(echo $f | cut -c8- | rev | cut -c3- | rev) ] & [ -f tev_dir/$(echo $f | cut -c8- | rev | cut -c3- | rev) ]
	then
		diff -s zaz_dir/$(echo $f | cut -c8- | rev | cut -c3- | rev) tev_dir/$(echo $f | cut -c8- | rev | cut -c3- | rev)
	elif [ -f tev_dir/$(echo $f | cut -c8- | rev | cut -c3- | rev) ]
	then
		echo "WARNING : $(echo $f | cut -c8- | rev | cut -c3- | rev) created by tev but not zaz"
	elif [ -f zaz_dir/$(echo $f | cut -c8- | rev | cut -c3- | rev) ]
	then
		echo "WARNING : $(echo $f | cut -c8- | rev | cut -c3- | rev) created by zaz but not tev"
	fi
done
rm -rf tev_dir
rm -rf zaz_dir
