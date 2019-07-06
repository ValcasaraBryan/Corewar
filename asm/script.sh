cor=".cor"
dir="champs/*"
dir_2="asm_test/*/*"

make
echo "" > result
rm $dir_2$cor
for f in $dir_2.s
do
    echo $f >> result
    echo "moi :" >> result
    ./asm $f 2>> result >> result
    echo "zaz :" >> result
    ./../ressources/asm $f 2>> result >> result
    echo "" >> result
    echo "" >> result
    echo "done $f"
done
echo "done result"
echo "" > result_2
rm $dir$cor
for f in $dir.s
do
    echo $f >> result_2
    echo "moi :" >> result_2
    ./asm $f 2>> result_2 >> result_2
    echo "zaz :" >> result_2
    ./../ressources/asm $f 2>> result_2 >> result_2
    echo "" >> result_2
    echo "" >> result_2
    echo "done $f"
done
echo "done result_2"
echo "done all"