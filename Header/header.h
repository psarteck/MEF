/*
Header contenant toutes les fonctions utiles au calcul et à l'assemblage
*/

#include "fdp.h"
#include "forfun.h"


int returnQ(int t);

float **alloctab(int dim1, int dim2);

int **alloctabI(int dim1, int dim2);

void lecfima(char *ficmai, int *type1, int *nbtng, float ***pcoord,
             int *nbtel, int ***pngnel, int *nbneel, int *nbaret, int ***pnRefAr);

void ppquad(const int t, float **pts, float **pds);

void calFbase(float *valBase, int t, float *pts);

void calDerFbase(float **valDBase, int t, float *pts);

void transFK(float **ai, float *valBase, int t, float *res);

void invertM2x2(float *det, float **M, float **Minv);

void freetab(void *ptr);

void matJacob(float **ai, float **valDBase, int d, float **Jcob, int Pk);

void numNaret(int t, int pts[], int aret);

void selectPts(int nb, int num[], float *coorEns[], float *coorSel[]);

void impCalEl(int K, int typEl, int nbneel, float **MatElem, float *SMbrElem,
              int *NuDElem, float *uDElem);

void WW(int nbneel, float *fctbas, float eltdif, float cofvar, float **matelm);

void W(int nbneel, float *fctbas, float eltdif, float cofvar, float *felm);

void ADWDW(int nbneel, float **fctbas, float eltdif, float **cofvar, float **invMatJ, float **matelm);

float prodScal(float **Mat1, float **Mat2, int indiceAB, int indiceIJ);

void intElem(int type, int nbneel, float **coorEl, float **matelm, float *felm);

void intAret(int type, int nbneel, float **coorEl, float **matelm, float *felm, int aret);

void lecNumRef(char *ficmai, int *nRefDom, int **numRefD0, int **numRefD1, int **numRefF1, 
            int *nbRefD0, int *nbRefD1, int *nbRefF1);

void cal1Elem(int nRefDom, int nbRefD0, int *numRefD0, int nbRefD1, int *numRefD1, 
        int nbRefF1, int *numRefF1, int typeEl, int nbneel, float **coordEl, int nbaret, 
        int nRefArEl[], float **MatElem, float *SMbrElem, int *NuDElem, float *uDElem);

void impCalEl(int K, int typEl, int nbneel, float **MatElem, float *SMbrElem,
        int *NuDElem, float *uDElem);

void assemblage(int NbLign, int NbCoeff, int nbEls, int typeEl, int nbArPaEl, 
        float Matrice[], int AdPrCoefLi[], int AdSuccLi[], int NumCol[], float SecMembre[], 
        int NumDLDir[], float ValDLDir[], int nbNePaEl, int **ngnel, float **coord, int **nRefAr, 
        int nRefDom, int nbRefD0, int *numRefD0, int nbRefD1, int *numRefD1, int nbRefF1, int *numRefF1);

void dSMDaSMO(int NbLign, int AdPrCoefLi[], int NumCol[], int AdSuccLi[], float Matrice[], 
        float SecMembre[], int NumDLDir[], float ValDLDir[], int NumColO[], float MatriceO[]);

void dSMOaPR(int NbLign, int *NbCoeff, int AdPrCoefLiO[], float MatriceO[], int NumColO[], 
        float **MatProf, int Profil[]);

void decompLU(int NbLign, int NbCoeff, float MatProf[], int Profil[], float U[], float SecMembre[]);

float solex(float *coor);

void calSol(int NbLign, float **coord, float *UEX);

void menu(char **ficmai, char **ficnum);


