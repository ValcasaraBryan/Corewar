cor=".cor"
dir="test_asm/champs"

rm $dir/*$cor
for f in $dir/*.s
do
    echo "moi :"
    ./asm $f
    echo "zaz :"
    ./../ressources/asm $f
    echo ""
done