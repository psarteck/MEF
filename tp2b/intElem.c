#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <math.h>



void intElem(int type, int nbneel, float **coorEl, float **matelm, float *felm){
    
    
    float *fctB = calloc(nbneel, sizeof(float));
    float **fctDerB = alloctab(nbneel, 2);
    float **mat = alloctab(2, 2);
    float **matInv = alloctab(2, 2);
    float deter = 0;
    float imagePts[2] = {0.0, 0.0};
    float eltdif = 0.0;
    float **cofvarAD = alloctab(2, 2);
    float cofvarWW = 0.0;
    float cofvarW = 0.0;
    
    int q = returnQ(type);
    float *pts= calloc(2*q, sizeof(float));
    float *pds = calloc(q, sizeof(float));
    ppquad(type, &pts, &pds);
    
    
    for(int indicepts = 0 ; indicepts < q ; indicepts ++){
        
        calFbase(fctB, type, &pts[2*indicepts]);
        calDerFbase(fctDerB, type, &pts[2*indicepts]);
        matJacob(coorEl, fctDerB, 2, mat, nbneel);
        invertM2x2(&deter, mat, matInv);
        transFK(coorEl, fctB, nbneel, imagePts);
        

        eltdif = deter * pds[indicepts];
        
        
        cofvarAD[0][0] = A11(imagePts);
        cofvarAD[0][1] = A12(imagePts);
        cofvarAD[1][0] = A12(imagePts);
        cofvarAD[1][1] = A22(imagePts);
        
        ADWDW(nbneel, fctDerB, eltdif, cofvarAD, matInv, matelm);

        cofvarWW = A00(imagePts);
        
        WW(nbneel, fctB, eltdif, cofvarWW, matelm);
        
                
        cofvarW = FOMEGA(imagePts);
        
        W(nbneel, fctB, eltdif, cofvarW, felm);
        
    }
      
    
        
}
