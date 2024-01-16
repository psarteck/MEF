/*
Fonction qui donne le numéro de l'arete sur laquelle 
est situé d'un point donné (pts)
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../Header/header.h"

void numNaret(int t, int pts[], int aret){
    
    
    switch(t){
    // Quadrangle ordre 1
        case 1:
            pts[0] = aret;
            if(aret == 4)
                pts[1] = 1;
            else
                pts[1] = aret+1;
            break;
            
    // Triangle ordre 1
        case 2:
            pts[0] = aret;
            if(aret == 3)
                pts[1] = 1;
            else
                pts[1] = aret+1;
            break;
    // Quadrangle ordre 2
        case 4:
            pts[0] = aret;
            if(aret == 4)
                pts[1] = 1;
            else
                pts[1] = aret+1;
            pts[2] = aret + 4;
            break;
    // Triangle ordre 2
        case 5:
            pts[0] = aret;
            if(aret == 3)
                pts[1] = 1;
            else
                pts[1] = aret+1;
            pts[2] = aret + 3;
            break;
        default:
            printf("\nMauvaise valeur de t.\n");
            break;
            
    }
    
    
    
}
