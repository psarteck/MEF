#include <stdio.h>
#include <stdlib.h>


// double aij(double i, double j){
//     return (i == j);
// }

// double A11(float *x){
//     return 1;
// }

// double A00(float *x){
//     return 0;
// }

// double A12(float *x){
//     return 0;
// }

// double A22(float *x){
//     return 1;
// }

// double BN(float *x){
//     return 1;
// }

// double FOMEGA(float x[]){

//     return 32*(x[0]*(1-x[0])+x[1]*(1-x[1]));
// }

// double FN(float *x, int numAret){
//     return 1.;
// }

// double UD(float *x){
//     return 100*x[0]+x[1];
// }




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
    return 1;
}

float FN(float *x){
    return 1;
}

float UD(float x[]){
    return 100*x[0]+x[1];
}
