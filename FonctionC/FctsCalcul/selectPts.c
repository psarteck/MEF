/*
Fonction qui sélectionne les coordonnées des points à partir du numéro globals 
de ces points
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../Header/header.h"

void selectPts(int nb, int num[], float *coorEns[], float *coorSel[]){
    
    for(int i = 0 ; i < nb ; i ++){
        coorSel[i] = coorEns[num[i]-1];
    }
    
}

