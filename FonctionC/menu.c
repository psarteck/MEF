// Fonction MENU qui peut être utilisée afin de demander à l'utilisateur quel problème
// quel domaine et quel maillage il souhaite 

// ficmai : le nom du fichier de maillage qui sera utilisé 
// ficnum : le fichier de numéro de référence qui sera utilisé 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/header.h"

extern int nucas;
extern int dom;
extern int numSortie;

void menu(char **ficmai, char **ficnum){
    
    char maill[3];
    char domC[3];
    char finesseC[3];
    char numSortieC[3];
    char nucasC[3];
    
    printf("Menu pour le TP5\nVous pouvez ici sélectionner le domaine et le problème à traiter.\n");
   // while(dom > 2||dom < 1){
        printf("\nChoisissez le domaine que vous voulez étudier : 1 ou 2\n");
        scanf("%s", domC);
  //  }
    //while(nucas > 3||nucas < 1){
        printf("\nChoisissez le problème que vous voulez étudier : 1, 2 ou 3\n");
        scanf("%s", nucasC);
    //}
    
    //while(nucas > 3||nucas < 1){
        printf("\nChoisissez le type d'élément que vous voulez étudier : t pour triangle, q pour quadrangle\n");
        scanf("%s", maill);
    //}
    
    //while(nucas > 3||nucas < 1){
        printf("\nChoisissez la finesse du maillage que vous voulez étudier : 2, 4, 8, 16, 32, 64\n");
        scanf("%s", finesseC);
    //}
    
    printf("\nVoulez vous imprimer la solution à l'écran (-1) ou dans un fichier (numéro de sortie > 0)\n");
    scanf("%s", numSortieC);
    

    char chaineM[] = "./FicMaillage/d";
    int tailleM = strlen(chaineM)+7;
    
    *ficmai = calloc(tailleM, sizeof(char));
    for(int i = 0 ; i < tailleM-7 ; i++){
        (*ficmai)[i] = chaineM[i];
    }
    
    strcat((*ficmai), domC);
    strcat((*ficmai), maill);
    strcat((*ficmai), "1_");
    strcat((*ficmai), finesseC);

    
    
    char chaineN[] = "./NumRef/ref";
    int tailleN = strlen(chaineN)+4;
    
    *ficnum = calloc(tailleN, sizeof(char));
    for(int i = 0 ; i < tailleN-4 ; i++){
        (*ficnum)[i] = chaineN[i];
    }
    strcat((*ficnum), domC);
    strcat((*ficnum), "_");
    strcat((*ficnum), nucasC);
    
    nucas = atoi(nucasC);
    dom = atoi(domC);
    numSortie = atoi(numSortieC);
    
}
