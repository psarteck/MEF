/*
Arguments d'entree :
   nbneel : nombre de noeuds de l'element
   fctbas : valeurs des fonctions de base au point de quadrature courant
            Dimensions utiles : fctbas(nbneel)
   eltdif : element differentiel multiplie par le poids de quadrature
   cofvar : valeur du coefficient variable (fonction a integrer calculee
            en l'image par FK du point de quadrature courant)
  Arguments de sortie :
   matelm : second membre elementaire actualisé
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../Header/header.h"
void W(int nbneel, float *fctbas, float eltdif, float cofvar, float *felm) {
	for (int i = 0 ; i < nbneel ; i++) {
        felm[i] = felm[i] + eltdif * cofvar * fctbas[i];
  	}
}
