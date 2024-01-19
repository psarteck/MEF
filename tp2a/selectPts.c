#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void selectPts(int nb, int num[], float *coorEns[], float *coorSel[]){
    
    for(int i = 0 ; i < nb ; i ++){
        coorSel[i] = coorEns[num[i]];
    }
    
}

