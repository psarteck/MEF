#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void ppquad(const int t, float **pts, float **pds){

// Return de la valeur de q

	int q = returnQ(t);
	
	

// Affectation des points et des poids

	// Test sur t
	
	switch(t){
		case 1:		// Quadrangle
		// Poids 
		
			for(int i = 0 ; i < 4 ; i++){
                *(*(pds)+i) = 1./36;
			}
			for(int i = 4 ; i < q-1 ; i++){
                *(*(pds)+i) = 1./9;
			}
            *(*(pds)+q-1) = 4./9;
			
		// Points
		
			**pts = 1;
            *(*(pts)+1) = 0;
            
            *(*(pts)+2) = 1;
            *(*(pts)+3) = 1;
            
            *(*(pts)+4) = 0;
            *(*(pts)+5) = 1;
            
            *(*(pts)+6) = 0;
            *(*(pts)+7) = 0;
            
            *(*(pts)+8) = 1;
            *(*(pts)+9) = 0.5;
            
            *(*(pts)+10) = 0.5;
            *(*(pts)+11) = 1;
            
            *(*(pts)+12) = 0;
            *(*(pts)+13) = 0.5;
            
            *(*(pts)+14) = 0.5;
            *(*(pts)+15) = 0;
            
            *(*(pts)+16) = 0.5;
            *(*(pts)+17) = 0.5;
			
			
            break;
            
		case 2:		// Triangle
		
		// Poids
		
			for(int i = 0 ; i < q ; i++){
                *(*(pds)+i) = 1./6;
			}
			
		// Points
            **pts = 0.5;
            *(*(pts)+1) = 0.5;
            
            *(*(pts)+2) = 0;
            *(*(pts)+3) = 0.5;
            
            *(*(pts)+4) = 0.5;
            *(*(pts)+5) = 0;
            
            
            break;
            
		case 3:		// Segment
		
			
		// Poids
		
            **pds = 1./6;
            *(*(pds)+1) = 1./6;
            *(*(pds)+2) = 2./3;
			
		// Points
             
             **pts = 1;
             *(*(pts)+1) = 0;
             *(*(pts)+2) = 0.5;
            
            break;
        default :
            printf("PB");
            break;
	}
}
