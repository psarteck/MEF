#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float aij(float i, float j){
    return (i == j);
}

float A11(float *x){
    return 1;
}

float A00(float *x){
    return 1;
}

float A12(float *x){
    return 0;
}

float A22(float *x){
    return 1;
}

float BN(float *x){
    return 1;
}

float FOMEGA(float *x){
    return 1;//(1+2*M_PI*M_PI)*cos(M_PI*x[0])*cos(M_PI*x[1]);
}

float FN(float *x){
    return 1;
}

float UD(float x[]){
    return 100*x[0]+x[1];
}
