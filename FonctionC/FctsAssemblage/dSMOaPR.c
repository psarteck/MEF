/*
Fonction de passage de la structure SMO à la strucutre Profil
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../Header/header.h"



void dSMOaPR(int NbLign, int *NbCoeff, int AdPrCoefLiO[], float MatriceO[], int NumColO[], 
            float **MatProf, int Profil[]){
    
    int tailleMat = 1;
//      On cherche les  nombres de valeurs sur les lignes
    Profil[0] = 1;
    for (int i = 1 ; i < NbLign ; i ++){
        if(AdPrCoefLiO[i-1]!=AdPrCoefLiO[i]){
            tailleMat += i+1 - NumColO[AdPrCoefLiO[i-1]-1];
        }
        Profil[i] = tailleMat;
    }
    *NbCoeff = tailleMat-1;
    printf("Taille mat = %d\n\n", tailleMat-1);
    *MatProf = calloc(NbLign+tailleMat-1, sizeof(float));

//    Initialisation à zéros
    for (int i = 0 ; i < NbLign+tailleMat ; i ++){
        (*MatProf)[i] = 0;
    }
//    On rajoute les valeurs de la diag de smo à profil
    for (int i = 0 ; i < NbLign ; i ++){
        (*MatProf)[i] = MatriceO[i];
    }
    
// Insertion des éléments des non nuls pour LMatP
    for(int i = 0 ; i < NbLign-1 ; i ++){
        for(int j = AdPrCoefLiO[i] ; j < AdPrCoefLiO[i+1] ; j++){
            //printf("%d %d , %d , %f\n", i+1,AdPrCoefLiO[i], AdPrCoefLiO[i+1], MatriceO[j-1+NbLign]);
            (*MatProf)[NbLign+Profil[i]-1+NumColO[j-1]-NumColO[AdPrCoefLiO[i]-1]]  = MatriceO[j-1+NbLign];
        }
    }
    
    
}
