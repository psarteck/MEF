#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void numNaret(int t, int ordre, int pts[], int aret){
    
    
    switch(t){
    // Quadrangle
        case 1:
            if(ordre == 1){
                pts[0] = aret;
                if(aret == 4)
                    pts[1] = 1;
                else
                    pts[1] = aret+1;
            }
            else{
                pts[0] = aret;
                if(aret == 4)
                    pts[1] = 1;
                else
                    pts[1] = aret+1;
                pts[2] = aret + 4;
            }
            break;
            
    // Triangle
        case 2:
            if(ordre == 1){
                pts[0] = aret;
                if(aret == 3)
                    pts[1] = 1;
                else
                    pts[1] = aret+1;
            }
            else{
                pts[0] = aret;
                if(aret == 3)
                    pts[1] = 1;
                else
                    pts[1] = aret+1;
                pts[2] = aret + 3;
            }
            break;
        default:
            printf("\nMauvaise valeur de t.\n");
            break;
            
    }
    
    
}
