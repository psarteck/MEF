#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void invertM2x2(float *det, float **M, float **Minv){
    
    *det = M[0][0]*M[1][1] - M[0][1]*M[1][0];
    
    Minv[0][0] = 1/ *det * M[1][1];
    Minv[0][1] = -1/ *det * M[0][1];
    Minv[1][0] = -1/ *det * M[1][0];
    Minv[1][1] = 1/ *det * M[0][0];
    
}
