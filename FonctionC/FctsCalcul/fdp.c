/*
Définition des fonctions inhérentes à la l'opérateur différentiel et la formulation variationelle :

A_00
A_11, A_12, A_21, A_22
B_N
F_N
UD
F_OMEGA
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int nucas;
extern int dom;

float aij(float i, float j){
    return 0;
}

float A11(float *x){
    return 1;
}

float A00(float *x){
    switch(nucas){
        case 1:
            return 0;
            break;
        case 2:
            return 0;
            break;
        case 3:
            return 1;
            break;
        default:
            printf("\nMauvaise valeur de nucas !\n");
            return 0;
            break;
    }
}

float A12(float *x){
    return 0;
}

float A22(float *x){
    return 1;
}

float BN(float *x){
    return 0;
}

float FOMEGA(float *x){
    switch(nucas){
        case 1:
            return 32*(x[0]-x[0]*x[0]+x[1]-x[1]*x[1]);
            break;
        case 2:
            return 2*M_PI*M_PI*sin(M_PI*x[0])*sin(M_PI*x[1]);
            break;
        case 3:
            return (1+2*M_PI*M_PI)*cos(M_PI*x[0])*cos(M_PI*x[1]);
            break;
        default:
            printf("\nMauvaise valeur de nucas !\n");
            return 0;
            break;
    }
}

float FN(float *x, int aret){
    if(dom == 1){
        switch(nucas){
            case 1:
                return 0;
                break;
            case 2:
                return 0;
                break;
            case 3:
                switch(aret){
                    case 2:
                        return -M_PI*sin(M_PI*x[0])*cos(M_PI*x[1]);
                        break;
                    case 3:
                        return -M_PI*cos(M_PI*x[0])*sin(M_PI*x[1]);
                        break;
                    case 4:
                        return M_PI*sin(M_PI*x[0])*cos(M_PI*x[1]);
                        break;
                    case 1:
                        return M_PI*cos(M_PI*x[0])*sin(M_PI*x[1]);
                        break;
                    default:
                        printf("\nMauvaise valeur d'aret !\n");
                        return 0;
                        break;
                }
            default:
                printf("\nMauvaise valeur de nucas !\n");
                return 0;
                break;
        }
    }
    else if(dom == 2){
        switch(nucas){
            case 1:
                switch(aret){
                    case 2:
                        return 16*x[0]*(1-x[0]);
                        break;
                    case 3:
                        return 16*x[1]*(1-x[1]);
                        break;
                    default:
                        printf("\nMauvaise valeur d'aret !\n");
                        return 0;
                        break;
                }
                break;
            case 2:
                switch(aret){
                    case 2:
                        return M_PI*cos(M_PI*x[0])*sin(M_PI*x[1]);
                        break;
                    case 3:
                        return M_PI*sin(M_PI*x[0])*cos(M_PI*x[1]);
                        break;
                    default:
                        printf("\nMauvaise valeur d'aret !\n");
                        return 0;
                        break;
                }
                break;
            case 3:
                switch(aret){
                    case 2:
                        return -M_PI*sin(M_PI*x[0])*cos(M_PI*x[1]);
                        break;
                    case 3:
                        return -M_PI*cos(M_PI*x[0])*sin(M_PI*x[1]);
                        break;
                    default:
                        printf("\nMauvaise valeur d'aret !\n");
                        return 0;
                        break;
                }
                break;
            default:
                printf("\nMauvaise valeur de nucas !\n");
                return 0;
                break;
        }
    }
    else{
        printf("\nMauvaise valeur du domaine !\n");
        return 0;
    }
}

float UD(float x[]){
    
    switch(nucas){
        case 1:
            return 16*x[0]*x[1]*(1-x[0])*(1-x[1]);
            break;
        case 2:
            return sin(x[0]*M_PI)*sin(x[1]*M_PI);
            break;
        case 3:
            return cos(M_PI*x[0])*cos(M_PI*x[1]);
            break;
        default:
            printf("\nMauvaise valeur de nucas !\n");
            return 0;
            break;
        }
    
}
