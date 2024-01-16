/*
--------------------------------------------------------------------------------
   Passage de la structure morse ordonnee (S.M.O.) a la structure profil.

   Arguments d'entree :
  nblign : nombre de lignes de la matrice
  adprcl : adresses (dans lmatri) des premiers coefficients des lignes de
           la partie triangulaire inferieure stricte de la matrice
  numcol : numeros de colonnes des coeff. de la partie triang. inf. stricte
  matris : tableau contenant la diagonale de la matrice (dmatri) puis la
           partie triangulaire inferieure stricte (lmatri) sous forme S.M.0.
  nbcprx : taille max du tableau matrip

   Arguments de sortie :
  profil : adresses (dans lmatrip) des premiers coefficients des lignes de
           la partie triangulaire inferieure stricte de la matrice
  matrip : tableau contenant la diagonale de la matrice (dmatrip) puis la
           partie triangulaire inferieure stricte (lmatrip) sous forme profil
  codret : code de retour egal a 0 si R.A.S., 1 si la taille de matrip est
           insuffisante (nbcprx)
--------------------------------------------------------------------------------
*/
void dmoapr (const int nblign, const int *adprcl, const int *numcol,
     const float *matris, const int nbcprx, int *profil, float *matrip,
     int *codret);
