#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void lecNumRef(char *ficmai, int *nRefDom, int **numRefD0, int **numRefD1, int **numRefF1, int *nbRefD0, int *nbRefD1, int *nbRefF1){
    
    
    FILE *fic = NULL;
    fic = fopen(ficmai, "r");
    if(fic == NULL){
        printf("Ouverture du fichier impossible\n");
    }

    else {
        int i = 0;
        
        fscanf(fic, "%d", nRefDom);
        
        fscanf(fic, "%d", nbRefD0);
        int *p1 = *numRefD0 = calloc(*nbRefD0, sizeof(int));
        for(i = 0 ; i < *nbRefD0 ; i ++){
            fscanf(fic, "%d", &p1[i]);
        }
        
        fscanf(fic, "%d", nbRefD1);
        int *p2 = *numRefD1 = calloc(*nbRefD1, sizeof(int));
        for(i = 0 ; i < *nbRefD1 ; i ++){
            fscanf(fic, "%d", &p2[i]);
        }
        
        fscanf(fic, "%d", nbRefF1);
        int *p3 = *numRefF1 = calloc(*nbRefF1, sizeof(int));
        for(i = 0 ; i < *nbRefF1 ; i ++){
            fscanf(fic, "%d", &p3[i]);
        }
    }
    
}
