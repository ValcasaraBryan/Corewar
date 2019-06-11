.name "Virtual"
.comment "Tu t'es fait effacer de la virtualisation !"


ld 1, %5, :salut
ld 1 ,%2, :salut
ld 1 ,%2, salut
and 1
or 1
xor 1
zjmp 2
ldi 4
sti 1
lldi 1
fork 1
aff 1
st r2, 15     #  salut          
st r1, 14#               coucou
st r1, :lewe#               coucou
st r1, %:lewe#               coucou
    #salut lld %5 , r9
        # 50


        #s
lewe:
