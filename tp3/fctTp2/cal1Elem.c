#include <stdio.h>
#include <stdlib.h>
#include "header.h"



void cal1Elem(int nRefDom, int nbRefD0, int *numRefD0, int nbRefD1, int *numRefD1, int nbRefF1, int *numRefF1, int typeEl, int nbneel, float **coordEl, int nbaret, int nRefArEl[], float **MatElem, float *SMbrElem, int *NuDElem, float *uDElem){
    

    for(int j = 0 ; j < nbneel ; j ++){
        NuDElem[j] = 1;
        uDElem[j] = 0;
    }
    for(int k = 0 ; k < nbneel ; k ++){
        SMbrElem[k] = 0;
        for(int l = 0 ; l < nbneel ; l++){
            MatElem[k][l] = 0;
        }
    }
    
    
    intElem(typeEl, nbneel, coordEl, MatElem, SMbrElem);

    for(int i = 0 ; i < nbneel ; i++){
        for(int j = 0 ; j < nbneel ; j++){
            printf("%f ", MatElem[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    float *coorAr[nbneel];
    int ptsAret[nbneel];
    int i, j;
    int aretTrouve = 0;

// AREVOIR !!
    for(i = 0 ; i < nbaret ; i++){
        aretTrouve = 0;
        numNaret(typeEl, ptsAret, i+1);
        for(j = 0 ; j < nbRefD1 ; j++){
            if(nRefArEl[i] == numRefD1[j]){
                aretTrouve = 1;
                NuDElem[ptsAret[0]-1] = -1;
                NuDElem[ptsAret[1]-1] = -1;
                uDElem[ptsAret[0]-1] = UD(coordEl[ptsAret[0]-1]);
                uDElem[ptsAret[1]-1] = UD(coordEl[ptsAret[1]-1]);
            }
        }
        if(aretTrouve == 1){
            continue;
        }
        for(j = 0 ; j < nbRefD0 ; j++){
            if(nRefArEl[i] == numRefD0[j]){
                NuDElem[ptsAret[0]-1] = 0;
                NuDElem[ptsAret[1]-1] = 0;
            }
        }
    }
    
    int nbneAr = 2;
    float **MatAret = alloctab(nbneAr,nbneAr);
    float SMbrAret[nbneAr];
    
    for(i = 0 ; i < nbaret ; i++){
        
        if (nRefArEl[i] == nRefDom){
            continue;
        }
        else {
            
            for(int p = 0 ; p <  nbRefF1 ; p++){
                
                if(nRefArEl[i]  == numRefF1[p]){
                    for(int j = 0 ; j < nbneAr ; j++){
                        MatAret[j][0] = 0;
                        MatAret[j][1] = 0;
                        SMbrAret[j] = 0;
                    }
                    
                    numNaret(typeEl, ptsAret, i+1);
                    
                    selectPts(nbneAr, ptsAret, coordEl, coorAr);
                    intAret(3, nbneAr, coorAr, MatAret, SMbrAret);                    
                    
                    for(int i = 0 ; i < nbneAr ; i++){
                        printf("%f ", SMbrAret[i]);
                    }
                    
                    for (int m = 0 ; m < nbneAr ; m++){
                        
                        SMbrElem[ptsAret[m]-1] = SMbrElem[ptsAret[m]-1] + SMbrAret[m];
                        
                        for (int a = 0 ; a < nbneAr ; a++){
                            int nm=ptsAret[m]-1;
                            int na= ptsAret[a]-1;
                            MatElem[nm][na] = MatElem[nm][na] + MatAret[m][a];
                            
                        }
                    }
                }
                else{
                    continue;
                }
                
                
            }
        }
        
    }
    
    freetab(MatAret);
    
}
