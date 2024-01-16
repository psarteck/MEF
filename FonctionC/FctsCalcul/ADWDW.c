#include <stdio.h>
#include <stdlib.h>
#include "../../Header/header.h"

void ADWDW(int nbneel, float **fctDbas, float eltdif, float **cofvar, float **invMatJ, float **matelm) {


	int i, j, alpha, beta;

	for (i = 0 ; i < nbneel ; i++) {
    	for (j = 0 ; j < nbneel ; j++) {
    		for(alpha = 0 ; alpha < 2 ; alpha++){
                float pdscai = prodScal(fctDbas, invMatJ, alpha, j);
                
    			for(beta = 0 ; beta < 2 ; beta++){
                    float pdscaj = prodScal(fctDbas, invMatJ, beta, i);
      				matelm[i][j] += eltdif * cofvar[alpha][beta] * pdscai * pdscaj;
      			}
      		}
    	}
  	}
    

}


float prodScal(float **Mat1, float **Mat2, int indiceAB, int indiceIJ){
    float somme = 0;
    for(int k = 0 ; k < 2 ; k++){
        somme += Mat1[indiceIJ][k]*Mat2[indiceAB][k];
    }
    return somme;
}
