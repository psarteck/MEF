

#include <stdio.h>
#include <stdlib.h>


void calDerFbase(float **valDBase, int t, float *pts){
    
    
    switch(t){
            
        case 1:
//            valDBase[0][0]= 1-pts[1];
//            valDBase[0][1]= pts[1];
//            valDBase[0][2]= -pts[1];
//            valDBase[0][3]= pts[1]-1;
//
//            valDBase[1][0]= -pts[0];
//            valDBase[1][1]= pts[0];
//            valDBase[1][2]= 1-pts[0];
//            valDBase[1][3]= pts[0]- 1;
            
            valDBase[0][0]= 1-pts[1];
            valDBase[1][0]= pts[1];
            valDBase[2][0]= -pts[1];
            valDBase[3][0]= pts[1]-1;
            
            valDBase[0][1]= -pts[0];
            valDBase[1][1]= pts[0];
            valDBase[2][1]= 1-pts[0];
            valDBase[3][1]= pts[0]- 1;
            
            
            
            break;
        case 2:
            
//            valDBase[0][0]= 1;
//            valDBase[0][1]= 0;
//            valDBase[0][2]= -1;
//
//            valDBase[1][0]= 0;
//            valDBase[1][1]= 1;
//            valDBase[1][2]= -1;
            
            valDBase[0][0]= 1;
            valDBase[1][0]= 0;
            valDBase[2][0]= -1;
            
            valDBase[0][1]= 0;
            valDBase[1][1]= 1;
            valDBase[2][1]= -1;
            
            break;
        case 3:
            
            valDBase[0][0]= 1;
            valDBase[0][1]= -1;
            
            break;
        default:
            printf("\nErreur sur le type d'élément t.\n");
            
            break;
    }
    
}
