.name "Virtual"
.comment "Tu t'es fait effacer de la virtualisation !"


ld 1, r2
deuxie:
ld 1 , r2
ld 1 ,r2
and 1, 1, r2
or 1, 1, r2
xor 1,1 ,r2
zjmp %2
ldi %4, %5, r1
sti r1, %1, r2
lldi 1, r2, r1
fork %1
aff r1
st r2, 15     #  salut          
st r1, 14#               coucou
st r1, 5#               coucou
st r1, r1 #coucou
