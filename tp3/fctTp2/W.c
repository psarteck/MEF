#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void W(int nbneel, float *fctbas, float eltdif, float cofvar, float *felm) {
	for (int i = 0 ; i < nbneel ; i++) {
        felm[i] = felm[i] + eltdif * cofvar * fctbas[i];
  	}
}
