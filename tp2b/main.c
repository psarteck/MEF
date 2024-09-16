#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main(){
    
    // Déclaration des variables
	
	//char ficmai[] = "ficMaillage.txt";
	//char ficmai[] = "car1x1q_4.txt";
	char ficmai[] = "car3x3t_3.txt";
	// char ficmai[] = "car1x1t_4.txt";
    char ficnum[] = "NUMREF.Test";
	int t, n, m, p, q;
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
    
    
    
	
	
// Récupération des données dans le fichier
    
	lecfima(ficmai, &t, &n, &coord, &m, &ngnel, &p, &q, &nRefAr);
    
    
    int nRefDom, nbRefD0, nbRefD1, nbRefF1;
    int *numRefD1, *numRefD0, *numRefF1;
    
    
    lecNumRef(ficnum, &nRefDom, &numRefD0, &numRefD1, &numRefF1, &nbRefD0, &nbRefD1, &nbRefF1);
    
    
    
    float ** MatElem = alloctab(p, p);
    float * SMbrElem = calloc(p, sizeof(float));
    
    int * NuDElem = calloc(p, sizeof(float));
    
    
    float * uDElem = calloc(p, sizeof(float));
    float *coordEl[p];

    for(int i = 0 ; i < m ; i++){
        
        
        selectPts(p, ngnel[i], coord, coordEl);

        // printf("Coord : %f, %f, %f\n", coord[0][0], coord[0][1], coord[0][2]);
        // printf("Coord : %f, %f, %f\n", coordEl[0], coordEl[1], coordEl[2]);
        
        cal1Elem(nRefDom, nbRefD0, numRefD0, nbRefD1, numRefD1, nbRefF1, numRefF1, t, p, coordEl, q, nRefAr[i], MatElem, SMbrElem, NuDElem, uDElem);
        
        impCalEl(i+1, t, p, MatElem, SMbrElem, NuDElem, uDElem);
        
    }
    
    
    
    
    

// Libération de la mémoire allouée
	
	freetab(coord);
	freetab(ngnel);
	freetab(nRefAr);
    free(numRefD0);
    free(numRefD1);
    free(numRefF1);
    
    return 0;
}
