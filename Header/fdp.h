/*
Header contenant les fonctions qui définissent la formulation variationnelle
*/

float aij(float i, float j);

float A11(float *x);
float A00(float *x);
float A12(float *x);
float A22(float *x);
float BN(float *x);
float FOMEGA(float *x);
float FN(float *x, int aret);
float UD(float x[]);
