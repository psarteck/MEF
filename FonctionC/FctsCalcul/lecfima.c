// 	Fonction de lecture d'un fichier de maillage et d'implémentation
//	des données dans des variables allouées transmises.

#include <stdlib.h>
#include <stdio.h>
#include "../../Header/header.h"


void lecfima(char *ficmai, int *type1, int *nbtng, float ***pcoord,
			int *nbtel, int ***pngnel, int *nbneel, int *nbaret, int ***pnRefAr){
			
	// Ouverture du fichier et test
	
		FILE *fic = NULL;
		fic = fopen(ficmai, "r");
		if(fic == NULL){
			printf("Ouverture du fichier impossible : lecfima\n");
			exit(0);
		}
	
		else {
		
		// Récupération de n
			
			fscanf(fic, "%d", nbtng);
			
			
		// Récupération du tableau de coordonnée 
			
			*pcoord = alloctab(*nbtng,2);
			for(int i = 0 ; i < *nbtng ; i++){
				fscanf(fic, "%f %f", (*(*pcoord+i)), (*(*pcoord+i)+1));
			}
			
		// Récuparation de m, t, p et q
			
			fscanf(fic, "%d %d %d %d", nbtel, type1, nbneel, nbaret);
			
			
			
		// Récupération des éléments et aretes
			
			// Si quadrangle
			if(*type1 == 1){
				
				*pngnel = alloctabI(*nbtel,*nbneel);
				*pnRefAr = alloctabI(*nbtel,*nbaret);
				
				for(int i = 0 ; i < *nbtel ; i++){
					fscanf(fic, "%d %d %d %d %d %d %d %d", (*(*pngnel+i)), (*(*pngnel+i)+1),
									(*(*pngnel+i)+2), (*(*pngnel+i)+3), 
									(*(*pnRefAr+i)), (*(*pnRefAr+i)+1), (*(*pnRefAr+i)+2), (*(*pnRefAr+i)+3));
				}
				
			
			}
			// Si triangle
			else if(*type1 == 2){
			
				*pngnel = alloctabI(*nbtel,*nbneel);
				*pnRefAr = alloctabI(*nbtel,*nbaret);
				
				for(int i = 0 ; i < *nbtel ; i++){
					fscanf(fic, "%d %d %d %d %d %d", (*(*pngnel+i)), (*(*pngnel+i)+1),
									(*(*pngnel+i)+2), 
									(*(*pnRefAr+i)), (*(*pnRefAr+i)+1), (*(*pnRefAr+i)+2));
				}
			
			}
			// Sinon
			else {
				printf("\nLes données du fichier maillage sont incorrectes.\n");
				exit(0);
			}
			
			
		}
		
}