.name "Virtual"
.comment "Tu t'es fait effacer de la virtualisation !"

coucou:
live %1229539649
ld 2147483647, r2
ld %2147483647, r2
st r2, 2147483647
add r1, r2, r2
sub r1, r2, r2
and 2147483647, 2147483647, r2
or 2147483647, 2147483647, r2
xor 2147483647, 2147483647, r2
zjmp %44444
ldi 2147483647, %2147483647, r2
sti r1, %2147483647, %2147483647
fork %2147483647
lld 2147483647, r1
lld %2147483647, r1
lldi 2147483647, %2147483647, r2
lfork %2147483647
lldi :label, %:label, r2
aff r99
label:
    live %1
