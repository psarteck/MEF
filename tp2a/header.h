

int returnQ(int t);
float **alloctab(int dim1, int dim2);
void ppquad(const int t, float **pts, float **pds);
void calFbase(float *valBase, int t, float *pts);
void calDerFbase(float **valDBase, int t, float *pts);
void transFK(float **ai, float *valBase, int t, float *res);
void invertM2x2(float *det, float M[2][2], float Minv[2][2]);
void freetab(void *ptr);
void matJacob(float **ai, float **valDBase, int d, float **Jcob, int Pk);
void numNaret(int t, int ordre, int pts[], int aret);
void selectPts(int nb, int num[], float *coorEns[], float *coorSel[]);
