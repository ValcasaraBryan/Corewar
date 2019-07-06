cor=".cor"
dir="champs"

make
rm result_diff.txt
mv asm tev
mv ../ressources/asm zaz
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
	echo "$(valgrind --leak-check=yes ./tev -a $f >/dev/null 2>&1 | grep lost)" 2>> result_diff.txt >> result_diff.txt 
	if [ -f "$(echo $f | rev | cut -c3- | rev)$cor" ]
	then
		hexdump -C $(echo $f | rev | cut -c3- | rev)$cor > tev_dir/$(echo $f | cut -c8- | rev | cut -c3- | rev)
		rm -f $(echo $f | rev | cut -c3- | rev)$cor
	fi
	if [ -f zaz_dir/$(echo $f | cut -c8- | rev | cut -c3- | rev) ] & [ -f tev_dir/$(echo $f | cut -c8- | rev | cut -c3- | rev) ]
	then
		diff -s zaz_dir/$(echo $f | cut -c8- | rev | cut -c3- | rev) tev_dir/$(echo $f | cut -c8- | rev | cut -c3- | rev) 2>> result_diff.txt >> result_diff.txt 
	elif [ -f tev_dir/$(echo $f | cut -c8- | rev | cut -c3- | rev) ]
	then
		echo "WARNING : $(echo $f | cut -c8- | rev | cut -c3- | rev) created by tev but not zaz" 2>> result_diff.txt >> result_diff.txt 
	elif [ -f zaz_dir/$(echo $f | cut -c8- | rev | cut -c3- | rev) ]
	then
		echo "WARNING : $(echo $f | cut -c8- | rev | cut -c3- | rev) created by zaz but not tev" >> result_diff.txt
	else
        echo "OK $(echo $f | cut -c8- | rev | cut -c3- | rev)" 2>> result_diff.txt >> result_diff.txt 
    fi
done
rm -rf tev_dir
rm -rf zaz_dir
mv tev asm
mv zaz ../ressources/asm