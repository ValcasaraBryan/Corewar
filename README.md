Ce projet Corewar est le dernier projet avant de partir en stage.

Le but était de créer une arène dans laquelle 2 champions ou plus doivent se battre à mort pour remporter la victoire.
Pour se faire, chaque combattant dois déclarer qu'il est en vie; le dernier à l'avoir fait, à la fin du cycle, peut se déclarer victorieux.

Pour compiler les programmes lancez la commande :
- make

Utilisez un champion disponible, ou créez en un, avec l'extension ".s" et utilisez l'asm pour compiler le champion ce qui fournira un champion avec l'extension ".cor"

Le pseudo code champion est en assembleur :

Les paramètres d'instructions sont uniquement : DIRECT, INDIRECT ou REGISTRE et ne depasse pas un entier sur 4 octets

Les instructions sont uniquement : live, ld, st, add, sub, and, or, xor, zjmp, ldi, sti, fork, lld, lldi, lfork ou aff.

Pour plus d'informations sur les instructions lire le fichier "op.c" dans les sources.

exemple :

ld %65535, r2

live %1

./asm Monchampion.s

Utilisez ensuite l'arène pour lancer le combat

./corewar Monchampion.cor Monchampion_2.cor

Pour plus de clartée, utilisez les options disponible.

-v              visualisateur

Logiciels utils :
- sdl2
- sdl2_ttf

Tout est disponible avec brew

Si besoin modifiez le makefile pour accéder au chemin d'acces du framework (FLAGS_LIB_SDL)

Systeme d'exploitation :

Mac OSX

VALCASARA Bryan 24/08/2019
