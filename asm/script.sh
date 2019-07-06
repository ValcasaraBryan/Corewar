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
for f in $dir.s
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
echo "done all"