cor=".cor"
dir="champs"

make
echo "" > result
rm $dir/*$cor
for f in $dir/*.s
do
    echo "moi :"
    valgrind --leak-check=full ./asm $f
    echo "zaz :"
    ./../ressources/asm $f
    echo ""
done