#include <stdio.h>
#include <stdlib.h>
#include "./fctTp2/./header.h"
#include "forfun.h"


int main(){
    
    // Déclaration des variables
	
	//char ficmai[] = "ficMaillage.txt";
	//char ficmai[] = "car1x1q_4.txt";
	char ficmai[] = "./ficMai/car1x1t_1.txt";
    char ficnum[] = "./ficMai/NUMREF.Test";
	int typeEl, nbNeTot, nbEls, nbNePaEl, nbArPaEl;
    // t : type
    // n : nb de noeuds totals
    // m : nb element
    // p : nb de noeuds géo / element       / nbeel
    // q : nb daret / element
   
    // tableau des coord
	float **coord;
    
    // ngnel : num globaux noeuds / elem
	int **ngnel;
    
    // Tableau des ref des arete
	int **nRefAr;
    
    
    
	
	
// Récupération des données dans le fichier de maillage
    
	lecfima(ficmai, &typeEl, &nbNeTot, &coord, &nbEls, &ngnel, &nbNePaEl, &nbArPaEl, &nRefAr);
    
    
    int nRefDom, nbRefD0, nbRefD1, nbRefF1;
    int *numRefD1, *numRefD0, *numRefF1;
    
// Récupération des numéros de références
    
    lecNumRef(ficnum, &nRefDom, &numRefD0, &numRefD1, &numRefF1, &nbRefD0, &nbRefD1, &nbRefF1);
    
    
// Création des objets nécessaires pour CAL1ELEM
    
    float ** MatElem = alloctab(nbNePaEl, nbNePaEl);
    float * SMbrElem = calloc(nbNePaEl, sizeof(float));
    
    int * NuDElem = calloc(nbNePaEl, sizeof(float));
    
    
    float * uDElem = calloc(nbNePaEl, sizeof(float));
    float *coordEl[nbNePaEl];
    
// Création des objets nécessaires pour l'assemblage
    
    int NbLign = nbNeTot;
    int NbCoeff = 0;
    for(int i = 0 ; i < NbLign ; i++){
        NbCoeff += i;
    }
    float Matrice[NbLign+NbCoeff];
    int AdPrCoefLi[NbLign];
    int AdSuccLi[NbCoeff];
    int NumCol[NbCoeff];
    
    float SecMembre[NbLign];
    int NumDLDir[NbLign];
    float ValDLDir[NbLign];
    
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
        NumCol[i] = 0;
    }
    
// Boucle sur le nombre d'éléements et calcul des matrices élémentaires
    
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

        // impCalEl(El+1, typeEl, nbNePaEl, MatElem, SMbrElem, NuDElem, uDElem);
        
    }
    AdPrCoefLi[NbLign-1] = NextAd;
    
    affsmd_(&NbLign, AdPrCoefLi,NumCol, AdSuccLi, Matrice, SecMembre,NumDLDir, ValDLDir);
    
    int RealNbCoeff = 0;
    while(NumCol[RealNbCoeff] > 0){
        RealNbCoeff += 1;
    }
    // Divergence d'opinion entre Matthieu et Alex qui donne
    // globalement le même résultat
    //printf("\n%d\n\n", AdPrCoefLi[NbLign-1]-1);
    printf("\n%d\n\n", RealNbCoeff);
    
// Libération de la mémoire allouée
	
	freetab(coord);
	freetab(ngnel);
	freetab(nRefAr);
    free(numRefD0);
    free(numRefD1);
    free(numRefF1);
    
    return 0;
}
