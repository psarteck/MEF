/* 
Fonction qui effectue la décomposiion LU de la matrice et calcule la solution 

Argument d'entrée : 
    NbLign : nombre de ligne de la matrice
    NbCoeff : nombre de coefficient de la matrice (surévalué)
    MatProf : Matrice sous la forme profil
    Profil : tableau de la structure profil de la matrice 
    SecMembre : second membre du système
Argument de sortie :
    U : solution calculée par le code élément finis
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../Header/header.h"



void decompLU(int NbLign, int NbCoeff, float MatProf[], int Profil[], float U[], float SecMembre[]){
    
    float *ld = calloc(NbLign, sizeof(float));
    float *ll = calloc(NbCoeff, sizeof(float));
    
    float eps = 0.0001;

    float *Y = calloc(NbLign, sizeof(float));

    ltlpr_(&NbLign, Profil, &MatProf[0], &MatProf[NbLign], &eps, ld, ll);
    rsprl_(&NbLign, Profil, ld, ll, SecMembre, Y);
    rspru_(&NbLign, Profil, ld, ll, Y, U);

    free(ld);
    free(ll);
    free(Y);
}
