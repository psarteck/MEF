#!/bin/bash

## Bash afin de d'éxecuter le code éléments finis pour chaque problème chaque domaine et chaque maillage

clear
clear


gfortran -c ./FonctionsFortran/*.f -std=legacy && mv *.o ./FonctionsFortran 
gcc -Wall ./FonctionC/*.c ./FonctionC/Main/mainBoucle.c ./FonctionC/FctsAssemblage/*.c ./FonctionC/FctsCalcul/*.c \
    ./FonctionsFortran/*.o -L/opt/homebrew/Cellar/gcc/12.2.0/bin/../lib/gcc/current -lgfortran -lm 


maillage="./FicMaillage/d"
numDom="./NumRef/ref"
tiret="_"
un="1"
for d in 1 2
do
    for p in 1 2 3
    do
        for tq in t q
        do
            for i in 2 4 8 16 32 64
            do
                ./a.out "$maillage$d$tq$un$tiret$i" "$numDom$d$tiret$p" "$p" "$d" "$tq"
            done
        done
    done
done
mv fort.* ./FichiersResultats
