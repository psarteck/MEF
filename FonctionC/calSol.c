/*
Fonction qui calcule la solution exacte 

Arguments d'entrée : 
    NbLign : nombre de ligne
    coord : tableau des coordonées des coeuds
Argument de sortie :
    UEX : solution exacte calculée par la fonction solex
*/

#include <stdio.h>
#include <stdlib.h>
#include "../Header/header.h"

void calSol(int NbLign, float **coord, float *UEX){
    
    for(int i = 0 ; i < NbLign ; i ++){
        UEX[i] = solex(coord[i]);
    }
    
}
