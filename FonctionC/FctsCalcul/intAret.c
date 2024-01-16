/*
Fonction pour calculer les intégrales d'arete 
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../Header/header.h"
#include <math.h>

void intAret(int type, int nbneel, float **coorAr, float **matelm, float *felm, int aret){
    
    int d = 1;
    
    float *fctB = calloc(nbneel, sizeof(float));
    float **fctDerB = alloctab(nbneel, d);
    float **mat = alloctab(2, d);
    float imagePts[2] = {0.0, 0.0};
    float eltdif = 0.0;
    float cofvarWW = 0.0;
    float cofvarW = 0.0;
    
    int q = returnQ(type);
    float *pts= calloc(q*d, sizeof(float));
    float *pds = calloc(q*d, sizeof(float));
    ppquad(type, &pts, &pds);
    
    
    
    for(int indicepts = 0 ; indicepts < q ; indicepts ++){

        calFbase(fctB, type, &pts[indicepts]);
        //printf("%f %f\n\n", fctB[0], fctB[1]);
        calDerFbase(fctDerB, type, &pts[indicepts]);
        
        matJacob(coorAr, fctDerB, 1, mat, nbneel);
        
        transFK(coorAr, fctB, nbneel, imagePts);


   
        eltdif = pds[indicepts] * sqrt(mat[0][0]*mat[0][0] + mat[0][1]*mat[0][1]);
        
        cofvarWW = BN(imagePts);
        
        WW(nbneel, fctB, eltdif, cofvarWW, matelm);
        
        cofvarW = FN(imagePts, aret);

        W(nbneel, fctB, eltdif, cofvarW, felm);
        
    }
}
