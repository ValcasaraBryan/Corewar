Ce projet Corewar est le dernier projet avant de partir en stage.

Le but etait de créer une arène dans laquelle 2 champions ou plus doivent se battre à mort pour remporter la victoire.
Pour se faire, chaque combattant dois déclarer qu'il est en vie; le dernier à l'avoir fait, à la fin du cycle, peut se déclarer victorieux.

Pour compiler les programmes lancer la commande :
- make

Utilisez un champion disponible, ou créez en un, avec l'extension ".s" et utilisez l'asm pour compiler le champions ce qui fourniras un champions avec l'extension ".cor"

./asm Monchampion.s

Utilisez ensuite l'arène pour lancer le combat

./corewar Monchampion.cor Monchampion_2.cor

Pour plus de clartée, utilisez les options disponible.

-v              visualisateur

Logiciels utils :
- sdl2          brew install sdl2
- sdl2_ttf      brew install sdl2_ttf

Si besoin modifiez le makefile pour accéder au chemin d'acces du framework (FLAGS_LIB_SDL)

Systeme d'exploitation :

Mac OSX

VALCASARA Bryan 24/08/2019
