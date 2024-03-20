// fct.cpp
#include <iostream>
#include <fstream> // Pour la manipulation de fichiers

void calculate() {
    // Ouvrir le fichier "data.txt" en mode écriture
    std::ofstream file("data.txt");

    // Vérifier si le fichier est ouvert avec succès
    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier data.txt" << std::endl;
        return;
    }

    // Écrire les premiers entiers de 1 à 15 dans le fichier
    for (int i = 1; i <= 15; ++i) {
        file << i << std::endl;
    }

    // Fermer le fichier
    file.close();

    // Afficher un message pour indiquer que l'écriture dans le fichier est terminée
    std::cout << "Les premiers entiers de 1 à 15 ont été écrits dans le fichier data.txt" << std::endl;
}

int main() {
    calculate(); // Appeler la fonction calculate()
    return 0;
}
