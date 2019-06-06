.name "Virtual"
.comment "Tu t'es fait effacer de la virtualisation !"


ld 1, %5 _salut
ld 1 ,%2, :salut
ld 1 ,%2, salut
st r2, 15     #  salut          
st r1, 14#               coucou
st r1, :lewe#               coucou
st r1, %:lewe#               coucou
    #salut lld %5 , r9
        # 50


        #s
lewe:
