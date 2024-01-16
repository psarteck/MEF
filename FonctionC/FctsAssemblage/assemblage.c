/* 
Fonction qui calcule les matrices et seconds membres élémentaires et assemble la matrice
 et le second membre du système sous la forme SMD

 NbLign : nombre de ligne 
 NbCoeff : nombre de coefficient 
 nbEls : nombre d'éléments du maillage 
 typeEl : type d'élement du maillage 
 nbArPaEl : nombre d'arete par élément
 Matrice : matrice du système sous la forme SMD
 AdPrCoefLi / AdSuccLi / NumCol : tableau pour la forme SMD
 SecMembre : second membre du système
 NumDLDir : numéro des conditions de Dirichlet
 ValDLDir : valeur des conditions de Dirichlet
 nbNePaEl : nombre de noeuds par élément
 ngnel : numéro globaux des noeuds 
 coord : tableau des coordonées des éléments
 nRefAr : tableau des numéros de références de aretes
 nRefDom : numéro de référence du domaine
 nbRefD0 / nbRefD1 / nbRefF1 : nombre d'aret avec les conditions de Dirichlet homogène, non homogène ou Neumann
 numRefD0 / numRefD1 / numRefF1 : aret avec les conditions de Dirichlet homogène, non homogène ou Neumann
*/


#include <stdio.h>
#include <stdlib.h>
#include "../../Header/header.h"
#include "../../Header/forfun.h"


void assemblage(int NbLign, int NbCoeff, int nbEls, int typeEl, int nbArPaEl, 
            float Matrice[], int AdPrCoefLi[], int AdSuccLi[], int NumCol[], 
            float SecMembre[], int NumDLDir[], float ValDLDir[], int nbNePaEl, 
            int **ngnel, float **coord, int **nRefAr, int nRefDom, int nbRefD0, 
            int *numRefD0, int nbRefD1, int *numRefD1, int nbRefF1, int *numRefF1){
    
    float ** MatElem = alloctab(nbNePaEl, nbNePaEl);
    float * SMbrElem = calloc(nbNePaEl, sizeof(float));
    int * NuDElem = calloc(nbNePaEl, sizeof(float));
    float * uDElem = calloc(nbNePaEl, sizeof(float));
    float *coordEl[nbNePaEl];
    
    
    int NextAd = 1 ;
    
    int I ;
    int J ;
    
// Initialisation
    
    for(int i = 0 ; i < NbLign+NbCoeff ; i++){
        Matrice[i]= 0;
    }
    for(int i = 0 ; i < NbLign ; i++){
        AdPrCoefLi[i] = 0;
        SecMembre[i] = 0;
        NumDLDir[i] = i+1;
        ValDLDir[i] = 0;
    }
    for(int i = 0 ; i < NbCoeff ; i++){
        NumCol[i] = -1;
    }
    
    // Boucle sur le nombre d'éléments et calcul des matrices élémentaires
        
        for(int El = 0 ; El < nbEls ; El++){
                    
            selectPts(nbNePaEl, ngnel[El], coord, coordEl);
            
            cal1Elem(nRefDom, nbRefD0, numRefD0, nbRefD1, numRefD1, nbRefF1, numRefF1, typeEl, nbNePaEl, coordEl, nbArPaEl, nRefAr[El], MatElem, SMbrElem, NuDElem, uDElem);
            
            for(int i = 0 ; i < nbNePaEl ; i++){
                I = ngnel[El][i];
                
                if(NuDElem[i] == -1){
                    NumDLDir[I-1] = -I;
                    ValDLDir[I-1] = uDElem[i];
                }
                else if(NuDElem[i] == 0){
                    NumDLDir[I-1] = 0;
                    ValDLDir[I-1] = 0;
                }

                SecMembre[I-1] += SMbrElem[i];
                
                for(int j = 0 ; j <= i ; j++){
                    J = ngnel[El][j];
                    if(I > J){
                        assmat_(&I,&J,&MatElem[i][j],AdPrCoefLi, NumCol, AdSuccLi, &Matrice[NbLign], &NextAd);
                    }
                    else if(I < J){
                        assmat_(&J,&I,&MatElem[i][j],AdPrCoefLi, NumCol, AdSuccLi, &Matrice[NbLign], &NextAd);
                    }
                        
                    else {
                        Matrice[I-1] += MatElem[i][j];
                        
                    }
                }
            }
            
            //impCalEl(El+1, typeEl, nbNePaEl, MatElem, SMbrElem, NuDElem, uDElem);
            
        }
        AdPrCoefLi[NbLign-1] = NextAd;
        
        //affsmd_(&NbLign, AdPrCoefLi,NumCol, AdSuccLi, Matrice, SecMembre,NumDLDir, ValDLDir);
    
    free(MatElem);
    free(SMbrElem);
    free(NuDElem);
    free(uDElem);
    
}
