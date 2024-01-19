#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){

// Déclaration des variables

    int t = 1, q = returnQ(t);
	float *pts;
	float *pds;
    
    pts = calloc(2*q, sizeof(float));
    pds = calloc(q, sizeof(float));
	
// Définition de q
//	int q = returnQ(t);
	
// Récupération des poids et points de quadrature

// Fonction 1
    printf("\nFonction 1 ---------\n\n");
    
	ppquad(t, &pts, &pds);
	
	for(int i = 0 ; i < returnQ(t) ; i++){
        printf(" %f %f \n", *(pts+2*i), *(pts+2*i+1));
	}
    printf("\n\n");
    for(int i = 0 ; i < returnQ(t) ; i++){
        printf(" %f \n", *(pds+i));
    }
    
// Fonction 2
    printf("\n\nFonction 2  ---------------\n\n");
    
    // Normal
    
    t = 1;
    float *valBase = calloc(4, sizeof(float));
    float points[2] = {0,0};
    calFbase(valBase, t, &points[0]);
    
    for(int i = 0 ; i < 4 ; i++){
        printf("w%d en x1 : %f \n", i+1,valBase[i]);
    }
    printf("\n\n");

    // Dérivée

    t=1;
    float **valDBase = alloctab(4,2);
    float points1[2] = {1,0};
    calDerFbase(valDBase, t, &points1[0]);

    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 2 ; j++)
            printf("Dérivée de w%d en x%i : %f \n",i+1, j+1,valDBase[i][j]);
    }
    printf("\n");
    
    free(valBase);
    
    
// Fonction 3
    printf("\n\nFonction 3 ---------------\n\n");
    
    t = 2;
    
    float points2[2] = {0,1};
    
    float *valBase2 = calloc(3, sizeof(float));
    calFbase(valBase2, t, points2);
    
    
    float **ai = alloctab(3,2);
    ai[0][0] = 4;
    ai[0][1] = 3;
    
    ai[1][0] = 3;
    ai[1][1] = 4;
    
    ai[2][0] = 3;
    ai[2][1] = 3;
    
    //ai[3][0] = 3;
    //ai[3][1] = 3;
    
    
    
    float *res = calloc(2, sizeof(float));
    
    transFK(ai, valBase2, 3, res);
    printf("\nPour t = %d\n", t);
    printf("Le transformé du points x^ = (%f,%f) est : \n", points2[0], points2[1]);
    printf("x = (%f,%f)\n", res[0], res[1]);
    
    
    free(valBase2);
    freetab(ai);
    free(res);
    
// Fonction 4
    printf("\n\nFonction 4 -----------------\n\n");
    
    t=1;
    float **valDBase2 = alloctab(4,2);
    float points3[2] = {1,0};
    calDerFbase(valDBase2, t, &points3[0]);
    
    float **ai2 = alloctab(4,2);
    
    ai2[0][0] = 4;
    ai2[0][1] = 3;
    
    ai2[1][0] = 3;
    ai2[1][1] = 4;
    
    ai2[2][0] = 3;
    ai2[2][1] = 3;
    
    ai2[3][0] = 3;
    ai2[3][1] = 3;
    
    float **Jcob = alloctab(2,2);
    matJacob(ai2, valDBase2, 2, Jcob, 4);
    
    printf("\nCoordonnées de départ : \n");
    for (int i = 0  ; i < 4 ; i++){
        for (int j = 0  ; j < 2 ; j++){
            printf("%f ", ai2[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatrice jacobienne : \n");
    for (int i = 0  ; i < 2 ; i++){
        for (int j = 0  ; j < 2 ; j++){
            printf("%f ", Jcob[i][j]);
        }
        printf("\n");
    }
    freetab(valDBase2);
    freetab(Jcob);
    freetab(ai2);
    
// Fonction 5
    printf("\n\nFonction 5 ----------------\n\n");

    float Minv[2][2];
    float M[2][2];
    M[0][0] = 1;
    M[0][1] = 2;
    M[1][0] = 3;
    M[1][1] = 4;
    float det;
    
    invertM2x2(&det, M, Minv);
    
    for (int i = 0  ; i < 2 ; i++){
        for (int j = 0  ; j < 2 ; j++){
            printf("%f ", Minv[i][j]);
        }
        printf("\n");
    }
    printf("\nDet = %f \n", det);
    
// Fonction 6
    printf("\n\nFonction 6 ----------------\n\n");
    
    
    t = 2;
    int pts3[3] = {0,0,0};
    int nbA = 3;
    int ordre = 2;
    
    numNaret(t, ordre, pts3, nbA);
    printf("Points sur l'arete n°%d : %d %d %d\n", nbA, pts3[0], pts3[1], pts3[2]);
    
    
// Fonction 7
    printf("\n\nFonction 7 ----------------\n\n");
    
    int nb= 4;
    int num[] = {13,18,17,12};
    float *coorEns[25];
    float *coorSel[nb];
    float pts5[25][2];
    

    
    float a = 0;
    float b = 1;
    float c = 0;
    float d = 1;
    
    int n1 = 5;
    int n2 = 5;
    
    for(int i = 0 ; i < n1 ; i++){
            for(int j = 0 ; j < n2; j++){
                pts5[5*i+j][0] = a+j*(b-a)/(n1-1);
                pts5[5*i+j][1] = c+i*(d-c)/(n2-1);
            }
    }
    for(int i = 0 ; i < 25 ; i++){
        coorEns[i] = pts5[i];
    }
    
    
    
    selectPts(nb, num, coorEns, coorSel);
    
    for(int i = 0 ; i < nb ; i ++){
        for(int j = 0 ; j < 2 ; j++){
            printf("%f ", *(coorSel[i] +j) );
        }
        printf("\n");
    }
    
    
}
