#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void calFbase(float *valBase, int t, float *pts){
    
// Switch sur le type de l'élément
    
    switch(t){
            
        case 1:
            
            valBase[0] = pts[0] - pts[0]*pts[1];
            valBase[1] = pts[0]*pts[1];
            valBase[2] = pts[1] - pts[0]*pts[1];
            valBase[3] = pts[0]*pts[1] - pts[1] - pts[0] + 1;
            
            break;
        case 2:
            
            valBase[0] = pts[0];
            valBase[1] = pts[1];
            valBase[2] = 1 - pts[0] - pts[1];
            
            break;
        case 3:
            
            valBase[0] = *pts;
            valBase[1] = 1-*pts;
            
            break;
        default:
            printf("\nErreur sur le type d'élément t.\n");
            
            break;
            
    }
    
    
}
