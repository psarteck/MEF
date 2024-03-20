#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void transFK(float **ai, float *valBase, int Pk, float *res){
    
    res[0] = 0;
    res[1] = 0;
    
    for(int i = 0 ; i < Pk ; i++){
        res[0] = res[0] + ai[i][0] * valBase[i];
        res[1] = res[1] + ai[i][1] * valBase[i];
    }
       
}
