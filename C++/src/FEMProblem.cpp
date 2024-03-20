#include "FEMProblem.h"

namespace FEMProblem {
    /*
Définition des fonctions inhérentes à la l'opérateur différentiel et la formulation variationelle :

A_00
A_11, A_12, A_21, A_22
B_N
F_N
UD
F_OMEGA
*/
// extern int nucas;
// extern int dom;

double aij(double i, double j){
    return (i == j);
}

double A11(std::vector<double> x){
    return 1;
}

double A00(std::vector<double> x){
    return 1;
}

double A12(std::vector<double> x){
    return 0;
}

double A22(std::vector<double> x){
    return 1;
}

double BN(std::vector<double> x){
    return 1;
}

double FOMEGA(std::vector<double> x){
    // switch(nucas){
    //     case 1:
    //         return 32*(x[0]-x[0]*x[0]+x[1]-x[1]*x[1]);
    //         break;
    //     case 2:
    //         return 2*M_PI*M_PI*sin(M_PI*x[0])*sin(M_PI*x[1]);
    //         break;
    //     case 3:
    //         return (1+2*M_PI*M_PI)*cos(M_PI*x[0])*cos(M_PI*x[1]);
    //         break;
    //     default:
    //         printf("\nMauvaise valeur de nucas !\n");
    //         return 0;
    //         break;
    // }
    return 1.;
}

double FN(std::vector<double> x, int numAret){
    // if(dom == 1){
    //     switch(nucas){
    //         case 1:
    //             return 0;
    //             break;
    //         case 2:
    //             return 0;
    //             break;
    //         case 3:
    //             switch(aret){
    //                 case 2:
    //                     return -M_PI*sin(M_PI*x[0])*cos(M_PI*x[1]);
    //                     break;
    //                 case 3:
    //                     return -M_PI*cos(M_PI*x[0])*sin(M_PI*x[1]);
    //                     break;
    //                 case 4:
    //                     return M_PI*sin(M_PI*x[0])*cos(M_PI*x[1]);
    //                     break;
    //                 case 1:
    //                     return M_PI*cos(M_PI*x[0])*sin(M_PI*x[1]);
    //                     break;
    //                 default:
    //                     printf("\nMauvaise valeur d'aret !\n");
    //                     return 0;
    //                     break;
    //             }
    //         default:
    //             printf("\nMauvaise valeur de nucas !\n");
    //             return 0;
    //             break;
    //     }
    // }
    // else if(dom == 2){
    //     switch(nucas){
    //         case 1:
    //             switch(aret){
    //                 case 2:
    //                     return 16*x[0]*(1-x[0]);
    //                     break;
    //                 case 3:
    //                     return 16*x[1]*(1-x[1]);
    //                     break;
    //                 default:
    //                     printf("\nMauvaise valeur d'aret !\n");
    //                     return 0;
    //                     break;
    //             }
    //             break;
    //         case 2:
    //             switch(aret){
    //                 case 2:
    //                     return M_PI*cos(M_PI*x[0])*sin(M_PI*x[1]);
    //                     break;
    //                 case 3:
    //                     return M_PI*sin(M_PI*x[0])*cos(M_PI*x[1]);
    //                     break;
    //                 default:
    //                     printf("\nMauvaise valeur d'aret !\n");
    //                     return 0;
    //                     break;
    //             }
    //             break;
    //         case 3:
    //             switch(aret){
    //                 case 2:
    //                     return -M_PI*sin(M_PI*x[0])*cos(M_PI*x[1]);
    //                     break;
    //                 case 3:
    //                     return -M_PI*cos(M_PI*x[0])*sin(M_PI*x[1]);
    //                     break;
    //                 default:
    //                     printf("\nMauvaise valeur d'aret !\n");
    //                     return 0;
    //                     break;
    //             }
    //             break;
    //         default:
    //             printf("\nMauvaise valeur de nucas !\n");
    //             return 0;
    //             break;
    //     }
    // }
    // else{
    //     printf("\nMauvaise valeur du domaine !\n");
    //     return 0;
    // }
    return 1.;
}

double UD(std::vector<double> x){
    
    // switch(nucas){
    //     case 1:
    //         return 16*x[0]*x[1]*(1-x[0])*(1-x[1]);
    //         break;
    //     case 2:
    //         return sin(x[0]*M_PI)*sin(x[1]*M_PI);
    //         break;
    //     case 3:
    //         return cos(M_PI*x[0])*cos(M_PI*x[1]);
    //         break;
    //     default:
    //         printf("\nMauvaise valeur de nucas !\n");
    //         return 0;
    //         break;
    //     }
    return 100*x[0]+x[1];
}

}