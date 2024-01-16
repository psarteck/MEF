/*
Fonction de passage de la structure SMD à la strucutre SMO

 NbLign : nombre de ligne 
 Matrice : matrice du système sous la forme SMD
 Matrice0 : matrice du système sous la forme SM0
 AdPrCoefLi / AdSuccLi / NumCol : tableaux pour la forme SMD
 NumCol0 : tableaux pour la forme SMO
 SecMembre : second membre du système
 NumDLDir : numéro des conditions de Dirichlet
 ValDLDir : valeur des conditions de Dirichlet
 
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../Header/header.h"


// Procédure de passage de la SMD à la SMO

void dSMDaSMO(int NbLign, int AdPrCoefLi[], int NumCol[], int AdSuccLi[], float Matrice[], 
            float SecMembre[], int NumDLDir[], float ValDLDir[], int NumColO[], float MatriceO[]){
    
    
    cdesse_(&NbLign, AdPrCoefLi, NumCol, AdSuccLi, Matrice,SecMembre, NumDLDir, ValDLDir, AdPrCoefLi, NumColO, MatriceO, SecMembre);
    
    //affsmo_(&NbLign, AdPrCoefLi, NumColO, MatriceO, SecMembre);
    
}
