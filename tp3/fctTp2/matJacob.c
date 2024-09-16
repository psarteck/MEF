#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void matJacob(float **ai, float **valDBase, int d, float **Jcob, int Pk){
    
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < d ; j++){
            Jcob[i][j] = 0;
        }
    }
    // for(int i = 0 ; i < 3 ; i++){
    //     printf("X = %f, Y = %f\n",ai[i][0], ai[i][1]);
    // }
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < d ; j++){
            for(int k = 0 ; k < Pk ; k++){
                Jcob[i][j] = Jcob[i][j] + ai[k][i] * valDBase[k][j];
            }
        }
    }
        
}
