#!/bin/bash

## Bash afin de d'éxecuter le code éléments finis pour le problème que l'utilisateur souhaite résoudre.

clear
clear


gfortran -c ./FonctionsFortran/*.f -std=legacy && mv *.o ./FonctionsFortran 
gcc -Wall ./FonctionC/*.c ./FonctionC/Main/main.c ./FonctionC/FctsAssemblage/*.c ./FonctionC/FctsCalcul/*.c \
    ./FonctionsFortran/*.o -L/opt/homebrew/Cellar/gcc/13.2.0/bin/../lib/gcc/current -lgfortran -lm && ./a.out 


