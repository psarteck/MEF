## Programme python permettant de tracer les courbes d'erreurs pour chaque problème et chaque domaine


import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
import warnings
from matplotlib import gridspec


for d in range(1,3):
    for p in range(1,4):
        for maillage in range(3,5):
    
            if (maillage == 3):
                m = 'T'
                textMai = 'Triangle'
            else :
                m = 'Q'
                textMai = 'Quadrangle'
            print("Création du la courbe d'erreur pour le Domaine "+str(d)+" Problème "+str(p)+" Maillage "+textMai)
            
            data = np.loadtxt("./FichiersResultats/fort."+str(maillage)+str(d)+str(p))
            plt.figure(figsize=(10,8))
            
            plt.plot(np.log(data[:,2]), np.log(data[:,0]), 'o', label='Erreur quadratique')
            if d == 1 :
                poly = np.polyfit(np.log(data[:,2]), np.log(data[:,0]) , 1)
            else :
                poly = np.polyfit(np.log(data[:-1,2]), np.log(data[:-1,0]) , 1)
            plt.plot(np.log(data[:,2]), np.polyval(poly, np.log(data[:,2])), label="Droite d'interpolation quadratique")

            plt.suptitle("Etude de l'erreur en fonction du pas de discrétisation", fontsize=25)
            plt.title("Domaine "+str(d)+" Problème "+str(p)+" Maillage "+textMai, fontsize=20)
            plt.xlabel("Logarithme du pas h", fontsize=15)
            plt.ylabel("Logarithme de l'erreur", fontsize=15)
            
           
            if (p == 1):
                fct = "$-\Delta u = 16xy(1-x)(1-y)$"
                cond = "$\Gamma_D = \{1,2,3,4\}$, $\Gamma_N =  \emptyset$"
            elif(p == 2):
                fct = "$-\Delta u = \sin(\pi x)\sin(\pi y)$"
                cond = "$\Gamma_D = \{1,2,3,4\}$, $\Gamma_N =  \emptyset$"
            else:
                fct = "$-\Delta u + u = \cos(\pi x)\cos(\pi y)$"
                if(d == 1):
                    cond = "$\Gamma_D = \emptyset$, $\Gamma_N =  \{1,2,3,4\}$"
                else:
                    cond = "$\Gamma_D = \{3,4\}$, $\Gamma_N =  \{1,2\}$"

            if (d == 1):
                xt = -2.5
                xp = -1.7
                yt = -7
                yp = -4
            else:
                xp = -4.8
                xt = -3.2
                yp = -7
                yt = -8.9
            if (poly[1] > 0):
                signe = '+'
            else:
                signe = ''
            plt.text(xp,yp, 'p(x)='+str(round(poly[0],2))+'x'+signe+str(round(poly[1],3)), fontsize=11)
            if (d == 1):
                plt.text(xt,yt, "Domaine "+str(d)+" : [0,1]x[0,1], "+cond, fontsize=11)
            elif (d==2):
                plt.text(xt,yt, "Domaine "+str(d)+" : [0,1/2]x[0,1/2], "+cond, fontsize=11)
            
            
            plt.text(xt,yt+0.5, fct, fontsize=11)

            name = "./Images/Courbes_Erreurs/D"+str(d)+'P'+str(p)+m+".png"
            plt.legend()
            plt.savefig(name, dpi=400)
