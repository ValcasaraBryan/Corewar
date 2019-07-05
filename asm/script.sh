cor=".cor"
dir="asm_test"

make
echo "" > result
rm $dir/*/*$cor
for f in $dir/*/*.s
do
    echo "moi :"
    ./asm $f
    echo "zaz :"
    ./../ressources/asm $f
    echo ""
done