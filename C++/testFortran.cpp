#include <iostream>
#include <vector>
#include <iomanip> // Pour la mise en forme

#include "FEMAssembly.hpp"

// Fonction pour générer une matrice test
void generateTestData(int nblign, 
                      std::vector<int>& adprcl, 
                      std::vector<int>& numcol, 
                      std::vector<int>& adsucl, 
                      std::vector<float>& matris, 
                      std::vector<float>& secmbr, 
                      std::vector<int>& nuddir, 
                      std::vector<float>& valdir) {

    // Générer des données fictives pour tester
    for (int i = 0; i < nblign; i++) {
        secmbr[i] = 1.0f * (i + 1);
        nuddir[i] = i % 2;  // Alternance entre 0 et 1
        valdir[i] = 10.0f + i; 

        // Génération d'une structure simple pour adprcl, numcol et adsucl
        if (i > 0) {
            adprcl[i] = i;  // Adresses fictives
            numcol[i] = i;  // N° colonne fictif
            adsucl[i] = i == nblign-1 ? 0 : i+1;  // Suivant (dernier élément pointe vers 0)
        } else {
            adprcl[i] = 0;  // La première ligne n'a pas de partie triangulaire
        }
    }

    // Remplir la matrice diagonale avec des valeurs fictives
    for (int i = 0; i < nblign; i++) {
        matris[i] = 5.0f * (i + 1);  // Diagonale fictive
    }

    // Remplir la partie triangulaire inférieure
    for (int i = nblign; i < 2 * nblign; i++) {
        matris[i] = 0.5f * (i - nblign + 1);  // Valeurs fictives
    }
}

// Fonction pour comparer les sorties
void compareOutputs(int nblign,
                    const std::vector<int>& adprcl, 
                    const std::vector<int>& numcol, 
                    const std::vector<int>& adsucl, 
                    const std::vector<float>& matris, 
                    const std::vector<float>& secmbr, 
                    const std::vector<int>& nuddir, 
                    const std::vector<float>& valdir) {

    std::cout << "\n--- Test de la méthode AFFSMD ---" << std::endl;

    // Appel de la fonction traduite
    FEMAssembly::AFFSMD(nblign, adprcl, numcol, adsucl, matris, secmbr, nuddir, valdir);
    
    // Comparaison possible ici avec les sorties attendues d'une version Fortran si disponibles
}

int main() {
    // Nombre de lignes de la matrice
    int nblign = 5;

    // Initialisation des tableaux
    std::vector<int> adprcl(nblign), numcol(nblign), adsucl(nblign);
    std::vector<float> matris(2 * nblign), secmbr(nblign), valdir(nblign);
    std::vector<int> nuddir(nblign);

    // Générer des données de test
    generateTestData(nblign, adprcl, numcol, adsucl, matris, secmbr, nuddir, valdir);

    // Comparer les sorties de la méthode traduite
    compareOutputs(nblign, adprcl, numcol, adsucl, matris, secmbr, nuddir, valdir);

    return 0;
}