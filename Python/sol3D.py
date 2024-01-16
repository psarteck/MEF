##  Code python pour afficher la solution calculée en 3D pour chaque problème 
##  uniquement pour un maillage triangulaire


import numpy as np
#from scipy.spatial import Delaunay
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


for d in range(1,3):
    for p in range(1,4):
        print("Création du la courbe d'erreur pour le Domaine "+str(d)+" Problème "+str(p)+" Maillage Quadrangle")
        name = "./FichiersResultats/solCalc4"+str(d)+str(p)+".txt"
        data = np.loadtxt(name)
        tab = data[:].astype(float)
        taille = np.sqrt(len(tab[:])).astype(int)
       
        
        U = tab.reshape((taille,taille))
        x = np.linspace(0, 1/d, taille)
        y = np.linspace(0, 1/d, taille)
        X, Y = np.meshgrid(x, y)

        fig = plt.figure(figsize=(10,8))
        ax = fig.add_subplot(111, projection='3d')
        ax.grid(False)
        surf = ax.plot_surface(X,Y,U, cmap='turbo', shade=True, rstride=1, cstride=1, alpha=None, antialiased=True)
        fig.colorbar(surf)
        ax.view_init(45, 0)
        plt.xlabel('X', fontsize=22)
        plt.ylabel('Y', fontsize=22)
        plt.title('Solution pour le Domaine '+str(d)+' Problème '+str(p), fontsize=20)
        plt.savefig('./Images/Figures_Calculees/sol3D'+str(d)+str(p)+'.png', dpi=400)
        ax.view_init(90, 0)
        plt.savefig('./Images/Figures_Calculees/sol3DVH'+str(d)+str(p)+'.png', dpi=400)
